#include "raylib.h"
#include <iostream>
#include <cmath>

using namespace std;

int width = 1000;
int height = 1000;
int spacing = 25;

float center_mass_radius = 50;
float center_mass = 1500;

float x_cm = (float)width/2.0;
float y_cm = (float)height/2.0;

float Gaussian(float x, float mu, float sigma, float A){
  return A*exp(-pow(x-mu,2)/(2*pow(sigma,2)));
}

void warped_spacetime_2D(){
  float sigma = 100.0f;
  float A = 5000.0f;
  
  for(int x = -width/2.0; x < width/2.0; x += spacing){
    for(int y = -height/2.0; y < height/2.0; y += spacing){
	float dx = x;
	float dy = y;
	float r = sqrt(dx*dx + dy*dy);

	float deformation = Gaussian(r,0,sigma,A);
	
	Vector3 pos = {x_cm + x, y_cm + y, -deformation};
      
	DrawSphere(pos,1.5,WHITE);
    }
  }    
}

void warped_spacetime_3D(){
  int z_limit = 250;
  float sigma = 100.0f;
  float A = 50000.0f;

  for(int x = -width/2.0; x < width/2.0; x += spacing){
    for(int y = -height/2.0; y < height/2.0; y += spacing){
      for(int z = -z_limit; z < z_limit; z += spacing){
	float dx = x;
	float dy = y;
       	float dz = z;
	float r = sqrt(dx*dx + dy*dy + dz*dz);

	float deformation = Gaussian(r,0,sigma,A);
	
	Vector3 pos = {x_cm + x, y_cm + y, z - deformation};
      
	DrawSphere(pos,1.5,WHITE);
    }
  }    
}
}

void Center_Mass(float x, float y, float radius){
  DrawSphere((Vector3){x,y,0},radius,YELLOW);
}

int main(){
  InitWindow(1000, 1000, "Space-Time Curvature");
  SetTargetFPS(60);

  enum Dim {Dim_2D, Dim_3D};
  
  Dim currentDim = Dim_2D;
  
  float angle = 0.0f;
  float radius = 800.0f;
  float height = 500.0f;  // height above the center

  Camera3D camera = {0};
  camera.position = (Vector3){x_cm,y_cm - 700.0f,300.0f};
  camera.target = (Vector3){x_cm,y_cm,0.0f};
  camera.up = (Vector3){0.0f,0.0f,1.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;
    
  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);

    Vector3 rotation = {0};
    
    if(IsKeyDown(KEY_LEFT)){
      angle -= 0.01f;
    }
    
    if(IsKeyDown(KEY_RIGHT)){
      angle += 0.01f;
    }
    
    if(IsKeyDown(KEY_UP)){
      radius -= 5.0f;
    }
    
    if(IsKeyDown(KEY_DOWN)){
      radius += 5.0f;
    }
    
    // Update camera position to orbit around center mass
    camera.position.x = x_cm + radius * cosf(angle);
    camera.position.y = y_cm + radius * sinf(angle);
    camera.position.z = height;

    camera.target = (Vector3){x_cm, y_cm, 0.0f};     // always look at the center
    camera.up = (Vector3){0.0f, 0.0f, 1.0f};         // Z is up
    
    BeginMode3D(camera);
    
    if(IsKeyDown(KEY_TWO)){
      currentDim = Dim_2D;
    }

    if(IsKeyDown(KEY_THREE)){
        currentDim = Dim_3D;
    }

    if(currentDim == Dim_2D){
      warped_spacetime_2D();
    Center_Mass(x_cm,y_cm,center_mass_radius);    
    }

    else if(currentDim == Dim_3D){
      warped_spacetime_3D();
      Center_Mass(x_cm,y_cm,center_mass_radius);
    }

    EndMode3D();		
    EndDrawing();
  }
	
CloseWindow();
  return 0;
}

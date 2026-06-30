# 🌌 Spacetime Curvature Visualization

A real-time 3D visualization of **spacetime curvature** (gravitational warping) built with **C++** and **Raylib**.  
Explore the effects of a massive object on the fabric of spacetime in 2D or 3D.

---

## 🎮 Features

- **2D and 3D visualization** — toggle between 2D and 3D spacetime curvature
- **Gaussian deformation** — realistic gravitational warping effect
- **Interactive camera** — orbit around the mass using arrow keys
- **Real-time rendering** — smooth 60 FPS visualization
- **Visual feedback** — yellow sphere marks the center mass

---

## 🛠️ Technologies Used

- **C++** — core logic
- **Raylib** — 3D rendering, camera controls, input handling

---

## 🚀 How to Build

### Requirements

Install Raylib:

bash
# Ubuntu / Debian
sudo apt install libraylib-dev

# Or build from source
git clone https://github.com/raysan5/raylib.git
cd raylib
mkdir build && cd build
cmake ..
make
sudo make install

### Compile

g++ -o spacetime spacetime.cpp \
    -lraylib -lm -lpthread -ldl -lrt -lX11

### Run

./spacetime

🎮 Controls
Key	Action
Left Arrow	Rotate camera left
Right Arrow	Rotate camera right
Up Arrow	Zoom in (decrease orbit radius)
Down Arrow	Zoom out (increase orbit radius)
2	Switch to 2D view
3	Switch to 3D view
Close Window	Exit the application

🧠 How It Works

 1.   Gaussian deformation — the spacetime grid is warped using a Gaussian function centered on the mass

 2.   2D view — shows a flat grid warped into a funnel shape

 3.   3D view — shows a 3D volume warped by the mass

 4.   Camera orbit — the camera orbits around the center mass

 5.   Rendering — Raylib handles 3D rendering and input

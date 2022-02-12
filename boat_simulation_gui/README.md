# Boat Simulation GUI

## Final `Sample`:

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/Screenshot-03-PlotingTheCsvFile.png" alt="final_sample" width="1000px" />
  <br>
</h2>

## Description 📄:
The goal of this project is to construct a simulator of boat activities. The boats are assumed to be inside or outside of a grid of N x N pixels, which is further divided into subregions.
### Main components:
⚡️ Simulation Mechanism\
⚡️ Boat Activities Widgets\
⚡️ File Menu Interface\
⚡️ Simulation Engine

## Simulation `Mechanism` 🛠️: 
- Time driven mechanism
- Grid size
- Boats' initial location
- Type of activity
- Simulation duration be the event that two boats are "too close to each other" or a specific boat is in a specific subregion of grid
- Trajectory of the boats

## Boat `Action Widgets` include 🛠️:
1. Map size
2. Boat X is folowwing boat Y
3. Boat X is chasing boat Y
4. Boat X is circling boat Y
5. Boat Y and boat Z are approaching each other

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s1.png" alt="widget" width="70%" />
  <br>
</h2>

## Adding `Menu Interface` 🛠️:
- Docking widgets
- Add a file items drop-down menu
- Add a text-edit area
- Add a quit item
- Add a help menu

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s2_3.png" alt="menu" width="70%" />
  <br>
</h2>

## Implement Simulation `Engine` 🛠️:
### Engine: 
- Check system status
- Make a decision
- Update system status
- Collect data
- Check for exceptions

| | | |
|:-------------------------:|:-------------------------:|:-------------------------:|
|<img width="600" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update1.png"> Tracking |  <img width="600" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update2a.png"> Event Reached |<img width="600" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update3.png"> Times Up|

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update.png" alt="engine" width="70%" />
  <br>
</h2>

## `Tracking and Analyzing` 🛠️:
- Develop an embedded function to read and write .csv file
- Tracking boat location

| | | 
|:-------------------------:|:-------------------------:|
|<img width="500" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s4_analyze.png"> Read and Write to files |  <img width="900" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s4_track.png"> Track boats location |

## `Grid Map` 🛠️:

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/grid_map.png" alt="map" width="70%" />
  <br>
</h2>




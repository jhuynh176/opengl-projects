# Boat Simulation GUI

## Final sample:

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/Screenshot-03-PlotingTheCsvFile.png" alt="project_s2" width="1000px" />
  <br>
</h2>

## Description:
The goal of this project is to construct a simulator of boat activities. The boats are assumed to be inside or outside of a grid of N x N pixels, which is further divided into subregions.
### Main components:
⚡️ Simulation Mechanism\
⚡️ Boat Activities Widgets\
⚡️ File Menu Interface\
⚡️ Simulation Engine

## Simulation Mechanism: 
- Time driven mechanism
- Grid size
- Boats' initial location
- Type of activity
- Simulation duration be the event that two boats are "too close to each other" or a specific boat is in a specific subregion of grid
- Trajectory of the boats

## Boat activities widgets include:
1. Map size
2. Boat X is folowwing boat Y
3. Boat X is chasing boat Y
4. Boat X is circling boat Y
5. Boat Y and boat Z are approaching each other

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s1.png" alt="s1" width="70%" />
  <br>
</h2>

## Adding Menu Fnterface:
- Docking widgets
- Add a file items drop-down menu
- Add a text-edit area
- Add a quit item
- Add a help menu

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s2_3.png" alt="s2" width="70%" />
  <br>
</h2>

## Implement Simulation Engine:
### Engine: 
- Check system status
- Make a decision
- Update system status
- Collect data
- Check for exceptions

| | | |
|:-------------------------:|:-------------------------:|:-------------------------:|
|<img width="1604" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update1.png"> |  <img width="1604" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update2a.png">|<img width="1604" alt="engine" src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update3.png">|


<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s3_update.png" alt="s2" width="70%" />
  <br>
</h2>

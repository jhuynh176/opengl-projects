# Boat Simulation GUI

## Final sample:

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/Screenshot-03-PlotingTheCsvFile.png" alt="project_s2" width="1000px" />
  <br>
</h2>

## Description:
The goal of this project is to construct a simulator of boat activities. The boats are assumed to be inside or outside of a grid of N x N pixels, which is further divided into subregions.
- 

## Simulation Mechanism: 
- Time driven mechanism
- Grid size
- Boats' initial location
- Type of activity
- Simulation duration be the event that two boats are "too close to each other" or a specific boat is in a specific subregion of grid
- Trajectory of the boats

## Boat activities widgets include:
1. Boat X is folowwing boat Y
2. Boat X is chasing boat Y
3. Boat X is circling boat Y
4. Boat Y and boat Z are approaching each other

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s1.png" alt="s1" width="70%" />
  <br>
</h2>

## Adding Menu interface:
- Docking widgets
- Add a file items drop-down menu
- Add a text-edit area
- Add a quit item
- Add a help menu

<h2 align="center">
  <img src="https://github.com/jhuynh176/opengl-projects-CPP-based/blob/main/boat_simulation_gui/example/s2_2.png" alt="s2" width="70%" />
  <br>
</h2>

## Implement Simulation Engine:
### Engine: 
- Check system status
- Make a decision
- Update system status
- Collect data
- Check for exceptions

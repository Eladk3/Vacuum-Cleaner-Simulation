# Vacuum Cleaner Simulation

## Contributors
- Elad Eli Kadosh 318730116
- Noy Agam 314623372

## Overview
This project simulates an automatic vacuum cleaner navigating and cleaning a house. The house layout is provided as an input file, and the vacuum cleaner's actions and final status are output to a file.

## Input Format
- `#`: Wall
- ` `: Empty space
- `D`: Docking station
- `1-9`: Dirt levels

## Output Format
The program outputs the sequence of actions taken by the vacuum cleaner and its final status, including total steps, remaining dirt, battery status, and mission success.

## Compilation and Execution
To compile:
```sh
make

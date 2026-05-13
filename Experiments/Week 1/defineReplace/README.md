# Circle Info Calculator
<img width="1659" height="871" alt="circleInfo" src="https://github.com/user-attachments/assets/20c51175-1661-4b95-8a83-9f1c23552a89" />

A comprehensive command-line utility written in `C` that calculates over 15 geometric, engineering, and 3D properties of a circle/sphere based solely on its radius. 

## Features
Given a single positive float value for the radius, the program instantly calculates:
* **Primary Geometric Measurements:** Diameter, Area, Circumference, and Curvature.
* **Engineering & Physics Properties:** Area Moment of Inertia, Polar Moment of Inertia, Section Modulus, and Radius of Gyration.
* **Bounding & Inscribed Shapes:** Areas and side lengths for inscribed/circumscribed squares, inscribed equilateral triangles, and inscribed regular hexagons.
* **Semicircles:** Semicircle Area and Perimeter.
* **3D Sphere Info:** Volume and Surface Area.

## Dependencies
* [CS50 Library](https://cs50.readthedocs.io/libraries/cs50/c/) (`cs50.h`) - Used for robust user input handling.
* Standard C libraries: `<math.h>` and `<stdio.h>`.

## Usage
Run the compiled program in your terminal. It will continuously prompt you for a radius and display the categorized results. 

```bash
# Compile the program (ensure the math and cs50 libraries are linked)
gcc -o circle_calc circle_calc.c -lcs50 -lm

# Run the program
./circle_calc
```
- The program will output all mathematical properties formatted to 5 decimal places.
- The prompt runs in a continuous loop for quick successive calculations.
  - **To exit:** Press ctrl+d for graceful closure, or ctrl+c to kill program

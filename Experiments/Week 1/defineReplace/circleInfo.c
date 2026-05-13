// #define Preprocessing Directive Test.
// Calculates numerous circles parameters (as area, volume and more) using only it's radius
// timeSpentHere = (5) hours
// --------------------------------------------------------------------------------------------------------
// Headers
#include <cs50.h>   // Header for userPrompt functions
#include <float.h>  // Header for FLT_MAX (EOF try...catch)
#include <math.h>   // Header for sqrt()
#include <stdio.h>  // Header for i/o functions
#include <stdlib.h> // Header for exit() to kill program


// PP replace directives
#ifndef M_PI
    #define M_PI 3.14159265358979323846 // Definition of PI if not defined in the library (highPrecision)
#endif
#define PI M_PI                         // Value of PI


// Prototypes
// Get radius from user
float getRadius(void);

// Primary Geometric Measurements
void calcDiameter(float radius);
void calcArea(float radius);
void calcCircumference(float radius);
void calcCrvture(float radius);

// Engineering & Physics Properties
void calcArMntInertia(float radius);
void calcPolMntInertia(float radius);
void calcSectModulus(float radius);
void calcRdsGyr(float radius);

// Bounding & Inscribed Shapes
void calcInscSqArea(float radius, double sqrt2);
void calcCircmSqArea(float radius);
void calcInscTriArea(float radius, double sqrt3);
void calcInscHexArea(float radius, double sqrt3);

// Semicircles
void calcSemiArea(float radius);
void calcSemiPerimeter(float radius);

// 3D Sphere Info
void calc3DVolume(float radius);
void calc3DSfcArea(float radius);


// --------------------------------------------------------------------------------------------------------
// Main function
int main(void)
{
    // Global Constants
    const double sqrt2 = sqrt(2); // Square root of 2
    const double sqrt3 = sqrt(3); // Square root of 3

    while (true)
    {
        // Ask for radius and initialize it into main
        float radius = getRadius();

        // Print calculations' results
        // Primary Geometric Measurements
        calcDiameter(radius);
        calcArea(radius);
        calcCircumference(radius);
        calcCrvture(radius);

        // Engineering & Physics Properties
        calcArMntInertia(radius);
        calcPolMntInertia(radius);
        calcSectModulus(radius);
        calcRdsGyr(radius);

        // Bounding & Inscribed Shapes
        calcInscSqArea(radius, sqrt2);
        calcCircmSqArea(radius);
        calcInscTriArea(radius, sqrt3);
        calcInscHexArea(radius, sqrt3);

        //Semicircles
        calcSemiArea(radius);
        calcSemiPerimeter(radius);

        // 3D Sphere Info
        calc3DVolume(radius);
        calc3DSfcArea(radius);
    }

    // Return 0 if successful, end of program
    return 0;
}

// Prototype Defs
// ---------------------------------------------------------------------------------------------------------
// Prompt user for radius of circle. Return 'radius' as a float
float getRadius(void)
{
    // Get radius of user's circle.
    printf("\n--- CIRCLE INFO CALCULATOR (Note: press ctrl+d to close)---\n\n");
    float radius;
    do
    {
        radius = get_float("Radius of your circle = ");
        // If user types ctrl+d (throws EOF signal, get_float returns FLT_MAX) exit program gracefully to catch terminal bleeding
        if (radius == FLT_MAX)
        {
            // Exit program, print a closing message
            printf("\n(Typed ctrl+d)\tEOF, Exiting...\n");
            exit(0);
        }
    }
    // ctrl+d try-catch and only-positive-integers
    while (radius <= 0);
    printf("\n--- RESULTS ---\n\nPrimary Geometric Measurements\n\n value of radius = %0.5f\n", radius);

    // Return radius to main
    return radius;
}



// Primary Geometric Measurements
// Diameter script, take radius as an argument, print result directly
void calcDiameter(float radius)
{
    // Diameter formula = radius*2
    printf("\t-Diameter (d) = %0.5f\n", radius * 2);
}

// Area script, take radius as an argument, print result directly
void calcArea(float radius)
{
    // Area formula = PI*radius^2
    printf("\t-Area (A) = %0.5f\n", PI * radius * radius);
}

// Circumference script, take radius as an argument, print result directly
void calcCircumference(float radius)
{
    // Circumference formula = 2*PI*radius
    printf("\t-Circumference (C) = %0.5f\n", 2 * PI * radius);
}

// Curvature script, take radius as an argument, print result directly
void calcCrvture(float radius)
{
    // Curvature formula = 1/radius
    printf("\t-Curvature (k) = %0.5f\n", 1 / radius);
}



// Engineering & Physics Properties
// Area Moment of Inertia (Resistance to bending)
void calcArMntInertia(float radius)
{
    // Area Moment of Inertia formula = (PI*radius^4)/4
    printf("\nEngineering & Physics Properties\n");
    float piradius4 = PI * radius * radius * radius * radius;
    printf("\t-Area Moment of Inertia (I) = %0.5f\n", piradius4 / 4);
}

// Polar Moment of Inertia (Resistance to torsion (twisting))
void calcPolMntInertia(float radius)
{
    // Polar Moment of Inertia formula = (PI*radius^4)/2
    float piradius4 = PI * radius * radius * radius * radius;
    printf("\t-Polar Moment of Inertia (J) = %0.5f\n", piradius4 / 2);
}

// Section Modulus (Used to calculate bending stresses)
void calcSectModulus(float radius)
{
    // Section Modulus = (PI*radius^3)/4
    float piradius3 = PI * radius * radius * radius;
    printf("\t-Section Modulus (Z) = %0.5f\n", piradius3 / 4);
}

// Radius of Gyration (Used calculate buckling in columns)
void calcRdsGyr(float radius)
{
    // Radius or Gyration formula = radius/2
    printf("\t-Radius of Gyration (k) = %0.5f\n", radius / 2);
}



// Bounding & Inscribed Shapes
// Inscribed Square Area (The largest square that fits inside the circle)
void calcInscSqArea(float radius, double sqrt2)
{
    // Inscribed Square Area formula = 2*radius^2
    // Side Lenght formula = radius*sqrt(2)
    printf("\nBounding & Inscriber Shapes\n");
    printf("\t-Inscribed Square Area = %0.5f\n\t\t-Side Length = %0.5f\n", 2 * radius * radius,
           radius * sqrt2);
}

// Circumscribed Square Area (The smallest square that fits outside the circle)
void calcCircmSqArea(float radius)
{
    // Circumscribed Square Area formula = 4*radius^2
    // Side Length formula = 2*radius
    printf("\t-Circumscribed Square Area = %0.5f\n\t\t-Side Length = %0.5f\n", 4 * radius * radius,
           2 * radius);
}

// Inscribed Equilateral Triangle Area (The largest triangle that fits inside the circle)
void calcInscTriArea(float radius, double sqrt3)
{
    // Inscribed Equilateral Triangle Area formula = ((3*sqrt3)/4)*radius2
    // Side Length formula = radius*sqrt3
    double divnum = 3 * sqrt3;
    printf("\t-Inscribed Equilateral Triangle Area = %0.5f\n\t\t-Side Length = %0.5f\n",
           divnum / 4 * radius * radius, radius * sqrt3);
}

// Inscribed Regular Hexagon (The largest hexagon that fits inside the circle)
void calcInscHexArea(float radius, double sqrt3)
{
    // Inscribed Regular Hexagon formula = ((3*sqrt3)/2)*radius2
    // Side Length formula = radius
    double divnum = 3 * sqrt3;
    printf("\t-Inscribed Regular Hexagon Area = %0.5f\n\t\t-Side Length = %0.5f\n",
           divnum / 2 * radius * radius, radius);
}



// Semicircles
// Semicircle Area
void calcSemiArea(float radius)
{
    // Semicircle Area formula = (PI*radius^2)/2
    printf("\nSemicircles\n");
    float piradius2 = PI * radius * radius;
    printf("\t-Semicircle Area = %0.5f\n", piradius2 / 2);
}

// Semicircle Perimeter
void calcSemiPerimeter(float radius)
{
    // Semicircle Perimeter formula = PI*radius+2*radius
    printf("\t-Semicircle Perimeter = %0.5f\n", PI * radius + 2 * radius);
}



// 3D Sphere Info
// Sphere volume script, take radius as an argument, print result directly
void calc3DVolume(float radius)
{
    // Volume formula = (4/3)*PI*radius^3
    printf("\n3D Info (Sphere)\n");
    printf("\t-Volume (V) = %0.5f\n", 4.0 / 3 * PI * radius * radius * radius);
}

// Sphere surface area script, take radius as an argument, print result directly
void calc3DSfcArea(float radius)
{
    // Surface area formula = 4*PI*radius^2
    printf("\t-Surface area (A) = %0.5f\n", 4 * PI * radius * radius);
}

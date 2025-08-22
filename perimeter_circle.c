#include <stdio.h>

// Function to calculate area of circle
float circleArea(float r) {
    return 3.14159f * r * r;
}

// Function to calculate area of rectangle
float rectangleArea(float l, float w) {
    return l * w;
}

// Function to calculate area of square
float squareArea(float s) {
    return s * s;
}

// Function to calculate area of triangle
float triangleArea(float b, float h) {
    return 0.5f * b * h;
}

int main() {
    float r, l, w, s, b, h;

    // Circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &r);
    printf("The area of the circle is: %.2f\n", circleArea(r));

    // Rectangle
    printf("Enter the length and width of the rectangle: ");
    scanf("%f%f", &l, &w);
    printf("The area of the rectangle is: %.2f\n", rectangleArea(l, w));

    // Square
    printf("Enter the side of the square: ");
    scanf("%f", &s);
    printf("The area of the square is: %.2f\n", squareArea(s));

    // Triangle
    printf("Enter the base and height of the triangle: ");
    scanf("%f%f", &b, &h);
    printf("The area of the triangle is: %.2f\n", triangleArea(b, h));

    return 0;
}

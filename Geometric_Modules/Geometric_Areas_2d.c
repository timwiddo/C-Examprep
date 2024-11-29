//
// Created by s_widmoser24 on 29.11.2024.
//


#include <math.h>
#define PI 3.14159265

float square_area(float length) {
    return pow(length, 2);
}

float triangle_area(float base_length, float height) {
    return base_length * height * (0.5);
}

float circle_area(float radius) {
    return PI * pow(radius, 2);
}
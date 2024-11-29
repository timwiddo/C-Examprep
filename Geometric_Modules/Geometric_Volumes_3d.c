//
// Created by s_widmoser24 on 29.11.2024.
//
//Areas: Square, Triangle, Circle, Rectangle, Parallelogram


#include <math.h>

#define PI 3.14159265

float square_volume(float length) {
    return pow(length, 3);
}

float pyramid_volume(float base_length, float height) {
    return pow(base_length, 2) * height * (1/3);
}

float sphere_volume(float radius) {
    return PI * pow(radius, 3) * (4/3);
}
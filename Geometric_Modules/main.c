#include <stdio.h>
#include "2d_Functions.h"
#include "3d_Functions.h"

int main(void) {
    float radius1 = 4.1;
    float radius2 = 3.584;

    printf("%.2f\n", circle_area(radius1));

    printf("The Volume of the Sphere with Radius %.2f cm is %.2f cm^3.", radius2, sphere_volume(3.584));

}

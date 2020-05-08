#include "circle.h"
#include <stdio.h>

circle_t define_circle()
{
    circle_t circle;

    printf("Enter x, y, radius: ");
    int x, y;
    float radius;
    scanf("%d %d %f", &x, &y, &radius);

    circle.x = x;
    circle.y = y;
    circle.radius = radius;

    return circle;
}

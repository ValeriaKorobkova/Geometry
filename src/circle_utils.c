#include "circle.h"
#define PI 3.141592653589793

float get_perimeter(circle_t circle)
{
    return 2 * PI * circle.radius;
}

float get_area(circle_t circle)
{
    return PI * circle.radius * circle.radius;
}

int is_intersected(circle_t circle_1, circle_t circle_2)
{
    float distance
            = sqrt(pow((circle_1.x - circle_2.x), 2)
                   + pow((circle_1.y - circle_2.y), 2));
    if (circle_1.radius + circle_2.radius >= distance)
        return 1;
    else
        return 0;
}

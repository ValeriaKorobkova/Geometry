#include <stdio.h>

#define PI 3.141592653589793

struct Circle {
    int x;
    int y;
    float radius;
};

Circle define_circle();
float get_area(Circle circle);

int main()
{
    int size = 3;
    Circle circles[size];
    for (int i = 0; i < size; i++) {
        circles[i] = define_circle();
    }

    for (int i = 0; i < size; i++) {
        printf("circle(%d %d, %.2f)\n",
               circles[i].x,
               circles[i].y,
               circles[i].radius);
        printf(" area = %.2f\n", get_area(circles[i]));
    }

    return 0;
}

Circle define_circle()
{
    Circle circle;

    printf("Enter x, y, radius: ");
    int x, y;
    float radius;
    scanf("%d %d %f", &x, &y, &radius);

    circle.x = x;
    circle.y = y;
    circle.radius = radius;

    return circle;
}

float get_area(Circle circle)
{
    return PI * circle.radius * circle.radius;
}

#include <math.h>
#include <stdio.h>

#define PI 3.141592653589793

struct Circle {
    int x;
    int y;
    float radius;
};

Circle define_circle();
float get_area(Circle circle);
float get_perimeter(Circle circle);
int is_intersected(Circle circle_1, Circle circle_2);

int main()
{
    int size;
	printf("Circles count: ");
	scanf("%d",&size);
    Circle circles[size];
    for (int i = 0; i < size; i++) {
        circles[i] = define_circle();
    }
    printf("\n\n");

    for (int i = 0; i < size; i++) {
        printf("circle(%d %d, %.2f)\n",
               circles[i].x,
               circles[i].y,
               circles[i].radius);
        printf(" area = %.2f\n", get_area(circles[i]));
        printf(" perimeter = %.2f\n", get_perimeter(circles[i]));
        printf(" intersects: \n");

        int flag = 0;
        for (int j = 0; j < size; j++) {
            if (i == j)
                continue;
            if (is_intersected(circles[i], circles[j])) {
                printf("  %d. circle\n", j);
                flag = 1;
            }
        }
        if (!flag) {
            printf("  no, sorry :(\n");
        }

        printf("\n");
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

float get_perimeter(Circle circle)
{
    return 2 * PI * circle.radius;
}

float get_area(Circle circle)
{
    return PI * circle.radius * circle.radius;
}

int is_intersected(Circle circle_1, Circle circle_2)
{
    float distance
            = sqrt(pow((circle_1.x - circle_2.x), 2)
                   + pow((circle_1.y - circle_2.y), 2));
    if (circle_1.radius + circle_2.radius >= distance)
        return 1;
    else
        return 0;
}

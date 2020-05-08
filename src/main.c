#include "circle_utils.h"
#include <math.h>
#include <stdio.h>

int main()
{
    int size;
    printf("Circles count: ");
    scanf("%d", &size);
    circle_t circles[size];
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

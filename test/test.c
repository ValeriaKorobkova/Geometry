#define CTEST_MAIN
#include "../includes/ctest.h"
#include "../src/circle_utils.h"

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(circle_utils_suite, test_area)
{
    circle_t circle;
    circle.x = 0;
    circle.y = 0;
    circle.radius = 1;

    float area = get_area(circle);
    ASSERT_DBL_NEAR_TOL(area, 3.141592653589793, 1e-5);

    circle.radius = 2;
    area = get_area(circle);
    ASSERT_DBL_NEAR_TOL(area, 12.566370614359172, 1e-5);

    circle.radius = 0.5641895835477562;
    area = get_area(circle);
    ASSERT_DBL_NEAR_TOL(area, 1, 1e-5);
}

CTEST(circle_utils_suite, test_perimeter)
{
    circle_t circle;
    circle.x = 1;
    circle.y = 1;
    circle.radius = 2;

    float perimeter = get_perimeter(circle);
    ASSERT_DBL_NEAR_TOL(perimeter, 12.5663706143, 1e-5);

    circle.radius = 6;

    perimeter = get_perimeter(circle);
    ASSERT_DBL_NEAR_TOL(perimeter, 37.6991118430, 1e-5);
}

CTEST(circle_utils_suite, test_intersected)
{
    circle_t circle_1, circle_2;
    circle_1.x = 0;
    circle_1.y = 0;
    circle_1.radius = 2;

    circle_2.x = 4;
    circle_2.y = 0;
    circle_2.radius = 2;

    int intersected = is_intersected(circle_1, circle_2);
    ASSERT_EQUAL(intersected, 1);

    circle_1.x = 0;
    circle_1.y = 0;
    circle_1.radius = 1;

    circle_2.x = 4;
    circle_2.y = 0;
    circle_2.radius = 1;

    intersected = is_intersected(circle_1, circle_2);
    ASSERT_EQUAL(intersected, 0);
}
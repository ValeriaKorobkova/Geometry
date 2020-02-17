#include <stdio.h>

struct Circle {
	int x;
	int y;
	float radius;
};

Circle define_circle();

int main() {
	int size = 3;
	Circle circles[size];
	for (int i = 0; i < size; i++) {
		circles[i] = define_circle();
	}

	for (int i = 0; i < size; i++) {
		printf("%d %d %.2f\n", 
			circles[i].x,
		       	circles[i].y,
		       	circles[i].radius
		);
        }


	return 0;
}

Circle define_circle() {
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

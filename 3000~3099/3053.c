#include <stdio.h>
#define PI 3.14159265358979323846

int main() {
	double r;
	scanf("%lf", &r);
	printf("%.6lf\n", PI * r * r);
	printf("%.6lf\n", 2 * r * r);
	return 0;
}

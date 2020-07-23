#include <stdio.h>
#include <math.h>

int main() {
	int i, j, T;
	int x, y;
	int speed, count, distance, temp, temp_sum;
	double key_number;
	scanf("%d", &T);
	for (i = 0; i < T; ++i) {
		count = 0;
		speed = 1;
		scanf("%d %d", &x, &y);
		distance = y - x;
		if (distance <= 3)
			count = distance;
		else {
			key_number = sqrt(distance);
			count = key_number * 2 - 1;
			if (key_number - ((int)key_number) == 0.0);
			else {
				temp_sum = key_number * key_number;
				temp = distance - temp_sum;
				if (temp <= key_number)
					++count;
				else {
					for (j = temp-1; j > 0; --j) {
						++count;
						temp_sum += j;
						if (temp_sum == distance)
							break;
					}
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
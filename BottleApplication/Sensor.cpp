#include "Sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 1 tanimlanmadi, 2 kucuk sise 25 kurus, 3 orta buyuklukte 50 kurus, 4 buyuk sise 100 kurus

int32_t temp_value[4] = { 1,2,3,4 };


void sensor_init() {

	printf("Sensor calibration is done \n");

}
int32_t sensor_Get_Bottle_Value() {

	srand(time(NULL));

	int temp = (rand() % 4) + 1; // rand() % n, 0 ile n-1 arasýnda rastgele bir sayý üretir.
	return temp;

}
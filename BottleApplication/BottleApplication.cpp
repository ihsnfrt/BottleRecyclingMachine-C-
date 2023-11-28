#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include "Sensor.h"
#include "Display.h"
#include "Motor.h"
#include "Counter.h"

int small_bottle = 0;
int medium_bottle = 0;
int large_bottle = 0;


int main()
{
	display_init();
	sensor_init();
	sayac_init(&small_bottle, &medium_bottle, &large_bottle);
	motor_init();
	display_Power_on();


	int desiredchoice = 0;
	int barkod = 0;
	int barkod_read_value;
	int* pdesiredchoice = NULL;
	pdesiredchoice = &desiredchoice;
	int32_t bottle_kind = 0;
	int confirmed = 0;
	int ask_to_user = 1;


	printf("Hos Geldiniz: \n");
	printf("Ucreti Yemek Fisi olarak istiyorsaniz 1'e basiniz \n");
	printf("Ucreti Market Fisi olarak istiyorsaniz 2'ye basiniz \n");

	scanf("%d", &desiredchoice);  //istenilen secime gore en son barkod basilacak

	while (ask_to_user == 1) {
		if (barkod == 0) {      //barkod gorene kadar konveyor ileriye gidecek
			motor_open();
			motor_forward();
		}
		if (barkod == 1) {       //barkod gordugunde motor duracak

			motor_close();
		}
		barkod_read_value = sensor_Get_Bottle_Value();    // barkod tanimina gore sise sayisi artacak

		sayac_calculate(barkod_read_value, &small_bottle, &medium_bottle, &large_bottle);

		printf("Yeni sise atilacak ise 1'e ucreti almak icin 2'ye basiniz");
		scanf("%d", &ask_to_user);

	}
	sayac_money_calculate(&small_bottle, &medium_bottle, &large_bottle);
}




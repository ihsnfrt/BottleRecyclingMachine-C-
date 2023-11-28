#include "Counter.h"
#include "Motor.h"
#include <stdio.h>



void sayac_init(int *s_bottle, int *m_bottle, int *l_bottle) {

	*s_bottle = 0;
	*m_bottle = 0;
	*l_bottle = 0;

}

void sayac_calculate(int sayi, int* s_bottle, int* m_bottle, int* l_bottle) {


	if (sayi == 1) {

		printf("Sise tanimlanmadi \n");
		motor_open();
		motor_Back();
	}

	else if (sayi == 2) {

		printf("Kucuk boy sise tanimlandi \n");
		*s_bottle += 1;
		motor_open();
		motor_forward();
	}

	else if (sayi == 3) {

		printf("Orta boy sise tanimlandi \n");
		*m_bottle += 1;
		motor_open();
		motor_forward();
	}

	else if (sayi == 4) {

		printf("Buyuk boy sise tanimlandi \n");
		*l_bottle += 1;
		motor_open();
		motor_forward();

	}
}

int sayac_money_calculate(int* s_bottle, int* m_bottle, int* l_bottle) {

	int total = 0;
	total = (*s_bottle * 25) + (*m_bottle * 50) + (*l_bottle * 100);

	printf("\n***************************** \n"
		"Toplam Gecerli Kucuk Boy Sise: %d \n "
		"Toplam Gecerli Orta Boy Sise: %d \n "
		"Toplam Gecerli Buyuk Sise: %d \n "
		"******************************* \n", *s_bottle, *m_bottle, *l_bottle);
	printf("Toplam Verilecek tutar %d kurustur \n", total);

	return total;

}
#include "Display.h"
#include "Motor.h"
#include <stdio.h>




void display_init(void) {

	printf("Display init is done \n");

};
void display_Power_on(void) {

	printf("Display is opened \n");

};
void display_Power_off(void) {

	printf("display is closed \n");

};
void display_write_to_screen(int32_t num) {

	printf("**************************");
	printf("Passed bottle is %d", num);
	printf("**************************");

};

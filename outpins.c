//(C) Mike Dorsett 2024.
// GNU General Public licence V3 terms apply.
// test change
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h> 

extern char k1;   //gpioinfo | grep -i -e chip -e P9_25
extern char k2;  // pin value = gpiochip*32+line no.
extern char k3;
extern char k4;
extern char p9_12;
extern char p9_14;


void pinset(){
	FILE *fptr_e;
	fptr_e = fopen("/sys/class/gpio/export","w");
	fprintf(fptr_e,"49");
	fprintf(fptr_e,"111");
	fprintf(fptr_e,"115");
	fprintf(fptr_e,"117");
	fclose(fptr_e);
	fptr_e = fopen("/sys/class/gpio/gpio49/direction","w");
	fprintf(fptr_e,"out");
	fclose(fptr_e);
	fptr_e = fopen("/sys/class/gpio/gpio111/direction","w");
	fprintf(fptr_e,"out");
	fclose(fptr_e);
	fptr_e = fopen("/sys/class/gpio/gpio115/direction","w");
	fprintf(fptr_e,"out");
	fclose(fptr_e);
	fptr_e = fopen("/sys/class/gpio/gpio117/direction","w");
	fprintf(fptr_e,"out");
	fclose(fptr_e);
	return;
}

void pin_write(char pin,char val){
	FILE *fptr_e;
	//printf("%d  >> %d\n",pin,val);
	if (pin==k1){
		fptr_e = fopen("/sys/class/gpio/gpio49/value","w");
		//printf("k1 %d\n",val);
		fprintf(fptr_e,"%d",val);
		fclose(fptr_e);
	}
	if (pin==k2){
		fptr_e = fopen("/sys/class/gpio/gpio111/value","w");
		fprintf(fptr_e,"%d",val);
		fclose(fptr_e);
	}
	if (pin==k3){
		fptr_e = fopen("/sys/class/gpio/gpio115/value","w");
		fprintf(fptr_e,"%d",val);
		fclose(fptr_e);
	}
	if (pin==k4){
		fptr_e = fopen("/sys/class/gpio/gpio117/value","w");
		fprintf(fptr_e,"%d",val);
		fclose(fptr_e);
	}
	return;
}

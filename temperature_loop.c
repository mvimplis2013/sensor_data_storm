#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "temperature_read.h"

int main(int argc, char *argv[]) {
	int i=0;
	
	int ret;
	float temperature_now;
	
	while(1) {
		printf("Now I will collect last temperature sensor data ...%d\n", ++i);
		
		ret = temperature_read(&temperature_now);
		if (ret < 0) {
			perror("temperature_read");
			return -1;
		}
		
		sleep(2);
	}
	
	return 0;
}

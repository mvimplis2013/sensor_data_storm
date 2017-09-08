#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

#define BUF_SIZE 200

int main(int argc, char *argv[]) {
	int fd;
	ssize_t ret;
	char buffer[BUF_SIZE];
	
	fd = open("/sys/bus/w1/devices/28-011627f51bee/w1_slave", O_RDONLY);
	if (fd == -1) {
		perror("open");
		return -1; 
	}
	 
	ret = read(fd, &buffer, BUF_SIZE);
	if (ret == -1) {
		perror("read");
		return -1;
	}	
	
	char *token = strchr(&buffer[0], 't');
	token = strtok(token, " ");
	
	char *temperature = malloc(8);
	int i;
	for (i=0; i<5; i++) {
		temperature[i] = *(token+i+2);
	}
	
	float t = atof(temperature)/ 1000;
	
	printf("%f\n", t);
	
	if (close(fd) == -1) {
		perror("close");
		return -1;
	}
	
	return 0;
}

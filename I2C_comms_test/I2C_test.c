#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
	
	int i2cHandle;
    char filename[40];
    int addr = 0x0C;   // The I2C address of the wingtip board (0x0C)
	char rxBuffer[32];  // receive buffer
    char txBuffer[32];  // transmit buffer
	
	sprintf(filename,"/dev/i2c-1");
	
    printf("Hello! This is a test program for I2C1 communications.\n");
 
    // I2C1 stuff
    if ((i2cHandle = open(filename, O_RDWR)) < 0) {
        perror("Failed to open the i2c bus");
        return(1);
    }
	else {
		printf("Opened I2C1\n");
	}
	
	ioctl(i2cHandle, I2C_TENBIT, 0);  // Tell the device we're not using 10-bit addresses
  
    if (ioctl(i2cHandle,I2C_SLAVE,addr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        exit(1);
    }
	else {
		printf("Opened communications with slave\n");
	}

	// Clear our buffers
    memset(rxBuffer, 0, sizeof(rxBuffer));
    memset(txBuffer, 0, sizeof(txBuffer));
	
	// Do comminucatiosn
	txBuffer[0] = 0x01;
	write(i2cHandle, txBuffer, 1);
	read(i2cHandle, rxBuffer, 6);
 
    // Print the results
    printf("\nhello = %s\n\n",rxBuffer);
	
 	printf("Finished!\n");
    return 0;
}
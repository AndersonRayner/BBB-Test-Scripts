/* A script to test turning the EXT_RST on and off */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

#define MAX_BUF 64
int main(void)
{
   printf("Welcome to RESET THE ARDU!\n\n");

    int fd;
    char buf[MAX_BUF];

	// Access the GPIO
    snprintf(buf, sizeof(buf),"/sys/class/gpio/gpio48/value");

    fd = open(buf, O_WRONLY);

    if (fd < 0) {
        perror("gpio/set-value");
        return fd;
    }
	
	// Turn the Ardu off (set EXT_RST low)
	printf("Turning the arduino off\n");
	write(fd, "0", 2); // Set low
	
	// Wait 5 seconds 
	printf("Waiting five seconds\n");
	sleep(5);
	
	// Turn the Ardu on (set EXT_RST high)
	printf("Turning the arduino on\n");
    write(fd, "1", 2); // Set high

	// Close the GPIO 
    close(fd);
	
	// Return
    return 0;
}

/* Bash Script

// Enable the pin in linux
 echo 48 > /sys/class/gpio/export  
 
 // Set the pin mode to output and set the output to high
 echo high > /sys/class/gpio/gpio48/direction 
 
 // Set the EXT_RST pin low (resets the external boards)
 echo 0 > /sys/class/gpio/gpio48/value 
 
 // Set the EXT_RST pin high (turns on the external boards)
 echo 1 > /sys/class/gpio/gpio48/value 
 
 */

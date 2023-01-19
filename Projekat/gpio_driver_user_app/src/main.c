//User app

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_LEN 80


int main()
{
    int file_desc;
    int ret_val;
    char tmp[BUF_LEN];
    int pin_value;
    char c;
    int speed;
    int speed_new = 0;
    
   
    /* Wait for user command and check if the right key is pressed. */	
        printf("Insert speed of the vehicle: ");
	scanf("%d",&speed);
	
	printf("\n-------------------- Press ENTER to begin --------------------\n");
	while(1)
	{
	    c = getchar();
	    if(c == '\n')
	    {
		break;
	    }
	}
	
	while(1)
	{
		    /* Open gpio_driver file. */			
		    file_desc = open("/dev/gpio_driver", O_RDWR);

		    if(file_desc < 0)
		    {
			    printf("ERROR: 'gpio_driver' not opened\n");
			    return -1;
		    }
		
		    memset(tmp, 0, BUF_LEN);

		    /* Read from gpio_driver file. */
		    ret_val = read(file_desc, tmp, BUF_LEN);
		    if(ret_val != -1)
		    {
			    pin_value = atoi(tmp);
			
			
			    if(pin_value == 0)
			    {
				    if(speed > 0)
				    {
					    speed_new = speed - 10;                          //if the vibration is detected decrease the speed for 10
					    if((speed - 10) == speed_new) 
					    {
						printf("Current speed is: %d \n",speed_new);
						break;
					    }
				    }
			    } 
			    //speed = speed_new;
				    
			   
					
		     } else
		     {
			    printf("ERROR: 'gpio_driver' read problem\n");
			    return -1;
		     }
				
				
		
		    /* Close gpio_driver file. */
		    close(file_desc);
	}
			
			    
    return 0;
}


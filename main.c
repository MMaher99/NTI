
/* FreeRTOS*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "USART.h"
#define F_CPU 16000000UL
TimerHandle_t Timer_Function1;
void MyTimer( TimerHandle_t Timer_Function1 )
{
	PORTD ^=0xff;
	
	/*toggle the led on portD pin 5*/
}
void Task1(void* para)
{
	char in;
	uint16_t period = 100; //initial timer period in ticks
	while(true)
	{
		in=USART_receive(); 
		if (in=='s'){
			
			xTimerStop(Timer_Function1,100);
		}
		else if(in == 'd'){
				xTimerReset(Timer_Function1,100);
				
		}
		else if(in=='r'){
			xTimerChangePeriod(Timer_Function1,period,1000);
			
		}
	    /*
		1. receive a char from the user,then display it on terminal window. 
		
		2. implement the mentioned conditions.
		
		*/

	}
}
int main(void) {
	USART_init();
	DDRD = 0xFF;
	
	Timer_Function1 = xTimerCreate("MyTimer",100,pdTRUE,(void *)0,MyTimer );
	xTimerStart();
	xTaskCreate(Task1,"task1",250,NULL,1,NULL);
	vTaskStartScheduler();
	return 0;
	/*
	1. create a auto-reload timer with periodic ticks = 100.
	
	2. start the timer.
	
	3. create a task which controls the frequency of the timer.
	
	4. start the scheduler.
	
	*/
	
	return 0;
}

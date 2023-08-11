#ifndef KERNEL_PRV_H_
#define	KERNEL_PRV_H_




static void Scheduler(void);




typedef struct
{

	uint16 periodicity;
	uint16 FirstDelay;
	void(*TaskFunc)(void);
	uint8 Suspendded;



}Task_t;


#endif

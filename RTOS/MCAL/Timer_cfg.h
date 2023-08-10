#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/*
 * Choose one of the following Modes: 1-Normal_Mode
									  2-PWM_PhaseCorrect
									  3-CTC_Mode
									  4-Fast_PWM
 */


#define MODE_USED				Fast_PWM

/*
 * Choose the required Prescaler: 1-NO_PRESCALER
								  2-PRESCALER_8
        						  3-PRESCALER_64
        						  4-PRESCALER_256
        						  5-PRESCALER_1024
*/

#define PRESCALER_USED				PRESCALER_64


/** Choose T1 Modes
 * 					1-T1_NormalMode
					2-T1_FastPWM
 */

#define T1_ModeUsed				T1_NormalMode










#endif

#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/EXTI0/EXTI_Interface.h"
#include "../HAL/LED/LED_Interface.h"

/* LED connected to PORTB, PIN1 */
#define LED_PORT    GPIO_PORTB
#define LED_PIN     GPIO_PIN1

/* Callback function - toggles LED */
void Toggle_LED(void)
{
    LED_Toggle(LED_PORT, LED_PIN);
}

void main()
{

    LED_Init(LED_PORT, LED_PIN);

    /* Initialize EXTI */
    EXTI_Init();
    EXTI_SetCallBack(Toggle_LED);
    EXTI_Enable();


    while(1)
    {

    }
}

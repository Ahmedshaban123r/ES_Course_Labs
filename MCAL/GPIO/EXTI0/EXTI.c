#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*EXTI_CallBack)(void) = 0;

void EXTI_Init(void)
{

    TRISB.B0 = 1;


    #if EXTI_EDGE == EXTI_RISING_EDGE

        OPTION_REG.INTEDG = 1;
    #else

        OPTION_REG.INTEDG = 0;
    #endif


    CLR_BIT(INTCON_REG, INTF_POS);

}

void EXTI_SetEdge(u8 Edge)
{
    if (Edge == EXTI_RISING_EDGE)
    {
        SET_BIT(OPTION_REG_ADDR, INTEDG_POS);
    }
    else if (Edge == EXTI_FALLING_EDGE)
    {
        CLR_BIT(OPTION_REG_ADDR, INTEDG_POS);
    }
}

void EXTI_Enable(void)
{
    SET_BIT(INTCON_REG, INTE_POS);
    SET_BIT(INTCON_REG, GIE_POS);
}

void EXTI_Disable(void)
{
    CLR_BIT(INTCON_REG, INTE_POS);
}

void EXTI_SetCallBack(void (*Copy_ptr)(void))
{
    EXTI_CallBack = Copy_ptr;
}


void interrupt()
{
    if (GET_BIT(INTCON_REG, INTF_POS))
    {
        if (EXTI_CallBack != NULL_PTR)
        {
            EXTI_CallBack();
        }

        CLR_BIT(INTCON_REG, INTF_POS);
    }
}

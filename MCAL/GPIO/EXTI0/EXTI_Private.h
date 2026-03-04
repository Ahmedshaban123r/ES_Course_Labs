#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H





/* INTCON Register Address (from pic16f877.h) */
#define INTCON_REG      (*(volatile u8*)0x0B)  // INTCON address

/* INTCON Register Bit Positions */
#define GIE_POS         7      // Global Interrupt Enable bit position
#define INTE_POS        4      // INT0 External Interrupt Enable bit position
#define INTF_POS        1      // INT0 External Interrupt Flag bit position

/* OPTION_REG Register Address */
#define OPTION_REG_ADDR (*(volatile u8*)0x81)  // OPTION_REG address (Bank 1)

/* OPTION_REG Bit Positions */
#define INTEDG_POS      6      // Interrupt Edge Select bit position

#endif

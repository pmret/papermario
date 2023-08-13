#ifndef _BCP_H_
#define _BCP_H_
#ifdef BBPLAYER

#include "rcp.h"

/**
 * MIPS Interface (MI) Additional Registers
 */

//! MI_SK_EXCEPTION_REG ?
#define MI_14_REG (MI_BASE_REG + 0x14)



//! ?
#define MI_30_REG (MI_BASE_REG + 0x30)



//! ?
#define MI_38_REG (MI_BASE_REG + 0x38)



//! MI_HW_INTR_MASK_REG ?
#define MI_3C_REG (MI_BASE_REG + 0x3C)



/**
 * Peripheral Interface (PI) Additional Registers 
 */

//! PI_ATB_UPPER_REG ?
#define PI_40_REG (PI_BASE_REG + 0x40)



//! ?
#define PI_44_REG (PI_BASE_REG + 0x44)



//! PI_CARD_CNT_REG ?
#define PI_48_REG (PI_BASE_REG + 0x48)



//! ?
#define PI_4C_REG (PI_BASE_REG + 0x4C)



//! PI_AES_CNT_REG ?
#define PI_50_REG (PI_BASE_REG + 0x50)



//! PI_ALLOWED_IO_REG ?
#define PI_54_REG (PI_BASE_REG + 0x54)



//! ?
#define PI_58_REG (PI_BASE_REG + 0x58)



//! ?
#define PI_5C_REG (PI_BASE_REG + 0x5C)



//! PI_MISC_REG ?
#define PI_60_REG (PI_BASE_REG + 0x60)



//! ?
#define PI_64_REG (PI_BASE_REG + 0x64)



//! PI_CARD_BLK_OFFSET_REG ?
#define PI_70_REG (PI_BASE_REG + 0x70)



//! PI_EX_DMA_BUF ?
#define PI_10000_REG(i) (PI_BASE_REG + 0x10000 + (i))



//! PI_ATB_LOWER_REG ?
#define PI_10500_REG(i) (PI_BASE_REG + 0x10500 + (i) * 4)



/**
 * Serial Interface (SI) Additional Registers
 */

//! ?
#define SI_0C_REG (SI_BASE_REG + 0x0C)



//! ?
#define SI_1C_REG (SI_BASE_REG + 0x1C)



#endif
#endif

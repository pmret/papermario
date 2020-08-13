
/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.
        
        $RCSfile: os_gbpak.h,v $
        $Revision: 1.1 $
        $Date: 1998/10/09 08:01:07 $
 *---------------------------------------------------------------------*/

#ifndef _OS_GBPAK_H_
#define	_OS_GBPAK_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"
#include "os_pfs.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

typedef struct {
  u16	fixed1;
  u16	start_address;
  u8	nintendo_chr[0x30];
  u8	game_title[16];
  u16	company_code;
  u8	body_code;
  u8	cart_type;
  u8	rom_size;
  u8	ram_size;
  u8	country_code;
  u8	fixed2;
  u8	version;
  u8	isum;
  u16	sum;
} OSGbpakId;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* definition for 64GB-PAK */

#define OS_GBPAK_POWER          0x01
#define OS_GBPAK_RSTB_DETECTION 0x04
#define OS_GBPAK_RSTB_STATUS    0x08
#define OS_GBPAK_GBCART_PULL    0x40
#define OS_GBPAK_GBCART_ON      0x80

#define	OS_GBPAK_POWER_OFF	0x00 	/* power of 64GB-PAK */
#define	OS_GBPAK_POWER_ON	0x01

#define	OS_GBPAK_ROM_ID_SIZE	0x50	/* ID size of GB cartridge */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* 64GB-PAK */
extern  s32     osGbpakInit(OSMesgQueue *, OSPfs *, int);
extern  s32     osGbpakPower(OSPfs *, s32);
extern  s32     osGbpakGetStatus(OSPfs *, u8 *);
extern  s32     osGbpakReadWrite(OSPfs *, u16, u16, u8 *, u16);
extern  s32     osGbpakReadId(OSPfs *, OSGbpakId *, u8 *);
extern  s32	osGbpakCheckConnector(OSPfs *, u8 *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_GBPAK_H_ */

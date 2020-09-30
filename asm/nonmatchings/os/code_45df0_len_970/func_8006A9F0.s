.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006A9F0
/* 45DF0 8006A9F0 3C1A8007 */  lui       $k0, 0x8007
/* 45DF4 8006A9F4 275AAA00 */  addiu     $k0, $k0, -0x5600
/* 45DF8 8006A9F8 03400008 */  jr        $k0
/* 45DFC 8006A9FC 00000000 */   nop      

.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osViGetNextFramebuffer
/* 041DF0 800669F0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 041DF4 800669F4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 041DF8 800669F8 0C01ACD8 */  jal   __osDisableInt
/* 041DFC 800669FC AFB00010 */   sw    $s0, 0x10($sp)
/* 041E00 80066A00 3C038009 */  lui   $v1, 0x8009
/* 041E04 80066A04 8C6359D4 */  lw    $v1, 0x59d4($v1)
/* 041E08 80066A08 8C700004 */  lw    $s0, 4($v1)
/* 041E0C 80066A0C 0C01ACF4 */  jal   __osRestoreInt
/* 041E10 80066A10 00402021 */   addu  $a0, $v0, $zero
/* 041E14 80066A14 02001021 */  addu  $v0, $s0, $zero
/* 041E18 80066A18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 041E1C 80066A1C 8FB00010 */  lw    $s0, 0x10($sp)
/* 041E20 80066A20 03E00008 */  jr    $ra
/* 041E24 80066A24 27BD0018 */   addiu $sp, $sp, 0x18

/* 041E28 80066A28 00000000 */  nop   
/* 041E2C 80066A2C 00000000 */  nop   

.set reorder

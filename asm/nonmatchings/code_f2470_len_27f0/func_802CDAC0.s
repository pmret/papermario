.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802CDAC0
/* 0F2470 802CDAC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F2474 802CDAC4 0080182D */  daddu $v1, $a0, $zero
/* 0F2478 802CDAC8 00A0202D */  daddu $a0, $a1, $zero
/* 0F247C 802CDACC 2402FFFF */  addiu $v0, $zero, -1
/* 0F2480 802CDAD0 14820004 */  bne   $a0, $v0, .L802CDAE4
/* 0F2484 802CDAD4 AFBF0010 */   sw    $ra, 0x10($sp)
/* 0F2488 802CDAD8 8C64014C */  lw    $a0, 0x14c($v1)
/* 0F248C 802CDADC 080B36BE */  j     .L802CDAF8
/* 0F2490 802CDAE0 00000000 */   nop   

.L802CDAE4:
/* 0F2494 802CDAE4 3C02EFE8 */  lui   $v0, 0xefe8
/* 0F2498 802CDAE8 34422080 */  ori   $v0, $v0, 0x2080
/* 0F249C 802CDAEC 0082102A */  slt   $v0, $a0, $v0
/* 0F24A0 802CDAF0 14400003 */  bnez  $v0, .L802CDB00
/* 0F24A4 802CDAF4 0080102D */   daddu $v0, $a0, $zero
.L802CDAF8:
/* 0F24A8 802CDAF8 0C00EAD2 */  jal   get_npc_safe
/* 0F24AC 802CDAFC 00000000 */   nop   
.L802CDB00:
/* 0F24B0 802CDB00 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F24B4 802CDB04 03E00008 */  jr    $ra
/* 0F24B8 802CDB08 27BD0018 */   addiu $sp, $sp, 0x18


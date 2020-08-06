.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osInsertTimer
/* 041A90 80066690 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 041A94 80066694 AFB20018 */  sw    $s2, 0x18($sp)
/* 041A98 80066698 00809021 */  addu  $s2, $a0, $zero
/* 041A9C 8006669C AFBF001C */  sw    $ra, 0x1c($sp)
/* 041AA0 800666A0 AFB10014 */  sw    $s1, 0x14($sp)
/* 041AA4 800666A4 0C01ACD8 */  jal   __osDisableInt
/* 041AA8 800666A8 AFB00010 */   sw    $s0, 0x10($sp)
/* 041AAC 800666AC 3C038009 */  lui   $v1, 0x8009
/* 041AB0 800666B0 8C634670 */  lw    $v1, 0x4670($v1)
/* 041AB4 800666B4 8C660000 */  lw    $a2, ($v1)
/* 041AB8 800666B8 8E500010 */  lw    $s0, 0x10($s2)
/* 041ABC 800666BC 8E510014 */  lw    $s1, 0x14($s2)
/* 041AC0 800666C0 10C30017 */  beq   $a2, $v1, .L80066720
/* 041AC4 800666C4 00403821 */   addu  $a3, $v0, $zero
/* 041AC8 800666C8 080199BE */  j     .L800666F8
/* 041ACC 800666CC 00000000 */   nop   

.L800666D0:
/* 041AD0 800666D0 8CC20010 */  lw    $v0, 0x10($a2)
/* 041AD4 800666D4 8CC30014 */  lw    $v1, 0x14($a2)
/* 041AD8 800666D8 8CC60000 */  lw    $a2, ($a2)
/* 041ADC 800666DC 3C048009 */  lui   $a0, 0x8009
/* 041AE0 800666E0 8C844670 */  lw    $a0, 0x4670($a0)
/* 041AE4 800666E4 0223282B */  sltu  $a1, $s1, $v1
/* 041AE8 800666E8 02238823 */  subu  $s1, $s1, $v1
/* 041AEC 800666EC 02028023 */  subu  $s0, $s0, $v0
/* 041AF0 800666F0 10C4000B */  beq   $a2, $a0, .L80066720
/* 041AF4 800666F4 02058023 */   subu  $s0, $s0, $a1
.L800666F8:
/* 041AF8 800666F8 8CC30010 */  lw    $v1, 0x10($a2)
/* 041AFC 800666FC 0070102B */  sltu  $v0, $v1, $s0
/* 041B00 80066700 1440FFF3 */  bnez  $v0, .L800666D0
/* 041B04 80066704 00000000 */   nop   
/* 041B08 80066708 16030005 */  bne   $s0, $v1, .L80066720
/* 041B0C 8006670C 00000000 */   nop   
/* 041B10 80066710 8CC20014 */  lw    $v0, 0x14($a2)
/* 041B14 80066714 0051102B */  sltu  $v0, $v0, $s1
/* 041B18 80066718 1440FFED */  bnez  $v0, .L800666D0
/* 041B1C 8006671C 00000000 */   nop   
.L80066720:
/* 041B20 80066720 3C028009 */  lui   $v0, 0x8009
/* 041B24 80066724 8C424670 */  lw    $v0, 0x4670($v0)
/* 041B28 80066728 AE500010 */  sw    $s0, 0x10($s2)
/* 041B2C 8006672C AE510014 */  sw    $s1, 0x14($s2)
/* 041B30 80066730 50C2000A */  beql  $a2, $v0, .L8006675C
/* 041B34 80066734 AE460000 */   sw    $a2, ($s2)
/* 041B38 80066738 8CC20010 */  lw    $v0, 0x10($a2)
/* 041B3C 8006673C 8CC30014 */  lw    $v1, 0x14($a2)
/* 041B40 80066740 0071202B */  sltu  $a0, $v1, $s1
/* 041B44 80066744 00711823 */  subu  $v1, $v1, $s1
/* 041B48 80066748 00501023 */  subu  $v0, $v0, $s0
/* 041B4C 8006674C 00441023 */  subu  $v0, $v0, $a0
/* 041B50 80066750 ACC20010 */  sw    $v0, 0x10($a2)
/* 041B54 80066754 ACC30014 */  sw    $v1, 0x14($a2)
/* 041B58 80066758 AE460000 */  sw    $a2, ($s2)
.L8006675C:
/* 041B5C 8006675C 8CC20004 */  lw    $v0, 4($a2)
/* 041B60 80066760 AE420004 */  sw    $v0, 4($s2)
/* 041B64 80066764 8CC20004 */  lw    $v0, 4($a2)
/* 041B68 80066768 00E02021 */  addu  $a0, $a3, $zero
/* 041B6C 8006676C AC520000 */  sw    $s2, ($v0)
/* 041B70 80066770 0C01ACF4 */  jal   __osRestoreInt
/* 041B74 80066774 ACD20004 */   sw    $s2, 4($a2)
/* 041B78 80066778 02001021 */  addu  $v0, $s0, $zero
/* 041B7C 8006677C 02201821 */  addu  $v1, $s1, $zero
/* 041B80 80066780 8FBF001C */  lw    $ra, 0x1c($sp)
/* 041B84 80066784 8FB20018 */  lw    $s2, 0x18($sp)
/* 041B88 80066788 8FB10014 */  lw    $s1, 0x14($sp)
/* 041B8C 8006678C 8FB00010 */  lw    $s0, 0x10($sp)
/* 041B90 80066790 03E00008 */  jr    $ra
/* 041B94 80066794 27BD0020 */   addiu $sp, $sp, 0x20

/* 041B98 80066798 00000000 */  nop   
/* 041B9C 8006679C 00000000 */  nop   



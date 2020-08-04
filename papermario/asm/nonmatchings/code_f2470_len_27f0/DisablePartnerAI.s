.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel DisablePartnerAI
/* 0F3E98 802CF4E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F3E9C 802CF4EC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F3EA0 802CF4F0 8C82000C */  lw    $v0, 0xc($a0)
/* 0F3EA4 802CF4F4 0C0B1EAF */  jal   get_variable
/* 0F3EA8 802CF4F8 8C450000 */   lw    $a1, ($v0)
/* 0F3EAC 802CF4FC 14400005 */  bnez  $v0, .L802CF514
/* 0F3EB0 802CF500 00000000 */   nop   
/* 0F3EB4 802CF504 0C03BCC5 */  jal   func_800EF314
/* 0F3EB8 802CF508 00000000 */   nop   
/* 0F3EBC 802CF50C 080B3D47 */  j     .L802CF51C
/* 0F3EC0 802CF510 00000000 */   nop   

.L802CF514:
/* 0F3EC4 802CF514 0C03BCC0 */  jal   func_800EF300
/* 0F3EC8 802CF518 00000000 */   nop   
.L802CF51C:
/* 0F3ECC 802CF51C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F3ED0 802CF520 24020002 */  addiu $v0, $zero, 2
/* 0F3ED4 802CF524 03E00008 */  jr    $ra
/* 0F3ED8 802CF528 27BD0018 */   addiu $sp, $sp, 0x18


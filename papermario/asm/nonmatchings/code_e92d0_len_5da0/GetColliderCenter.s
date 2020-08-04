.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetColliderCenter
/* 0EEA5C 802CA0AC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EEA60 802CA0B0 AFB00020 */  sw    $s0, 0x20($sp)
/* 0EEA64 802CA0B4 0080802D */  daddu $s0, $a0, $zero
/* 0EEA68 802CA0B8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0EEA6C 802CA0BC 8E02000C */  lw    $v0, 0xc($s0)
/* 0EEA70 802CA0C0 0C0B1EAF */  jal   get_variable
/* 0EEA74 802CA0C4 8C450000 */   lw    $a1, ($v0)
/* 0EEA78 802CA0C8 0040202D */  daddu $a0, $v0, $zero
/* 0EEA7C 802CA0CC 27A50010 */  addiu $a1, $sp, 0x10
/* 0EEA80 802CA0D0 27A60014 */  addiu $a2, $sp, 0x14
/* 0EEA84 802CA0D4 0C016F84 */  jal   get_collider_center
/* 0EEA88 802CA0D8 27A70018 */   addiu $a3, $sp, 0x18
/* 0EEA8C 802CA0DC C7A00010 */  lwc1  $f0, 0x10($sp)
/* 0EEA90 802CA0E0 4600010D */  trunc.w.s $f4, $f0
/* 0EEA94 802CA0E4 E6040084 */  swc1  $f4, 0x84($s0)
/* 0EEA98 802CA0E8 C7A00014 */  lwc1  $f0, 0x14($sp)
/* 0EEA9C 802CA0EC C7A20018 */  lwc1  $f2, 0x18($sp)
/* 0EEAA0 802CA0F0 4600010D */  trunc.w.s $f4, $f0
/* 0EEAA4 802CA0F4 E6040088 */  swc1  $f4, 0x88($s0)
/* 0EEAA8 802CA0F8 4600110D */  trunc.w.s $f4, $f2
/* 0EEAAC 802CA0FC E604008C */  swc1  $f4, 0x8c($s0)
/* 0EEAB0 802CA100 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0EEAB4 802CA104 8FB00020 */  lw    $s0, 0x20($sp)
/* 0EEAB8 802CA108 24020002 */  addiu $v0, $zero, 2
/* 0EEABC 802CA10C 03E00008 */  jr    $ra
/* 0EEAC0 802CA110 27BD0028 */   addiu $sp, $sp, 0x28


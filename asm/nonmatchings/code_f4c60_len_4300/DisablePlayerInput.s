.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel DisablePlayerInput
/* 0F57D8 802D0E28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F57DC 802D0E2C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F57E0 802D0E30 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F57E4 802D0E34 8C82000C */  lw    $v0, 0xc($a0)
/* 0F57E8 802D0E38 8C450000 */  lw    $a1, ($v0)
/* 0F57EC 802D0E3C 3C108011 */  lui   $s0, 0x8011
/* 0F57F0 802D0E40 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 0F57F4 802D0E44 0C0B1EAF */  jal   get_variable
/* 0F57F8 802D0E48 00000000 */   nop   
/* 0F57FC 802D0E4C 10400016 */  beqz  $v0, .L802D0EA8
/* 0F5800 802D0E50 00000000 */   nop   
/* 0F5804 802D0E54 0C03805E */  jal   func_800E0178
/* 0F5808 802D0E58 00000000 */   nop   
/* 0F580C 802D0E5C 0C03BD8A */  jal   func_800EF628
/* 0F5810 802D0E60 00000000 */   nop   
/* 0F5814 802D0E64 0C03A5EE */  jal   func_800E97B8
/* 0F5818 802D0E68 00000000 */   nop   
/* 0F581C 802D0E6C 0C03A613 */  jal   func_800E984C
/* 0F5820 802D0E70 00000000 */   nop   
/* 0F5824 802D0E74 820300B4 */  lb    $v1, 0xb4($s0)
/* 0F5828 802D0E78 2402001A */  addiu $v0, $zero, 0x1a
/* 0F582C 802D0E7C 14620004 */  bne   $v1, $v0, .L802D0E90
/* 0F5830 802D0E80 3C030004 */   lui   $v1, 4
/* 0F5834 802D0E84 8E020004 */  lw    $v0, 4($s0)
/* 0F5838 802D0E88 00431025 */  or    $v0, $v0, $v1
/* 0F583C 802D0E8C AE020004 */  sw    $v0, 4($s0)
.L802D0E90:
/* 0F5840 802D0E90 3C03800A */  lui   $v1, 0x800a
/* 0F5844 802D0E94 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0F5848 802D0E98 8C620000 */  lw    $v0, ($v1)
/* 0F584C 802D0E9C 34420040 */  ori   $v0, $v0, 0x40
/* 0F5850 802D0EA0 080B43B7 */  j     .L802D0EDC
/* 0F5854 802D0EA4 AC620000 */   sw    $v0, ($v1)

.L802D0EA8:
/* 0F5858 802D0EA8 0C038069 */  jal   func_800E01A4
/* 0F585C 802D0EAC 00000000 */   nop   
/* 0F5860 802D0EB0 0C03BD80 */  jal   func_800EF600
/* 0F5864 802D0EB4 00000000 */   nop   
/* 0F5868 802D0EB8 0C038077 */  jal   func_800E01DC
/* 0F586C 802D0EBC 00000000 */   nop   
/* 0F5870 802D0EC0 3C02800A */  lui   $v0, 0x800a
/* 0F5874 802D0EC4 2442A650 */  addiu $v0, $v0, -0x59b0
/* 0F5878 802D0EC8 8C430000 */  lw    $v1, ($v0)
/* 0F587C 802D0ECC 2404FFBF */  addiu $a0, $zero, -0x41
/* 0F5880 802D0ED0 00641824 */  and   $v1, $v1, $a0
/* 0F5884 802D0ED4 0C03A60F */  jal   func_800E983C
/* 0F5888 802D0ED8 AC430000 */   sw    $v1, ($v0)
.L802D0EDC:
/* 0F588C 802D0EDC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F5890 802D0EE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F5894 802D0EE4 24020002 */  addiu $v0, $zero, 2
/* 0F5898 802D0EE8 03E00008 */  jr    $ra
/* 0F589C 802D0EEC 27BD0018 */   addiu $sp, $sp, 0x18


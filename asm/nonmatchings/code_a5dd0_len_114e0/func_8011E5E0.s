.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011E5E0
/* 0B4CE0 8011E5E0 3C038015 */  lui   $v1, 0x8015
/* 0B4CE4 8011E5E4 8C633A40 */  lw    $v1, 0x3a40($v1)
/* 0B4CE8 8011E5E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B4CEC 8011E5EC AFB10014 */  sw    $s1, 0x14($sp)
/* 0B4CF0 8011E5F0 0080882D */  daddu $s1, $a0, $zero
/* 0B4CF4 8011E5F4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0B4CF8 8011E5F8 00A0902D */  daddu $s2, $a1, $zero
/* 0B4CFC 8011E5FC AFB00010 */  sw    $s0, 0x10($sp)
/* 0B4D00 8011E600 0000802D */  daddu $s0, $zero, $zero
/* 0B4D04 8011E604 AFBF001C */  sw    $ra, 0x1c($sp)
.L8011E608:
/* 0B4D08 8011E608 8C620000 */  lw    $v0, ($v1)
/* 0B4D0C 8011E60C 10400006 */  beqz  $v0, .L8011E628
/* 0B4D10 8011E610 2A020010 */   slti  $v0, $s0, 0x10
/* 0B4D14 8011E614 26100001 */  addiu $s0, $s0, 1
/* 0B4D18 8011E618 2A020010 */  slti  $v0, $s0, 0x10
/* 0B4D1C 8011E61C 1440FFFA */  bnez  $v0, .L8011E608
/* 0B4D20 8011E620 24630004 */   addiu $v1, $v1, 4
/* 0B4D24 8011E624 2A020010 */  slti  $v0, $s0, 0x10
.L8011E628:
/* 0B4D28 8011E628 14400003 */  bnez  $v0, .L8011E638
/* 0B4D2C 8011E62C 00000000 */   nop   
.L8011E630:
/* 0B4D30 8011E630 0804798C */  j     .L8011E630
/* 0B4D34 8011E634 00000000 */   nop   

.L8011E638:
/* 0B4D38 8011E638 0C00AB39 */  jal   heap_malloc
/* 0B4D3C 8011E63C 240402E0 */   addiu $a0, $zero, 0x2e0
/* 0B4D40 8011E640 00102080 */  sll   $a0, $s0, 2
/* 0B4D44 8011E644 3C038015 */  lui   $v1, 0x8015
/* 0B4D48 8011E648 8C633A40 */  lw    $v1, 0x3a40($v1)
/* 0B4D4C 8011E64C 3C058015 */  lui   $a1, 0x8015
/* 0B4D50 8011E650 24A512D4 */  addiu $a1, $a1, 0x12d4
/* 0B4D54 8011E654 00832021 */  addu  $a0, $a0, $v1
/* 0B4D58 8011E658 8CA30000 */  lw    $v1, ($a1)
/* 0B4D5C 8011E65C 0040302D */  daddu $a2, $v0, $zero
/* 0B4D60 8011E660 AC860000 */  sw    $a2, ($a0)
/* 0B4D64 8011E664 24630001 */  addiu $v1, $v1, 1
/* 0B4D68 8011E668 14C00003 */  bnez  $a2, .L8011E678
/* 0B4D6C 8011E66C ACA30000 */   sw    $v1, ($a1)
.L8011E670:
/* 0B4D70 8011E670 0804799C */  j     .L8011E670
/* 0B4D74 8011E674 00000000 */   nop   

.L8011E678:
/* 0B4D78 8011E678 3C0300FF */  lui   $v1, 0xff
/* 0B4D7C 8011E67C 3463FFFF */  ori   $v1, $v1, 0xffff
/* 0B4D80 8011E680 0000202D */  daddu $a0, $zero, $zero
/* 0B4D84 8011E684 24020057 */  addiu $v0, $zero, 0x57
/* 0B4D88 8011E688 ACC20000 */  sw    $v0, ($a2)
/* 0B4D8C 8011E68C 2402000D */  addiu $v0, $zero, 0xd
/* 0B4D90 8011E690 02231824 */  and   $v1, $s1, $v1
/* 0B4D94 8011E694 A0C20004 */  sb    $v0, 4($a2)
/* 0B4D98 8011E698 ACD200DC */  sw    $s2, 0xdc($a2)
/* 0B4D9C 8011E69C 0240102D */  daddu $v0, $s2, $zero
/* 0B4DA0 8011E6A0 3C013F80 */  lui   $at, 0x3f80
/* 0B4DA4 8011E6A4 44810000 */  mtc1  $at, $f0
/* 0B4DA8 8011E6A8 00628821 */  addu  $s1, $v1, $v0
/* 0B4DAC 8011E6AC ACC000D8 */  sw    $zero, 0xd8($a2)
/* 0B4DB0 8011E6B0 ACC002D4 */  sw    $zero, 0x2d4($a2)
/* 0B4DB4 8011E6B4 ACC00010 */  sw    $zero, 0x10($a2)
/* 0B4DB8 8011E6B8 A0C00014 */  sb    $zero, 0x14($a2)
/* 0B4DBC 8011E6BC ACD10008 */  sw    $s1, 8($a2)
/* 0B4DC0 8011E6C0 ACD1000C */  sw    $s1, 0xc($a2)
/* 0B4DC4 8011E6C4 E4C00090 */  swc1  $f0, 0x90($a2)
/* 0B4DC8 8011E6C8 E4C00094 */  swc1  $f0, 0x94($a2)
/* 0B4DCC 8011E6CC 00C41821 */  addu  $v1, $a2, $a0
.L8011E6D0:
/* 0B4DD0 8011E6D0 24820001 */  addiu $v0, $a0, 1
/* 0B4DD4 8011E6D4 A0620015 */  sb    $v0, 0x15($v1)
/* 0B4DD8 8011E6D8 0040202D */  daddu $a0, $v0, $zero
/* 0B4DDC 8011E6DC 2882007A */  slti  $v0, $a0, 0x7a
/* 0B4DE0 8011E6E0 5440FFFB */  bnel  $v0, $zero, .L8011E6D0
/* 0B4DE4 8011E6E4 00C41821 */   addu  $v1, $a2, $a0
/* 0B4DE8 8011E6E8 3C028007 */  lui   $v0, 0x8007
/* 0B4DEC 8011E6EC 8C42419C */  lw    $v0, 0x419c($v0)
/* 0B4DF0 8011E6F0 80420070 */  lb    $v0, 0x70($v0)
/* 0B4DF4 8011E6F4 54400001 */  bnel  $v0, $zero, .L8011E6FC
/* 0B4DF8 8011E6F8 36100800 */   ori   $s0, $s0, 0x800
.L8011E6FC:
/* 0B4DFC 8011E6FC 0200102D */  daddu $v0, $s0, $zero
/* 0B4E00 8011E700 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0B4E04 8011E704 8FB20018 */  lw    $s2, 0x18($sp)
/* 0B4E08 8011E708 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B4E0C 8011E70C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B4E10 8011E710 03E00008 */  jr    $ra
/* 0B4E14 8011E714 27BD0020 */   addiu $sp, $sp, 0x20


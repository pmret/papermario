.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80117E74
/* 0AE574 80117E74 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0AE578 80117E78 AFB20018 */  sw    $s2, 0x18($sp)
/* 0AE57C 80117E7C 0080902D */  daddu $s2, $a0, $zero
/* 0AE580 80117E80 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0AE584 80117E84 3C13800A */  lui   $s3, 0x800a
/* 0AE588 80117E88 2673A66C */  addiu $s3, $s3, -0x5994
/* 0AE58C 80117E8C AFBF0020 */  sw    $ra, 0x20($sp)
/* 0AE590 80117E90 AFB10014 */  sw    $s1, 0x14($sp)
/* 0AE594 80117E94 12400056 */  beqz  $s2, .L80117FF0
/* 0AE598 80117E98 AFB00010 */   sw    $s0, 0x10($sp)
/* 0AE59C 80117E9C 8E430000 */  lw    $v1, ($s2)
/* 0AE5A0 80117EA0 24020005 */  addiu $v0, $zero, 5
/* 0AE5A4 80117EA4 14620017 */  bne   $v1, $v0, .L80117F04
/* 0AE5A8 80117EA8 24020002 */   addiu $v0, $zero, 2
/* 0AE5AC 80117EAC 0C0456C3 */  jal   get_model_property
/* 0AE5B0 80117EB0 24050060 */   addiu $a1, $zero, 0x60
/* 0AE5B4 80117EB4 10400011 */  beqz  $v0, .L80117EFC
/* 0AE5B8 80117EB8 00000000 */   nop   
/* 0AE5BC 80117EBC 8C420008 */  lw    $v0, 8($v0)
/* 0AE5C0 80117EC0 1040000E */  beqz  $v0, .L80117EFC
/* 0AE5C4 80117EC4 00000000 */   nop   
/* 0AE5C8 80117EC8 3C108015 */  lui   $s0, 0x8015
/* 0AE5CC 80117ECC 2610336C */  addiu $s0, $s0, 0x336c
/* 0AE5D0 80117ED0 0C046B4C */  jal   get_model_from_list_index
/* 0AE5D4 80117ED4 96040000 */   lhu   $a0, ($s0)
/* 0AE5D8 80117ED8 0040202D */  daddu $a0, $v0, $zero
/* 0AE5DC 80117EDC 94820000 */  lhu   $v0, ($a0)
/* 0AE5E0 80117EE0 30420002 */  andi  $v0, $v0, 2
/* 0AE5E4 80117EE4 1440003F */  bnez  $v0, .L80117FE4
/* 0AE5E8 80117EE8 00000000 */   nop   
/* 0AE5EC 80117EEC 0C045F25 */  jal   func_80117C94
/* 0AE5F0 80117EF0 00000000 */   nop   
/* 0AE5F4 80117EF4 08045FF9 */  j     .L80117FE4
/* 0AE5F8 80117EF8 00000000 */   nop   

.L80117EFC:
/* 0AE5FC 80117EFC 8E430000 */  lw    $v1, ($s2)
/* 0AE600 80117F00 24020002 */  addiu $v0, $zero, 2
.L80117F04:
/* 0AE604 80117F04 1062002C */  beq   $v1, $v0, .L80117FB8
/* 0AE608 80117F08 00000000 */   nop   
/* 0AE60C 80117F0C 8E420010 */  lw    $v0, 0x10($s2)
/* 0AE610 80117F10 10400037 */  beqz  $v0, .L80117FF0
/* 0AE614 80117F14 00000000 */   nop   
/* 0AE618 80117F18 8C420000 */  lw    $v0, ($v0)
/* 0AE61C 80117F1C 10400009 */  beqz  $v0, .L80117F44
/* 0AE620 80117F20 3C02DA38 */   lui   $v0, 0xda38
/* 0AE624 80117F24 8E630000 */  lw    $v1, ($s3)
/* 0AE628 80117F28 0060202D */  daddu $a0, $v1, $zero
/* 0AE62C 80117F2C AC820000 */  sw    $v0, ($a0)
/* 0AE630 80117F30 8E420010 */  lw    $v0, 0x10($s2)
/* 0AE634 80117F34 8C420000 */  lw    $v0, ($v0)
/* 0AE638 80117F38 24630008 */  addiu $v1, $v1, 8
/* 0AE63C 80117F3C AE630000 */  sw    $v1, ($s3)
/* 0AE640 80117F40 AC820004 */  sw    $v0, 4($a0)
.L80117F44:
/* 0AE644 80117F44 8E420010 */  lw    $v0, 0x10($s2)
/* 0AE648 80117F48 8C51000C */  lw    $s1, 0xc($v0)
/* 0AE64C 80117F4C 1220000E */  beqz  $s1, .L80117F88
/* 0AE650 80117F50 00000000 */   nop   
/* 0AE654 80117F54 1A20000C */  blez  $s1, .L80117F88
/* 0AE658 80117F58 0000802D */   daddu $s0, $zero, $zero
.L80117F5C:
/* 0AE65C 80117F5C 8E420010 */  lw    $v0, 0x10($s2)
/* 0AE660 80117F60 8C430010 */  lw    $v1, 0x10($v0)
/* 0AE664 80117F64 00101080 */  sll   $v0, $s0, 2
/* 0AE668 80117F68 00431021 */  addu  $v0, $v0, $v1
/* 0AE66C 80117F6C 8C440000 */  lw    $a0, ($v0)
/* 0AE670 80117F70 0C045F9D */  jal   func_80117E74
/* 0AE674 80117F74 26100001 */   addiu $s0, $s0, 1
/* 0AE678 80117F78 0211102A */  slt   $v0, $s0, $s1
/* 0AE67C 80117F7C 1440FFF7 */  bnez  $v0, .L80117F5C
/* 0AE680 80117F80 00000000 */   nop   
/* 0AE684 80117F84 8E420010 */  lw    $v0, 0x10($s2)
.L80117F88:
/* 0AE688 80117F88 8C420000 */  lw    $v0, ($v0)
/* 0AE68C 80117F8C 10400018 */  beqz  $v0, .L80117FF0
/* 0AE690 80117F90 3C04D838 */   lui   $a0, 0xd838
/* 0AE694 80117F94 8E620000 */  lw    $v0, ($s3)
/* 0AE698 80117F98 34840002 */  ori   $a0, $a0, 2
/* 0AE69C 80117F9C 0040182D */  daddu $v1, $v0, $zero
/* 0AE6A0 80117FA0 24420008 */  addiu $v0, $v0, 8
/* 0AE6A4 80117FA4 AE620000 */  sw    $v0, ($s3)
/* 0AE6A8 80117FA8 24020040 */  addiu $v0, $zero, 0x40
/* 0AE6AC 80117FAC AC640000 */  sw    $a0, ($v1)
/* 0AE6B0 80117FB0 08045FFC */  j     .L80117FF0
/* 0AE6B4 80117FB4 AC620004 */   sw    $v0, 4($v1)

.L80117FB8:
/* 0AE6B8 80117FB8 3C108015 */  lui   $s0, 0x8015
/* 0AE6BC 80117FBC 2610336C */  addiu $s0, $s0, 0x336c
/* 0AE6C0 80117FC0 0C046B4C */  jal   get_model_from_list_index
/* 0AE6C4 80117FC4 96040000 */   lhu   $a0, ($s0)
/* 0AE6C8 80117FC8 0040202D */  daddu $a0, $v0, $zero
/* 0AE6CC 80117FCC 94820000 */  lhu   $v0, ($a0)
/* 0AE6D0 80117FD0 30420002 */  andi  $v0, $v0, 2
/* 0AE6D4 80117FD4 14400003 */  bnez  $v0, .L80117FE4
/* 0AE6D8 80117FD8 00000000 */   nop   
/* 0AE6DC 80117FDC 0C044C24 */  jal   func_80113090
/* 0AE6E0 80117FE0 00000000 */   nop   
.L80117FE4:
/* 0AE6E4 80117FE4 96020000 */  lhu   $v0, ($s0)
/* 0AE6E8 80117FE8 24420001 */  addiu $v0, $v0, 1
/* 0AE6EC 80117FEC A6020000 */  sh    $v0, ($s0)
.L80117FF0:
/* 0AE6F0 80117FF0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0AE6F4 80117FF4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0AE6F8 80117FF8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0AE6FC 80117FFC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0AE700 80118000 8FB00010 */  lw    $s0, 0x10($sp)
/* 0AE704 80118004 03E00008 */  jr    $ra
/* 0AE708 80118008 27BD0028 */   addiu $sp, $sp, 0x28

/* 0AE70C 8011800C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0AE710 80118010 0080282D */  daddu $a1, $a0, $zero
/* 0AE714 80118014 AFB10014 */  sw    $s1, 0x14($sp)
/* 0AE718 80118018 00A0882D */  daddu $s1, $a1, $zero
/* 0AE71C 8011801C AFB00010 */  sw    $s0, 0x10($sp)
/* 0AE720 80118020 3C10800A */  lui   $s0, 0x800a
/* 0AE724 80118024 2610A66C */  addiu $s0, $s0, -0x5994
/* 0AE728 80118028 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AE72C 8011802C AFB20018 */  sw    $s2, 0x18($sp)
/* 0AE730 80118030 94A20000 */  lhu   $v0, ($a1)
/* 0AE734 80118034 30420004 */  andi  $v0, $v0, 4
/* 0AE738 80118038 14400025 */  bnez  $v0, .L801180D0
/* 0AE73C 8011803C 0200902D */   daddu $s2, $s0, $zero
/* 0AE740 80118040 94A20000 */  lhu   $v0, ($a1)
/* 0AE744 80118044 90A3009C */  lbu   $v1, 0x9c($a1)
/* 0AE748 80118048 30422000 */  andi  $v0, $v0, 0x2000
/* 0AE74C 8011804C 3C018015 */  lui   $at, 0x8015
/* 0AE750 80118050 A423336C */  sh    $v1, 0x336c($at)
/* 0AE754 80118054 14400009 */  bnez  $v0, .L8011807C
/* 0AE758 80118058 3C03DA38 */   lui   $v1, 0xda38
/* 0AE75C 8011805C 8E020000 */  lw    $v0, ($s0)
/* 0AE760 80118060 34630002 */  ori   $v1, $v1, 2
/* 0AE764 80118064 0040202D */  daddu $a0, $v0, $zero
/* 0AE768 80118068 AC830000 */  sw    $v1, ($a0)
/* 0AE76C 8011806C 8CA3000C */  lw    $v1, 0xc($a1)
/* 0AE770 80118070 24420008 */  addiu $v0, $v0, 8
/* 0AE774 80118074 AE020000 */  sw    $v0, ($s0)
/* 0AE778 80118078 AC830004 */  sw    $v1, 4($a0)
.L8011807C:
/* 0AE77C 8011807C 0C045F9D */  jal   func_80117E74
/* 0AE780 80118080 8E240008 */   lw    $a0, 8($s1)
/* 0AE784 80118084 96220000 */  lhu   $v0, ($s1)
/* 0AE788 80118088 30422000 */  andi  $v0, $v0, 0x2000
/* 0AE78C 8011808C 14400009 */  bnez  $v0, .L801180B4
/* 0AE790 80118090 3C04D838 */   lui   $a0, 0xd838
/* 0AE794 80118094 8E020000 */  lw    $v0, ($s0)
/* 0AE798 80118098 34840002 */  ori   $a0, $a0, 2
/* 0AE79C 8011809C 0040182D */  daddu $v1, $v0, $zero
/* 0AE7A0 801180A0 24420008 */  addiu $v0, $v0, 8
/* 0AE7A4 801180A4 AE020000 */  sw    $v0, ($s0)
/* 0AE7A8 801180A8 24020040 */  addiu $v0, $zero, 0x40
/* 0AE7AC 801180AC AC640000 */  sw    $a0, ($v1)
/* 0AE7B0 801180B0 AC620004 */  sw    $v0, 4($v1)
.L801180B4:
/* 0AE7B4 801180B4 8E420000 */  lw    $v0, ($s2)
/* 0AE7B8 801180B8 0040182D */  daddu $v1, $v0, $zero
/* 0AE7BC 801180BC 24420008 */  addiu $v0, $v0, 8
/* 0AE7C0 801180C0 AE420000 */  sw    $v0, ($s2)
/* 0AE7C4 801180C4 3C02E700 */  lui   $v0, 0xe700
/* 0AE7C8 801180C8 AC620000 */  sw    $v0, ($v1)
/* 0AE7CC 801180CC AC600004 */  sw    $zero, 4($v1)
.L801180D0:
/* 0AE7D0 801180D0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0AE7D4 801180D4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0AE7D8 801180D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0AE7DC 801180DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0AE7E0 801180E0 03E00008 */  jr    $ra
/* 0AE7E4 801180E4 27BD0020 */   addiu $sp, $sp, 0x20


.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_menu_icon_script
/* 0DAEFC 801447FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DAF00 80144800 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DAF04 80144804 00822024 */  and   $a0, $a0, $v0
/* 0DAF08 80144808 3C028015 */  lui   $v0, 0x8015
/* 0DAF0C 8014480C 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DAF10 80144810 00042080 */  sll   $a0, $a0, 2
/* 0DAF14 80144814 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DAF18 80144818 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DAF1C 8014481C 00822021 */  addu  $a0, $a0, $v0
/* 0DAF20 80144820 8C900000 */  lw    $s0, ($a0)
/* 0DAF24 80144824 14A00003 */  bnez  $a1, .L80144834
/* 0DAF28 80144828 0200202D */   daddu $a0, $s0, $zero
/* 0DAF2C 8014482C 3C058015 */  lui   $a1, 0x8015
/* 0DAF30 80144830 24A5EFC8 */  addiu $a1, $a1, -0x1038
.L80144834:
/* 0DAF34 80144834 24020001 */  addiu $v0, $zero, 1
/* 0DAF38 80144838 A2020047 */  sb    $v0, 0x47($s0)
/* 0DAF3C 8014483C 24020400 */  addiu $v0, $zero, 0x400
/* 0DAF40 80144840 AE020034 */  sw    $v0, 0x34($s0)
/* 0DAF44 80144844 AE020038 */  sw    $v0, 0x38($s0)
/* 0DAF48 80144848 8E020000 */  lw    $v0, ($s0)
/* 0DAF4C 8014484C 3C013F80 */  lui   $at, 0x3f80
/* 0DAF50 80144850 44810000 */  mtc1  $at, $f0
/* 0DAF54 80144854 2403FFFB */  addiu $v1, $zero, -5
/* 0DAF58 80144858 AE050004 */  sw    $a1, 4($s0)
/* 0DAF5C 8014485C AE050008 */  sw    $a1, 8($s0)
/* 0DAF60 80144860 AE05000C */  sw    $a1, 0xc($s0)
/* 0DAF64 80144864 A2000040 */  sb    $zero, 0x40($s0)
/* 0DAF68 80144868 A2000041 */  sb    $zero, 0x41($s0)
/* 0DAF6C 8014486C A2000042 */  sb    $zero, 0x42($s0)
/* 0DAF70 80144870 A2000043 */  sb    $zero, 0x43($s0)
/* 0DAF74 80144874 00431024 */  and   $v0, $v0, $v1
/* 0DAF78 80144878 2403F6CF */  addiu $v1, $zero, -0x931
/* 0DAF7C 8014487C AE020000 */  sw    $v0, ($s0)
/* 0DAF80 80144880 00431024 */  and   $v0, $v0, $v1
/* 0DAF84 80144884 E6000030 */  swc1  $f0, 0x30($s0)
/* 0DAF88 80144888 0C04FCD4 */  jal   func_8013F350
/* 0DAF8C 8014488C AE020000 */   sw    $v0, ($s0)
.L80144890:
/* 0DAF90 80144890 0C0505C1 */  jal   func_80141704
/* 0DAF94 80144894 0200202D */   daddu $a0, $s0, $zero
/* 0DAF98 80144898 1440FFFD */  bnez  $v0, .L80144890
/* 0DAF9C 8014489C 00000000 */   nop   
/* 0DAFA0 801448A0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DAFA4 801448A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DAFA8 801448A8 03E00008 */  jr    $ra
/* 0DAFAC 801448AC 27BD0018 */   addiu $sp, $sp, 0x18


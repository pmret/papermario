.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel setup_path_data
/* 0F975C 802D4DAC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F9760 802D4DB0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F9764 802D4DB4 0080982D */  daddu $s3, $a0, $zero
/* 0F9768 802D4DB8 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F976C 802D4DBC 00A0A82D */  daddu $s5, $a1, $zero
/* 0F9770 802D4DC0 AFBE0030 */  sw    $fp, 0x30($sp)
/* 0F9774 802D4DC4 00C0F02D */  daddu $fp, $a2, $zero
/* 0F9778 802D4DC8 AFB60028 */  sw    $s6, 0x28($sp)
/* 0F977C 802D4DCC 00E0B02D */  daddu $s6, $a3, $zero
/* 0F9780 802D4DD0 00132080 */  sll   $a0, $s3, 2
/* 0F9784 802D4DD4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0F9788 802D4DD8 AFB7002C */  sw    $s7, 0x2c($sp)
/* 0F978C 802D4DDC AFB40020 */  sw    $s4, 0x20($sp)
/* 0F9790 802D4DE0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9794 802D4DE4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9798 802D4DE8 0C00AB39 */  jal   heap_malloc
/* 0F979C 802D4DEC AFB00010 */   sw    $s0, 0x10($sp)
/* 0F97A0 802D4DF0 00132040 */  sll   $a0, $s3, 1
/* 0F97A4 802D4DF4 00932021 */  addu  $a0, $a0, $s3
/* 0F97A8 802D4DF8 00042080 */  sll   $a0, $a0, 2
/* 0F97AC 802D4DFC 0C00AB39 */  jal   heap_malloc
/* 0F97B0 802D4E00 0040B82D */   daddu $s7, $v0, $zero
/* 0F97B4 802D4E04 24110001 */  addiu $s1, $zero, 1
/* 0F97B8 802D4E08 0040A02D */  daddu $s4, $v0, $zero
/* 0F97BC 802D4E0C 0233102A */  slt   $v0, $s1, $s3
/* 0F97C0 802D4E10 10400026 */  beqz  $v0, .L802D4EAC
/* 0F97C4 802D4E14 AEA00000 */   sw    $zero, ($s5)
/* 0F97C8 802D4E18 26B20004 */  addiu $s2, $s5, 4
/* 0F97CC 802D4E1C 27D0000C */  addiu $s0, $fp, 0xc
.L802D4E20:
/* 0F97D0 802D4E20 C6040000 */  lwc1  $f4, ($s0)
/* 0F97D4 802D4E24 C600FFF4 */  lwc1  $f0, -0xc($s0)
/* 0F97D8 802D4E28 46002101 */  sub.s $f4, $f4, $f0
/* 0F97DC 802D4E2C 46042102 */  mul.s $f4, $f4, $f4
/* 0F97E0 802D4E30 00000000 */  nop   
/* 0F97E4 802D4E34 C6060004 */  lwc1  $f6, 4($s0)
/* 0F97E8 802D4E38 C600FFF8 */  lwc1  $f0, -8($s0)
/* 0F97EC 802D4E3C 46003181 */  sub.s $f6, $f6, $f0
/* 0F97F0 802D4E40 46063182 */  mul.s $f6, $f6, $f6
/* 0F97F4 802D4E44 00000000 */  nop   
/* 0F97F8 802D4E48 C602FFFC */  lwc1  $f2, -4($s0)
/* 0F97FC 802D4E4C C6000008 */  lwc1  $f0, 8($s0)
/* 0F9800 802D4E50 46020001 */  sub.s $f0, $f0, $f2
/* 0F9804 802D4E54 46000002 */  mul.s $f0, $f0, $f0
/* 0F9808 802D4E58 00000000 */  nop   
/* 0F980C 802D4E5C 46062100 */  add.s $f4, $f4, $f6
/* 0F9810 802D4E60 46002300 */  add.s $f12, $f4, $f0
/* 0F9814 802D4E64 46006084 */  sqrt.s $f2, $f12
/* 0F9818 802D4E68 46021032 */  c.eq.s $f2, $f2
/* 0F981C 802D4E6C 00000000 */  nop   
/* 0F9820 802D4E70 45010004 */  bc1t  .L802D4E84
/* 0F9824 802D4E74 00000000 */   nop   
/* 0F9828 802D4E78 0C0187BC */  jal   sqrtf
/* 0F982C 802D4E7C 00000000 */   nop   
/* 0F9830 802D4E80 46000086 */  mov.s $f2, $f0
.L802D4E84:
/* 0F9834 802D4E84 C640FFFC */  lwc1  $f0, -4($s2)
/* 0F9838 802D4E88 2610000C */  addiu $s0, $s0, 0xc
/* 0F983C 802D4E8C 46020000 */  add.s $f0, $f0, $f2
/* 0F9840 802D4E90 26310001 */  addiu $s1, $s1, 1
/* 0F9844 802D4E94 0233102A */  slt   $v0, $s1, $s3
/* 0F9848 802D4E98 E6400000 */  swc1  $f0, ($s2)
/* 0F984C 802D4E9C 1440FFE0 */  bnez  $v0, .L802D4E20
/* 0F9850 802D4EA0 26520004 */   addiu $s2, $s2, 4
/* 0F9854 802D4EA4 24110001 */  addiu $s1, $zero, 1
/* 0F9858 802D4EA8 0233102A */  slt   $v0, $s1, $s3
.L802D4EAC:
/* 0F985C 802D4EAC 1040000B */  beqz  $v0, .L802D4EDC
/* 0F9860 802D4EB0 00131080 */   sll   $v0, $s3, 2
/* 0F9864 802D4EB4 00552021 */  addu  $a0, $v0, $s5
/* 0F9868 802D4EB8 26A30004 */  addiu $v1, $s5, 4
.L802D4EBC:
/* 0F986C 802D4EBC 26310001 */  addiu $s1, $s1, 1
/* 0F9870 802D4EC0 C4600000 */  lwc1  $f0, ($v1)
/* 0F9874 802D4EC4 C482FFFC */  lwc1  $f2, -4($a0)
/* 0F9878 802D4EC8 0233102A */  slt   $v0, $s1, $s3
/* 0F987C 802D4ECC 46020003 */  div.s $f0, $f0, $f2
/* 0F9880 802D4ED0 E4600000 */  swc1  $f0, ($v1)
/* 0F9884 802D4ED4 1440FFF9 */  bnez  $v0, .L802D4EBC
/* 0F9888 802D4ED8 24630004 */   addiu $v1, $v1, 4
.L802D4EDC:
/* 0F988C 802D4EDC 0000882D */  daddu $s1, $zero, $zero
/* 0F9890 802D4EE0 00131040 */  sll   $v0, $s3, 1
/* 0F9894 802D4EE4 00531021 */  addu  $v0, $v0, $s3
/* 0F9898 802D4EE8 00021080 */  sll   $v0, $v0, 2
/* 0F989C 802D4EEC 00561021 */  addu  $v0, $v0, $s6
/* 0F98A0 802D4EF0 2667FFFF */  addiu $a3, $s3, -1
/* 0F98A4 802D4EF4 AEC00000 */  sw    $zero, ($s6)
/* 0F98A8 802D4EF8 AEC00004 */  sw    $zero, 4($s6)
/* 0F98AC 802D4EFC AEC00008 */  sw    $zero, 8($s6)
/* 0F98B0 802D4F00 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F98B4 802D4F04 AC40FFF8 */  sw    $zero, -8($v0)
/* 0F98B8 802D4F08 18E00021 */  blez  $a3, .L802D4F90
/* 0F98BC 802D4F0C AC40FFFC */   sw    $zero, -4($v0)
/* 0F98C0 802D4F10 02E0202D */  daddu $a0, $s7, $zero
/* 0F98C4 802D4F14 03C0302D */  daddu $a2, $fp, $zero
/* 0F98C8 802D4F18 0280182D */  daddu $v1, $s4, $zero
/* 0F98CC 802D4F1C 02A0282D */  daddu $a1, $s5, $zero
.L802D4F20:
/* 0F98D0 802D4F20 C4A40004 */  lwc1  $f4, 4($a1)
/* 0F98D4 802D4F24 C4A00000 */  lwc1  $f0, ($a1)
/* 0F98D8 802D4F28 46002101 */  sub.s $f4, $f4, $f0
/* 0F98DC 802D4F2C E4840000 */  swc1  $f4, ($a0)
/* 0F98E0 802D4F30 C4C0000C */  lwc1  $f0, 0xc($a2)
/* 0F98E4 802D4F34 C4C20000 */  lwc1  $f2, ($a2)
/* 0F98E8 802D4F38 46020001 */  sub.s $f0, $f0, $f2
/* 0F98EC 802D4F3C 24A50004 */  addiu $a1, $a1, 4
/* 0F98F0 802D4F40 46040003 */  div.s $f0, $f0, $f4
/* 0F98F4 802D4F44 E460000C */  swc1  $f0, 0xc($v1)
/* 0F98F8 802D4F48 C4C20010 */  lwc1  $f2, 0x10($a2)
/* 0F98FC 802D4F4C C4C00004 */  lwc1  $f0, 4($a2)
/* 0F9900 802D4F50 26310001 */  addiu $s1, $s1, 1
/* 0F9904 802D4F54 46001081 */  sub.s $f2, $f2, $f0
/* 0F9908 802D4F58 C4800000 */  lwc1  $f0, ($a0)
/* 0F990C 802D4F5C 0227102A */  slt   $v0, $s1, $a3
/* 0F9910 802D4F60 46001083 */  div.s $f2, $f2, $f0
/* 0F9914 802D4F64 E4620010 */  swc1  $f2, 0x10($v1)
/* 0F9918 802D4F68 C4C00014 */  lwc1  $f0, 0x14($a2)
/* 0F991C 802D4F6C C4C20008 */  lwc1  $f2, 8($a2)
/* 0F9920 802D4F70 24C6000C */  addiu $a2, $a2, 0xc
/* 0F9924 802D4F74 46020001 */  sub.s $f0, $f0, $f2
/* 0F9928 802D4F78 C4820000 */  lwc1  $f2, ($a0)
/* 0F992C 802D4F7C 24840004 */  addiu $a0, $a0, 4
/* 0F9930 802D4F80 46020003 */  div.s $f0, $f0, $f2
/* 0F9934 802D4F84 E4600014 */  swc1  $f0, 0x14($v1)
/* 0F9938 802D4F88 1440FFE5 */  bnez  $v0, .L802D4F20
/* 0F993C 802D4F8C 2463000C */   addiu $v1, $v1, 0xc
.L802D4F90:
/* 0F9940 802D4F90 C6800018 */  lwc1  $f0, 0x18($s4)
/* 0F9944 802D4F94 C682000C */  lwc1  $f2, 0xc($s4)
/* 0F9948 802D4F98 46020001 */  sub.s $f0, $f0, $f2
/* 0F994C 802D4F9C E6C0000C */  swc1  $f0, 0xc($s6)
/* 0F9950 802D4FA0 C680001C */  lwc1  $f0, 0x1c($s4)
/* 0F9954 802D4FA4 C6820010 */  lwc1  $f2, 0x10($s4)
/* 0F9958 802D4FA8 46020001 */  sub.s $f0, $f0, $f2
/* 0F995C 802D4FAC E6C00010 */  swc1  $f0, 0x10($s6)
/* 0F9960 802D4FB0 C6800020 */  lwc1  $f0, 0x20($s4)
/* 0F9964 802D4FB4 C6820014 */  lwc1  $f2, 0x14($s4)
/* 0F9968 802D4FB8 46020001 */  sub.s $f0, $f0, $f2
/* 0F996C 802D4FBC E6C00014 */  swc1  $f0, 0x14($s6)
/* 0F9970 802D4FC0 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F9974 802D4FC4 C6A20000 */  lwc1  $f2, ($s5)
/* 0F9978 802D4FC8 46020001 */  sub.s $f0, $f0, $f2
/* 0F997C 802D4FCC 46000000 */  add.s $f0, $f0, $f0
/* 0F9980 802D4FD0 E680000C */  swc1  $f0, 0xc($s4)
/* 0F9984 802D4FD4 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F9988 802D4FD8 C6A20000 */  lwc1  $f2, ($s5)
/* 0F998C 802D4FDC 46020001 */  sub.s $f0, $f0, $f2
/* 0F9990 802D4FE0 46000000 */  add.s $f0, $f0, $f0
/* 0F9994 802D4FE4 E6800010 */  swc1  $f0, 0x10($s4)
/* 0F9998 802D4FE8 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F999C 802D4FEC C6A20000 */  lwc1  $f2, ($s5)
/* 0F99A0 802D4FF0 46020001 */  sub.s $f0, $f0, $f2
/* 0F99A4 802D4FF4 24110001 */  addiu $s1, $zero, 1
/* 0F99A8 802D4FF8 46000000 */  add.s $f0, $f0, $f0
/* 0F99AC 802D4FFC 2667FFFE */  addiu $a3, $s3, -2
/* 0F99B0 802D5000 0227102A */  slt   $v0, $s1, $a3
/* 0F99B4 802D5004 10400046 */  beqz  $v0, .L802D5120
/* 0F99B8 802D5008 E6800014 */   swc1  $f0, 0x14($s4)
/* 0F99BC 802D500C 26E60004 */  addiu $a2, $s7, 4
/* 0F99C0 802D5010 26A50004 */  addiu $a1, $s5, 4
/* 0F99C4 802D5014 26C4000C */  addiu $a0, $s6, 0xc
/* 0F99C8 802D5018 2683000C */  addiu $v1, $s4, 0xc
.L802D501C:
/* 0F99CC 802D501C C4CC0000 */  lwc1  $f12, ($a2)
/* 0F99D0 802D5020 C4660000 */  lwc1  $f6, ($v1)
/* 0F99D4 802D5024 C4840000 */  lwc1  $f4, ($a0)
/* 0F99D8 802D5028 46066183 */  div.s $f6, $f12, $f6
/* 0F99DC 802D502C 46062102 */  mul.s $f4, $f4, $f6
/* 0F99E0 802D5030 00000000 */  nop   
/* 0F99E4 802D5034 C4600018 */  lwc1  $f0, 0x18($v1)
/* 0F99E8 802D5038 C462000C */  lwc1  $f2, 0xc($v1)
/* 0F99EC 802D503C 46020001 */  sub.s $f0, $f0, $f2
/* 0F99F0 802D5040 C4680004 */  lwc1  $f8, 4($v1)
/* 0F99F4 802D5044 C46A0008 */  lwc1  $f10, 8($v1)
/* 0F99F8 802D5048 46040001 */  sub.s $f0, $f0, $f4
/* 0F99FC 802D504C C4840004 */  lwc1  $f4, 4($a0)
/* 0F9A00 802D5050 46086203 */  div.s $f8, $f12, $f8
/* 0F9A04 802D5054 46082102 */  mul.s $f4, $f4, $f8
/* 0F9A08 802D5058 00000000 */  nop   
/* 0F9A0C 802D505C E480000C */  swc1  $f0, 0xc($a0)
/* 0F9A10 802D5060 C462001C */  lwc1  $f2, 0x1c($v1)
/* 0F9A14 802D5064 C4600010 */  lwc1  $f0, 0x10($v1)
/* 0F9A18 802D5068 46001081 */  sub.s $f2, $f2, $f0
/* 0F9A1C 802D506C 46041081 */  sub.s $f2, $f2, $f4
/* 0F9A20 802D5070 C4840008 */  lwc1  $f4, 8($a0)
/* 0F9A24 802D5074 460A6303 */  div.s $f12, $f12, $f10
/* 0F9A28 802D5078 460C2102 */  mul.s $f4, $f4, $f12
/* 0F9A2C 802D507C 00000000 */  nop   
/* 0F9A30 802D5080 E4820010 */  swc1  $f2, 0x10($a0)
/* 0F9A34 802D5084 C4600020 */  lwc1  $f0, 0x20($v1)
/* 0F9A38 802D5088 C4620014 */  lwc1  $f2, 0x14($v1)
/* 0F9A3C 802D508C 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A40 802D5090 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A44 802D5094 E4800014 */  swc1  $f0, 0x14($a0)
/* 0F9A48 802D5098 C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A4C 802D509C 46062102 */  mul.s $f4, $f4, $f6
/* 0F9A50 802D50A0 00000000 */  nop   
/* 0F9A54 802D50A4 C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9A58 802D50A8 C4A20000 */  lwc1  $f2, ($a1)
/* 0F9A5C 802D50AC 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A60 802D50B0 46000000 */  add.s $f0, $f0, $f0
/* 0F9A64 802D50B4 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A68 802D50B8 E460000C */  swc1  $f0, 0xc($v1)
/* 0F9A6C 802D50BC C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A70 802D50C0 46082102 */  mul.s $f4, $f4, $f8
/* 0F9A74 802D50C4 00000000 */  nop   
/* 0F9A78 802D50C8 C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9A7C 802D50CC C4A20000 */  lwc1  $f2, ($a1)
/* 0F9A80 802D50D0 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A84 802D50D4 46000000 */  add.s $f0, $f0, $f0
/* 0F9A88 802D50D8 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A8C 802D50DC E4600010 */  swc1  $f0, 0x10($v1)
/* 0F9A90 802D50E0 C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A94 802D50E4 460C2102 */  mul.s $f4, $f4, $f12
/* 0F9A98 802D50E8 00000000 */  nop   
/* 0F9A9C 802D50EC C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9AA0 802D50F0 C4A20000 */  lwc1  $f2, ($a1)
/* 0F9AA4 802D50F4 46020001 */  sub.s $f0, $f0, $f2
/* 0F9AA8 802D50F8 26310001 */  addiu $s1, $s1, 1
/* 0F9AAC 802D50FC 46000000 */  add.s $f0, $f0, $f0
/* 0F9AB0 802D5100 0227102A */  slt   $v0, $s1, $a3
/* 0F9AB4 802D5104 2484000C */  addiu $a0, $a0, 0xc
/* 0F9AB8 802D5108 46040001 */  sub.s $f0, $f0, $f4
/* 0F9ABC 802D510C 24C60004 */  addiu $a2, $a2, 4
/* 0F9AC0 802D5110 24A50004 */  addiu $a1, $a1, 4
/* 0F9AC4 802D5114 E4600014 */  swc1  $f0, 0x14($v1)
/* 0F9AC8 802D5118 1440FFC0 */  bnez  $v0, .L802D501C
/* 0F9ACC 802D511C 2463000C */   addiu $v1, $v1, 0xc
.L802D5120:
/* 0F9AD0 802D5120 00131040 */  sll   $v0, $s3, 1
/* 0F9AD4 802D5124 00531021 */  addu  $v0, $v0, $s3
/* 0F9AD8 802D5128 00021080 */  sll   $v0, $v0, 2
/* 0F9ADC 802D512C 00561021 */  addu  $v0, $v0, $s6
/* 0F9AE0 802D5130 00131880 */  sll   $v1, $s3, 2
/* 0F9AE4 802D5134 00771821 */  addu  $v1, $v1, $s7
/* 0F9AE8 802D5138 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9AEC 802D513C C440FFF4 */  lwc1  $f0, -0xc($v0)
/* 0F9AF0 802D5140 46001082 */  mul.s $f2, $f2, $f0
/* 0F9AF4 802D5144 00000000 */  nop   
/* 0F9AF8 802D5148 C440FFE8 */  lwc1  $f0, -0x18($v0)
/* 0F9AFC 802D514C 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B00 802D5150 E440FFE8 */  swc1  $f0, -0x18($v0)
/* 0F9B04 802D5154 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9B08 802D5158 C440FFF8 */  lwc1  $f0, -8($v0)
/* 0F9B0C 802D515C 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B10 802D5160 00000000 */  nop   
/* 0F9B14 802D5164 C440FFEC */  lwc1  $f0, -0x14($v0)
/* 0F9B18 802D5168 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B1C 802D516C E440FFEC */  swc1  $f0, -0x14($v0)
/* 0F9B20 802D5170 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9B24 802D5174 C440FFFC */  lwc1  $f0, -4($v0)
/* 0F9B28 802D5178 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B2C 802D517C 00000000 */  nop   
/* 0F9B30 802D5180 C440FFF0 */  lwc1  $f0, -0x10($v0)
/* 0F9B34 802D5184 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B38 802D5188 2671FFFE */  addiu $s1, $s3, -2
/* 0F9B3C 802D518C 1A200028 */  blez  $s1, .L802D5230
/* 0F9B40 802D5190 E440FFF0 */   swc1  $f0, -0x10($v0)
/* 0F9B44 802D5194 00111080 */  sll   $v0, $s1, 2
/* 0F9B48 802D5198 00571821 */  addu  $v1, $v0, $s7
/* 0F9B4C 802D519C 00111040 */  sll   $v0, $s1, 1
/* 0F9B50 802D51A0 00511021 */  addu  $v0, $v0, $s1
/* 0F9B54 802D51A4 00021080 */  sll   $v0, $v0, 2
/* 0F9B58 802D51A8 00563821 */  addu  $a3, $v0, $s6
/* 0F9B5C 802D51AC 00541021 */  addu  $v0, $v0, $s4
.L802D51B0:
/* 0F9B60 802D51B0 C4620000 */  lwc1  $f2, ($v1)
/* 0F9B64 802D51B4 C4E0000C */  lwc1  $f0, 0xc($a3)
/* 0F9B68 802D51B8 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B6C 802D51BC 00000000 */  nop   
/* 0F9B70 802D51C0 C4E00000 */  lwc1  $f0, ($a3)
/* 0F9B74 802D51C4 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B78 802D51C8 C4420000 */  lwc1  $f2, ($v0)
/* 0F9B7C 802D51CC 46020003 */  div.s $f0, $f0, $f2
/* 0F9B80 802D51D0 E4E00000 */  swc1  $f0, ($a3)
/* 0F9B84 802D51D4 C4620000 */  lwc1  $f2, ($v1)
/* 0F9B88 802D51D8 C4E00010 */  lwc1  $f0, 0x10($a3)
/* 0F9B8C 802D51DC 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B90 802D51E0 00000000 */  nop   
/* 0F9B94 802D51E4 C4E00004 */  lwc1  $f0, 4($a3)
/* 0F9B98 802D51E8 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B9C 802D51EC C4420004 */  lwc1  $f2, 4($v0)
/* 0F9BA0 802D51F0 46020003 */  div.s $f0, $f0, $f2
/* 0F9BA4 802D51F4 E4E00004 */  swc1  $f0, 4($a3)
/* 0F9BA8 802D51F8 C4620000 */  lwc1  $f2, ($v1)
/* 0F9BAC 802D51FC C4E00014 */  lwc1  $f0, 0x14($a3)
/* 0F9BB0 802D5200 46001082 */  mul.s $f2, $f2, $f0
/* 0F9BB4 802D5204 00000000 */  nop   
/* 0F9BB8 802D5208 2631FFFF */  addiu $s1, $s1, -1
/* 0F9BBC 802D520C C4E00008 */  lwc1  $f0, 8($a3)
/* 0F9BC0 802D5210 2463FFFC */  addiu $v1, $v1, -4
/* 0F9BC4 802D5214 46020001 */  sub.s $f0, $f0, $f2
/* 0F9BC8 802D5218 C4420008 */  lwc1  $f2, 8($v0)
/* 0F9BCC 802D521C 2442FFF4 */  addiu $v0, $v0, -0xc
/* 0F9BD0 802D5220 46020003 */  div.s $f0, $f0, $f2
/* 0F9BD4 802D5224 E4E00008 */  swc1  $f0, 8($a3)
/* 0F9BD8 802D5228 1E20FFE1 */  bgtz  $s1, .L802D51B0
/* 0F9BDC 802D522C 24E7FFF4 */   addiu $a3, $a3, -0xc
.L802D5230:
/* 0F9BE0 802D5230 0C00AB4B */  jal   heap_free
/* 0F9BE4 802D5234 02E0202D */   daddu $a0, $s7, $zero
/* 0F9BE8 802D5238 0C00AB4B */  jal   heap_free
/* 0F9BEC 802D523C 0280202D */   daddu $a0, $s4, $zero
/* 0F9BF0 802D5240 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0F9BF4 802D5244 8FBE0030 */  lw    $fp, 0x30($sp)
/* 0F9BF8 802D5248 8FB7002C */  lw    $s7, 0x2c($sp)
/* 0F9BFC 802D524C 8FB60028 */  lw    $s6, 0x28($sp)
/* 0F9C00 802D5250 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F9C04 802D5254 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F9C08 802D5258 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F9C0C 802D525C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9C10 802D5260 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9C14 802D5264 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9C18 802D5268 03E00008 */  jr    $ra
/* 0F9C1C 802D526C 27BD0038 */   addiu $sp, $sp, 0x38


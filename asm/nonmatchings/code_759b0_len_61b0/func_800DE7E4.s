.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DE7E4
/* 077C94 800DE7E4 27BDFF90 */  addiu $sp, $sp, -0x70
/* 077C98 800DE7E8 F7B40048 */  sdc1  $f20, 0x48($sp)
/* 077C9C 800DE7EC C7B40084 */  lwc1  $f20, 0x84($sp)
/* 077CA0 800DE7F0 3C0140C9 */  lui   $at, 0x40c9
/* 077CA4 800DE7F4 34210FD0 */  ori   $at, $at, 0xfd0
/* 077CA8 800DE7F8 44810000 */  mtc1  $at, $f0
/* 077CAC 800DE7FC AFB60038 */  sw    $s6, 0x38($sp)
/* 077CB0 800DE800 00A0B02D */  daddu $s6, $a1, $zero
/* 077CB4 800DE804 AFB7003C */  sw    $s7, 0x3c($sp)
/* 077CB8 800DE808 00C0B82D */  daddu $s7, $a2, $zero
/* 077CBC 800DE80C AFBE0040 */  sw    $fp, 0x40($sp)
/* 077CC0 800DE810 00E0F02D */  daddu $fp, $a3, $zero
/* 077CC4 800DE814 AFB40030 */  sw    $s4, 0x30($sp)
/* 077CC8 800DE818 2414FFFF */  addiu $s4, $zero, -1
/* 077CCC 800DE81C AFBF0044 */  sw    $ra, 0x44($sp)
/* 077CD0 800DE820 AFB50034 */  sw    $s5, 0x34($sp)
/* 077CD4 800DE824 AFB3002C */  sw    $s3, 0x2c($sp)
/* 077CD8 800DE828 AFB20028 */  sw    $s2, 0x28($sp)
/* 077CDC 800DE82C AFB10024 */  sw    $s1, 0x24($sp)
/* 077CE0 800DE830 AFB00020 */  sw    $s0, 0x20($sp)
/* 077CE4 800DE834 F7BC0068 */  sdc1  $f28, 0x68($sp)
/* 077CE8 800DE838 F7BA0060 */  sdc1  $f26, 0x60($sp)
/* 077CEC 800DE83C F7B80058 */  sdc1  $f24, 0x58($sp)
/* 077CF0 800DE840 F7B60050 */  sdc1  $f22, 0x50($sp)
/* 077CF4 800DE844 848200B2 */  lh    $v0, 0xb2($a0)
/* 077CF8 800DE848 4600A502 */  mul.s $f20, $f20, $f0
/* 077CFC 800DE84C 00000000 */  nop   
/* 077D00 800DE850 3C013E99 */  lui   $at, 0x3e99
/* 077D04 800DE854 3421999A */  ori   $at, $at, 0x999a
/* 077D08 800DE858 44811000 */  mtc1  $at, $f2
/* 077D0C 800DE85C 8FB50080 */  lw    $s5, 0x80($sp)
/* 077D10 800DE860 4482B000 */  mtc1  $v0, $f22
/* 077D14 800DE864 00000000 */  nop   
/* 077D18 800DE868 4680B5A0 */  cvt.s.w $f22, $f22
/* 077D1C 800DE86C 3C0143B4 */  lui   $at, 0x43b4
/* 077D20 800DE870 44810000 */  mtc1  $at, $f0
/* 077D24 800DE874 4602B582 */  mul.s $f22, $f22, $f2
/* 077D28 800DE878 00000000 */  nop   
/* 077D2C 800DE87C 4600A503 */  div.s $f20, $f20, $f0
/* 077D30 800DE880 0C00A85B */  jal   sin_rad
/* 077D34 800DE884 4600A306 */   mov.s $f12, $f20
/* 077D38 800DE888 4600B702 */  mul.s $f28, $f22, $f0
/* 077D3C 800DE88C 00000000 */  nop   
/* 077D40 800DE890 0C00A874 */  jal   cos_rad
/* 077D44 800DE894 4600A306 */   mov.s $f12, $f20
/* 077D48 800DE898 27B30010 */  addiu $s3, $sp, 0x10
/* 077D4C 800DE89C 0260202D */  daddu $a0, $s3, $zero
/* 077D50 800DE8A0 27B20014 */  addiu $s2, $sp, 0x14
/* 077D54 800DE8A4 0240282D */  daddu $a1, $s2, $zero
/* 077D58 800DE8A8 27B10018 */  addiu $s1, $sp, 0x18
/* 077D5C 800DE8AC 0220302D */  daddu $a2, $s1, $zero
/* 077D60 800DE8B0 27B0001C */  addiu $s0, $sp, 0x1c
/* 077D64 800DE8B4 4600B587 */  neg.s $f22, $f22
/* 077D68 800DE8B8 4600B682 */  mul.s $f26, $f22, $f0
/* 077D6C 800DE8BC 00000000 */  nop   
/* 077D70 800DE8C0 C6D60000 */  lwc1  $f22, ($s6)
/* 077D74 800DE8C4 C6F80000 */  lwc1  $f24, ($s7)
/* 077D78 800DE8C8 C7D40000 */  lwc1  $f20, ($fp)
/* 077D7C 800DE8CC C6A00000 */  lwc1  $f0, ($s5)
/* 077D80 800DE8D0 461CB080 */  add.s $f2, $f22, $f28
/* 077D84 800DE8D4 0200382D */  daddu $a3, $s0, $zero
/* 077D88 800DE8D8 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 077D8C 800DE8DC 461AA000 */  add.s $f0, $f20, $f26
/* 077D90 800DE8E0 E7B80014 */  swc1  $f24, 0x14($sp)
/* 077D94 800DE8E4 E7A20010 */  swc1  $f2, 0x10($sp)
/* 077D98 800DE8E8 0C037A82 */  jal   trace_above_player
/* 077D9C 800DE8EC E7A00018 */   swc1  $f0, 0x18($sp)
/* 077DA0 800DE8F0 04410022 */  bgez  $v0, .L800DE97C
/* 077DA4 800DE8F4 0260202D */   daddu $a0, $s3, $zero
/* 077DA8 800DE8F8 0240282D */  daddu $a1, $s2, $zero
/* 077DAC 800DE8FC 461CB081 */  sub.s $f2, $f22, $f28
/* 077DB0 800DE900 0220302D */  daddu $a2, $s1, $zero
/* 077DB4 800DE904 0200382D */  daddu $a3, $s0, $zero
/* 077DB8 800DE908 461AA001 */  sub.s $f0, $f20, $f26
/* 077DBC 800DE90C E7B80014 */  swc1  $f24, 0x14($sp)
/* 077DC0 800DE910 E7A20010 */  swc1  $f2, 0x10($sp)
/* 077DC4 800DE914 0C037A82 */  jal   trace_above_player
/* 077DC8 800DE918 E7A00018 */   swc1  $f0, 0x18($sp)
/* 077DCC 800DE91C 04410017 */  bgez  $v0, .L800DE97C
/* 077DD0 800DE920 0260202D */   daddu $a0, $s3, $zero
/* 077DD4 800DE924 0240282D */  daddu $a1, $s2, $zero
/* 077DD8 800DE928 461AB080 */  add.s $f2, $f22, $f26
/* 077DDC 800DE92C 0220302D */  daddu $a2, $s1, $zero
/* 077DE0 800DE930 0200382D */  daddu $a3, $s0, $zero
/* 077DE4 800DE934 461CA000 */  add.s $f0, $f20, $f28
/* 077DE8 800DE938 E7B80014 */  swc1  $f24, 0x14($sp)
/* 077DEC 800DE93C E7A20010 */  swc1  $f2, 0x10($sp)
/* 077DF0 800DE940 0C037A82 */  jal   trace_above_player
/* 077DF4 800DE944 E7A00018 */   swc1  $f0, 0x18($sp)
/* 077DF8 800DE948 0441000C */  bgez  $v0, .L800DE97C
/* 077DFC 800DE94C 0260202D */   daddu $a0, $s3, $zero
/* 077E00 800DE950 0240282D */  daddu $a1, $s2, $zero
/* 077E04 800DE954 461AB081 */  sub.s $f2, $f22, $f26
/* 077E08 800DE958 0220302D */  daddu $a2, $s1, $zero
/* 077E0C 800DE95C 0200382D */  daddu $a3, $s0, $zero
/* 077E10 800DE960 461CA001 */  sub.s $f0, $f20, $f28
/* 077E14 800DE964 E7B80014 */  swc1  $f24, 0x14($sp)
/* 077E18 800DE968 E7A20010 */  swc1  $f2, 0x10($sp)
/* 077E1C 800DE96C 0C037A82 */  jal   trace_above_player
/* 077E20 800DE970 E7A00018 */   swc1  $f0, 0x18($sp)
/* 077E24 800DE974 0440000A */  bltz  $v0, .L800DE9A0
/* 077E28 800DE978 00000000 */   nop   
.L800DE97C:
/* 077E2C 800DE97C C7A00010 */  lwc1  $f0, 0x10($sp)
/* 077E30 800DE980 E6C00000 */  swc1  $f0, ($s6)
/* 077E34 800DE984 C7A00014 */  lwc1  $f0, 0x14($sp)
/* 077E38 800DE988 E6E00000 */  swc1  $f0, ($s7)
/* 077E3C 800DE98C C7A00018 */  lwc1  $f0, 0x18($sp)
/* 077E40 800DE990 E7C00000 */  swc1  $f0, ($fp)
/* 077E44 800DE994 C7A0001C */  lwc1  $f0, 0x1c($sp)
/* 077E48 800DE998 0040A02D */  daddu $s4, $v0, $zero
/* 077E4C 800DE99C E6A00000 */  swc1  $f0, ($s5)
.L800DE9A0:
/* 077E50 800DE9A0 06810008 */  bgez  $s4, .L800DE9C4
/* 077E54 800DE9A4 0280102D */   daddu $v0, $s4, $zero
/* 077E58 800DE9A8 C7A00010 */  lwc1  $f0, 0x10($sp)
/* 077E5C 800DE9AC E6C00000 */  swc1  $f0, ($s6)
/* 077E60 800DE9B0 C7A00014 */  lwc1  $f0, 0x14($sp)
/* 077E64 800DE9B4 E6E00000 */  swc1  $f0, ($s7)
/* 077E68 800DE9B8 C7A00018 */  lwc1  $f0, 0x18($sp)
/* 077E6C 800DE9BC E7C00000 */  swc1  $f0, ($fp)
/* 077E70 800DE9C0 AEA00000 */  sw    $zero, ($s5)
.L800DE9C4:
/* 077E74 800DE9C4 8FBF0044 */  lw    $ra, 0x44($sp)
/* 077E78 800DE9C8 8FBE0040 */  lw    $fp, 0x40($sp)
/* 077E7C 800DE9CC 8FB7003C */  lw    $s7, 0x3c($sp)
/* 077E80 800DE9D0 8FB60038 */  lw    $s6, 0x38($sp)
/* 077E84 800DE9D4 8FB50034 */  lw    $s5, 0x34($sp)
/* 077E88 800DE9D8 8FB40030 */  lw    $s4, 0x30($sp)
/* 077E8C 800DE9DC 8FB3002C */  lw    $s3, 0x2c($sp)
/* 077E90 800DE9E0 8FB20028 */  lw    $s2, 0x28($sp)
/* 077E94 800DE9E4 8FB10024 */  lw    $s1, 0x24($sp)
/* 077E98 800DE9E8 8FB00020 */  lw    $s0, 0x20($sp)
/* 077E9C 800DE9EC D7BC0068 */  ldc1  $f28, 0x68($sp)
/* 077EA0 800DE9F0 D7BA0060 */  ldc1  $f26, 0x60($sp)
/* 077EA4 800DE9F4 D7B80058 */  ldc1  $f24, 0x58($sp)
/* 077EA8 800DE9F8 D7B60050 */  ldc1  $f22, 0x50($sp)
/* 077EAC 800DE9FC D7B40048 */  ldc1  $f20, 0x48($sp)
/* 077EB0 800DEA00 03E00008 */  jr    $ra
/* 077EB4 800DEA04 27BD0070 */   addiu $sp, $sp, 0x70


.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024B974
/* 13ECB4 8024B974 AC790000 */   sw    $t9, ($v1)
/* 13ECB8 8024B978 2673000C */  addiu $s3, $s3, 0xc
/* 13ECBC 8024B97C 26D60180 */  addiu $s6, $s6, 0x180
/* 13ECC0 8024B980 26B5000C */  addiu $s5, $s5, 0xc
/* 13ECC4 8024B984 26940030 */  addiu $s4, $s4, 0x30
/* 13ECC8 8024B988 26100001 */  addiu $s0, $s0, 1
/* 13ECCC 8024B98C 2A020014 */  slti  $v0, $s0, 0x14
/* 13ECD0 8024B990 1440FFA0 */  bnez  $v0, .L8024B814
/* 13ECD4 8024B994 2652000C */   addiu $s2, $s2, 0xc
.L8024B998:
/* 13ECD8 8024B998 26F70096 */  addiu $s7, $s7, 0x96
/* 13ECDC 8024B99C 27DE0004 */  addiu $fp, $fp, 4
/* 13ECE0 8024B9A0 3C0F8025 */  lui   $t7, 0x8025
/* 13ECE4 8024B9A4 25EFF73C */  addiu $t7, $t7, -0x8c4
/* 13ECE8 8024B9A8 25E20008 */  addiu $v0, $t7, 8
/* 13ECEC 8024B9AC 8FAD0114 */  lw    $t5, 0x114($sp)
/* 13ECF0 8024B9B0 03C2102A */  slt   $v0, $fp, $v0
/* 13ECF4 8024B9B4 25AD0004 */  addiu $t5, $t5, 4
/* 13ECF8 8024B9B8 1440FF5B */  bnez  $v0, .L8024B728
/* 13ECFC 8024B9BC AFAD0114 */   sw    $t5, 0x114($sp)
/* 13ED00 8024B9C0 8FB8018C */  lw    $t8, 0x18c($sp)
/* 13ED04 8024B9C4 8FAC0190 */  lw    $t4, 0x190($sp)
/* 13ED08 8024B9C8 2707007A */  addiu $a3, $t8, 0x7a
/* 13ED0C 8024B9CC 25880010 */  addiu $t0, $t4, 0x10
/* 13ED10 8024B9D0 270A0120 */  addiu $t2, $t8, 0x120
/* 13ED14 8024B9D4 1CE00002 */  bgtz  $a3, .L8024B9E0
/* 13ED18 8024B9D8 258B0089 */   addiu $t3, $t4, 0x89
/* 13ED1C 8024B9DC 24070001 */  addiu $a3, $zero, 1
.L8024B9E0:
/* 13ED20 8024B9E0 59000001 */  blezl $t0, .L8024B9E8
/* 13ED24 8024B9E4 24080001 */   addiu $t0, $zero, 1
.L8024B9E8:
/* 13ED28 8024B9E8 1940005F */  blez  $t2, .L8024BB68
/* 13ED2C 8024B9EC 00000000 */   nop   
/* 13ED30 8024B9F0 1960005D */  blez  $t3, .L8024BB68
/* 13ED34 8024B9F4 28E2013F */   slti  $v0, $a3, 0x13f
/* 13ED38 8024B9F8 1040005B */  beqz  $v0, .L8024BB68
/* 13ED3C 8024B9FC 290200EF */   slti  $v0, $t0, 0xef
/* 13ED40 8024BA00 10400059 */  beqz  $v0, .L8024BB68
/* 13ED44 8024BA04 2942013F */   slti  $v0, $t2, 0x13f
/* 13ED48 8024BA08 50400001 */  beql  $v0, $zero, .L8024BA10
/* 13ED4C 8024BA0C 240A013F */   addiu $t2, $zero, 0x13f
.L8024BA10:
/* 13ED50 8024BA10 296200EF */  slti  $v0, $t3, 0xef
/* 13ED54 8024BA14 50400001 */  beql  $v0, $zero, .L8024BA1C
/* 13ED58 8024BA18 240B00EF */   addiu $t3, $zero, 0xef
.L8024BA1C:
/* 13ED5C 8024BA1C 3C03800A */  lui   $v1, 0x800a
/* 13ED60 8024BA20 2463A66C */  addiu $v1, $v1, -0x5994
/* 13ED64 8024BA24 44871000 */  mtc1  $a3, $f2
/* 13ED68 8024BA28 00000000 */  nop   
/* 13ED6C 8024BA2C 468010A0 */  cvt.s.w $f2, $f2
/* 13ED70 8024BA30 44880000 */  mtc1  $t0, $f0
/* 13ED74 8024BA34 00000000 */  nop   
/* 13ED78 8024BA38 46800020 */  cvt.s.w $f0, $f0
/* 13ED7C 8024BA3C 3C08ED00 */  lui   $t0, 0xed00
/* 13ED80 8024BA40 8FAD018C */  lw    $t5, 0x18c($sp)
/* 13ED84 8024BA44 8C620000 */  lw    $v0, ($v1)
/* 13ED88 8024BA48 3C014080 */  lui   $at, 0x4080
/* 13ED8C 8024BA4C 44812000 */  mtc1  $at, $f4
/* 13ED90 8024BA50 8FAF0190 */  lw    $t7, 0x190($sp)
/* 13ED94 8024BA54 46041082 */  mul.s $f2, $f2, $f4
/* 13ED98 8024BA58 00000000 */  nop   
/* 13ED9C 8024BA5C 25A6007A */  addiu $a2, $t5, 0x7a
/* 13EDA0 8024BA60 25E70010 */  addiu $a3, $t7, 0x10
/* 13EDA4 8024BA64 0040482D */  daddu $t1, $v0, $zero
/* 13EDA8 8024BA68 24420008 */  addiu $v0, $v0, 8
/* 13EDAC 8024BA6C 46040002 */  mul.s $f0, $f0, $f4
/* 13EDB0 8024BA70 00000000 */  nop   
/* 13EDB4 8024BA74 AC620000 */  sw    $v0, ($v1)
/* 13EDB8 8024BA78 4600128D */  trunc.w.s $f10, $f2
/* 13EDBC 8024BA7C 44025000 */  mfc1  $v0, $f10
/* 13EDC0 8024BA80 00000000 */  nop   
/* 13EDC4 8024BA84 30420FFF */  andi  $v0, $v0, 0xfff
/* 13EDC8 8024BA88 00021300 */  sll   $v0, $v0, 0xc
/* 13EDCC 8024BA8C 4600028D */  trunc.w.s $f10, $f0
/* 13EDD0 8024BA90 44035000 */  mfc1  $v1, $f10
/* 13EDD4 8024BA94 448A1000 */  mtc1  $t2, $f2
/* 13EDD8 8024BA98 00000000 */  nop   
/* 13EDDC 8024BA9C 468010A0 */  cvt.s.w $f2, $f2
/* 13EDE0 8024BAA0 46041082 */  mul.s $f2, $f2, $f4
/* 13EDE4 8024BAA4 00000000 */  nop   
/* 13EDE8 8024BAA8 30630FFF */  andi  $v1, $v1, 0xfff
/* 13EDEC 8024BAAC 00681825 */  or    $v1, $v1, $t0
/* 13EDF0 8024BAB0 00431025 */  or    $v0, $v0, $v1
/* 13EDF4 8024BAB4 448B0000 */  mtc1  $t3, $f0
/* 13EDF8 8024BAB8 00000000 */  nop   
/* 13EDFC 8024BABC 46800020 */  cvt.s.w $f0, $f0
/* 13EE00 8024BAC0 46040002 */  mul.s $f0, $f0, $f4
/* 13EE04 8024BAC4 00000000 */  nop   
/* 13EE08 8024BAC8 AD220000 */  sw    $v0, ($t1)
/* 13EE0C 8024BACC 4600128D */  trunc.w.s $f10, $f2
/* 13EE10 8024BAD0 44025000 */  mfc1  $v0, $f10
/* 13EE14 8024BAD4 00000000 */  nop   
/* 13EE18 8024BAD8 30420FFF */  andi  $v0, $v0, 0xfff
/* 13EE1C 8024BADC 00021300 */  sll   $v0, $v0, 0xc
/* 13EE20 8024BAE0 4600028D */  trunc.w.s $f10, $f0
/* 13EE24 8024BAE4 44035000 */  mfc1  $v1, $f10
/* 13EE28 8024BAE8 00000000 */  nop   
/* 13EE2C 8024BAEC 30630FFF */  andi  $v1, $v1, 0xfff
/* 13EE30 8024BAF0 00431025 */  or    $v0, $v0, $v1
/* 13EE34 8024BAF4 AD220004 */  sw    $v0, 4($t1)
/* 13EE38 8024BAF8 240200A6 */  addiu $v0, $zero, 0xa6
/* 13EE3C 8024BAFC AFA20014 */  sw    $v0, 0x14($sp)
/* 13EE40 8024BB00 24020079 */  addiu $v0, $zero, 0x79
/* 13EE44 8024BB04 AFA20018 */  sw    $v0, 0x18($sp)
/* 13EE48 8024BB08 93A2019F */  lbu   $v0, 0x19f($sp)
/* 13EE4C 8024BB0C 3C013F80 */  lui   $at, 0x3f80
/* 13EE50 8024BB10 44810000 */  mtc1  $at, $f0
/* 13EE54 8024BB14 8FAD0194 */  lw    $t5, 0x194($sp)
/* 13EE58 8024BB18 AFA2001C */  sw    $v0, 0x1c($sp)
/* 13EE5C 8024BB1C 93A201A3 */  lbu   $v0, 0x1a3($sp)
/* 13EE60 8024BB20 0000202D */  daddu $a0, $zero, $zero
/* 13EE64 8024BB24 AFA20020 */  sw    $v0, 0x20($sp)
/* 13EE68 8024BB28 8FA20198 */  lw    $v0, 0x198($sp)
/* 13EE6C 8024BB2C 3C058027 */  lui   $a1, 0x8027
/* 13EE70 8024BB30 24A5FD98 */  addiu $a1, $a1, -0x268
/* 13EE74 8024BB34 AFA00010 */  sw    $zero, 0x10($sp)
/* 13EE78 8024BB38 AFA0002C */  sw    $zero, 0x2c($sp)
/* 13EE7C 8024BB3C AFA00030 */  sw    $zero, 0x30($sp)
/* 13EE80 8024BB40 AFA00034 */  sw    $zero, 0x34($sp)
/* 13EE84 8024BB44 AFA00038 */  sw    $zero, 0x38($sp)
/* 13EE88 8024BB48 AFA0003C */  sw    $zero, 0x3c($sp)
/* 13EE8C 8024BB4C AFA00040 */  sw    $zero, 0x40($sp)
/* 13EE90 8024BB50 AFA0004C */  sw    $zero, 0x4c($sp)
/* 13EE94 8024BB54 E7A00024 */  swc1  $f0, 0x24($sp)
/* 13EE98 8024BB58 E7A00028 */  swc1  $f0, 0x28($sp)
/* 13EE9C 8024BB5C AFAD0044 */  sw    $t5, 0x44($sp)
/* 13EEA0 8024BB60 0C03D4B8 */  jal   draw_box
/* 13EEA4 8024BB64 AFA20048 */   sw    $v0, 0x48($sp)
.L8024BB68:
/* 13EEA8 8024BB68 8FBF015C */  lw    $ra, 0x15c($sp)
/* 13EEAC 8024BB6C 8FBE0158 */  lw    $fp, 0x158($sp)
/* 13EEB0 8024BB70 8FB70154 */  lw    $s7, 0x154($sp)
/* 13EEB4 8024BB74 8FB60150 */  lw    $s6, 0x150($sp)
/* 13EEB8 8024BB78 8FB5014C */  lw    $s5, 0x14c($sp)
/* 13EEBC 8024BB7C 8FB40148 */  lw    $s4, 0x148($sp)
/* 13EEC0 8024BB80 8FB30144 */  lw    $s3, 0x144($sp)
/* 13EEC4 8024BB84 8FB20140 */  lw    $s2, 0x140($sp)
/* 13EEC8 8024BB88 8FB1013C */  lw    $s1, 0x13c($sp)
/* 13EECC 8024BB8C 8FB00138 */  lw    $s0, 0x138($sp)
/* 13EED0 8024BB90 D7BC0180 */  ldc1  $f28, 0x180($sp)
/* 13EED4 8024BB94 D7BA0178 */  ldc1  $f26, 0x178($sp)
/* 13EED8 8024BB98 D7B80170 */  ldc1  $f24, 0x170($sp)
/* 13EEDC 8024BB9C D7B60168 */  ldc1  $f22, 0x168($sp)
/* 13EEE0 8024BBA0 D7B40160 */  ldc1  $f20, 0x160($sp)
/* 13EEE4 8024BBA4 03E00008 */  jr    $ra
/* 13EEE8 8024BBA8 27BD0188 */   addiu $sp, $sp, 0x188

/* 13EEEC 8024BBAC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 13EEF0 8024BBB0 AFB00018 */  sw    $s0, 0x18($sp)
/* 13EEF4 8024BBB4 3C108027 */  lui   $s0, 0x8027
/* 13EEF8 8024BBB8 261006A0 */  addiu $s0, $s0, 0x6a0
/* 13EEFC 8024BBBC AFBF002C */  sw    $ra, 0x2c($sp)

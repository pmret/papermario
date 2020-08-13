.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetCamTarget
/* 0EF8DC 802CAF2C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EF8E0 802CAF30 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF8E4 802CAF34 0080882D */  daddu $s1, $a0, $zero
/* 0EF8E8 802CAF38 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0EF8EC 802CAF3C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF8F0 802CAF40 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF8F4 802CAF44 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF8F8 802CAF48 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF8FC 802CAF4C 8E050000 */  lw    $a1, ($s0)
/* 0EF900 802CAF50 0C0B1EAF */  jal   get_variable
/* 0EF904 802CAF54 26100004 */   addiu $s0, $s0, 4
/* 0EF908 802CAF58 8E050000 */  lw    $a1, ($s0)
/* 0EF90C 802CAF5C 26100004 */  addiu $s0, $s0, 4
/* 0EF910 802CAF60 0220202D */  daddu $a0, $s1, $zero
/* 0EF914 802CAF64 0C0B1EAF */  jal   get_variable
/* 0EF918 802CAF68 0040902D */   daddu $s2, $v0, $zero
/* 0EF91C 802CAF6C 8E050000 */  lw    $a1, ($s0)
/* 0EF920 802CAF70 26100004 */  addiu $s0, $s0, 4
/* 0EF924 802CAF74 0220202D */  daddu $a0, $s1, $zero
/* 0EF928 802CAF78 0C0B1EAF */  jal   get_variable
/* 0EF92C 802CAF7C 0040982D */   daddu $s3, $v0, $zero
/* 0EF930 802CAF80 0220202D */  daddu $a0, $s1, $zero
/* 0EF934 802CAF84 8E050000 */  lw    $a1, ($s0)
/* 0EF938 802CAF88 0C0B1EAF */  jal   get_variable
/* 0EF93C 802CAF8C 0040802D */   daddu $s0, $v0, $zero
/* 0EF940 802CAF90 44821000 */  mtc1  $v0, $f2
/* 0EF944 802CAF94 00000000 */  nop   
/* 0EF948 802CAF98 468010A0 */  cvt.s.w $f2, $f2
/* 0EF94C 802CAF9C 24020002 */  addiu $v0, $zero, 2
/* 0EF950 802CAFA0 3C05800B */  lui   $a1, 0x800b
/* 0EF954 802CAFA4 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0EF958 802CAFA8 00521804 */  sllv  $v1, $s2, $v0
/* 0EF95C 802CAFAC 00721821 */  addu  $v1, $v1, $s2
/* 0EF960 802CAFB0 00431804 */  sllv  $v1, $v1, $v0
/* 0EF964 802CAFB4 00721823 */  subu  $v1, $v1, $s2
/* 0EF968 802CAFB8 000320C0 */  sll   $a0, $v1, 3
/* 0EF96C 802CAFBC 00641821 */  addu  $v1, $v1, $a0
/* 0EF970 802CAFC0 000318C0 */  sll   $v1, $v1, 3
/* 0EF974 802CAFC4 00651821 */  addu  $v1, $v1, $a1
/* 0EF978 802CAFC8 44930000 */  mtc1  $s3, $f0
/* 0EF97C 802CAFCC 00000000 */  nop   
/* 0EF980 802CAFD0 46800020 */  cvt.s.w $f0, $f0
/* 0EF984 802CAFD4 E4600060 */  swc1  $f0, 0x60($v1)
/* 0EF988 802CAFD8 44900000 */  mtc1  $s0, $f0
/* 0EF98C 802CAFDC 00000000 */  nop   
/* 0EF990 802CAFE0 46800020 */  cvt.s.w $f0, $f0
/* 0EF994 802CAFE4 E4600064 */  swc1  $f0, 0x64($v1)
/* 0EF998 802CAFE8 E4620068 */  swc1  $f2, 0x68($v1)
/* 0EF99C 802CAFEC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0EF9A0 802CAFF0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EF9A4 802CAFF4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EF9A8 802CAFF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF9AC 802CAFFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF9B0 802CB000 03E00008 */  jr    $ra
/* 0EF9B4 802CB004 27BD0028 */   addiu $sp, $sp, 0x28

/* 0EF9B8 802CB008 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0EF9BC 802CB00C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF9C0 802CB010 0080982D */  daddu $s3, $a0, $zero
/* 0EF9C4 802CB014 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0EF9C8 802CB018 AFB60028 */  sw    $s6, 0x28($sp)
/* 0EF9CC 802CB01C AFB50024 */  sw    $s5, 0x24($sp)
/* 0EF9D0 802CB020 AFB40020 */  sw    $s4, 0x20($sp)
/* 0EF9D4 802CB024 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF9D8 802CB028 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF9DC 802CB02C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF9E0 802CB030 10A00066 */  beqz  $a1, .L802CB1CC
/* 0EF9E4 802CB034 8E72000C */   lw    $s2, 0xc($s3)
/* 0EF9E8 802CB038 8E450000 */  lw    $a1, ($s2)
/* 0EF9EC 802CB03C 0C0B1EAF */  jal   get_variable
/* 0EF9F0 802CB040 26520004 */   addiu $s2, $s2, 4
/* 0EF9F4 802CB044 8E450000 */  lw    $a1, ($s2)
/* 0EF9F8 802CB048 26520004 */  addiu $s2, $s2, 4
/* 0EF9FC 802CB04C 0260202D */  daddu $a0, $s3, $zero
/* 0EFA00 802CB050 0C0B1EAF */  jal   get_variable
/* 0EFA04 802CB054 0040802D */   daddu $s0, $v0, $zero
/* 0EFA08 802CB058 8E450000 */  lw    $a1, ($s2)
/* 0EFA0C 802CB05C 26520004 */  addiu $s2, $s2, 4
/* 0EFA10 802CB060 0260202D */  daddu $a0, $s3, $zero
/* 0EFA14 802CB064 0C0B1EAF */  jal   get_variable
/* 0EFA18 802CB068 0040882D */   daddu $s1, $v0, $zero
/* 0EFA1C 802CB06C 8E450000 */  lw    $a1, ($s2)
/* 0EFA20 802CB070 26520004 */  addiu $s2, $s2, 4
/* 0EFA24 802CB074 0260202D */  daddu $a0, $s3, $zero
/* 0EFA28 802CB078 0C0B1EAF */  jal   get_variable
/* 0EFA2C 802CB07C 0040A02D */   daddu $s4, $v0, $zero
/* 0EFA30 802CB080 8E450000 */  lw    $a1, ($s2)
/* 0EFA34 802CB084 26520004 */  addiu $s2, $s2, 4
/* 0EFA38 802CB088 0260202D */  daddu $a0, $s3, $zero
/* 0EFA3C 802CB08C 0C0B1EAF */  jal   get_variable
/* 0EFA40 802CB090 0040A82D */   daddu $s5, $v0, $zero
/* 0EFA44 802CB094 0260202D */  daddu $a0, $s3, $zero
/* 0EFA48 802CB098 8E450000 */  lw    $a1, ($s2)
/* 0EFA4C 802CB09C 0C0B1EAF */  jal   get_variable
/* 0EFA50 802CB0A0 0040B02D */   daddu $s6, $v0, $zero
/* 0EFA54 802CB0A4 24040018 */  addiu $a0, $zero, 0x18
/* 0EFA58 802CB0A8 0C00AB39 */  jal   heap_malloc
/* 0EFA5C 802CB0AC 0040902D */   daddu $s2, $v0, $zero
/* 0EFA60 802CB0B0 0040282D */  daddu $a1, $v0, $zero
/* 0EFA64 802CB0B4 3C04800B */  lui   $a0, 0x800b
/* 0EFA68 802CB0B8 24841D80 */  addiu $a0, $a0, 0x1d80
/* 0EFA6C 802CB0BC 00101080 */  sll   $v0, $s0, 2
/* 0EFA70 802CB0C0 00501021 */  addu  $v0, $v0, $s0
/* 0EFA74 802CB0C4 00021080 */  sll   $v0, $v0, 2
/* 0EFA78 802CB0C8 00501023 */  subu  $v0, $v0, $s0
/* 0EFA7C 802CB0CC 000218C0 */  sll   $v1, $v0, 3
/* 0EFA80 802CB0D0 00431021 */  addu  $v0, $v0, $v1
/* 0EFA84 802CB0D4 000210C0 */  sll   $v0, $v0, 3
/* 0EFA88 802CB0D8 AE650060 */  sw    $a1, 0x60($s3)
/* 0EFA8C 802CB0DC ACB10004 */  sw    $s1, 4($a1)
/* 0EFA90 802CB0E0 0220302D */  daddu $a2, $s1, $zero
/* 0EFA94 802CB0E4 00441821 */  addu  $v1, $v0, $a0
/* 0EFA98 802CB0E8 ACA30000 */  sw    $v1, ($a1)
/* 0EFA9C 802CB0EC 10C00006 */  beqz  $a2, .L802CB108
/* 0EFAA0 802CB0F0 ACB20014 */   sw    $s2, 0x14($a1)
/* 0EFAA4 802CB0F4 24020001 */  addiu $v0, $zero, 1
/* 0EFAA8 802CB0F8 10C20018 */  beq   $a2, $v0, .L802CB15C
/* 0EFAAC 802CB0FC 00000000 */   nop   
/* 0EFAB0 802CB100 080B2C73 */  j     .L802CB1CC
/* 0EFAB4 802CB104 00000000 */   nop   

.L802CB108:
/* 0EFAB8 802CB108 C4620054 */  lwc1  $f2, 0x54($v1)
/* 0EFABC 802CB10C 44940000 */  mtc1  $s4, $f0
/* 0EFAC0 802CB110 00000000 */  nop   
/* 0EFAC4 802CB114 46800020 */  cvt.s.w $f0, $f0
/* 0EFAC8 802CB118 46020001 */  sub.s $f0, $f0, $f2
/* 0EFACC 802CB11C 44921000 */  mtc1  $s2, $f2
/* 0EFAD0 802CB120 00000000 */  nop   
/* 0EFAD4 802CB124 468010A0 */  cvt.s.w $f2, $f2
/* 0EFAD8 802CB128 46020003 */  div.s $f0, $f0, $f2
/* 0EFADC 802CB12C E4A00008 */  swc1  $f0, 8($a1)
/* 0EFAE0 802CB130 C4620058 */  lwc1  $f2, 0x58($v1)
/* 0EFAE4 802CB134 44950000 */  mtc1  $s5, $f0
/* 0EFAE8 802CB138 00000000 */  nop   
/* 0EFAEC 802CB13C 46800020 */  cvt.s.w $f0, $f0
/* 0EFAF0 802CB140 46020001 */  sub.s $f0, $f0, $f2
/* 0EFAF4 802CB144 C4A20014 */  lwc1  $f2, 0x14($a1)
/* 0EFAF8 802CB148 468010A0 */  cvt.s.w $f2, $f2
/* 0EFAFC 802CB14C 46020003 */  div.s $f0, $f0, $f2
/* 0EFB00 802CB150 E4A0000C */  swc1  $f0, 0xc($a1)
/* 0EFB04 802CB154 080B2C6B */  j     .L802CB1AC
/* 0EFB08 802CB158 C462005C */   lwc1  $f2, 0x5c($v1)

.L802CB15C:
/* 0EFB0C 802CB15C C4620060 */  lwc1  $f2, 0x60($v1)
/* 0EFB10 802CB160 44940000 */  mtc1  $s4, $f0
/* 0EFB14 802CB164 00000000 */  nop   
/* 0EFB18 802CB168 46800020 */  cvt.s.w $f0, $f0
/* 0EFB1C 802CB16C 46020001 */  sub.s $f0, $f0, $f2
/* 0EFB20 802CB170 44921000 */  mtc1  $s2, $f2
/* 0EFB24 802CB174 00000000 */  nop   
/* 0EFB28 802CB178 468010A0 */  cvt.s.w $f2, $f2
/* 0EFB2C 802CB17C 46020003 */  div.s $f0, $f0, $f2
/* 0EFB30 802CB180 E4A00008 */  swc1  $f0, 8($a1)
/* 0EFB34 802CB184 C4620064 */  lwc1  $f2, 0x64($v1)
/* 0EFB38 802CB188 44950000 */  mtc1  $s5, $f0
/* 0EFB3C 802CB18C 00000000 */  nop   
/* 0EFB40 802CB190 46800020 */  cvt.s.w $f0, $f0
/* 0EFB44 802CB194 46020001 */  sub.s $f0, $f0, $f2
/* 0EFB48 802CB198 C4A20014 */  lwc1  $f2, 0x14($a1)
/* 0EFB4C 802CB19C 468010A0 */  cvt.s.w $f2, $f2
/* 0EFB50 802CB1A0 46020003 */  div.s $f0, $f0, $f2
/* 0EFB54 802CB1A4 E4A0000C */  swc1  $f0, 0xc($a1)
/* 0EFB58 802CB1A8 C4620068 */  lwc1  $f2, 0x68($v1)
.L802CB1AC:
/* 0EFB5C 802CB1AC 44960000 */  mtc1  $s6, $f0
/* 0EFB60 802CB1B0 00000000 */  nop   
/* 0EFB64 802CB1B4 46800020 */  cvt.s.w $f0, $f0
/* 0EFB68 802CB1B8 46020001 */  sub.s $f0, $f0, $f2
/* 0EFB6C 802CB1BC C4A20014 */  lwc1  $f2, 0x14($a1)
/* 0EFB70 802CB1C0 468010A0 */  cvt.s.w $f2, $f2
/* 0EFB74 802CB1C4 46020003 */  div.s $f0, $f0, $f2
/* 0EFB78 802CB1C8 E4A00010 */  swc1  $f0, 0x10($a1)
.L802CB1CC:
/* 0EFB7C 802CB1CC 8E650060 */  lw    $a1, 0x60($s3)
/* 0EFB80 802CB1D0 8CA40004 */  lw    $a0, 4($a1)
/* 0EFB84 802CB1D4 8CA30000 */  lw    $v1, ($a1)
/* 0EFB88 802CB1D8 10800005 */  beqz  $a0, .L802CB1F0
/* 0EFB8C 802CB1DC 24020001 */   addiu $v0, $zero, 1
/* 0EFB90 802CB1E0 10820010 */  beq   $a0, $v0, .L802CB224
/* 0EFB94 802CB1E4 00000000 */   nop   
/* 0EFB98 802CB1E8 080B2C95 */  j     .L802CB254
/* 0EFB9C 802CB1EC 00000000 */   nop   

.L802CB1F0:
/* 0EFBA0 802CB1F0 C4600054 */  lwc1  $f0, 0x54($v1)
/* 0EFBA4 802CB1F4 C4A20008 */  lwc1  $f2, 8($a1)
/* 0EFBA8 802CB1F8 46020000 */  add.s $f0, $f0, $f2
/* 0EFBAC 802CB1FC E4600054 */  swc1  $f0, 0x54($v1)
/* 0EFBB0 802CB200 C4600058 */  lwc1  $f0, 0x58($v1)
/* 0EFBB4 802CB204 C4A2000C */  lwc1  $f2, 0xc($a1)
/* 0EFBB8 802CB208 46020000 */  add.s $f0, $f0, $f2
/* 0EFBBC 802CB20C E4600058 */  swc1  $f0, 0x58($v1)
/* 0EFBC0 802CB210 C460005C */  lwc1  $f0, 0x5c($v1)
/* 0EFBC4 802CB214 C4A20010 */  lwc1  $f2, 0x10($a1)
/* 0EFBC8 802CB218 46020000 */  add.s $f0, $f0, $f2
/* 0EFBCC 802CB21C 080B2C95 */  j     .L802CB254
/* 0EFBD0 802CB220 E460005C */   swc1  $f0, 0x5c($v1)

.L802CB224:
/* 0EFBD4 802CB224 C4600060 */  lwc1  $f0, 0x60($v1)
/* 0EFBD8 802CB228 C4A20008 */  lwc1  $f2, 8($a1)
/* 0EFBDC 802CB22C 46020000 */  add.s $f0, $f0, $f2
/* 0EFBE0 802CB230 E4600060 */  swc1  $f0, 0x60($v1)
/* 0EFBE4 802CB234 C4600064 */  lwc1  $f0, 0x64($v1)
/* 0EFBE8 802CB238 C4A2000C */  lwc1  $f2, 0xc($a1)
/* 0EFBEC 802CB23C 46020000 */  add.s $f0, $f0, $f2
/* 0EFBF0 802CB240 E4600064 */  swc1  $f0, 0x64($v1)
/* 0EFBF4 802CB244 C4600068 */  lwc1  $f0, 0x68($v1)
/* 0EFBF8 802CB248 C4A20010 */  lwc1  $f2, 0x10($a1)
/* 0EFBFC 802CB24C 46020000 */  add.s $f0, $f0, $f2
/* 0EFC00 802CB250 E4600068 */  swc1  $f0, 0x68($v1)
.L802CB254:
/* 0EFC04 802CB254 8CA20014 */  lw    $v0, 0x14($a1)
/* 0EFC08 802CB258 2442FFFF */  addiu $v0, $v0, -1
/* 0EFC0C 802CB25C 10400003 */  beqz  $v0, .L802CB26C
/* 0EFC10 802CB260 ACA20014 */   sw    $v0, 0x14($a1)
/* 0EFC14 802CB264 080B2CA0 */  j     .L802CB280
/* 0EFC18 802CB268 0000102D */   daddu $v0, $zero, $zero

.L802CB26C:
/* 0EFC1C 802CB26C 8E640060 */  lw    $a0, 0x60($s3)
/* 0EFC20 802CB270 0C00AB4B */  jal   heap_free
/* 0EFC24 802CB274 00000000 */   nop   
/* 0EFC28 802CB278 24020002 */  addiu $v0, $zero, 2
/* 0EFC2C 802CB27C AE600060 */  sw    $zero, 0x60($s3)
.L802CB280:
/* 0EFC30 802CB280 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0EFC34 802CB284 8FB60028 */  lw    $s6, 0x28($sp)
/* 0EFC38 802CB288 8FB50024 */  lw    $s5, 0x24($sp)
/* 0EFC3C 802CB28C 8FB40020 */  lw    $s4, 0x20($sp)
/* 0EFC40 802CB290 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EFC44 802CB294 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EFC48 802CB298 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EFC4C 802CB29C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EFC50 802CB2A0 03E00008 */  jr    $ra
/* 0EFC54 802CB2A4 27BD0030 */   addiu $sp, $sp, 0x30


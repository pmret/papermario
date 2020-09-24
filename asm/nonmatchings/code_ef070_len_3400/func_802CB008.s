.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CB008
/* EF9B8 802CB008 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EF9BC 802CB00C AFB3001C */  sw        $s3, 0x1c($sp)
/* EF9C0 802CB010 0080982D */  daddu     $s3, $a0, $zero
/* EF9C4 802CB014 AFBF002C */  sw        $ra, 0x2c($sp)
/* EF9C8 802CB018 AFB60028 */  sw        $s6, 0x28($sp)
/* EF9CC 802CB01C AFB50024 */  sw        $s5, 0x24($sp)
/* EF9D0 802CB020 AFB40020 */  sw        $s4, 0x20($sp)
/* EF9D4 802CB024 AFB20018 */  sw        $s2, 0x18($sp)
/* EF9D8 802CB028 AFB10014 */  sw        $s1, 0x14($sp)
/* EF9DC 802CB02C AFB00010 */  sw        $s0, 0x10($sp)
/* EF9E0 802CB030 10A00066 */  beqz      $a1, .L802CB1CC
/* EF9E4 802CB034 8E72000C */   lw       $s2, 0xc($s3)
/* EF9E8 802CB038 8E450000 */  lw        $a1, ($s2)
/* EF9EC 802CB03C 0C0B1EAF */  jal       get_variable
/* EF9F0 802CB040 26520004 */   addiu    $s2, $s2, 4
/* EF9F4 802CB044 8E450000 */  lw        $a1, ($s2)
/* EF9F8 802CB048 26520004 */  addiu     $s2, $s2, 4
/* EF9FC 802CB04C 0260202D */  daddu     $a0, $s3, $zero
/* EFA00 802CB050 0C0B1EAF */  jal       get_variable
/* EFA04 802CB054 0040802D */   daddu    $s0, $v0, $zero
/* EFA08 802CB058 8E450000 */  lw        $a1, ($s2)
/* EFA0C 802CB05C 26520004 */  addiu     $s2, $s2, 4
/* EFA10 802CB060 0260202D */  daddu     $a0, $s3, $zero
/* EFA14 802CB064 0C0B1EAF */  jal       get_variable
/* EFA18 802CB068 0040882D */   daddu    $s1, $v0, $zero
/* EFA1C 802CB06C 8E450000 */  lw        $a1, ($s2)
/* EFA20 802CB070 26520004 */  addiu     $s2, $s2, 4
/* EFA24 802CB074 0260202D */  daddu     $a0, $s3, $zero
/* EFA28 802CB078 0C0B1EAF */  jal       get_variable
/* EFA2C 802CB07C 0040A02D */   daddu    $s4, $v0, $zero
/* EFA30 802CB080 8E450000 */  lw        $a1, ($s2)
/* EFA34 802CB084 26520004 */  addiu     $s2, $s2, 4
/* EFA38 802CB088 0260202D */  daddu     $a0, $s3, $zero
/* EFA3C 802CB08C 0C0B1EAF */  jal       get_variable
/* EFA40 802CB090 0040A82D */   daddu    $s5, $v0, $zero
/* EFA44 802CB094 0260202D */  daddu     $a0, $s3, $zero
/* EFA48 802CB098 8E450000 */  lw        $a1, ($s2)
/* EFA4C 802CB09C 0C0B1EAF */  jal       get_variable
/* EFA50 802CB0A0 0040B02D */   daddu    $s6, $v0, $zero
/* EFA54 802CB0A4 24040018 */  addiu     $a0, $zero, 0x18
/* EFA58 802CB0A8 0C00AB39 */  jal       heap_malloc
/* EFA5C 802CB0AC 0040902D */   daddu    $s2, $v0, $zero
/* EFA60 802CB0B0 0040282D */  daddu     $a1, $v0, $zero
/* EFA64 802CB0B4 3C04800B */  lui       $a0, 0x800b
/* EFA68 802CB0B8 24841D80 */  addiu     $a0, $a0, 0x1d80
/* EFA6C 802CB0BC 00101080 */  sll       $v0, $s0, 2
/* EFA70 802CB0C0 00501021 */  addu      $v0, $v0, $s0
/* EFA74 802CB0C4 00021080 */  sll       $v0, $v0, 2
/* EFA78 802CB0C8 00501023 */  subu      $v0, $v0, $s0
/* EFA7C 802CB0CC 000218C0 */  sll       $v1, $v0, 3
/* EFA80 802CB0D0 00431021 */  addu      $v0, $v0, $v1
/* EFA84 802CB0D4 000210C0 */  sll       $v0, $v0, 3
/* EFA88 802CB0D8 AE650060 */  sw        $a1, 0x60($s3)
/* EFA8C 802CB0DC ACB10004 */  sw        $s1, 4($a1)
/* EFA90 802CB0E0 0220302D */  daddu     $a2, $s1, $zero
/* EFA94 802CB0E4 00441821 */  addu      $v1, $v0, $a0
/* EFA98 802CB0E8 ACA30000 */  sw        $v1, ($a1)
/* EFA9C 802CB0EC 10C00006 */  beqz      $a2, .L802CB108
/* EFAA0 802CB0F0 ACB20014 */   sw       $s2, 0x14($a1)
/* EFAA4 802CB0F4 24020001 */  addiu     $v0, $zero, 1
/* EFAA8 802CB0F8 10C20018 */  beq       $a2, $v0, .L802CB15C
/* EFAAC 802CB0FC 00000000 */   nop      
/* EFAB0 802CB100 080B2C73 */  j         .L802CB1CC
/* EFAB4 802CB104 00000000 */   nop      
.L802CB108:
/* EFAB8 802CB108 C4620054 */  lwc1      $f2, 0x54($v1)
/* EFABC 802CB10C 44940000 */  mtc1      $s4, $f0
/* EFAC0 802CB110 00000000 */  nop       
/* EFAC4 802CB114 46800020 */  cvt.s.w   $f0, $f0
/* EFAC8 802CB118 46020001 */  sub.s     $f0, $f0, $f2
/* EFACC 802CB11C 44921000 */  mtc1      $s2, $f2
/* EFAD0 802CB120 00000000 */  nop       
/* EFAD4 802CB124 468010A0 */  cvt.s.w   $f2, $f2
/* EFAD8 802CB128 46020003 */  div.s     $f0, $f0, $f2
/* EFADC 802CB12C E4A00008 */  swc1      $f0, 8($a1)
/* EFAE0 802CB130 C4620058 */  lwc1      $f2, 0x58($v1)
/* EFAE4 802CB134 44950000 */  mtc1      $s5, $f0
/* EFAE8 802CB138 00000000 */  nop       
/* EFAEC 802CB13C 46800020 */  cvt.s.w   $f0, $f0
/* EFAF0 802CB140 46020001 */  sub.s     $f0, $f0, $f2
/* EFAF4 802CB144 C4A20014 */  lwc1      $f2, 0x14($a1)
/* EFAF8 802CB148 468010A0 */  cvt.s.w   $f2, $f2
/* EFAFC 802CB14C 46020003 */  div.s     $f0, $f0, $f2
/* EFB00 802CB150 E4A0000C */  swc1      $f0, 0xc($a1)
/* EFB04 802CB154 080B2C6B */  j         .L802CB1AC
/* EFB08 802CB158 C462005C */   lwc1     $f2, 0x5c($v1)
.L802CB15C:
/* EFB0C 802CB15C C4620060 */  lwc1      $f2, 0x60($v1)
/* EFB10 802CB160 44940000 */  mtc1      $s4, $f0
/* EFB14 802CB164 00000000 */  nop       
/* EFB18 802CB168 46800020 */  cvt.s.w   $f0, $f0
/* EFB1C 802CB16C 46020001 */  sub.s     $f0, $f0, $f2
/* EFB20 802CB170 44921000 */  mtc1      $s2, $f2
/* EFB24 802CB174 00000000 */  nop       
/* EFB28 802CB178 468010A0 */  cvt.s.w   $f2, $f2
/* EFB2C 802CB17C 46020003 */  div.s     $f0, $f0, $f2
/* EFB30 802CB180 E4A00008 */  swc1      $f0, 8($a1)
/* EFB34 802CB184 C4620064 */  lwc1      $f2, 0x64($v1)
/* EFB38 802CB188 44950000 */  mtc1      $s5, $f0
/* EFB3C 802CB18C 00000000 */  nop       
/* EFB40 802CB190 46800020 */  cvt.s.w   $f0, $f0
/* EFB44 802CB194 46020001 */  sub.s     $f0, $f0, $f2
/* EFB48 802CB198 C4A20014 */  lwc1      $f2, 0x14($a1)
/* EFB4C 802CB19C 468010A0 */  cvt.s.w   $f2, $f2
/* EFB50 802CB1A0 46020003 */  div.s     $f0, $f0, $f2
/* EFB54 802CB1A4 E4A0000C */  swc1      $f0, 0xc($a1)
/* EFB58 802CB1A8 C4620068 */  lwc1      $f2, 0x68($v1)
.L802CB1AC:
/* EFB5C 802CB1AC 44960000 */  mtc1      $s6, $f0
/* EFB60 802CB1B0 00000000 */  nop       
/* EFB64 802CB1B4 46800020 */  cvt.s.w   $f0, $f0
/* EFB68 802CB1B8 46020001 */  sub.s     $f0, $f0, $f2
/* EFB6C 802CB1BC C4A20014 */  lwc1      $f2, 0x14($a1)
/* EFB70 802CB1C0 468010A0 */  cvt.s.w   $f2, $f2
/* EFB74 802CB1C4 46020003 */  div.s     $f0, $f0, $f2
/* EFB78 802CB1C8 E4A00010 */  swc1      $f0, 0x10($a1)
.L802CB1CC:
/* EFB7C 802CB1CC 8E650060 */  lw        $a1, 0x60($s3)
/* EFB80 802CB1D0 8CA40004 */  lw        $a0, 4($a1)
/* EFB84 802CB1D4 8CA30000 */  lw        $v1, ($a1)
/* EFB88 802CB1D8 10800005 */  beqz      $a0, .L802CB1F0
/* EFB8C 802CB1DC 24020001 */   addiu    $v0, $zero, 1
/* EFB90 802CB1E0 10820010 */  beq       $a0, $v0, .L802CB224
/* EFB94 802CB1E4 00000000 */   nop      
/* EFB98 802CB1E8 080B2C95 */  j         .L802CB254
/* EFB9C 802CB1EC 00000000 */   nop      
.L802CB1F0:
/* EFBA0 802CB1F0 C4600054 */  lwc1      $f0, 0x54($v1)
/* EFBA4 802CB1F4 C4A20008 */  lwc1      $f2, 8($a1)
/* EFBA8 802CB1F8 46020000 */  add.s     $f0, $f0, $f2
/* EFBAC 802CB1FC E4600054 */  swc1      $f0, 0x54($v1)
/* EFBB0 802CB200 C4600058 */  lwc1      $f0, 0x58($v1)
/* EFBB4 802CB204 C4A2000C */  lwc1      $f2, 0xc($a1)
/* EFBB8 802CB208 46020000 */  add.s     $f0, $f0, $f2
/* EFBBC 802CB20C E4600058 */  swc1      $f0, 0x58($v1)
/* EFBC0 802CB210 C460005C */  lwc1      $f0, 0x5c($v1)
/* EFBC4 802CB214 C4A20010 */  lwc1      $f2, 0x10($a1)
/* EFBC8 802CB218 46020000 */  add.s     $f0, $f0, $f2
/* EFBCC 802CB21C 080B2C95 */  j         .L802CB254
/* EFBD0 802CB220 E460005C */   swc1     $f0, 0x5c($v1)
.L802CB224:
/* EFBD4 802CB224 C4600060 */  lwc1      $f0, 0x60($v1)
/* EFBD8 802CB228 C4A20008 */  lwc1      $f2, 8($a1)
/* EFBDC 802CB22C 46020000 */  add.s     $f0, $f0, $f2
/* EFBE0 802CB230 E4600060 */  swc1      $f0, 0x60($v1)
/* EFBE4 802CB234 C4600064 */  lwc1      $f0, 0x64($v1)
/* EFBE8 802CB238 C4A2000C */  lwc1      $f2, 0xc($a1)
/* EFBEC 802CB23C 46020000 */  add.s     $f0, $f0, $f2
/* EFBF0 802CB240 E4600064 */  swc1      $f0, 0x64($v1)
/* EFBF4 802CB244 C4600068 */  lwc1      $f0, 0x68($v1)
/* EFBF8 802CB248 C4A20010 */  lwc1      $f2, 0x10($a1)
/* EFBFC 802CB24C 46020000 */  add.s     $f0, $f0, $f2
/* EFC00 802CB250 E4600068 */  swc1      $f0, 0x68($v1)
.L802CB254:
/* EFC04 802CB254 8CA20014 */  lw        $v0, 0x14($a1)
/* EFC08 802CB258 2442FFFF */  addiu     $v0, $v0, -1
/* EFC0C 802CB25C 10400003 */  beqz      $v0, .L802CB26C
/* EFC10 802CB260 ACA20014 */   sw       $v0, 0x14($a1)
/* EFC14 802CB264 080B2CA0 */  j         .L802CB280
/* EFC18 802CB268 0000102D */   daddu    $v0, $zero, $zero
.L802CB26C:
/* EFC1C 802CB26C 8E640060 */  lw        $a0, 0x60($s3)
/* EFC20 802CB270 0C00AB4B */  jal       heap_free
/* EFC24 802CB274 00000000 */   nop      
/* EFC28 802CB278 24020002 */  addiu     $v0, $zero, 2
/* EFC2C 802CB27C AE600060 */  sw        $zero, 0x60($s3)
.L802CB280:
/* EFC30 802CB280 8FBF002C */  lw        $ra, 0x2c($sp)
/* EFC34 802CB284 8FB60028 */  lw        $s6, 0x28($sp)
/* EFC38 802CB288 8FB50024 */  lw        $s5, 0x24($sp)
/* EFC3C 802CB28C 8FB40020 */  lw        $s4, 0x20($sp)
/* EFC40 802CB290 8FB3001C */  lw        $s3, 0x1c($sp)
/* EFC44 802CB294 8FB20018 */  lw        $s2, 0x18($sp)
/* EFC48 802CB298 8FB10014 */  lw        $s1, 0x14($sp)
/* EFC4C 802CB29C 8FB00010 */  lw        $s0, 0x10($sp)
/* EFC50 802CB2A0 03E00008 */  jr        $ra
/* EFC54 802CB2A4 27BD0030 */   addiu    $sp, $sp, 0x30

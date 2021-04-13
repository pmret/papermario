.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802BEC38_31CC58
.double 0.55

glabel D_802BEC40_31CC60
.double 0.8, 0.0

.section .text

glabel func_802BE818_31C838
/* 31C838 802BE818 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 31C83C 802BE81C AFB10044 */  sw        $s1, 0x44($sp)
/* 31C840 802BE820 3C11802C */  lui       $s1, %hi(D_802BEB40_31CB60)
/* 31C844 802BE824 2631EB40 */  addiu     $s1, $s1, %lo(D_802BEB40_31CB60)
/* 31C848 802BE828 AFBF0048 */  sw        $ra, 0x48($sp)
/* 31C84C 802BE82C AFB00040 */  sw        $s0, 0x40($sp)
/* 31C850 802BE830 F7BE0078 */  sdc1      $f30, 0x78($sp)
/* 31C854 802BE834 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 31C858 802BE838 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 31C85C 802BE83C F7B80060 */  sdc1      $f24, 0x60($sp)
/* 31C860 802BE840 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 31C864 802BE844 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 31C868 802BE848 8E220000 */  lw        $v0, ($s1)
/* 31C86C 802BE84C 10400069 */  beqz      $v0, .L802BE9F4
/* 31C870 802BE850 0080802D */   daddu    $s0, $a0, $zero
/* 31C874 802BE854 C6160038 */  lwc1      $f22, 0x38($s0)
/* 31C878 802BE858 C6180040 */  lwc1      $f24, 0x40($s0)
/* 31C87C 802BE85C 84A200A6 */  lh        $v0, 0xa6($a1)
/* 31C880 802BE860 3C01802C */  lui       $at, %hi(D_802BEC38_31CC58)
/* 31C884 802BE864 D420EC38 */  ldc1      $f0, %lo(D_802BEC38_31CC58)($at)
/* 31C888 802BE868 C4BE0038 */  lwc1      $f30, 0x38($a1)
/* 31C88C 802BE86C C4A80040 */  lwc1      $f8, 0x40($a1)
/* 31C890 802BE870 44822000 */  mtc1      $v0, $f4
/* 31C894 802BE874 00000000 */  nop
/* 31C898 802BE878 46802121 */  cvt.d.w   $f4, $f4
/* 31C89C 802BE87C 46004386 */  mov.s     $f14, $f8
/* 31C8A0 802BE880 46202102 */  mul.d     $f4, $f4, $f0
/* 31C8A4 802BE884 00000000 */  nop
/* 31C8A8 802BE888 E7A80030 */  swc1      $f8, 0x30($sp)
/* 31C8AC 802BE88C 860200A6 */  lh        $v0, 0xa6($s0)
/* 31C8B0 802BE890 3C01802C */  lui       $at, %hi(D_802BEC40_31CC60)
/* 31C8B4 802BE894 D420EC40 */  ldc1      $f0, %lo(D_802BEC40_31CC60)($at)
/* 31C8B8 802BE898 4406B000 */  mfc1      $a2, $f22
/* 31C8BC 802BE89C 44821000 */  mtc1      $v0, $f2
/* 31C8C0 802BE8A0 00000000 */  nop
/* 31C8C4 802BE8A4 468010A1 */  cvt.d.w   $f2, $f2
/* 31C8C8 802BE8A8 84A200A8 */  lh        $v0, 0xa8($a1)
/* 31C8CC 802BE8AC 4407C000 */  mfc1      $a3, $f24
/* 31C8D0 802BE8B0 44825000 */  mtc1      $v0, $f10
/* 31C8D4 802BE8B4 00000000 */  nop
/* 31C8D8 802BE8B8 468052A0 */  cvt.s.w   $f10, $f10
/* 31C8DC 802BE8BC E7AA0034 */  swc1      $f10, 0x34($sp)
/* 31C8E0 802BE8C0 860200A8 */  lh        $v0, 0xa8($s0)
/* 31C8E4 802BE8C4 46201082 */  mul.d     $f2, $f2, $f0
/* 31C8E8 802BE8C8 00000000 */  nop
/* 31C8EC 802BE8CC 44824000 */  mtc1      $v0, $f8
/* 31C8F0 802BE8D0 00000000 */  nop
/* 31C8F4 802BE8D4 46804220 */  cvt.s.w   $f8, $f8
/* 31C8F8 802BE8D8 E7A8003C */  swc1      $f8, 0x3c($sp)
/* 31C8FC 802BE8DC C4AA003C */  lwc1      $f10, 0x3c($a1)
/* 31C900 802BE8E0 E7AA002C */  swc1      $f10, 0x2c($sp)
/* 31C904 802BE8E4 C608003C */  lwc1      $f8, 0x3c($s0)
/* 31C908 802BE8E8 4600F306 */  mov.s     $f12, $f30
/* 31C90C 802BE8EC E7A80038 */  swc1      $f8, 0x38($sp)
/* 31C910 802BE8F0 46202720 */  cvt.s.d   $f28, $f4
/* 31C914 802BE8F4 0C00A720 */  jal       atan2
/* 31C918 802BE8F8 462016A0 */   cvt.s.d  $f26, $f2
/* 31C91C 802BE8FC 4600F306 */  mov.s     $f12, $f30
/* 31C920 802BE900 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 31C924 802BE904 4406B000 */  mfc1      $a2, $f22
/* 31C928 802BE908 4407C000 */  mfc1      $a3, $f24
/* 31C92C 802BE90C 0C00A7B5 */  jal       dist2D
/* 31C930 802BE910 46000506 */   mov.s    $f20, $f0
/* 31C934 802BE914 27A60024 */  addiu     $a2, $sp, 0x24
/* 31C938 802BE918 27A70028 */  addiu     $a3, $sp, 0x28
/* 31C93C 802BE91C 0000202D */  daddu     $a0, $zero, $zero
/* 31C940 802BE920 C6020038 */  lwc1      $f2, 0x38($s0)
/* 31C944 802BE924 C604003C */  lwc1      $f4, 0x3c($s0)
/* 31C948 802BE928 C6060040 */  lwc1      $f6, 0x40($s0)
/* 31C94C 802BE92C C7AA003C */  lwc1      $f10, 0x3c($sp)
/* 31C950 802BE930 27A50020 */  addiu     $a1, $sp, 0x20
/* 31C954 802BE934 E7A20020 */  swc1      $f2, 0x20($sp)
/* 31C958 802BE938 E7A40024 */  swc1      $f4, 0x24($sp)
/* 31C95C 802BE93C E7A60028 */  swc1      $f6, 0x28($sp)
/* 31C960 802BE940 E7A00010 */  swc1      $f0, 0x10($sp)
/* 31C964 802BE944 461CD000 */  add.s     $f0, $f26, $f28
/* 31C968 802BE948 E7B40014 */  swc1      $f20, 0x14($sp)
/* 31C96C 802BE94C E7AA0018 */  swc1      $f10, 0x18($sp)
/* 31C970 802BE950 0C0376B9 */  jal       func_800DDAE4
/* 31C974 802BE954 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31C978 802BE958 54400027 */  bnel      $v0, $zero, .L802BE9F8
/* 31C97C 802BE95C 0000102D */   daddu    $v0, $zero, $zero
/* 31C980 802BE960 C7A8002C */  lwc1      $f8, 0x2c($sp)
/* 31C984 802BE964 C7AA0034 */  lwc1      $f10, 0x34($sp)
/* 31C988 802BE968 460A4000 */  add.s     $f0, $f8, $f10
/* 31C98C 802BE96C C7A80038 */  lwc1      $f8, 0x38($sp)
/* 31C990 802BE970 4608003C */  c.lt.s    $f0, $f8
/* 31C994 802BE974 00000000 */  nop
/* 31C998 802BE978 4503001F */  bc1tl     .L802BE9F8
/* 31C99C 802BE97C 0000102D */   daddu    $v0, $zero, $zero
/* 31C9A0 802BE980 C7AA0038 */  lwc1      $f10, 0x38($sp)
/* 31C9A4 802BE984 C7A8003C */  lwc1      $f8, 0x3c($sp)
/* 31C9A8 802BE988 46085000 */  add.s     $f0, $f10, $f8
/* 31C9AC 802BE98C C7AA002C */  lwc1      $f10, 0x2c($sp)
/* 31C9B0 802BE990 460A003C */  c.lt.s    $f0, $f10
/* 31C9B4 802BE994 00000000 */  nop
/* 31C9B8 802BE998 45030017 */  bc1tl     .L802BE9F8
/* 31C9BC 802BE99C 0000102D */   daddu    $v0, $zero, $zero
/* 31C9C0 802BE9A0 461AD002 */  mul.s     $f0, $f26, $f26
/* 31C9C4 802BE9A4 00000000 */  nop
/* 31C9C8 802BE9A8 461CE082 */  mul.s     $f2, $f28, $f28
/* 31C9CC 802BE9AC 00000000 */  nop
/* 31C9D0 802BE9B0 4616F581 */  sub.s     $f22, $f30, $f22
/* 31C9D4 802BE9B4 4616B182 */  mul.s     $f6, $f22, $f22
/* 31C9D8 802BE9B8 00000000 */  nop
/* 31C9DC 802BE9BC C7A80030 */  lwc1      $f8, 0x30($sp)
/* 31C9E0 802BE9C0 46184601 */  sub.s     $f24, $f8, $f24
/* 31C9E4 802BE9C4 4618C102 */  mul.s     $f4, $f24, $f24
/* 31C9E8 802BE9C8 00000000 */  nop
/* 31C9EC 802BE9CC 46020000 */  add.s     $f0, $f0, $f2
/* 31C9F0 802BE9D0 46043180 */  add.s     $f6, $f6, $f4
/* 31C9F4 802BE9D4 4606003E */  c.le.s    $f0, $f6
/* 31C9F8 802BE9D8 00000000 */  nop
/* 31C9FC 802BE9DC 45030006 */  bc1tl     .L802BE9F8
/* 31CA00 802BE9E0 0000102D */   daddu    $v0, $zero, $zero
/* 31CA04 802BE9E4 24020002 */  addiu     $v0, $zero, 2
/* 31CA08 802BE9E8 AE220000 */  sw        $v0, ($s1)
/* 31CA0C 802BE9EC 080AFA7E */  j         .L802BE9F8
/* 31CA10 802BE9F0 24020001 */   addiu    $v0, $zero, 1
.L802BE9F4:
/* 31CA14 802BE9F4 0000102D */  daddu     $v0, $zero, $zero
.L802BE9F8:
/* 31CA18 802BE9F8 8FBF0048 */  lw        $ra, 0x48($sp)
/* 31CA1C 802BE9FC 8FB10044 */  lw        $s1, 0x44($sp)
/* 31CA20 802BEA00 8FB00040 */  lw        $s0, 0x40($sp)
/* 31CA24 802BEA04 D7BE0078 */  ldc1      $f30, 0x78($sp)
/* 31CA28 802BEA08 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 31CA2C 802BEA0C D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 31CA30 802BEA10 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 31CA34 802BEA14 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 31CA38 802BEA18 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 31CA3C 802BEA1C 03E00008 */  jr        $ra
/* 31CA40 802BEA20 27BD0080 */   addiu    $sp, $sp, 0x80

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240184_9EDD74
/* 9EDD74 80240184 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9EDD78 80240188 AFB20018 */  sw        $s2, 0x18($sp)
/* 9EDD7C 8024018C 0080902D */  daddu     $s2, $a0, $zero
/* 9EDD80 80240190 AFBF0028 */  sw        $ra, 0x28($sp)
/* 9EDD84 80240194 AFB50024 */  sw        $s5, 0x24($sp)
/* 9EDD88 80240198 AFB40020 */  sw        $s4, 0x20($sp)
/* 9EDD8C 8024019C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9EDD90 802401A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9EDD94 802401A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9EDD98 802401A8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 9EDD9C 802401AC F7B60038 */  sdc1      $f22, 0x38($sp)
/* 9EDDA0 802401B0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 9EDDA4 802401B4 8E50000C */  lw        $s0, 0xc($s2)
/* 9EDDA8 802401B8 8E140000 */  lw        $s4, ($s0)
/* 9EDDAC 802401BC 26100004 */  addiu     $s0, $s0, 4
/* 9EDDB0 802401C0 0C0B1EAF */  jal       get_variable
/* 9EDDB4 802401C4 0280282D */   daddu    $a1, $s4, $zero
/* 9EDDB8 802401C8 0040982D */  daddu     $s3, $v0, $zero
/* 9EDDBC 802401CC 8E150000 */  lw        $s5, ($s0)
/* 9EDDC0 802401D0 26100004 */  addiu     $s0, $s0, 4
/* 9EDDC4 802401D4 8E050000 */  lw        $a1, ($s0)
/* 9EDDC8 802401D8 26100004 */  addiu     $s0, $s0, 4
/* 9EDDCC 802401DC 0C0B210B */  jal       get_float_variable
/* 9EDDD0 802401E0 0240202D */   daddu    $a0, $s2, $zero
/* 9EDDD4 802401E4 8E050000 */  lw        $a1, ($s0)
/* 9EDDD8 802401E8 26100004 */  addiu     $s0, $s0, 4
/* 9EDDDC 802401EC 0240202D */  daddu     $a0, $s2, $zero
/* 9EDDE0 802401F0 0C0B210B */  jal       get_float_variable
/* 9EDDE4 802401F4 46000606 */   mov.s    $f24, $f0
/* 9EDDE8 802401F8 8E050000 */  lw        $a1, ($s0)
/* 9EDDEC 802401FC 26100004 */  addiu     $s0, $s0, 4
/* 9EDDF0 80240200 0240202D */  daddu     $a0, $s2, $zero
/* 9EDDF4 80240204 0C0B1EAF */  jal       get_variable
/* 9EDDF8 80240208 46000506 */   mov.s    $f20, $f0
/* 9EDDFC 8024020C 8E050000 */  lw        $a1, ($s0)
/* 9EDE00 80240210 26100004 */  addiu     $s0, $s0, 4
/* 9EDE04 80240214 0240202D */  daddu     $a0, $s2, $zero
/* 9EDE08 80240218 0C0B1EAF */  jal       get_variable
/* 9EDE0C 8024021C 0040882D */   daddu    $s1, $v0, $zero
/* 9EDE10 80240220 0240202D */  daddu     $a0, $s2, $zero
/* 9EDE14 80240224 8E050000 */  lw        $a1, ($s0)
/* 9EDE18 80240228 0C0B210B */  jal       get_float_variable
/* 9EDE1C 8024022C 0040802D */   daddu    $s0, $v0, $zero
/* 9EDE20 80240230 3C014334 */  lui       $at, 0x4334
/* 9EDE24 80240234 44811000 */  mtc1      $at, $f2
/* 9EDE28 80240238 3C014049 */  lui       $at, 0x4049
/* 9EDE2C 8024023C 34210FD8 */  ori       $at, $at, 0xfd8
/* 9EDE30 80240240 44812000 */  mtc1      $at, $f4
/* 9EDE34 80240244 46020003 */  div.s     $f0, $f0, $f2
/* 9EDE38 80240248 46040582 */  mul.s     $f22, $f0, $f4
/* 9EDE3C 8024024C 00000000 */  nop       
/* 9EDE40 80240250 4618A501 */  sub.s     $f20, $f20, $f24
/* 9EDE44 80240254 3C013F00 */  lui       $at, 0x3f00
/* 9EDE48 80240258 44810000 */  mtc1      $at, $f0
/* 9EDE4C 8024025C 00000000 */  nop       
/* 9EDE50 80240260 4600A502 */  mul.s     $f20, $f20, $f0
/* 9EDE54 80240264 00000000 */  nop       
/* 9EDE58 80240268 12000007 */  beqz      $s0, .L80240288
/* 9EDE5C 8024026C 0233102A */   slt      $v0, $s1, $s3
/* 9EDE60 80240270 10400005 */  beqz      $v0, .L80240288
/* 9EDE64 80240274 0240202D */   daddu    $a0, $s2, $zero
/* 9EDE68 80240278 0220982D */  daddu     $s3, $s1, $zero
/* 9EDE6C 8024027C 0280282D */  daddu     $a1, $s4, $zero
/* 9EDE70 80240280 0C0B2026 */  jal       set_variable
/* 9EDE74 80240284 0220302D */   daddu    $a2, $s1, $zero
.L80240288:
/* 9EDE78 80240288 3C014049 */  lui       $at, 0x4049
/* 9EDE7C 8024028C 34210FD8 */  ori       $at, $at, 0xfd8
/* 9EDE80 80240290 44810000 */  mtc1      $at, $f0
/* 9EDE84 80240294 44936000 */  mtc1      $s3, $f12
/* 9EDE88 80240298 00000000 */  nop       
/* 9EDE8C 8024029C 46806320 */  cvt.s.w   $f12, $f12
/* 9EDE90 802402A0 46006302 */  mul.s     $f12, $f12, $f0
/* 9EDE94 802402A4 00000000 */  nop       
/* 9EDE98 802402A8 44910000 */  mtc1      $s1, $f0
/* 9EDE9C 802402AC 00000000 */  nop       
/* 9EDEA0 802402B0 46800020 */  cvt.s.w   $f0, $f0
/* 9EDEA4 802402B4 46006303 */  div.s     $f12, $f12, $f0
/* 9EDEA8 802402B8 0C00A874 */  jal       cos_rad
/* 9EDEAC 802402BC 46166300 */   add.s    $f12, $f12, $f22
/* 9EDEB0 802402C0 4600A002 */  mul.s     $f0, $f20, $f0
/* 9EDEB4 802402C4 00000000 */  nop       
/* 9EDEB8 802402C8 4614C080 */  add.s     $f2, $f24, $f20
/* 9EDEBC 802402CC 46001081 */  sub.s     $f2, $f2, $f0
/* 9EDEC0 802402D0 0240202D */  daddu     $a0, $s2, $zero
/* 9EDEC4 802402D4 44061000 */  mfc1      $a2, $f2
/* 9EDEC8 802402D8 0C0B2190 */  jal       set_float_variable
/* 9EDECC 802402DC 02A0282D */   daddu    $a1, $s5, $zero
/* 9EDED0 802402E0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 9EDED4 802402E4 8FB50024 */  lw        $s5, 0x24($sp)
/* 9EDED8 802402E8 8FB40020 */  lw        $s4, 0x20($sp)
/* 9EDEDC 802402EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9EDEE0 802402F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9EDEE4 802402F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9EDEE8 802402F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9EDEEC 802402FC D7B80040 */  ldc1      $f24, 0x40($sp)
/* 9EDEF0 80240300 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 9EDEF4 80240304 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 9EDEF8 80240308 24020002 */  addiu     $v0, $zero, 2
/* 9EDEFC 8024030C 03E00008 */  jr        $ra
/* 9EDF00 80240310 27BD0048 */   addiu    $sp, $sp, 0x48

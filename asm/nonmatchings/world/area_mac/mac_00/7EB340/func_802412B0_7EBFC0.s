.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412B0_7EBFC0
/* 7EBFC0 802412B0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7EBFC4 802412B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 7EBFC8 802412B8 0080902D */  daddu     $s2, $a0, $zero
/* 7EBFCC 802412BC AFBF0030 */  sw        $ra, 0x30($sp)
/* 7EBFD0 802412C0 AFB7002C */  sw        $s7, 0x2c($sp)
/* 7EBFD4 802412C4 AFB60028 */  sw        $s6, 0x28($sp)
/* 7EBFD8 802412C8 AFB50024 */  sw        $s5, 0x24($sp)
/* 7EBFDC 802412CC AFB40020 */  sw        $s4, 0x20($sp)
/* 7EBFE0 802412D0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7EBFE4 802412D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EBFE8 802412D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EBFEC 802412DC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 7EBFF0 802412E0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 7EBFF4 802412E4 8E50000C */  lw        $s0, 0xc($s2)
/* 7EBFF8 802412E8 8E050000 */  lw        $a1, ($s0)
/* 7EBFFC 802412EC 0C0B1EAF */  jal       get_variable
/* 7EC000 802412F0 26100004 */   addiu    $s0, $s0, 4
/* 7EC004 802412F4 8E050000 */  lw        $a1, ($s0)
/* 7EC008 802412F8 26100004 */  addiu     $s0, $s0, 4
/* 7EC00C 802412FC 0240202D */  daddu     $a0, $s2, $zero
/* 7EC010 80241300 0C0B1EAF */  jal       get_variable
/* 7EC014 80241304 0040B82D */   daddu    $s7, $v0, $zero
/* 7EC018 80241308 8E050000 */  lw        $a1, ($s0)
/* 7EC01C 8024130C 26100004 */  addiu     $s0, $s0, 4
/* 7EC020 80241310 0240202D */  daddu     $a0, $s2, $zero
/* 7EC024 80241314 0C0B1EAF */  jal       get_variable
/* 7EC028 80241318 0040B02D */   daddu    $s6, $v0, $zero
/* 7EC02C 8024131C 0240202D */  daddu     $a0, $s2, $zero
/* 7EC030 80241320 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EC034 80241324 34A5D481 */  ori       $a1, $a1, 0xd481
/* 7EC038 80241328 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* 7EC03C 8024132C 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* 7EC040 80241330 8E140000 */  lw        $s4, ($s0)
/* 7EC044 80241334 00061880 */  sll       $v1, $a2, 2
/* 7EC048 80241338 00661821 */  addu      $v1, $v1, $a2
/* 7EC04C 8024133C 00031880 */  sll       $v1, $v1, 2
/* 7EC050 80241340 00661823 */  subu      $v1, $v1, $a2
/* 7EC054 80241344 000330C0 */  sll       $a2, $v1, 3
/* 7EC058 80241348 00661821 */  addu      $v1, $v1, $a2
/* 7EC05C 8024134C 000318C0 */  sll       $v1, $v1, 3
/* 7EC060 80241350 3C01800B */  lui       $at, 0x800b
/* 7EC064 80241354 00230821 */  addu      $at, $at, $v1
/* 7EC068 80241358 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7EC06C 8024135C 8E150004 */  lw        $s5, 4($s0)
/* 7EC070 80241360 4600010D */  trunc.w.s $f4, $f0
/* 7EC074 80241364 44112000 */  mfc1      $s1, $f4
/* 7EC078 80241368 0C0B1EAF */  jal       get_variable
/* 7EC07C 8024136C 0040982D */   daddu    $s3, $v0, $zero
/* 7EC080 80241370 4491B000 */  mtc1      $s1, $f22
/* 7EC084 80241374 00000000 */  nop       
/* 7EC088 80241378 4680B5A0 */  cvt.s.w   $f22, $f22
/* 7EC08C 8024137C 4600B306 */  mov.s     $f12, $f22
/* 7EC090 80241380 0C00A8D4 */  jal       cos_deg
/* 7EC094 80241384 0040802D */   daddu    $s0, $v0, $zero
/* 7EC098 80241388 4493A000 */  mtc1      $s3, $f20
/* 7EC09C 8024138C 00000000 */  nop       
/* 7EC0A0 80241390 4680A520 */  cvt.s.w   $f20, $f20
/* 7EC0A4 80241394 4600A002 */  mul.s     $f0, $f20, $f0
/* 7EC0A8 80241398 00000000 */  nop       
/* 7EC0AC 8024139C 0240202D */  daddu     $a0, $s2, $zero
/* 7EC0B0 802413A0 44901000 */  mtc1      $s0, $f2
/* 7EC0B4 802413A4 00000000 */  nop       
/* 7EC0B8 802413A8 468010A0 */  cvt.s.w   $f2, $f2
/* 7EC0BC 802413AC 46001081 */  sub.s     $f2, $f2, $f0
/* 7EC0C0 802413B0 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EC0C4 802413B4 4600110D */  trunc.w.s $f4, $f2
/* 7EC0C8 802413B8 44102000 */  mfc1      $s0, $f4
/* 7EC0CC 802413BC 0C0B1EAF */  jal       get_variable
/* 7EC0D0 802413C0 34A5D483 */   ori      $a1, $a1, 0xd483
/* 7EC0D4 802413C4 4600B306 */  mov.s     $f12, $f22
/* 7EC0D8 802413C8 0C00A8BB */  jal       sin_deg
/* 7EC0DC 802413CC 0040882D */   daddu    $s1, $v0, $zero
/* 7EC0E0 802413D0 4600A502 */  mul.s     $f20, $f20, $f0
/* 7EC0E4 802413D4 00000000 */  nop       
/* 7EC0E8 802413D8 0240202D */  daddu     $a0, $s2, $zero
/* 7EC0EC 802413DC 44910000 */  mtc1      $s1, $f0
/* 7EC0F0 802413E0 00000000 */  nop       
/* 7EC0F4 802413E4 46800020 */  cvt.s.w   $f0, $f0
/* 7EC0F8 802413E8 46140001 */  sub.s     $f0, $f0, $f20
/* 7EC0FC 802413EC 0280282D */  daddu     $a1, $s4, $zero
/* 7EC100 802413F0 02173023 */  subu      $a2, $s0, $s7
/* 7EC104 802413F4 4600010D */  trunc.w.s $f4, $f0
/* 7EC108 802413F8 44102000 */  mfc1      $s0, $f4
/* 7EC10C 802413FC 0C0B2026 */  jal       set_variable
/* 7EC110 80241400 02168023 */   subu     $s0, $s0, $s6
/* 7EC114 80241404 0240202D */  daddu     $a0, $s2, $zero
/* 7EC118 80241408 02A0282D */  daddu     $a1, $s5, $zero
/* 7EC11C 8024140C 0C0B2026 */  jal       set_variable
/* 7EC120 80241410 0200302D */   daddu    $a2, $s0, $zero
/* 7EC124 80241414 8FBF0030 */  lw        $ra, 0x30($sp)
/* 7EC128 80241418 8FB7002C */  lw        $s7, 0x2c($sp)
/* 7EC12C 8024141C 8FB60028 */  lw        $s6, 0x28($sp)
/* 7EC130 80241420 8FB50024 */  lw        $s5, 0x24($sp)
/* 7EC134 80241424 8FB40020 */  lw        $s4, 0x20($sp)
/* 7EC138 80241428 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7EC13C 8024142C 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EC140 80241430 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EC144 80241434 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EC148 80241438 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 7EC14C 8024143C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 7EC150 80241440 24020002 */  addiu     $v0, $zero, 2
/* 7EC154 80241444 03E00008 */  jr        $ra
/* 7EC158 80241448 27BD0048 */   addiu    $sp, $sp, 0x48

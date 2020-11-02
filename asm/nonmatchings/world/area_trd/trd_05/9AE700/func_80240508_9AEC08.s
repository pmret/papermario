.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240508_9AEC08
/* 9AEC08 80240508 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9AEC0C 8024050C AFB10014 */  sw        $s1, 0x14($sp)
/* 9AEC10 80240510 0080882D */  daddu     $s1, $a0, $zero
/* 9AEC14 80240514 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9AEC18 80240518 AFB20018 */  sw        $s2, 0x18($sp)
/* 9AEC1C 8024051C AFB00010 */  sw        $s0, 0x10($sp)
/* 9AEC20 80240520 8E30000C */  lw        $s0, 0xc($s1)
/* 9AEC24 80240524 8E050000 */  lw        $a1, ($s0)
/* 9AEC28 80240528 0C0B210B */  jal       get_float_variable
/* 9AEC2C 8024052C 26100004 */   addiu    $s0, $s0, 4
/* 9AEC30 80240530 8E050000 */  lw        $a1, ($s0)
/* 9AEC34 80240534 26100004 */  addiu     $s0, $s0, 4
/* 9AEC38 80240538 4600018D */  trunc.w.s $f6, $f0
/* 9AEC3C 8024053C 44123000 */  mfc1      $s2, $f6
/* 9AEC40 80240540 0C0B210B */  jal       get_float_variable
/* 9AEC44 80240544 0220202D */   daddu    $a0, $s1, $zero
/* 9AEC48 80240548 8E050000 */  lw        $a1, ($s0)
/* 9AEC4C 8024054C 4600018D */  trunc.w.s $f6, $f0
/* 9AEC50 80240550 44103000 */  mfc1      $s0, $f6
/* 9AEC54 80240554 0C0B210B */  jal       get_float_variable
/* 9AEC58 80240558 0220202D */   daddu    $a0, $s1, $zero
/* 9AEC5C 8024055C 3C028011 */  lui       $v0, %hi(gPlayerStatus+0xB0)
/* 9AEC60 80240560 8442F078 */  lh        $v0, %lo(gPlayerStatus+0xB0)($v0)
/* 9AEC64 80240564 3C018024 */  lui       $at, 0x8024
/* 9AEC68 80240568 D4223078 */  ldc1      $f2, 0x3078($at)
/* 9AEC6C 8024056C 44822000 */  mtc1      $v0, $f4
/* 9AEC70 80240570 00000000 */  nop       
/* 9AEC74 80240574 46802121 */  cvt.d.w   $f4, $f4
/* 9AEC78 80240578 46222102 */  mul.d     $f4, $f4, $f2
/* 9AEC7C 8024057C 00000000 */  nop       
/* 9AEC80 80240580 3C013FE0 */  lui       $at, 0x3fe0
/* 9AEC84 80240584 44811800 */  mtc1      $at, $f3
/* 9AEC88 80240588 44801000 */  mtc1      $zero, $f2
/* 9AEC8C 8024058C 00000000 */  nop       
/* 9AEC90 80240590 46222102 */  mul.d     $f4, $f4, $f2
/* 9AEC94 80240594 00000000 */  nop       
/* 9AEC98 80240598 4600018D */  trunc.w.s $f6, $f0
/* 9AEC9C 8024059C 44033000 */  mfc1      $v1, $f6
/* 9AECA0 802405A0 44900000 */  mtc1      $s0, $f0
/* 9AECA4 802405A4 00000000 */  nop       
/* 9AECA8 802405A8 46800021 */  cvt.d.w   $f0, $f0
/* 9AECAC 802405AC 3C028024 */  lui       $v0, 0x8024
/* 9AECB0 802405B0 24423090 */  addiu     $v0, $v0, 0x3090
/* 9AECB4 802405B4 44921000 */  mtc1      $s2, $f2
/* 9AECB8 802405B8 00000000 */  nop       
/* 9AECBC 802405BC 468010A0 */  cvt.s.w   $f2, $f2
/* 9AECC0 802405C0 E4420010 */  swc1      $f2, 0x10($v0)
/* 9AECC4 802405C4 46240000 */  add.d     $f0, $f0, $f4
/* 9AECC8 802405C8 44831000 */  mtc1      $v1, $f2
/* 9AECCC 802405CC 00000000 */  nop       
/* 9AECD0 802405D0 468010A0 */  cvt.s.w   $f2, $f2
/* 9AECD4 802405D4 E4420018 */  swc1      $f2, 0x18($v0)
/* 9AECD8 802405D8 46200020 */  cvt.s.d   $f0, $f0
/* 9AECDC 802405DC E4400014 */  swc1      $f0, 0x14($v0)
/* 9AECE0 802405E0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9AECE4 802405E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 9AECE8 802405E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 9AECEC 802405EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AECF0 802405F0 24020002 */  addiu     $v0, $zero, 2
/* 9AECF4 802405F4 03E00008 */  jr        $ra
/* 9AECF8 802405F8 27BD0020 */   addiu    $sp, $sp, 0x20

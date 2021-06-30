.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240404_9AEB04
/* 9AEB04 80240404 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9AEB08 80240408 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 9AEB0C 8024040C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 9AEB10 80240410 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9AEB14 80240414 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AEB18 80240418 844300B0 */  lh        $v1, 0xb0($v0)
/* 9AEB1C 8024041C 3C018024 */  lui       $at, %hi(D_80243070_9B1770)
/* 9AEB20 80240420 D4203070 */  ldc1      $f0, %lo(D_80243070_9B1770)($at)
/* 9AEB24 80240424 44831000 */  mtc1      $v1, $f2
/* 9AEB28 80240428 00000000 */  nop
/* 9AEB2C 8024042C 468010A1 */  cvt.d.w   $f2, $f2
/* 9AEB30 80240430 46201082 */  mul.d     $f2, $f2, $f0
/* 9AEB34 80240434 00000000 */  nop
/* 9AEB38 80240438 24040001 */  addiu     $a0, $zero, 1
/* 9AEB3C 8024043C 3C108024 */  lui       $s0, %hi(func_80243090)
/* 9AEB40 80240440 26103090 */  addiu     $s0, $s0, %lo(func_80243090)
/* 9AEB44 80240444 C44A0028 */  lwc1      $f10, 0x28($v0)
/* 9AEB48 80240448 3C013FE0 */  lui       $at, 0x3fe0
/* 9AEB4C 8024044C 44812800 */  mtc1      $at, $f5
/* 9AEB50 80240450 44802000 */  mtc1      $zero, $f4
/* 9AEB54 80240454 C4480030 */  lwc1      $f8, 0x30($v0)
/* 9AEB58 80240458 3C013F36 */  lui       $at, 0x3f36
/* 9AEB5C 8024045C 3421DB6E */  ori       $at, $at, 0xdb6e
/* 9AEB60 80240460 44813000 */  mtc1      $at, $f6
/* 9AEB64 80240464 C440002C */  lwc1      $f0, 0x2c($v0)
/* 9AEB68 80240468 46241082 */  mul.d     $f2, $f2, $f4
/* 9AEB6C 8024046C 00000000 */  nop
/* 9AEB70 80240470 AE00001C */  sw        $zero, 0x1c($s0)
/* 9AEB74 80240474 AE000020 */  sw        $zero, 0x20($s0)
/* 9AEB78 80240478 AE000024 */  sw        $zero, 0x24($s0)
/* 9AEB7C 8024047C E60A0010 */  swc1      $f10, 0x10($s0)
/* 9AEB80 80240480 E6080018 */  swc1      $f8, 0x18($s0)
/* 9AEB84 80240484 E6060028 */  swc1      $f6, 0x28($s0)
/* 9AEB88 80240488 46000021 */  cvt.d.s   $f0, $f0
/* 9AEB8C 8024048C 46220000 */  add.d     $f0, $f0, $f2
/* 9AEB90 80240490 E606002C */  swc1      $f6, 0x2c($s0)
/* 9AEB94 80240494 E6060030 */  swc1      $f6, 0x30($s0)
/* 9AEB98 80240498 46200020 */  cvt.s.d   $f0, $f0
/* 9AEB9C 8024049C 0C04E9C1 */  jal       func_8013A704
/* 9AEBA0 802404A0 E6000014 */   swc1     $f0, 0x14($s0)
/* 9AEBA4 802404A4 0000202D */  daddu     $a0, $zero, $zero
/* 9AEBA8 802404A8 3C058024 */  lui       $a1, %hi(func_80240020_9AE720)
/* 9AEBAC 802404AC 24A50020 */  addiu     $a1, $a1, %lo(func_80240020_9AE720)
/* 9AEBB0 802404B0 0C048C56 */  jal       create_generic_entity_world
/* 9AEBB4 802404B4 AE020000 */   sw       $v0, ($s0)
/* 9AEBB8 802404B8 AE020004 */  sw        $v0, 4($s0)
/* 9AEBBC 802404BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9AEBC0 802404C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AEBC4 802404C4 24020002 */  addiu     $v0, $zero, 2
/* 9AEBC8 802404C8 03E00008 */  jr        $ra
/* 9AEBCC 802404CC 27BD0018 */   addiu    $sp, $sp, 0x18

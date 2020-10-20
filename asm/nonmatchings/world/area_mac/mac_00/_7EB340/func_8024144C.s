.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024144C
/* 7EC15C 8024144C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 7EC160 80241450 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 7EC164 80241454 10A00002 */  beqz      $a1, .L80241460
/* 7EC168 80241458 2402003C */   addiu    $v0, $zero, 0x3c
/* 7EC16C 8024145C AC820070 */  sw        $v0, 0x70($a0)
.L80241460:
/* 7EC170 80241460 C4620080 */  lwc1      $f2, 0x80($v1)
/* 7EC174 80241464 3C0141F0 */  lui       $at, 0x41f0
/* 7EC178 80241468 44810000 */  mtc1      $at, $f0
/* 7EC17C 8024146C 00000000 */  nop       
/* 7EC180 80241470 46001000 */  add.s     $f0, $f2, $f0
/* 7EC184 80241474 3C0143B4 */  lui       $at, 0x43b4
/* 7EC188 80241478 44811000 */  mtc1      $at, $f2
/* 7EC18C 8024147C 00000000 */  nop       
/* 7EC190 80241480 4600103E */  c.le.s    $f2, $f0
/* 7EC194 80241484 00000000 */  nop       
/* 7EC198 80241488 45000003 */  bc1f      .L80241498
/* 7EC19C 8024148C E4600080 */   swc1     $f0, 0x80($v1)
/* 7EC1A0 80241490 46020001 */  sub.s     $f0, $f0, $f2
/* 7EC1A4 80241494 E4600080 */  swc1      $f0, 0x80($v1)
.L80241498:
/* 7EC1A8 80241498 8C820070 */  lw        $v0, 0x70($a0)
/* 7EC1AC 8024149C 2442FFFF */  addiu     $v0, $v0, -1
/* 7EC1B0 802414A0 AC820070 */  sw        $v0, 0x70($a0)
/* 7EC1B4 802414A4 000217C3 */  sra       $v0, $v0, 0x1f
/* 7EC1B8 802414A8 03E00008 */  jr        $ra
/* 7EC1BC 802414AC 30420002 */   andi     $v0, $v0, 2

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024228C_95D48C
/* 95D48C 8024228C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 95D490 80242290 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 95D494 80242294 10A00002 */  beqz      $a1, .L802422A0
/* 95D498 80242298 2402003C */   addiu    $v0, $zero, 0x3c
/* 95D49C 8024229C AC820070 */  sw        $v0, 0x70($a0)
.L802422A0:
/* 95D4A0 802422A0 C4620080 */  lwc1      $f2, 0x80($v1)
/* 95D4A4 802422A4 3C0141F0 */  lui       $at, 0x41f0
/* 95D4A8 802422A8 44810000 */  mtc1      $at, $f0
/* 95D4AC 802422AC 00000000 */  nop       
/* 95D4B0 802422B0 46001000 */  add.s     $f0, $f2, $f0
/* 95D4B4 802422B4 3C0143B4 */  lui       $at, 0x43b4
/* 95D4B8 802422B8 44811000 */  mtc1      $at, $f2
/* 95D4BC 802422BC 00000000 */  nop       
/* 95D4C0 802422C0 4600103E */  c.le.s    $f2, $f0
/* 95D4C4 802422C4 00000000 */  nop       
/* 95D4C8 802422C8 45000003 */  bc1f      .L802422D8
/* 95D4CC 802422CC E4600080 */   swc1     $f0, 0x80($v1)
/* 95D4D0 802422D0 46020001 */  sub.s     $f0, $f0, $f2
/* 95D4D4 802422D4 E4600080 */  swc1      $f0, 0x80($v1)
.L802422D8:
/* 95D4D8 802422D8 8C820070 */  lw        $v0, 0x70($a0)
/* 95D4DC 802422DC 2442FFFF */  addiu     $v0, $v0, -1
/* 95D4E0 802422E0 AC820070 */  sw        $v0, 0x70($a0)
/* 95D4E4 802422E4 000217C3 */  sra       $v0, $v0, 0x1f
/* 95D4E8 802422E8 03E00008 */  jr        $ra
/* 95D4EC 802422EC 30420002 */   andi     $v0, $v0, 2

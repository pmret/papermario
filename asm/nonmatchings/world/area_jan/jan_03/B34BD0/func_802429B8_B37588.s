.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429B8_B37588
/* B37588 802429B8 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* B3758C 802429BC 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* B37590 802429C0 10A00002 */  beqz      $a1, .L802429CC
/* B37594 802429C4 2402003C */   addiu    $v0, $zero, 0x3c
/* B37598 802429C8 AC820070 */  sw        $v0, 0x70($a0)
.L802429CC:
/* B3759C 802429CC C4620080 */  lwc1      $f2, 0x80($v1)
/* B375A0 802429D0 3C0141F0 */  lui       $at, 0x41f0
/* B375A4 802429D4 44810000 */  mtc1      $at, $f0
/* B375A8 802429D8 00000000 */  nop       
/* B375AC 802429DC 46001000 */  add.s     $f0, $f2, $f0
/* B375B0 802429E0 3C0143B4 */  lui       $at, 0x43b4
/* B375B4 802429E4 44811000 */  mtc1      $at, $f2
/* B375B8 802429E8 00000000 */  nop       
/* B375BC 802429EC 4600103E */  c.le.s    $f2, $f0
/* B375C0 802429F0 00000000 */  nop       
/* B375C4 802429F4 45000003 */  bc1f      .L80242A04
/* B375C8 802429F8 E4600080 */   swc1     $f0, 0x80($v1)
/* B375CC 802429FC 46020001 */  sub.s     $f0, $f0, $f2
/* B375D0 80242A00 E4600080 */  swc1      $f0, 0x80($v1)
.L80242A04:
/* B375D4 80242A04 8C820070 */  lw        $v0, 0x70($a0)
/* B375D8 80242A08 2442FFFF */  addiu     $v0, $v0, -1
/* B375DC 80242A0C AC820070 */  sw        $v0, 0x70($a0)
/* B375E0 80242A10 000217C3 */  sra       $v0, $v0, 0x1f
/* B375E4 80242A14 03E00008 */  jr        $ra
/* B375E8 80242A18 30420002 */   andi     $v0, $v0, 2

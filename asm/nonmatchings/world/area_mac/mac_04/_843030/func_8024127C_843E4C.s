.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024127C_843E4C
/* 843E4C 8024127C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 843E50 80241280 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 843E54 80241284 10A00002 */  beqz      $a1, .L80241290
/* 843E58 80241288 2402003C */   addiu    $v0, $zero, 0x3c
/* 843E5C 8024128C AC820070 */  sw        $v0, 0x70($a0)
.L80241290:
/* 843E60 80241290 C4620080 */  lwc1      $f2, 0x80($v1)
/* 843E64 80241294 3C0141F0 */  lui       $at, 0x41f0
/* 843E68 80241298 44810000 */  mtc1      $at, $f0
/* 843E6C 8024129C 00000000 */  nop       
/* 843E70 802412A0 46001000 */  add.s     $f0, $f2, $f0
/* 843E74 802412A4 3C0143B4 */  lui       $at, 0x43b4
/* 843E78 802412A8 44811000 */  mtc1      $at, $f2
/* 843E7C 802412AC 00000000 */  nop       
/* 843E80 802412B0 4600103E */  c.le.s    $f2, $f0
/* 843E84 802412B4 00000000 */  nop       
/* 843E88 802412B8 45000003 */  bc1f      .L802412C8
/* 843E8C 802412BC E4600080 */   swc1     $f0, 0x80($v1)
/* 843E90 802412C0 46020001 */  sub.s     $f0, $f0, $f2
/* 843E94 802412C4 E4600080 */  swc1      $f0, 0x80($v1)
.L802412C8:
/* 843E98 802412C8 8C820070 */  lw        $v0, 0x70($a0)
/* 843E9C 802412CC 2442FFFF */  addiu     $v0, $v0, -1
/* 843EA0 802412D0 AC820070 */  sw        $v0, 0x70($a0)
/* 843EA4 802412D4 000217C3 */  sra       $v0, $v0, 0x1f
/* 843EA8 802412D8 03E00008 */  jr        $ra
/* 843EAC 802412DC 30420002 */   andi     $v0, $v0, 2

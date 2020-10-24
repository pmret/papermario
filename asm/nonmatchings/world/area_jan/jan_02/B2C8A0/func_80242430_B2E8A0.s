.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242430_B2E8A0
/* B2E8A0 80242430 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* B2E8A4 80242434 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* B2E8A8 80242438 10A00002 */  beqz      $a1, .L80242444
/* B2E8AC 8024243C 2402003C */   addiu    $v0, $zero, 0x3c
/* B2E8B0 80242440 AC820070 */  sw        $v0, 0x70($a0)
.L80242444:
/* B2E8B4 80242444 C4620080 */  lwc1      $f2, 0x80($v1)
/* B2E8B8 80242448 3C0141F0 */  lui       $at, 0x41f0
/* B2E8BC 8024244C 44810000 */  mtc1      $at, $f0
/* B2E8C0 80242450 00000000 */  nop       
/* B2E8C4 80242454 46001000 */  add.s     $f0, $f2, $f0
/* B2E8C8 80242458 3C0143B4 */  lui       $at, 0x43b4
/* B2E8CC 8024245C 44811000 */  mtc1      $at, $f2
/* B2E8D0 80242460 00000000 */  nop       
/* B2E8D4 80242464 4600103E */  c.le.s    $f2, $f0
/* B2E8D8 80242468 00000000 */  nop       
/* B2E8DC 8024246C 45000003 */  bc1f      .L8024247C
/* B2E8E0 80242470 E4600080 */   swc1     $f0, 0x80($v1)
/* B2E8E4 80242474 46020001 */  sub.s     $f0, $f0, $f2
/* B2E8E8 80242478 E4600080 */  swc1      $f0, 0x80($v1)
.L8024247C:
/* B2E8EC 8024247C 8C820070 */  lw        $v0, 0x70($a0)
/* B2E8F0 80242480 2442FFFF */  addiu     $v0, $v0, -1
/* B2E8F4 80242484 AC820070 */  sw        $v0, 0x70($a0)
/* B2E8F8 80242488 000217C3 */  sra       $v0, $v0, 0x1f
/* B2E8FC 8024248C 03E00008 */  jr        $ra
/* B2E900 80242490 30420002 */   andi     $v0, $v0, 2

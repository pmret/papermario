.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024151C_CF908C
/* CF908C 8024151C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* CF9090 80241520 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* CF9094 80241524 10A00002 */  beqz      $a1, .L80241530
/* CF9098 80241528 2402003C */   addiu    $v0, $zero, 0x3c
/* CF909C 8024152C AC820070 */  sw        $v0, 0x70($a0)
.L80241530:
/* CF90A0 80241530 C4620080 */  lwc1      $f2, 0x80($v1)
/* CF90A4 80241534 3C0141F0 */  lui       $at, 0x41f0
/* CF90A8 80241538 44810000 */  mtc1      $at, $f0
/* CF90AC 8024153C 00000000 */  nop       
/* CF90B0 80241540 46001000 */  add.s     $f0, $f2, $f0
/* CF90B4 80241544 3C0143B4 */  lui       $at, 0x43b4
/* CF90B8 80241548 44811000 */  mtc1      $at, $f2
/* CF90BC 8024154C 00000000 */  nop       
/* CF90C0 80241550 4600103E */  c.le.s    $f2, $f0
/* CF90C4 80241554 00000000 */  nop       
/* CF90C8 80241558 45000003 */  bc1f      .L80241568
/* CF90CC 8024155C E4600080 */   swc1     $f0, 0x80($v1)
/* CF90D0 80241560 46020001 */  sub.s     $f0, $f0, $f2
/* CF90D4 80241564 E4600080 */  swc1      $f0, 0x80($v1)
.L80241568:
/* CF90D8 80241568 8C820070 */  lw        $v0, 0x70($a0)
/* CF90DC 8024156C 2442FFFF */  addiu     $v0, $v0, -1
/* CF90E0 80241570 AC820070 */  sw        $v0, 0x70($a0)
/* CF90E4 80241574 000217C3 */  sra       $v0, $v0, 0x1f
/* CF90E8 80241578 03E00008 */  jr        $ra
/* CF90EC 8024157C 30420002 */   andi     $v0, $v0, 2

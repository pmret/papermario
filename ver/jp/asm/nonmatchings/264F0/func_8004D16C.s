.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D16C
/* 2856C 8004D16C 0000282D */  daddu     $a1, $zero, $zero
/* 28570 8004D170 3C088008 */  lui       $t0, %hi(D_80078434)
/* 28574 8004D174 25088434 */  addiu     $t0, $t0, %lo(D_80078434)
/* 28578 8004D178 24070001 */  addiu     $a3, $zero, 1
/* 2857C 8004D17C 24060001 */  addiu     $a2, $zero, 1
/* 28580 8004D180 2403016C */  addiu     $v1, $zero, 0x16c
.L8004D184:
/* 28584 8004D184 00831021 */  addu      $v0, $a0, $v1
/* 28588 8004D188 24A50001 */  addiu     $a1, $a1, 1
/* 2858C 8004D18C AC480000 */  sw        $t0, ($v0)
/* 28590 8004D190 AC400080 */  sw        $zero, 0x80($v0)
/* 28594 8004D194 A047009A */  sb        $a3, 0x9a($v0)
/* 28598 8004D198 A04000A9 */  sb        $zero, 0xa9($v0)
/* 2859C 8004D19C A446008E */  sh        $a2, 0x8e($v0)
/* 285A0 8004D1A0 A0400098 */  sb        $zero, 0x98($v0)
/* 285A4 8004D1A4 A0400099 */  sb        $zero, 0x99($v0)
/* 285A8 8004D1A8 28A20008 */  slti      $v0, $a1, 8
/* 285AC 8004D1AC 1440FFF5 */  bnez      $v0, .L8004D184
/* 285B0 8004D1B0 246300AC */   addiu    $v1, $v1, 0xac
/* 285B4 8004D1B4 03E00008 */  jr        $ra
/* 285B8 8004D1B8 00000000 */   nop
/* 285BC 8004D1BC 00000000 */  nop

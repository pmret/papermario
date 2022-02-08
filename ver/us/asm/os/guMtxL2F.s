.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel guMtxL2F
/* 42980 80067580 3C013780 */  lui       $at, 0x3780
/* 42984 80067584 44810000 */  mtc1      $at, $f0
/* 42988 80067588 3C19FFFF */  lui       $t9, 0xffff
/* 4298C 8006758C 24B80020 */  addiu     $t8, $a1, 0x20
.L80067590:
/* 42990 80067590 8CA80000 */  lw        $t0, ($a1)
/* 42994 80067594 8CA90020 */  lw        $t1, 0x20($a1)
/* 42998 80067598 01195024 */  and       $t2, $t0, $t9
/* 4299C 8006759C 00095C02 */  srl       $t3, $t1, 0x10
/* 429A0 800675A0 014B6025 */  or        $t4, $t2, $t3
/* 429A4 800675A4 00086C00 */  sll       $t5, $t0, 0x10
/* 429A8 800675A8 312EFFFF */  andi      $t6, $t1, 0xffff
/* 429AC 800675AC 01AE7825 */  or        $t7, $t5, $t6
/* 429B0 800675B0 448C2000 */  mtc1      $t4, $f4
/* 429B4 800675B4 00000000 */  nop
/* 429B8 800675B8 468021A0 */  cvt.s.w   $f6, $f4
/* 429BC 800675BC 46003202 */  mul.s     $f8, $f6, $f0
/* 429C0 800675C0 448F5000 */  mtc1      $t7, $f10
/* 429C4 800675C4 00000000 */  nop
/* 429C8 800675C8 46805420 */  cvt.s.w   $f16, $f10
/* 429CC 800675CC 46008482 */  mul.s     $f18, $f16, $f0
/* 429D0 800675D0 E4880000 */  swc1      $f8, ($a0)
/* 429D4 800675D4 E4920004 */  swc1      $f18, 4($a0)
/* 429D8 800675D8 24A50004 */  addiu     $a1, $a1, 4
/* 429DC 800675DC 14B8FFEC */  bne       $a1, $t8, .L80067590
/* 429E0 800675E0 24840008 */   addiu    $a0, $a0, 8
/* 429E4 800675E4 03E00008 */  jr        $ra
/* 429E8 800675E8 00000000 */   nop
/* 429EC 800675EC 00000000 */  nop
/* 429F0 800675F0 00000000 */  nop
/* 429F4 800675F4 00000000 */  nop
/* 429F8 800675F8 00000000 */  nop
/* 429FC 800675FC 00000000 */  nop

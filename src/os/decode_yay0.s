.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers


glabel decode_yay0
/* 4A1F0 8006EDF0 8C980004 */  lw        $t8, 4($a0)
/* 4A1F4 8006EDF4 8C870008 */  lw        $a3, 8($a0)
/* 4A1F8 8006EDF8 8C99000C */  lw        $t9, 0xc($a0)
/* 4A1FC 8006EDFC 0000302D */  daddu     $a2, $zero, $zero
/* 4A200 8006EE00 0305C020 */  add       $t8, $t8, $a1
/* 4A204 8006EE04 00E43820 */  add       $a3, $a3, $a0
/* 4A208 8006EE08 0324C820 */  add       $t9, $t9, $a0
/* 4A20C 8006EE0C 20840010 */  addi      $a0, $a0, 0x10
.L8006EE10:
/* 4A210 8006EE10 14C00004 */  bnez      $a2, .L8006EE24
/* 4A214 8006EE14 00000000 */   nop
/* 4A218 8006EE18 8C880000 */  lw        $t0, ($a0)
/* 4A21C 8006EE1C 24060020 */  addiu     $a2, $zero, 0x20
/* 4A220 8006EE20 20840004 */  addi      $a0, $a0, 4
.L8006EE24:
/* 4A224 8006EE24 0100482A */  slt       $t1, $t0, $zero
/* 4A228 8006EE28 11200006 */  beqz      $t1, .L8006EE44
/* 4A22C 8006EE2C 00000000 */   nop
/* 4A230 8006EE30 832A0000 */  lb        $t2, ($t9)
/* 4A234 8006EE34 23390001 */  addi      $t9, $t9, 1
/* 4A238 8006EE38 A0AA0000 */  sb        $t2, ($a1)
/* 4A23C 8006EE3C 1000000E */  b         .L8006EE78
/* 4A240 8006EE40 20A50001 */   addi     $a1, $a1, 1
.L8006EE44:
/* 4A244 8006EE44 94EA0000 */  lhu       $t2, ($a3)
/* 4A248 8006EE48 20E70002 */  addi      $a3, $a3, 2
/* 4A24C 8006EE4C 000A5B02 */  srl       $t3, $t2, 0xc
/* 4A250 8006EE50 314A0FFF */  andi      $t2, $t2, 0xfff
/* 4A254 8006EE54 1160000D */  beqz      $t3, .L8006EE8C
/* 4A258 8006EE58 00AA4822 */   sub      $t1, $a1, $t2
/* 4A25C 8006EE5C 216B0002 */  addi      $t3, $t3, 2
.L8006EE60:
/* 4A260 8006EE60 812AFFFF */  lb        $t2, -1($t1)
/* 4A264 8006EE64 216BFFFF */  addi      $t3, $t3, -1
/* 4A268 8006EE68 21290001 */  addi      $t1, $t1, 1
/* 4A26C 8006EE6C A0AA0000 */  sb        $t2, ($a1)
/* 4A270 8006EE70 1560FFFB */  bnez      $t3, .L8006EE60
/* 4A274 8006EE74 20A50001 */   addi     $a1, $a1, 1
.L8006EE78:
/* 4A278 8006EE78 00084040 */  sll       $t0, $t0, 1
/* 4A27C 8006EE7C 14B8FFE4 */  bne       $a1, $t8, .L8006EE10
/* 4A280 8006EE80 20C6FFFF */   addi     $a2, $a2, -1
/* 4A284 8006EE84 03E00008 */  jr        $ra
/* 4A288 8006EE88 00000000 */   nop
.L8006EE8C:
/* 4A28C 8006EE8C 932B0000 */  lbu       $t3, ($t9)
/* 4A290 8006EE90 23390001 */  addi      $t9, $t9, 1
/* 4A294 8006EE94 1000FFF2 */  b         .L8006EE60
/* 4A298 8006EE98 216B0012 */   addi     $t3, $t3, 0x12
/* 4A29C 8006EE9C 00000000 */  nop

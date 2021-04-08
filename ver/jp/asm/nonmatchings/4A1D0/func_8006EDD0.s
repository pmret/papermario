.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006EDD0
/* 4A1D0 8006EDD0 8C980004 */  lw        $t8, 4($a0)
/* 4A1D4 8006EDD4 8C870008 */  lw        $a3, 8($a0)
/* 4A1D8 8006EDD8 8C99000C */  lw        $t9, 0xc($a0)
/* 4A1DC 8006EDDC 0000302D */  daddu     $a2, $zero, $zero
/* 4A1E0 8006EDE0 0305C020 */  add       $t8, $t8, $a1
/* 4A1E4 8006EDE4 00E43820 */  add       $a3, $a3, $a0
/* 4A1E8 8006EDE8 0324C820 */  add       $t9, $t9, $a0
/* 4A1EC 8006EDEC 20840010 */  addi      $a0, $a0, 0x10
.L8006EDF0:
/* 4A1F0 8006EDF0 14C00004 */  bnez      $a2, .L8006EE04
/* 4A1F4 8006EDF4 00000000 */   nop
/* 4A1F8 8006EDF8 8C880000 */  lw        $t0, ($a0)
/* 4A1FC 8006EDFC 24060020 */  addiu     $a2, $zero, 0x20
/* 4A200 8006EE00 20840004 */  addi      $a0, $a0, 4
.L8006EE04:
/* 4A204 8006EE04 0100482A */  slt       $t1, $t0, $zero
/* 4A208 8006EE08 11200006 */  beqz      $t1, .L8006EE24
/* 4A20C 8006EE0C 00000000 */   nop
/* 4A210 8006EE10 832A0000 */  lb        $t2, ($t9)
/* 4A214 8006EE14 23390001 */  addi      $t9, $t9, 1
/* 4A218 8006EE18 A0AA0000 */  sb        $t2, ($a1)
/* 4A21C 8006EE1C 1000000E */  b         .L8006EE58
/* 4A220 8006EE20 20A50001 */   addi     $a1, $a1, 1
.L8006EE24:
/* 4A224 8006EE24 94EA0000 */  lhu       $t2, ($a3)
/* 4A228 8006EE28 20E70002 */  addi      $a3, $a3, 2
/* 4A22C 8006EE2C 000A5B02 */  srl       $t3, $t2, 0xc
/* 4A230 8006EE30 314A0FFF */  andi      $t2, $t2, 0xfff
/* 4A234 8006EE34 1160000D */  beqz      $t3, .L8006EE6C
/* 4A238 8006EE38 00AA4822 */   sub      $t1, $a1, $t2
/* 4A23C 8006EE3C 216B0002 */  addi      $t3, $t3, 2
.L8006EE40:
/* 4A240 8006EE40 812AFFFF */  lb        $t2, -1($t1)
/* 4A244 8006EE44 216BFFFF */  addi      $t3, $t3, -1
/* 4A248 8006EE48 21290001 */  addi      $t1, $t1, 1
/* 4A24C 8006EE4C A0AA0000 */  sb        $t2, ($a1)
/* 4A250 8006EE50 1560FFFB */  bnez      $t3, .L8006EE40
/* 4A254 8006EE54 20A50001 */   addi     $a1, $a1, 1
.L8006EE58:
/* 4A258 8006EE58 00084040 */  sll       $t0, $t0, 1
/* 4A25C 8006EE5C 14B8FFE4 */  bne       $a1, $t8, .L8006EDF0
/* 4A260 8006EE60 20C6FFFF */   addi     $a2, $a2, -1
/* 4A264 8006EE64 03E00008 */  jr        $ra
/* 4A268 8006EE68 00000000 */   nop
.L8006EE6C:
/* 4A26C 8006EE6C 932B0000 */  lbu       $t3, ($t9)
/* 4A270 8006EE70 23390001 */  addi      $t9, $t9, 1
/* 4A274 8006EE74 1000FFF2 */  b         .L8006EE40
/* 4A278 8006EE78 216B0012 */   addi     $t3, $t3, 0x12
/* 4A27C 8006EE7C 00000000 */  nop
/* 4A280 8006EE80 308400FF */  andi      $a0, $a0, 0xff
/* 4A284 8006EE84 30A500FF */  andi      $a1, $a1, 0xff
/* 4A288 8006EE88 30C600FF */  andi      $a2, $a2, 0xff
/* 4A28C 8006EE8C 30E700FF */  andi      $a3, $a3, 0xff
/* 4A290 8006EE90 8FAE0010 */  lw        $t6, 0x10($sp)
/* 4A294 8006EE94 3C01A000 */  lui       $at, 0xa000
/* 4A298 8006EE98 01C17825 */  or        $t7, $t6, $at
/* 4A29C 8006EE9C 3C01800B */  lui       $at, %hi(D_800B0C5C)
/* 4A2A0 8006EEA0 AC2F0C5C */  sw        $t7, %lo(D_800B0C5C)($at)
/* 4A2A4 8006EEA4 3C18800B */  lui       $t8, %hi(D_800B0C54)
/* 4A2A8 8006EEA8 93180C54 */  lbu       $t8, %lo(D_800B0C54)($t8)
/* 4A2AC 8006EEAC 00000000 */  nop
/* 4A2B0 8006EEB0 27190001 */  addiu     $t9, $t8, 1
/* 4A2B4 8006EEB4 3C01800B */  lui       $at, %hi(D_800B0C54)
/* 4A2B8 8006EEB8 A0390C54 */  sb        $t9, %lo(D_800B0C54)($at)
/* 4A2BC 8006EEBC 3C01800B */  lui       $at, %hi(D_800B0C55)
/* 4A2C0 8006EEC0 A0240C55 */  sb        $a0, %lo(D_800B0C55)($at)
/* 4A2C4 8006EEC4 3C01800B */  lui       $at, %hi(D_800B0C58)
/* 4A2C8 8006EEC8 A0250C58 */  sb        $a1, %lo(D_800B0C58)($at)
/* 4A2CC 8006EECC 3C01800B */  lui       $at, %hi(D_800B0C56)
/* 4A2D0 8006EED0 A0260C56 */  sb        $a2, %lo(D_800B0C56)($at)
/* 4A2D4 8006EED4 3C01800B */  lui       $at, %hi(D_800B0C57)
/* 4A2D8 8006EED8 A0270C57 */  sb        $a3, %lo(D_800B0C57)($at)
/* 4A2DC 8006EEDC 24080001 */  addiu     $t0, $zero, 1
/* 4A2E0 8006EEE0 3C01800B */  lui       $at, %hi(D_800B0C59)
/* 4A2E4 8006EEE4 A0280C59 */  sb        $t0, %lo(D_800B0C59)($at)
/* 4A2E8 8006EEE8 3C02800B */  lui       $v0, %hi(D_800B0C50)
/* 4A2EC 8006EEEC 24420C50 */  addiu     $v0, $v0, %lo(D_800B0C50)
/* 4A2F0 8006EEF0 03E00008 */  jr        $ra
/* 4A2F4 8006EEF4 00000000 */   nop

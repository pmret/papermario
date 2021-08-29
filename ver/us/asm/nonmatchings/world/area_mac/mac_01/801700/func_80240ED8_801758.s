.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ED8_801758
/* 801758 80240ED8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 80175C 80240EDC AFB00010 */  sw        $s0, 0x10($sp)
/* 801760 80240EE0 0080802D */  daddu     $s0, $a0, $zero
/* 801764 80240EE4 3C05F5DE */  lui       $a1, 0xf5de
/* 801768 80240EE8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 80176C 80240EEC 0C0B1EAF */  jal       get_variable
/* 801770 80240EF0 34A50180 */   ori      $a1, $a1, 0x180
/* 801774 80240EF4 0040202D */  daddu     $a0, $v0, $zero
/* 801778 80240EF8 3C038025 */  lui       $v1, %hi(D_80248714_808F94)
/* 80177C 80240EFC 24638714 */  addiu     $v1, $v1, %lo(D_80248714_808F94)
/* 801780 80240F00 24060019 */  addiu     $a2, $zero, 0x19
.L80240F04:
/* 801784 80240F04 8C620008 */  lw        $v0, 8($v1)
/* 801788 80240F08 0082102A */  slt       $v0, $a0, $v0
/* 80178C 80240F0C 50400005 */  beql      $v0, $zero, .L80240F24
/* 801790 80240F10 0200202D */   daddu    $a0, $s0, $zero
/* 801794 80240F14 24C6FFFF */  addiu     $a2, $a2, -1
/* 801798 80240F18 04C1FFFA */  bgez      $a2, .L80240F04
/* 80179C 80240F1C 2463FFF4 */   addiu    $v1, $v1, -0xc
/* 8017A0 80240F20 0200202D */  daddu     $a0, $s0, $zero
.L80240F24:
/* 8017A4 80240F24 3C05F5DE */  lui       $a1, 0xf5de
/* 8017A8 80240F28 0C0B2026 */  jal       evt_set_variable
/* 8017AC 80240F2C 34A502DD */   ori      $a1, $a1, 0x2dd
/* 8017B0 80240F30 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8017B4 80240F34 8FB00010 */  lw        $s0, 0x10($sp)
/* 8017B8 80240F38 24020002 */  addiu     $v0, $zero, 2
/* 8017BC 80240F3C 03E00008 */  jr        $ra
/* 8017C0 80240F40 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8017C4 80240F44 00000000 */  nop
/* 8017C8 80240F48 00000000 */  nop
/* 8017CC 80240F4C 00000000 */  nop

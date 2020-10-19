.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802439C0_9DA9E0
/* 9DA9E0 802439C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9DA9E4 802439C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DA9E8 802439C8 0080882D */  daddu     $s1, $a0, $zero
/* 9DA9EC 802439CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9DA9F0 802439D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DA9F4 802439D4 8E30000C */  lw        $s0, 0xc($s1)
/* 9DA9F8 802439D8 8E050000 */  lw        $a1, ($s0)
/* 9DA9FC 802439DC 0C0B1EAF */  jal       get_variable
/* 9DAA00 802439E0 26100004 */   addiu    $s0, $s0, 4
/* 9DAA04 802439E4 0C00EAD2 */  jal       get_npc_safe
/* 9DAA08 802439E8 0040202D */   daddu    $a0, $v0, $zero
/* 9DAA0C 802439EC 10400005 */  beqz      $v0, .L80243A04
/* 9DAA10 802439F0 00000000 */   nop      
/* 9DAA14 802439F4 8E050000 */  lw        $a1, ($s0)
/* 9DAA18 802439F8 844600A8 */  lh        $a2, 0xa8($v0)
/* 9DAA1C 802439FC 0C0B2026 */  jal       set_variable
/* 9DAA20 80243A00 0220202D */   daddu    $a0, $s1, $zero
.L80243A04:
/* 9DAA24 80243A04 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9DAA28 80243A08 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DAA2C 80243A0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DAA30 80243A10 24020002 */  addiu     $v0, $zero, 2
/* 9DAA34 80243A14 03E00008 */  jr        $ra
/* 9DAA38 80243A18 27BD0020 */   addiu    $sp, $sp, 0x20

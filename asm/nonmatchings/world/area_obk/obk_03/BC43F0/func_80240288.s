.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240288
/* BC4508 80240288 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC450C 8024028C AFB10014 */  sw        $s1, 0x14($sp)
/* BC4510 80240290 0080882D */  daddu     $s1, $a0, $zero
/* BC4514 80240294 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC4518 80240298 AFB00010 */  sw        $s0, 0x10($sp)
/* BC451C 8024029C 8E30000C */  lw        $s0, 0xc($s1)
/* BC4520 802402A0 8E050000 */  lw        $a1, ($s0)
/* BC4524 802402A4 0C0B1EAF */  jal       get_variable
/* BC4528 802402A8 26100004 */   addiu    $s0, $s0, 4
/* BC452C 802402AC 0C00EAD2 */  jal       get_npc_safe
/* BC4530 802402B0 0040202D */   daddu    $a0, $v0, $zero
/* BC4534 802402B4 10400005 */  beqz      $v0, .L802402CC
/* BC4538 802402B8 00000000 */   nop      
/* BC453C 802402BC 8E050000 */  lw        $a1, ($s0)
/* BC4540 802402C0 844600A8 */  lh        $a2, 0xa8($v0)
/* BC4544 802402C4 0C0B2026 */  jal       set_variable
/* BC4548 802402C8 0220202D */   daddu    $a0, $s1, $zero
.L802402CC:
/* BC454C 802402CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC4550 802402D0 8FB10014 */  lw        $s1, 0x14($sp)
/* BC4554 802402D4 8FB00010 */  lw        $s0, 0x10($sp)
/* BC4558 802402D8 24020002 */  addiu     $v0, $zero, 2
/* BC455C 802402DC 03E00008 */  jr        $ra
/* BC4560 802402E0 27BD0020 */   addiu    $sp, $sp, 0x20

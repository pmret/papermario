.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242504
/* 95D704 80242504 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95D708 80242508 AFB10014 */  sw        $s1, 0x14($sp)
/* 95D70C 8024250C 0080882D */  daddu     $s1, $a0, $zero
/* 95D710 80242510 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95D714 80242514 AFB00010 */  sw        $s0, 0x10($sp)
/* 95D718 80242518 8E30000C */  lw        $s0, 0xc($s1)
/* 95D71C 8024251C 8E050000 */  lw        $a1, ($s0)
/* 95D720 80242520 0C0B1EAF */  jal       get_variable
/* 95D724 80242524 26100004 */   addiu    $s0, $s0, 4
/* 95D728 80242528 0C00EAD2 */  jal       get_npc_safe
/* 95D72C 8024252C 0040202D */   daddu    $a0, $v0, $zero
/* 95D730 80242530 10400005 */  beqz      $v0, .L80242548
/* 95D734 80242534 00000000 */   nop      
/* 95D738 80242538 8E050000 */  lw        $a1, ($s0)
/* 95D73C 8024253C 844600A8 */  lh        $a2, 0xa8($v0)
/* 95D740 80242540 0C0B2026 */  jal       set_variable
/* 95D744 80242544 0220202D */   daddu    $a0, $s1, $zero
.L80242548:
/* 95D748 80242548 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95D74C 8024254C 8FB10014 */  lw        $s1, 0x14($sp)
/* 95D750 80242550 8FB00010 */  lw        $s0, 0x10($sp)
/* 95D754 80242554 24020002 */  addiu     $v0, $zero, 2
/* 95D758 80242558 03E00008 */  jr        $ra
/* 95D75C 8024255C 27BD0020 */   addiu    $sp, $sp, 0x20

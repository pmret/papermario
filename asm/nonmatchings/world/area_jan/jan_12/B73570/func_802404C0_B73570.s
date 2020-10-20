.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C0_B73570
/* B73570 802404C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B73574 802404C4 AFB10014 */  sw        $s1, 0x14($sp)
/* B73578 802404C8 0080882D */  daddu     $s1, $a0, $zero
/* B7357C 802404CC AFBF0018 */  sw        $ra, 0x18($sp)
/* B73580 802404D0 AFB00010 */  sw        $s0, 0x10($sp)
/* B73584 802404D4 8E300148 */  lw        $s0, 0x148($s1)
/* B73588 802404D8 0C00EABB */  jal       get_npc_unsafe
/* B7358C 802404DC 86040008 */   lh       $a0, 8($s0)
/* B73590 802404E0 3C054387 */  lui       $a1, 0x4387
/* B73594 802404E4 0040202D */  daddu     $a0, $v0, $zero
/* B73598 802404E8 0C00ECD0 */  jal       set_npc_yaw
/* B7359C 802404EC A480008E */   sh       $zero, 0x8e($a0)
/* B735A0 802404F0 24020003 */  addiu     $v0, $zero, 3
/* B735A4 802404F4 AE00006C */  sw        $zero, 0x6c($s0)
/* B735A8 802404F8 AE220070 */  sw        $v0, 0x70($s1)
/* B735AC 802404FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* B735B0 80240500 8FB10014 */  lw        $s1, 0x14($sp)
/* B735B4 80240504 8FB00010 */  lw        $s0, 0x10($sp)
/* B735B8 80240508 03E00008 */  jr        $ra
/* B735BC 8024050C 27BD0020 */   addiu    $sp, $sp, 0x20

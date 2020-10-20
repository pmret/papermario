.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_A7A550
/* A7A550 80240050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A7A554 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* A7A558 80240058 0080882D */  daddu     $s1, $a0, $zero
/* A7A55C 8024005C AFBF0018 */  sw        $ra, 0x18($sp)
/* A7A560 80240060 AFB00010 */  sw        $s0, 0x10($sp)
/* A7A564 80240064 8E30000C */  lw        $s0, 0xc($s1)
/* A7A568 80240068 8E050000 */  lw        $a1, ($s0)
/* A7A56C 8024006C 0C0B1EAF */  jal       get_variable
/* A7A570 80240070 26100004 */   addiu    $s0, $s0, 4
/* A7A574 80240074 0C00EAD2 */  jal       get_npc_safe
/* A7A578 80240078 0040202D */   daddu    $a0, $v0, $zero
/* A7A57C 8024007C 10400005 */  beqz      $v0, .L80240094
/* A7A580 80240080 00000000 */   nop      
/* A7A584 80240084 8E050000 */  lw        $a1, ($s0)
/* A7A588 80240088 844600A8 */  lh        $a2, 0xa8($v0)
/* A7A58C 8024008C 0C0B2026 */  jal       set_variable
/* A7A590 80240090 0220202D */   daddu    $a0, $s1, $zero
.L80240094:
/* A7A594 80240094 8FBF0018 */  lw        $ra, 0x18($sp)
/* A7A598 80240098 8FB10014 */  lw        $s1, 0x14($sp)
/* A7A59C 8024009C 8FB00010 */  lw        $s0, 0x10($sp)
/* A7A5A0 802400A0 24020002 */  addiu     $v0, $zero, 2
/* A7A5A4 802400A4 03E00008 */  jr        $ra
/* A7A5A8 802400A8 27BD0020 */   addiu    $sp, $sp, 0x20

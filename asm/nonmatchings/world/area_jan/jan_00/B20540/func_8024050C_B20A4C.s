.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024050C_B20A4C
/* B20A4C 8024050C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B20A50 80240510 AFB10014 */  sw        $s1, 0x14($sp)
/* B20A54 80240514 0080882D */  daddu     $s1, $a0, $zero
/* B20A58 80240518 AFBF0018 */  sw        $ra, 0x18($sp)
/* B20A5C 8024051C AFB00010 */  sw        $s0, 0x10($sp)
/* B20A60 80240520 8E30000C */  lw        $s0, 0xc($s1)
/* B20A64 80240524 8E050000 */  lw        $a1, ($s0)
/* B20A68 80240528 0C0B1EAF */  jal       get_variable
/* B20A6C 8024052C 26100004 */   addiu    $s0, $s0, 4
/* B20A70 80240530 0C00EAD2 */  jal       get_npc_safe
/* B20A74 80240534 0040202D */   daddu    $a0, $v0, $zero
/* B20A78 80240538 10400005 */  beqz      $v0, .L80240550
/* B20A7C 8024053C 00000000 */   nop      
/* B20A80 80240540 8E050000 */  lw        $a1, ($s0)
/* B20A84 80240544 844600A8 */  lh        $a2, 0xa8($v0)
/* B20A88 80240548 0C0B2026 */  jal       set_variable
/* B20A8C 8024054C 0220202D */   daddu    $a0, $s1, $zero
.L80240550:
/* B20A90 80240550 8FBF0018 */  lw        $ra, 0x18($sp)
/* B20A94 80240554 8FB10014 */  lw        $s1, 0x14($sp)
/* B20A98 80240558 8FB00010 */  lw        $s0, 0x10($sp)
/* B20A9C 8024055C 24020002 */  addiu     $v0, $zero, 2
/* B20AA0 80240560 03E00008 */  jr        $ra
/* B20AA4 80240564 27BD0020 */   addiu    $sp, $sp, 0x20

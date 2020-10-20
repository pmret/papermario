.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241544
/* 832D44 80241544 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 832D48 80241548 AFB10014 */  sw        $s1, 0x14($sp)
/* 832D4C 8024154C 0080882D */  daddu     $s1, $a0, $zero
/* 832D50 80241550 AFBF0018 */  sw        $ra, 0x18($sp)
/* 832D54 80241554 AFB00010 */  sw        $s0, 0x10($sp)
/* 832D58 80241558 8E30000C */  lw        $s0, 0xc($s1)
/* 832D5C 8024155C 8E050000 */  lw        $a1, ($s0)
/* 832D60 80241560 0C0B1EAF */  jal       get_variable
/* 832D64 80241564 26100004 */   addiu    $s0, $s0, 4
/* 832D68 80241568 0C00EAD2 */  jal       get_npc_safe
/* 832D6C 8024156C 0040202D */   daddu    $a0, $v0, $zero
/* 832D70 80241570 10400005 */  beqz      $v0, .L80241588
/* 832D74 80241574 00000000 */   nop      
/* 832D78 80241578 8E050000 */  lw        $a1, ($s0)
/* 832D7C 8024157C 844600A8 */  lh        $a2, 0xa8($v0)
/* 832D80 80241580 0C0B2026 */  jal       set_variable
/* 832D84 80241584 0220202D */   daddu    $a0, $s1, $zero
.L80241588:
/* 832D88 80241588 8FBF0018 */  lw        $ra, 0x18($sp)
/* 832D8C 8024158C 8FB10014 */  lw        $s1, 0x14($sp)
/* 832D90 80241590 8FB00010 */  lw        $s0, 0x10($sp)
/* 832D94 80241594 24020002 */  addiu     $v0, $zero, 2
/* 832D98 80241598 03E00008 */  jr        $ra
/* 832D9C 8024159C 27BD0020 */   addiu    $sp, $sp, 0x20

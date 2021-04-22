.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel CreateNpc
/* F2554 802CDBA4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F2558 802CDBA8 AFB10024 */  sw        $s1, 0x24($sp)
/* F255C 802CDBAC 0080882D */  daddu     $s1, $a0, $zero
/* F2560 802CDBB0 AFBF0028 */  sw        $ra, 0x28($sp)
/* F2564 802CDBB4 AFB00020 */  sw        $s0, 0x20($sp)
/* F2568 802CDBB8 8E30000C */  lw        $s0, 0xc($s1)
/* F256C 802CDBBC 8E050000 */  lw        $a1, ($s0)
/* F2570 802CDBC0 0C0B1EAF */  jal       get_variable
/* F2574 802CDBC4 26100004 */   addiu    $s0, $s0, 4
/* F2578 802CDBC8 0220202D */  daddu     $a0, $s1, $zero
/* F257C 802CDBCC 8E050000 */  lw        $a1, ($s0)
/* F2580 802CDBD0 0C0B1EAF */  jal       get_variable
/* F2584 802CDBD4 0040802D */   daddu    $s0, $v0, $zero
/* F2588 802CDBD8 27A40010 */  addiu     $a0, $sp, 0x10
/* F258C 802CDBDC AFA00010 */  sw        $zero, 0x10($sp)
/* F2590 802CDBE0 AFA20014 */  sw        $v0, 0x14($sp)
/* F2594 802CDBE4 AFA00018 */  sw        $zero, 0x18($sp)
/* F2598 802CDBE8 0C00E211 */  jal       npc_create_basic
/* F259C 802CDBEC AFA0001C */   sw       $zero, 0x1c($sp)
/* F25A0 802CDBF0 0C00E2B7 */  jal       get_npc_by_index
/* F25A4 802CDBF4 0040202D */   daddu    $a0, $v0, $zero
/* F25A8 802CDBF8 0040202D */  daddu     $a0, $v0, $zero
/* F25AC 802CDBFC 0C00EAFF */  jal       disable_npc_shadow
/* F25B0 802CDC00 A09000A4 */   sb       $s0, 0xa4($a0)
/* F25B4 802CDC04 8FBF0028 */  lw        $ra, 0x28($sp)
/* F25B8 802CDC08 8FB10024 */  lw        $s1, 0x24($sp)
/* F25BC 802CDC0C 8FB00020 */  lw        $s0, 0x20($sp)
/* F25C0 802CDC10 24020002 */  addiu     $v0, $zero, 2
/* F25C4 802CDC14 03E00008 */  jr        $ra
/* F25C8 802CDC18 27BD0030 */   addiu    $sp, $sp, 0x30

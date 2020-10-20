.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241580
/* C8F130 80241580 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8F134 80241584 AFB10014 */  sw        $s1, 0x14($sp)
/* C8F138 80241588 0080882D */  daddu     $s1, $a0, $zero
/* C8F13C 8024158C AFBF0018 */  sw        $ra, 0x18($sp)
/* C8F140 80241590 AFB00010 */  sw        $s0, 0x10($sp)
/* C8F144 80241594 8E30000C */  lw        $s0, 0xc($s1)
/* C8F148 80241598 8E050000 */  lw        $a1, ($s0)
/* C8F14C 8024159C 0C0B1EAF */  jal       get_variable
/* C8F150 802415A0 26100004 */   addiu    $s0, $s0, 4
/* C8F154 802415A4 0C00EAD2 */  jal       get_npc_safe
/* C8F158 802415A8 0040202D */   daddu    $a0, $v0, $zero
/* C8F15C 802415AC 10400005 */  beqz      $v0, .L802415C4
/* C8F160 802415B0 00000000 */   nop      
/* C8F164 802415B4 8E050000 */  lw        $a1, ($s0)
/* C8F168 802415B8 844600A8 */  lh        $a2, 0xa8($v0)
/* C8F16C 802415BC 0C0B2026 */  jal       set_variable
/* C8F170 802415C0 0220202D */   daddu    $a0, $s1, $zero
.L802415C4:
/* C8F174 802415C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C8F178 802415C8 8FB10014 */  lw        $s1, 0x14($sp)
/* C8F17C 802415CC 8FB00010 */  lw        $s0, 0x10($sp)
/* C8F180 802415D0 24020002 */  addiu     $v0, $zero, 2
/* C8F184 802415D4 03E00008 */  jr        $ra
/* C8F188 802415D8 27BD0020 */   addiu    $sp, $sp, 0x20

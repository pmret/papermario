.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243094
/* 96C254 80243094 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96C258 80243098 AFB10014 */  sw        $s1, 0x14($sp)
/* 96C25C 8024309C 0080882D */  daddu     $s1, $a0, $zero
/* 96C260 802430A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 96C264 802430A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 96C268 802430A8 8E30000C */  lw        $s0, 0xc($s1)
/* 96C26C 802430AC 8E050000 */  lw        $a1, ($s0)
/* 96C270 802430B0 0C0B1EAF */  jal       get_variable
/* 96C274 802430B4 26100004 */   addiu    $s0, $s0, 4
/* 96C278 802430B8 0C00EAD2 */  jal       get_npc_safe
/* 96C27C 802430BC 0040202D */   daddu    $a0, $v0, $zero
/* 96C280 802430C0 10400005 */  beqz      $v0, .L802430D8
/* 96C284 802430C4 00000000 */   nop      
/* 96C288 802430C8 8E050000 */  lw        $a1, ($s0)
/* 96C28C 802430CC 844600A8 */  lh        $a2, 0xa8($v0)
/* 96C290 802430D0 0C0B2026 */  jal       set_variable
/* 96C294 802430D4 0220202D */   daddu    $a0, $s1, $zero
.L802430D8:
/* 96C298 802430D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 96C29C 802430DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 96C2A0 802430E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 96C2A4 802430E4 24020002 */  addiu     $v0, $zero, 2
/* 96C2A8 802430E8 03E00008 */  jr        $ra
/* 96C2AC 802430EC 27BD0020 */   addiu    $sp, $sp, 0x20

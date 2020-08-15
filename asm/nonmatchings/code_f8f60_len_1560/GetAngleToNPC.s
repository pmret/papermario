.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetAngleToNPC
/* 0F9164 802D47B4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9168 802D47B8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F916C 802D47BC 0080882D */  daddu $s1, $a0, $zero
/* 0F9170 802D47C0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F9174 802D47C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9178 802D47C8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F917C 802D47CC 8E050000 */  lw    $a1, ($s0)
/* 0F9180 802D47D0 0C0B1EAF */  jal   get_variable
/* 0F9184 802D47D4 26100004 */   addiu $s0, $s0, 4
/* 0F9188 802D47D8 0220202D */  daddu $a0, $s1, $zero
/* 0F918C 802D47DC 8E100000 */  lw    $s0, ($s0)
/* 0F9190 802D47E0 0C0B36B0 */  jal   resolve_npc
/* 0F9194 802D47E4 0040282D */   daddu $a1, $v0, $zero
/* 0F9198 802D47E8 3C038011 */  lui   $v1, 0x8011
/* 0F919C 802D47EC 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F91A0 802D47F0 8C460038 */  lw    $a2, 0x38($v0)
/* 0F91A4 802D47F4 C46C0028 */  lwc1  $f12, 0x28($v1)
/* 0F91A8 802D47F8 C46E0030 */  lwc1  $f14, 0x30($v1)
/* 0F91AC 802D47FC 0C00A720 */  jal   atan2
/* 0F91B0 802D4800 8C470040 */   lw    $a3, 0x40($v0)
/* 0F91B4 802D4804 0220202D */  daddu $a0, $s1, $zero
/* 0F91B8 802D4808 4600008D */  trunc.w.s $f2, $f0
/* 0F91BC 802D480C 44061000 */  mfc1  $a2, $f2
/* 0F91C0 802D4810 0C0B2026 */  jal   set_variable
/* 0F91C4 802D4814 0200282D */   daddu $a1, $s0, $zero
/* 0F91C8 802D4818 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F91CC 802D481C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F91D0 802D4820 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F91D4 802D4824 24020002 */  addiu $v0, $zero, 2
/* 0F91D8 802D4828 03E00008 */  jr    $ra
/* 0F91DC 802D482C 27BD0020 */   addiu $sp, $sp, 0x20


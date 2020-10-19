.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DFC
/* 9C71DC 80241DFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C71E0 80241E00 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C71E4 80241E04 0080882D */  daddu     $s1, $a0, $zero
/* 9C71E8 80241E08 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C71EC 80241E0C AFB00010 */  sw        $s0, 0x10($sp)
/* 9C71F0 80241E10 8E30000C */  lw        $s0, 0xc($s1)
/* 9C71F4 80241E14 8E050000 */  lw        $a1, ($s0)
/* 9C71F8 80241E18 0C0B1EAF */  jal       get_variable
/* 9C71FC 80241E1C 26100004 */   addiu    $s0, $s0, 4
/* 9C7200 80241E20 0C00EAD2 */  jal       get_npc_safe
/* 9C7204 80241E24 0040202D */   daddu    $a0, $v0, $zero
/* 9C7208 80241E28 10400005 */  beqz      $v0, .L80241E40
/* 9C720C 80241E2C 00000000 */   nop      
/* 9C7210 80241E30 8E050000 */  lw        $a1, ($s0)
/* 9C7214 80241E34 844600A8 */  lh        $a2, 0xa8($v0)
/* 9C7218 80241E38 0C0B2026 */  jal       set_variable
/* 9C721C 80241E3C 0220202D */   daddu    $a0, $s1, $zero
.L80241E40:
/* 9C7220 80241E40 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C7224 80241E44 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C7228 80241E48 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C722C 80241E4C 24020002 */  addiu     $v0, $zero, 2
/* 9C7230 80241E50 03E00008 */  jr        $ra
/* 9C7234 80241E54 27BD0020 */   addiu    $sp, $sp, 0x20

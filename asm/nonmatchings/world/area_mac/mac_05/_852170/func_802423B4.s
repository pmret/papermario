.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423B4
/* 854524 802423B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 854528 802423B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 85452C 802423BC 0080882D */  daddu     $s1, $a0, $zero
/* 854530 802423C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 854534 802423C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 854538 802423C8 8E30000C */  lw        $s0, 0xc($s1)
/* 85453C 802423CC 8E050000 */  lw        $a1, ($s0)
/* 854540 802423D0 0C0B1EAF */  jal       get_variable
/* 854544 802423D4 26100004 */   addiu    $s0, $s0, 4
/* 854548 802423D8 0C00EAD2 */  jal       get_npc_safe
/* 85454C 802423DC 0040202D */   daddu    $a0, $v0, $zero
/* 854550 802423E0 10400005 */  beqz      $v0, .L802423F8
/* 854554 802423E4 00000000 */   nop      
/* 854558 802423E8 8E050000 */  lw        $a1, ($s0)
/* 85455C 802423EC 844600A8 */  lh        $a2, 0xa8($v0)
/* 854560 802423F0 0C0B2026 */  jal       set_variable
/* 854564 802423F4 0220202D */   daddu    $a0, $s1, $zero
.L802423F8:
/* 854568 802423F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 85456C 802423FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 854570 80242400 8FB00010 */  lw        $s0, 0x10($sp)
/* 854574 80242404 24020002 */  addiu     $v0, $zero, 2
/* 854578 80242408 03E00008 */  jr        $ra
/* 85457C 8024240C 27BD0020 */   addiu    $sp, $sp, 0x20

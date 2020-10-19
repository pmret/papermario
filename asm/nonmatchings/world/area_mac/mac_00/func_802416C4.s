.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C4
/* 7EC3D4 802416C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EC3D8 802416C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EC3DC 802416CC 0080882D */  daddu     $s1, $a0, $zero
/* 7EC3E0 802416D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EC3E4 802416D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EC3E8 802416D8 8E30000C */  lw        $s0, 0xc($s1)
/* 7EC3EC 802416DC 8E050000 */  lw        $a1, ($s0)
/* 7EC3F0 802416E0 0C0B1EAF */  jal       get_variable
/* 7EC3F4 802416E4 26100004 */   addiu    $s0, $s0, 4
/* 7EC3F8 802416E8 0C00EAD2 */  jal       get_npc_safe
/* 7EC3FC 802416EC 0040202D */   daddu    $a0, $v0, $zero
/* 7EC400 802416F0 10400005 */  beqz      $v0, .L80241708
/* 7EC404 802416F4 00000000 */   nop      
/* 7EC408 802416F8 8E050000 */  lw        $a1, ($s0)
/* 7EC40C 802416FC 844600A8 */  lh        $a2, 0xa8($v0)
/* 7EC410 80241700 0C0B2026 */  jal       set_variable
/* 7EC414 80241704 0220202D */   daddu    $a0, $s1, $zero
.L80241708:
/* 7EC418 80241708 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EC41C 8024170C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EC420 80241710 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EC424 80241714 24020002 */  addiu     $v0, $zero, 2
/* 7EC428 80241718 03E00008 */  jr        $ra
/* 7EC42C 8024171C 27BD0020 */   addiu    $sp, $sp, 0x20

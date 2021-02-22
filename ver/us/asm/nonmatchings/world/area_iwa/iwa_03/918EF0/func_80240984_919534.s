.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240984_919534
/* 919534 80240984 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 919538 80240988 AFB10014 */  sw        $s1, 0x14($sp)
/* 91953C 8024098C 0080882D */  daddu     $s1, $a0, $zero
/* 919540 80240990 AFBF0018 */  sw        $ra, 0x18($sp)
/* 919544 80240994 AFB00010 */  sw        $s0, 0x10($sp)
/* 919548 80240998 8E300148 */  lw        $s0, 0x148($s1)
/* 91954C 8024099C 0C00EABB */  jal       get_npc_unsafe
/* 919550 802409A0 86040008 */   lh       $a0, 8($s0)
/* 919554 802409A4 96030096 */  lhu       $v1, 0x96($s0)
/* 919558 802409A8 A443008E */  sh        $v1, 0x8e($v0)
/* 91955C 802409AC 8E0300CC */  lw        $v1, 0xcc($s0)
/* 919560 802409B0 8C630034 */  lw        $v1, 0x34($v1)
/* 919564 802409B4 AC430028 */  sw        $v1, 0x28($v0)
/* 919568 802409B8 24020015 */  addiu     $v0, $zero, 0x15
/* 91956C 802409BC AE220070 */  sw        $v0, 0x70($s1)
/* 919570 802409C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 919574 802409C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 919578 802409C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 91957C 802409CC 03E00008 */  jr        $ra
/* 919580 802409D0 27BD0020 */   addiu    $sp, $sp, 0x20

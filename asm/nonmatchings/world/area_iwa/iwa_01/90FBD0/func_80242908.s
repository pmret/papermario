.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242908
/* 911FB8 80242908 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 911FBC 8024290C AFB10014 */  sw        $s1, 0x14($sp)
/* 911FC0 80242910 0080882D */  daddu     $s1, $a0, $zero
/* 911FC4 80242914 AFBF0018 */  sw        $ra, 0x18($sp)
/* 911FC8 80242918 AFB00010 */  sw        $s0, 0x10($sp)
/* 911FCC 8024291C 8E300148 */  lw        $s0, 0x148($s1)
/* 911FD0 80242920 0C00EABB */  jal       get_npc_unsafe
/* 911FD4 80242924 86040008 */   lh       $a0, 8($s0)
/* 911FD8 80242928 96030096 */  lhu       $v1, 0x96($s0)
/* 911FDC 8024292C A443008E */  sh        $v1, 0x8e($v0)
/* 911FE0 80242930 8E0300CC */  lw        $v1, 0xcc($s0)
/* 911FE4 80242934 8C630034 */  lw        $v1, 0x34($v1)
/* 911FE8 80242938 AC430028 */  sw        $v1, 0x28($v0)
/* 911FEC 8024293C 24020015 */  addiu     $v0, $zero, 0x15
/* 911FF0 80242940 AE220070 */  sw        $v0, 0x70($s1)
/* 911FF4 80242944 8FBF0018 */  lw        $ra, 0x18($sp)
/* 911FF8 80242948 8FB10014 */  lw        $s1, 0x14($sp)
/* 911FFC 8024294C 8FB00010 */  lw        $s0, 0x10($sp)
/* 912000 80242950 03E00008 */  jr        $ra
/* 912004 80242954 27BD0020 */   addiu    $sp, $sp, 0x20

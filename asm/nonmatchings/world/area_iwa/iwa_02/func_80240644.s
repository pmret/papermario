.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240644
/* 9163B4 80240644 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9163B8 80240648 AFB10014 */  sw        $s1, 0x14($sp)
/* 9163BC 8024064C 0080882D */  daddu     $s1, $a0, $zero
/* 9163C0 80240650 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9163C4 80240654 AFB00010 */  sw        $s0, 0x10($sp)
/* 9163C8 80240658 8E300148 */  lw        $s0, 0x148($s1)
/* 9163CC 8024065C 0C00EABB */  jal       get_npc_unsafe
/* 9163D0 80240660 86040008 */   lh       $a0, 8($s0)
/* 9163D4 80240664 96030096 */  lhu       $v1, 0x96($s0)
/* 9163D8 80240668 A443008E */  sh        $v1, 0x8e($v0)
/* 9163DC 8024066C 8E0300CC */  lw        $v1, 0xcc($s0)
/* 9163E0 80240670 8C630034 */  lw        $v1, 0x34($v1)
/* 9163E4 80240674 AC430028 */  sw        $v1, 0x28($v0)
/* 9163E8 80240678 24020015 */  addiu     $v0, $zero, 0x15
/* 9163EC 8024067C AE220070 */  sw        $v0, 0x70($s1)
/* 9163F0 80240680 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9163F4 80240684 8FB10014 */  lw        $s1, 0x14($sp)
/* 9163F8 80240688 8FB00010 */  lw        $s0, 0x10($sp)
/* 9163FC 8024068C 03E00008 */  jr        $ra
/* 916400 80240690 27BD0020 */   addiu    $sp, $sp, 0x20

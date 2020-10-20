.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240660
/* 969820 80240660 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 969824 80240664 AFBF0014 */  sw        $ra, 0x14($sp)
/* 969828 80240668 AFB00010 */  sw        $s0, 0x10($sp)
/* 96982C 8024066C 0C00EABB */  jal       get_npc_unsafe
/* 969830 80240670 8C84014C */   lw       $a0, 0x14c($a0)
/* 969834 80240674 24040008 */  addiu     $a0, $zero, 8
/* 969838 80240678 0040802D */  daddu     $s0, $v0, $zero
/* 96983C 8024067C 3C028024 */  lui       $v0, 0x8024
/* 969840 80240680 244206CC */  addiu     $v0, $v0, 0x6cc
/* 969844 80240684 0C00AB39 */  jal       heap_malloc
/* 969848 80240688 AE020008 */   sw       $v0, 8($s0)
/* 96984C 8024068C 0040182D */  daddu     $v1, $v0, $zero
/* 969850 80240690 AE030020 */  sw        $v1, 0x20($s0)
/* 969854 80240694 AC600000 */  sw        $zero, ($v1)
/* 969858 80240698 8FBF0014 */  lw        $ra, 0x14($sp)
/* 96985C 8024069C 8FB00010 */  lw        $s0, 0x10($sp)
/* 969860 802406A0 24020001 */  addiu     $v0, $zero, 1
/* 969864 802406A4 03E00008 */  jr        $ra
/* 969868 802406A8 27BD0018 */   addiu    $sp, $sp, 0x18

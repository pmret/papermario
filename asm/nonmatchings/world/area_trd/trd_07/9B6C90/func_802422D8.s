.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422D8
/* 9B8C58 802422D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9B8C5C 802422DC AFB00010 */  sw        $s0, 0x10($sp)
/* 9B8C60 802422E0 0080802D */  daddu     $s0, $a0, $zero
/* 9B8C64 802422E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9B8C68 802422E8 8E020148 */  lw        $v0, 0x148($s0)
/* 9B8C6C 802422EC 0C00EABB */  jal       get_npc_unsafe
/* 9B8C70 802422F0 84440008 */   lh       $a0, 8($v0)
/* 9B8C74 802422F4 9443008E */  lhu       $v1, 0x8e($v0)
/* 9B8C78 802422F8 2463FFFF */  addiu     $v1, $v1, -1
/* 9B8C7C 802422FC A443008E */  sh        $v1, 0x8e($v0)
/* 9B8C80 80242300 00031C00 */  sll       $v1, $v1, 0x10
/* 9B8C84 80242304 58600001 */  blezl     $v1, .L8024230C
/* 9B8C88 80242308 AE000070 */   sw       $zero, 0x70($s0)
.L8024230C:
/* 9B8C8C 8024230C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9B8C90 80242310 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B8C94 80242314 03E00008 */  jr        $ra
/* 9B8C98 80242318 27BD0018 */   addiu    $sp, $sp, 0x18

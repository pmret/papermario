.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A38_9100E8
/* 9100E8 80240A38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9100EC 80240A3C AFB00010 */  sw        $s0, 0x10($sp)
/* 9100F0 80240A40 0080802D */  daddu     $s0, $a0, $zero
/* 9100F4 80240A44 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9100F8 80240A48 8E020148 */  lw        $v0, 0x148($s0)
/* 9100FC 80240A4C 0C00EABB */  jal       get_npc_unsafe
/* 910100 80240A50 84440008 */   lh       $a0, 8($v0)
/* 910104 80240A54 9443008E */  lhu       $v1, 0x8e($v0)
/* 910108 80240A58 2463FFFF */  addiu     $v1, $v1, -1
/* 91010C 80240A5C A443008E */  sh        $v1, 0x8e($v0)
/* 910110 80240A60 00031C00 */  sll       $v1, $v1, 0x10
/* 910114 80240A64 58600001 */  blezl     $v1, .L80240A6C
/* 910118 80240A68 AE000070 */   sw       $zero, 0x70($s0)
.L80240A6C:
/* 91011C 80240A6C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 910120 80240A70 8FB00010 */  lw        $s0, 0x10($sp)
/* 910124 80240A74 03E00008 */  jr        $ra
/* 910128 80240A78 27BD0018 */   addiu    $sp, $sp, 0x18

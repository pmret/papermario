.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240688_A9F3C8
/* A9F3C8 80240688 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9F3CC 8024068C AFB00010 */  sw        $s0, 0x10($sp)
/* A9F3D0 80240690 0080802D */  daddu     $s0, $a0, $zero
/* A9F3D4 80240694 AFBF0014 */  sw        $ra, 0x14($sp)
/* A9F3D8 80240698 8E020148 */  lw        $v0, 0x148($s0)
/* A9F3DC 8024069C 0C00EABB */  jal       get_npc_unsafe
/* A9F3E0 802406A0 84440008 */   lh       $a0, 8($v0)
/* A9F3E4 802406A4 9443008E */  lhu       $v1, 0x8e($v0)
/* A9F3E8 802406A8 2463FFFF */  addiu     $v1, $v1, -1
/* A9F3EC 802406AC A443008E */  sh        $v1, 0x8e($v0)
/* A9F3F0 802406B0 00031C00 */  sll       $v1, $v1, 0x10
/* A9F3F4 802406B4 58600001 */  blezl     $v1, .L802406BC
/* A9F3F8 802406B8 AE000070 */   sw       $zero, 0x70($s0)
.L802406BC:
/* A9F3FC 802406BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A9F400 802406C0 8FB00010 */  lw        $s0, 0x10($sp)
/* A9F404 802406C4 03E00008 */  jr        $ra
/* A9F408 802406C8 27BD0018 */   addiu    $sp, $sp, 0x18

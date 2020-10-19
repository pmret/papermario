.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405F8
/* A676F8 802405F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A676FC 802405FC AFB00010 */  sw        $s0, 0x10($sp)
/* A67700 80240600 0080802D */  daddu     $s0, $a0, $zero
/* A67704 80240604 AFBF0014 */  sw        $ra, 0x14($sp)
/* A67708 80240608 8E020148 */  lw        $v0, 0x148($s0)
/* A6770C 8024060C 0C00EABB */  jal       get_npc_unsafe
/* A67710 80240610 84440008 */   lh       $a0, 8($v0)
/* A67714 80240614 9443008E */  lhu       $v1, 0x8e($v0)
/* A67718 80240618 2463FFFF */  addiu     $v1, $v1, -1
/* A6771C 8024061C A443008E */  sh        $v1, 0x8e($v0)
/* A67720 80240620 00031C00 */  sll       $v1, $v1, 0x10
/* A67724 80240624 58600001 */  blezl     $v1, .L8024062C
/* A67728 80240628 AE000070 */   sw       $zero, 0x70($s0)
.L8024062C:
/* A6772C 8024062C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A67730 80240630 8FB00010 */  lw        $s0, 0x10($sp)
/* A67734 80240634 03E00008 */  jr        $ra
/* A67738 80240638 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242870_DCF540
/* DCF540 80242870 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DCF544 80242874 AFB00010 */  sw        $s0, 0x10($sp)
/* DCF548 80242878 0080802D */  daddu     $s0, $a0, $zero
/* DCF54C 8024287C AFBF0014 */  sw        $ra, 0x14($sp)
/* DCF550 80242880 8E020148 */  lw        $v0, 0x148($s0)
/* DCF554 80242884 0C00EABB */  jal       get_npc_unsafe
/* DCF558 80242888 84440008 */   lh       $a0, 8($v0)
/* DCF55C 8024288C 9443008E */  lhu       $v1, 0x8e($v0)
/* DCF560 80242890 2463FFFF */  addiu     $v1, $v1, -1
/* DCF564 80242894 A443008E */  sh        $v1, 0x8e($v0)
/* DCF568 80242898 00031C00 */  sll       $v1, $v1, 0x10
/* DCF56C 8024289C 58600001 */  blezl     $v1, .L802428A4
/* DCF570 802428A0 AE000070 */   sw       $zero, 0x70($s0)
.L802428A4:
/* DCF574 802428A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* DCF578 802428A8 8FB00010 */  lw        $s0, 0x10($sp)
/* DCF57C 802428AC 03E00008 */  jr        $ra
/* DCF580 802428B0 27BD0018 */   addiu    $sp, $sp, 0x18

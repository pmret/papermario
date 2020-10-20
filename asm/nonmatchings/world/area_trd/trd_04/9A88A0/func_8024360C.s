.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024360C
/* 9AB9FC 8024360C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9ABA00 80243610 AFB00010 */  sw        $s0, 0x10($sp)
/* 9ABA04 80243614 0080802D */  daddu     $s0, $a0, $zero
/* 9ABA08 80243618 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9ABA0C 8024361C 8E020148 */  lw        $v0, 0x148($s0)
/* 9ABA10 80243620 0C00EABB */  jal       get_npc_unsafe
/* 9ABA14 80243624 84440008 */   lh       $a0, 8($v0)
/* 9ABA18 80243628 9443008E */  lhu       $v1, 0x8e($v0)
/* 9ABA1C 8024362C 2463FFFF */  addiu     $v1, $v1, -1
/* 9ABA20 80243630 A443008E */  sh        $v1, 0x8e($v0)
/* 9ABA24 80243634 00031C00 */  sll       $v1, $v1, 0x10
/* 9ABA28 80243638 58600001 */  blezl     $v1, .L80243640
/* 9ABA2C 8024363C AE000070 */   sw       $zero, 0x70($s0)
.L80243640:
/* 9ABA30 80243640 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9ABA34 80243644 8FB00010 */  lw        $s0, 0x10($sp)
/* 9ABA38 80243648 03E00008 */  jr        $ra
/* 9ABA3C 8024364C 27BD0018 */   addiu    $sp, $sp, 0x18

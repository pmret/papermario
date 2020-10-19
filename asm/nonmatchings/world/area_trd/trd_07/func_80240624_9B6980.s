.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240624_9B6FA4
/* 9B6FA4 80240624 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9B6FA8 80240628 AFB10014 */  sw        $s1, 0x14($sp)
/* 9B6FAC 8024062C 0080882D */  daddu     $s1, $a0, $zero
/* 9B6FB0 80240630 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9B6FB4 80240634 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B6FB8 80240638 8E300148 */  lw        $s0, 0x148($s1)
/* 9B6FBC 8024063C 0C00EABB */  jal       get_npc_unsafe
/* 9B6FC0 80240640 86040008 */   lh       $a0, 8($s0)
/* 9B6FC4 80240644 0040202D */  daddu     $a0, $v0, $zero
/* 9B6FC8 80240648 9482008E */  lhu       $v0, 0x8e($a0)
/* 9B6FCC 8024064C 24030003 */  addiu     $v1, $zero, 3
/* 9B6FD0 80240650 24420001 */  addiu     $v0, $v0, 1
/* 9B6FD4 80240654 A482008E */  sh        $v0, 0x8e($a0)
/* 9B6FD8 80240658 00021400 */  sll       $v0, $v0, 0x10
/* 9B6FDC 8024065C 00021403 */  sra       $v0, $v0, 0x10
/* 9B6FE0 80240660 14430003 */  bne       $v0, $v1, .L80240670
/* 9B6FE4 80240664 00000000 */   nop      
/* 9B6FE8 80240668 96020086 */  lhu       $v0, 0x86($s0)
/* 9B6FEC 8024066C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240670:
/* 9B6FF0 80240670 8482008E */  lh        $v0, 0x8e($a0)
/* 9B6FF4 80240674 8E030080 */  lw        $v1, 0x80($s0)
/* 9B6FF8 80240678 0043102A */  slt       $v0, $v0, $v1
/* 9B6FFC 8024067C 14400004 */  bnez      $v0, .L80240690
/* 9B7000 80240680 00000000 */   nop      
/* 9B7004 80240684 96020086 */  lhu       $v0, 0x86($s0)
/* 9B7008 80240688 A48200A8 */  sh        $v0, 0xa8($a0)
/* 9B700C 8024068C AE200070 */  sw        $zero, 0x70($s1)
.L80240690:
/* 9B7010 80240690 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9B7014 80240694 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B7018 80240698 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B701C 8024069C 03E00008 */  jr        $ra
/* 9B7020 802406A0 27BD0020 */   addiu    $sp, $sp, 0x20

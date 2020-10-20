.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240624_A6EA04
/* A6EA04 80240624 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A6EA08 80240628 AFB10014 */  sw        $s1, 0x14($sp)
/* A6EA0C 8024062C 0080882D */  daddu     $s1, $a0, $zero
/* A6EA10 80240630 AFBF0018 */  sw        $ra, 0x18($sp)
/* A6EA14 80240634 AFB00010 */  sw        $s0, 0x10($sp)
/* A6EA18 80240638 8E300148 */  lw        $s0, 0x148($s1)
/* A6EA1C 8024063C 0C00EABB */  jal       get_npc_unsafe
/* A6EA20 80240640 86040008 */   lh       $a0, 8($s0)
/* A6EA24 80240644 0040202D */  daddu     $a0, $v0, $zero
/* A6EA28 80240648 9482008E */  lhu       $v0, 0x8e($a0)
/* A6EA2C 8024064C 24030003 */  addiu     $v1, $zero, 3
/* A6EA30 80240650 24420001 */  addiu     $v0, $v0, 1
/* A6EA34 80240654 A482008E */  sh        $v0, 0x8e($a0)
/* A6EA38 80240658 00021400 */  sll       $v0, $v0, 0x10
/* A6EA3C 8024065C 00021403 */  sra       $v0, $v0, 0x10
/* A6EA40 80240660 14430003 */  bne       $v0, $v1, .L80240670
/* A6EA44 80240664 00000000 */   nop      
/* A6EA48 80240668 96020086 */  lhu       $v0, 0x86($s0)
/* A6EA4C 8024066C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240670:
/* A6EA50 80240670 8482008E */  lh        $v0, 0x8e($a0)
/* A6EA54 80240674 8E030080 */  lw        $v1, 0x80($s0)
/* A6EA58 80240678 0043102A */  slt       $v0, $v0, $v1
/* A6EA5C 8024067C 14400004 */  bnez      $v0, .L80240690
/* A6EA60 80240680 00000000 */   nop      
/* A6EA64 80240684 96020086 */  lhu       $v0, 0x86($s0)
/* A6EA68 80240688 A48200A8 */  sh        $v0, 0xa8($a0)
/* A6EA6C 8024068C AE200070 */  sw        $zero, 0x70($s1)
.L80240690:
/* A6EA70 80240690 8FBF0018 */  lw        $ra, 0x18($sp)
/* A6EA74 80240694 8FB10014 */  lw        $s1, 0x14($sp)
/* A6EA78 80240698 8FB00010 */  lw        $s0, 0x10($sp)
/* A6EA7C 8024069C 03E00008 */  jr        $ra
/* A6EA80 802406A0 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407C4_9A8BB4
/* 9A8BB4 802407C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A8BB8 802407C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A8BBC 802407CC 0080882D */  daddu     $s1, $a0, $zero
/* 9A8BC0 802407D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9A8BC4 802407D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A8BC8 802407D8 8E300148 */  lw        $s0, 0x148($s1)
/* 9A8BCC 802407DC 0C00EABB */  jal       get_npc_unsafe
/* 9A8BD0 802407E0 86040008 */   lh       $a0, 8($s0)
/* 9A8BD4 802407E4 0040202D */  daddu     $a0, $v0, $zero
/* 9A8BD8 802407E8 9482008E */  lhu       $v0, 0x8e($a0)
/* 9A8BDC 802407EC 24030003 */  addiu     $v1, $zero, 3
/* 9A8BE0 802407F0 24420001 */  addiu     $v0, $v0, 1
/* 9A8BE4 802407F4 A482008E */  sh        $v0, 0x8e($a0)
/* 9A8BE8 802407F8 00021400 */  sll       $v0, $v0, 0x10
/* 9A8BEC 802407FC 00021403 */  sra       $v0, $v0, 0x10
/* 9A8BF0 80240800 14430003 */  bne       $v0, $v1, .L80240810
/* 9A8BF4 80240804 00000000 */   nop      
/* 9A8BF8 80240808 96020086 */  lhu       $v0, 0x86($s0)
/* 9A8BFC 8024080C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240810:
/* 9A8C00 80240810 8482008E */  lh        $v0, 0x8e($a0)
/* 9A8C04 80240814 8E030080 */  lw        $v1, 0x80($s0)
/* 9A8C08 80240818 0043102A */  slt       $v0, $v0, $v1
/* 9A8C0C 8024081C 14400004 */  bnez      $v0, .L80240830
/* 9A8C10 80240820 00000000 */   nop      
/* 9A8C14 80240824 96020086 */  lhu       $v0, 0x86($s0)
/* 9A8C18 80240828 A48200A8 */  sh        $v0, 0xa8($a0)
/* 9A8C1C 8024082C AE200070 */  sw        $zero, 0x70($s1)
.L80240830:
/* 9A8C20 80240830 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9A8C24 80240834 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A8C28 80240838 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A8C2C 8024083C 03E00008 */  jr        $ra
/* 9A8C30 80240840 27BD0020 */   addiu    $sp, $sp, 0x20

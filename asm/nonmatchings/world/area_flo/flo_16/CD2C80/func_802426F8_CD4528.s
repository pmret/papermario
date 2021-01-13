.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426F8_CD4528
/* CD4528 802426F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD452C 802426FC AFB10014 */  sw        $s1, 0x14($sp)
/* CD4530 80242700 0080882D */  daddu     $s1, $a0, $zero
/* CD4534 80242704 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD4538 80242708 AFB00010 */  sw        $s0, 0x10($sp)
/* CD453C 8024270C 8E300148 */  lw        $s0, 0x148($s1)
/* CD4540 80242710 0C00EABB */  jal       get_npc_unsafe
/* CD4544 80242714 86040008 */   lh       $a0, 8($s0)
/* CD4548 80242718 0040182D */  daddu     $v1, $v0, $zero
/* CD454C 8024271C 9462008E */  lhu       $v0, 0x8e($v1)
/* CD4550 80242720 2442FFFF */  addiu     $v0, $v0, -1
/* CD4554 80242724 A462008E */  sh        $v0, 0x8e($v1)
/* CD4558 80242728 00021400 */  sll       $v0, $v0, 0x10
/* CD455C 8024272C 1C400004 */  bgtz      $v0, .L80242740
/* CD4560 80242730 00000000 */   nop
/* CD4564 80242734 AE000074 */  sw        $zero, 0x74($s0)
/* CD4568 80242738 A460008E */  sh        $zero, 0x8e($v1)
/* CD456C 8024273C AE200070 */  sw        $zero, 0x70($s1)
.L80242740:
/* CD4570 80242740 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD4574 80242744 8FB10014 */  lw        $s1, 0x14($sp)
/* CD4578 80242748 8FB00010 */  lw        $s0, 0x10($sp)
/* CD457C 8024274C 03E00008 */  jr        $ra
/* CD4580 80242750 27BD0020 */   addiu    $sp, $sp, 0x20

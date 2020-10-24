.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426F0_C73B70
/* C73B70 802426F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C73B74 802426F4 AFB10014 */  sw        $s1, 0x14($sp)
/* C73B78 802426F8 0080882D */  daddu     $s1, $a0, $zero
/* C73B7C 802426FC AFBF0018 */  sw        $ra, 0x18($sp)
/* C73B80 80242700 AFB00010 */  sw        $s0, 0x10($sp)
/* C73B84 80242704 8E300148 */  lw        $s0, 0x148($s1)
/* C73B88 80242708 0C00EABB */  jal       get_npc_unsafe
/* C73B8C 8024270C 86040008 */   lh       $a0, 8($s0)
/* C73B90 80242710 9443008E */  lhu       $v1, 0x8e($v0)
/* C73B94 80242714 2463FFFF */  addiu     $v1, $v1, -1
/* C73B98 80242718 A443008E */  sh        $v1, 0x8e($v0)
/* C73B9C 8024271C 00031C00 */  sll       $v1, $v1, 0x10
/* C73BA0 80242720 1C600003 */  bgtz      $v1, .L80242730
/* C73BA4 80242724 2402000C */   addiu    $v0, $zero, 0xc
/* C73BA8 80242728 AE00006C */  sw        $zero, 0x6c($s0)
/* C73BAC 8024272C AE220070 */  sw        $v0, 0x70($s1)
.L80242730:
/* C73BB0 80242730 8FBF0018 */  lw        $ra, 0x18($sp)
/* C73BB4 80242734 8FB10014 */  lw        $s1, 0x14($sp)
/* C73BB8 80242738 8FB00010 */  lw        $s0, 0x10($sp)
/* C73BBC 8024273C 03E00008 */  jr        $ra
/* C73BC0 80242740 27BD0020 */   addiu    $sp, $sp, 0x20

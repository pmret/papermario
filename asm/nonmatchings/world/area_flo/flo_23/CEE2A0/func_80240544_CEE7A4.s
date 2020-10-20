.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_CEE7A4
/* CEE7A4 80240544 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CEE7A8 80240548 AFB3003C */  sw        $s3, 0x3c($sp)
/* CEE7AC 8024054C 0080982D */  daddu     $s3, $a0, $zero
/* CEE7B0 80240550 AFBF0040 */  sw        $ra, 0x40($sp)
/* CEE7B4 80240554 AFB20038 */  sw        $s2, 0x38($sp)
/* CEE7B8 80240558 AFB10034 */  sw        $s1, 0x34($sp)
/* CEE7BC 8024055C AFB00030 */  sw        $s0, 0x30($sp)
/* CEE7C0 80240560 8E710148 */  lw        $s1, 0x148($s3)
/* CEE7C4 80240564 0C00EABB */  jal       get_npc_unsafe
/* CEE7C8 80240568 86240008 */   lh       $a0, 8($s1)
/* CEE7CC 8024056C 0040802D */  daddu     $s0, $v0, $zero
/* CEE7D0 80240570 8E22007C */  lw        $v0, 0x7c($s1)
/* CEE7D4 80240574 8603008E */  lh        $v1, 0x8e($s0)
/* CEE7D8 80240578 2442FFFF */  addiu     $v0, $v0, -1
/* CEE7DC 8024057C 14620012 */  bne       $v1, $v0, .L802405C8
/* CEE7E0 80240580 00000000 */   nop      
/* CEE7E4 80240584 C6000038 */  lwc1      $f0, 0x38($s0)
/* CEE7E8 80240588 4600020D */  trunc.w.s $f8, $f0
/* CEE7EC 8024058C 44024000 */  mfc1      $v0, $f8
/* CEE7F0 80240590 00000000 */  nop       
/* CEE7F4 80240594 A6220010 */  sh        $v0, 0x10($s1)
/* CEE7F8 80240598 C600003C */  lwc1      $f0, 0x3c($s0)
/* CEE7FC 8024059C 4600020D */  trunc.w.s $f8, $f0
/* CEE800 802405A0 44024000 */  mfc1      $v0, $f8
/* CEE804 802405A4 00000000 */  nop       
/* CEE808 802405A8 A6220012 */  sh        $v0, 0x12($s1)
/* CEE80C 802405AC C6000040 */  lwc1      $f0, 0x40($s0)
/* CEE810 802405B0 24020001 */  addiu     $v0, $zero, 1
/* CEE814 802405B4 A2220007 */  sb        $v0, 7($s1)
/* CEE818 802405B8 4600020D */  trunc.w.s $f8, $f0
/* CEE81C 802405BC 44024000 */  mfc1      $v0, $f8
/* CEE820 802405C0 00000000 */  nop       
/* CEE824 802405C4 A6220014 */  sh        $v0, 0x14($s1)
.L802405C8:
/* CEE828 802405C8 C6000038 */  lwc1      $f0, 0x38($s0)
/* CEE82C 802405CC C602003C */  lwc1      $f2, 0x3c($s0)
/* CEE830 802405D0 C6040040 */  lwc1      $f4, 0x40($s0)
/* CEE834 802405D4 C6060018 */  lwc1      $f6, 0x18($s0)
/* CEE838 802405D8 E7A00020 */  swc1      $f0, 0x20($sp)
/* CEE83C 802405DC E7A20024 */  swc1      $f2, 0x24($sp)
/* CEE840 802405E0 E7A40028 */  swc1      $f4, 0x28($sp)
/* CEE844 802405E4 E7A60010 */  swc1      $f6, 0x10($sp)
/* CEE848 802405E8 C600000C */  lwc1      $f0, 0xc($s0)
/* CEE84C 802405EC E7A00014 */  swc1      $f0, 0x14($sp)
/* CEE850 802405F0 860200A8 */  lh        $v0, 0xa8($s0)
/* CEE854 802405F4 27A50020 */  addiu     $a1, $sp, 0x20
/* CEE858 802405F8 44820000 */  mtc1      $v0, $f0
/* CEE85C 802405FC 00000000 */  nop       
/* CEE860 80240600 46800020 */  cvt.s.w   $f0, $f0
/* CEE864 80240604 E7A00018 */  swc1      $f0, 0x18($sp)
/* CEE868 80240608 860200A6 */  lh        $v0, 0xa6($s0)
/* CEE86C 8024060C 27A60024 */  addiu     $a2, $sp, 0x24
/* CEE870 80240610 44820000 */  mtc1      $v0, $f0
/* CEE874 80240614 00000000 */  nop       
/* CEE878 80240618 46800020 */  cvt.s.w   $f0, $f0
/* CEE87C 8024061C E7A0001C */  swc1      $f0, 0x1c($sp)
/* CEE880 80240620 8E040080 */  lw        $a0, 0x80($s0)
/* CEE884 80240624 0C037711 */  jal       func_800DDC44
/* CEE888 80240628 27A70028 */   addiu    $a3, $sp, 0x28
/* CEE88C 8024062C 0040902D */  daddu     $s2, $v0, $zero
/* CEE890 80240630 16400005 */  bnez      $s2, .L80240648
/* CEE894 80240634 00000000 */   nop      
/* CEE898 80240638 8E050018 */  lw        $a1, 0x18($s0)
/* CEE89C 8024063C 8E06000C */  lw        $a2, 0xc($s0)
/* CEE8A0 80240640 0C00EA95 */  jal       npc_move_heading
/* CEE8A4 80240644 0200202D */   daddu    $a0, $s0, $zero
.L80240648:
/* CEE8A8 80240648 8602008E */  lh        $v0, 0x8e($s0)
/* CEE8AC 8024064C 9603008E */  lhu       $v1, 0x8e($s0)
/* CEE8B0 80240650 18400007 */  blez      $v0, .L80240670
/* CEE8B4 80240654 2462FFFF */   addiu    $v0, $v1, -1
/* CEE8B8 80240658 A602008E */  sh        $v0, 0x8e($s0)
/* CEE8BC 8024065C 00021400 */  sll       $v0, $v0, 0x10
/* CEE8C0 80240660 18400003 */  blez      $v0, .L80240670
/* CEE8C4 80240664 00000000 */   nop      
/* CEE8C8 80240668 12400008 */  beqz      $s2, .L8024068C
/* CEE8CC 8024066C 00000000 */   nop      
.L80240670:
/* CEE8D0 80240670 8E2200CC */  lw        $v0, 0xcc($s1)
/* CEE8D4 80240674 A2200007 */  sb        $zero, 7($s1)
/* CEE8D8 80240678 8C420028 */  lw        $v0, 0x28($v0)
/* CEE8DC 8024067C A600008E */  sh        $zero, 0x8e($s0)
/* CEE8E0 80240680 AE020028 */  sw        $v0, 0x28($s0)
/* CEE8E4 80240684 2402000F */  addiu     $v0, $zero, 0xf
/* CEE8E8 80240688 AE620070 */  sw        $v0, 0x70($s3)
.L8024068C:
/* CEE8EC 8024068C 8FBF0040 */  lw        $ra, 0x40($sp)
/* CEE8F0 80240690 8FB3003C */  lw        $s3, 0x3c($sp)
/* CEE8F4 80240694 8FB20038 */  lw        $s2, 0x38($sp)
/* CEE8F8 80240698 8FB10034 */  lw        $s1, 0x34($sp)
/* CEE8FC 8024069C 8FB00030 */  lw        $s0, 0x30($sp)
/* CEE900 802406A0 03E00008 */  jr        $ra
/* CEE904 802406A4 27BD0048 */   addiu    $sp, $sp, 0x48

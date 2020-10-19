.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415FC_A6568C
/* A6568C 802415FC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A65690 80241600 AFB3003C */  sw        $s3, 0x3c($sp)
/* A65694 80241604 0080982D */  daddu     $s3, $a0, $zero
/* A65698 80241608 AFBF0040 */  sw        $ra, 0x40($sp)
/* A6569C 8024160C AFB20038 */  sw        $s2, 0x38($sp)
/* A656A0 80241610 AFB10034 */  sw        $s1, 0x34($sp)
/* A656A4 80241614 AFB00030 */  sw        $s0, 0x30($sp)
/* A656A8 80241618 8E710148 */  lw        $s1, 0x148($s3)
/* A656AC 8024161C 0C00EABB */  jal       get_npc_unsafe
/* A656B0 80241620 86240008 */   lh       $a0, 8($s1)
/* A656B4 80241624 0040802D */  daddu     $s0, $v0, $zero
/* A656B8 80241628 8E22007C */  lw        $v0, 0x7c($s1)
/* A656BC 8024162C 8603008E */  lh        $v1, 0x8e($s0)
/* A656C0 80241630 2442FFFF */  addiu     $v0, $v0, -1
/* A656C4 80241634 14620012 */  bne       $v1, $v0, .L80241680
/* A656C8 80241638 00000000 */   nop      
/* A656CC 8024163C C6000038 */  lwc1      $f0, 0x38($s0)
/* A656D0 80241640 4600020D */  trunc.w.s $f8, $f0
/* A656D4 80241644 44024000 */  mfc1      $v0, $f8
/* A656D8 80241648 00000000 */  nop       
/* A656DC 8024164C A6220010 */  sh        $v0, 0x10($s1)
/* A656E0 80241650 C600003C */  lwc1      $f0, 0x3c($s0)
/* A656E4 80241654 4600020D */  trunc.w.s $f8, $f0
/* A656E8 80241658 44024000 */  mfc1      $v0, $f8
/* A656EC 8024165C 00000000 */  nop       
/* A656F0 80241660 A6220012 */  sh        $v0, 0x12($s1)
/* A656F4 80241664 C6000040 */  lwc1      $f0, 0x40($s0)
/* A656F8 80241668 24020001 */  addiu     $v0, $zero, 1
/* A656FC 8024166C A2220007 */  sb        $v0, 7($s1)
/* A65700 80241670 4600020D */  trunc.w.s $f8, $f0
/* A65704 80241674 44024000 */  mfc1      $v0, $f8
/* A65708 80241678 00000000 */  nop       
/* A6570C 8024167C A6220014 */  sh        $v0, 0x14($s1)
.L80241680:
/* A65710 80241680 C6000038 */  lwc1      $f0, 0x38($s0)
/* A65714 80241684 C602003C */  lwc1      $f2, 0x3c($s0)
/* A65718 80241688 C6040040 */  lwc1      $f4, 0x40($s0)
/* A6571C 8024168C C6060018 */  lwc1      $f6, 0x18($s0)
/* A65720 80241690 E7A00020 */  swc1      $f0, 0x20($sp)
/* A65724 80241694 E7A20024 */  swc1      $f2, 0x24($sp)
/* A65728 80241698 E7A40028 */  swc1      $f4, 0x28($sp)
/* A6572C 8024169C E7A60010 */  swc1      $f6, 0x10($sp)
/* A65730 802416A0 C600000C */  lwc1      $f0, 0xc($s0)
/* A65734 802416A4 E7A00014 */  swc1      $f0, 0x14($sp)
/* A65738 802416A8 860200A8 */  lh        $v0, 0xa8($s0)
/* A6573C 802416AC 27A50020 */  addiu     $a1, $sp, 0x20
/* A65740 802416B0 44820000 */  mtc1      $v0, $f0
/* A65744 802416B4 00000000 */  nop       
/* A65748 802416B8 46800020 */  cvt.s.w   $f0, $f0
/* A6574C 802416BC E7A00018 */  swc1      $f0, 0x18($sp)
/* A65750 802416C0 860200A6 */  lh        $v0, 0xa6($s0)
/* A65754 802416C4 27A60024 */  addiu     $a2, $sp, 0x24
/* A65758 802416C8 44820000 */  mtc1      $v0, $f0
/* A6575C 802416CC 00000000 */  nop       
/* A65760 802416D0 46800020 */  cvt.s.w   $f0, $f0
/* A65764 802416D4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A65768 802416D8 8E040080 */  lw        $a0, 0x80($s0)
/* A6576C 802416DC 0C037711 */  jal       func_800DDC44
/* A65770 802416E0 27A70028 */   addiu    $a3, $sp, 0x28
/* A65774 802416E4 0040902D */  daddu     $s2, $v0, $zero
/* A65778 802416E8 16400005 */  bnez      $s2, .L80241700
/* A6577C 802416EC 00000000 */   nop      
/* A65780 802416F0 8E050018 */  lw        $a1, 0x18($s0)
/* A65784 802416F4 8E06000C */  lw        $a2, 0xc($s0)
/* A65788 802416F8 0C00EA95 */  jal       npc_move_heading
/* A6578C 802416FC 0200202D */   daddu    $a0, $s0, $zero
.L80241700:
/* A65790 80241700 8602008E */  lh        $v0, 0x8e($s0)
/* A65794 80241704 9603008E */  lhu       $v1, 0x8e($s0)
/* A65798 80241708 18400007 */  blez      $v0, .L80241728
/* A6579C 8024170C 2462FFFF */   addiu    $v0, $v1, -1
/* A657A0 80241710 A602008E */  sh        $v0, 0x8e($s0)
/* A657A4 80241714 00021400 */  sll       $v0, $v0, 0x10
/* A657A8 80241718 18400003 */  blez      $v0, .L80241728
/* A657AC 8024171C 00000000 */   nop      
/* A657B0 80241720 12400008 */  beqz      $s2, .L80241744
/* A657B4 80241724 00000000 */   nop      
.L80241728:
/* A657B8 80241728 8E2200CC */  lw        $v0, 0xcc($s1)
/* A657BC 8024172C A2200007 */  sb        $zero, 7($s1)
/* A657C0 80241730 8C420028 */  lw        $v0, 0x28($v0)
/* A657C4 80241734 A600008E */  sh        $zero, 0x8e($s0)
/* A657C8 80241738 AE020028 */  sw        $v0, 0x28($s0)
/* A657CC 8024173C 2402000F */  addiu     $v0, $zero, 0xf
/* A657D0 80241740 AE620070 */  sw        $v0, 0x70($s3)
.L80241744:
/* A657D4 80241744 8FBF0040 */  lw        $ra, 0x40($sp)
/* A657D8 80241748 8FB3003C */  lw        $s3, 0x3c($sp)
/* A657DC 8024174C 8FB20038 */  lw        $s2, 0x38($sp)
/* A657E0 80241750 8FB10034 */  lw        $s1, 0x34($sp)
/* A657E4 80241754 8FB00030 */  lw        $s0, 0x30($sp)
/* A657E8 80241758 03E00008 */  jr        $ra
/* A657EC 8024175C 27BD0048 */   addiu    $sp, $sp, 0x48

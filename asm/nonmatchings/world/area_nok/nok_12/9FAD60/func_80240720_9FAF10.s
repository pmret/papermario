.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240720_9FAF10
/* 9FAF10 80240720 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9FAF14 80240724 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9FAF18 80240728 0080982D */  daddu     $s3, $a0, $zero
/* 9FAF1C 8024072C AFBF0040 */  sw        $ra, 0x40($sp)
/* 9FAF20 80240730 AFB20038 */  sw        $s2, 0x38($sp)
/* 9FAF24 80240734 AFB10034 */  sw        $s1, 0x34($sp)
/* 9FAF28 80240738 AFB00030 */  sw        $s0, 0x30($sp)
/* 9FAF2C 8024073C 8E710148 */  lw        $s1, 0x148($s3)
/* 9FAF30 80240740 0C00EABB */  jal       get_npc_unsafe
/* 9FAF34 80240744 86240008 */   lh       $a0, 8($s1)
/* 9FAF38 80240748 0040802D */  daddu     $s0, $v0, $zero
/* 9FAF3C 8024074C 8E22007C */  lw        $v0, 0x7c($s1)
/* 9FAF40 80240750 8603008E */  lh        $v1, 0x8e($s0)
/* 9FAF44 80240754 2442FFFF */  addiu     $v0, $v0, -1
/* 9FAF48 80240758 14620012 */  bne       $v1, $v0, .L802407A4
/* 9FAF4C 8024075C 00000000 */   nop      
/* 9FAF50 80240760 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9FAF54 80240764 4600020D */  trunc.w.s $f8, $f0
/* 9FAF58 80240768 44024000 */  mfc1      $v0, $f8
/* 9FAF5C 8024076C 00000000 */  nop       
/* 9FAF60 80240770 A6220010 */  sh        $v0, 0x10($s1)
/* 9FAF64 80240774 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9FAF68 80240778 4600020D */  trunc.w.s $f8, $f0
/* 9FAF6C 8024077C 44024000 */  mfc1      $v0, $f8
/* 9FAF70 80240780 00000000 */  nop       
/* 9FAF74 80240784 A6220012 */  sh        $v0, 0x12($s1)
/* 9FAF78 80240788 C6000040 */  lwc1      $f0, 0x40($s0)
/* 9FAF7C 8024078C 24020001 */  addiu     $v0, $zero, 1
/* 9FAF80 80240790 A2220007 */  sb        $v0, 7($s1)
/* 9FAF84 80240794 4600020D */  trunc.w.s $f8, $f0
/* 9FAF88 80240798 44024000 */  mfc1      $v0, $f8
/* 9FAF8C 8024079C 00000000 */  nop       
/* 9FAF90 802407A0 A6220014 */  sh        $v0, 0x14($s1)
.L802407A4:
/* 9FAF94 802407A4 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9FAF98 802407A8 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9FAF9C 802407AC C6040040 */  lwc1      $f4, 0x40($s0)
/* 9FAFA0 802407B0 C6060018 */  lwc1      $f6, 0x18($s0)
/* 9FAFA4 802407B4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 9FAFA8 802407B8 E7A20024 */  swc1      $f2, 0x24($sp)
/* 9FAFAC 802407BC E7A40028 */  swc1      $f4, 0x28($sp)
/* 9FAFB0 802407C0 E7A60010 */  swc1      $f6, 0x10($sp)
/* 9FAFB4 802407C4 C600000C */  lwc1      $f0, 0xc($s0)
/* 9FAFB8 802407C8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 9FAFBC 802407CC 860200A8 */  lh        $v0, 0xa8($s0)
/* 9FAFC0 802407D0 27A50020 */  addiu     $a1, $sp, 0x20
/* 9FAFC4 802407D4 44820000 */  mtc1      $v0, $f0
/* 9FAFC8 802407D8 00000000 */  nop       
/* 9FAFCC 802407DC 46800020 */  cvt.s.w   $f0, $f0
/* 9FAFD0 802407E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9FAFD4 802407E4 860200A6 */  lh        $v0, 0xa6($s0)
/* 9FAFD8 802407E8 27A60024 */  addiu     $a2, $sp, 0x24
/* 9FAFDC 802407EC 44820000 */  mtc1      $v0, $f0
/* 9FAFE0 802407F0 00000000 */  nop       
/* 9FAFE4 802407F4 46800020 */  cvt.s.w   $f0, $f0
/* 9FAFE8 802407F8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 9FAFEC 802407FC 8E040080 */  lw        $a0, 0x80($s0)
/* 9FAFF0 80240800 0C037711 */  jal       func_800DDC44
/* 9FAFF4 80240804 27A70028 */   addiu    $a3, $sp, 0x28
/* 9FAFF8 80240808 0040902D */  daddu     $s2, $v0, $zero
/* 9FAFFC 8024080C 16400005 */  bnez      $s2, .L80240824
/* 9FB000 80240810 00000000 */   nop      
/* 9FB004 80240814 8E050018 */  lw        $a1, 0x18($s0)
/* 9FB008 80240818 8E06000C */  lw        $a2, 0xc($s0)
/* 9FB00C 8024081C 0C00EA95 */  jal       npc_move_heading
/* 9FB010 80240820 0200202D */   daddu    $a0, $s0, $zero
.L80240824:
/* 9FB014 80240824 8602008E */  lh        $v0, 0x8e($s0)
/* 9FB018 80240828 9603008E */  lhu       $v1, 0x8e($s0)
/* 9FB01C 8024082C 18400007 */  blez      $v0, .L8024084C
/* 9FB020 80240830 2462FFFF */   addiu    $v0, $v1, -1
/* 9FB024 80240834 A602008E */  sh        $v0, 0x8e($s0)
/* 9FB028 80240838 00021400 */  sll       $v0, $v0, 0x10
/* 9FB02C 8024083C 18400003 */  blez      $v0, .L8024084C
/* 9FB030 80240840 00000000 */   nop      
/* 9FB034 80240844 12400008 */  beqz      $s2, .L80240868
/* 9FB038 80240848 00000000 */   nop      
.L8024084C:
/* 9FB03C 8024084C 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9FB040 80240850 A2200007 */  sb        $zero, 7($s1)
/* 9FB044 80240854 8C420028 */  lw        $v0, 0x28($v0)
/* 9FB048 80240858 A600008E */  sh        $zero, 0x8e($s0)
/* 9FB04C 8024085C AE020028 */  sw        $v0, 0x28($s0)
/* 9FB050 80240860 2402000F */  addiu     $v0, $zero, 0xf
/* 9FB054 80240864 AE620070 */  sw        $v0, 0x70($s3)
.L80240868:
/* 9FB058 80240868 8FBF0040 */  lw        $ra, 0x40($sp)
/* 9FB05C 8024086C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9FB060 80240870 8FB20038 */  lw        $s2, 0x38($sp)
/* 9FB064 80240874 8FB10034 */  lw        $s1, 0x34($sp)
/* 9FB068 80240878 8FB00030 */  lw        $s0, 0x30($sp)
/* 9FB06C 8024087C 03E00008 */  jr        $ra
/* 9FB070 80240880 27BD0048 */   addiu    $sp, $sp, 0x48

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RunPartTo
/* 1A958C 8027ACAC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 1A9590 8027ACB0 AFB40028 */  sw        $s4, 0x28($sp)
/* 1A9594 8027ACB4 0080A02D */  daddu     $s4, $a0, $zero
/* 1A9598 8027ACB8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 1A959C 8027ACBC AFB30024 */  sw        $s3, 0x24($sp)
/* 1A95A0 8027ACC0 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A95A4 8027ACC4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A95A8 8027ACC8 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A95AC 8027ACCC F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 1A95B0 8027ACD0 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 1A95B4 8027ACD4 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 1A95B8 8027ACD8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 1A95BC 8027ACDC 8E91000C */  lw        $s1, 0xc($s4)
/* 1A95C0 8027ACE0 54A00001 */  bnel      $a1, $zero, .L8027ACE8
/* 1A95C4 8027ACE4 AE800070 */   sw       $zero, 0x70($s4)
.L8027ACE8:
/* 1A95C8 8027ACE8 8E820070 */  lw        $v0, 0x70($s4)
/* 1A95CC 8027ACEC 1440006F */  bnez      $v0, .L8027AEAC
/* 1A95D0 8027ACF0 00000000 */   nop
/* 1A95D4 8027ACF4 8E250000 */  lw        $a1, ($s1)
/* 1A95D8 8027ACF8 26310004 */  addiu     $s1, $s1, 4
/* 1A95DC 8027ACFC 0C0B1EAF */  jal       get_variable
/* 1A95E0 8027AD00 0280202D */   daddu    $a0, $s4, $zero
/* 1A95E4 8027AD04 0040802D */  daddu     $s0, $v0, $zero
/* 1A95E8 8027AD08 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1A95EC 8027AD0C 16020002 */  bne       $s0, $v0, .L8027AD18
/* 1A95F0 8027AD10 00000000 */   nop
/* 1A95F4 8027AD14 8E900148 */  lw        $s0, 0x148($s4)
.L8027AD18:
/* 1A95F8 8027AD18 8E250000 */  lw        $a1, ($s1)
/* 1A95FC 8027AD1C 26310004 */  addiu     $s1, $s1, 4
/* 1A9600 8027AD20 0C0B1EAF */  jal       get_variable
/* 1A9604 8027AD24 0280202D */   daddu    $a0, $s4, $zero
/* 1A9608 8027AD28 0200202D */  daddu     $a0, $s0, $zero
/* 1A960C 8027AD2C 0C09A75B */  jal       get_actor
/* 1A9610 8027AD30 0040802D */   daddu    $s0, $v0, $zero
/* 1A9614 8027AD34 0040982D */  daddu     $s3, $v0, $zero
/* 1A9618 8027AD38 0260202D */  daddu     $a0, $s3, $zero
/* 1A961C 8027AD3C 0C099117 */  jal       get_actor_part
/* 1A9620 8027AD40 0200282D */   daddu    $a1, $s0, $zero
/* 1A9624 8027AD44 0040902D */  daddu     $s2, $v0, $zero
/* 1A9628 8027AD48 AE930074 */  sw        $s3, 0x74($s4)
/* 1A962C 8027AD4C AE920078 */  sw        $s2, 0x78($s4)
/* 1A9630 8027AD50 8E250000 */  lw        $a1, ($s1)
/* 1A9634 8027AD54 26310004 */  addiu     $s1, $s1, 4
/* 1A9638 8027AD58 8E500010 */  lw        $s0, 0x10($s2)
/* 1A963C 8027AD5C 0C0B1EAF */  jal       get_variable
/* 1A9640 8027AD60 0280202D */   daddu    $a0, $s4, $zero
/* 1A9644 8027AD64 4482D000 */  mtc1      $v0, $f26
/* 1A9648 8027AD68 00000000 */  nop
/* 1A964C 8027AD6C 4680D6A0 */  cvt.s.w   $f26, $f26
/* 1A9650 8027AD70 8E250000 */  lw        $a1, ($s1)
/* 1A9654 8027AD74 26310004 */  addiu     $s1, $s1, 4
/* 1A9658 8027AD78 0C0B1EAF */  jal       get_variable
/* 1A965C 8027AD7C 0280202D */   daddu    $a0, $s4, $zero
/* 1A9660 8027AD80 8E250000 */  lw        $a1, ($s1)
/* 1A9664 8027AD84 26310004 */  addiu     $s1, $s1, 4
/* 1A9668 8027AD88 4482A000 */  mtc1      $v0, $f20
/* 1A966C 8027AD8C 00000000 */  nop
/* 1A9670 8027AD90 4680A520 */  cvt.s.w   $f20, $f20
/* 1A9674 8027AD94 0C0B1EAF */  jal       get_variable
/* 1A9678 8027AD98 0280202D */   daddu    $a0, $s4, $zero
/* 1A967C 8027AD9C 44820000 */  mtc1      $v0, $f0
/* 1A9680 8027ADA0 00000000 */  nop
/* 1A9684 8027ADA4 46800020 */  cvt.s.w   $f0, $f0
/* 1A9688 8027ADA8 E61A000C */  swc1      $f26, 0xc($s0)
/* 1A968C 8027ADAC E6140010 */  swc1      $f20, 0x10($s0)
/* 1A9690 8027ADB0 E6000014 */  swc1      $f0, 0x14($s0)
/* 1A9694 8027ADB4 8E250000 */  lw        $a1, ($s1)
/* 1A9698 8027ADB8 0C0B1EAF */  jal       get_variable
/* 1A969C 8027ADBC 0280202D */   daddu    $a0, $s4, $zero
/* 1A96A0 8027ADC0 A6020038 */  sh        $v0, 0x38($s0)
/* 1A96A4 8027ADC4 C640002C */  lwc1      $f0, 0x2c($s2)
/* 1A96A8 8027ADC8 C616000C */  lwc1      $f22, 0xc($s0)
/* 1A96AC 8027ADCC C6180014 */  lwc1      $f24, 0x14($s0)
/* 1A96B0 8027ADD0 E6000000 */  swc1      $f0, ($s0)
/* 1A96B4 8027ADD4 46000686 */  mov.s     $f26, $f0
/* 1A96B8 8027ADD8 4406B000 */  mfc1      $a2, $f22
/* 1A96BC 8027ADDC C6400030 */  lwc1      $f0, 0x30($s2)
/* 1A96C0 8027ADE0 4600D306 */  mov.s     $f12, $f26
/* 1A96C4 8027ADE4 E6000004 */  swc1      $f0, 4($s0)
/* 1A96C8 8027ADE8 C6540034 */  lwc1      $f20, 0x34($s2)
/* 1A96CC 8027ADEC 4407C000 */  mfc1      $a3, $f24
/* 1A96D0 8027ADF0 4600A386 */  mov.s     $f14, $f20
/* 1A96D4 8027ADF4 0C00A720 */  jal       atan2
/* 1A96D8 8027ADF8 E6140008 */   swc1     $f20, 8($s0)
/* 1A96DC 8027ADFC 4600D306 */  mov.s     $f12, $f26
/* 1A96E0 8027AE00 4406B000 */  mfc1      $a2, $f22
/* 1A96E4 8027AE04 4407C000 */  mfc1      $a3, $f24
/* 1A96E8 8027AE08 4600A386 */  mov.s     $f14, $f20
/* 1A96EC 8027AE0C 0C00A7B5 */  jal       dist2D
/* 1A96F0 8027AE10 E6000030 */   swc1     $f0, 0x30($s0)
/* 1A96F4 8027AE14 86020038 */  lh        $v0, 0x38($s0)
/* 1A96F8 8027AE18 46000086 */  mov.s     $f2, $f0
/* 1A96FC 8027AE1C 14400007 */  bnez      $v0, .L8027AE3C
/* 1A9700 8027AE20 E6020034 */   swc1     $f2, 0x34($s0)
/* 1A9704 8027AE24 C6000028 */  lwc1      $f0, 0x28($s0)
/* 1A9708 8027AE28 46001003 */  div.s     $f0, $f2, $f0
/* 1A970C 8027AE2C 4600010D */  trunc.w.s $f4, $f0
/* 1A9710 8027AE30 44022000 */  mfc1      $v0, $f4
/* 1A9714 8027AE34 0809EB94 */  j         .L8027AE50
/* 1A9718 8027AE38 A6020038 */   sh       $v0, 0x38($s0)
.L8027AE3C:
/* 1A971C 8027AE3C 44820000 */  mtc1      $v0, $f0
/* 1A9720 8027AE40 00000000 */  nop
/* 1A9724 8027AE44 46800020 */  cvt.s.w   $f0, $f0
/* 1A9728 8027AE48 46001003 */  div.s     $f0, $f2, $f0
/* 1A972C 8027AE4C E6000028 */  swc1      $f0, 0x28($s0)
.L8027AE50:
/* 1A9730 8027AE50 864200BC */  lh        $v0, 0xbc($s2)
/* 1A9734 8027AE54 04420002 */  bltzl     $v0, .L8027AE60
/* 1A9738 8027AE58 00021027 */   nor      $v0, $zero, $v0
/* 1A973C 8027AE5C 24420001 */  addiu     $v0, $v0, 1
.L8027AE60:
/* 1A9740 8027AE60 44820000 */  mtc1      $v0, $f0
/* 1A9744 8027AE64 00000000 */  nop
/* 1A9748 8027AE68 46800020 */  cvt.s.w   $f0, $f0
/* 1A974C 8027AE6C E6000034 */  swc1      $f0, 0x34($s0)
/* 1A9750 8027AE70 8E4200A4 */  lw        $v0, 0xa4($s2)
/* 1A9754 8027AE74 1040000C */  beqz      $v0, .L8027AEA8
/* 1A9758 8027AE78 24020001 */   addiu    $v0, $zero, 1
/* 1A975C 8027AE7C 8E4200A8 */  lw        $v0, 0xa8($s2)
/* 1A9760 8027AE80 14400009 */  bnez      $v0, .L8027AEA8
/* 1A9764 8027AE84 24020001 */   addiu    $v0, $zero, 1
/* 1A9768 8027AE88 C6400034 */  lwc1      $f0, 0x34($s2)
/* 1A976C 8027AE8C E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A9770 8027AE90 8E4400A4 */  lw        $a0, 0xa4($s2)
/* 1A9774 8027AE94 8E46002C */  lw        $a2, 0x2c($s2)
/* 1A9778 8027AE98 8E470030 */  lw        $a3, 0x30($s2)
/* 1A977C 8027AE9C 0C052757 */  jal       sfx_play_sound_at_position
/* 1A9780 8027AEA0 0000282D */   daddu    $a1, $zero, $zero
/* 1A9784 8027AEA4 24020001 */  addiu     $v0, $zero, 1
.L8027AEA8:
/* 1A9788 8027AEA8 AE820070 */  sw        $v0, 0x70($s4)
.L8027AEAC:
/* 1A978C 8027AEAC 8E920078 */  lw        $s2, 0x78($s4)
/* 1A9790 8027AEB0 8E500010 */  lw        $s0, 0x10($s2)
/* 1A9794 8027AEB4 8E930074 */  lw        $s3, 0x74($s4)
/* 1A9798 8027AEB8 8E050028 */  lw        $a1, 0x28($s0)
/* 1A979C 8027AEBC 8E060030 */  lw        $a2, 0x30($s0)
/* 1A97A0 8027AEC0 0C099070 */  jal       add_xz_vec3f_copy1
/* 1A97A4 8027AEC4 0200202D */   daddu    $a0, $s0, $zero
/* 1A97A8 8027AEC8 C6020028 */  lwc1      $f2, 0x28($s0)
/* 1A97AC 8027AECC 3C014080 */  lui       $at, 0x4080
/* 1A97B0 8027AED0 44810000 */  mtc1      $at, $f0
/* 1A97B4 8027AED4 00000000 */  nop
/* 1A97B8 8027AED8 4600103C */  c.lt.s    $f2, $f0
/* 1A97BC 8027AEDC 00000000 */  nop
/* 1A97C0 8027AEE0 45000007 */  bc1f      .L8027AF00
/* 1A97C4 8027AEE4 0000202D */   daddu    $a0, $zero, $zero
/* 1A97C8 8027AEE8 C6000030 */  lwc1      $f0, 0x30($s0)
/* 1A97CC 8027AEEC E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A97D0 8027AEF0 8E050000 */  lw        $a1, ($s0)
/* 1A97D4 8027AEF4 8E060004 */  lw        $a2, 4($s0)
/* 1A97D8 8027AEF8 0809EBC6 */  j         .L8027AF18
/* 1A97DC 8027AEFC 8E070008 */   lw       $a3, 8($s0)
.L8027AF00:
/* 1A97E0 8027AF00 C6000030 */  lwc1      $f0, 0x30($s0)
/* 1A97E4 8027AF04 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A97E8 8027AF08 8E050000 */  lw        $a1, ($s0)
/* 1A97EC 8027AF0C 8E060004 */  lw        $a2, 4($s0)
/* 1A97F0 8027AF10 8E070008 */  lw        $a3, 8($s0)
/* 1A97F4 8027AF14 24040001 */  addiu     $a0, $zero, 1
.L8027AF18:
/* 1A97F8 8027AF18 0C0990BC */  jal       play_movement_dust_effects
/* 1A97FC 8027AF1C 00000000 */   nop
/* 1A9800 8027AF20 C6000000 */  lwc1      $f0, ($s0)
/* 1A9804 8027AF24 8E4200A4 */  lw        $v0, 0xa4($s2)
/* 1A9808 8027AF28 E640002C */  swc1      $f0, 0x2c($s2)
/* 1A980C 8027AF2C C6000004 */  lwc1      $f0, 4($s0)
/* 1A9810 8027AF30 E6400030 */  swc1      $f0, 0x30($s2)
/* 1A9814 8027AF34 C6000008 */  lwc1      $f0, 8($s0)
/* 1A9818 8027AF38 1040004A */  beqz      $v0, .L8027B064
/* 1A981C 8027AF3C E6400034 */   swc1     $f0, 0x34($s2)
/* 1A9820 8027AF40 8E4200A8 */  lw        $v0, 0xa8($s2)
/* 1A9824 8027AF44 10400047 */  beqz      $v0, .L8027B064
/* 1A9828 8027AF48 00000000 */   nop
/* 1A982C 8027AF4C 864200BC */  lh        $v0, 0xbc($s2)
/* 1A9830 8027AF50 0440001C */  bltz      $v0, .L8027AFC4
/* 1A9834 8027AF54 00000000 */   nop
/* 1A9838 8027AF58 C6020034 */  lwc1      $f2, 0x34($s0)
/* 1A983C 8027AF5C C6000028 */  lwc1      $f0, 0x28($s0)
/* 1A9840 8027AF60 46001080 */  add.s     $f2, $f2, $f0
/* 1A9844 8027AF64 E6020034 */  swc1      $f2, 0x34($s0)
/* 1A9848 8027AF68 864200BC */  lh        $v0, 0xbc($s2)
/* 1A984C 8027AF6C 44820000 */  mtc1      $v0, $f0
/* 1A9850 8027AF70 00000000 */  nop
/* 1A9854 8027AF74 46800020 */  cvt.s.w   $f0, $f0
/* 1A9858 8027AF78 4602003C */  c.lt.s    $f0, $f2
/* 1A985C 8027AF7C 00000000 */  nop
/* 1A9860 8027AF80 45000038 */  bc1f      .L8027B064
/* 1A9864 8027AF84 00000000 */   nop
/* 1A9868 8027AF88 92620135 */  lbu       $v0, 0x135($s3)
/* 1A986C 8027AF8C 24420001 */  addiu     $v0, $v0, 1
/* 1A9870 8027AF90 A2620135 */  sb        $v0, 0x135($s3)
/* 1A9874 8027AF94 AE000034 */  sw        $zero, 0x34($s0)
/* 1A9878 8027AF98 92620135 */  lbu       $v0, 0x135($s3)
/* 1A987C 8027AF9C 30420001 */  andi      $v0, $v0, 1
/* 1A9880 8027AFA0 10400026 */  beqz      $v0, .L8027B03C
/* 1A9884 8027AFA4 00000000 */   nop
/* 1A9888 8027AFA8 8E4200A4 */  lw        $v0, 0xa4($s2)
/* 1A988C 8027AFAC 1040002D */  beqz      $v0, .L8027B064
/* 1A9890 8027AFB0 00000000 */   nop
/* 1A9894 8027AFB4 C6400034 */  lwc1      $f0, 0x34($s2)
/* 1A9898 8027AFB8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A989C 8027AFBC 0809EC15 */  j         .L8027B054
/* 1A98A0 8027AFC0 8E4400A4 */   lw       $a0, 0xa4($s2)
.L8027AFC4:
/* 1A98A4 8027AFC4 C6020034 */  lwc1      $f2, 0x34($s0)
/* 1A98A8 8027AFC8 3C013F80 */  lui       $at, 0x3f80
/* 1A98AC 8027AFCC 44810000 */  mtc1      $at, $f0
/* 1A98B0 8027AFD0 00000000 */  nop
/* 1A98B4 8027AFD4 46001080 */  add.s     $f2, $f2, $f0
/* 1A98B8 8027AFD8 E6020034 */  swc1      $f2, 0x34($s0)
/* 1A98BC 8027AFDC 864200BC */  lh        $v0, 0xbc($s2)
/* 1A98C0 8027AFE0 00021023 */  negu      $v0, $v0
/* 1A98C4 8027AFE4 44820000 */  mtc1      $v0, $f0
/* 1A98C8 8027AFE8 00000000 */  nop
/* 1A98CC 8027AFEC 46800020 */  cvt.s.w   $f0, $f0
/* 1A98D0 8027AFF0 4602003E */  c.le.s    $f0, $f2
/* 1A98D4 8027AFF4 00000000 */  nop
/* 1A98D8 8027AFF8 4500001A */  bc1f      .L8027B064
/* 1A98DC 8027AFFC 00000000 */   nop
/* 1A98E0 8027B000 92620135 */  lbu       $v0, 0x135($s3)
/* 1A98E4 8027B004 24420001 */  addiu     $v0, $v0, 1
/* 1A98E8 8027B008 A2620135 */  sb        $v0, 0x135($s3)
/* 1A98EC 8027B00C AE000034 */  sw        $zero, 0x34($s0)
/* 1A98F0 8027B010 92620135 */  lbu       $v0, 0x135($s3)
/* 1A98F4 8027B014 30420001 */  andi      $v0, $v0, 1
/* 1A98F8 8027B018 10400008 */  beqz      $v0, .L8027B03C
/* 1A98FC 8027B01C 00000000 */   nop
/* 1A9900 8027B020 8E4200A4 */  lw        $v0, 0xa4($s2)
/* 1A9904 8027B024 1040000F */  beqz      $v0, .L8027B064
/* 1A9908 8027B028 00000000 */   nop
/* 1A990C 8027B02C C6400034 */  lwc1      $f0, 0x34($s2)
/* 1A9910 8027B030 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A9914 8027B034 0809EC15 */  j         .L8027B054
/* 1A9918 8027B038 8E4400A4 */   lw       $a0, 0xa4($s2)
.L8027B03C:
/* 1A991C 8027B03C 8E4200A8 */  lw        $v0, 0xa8($s2)
/* 1A9920 8027B040 10400008 */  beqz      $v0, .L8027B064
/* 1A9924 8027B044 00000000 */   nop
/* 1A9928 8027B048 C6400034 */  lwc1      $f0, 0x34($s2)
/* 1A992C 8027B04C E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A9930 8027B050 8E4400A8 */  lw        $a0, 0xa8($s2)
.L8027B054:
/* 1A9934 8027B054 8E46002C */  lw        $a2, 0x2c($s2)
/* 1A9938 8027B058 8E470030 */  lw        $a3, 0x30($s2)
/* 1A993C 8027B05C 0C052757 */  jal       sfx_play_sound_at_position
/* 1A9940 8027B060 0000282D */   daddu    $a1, $zero, $zero
.L8027B064:
/* 1A9944 8027B064 96020038 */  lhu       $v0, 0x38($s0)
/* 1A9948 8027B068 2442FFFF */  addiu     $v0, $v0, -1
/* 1A994C 8027B06C A6020038 */  sh        $v0, 0x38($s0)
/* 1A9950 8027B070 00021400 */  sll       $v0, $v0, 0x10
/* 1A9954 8027B074 1C40000D */  bgtz      $v0, .L8027B0AC
/* 1A9958 8027B078 0000102D */   daddu    $v0, $zero, $zero
/* 1A995C 8027B07C C600000C */  lwc1      $f0, 0xc($s0)
/* 1A9960 8027B080 8E4400A4 */  lw        $a0, 0xa4($s2)
/* 1A9964 8027B084 E640002C */  swc1      $f0, 0x2c($s2)
/* 1A9968 8027B088 C6000014 */  lwc1      $f0, 0x14($s0)
/* 1A996C 8027B08C 10800006 */  beqz      $a0, .L8027B0A8
/* 1A9970 8027B090 E6400034 */   swc1     $f0, 0x34($s2)
/* 1A9974 8027B094 8E4200A8 */  lw        $v0, 0xa8($s2)
/* 1A9978 8027B098 14400004 */  bnez      $v0, .L8027B0AC
/* 1A997C 8027B09C 24020001 */   addiu    $v0, $zero, 1
/* 1A9980 8027B0A0 0C0154F0 */  jal       snd_stop_sound
/* 1A9984 8027B0A4 00000000 */   nop
.L8027B0A8:
/* 1A9988 8027B0A8 24020001 */  addiu     $v0, $zero, 1
.L8027B0AC:
/* 1A998C 8027B0AC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1A9990 8027B0B0 8FB40028 */  lw        $s4, 0x28($sp)
/* 1A9994 8027B0B4 8FB30024 */  lw        $s3, 0x24($sp)
/* 1A9998 8027B0B8 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A999C 8027B0BC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A99A0 8027B0C0 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A99A4 8027B0C4 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 1A99A8 8027B0C8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 1A99AC 8027B0CC D7B60038 */  ldc1      $f22, 0x38($sp)
/* 1A99B0 8027B0D0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 1A99B4 8027B0D4 03E00008 */  jr        $ra
/* 1A99B8 8027B0D8 27BD0050 */   addiu    $sp, $sp, 0x50

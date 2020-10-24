.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241690_9FBE80
/* 9FBE80 80241690 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9FBE84 80241694 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9FBE88 80241698 0080982D */  daddu     $s3, $a0, $zero
/* 9FBE8C 8024169C AFBF0040 */  sw        $ra, 0x40($sp)
/* 9FBE90 802416A0 AFB20038 */  sw        $s2, 0x38($sp)
/* 9FBE94 802416A4 AFB10034 */  sw        $s1, 0x34($sp)
/* 9FBE98 802416A8 AFB00030 */  sw        $s0, 0x30($sp)
/* 9FBE9C 802416AC 8E720148 */  lw        $s2, 0x148($s3)
/* 9FBEA0 802416B0 00A0882D */  daddu     $s1, $a1, $zero
/* 9FBEA4 802416B4 86440008 */  lh        $a0, 8($s2)
/* 9FBEA8 802416B8 0C00EABB */  jal       get_npc_unsafe
/* 9FBEAC 802416BC 00C0802D */   daddu    $s0, $a2, $zero
/* 9FBEB0 802416C0 0200202D */  daddu     $a0, $s0, $zero
/* 9FBEB4 802416C4 0240282D */  daddu     $a1, $s2, $zero
/* 9FBEB8 802416C8 24030001 */  addiu     $v1, $zero, 1
/* 9FBEBC 802416CC AFA30010 */  sw        $v1, 0x10($sp)
/* 9FBEC0 802416D0 8E260024 */  lw        $a2, 0x24($s1)
/* 9FBEC4 802416D4 8E270028 */  lw        $a3, 0x28($s1)
/* 9FBEC8 802416D8 0C01242D */  jal       func_800490B4
/* 9FBECC 802416DC 0040802D */   daddu    $s0, $v0, $zero
/* 9FBED0 802416E0 1440001E */  bnez      $v0, .L8024175C
/* 9FBED4 802416E4 0200202D */   daddu    $a0, $s0, $zero
/* 9FBED8 802416E8 24040002 */  addiu     $a0, $zero, 2
/* 9FBEDC 802416EC 0200282D */  daddu     $a1, $s0, $zero
/* 9FBEE0 802416F0 0000302D */  daddu     $a2, $zero, $zero
/* 9FBEE4 802416F4 860300A8 */  lh        $v1, 0xa8($s0)
/* 9FBEE8 802416F8 3C013F80 */  lui       $at, 0x3f80
/* 9FBEEC 802416FC 44810000 */  mtc1      $at, $f0
/* 9FBEF0 80241700 3C014000 */  lui       $at, 0x4000
/* 9FBEF4 80241704 44811000 */  mtc1      $at, $f2
/* 9FBEF8 80241708 3C01C1A0 */  lui       $at, 0xc1a0
/* 9FBEFC 8024170C 44812000 */  mtc1      $at, $f4
/* 9FBF00 80241710 2402000F */  addiu     $v0, $zero, 0xf
/* 9FBF04 80241714 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9FBF08 80241718 44833000 */  mtc1      $v1, $f6
/* 9FBF0C 8024171C 00000000 */  nop       
/* 9FBF10 80241720 468031A0 */  cvt.s.w   $f6, $f6
/* 9FBF14 80241724 44073000 */  mfc1      $a3, $f6
/* 9FBF18 80241728 27A20028 */  addiu     $v0, $sp, 0x28
/* 9FBF1C 8024172C AFA20020 */  sw        $v0, 0x20($sp)
/* 9FBF20 80241730 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9FBF24 80241734 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9FBF28 80241738 0C01BFA4 */  jal       fx_emote
/* 9FBF2C 8024173C E7A40018 */   swc1     $f4, 0x18($sp)
/* 9FBF30 80241740 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9FBF34 80241744 8C430000 */  lw        $v1, ($v0)
/* 9FBF38 80241748 24020019 */  addiu     $v0, $zero, 0x19
/* 9FBF3C 8024174C A602008E */  sh        $v0, 0x8e($s0)
/* 9FBF40 80241750 2402000E */  addiu     $v0, $zero, 0xe
/* 9FBF44 80241754 080905E4 */  j         .L80241790
/* 9FBF48 80241758 AE030028 */   sw       $v1, 0x28($s0)
.L8024175C:
/* 9FBF4C 8024175C 0C00F598 */  jal       func_8003D660
/* 9FBF50 80241760 24050001 */   addiu    $a1, $zero, 1
/* 9FBF54 80241764 8E050018 */  lw        $a1, 0x18($s0)
/* 9FBF58 80241768 8E06000C */  lw        $a2, 0xc($s0)
/* 9FBF5C 8024176C 0C00EA95 */  jal       npc_move_heading
/* 9FBF60 80241770 0200202D */   daddu    $a0, $s0, $zero
/* 9FBF64 80241774 8602008E */  lh        $v0, 0x8e($s0)
/* 9FBF68 80241778 9603008E */  lhu       $v1, 0x8e($s0)
/* 9FBF6C 8024177C 18400003 */  blez      $v0, .L8024178C
/* 9FBF70 80241780 2462FFFF */   addiu    $v0, $v1, -1
/* 9FBF74 80241784 080905E5 */  j         .L80241794
/* 9FBF78 80241788 A602008E */   sh       $v0, 0x8e($s0)
.L8024178C:
/* 9FBF7C 8024178C 2402000C */  addiu     $v0, $zero, 0xc
.L80241790:
/* 9FBF80 80241790 AE620070 */  sw        $v0, 0x70($s3)
.L80241794:
/* 9FBF84 80241794 8FBF0040 */  lw        $ra, 0x40($sp)
/* 9FBF88 80241798 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9FBF8C 8024179C 8FB20038 */  lw        $s2, 0x38($sp)
/* 9FBF90 802417A0 8FB10034 */  lw        $s1, 0x34($sp)
/* 9FBF94 802417A4 8FB00030 */  lw        $s0, 0x30($sp)
/* 9FBF98 802417A8 03E00008 */  jr        $ra
/* 9FBF9C 802417AC 27BD0048 */   addiu    $sp, $sp, 0x48

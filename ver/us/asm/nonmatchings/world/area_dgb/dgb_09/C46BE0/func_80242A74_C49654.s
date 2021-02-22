.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A74_C49654
/* C49654 80242A74 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C49658 80242A78 AFB30024 */  sw        $s3, 0x24($sp)
/* C4965C 80242A7C 0080982D */  daddu     $s3, $a0, $zero
/* C49660 80242A80 AFBF0028 */  sw        $ra, 0x28($sp)
/* C49664 80242A84 AFB20020 */  sw        $s2, 0x20($sp)
/* C49668 80242A88 AFB1001C */  sw        $s1, 0x1c($sp)
/* C4966C 80242A8C AFB00018 */  sw        $s0, 0x18($sp)
/* C49670 80242A90 8E700148 */  lw        $s0, 0x148($s3)
/* C49674 80242A94 00A0902D */  daddu     $s2, $a1, $zero
/* C49678 80242A98 86040008 */  lh        $a0, 8($s0)
/* C4967C 80242A9C 0C00EABB */  jal       get_npc_unsafe
/* C49680 80242AA0 00C0882D */   daddu    $s1, $a2, $zero
/* C49684 80242AA4 0220202D */  daddu     $a0, $s1, $zero
/* C49688 80242AA8 0200282D */  daddu     $a1, $s0, $zero
/* C4968C 80242AAC 24030001 */  addiu     $v1, $zero, 1
/* C49690 80242AB0 AFA30010 */  sw        $v1, 0x10($sp)
/* C49694 80242AB4 8E460024 */  lw        $a2, 0x24($s2)
/* C49698 80242AB8 8E470028 */  lw        $a3, 0x28($s2)
/* C4969C 80242ABC 0C01242D */  jal       func_800490B4
/* C496A0 80242AC0 0040802D */   daddu    $s0, $v0, $zero
/* C496A4 80242AC4 10400024 */  beqz      $v0, .L80242B58
/* C496A8 80242AC8 24020010 */   addiu    $v0, $zero, 0x10
/* C496AC 80242ACC 8E050018 */  lw        $a1, 0x18($s0)
/* C496B0 80242AD0 8E06000C */  lw        $a2, 0xc($s0)
/* C496B4 80242AD4 0C00EA95 */  jal       npc_move_heading
/* C496B8 80242AD8 0200202D */   daddu    $a0, $s0, $zero
/* C496BC 80242ADC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C496C0 80242AE0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C496C4 80242AE4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C496C8 80242AE8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C496CC 80242AEC 8C460028 */  lw        $a2, 0x28($v0)
/* C496D0 80242AF0 0C00A7B5 */  jal       dist2D
/* C496D4 80242AF4 8C470030 */   lw       $a3, 0x30($v0)
/* C496D8 80242AF8 C6020018 */  lwc1      $f2, 0x18($s0)
/* C496DC 80242AFC 3C014004 */  lui       $at, 0x4004
/* C496E0 80242B00 44812800 */  mtc1      $at, $f5
/* C496E4 80242B04 44802000 */  mtc1      $zero, $f4
/* C496E8 80242B08 460010A1 */  cvt.d.s   $f2, $f2
/* C496EC 80242B0C 46241082 */  mul.d     $f2, $f2, $f4
/* C496F0 80242B10 00000000 */  nop
/* C496F4 80242B14 46000021 */  cvt.d.s   $f0, $f0
/* C496F8 80242B18 4622003E */  c.le.d    $f0, $f2
/* C496FC 80242B1C 00000000 */  nop
/* C49700 80242B20 45000003 */  bc1f      .L80242B30
/* C49704 80242B24 2402000E */   addiu    $v0, $zero, 0xe
/* C49708 80242B28 08090AD6 */  j         .L80242B58
/* C4970C 80242B2C A600008E */   sh       $zero, 0x8e($s0)
.L80242B30:
/* C49710 80242B30 9602008E */  lhu       $v0, 0x8e($s0)
/* C49714 80242B34 2442FFFF */  addiu     $v0, $v0, -1
/* C49718 80242B38 A602008E */  sh        $v0, 0x8e($s0)
/* C4971C 80242B3C 00021400 */  sll       $v0, $v0, 0x10
/* C49720 80242B40 1C400006 */  bgtz      $v0, .L80242B5C
/* C49724 80242B44 3C030020 */   lui      $v1, 0x20
/* C49728 80242B48 8E020000 */  lw        $v0, ($s0)
/* C4972C 80242B4C 00431025 */  or        $v0, $v0, $v1
/* C49730 80242B50 AE020000 */  sw        $v0, ($s0)
/* C49734 80242B54 2402000C */  addiu     $v0, $zero, 0xc
.L80242B58:
/* C49738 80242B58 AE620070 */  sw        $v0, 0x70($s3)
.L80242B5C:
/* C4973C 80242B5C 8FBF0028 */  lw        $ra, 0x28($sp)
/* C49740 80242B60 8FB30024 */  lw        $s3, 0x24($sp)
/* C49744 80242B64 8FB20020 */  lw        $s2, 0x20($sp)
/* C49748 80242B68 8FB1001C */  lw        $s1, 0x1c($sp)
/* C4974C 80242B6C 8FB00018 */  lw        $s0, 0x18($sp)
/* C49750 80242B70 03E00008 */  jr        $ra
/* C49754 80242B74 27BD0030 */   addiu    $sp, $sp, 0x30

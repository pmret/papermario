.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408D8
/* CF34A8 802408D8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* CF34AC 802408DC AFB3004C */  sw        $s3, 0x4c($sp)
/* CF34B0 802408E0 0080982D */  daddu     $s3, $a0, $zero
/* CF34B4 802408E4 AFBF0054 */  sw        $ra, 0x54($sp)
/* CF34B8 802408E8 AFB40050 */  sw        $s4, 0x50($sp)
/* CF34BC 802408EC AFB20048 */  sw        $s2, 0x48($sp)
/* CF34C0 802408F0 AFB10044 */  sw        $s1, 0x44($sp)
/* CF34C4 802408F4 AFB00040 */  sw        $s0, 0x40($sp)
/* CF34C8 802408F8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* CF34CC 802408FC F7B80068 */  sdc1      $f24, 0x68($sp)
/* CF34D0 80240900 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CF34D4 80240904 F7B40058 */  sdc1      $f20, 0x58($sp)
/* CF34D8 80240908 8E710148 */  lw        $s1, 0x148($s3)
/* CF34DC 8024090C 00A0902D */  daddu     $s2, $a1, $zero
/* CF34E0 80240910 86240008 */  lh        $a0, 8($s1)
/* CF34E4 80240914 0C00EABB */  jal       get_npc_unsafe
/* CF34E8 80240918 00C0A02D */   daddu    $s4, $a2, $zero
/* CF34EC 8024091C 0040802D */  daddu     $s0, $v0, $zero
/* CF34F0 80240920 C6200078 */  lwc1      $f0, 0x78($s1)
/* CF34F4 80240924 46800020 */  cvt.s.w   $f0, $f0
/* CF34F8 80240928 46000021 */  cvt.d.s   $f0, $f0
/* CF34FC 8024092C 3C014059 */  lui       $at, 0x4059
/* CF3500 80240930 44811800 */  mtc1      $at, $f3
/* CF3504 80240934 44801000 */  mtc1      $zero, $f2
/* CF3508 80240938 8602008E */  lh        $v0, 0x8e($s0)
/* CF350C 8024093C 9603008E */  lhu       $v1, 0x8e($s0)
/* CF3510 80240940 46220003 */  div.d     $f0, $f0, $f2
/* CF3514 80240944 46200620 */  cvt.s.d   $f24, $f0
/* CF3518 80240948 C6200088 */  lwc1      $f0, 0x88($s1)
/* CF351C 8024094C 46800020 */  cvt.s.w   $f0, $f0
/* CF3520 80240950 46000021 */  cvt.d.s   $f0, $f0
/* CF3524 80240954 46220003 */  div.d     $f0, $f0, $f2
/* CF3528 80240958 46200020 */  cvt.s.d   $f0, $f0
/* CF352C 8024095C 18400003 */  blez      $v0, .L8024096C
/* CF3530 80240960 4600C680 */   add.s    $f26, $f24, $f0
/* CF3534 80240964 2462FFFF */  addiu     $v0, $v1, -1
/* CF3538 80240968 A602008E */  sh        $v0, 0x8e($s0)
.L8024096C:
/* CF353C 8024096C 8E220070 */  lw        $v0, 0x70($s1)
/* CF3540 80240970 18400034 */  blez      $v0, .L80240A44
/* CF3544 80240974 00000000 */   nop      
/* CF3548 80240978 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CF354C 8024097C 46806320 */  cvt.s.w   $f12, $f12
/* CF3550 80240980 44820000 */  mtc1      $v0, $f0
/* CF3554 80240984 00000000 */  nop       
/* CF3558 80240988 46800020 */  cvt.s.w   $f0, $f0
/* CF355C 8024098C 46000021 */  cvt.d.s   $f0, $f0
/* CF3560 80240990 46220003 */  div.d     $f0, $f0, $f2
/* CF3564 80240994 0C00A8BB */  jal       sin_deg
/* CF3568 80240998 462005A0 */   cvt.s.d  $f22, $f0
/* CF356C 8024099C 8E020000 */  lw        $v0, ($s0)
/* CF3570 802409A0 30420008 */  andi      $v0, $v0, 8
/* CF3574 802409A4 10400003 */  beqz      $v0, .L802409B4
/* CF3578 802409A8 46000506 */   mov.s    $f20, $f0
/* CF357C 802409AC 0809027D */  j         .L802409F4
/* CF3580 802409B0 0000102D */   daddu    $v0, $zero, $zero
.L802409B4:
/* CF3584 802409B4 27A50028 */  addiu     $a1, $sp, 0x28
/* CF3588 802409B8 27A6002C */  addiu     $a2, $sp, 0x2c
/* CF358C 802409BC C6000038 */  lwc1      $f0, 0x38($s0)
/* CF3590 802409C0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CF3594 802409C4 C6040040 */  lwc1      $f4, 0x40($s0)
/* CF3598 802409C8 3C01447A */  lui       $at, 0x447a
/* CF359C 802409CC 44813000 */  mtc1      $at, $f6
/* CF35A0 802409D0 27A20034 */  addiu     $v0, $sp, 0x34
/* CF35A4 802409D4 E7A00028 */  swc1      $f0, 0x28($sp)
/* CF35A8 802409D8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CF35AC 802409DC E7A40030 */  swc1      $f4, 0x30($sp)
/* CF35B0 802409E0 E7A60034 */  swc1      $f6, 0x34($sp)
/* CF35B4 802409E4 AFA20010 */  sw        $v0, 0x10($sp)
/* CF35B8 802409E8 8E040080 */  lw        $a0, 0x80($s0)
/* CF35BC 802409EC 0C0372DF */  jal       func_800DCB7C
/* CF35C0 802409F0 27A70030 */   addiu    $a3, $sp, 0x30
.L802409F4:
/* CF35C4 802409F4 10400007 */  beqz      $v0, .L80240A14
/* CF35C8 802409F8 00000000 */   nop      
/* CF35CC 802409FC 4616A082 */  mul.s     $f2, $f20, $f22
/* CF35D0 80240A00 00000000 */  nop       
/* CF35D4 80240A04 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CF35D8 80240A08 46180000 */  add.s     $f0, $f0, $f24
/* CF35DC 80240A0C 08090288 */  j         .L80240A20
/* CF35E0 80240A10 46020000 */   add.s    $f0, $f0, $f2
.L80240A14:
/* CF35E4 80240A14 4616A002 */  mul.s     $f0, $f20, $f22
/* CF35E8 80240A18 00000000 */  nop       
/* CF35EC 80240A1C 4600D000 */  add.s     $f0, $f26, $f0
.L80240A20:
/* CF35F0 80240A20 E600003C */  swc1      $f0, 0x3c($s0)
/* CF35F4 80240A24 8E220074 */  lw        $v0, 0x74($s1)
/* CF35F8 80240A28 2442000A */  addiu     $v0, $v0, 0xa
/* CF35FC 80240A2C 44826000 */  mtc1      $v0, $f12
/* CF3600 80240A30 00000000 */  nop       
/* CF3604 80240A34 0C00A6C9 */  jal       clamp_angle
/* CF3608 80240A38 46806320 */   cvt.s.w  $f12, $f12
/* CF360C 80240A3C 4600020D */  trunc.w.s $f8, $f0
/* CF3610 80240A40 E6280074 */  swc1      $f8, 0x74($s1)
.L80240A44:
/* CF3614 80240A44 8E220090 */  lw        $v0, 0x90($s1)
/* CF3618 80240A48 1C400040 */  bgtz      $v0, .L80240B4C
/* CF361C 80240A4C 2442FFFF */   addiu    $v0, $v0, -1
/* CF3620 80240A50 860200A8 */  lh        $v0, 0xa8($s0)
/* CF3624 80240A54 C600003C */  lwc1      $f0, 0x3c($s0)
/* CF3628 80240A58 44821000 */  mtc1      $v0, $f2
/* CF362C 80240A5C 00000000 */  nop       
/* CF3630 80240A60 468010A0 */  cvt.s.w   $f2, $f2
/* CF3634 80240A64 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CF3638 80240A68 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CF363C 80240A6C 46020000 */  add.s     $f0, $f0, $f2
/* CF3640 80240A70 3C014024 */  lui       $at, 0x4024
/* CF3644 80240A74 44812800 */  mtc1      $at, $f5
/* CF3648 80240A78 44802000 */  mtc1      $zero, $f4
/* CF364C 80240A7C C442002C */  lwc1      $f2, 0x2c($v0)
/* CF3650 80240A80 46000021 */  cvt.d.s   $f0, $f0
/* CF3654 80240A84 46240000 */  add.d     $f0, $f0, $f4
/* CF3658 80240A88 460010A1 */  cvt.d.s   $f2, $f2
/* CF365C 80240A8C 4620103C */  c.lt.d    $f2, $f0
/* CF3660 80240A90 00000000 */  nop       
/* CF3664 80240A94 4500002E */  bc1f      .L80240B50
/* CF3668 80240A98 0280202D */   daddu    $a0, $s4, $zero
/* CF366C 80240A9C 24020001 */  addiu     $v0, $zero, 1
/* CF3670 80240AA0 AFA20010 */  sw        $v0, 0x10($sp)
/* CF3674 80240AA4 8E460024 */  lw        $a2, 0x24($s2)
/* CF3678 80240AA8 8E470028 */  lw        $a3, 0x28($s2)
/* CF367C 80240AAC 0C01242D */  jal       func_800490B4
/* CF3680 80240AB0 0220282D */   daddu    $a1, $s1, $zero
/* CF3684 80240AB4 10400026 */  beqz      $v0, .L80240B50
/* CF3688 80240AB8 0000202D */   daddu    $a0, $zero, $zero
/* CF368C 80240ABC 0200282D */  daddu     $a1, $s0, $zero
/* CF3690 80240AC0 0000302D */  daddu     $a2, $zero, $zero
/* CF3694 80240AC4 2412000C */  addiu     $s2, $zero, 0xc
/* CF3698 80240AC8 860300A8 */  lh        $v1, 0xa8($s0)
/* CF369C 80240ACC 3C013F80 */  lui       $at, 0x3f80
/* CF36A0 80240AD0 44810000 */  mtc1      $at, $f0
/* CF36A4 80240AD4 3C014000 */  lui       $at, 0x4000
/* CF36A8 80240AD8 44811000 */  mtc1      $at, $f2
/* CF36AC 80240ADC 3C01C1A0 */  lui       $at, 0xc1a0
/* CF36B0 80240AE0 44812000 */  mtc1      $at, $f4
/* CF36B4 80240AE4 44834000 */  mtc1      $v1, $f8
/* CF36B8 80240AE8 00000000 */  nop       
/* CF36BC 80240AEC 46804220 */  cvt.s.w   $f8, $f8
/* CF36C0 80240AF0 44074000 */  mfc1      $a3, $f8
/* CF36C4 80240AF4 27A20038 */  addiu     $v0, $sp, 0x38
/* CF36C8 80240AF8 AFB2001C */  sw        $s2, 0x1c($sp)
/* CF36CC 80240AFC AFA20020 */  sw        $v0, 0x20($sp)
/* CF36D0 80240B00 E7A00010 */  swc1      $f0, 0x10($sp)
/* CF36D4 80240B04 E7A20014 */  swc1      $f2, 0x14($sp)
/* CF36D8 80240B08 0C01BFA4 */  jal       fx_emote
/* CF36DC 80240B0C E7A40018 */   swc1     $f4, 0x18($sp)
/* CF36E0 80240B10 0200202D */  daddu     $a0, $s0, $zero
/* CF36E4 80240B14 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CF36E8 80240B18 C480003C */  lwc1      $f0, 0x3c($a0)
/* CF36EC 80240B1C 3C060020 */  lui       $a2, 0x20
/* CF36F0 80240B20 0C012530 */  jal       func_800494C0
/* CF36F4 80240B24 E4800064 */   swc1     $f0, 0x64($a0)
/* CF36F8 80240B28 8E220018 */  lw        $v0, 0x18($s1)
/* CF36FC 80240B2C 9442002A */  lhu       $v0, 0x2a($v0)
/* CF3700 80240B30 30420001 */  andi      $v0, $v0, 1
/* CF3704 80240B34 10400003 */  beqz      $v0, .L80240B44
/* CF3708 80240B38 2402000A */   addiu    $v0, $zero, 0xa
/* CF370C 80240B3C 080902FB */  j         .L80240BEC
/* CF3710 80240B40 AE620070 */   sw       $v0, 0x70($s3)
.L80240B44:
/* CF3714 80240B44 080902FB */  j         .L80240BEC
/* CF3718 80240B48 AE720070 */   sw       $s2, 0x70($s3)
.L80240B4C:
/* CF371C 80240B4C AE220090 */  sw        $v0, 0x90($s1)
.L80240B50:
/* CF3720 80240B50 8602008C */  lh        $v0, 0x8c($s0)
/* CF3724 80240B54 14400025 */  bnez      $v0, .L80240BEC
/* CF3728 80240B58 00000000 */   nop      
/* CF372C 80240B5C 8602008E */  lh        $v0, 0x8e($s0)
/* CF3730 80240B60 1C400022 */  bgtz      $v0, .L80240BEC
/* CF3734 80240B64 00000000 */   nop      
/* CF3738 80240B68 8E620074 */  lw        $v0, 0x74($s3)
/* CF373C 80240B6C 2442FFFF */  addiu     $v0, $v0, -1
/* CF3740 80240B70 1840001D */  blez      $v0, .L80240BE8
/* CF3744 80240B74 AE620074 */   sw       $v0, 0x74($s3)
/* CF3748 80240B78 8E220018 */  lw        $v0, 0x18($s1)
/* CF374C 80240B7C 9442002A */  lhu       $v0, 0x2a($v0)
/* CF3750 80240B80 30420010 */  andi      $v0, $v0, 0x10
/* CF3754 80240B84 14400007 */  bnez      $v0, .L80240BA4
/* CF3758 80240B88 00000000 */   nop      
/* CF375C 80240B8C C600000C */  lwc1      $f0, 0xc($s0)
/* CF3760 80240B90 3C014334 */  lui       $at, 0x4334
/* CF3764 80240B94 44816000 */  mtc1      $at, $f12
/* CF3768 80240B98 0C00A6C9 */  jal       clamp_angle
/* CF376C 80240B9C 460C0300 */   add.s    $f12, $f0, $f12
/* CF3770 80240BA0 E600000C */  swc1      $f0, 0xc($s0)
.L80240BA4:
/* CF3774 80240BA4 0C00A67F */  jal       rand_int
/* CF3778 80240BA8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* CF377C 80240BAC 3C032E8B */  lui       $v1, 0x2e8b
/* CF3780 80240BB0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* CF3784 80240BB4 00430018 */  mult      $v0, $v1
/* CF3788 80240BB8 00021FC3 */  sra       $v1, $v0, 0x1f
/* CF378C 80240BBC 00004010 */  mfhi      $t0
/* CF3790 80240BC0 00082043 */  sra       $a0, $t0, 1
/* CF3794 80240BC4 00832023 */  subu      $a0, $a0, $v1
/* CF3798 80240BC8 00041840 */  sll       $v1, $a0, 1
/* CF379C 80240BCC 00641821 */  addu      $v1, $v1, $a0
/* CF37A0 80240BD0 00031880 */  sll       $v1, $v1, 2
/* CF37A4 80240BD4 00641823 */  subu      $v1, $v1, $a0
/* CF37A8 80240BD8 00431023 */  subu      $v0, $v0, $v1
/* CF37AC 80240BDC 24420005 */  addiu     $v0, $v0, 5
/* CF37B0 80240BE0 080902FB */  j         .L80240BEC
/* CF37B4 80240BE4 A602008E */   sh       $v0, 0x8e($s0)
.L80240BE8:
/* CF37B8 80240BE8 AE600070 */  sw        $zero, 0x70($s3)
.L80240BEC:
/* CF37BC 80240BEC 8FBF0054 */  lw        $ra, 0x54($sp)
/* CF37C0 80240BF0 8FB40050 */  lw        $s4, 0x50($sp)
/* CF37C4 80240BF4 8FB3004C */  lw        $s3, 0x4c($sp)
/* CF37C8 80240BF8 8FB20048 */  lw        $s2, 0x48($sp)
/* CF37CC 80240BFC 8FB10044 */  lw        $s1, 0x44($sp)
/* CF37D0 80240C00 8FB00040 */  lw        $s0, 0x40($sp)
/* CF37D4 80240C04 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* CF37D8 80240C08 D7B80068 */  ldc1      $f24, 0x68($sp)
/* CF37DC 80240C0C D7B60060 */  ldc1      $f22, 0x60($sp)
/* CF37E0 80240C10 D7B40058 */  ldc1      $f20, 0x58($sp)
/* CF37E4 80240C14 03E00008 */  jr        $ra
/* CF37E8 80240C18 27BD0078 */   addiu    $sp, $sp, 0x78

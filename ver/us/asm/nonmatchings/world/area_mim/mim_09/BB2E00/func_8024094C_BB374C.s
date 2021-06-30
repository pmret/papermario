.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024094C_BB374C
/* BB374C 8024094C 27BDFF90 */  addiu     $sp, $sp, -0x70
/* BB3750 80240950 AFB40050 */  sw        $s4, 0x50($sp)
/* BB3754 80240954 0080A02D */  daddu     $s4, $a0, $zero
/* BB3758 80240958 AFBF0060 */  sw        $ra, 0x60($sp)
/* BB375C 8024095C AFB7005C */  sw        $s7, 0x5c($sp)
/* BB3760 80240960 AFB60058 */  sw        $s6, 0x58($sp)
/* BB3764 80240964 AFB50054 */  sw        $s5, 0x54($sp)
/* BB3768 80240968 AFB3004C */  sw        $s3, 0x4c($sp)
/* BB376C 8024096C AFB20048 */  sw        $s2, 0x48($sp)
/* BB3770 80240970 AFB10044 */  sw        $s1, 0x44($sp)
/* BB3774 80240974 AFB00040 */  sw        $s0, 0x40($sp)
/* BB3778 80240978 F7B40068 */  sdc1      $f20, 0x68($sp)
/* BB377C 8024097C 8E950148 */  lw        $s5, 0x148($s4)
/* BB3780 80240980 00A0B02D */  daddu     $s6, $a1, $zero
/* BB3784 80240984 86A40008 */  lh        $a0, 8($s5)
/* BB3788 80240988 0C00EABB */  jal       get_npc_unsafe
/* BB378C 8024098C 00C0B82D */   daddu    $s7, $a2, $zero
/* BB3790 80240990 0040982D */  daddu     $s3, $v0, $zero
/* BB3794 80240994 C6600018 */  lwc1      $f0, 0x18($s3)
/* BB3798 80240998 44801000 */  mtc1      $zero, $f2
/* BB379C 8024099C 44801800 */  mtc1      $zero, $f3
/* BB37A0 802409A0 46000021 */  cvt.d.s   $f0, $f0
/* BB37A4 802409A4 4620103C */  c.lt.d    $f2, $f0
/* BB37A8 802409A8 00000000 */  nop
/* BB37AC 802409AC 45000021 */  bc1f      .L80240A34
/* BB37B0 802409B0 27A50028 */   addiu    $a1, $sp, 0x28
/* BB37B4 802409B4 C6600038 */  lwc1      $f0, 0x38($s3)
/* BB37B8 802409B8 C662003C */  lwc1      $f2, 0x3c($s3)
/* BB37BC 802409BC C6640040 */  lwc1      $f4, 0x40($s3)
/* BB37C0 802409C0 C6660018 */  lwc1      $f6, 0x18($s3)
/* BB37C4 802409C4 E7A00028 */  swc1      $f0, 0x28($sp)
/* BB37C8 802409C8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BB37CC 802409CC E7A40030 */  swc1      $f4, 0x30($sp)
/* BB37D0 802409D0 E7A60010 */  swc1      $f6, 0x10($sp)
/* BB37D4 802409D4 C660000C */  lwc1      $f0, 0xc($s3)
/* BB37D8 802409D8 E7A00014 */  swc1      $f0, 0x14($sp)
/* BB37DC 802409DC 866200A8 */  lh        $v0, 0xa8($s3)
/* BB37E0 802409E0 44820000 */  mtc1      $v0, $f0
/* BB37E4 802409E4 00000000 */  nop
/* BB37E8 802409E8 46800020 */  cvt.s.w   $f0, $f0
/* BB37EC 802409EC E7A00018 */  swc1      $f0, 0x18($sp)
/* BB37F0 802409F0 866200A6 */  lh        $v0, 0xa6($s3)
/* BB37F4 802409F4 27A6002C */  addiu     $a2, $sp, 0x2c
/* BB37F8 802409F8 44820000 */  mtc1      $v0, $f0
/* BB37FC 802409FC 00000000 */  nop
/* BB3800 80240A00 46800020 */  cvt.s.w   $f0, $f0
/* BB3804 80240A04 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BB3808 80240A08 8E640080 */  lw        $a0, 0x80($s3)
/* BB380C 80240A0C 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BB3810 80240A10 27A70030 */   addiu    $a3, $sp, 0x30
/* BB3814 80240A14 10400003 */  beqz      $v0, .L80240A24
/* BB3818 80240A18 00000000 */   nop
/* BB381C 80240A1C 0809028D */  j         .L80240A34
/* BB3820 80240A20 AE600018 */   sw       $zero, 0x18($s3)
.L80240A24:
/* BB3824 80240A24 8E650018 */  lw        $a1, 0x18($s3)
/* BB3828 80240A28 8E66000C */  lw        $a2, 0xc($s3)
/* BB382C 80240A2C 0C00EA95 */  jal       npc_move_heading
/* BB3830 80240A30 0260202D */   daddu    $a0, $s3, $zero
.L80240A34:
/* BB3834 80240A34 C660001C */  lwc1      $f0, 0x1c($s3)
/* BB3838 80240A38 44801000 */  mtc1      $zero, $f2
/* BB383C 80240A3C 44801800 */  mtc1      $zero, $f3
/* BB3840 80240A40 46000021 */  cvt.d.s   $f0, $f0
/* BB3844 80240A44 4622003C */  c.lt.d    $f0, $f2
/* BB3848 80240A48 00000000 */  nop
/* BB384C 80240A4C 4500006C */  bc1f      .L80240C00
/* BB3850 80240A50 27B00028 */   addiu    $s0, $sp, 0x28
/* BB3854 80240A54 0200282D */  daddu     $a1, $s0, $zero
/* BB3858 80240A58 27A60034 */  addiu     $a2, $sp, 0x34
/* BB385C 80240A5C 27B20038 */  addiu     $s2, $sp, 0x38
/* BB3860 80240A60 C6600038 */  lwc1      $f0, 0x38($s3)
/* BB3864 80240A64 3C0142C8 */  lui       $at, 0x42c8
/* BB3868 80240A68 44811000 */  mtc1      $at, $f2
/* BB386C 80240A6C C6640040 */  lwc1      $f4, 0x40($s3)
/* BB3870 80240A70 3C01447A */  lui       $at, 0x447a
/* BB3874 80240A74 44813000 */  mtc1      $at, $f6
/* BB3878 80240A78 27B10030 */  addiu     $s1, $sp, 0x30
/* BB387C 80240A7C E7A00028 */  swc1      $f0, 0x28($sp)
/* BB3880 80240A80 E7A20034 */  swc1      $f2, 0x34($sp)
/* BB3884 80240A84 E7A40030 */  swc1      $f4, 0x30($sp)
/* BB3888 80240A88 E7A60038 */  swc1      $f6, 0x38($sp)
/* BB388C 80240A8C AFB20010 */  sw        $s2, 0x10($sp)
/* BB3890 80240A90 8E640080 */  lw        $a0, 0x80($s3)
/* BB3894 80240A94 0C0372DF */  jal       npc_raycast_down_sides
/* BB3898 80240A98 0220382D */   daddu    $a3, $s1, $zero
/* BB389C 80240A9C 0200282D */  daddu     $a1, $s0, $zero
/* BB38A0 80240AA0 27A6002C */  addiu     $a2, $sp, 0x2c
/* BB38A4 80240AA4 C662003C */  lwc1      $f2, 0x3c($s3)
/* BB38A8 80240AA8 C6660038 */  lwc1      $f6, 0x38($s3)
/* BB38AC 80240AAC 3C01402A */  lui       $at, 0x402a
/* BB38B0 80240AB0 4481A800 */  mtc1      $at, $f21
/* BB38B4 80240AB4 4480A000 */  mtc1      $zero, $f20
/* BB38B8 80240AB8 460010A1 */  cvt.d.s   $f2, $f2
/* BB38BC 80240ABC 46341080 */  add.d     $f2, $f2, $f20
/* BB38C0 80240AC0 C660001C */  lwc1      $f0, 0x1c($s3)
/* BB38C4 80240AC4 C6640040 */  lwc1      $f4, 0x40($s3)
/* BB38C8 80240AC8 46000005 */  abs.s     $f0, $f0
/* BB38CC 80240ACC E7A40030 */  swc1      $f4, 0x30($sp)
/* BB38D0 80240AD0 3C014030 */  lui       $at, 0x4030
/* BB38D4 80240AD4 44812800 */  mtc1      $at, $f5
/* BB38D8 80240AD8 44802000 */  mtc1      $zero, $f4
/* BB38DC 80240ADC 46000021 */  cvt.d.s   $f0, $f0
/* BB38E0 80240AE0 E7A60028 */  swc1      $f6, 0x28($sp)
/* BB38E4 80240AE4 46240000 */  add.d     $f0, $f0, $f4
/* BB38E8 80240AE8 462010A0 */  cvt.s.d   $f2, $f2
/* BB38EC 80240AEC E7A2002C */  swc1      $f2, 0x2c($sp)
/* BB38F0 80240AF0 46200020 */  cvt.s.d   $f0, $f0
/* BB38F4 80240AF4 E7A00038 */  swc1      $f0, 0x38($sp)
/* BB38F8 80240AF8 AFB20010 */  sw        $s2, 0x10($sp)
/* BB38FC 80240AFC 8E640080 */  lw        $a0, 0x80($s3)
/* BB3900 80240B00 0C0372DF */  jal       npc_raycast_down_sides
/* BB3904 80240B04 0220382D */   daddu    $a3, $s1, $zero
/* BB3908 80240B08 1040003D */  beqz      $v0, .L80240C00
/* BB390C 80240B0C 00000000 */   nop
/* BB3910 80240B10 C660001C */  lwc1      $f0, 0x1c($s3)
/* BB3914 80240B14 C7A20038 */  lwc1      $f2, 0x38($sp)
/* BB3918 80240B18 46000005 */  abs.s     $f0, $f0
/* BB391C 80240B1C 46000021 */  cvt.d.s   $f0, $f0
/* BB3920 80240B20 46340000 */  add.d     $f0, $f0, $f20
/* BB3924 80240B24 460010A1 */  cvt.d.s   $f2, $f2
/* BB3928 80240B28 4620103E */  c.le.d    $f2, $f0
/* BB392C 80240B2C 00000000 */  nop
/* BB3930 80240B30 45000033 */  bc1f      .L80240C00
/* BB3934 80240B34 2403F7FF */   addiu    $v1, $zero, -0x801
/* BB3938 80240B38 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BB393C 80240B3C 8E620000 */  lw        $v0, ($s3)
/* BB3940 80240B40 AE60001C */  sw        $zero, 0x1c($s3)
/* BB3944 80240B44 00431024 */  and       $v0, $v0, $v1
/* BB3948 80240B48 E660003C */  swc1      $f0, 0x3c($s3)
/* BB394C 80240B4C AE620000 */  sw        $v0, ($s3)
/* BB3950 80240B50 AFA00010 */  sw        $zero, 0x10($sp)
/* BB3954 80240B54 AFA00014 */  sw        $zero, 0x14($sp)
/* BB3958 80240B58 8E650038 */  lw        $a1, 0x38($s3)
/* BB395C 80240B5C 8E66003C */  lw        $a2, 0x3c($s3)
/* BB3960 80240B60 8E670040 */  lw        $a3, 0x40($s3)
/* BB3964 80240B64 0C01BECC */  jal       fx_walk
/* BB3968 80240B68 24040002 */   addiu    $a0, $zero, 2
/* BB396C 80240B6C 02E0202D */  daddu     $a0, $s7, $zero
/* BB3970 80240B70 2402000C */  addiu     $v0, $zero, 0xc
/* BB3974 80240B74 AE820070 */  sw        $v0, 0x70($s4)
/* BB3978 80240B78 24020001 */  addiu     $v0, $zero, 1
/* BB397C 80240B7C AFA20010 */  sw        $v0, 0x10($sp)
/* BB3980 80240B80 8EC60024 */  lw        $a2, 0x24($s6)
/* BB3984 80240B84 8EC70028 */  lw        $a3, 0x28($s6)
/* BB3988 80240B88 0C01242D */  jal       func_800490B4
/* BB398C 80240B8C 02A0282D */   daddu    $a1, $s5, $zero
/* BB3990 80240B90 14400022 */  bnez      $v0, .L80240C1C
/* BB3994 80240B94 24040002 */   addiu    $a0, $zero, 2
/* BB3998 80240B98 0260282D */  daddu     $a1, $s3, $zero
/* BB399C 80240B9C 0000302D */  daddu     $a2, $zero, $zero
/* BB39A0 80240BA0 866300A8 */  lh        $v1, 0xa8($s3)
/* BB39A4 80240BA4 3C013F80 */  lui       $at, 0x3f80
/* BB39A8 80240BA8 44810000 */  mtc1      $at, $f0
/* BB39AC 80240BAC 3C014000 */  lui       $at, 0x4000
/* BB39B0 80240BB0 44811000 */  mtc1      $at, $f2
/* BB39B4 80240BB4 3C01C1A0 */  lui       $at, 0xc1a0
/* BB39B8 80240BB8 44812000 */  mtc1      $at, $f4
/* BB39BC 80240BBC 2402000F */  addiu     $v0, $zero, 0xf
/* BB39C0 80240BC0 AFA2001C */  sw        $v0, 0x1c($sp)
/* BB39C4 80240BC4 44834000 */  mtc1      $v1, $f8
/* BB39C8 80240BC8 00000000 */  nop
/* BB39CC 80240BCC 46804220 */  cvt.s.w   $f8, $f8
/* BB39D0 80240BD0 44074000 */  mfc1      $a3, $f8
/* BB39D4 80240BD4 27A2003C */  addiu     $v0, $sp, 0x3c
/* BB39D8 80240BD8 AFA20020 */  sw        $v0, 0x20($sp)
/* BB39DC 80240BDC E7A00010 */  swc1      $f0, 0x10($sp)
/* BB39E0 80240BE0 E7A20014 */  swc1      $f2, 0x14($sp)
/* BB39E4 80240BE4 0C01BFA4 */  jal       fx_emote
/* BB39E8 80240BE8 E7A40018 */   swc1     $f4, 0x18($sp)
/* BB39EC 80240BEC 24020019 */  addiu     $v0, $zero, 0x19
/* BB39F0 80240BF0 A662008E */  sh        $v0, 0x8e($s3)
/* BB39F4 80240BF4 2402000E */  addiu     $v0, $zero, 0xe
/* BB39F8 80240BF8 08090307 */  j         .L80240C1C
/* BB39FC 80240BFC AE820070 */   sw       $v0, 0x70($s4)
.L80240C00:
/* BB3A00 80240C00 C664003C */  lwc1      $f4, 0x3c($s3)
/* BB3A04 80240C04 C660001C */  lwc1      $f0, 0x1c($s3)
/* BB3A08 80240C08 46002100 */  add.s     $f4, $f4, $f0
/* BB3A0C 80240C0C C6620014 */  lwc1      $f2, 0x14($s3)
/* BB3A10 80240C10 46020001 */  sub.s     $f0, $f0, $f2
/* BB3A14 80240C14 E664003C */  swc1      $f4, 0x3c($s3)
/* BB3A18 80240C18 E660001C */  swc1      $f0, 0x1c($s3)
.L80240C1C:
/* BB3A1C 80240C1C 8FBF0060 */  lw        $ra, 0x60($sp)
/* BB3A20 80240C20 8FB7005C */  lw        $s7, 0x5c($sp)
/* BB3A24 80240C24 8FB60058 */  lw        $s6, 0x58($sp)
/* BB3A28 80240C28 8FB50054 */  lw        $s5, 0x54($sp)
/* BB3A2C 80240C2C 8FB40050 */  lw        $s4, 0x50($sp)
/* BB3A30 80240C30 8FB3004C */  lw        $s3, 0x4c($sp)
/* BB3A34 80240C34 8FB20048 */  lw        $s2, 0x48($sp)
/* BB3A38 80240C38 8FB10044 */  lw        $s1, 0x44($sp)
/* BB3A3C 80240C3C 8FB00040 */  lw        $s0, 0x40($sp)
/* BB3A40 80240C40 D7B40068 */  ldc1      $f20, 0x68($sp)
/* BB3A44 80240C44 03E00008 */  jr        $ra
/* BB3A48 80240C48 27BD0070 */   addiu    $sp, $sp, 0x70

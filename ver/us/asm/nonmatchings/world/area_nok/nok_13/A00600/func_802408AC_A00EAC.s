.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408AC_A00EAC
/* A00EAC 802408AC 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A00EB0 802408B0 AFB40050 */  sw        $s4, 0x50($sp)
/* A00EB4 802408B4 0080A02D */  daddu     $s4, $a0, $zero
/* A00EB8 802408B8 AFBF0060 */  sw        $ra, 0x60($sp)
/* A00EBC 802408BC AFB7005C */  sw        $s7, 0x5c($sp)
/* A00EC0 802408C0 AFB60058 */  sw        $s6, 0x58($sp)
/* A00EC4 802408C4 AFB50054 */  sw        $s5, 0x54($sp)
/* A00EC8 802408C8 AFB3004C */  sw        $s3, 0x4c($sp)
/* A00ECC 802408CC AFB20048 */  sw        $s2, 0x48($sp)
/* A00ED0 802408D0 AFB10044 */  sw        $s1, 0x44($sp)
/* A00ED4 802408D4 AFB00040 */  sw        $s0, 0x40($sp)
/* A00ED8 802408D8 F7B40068 */  sdc1      $f20, 0x68($sp)
/* A00EDC 802408DC 8E950148 */  lw        $s5, 0x148($s4)
/* A00EE0 802408E0 00A0B02D */  daddu     $s6, $a1, $zero
/* A00EE4 802408E4 86A40008 */  lh        $a0, 8($s5)
/* A00EE8 802408E8 0C00EABB */  jal       get_npc_unsafe
/* A00EEC 802408EC 00C0B82D */   daddu    $s7, $a2, $zero
/* A00EF0 802408F0 0040982D */  daddu     $s3, $v0, $zero
/* A00EF4 802408F4 C6600018 */  lwc1      $f0, 0x18($s3)
/* A00EF8 802408F8 44801000 */  mtc1      $zero, $f2
/* A00EFC 802408FC 44801800 */  mtc1      $zero, $f3
/* A00F00 80240900 46000021 */  cvt.d.s   $f0, $f0
/* A00F04 80240904 4620103C */  c.lt.d    $f2, $f0
/* A00F08 80240908 00000000 */  nop
/* A00F0C 8024090C 45000021 */  bc1f      .L80240994
/* A00F10 80240910 27A50028 */   addiu    $a1, $sp, 0x28
/* A00F14 80240914 C6600038 */  lwc1      $f0, 0x38($s3)
/* A00F18 80240918 C662003C */  lwc1      $f2, 0x3c($s3)
/* A00F1C 8024091C C6640040 */  lwc1      $f4, 0x40($s3)
/* A00F20 80240920 C6660018 */  lwc1      $f6, 0x18($s3)
/* A00F24 80240924 E7A00028 */  swc1      $f0, 0x28($sp)
/* A00F28 80240928 E7A2002C */  swc1      $f2, 0x2c($sp)
/* A00F2C 8024092C E7A40030 */  swc1      $f4, 0x30($sp)
/* A00F30 80240930 E7A60010 */  swc1      $f6, 0x10($sp)
/* A00F34 80240934 C660000C */  lwc1      $f0, 0xc($s3)
/* A00F38 80240938 E7A00014 */  swc1      $f0, 0x14($sp)
/* A00F3C 8024093C 866200A8 */  lh        $v0, 0xa8($s3)
/* A00F40 80240940 44820000 */  mtc1      $v0, $f0
/* A00F44 80240944 00000000 */  nop
/* A00F48 80240948 46800020 */  cvt.s.w   $f0, $f0
/* A00F4C 8024094C E7A00018 */  swc1      $f0, 0x18($sp)
/* A00F50 80240950 866200A6 */  lh        $v0, 0xa6($s3)
/* A00F54 80240954 27A6002C */  addiu     $a2, $sp, 0x2c
/* A00F58 80240958 44820000 */  mtc1      $v0, $f0
/* A00F5C 8024095C 00000000 */  nop
/* A00F60 80240960 46800020 */  cvt.s.w   $f0, $f0
/* A00F64 80240964 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A00F68 80240968 8E640080 */  lw        $a0, 0x80($s3)
/* A00F6C 8024096C 0C037711 */  jal       npc_test_move_simple_with_slipping
/* A00F70 80240970 27A70030 */   addiu    $a3, $sp, 0x30
/* A00F74 80240974 10400003 */  beqz      $v0, .L80240984
/* A00F78 80240978 00000000 */   nop
/* A00F7C 8024097C 08090265 */  j         .L80240994
/* A00F80 80240980 AE600018 */   sw       $zero, 0x18($s3)
.L80240984:
/* A00F84 80240984 8E650018 */  lw        $a1, 0x18($s3)
/* A00F88 80240988 8E66000C */  lw        $a2, 0xc($s3)
/* A00F8C 8024098C 0C00EA95 */  jal       npc_move_heading
/* A00F90 80240990 0260202D */   daddu    $a0, $s3, $zero
.L80240994:
/* A00F94 80240994 C660001C */  lwc1      $f0, 0x1c($s3)
/* A00F98 80240998 44801000 */  mtc1      $zero, $f2
/* A00F9C 8024099C 44801800 */  mtc1      $zero, $f3
/* A00FA0 802409A0 46000021 */  cvt.d.s   $f0, $f0
/* A00FA4 802409A4 4622003C */  c.lt.d    $f0, $f2
/* A00FA8 802409A8 00000000 */  nop
/* A00FAC 802409AC 4500006C */  bc1f      .L80240B60
/* A00FB0 802409B0 27B00028 */   addiu    $s0, $sp, 0x28
/* A00FB4 802409B4 0200282D */  daddu     $a1, $s0, $zero
/* A00FB8 802409B8 27A60034 */  addiu     $a2, $sp, 0x34
/* A00FBC 802409BC 27B20038 */  addiu     $s2, $sp, 0x38
/* A00FC0 802409C0 C6600038 */  lwc1      $f0, 0x38($s3)
/* A00FC4 802409C4 3C0142C8 */  lui       $at, 0x42c8
/* A00FC8 802409C8 44811000 */  mtc1      $at, $f2
/* A00FCC 802409CC C6640040 */  lwc1      $f4, 0x40($s3)
/* A00FD0 802409D0 3C01447A */  lui       $at, 0x447a
/* A00FD4 802409D4 44813000 */  mtc1      $at, $f6
/* A00FD8 802409D8 27B10030 */  addiu     $s1, $sp, 0x30
/* A00FDC 802409DC E7A00028 */  swc1      $f0, 0x28($sp)
/* A00FE0 802409E0 E7A20034 */  swc1      $f2, 0x34($sp)
/* A00FE4 802409E4 E7A40030 */  swc1      $f4, 0x30($sp)
/* A00FE8 802409E8 E7A60038 */  swc1      $f6, 0x38($sp)
/* A00FEC 802409EC AFB20010 */  sw        $s2, 0x10($sp)
/* A00FF0 802409F0 8E640080 */  lw        $a0, 0x80($s3)
/* A00FF4 802409F4 0C0372DF */  jal       npc_raycast_down_sides
/* A00FF8 802409F8 0220382D */   daddu    $a3, $s1, $zero
/* A00FFC 802409FC 0200282D */  daddu     $a1, $s0, $zero
/* A01000 80240A00 27A6002C */  addiu     $a2, $sp, 0x2c
/* A01004 80240A04 C662003C */  lwc1      $f2, 0x3c($s3)
/* A01008 80240A08 C6660038 */  lwc1      $f6, 0x38($s3)
/* A0100C 80240A0C 3C01402A */  lui       $at, 0x402a
/* A01010 80240A10 4481A800 */  mtc1      $at, $f21
/* A01014 80240A14 4480A000 */  mtc1      $zero, $f20
/* A01018 80240A18 460010A1 */  cvt.d.s   $f2, $f2
/* A0101C 80240A1C 46341080 */  add.d     $f2, $f2, $f20
/* A01020 80240A20 C660001C */  lwc1      $f0, 0x1c($s3)
/* A01024 80240A24 C6640040 */  lwc1      $f4, 0x40($s3)
/* A01028 80240A28 46000005 */  abs.s     $f0, $f0
/* A0102C 80240A2C E7A40030 */  swc1      $f4, 0x30($sp)
/* A01030 80240A30 3C014030 */  lui       $at, 0x4030
/* A01034 80240A34 44812800 */  mtc1      $at, $f5
/* A01038 80240A38 44802000 */  mtc1      $zero, $f4
/* A0103C 80240A3C 46000021 */  cvt.d.s   $f0, $f0
/* A01040 80240A40 E7A60028 */  swc1      $f6, 0x28($sp)
/* A01044 80240A44 46240000 */  add.d     $f0, $f0, $f4
/* A01048 80240A48 462010A0 */  cvt.s.d   $f2, $f2
/* A0104C 80240A4C E7A2002C */  swc1      $f2, 0x2c($sp)
/* A01050 80240A50 46200020 */  cvt.s.d   $f0, $f0
/* A01054 80240A54 E7A00038 */  swc1      $f0, 0x38($sp)
/* A01058 80240A58 AFB20010 */  sw        $s2, 0x10($sp)
/* A0105C 80240A5C 8E640080 */  lw        $a0, 0x80($s3)
/* A01060 80240A60 0C0372DF */  jal       npc_raycast_down_sides
/* A01064 80240A64 0220382D */   daddu    $a3, $s1, $zero
/* A01068 80240A68 1040003D */  beqz      $v0, .L80240B60
/* A0106C 80240A6C 00000000 */   nop
/* A01070 80240A70 C660001C */  lwc1      $f0, 0x1c($s3)
/* A01074 80240A74 C7A20038 */  lwc1      $f2, 0x38($sp)
/* A01078 80240A78 46000005 */  abs.s     $f0, $f0
/* A0107C 80240A7C 46000021 */  cvt.d.s   $f0, $f0
/* A01080 80240A80 46340000 */  add.d     $f0, $f0, $f20
/* A01084 80240A84 460010A1 */  cvt.d.s   $f2, $f2
/* A01088 80240A88 4620103E */  c.le.d    $f2, $f0
/* A0108C 80240A8C 00000000 */  nop
/* A01090 80240A90 45000033 */  bc1f      .L80240B60
/* A01094 80240A94 2403F7FF */   addiu    $v1, $zero, -0x801
/* A01098 80240A98 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A0109C 80240A9C 8E620000 */  lw        $v0, ($s3)
/* A010A0 80240AA0 AE60001C */  sw        $zero, 0x1c($s3)
/* A010A4 80240AA4 00431024 */  and       $v0, $v0, $v1
/* A010A8 80240AA8 E660003C */  swc1      $f0, 0x3c($s3)
/* A010AC 80240AAC AE620000 */  sw        $v0, ($s3)
/* A010B0 80240AB0 AFA00010 */  sw        $zero, 0x10($sp)
/* A010B4 80240AB4 AFA00014 */  sw        $zero, 0x14($sp)
/* A010B8 80240AB8 8E650038 */  lw        $a1, 0x38($s3)
/* A010BC 80240ABC 8E66003C */  lw        $a2, 0x3c($s3)
/* A010C0 80240AC0 8E670040 */  lw        $a3, 0x40($s3)
/* A010C4 80240AC4 0C01BECC */  jal       fx_walk
/* A010C8 80240AC8 24040002 */   addiu    $a0, $zero, 2
/* A010CC 80240ACC 02E0202D */  daddu     $a0, $s7, $zero
/* A010D0 80240AD0 2402000C */  addiu     $v0, $zero, 0xc
/* A010D4 80240AD4 AE820070 */  sw        $v0, 0x70($s4)
/* A010D8 80240AD8 24020001 */  addiu     $v0, $zero, 1
/* A010DC 80240ADC AFA20010 */  sw        $v0, 0x10($sp)
/* A010E0 80240AE0 8EC60024 */  lw        $a2, 0x24($s6)
/* A010E4 80240AE4 8EC70028 */  lw        $a3, 0x28($s6)
/* A010E8 80240AE8 0C01242D */  jal       func_800490B4
/* A010EC 80240AEC 02A0282D */   daddu    $a1, $s5, $zero
/* A010F0 80240AF0 14400022 */  bnez      $v0, .L80240B7C
/* A010F4 80240AF4 24040002 */   addiu    $a0, $zero, 2
/* A010F8 80240AF8 0260282D */  daddu     $a1, $s3, $zero
/* A010FC 80240AFC 0000302D */  daddu     $a2, $zero, $zero
/* A01100 80240B00 866300A8 */  lh        $v1, 0xa8($s3)
/* A01104 80240B04 3C013F80 */  lui       $at, 0x3f80
/* A01108 80240B08 44810000 */  mtc1      $at, $f0
/* A0110C 80240B0C 3C014000 */  lui       $at, 0x4000
/* A01110 80240B10 44811000 */  mtc1      $at, $f2
/* A01114 80240B14 3C01C1A0 */  lui       $at, 0xc1a0
/* A01118 80240B18 44812000 */  mtc1      $at, $f4
/* A0111C 80240B1C 2402000F */  addiu     $v0, $zero, 0xf
/* A01120 80240B20 AFA2001C */  sw        $v0, 0x1c($sp)
/* A01124 80240B24 44834000 */  mtc1      $v1, $f8
/* A01128 80240B28 00000000 */  nop
/* A0112C 80240B2C 46804220 */  cvt.s.w   $f8, $f8
/* A01130 80240B30 44074000 */  mfc1      $a3, $f8
/* A01134 80240B34 27A2003C */  addiu     $v0, $sp, 0x3c
/* A01138 80240B38 AFA20020 */  sw        $v0, 0x20($sp)
/* A0113C 80240B3C E7A00010 */  swc1      $f0, 0x10($sp)
/* A01140 80240B40 E7A20014 */  swc1      $f2, 0x14($sp)
/* A01144 80240B44 0C01BFA4 */  jal       fx_emote
/* A01148 80240B48 E7A40018 */   swc1     $f4, 0x18($sp)
/* A0114C 80240B4C 24020019 */  addiu     $v0, $zero, 0x19
/* A01150 80240B50 A662008E */  sh        $v0, 0x8e($s3)
/* A01154 80240B54 2402000E */  addiu     $v0, $zero, 0xe
/* A01158 80240B58 080902DF */  j         .L80240B7C
/* A0115C 80240B5C AE820070 */   sw       $v0, 0x70($s4)
.L80240B60:
/* A01160 80240B60 C664003C */  lwc1      $f4, 0x3c($s3)
/* A01164 80240B64 C660001C */  lwc1      $f0, 0x1c($s3)
/* A01168 80240B68 46002100 */  add.s     $f4, $f4, $f0
/* A0116C 80240B6C C6620014 */  lwc1      $f2, 0x14($s3)
/* A01170 80240B70 46020001 */  sub.s     $f0, $f0, $f2
/* A01174 80240B74 E664003C */  swc1      $f4, 0x3c($s3)
/* A01178 80240B78 E660001C */  swc1      $f0, 0x1c($s3)
.L80240B7C:
/* A0117C 80240B7C 8FBF0060 */  lw        $ra, 0x60($sp)
/* A01180 80240B80 8FB7005C */  lw        $s7, 0x5c($sp)
/* A01184 80240B84 8FB60058 */  lw        $s6, 0x58($sp)
/* A01188 80240B88 8FB50054 */  lw        $s5, 0x54($sp)
/* A0118C 80240B8C 8FB40050 */  lw        $s4, 0x50($sp)
/* A01190 80240B90 8FB3004C */  lw        $s3, 0x4c($sp)
/* A01194 80240B94 8FB20048 */  lw        $s2, 0x48($sp)
/* A01198 80240B98 8FB10044 */  lw        $s1, 0x44($sp)
/* A0119C 80240B9C 8FB00040 */  lw        $s0, 0x40($sp)
/* A011A0 80240BA0 D7B40068 */  ldc1      $f20, 0x68($sp)
/* A011A4 80240BA4 03E00008 */  jr        $ra
/* A011A8 80240BA8 27BD0070 */   addiu    $sp, $sp, 0x70

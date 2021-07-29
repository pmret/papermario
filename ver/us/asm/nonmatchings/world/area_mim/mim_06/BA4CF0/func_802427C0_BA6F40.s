.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427C0_BA6F40
/* BA6F40 802427C0 27BDFF90 */  addiu     $sp, $sp, -0x70
/* BA6F44 802427C4 AFB40050 */  sw        $s4, 0x50($sp)
/* BA6F48 802427C8 0080A02D */  daddu     $s4, $a0, $zero
/* BA6F4C 802427CC AFBF0060 */  sw        $ra, 0x60($sp)
/* BA6F50 802427D0 AFB7005C */  sw        $s7, 0x5c($sp)
/* BA6F54 802427D4 AFB60058 */  sw        $s6, 0x58($sp)
/* BA6F58 802427D8 AFB50054 */  sw        $s5, 0x54($sp)
/* BA6F5C 802427DC AFB3004C */  sw        $s3, 0x4c($sp)
/* BA6F60 802427E0 AFB20048 */  sw        $s2, 0x48($sp)
/* BA6F64 802427E4 AFB10044 */  sw        $s1, 0x44($sp)
/* BA6F68 802427E8 AFB00040 */  sw        $s0, 0x40($sp)
/* BA6F6C 802427EC F7B40068 */  sdc1      $f20, 0x68($sp)
/* BA6F70 802427F0 8E950148 */  lw        $s5, 0x148($s4)
/* BA6F74 802427F4 00A0B02D */  daddu     $s6, $a1, $zero
/* BA6F78 802427F8 86A40008 */  lh        $a0, 8($s5)
/* BA6F7C 802427FC 0C00EABB */  jal       get_npc_unsafe
/* BA6F80 80242800 00C0B82D */   daddu    $s7, $a2, $zero
/* BA6F84 80242804 0040982D */  daddu     $s3, $v0, $zero
/* BA6F88 80242808 C6600018 */  lwc1      $f0, 0x18($s3)
/* BA6F8C 8024280C 44801000 */  mtc1      $zero, $f2
/* BA6F90 80242810 44801800 */  mtc1      $zero, $f3
/* BA6F94 80242814 46000021 */  cvt.d.s   $f0, $f0
/* BA6F98 80242818 4620103C */  c.lt.d    $f2, $f0
/* BA6F9C 8024281C 00000000 */  nop
/* BA6FA0 80242820 45000021 */  bc1f      .L802428A8
/* BA6FA4 80242824 27A50028 */   addiu    $a1, $sp, 0x28
/* BA6FA8 80242828 C6600038 */  lwc1      $f0, 0x38($s3)
/* BA6FAC 8024282C C662003C */  lwc1      $f2, 0x3c($s3)
/* BA6FB0 80242830 C6640040 */  lwc1      $f4, 0x40($s3)
/* BA6FB4 80242834 C6660018 */  lwc1      $f6, 0x18($s3)
/* BA6FB8 80242838 E7A00028 */  swc1      $f0, 0x28($sp)
/* BA6FBC 8024283C E7A2002C */  swc1      $f2, 0x2c($sp)
/* BA6FC0 80242840 E7A40030 */  swc1      $f4, 0x30($sp)
/* BA6FC4 80242844 E7A60010 */  swc1      $f6, 0x10($sp)
/* BA6FC8 80242848 C660000C */  lwc1      $f0, 0xc($s3)
/* BA6FCC 8024284C E7A00014 */  swc1      $f0, 0x14($sp)
/* BA6FD0 80242850 866200A8 */  lh        $v0, 0xa8($s3)
/* BA6FD4 80242854 44820000 */  mtc1      $v0, $f0
/* BA6FD8 80242858 00000000 */  nop
/* BA6FDC 8024285C 46800020 */  cvt.s.w   $f0, $f0
/* BA6FE0 80242860 E7A00018 */  swc1      $f0, 0x18($sp)
/* BA6FE4 80242864 866200A6 */  lh        $v0, 0xa6($s3)
/* BA6FE8 80242868 27A6002C */  addiu     $a2, $sp, 0x2c
/* BA6FEC 8024286C 44820000 */  mtc1      $v0, $f0
/* BA6FF0 80242870 00000000 */  nop
/* BA6FF4 80242874 46800020 */  cvt.s.w   $f0, $f0
/* BA6FF8 80242878 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BA6FFC 8024287C 8E640080 */  lw        $a0, 0x80($s3)
/* BA7000 80242880 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BA7004 80242884 27A70030 */   addiu    $a3, $sp, 0x30
/* BA7008 80242888 10400003 */  beqz      $v0, .L80242898
/* BA700C 8024288C 00000000 */   nop
/* BA7010 80242890 08090A2A */  j         .L802428A8
/* BA7014 80242894 AE600018 */   sw       $zero, 0x18($s3)
.L80242898:
/* BA7018 80242898 8E650018 */  lw        $a1, 0x18($s3)
/* BA701C 8024289C 8E66000C */  lw        $a2, 0xc($s3)
/* BA7020 802428A0 0C00EA95 */  jal       npc_move_heading
/* BA7024 802428A4 0260202D */   daddu    $a0, $s3, $zero
.L802428A8:
/* BA7028 802428A8 C660001C */  lwc1      $f0, 0x1c($s3)
/* BA702C 802428AC 44801000 */  mtc1      $zero, $f2
/* BA7030 802428B0 44801800 */  mtc1      $zero, $f3
/* BA7034 802428B4 46000021 */  cvt.d.s   $f0, $f0
/* BA7038 802428B8 4622003C */  c.lt.d    $f0, $f2
/* BA703C 802428BC 00000000 */  nop
/* BA7040 802428C0 4500006C */  bc1f      .L80242A74
/* BA7044 802428C4 27B00028 */   addiu    $s0, $sp, 0x28
/* BA7048 802428C8 0200282D */  daddu     $a1, $s0, $zero
/* BA704C 802428CC 27A60034 */  addiu     $a2, $sp, 0x34
/* BA7050 802428D0 27B20038 */  addiu     $s2, $sp, 0x38
/* BA7054 802428D4 C6600038 */  lwc1      $f0, 0x38($s3)
/* BA7058 802428D8 3C0142C8 */  lui       $at, 0x42c8
/* BA705C 802428DC 44811000 */  mtc1      $at, $f2
/* BA7060 802428E0 C6640040 */  lwc1      $f4, 0x40($s3)
/* BA7064 802428E4 3C01447A */  lui       $at, 0x447a
/* BA7068 802428E8 44813000 */  mtc1      $at, $f6
/* BA706C 802428EC 27B10030 */  addiu     $s1, $sp, 0x30
/* BA7070 802428F0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BA7074 802428F4 E7A20034 */  swc1      $f2, 0x34($sp)
/* BA7078 802428F8 E7A40030 */  swc1      $f4, 0x30($sp)
/* BA707C 802428FC E7A60038 */  swc1      $f6, 0x38($sp)
/* BA7080 80242900 AFB20010 */  sw        $s2, 0x10($sp)
/* BA7084 80242904 8E640080 */  lw        $a0, 0x80($s3)
/* BA7088 80242908 0C0372DF */  jal       npc_raycast_down_sides
/* BA708C 8024290C 0220382D */   daddu    $a3, $s1, $zero
/* BA7090 80242910 0200282D */  daddu     $a1, $s0, $zero
/* BA7094 80242914 27A6002C */  addiu     $a2, $sp, 0x2c
/* BA7098 80242918 C662003C */  lwc1      $f2, 0x3c($s3)
/* BA709C 8024291C C6660038 */  lwc1      $f6, 0x38($s3)
/* BA70A0 80242920 3C01402A */  lui       $at, 0x402a
/* BA70A4 80242924 4481A800 */  mtc1      $at, $f21
/* BA70A8 80242928 4480A000 */  mtc1      $zero, $f20
/* BA70AC 8024292C 460010A1 */  cvt.d.s   $f2, $f2
/* BA70B0 80242930 46341080 */  add.d     $f2, $f2, $f20
/* BA70B4 80242934 C660001C */  lwc1      $f0, 0x1c($s3)
/* BA70B8 80242938 C6640040 */  lwc1      $f4, 0x40($s3)
/* BA70BC 8024293C 46000005 */  abs.s     $f0, $f0
/* BA70C0 80242940 E7A40030 */  swc1      $f4, 0x30($sp)
/* BA70C4 80242944 3C014030 */  lui       $at, 0x4030
/* BA70C8 80242948 44812800 */  mtc1      $at, $f5
/* BA70CC 8024294C 44802000 */  mtc1      $zero, $f4
/* BA70D0 80242950 46000021 */  cvt.d.s   $f0, $f0
/* BA70D4 80242954 E7A60028 */  swc1      $f6, 0x28($sp)
/* BA70D8 80242958 46240000 */  add.d     $f0, $f0, $f4
/* BA70DC 8024295C 462010A0 */  cvt.s.d   $f2, $f2
/* BA70E0 80242960 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BA70E4 80242964 46200020 */  cvt.s.d   $f0, $f0
/* BA70E8 80242968 E7A00038 */  swc1      $f0, 0x38($sp)
/* BA70EC 8024296C AFB20010 */  sw        $s2, 0x10($sp)
/* BA70F0 80242970 8E640080 */  lw        $a0, 0x80($s3)
/* BA70F4 80242974 0C0372DF */  jal       npc_raycast_down_sides
/* BA70F8 80242978 0220382D */   daddu    $a3, $s1, $zero
/* BA70FC 8024297C 1040003D */  beqz      $v0, .L80242A74
/* BA7100 80242980 00000000 */   nop
/* BA7104 80242984 C660001C */  lwc1      $f0, 0x1c($s3)
/* BA7108 80242988 C7A20038 */  lwc1      $f2, 0x38($sp)
/* BA710C 8024298C 46000005 */  abs.s     $f0, $f0
/* BA7110 80242990 46000021 */  cvt.d.s   $f0, $f0
/* BA7114 80242994 46340000 */  add.d     $f0, $f0, $f20
/* BA7118 80242998 460010A1 */  cvt.d.s   $f2, $f2
/* BA711C 8024299C 4620103E */  c.le.d    $f2, $f0
/* BA7120 802429A0 00000000 */  nop
/* BA7124 802429A4 45000033 */  bc1f      .L80242A74
/* BA7128 802429A8 2403F7FF */   addiu    $v1, $zero, -0x801
/* BA712C 802429AC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BA7130 802429B0 8E620000 */  lw        $v0, ($s3)
/* BA7134 802429B4 AE60001C */  sw        $zero, 0x1c($s3)
/* BA7138 802429B8 00431024 */  and       $v0, $v0, $v1
/* BA713C 802429BC E660003C */  swc1      $f0, 0x3c($s3)
/* BA7140 802429C0 AE620000 */  sw        $v0, ($s3)
/* BA7144 802429C4 AFA00010 */  sw        $zero, 0x10($sp)
/* BA7148 802429C8 AFA00014 */  sw        $zero, 0x14($sp)
/* BA714C 802429CC 8E650038 */  lw        $a1, 0x38($s3)
/* BA7150 802429D0 8E66003C */  lw        $a2, 0x3c($s3)
/* BA7154 802429D4 8E670040 */  lw        $a3, 0x40($s3)
/* BA7158 802429D8 0C01BECC */  jal       fx_walk
/* BA715C 802429DC 24040002 */   addiu    $a0, $zero, 2
/* BA7160 802429E0 02E0202D */  daddu     $a0, $s7, $zero
/* BA7164 802429E4 2402000C */  addiu     $v0, $zero, 0xc
/* BA7168 802429E8 AE820070 */  sw        $v0, 0x70($s4)
/* BA716C 802429EC 24020001 */  addiu     $v0, $zero, 1
/* BA7170 802429F0 AFA20010 */  sw        $v0, 0x10($sp)
/* BA7174 802429F4 8EC60024 */  lw        $a2, 0x24($s6)
/* BA7178 802429F8 8EC70028 */  lw        $a3, 0x28($s6)
/* BA717C 802429FC 0C01242D */  jal       func_800490B4
/* BA7180 80242A00 02A0282D */   daddu    $a1, $s5, $zero
/* BA7184 80242A04 14400022 */  bnez      $v0, .L80242A90
/* BA7188 80242A08 24040002 */   addiu    $a0, $zero, 2
/* BA718C 80242A0C 0260282D */  daddu     $a1, $s3, $zero
/* BA7190 80242A10 0000302D */  daddu     $a2, $zero, $zero
/* BA7194 80242A14 866300A8 */  lh        $v1, 0xa8($s3)
/* BA7198 80242A18 3C013F80 */  lui       $at, 0x3f80
/* BA719C 80242A1C 44810000 */  mtc1      $at, $f0
/* BA71A0 80242A20 3C014000 */  lui       $at, 0x4000
/* BA71A4 80242A24 44811000 */  mtc1      $at, $f2
/* BA71A8 80242A28 3C01C1A0 */  lui       $at, 0xc1a0
/* BA71AC 80242A2C 44812000 */  mtc1      $at, $f4
/* BA71B0 80242A30 2402000F */  addiu     $v0, $zero, 0xf
/* BA71B4 80242A34 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA71B8 80242A38 44834000 */  mtc1      $v1, $f8
/* BA71BC 80242A3C 00000000 */  nop
/* BA71C0 80242A40 46804220 */  cvt.s.w   $f8, $f8
/* BA71C4 80242A44 44074000 */  mfc1      $a3, $f8
/* BA71C8 80242A48 27A2003C */  addiu     $v0, $sp, 0x3c
/* BA71CC 80242A4C AFA20020 */  sw        $v0, 0x20($sp)
/* BA71D0 80242A50 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA71D4 80242A54 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA71D8 80242A58 0C01BFA4 */  jal       fx_emote
/* BA71DC 80242A5C E7A40018 */   swc1     $f4, 0x18($sp)
/* BA71E0 80242A60 24020019 */  addiu     $v0, $zero, 0x19
/* BA71E4 80242A64 A662008E */  sh        $v0, 0x8e($s3)
/* BA71E8 80242A68 2402000E */  addiu     $v0, $zero, 0xe
/* BA71EC 80242A6C 08090AA4 */  j         .L80242A90
/* BA71F0 80242A70 AE820070 */   sw       $v0, 0x70($s4)
.L80242A74:
/* BA71F4 80242A74 C664003C */  lwc1      $f4, 0x3c($s3)
/* BA71F8 80242A78 C660001C */  lwc1      $f0, 0x1c($s3)
/* BA71FC 80242A7C 46002100 */  add.s     $f4, $f4, $f0
/* BA7200 80242A80 C6620014 */  lwc1      $f2, 0x14($s3)
/* BA7204 80242A84 46020001 */  sub.s     $f0, $f0, $f2
/* BA7208 80242A88 E664003C */  swc1      $f4, 0x3c($s3)
/* BA720C 80242A8C E660001C */  swc1      $f0, 0x1c($s3)
.L80242A90:
/* BA7210 80242A90 8FBF0060 */  lw        $ra, 0x60($sp)
/* BA7214 80242A94 8FB7005C */  lw        $s7, 0x5c($sp)
/* BA7218 80242A98 8FB60058 */  lw        $s6, 0x58($sp)
/* BA721C 80242A9C 8FB50054 */  lw        $s5, 0x54($sp)
/* BA7220 80242AA0 8FB40050 */  lw        $s4, 0x50($sp)
/* BA7224 80242AA4 8FB3004C */  lw        $s3, 0x4c($sp)
/* BA7228 80242AA8 8FB20048 */  lw        $s2, 0x48($sp)
/* BA722C 80242AAC 8FB10044 */  lw        $s1, 0x44($sp)
/* BA7230 80242AB0 8FB00040 */  lw        $s0, 0x40($sp)
/* BA7234 80242AB4 D7B40068 */  ldc1      $f20, 0x68($sp)
/* BA7238 80242AB8 03E00008 */  jr        $ra
/* BA723C 80242ABC 27BD0070 */   addiu    $sp, $sp, 0x70

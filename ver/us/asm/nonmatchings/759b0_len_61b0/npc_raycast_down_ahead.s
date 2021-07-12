.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel npc_raycast_down_ahead
/* 75C28 800DC778 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 75C2C 800DC77C F7B80068 */  sdc1      $f24, 0x68($sp)
/* 75C30 800DC780 C7B800A0 */  lwc1      $f24, 0xa0($sp)
/* 75C34 800DC784 AFB40050 */  sw        $s4, 0x50($sp)
/* 75C38 800DC788 8FB40098 */  lw        $s4, 0x98($sp)
/* 75C3C 800DC78C AFBF0054 */  sw        $ra, 0x54($sp)
/* 75C40 800DC790 AFB3004C */  sw        $s3, 0x4c($sp)
/* 75C44 800DC794 AFB20048 */  sw        $s2, 0x48($sp)
/* 75C48 800DC798 AFB10044 */  sw        $s1, 0x44($sp)
/* 75C4C 800DC79C AFB00040 */  sw        $s0, 0x40($sp)
/* 75C50 800DC7A0 F7BE0080 */  sdc1      $f30, 0x80($sp)
/* 75C54 800DC7A4 F7BC0078 */  sdc1      $f28, 0x78($sp)
/* 75C58 800DC7A8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 75C5C 800DC7AC F7B60060 */  sdc1      $f22, 0x60($sp)
/* 75C60 800DC7B0 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 75C64 800DC7B4 C4A60000 */  lwc1      $f6, ($a1)
/* 75C68 800DC7B8 00C0882D */  daddu     $s1, $a2, $zero
/* 75C6C 800DC7BC E7A60028 */  swc1      $f6, 0x28($sp)
/* 75C70 800DC7C0 C6260000 */  lwc1      $f6, ($s1)
/* 75C74 800DC7C4 0080902D */  daddu     $s2, $a0, $zero
/* 75C78 800DC7C8 E7A6002C */  swc1      $f6, 0x2c($sp)
/* 75C7C 800DC7CC C4E60000 */  lwc1      $f6, ($a3)
/* 75C80 800DC7D0 3C138011 */  lui       $s3, %hi(D_8010C970)
/* 75C84 800DC7D4 2673C970 */  addiu     $s3, $s3, %lo(D_8010C970)
/* 75C88 800DC7D8 E7A60030 */  swc1      $f6, 0x30($sp)
/* 75C8C 800DC7DC C7A6002C */  lwc1      $f6, 0x2c($sp)
/* 75C90 800DC7E0 44806000 */  mtc1      $zero, $f12
/* 75C94 800DC7E4 4600318D */  trunc.w.s $f6, $f6
/* 75C98 800DC7E8 E6660000 */  swc1      $f6, ($s3)
/* 75C9C 800DC7EC C6200000 */  lwc1      $f0, ($s1)
/* 75CA0 800DC7F0 3C014004 */  lui       $at, 0x4004
/* 75CA4 800DC7F4 44811800 */  mtc1      $at, $f3
/* 75CA8 800DC7F8 44801000 */  mtc1      $zero, $f2
/* 75CAC 800DC7FC 4600018D */  trunc.w.s $f6, $f0
/* 75CB0 800DC800 3C018011 */  lui       $at, %hi(D_8010C94C)
/* 75CB4 800DC804 E426C94C */  swc1      $f6, %lo(D_8010C94C)($at)
/* 75CB8 800DC808 C7A6009C */  lwc1      $f6, 0x9c($sp)
/* 75CBC 800DC80C C6200000 */  lwc1      $f0, ($s1)
/* 75CC0 800DC810 460C3300 */  add.s     $f12, $f6, $f12
/* 75CC4 800DC814 4600018D */  trunc.w.s $f6, $f0
/* 75CC8 800DC818 3C018011 */  lui       $at, %hi(D_8010C974)
/* 75CCC 800DC81C E426C974 */  swc1      $f6, %lo(D_8010C974)($at)
/* 75CD0 800DC820 4600C021 */  cvt.d.s   $f0, $f24
/* 75CD4 800DC824 46220003 */  div.d     $f0, $f0, $f2
/* 75CD8 800DC828 C6820000 */  lwc1      $f2, ($s4)
/* 75CDC 800DC82C 46200620 */  cvt.s.d   $f24, $f0
/* 75CE0 800DC830 0C00A6C9 */  jal       clamp_angle
/* 75CE4 800DC834 46001685 */   abs.s    $f26, $f2
/* 75CE8 800DC838 3C0140C9 */  lui       $at, 0x40c9
/* 75CEC 800DC83C 34210FD0 */  ori       $at, $at, 0xfd0
/* 75CF0 800DC840 44811000 */  mtc1      $at, $f2
/* 75CF4 800DC844 00000000 */  nop
/* 75CF8 800DC848 46020002 */  mul.s     $f0, $f0, $f2
/* 75CFC 800DC84C 00000000 */  nop
/* 75D00 800DC850 3C0143B4 */  lui       $at, 0x43b4
/* 75D04 800DC854 44811000 */  mtc1      $at, $f2
/* 75D08 800DC858 00000000 */  nop
/* 75D0C 800DC85C 46020503 */  div.s     $f20, $f0, $f2
/* 75D10 800DC860 0C00A85B */  jal       sin_rad
/* 75D14 800DC864 4600A306 */   mov.s    $f12, $f20
/* 75D18 800DC868 46000586 */  mov.s     $f22, $f0
/* 75D1C 800DC86C 0C00A874 */  jal       cos_rad
/* 75D20 800DC870 4600A306 */   mov.s    $f12, $f20
/* 75D24 800DC874 4616C102 */  mul.s     $f4, $f24, $f22
/* 75D28 800DC878 00000000 */  nop
/* 75D2C 800DC87C 0000802D */  daddu     $s0, $zero, $zero
/* 75D30 800DC880 0240202D */  daddu     $a0, $s2, $zero
/* 75D34 800DC884 27A50018 */  addiu     $a1, $sp, 0x18
/* 75D38 800DC888 4600C087 */  neg.s     $f2, $f24
/* 75D3C 800DC88C 46001002 */  mul.s     $f0, $f2, $f0
/* 75D40 800DC890 00000000 */  nop
/* 75D44 800DC894 27A6001C */  addiu     $a2, $sp, 0x1c
/* 75D48 800DC898 27A70020 */  addiu     $a3, $sp, 0x20
/* 75D4C 800DC89C C7A60028 */  lwc1      $f6, 0x28($sp)
/* 75D50 800DC8A0 3C01C6FF */  lui       $at, 0xc6ff
/* 75D54 800DC8A4 3421FE00 */  ori       $at, $at, 0xfe00
/* 75D58 800DC8A8 4481E000 */  mtc1      $at, $f28
/* 75D5C 800DC8AC 46043080 */  add.s     $f2, $f6, $f4
/* 75D60 800DC8B0 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* 75D64 800DC8B4 27A20024 */  addiu     $v0, $sp, 0x24
/* 75D68 800DC8B8 E7BA0024 */  swc1      $f26, 0x24($sp)
/* 75D6C 800DC8BC E7A6001C */  swc1      $f6, 0x1c($sp)
/* 75D70 800DC8C0 C7A60030 */  lwc1      $f6, 0x30($sp)
/* 75D74 800DC8C4 4600E786 */  mov.s     $f30, $f28
/* 75D78 800DC8C8 46003000 */  add.s     $f0, $f6, $f0
/* 75D7C 800DC8CC E7BC0038 */  swc1      $f28, 0x38($sp)
/* 75D80 800DC8D0 E7A20018 */  swc1      $f2, 0x18($sp)
/* 75D84 800DC8D4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 75D88 800DC8D8 0C037140 */  jal       npc_raycast_down
/* 75D8C 800DC8DC AFA20010 */   sw       $v0, 0x10($sp)
/* 75D90 800DC8E0 0440000F */  bltz      $v0, .L800DC920
/* 75D94 800DC8E4 E7BA0034 */   swc1     $f26, 0x34($sp)
/* 75D98 800DC8E8 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 75D9C 800DC8EC 461A003E */  c.le.s    $f0, $f26
/* 75DA0 800DC8F0 00000000 */  nop
/* 75DA4 800DC8F4 4500000A */  bc1f      .L800DC920
/* 75DA8 800DC8F8 00000000 */   nop
/* 75DAC 800DC8FC 46000686 */  mov.s     $f26, $f0
/* 75DB0 800DC900 C7BC001C */  lwc1      $f28, 0x1c($sp)
/* 75DB4 800DC904 24100001 */  addiu     $s0, $zero, 1
/* 75DB8 800DC908 3C018011 */  lui       $at, %hi(D_8010C978)
/* 75DBC 800DC90C AC22C978 */  sw        $v0, %lo(D_8010C978)($at)
/* 75DC0 800DC910 3C018011 */  lui       $at, %hi(D_8010C98C)
/* 75DC4 800DC914 AC22C98C */  sw        $v0, %lo(D_8010C98C)($at)
/* 75DC8 800DC918 4600E18D */  trunc.w.s $f6, $f28
/* 75DCC 800DC91C E6660000 */  swc1      $f6, ($s3)
.L800DC920:
/* 75DD0 800DC920 3C0142F0 */  lui       $at, 0x42f0
/* 75DD4 800DC924 44816000 */  mtc1      $at, $f12
/* 75DD8 800DC928 C7A6009C */  lwc1      $f6, 0x9c($sp)
/* 75DDC 800DC92C 0C00A6C9 */  jal       clamp_angle
/* 75DE0 800DC930 460C3300 */   add.s    $f12, $f6, $f12
/* 75DE4 800DC934 3C0140C9 */  lui       $at, 0x40c9
/* 75DE8 800DC938 34210FD0 */  ori       $at, $at, 0xfd0
/* 75DEC 800DC93C 44811000 */  mtc1      $at, $f2
/* 75DF0 800DC940 00000000 */  nop
/* 75DF4 800DC944 46020002 */  mul.s     $f0, $f0, $f2
/* 75DF8 800DC948 00000000 */  nop
/* 75DFC 800DC94C 3C0143B4 */  lui       $at, 0x43b4
/* 75E00 800DC950 44811000 */  mtc1      $at, $f2
/* 75E04 800DC954 00000000 */  nop
/* 75E08 800DC958 46020503 */  div.s     $f20, $f0, $f2
/* 75E0C 800DC95C 0C00A85B */  jal       sin_rad
/* 75E10 800DC960 4600A306 */   mov.s    $f12, $f20
/* 75E14 800DC964 46000586 */  mov.s     $f22, $f0
/* 75E18 800DC968 0C00A874 */  jal       cos_rad
/* 75E1C 800DC96C 4600A306 */   mov.s    $f12, $f20
/* 75E20 800DC970 4616C102 */  mul.s     $f4, $f24, $f22
/* 75E24 800DC974 00000000 */  nop
/* 75E28 800DC978 4600C087 */  neg.s     $f2, $f24
/* 75E2C 800DC97C 46001002 */  mul.s     $f0, $f2, $f0
/* 75E30 800DC980 00000000 */  nop
/* 75E34 800DC984 0240202D */  daddu     $a0, $s2, $zero
/* 75E38 800DC988 C7A60028 */  lwc1      $f6, 0x28($sp)
/* 75E3C 800DC98C 27A50018 */  addiu     $a1, $sp, 0x18
/* 75E40 800DC990 46043080 */  add.s     $f2, $f6, $f4
/* 75E44 800DC994 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* 75E48 800DC998 27A6001C */  addiu     $a2, $sp, 0x1c
/* 75E4C 800DC99C E7A6001C */  swc1      $f6, 0x1c($sp)
/* 75E50 800DC9A0 C7A60030 */  lwc1      $f6, 0x30($sp)
/* 75E54 800DC9A4 27A70020 */  addiu     $a3, $sp, 0x20
/* 75E58 800DC9A8 46003000 */  add.s     $f0, $f6, $f0
/* 75E5C 800DC9AC C7A60034 */  lwc1      $f6, 0x34($sp)
/* 75E60 800DC9B0 27A20024 */  addiu     $v0, $sp, 0x24
/* 75E64 800DC9B4 E7A20018 */  swc1      $f2, 0x18($sp)
/* 75E68 800DC9B8 E7A60024 */  swc1      $f6, 0x24($sp)
/* 75E6C 800DC9BC E7A00020 */  swc1      $f0, 0x20($sp)
/* 75E70 800DC9C0 0C037140 */  jal       npc_raycast_down
/* 75E74 800DC9C4 AFA20010 */   sw       $v0, 0x10($sp)
/* 75E78 800DC9C8 04400010 */  bltz      $v0, .L800DCA0C
/* 75E7C 800DC9CC 00000000 */   nop
/* 75E80 800DC9D0 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 75E84 800DC9D4 461A003E */  c.le.s    $f0, $f26
/* 75E88 800DC9D8 00000000 */  nop
/* 75E8C 800DC9DC 4500000B */  bc1f      .L800DCA0C
/* 75E90 800DC9E0 00000000 */   nop
/* 75E94 800DC9E4 46000686 */  mov.s     $f26, $f0
/* 75E98 800DC9E8 C7BE001C */  lwc1      $f30, 0x1c($sp)
/* 75E9C 800DC9EC 24100001 */  addiu     $s0, $zero, 1
/* 75EA0 800DC9F0 3C018011 */  lui       $at, %hi(D_8010C978)
/* 75EA4 800DC9F4 AC22C978 */  sw        $v0, %lo(D_8010C978)($at)
/* 75EA8 800DC9F8 3C018011 */  lui       $at, %hi(D_8010C968)
/* 75EAC 800DC9FC AC22C968 */  sw        $v0, %lo(D_8010C968)($at)
/* 75EB0 800DCA00 4600F18D */  trunc.w.s $f6, $f30
/* 75EB4 800DCA04 3C018011 */  lui       $at, %hi(D_8010C94C)
/* 75EB8 800DCA08 E426C94C */  swc1      $f6, %lo(D_8010C94C)($at)
.L800DCA0C:
/* 75EBC 800DCA0C 3C0142F0 */  lui       $at, 0x42f0
/* 75EC0 800DCA10 44816000 */  mtc1      $at, $f12
/* 75EC4 800DCA14 C7A6009C */  lwc1      $f6, 0x9c($sp)
/* 75EC8 800DCA18 0C00A6C9 */  jal       clamp_angle
/* 75ECC 800DCA1C 460C3301 */   sub.s    $f12, $f6, $f12
/* 75ED0 800DCA20 3C0140C9 */  lui       $at, 0x40c9
/* 75ED4 800DCA24 34210FD0 */  ori       $at, $at, 0xfd0
/* 75ED8 800DCA28 44811000 */  mtc1      $at, $f2
/* 75EDC 800DCA2C 00000000 */  nop
/* 75EE0 800DCA30 46020002 */  mul.s     $f0, $f0, $f2
/* 75EE4 800DCA34 00000000 */  nop
/* 75EE8 800DCA38 3C0143B4 */  lui       $at, 0x43b4
/* 75EEC 800DCA3C 44811000 */  mtc1      $at, $f2
/* 75EF0 800DCA40 00000000 */  nop
/* 75EF4 800DCA44 46020503 */  div.s     $f20, $f0, $f2
/* 75EF8 800DCA48 0C00A85B */  jal       sin_rad
/* 75EFC 800DCA4C 4600A306 */   mov.s    $f12, $f20
/* 75F00 800DCA50 46000586 */  mov.s     $f22, $f0
/* 75F04 800DCA54 0C00A874 */  jal       cos_rad
/* 75F08 800DCA58 4600A306 */   mov.s    $f12, $f20
/* 75F0C 800DCA5C 4616C102 */  mul.s     $f4, $f24, $f22
/* 75F10 800DCA60 00000000 */  nop
/* 75F14 800DCA64 4600C087 */  neg.s     $f2, $f24
/* 75F18 800DCA68 46001002 */  mul.s     $f0, $f2, $f0
/* 75F1C 800DCA6C 00000000 */  nop
/* 75F20 800DCA70 0240202D */  daddu     $a0, $s2, $zero
/* 75F24 800DCA74 C7A60028 */  lwc1      $f6, 0x28($sp)
/* 75F28 800DCA78 27A50018 */  addiu     $a1, $sp, 0x18
/* 75F2C 800DCA7C 46043080 */  add.s     $f2, $f6, $f4
/* 75F30 800DCA80 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* 75F34 800DCA84 27A6001C */  addiu     $a2, $sp, 0x1c
/* 75F38 800DCA88 E7A6001C */  swc1      $f6, 0x1c($sp)
/* 75F3C 800DCA8C C7A60030 */  lwc1      $f6, 0x30($sp)
/* 75F40 800DCA90 27A70020 */  addiu     $a3, $sp, 0x20
/* 75F44 800DCA94 46003000 */  add.s     $f0, $f6, $f0
/* 75F48 800DCA98 C7A60034 */  lwc1      $f6, 0x34($sp)
/* 75F4C 800DCA9C 27A20024 */  addiu     $v0, $sp, 0x24
/* 75F50 800DCAA0 E7A20018 */  swc1      $f2, 0x18($sp)
/* 75F54 800DCAA4 E7A60024 */  swc1      $f6, 0x24($sp)
/* 75F58 800DCAA8 E7A00020 */  swc1      $f0, 0x20($sp)
/* 75F5C 800DCAAC 0C037140 */  jal       npc_raycast_down
/* 75F60 800DCAB0 AFA20010 */   sw       $v0, 0x10($sp)
/* 75F64 800DCAB4 04400011 */  bltz      $v0, .L800DCAFC
/* 75F68 800DCAB8 00000000 */   nop
/* 75F6C 800DCABC C7A00024 */  lwc1      $f0, 0x24($sp)
/* 75F70 800DCAC0 461A003E */  c.le.s    $f0, $f26
/* 75F74 800DCAC4 00000000 */  nop
/* 75F78 800DCAC8 4500000C */  bc1f      .L800DCAFC
/* 75F7C 800DCACC 00000000 */   nop
/* 75F80 800DCAD0 46000686 */  mov.s     $f26, $f0
/* 75F84 800DCAD4 C7A6001C */  lwc1      $f6, 0x1c($sp)
/* 75F88 800DCAD8 24100001 */  addiu     $s0, $zero, 1
/* 75F8C 800DCADC 3C018011 */  lui       $at, %hi(D_8010C978)
/* 75F90 800DCAE0 AC22C978 */  sw        $v0, %lo(D_8010C978)($at)
/* 75F94 800DCAE4 3C018011 */  lui       $at, %hi(D_8010C968)
/* 75F98 800DCAE8 AC22C968 */  sw        $v0, %lo(D_8010C968)($at)
/* 75F9C 800DCAEC E7A60038 */  swc1      $f6, 0x38($sp)
/* 75FA0 800DCAF0 4600318D */  trunc.w.s $f6, $f6
/* 75FA4 800DCAF4 3C018011 */  lui       $at, %hi(D_8010C974)
/* 75FA8 800DCAF8 E426C974 */  swc1      $f6, %lo(D_8010C974)($at)
.L800DCAFC:
/* 75FAC 800DCAFC 1200000F */  beqz      $s0, .L800DCB3C
/* 75FB0 800DCB00 0000102D */   daddu    $v0, $zero, $zero
/* 75FB4 800DCB04 461EE03C */  c.lt.s    $f28, $f30
/* 75FB8 800DCB08 00000000 */  nop
/* 75FBC 800DCB0C 45020002 */  bc1fl     .L800DCB18
/* 75FC0 800DCB10 E63C0000 */   swc1     $f28, ($s1)
/* 75FC4 800DCB14 E63E0000 */  swc1      $f30, ($s1)
.L800DCB18:
/* 75FC8 800DCB18 C6200000 */  lwc1      $f0, ($s1)
/* 75FCC 800DCB1C C7A60038 */  lwc1      $f6, 0x38($sp)
/* 75FD0 800DCB20 4606003C */  c.lt.s    $f0, $f6
/* 75FD4 800DCB24 00000000 */  nop
/* 75FD8 800DCB28 45030001 */  bc1tl     .L800DCB30
/* 75FDC 800DCB2C E6260000 */   swc1     $f6, ($s1)
.L800DCB30:
/* 75FE0 800DCB30 E69A0000 */  swc1      $f26, ($s4)
/* 75FE4 800DCB34 080372D1 */  j         .L800DCB44
/* 75FE8 800DCB38 24020001 */   addiu    $v0, $zero, 1
.L800DCB3C:
/* 75FEC 800DCB3C C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 75FF0 800DCB40 E6200000 */  swc1      $f0, ($s1)
.L800DCB44:
/* 75FF4 800DCB44 8FBF0054 */  lw        $ra, 0x54($sp)
/* 75FF8 800DCB48 8FB40050 */  lw        $s4, 0x50($sp)
/* 75FFC 800DCB4C 8FB3004C */  lw        $s3, 0x4c($sp)
/* 76000 800DCB50 8FB20048 */  lw        $s2, 0x48($sp)
/* 76004 800DCB54 8FB10044 */  lw        $s1, 0x44($sp)
/* 76008 800DCB58 8FB00040 */  lw        $s0, 0x40($sp)
/* 7600C 800DCB5C D7BE0080 */  ldc1      $f30, 0x80($sp)
/* 76010 800DCB60 D7BC0078 */  ldc1      $f28, 0x78($sp)
/* 76014 800DCB64 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 76018 800DCB68 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 7601C 800DCB6C D7B60060 */  ldc1      $f22, 0x60($sp)
/* 76020 800DCB70 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 76024 800DCB74 03E00008 */  jr        $ra
/* 76028 800DCB78 27BD0088 */   addiu    $sp, $sp, 0x88

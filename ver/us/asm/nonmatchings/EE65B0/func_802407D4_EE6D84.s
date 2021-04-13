.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D4_EE6D84
/* EE6D84 802407D4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* EE6D88 802407D8 24040001 */  addiu     $a0, $zero, 1
/* EE6D8C 802407DC 27A50010 */  addiu     $a1, $sp, 0x10
/* EE6D90 802407E0 27A60014 */  addiu     $a2, $sp, 0x14
/* EE6D94 802407E4 AFBF0030 */  sw        $ra, 0x30($sp)
/* EE6D98 802407E8 AFB3002C */  sw        $s3, 0x2c($sp)
/* EE6D9C 802407EC AFB20028 */  sw        $s2, 0x28($sp)
/* EE6DA0 802407F0 AFB10024 */  sw        $s1, 0x24($sp)
/* EE6DA4 802407F4 AFB00020 */  sw        $s0, 0x20($sp)
/* EE6DA8 802407F8 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* EE6DAC 802407FC F7B80048 */  sdc1      $f24, 0x48($sp)
/* EE6DB0 80240800 F7B60040 */  sdc1      $f22, 0x40($sp)
/* EE6DB4 80240804 F7B40038 */  sdc1      $f20, 0x38($sp)
/* EE6DB8 80240808 0C0499BE */  jal       func_801266F8
/* EE6DBC 8024080C 27A70018 */   addiu    $a3, $sp, 0x18
/* EE6DC0 80240810 8FA20018 */  lw        $v0, 0x18($sp)
/* EE6DC4 80240814 18400072 */  blez      $v0, .L802409E0
/* EE6DC8 80240818 0000902D */   daddu    $s2, $zero, $zero
/* EE6DCC 8024081C 3C138024 */  lui       $s3, %hi(D_80243B48_EEA0F8)
/* EE6DD0 80240820 26733B48 */  addiu     $s3, $s3, %lo(D_80243B48_EEA0F8)
/* EE6DD4 80240824 3C014334 */  lui       $at, 0x4334
/* EE6DD8 80240828 4481D000 */  mtc1      $at, $f26
/* EE6DDC 8024082C 3C018024 */  lui       $at, %hi(D_80245360_EEB910)
/* EE6DE0 80240830 D4385360 */  ldc1      $f24, %lo(D_80245360_EEB910)($at)
/* EE6DE4 80240834 3C018024 */  lui       $at, %hi(D_80245368_EEB918)
/* EE6DE8 80240838 D4365368 */  ldc1      $f22, %lo(D_80245368_EEB918)($at)
/* EE6DEC 8024083C 00122100 */  sll       $a0, $s2, 4
.L80240840:
/* EE6DF0 80240840 8FA20010 */  lw        $v0, 0x10($sp)
/* EE6DF4 80240844 8FA30014 */  lw        $v1, 0x14($sp)
/* EE6DF8 80240848 00448021 */  addu      $s0, $v0, $a0
/* EE6DFC 8024084C 86020000 */  lh        $v0, ($s0)
/* EE6E00 80240850 28420259 */  slti      $v0, $v0, 0x259
/* EE6E04 80240854 1040005D */  beqz      $v0, .L802409CC
/* EE6E08 80240858 00648821 */   addu     $s1, $v1, $a0
/* EE6E0C 8024085C C66C0000 */  lwc1      $f12, ($s3)
/* EE6E10 80240860 46806320 */  cvt.s.w   $f12, $f12
/* EE6E14 80240864 461A6303 */  div.s     $f12, $f12, $f26
/* EE6E18 80240868 46006321 */  cvt.d.s   $f12, $f12
/* EE6E1C 8024086C 46386302 */  mul.d     $f12, $f12, $f24
/* EE6E20 80240870 00000000 */  nop
/* EE6E24 80240874 0C00AD17 */  jal       func_8002B45C
/* EE6E28 80240878 46206320 */   cvt.s.d  $f12, $f12
/* EE6E2C 8024087C C66C0000 */  lwc1      $f12, ($s3)
/* EE6E30 80240880 46806320 */  cvt.s.w   $f12, $f12
/* EE6E34 80240884 461A6303 */  div.s     $f12, $f12, $f26
/* EE6E38 80240888 46006321 */  cvt.d.s   $f12, $f12
/* EE6E3C 8024088C 46386302 */  mul.d     $f12, $f12, $f24
/* EE6E40 80240890 00000000 */  nop
/* EE6E44 80240894 3C018024 */  lui       $at, %hi(D_80245370_EEB920)
/* EE6E48 80240898 D4225370 */  ldc1      $f2, %lo(D_80245370_EEB920)($at)
/* EE6E4C 8024089C 46000521 */  cvt.d.s   $f20, $f0
/* EE6E50 802408A0 4622A502 */  mul.d     $f20, $f20, $f2
/* EE6E54 802408A4 00000000 */  nop
/* EE6E58 802408A8 3C018024 */  lui       $at, %hi(D_80245378_EEB928)
/* EE6E5C 802408AC D4205378 */  ldc1      $f0, %lo(D_80245378_EEB928)($at)
/* EE6E60 802408B0 4620A500 */  add.d     $f20, $f20, $f0
/* EE6E64 802408B4 46206320 */  cvt.s.d   $f12, $f12
/* EE6E68 802408B8 0C00AD17 */  jal       func_8002B45C
/* EE6E6C 802408BC 4620A520 */   cvt.s.d  $f20, $f20
/* EE6E70 802408C0 46000021 */  cvt.d.s   $f0, $f0
/* EE6E74 802408C4 46360002 */  mul.d     $f0, $f0, $f22
/* EE6E78 802408C8 00000000 */  nop
/* EE6E7C 802408CC 86020000 */  lh        $v0, ($s0)
/* EE6E80 802408D0 2442FD98 */  addiu     $v0, $v0, -0x268
/* EE6E84 802408D4 44822000 */  mtc1      $v0, $f4
/* EE6E88 802408D8 00000000 */  nop
/* EE6E8C 802408DC 46802120 */  cvt.s.w   $f4, $f4
/* EE6E90 802408E0 46142102 */  mul.s     $f4, $f4, $f20
/* EE6E94 802408E4 00000000 */  nop
/* EE6E98 802408E8 4620B001 */  sub.d     $f0, $f22, $f0
/* EE6E9C 802408EC 3C01C240 */  lui       $at, 0xc240
/* EE6EA0 802408F0 44813000 */  mtc1      $at, $f6
/* EE6EA4 802408F4 46200020 */  cvt.s.d   $f0, $f0
/* EE6EA8 802408F8 46060182 */  mul.s     $f6, $f0, $f6
/* EE6EAC 802408FC 00000000 */  nop
/* EE6EB0 80240900 3C01441A */  lui       $at, 0x441a
/* EE6EB4 80240904 44811000 */  mtc1      $at, $f2
/* EE6EB8 80240908 00000000 */  nop
/* EE6EBC 8024090C 46022100 */  add.s     $f4, $f4, $f2
/* EE6EC0 80240910 46062100 */  add.s     $f4, $f4, $f6
/* EE6EC4 80240914 3C0141C8 */  lui       $at, 0x41c8
/* EE6EC8 80240918 44813000 */  mtc1      $at, $f6
/* EE6ECC 8024091C 00000000 */  nop
/* EE6ED0 80240920 46060182 */  mul.s     $f6, $f0, $f6
/* EE6ED4 80240924 00000000 */  nop
/* EE6ED8 80240928 4600220D */  trunc.w.s $f8, $f4
/* EE6EDC 8024092C 44024000 */  mfc1      $v0, $f8
/* EE6EE0 80240930 00000000 */  nop
/* EE6EE4 80240934 A6220000 */  sh        $v0, ($s1)
/* EE6EE8 80240938 86020002 */  lh        $v0, 2($s0)
/* EE6EEC 8024093C 2442FFD4 */  addiu     $v0, $v0, -0x2c
/* EE6EF0 80240940 44821000 */  mtc1      $v0, $f2
/* EE6EF4 80240944 00000000 */  nop
/* EE6EF8 80240948 468010A0 */  cvt.s.w   $f2, $f2
/* EE6EFC 8024094C 46141082 */  mul.s     $f2, $f2, $f20
/* EE6F00 80240950 00000000 */  nop
/* EE6F04 80240954 3C014230 */  lui       $at, 0x4230
/* EE6F08 80240958 44812000 */  mtc1      $at, $f4
/* EE6F0C 8024095C 00000000 */  nop
/* EE6F10 80240960 46041080 */  add.s     $f2, $f2, $f4
/* EE6F14 80240964 46061080 */  add.s     $f2, $f2, $f6
/* EE6F18 80240968 3C01C2AE */  lui       $at, 0xc2ae
/* EE6F1C 8024096C 44812000 */  mtc1      $at, $f4
/* EE6F20 80240970 00000000 */  nop
/* EE6F24 80240974 46040002 */  mul.s     $f0, $f0, $f4
/* EE6F28 80240978 00000000 */  nop
/* EE6F2C 8024097C 4600120D */  trunc.w.s $f8, $f2
/* EE6F30 80240980 44024000 */  mfc1      $v0, $f8
/* EE6F34 80240984 00000000 */  nop
/* EE6F38 80240988 A6220002 */  sh        $v0, 2($s1)
/* EE6F3C 8024098C 86020004 */  lh        $v0, 4($s0)
/* EE6F40 80240990 2442FF8F */  addiu     $v0, $v0, -0x71
/* EE6F44 80240994 44821000 */  mtc1      $v0, $f2
/* EE6F48 80240998 00000000 */  nop
/* EE6F4C 8024099C 468010A0 */  cvt.s.w   $f2, $f2
/* EE6F50 802409A0 46141082 */  mul.s     $f2, $f2, $f20
/* EE6F54 802409A4 00000000 */  nop
/* EE6F58 802409A8 3C0142E2 */  lui       $at, 0x42e2
/* EE6F5C 802409AC 44812000 */  mtc1      $at, $f4
/* EE6F60 802409B0 00000000 */  nop
/* EE6F64 802409B4 46041080 */  add.s     $f2, $f2, $f4
/* EE6F68 802409B8 46001080 */  add.s     $f2, $f2, $f0
/* EE6F6C 802409BC 4600120D */  trunc.w.s $f8, $f2
/* EE6F70 802409C0 44024000 */  mfc1      $v0, $f8
/* EE6F74 802409C4 00000000 */  nop
/* EE6F78 802409C8 A6220004 */  sh        $v0, 4($s1)
.L802409CC:
/* EE6F7C 802409CC 8FA20018 */  lw        $v0, 0x18($sp)
/* EE6F80 802409D0 26520001 */  addiu     $s2, $s2, 1
/* EE6F84 802409D4 0242102A */  slt       $v0, $s2, $v0
/* EE6F88 802409D8 1440FF99 */  bnez      $v0, .L80240840
/* EE6F8C 802409DC 00122100 */   sll      $a0, $s2, 4
.L802409E0:
/* EE6F90 802409E0 3C03800A */  lui       $v1, %hi(D_800A15C4)
/* EE6F94 802409E4 246315C4 */  addiu     $v1, $v1, %lo(D_800A15C4)
/* EE6F98 802409E8 8C620000 */  lw        $v0, ($v1)
/* EE6F9C 802409EC 24040001 */  addiu     $a0, $zero, 1
/* EE6FA0 802409F0 0040802D */  daddu     $s0, $v0, $zero
/* EE6FA4 802409F4 24420008 */  addiu     $v0, $v0, 8
/* EE6FA8 802409F8 AC620000 */  sw        $v0, ($v1)
/* EE6FAC 802409FC 3C02DE00 */  lui       $v0, 0xde00
/* EE6FB0 80240A00 0C0499CD */  jal       func_80126734
/* EE6FB4 80240A04 AE020000 */   sw       $v0, ($s0)
/* EE6FB8 80240A08 0000202D */  daddu     $a0, $zero, $zero
/* EE6FBC 80240A0C 3C05F971 */  lui       $a1, 0xf971
/* EE6FC0 80240A10 34A588A4 */  ori       $a1, $a1, 0x88a4
/* EE6FC4 80240A14 0C0B53A3 */  jal       dead_get_variable
/* EE6FC8 80240A18 AE020004 */   sw       $v0, 4($s0)
/* EE6FCC 80240A1C 10400017 */  beqz      $v0, .L80240A7C
/* EE6FD0 80240A20 00000000 */   nop
/* EE6FD4 80240A24 3C048024 */  lui       $a0, %hi(D_80243B48_EEA0F8)
/* EE6FD8 80240A28 24843B48 */  addiu     $a0, $a0, %lo(D_80243B48_EEA0F8)
/* EE6FDC 80240A2C 8C830000 */  lw        $v1, ($a0)
/* EE6FE0 80240A30 2862005B */  slti      $v0, $v1, 0x5b
/* EE6FE4 80240A34 14400005 */  bnez      $v0, .L80240A4C
/* EE6FE8 80240A38 2862FFA6 */   slti     $v0, $v1, -0x5a
/* EE6FEC 80240A3C 2462FE98 */  addiu     $v0, $v1, -0x168
/* EE6FF0 80240A40 AC820000 */  sw        $v0, ($a0)
/* EE6FF4 80240A44 8C830000 */  lw        $v1, ($a0)
/* EE6FF8 80240A48 2862FFA6 */  slti      $v0, $v1, -0x5a
.L80240A4C:
/* EE6FFC 80240A4C 14400002 */  bnez      $v0, .L80240A58
/* EE7000 80240A50 24620014 */   addiu    $v0, $v1, 0x14
/* EE7004 80240A54 24620005 */  addiu     $v0, $v1, 5
.L80240A58:
/* EE7008 80240A58 AC820000 */  sw        $v0, ($a0)
/* EE700C 80240A5C 3C038024 */  lui       $v1, %hi(D_80243B48_EEA0F8)
/* EE7010 80240A60 24633B48 */  addiu     $v1, $v1, %lo(D_80243B48_EEA0F8)
/* EE7014 80240A64 8C620000 */  lw        $v0, ($v1)
/* EE7018 80240A68 2842005A */  slti      $v0, $v0, 0x5a
/* EE701C 80240A6C 14400013 */  bnez      $v0, .L80240ABC
/* EE7020 80240A70 2402005A */   addiu    $v0, $zero, 0x5a
/* EE7024 80240A74 080902AF */  j         .L80240ABC
/* EE7028 80240A78 AC620000 */   sw       $v0, ($v1)
.L80240A7C:
/* EE702C 80240A7C 3C028024 */  lui       $v0, %hi(D_80243B48_EEA0F8)
/* EE7030 80240A80 8C423B48 */  lw        $v0, %lo(D_80243B48_EEA0F8)($v0)
/* EE7034 80240A84 2442FF73 */  addiu     $v0, $v0, -0x8d
/* EE7038 80240A88 2C420077 */  sltiu     $v0, $v0, 0x77
/* EE703C 80240A8C 10400004 */  beqz      $v0, .L80240AA0
/* EE7040 80240A90 24020001 */   addiu    $v0, $zero, 1
/* EE7044 80240A94 3C018024 */  lui       $at, %hi(D_802431FC_EE97AC)
/* EE7048 80240A98 080902AA */  j         .L80240AA8
/* EE704C 80240A9C AC2231FC */   sw       $v0, %lo(D_802431FC_EE97AC)($at)
.L80240AA0:
/* EE7050 80240AA0 3C018024 */  lui       $at, %hi(D_802431FC_EE97AC)
/* EE7054 80240AA4 AC2031FC */  sw        $zero, %lo(D_802431FC_EE97AC)($at)
.L80240AA8:
/* EE7058 80240AA8 3C038024 */  lui       $v1, %hi(D_80243B48_EEA0F8)
/* EE705C 80240AAC 24633B48 */  addiu     $v1, $v1, %lo(D_80243B48_EEA0F8)
/* EE7060 80240AB0 8C620000 */  lw        $v0, ($v1)
/* EE7064 80240AB4 24420005 */  addiu     $v0, $v0, 5
/* EE7068 80240AB8 AC620000 */  sw        $v0, ($v1)
.L80240ABC:
/* EE706C 80240ABC 3C048024 */  lui       $a0, %hi(D_80243B48_EEA0F8)
/* EE7070 80240AC0 24843B48 */  addiu     $a0, $a0, %lo(D_80243B48_EEA0F8)
/* EE7074 80240AC4 8C830000 */  lw        $v1, ($a0)
/* EE7078 80240AC8 28620168 */  slti      $v0, $v1, 0x168
/* EE707C 80240ACC 14400002 */  bnez      $v0, .L80240AD8
/* EE7080 80240AD0 2462FE98 */   addiu    $v0, $v1, -0x168
/* EE7084 80240AD4 AC820000 */  sw        $v0, ($a0)
.L80240AD8:
/* EE7088 80240AD8 8FBF0030 */  lw        $ra, 0x30($sp)
/* EE708C 80240ADC 8FB3002C */  lw        $s3, 0x2c($sp)
/* EE7090 80240AE0 8FB20028 */  lw        $s2, 0x28($sp)
/* EE7094 80240AE4 8FB10024 */  lw        $s1, 0x24($sp)
/* EE7098 80240AE8 8FB00020 */  lw        $s0, 0x20($sp)
/* EE709C 80240AEC D7BA0050 */  ldc1      $f26, 0x50($sp)
/* EE70A0 80240AF0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* EE70A4 80240AF4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* EE70A8 80240AF8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* EE70AC 80240AFC 03E00008 */  jr        $ra
/* EE70B0 80240B00 27BD0058 */   addiu    $sp, $sp, 0x58
/* EE70B4 80240B04 00000000 */  nop
/* EE70B8 80240B08 00000000 */  nop
/* EE70BC 80240B0C 00000000 */  nop

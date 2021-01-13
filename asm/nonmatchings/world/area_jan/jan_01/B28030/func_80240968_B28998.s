.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240968_B28998
/* B28998 80240968 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B2899C 8024096C AFB40040 */  sw        $s4, 0x40($sp)
/* B289A0 80240970 0080A02D */  daddu     $s4, $a0, $zero
/* B289A4 80240974 AFBF0044 */  sw        $ra, 0x44($sp)
/* B289A8 80240978 AFB3003C */  sw        $s3, 0x3c($sp)
/* B289AC 8024097C AFB20038 */  sw        $s2, 0x38($sp)
/* B289B0 80240980 AFB10034 */  sw        $s1, 0x34($sp)
/* B289B4 80240984 AFB00030 */  sw        $s0, 0x30($sp)
/* B289B8 80240988 8E920148 */  lw        $s2, 0x148($s4)
/* B289BC 8024098C 00A0882D */  daddu     $s1, $a1, $zero
/* B289C0 80240990 86440008 */  lh        $a0, 8($s2)
/* B289C4 80240994 0C00EABB */  jal       get_npc_unsafe
/* B289C8 80240998 00C0982D */   daddu    $s3, $a2, $zero
/* B289CC 8024099C 8E230014 */  lw        $v1, 0x14($s1)
/* B289D0 802409A0 0460002D */  bltz      $v1, .L80240A58
/* B289D4 802409A4 0040802D */   daddu    $s0, $v0, $zero
/* B289D8 802409A8 0260202D */  daddu     $a0, $s3, $zero
/* B289DC 802409AC AFA00010 */  sw        $zero, 0x10($sp)
/* B289E0 802409B0 8E260024 */  lw        $a2, 0x24($s1)
/* B289E4 802409B4 8E270028 */  lw        $a3, 0x28($s1)
/* B289E8 802409B8 0C01242D */  jal       func_800490B4
/* B289EC 802409BC 0240282D */   daddu    $a1, $s2, $zero
/* B289F0 802409C0 10400025 */  beqz      $v0, .L80240A58
/* B289F4 802409C4 0000202D */   daddu    $a0, $zero, $zero
/* B289F8 802409C8 0200282D */  daddu     $a1, $s0, $zero
/* B289FC 802409CC 0000302D */  daddu     $a2, $zero, $zero
/* B28A00 802409D0 860300A8 */  lh        $v1, 0xa8($s0)
/* B28A04 802409D4 3C013F80 */  lui       $at, 0x3f80
/* B28A08 802409D8 44810000 */  mtc1      $at, $f0
/* B28A0C 802409DC 3C014000 */  lui       $at, 0x4000
/* B28A10 802409E0 44811000 */  mtc1      $at, $f2
/* B28A14 802409E4 3C01C1A0 */  lui       $at, 0xc1a0
/* B28A18 802409E8 44812000 */  mtc1      $at, $f4
/* B28A1C 802409EC 2402000F */  addiu     $v0, $zero, 0xf
/* B28A20 802409F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B28A24 802409F4 44833000 */  mtc1      $v1, $f6
/* B28A28 802409F8 00000000 */  nop
/* B28A2C 802409FC 468031A0 */  cvt.s.w   $f6, $f6
/* B28A30 80240A00 44073000 */  mfc1      $a3, $f6
/* B28A34 80240A04 27A20028 */  addiu     $v0, $sp, 0x28
/* B28A38 80240A08 AFA20020 */  sw        $v0, 0x20($sp)
/* B28A3C 80240A0C E7A00010 */  swc1      $f0, 0x10($sp)
/* B28A40 80240A10 E7A20014 */  swc1      $f2, 0x14($sp)
/* B28A44 80240A14 0C01BFA4 */  jal       fx_emote
/* B28A48 80240A18 E7A40018 */   swc1     $f4, 0x18($sp)
/* B28A4C 80240A1C 0200202D */  daddu     $a0, $s0, $zero
/* B28A50 80240A20 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B28A54 80240A24 0C012530 */  jal       func_800494C0
/* B28A58 80240A28 3C060020 */   lui      $a2, 0x20
/* B28A5C 80240A2C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B28A60 80240A30 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B28A64 80240A34 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B28A68 80240A38 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B28A6C 80240A3C 8C460028 */  lw        $a2, 0x28($v0)
/* B28A70 80240A40 0C00A720 */  jal       atan2
/* B28A74 80240A44 8C470030 */   lw       $a3, 0x30($v0)
/* B28A78 80240A48 2402000C */  addiu     $v0, $zero, 0xc
/* B28A7C 80240A4C E600000C */  swc1      $f0, 0xc($s0)
/* B28A80 80240A50 080902BB */  j         .L80240AEC
/* B28A84 80240A54 AE820070 */   sw       $v0, 0x70($s4)
.L80240A58:
/* B28A88 80240A58 8602008C */  lh        $v0, 0x8c($s0)
/* B28A8C 80240A5C 14400023 */  bnez      $v0, .L80240AEC
/* B28A90 80240A60 00000000 */   nop
/* B28A94 80240A64 9602008E */  lhu       $v0, 0x8e($s0)
/* B28A98 80240A68 2442FFFF */  addiu     $v0, $v0, -1
/* B28A9C 80240A6C A602008E */  sh        $v0, 0x8e($s0)
/* B28AA0 80240A70 00021400 */  sll       $v0, $v0, 0x10
/* B28AA4 80240A74 1C40001D */  bgtz      $v0, .L80240AEC
/* B28AA8 80240A78 00000000 */   nop
/* B28AAC 80240A7C 8E820074 */  lw        $v0, 0x74($s4)
/* B28AB0 80240A80 2442FFFF */  addiu     $v0, $v0, -1
/* B28AB4 80240A84 18400018 */  blez      $v0, .L80240AE8
/* B28AB8 80240A88 AE820074 */   sw       $v0, 0x74($s4)
/* B28ABC 80240A8C C600000C */  lwc1      $f0, 0xc($s0)
/* B28AC0 80240A90 3C014334 */  lui       $at, 0x4334
/* B28AC4 80240A94 44816000 */  mtc1      $at, $f12
/* B28AC8 80240A98 0C00A6C9 */  jal       clamp_angle
/* B28ACC 80240A9C 460C0300 */   add.s    $f12, $f0, $f12
/* B28AD0 80240AA0 240403E8 */  addiu     $a0, $zero, 0x3e8
/* B28AD4 80240AA4 0C00A67F */  jal       rand_int
/* B28AD8 80240AA8 E600000C */   swc1     $f0, 0xc($s0)
/* B28ADC 80240AAC 3C032E8B */  lui       $v1, 0x2e8b
/* B28AE0 80240AB0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* B28AE4 80240AB4 00430018 */  mult      $v0, $v1
/* B28AE8 80240AB8 00021FC3 */  sra       $v1, $v0, 0x1f
/* B28AEC 80240ABC 00004010 */  mfhi      $t0
/* B28AF0 80240AC0 00082043 */  sra       $a0, $t0, 1
/* B28AF4 80240AC4 00832023 */  subu      $a0, $a0, $v1
/* B28AF8 80240AC8 00041840 */  sll       $v1, $a0, 1
/* B28AFC 80240ACC 00641821 */  addu      $v1, $v1, $a0
/* B28B00 80240AD0 00031880 */  sll       $v1, $v1, 2
/* B28B04 80240AD4 00641823 */  subu      $v1, $v1, $a0
/* B28B08 80240AD8 00431023 */  subu      $v0, $v0, $v1
/* B28B0C 80240ADC 24420005 */  addiu     $v0, $v0, 5
/* B28B10 80240AE0 080902BB */  j         .L80240AEC
/* B28B14 80240AE4 A602008E */   sh       $v0, 0x8e($s0)
.L80240AE8:
/* B28B18 80240AE8 AE800070 */  sw        $zero, 0x70($s4)
.L80240AEC:
/* B28B1C 80240AEC 8FBF0044 */  lw        $ra, 0x44($sp)
/* B28B20 80240AF0 8FB40040 */  lw        $s4, 0x40($sp)
/* B28B24 80240AF4 8FB3003C */  lw        $s3, 0x3c($sp)
/* B28B28 80240AF8 8FB20038 */  lw        $s2, 0x38($sp)
/* B28B2C 80240AFC 8FB10034 */  lw        $s1, 0x34($sp)
/* B28B30 80240B00 8FB00030 */  lw        $s0, 0x30($sp)
/* B28B34 80240B04 03E00008 */  jr        $ra
/* B28B38 80240B08 27BD0048 */   addiu    $sp, $sp, 0x48

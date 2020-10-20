.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240938
/* B6CCC8 80240938 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B6CCCC 8024093C AFB40040 */  sw        $s4, 0x40($sp)
/* B6CCD0 80240940 0080A02D */  daddu     $s4, $a0, $zero
/* B6CCD4 80240944 AFBF0044 */  sw        $ra, 0x44($sp)
/* B6CCD8 80240948 AFB3003C */  sw        $s3, 0x3c($sp)
/* B6CCDC 8024094C AFB20038 */  sw        $s2, 0x38($sp)
/* B6CCE0 80240950 AFB10034 */  sw        $s1, 0x34($sp)
/* B6CCE4 80240954 AFB00030 */  sw        $s0, 0x30($sp)
/* B6CCE8 80240958 8E920148 */  lw        $s2, 0x148($s4)
/* B6CCEC 8024095C 00A0882D */  daddu     $s1, $a1, $zero
/* B6CCF0 80240960 86440008 */  lh        $a0, 8($s2)
/* B6CCF4 80240964 0C00EABB */  jal       get_npc_unsafe
/* B6CCF8 80240968 00C0982D */   daddu    $s3, $a2, $zero
/* B6CCFC 8024096C 8E230014 */  lw        $v1, 0x14($s1)
/* B6CD00 80240970 0460002D */  bltz      $v1, .L80240A28
/* B6CD04 80240974 0040802D */   daddu    $s0, $v0, $zero
/* B6CD08 80240978 0260202D */  daddu     $a0, $s3, $zero
/* B6CD0C 8024097C AFA00010 */  sw        $zero, 0x10($sp)
/* B6CD10 80240980 8E260024 */  lw        $a2, 0x24($s1)
/* B6CD14 80240984 8E270028 */  lw        $a3, 0x28($s1)
/* B6CD18 80240988 0C01242D */  jal       func_800490B4
/* B6CD1C 8024098C 0240282D */   daddu    $a1, $s2, $zero
/* B6CD20 80240990 10400025 */  beqz      $v0, .L80240A28
/* B6CD24 80240994 0000202D */   daddu    $a0, $zero, $zero
/* B6CD28 80240998 0200282D */  daddu     $a1, $s0, $zero
/* B6CD2C 8024099C 0000302D */  daddu     $a2, $zero, $zero
/* B6CD30 802409A0 860300A8 */  lh        $v1, 0xa8($s0)
/* B6CD34 802409A4 3C013F80 */  lui       $at, 0x3f80
/* B6CD38 802409A8 44810000 */  mtc1      $at, $f0
/* B6CD3C 802409AC 3C014000 */  lui       $at, 0x4000
/* B6CD40 802409B0 44811000 */  mtc1      $at, $f2
/* B6CD44 802409B4 3C01C1A0 */  lui       $at, 0xc1a0
/* B6CD48 802409B8 44812000 */  mtc1      $at, $f4
/* B6CD4C 802409BC 2402000F */  addiu     $v0, $zero, 0xf
/* B6CD50 802409C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B6CD54 802409C4 44833000 */  mtc1      $v1, $f6
/* B6CD58 802409C8 00000000 */  nop       
/* B6CD5C 802409CC 468031A0 */  cvt.s.w   $f6, $f6
/* B6CD60 802409D0 44073000 */  mfc1      $a3, $f6
/* B6CD64 802409D4 27A20028 */  addiu     $v0, $sp, 0x28
/* B6CD68 802409D8 AFA20020 */  sw        $v0, 0x20($sp)
/* B6CD6C 802409DC E7A00010 */  swc1      $f0, 0x10($sp)
/* B6CD70 802409E0 E7A20014 */  swc1      $f2, 0x14($sp)
/* B6CD74 802409E4 0C01BFA4 */  jal       fx_emote
/* B6CD78 802409E8 E7A40018 */   swc1     $f4, 0x18($sp)
/* B6CD7C 802409EC 0200202D */  daddu     $a0, $s0, $zero
/* B6CD80 802409F0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B6CD84 802409F4 0C012530 */  jal       func_800494C0
/* B6CD88 802409F8 3C060020 */   lui      $a2, 0x20
/* B6CD8C 802409FC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B6CD90 80240A00 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B6CD94 80240A04 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B6CD98 80240A08 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B6CD9C 80240A0C 8C460028 */  lw        $a2, 0x28($v0)
/* B6CDA0 80240A10 0C00A720 */  jal       atan2
/* B6CDA4 80240A14 8C470030 */   lw       $a3, 0x30($v0)
/* B6CDA8 80240A18 2402000C */  addiu     $v0, $zero, 0xc
/* B6CDAC 80240A1C E600000C */  swc1      $f0, 0xc($s0)
/* B6CDB0 80240A20 080902AF */  j         .L80240ABC
/* B6CDB4 80240A24 AE820070 */   sw       $v0, 0x70($s4)
.L80240A28:
/* B6CDB8 80240A28 8602008C */  lh        $v0, 0x8c($s0)
/* B6CDBC 80240A2C 14400023 */  bnez      $v0, .L80240ABC
/* B6CDC0 80240A30 00000000 */   nop      
/* B6CDC4 80240A34 9602008E */  lhu       $v0, 0x8e($s0)
/* B6CDC8 80240A38 2442FFFF */  addiu     $v0, $v0, -1
/* B6CDCC 80240A3C A602008E */  sh        $v0, 0x8e($s0)
/* B6CDD0 80240A40 00021400 */  sll       $v0, $v0, 0x10
/* B6CDD4 80240A44 1C40001D */  bgtz      $v0, .L80240ABC
/* B6CDD8 80240A48 00000000 */   nop      
/* B6CDDC 80240A4C 8E820074 */  lw        $v0, 0x74($s4)
/* B6CDE0 80240A50 2442FFFF */  addiu     $v0, $v0, -1
/* B6CDE4 80240A54 18400018 */  blez      $v0, .L80240AB8
/* B6CDE8 80240A58 AE820074 */   sw       $v0, 0x74($s4)
/* B6CDEC 80240A5C C600000C */  lwc1      $f0, 0xc($s0)
/* B6CDF0 80240A60 3C014334 */  lui       $at, 0x4334
/* B6CDF4 80240A64 44816000 */  mtc1      $at, $f12
/* B6CDF8 80240A68 0C00A6C9 */  jal       clamp_angle
/* B6CDFC 80240A6C 460C0300 */   add.s    $f12, $f0, $f12
/* B6CE00 80240A70 240403E8 */  addiu     $a0, $zero, 0x3e8
/* B6CE04 80240A74 0C00A67F */  jal       rand_int
/* B6CE08 80240A78 E600000C */   swc1     $f0, 0xc($s0)
/* B6CE0C 80240A7C 3C032E8B */  lui       $v1, 0x2e8b
/* B6CE10 80240A80 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* B6CE14 80240A84 00430018 */  mult      $v0, $v1
/* B6CE18 80240A88 00021FC3 */  sra       $v1, $v0, 0x1f
/* B6CE1C 80240A8C 00004010 */  mfhi      $t0
/* B6CE20 80240A90 00082043 */  sra       $a0, $t0, 1
/* B6CE24 80240A94 00832023 */  subu      $a0, $a0, $v1
/* B6CE28 80240A98 00041840 */  sll       $v1, $a0, 1
/* B6CE2C 80240A9C 00641821 */  addu      $v1, $v1, $a0
/* B6CE30 80240AA0 00031880 */  sll       $v1, $v1, 2
/* B6CE34 80240AA4 00641823 */  subu      $v1, $v1, $a0
/* B6CE38 80240AA8 00431023 */  subu      $v0, $v0, $v1
/* B6CE3C 80240AAC 24420005 */  addiu     $v0, $v0, 5
/* B6CE40 80240AB0 080902AF */  j         .L80240ABC
/* B6CE44 80240AB4 A602008E */   sh       $v0, 0x8e($s0)
.L80240AB8:
/* B6CE48 80240AB8 AE800070 */  sw        $zero, 0x70($s4)
.L80240ABC:
/* B6CE4C 80240ABC 8FBF0044 */  lw        $ra, 0x44($sp)
/* B6CE50 80240AC0 8FB40040 */  lw        $s4, 0x40($sp)
/* B6CE54 80240AC4 8FB3003C */  lw        $s3, 0x3c($sp)
/* B6CE58 80240AC8 8FB20038 */  lw        $s2, 0x38($sp)
/* B6CE5C 80240ACC 8FB10034 */  lw        $s1, 0x34($sp)
/* B6CE60 80240AD0 8FB00030 */  lw        $s0, 0x30($sp)
/* B6CE64 80240AD4 03E00008 */  jr        $ra
/* B6CE68 80240AD8 27BD0048 */   addiu    $sp, $sp, 0x48

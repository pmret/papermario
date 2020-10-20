.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240898_BAA9D8
/* BAA9D8 80240898 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BAA9DC 8024089C AFB40040 */  sw        $s4, 0x40($sp)
/* BAA9E0 802408A0 0080A02D */  daddu     $s4, $a0, $zero
/* BAA9E4 802408A4 AFBF0044 */  sw        $ra, 0x44($sp)
/* BAA9E8 802408A8 AFB3003C */  sw        $s3, 0x3c($sp)
/* BAA9EC 802408AC AFB20038 */  sw        $s2, 0x38($sp)
/* BAA9F0 802408B0 AFB10034 */  sw        $s1, 0x34($sp)
/* BAA9F4 802408B4 AFB00030 */  sw        $s0, 0x30($sp)
/* BAA9F8 802408B8 8E920148 */  lw        $s2, 0x148($s4)
/* BAA9FC 802408BC 00A0882D */  daddu     $s1, $a1, $zero
/* BAAA00 802408C0 86440008 */  lh        $a0, 8($s2)
/* BAAA04 802408C4 0C00EABB */  jal       get_npc_unsafe
/* BAAA08 802408C8 00C0982D */   daddu    $s3, $a2, $zero
/* BAAA0C 802408CC 8E230014 */  lw        $v1, 0x14($s1)
/* BAAA10 802408D0 0460002D */  bltz      $v1, .L80240988
/* BAAA14 802408D4 0040802D */   daddu    $s0, $v0, $zero
/* BAAA18 802408D8 0260202D */  daddu     $a0, $s3, $zero
/* BAAA1C 802408DC AFA00010 */  sw        $zero, 0x10($sp)
/* BAAA20 802408E0 8E260024 */  lw        $a2, 0x24($s1)
/* BAAA24 802408E4 8E270028 */  lw        $a3, 0x28($s1)
/* BAAA28 802408E8 0C01242D */  jal       func_800490B4
/* BAAA2C 802408EC 0240282D */   daddu    $a1, $s2, $zero
/* BAAA30 802408F0 10400025 */  beqz      $v0, .L80240988
/* BAAA34 802408F4 0000202D */   daddu    $a0, $zero, $zero
/* BAAA38 802408F8 0200282D */  daddu     $a1, $s0, $zero
/* BAAA3C 802408FC 0000302D */  daddu     $a2, $zero, $zero
/* BAAA40 80240900 860300A8 */  lh        $v1, 0xa8($s0)
/* BAAA44 80240904 3C013F80 */  lui       $at, 0x3f80
/* BAAA48 80240908 44810000 */  mtc1      $at, $f0
/* BAAA4C 8024090C 3C014000 */  lui       $at, 0x4000
/* BAAA50 80240910 44811000 */  mtc1      $at, $f2
/* BAAA54 80240914 3C01C1A0 */  lui       $at, 0xc1a0
/* BAAA58 80240918 44812000 */  mtc1      $at, $f4
/* BAAA5C 8024091C 2402000F */  addiu     $v0, $zero, 0xf
/* BAAA60 80240920 AFA2001C */  sw        $v0, 0x1c($sp)
/* BAAA64 80240924 44833000 */  mtc1      $v1, $f6
/* BAAA68 80240928 00000000 */  nop       
/* BAAA6C 8024092C 468031A0 */  cvt.s.w   $f6, $f6
/* BAAA70 80240930 44073000 */  mfc1      $a3, $f6
/* BAAA74 80240934 27A20028 */  addiu     $v0, $sp, 0x28
/* BAAA78 80240938 AFA20020 */  sw        $v0, 0x20($sp)
/* BAAA7C 8024093C E7A00010 */  swc1      $f0, 0x10($sp)
/* BAAA80 80240940 E7A20014 */  swc1      $f2, 0x14($sp)
/* BAAA84 80240944 0C01BFA4 */  jal       fx_emote
/* BAAA88 80240948 E7A40018 */   swc1     $f4, 0x18($sp)
/* BAAA8C 8024094C 0200202D */  daddu     $a0, $s0, $zero
/* BAAA90 80240950 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BAAA94 80240954 0C012530 */  jal       func_800494C0
/* BAAA98 80240958 3C060020 */   lui      $a2, 0x20
/* BAAA9C 8024095C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAAAA0 80240960 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAAAA4 80240964 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAAAA8 80240968 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAAAAC 8024096C 8C460028 */  lw        $a2, 0x28($v0)
/* BAAAB0 80240970 0C00A720 */  jal       atan2
/* BAAAB4 80240974 8C470030 */   lw       $a3, 0x30($v0)
/* BAAAB8 80240978 2402000C */  addiu     $v0, $zero, 0xc
/* BAAABC 8024097C E600000C */  swc1      $f0, 0xc($s0)
/* BAAAC0 80240980 08090287 */  j         .L80240A1C
/* BAAAC4 80240984 AE820070 */   sw       $v0, 0x70($s4)
.L80240988:
/* BAAAC8 80240988 8602008C */  lh        $v0, 0x8c($s0)
/* BAAACC 8024098C 14400023 */  bnez      $v0, .L80240A1C
/* BAAAD0 80240990 00000000 */   nop      
/* BAAAD4 80240994 9602008E */  lhu       $v0, 0x8e($s0)
/* BAAAD8 80240998 2442FFFF */  addiu     $v0, $v0, -1
/* BAAADC 8024099C A602008E */  sh        $v0, 0x8e($s0)
/* BAAAE0 802409A0 00021400 */  sll       $v0, $v0, 0x10
/* BAAAE4 802409A4 1C40001D */  bgtz      $v0, .L80240A1C
/* BAAAE8 802409A8 00000000 */   nop      
/* BAAAEC 802409AC 8E820074 */  lw        $v0, 0x74($s4)
/* BAAAF0 802409B0 2442FFFF */  addiu     $v0, $v0, -1
/* BAAAF4 802409B4 18400018 */  blez      $v0, .L80240A18
/* BAAAF8 802409B8 AE820074 */   sw       $v0, 0x74($s4)
/* BAAAFC 802409BC C600000C */  lwc1      $f0, 0xc($s0)
/* BAAB00 802409C0 3C014334 */  lui       $at, 0x4334
/* BAAB04 802409C4 44816000 */  mtc1      $at, $f12
/* BAAB08 802409C8 0C00A6C9 */  jal       clamp_angle
/* BAAB0C 802409CC 460C0300 */   add.s    $f12, $f0, $f12
/* BAAB10 802409D0 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BAAB14 802409D4 0C00A67F */  jal       rand_int
/* BAAB18 802409D8 E600000C */   swc1     $f0, 0xc($s0)
/* BAAB1C 802409DC 3C032E8B */  lui       $v1, 0x2e8b
/* BAAB20 802409E0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* BAAB24 802409E4 00430018 */  mult      $v0, $v1
/* BAAB28 802409E8 00021FC3 */  sra       $v1, $v0, 0x1f
/* BAAB2C 802409EC 00004010 */  mfhi      $t0
/* BAAB30 802409F0 00082043 */  sra       $a0, $t0, 1
/* BAAB34 802409F4 00832023 */  subu      $a0, $a0, $v1
/* BAAB38 802409F8 00041840 */  sll       $v1, $a0, 1
/* BAAB3C 802409FC 00641821 */  addu      $v1, $v1, $a0
/* BAAB40 80240A00 00031880 */  sll       $v1, $v1, 2
/* BAAB44 80240A04 00641823 */  subu      $v1, $v1, $a0
/* BAAB48 80240A08 00431023 */  subu      $v0, $v0, $v1
/* BAAB4C 80240A0C 24420005 */  addiu     $v0, $v0, 5
/* BAAB50 80240A10 08090287 */  j         .L80240A1C
/* BAAB54 80240A14 A602008E */   sh       $v0, 0x8e($s0)
.L80240A18:
/* BAAB58 80240A18 AE800070 */  sw        $zero, 0x70($s4)
.L80240A1C:
/* BAAB5C 80240A1C 8FBF0044 */  lw        $ra, 0x44($sp)
/* BAAB60 80240A20 8FB40040 */  lw        $s4, 0x40($sp)
/* BAAB64 80240A24 8FB3003C */  lw        $s3, 0x3c($sp)
/* BAAB68 80240A28 8FB20038 */  lw        $s2, 0x38($sp)
/* BAAB6C 80240A2C 8FB10034 */  lw        $s1, 0x34($sp)
/* BAAB70 80240A30 8FB00030 */  lw        $s0, 0x30($sp)
/* BAAB74 80240A34 03E00008 */  jr        $ra
/* BAAB78 80240A38 27BD0048 */   addiu    $sp, $sp, 0x48

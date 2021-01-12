.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240928_A1BA28
/* A1BA28 80240928 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A1BA2C 8024092C AFB10014 */  sw        $s1, 0x14($sp)
/* A1BA30 80240930 3C118024 */  lui       $s1, %hi(D_80243BD4)
/* A1BA34 80240934 26313BD4 */  addiu     $s1, $s1, %lo(D_80243BD4)
/* A1BA38 80240938 AFBF0020 */  sw        $ra, 0x20($sp)
/* A1BA3C 8024093C AFB3001C */  sw        $s3, 0x1c($sp)
/* A1BA40 80240940 AFB20018 */  sw        $s2, 0x18($sp)
/* A1BA44 80240944 AFB00010 */  sw        $s0, 0x10($sp)
/* A1BA48 80240948 96240000 */  lhu       $a0, ($s1)
/* A1BA4C 8024094C 0C01917C */  jal       sins
/* A1BA50 80240950 3C130001 */   lui      $s3, 1
/* A1BA54 80240954 00021400 */  sll       $v0, $v0, 0x10
/* A1BA58 80240958 00021403 */  sra       $v0, $v0, 0x10
/* A1BA5C 8024095C 3C013800 */  lui       $at, 0x3800
/* A1BA60 80240960 44811000 */  mtc1      $at, $f2
/* A1BA64 80240964 44820000 */  mtc1      $v0, $f0
/* A1BA68 80240968 00000000 */  nop
/* A1BA6C 8024096C 46800020 */  cvt.s.w   $f0, $f0
/* A1BA70 80240970 46020002 */  mul.s     $f0, $f0, $f2
/* A1BA74 80240974 00000000 */  nop
/* A1BA78 80240978 3C013FE0 */  lui       $at, 0x3fe0
/* A1BA7C 8024097C 44811800 */  mtc1      $at, $f3
/* A1BA80 80240980 44801000 */  mtc1      $zero, $f2
/* A1BA84 80240984 46000021 */  cvt.d.s   $f0, $f0
/* A1BA88 80240988 46220002 */  mul.d     $f0, $f0, $f2
/* A1BA8C 8024098C 00000000 */  nop
/* A1BA90 80240990 36731630 */  ori       $s3, $s3, 0x1630
/* A1BA94 80240994 46220002 */  mul.d     $f0, $f0, $f2
/* A1BA98 80240998 00000000 */  nop
/* A1BA9C 8024099C 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* A1BAA0 802409A0 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* A1BAA4 802409A4 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* A1BAA8 802409A8 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* A1BAAC 802409AC 96040000 */  lhu       $a0, ($s0)
/* A1BAB0 802409B0 8E420000 */  lw        $v0, ($s2)
/* A1BAB4 802409B4 00042180 */  sll       $a0, $a0, 6
/* A1BAB8 802409B8 3C018025 */  lui       $at, %hi(D_8024BD60)
/* A1BABC 802409BC D422BD60 */  ldc1      $f2, %lo(D_8024BD60)($at)
/* A1BAC0 802409C0 00932021 */  addu      $a0, $a0, $s3
/* A1BAC4 802409C4 46220000 */  add.d     $f0, $f0, $f2
/* A1BAC8 802409C8 00442021 */  addu      $a0, $v0, $a0
/* A1BACC 802409CC 96220000 */  lhu       $v0, ($s1)
/* A1BAD0 802409D0 46200020 */  cvt.s.d   $f0, $f0
/* A1BAD4 802409D4 44050000 */  mfc1      $a1, $f0
/* A1BAD8 802409D8 24420199 */  addiu     $v0, $v0, 0x199
/* A1BADC 802409DC A6220000 */  sh        $v0, ($s1)
/* A1BAE0 802409E0 00A0302D */  daddu     $a2, $a1, $zero
/* A1BAE4 802409E4 0C019DC0 */  jal       guScale
/* A1BAE8 802409E8 00A0382D */   daddu    $a3, $a1, $zero
/* A1BAEC 802409EC 3C05DA38 */  lui       $a1, 0xda38
/* A1BAF0 802409F0 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* A1BAF4 802409F4 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* A1BAF8 802409F8 34A50001 */  ori       $a1, $a1, 1
/* A1BAFC 802409FC 8C830000 */  lw        $v1, ($a0)
/* A1BB00 80240A00 96020000 */  lhu       $v0, ($s0)
/* A1BB04 80240A04 0060302D */  daddu     $a2, $v1, $zero
/* A1BB08 80240A08 24630008 */  addiu     $v1, $v1, 8
/* A1BB0C 80240A0C AC830000 */  sw        $v1, ($a0)
/* A1BB10 80240A10 24430001 */  addiu     $v1, $v0, 1
/* A1BB14 80240A14 3042FFFF */  andi      $v0, $v0, 0xffff
/* A1BB18 80240A18 00021180 */  sll       $v0, $v0, 6
/* A1BB1C 80240A1C ACC50000 */  sw        $a1, ($a2)
/* A1BB20 80240A20 A6030000 */  sh        $v1, ($s0)
/* A1BB24 80240A24 8E430000 */  lw        $v1, ($s2)
/* A1BB28 80240A28 00531021 */  addu      $v0, $v0, $s3
/* A1BB2C 80240A2C 00621821 */  addu      $v1, $v1, $v0
/* A1BB30 80240A30 ACC30004 */  sw        $v1, 4($a2)
/* A1BB34 80240A34 8FBF0020 */  lw        $ra, 0x20($sp)
/* A1BB38 80240A38 8FB3001C */  lw        $s3, 0x1c($sp)
/* A1BB3C 80240A3C 8FB20018 */  lw        $s2, 0x18($sp)
/* A1BB40 80240A40 8FB10014 */  lw        $s1, 0x14($sp)
/* A1BB44 80240A44 8FB00010 */  lw        $s0, 0x10($sp)
/* A1BB48 80240A48 03E00008 */  jr        $ra
/* A1BB4C 80240A4C 27BD0028 */   addiu    $sp, $sp, 0x28

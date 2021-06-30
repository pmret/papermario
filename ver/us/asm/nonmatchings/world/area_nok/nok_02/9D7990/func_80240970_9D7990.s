.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240970_9D7990
/* 9D7990 80240970 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9D7994 80240974 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D7998 80240978 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 9D799C 8024097C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9D79A0 80240980 0C00A67F */  jal       rand_int
/* 9D79A4 80240984 240400C8 */   addiu    $a0, $zero, 0xc8
/* 9D79A8 80240988 2442FF9C */  addiu     $v0, $v0, -0x64
/* 9D79AC 8024098C 4482A000 */  mtc1      $v0, $f20
/* 9D79B0 80240990 00000000 */  nop
/* 9D79B4 80240994 4680A520 */  cvt.s.w   $f20, $f20
/* 9D79B8 80240998 0C00A67F */  jal       rand_int
/* 9D79BC 8024099C 24040096 */   addiu    $a0, $zero, 0x96
/* 9D79C0 802409A0 44820000 */  mtc1      $v0, $f0
/* 9D79C4 802409A4 00000000 */  nop
/* 9D79C8 802409A8 46800020 */  cvt.s.w   $f0, $f0
/* 9D79CC 802409AC 3C01C334 */  lui       $at, 0xc334
/* 9D79D0 802409B0 4481B000 */  mtc1      $at, $f22
/* 9D79D4 802409B4 4405A000 */  mfc1      $a1, $f20
/* 9D79D8 802409B8 44060000 */  mfc1      $a2, $f0
/* 9D79DC 802409BC 4407B000 */  mfc1      $a3, $f22
/* 9D79E0 802409C0 24040002 */  addiu     $a0, $zero, 2
/* 9D79E4 802409C4 AFA00010 */  sw        $zero, 0x10($sp)
/* 9D79E8 802409C8 0C01BECC */  jal       fx_walk
/* 9D79EC 802409CC AFA00014 */   sw       $zero, 0x14($sp)
/* 9D79F0 802409D0 0C00A67F */  jal       rand_int
/* 9D79F4 802409D4 240400C8 */   addiu    $a0, $zero, 0xc8
/* 9D79F8 802409D8 2442FF9C */  addiu     $v0, $v0, -0x64
/* 9D79FC 802409DC 4482A000 */  mtc1      $v0, $f20
/* 9D7A00 802409E0 00000000 */  nop
/* 9D7A04 802409E4 4680A520 */  cvt.s.w   $f20, $f20
/* 9D7A08 802409E8 0C00A67F */  jal       rand_int
/* 9D7A0C 802409EC 24040096 */   addiu    $a0, $zero, 0x96
/* 9D7A10 802409F0 44820000 */  mtc1      $v0, $f0
/* 9D7A14 802409F4 00000000 */  nop
/* 9D7A18 802409F8 46800020 */  cvt.s.w   $f0, $f0
/* 9D7A1C 802409FC 4405A000 */  mfc1      $a1, $f20
/* 9D7A20 80240A00 4407B000 */  mfc1      $a3, $f22
/* 9D7A24 80240A04 44060000 */  mfc1      $a2, $f0
/* 9D7A28 80240A08 24040002 */  addiu     $a0, $zero, 2
/* 9D7A2C 80240A0C AFA00010 */  sw        $zero, 0x10($sp)
/* 9D7A30 80240A10 0C01BECC */  jal       fx_walk
/* 9D7A34 80240A14 AFA00014 */   sw       $zero, 0x14($sp)
/* 9D7A38 80240A18 0C00A67F */  jal       rand_int
/* 9D7A3C 80240A1C 240400C8 */   addiu    $a0, $zero, 0xc8
/* 9D7A40 80240A20 2442FF9C */  addiu     $v0, $v0, -0x64
/* 9D7A44 80240A24 4482A000 */  mtc1      $v0, $f20
/* 9D7A48 80240A28 00000000 */  nop
/* 9D7A4C 80240A2C 4680A520 */  cvt.s.w   $f20, $f20
/* 9D7A50 80240A30 0C00A67F */  jal       rand_int
/* 9D7A54 80240A34 24040096 */   addiu    $a0, $zero, 0x96
/* 9D7A58 80240A38 44820000 */  mtc1      $v0, $f0
/* 9D7A5C 80240A3C 00000000 */  nop
/* 9D7A60 80240A40 46800020 */  cvt.s.w   $f0, $f0
/* 9D7A64 80240A44 4405A000 */  mfc1      $a1, $f20
/* 9D7A68 80240A48 4407B000 */  mfc1      $a3, $f22
/* 9D7A6C 80240A4C 44060000 */  mfc1      $a2, $f0
/* 9D7A70 80240A50 24040002 */  addiu     $a0, $zero, 2
/* 9D7A74 80240A54 AFA00010 */  sw        $zero, 0x10($sp)
/* 9D7A78 80240A58 0C01BECC */  jal       fx_walk
/* 9D7A7C 80240A5C AFA00014 */   sw       $zero, 0x14($sp)
/* 9D7A80 80240A60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D7A84 80240A64 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 9D7A88 80240A68 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9D7A8C 80240A6C 24020002 */  addiu     $v0, $zero, 2
/* 9D7A90 80240A70 03E00008 */  jr        $ra
/* 9D7A94 80240A74 27BD0030 */   addiu    $sp, $sp, 0x30
/* 9D7A98 80240A78 00000000 */  nop
/* 9D7A9C 80240A7C 00000000 */  nop

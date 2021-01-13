.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240850_AEDC60
/* AEDC60 80240850 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* AEDC64 80240854 AFB3003C */  sw        $s3, 0x3c($sp)
/* AEDC68 80240858 0080982D */  daddu     $s3, $a0, $zero
/* AEDC6C 8024085C AFBF0044 */  sw        $ra, 0x44($sp)
/* AEDC70 80240860 AFB40040 */  sw        $s4, 0x40($sp)
/* AEDC74 80240864 AFB20038 */  sw        $s2, 0x38($sp)
/* AEDC78 80240868 AFB10034 */  sw        $s1, 0x34($sp)
/* AEDC7C 8024086C AFB00030 */  sw        $s0, 0x30($sp)
/* AEDC80 80240870 F7B80058 */  sdc1      $f24, 0x58($sp)
/* AEDC84 80240874 F7B60050 */  sdc1      $f22, 0x50($sp)
/* AEDC88 80240878 F7B40048 */  sdc1      $f20, 0x48($sp)
/* AEDC8C 8024087C 8E620148 */  lw        $v0, 0x148($s3)
/* AEDC90 80240880 0C00EABB */  jal       get_npc_unsafe
/* AEDC94 80240884 84440008 */   lh       $a0, 8($v0)
/* AEDC98 80240888 27A40020 */  addiu     $a0, $sp, 0x20
/* AEDC9C 8024088C 27A50024 */  addiu     $a1, $sp, 0x24
/* AEDCA0 80240890 0040802D */  daddu     $s0, $v0, $zero
/* AEDCA4 80240894 8E63000C */  lw        $v1, 0xc($s3)
/* AEDCA8 80240898 8E07000C */  lw        $a3, 0xc($s0)
/* AEDCAC 8024089C C6000038 */  lwc1      $f0, 0x38($s0)
/* AEDCB0 802408A0 C6020040 */  lwc1      $f2, 0x40($s0)
/* AEDCB4 802408A4 8C740000 */  lw        $s4, ($v1)
/* AEDCB8 802408A8 24630004 */  addiu     $v1, $v1, 4
/* AEDCBC 802408AC C4780000 */  lwc1      $f24, ($v1)
/* AEDCC0 802408B0 4680C620 */  cvt.s.w   $f24, $f24
/* AEDCC4 802408B4 24630004 */  addiu     $v1, $v1, 4
/* AEDCC8 802408B8 C4740000 */  lwc1      $f20, ($v1)
/* AEDCCC 802408BC 4680A520 */  cvt.s.w   $f20, $f20
/* AEDCD0 802408C0 4406A000 */  mfc1      $a2, $f20
/* AEDCD4 802408C4 C4760004 */  lwc1      $f22, 4($v1)
/* AEDCD8 802408C8 4680B5A0 */  cvt.s.w   $f22, $f22
/* AEDCDC 802408CC E7A00020 */  swc1      $f0, 0x20($sp)
/* AEDCE0 802408D0 0C00A7E7 */  jal       add_vec2D_polar
/* AEDCE4 802408D4 E7A20024 */   swc1     $f2, 0x24($sp)
/* AEDCE8 802408D8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AEDCEC 802408DC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AEDCF0 802408E0 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AEDCF4 802408E4 4480A000 */  mtc1      $zero, $f20
/* AEDCF8 802408E8 8E460028 */  lw        $a2, 0x28($s2)
/* AEDCFC 802408EC 4407A000 */  mfc1      $a3, $f20
/* AEDD00 802408F0 0C00A7B5 */  jal       dist2D
/* AEDD04 802408F4 4600A386 */   mov.s    $f14, $f20
/* AEDD08 802408F8 4600A306 */  mov.s     $f12, $f20
/* AEDD0C 802408FC C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AEDD10 80240900 44066000 */  mfc1      $a2, $f12
/* AEDD14 80240904 8E470030 */  lw        $a3, 0x30($s2)
/* AEDD18 80240908 0C00A7B5 */  jal       dist2D
/* AEDD1C 8024090C 46000506 */   mov.s    $f20, $f0
/* AEDD20 80240910 C604000C */  lwc1      $f4, 0xc($s0)
/* AEDD24 80240914 3C018024 */  lui       $at, %hi(D_80244830)
/* AEDD28 80240918 D4224830 */  ldc1      $f2, %lo(D_80244830)($at)
/* AEDD2C 8024091C 46002121 */  cvt.d.s   $f4, $f4
/* AEDD30 80240920 46222032 */  c.eq.d    $f4, $f2
/* AEDD34 80240924 00000000 */  nop
/* AEDD38 80240928 45010007 */  bc1t      .L80240948
/* AEDD3C 8024092C 46000086 */   mov.s    $f2, $f0
/* AEDD40 80240930 3C018024 */  lui       $at, %hi(D_80244838)
/* AEDD44 80240934 D4204838 */  ldc1      $f0, %lo(D_80244838)($at)
/* AEDD48 80240938 46202032 */  c.eq.d    $f4, $f0
/* AEDD4C 8024093C 00000000 */  nop
/* AEDD50 80240940 45000008 */  bc1f      .L80240964
/* AEDD54 80240944 00000000 */   nop
.L80240948:
/* AEDD58 80240948 4618A03E */  c.le.s    $f20, $f24
/* AEDD5C 8024094C 00000000 */  nop
/* AEDD60 80240950 4500000C */  bc1f      .L80240984
/* AEDD64 80240954 0000882D */   daddu    $s1, $zero, $zero
/* AEDD68 80240958 4616103E */  c.le.s    $f2, $f22
/* AEDD6C 8024095C 0809025F */  j         .L8024097C
/* AEDD70 80240960 00000000 */   nop
.L80240964:
/* AEDD74 80240964 4618103E */  c.le.s    $f2, $f24
/* AEDD78 80240968 00000000 */  nop
/* AEDD7C 8024096C 45000005 */  bc1f      .L80240984
/* AEDD80 80240970 0000882D */   daddu    $s1, $zero, $zero
/* AEDD84 80240974 4616A03E */  c.le.s    $f20, $f22
/* AEDD88 80240978 00000000 */  nop
.L8024097C:
/* AEDD8C 8024097C 45030001 */  bc1tl     .L80240984
/* AEDD90 80240980 24110001 */   addiu    $s1, $zero, 1
.L80240984:
/* AEDD94 80240984 12200027 */  beqz      $s1, .L80240A24
/* AEDD98 80240988 0260202D */   daddu    $a0, $s3, $zero
/* AEDD9C 8024098C C60C0038 */  lwc1      $f12, 0x38($s0)
/* AEDDA0 80240990 C60E0040 */  lwc1      $f14, 0x40($s0)
/* AEDDA4 80240994 8E460028 */  lw        $a2, 0x28($s2)
/* AEDDA8 80240998 8E470030 */  lw        $a3, 0x30($s2)
/* AEDDAC 8024099C C602003C */  lwc1      $f2, 0x3c($s0)
/* AEDDB0 802409A0 46006006 */  mov.s     $f0, $f12
/* AEDDB4 802409A4 46007106 */  mov.s     $f4, $f14
/* AEDDB8 802409A8 E7A00020 */  swc1      $f0, 0x20($sp)
/* AEDDBC 802409AC E7A20028 */  swc1      $f2, 0x28($sp)
/* AEDDC0 802409B0 0C00A7B5 */  jal       dist2D
/* AEDDC4 802409B4 E7A40024 */   swc1     $f4, 0x24($sp)
/* AEDDC8 802409B8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* AEDDCC 802409BC C60E0040 */  lwc1      $f14, 0x40($s0)
/* AEDDD0 802409C0 8E460028 */  lw        $a2, 0x28($s2)
/* AEDDD4 802409C4 8E470030 */  lw        $a3, 0x30($s2)
/* AEDDD8 802409C8 0C00A720 */  jal       atan2
/* AEDDDC 802409CC 46000506 */   mov.s    $f20, $f0
/* AEDDE0 802409D0 3C040007 */  lui       $a0, 7
/* AEDDE4 802409D4 34848000 */  ori       $a0, $a0, 0x8000
/* AEDDE8 802409D8 27A50020 */  addiu     $a1, $sp, 0x20
/* AEDDEC 802409DC E7B40010 */  swc1      $f20, 0x10($sp)
/* AEDDF0 802409E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* AEDDF4 802409E4 860200A6 */  lh        $v0, 0xa6($s0)
/* AEDDF8 802409E8 27A60028 */  addiu     $a2, $sp, 0x28
/* AEDDFC 802409EC 44820000 */  mtc1      $v0, $f0
/* AEDE00 802409F0 00000000 */  nop
/* AEDE04 802409F4 46800020 */  cvt.s.w   $f0, $f0
/* AEDE08 802409F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* AEDE0C 802409FC 860200A8 */  lh        $v0, 0xa8($s0)
/* AEDE10 80240A00 27A70024 */  addiu     $a3, $sp, 0x24
/* AEDE14 80240A04 44820000 */  mtc1      $v0, $f0
/* AEDE18 80240A08 00000000 */  nop
/* AEDE1C 80240A0C 46800020 */  cvt.s.w   $f0, $f0
/* AEDE20 80240A10 0C0376B9 */  jal       func_800DDAE4
/* AEDE24 80240A14 E7A0001C */   swc1     $f0, 0x1c($sp)
/* AEDE28 80240A18 54400001 */  bnel      $v0, $zero, .L80240A20
/* AEDE2C 80240A1C 0000882D */   daddu    $s1, $zero, $zero
.L80240A20:
/* AEDE30 80240A20 0260202D */  daddu     $a0, $s3, $zero
.L80240A24:
/* AEDE34 80240A24 0280282D */  daddu     $a1, $s4, $zero
/* AEDE38 80240A28 0C0B2026 */  jal       set_variable
/* AEDE3C 80240A2C 0220302D */   daddu    $a2, $s1, $zero
/* AEDE40 80240A30 8FBF0044 */  lw        $ra, 0x44($sp)
/* AEDE44 80240A34 8FB40040 */  lw        $s4, 0x40($sp)
/* AEDE48 80240A38 8FB3003C */  lw        $s3, 0x3c($sp)
/* AEDE4C 80240A3C 8FB20038 */  lw        $s2, 0x38($sp)
/* AEDE50 80240A40 8FB10034 */  lw        $s1, 0x34($sp)
/* AEDE54 80240A44 8FB00030 */  lw        $s0, 0x30($sp)
/* AEDE58 80240A48 D7B80058 */  ldc1      $f24, 0x58($sp)
/* AEDE5C 80240A4C D7B60050 */  ldc1      $f22, 0x50($sp)
/* AEDE60 80240A50 D7B40048 */  ldc1      $f20, 0x48($sp)
/* AEDE64 80240A54 24020002 */  addiu     $v0, $zero, 2
/* AEDE68 80240A58 03E00008 */  jr        $ra
/* AEDE6C 80240A5C 27BD0060 */   addiu    $sp, $sp, 0x60

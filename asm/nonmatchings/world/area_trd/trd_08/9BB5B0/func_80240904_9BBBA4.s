.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240904_9BBBA4
/* 9BBBA4 80240904 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9BBBA8 80240908 AFB00010 */  sw        $s0, 0x10($sp)
/* 9BBBAC 8024090C 0080802D */  daddu     $s0, $a0, $zero
/* 9BBBB0 80240910 24020001 */  addiu     $v0, $zero, 1
/* 9BBBB4 80240914 10A20019 */  beq       $a1, $v0, .L8024097C
/* 9BBBB8 80240918 AFBF0014 */   sw       $ra, 0x14($sp)
/* 9BBBBC 8024091C 28A20002 */  slti      $v0, $a1, 2
/* 9BBBC0 80240920 50400005 */  beql      $v0, $zero, .L80240938
/* 9BBBC4 80240924 24020002 */   addiu    $v0, $zero, 2
/* 9BBBC8 80240928 10A00007 */  beqz      $a1, .L80240948
/* 9BBBCC 8024092C 00000000 */   nop      
/* 9BBBD0 80240930 08090284 */  j         .L80240A10
/* 9BBBD4 80240934 00000000 */   nop      
.L80240938:
/* 9BBBD8 80240938 10A20028 */  beq       $a1, $v0, .L802409DC
/* 9BBBDC 8024093C 00000000 */   nop      
/* 9BBBE0 80240940 08090284 */  j         .L80240A10
/* 9BBBE4 80240944 00000000 */   nop      
.L80240948:
/* 9BBBE8 80240948 8E020000 */  lw        $v0, ($s0)
/* 9BBBEC 8024094C 30420002 */  andi      $v0, $v0, 2
/* 9BBBF0 80240950 1040002F */  beqz      $v0, .L80240A10
/* 9BBBF4 80240954 00000000 */   nop      
/* 9BBBF8 80240958 C6000010 */  lwc1      $f0, 0x10($s0)
/* 9BBBFC 8024095C 3C013F73 */  lui       $at, 0x3f73
/* 9BBC00 80240960 34213333 */  ori       $at, $at, 0x3333
/* 9BBC04 80240964 44811000 */  mtc1      $at, $f2
/* 9BBC08 80240968 00000000 */  nop       
/* 9BBC0C 8024096C 46020002 */  mul.s     $f0, $f0, $f2
/* 9BBC10 80240970 00000000 */  nop       
/* 9BBC14 80240974 08090284 */  j         .L80240A10
/* 9BBC18 80240978 E6000010 */   swc1     $f0, 0x10($s0)
.L8024097C:
/* 9BBC1C 8024097C C6000010 */  lwc1      $f0, 0x10($s0)
/* 9BBC20 80240980 3C013F8F */  lui       $at, 0x3f8f
/* 9BBC24 80240984 34215C29 */  ori       $at, $at, 0x5c29
/* 9BBC28 80240988 44811000 */  mtc1      $at, $f2
/* 9BBC2C 8024098C 00000000 */  nop       
/* 9BBC30 80240990 46020002 */  mul.s     $f0, $f0, $f2
/* 9BBC34 80240994 00000000 */  nop       
/* 9BBC38 80240998 8E030020 */  lw        $v1, 0x20($s0)
/* 9BBC3C 8024099C 2402000A */  addiu     $v0, $zero, 0xa
/* 9BBC40 802409A0 1462001B */  bne       $v1, $v0, .L80240A10
/* 9BBC44 802409A4 E6000010 */   swc1     $f0, 0x10($s0)
/* 9BBC48 802409A8 3C048024 */  lui       $a0, %hi(func_80240F2C_95C12C)
/* 9BBC4C 802409AC 24840F2C */  addiu     $a0, $a0, %lo(func_80240F2C_95C12C)
/* 9BBC50 802409B0 24050001 */  addiu     $a1, $zero, 1
/* 9BBC54 802409B4 0C0B0CF8 */  jal       start_script
/* 9BBC58 802409B8 0000302D */   daddu    $a2, $zero, $zero
/* 9BBC5C 802409BC 8E030014 */  lw        $v1, 0x14($s0)
/* 9BBC60 802409C0 AC430084 */  sw        $v1, 0x84($v0)
/* 9BBC64 802409C4 8E030018 */  lw        $v1, 0x18($s0)
/* 9BBC68 802409C8 AC430088 */  sw        $v1, 0x88($v0)
/* 9BBC6C 802409CC 8E020000 */  lw        $v0, ($s0)
/* 9BBC70 802409D0 34420002 */  ori       $v0, $v0, 2
/* 9BBC74 802409D4 08090284 */  j         .L80240A10
/* 9BBC78 802409D8 AE020000 */   sw       $v0, ($s0)
.L802409DC:
/* 9BBC7C 802409DC C60C0010 */  lwc1      $f12, 0x10($s0)
/* 9BBC80 802409E0 0C00A69F */  jal       signF
/* 9BBC84 802409E4 46006307 */   neg.s    $f12, $f12
/* 9BBC88 802409E8 8E02002C */  lw        $v0, 0x2c($s0)
/* 9BBC8C 802409EC 8C42000C */  lw        $v0, 0xc($v0)
/* 9BBC90 802409F0 04420001 */  bltzl     $v0, .L802409F8
/* 9BBC94 802409F4 00021023 */   negu     $v0, $v0
.L802409F8:
/* 9BBC98 802409F8 44821000 */  mtc1      $v0, $f2
/* 9BBC9C 802409FC 00000000 */  nop       
/* 9BBCA0 80240A00 468010A0 */  cvt.s.w   $f2, $f2
/* 9BBCA4 80240A04 46001082 */  mul.s     $f2, $f2, $f0
/* 9BBCA8 80240A08 00000000 */  nop       
/* 9BBCAC 80240A0C E6020010 */  swc1      $f2, 0x10($s0)
.L80240A10:
/* 9BBCB0 80240A10 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9BBCB4 80240A14 8FB00010 */  lw        $s0, 0x10($sp)
/* 9BBCB8 80240A18 03E00008 */  jr        $ra
/* 9BBCBC 80240A1C 27BD0018 */   addiu    $sp, $sp, 0x18

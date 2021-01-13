.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024083C_CF83AC
/* CF83AC 8024083C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CF83B0 80240840 AFB10024 */  sw        $s1, 0x24($sp)
/* CF83B4 80240844 0080882D */  daddu     $s1, $a0, $zero
/* CF83B8 80240848 3C05F840 */  lui       $a1, 0xf840
/* CF83BC 8024084C AFBF0044 */  sw        $ra, 0x44($sp)
/* CF83C0 80240850 AFBE0040 */  sw        $fp, 0x40($sp)
/* CF83C4 80240854 AFB7003C */  sw        $s7, 0x3c($sp)
/* CF83C8 80240858 AFB60038 */  sw        $s6, 0x38($sp)
/* CF83CC 8024085C AFB50034 */  sw        $s5, 0x34($sp)
/* CF83D0 80240860 AFB40030 */  sw        $s4, 0x30($sp)
/* CF83D4 80240864 AFB3002C */  sw        $s3, 0x2c($sp)
/* CF83D8 80240868 AFB20028 */  sw        $s2, 0x28($sp)
/* CF83DC 8024086C AFB00020 */  sw        $s0, 0x20($sp)
/* CF83E0 80240870 8E3E0148 */  lw        $fp, 0x148($s1)
/* CF83E4 80240874 0C0B1EAF */  jal       get_variable
/* CF83E8 80240878 34A56268 */   ori      $a1, $a1, 0x6268
/* CF83EC 8024087C 0040802D */  daddu     $s0, $v0, $zero
/* CF83F0 80240880 0220202D */  daddu     $a0, $s1, $zero
/* CF83F4 80240884 3C05F840 */  lui       $a1, 0xf840
/* CF83F8 80240888 0C0B1EAF */  jal       get_variable
/* CF83FC 8024088C 34A56269 */   ori      $a1, $a1, 0x6269
/* CF8400 80240890 0040B82D */  daddu     $s7, $v0, $zero
/* CF8404 80240894 0220202D */  daddu     $a0, $s1, $zero
/* CF8408 80240898 3C05F5DE */  lui       $a1, 0xf5de
/* CF840C 8024089C 0C0B1EAF */  jal       get_variable
/* CF8410 802408A0 34A502DE */   ori      $a1, $a1, 0x2de
/* CF8414 802408A4 0040B02D */  daddu     $s6, $v0, $zero
/* CF8418 802408A8 0220202D */  daddu     $a0, $s1, $zero
/* CF841C 802408AC 3C05F5DE */  lui       $a1, 0xf5de
/* CF8420 802408B0 0C0B1EAF */  jal       get_variable
/* CF8424 802408B4 34A502DF */   ori      $a1, $a1, 0x2df
/* CF8428 802408B8 0040A82D */  daddu     $s5, $v0, $zero
/* CF842C 802408BC 93D3006D */  lbu       $s3, 0x6d($fp)
/* CF8430 802408C0 32C2FFFF */  andi      $v0, $s6, 0xffff
/* CF8434 802408C4 A7B30010 */  sh        $s3, 0x10($sp)
/* CF8438 802408C8 93D2006E */  lbu       $s2, 0x6e($fp)
/* CF843C 802408CC 93C7006F */  lbu       $a3, 0x6f($fp)
/* CF8440 802408D0 3274FFFF */  andi      $s4, $s3, 0xffff
/* CF8444 802408D4 12820003 */  beq       $s4, $v0, .L802408E4
/* CF8448 802408D8 A7A7001E */   sh       $a3, 0x1e($sp)
/* CF844C 802408DC 0000B82D */  daddu     $s7, $zero, $zero
/* CF8450 802408E0 02E0802D */  daddu     $s0, $s7, $zero
.L802408E4:
/* CF8454 802408E4 3202FFFF */  andi      $v0, $s0, 0xffff
/* CF8458 802408E8 14400016 */  bnez      $v0, .L80240944
/* CF845C 802408EC 0220202D */   daddu    $a0, $s1, $zero
/* CF8460 802408F0 0C00A67F */  jal       rand_int
/* CF8464 802408F4 24040064 */   addiu    $a0, $zero, 0x64
/* CF8468 802408F8 2842001E */  slti      $v0, $v0, 0x1e
/* CF846C 802408FC 10400011 */  beqz      $v0, .L80240944
/* CF8470 80240900 0220202D */   daddu    $a0, $s1, $zero
/* CF8474 80240904 0C00A67F */  jal       rand_int
/* CF8478 80240908 2644FFFF */   addiu    $a0, $s2, -1
/* CF847C 8024090C 0040A82D */  daddu     $s5, $v0, $zero
/* CF8480 80240910 0260B02D */  daddu     $s6, $s3, $zero
/* CF8484 80240914 0220202D */  daddu     $a0, $s1, $zero
/* CF8488 80240918 3C05F5DE */  lui       $a1, 0xf5de
/* CF848C 8024091C 34A502DE */  ori       $a1, $a1, 0x2de
/* CF8490 80240920 0C0B2026 */  jal       set_variable
/* CF8494 80240924 0280302D */   daddu    $a2, $s4, $zero
/* CF8498 80240928 0220202D */  daddu     $a0, $s1, $zero
/* CF849C 8024092C 3C05F5DE */  lui       $a1, 0xf5de
/* CF84A0 80240930 34A502DF */  ori       $a1, $a1, 0x2df
/* CF84A4 80240934 0C0B2026 */  jal       set_variable
/* CF84A8 80240938 32A6FFFF */   andi     $a2, $s5, 0xffff
/* CF84AC 8024093C 24100001 */  addiu     $s0, $zero, 1
/* CF84B0 80240940 0220202D */  daddu     $a0, $s1, $zero
.L80240944:
/* CF84B4 80240944 3C05F840 */  lui       $a1, 0xf840
/* CF84B8 80240948 34A56268 */  ori       $a1, $a1, 0x6268
/* CF84BC 8024094C 0C0B2026 */  jal       set_variable
/* CF84C0 80240950 3206FFFF */   andi     $a2, $s0, 0xffff
/* CF84C4 80240954 0220202D */  daddu     $a0, $s1, $zero
/* CF84C8 80240958 3C05F840 */  lui       $a1, 0xf840
/* CF84CC 8024095C 34A56269 */  ori       $a1, $a1, 0x6269
/* CF84D0 80240960 0C0B2026 */  jal       set_variable
/* CF84D4 80240964 32E6FFFF */   andi     $a2, $s7, 0xffff
/* CF84D8 80240968 0000202D */  daddu     $a0, $zero, $zero
/* CF84DC 8024096C 3C05F5DE */  lui       $a1, 0xf5de
/* CF84E0 80240970 0C0B1EAF */  jal       get_variable
/* CF84E4 80240974 34A502E0 */   ori      $a1, $a1, 0x2e0
/* CF84E8 80240978 0000202D */  daddu     $a0, $zero, $zero
/* CF84EC 8024097C 3C05F5DE */  lui       $a1, 0xf5de
/* CF84F0 80240980 34A50180 */  ori       $a1, $a1, 0x180
/* CF84F4 80240984 0C0B1EAF */  jal       get_variable
/* CF84F8 80240988 0040802D */   daddu    $s0, $v0, $zero
/* CF84FC 8024098C 0040282D */  daddu     $a1, $v0, $zero
/* CF8500 80240990 0000182D */  daddu     $v1, $zero, $zero
/* CF8504 80240994 3C068024 */  lui       $a2, %hi(D_8024373C)
/* CF8508 80240998 24C6373C */  addiu     $a2, $a2, %lo(D_8024373C)
/* CF850C 8024099C 00C0202D */  daddu     $a0, $a2, $zero
.L802409A0:
/* CF8510 802409A0 8C820000 */  lw        $v0, ($a0)
/* CF8514 802409A4 00A2102A */  slt       $v0, $a1, $v0
/* CF8518 802409A8 14400006 */  bnez      $v0, .L802409C4
/* CF851C 802409AC 000310C0 */   sll      $v0, $v1, 3
/* CF8520 802409B0 24630001 */  addiu     $v1, $v1, 1
/* CF8524 802409B4 28620008 */  slti      $v0, $v1, 8
/* CF8528 802409B8 1440FFF9 */  bnez      $v0, .L802409A0
/* CF852C 802409BC 24840008 */   addiu    $a0, $a0, 8
/* CF8530 802409C0 000310C0 */  sll       $v0, $v1, 3
.L802409C4:
/* CF8534 802409C4 00461021 */  addu      $v0, $v0, $a2
/* CF8538 802409C8 8C420004 */  lw        $v0, 4($v0)
/* CF853C 802409CC 97A30010 */  lhu       $v1, 0x10($sp)
/* CF8540 802409D0 0202202A */  slt       $a0, $s0, $v0
/* CF8544 802409D4 32C2FFFF */  andi      $v0, $s6, 0xffff
/* CF8548 802409D8 14620008 */  bne       $v1, $v0, .L802409FC
/* CF854C 802409DC 32A2FFFF */   andi     $v0, $s5, 0xffff
/* CF8550 802409E0 97A7001E */  lhu       $a3, 0x1e($sp)
/* CF8554 802409E4 14E20005 */  bne       $a3, $v0, .L802409FC
/* CF8558 802409E8 32E2FFFF */   andi     $v0, $s7, 0xffff
/* CF855C 802409EC 14400003 */  bnez      $v0, .L802409FC
/* CF8560 802409F0 00000000 */   nop
/* CF8564 802409F4 14800008 */  bnez      $a0, .L80240A18
/* CF8568 802409F8 24020001 */   addiu    $v0, $zero, 1
.L802409FC:
/* CF856C 802409FC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CF8570 80240A00 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CF8574 80240A04 80420075 */  lb        $v0, 0x75($v0)
/* CF8578 80240A08 10400005 */  beqz      $v0, .L80240A20
/* CF857C 80240A0C 00000000 */   nop
/* CF8580 80240A10 10800003 */  beqz      $a0, .L80240A20
/* CF8584 80240A14 24020001 */   addiu    $v0, $zero, 1
.L80240A18:
/* CF8588 80240A18 0809028B */  j         .L80240A2C
/* CF858C 80240A1C AE220084 */   sw       $v0, 0x84($s1)
.L80240A20:
/* CF8590 80240A20 0C00F9EB */  jal       kill_enemy
/* CF8594 80240A24 03C0202D */   daddu    $a0, $fp, $zero
/* CF8598 80240A28 AE200084 */  sw        $zero, 0x84($s1)
.L80240A2C:
/* CF859C 80240A2C 8FBF0044 */  lw        $ra, 0x44($sp)
/* CF85A0 80240A30 8FBE0040 */  lw        $fp, 0x40($sp)
/* CF85A4 80240A34 8FB7003C */  lw        $s7, 0x3c($sp)
/* CF85A8 80240A38 8FB60038 */  lw        $s6, 0x38($sp)
/* CF85AC 80240A3C 8FB50034 */  lw        $s5, 0x34($sp)
/* CF85B0 80240A40 8FB40030 */  lw        $s4, 0x30($sp)
/* CF85B4 80240A44 8FB3002C */  lw        $s3, 0x2c($sp)
/* CF85B8 80240A48 8FB20028 */  lw        $s2, 0x28($sp)
/* CF85BC 80240A4C 8FB10024 */  lw        $s1, 0x24($sp)
/* CF85C0 80240A50 8FB00020 */  lw        $s0, 0x20($sp)
/* CF85C4 80240A54 24020002 */  addiu     $v0, $zero, 2
/* CF85C8 80240A58 03E00008 */  jr        $ra
/* CF85CC 80240A5C 27BD0048 */   addiu    $sp, $sp, 0x48

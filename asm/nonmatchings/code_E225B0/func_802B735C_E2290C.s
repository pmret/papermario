.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B735C_E2290C
/* E2290C 802B735C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E22910 802B7360 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* E22914 802B7364 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* E22918 802B7368 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2291C 802B736C 84A200B0 */  lh        $v0, 0xb0($a1)
/* E22920 802B7370 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* E22924 802B7374 44821000 */  mtc1      $v0, $f2
/* E22928 802B7378 00000000 */  nop       
/* E2292C 802B737C 468010A0 */  cvt.s.w   $f2, $f2
/* E22930 802B7380 46020000 */  add.s     $f0, $f0, $f2
/* E22934 802B7384 3C014120 */  lui       $at, 0x4120
/* E22938 802B7388 44811000 */  mtc1      $at, $f2
/* E2293C 802B738C 3C04802B */  lui       $a0, %hi(D_802B7C78)
/* E22940 802B7390 8C847C78 */  lw        $a0, %lo(D_802B7C78)($a0)
/* E22944 802B7394 46020000 */  add.s     $f0, $f0, $f2
/* E22948 802B7398 C4820004 */  lwc1      $f2, 4($a0)
/* E2294C 802B739C 46020001 */  sub.s     $f0, $f0, $f2
/* E22950 802B73A0 3C013FC0 */  lui       $at, 0x3fc0
/* E22954 802B73A4 44812000 */  mtc1      $at, $f4
/* E22958 802B73A8 00000000 */  nop       
/* E2295C 802B73AC 46040003 */  div.s     $f0, $f0, $f4
/* E22960 802B73B0 46001080 */  add.s     $f2, $f2, $f0
/* E22964 802B73B4 8C830024 */  lw        $v1, 0x24($a0)
/* E22968 802B73B8 E4820004 */  swc1      $f2, 4($a0)
/* E2296C 802B73BC C4A00028 */  lwc1      $f0, 0x28($a1)
/* E22970 802B73C0 3C068011 */  lui       $a2, %hi(D_8010EBB0)
/* E22974 802B73C4 24C6EBB0 */  addiu     $a2, $a2, %lo(D_8010EBB0)
/* E22978 802B73C8 E4800000 */  swc1      $f0, ($a0)
/* E2297C 802B73CC C4A00030 */  lwc1      $f0, 0x30($a1)
/* E22980 802B73D0 24020001 */  addiu     $v0, $zero, 1
/* E22984 802B73D4 10620022 */  beq       $v1, $v0, .L802B7460
/* E22988 802B73D8 E4800008 */   swc1     $f0, 8($a0)
/* E2298C 802B73DC 28620002 */  slti      $v0, $v1, 2
/* E22990 802B73E0 50400005 */  beql      $v0, $zero, .L802B73F8
/* E22994 802B73E4 24020002 */   addiu    $v0, $zero, 2
/* E22998 802B73E8 10600009 */  beqz      $v1, .L802B7410
/* E2299C 802B73EC 00000000 */   nop      
/* E229A0 802B73F0 080ADD5A */  j         .L802B7568
/* E229A4 802B73F4 00000000 */   nop      
.L802B73F8:
/* E229A8 802B73F8 1062002D */  beq       $v1, $v0, .L802B74B0
/* E229AC 802B73FC 24020003 */   addiu    $v0, $zero, 3
/* E229B0 802B7400 10620037 */  beq       $v1, $v0, .L802B74E0
/* E229B4 802B7404 00000000 */   nop      
/* E229B8 802B7408 080ADD5A */  j         .L802B7568
/* E229BC 802B740C 00000000 */   nop      
.L802B7410:
/* E229C0 802B7410 80C20000 */  lb        $v0, ($a2)
/* E229C4 802B7414 10400008 */  beqz      $v0, .L802B7438
/* E229C8 802B7418 24020008 */   addiu    $v0, $zero, 8
/* E229CC 802B741C 80C30003 */  lb        $v1, 3($a2)
/* E229D0 802B7420 14620005 */  bne       $v1, $v0, .L802B7438
/* E229D4 802B7424 00000000 */   nop      
/* E229D8 802B7428 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E229DC 802B742C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E229E0 802B7430 080ADD10 */  j         .L802B7440
/* E229E4 802B7434 8042007D */   lb       $v0, 0x7d($v0)
.L802B7438:
/* E229E8 802B7438 8CA20000 */  lw        $v0, ($a1)
/* E229EC 802B743C 30423000 */  andi      $v0, $v0, 0x3000
.L802B7440:
/* E229F0 802B7440 14400049 */  bnez      $v0, .L802B7568
/* E229F4 802B7444 00000000 */   nop      
/* E229F8 802B7448 3C03802B */  lui       $v1, %hi(D_802B7C78)
/* E229FC 802B744C 8C637C78 */  lw        $v1, %lo(D_802B7C78)($v1)
/* E22A00 802B7450 8C620024 */  lw        $v0, 0x24($v1)
/* E22A04 802B7454 24420001 */  addiu     $v0, $v0, 1
/* E22A08 802B7458 080ADD5A */  j         .L802B7568
/* E22A0C 802B745C AC620024 */   sw       $v0, 0x24($v1)
.L802B7460:
/* E22A10 802B7460 8CA20000 */  lw        $v0, ($a1)
/* E22A14 802B7464 30420020 */  andi      $v0, $v0, 0x20
/* E22A18 802B7468 10400003 */  beqz      $v0, .L802B7478
/* E22A1C 802B746C 24020003 */   addiu    $v0, $zero, 3
/* E22A20 802B7470 080ADD5A */  j         .L802B7568
/* E22A24 802B7474 AC820024 */   sw       $v0, 0x24($a0)
.L802B7478:
/* E22A28 802B7478 8C820018 */  lw        $v0, 0x18($a0)
/* E22A2C 802B747C 0040182D */  daddu     $v1, $v0, $zero
/* E22A30 802B7480 24420001 */  addiu     $v0, $v0, 1
/* E22A34 802B7484 28630010 */  slti      $v1, $v1, 0x10
/* E22A38 802B7488 14600037 */  bnez      $v1, .L802B7568
/* E22A3C 802B748C AC820018 */   sw       $v0, 0x18($a0)
/* E22A40 802B7490 8C820024 */  lw        $v0, 0x24($a0)
/* E22A44 802B7494 3C013EB8 */  lui       $at, 0x3eb8
/* E22A48 802B7498 342151EC */  ori       $at, $at, 0x51ec
/* E22A4C 802B749C 44810000 */  mtc1      $at, $f0
/* E22A50 802B74A0 24420001 */  addiu     $v0, $v0, 1
/* E22A54 802B74A4 E480000C */  swc1      $f0, 0xc($a0)
/* E22A58 802B74A8 080ADD5A */  j         .L802B7568
/* E22A5C 802B74AC AC820024 */   sw       $v0, 0x24($a0)
.L802B74B0:
/* E22A60 802B74B0 0000282D */  daddu     $a1, $zero, $zero
/* E22A64 802B74B4 8C820024 */  lw        $v0, 0x24($a0)
/* E22A68 802B74B8 3C013F11 */  lui       $at, 0x3f11
/* E22A6C 802B74BC 3421EB85 */  ori       $at, $at, 0xeb85
/* E22A70 802B74C0 44810000 */  mtc1      $at, $f0
/* E22A74 802B74C4 24420001 */  addiu     $v0, $v0, 1
/* E22A78 802B74C8 E480000C */  swc1      $f0, 0xc($a0)
/* E22A7C 802B74CC AC820024 */  sw        $v0, 0x24($a0)
/* E22A80 802B74D0 0C052736 */  jal       play_sound_at_player
/* E22A84 802B74D4 2404017B */   addiu    $a0, $zero, 0x17b
/* E22A88 802B74D8 080ADD5A */  j         .L802B7568
/* E22A8C 802B74DC 00000000 */   nop      
.L802B74E0:
/* E22A90 802B74E0 8C820018 */  lw        $v0, 0x18($a0)
/* E22A94 802B74E4 3C013F07 */  lui       $at, 0x3f07
/* E22A98 802B74E8 3421AE14 */  ori       $at, $at, 0xae14
/* E22A9C 802B74EC 44810000 */  mtc1      $at, $f0
/* E22AA0 802B74F0 2842002F */  slti      $v0, $v0, 0x2f
/* E22AA4 802B74F4 10400005 */  beqz      $v0, .L802B750C
/* E22AA8 802B74F8 E480000C */   swc1     $f0, 0xc($a0)
/* E22AAC 802B74FC 8CA20000 */  lw        $v0, ($a1)
/* E22AB0 802B7500 30420020 */  andi      $v0, $v0, 0x20
/* E22AB4 802B7504 10400008 */  beqz      $v0, .L802B7528
/* E22AB8 802B7508 00000000 */   nop      
.L802B750C:
/* E22ABC 802B750C 8C820028 */  lw        $v0, 0x28($a0)
/* E22AC0 802B7510 2442FFC0 */  addiu     $v0, $v0, -0x40
/* E22AC4 802B7514 04410004 */  bgez      $v0, .L802B7528
/* E22AC8 802B7518 AC820028 */   sw       $v0, 0x28($a0)
/* E22ACC 802B751C 24020033 */  addiu     $v0, $zero, 0x33
/* E22AD0 802B7520 AC800028 */  sw        $zero, 0x28($a0)
/* E22AD4 802B7524 AC820018 */  sw        $v0, 0x18($a0)
.L802B7528:
/* E22AD8 802B7528 3C02802B */  lui       $v0, %hi(D_802B7C78)
/* E22ADC 802B752C 8C427C78 */  lw        $v0, %lo(D_802B7C78)($v0)
/* E22AE0 802B7530 8C430018 */  lw        $v1, 0x18($v0)
/* E22AE4 802B7534 0060202D */  daddu     $a0, $v1, $zero
/* E22AE8 802B7538 24630001 */  addiu     $v1, $v1, 1
/* E22AEC 802B753C 28840033 */  slti      $a0, $a0, 0x33
/* E22AF0 802B7540 14800009 */  bnez      $a0, .L802B7568
/* E22AF4 802B7544 AC430018 */   sw       $v1, 0x18($v0)
/* E22AF8 802B7548 3C018016 */  lui       $at, %hi(D_8015A57A)
/* E22AFC 802B754C A020A57A */  sb        $zero, %lo(D_8015A57A)($at)
/* E22B00 802B7550 8CA20004 */  lw        $v0, 4($a1)
/* E22B04 802B7554 2403FEFF */  addiu     $v1, $zero, -0x101
/* E22B08 802B7558 3C018011 */  lui       $at, %hi(D_8010C93C)
/* E22B0C 802B755C AC20C93C */  sw        $zero, %lo(D_8010C93C)($at)
/* E22B10 802B7560 00431024 */  and       $v0, $v0, $v1
/* E22B14 802B7564 ACA20004 */  sw        $v0, 4($a1)
.L802B7568:
/* E22B18 802B7568 8FBF0010 */  lw        $ra, 0x10($sp)
/* E22B1C 802B756C 03E00008 */  jr        $ra
/* E22B20 802B7570 27BD0018 */   addiu    $sp, $sp, 0x18
/* E22B24 802B7574 00000000 */  nop       
/* E22B28 802B7578 00000000 */  nop       
/* E22B2C 802B757C 00000000 */  nop       

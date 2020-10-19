.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413CC
/* 9D83EC 802413CC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9D83F0 802413D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9D83F4 802413D4 0080982D */  daddu     $s3, $a0, $zero
/* 9D83F8 802413D8 AFBF0040 */  sw        $ra, 0x40($sp)
/* 9D83FC 802413DC AFB20038 */  sw        $s2, 0x38($sp)
/* 9D8400 802413E0 AFB10034 */  sw        $s1, 0x34($sp)
/* 9D8404 802413E4 AFB00030 */  sw        $s0, 0x30($sp)
/* 9D8408 802413E8 8E720148 */  lw        $s2, 0x148($s3)
/* 9D840C 802413EC 00A0882D */  daddu     $s1, $a1, $zero
/* 9D8410 802413F0 86440008 */  lh        $a0, 8($s2)
/* 9D8414 802413F4 0C00EABB */  jal       get_npc_unsafe
/* 9D8418 802413F8 00C0802D */   daddu    $s0, $a2, $zero
/* 9D841C 802413FC 0200202D */  daddu     $a0, $s0, $zero
/* 9D8420 80241400 0240282D */  daddu     $a1, $s2, $zero
/* 9D8424 80241404 24030001 */  addiu     $v1, $zero, 1
/* 9D8428 80241408 AFA30010 */  sw        $v1, 0x10($sp)
/* 9D842C 8024140C 8E260024 */  lw        $a2, 0x24($s1)
/* 9D8430 80241410 8E270028 */  lw        $a3, 0x28($s1)
/* 9D8434 80241414 0C01242D */  jal       func_800490B4
/* 9D8438 80241418 0040802D */   daddu    $s0, $v0, $zero
/* 9D843C 8024141C 1440001E */  bnez      $v0, .L80241498
/* 9D8440 80241420 0200202D */   daddu    $a0, $s0, $zero
/* 9D8444 80241424 24040002 */  addiu     $a0, $zero, 2
/* 9D8448 80241428 0200282D */  daddu     $a1, $s0, $zero
/* 9D844C 8024142C 0000302D */  daddu     $a2, $zero, $zero
/* 9D8450 80241430 860300A8 */  lh        $v1, 0xa8($s0)
/* 9D8454 80241434 3C013F80 */  lui       $at, 0x3f80
/* 9D8458 80241438 44810000 */  mtc1      $at, $f0
/* 9D845C 8024143C 3C014000 */  lui       $at, 0x4000
/* 9D8460 80241440 44811000 */  mtc1      $at, $f2
/* 9D8464 80241444 3C01C1A0 */  lui       $at, 0xc1a0
/* 9D8468 80241448 44812000 */  mtc1      $at, $f4
/* 9D846C 8024144C 2402000F */  addiu     $v0, $zero, 0xf
/* 9D8470 80241450 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9D8474 80241454 44833000 */  mtc1      $v1, $f6
/* 9D8478 80241458 00000000 */  nop       
/* 9D847C 8024145C 468031A0 */  cvt.s.w   $f6, $f6
/* 9D8480 80241460 44073000 */  mfc1      $a3, $f6
/* 9D8484 80241464 27A20028 */  addiu     $v0, $sp, 0x28
/* 9D8488 80241468 AFA20020 */  sw        $v0, 0x20($sp)
/* 9D848C 8024146C E7A00010 */  swc1      $f0, 0x10($sp)
/* 9D8490 80241470 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9D8494 80241474 0C01BFA4 */  jal       fx_emote
/* 9D8498 80241478 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9D849C 8024147C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9D84A0 80241480 8C430000 */  lw        $v1, ($v0)
/* 9D84A4 80241484 24020019 */  addiu     $v0, $zero, 0x19
/* 9D84A8 80241488 A602008E */  sh        $v0, 0x8e($s0)
/* 9D84AC 8024148C 2402000E */  addiu     $v0, $zero, 0xe
/* 9D84B0 80241490 08090533 */  j         .L802414CC
/* 9D84B4 80241494 AE030028 */   sw       $v1, 0x28($s0)
.L80241498:
/* 9D84B8 80241498 0C00F598 */  jal       func_8003D660
/* 9D84BC 8024149C 24050001 */   addiu    $a1, $zero, 1
/* 9D84C0 802414A0 8E050018 */  lw        $a1, 0x18($s0)
/* 9D84C4 802414A4 8E06000C */  lw        $a2, 0xc($s0)
/* 9D84C8 802414A8 0C00EA95 */  jal       npc_move_heading
/* 9D84CC 802414AC 0200202D */   daddu    $a0, $s0, $zero
/* 9D84D0 802414B0 8602008E */  lh        $v0, 0x8e($s0)
/* 9D84D4 802414B4 9603008E */  lhu       $v1, 0x8e($s0)
/* 9D84D8 802414B8 18400003 */  blez      $v0, .L802414C8
/* 9D84DC 802414BC 2462FFFF */   addiu    $v0, $v1, -1
/* 9D84E0 802414C0 08090534 */  j         .L802414D0
/* 9D84E4 802414C4 A602008E */   sh       $v0, 0x8e($s0)
.L802414C8:
/* 9D84E8 802414C8 2402000C */  addiu     $v0, $zero, 0xc
.L802414CC:
/* 9D84EC 802414CC AE620070 */  sw        $v0, 0x70($s3)
.L802414D0:
/* 9D84F0 802414D0 8FBF0040 */  lw        $ra, 0x40($sp)
/* 9D84F4 802414D4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9D84F8 802414D8 8FB20038 */  lw        $s2, 0x38($sp)
/* 9D84FC 802414DC 8FB10034 */  lw        $s1, 0x34($sp)
/* 9D8500 802414E0 8FB00030 */  lw        $s0, 0x30($sp)
/* 9D8504 802414E4 03E00008 */  jr        $ra
/* 9D8508 802414E8 27BD0048 */   addiu    $sp, $sp, 0x48

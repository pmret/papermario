.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel make_transform_group
/* B1A7C 8011B37C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B1A80 8011B380 3C038015 */  lui       $v1, %hi(D_801512FC)
/* B1A84 8011B384 8C6312FC */  lw        $v1, %lo(D_801512FC)($v1)
/* B1A88 8011B388 0080102D */  daddu     $v0, $a0, $zero
/* B1A8C 8011B38C AFB00030 */  sw        $s0, 0x30($sp)
/* B1A90 8011B390 3C108015 */  lui       $s0, %hi(D_80153370)
/* B1A94 8011B394 26103370 */  addiu     $s0, $s0, %lo(D_80153370)
/* B1A98 8011B398 AFBF003C */  sw        $ra, 0x3c($sp)
/* B1A9C 8011B39C AFB20038 */  sw        $s2, 0x38($sp)
/* B1AA0 8011B3A0 AFB10034 */  sw        $s1, 0x34($sp)
/* B1AA4 8011B3A4 3C018015 */  lui       $at, %hi(D_80153224)
/* B1AA8 8011B3A8 AC203224 */  sw        $zero, %lo(D_80153224)($at)
/* B1AAC 8011B3AC AE000000 */  sw        $zero, ($s0)
/* B1AB0 8011B3B0 3C018015 */  lui       $at, %hi(D_8015336E)
/* B1AB4 8011B3B4 A422336E */  sh        $v0, %lo(D_8015336E)($at)
/* B1AB8 8011B3B8 3C018015 */  lui       $at, %hi(D_80153376)
/* B1ABC 8011B3BC A4203376 */  sh        $zero, %lo(D_80153376)($at)
/* B1AC0 8011B3C0 3C018015 */  lui       $at, %hi(D_80153374)
/* B1AC4 8011B3C4 A4203374 */  sh        $zero, %lo(D_80153374)($at)
/* B1AC8 8011B3C8 8C640000 */  lw        $a0, ($v1)
/* B1ACC 8011B3CC 0C046C76 */  jal       func_8011B1D8
/* B1AD0 8011B3D0 0040902D */   daddu    $s2, $v0, $zero
/* B1AD4 8011B3D4 8E020000 */  lw        $v0, ($s0)
/* B1AD8 8011B3D8 10400077 */  beqz      $v0, .L8011B5B8
/* B1ADC 8011B3DC 0000802D */   daddu    $s0, $zero, $zero
/* B1AE0 8011B3E0 3C118015 */  lui       $s1, %hi(gCurrentTransformGroups)
/* B1AE4 8011B3E4 263112E0 */  addiu     $s1, $s1, %lo(gCurrentTransformGroups)
/* B1AE8 8011B3E8 8E230000 */  lw        $v1, ($s1)
.L8011B3EC:
/* B1AEC 8011B3EC 8C620000 */  lw        $v0, ($v1)
/* B1AF0 8011B3F0 10400005 */  beqz      $v0, .L8011B408
/* B1AF4 8011B3F4 00000000 */   nop
/* B1AF8 8011B3F8 26100001 */  addiu     $s0, $s0, 1
/* B1AFC 8011B3FC 2A020004 */  slti      $v0, $s0, 4
/* B1B00 8011B400 1440FFFA */  bnez      $v0, .L8011B3EC
/* B1B04 8011B404 24630004 */   addiu    $v1, $v1, 4
.L8011B408:
/* B1B08 8011B408 0C00AB39 */  jal       heap_malloc
/* B1B0C 8011B40C 240400A0 */   addiu    $a0, $zero, 0xa0
/* B1B10 8011B410 00101880 */  sll       $v1, $s0, 2
/* B1B14 8011B414 0040802D */  daddu     $s0, $v0, $zero
/* B1B18 8011B418 24020001 */  addiu     $v0, $zero, 1
/* B1B1C 8011B41C 8E250000 */  lw        $a1, ($s1)
/* B1B20 8011B420 3C048015 */  lui       $a0, %hi(D_80153374)
/* B1B24 8011B424 94843374 */  lhu       $a0, %lo(D_80153374)($a0)
/* B1B28 8011B428 00651821 */  addu      $v1, $v1, $a1
/* B1B2C 8011B42C AC700000 */  sw        $s0, ($v1)
/* B1B30 8011B430 A6020000 */  sh        $v0, ($s0)
/* B1B34 8011B434 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B1B38 8011B438 A6120002 */   sh       $s2, 2($s0)
/* B1B3C 8011B43C A202009C */  sb        $v0, 0x9c($s0)
/* B1B40 8011B440 3C048015 */  lui       $a0, %hi(D_80153376)
/* B1B44 8011B444 94843376 */  lhu       $a0, %lo(D_80153376)($a0)
/* B1B48 8011B448 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B1B4C 8011B44C 00000000 */   nop
/* B1B50 8011B450 A202009D */  sb        $v0, 0x9d($s0)
/* B1B54 8011B454 A200009F */  sb        $zero, 0x9f($s0)
/* B1B58 8011B458 3C028015 */  lui       $v0, %hi(D_80153370)
/* B1B5C 8011B45C 8C423370 */  lw        $v0, %lo(D_80153370)($v0)
/* B1B60 8011B460 26040010 */  addiu     $a0, $s0, 0x10
/* B1B64 8011B464 AE000004 */  sw        $zero, 4($s0)
/* B1B68 8011B468 0C019D10 */  jal       guMtxIdent
/* B1B6C 8011B46C AE020008 */   sw       $v0, 8($s0)
/* B1B70 8011B470 96020000 */  lhu       $v0, ($s0)
/* B1B74 8011B474 26040050 */  addiu     $a0, $s0, 0x50
/* B1B78 8011B478 34422000 */  ori       $v0, $v0, 0x2000
/* B1B7C 8011B47C 0C019D28 */  jal       guMtxIdentF
/* B1B80 8011B480 A6020000 */   sh       $v0, ($s0)
/* B1B84 8011B484 8E110008 */  lw        $s1, 8($s0)
/* B1B88 8011B488 8E230000 */  lw        $v1, ($s1)
/* B1B8C 8011B48C 24020005 */  addiu     $v0, $zero, 5
/* B1B90 8011B490 10620005 */  beq       $v1, $v0, .L8011B4A8
/* B1B94 8011B494 0220202D */   daddu    $a0, $s1, $zero
/* B1B98 8011B498 0C0456C3 */  jal       get_model_property
/* B1B9C 8011B49C 2405005C */   addiu    $a1, $zero, 0x5c
/* B1BA0 8011B4A0 08046D2E */  j         .L8011B4B8
/* B1BA4 8011B4A4 00000000 */   nop
.L8011B4A8:
/* B1BA8 8011B4A8 0C0456C3 */  jal       get_model_property
/* B1BAC 8011B4AC 24050060 */   addiu    $a1, $zero, 0x60
/* B1BB0 8011B4B0 10400006 */  beqz      $v0, .L8011B4CC
/* B1BB4 8011B4B4 2442000C */   addiu    $v0, $v0, 0xc
.L8011B4B8:
/* B1BB8 8011B4B8 50400005 */  beql      $v0, $zero, .L8011B4D0
/* B1BBC 8011B4BC 24020001 */   addiu    $v0, $zero, 1
/* B1BC0 8011B4C0 9042000B */  lbu       $v0, 0xb($v0)
/* B1BC4 8011B4C4 08046D35 */  j         .L8011B4D4
/* B1BC8 8011B4C8 A202009E */   sb       $v0, 0x9e($s0)
.L8011B4CC:
/* B1BCC 8011B4CC 24020001 */  addiu     $v0, $zero, 1
.L8011B4D0:
/* B1BD0 8011B4D0 A202009E */  sb        $v0, 0x9e($s0)
.L8011B4D4:
/* B1BD4 8011B4D4 0220202D */  daddu     $a0, $s1, $zero
/* B1BD8 8011B4D8 0C0456C3 */  jal       get_model_property
/* B1BDC 8011B4DC 24050061 */   addiu    $a1, $zero, 0x61
/* B1BE0 8011B4E0 10400017 */  beqz      $v0, .L8011B540
/* B1BE4 8011B4E4 00000000 */   nop
/* B1BE8 8011B4E8 C4460008 */  lwc1      $f6, 8($v0)
/* B1BEC 8011B4EC C440002C */  lwc1      $f0, 0x2c($v0)
/* B1BF0 8011B4F0 46003180 */  add.s     $f6, $f6, $f0
/* B1BF4 8011B4F4 3C013F00 */  lui       $at, 0x3f00
/* B1BF8 8011B4F8 44814000 */  mtc1      $at, $f8
/* B1BFC 8011B4FC 00000000 */  nop
/* B1C00 8011B500 46083182 */  mul.s     $f6, $f6, $f8
/* B1C04 8011B504 00000000 */  nop
/* B1C08 8011B508 C4440014 */  lwc1      $f4, 0x14($v0)
/* B1C0C 8011B50C C4400038 */  lwc1      $f0, 0x38($v0)
/* B1C10 8011B510 46002100 */  add.s     $f4, $f4, $f0
/* B1C14 8011B514 46082102 */  mul.s     $f4, $f4, $f8
/* B1C18 8011B518 00000000 */  nop
/* B1C1C 8011B51C C4420044 */  lwc1      $f2, 0x44($v0)
/* B1C20 8011B520 C4400020 */  lwc1      $f0, 0x20($v0)
/* B1C24 8011B524 46020000 */  add.s     $f0, $f0, $f2
/* B1C28 8011B528 46080002 */  mul.s     $f0, $f0, $f8
/* B1C2C 8011B52C 00000000 */  nop
/* B1C30 8011B530 E7A60020 */  swc1      $f6, 0x20($sp)
/* B1C34 8011B534 E7A40024 */  swc1      $f4, 0x24($sp)
/* B1C38 8011B538 08046D55 */  j         .L8011B554
/* B1C3C 8011B53C E7A00028 */   swc1     $f0, 0x28($sp)
.L8011B540:
/* B1C40 8011B540 44800000 */  mtc1      $zero, $f0
/* B1C44 8011B544 00000000 */  nop
/* B1C48 8011B548 E7A00028 */  swc1      $f0, 0x28($sp)
/* B1C4C 8011B54C E7A00024 */  swc1      $f0, 0x24($sp)
/* B1C50 8011B550 E7A00020 */  swc1      $f0, 0x20($sp)
.L8011B554:
/* B1C54 8011B554 8E020004 */  lw        $v0, 4($s0)
/* B1C58 8011B558 1040000F */  beqz      $v0, .L8011B598
/* B1C5C 8011B55C 27A20020 */   addiu    $v0, $sp, 0x20
/* B1C60 8011B560 C7A00020 */  lwc1      $f0, 0x20($sp)
/* B1C64 8011B564 C7A20024 */  lwc1      $f2, 0x24($sp)
/* B1C68 8011B568 C7A40028 */  lwc1      $f4, 0x28($sp)
/* B1C6C 8011B56C AFA20010 */  sw        $v0, 0x10($sp)
/* B1C70 8011B570 27A20024 */  addiu     $v0, $sp, 0x24
/* B1C74 8011B574 AFA20014 */  sw        $v0, 0x14($sp)
/* B1C78 8011B578 27A20028 */  addiu     $v0, $sp, 0x28
/* B1C7C 8011B57C AFA20018 */  sw        $v0, 0x18($sp)
/* B1C80 8011B580 8E040004 */  lw        $a0, 4($s0)
/* B1C84 8011B584 44050000 */  mfc1      $a1, $f0
/* B1C88 8011B588 44061000 */  mfc1      $a2, $f2
/* B1C8C 8011B58C 44072000 */  mfc1      $a3, $f4
/* B1C90 8011B590 0C019E78 */  jal       guMtxXFML
/* B1C94 8011B594 00000000 */   nop
.L8011B598:
/* B1C98 8011B598 C7A00020 */  lwc1      $f0, 0x20($sp)
/* B1C9C 8011B59C C7A20024 */  lwc1      $f2, 0x24($sp)
/* B1CA0 8011B5A0 C7A40028 */  lwc1      $f4, 0x28($sp)
/* B1CA4 8011B5A4 3244FFFF */  andi      $a0, $s2, 0xffff
/* B1CA8 8011B5A8 E6000090 */  swc1      $f0, 0x90($s0)
/* B1CAC 8011B5AC E6020094 */  swc1      $f2, 0x94($s0)
/* B1CB0 8011B5B0 0C046D74 */  jal       enable_transform_group
/* B1CB4 8011B5B4 E6040098 */   swc1     $f4, 0x98($s0)
.L8011B5B8:
/* B1CB8 8011B5B8 8FBF003C */  lw        $ra, 0x3c($sp)
/* B1CBC 8011B5BC 8FB20038 */  lw        $s2, 0x38($sp)
/* B1CC0 8011B5C0 8FB10034 */  lw        $s1, 0x34($sp)
/* B1CC4 8011B5C4 8FB00030 */  lw        $s0, 0x30($sp)
/* B1CC8 8011B5C8 03E00008 */  jr        $ra
/* B1CCC 8011B5CC 27BD0040 */   addiu    $sp, $sp, 0x40

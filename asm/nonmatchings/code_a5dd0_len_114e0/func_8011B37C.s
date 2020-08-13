.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011B37C
/* 0B1A7C 8011B37C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0B1A80 8011B380 3C038015 */  lui   $v1, 0x8015
/* 0B1A84 8011B384 8C6312FC */  lw    $v1, 0x12fc($v1)
/* 0B1A88 8011B388 0080102D */  daddu $v0, $a0, $zero
/* 0B1A8C 8011B38C AFB00030 */  sw    $s0, 0x30($sp)
/* 0B1A90 8011B390 3C108015 */  lui   $s0, 0x8015
/* 0B1A94 8011B394 26103370 */  addiu $s0, $s0, 0x3370
/* 0B1A98 8011B398 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0B1A9C 8011B39C AFB20038 */  sw    $s2, 0x38($sp)
/* 0B1AA0 8011B3A0 AFB10034 */  sw    $s1, 0x34($sp)
/* 0B1AA4 8011B3A4 3C018015 */  lui   $at, 0x8015
/* 0B1AA8 8011B3A8 AC203224 */  sw    $zero, 0x3224($at)
/* 0B1AAC 8011B3AC AE000000 */  sw    $zero, ($s0)
/* 0B1AB0 8011B3B0 3C018015 */  lui   $at, 0x8015
/* 0B1AB4 8011B3B4 A422336E */  sh    $v0, 0x336e($at)
/* 0B1AB8 8011B3B8 3C018015 */  lui   $at, 0x8015
/* 0B1ABC 8011B3BC A4203376 */  sh    $zero, 0x3376($at)
/* 0B1AC0 8011B3C0 3C018015 */  lui   $at, 0x8015
/* 0B1AC4 8011B3C4 A4203374 */  sh    $zero, 0x3374($at)
/* 0B1AC8 8011B3C8 8C640000 */  lw    $a0, ($v1)
/* 0B1ACC 8011B3CC 0C046C76 */  jal   func_8011B1D8
/* 0B1AD0 8011B3D0 0040902D */   daddu $s2, $v0, $zero
/* 0B1AD4 8011B3D4 8E020000 */  lw    $v0, ($s0)
/* 0B1AD8 8011B3D8 10400077 */  beqz  $v0, .L8011B5B8
/* 0B1ADC 8011B3DC 0000802D */   daddu $s0, $zero, $zero
/* 0B1AE0 8011B3E0 3C118015 */  lui   $s1, 0x8015
/* 0B1AE4 8011B3E4 263112E0 */  addiu $s1, $s1, 0x12e0
/* 0B1AE8 8011B3E8 8E230000 */  lw    $v1, ($s1)
.L8011B3EC:
/* 0B1AEC 8011B3EC 8C620000 */  lw    $v0, ($v1)
/* 0B1AF0 8011B3F0 10400005 */  beqz  $v0, .L8011B408
/* 0B1AF4 8011B3F4 00000000 */   nop   
/* 0B1AF8 8011B3F8 26100001 */  addiu $s0, $s0, 1
/* 0B1AFC 8011B3FC 2A020004 */  slti  $v0, $s0, 4
/* 0B1B00 8011B400 1440FFFA */  bnez  $v0, .L8011B3EC
/* 0B1B04 8011B404 24630004 */   addiu $v1, $v1, 4
.L8011B408:
/* 0B1B08 8011B408 0C00AB39 */  jal   heap_malloc
/* 0B1B0C 8011B40C 240400A0 */   addiu $a0, $zero, 0xa0
/* 0B1B10 8011B410 00101880 */  sll   $v1, $s0, 2
/* 0B1B14 8011B414 0040802D */  daddu $s0, $v0, $zero
/* 0B1B18 8011B418 24020001 */  addiu $v0, $zero, 1
/* 0B1B1C 8011B41C 8E250000 */  lw    $a1, ($s1)
/* 0B1B20 8011B420 3C048015 */  lui   $a0, 0x8015
/* 0B1B24 8011B424 94843374 */  lhu   $a0, 0x3374($a0)
/* 0B1B28 8011B428 00651821 */  addu  $v1, $v1, $a1
/* 0B1B2C 8011B42C AC700000 */  sw    $s0, ($v1)
/* 0B1B30 8011B430 A6020000 */  sh    $v0, ($s0)
/* 0B1B34 8011B434 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0B1B38 8011B438 A6120002 */   sh    $s2, 2($s0)
/* 0B1B3C 8011B43C A202009C */  sb    $v0, 0x9c($s0)
/* 0B1B40 8011B440 3C048015 */  lui   $a0, 0x8015
/* 0B1B44 8011B444 94843376 */  lhu   $a0, 0x3376($a0)
/* 0B1B48 8011B448 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0B1B4C 8011B44C 00000000 */   nop   
/* 0B1B50 8011B450 A202009D */  sb    $v0, 0x9d($s0)
/* 0B1B54 8011B454 A200009F */  sb    $zero, 0x9f($s0)
/* 0B1B58 8011B458 3C028015 */  lui   $v0, 0x8015
/* 0B1B5C 8011B45C 8C423370 */  lw    $v0, 0x3370($v0)
/* 0B1B60 8011B460 26040010 */  addiu $a0, $s0, 0x10
/* 0B1B64 8011B464 AE000004 */  sw    $zero, 4($s0)
/* 0B1B68 8011B468 0C019D10 */  jal   guMtxIdent
/* 0B1B6C 8011B46C AE020008 */   sw    $v0, 8($s0)
/* 0B1B70 8011B470 96020000 */  lhu   $v0, ($s0)
/* 0B1B74 8011B474 26040050 */  addiu $a0, $s0, 0x50
/* 0B1B78 8011B478 34422000 */  ori   $v0, $v0, 0x2000
/* 0B1B7C 8011B47C 0C019D28 */  jal   guMtxIdentF
/* 0B1B80 8011B480 A6020000 */   sh    $v0, ($s0)
/* 0B1B84 8011B484 8E110008 */  lw    $s1, 8($s0)
/* 0B1B88 8011B488 8E230000 */  lw    $v1, ($s1)
/* 0B1B8C 8011B48C 24020005 */  addiu $v0, $zero, 5
/* 0B1B90 8011B490 10620005 */  beq   $v1, $v0, .L8011B4A8
/* 0B1B94 8011B494 0220202D */   daddu $a0, $s1, $zero
/* 0B1B98 8011B498 0C0456C3 */  jal   get_model_property
/* 0B1B9C 8011B49C 2405005C */   addiu $a1, $zero, 0x5c
/* 0B1BA0 8011B4A0 08046D2E */  j     .L8011B4B8
/* 0B1BA4 8011B4A4 00000000 */   nop   

.L8011B4A8:
/* 0B1BA8 8011B4A8 0C0456C3 */  jal   get_model_property
/* 0B1BAC 8011B4AC 24050060 */   addiu $a1, $zero, 0x60
/* 0B1BB0 8011B4B0 10400006 */  beqz  $v0, .L8011B4CC
/* 0B1BB4 8011B4B4 2442000C */   addiu $v0, $v0, 0xc
.L8011B4B8:
/* 0B1BB8 8011B4B8 50400005 */  beql  $v0, $zero, .L8011B4D0
/* 0B1BBC 8011B4BC 24020001 */   addiu $v0, $zero, 1
/* 0B1BC0 8011B4C0 9042000B */  lbu   $v0, 0xb($v0)
/* 0B1BC4 8011B4C4 08046D35 */  j     .L8011B4D4
/* 0B1BC8 8011B4C8 A202009E */   sb    $v0, 0x9e($s0)

.L8011B4CC:
/* 0B1BCC 8011B4CC 24020001 */  addiu $v0, $zero, 1
.L8011B4D0:
/* 0B1BD0 8011B4D0 A202009E */  sb    $v0, 0x9e($s0)
.L8011B4D4:
/* 0B1BD4 8011B4D4 0220202D */  daddu $a0, $s1, $zero
/* 0B1BD8 8011B4D8 0C0456C3 */  jal   get_model_property
/* 0B1BDC 8011B4DC 24050061 */   addiu $a1, $zero, 0x61
/* 0B1BE0 8011B4E0 10400017 */  beqz  $v0, .L8011B540
/* 0B1BE4 8011B4E4 00000000 */   nop   
/* 0B1BE8 8011B4E8 C4460008 */  lwc1  $f6, 8($v0)
/* 0B1BEC 8011B4EC C440002C */  lwc1  $f0, 0x2c($v0)
/* 0B1BF0 8011B4F0 46003180 */  add.s $f6, $f6, $f0
/* 0B1BF4 8011B4F4 3C013F00 */  lui   $at, 0x3f00
/* 0B1BF8 8011B4F8 44814000 */  mtc1  $at, $f8
/* 0B1BFC 8011B4FC 00000000 */  nop   
/* 0B1C00 8011B500 46083182 */  mul.s $f6, $f6, $f8
/* 0B1C04 8011B504 00000000 */  nop   
/* 0B1C08 8011B508 C4440014 */  lwc1  $f4, 0x14($v0)
/* 0B1C0C 8011B50C C4400038 */  lwc1  $f0, 0x38($v0)
/* 0B1C10 8011B510 46002100 */  add.s $f4, $f4, $f0
/* 0B1C14 8011B514 46082102 */  mul.s $f4, $f4, $f8
/* 0B1C18 8011B518 00000000 */  nop   
/* 0B1C1C 8011B51C C4420044 */  lwc1  $f2, 0x44($v0)
/* 0B1C20 8011B520 C4400020 */  lwc1  $f0, 0x20($v0)
/* 0B1C24 8011B524 46020000 */  add.s $f0, $f0, $f2
/* 0B1C28 8011B528 46080002 */  mul.s $f0, $f0, $f8
/* 0B1C2C 8011B52C 00000000 */  nop   
/* 0B1C30 8011B530 E7A60020 */  swc1  $f6, 0x20($sp)
/* 0B1C34 8011B534 E7A40024 */  swc1  $f4, 0x24($sp)
/* 0B1C38 8011B538 08046D55 */  j     .L8011B554
/* 0B1C3C 8011B53C E7A00028 */   swc1  $f0, 0x28($sp)

.L8011B540:
/* 0B1C40 8011B540 44800000 */  mtc1  $zero, $f0
/* 0B1C44 8011B544 00000000 */  nop   
/* 0B1C48 8011B548 E7A00028 */  swc1  $f0, 0x28($sp)
/* 0B1C4C 8011B54C E7A00024 */  swc1  $f0, 0x24($sp)
/* 0B1C50 8011B550 E7A00020 */  swc1  $f0, 0x20($sp)
.L8011B554:
/* 0B1C54 8011B554 8E020004 */  lw    $v0, 4($s0)
/* 0B1C58 8011B558 1040000F */  beqz  $v0, .L8011B598
/* 0B1C5C 8011B55C 27A20020 */   addiu $v0, $sp, 0x20
/* 0B1C60 8011B560 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0B1C64 8011B564 C7A20024 */  lwc1  $f2, 0x24($sp)
/* 0B1C68 8011B568 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 0B1C6C 8011B56C AFA20010 */  sw    $v0, 0x10($sp)
/* 0B1C70 8011B570 27A20024 */  addiu $v0, $sp, 0x24
/* 0B1C74 8011B574 AFA20014 */  sw    $v0, 0x14($sp)
/* 0B1C78 8011B578 27A20028 */  addiu $v0, $sp, 0x28
/* 0B1C7C 8011B57C AFA20018 */  sw    $v0, 0x18($sp)
/* 0B1C80 8011B580 8E040004 */  lw    $a0, 4($s0)
/* 0B1C84 8011B584 44050000 */  mfc1  $a1, $f0
/* 0B1C88 8011B588 44061000 */  mfc1  $a2, $f2
/* 0B1C8C 8011B58C 44072000 */  mfc1  $a3, $f4
/* 0B1C90 8011B590 0C019E78 */  jal   guMtxXFML
/* 0B1C94 8011B594 00000000 */   nop   
.L8011B598:
/* 0B1C98 8011B598 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0B1C9C 8011B59C C7A20024 */  lwc1  $f2, 0x24($sp)
/* 0B1CA0 8011B5A0 C7A40028 */  lwc1  $f4, 0x28($sp)
/* 0B1CA4 8011B5A4 3244FFFF */  andi  $a0, $s2, 0xffff
/* 0B1CA8 8011B5A8 E6000090 */  swc1  $f0, 0x90($s0)
/* 0B1CAC 8011B5AC E6020094 */  swc1  $f2, 0x94($s0)
/* 0B1CB0 8011B5B0 0C046D74 */  jal   func_8011B5D0
/* 0B1CB4 8011B5B4 E6040098 */   swc1  $f4, 0x98($s0)
.L8011B5B8:
/* 0B1CB8 8011B5B8 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0B1CBC 8011B5BC 8FB20038 */  lw    $s2, 0x38($sp)
/* 0B1CC0 8011B5C0 8FB10034 */  lw    $s1, 0x34($sp)
/* 0B1CC4 8011B5C4 8FB00030 */  lw    $s0, 0x30($sp)
/* 0B1CC8 8011B5C8 03E00008 */  jr    $ra
/* 0B1CCC 8011B5CC 27BD0040 */   addiu $sp, $sp, 0x40


.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011E310
/* 0B4A10 8011E310 3C028007 */  lui   $v0, 0x8007
/* 0B4A14 8011E314 8C42419C */  lw    $v0, 0x419c($v0)
/* 0B4A18 8011E318 80420070 */  lb    $v0, 0x70($v0)
/* 0B4A1C 8011E31C 14400005 */  bnez  $v0, .L8011E334
/* 0B4A20 8011E320 00000000 */   nop   
/* 0B4A24 8011E324 3C028015 */  lui   $v0, 0x8015
/* 0B4A28 8011E328 244239C0 */  addiu $v0, $v0, 0x39c0
/* 0B4A2C 8011E32C 080478CF */  j     .L8011E33C
/* 0B4A30 8011E330 00000000 */   nop   

.L8011E334:
/* 0B4A34 8011E334 3C028015 */  lui   $v0, 0x8015
/* 0B4A38 8011E338 24423A00 */  addiu $v0, $v0, 0x3a00
.L8011E33C:
/* 0B4A3C 8011E33C 3C018015 */  lui   $at, 0x8015
/* 0B4A40 8011E340 AC223A40 */  sw    $v0, 0x3a40($at)
/* 0B4A44 8011E344 2402000A */  addiu $v0, $zero, 0xa
/* 0B4A48 8011E348 3C018015 */  lui   $at, 0x8015
/* 0B4A4C 8011E34C AC223A48 */  sw    $v0, 0x3a48($at)
/* 0B4A50 8011E350 3C018015 */  lui   $at, 0x8015
/* 0B4A54 8011E354 AC223A4C */  sw    $v0, 0x3a4c($at)
/* 0B4A58 8011E358 3C018015 */  lui   $at, 0x8015
/* 0B4A5C 8011E35C AC223A50 */  sw    $v0, 0x3a50($at)
/* 0B4A60 8011E360 3C018015 */  lui   $at, 0x8015
/* 0B4A64 8011E364 AC223A54 */  sw    $v0, 0x3a54($at)
/* 0B4A68 8011E368 24020320 */  addiu $v0, $zero, 0x320
/* 0B4A6C 8011E36C 3C018015 */  lui   $at, 0x8015
/* 0B4A70 8011E370 AC223A58 */  sw    $v0, 0x3a58($at)
/* 0B4A74 8011E374 240203E8 */  addiu $v0, $zero, 0x3e8
/* 0B4A78 8011E378 3C018015 */  lui   $at, 0x8015
/* 0B4A7C 8011E37C AC2012D4 */  sw    $zero, 0x12d4($at)
/* 0B4A80 8011E380 3C018015 */  lui   $at, 0x8015
/* 0B4A84 8011E384 AC203A44 */  sw    $zero, 0x3a44($at)
/* 0B4A88 8011E388 3C018015 */  lui   $at, 0x8015
/* 0B4A8C 8011E38C AC223A5C */  sw    $v0, 0x3a5c($at)
/* 0B4A90 8011E390 03E00008 */  jr    $ra
/* 0B4A94 8011E394 00000000 */   nop   


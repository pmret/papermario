.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011E310
/* B4A10 8011E310 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B4A14 8011E314 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B4A18 8011E318 80420070 */  lb        $v0, 0x70($v0)
/* B4A1C 8011E31C 14400005 */  bnez      $v0, .L8011E334
/* B4A20 8011E320 00000000 */   nop      
/* B4A24 8011E324 3C028015 */  lui       $v0, %hi(D_801539C0)
/* B4A28 8011E328 244239C0 */  addiu     $v0, $v0, %lo(D_801539C0)
/* B4A2C 8011E32C 080478CF */  j         .L8011E33C
/* B4A30 8011E330 00000000 */   nop      
.L8011E334:
/* B4A34 8011E334 3C028015 */  lui       $v0, %hi(D_80153A00)
/* B4A38 8011E338 24423A00 */  addiu     $v0, $v0, %lo(D_80153A00)
.L8011E33C:
/* B4A3C 8011E33C 3C018015 */  lui       $at, %hi(gCurrentAnimMeshListPtr)
/* B4A40 8011E340 AC223A40 */  sw        $v0, %lo(gCurrentAnimMeshListPtr)($at)
/* B4A44 8011E344 2402000A */  addiu     $v0, $zero, 0xa
/* B4A48 8011E348 3C018015 */  lui       $at, %hi(D_80153A48)
/* B4A4C 8011E34C AC223A48 */  sw        $v0, %lo(D_80153A48)($at)
/* B4A50 8011E350 3C018015 */  lui       $at, %hi(D_80153A4C)
/* B4A54 8011E354 AC223A4C */  sw        $v0, %lo(D_80153A4C)($at)
/* B4A58 8011E358 3C018015 */  lui       $at, %hi(D_80153A50)
/* B4A5C 8011E35C AC223A50 */  sw        $v0, %lo(D_80153A50)($at)
/* B4A60 8011E360 3C018015 */  lui       $at, %hi(D_80153A54)
/* B4A64 8011E364 AC223A54 */  sw        $v0, %lo(D_80153A54)($at)
/* B4A68 8011E368 24020320 */  addiu     $v0, $zero, 0x320
/* B4A6C 8011E36C 3C018015 */  lui       $at, %hi(D_80153A58)
/* B4A70 8011E370 AC223A58 */  sw        $v0, %lo(D_80153A58)($at)
/* B4A74 8011E374 240203E8 */  addiu     $v0, $zero, 0x3e8
/* B4A78 8011E378 3C018015 */  lui       $at, %hi(D_801512D4)
/* B4A7C 8011E37C AC2012D4 */  sw        $zero, %lo(D_801512D4)($at)
/* B4A80 8011E380 3C018015 */  lui       $at, %hi(D_80153A44)
/* B4A84 8011E384 AC203A44 */  sw        $zero, %lo(D_80153A44)($at)
/* B4A88 8011E388 3C018015 */  lui       $at, %hi(D_80153A5C)
/* B4A8C 8011E38C AC223A5C */  sw        $v0, %lo(D_80153A5C)($at)
/* B4A90 8011E390 03E00008 */  jr        $ra
/* B4A94 8011E394 00000000 */   nop      

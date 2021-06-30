.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel WaitForState
/* 19CA78 8026E198 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19CA7C 8026E19C AFB00010 */  sw        $s0, 0x10($sp)
/* 19CA80 8026E1A0 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 19CA84 8026E1A4 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 19CA88 8026E1A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 19CA8C 8026E1AC 10A00008 */  beqz      $a1, .L8026E1D0
/* 19CA90 8026E1B0 8C82000C */   lw       $v0, 0xc($a0)
/* 19CA94 8026E1B4 0C0B1EAF */  jal       get_variable
/* 19CA98 8026E1B8 8C450000 */   lw       $a1, ($v0)
/* 19CA9C 8026E1BC 0040182D */  daddu     $v1, $v0, $zero
/* 19CAA0 8026E1C0 54600003 */  bnel      $v1, $zero, .L8026E1D0
/* 19CAA4 8026E1C4 A2030095 */   sb       $v1, 0x95($s0)
/* 19CAA8 8026E1C8 0809B87D */  j         .L8026E1F4
/* 19CAAC 8026E1CC A2000095 */   sb       $zero, 0x95($s0)
.L8026E1D0:
/* 19CAB0 8026E1D0 82030095 */  lb        $v1, 0x95($s0)
/* 19CAB4 8026E1D4 50600008 */  beql      $v1, $zero, .L8026E1F8
/* 19CAB8 8026E1D8 24020002 */   addiu    $v0, $zero, 2
/* 19CABC 8026E1DC 3C02800E */  lui       $v0, %hi(gBattleState)
/* 19CAC0 8026E1E0 8C42C068 */  lw        $v0, %lo(gBattleState)($v0)
/* 19CAC4 8026E1E4 00431026 */  xor       $v0, $v0, $v1
/* 19CAC8 8026E1E8 2C420001 */  sltiu     $v0, $v0, 1
/* 19CACC 8026E1EC 0809B87E */  j         .L8026E1F8
/* 19CAD0 8026E1F0 00021040 */   sll      $v0, $v0, 1
.L8026E1F4:
/* 19CAD4 8026E1F4 24020002 */  addiu     $v0, $zero, 2
.L8026E1F8:
/* 19CAD8 8026E1F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 19CADC 8026E1FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 19CAE0 8026E200 03E00008 */  jr        $ra
/* 19CAE4 8026E204 27BD0018 */   addiu    $sp, $sp, 0x18

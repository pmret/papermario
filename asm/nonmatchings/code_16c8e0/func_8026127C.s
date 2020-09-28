.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026127C
/* 18FB5C 8026127C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18FB60 80261280 3C04F7FF */  lui       $a0, 0xf7ff
/* 18FB64 80261284 3C02800E */  lui       $v0, 0x800e
/* 18FB68 80261288 8C42C4E4 */  lw        $v0, -0x3b1c($v0)
/* 18FB6C 8026128C 3C03800E */  lui       $v1, 0x800e
/* 18FB70 80261290 8C63C4D8 */  lw        $v1, -0x3b28($v1)
/* 18FB74 80261294 3484FFFF */  ori       $a0, $a0, 0xffff
/* 18FB78 80261298 AFB00010 */  sw        $s0, 0x10($sp)
/* 18FB7C 8026129C 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 18FB80 802612A0 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 18FB84 802612A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 18FB88 802612A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 18FB8C 802612AC A2000099 */  sb        $zero, 0x99($s0)
/* 18FB90 802612B0 3C01800E */  lui       $at, 0x800e
/* 18FB94 802612B4 AC22C068 */  sw        $v0, -0x3f98($at)
/* 18FB98 802612B8 8E020000 */  lw        $v0, ($s0)
/* 18FB9C 802612BC 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 18FBA0 802612C0 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 18FBA4 802612C4 3C01800E */  lui       $at, 0x800e
/* 18FBA8 802612C8 AC23C4DC */  sw        $v1, -0x3b24($at)
/* 18FBAC 802612CC 8E030004 */  lw        $v1, 4($s0)
/* 18FBB0 802612D0 34420008 */  ori       $v0, $v0, 8
/* 18FBB4 802612D4 00642024 */  and       $a0, $v1, $a0
/* 18FBB8 802612D8 30630040 */  andi      $v1, $v1, 0x40
/* 18FBBC 802612DC AE020000 */  sw        $v0, ($s0)
/* 18FBC0 802612E0 14600023 */  bnez      $v1, .L80261370
/* 18FBC4 802612E4 AE040004 */   sw       $a0, 4($s0)
/* 18FBC8 802612E8 82220002 */  lb        $v0, 2($s1)
/* 18FBCC 802612EC 28420002 */  slti      $v0, $v0, 2
/* 18FBD0 802612F0 1040000B */  beqz      $v0, .L80261320
/* 18FBD4 802612F4 00000000 */   nop      
/* 18FBD8 802612F8 0C03A752 */  jal       is_ability_active
/* 18FBDC 802612FC 24040014 */   addiu    $a0, $zero, 0x14
/* 18FBE0 80261300 10400007 */  beqz      $v0, .L80261320
/* 18FBE4 80261304 3C020800 */   lui      $v0, 0x800
/* 18FBE8 80261308 8E030004 */  lw        $v1, 4($s0)
/* 18FBEC 8026130C 92040099 */  lbu       $a0, 0x99($s0)
/* 18FBF0 80261310 00621825 */  or        $v1, $v1, $v0
/* 18FBF4 80261314 34840001 */  ori       $a0, $a0, 1
/* 18FBF8 80261318 AE030004 */  sw        $v1, 4($s0)
/* 18FBFC 8026131C A2040099 */  sb        $a0, 0x99($s0)
.L80261320:
/* 18FC00 80261320 82220002 */  lb        $v0, 2($s1)
/* 18FC04 80261324 28420006 */  slti      $v0, $v0, 6
/* 18FC08 80261328 10400011 */  beqz      $v0, .L80261370
/* 18FC0C 8026132C 00000000 */   nop      
/* 18FC10 80261330 0C03A752 */  jal       is_ability_active
/* 18FC14 80261334 2404001E */   addiu    $a0, $zero, 0x1e
/* 18FC18 80261338 1040000D */  beqz      $v0, .L80261370
/* 18FC1C 8026133C 00000000 */   nop      
/* 18FC20 80261340 92020099 */  lbu       $v0, 0x99($s0)
/* 18FC24 80261344 30420001 */  andi      $v0, $v0, 1
/* 18FC28 80261348 14400009 */  bnez      $v0, .L80261370
/* 18FC2C 8026134C 3C040800 */   lui      $a0, 0x800
/* 18FC30 80261350 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 18FC34 80261354 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 18FC38 80261358 8CA20004 */  lw        $v0, 4($a1)
/* 18FC3C 8026135C 92030099 */  lbu       $v1, 0x99($s0)
/* 18FC40 80261360 00441025 */  or        $v0, $v0, $a0
/* 18FC44 80261364 34630002 */  ori       $v1, $v1, 2
/* 18FC48 80261368 ACA20004 */  sw        $v0, 4($a1)
/* 18FC4C 8026136C A2030099 */  sb        $v1, 0x99($s0)
.L80261370:
/* 18FC50 80261370 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18FC54 80261374 8FB10014 */  lw        $s1, 0x14($sp)
/* 18FC58 80261378 8FB00010 */  lw        $s0, 0x10($sp)
/* 18FC5C 8026137C 24020002 */  addiu     $v0, $zero, 2
/* 18FC60 80261380 03E00008 */  jr        $ra
/* 18FC64 80261384 27BD0020 */   addiu    $sp, $sp, 0x20

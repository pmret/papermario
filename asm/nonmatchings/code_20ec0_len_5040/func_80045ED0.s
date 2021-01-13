.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045ED0
/* 212D0 80045ED0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 212D4 80045ED4 AFB20030 */  sw        $s2, 0x30($sp)
/* 212D8 80045ED8 0080902D */  daddu     $s2, $a0, $zero
/* 212DC 80045EDC AFBF0034 */  sw        $ra, 0x34($sp)
/* 212E0 80045EE0 AFB1002C */  sw        $s1, 0x2c($sp)
/* 212E4 80045EE4 AFB00028 */  sw        $s0, 0x28($sp)
/* 212E8 80045EE8 82420017 */  lb        $v0, 0x17($s2)
/* 212EC 80045EEC 10400027 */  beqz      $v0, .L80045F8C
/* 212F0 80045EF0 00000000 */   nop
/* 212F4 80045EF4 86420012 */  lh        $v0, 0x12($s2)
/* 212F8 80045EF8 A2400017 */  sb        $zero, 0x17($s2)
/* 212FC 80045EFC 00021080 */  sll       $v0, $v0, 2
/* 21300 80045F00 3C108008 */  lui       $s0, %hi(D_80078168)
/* 21304 80045F04 02028021 */  addu      $s0, $s0, $v0
/* 21308 80045F08 8E108168 */  lw        $s0, %lo(D_80078168)($s0)
/* 2130C 80045F0C 0000282D */  daddu     $a1, $zero, $zero
/* 21310 80045F10 0C04991D */  jal       get_string_width
/* 21314 80045F14 0200202D */   daddu    $a0, $s0, $zero
/* 21318 80045F18 0200202D */  daddu     $a0, $s0, $zero
/* 2131C 80045F1C 2451001E */  addiu     $s1, $v0, 0x1e
/* 21320 80045F20 001117C2 */  srl       $v0, $s1, 0x1f
/* 21324 80045F24 02221021 */  addu      $v0, $s1, $v0
/* 21328 80045F28 00021043 */  sra       $v0, $v0, 1
/* 2132C 80045F2C 241000A0 */  addiu     $s0, $zero, 0xa0
/* 21330 80045F30 0C04992C */  jal       func_801264B0
/* 21334 80045F34 02028023 */   subu     $s0, $s0, $v0
/* 21338 80045F38 24040009 */  addiu     $a0, $zero, 9
/* 2133C 80045F3C 2442FFFF */  addiu     $v0, $v0, -1
/* 21340 80045F40 00021040 */  sll       $v0, $v0, 1
/* 21344 80045F44 0200282D */  daddu     $a1, $s0, $zero
/* 21348 80045F48 3C038008 */  lui       $v1, %hi(D_80078160)
/* 2134C 80045F4C 00621821 */  addu      $v1, $v1, $v0
/* 21350 80045F50 84638160 */  lh        $v1, %lo(D_80078160)($v1)
/* 21354 80045F54 3C028004 */  lui       $v0, %hi(func_80045E4C)
/* 21358 80045F58 24425E4C */  addiu     $v0, $v0, %lo(func_80045E4C)
/* 2135C 80045F5C AFA20018 */  sw        $v0, 0x18($sp)
/* 21360 80045F60 2402FFFF */  addiu     $v0, $zero, -1
/* 21364 80045F64 24060050 */  addiu     $a2, $zero, 0x50
/* 21368 80045F68 0220382D */  daddu     $a3, $s1, $zero
/* 2136C 80045F6C AFA00014 */  sw        $zero, 0x14($sp)
/* 21370 80045F70 AFB2001C */  sw        $s2, 0x1c($sp)
/* 21374 80045F74 AFA20020 */  sw        $v0, 0x20($sp)
/* 21378 80045F78 0C051F32 */  jal       set_ui_panel_properties
/* 2137C 80045F7C AFA30010 */   sw       $v1, 0x10($sp)
/* 21380 80045F80 24040009 */  addiu     $a0, $zero, 9
/* 21384 80045F84 0C051F9F */  jal       func_80147E7C
/* 21388 80045F88 24050001 */   addiu    $a1, $zero, 1
.L80045F8C:
/* 2138C 80045F8C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 21390 80045F90 8FB20030 */  lw        $s2, 0x30($sp)
/* 21394 80045F94 8FB1002C */  lw        $s1, 0x2c($sp)
/* 21398 80045F98 8FB00028 */  lw        $s0, 0x28($sp)
/* 2139C 80045F9C 03E00008 */  jr        $ra
/* 213A0 80045FA0 27BD0038 */   addiu    $sp, $sp, 0x38

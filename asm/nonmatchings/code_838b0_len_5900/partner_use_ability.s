.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_use_ability
/* 847C4 800EB314 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 847C8 800EB318 AFBF0010 */  sw        $ra, 0x10($sp)
/* 847CC 800EB31C 0C011052 */  jal       func_80044148
/* 847D0 800EB320 00000000 */   nop
/* 847D4 800EB324 1440002B */  bnez      $v0, .L800EB3D4
/* 847D8 800EB328 0000102D */   daddu    $v0, $zero, $zero
/* 847DC 800EB32C 3C028011 */  lui       $v0, %hi(D_8010CFEC)
/* 847E0 800EB330 8C42CFEC */  lw        $v0, %lo(D_8010CFEC)($v0)
/* 847E4 800EB334 50400027 */  beql      $v0, $zero, .L800EB3D4
/* 847E8 800EB338 0000102D */   daddu    $v0, $zero, $zero
/* 847EC 800EB33C 8C42002C */  lw        $v0, 0x2c($v0)
/* 847F0 800EB340 10400007 */  beqz      $v0, .L800EB360
/* 847F4 800EB344 00000000 */   nop
/* 847F8 800EB348 3C048011 */  lui       $a0, %hi(D_8010C930)
/* 847FC 800EB34C 8C84C930 */  lw        $a0, %lo(D_8010C930)($a0)
/* 84800 800EB350 0040F809 */  jalr      $v0
/* 84804 800EB354 00000000 */   nop
/* 84808 800EB358 1040001E */  beqz      $v0, .L800EB3D4
/* 8480C 800EB35C 0000102D */   daddu    $v0, $zero, $zero
.L800EB360:
/* 84810 800EB360 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 84814 800EB364 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 84818 800EB368 80420081 */  lb        $v0, 0x81($v0)
/* 8481C 800EB36C 1040000B */  beqz      $v0, .L800EB39C
/* 84820 800EB370 00000000 */   nop
/* 84824 800EB374 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 84828 800EB378 2442EBB0 */  addiu     $v0, $v0, %lo(D_8010EBB0)
/* 8482C 800EB37C 8C420008 */  lw        $v0, 8($v0)
/* 84830 800EB380 30424000 */  andi      $v0, $v0, 0x4000
/* 84834 800EB384 10400005 */  beqz      $v0, .L800EB39C
/* 84838 800EB388 00000000 */   nop
/* 8483C 800EB38C 0C05272D */  jal       play_sound
/* 84840 800EB390 2404021D */   addiu    $a0, $zero, 0x21d
/* 84844 800EB394 0803ACF5 */  j         .L800EB3D4
/* 84848 800EB398 0000102D */   daddu    $v0, $zero, $zero
.L800EB39C:
/* 8484C 800EB39C 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 84850 800EB3A0 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 84854 800EB3A4 1040000A */  beqz      $v0, .L800EB3D0
/* 84858 800EB3A8 24020001 */   addiu    $v0, $zero, 1
/* 8485C 800EB3AC 3C018011 */  lui       $at, %hi(D_8010CFE0)
/* 84860 800EB3B0 AC22CFE0 */  sw        $v0, %lo(D_8010CFE0)($at)
/* 84864 800EB3B4 24020008 */  addiu     $v0, $zero, 8
/* 84868 800EB3B8 3C018011 */  lui       $at, %hi(D_8010CFE8)
/* 8486C 800EB3BC AC22CFE8 */  sw        $v0, %lo(D_8010CFE8)($at)
/* 84870 800EB3C0 0C03A9B3 */  jal       func_800EA6CC
/* 84874 800EB3C4 00000000 */   nop
/* 84878 800EB3C8 0803ACF5 */  j         .L800EB3D4
/* 8487C 800EB3CC 24020001 */   addiu    $v0, $zero, 1
.L800EB3D0:
/* 84880 800EB3D0 0000102D */  daddu     $v0, $zero, $zero
.L800EB3D4:
/* 84884 800EB3D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 84888 800EB3D8 03E00008 */  jr        $ra
/* 8488C 800EB3DC 27BD0018 */   addiu    $sp, $sp, 0x18

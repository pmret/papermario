.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070070
/* 4B470 80070070 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B474 80070074 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B478 80070078 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B47C 8007007C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B480 80070080 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B484 80070084 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B488 80070088 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B48C 8007008C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B490 80070090 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B494 80070094 0C016959 */  jal       play_effect
/* 4B498 80070098 24040015 */   addiu    $a0, $zero, 0x15
/* 4B49C 8007009C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B4A0 800700A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B4A4 800700A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B4A8 800700A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B4AC 800700AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B4B0 800700B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B4B4 800700B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B4B8 800700B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B4BC 800700BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B4C0 800700C0 3C018008 */  lui       $at, %hi(D_8007F408)
/* 4B4C4 800700C4 8C21F408 */  lw        $at, %lo(D_8007F408)($at)
/* 4B4C8 800700C8 00200008 */  jr        $at
/* 4B4CC 800700CC 00000000 */   nop

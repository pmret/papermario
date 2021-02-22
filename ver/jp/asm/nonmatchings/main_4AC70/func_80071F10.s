.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071F10
/* 4D310 80071F10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D314 80071F14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D318 80071F18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D31C 80071F1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D320 80071F20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D324 80071F24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D328 80071F28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D32C 80071F2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D330 80071F30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D334 80071F34 0C016885 */  jal       func_8005A214
/* 4D338 80071F38 24040067 */   addiu    $a0, $zero, 0x67
/* 4D33C 80071F3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D340 80071F40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D344 80071F44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D348 80071F48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D34C 80071F4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D350 80071F50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D354 80071F54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D358 80071F58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D35C 80071F5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D360 80071F60 3C018008 */  lui       $at, %hi(D_8007FB88)
/* 4D364 80071F64 8C21FB88 */  lw        $at, %lo(D_8007FB88)($at)
/* 4D368 80071F68 00200008 */  jr        $at
/* 4D36C 80071F6C 00000000 */   nop

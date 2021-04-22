.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071070
/* 4C470 80071070 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C474 80071074 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C478 80071078 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C47C 8007107C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C480 80071080 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C484 80071084 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C488 80071088 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C48C 8007108C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C490 80071090 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C494 80071094 0C016885 */  jal       func_8005A214
/* 4C498 80071098 24040040 */   addiu    $a0, $zero, 0x40
/* 4C49C 8007109C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C4A0 800710A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C4A4 800710A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C4A8 800710A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C4AC 800710AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C4B0 800710B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C4B4 800710B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C4B8 800710B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C4BC 800710BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C4C0 800710C0 3C018008 */  lui       $at, %hi(D_8007F7E0)
/* 4C4C4 800710C4 8C21F7E0 */  lw        $at, %lo(D_8007F7E0)($at)
/* 4C4C8 800710C8 00200008 */  jr        $at
/* 4C4CC 800710CC 00000000 */   nop

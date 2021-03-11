.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071090
/* 4C490 80071090 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C494 80071094 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C498 80071098 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C49C 8007109C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C4A0 800710A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C4A4 800710A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C4A8 800710A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C4AC 800710AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C4B0 800710B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C4B4 800710B4 0C016959 */  jal       load_effect
/* 4C4B8 800710B8 24040040 */   addiu    $a0, $zero, 0x40
/* 4C4BC 800710BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C4C0 800710C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C4C4 800710C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C4C8 800710C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C4CC 800710CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C4D0 800710D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C4D4 800710D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C4D8 800710D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C4DC 800710DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C4E0 800710E0 3C018008 */  lui       $at, %hi(D_8007F810)
/* 4C4E4 800710E4 8C21F810 */  lw        $at, %lo(D_8007F810)($at)
/* 4C4E8 800710E8 00200008 */  jr        $at
/* 4C4EC 800710EC 00000000 */   nop

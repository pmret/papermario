.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FF50
/* 4B350 8006FF50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B354 8006FF54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B358 8006FF58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B35C 8006FF5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B360 8006FF60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B364 8006FF64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B368 8006FF68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B36C 8006FF6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B370 8006FF70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B374 8006FF74 0C016959 */  jal       load_effect
/* 4B378 8006FF78 24040012 */   addiu    $a0, $zero, 0x12
/* 4B37C 8006FF7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B380 8006FF80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B384 8006FF84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B388 8006FF88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B38C 8006FF8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B390 8006FF90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B394 8006FF94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B398 8006FF98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B39C 8006FF9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B3A0 8006FFA0 3C018008 */  lui       $at, %hi(gEffectTable+0x1B0)
/* 4B3A4 8006FFA4 8C21F3C0 */  lw        $at, %lo(gEffectTable+0x1B0)($at)
/* 4B3A8 8006FFA8 00200008 */  jr        $at
/* 4B3AC 8006FFAC 00000000 */   nop

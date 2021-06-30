.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_30
/* 4BE90 80070A90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BE94 80070A94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BE98 80070A98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BE9C 80070A9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BEA0 80070AA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BEA4 80070AA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BEA8 80070AA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BEAC 80070AAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BEB0 80070AB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BEB4 80070AB4 0C016959 */  jal       load_effect
/* 4BEB8 80070AB8 24040030 */   addiu    $a0, $zero, 0x30
/* 4BEBC 80070ABC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BEC0 80070AC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BEC4 80070AC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BEC8 80070AC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BECC 80070ACC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BED0 80070AD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BED4 80070AD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BED8 80070AD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BEDC 80070ADC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BEE0 80070AE0 3C018008 */  lui       $at, %hi(gEffectTable+0x480)
/* 4BEE4 80070AE4 8C21F690 */  lw        $at, %lo(gEffectTable+0x480)($at)
/* 4BEE8 80070AE8 00200008 */  jr        $at
/* 4BEEC 80070AEC 00000000 */   nop

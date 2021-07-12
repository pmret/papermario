.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_55
/* 4CC70 80071870 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CC74 80071874 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CC78 80071878 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CC7C 8007187C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CC80 80071880 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CC84 80071884 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CC88 80071888 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CC8C 8007188C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CC90 80071890 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CC94 80071894 0C016959 */  jal       load_effect
/* 4CC98 80071898 24040055 */   addiu    $a0, $zero, 0x55
/* 4CC9C 8007189C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CCA0 800718A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CCA4 800718A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CCA8 800718A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CCAC 800718AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CCB0 800718B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CCB4 800718B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CCB8 800718B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CCBC 800718BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CCC0 800718C0 3C018008 */  lui       $at, %hi(gEffectTable+0x7F8)
/* 4CCC4 800718C4 8C21FA08 */  lw        $at, %lo(gEffectTable+0x7F8)($at)
/* 4CCC8 800718C8 00200008 */  jr        $at
/* 4CCCC 800718CC 00000000 */   nop

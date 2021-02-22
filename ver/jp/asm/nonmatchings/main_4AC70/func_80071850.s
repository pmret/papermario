.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071850
/* 4CC50 80071850 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CC54 80071854 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CC58 80071858 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CC5C 8007185C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CC60 80071860 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CC64 80071864 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CC68 80071868 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CC6C 8007186C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CC70 80071870 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CC74 80071874 0C016885 */  jal       func_8005A214
/* 4CC78 80071878 24040055 */   addiu    $a0, $zero, 0x55
/* 4CC7C 8007187C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CC80 80071880 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CC84 80071884 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CC88 80071888 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CC8C 8007188C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CC90 80071890 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CC94 80071894 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CC98 80071898 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CC9C 8007189C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CCA0 800718A0 3C018008 */  lui       $at, %hi(D_8007F9D8)
/* 4CCA4 800718A4 8C21F9D8 */  lw        $at, %lo(D_8007F9D8)($at)
/* 4CCA8 800718A8 00200008 */  jr        $at
/* 4CCAC 800718AC 00000000 */   nop

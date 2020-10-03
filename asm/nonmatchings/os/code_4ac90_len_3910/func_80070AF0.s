.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070AF0
/* 4BEF0 80070AF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BEF4 80070AF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BEF8 80070AF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BEFC 80070AFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BF00 80070B00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BF04 80070B04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BF08 80070B08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BF0C 80070B0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BF10 80070B10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BF14 80070B14 0C016959 */  jal       play_effect
/* 4BF18 80070B18 24040031 */   addiu    $a0, $zero, 0x31
/* 4BF1C 80070B1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BF20 80070B20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BF24 80070B24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BF28 80070B28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BF2C 80070B2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BF30 80070B30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BF34 80070B34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BF38 80070B38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BF3C 80070B3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BF40 80070B40 3C018008 */  lui       $at, 0x8008
/* 4BF44 80070B44 8C21F6A8 */  lw        $at, -0x958($at)
/* 4BF48 80070B48 00200008 */  jr        $at
/* 4BF4C 80070B4C 00000000 */   nop      

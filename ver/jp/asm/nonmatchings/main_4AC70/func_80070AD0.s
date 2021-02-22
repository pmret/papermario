.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070AD0
/* 4BED0 80070AD0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BED4 80070AD4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BED8 80070AD8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BEDC 80070ADC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BEE0 80070AE0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BEE4 80070AE4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BEE8 80070AE8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BEEC 80070AEC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BEF0 80070AF0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BEF4 80070AF4 0C016885 */  jal       func_8005A214
/* 4BEF8 80070AF8 24040031 */   addiu    $a0, $zero, 0x31
/* 4BEFC 80070AFC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BF00 80070B00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BF04 80070B04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BF08 80070B08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BF0C 80070B0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BF10 80070B10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BF14 80070B14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BF18 80070B18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BF1C 80070B1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BF20 80070B20 3C018008 */  lui       $at, %hi(D_8007F678)
/* 4BF24 80070B24 8C21F678 */  lw        $at, %lo(D_8007F678)($at)
/* 4BF28 80070B28 00200008 */  jr        $at
/* 4BF2C 80070B2C 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FED0
/* 4B2D0 8006FED0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B2D4 8006FED4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B2D8 8006FED8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B2DC 8006FEDC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B2E0 8006FEE0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B2E4 8006FEE4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B2E8 8006FEE8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B2EC 8006FEEC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B2F0 8006FEF0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B2F4 8006FEF4 0C016885 */  jal       func_8005A214
/* 4B2F8 8006FEF8 24040011 */   addiu    $a0, $zero, 0x11
/* 4B2FC 8006FEFC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B300 8006FF00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B304 8006FF04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B308 8006FF08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B30C 8006FF0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B310 8006FF10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B314 8006FF14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B318 8006FF18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B31C 8006FF1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B320 8006FF20 3C018008 */  lui       $at, %hi(D_8007F378)
/* 4B324 8006FF24 8C21F378 */  lw        $at, %lo(D_8007F378)($at)
/* 4B328 8006FF28 00200008 */  jr        $at
/* 4B32C 8006FF2C 00000000 */   nop

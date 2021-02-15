.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FE30
/* 4B230 8006FE30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B234 8006FE34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B238 8006FE38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B23C 8006FE3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B240 8006FE40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B244 8006FE44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B248 8006FE48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B24C 8006FE4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B250 8006FE50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B254 8006FE54 0C016959 */  jal       load_effect
/* 4B258 8006FE58 2404000F */   addiu    $a0, $zero, 0xf
/* 4B25C 8006FE5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B260 8006FE60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B264 8006FE64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B268 8006FE68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B26C 8006FE6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B270 8006FE70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B274 8006FE74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B278 8006FE78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B27C 8006FE7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B280 8006FE80 3C018008 */  lui       $at, %hi(D_8007F378)
/* 4B284 8006FE84 8C21F378 */  lw        $at, %lo(D_8007F378)($at)
/* 4B288 8006FE88 00200008 */  jr        $at
/* 4B28C 8006FE8C 00000000 */   nop

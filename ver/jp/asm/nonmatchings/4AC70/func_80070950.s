.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070950
/* 4BD50 80070950 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BD54 80070954 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BD58 80070958 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BD5C 8007095C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BD60 80070960 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BD64 80070964 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BD68 80070968 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BD6C 8007096C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BD70 80070970 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BD74 80070974 0C016885 */  jal       func_8005A214
/* 4BD78 80070978 2404002D */   addiu    $a0, $zero, 0x2d
/* 4BD7C 8007097C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BD80 80070980 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BD84 80070984 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BD88 80070988 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BD8C 8007098C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BD90 80070990 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BD94 80070994 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BD98 80070998 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BD9C 8007099C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BDA0 800709A0 3C018008 */  lui       $at, %hi(D_8007F618)
/* 4BDA4 800709A4 8C21F618 */  lw        $at, %lo(D_8007F618)($at)
/* 4BDA8 800709A8 00200008 */  jr        $at
/* 4BDAC 800709AC 00000000 */   nop

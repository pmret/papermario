.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_2D
/* 4BD70 80070970 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BD74 80070974 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BD78 80070978 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BD7C 8007097C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BD80 80070980 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BD84 80070984 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BD88 80070988 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BD8C 8007098C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BD90 80070990 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BD94 80070994 0C016959 */  jal       load_effect
/* 4BD98 80070998 2404002D */   addiu    $a0, $zero, 0x2d
/* 4BD9C 8007099C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BDA0 800709A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BDA4 800709A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BDA8 800709A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BDAC 800709AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BDB0 800709B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BDB4 800709B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BDB8 800709B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BDBC 800709BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BDC0 800709C0 3C018008 */  lui       $at, %hi(gEffectTable+0x438)
/* 4BDC4 800709C4 8C21F648 */  lw        $at, %lo(gEffectTable+0x438)($at)
/* 4BDC8 800709C8 00200008 */  jr        $at
/* 4BDCC 800709CC 00000000 */   nop

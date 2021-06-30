.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_4E
/* 4C9D0 800715D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C9D4 800715D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C9D8 800715D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C9DC 800715DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C9E0 800715E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C9E4 800715E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C9E8 800715E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C9EC 800715EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C9F0 800715F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C9F4 800715F4 0C016959 */  jal       load_effect
/* 4C9F8 800715F8 2404004E */   addiu    $a0, $zero, 0x4e
/* 4C9FC 800715FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CA00 80071600 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CA04 80071604 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CA08 80071608 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CA0C 8007160C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CA10 80071610 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CA14 80071614 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CA18 80071618 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CA1C 8007161C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CA20 80071620 3C018008 */  lui       $at, %hi(gEffectTable+0x750)
/* 4CA24 80071624 8C21F960 */  lw        $at, %lo(gEffectTable+0x750)($at)
/* 4CA28 80071628 00200008 */  jr        $at
/* 4CA2C 8007162C 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_4D
/* 4C970 80071570 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C974 80071574 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C978 80071578 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C97C 8007157C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C980 80071580 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C984 80071584 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C988 80071588 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C98C 8007158C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C990 80071590 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C994 80071594 0C016959 */  jal       load_effect
/* 4C998 80071598 2404004D */   addiu    $a0, $zero, 0x4d
/* 4C99C 8007159C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C9A0 800715A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C9A4 800715A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C9A8 800715A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C9AC 800715AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C9B0 800715B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C9B4 800715B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C9B8 800715B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C9BC 800715BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C9C0 800715C0 3C018008 */  lui       $at, %hi(gEffectTable+0x738)
/* 4C9C4 800715C4 8C21F948 */  lw        $at, %lo(gEffectTable+0x738)($at)
/* 4C9C8 800715C8 00200008 */  jr        $at
/* 4C9CC 800715CC 00000000 */   nop

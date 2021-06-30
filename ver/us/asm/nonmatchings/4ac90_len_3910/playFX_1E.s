.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_1E
/* 4B7D0 800703D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B7D4 800703D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B7D8 800703D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B7DC 800703DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B7E0 800703E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B7E4 800703E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B7E8 800703E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B7EC 800703EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B7F0 800703F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B7F4 800703F4 0C016959 */  jal       load_effect
/* 4B7F8 800703F8 2404001E */   addiu    $a0, $zero, 0x1e
/* 4B7FC 800703FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B800 80070400 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B804 80070404 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B808 80070408 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B80C 8007040C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B810 80070410 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B814 80070414 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B818 80070418 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B81C 8007041C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B820 80070420 3C018008 */  lui       $at, %hi(gEffectTable+0x2D0)
/* 4B824 80070424 8C21F4E0 */  lw        $at, %lo(gEffectTable+0x2D0)($at)
/* 4B828 80070428 00200008 */  jr        $at
/* 4B82C 8007042C 00000000 */   nop

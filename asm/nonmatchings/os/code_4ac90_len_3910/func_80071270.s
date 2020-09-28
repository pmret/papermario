.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071270
/* 4C670 80071270 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C674 80071274 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C678 80071278 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C67C 8007127C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C680 80071280 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C684 80071284 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C688 80071288 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C68C 8007128C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C690 80071290 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C694 80071294 0C016959 */  jal       play_effect
/* 4C698 80071298 24040045 */   addiu    $a0, $zero, 0x45
/* 4C69C 8007129C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C6A0 800712A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C6A4 800712A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C6A8 800712A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C6AC 800712AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C6B0 800712B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C6B4 800712B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C6B8 800712B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C6BC 800712BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C6C0 800712C0 3C018008 */  lui       $at, 0x8008
/* 4C6C4 800712C4 8C21F888 */  lw        $at, -0x778($at)
/* 4C6C8 800712C8 00200008 */  jr        $at
/* 4C6CC 800712CC 00000000 */   nop      

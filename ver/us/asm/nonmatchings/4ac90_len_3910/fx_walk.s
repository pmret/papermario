.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_walk
/* 4AF30 8006FB30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AF34 8006FB34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AF38 8006FB38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AF3C 8006FB3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AF40 8006FB40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AF44 8006FB44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AF48 8006FB48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AF4C 8006FB4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AF50 8006FB50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AF54 8006FB54 0C016959 */  jal       load_effect
/* 4AF58 8006FB58 24040007 */   addiu    $a0, $zero, 7
/* 4AF5C 8006FB5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AF60 8006FB60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AF64 8006FB64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AF68 8006FB68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AF6C 8006FB6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AF70 8006FB70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AF74 8006FB74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AF78 8006FB78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AF7C 8006FB7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AF80 8006FB80 3C018008 */  lui       $at, %hi(gEffectTable+0xA8)
/* 4AF84 8006FB84 8C21F2B8 */  lw        $at, %lo(gEffectTable+0xA8)($at)
/* 4AF88 8006FB88 00200008 */  jr        $at
/* 4AF8C 8006FB8C 00000000 */   nop

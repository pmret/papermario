.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FB70
/* 4AF70 8006FB70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AF74 8006FB74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AF78 8006FB78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AF7C 8006FB7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AF80 8006FB80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AF84 8006FB84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AF88 8006FB88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AF8C 8006FB8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AF90 8006FB90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AF94 8006FB94 0C016885 */  jal       func_8005A214
/* 4AF98 8006FB98 24040008 */   addiu    $a0, $zero, 8
/* 4AF9C 8006FB9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AFA0 8006FBA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AFA4 8006FBA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AFA8 8006FBA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AFAC 8006FBAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AFB0 8006FBB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AFB4 8006FBB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AFB8 8006FBB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AFBC 8006FBBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AFC0 8006FBC0 3C018008 */  lui       $at, %hi(D_8007F2A0)
/* 4AFC4 8006FBC4 8C21F2A0 */  lw        $at, %lo(D_8007F2A0)($at)
/* 4AFC8 8006FBC8 00200008 */  jr        $at
/* 4AFCC 8006FBCC 00000000 */   nop

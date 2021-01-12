.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FB90
/* 4AF90 8006FB90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AF94 8006FB94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AF98 8006FB98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AF9C 8006FB9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AFA0 8006FBA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AFA4 8006FBA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AFA8 8006FBA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AFAC 8006FBAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AFB0 8006FBB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AFB4 8006FBB4 0C016959 */  jal       play_effect
/* 4AFB8 8006FBB8 24040008 */   addiu    $a0, $zero, 8
/* 4AFBC 8006FBBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AFC0 8006FBC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AFC4 8006FBC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AFC8 8006FBC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AFCC 8006FBCC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AFD0 8006FBD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AFD4 8006FBD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AFD8 8006FBD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AFDC 8006FBDC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AFE0 8006FBE0 3C018008 */  lui       $at, %hi(D_8007F2D0)
/* 4AFE4 8006FBE4 8C21F2D0 */  lw        $at, %lo(D_8007F2D0)($at)
/* 4AFE8 8006FBE8 00200008 */  jr        $at
/* 4AFEC 8006FBEC 00000000 */   nop

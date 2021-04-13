.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FB10
/* 4AF10 8006FB10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AF14 8006FB14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AF18 8006FB18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AF1C 8006FB1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AF20 8006FB20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AF24 8006FB24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AF28 8006FB28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AF2C 8006FB2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AF30 8006FB30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AF34 8006FB34 0C016885 */  jal       func_8005A214
/* 4AF38 8006FB38 24040007 */   addiu    $a0, $zero, 7
/* 4AF3C 8006FB3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AF40 8006FB40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AF44 8006FB44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AF48 8006FB48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AF4C 8006FB4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AF50 8006FB50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AF54 8006FB54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AF58 8006FB58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AF5C 8006FB5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AF60 8006FB60 3C018008 */  lui       $at, %hi(D_8007F288)
/* 4AF64 8006FB64 8C21F288 */  lw        $at, %lo(D_8007F288)($at)
/* 4AF68 8006FB68 00200008 */  jr        $at
/* 4AF6C 8006FB6C 00000000 */   nop

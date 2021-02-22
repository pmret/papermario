.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071370
/* 4C770 80071370 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C774 80071374 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C778 80071378 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C77C 8007137C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C780 80071380 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C784 80071384 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C788 80071388 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C78C 8007138C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C790 80071390 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C794 80071394 0C016885 */  jal       func_8005A214
/* 4C798 80071398 24040048 */   addiu    $a0, $zero, 0x48
/* 4C79C 8007139C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C7A0 800713A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C7A4 800713A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C7A8 800713A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C7AC 800713AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C7B0 800713B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C7B4 800713B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C7B8 800713B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C7BC 800713BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C7C0 800713C0 3C018008 */  lui       $at, %hi(D_8007F8A0)
/* 4C7C4 800713C4 8C21F8A0 */  lw        $at, %lo(D_8007F8A0)($at)
/* 4C7C8 800713C8 00200008 */  jr        $at
/* 4C7CC 800713CC 00000000 */   nop

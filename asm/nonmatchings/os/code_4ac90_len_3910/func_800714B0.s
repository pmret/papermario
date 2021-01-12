.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800714B0
/* 4C8B0 800714B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C8B4 800714B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C8B8 800714B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C8BC 800714BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C8C0 800714C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C8C4 800714C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C8C8 800714C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C8CC 800714CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C8D0 800714D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C8D4 800714D4 0C016959 */  jal       play_effect
/* 4C8D8 800714D8 2404004B */   addiu    $a0, $zero, 0x4b
/* 4C8DC 800714DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C8E0 800714E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C8E4 800714E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C8E8 800714E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C8EC 800714EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C8F0 800714F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C8F4 800714F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C8F8 800714F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C8FC 800714FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C900 80071500 3C018008 */  lui       $at, %hi(D_8007F918)
/* 4C904 80071504 8C21F918 */  lw        $at, %lo(D_8007F918)($at)
/* 4C908 80071508 00200008 */  jr        $at
/* 4C90C 8007150C 00000000 */   nop

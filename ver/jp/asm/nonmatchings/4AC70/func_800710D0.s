.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800710D0
/* 4C4D0 800710D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C4D4 800710D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C4D8 800710D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C4DC 800710DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C4E0 800710E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C4E4 800710E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C4E8 800710E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C4EC 800710EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C4F0 800710F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C4F4 800710F4 0C016885 */  jal       func_8005A214
/* 4C4F8 800710F8 24040041 */   addiu    $a0, $zero, 0x41
/* 4C4FC 800710FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C500 80071100 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C504 80071104 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C508 80071108 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C50C 8007110C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C510 80071110 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C514 80071114 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C518 80071118 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C51C 8007111C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C520 80071120 3C018008 */  lui       $at, %hi(D_8007F7F8)
/* 4C524 80071124 8C21F7F8 */  lw        $at, %lo(D_8007F7F8)($at)
/* 4C528 80071128 00200008 */  jr        $at
/* 4C52C 8007112C 00000000 */   nop

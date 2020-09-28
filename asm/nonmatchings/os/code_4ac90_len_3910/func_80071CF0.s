.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071CF0
/* 4D0F0 80071CF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D0F4 80071CF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D0F8 80071CF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D0FC 80071CFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D100 80071D00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D104 80071D04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D108 80071D08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D10C 80071D0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D110 80071D10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D114 80071D14 0C016959 */  jal       play_effect
/* 4D118 80071D18 24040061 */   addiu    $a0, $zero, 0x61
/* 4D11C 80071D1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D120 80071D20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D124 80071D24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D128 80071D28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D12C 80071D2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D130 80071D30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D134 80071D34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D138 80071D38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D13C 80071D3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D140 80071D40 3C018008 */  lui       $at, 0x8008
/* 4D144 80071D44 8C21FB28 */  lw        $at, -0x4d8($at)
/* 4D148 80071D48 00200008 */  jr        $at
/* 4D14C 80071D4C 00000000 */   nop      

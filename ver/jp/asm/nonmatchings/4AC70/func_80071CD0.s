.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071CD0
/* 4D0D0 80071CD0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D0D4 80071CD4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D0D8 80071CD8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D0DC 80071CDC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D0E0 80071CE0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D0E4 80071CE4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D0E8 80071CE8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D0EC 80071CEC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D0F0 80071CF0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D0F4 80071CF4 0C016885 */  jal       func_8005A214
/* 4D0F8 80071CF8 24040061 */   addiu    $a0, $zero, 0x61
/* 4D0FC 80071CFC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D100 80071D00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D104 80071D04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D108 80071D08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D10C 80071D0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D110 80071D10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D114 80071D14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D118 80071D18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D11C 80071D1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D120 80071D20 3C018008 */  lui       $at, %hi(D_8007FAF8)
/* 4D124 80071D24 8C21FAF8 */  lw        $at, %lo(D_8007FAF8)($at)
/* 4D128 80071D28 00200008 */  jr        $at
/* 4D12C 80071D2C 00000000 */   nop

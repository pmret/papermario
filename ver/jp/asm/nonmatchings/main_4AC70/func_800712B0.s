.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800712B0
/* 4C6B0 800712B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C6B4 800712B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C6B8 800712B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C6BC 800712BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C6C0 800712C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C6C4 800712C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C6C8 800712C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C6CC 800712CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C6D0 800712D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C6D4 800712D4 0C016885 */  jal       func_8005A214
/* 4C6D8 800712D8 24040046 */   addiu    $a0, $zero, 0x46
/* 4C6DC 800712DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C6E0 800712E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C6E4 800712E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C6E8 800712E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C6EC 800712EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C6F0 800712F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C6F4 800712F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C6F8 800712F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C6FC 800712FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C700 80071300 3C018008 */  lui       $at, %hi(D_8007F870)
/* 4C704 80071304 8C21F870 */  lw        $at, %lo(D_8007F870)($at)
/* 4C708 80071308 00200008 */  jr        $at
/* 4C70C 8007130C 00000000 */   nop

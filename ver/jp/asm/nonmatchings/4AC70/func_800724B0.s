.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800724B0
/* 4D8B0 800724B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D8B4 800724B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D8B8 800724B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D8BC 800724BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D8C0 800724C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D8C4 800724C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D8C8 800724C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D8CC 800724CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D8D0 800724D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D8D4 800724D4 0C016885 */  jal       func_8005A214
/* 4D8D8 800724D8 24040076 */   addiu    $a0, $zero, 0x76
/* 4D8DC 800724DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D8E0 800724E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D8E4 800724E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D8E8 800724E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D8EC 800724EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D8F0 800724F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D8F4 800724F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D8F8 800724F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D8FC 800724FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D900 80072500 3C018008 */  lui       $at, %hi(D_8007FCF0)
/* 4D904 80072504 8C21FCF0 */  lw        $at, %lo(D_8007FCF0)($at)
/* 4D908 80072508 00200008 */  jr        $at
/* 4D90C 8007250C 00000000 */   nop

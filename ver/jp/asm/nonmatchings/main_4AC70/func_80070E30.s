.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070E30
/* 4C230 80070E30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C234 80070E34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C238 80070E38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C23C 80070E3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C240 80070E40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C244 80070E44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C248 80070E48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C24C 80070E4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C250 80070E50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C254 80070E54 0C016885 */  jal       func_8005A214
/* 4C258 80070E58 2404003A */   addiu    $a0, $zero, 0x3a
/* 4C25C 80070E5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C260 80070E60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C264 80070E64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C268 80070E68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C26C 80070E6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C270 80070E70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C274 80070E74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C278 80070E78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C27C 80070E7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C280 80070E80 3C018008 */  lui       $at, %hi(D_8007F750)
/* 4C284 80070E84 8C21F750 */  lw        $at, %lo(D_8007F750)($at)
/* 4C288 80070E88 00200008 */  jr        $at
/* 4C28C 80070E8C 00000000 */   nop

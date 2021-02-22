.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800715B0
/* 4C9B0 800715B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C9B4 800715B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C9B8 800715B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C9BC 800715BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C9C0 800715C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C9C4 800715C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C9C8 800715C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C9CC 800715CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C9D0 800715D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C9D4 800715D4 0C016885 */  jal       func_8005A214
/* 4C9D8 800715D8 2404004E */   addiu    $a0, $zero, 0x4e
/* 4C9DC 800715DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C9E0 800715E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C9E4 800715E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C9E8 800715E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C9EC 800715EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C9F0 800715F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C9F4 800715F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C9F8 800715F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C9FC 800715FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CA00 80071600 3C018008 */  lui       $at, %hi(D_8007F930)
/* 4CA04 80071604 8C21F930 */  lw        $at, %lo(D_8007F930)($at)
/* 4CA08 80071608 00200008 */  jr        $at
/* 4CA0C 8007160C 00000000 */   nop

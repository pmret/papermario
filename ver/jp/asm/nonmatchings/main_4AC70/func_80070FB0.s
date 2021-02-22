.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070FB0
/* 4C3B0 80070FB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C3B4 80070FB4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C3B8 80070FB8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C3BC 80070FBC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C3C0 80070FC0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C3C4 80070FC4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C3C8 80070FC8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C3CC 80070FCC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C3D0 80070FD0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C3D4 80070FD4 0C016885 */  jal       func_8005A214
/* 4C3D8 80070FD8 2404003E */   addiu    $a0, $zero, 0x3e
/* 4C3DC 80070FDC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C3E0 80070FE0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C3E4 80070FE4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C3E8 80070FE8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C3EC 80070FEC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C3F0 80070FF0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C3F4 80070FF4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C3F8 80070FF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C3FC 80070FFC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C400 80071000 3C018008 */  lui       $at, %hi(D_8007F7B0)
/* 4C404 80071004 8C21F7B0 */  lw        $at, %lo(D_8007F7B0)($at)
/* 4C408 80071008 00200008 */  jr        $at
/* 4C40C 8007100C 00000000 */   nop

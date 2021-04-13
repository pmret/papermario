.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070B30
/* 4BF30 80070B30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BF34 80070B34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BF38 80070B38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BF3C 80070B3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BF40 80070B40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BF44 80070B44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BF48 80070B48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BF4C 80070B4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BF50 80070B50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BF54 80070B54 0C016885 */  jal       func_8005A214
/* 4BF58 80070B58 24040032 */   addiu    $a0, $zero, 0x32
/* 4BF5C 80070B5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BF60 80070B60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BF64 80070B64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BF68 80070B68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BF6C 80070B6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BF70 80070B70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BF74 80070B74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BF78 80070B78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BF7C 80070B7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BF80 80070B80 3C018008 */  lui       $at, %hi(D_8007F690)
/* 4BF84 80070B84 8C21F690 */  lw        $at, %lo(D_8007F690)($at)
/* 4BF88 80070B88 00200008 */  jr        $at
/* 4BF8C 80070B8C 00000000 */   nop

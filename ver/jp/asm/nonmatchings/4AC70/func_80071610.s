.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071610
/* 4CA10 80071610 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CA14 80071614 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CA18 80071618 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CA1C 8007161C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CA20 80071620 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CA24 80071624 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CA28 80071628 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CA2C 8007162C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CA30 80071630 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CA34 80071634 0C016885 */  jal       func_8005A214
/* 4CA38 80071638 2404004F */   addiu    $a0, $zero, 0x4f
/* 4CA3C 8007163C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CA40 80071640 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CA44 80071644 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CA48 80071648 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CA4C 8007164C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CA50 80071650 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CA54 80071654 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CA58 80071658 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CA5C 8007165C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CA60 80071660 3C018008 */  lui       $at, %hi(D_8007F948)
/* 4CA64 80071664 8C21F948 */  lw        $at, %lo(D_8007F948)($at)
/* 4CA68 80071668 00200008 */  jr        $at
/* 4CA6C 8007166C 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070230
/* 4B630 80070230 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B634 80070234 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B638 80070238 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B63C 8007023C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B640 80070240 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B644 80070244 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B648 80070248 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B64C 8007024C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B650 80070250 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B654 80070254 0C016885 */  jal       func_8005A214
/* 4B658 80070258 2404001A */   addiu    $a0, $zero, 0x1a
/* 4B65C 8007025C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B660 80070260 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B664 80070264 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B668 80070268 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B66C 8007026C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B670 80070270 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B674 80070274 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B678 80070278 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B67C 8007027C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B680 80070280 3C018008 */  lui       $at, %hi(D_8007F450)
/* 4B684 80070284 8C21F450 */  lw        $at, %lo(D_8007F450)($at)
/* 4B688 80070288 00200008 */  jr        $at
/* 4B68C 8007028C 00000000 */   nop

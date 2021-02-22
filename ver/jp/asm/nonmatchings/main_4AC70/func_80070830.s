.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070830
/* 4BC30 80070830 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BC34 80070834 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BC38 80070838 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BC3C 8007083C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BC40 80070840 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BC44 80070844 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BC48 80070848 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BC4C 8007084C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BC50 80070850 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BC54 80070854 0C016885 */  jal       func_8005A214
/* 4BC58 80070858 2404002A */   addiu    $a0, $zero, 0x2a
/* 4BC5C 8007085C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BC60 80070860 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BC64 80070864 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BC68 80070868 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BC6C 8007086C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BC70 80070870 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BC74 80070874 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BC78 80070878 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BC7C 8007087C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BC80 80070880 3C018008 */  lui       $at, %hi(D_8007F5D0)
/* 4BC84 80070884 8C21F5D0 */  lw        $at, %lo(D_8007F5D0)($at)
/* 4BC88 80070888 00200008 */  jr        $at
/* 4BC8C 8007088C 00000000 */   nop

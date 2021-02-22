.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070A10
/* 4BE10 80070A10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BE14 80070A14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BE18 80070A18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BE1C 80070A1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BE20 80070A20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BE24 80070A24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BE28 80070A28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BE2C 80070A2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BE30 80070A30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BE34 80070A34 0C016885 */  jal       func_8005A214
/* 4BE38 80070A38 2404002F */   addiu    $a0, $zero, 0x2f
/* 4BE3C 80070A3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BE40 80070A40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BE44 80070A44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BE48 80070A48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BE4C 80070A4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BE50 80070A50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BE54 80070A54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BE58 80070A58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BE5C 80070A5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BE60 80070A60 3C018008 */  lui       $at, %hi(D_8007F648)
/* 4BE64 80070A64 8C21F648 */  lw        $at, %lo(D_8007F648)($at)
/* 4BE68 80070A68 00200008 */  jr        $at
/* 4BE6C 80070A6C 00000000 */   nop

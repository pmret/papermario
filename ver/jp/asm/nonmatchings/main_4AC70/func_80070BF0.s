.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070BF0
/* 4BFF0 80070BF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BFF4 80070BF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BFF8 80070BF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BFFC 80070BFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C000 80070C00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C004 80070C04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C008 80070C08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C00C 80070C0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C010 80070C10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C014 80070C14 0C016885 */  jal       func_8005A214
/* 4C018 80070C18 24040034 */   addiu    $a0, $zero, 0x34
/* 4C01C 80070C1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C020 80070C20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C024 80070C24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C028 80070C28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C02C 80070C2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C030 80070C30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C034 80070C34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C038 80070C38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C03C 80070C3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C040 80070C40 3C018008 */  lui       $at, %hi(D_8007F6C0)
/* 4C044 80070C44 8C21F6C0 */  lw        $at, %lo(D_8007F6C0)($at)
/* 4C048 80070C48 00200008 */  jr        $at
/* 4C04C 80070C4C 00000000 */   nop

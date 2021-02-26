.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800701D0
/* 4B5D0 800701D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B5D4 800701D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B5D8 800701D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B5DC 800701DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B5E0 800701E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B5E4 800701E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B5E8 800701E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B5EC 800701EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B5F0 800701F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B5F4 800701F4 0C016885 */  jal       func_8005A214
/* 4B5F8 800701F8 24040019 */   addiu    $a0, $zero, 0x19
/* 4B5FC 800701FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B600 80070200 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B604 80070204 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B608 80070208 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B60C 8007020C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B610 80070210 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B614 80070214 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B618 80070218 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B61C 8007021C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B620 80070220 3C018008 */  lui       $at, %hi(D_8007F438)
/* 4B624 80070224 8C21F438 */  lw        $at, %lo(D_8007F438)($at)
/* 4B628 80070228 00200008 */  jr        $at
/* 4B62C 8007022C 00000000 */   nop

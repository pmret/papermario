.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_19
/* 4B5F0 800701F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B5F4 800701F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B5F8 800701F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B5FC 800701FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B600 80070200 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B604 80070204 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B608 80070208 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B60C 8007020C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B610 80070210 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B614 80070214 0C016959 */  jal       load_effect
/* 4B618 80070218 24040019 */   addiu    $a0, $zero, 0x19
/* 4B61C 8007021C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B620 80070220 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B624 80070224 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B628 80070228 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B62C 8007022C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B630 80070230 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B634 80070234 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B638 80070238 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B63C 8007023C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B640 80070240 3C018008 */  lui       $at, %hi(gEffectTable+0x258)
/* 4B644 80070244 8C21F468 */  lw        $at, %lo(gEffectTable+0x258)($at)
/* 4B648 80070248 00200008 */  jr        $at
/* 4B64C 8007024C 00000000 */   nop

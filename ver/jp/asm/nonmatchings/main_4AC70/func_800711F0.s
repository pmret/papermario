.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800711F0
/* 4C5F0 800711F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C5F4 800711F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C5F8 800711F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C5FC 800711FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C600 80071200 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C604 80071204 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C608 80071208 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C60C 8007120C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C610 80071210 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C614 80071214 0C016885 */  jal       func_8005A214
/* 4C618 80071218 24040044 */   addiu    $a0, $zero, 0x44
/* 4C61C 8007121C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C620 80071220 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C624 80071224 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C628 80071228 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C62C 8007122C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C630 80071230 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C634 80071234 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C638 80071238 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C63C 8007123C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C640 80071240 3C018008 */  lui       $at, %hi(D_8007F840)
/* 4C644 80071244 8C21F840 */  lw        $at, %lo(D_8007F840)($at)
/* 4C648 80071248 00200008 */  jr        $at
/* 4C64C 8007124C 00000000 */   nop

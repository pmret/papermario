.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071210
/* 4C610 80071210 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C614 80071214 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C618 80071218 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C61C 8007121C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C620 80071220 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C624 80071224 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C628 80071228 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C62C 8007122C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C630 80071230 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C634 80071234 0C016959 */  jal       play_effect
/* 4C638 80071238 24040044 */   addiu    $a0, $zero, 0x44
/* 4C63C 8007123C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C640 80071240 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C644 80071244 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C648 80071248 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C64C 8007124C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C650 80071250 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C654 80071254 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C658 80071258 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C65C 8007125C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C660 80071260 3C018008 */  lui       $at, %hi(D_8007F870)
/* 4C664 80071264 8C21F870 */  lw        $at, %lo(D_8007F870)($at)
/* 4C668 80071268 00200008 */  jr        $at
/* 4C66C 8007126C 00000000 */   nop      

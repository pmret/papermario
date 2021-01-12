.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070BB0
/* 4BFB0 80070BB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BFB4 80070BB4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BFB8 80070BB8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BFBC 80070BBC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BFC0 80070BC0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BFC4 80070BC4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BFC8 80070BC8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BFCC 80070BCC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BFD0 80070BD0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BFD4 80070BD4 0C016959 */  jal       play_effect
/* 4BFD8 80070BD8 24040033 */   addiu    $a0, $zero, 0x33
/* 4BFDC 80070BDC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BFE0 80070BE0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BFE4 80070BE4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BFE8 80070BE8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BFEC 80070BEC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BFF0 80070BF0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BFF4 80070BF4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BFF8 80070BF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BFFC 80070BFC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C000 80070C00 3C018008 */  lui       $at, %hi(D_8007F6D8)
/* 4C004 80070C04 8C21F6D8 */  lw        $at, %lo(D_8007F6D8)($at)
/* 4C008 80070C08 00200008 */  jr        $at
/* 4C00C 80070C0C 00000000 */   nop

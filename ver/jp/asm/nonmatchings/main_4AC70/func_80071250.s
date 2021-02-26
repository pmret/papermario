.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071250
/* 4C650 80071250 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C654 80071254 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C658 80071258 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C65C 8007125C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C660 80071260 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C664 80071264 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C668 80071268 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C66C 8007126C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C670 80071270 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C674 80071274 0C016885 */  jal       func_8005A214
/* 4C678 80071278 24040045 */   addiu    $a0, $zero, 0x45
/* 4C67C 8007127C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C680 80071280 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C684 80071284 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C688 80071288 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C68C 8007128C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C690 80071290 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C694 80071294 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C698 80071298 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C69C 8007129C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C6A0 800712A0 3C018008 */  lui       $at, %hi(D_8007F858)
/* 4C6A4 800712A4 8C21F858 */  lw        $at, %lo(D_8007F858)($at)
/* 4C6A8 800712A8 00200008 */  jr        $at
/* 4C6AC 800712AC 00000000 */   nop

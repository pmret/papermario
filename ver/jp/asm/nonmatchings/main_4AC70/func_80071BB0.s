.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071BB0
/* 4CFB0 80071BB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CFB4 80071BB4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CFB8 80071BB8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CFBC 80071BBC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CFC0 80071BC0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CFC4 80071BC4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CFC8 80071BC8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CFCC 80071BCC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CFD0 80071BD0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CFD4 80071BD4 0C016885 */  jal       func_8005A214
/* 4CFD8 80071BD8 2404005E */   addiu    $a0, $zero, 0x5e
/* 4CFDC 80071BDC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CFE0 80071BE0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CFE4 80071BE4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CFE8 80071BE8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CFEC 80071BEC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CFF0 80071BF0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CFF4 80071BF4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CFF8 80071BF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CFFC 80071BFC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D000 80071C00 3C018008 */  lui       $at, %hi(D_8007FAB0)
/* 4D004 80071C04 8C21FAB0 */  lw        $at, %lo(D_8007FAB0)($at)
/* 4D008 80071C08 00200008 */  jr        $at
/* 4D00C 80071C0C 00000000 */   nop

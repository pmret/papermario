.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070710
/* 4BB10 80070710 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BB14 80070714 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BB18 80070718 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BB1C 8007071C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BB20 80070720 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BB24 80070724 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BB28 80070728 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BB2C 8007072C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BB30 80070730 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BB34 80070734 0C016885 */  jal       func_8005A214
/* 4BB38 80070738 24040027 */   addiu    $a0, $zero, 0x27
/* 4BB3C 8007073C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BB40 80070740 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BB44 80070744 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BB48 80070748 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BB4C 8007074C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BB50 80070750 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BB54 80070754 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BB58 80070758 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BB5C 8007075C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BB60 80070760 3C018008 */  lui       $at, %hi(D_8007F588)
/* 4BB64 80070764 8C21F588 */  lw        $at, %lo(D_8007F588)($at)
/* 4BB68 80070768 00200008 */  jr        $at
/* 4BB6C 8007076C 00000000 */   nop

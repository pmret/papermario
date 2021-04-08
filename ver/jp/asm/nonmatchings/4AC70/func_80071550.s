.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071550
/* 4C950 80071550 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C954 80071554 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C958 80071558 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C95C 8007155C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C960 80071560 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C964 80071564 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C968 80071568 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C96C 8007156C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C970 80071570 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C974 80071574 0C016885 */  jal       func_8005A214
/* 4C978 80071578 2404004D */   addiu    $a0, $zero, 0x4d
/* 4C97C 8007157C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C980 80071580 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C984 80071584 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C988 80071588 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C98C 8007158C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C990 80071590 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C994 80071594 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C998 80071598 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C99C 8007159C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C9A0 800715A0 3C018008 */  lui       $at, %hi(D_8007F918)
/* 4C9A4 800715A4 8C21F918 */  lw        $at, %lo(D_8007F918)($at)
/* 4C9A8 800715A8 00200008 */  jr        $at
/* 4C9AC 800715AC 00000000 */   nop

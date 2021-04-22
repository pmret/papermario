.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800716D0
/* 4CAD0 800716D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CAD4 800716D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CAD8 800716D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CADC 800716DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CAE0 800716E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CAE4 800716E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CAE8 800716E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CAEC 800716EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CAF0 800716F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CAF4 800716F4 0C016885 */  jal       func_8005A214
/* 4CAF8 800716F8 24040051 */   addiu    $a0, $zero, 0x51
/* 4CAFC 800716FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CB00 80071700 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CB04 80071704 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CB08 80071708 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CB0C 8007170C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CB10 80071710 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CB14 80071714 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CB18 80071718 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CB1C 8007171C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CB20 80071720 3C018008 */  lui       $at, %hi(D_8007F978)
/* 4CB24 80071724 8C21F978 */  lw        $at, %lo(D_8007F978)($at)
/* 4CB28 80071728 00200008 */  jr        $at
/* 4CB2C 8007172C 00000000 */   nop

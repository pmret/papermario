.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072750
/* 4DB50 80072750 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DB54 80072754 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DB58 80072758 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DB5C 8007275C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DB60 80072760 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DB64 80072764 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DB68 80072768 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DB6C 8007276C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DB70 80072770 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DB74 80072774 0C016885 */  jal       func_8005A214
/* 4DB78 80072778 2404007D */   addiu    $a0, $zero, 0x7d
/* 4DB7C 8007277C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DB80 80072780 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DB84 80072784 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DB88 80072788 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DB8C 8007278C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DB90 80072790 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DB94 80072794 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DB98 80072798 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DB9C 8007279C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DBA0 800727A0 3C018008 */  lui       $at, %hi(D_8007FD98)
/* 4DBA4 800727A4 8C21FD98 */  lw        $at, %lo(D_8007FD98)($at)
/* 4DBA8 800727A8 00200008 */  jr        $at
/* 4DBAC 800727AC 00000000 */   nop

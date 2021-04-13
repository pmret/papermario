.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072630
/* 4DA30 80072630 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DA34 80072634 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DA38 80072638 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DA3C 8007263C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DA40 80072640 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DA44 80072644 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DA48 80072648 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DA4C 8007264C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DA50 80072650 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DA54 80072654 0C016885 */  jal       func_8005A214
/* 4DA58 80072658 2404007A */   addiu    $a0, $zero, 0x7a
/* 4DA5C 8007265C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DA60 80072660 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DA64 80072664 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DA68 80072668 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DA6C 8007266C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DA70 80072670 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DA74 80072674 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DA78 80072678 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DA7C 8007267C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DA80 80072680 3C018008 */  lui       $at, %hi(D_8007FD50)
/* 4DA84 80072684 8C21FD50 */  lw        $at, %lo(D_8007FD50)($at)
/* 4DA88 80072688 00200008 */  jr        $at
/* 4DA8C 8007268C 00000000 */   nop

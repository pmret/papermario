.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070D90
/* 4C190 80070D90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C194 80070D94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C198 80070D98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C19C 80070D9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C1A0 80070DA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C1A4 80070DA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C1A8 80070DA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C1AC 80070DAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C1B0 80070DB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C1B4 80070DB4 0C016959 */  jal       play_effect
/* 4C1B8 80070DB8 24040038 */   addiu    $a0, $zero, 0x38
/* 4C1BC 80070DBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C1C0 80070DC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C1C4 80070DC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C1C8 80070DC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C1CC 80070DCC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C1D0 80070DD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C1D4 80070DD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C1D8 80070DD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C1DC 80070DDC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C1E0 80070DE0 3C018008 */  lui       $at, 0x8008
/* 4C1E4 80070DE4 8C21F750 */  lw        $at, -0x8b0($at)
/* 4C1E8 80070DE8 00200008 */  jr        $at
/* 4C1EC 80070DEC 00000000 */   nop      

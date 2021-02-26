.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070DD0
/* 4C1D0 80070DD0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C1D4 80070DD4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C1D8 80070DD8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C1DC 80070DDC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C1E0 80070DE0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C1E4 80070DE4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C1E8 80070DE8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C1EC 80070DEC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C1F0 80070DF0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C1F4 80070DF4 0C016885 */  jal       func_8005A214
/* 4C1F8 80070DF8 24040039 */   addiu    $a0, $zero, 0x39
/* 4C1FC 80070DFC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C200 80070E00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C204 80070E04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C208 80070E08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C20C 80070E0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C210 80070E10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C214 80070E14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C218 80070E18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C21C 80070E1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C220 80070E20 3C018008 */  lui       $at, %hi(D_8007F738)
/* 4C224 80070E24 8C21F738 */  lw        $at, %lo(D_8007F738)($at)
/* 4C228 80070E28 00200008 */  jr        $at
/* 4C22C 80070E2C 00000000 */   nop

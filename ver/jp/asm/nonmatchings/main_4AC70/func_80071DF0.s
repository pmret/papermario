.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071DF0
/* 4D1F0 80071DF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D1F4 80071DF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D1F8 80071DF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D1FC 80071DFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D200 80071E00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D204 80071E04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D208 80071E08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D20C 80071E0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D210 80071E10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D214 80071E14 0C016885 */  jal       func_8005A214
/* 4D218 80071E18 24040064 */   addiu    $a0, $zero, 0x64
/* 4D21C 80071E1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D220 80071E20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D224 80071E24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D228 80071E28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D22C 80071E2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D230 80071E30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D234 80071E34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D238 80071E38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D23C 80071E3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D240 80071E40 3C018008 */  lui       $at, %hi(D_8007FB40)
/* 4D244 80071E44 8C21FB40 */  lw        $at, %lo(D_8007FB40)($at)
/* 4D248 80071E48 00200008 */  jr        $at
/* 4D24C 80071E4C 00000000 */   nop

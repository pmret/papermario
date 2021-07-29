.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072030
/* 4D430 80072030 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D434 80072034 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D438 80072038 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D43C 8007203C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D440 80072040 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D444 80072044 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D448 80072048 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D44C 8007204C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D450 80072050 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D454 80072054 0C016885 */  jal       func_8005A214
/* 4D458 80072058 2404006A */   addiu    $a0, $zero, 0x6a
/* 4D45C 8007205C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D460 80072060 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D464 80072064 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D468 80072068 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D46C 8007206C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D470 80072070 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D474 80072074 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D478 80072078 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D47C 8007207C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D480 80072080 3C018008 */  lui       $at, %hi(D_8007FBD0)
/* 4D484 80072084 8C21FBD0 */  lw        $at, %lo(D_8007FBD0)($at)
/* 4D488 80072088 00200008 */  jr        $at
/* 4D48C 8007208C 00000000 */   nop

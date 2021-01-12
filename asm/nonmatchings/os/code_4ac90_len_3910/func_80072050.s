.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072050
/* 4D450 80072050 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D454 80072054 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D458 80072058 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D45C 8007205C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D460 80072060 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D464 80072064 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D468 80072068 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D46C 8007206C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D470 80072070 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D474 80072074 0C016959 */  jal       play_effect
/* 4D478 80072078 2404006A */   addiu    $a0, $zero, 0x6a
/* 4D47C 8007207C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D480 80072080 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D484 80072084 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D488 80072088 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D48C 8007208C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D490 80072090 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D494 80072094 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D498 80072098 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D49C 8007209C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D4A0 800720A0 3C018008 */  lui       $at, %hi(D_8007FC00)
/* 4D4A4 800720A4 8C21FC00 */  lw        $at, %lo(D_8007FC00)($at)
/* 4D4A8 800720A8 00200008 */  jr        $at
/* 4D4AC 800720AC 00000000 */   nop

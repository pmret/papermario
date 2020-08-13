.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80071FF0
/* 04D3F0 80071FF0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D3F4 80071FF4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D3F8 80071FF8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D3FC 80071FFC AFA60018 */  sw    $a2, 0x18($sp)
/* 04D400 80072000 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D404 80072004 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D408 80072008 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D40C 8007200C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D410 80072010 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D414 80072014 0C016959 */  jal   play_effect
/* 04D418 80072018 24040069 */   addiu $a0, $zero, 0x69
/* 04D41C 8007201C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D420 80072020 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D424 80072024 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D428 80072028 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D42C 8007202C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D430 80072030 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D434 80072034 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D438 80072038 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D43C 8007203C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D440 80072040 3C018008 */  lui   $at, 0x8008
/* 04D444 80072044 8C21FBE8 */  lw    $at, -0x418($at)
/* 04D448 80072048 00200008 */  jr    $at
/* 04D44C 8007204C 00000000 */   nop   
/* 04D450 80072050 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D454 80072054 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D458 80072058 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D45C 8007205C AFA60018 */  sw    $a2, 0x18($sp)
/* 04D460 80072060 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D464 80072064 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D468 80072068 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D46C 8007206C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D470 80072070 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D474 80072074 0C016959 */  jal   play_effect
/* 04D478 80072078 2404006A */   addiu $a0, $zero, 0x6a
/* 04D47C 8007207C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D480 80072080 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D484 80072084 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D488 80072088 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D48C 8007208C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D490 80072090 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D494 80072094 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D498 80072098 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D49C 8007209C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D4A0 800720A0 3C018008 */  lui   $at, 0x8008
/* 04D4A4 800720A4 8C21FC00 */  lw    $at, -0x400($at)
/* 04D4A8 800720A8 00200008 */  jr    $at
/* 04D4AC 800720AC 00000000 */   nop   

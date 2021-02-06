.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071FF0
/* 4D3F0 80071FF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D3F4 80071FF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D3F8 80071FF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D3FC 80071FFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D400 80072000 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D404 80072004 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D408 80072008 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D40C 8007200C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D410 80072010 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D414 80072014 0C016959 */  jal       load_effect
/* 4D418 80072018 24040069 */   addiu    $a0, $zero, 0x69
/* 4D41C 8007201C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D420 80072020 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D424 80072024 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D428 80072028 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D42C 8007202C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D430 80072030 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D434 80072034 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D438 80072038 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D43C 8007203C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D440 80072040 3C018008 */  lui       $at, %hi(D_8007FBE8)
/* 4D444 80072044 8C21FBE8 */  lw        $at, %lo(D_8007FBE8)($at)
/* 4D448 80072048 00200008 */  jr        $at
/* 4D44C 8007204C 00000000 */   nop

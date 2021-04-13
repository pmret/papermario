.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072450
/* 4D850 80072450 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D854 80072454 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D858 80072458 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D85C 8007245C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D860 80072460 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D864 80072464 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D868 80072468 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D86C 8007246C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D870 80072470 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D874 80072474 0C016885 */  jal       func_8005A214
/* 4D878 80072478 24040075 */   addiu    $a0, $zero, 0x75
/* 4D87C 8007247C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D880 80072480 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D884 80072484 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D888 80072488 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D88C 8007248C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D890 80072490 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D894 80072494 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D898 80072498 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D89C 8007249C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D8A0 800724A0 3C018008 */  lui       $at, %hi(D_8007FCD8)
/* 4D8A4 800724A4 8C21FCD8 */  lw        $at, %lo(D_8007FCD8)($at)
/* 4D8A8 800724A8 00200008 */  jr        $at
/* 4D8AC 800724AC 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072470
/* 4D870 80072470 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D874 80072474 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D878 80072478 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D87C 8007247C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D880 80072480 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D884 80072484 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D888 80072488 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D88C 8007248C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D890 80072490 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D894 80072494 0C016959 */  jal       load_effect
/* 4D898 80072498 24040075 */   addiu    $a0, $zero, 0x75
/* 4D89C 8007249C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D8A0 800724A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D8A4 800724A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D8A8 800724A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D8AC 800724AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D8B0 800724B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D8B4 800724B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D8B8 800724B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D8BC 800724BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D8C0 800724C0 3C018008 */  lui       $at, %hi(D_8007FD08)
/* 4D8C4 800724C4 8C21FD08 */  lw        $at, %lo(D_8007FD08)($at)
/* 4D8C8 800724C8 00200008 */  jr        $at
/* 4D8CC 800724CC 00000000 */   nop

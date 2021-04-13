.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072A50
/* 4DE50 80072A50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DE54 80072A54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DE58 80072A58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DE5C 80072A5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DE60 80072A60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DE64 80072A64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DE68 80072A68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DE6C 80072A6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DE70 80072A70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DE74 80072A74 0C016885 */  jal       func_8005A214
/* 4DE78 80072A78 24040085 */   addiu    $a0, $zero, 0x85
/* 4DE7C 80072A7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DE80 80072A80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DE84 80072A84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DE88 80072A88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DE8C 80072A8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DE90 80072A90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DE94 80072A94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DE98 80072A98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DE9C 80072A9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DEA0 80072AA0 3C018008 */  lui       $at, %hi(D_8007FE58)
/* 4DEA4 80072AA4 8C21FE58 */  lw        $at, %lo(D_8007FE58)($at)
/* 4DEA8 80072AA8 00200008 */  jr        $at
/* 4DEAC 80072AAC 00000000 */   nop

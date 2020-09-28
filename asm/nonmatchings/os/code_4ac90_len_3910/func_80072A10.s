.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072A10
/* 4DE10 80072A10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DE14 80072A14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DE18 80072A18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DE1C 80072A1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DE20 80072A20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DE24 80072A24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DE28 80072A28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DE2C 80072A2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DE30 80072A30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DE34 80072A34 0C016959 */  jal       play_effect
/* 4DE38 80072A38 24040084 */   addiu    $a0, $zero, 0x84
/* 4DE3C 80072A3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DE40 80072A40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DE44 80072A44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DE48 80072A48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DE4C 80072A4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DE50 80072A50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DE54 80072A54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DE58 80072A58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DE5C 80072A5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DE60 80072A60 3C018008 */  lui       $at, 0x8008
/* 4DE64 80072A64 8C21FE70 */  lw        $at, -0x190($at)
/* 4DE68 80072A68 00200008 */  jr        $at
/* 4DE6C 80072A6C 00000000 */   nop      

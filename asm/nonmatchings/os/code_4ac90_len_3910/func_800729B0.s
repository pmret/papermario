.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800729B0
/* 4DDB0 800729B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DDB4 800729B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DDB8 800729B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DDBC 800729BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DDC0 800729C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DDC4 800729C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DDC8 800729C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DDCC 800729CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DDD0 800729D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DDD4 800729D4 0C016959 */  jal       load_effect
/* 4DDD8 800729D8 24040083 */   addiu    $a0, $zero, 0x83
/* 4DDDC 800729DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DDE0 800729E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DDE4 800729E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DDE8 800729E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DDEC 800729EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DDF0 800729F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DDF4 800729F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DDF8 800729F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DDFC 800729FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DE00 80072A00 3C018008 */  lui       $at, %hi(D_8007FE58)
/* 4DE04 80072A04 8C21FE58 */  lw        $at, %lo(D_8007FE58)($at)
/* 4DE08 80072A08 00200008 */  jr        $at
/* 4DE0C 80072A0C 00000000 */   nop

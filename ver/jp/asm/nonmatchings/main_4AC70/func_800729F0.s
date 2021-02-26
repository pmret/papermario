.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800729F0
/* 4DDF0 800729F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DDF4 800729F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DDF8 800729F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DDFC 800729FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DE00 80072A00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DE04 80072A04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DE08 80072A08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DE0C 80072A0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DE10 80072A10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DE14 80072A14 0C016885 */  jal       func_8005A214
/* 4DE18 80072A18 24040084 */   addiu    $a0, $zero, 0x84
/* 4DE1C 80072A1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DE20 80072A20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DE24 80072A24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DE28 80072A28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DE2C 80072A2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DE30 80072A30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DE34 80072A34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DE38 80072A38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DE3C 80072A3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DE40 80072A40 3C018008 */  lui       $at, %hi(D_8007FE40)
/* 4DE44 80072A44 8C21FE40 */  lw        $at, %lo(D_8007FE40)($at)
/* 4DE48 80072A48 00200008 */  jr        $at
/* 4DE4C 80072A4C 00000000 */   nop

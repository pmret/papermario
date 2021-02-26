.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071130
/* 4C530 80071130 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C534 80071134 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C538 80071138 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C53C 8007113C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C540 80071140 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C544 80071144 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C548 80071148 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C54C 8007114C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C550 80071150 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C554 80071154 0C016885 */  jal       func_8005A214
/* 4C558 80071158 24040042 */   addiu    $a0, $zero, 0x42
/* 4C55C 8007115C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C560 80071160 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C564 80071164 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C568 80071168 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C56C 8007116C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C570 80071170 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C574 80071174 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C578 80071178 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C57C 8007117C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C580 80071180 3C018008 */  lui       $at, %hi(D_8007F810)
/* 4C584 80071184 8C21F810 */  lw        $at, %lo(D_8007F810)($at)
/* 4C588 80071188 00200008 */  jr        $at
/* 4C58C 8007118C 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072690
/* 4DA90 80072690 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DA94 80072694 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DA98 80072698 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DA9C 8007269C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DAA0 800726A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DAA4 800726A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DAA8 800726A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DAAC 800726AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DAB0 800726B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DAB4 800726B4 0C016885 */  jal       func_8005A214
/* 4DAB8 800726B8 2404007B */   addiu    $a0, $zero, 0x7b
/* 4DABC 800726BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DAC0 800726C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DAC4 800726C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DAC8 800726C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DACC 800726CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DAD0 800726D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DAD4 800726D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DAD8 800726D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DADC 800726DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DAE0 800726E0 3C018008 */  lui       $at, %hi(D_8007FD68)
/* 4DAE4 800726E4 8C21FD68 */  lw        $at, %lo(D_8007FD68)($at)
/* 4DAE8 800726E8 00200008 */  jr        $at
/* 4DAEC 800726EC 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800726B0
/* 4DAB0 800726B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DAB4 800726B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DAB8 800726B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DABC 800726BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DAC0 800726C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DAC4 800726C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DAC8 800726C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DACC 800726CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DAD0 800726D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DAD4 800726D4 0C016959 */  jal       load_effect
/* 4DAD8 800726D8 2404007B */   addiu    $a0, $zero, 0x7b
/* 4DADC 800726DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DAE0 800726E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DAE4 800726E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DAE8 800726E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DAEC 800726EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DAF0 800726F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DAF4 800726F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DAF8 800726F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DAFC 800726FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DB00 80072700 3C018008 */  lui       $at, %hi(gEffectTable+0xB88)
/* 4DB04 80072704 8C21FD98 */  lw        $at, %lo(gEffectTable+0xB88)($at)
/* 4DB08 80072708 00200008 */  jr        $at
/* 4DB0C 8007270C 00000000 */   nop

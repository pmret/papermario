.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072650
/* 4DA50 80072650 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DA54 80072654 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DA58 80072658 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DA5C 8007265C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DA60 80072660 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DA64 80072664 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DA68 80072668 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DA6C 8007266C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DA70 80072670 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DA74 80072674 0C016959 */  jal       load_effect
/* 4DA78 80072678 2404007A */   addiu    $a0, $zero, 0x7a
/* 4DA7C 8007267C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DA80 80072680 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DA84 80072684 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DA88 80072688 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DA8C 8007268C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DA90 80072690 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DA94 80072694 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DA98 80072698 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DA9C 8007269C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DAA0 800726A0 3C018008 */  lui       $at, %hi(gEffectTable+0xB70)
/* 4DAA4 800726A4 8C21FD80 */  lw        $at, %lo(gEffectTable+0xB70)($at)
/* 4DAA8 800726A8 00200008 */  jr        $at
/* 4DAAC 800726AC 00000000 */   nop

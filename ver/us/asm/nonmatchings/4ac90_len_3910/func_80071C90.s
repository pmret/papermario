.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071C90
/* 4D090 80071C90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D094 80071C94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D098 80071C98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D09C 80071C9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D0A0 80071CA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D0A4 80071CA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D0A8 80071CA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D0AC 80071CAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D0B0 80071CB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D0B4 80071CB4 0C016959 */  jal       load_effect
/* 4D0B8 80071CB8 24040060 */   addiu    $a0, $zero, 0x60
/* 4D0BC 80071CBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D0C0 80071CC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D0C4 80071CC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D0C8 80071CC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D0CC 80071CCC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D0D0 80071CD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D0D4 80071CD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D0D8 80071CD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D0DC 80071CDC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D0E0 80071CE0 3C018008 */  lui       $at, %hi(gEffectTable+0x900)
/* 4D0E4 80071CE4 8C21FB10 */  lw        $at, %lo(gEffectTable+0x900)($at)
/* 4D0E8 80071CE8 00200008 */  jr        $at
/* 4D0EC 80071CEC 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800717B0
/* 4CBB0 800717B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CBB4 800717B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CBB8 800717B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CBBC 800717BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CBC0 800717C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CBC4 800717C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CBC8 800717C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CBCC 800717CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CBD0 800717D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CBD4 800717D4 0C016959 */  jal       load_effect
/* 4CBD8 800717D8 24040053 */   addiu    $a0, $zero, 0x53
/* 4CBDC 800717DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CBE0 800717E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CBE4 800717E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CBE8 800717E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CBEC 800717EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CBF0 800717F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CBF4 800717F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CBF8 800717F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CBFC 800717FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CC00 80071800 3C018008 */  lui       $at, %hi(gEffectTable+0x7C8)
/* 4CC04 80071804 8C21F9D8 */  lw        $at, %lo(gEffectTable+0x7C8)($at)
/* 4CC08 80071808 00200008 */  jr        $at
/* 4CC0C 8007180C 00000000 */   nop

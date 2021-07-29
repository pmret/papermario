.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070770
/* 4BB70 80070770 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BB74 80070774 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BB78 80070778 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BB7C 8007077C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BB80 80070780 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BB84 80070784 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BB88 80070788 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BB8C 8007078C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BB90 80070790 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BB94 80070794 0C016885 */  jal       func_8005A214
/* 4BB98 80070798 24040028 */   addiu    $a0, $zero, 0x28
/* 4BB9C 8007079C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BBA0 800707A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BBA4 800707A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BBA8 800707A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BBAC 800707AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BBB0 800707B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BBB4 800707B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BBB8 800707B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BBBC 800707BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BBC0 800707C0 3C018008 */  lui       $at, %hi(D_8007F5A0)
/* 4BBC4 800707C4 8C21F5A0 */  lw        $at, %lo(D_8007F5A0)($at)
/* 4BBC8 800707C8 00200008 */  jr        $at
/* 4BBCC 800707CC 00000000 */   nop

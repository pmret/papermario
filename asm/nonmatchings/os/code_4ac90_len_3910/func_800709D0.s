.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800709D0
/* 4BDD0 800709D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BDD4 800709D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BDD8 800709D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BDDC 800709DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BDE0 800709E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BDE4 800709E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BDE8 800709E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BDEC 800709EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BDF0 800709F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BDF4 800709F4 0C016959 */  jal       play_effect
/* 4BDF8 800709F8 2404002E */   addiu    $a0, $zero, 0x2e
/* 4BDFC 800709FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BE00 80070A00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BE04 80070A04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BE08 80070A08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BE0C 80070A0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BE10 80070A10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BE14 80070A14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BE18 80070A18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BE1C 80070A1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BE20 80070A20 3C018008 */  lui       $at, %hi(D_8007F660)
/* 4BE24 80070A24 8C21F660 */  lw        $at, %lo(D_8007F660)($at)
/* 4BE28 80070A28 00200008 */  jr        $at
/* 4BE2C 80070A2C 00000000 */   nop

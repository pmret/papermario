.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800709B0
/* 4BDB0 800709B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BDB4 800709B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BDB8 800709B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BDBC 800709BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BDC0 800709C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BDC4 800709C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BDC8 800709C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BDCC 800709CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BDD0 800709D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BDD4 800709D4 0C016885 */  jal       func_8005A214
/* 4BDD8 800709D8 2404002E */   addiu    $a0, $zero, 0x2e
/* 4BDDC 800709DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BDE0 800709E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BDE4 800709E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BDE8 800709E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BDEC 800709EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BDF0 800709F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BDF4 800709F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BDF8 800709F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BDFC 800709FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BE00 80070A00 3C018008 */  lui       $at, %hi(D_8007F630)
/* 4BE04 80070A04 8C21F630 */  lw        $at, %lo(D_8007F630)($at)
/* 4BE08 80070A08 00200008 */  jr        $at
/* 4BE0C 80070A0C 00000000 */   nop

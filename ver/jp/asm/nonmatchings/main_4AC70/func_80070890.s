.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070890
/* 4BC90 80070890 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BC94 80070894 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BC98 80070898 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BC9C 8007089C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BCA0 800708A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BCA4 800708A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BCA8 800708A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BCAC 800708AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BCB0 800708B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BCB4 800708B4 0C016885 */  jal       func_8005A214
/* 4BCB8 800708B8 2404002B */   addiu    $a0, $zero, 0x2b
/* 4BCBC 800708BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BCC0 800708C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BCC4 800708C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BCC8 800708C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BCCC 800708CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BCD0 800708D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BCD4 800708D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BCD8 800708D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BCDC 800708DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BCE0 800708E0 3C018008 */  lui       $at, %hi(D_8007F5E8)
/* 4BCE4 800708E4 8C21F5E8 */  lw        $at, %lo(D_8007F5E8)($at)
/* 4BCE8 800708E8 00200008 */  jr        $at
/* 4BCEC 800708EC 00000000 */   nop

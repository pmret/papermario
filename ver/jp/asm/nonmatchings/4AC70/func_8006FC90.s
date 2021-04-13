.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FC90
/* 4B090 8006FC90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B094 8006FC94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B098 8006FC98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B09C 8006FC9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B0A0 8006FCA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B0A4 8006FCA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B0A8 8006FCA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B0AC 8006FCAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B0B0 8006FCB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B0B4 8006FCB4 0C016885 */  jal       func_8005A214
/* 4B0B8 8006FCB8 2404000B */   addiu    $a0, $zero, 0xb
/* 4B0BC 8006FCBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B0C0 8006FCC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B0C4 8006FCC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B0C8 8006FCC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B0CC 8006FCCC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B0D0 8006FCD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B0D4 8006FCD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B0D8 8006FCD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B0DC 8006FCDC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B0E0 8006FCE0 3C018008 */  lui       $at, %hi(D_8007F2E8)
/* 4B0E4 8006FCE4 8C21F2E8 */  lw        $at, %lo(D_8007F2E8)($at)
/* 4B0E8 8006FCE8 00200008 */  jr        $at
/* 4B0EC 8006FCEC 00000000 */   nop

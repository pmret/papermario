.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_2B
/* 4BCB0 800708B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BCB4 800708B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BCB8 800708B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BCBC 800708BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4BCC0 800708C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BCC4 800708C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BCC8 800708C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BCCC 800708CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BCD0 800708D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BCD4 800708D4 0C016959 */  jal       load_effect
/* 4BCD8 800708D8 2404002B */   addiu    $a0, $zero, 0x2b
/* 4BCDC 800708DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BCE0 800708E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BCE4 800708E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BCE8 800708E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BCEC 800708EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BCF0 800708F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BCF4 800708F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BCF8 800708F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BCFC 800708FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BD00 80070900 3C018008 */  lui       $at, %hi(gEffectTable+0x408)
/* 4BD04 80070904 8C21F618 */  lw        $at, %lo(gEffectTable+0x408)($at)
/* 4BD08 80070908 00200008 */  jr        $at
/* 4BD0C 8007090C 00000000 */   nop

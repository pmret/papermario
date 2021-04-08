.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800723B0
/* 4D7B0 800723B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D7B4 800723B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D7B8 800723B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D7BC 800723BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D7C0 800723C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D7C4 800723C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D7C8 800723C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D7CC 800723CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D7D0 800723D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D7D4 800723D4 0C016959 */  jal       load_effect
/* 4D7D8 800723D8 24040073 */   addiu    $a0, $zero, 0x73
/* 4D7DC 800723DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D7E0 800723E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D7E4 800723E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D7E8 800723E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D7EC 800723EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D7F0 800723F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D7F4 800723F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D7F8 800723F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D7FC 800723FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D800 80072400 3C018008 */  lui       $at, %hi(gEffectTable+0xAC8)
/* 4D804 80072404 8C21FCD8 */  lw        $at, %lo(gEffectTable+0xAC8)($at)
/* 4D808 80072408 00200008 */  jr        $at
/* 4D80C 8007240C 00000000 */   nop

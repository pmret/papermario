.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070E50
/* 4C250 80070E50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C254 80070E54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C258 80070E58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C25C 80070E5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C260 80070E60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C264 80070E64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C268 80070E68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C26C 80070E6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C270 80070E70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C274 80070E74 0C016959 */  jal       load_effect
/* 4C278 80070E78 2404003A */   addiu    $a0, $zero, 0x3a
/* 4C27C 80070E7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C280 80070E80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C284 80070E84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C288 80070E88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C28C 80070E8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C290 80070E90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C294 80070E94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C298 80070E98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C29C 80070E9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C2A0 80070EA0 3C018008 */  lui       $at, %hi(gEffectTable+0x570)
/* 4C2A4 80070EA4 8C21F780 */  lw        $at, %lo(gEffectTable+0x570)($at)
/* 4C2A8 80070EA8 00200008 */  jr        $at
/* 4C2AC 80070EAC 00000000 */   nop

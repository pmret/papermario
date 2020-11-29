.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070310
/* 4B710 80070310 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B714 80070314 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B718 80070318 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B71C 8007031C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B720 80070320 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B724 80070324 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B728 80070328 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B72C 8007032C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B730 80070330 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B734 80070334 0C016959 */  jal       play_effect
/* 4B738 80070338 2404001C */   addiu    $a0, $zero, 0x1c
/* 4B73C 8007033C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B740 80070340 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B744 80070344 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B748 80070348 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B74C 8007034C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B750 80070350 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B754 80070354 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B758 80070358 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B75C 8007035C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B760 80070360 3C018008 */  lui       $at, %hi(D_8007F4B0)
/* 4B764 80070364 8C21F4B0 */  lw        $at, %lo(D_8007F4B0)($at)
/* 4B768 80070368 00200008 */  jr        $at
/* 4B76C 8007036C 00000000 */   nop      

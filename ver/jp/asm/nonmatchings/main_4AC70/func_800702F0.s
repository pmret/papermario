.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800702F0
/* 4B6F0 800702F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B6F4 800702F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B6F8 800702F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B6FC 800702FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B700 80070300 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B704 80070304 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B708 80070308 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B70C 8007030C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B710 80070310 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B714 80070314 0C016885 */  jal       func_8005A214
/* 4B718 80070318 2404001C */   addiu    $a0, $zero, 0x1c
/* 4B71C 8007031C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B720 80070320 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B724 80070324 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B728 80070328 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B72C 8007032C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B730 80070330 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B734 80070334 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B738 80070338 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B73C 8007033C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B740 80070340 3C018008 */  lui       $at, %hi(D_8007F480)
/* 4B744 80070344 8C21F480 */  lw        $at, %lo(D_8007F480)($at)
/* 4B748 80070348 00200008 */  jr        $at
/* 4B74C 8007034C 00000000 */   nop

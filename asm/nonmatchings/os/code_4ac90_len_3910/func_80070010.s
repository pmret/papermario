.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070010
/* 4B410 80070010 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B414 80070014 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B418 80070018 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B41C 8007001C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B420 80070020 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B424 80070024 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B428 80070028 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B42C 8007002C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B430 80070030 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B434 80070034 0C016959 */  jal       play_effect
/* 4B438 80070038 24040014 */   addiu    $a0, $zero, 0x14
/* 4B43C 8007003C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B440 80070040 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B444 80070044 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B448 80070048 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B44C 8007004C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B450 80070050 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B454 80070054 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B458 80070058 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B45C 8007005C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B460 80070060 3C018008 */  lui       $at, %hi(D_8007F3F0)
/* 4B464 80070064 8C21F3F0 */  lw        $at, %lo(D_8007F3F0)($at)
/* 4B468 80070068 00200008 */  jr        $at
/* 4B46C 8007006C 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070050
/* 4B450 80070050 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B454 80070054 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B458 80070058 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B45C 8007005C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B460 80070060 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B464 80070064 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B468 80070068 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B46C 8007006C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B470 80070070 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B474 80070074 0C016885 */  jal       func_8005A214
/* 4B478 80070078 24040015 */   addiu    $a0, $zero, 0x15
/* 4B47C 8007007C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B480 80070080 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B484 80070084 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B488 80070088 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B48C 8007008C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B490 80070090 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B494 80070094 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B498 80070098 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B49C 8007009C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B4A0 800700A0 3C018008 */  lui       $at, %hi(D_8007F3D8)
/* 4B4A4 800700A4 8C21F3D8 */  lw        $at, %lo(D_8007F3D8)($at)
/* 4B4A8 800700A8 00200008 */  jr        $at
/* 4B4AC 800700AC 00000000 */   nop

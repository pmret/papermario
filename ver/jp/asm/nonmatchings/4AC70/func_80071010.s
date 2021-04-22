.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071010
/* 4C410 80071010 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C414 80071014 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C418 80071018 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C41C 8007101C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C420 80071020 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C424 80071024 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C428 80071028 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C42C 8007102C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C430 80071030 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C434 80071034 0C016885 */  jal       func_8005A214
/* 4C438 80071038 2404003F */   addiu    $a0, $zero, 0x3f
/* 4C43C 8007103C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C440 80071040 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C444 80071044 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C448 80071048 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C44C 8007104C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C450 80071050 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C454 80071054 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C458 80071058 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C45C 8007105C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C460 80071060 3C018008 */  lui       $at, %hi(D_8007F7C8)
/* 4C464 80071064 8C21F7C8 */  lw        $at, %lo(D_8007F7C8)($at)
/* 4C468 80071068 00200008 */  jr        $at
/* 4C46C 8007106C 00000000 */   nop

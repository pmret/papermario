.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070470
/* 4B870 80070470 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B874 80070474 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B878 80070478 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B87C 8007047C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B880 80070480 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B884 80070484 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B888 80070488 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B88C 8007048C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B890 80070490 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B894 80070494 0C016885 */  jal       func_8005A214
/* 4B898 80070498 24040020 */   addiu    $a0, $zero, 0x20
/* 4B89C 8007049C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B8A0 800704A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B8A4 800704A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B8A8 800704A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B8AC 800704AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B8B0 800704B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B8B4 800704B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B8B8 800704B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B8BC 800704BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B8C0 800704C0 3C018008 */  lui       $at, %hi(D_8007F4E0)
/* 4B8C4 800704C4 8C21F4E0 */  lw        $at, %lo(D_8007F4E0)($at)
/* 4B8C8 800704C8 00200008 */  jr        $at
/* 4B8CC 800704CC 00000000 */   nop

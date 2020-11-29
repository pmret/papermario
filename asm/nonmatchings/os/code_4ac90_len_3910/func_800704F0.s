.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800704F0
/* 4B8F0 800704F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B8F4 800704F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B8F8 800704F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B8FC 800704FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4B900 80070500 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B904 80070504 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B908 80070508 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B90C 8007050C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B910 80070510 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B914 80070514 0C016959 */  jal       play_effect
/* 4B918 80070518 24040021 */   addiu    $a0, $zero, 0x21
/* 4B91C 8007051C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B920 80070520 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B924 80070524 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B928 80070528 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B92C 8007052C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B930 80070530 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B934 80070534 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B938 80070538 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B93C 8007053C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B940 80070540 3C018008 */  lui       $at, %hi(D_8007F528)
/* 4B944 80070544 8C21F528 */  lw        $at, %lo(D_8007F528)($at)
/* 4B948 80070548 00200008 */  jr        $at
/* 4B94C 8007054C 00000000 */   nop      

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070B50
/* 4BF50 80070B50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BF54 80070B54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BF58 80070B58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BF5C 80070B5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BF60 80070B60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BF64 80070B64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BF68 80070B68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BF6C 80070B6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BF70 80070B70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BF74 80070B74 0C016959 */  jal       play_effect
/* 4BF78 80070B78 24040032 */   addiu    $a0, $zero, 0x32
/* 4BF7C 80070B7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BF80 80070B80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BF84 80070B84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BF88 80070B88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BF8C 80070B8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BF90 80070B90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BF94 80070B94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BF98 80070B98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BF9C 80070B9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BFA0 80070BA0 3C018008 */  lui       $at, 0x8008
/* 4BFA4 80070BA4 8C21F6C0 */  lw        $at, -0x940($at)
/* 4BFA8 80070BA8 00200008 */  jr        $at
/* 4BFAC 80070BAC 00000000 */   nop      

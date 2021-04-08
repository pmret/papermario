.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F8D0
/* 4ACD0 8006F8D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4ACD4 8006F8D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4ACD8 8006F8D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4ACDC 8006F8DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4ACE0 8006F8E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4ACE4 8006F8E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4ACE8 8006F8E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4ACEC 8006F8EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4ACF0 8006F8F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4ACF4 8006F8F4 0C016885 */  jal       func_8005A214
/* 4ACF8 8006F8F8 24040001 */   addiu    $a0, $zero, 1
/* 4ACFC 8006F8FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AD00 8006F900 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AD04 8006F904 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AD08 8006F908 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AD0C 8006F90C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AD10 8006F910 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AD14 8006F914 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AD18 8006F918 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AD1C 8006F91C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AD20 8006F920 3C018008 */  lui       $at, %hi(D_8007F1F8)
/* 4AD24 8006F924 8C21F1F8 */  lw        $at, %lo(D_8007F1F8)($at)
/* 4AD28 8006F928 00200008 */  jr        $at
/* 4AD2C 8006F92C 00000000 */   nop

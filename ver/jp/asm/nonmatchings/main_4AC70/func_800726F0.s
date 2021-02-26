.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800726F0
/* 4DAF0 800726F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DAF4 800726F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DAF8 800726F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DAFC 800726FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DB00 80072700 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DB04 80072704 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DB08 80072708 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DB0C 8007270C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DB10 80072710 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DB14 80072714 0C016885 */  jal       func_8005A214
/* 4DB18 80072718 2404007C */   addiu    $a0, $zero, 0x7c
/* 4DB1C 8007271C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DB20 80072720 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DB24 80072724 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DB28 80072728 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DB2C 8007272C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DB30 80072730 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DB34 80072734 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DB38 80072738 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DB3C 8007273C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DB40 80072740 3C018008 */  lui       $at, %hi(D_8007FD80)
/* 4DB44 80072744 8C21FD80 */  lw        $at, %lo(D_8007FD80)($at)
/* 4DB48 80072748 00200008 */  jr        $at
/* 4DB4C 8007274C 00000000 */   nop

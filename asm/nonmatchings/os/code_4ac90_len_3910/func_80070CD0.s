.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070CD0
/* 4C0D0 80070CD0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C0D4 80070CD4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C0D8 80070CD8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C0DC 80070CDC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C0E0 80070CE0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C0E4 80070CE4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C0E8 80070CE8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C0EC 80070CEC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C0F0 80070CF0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C0F4 80070CF4 0C016959 */  jal       play_effect
/* 4C0F8 80070CF8 24040036 */   addiu    $a0, $zero, 0x36
/* 4C0FC 80070CFC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C100 80070D00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C104 80070D04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C108 80070D08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C10C 80070D0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C110 80070D10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C114 80070D14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C118 80070D18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C11C 80070D1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C120 80070D20 3C018008 */  lui       $at, %hi(D_8007F720)
/* 4C124 80070D24 8C21F720 */  lw        $at, %lo(D_8007F720)($at)
/* 4C128 80070D28 00200008 */  jr        $at
/* 4C12C 80070D2C 00000000 */   nop

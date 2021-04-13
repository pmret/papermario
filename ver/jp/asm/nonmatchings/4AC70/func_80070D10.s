.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070D10
/* 4C110 80070D10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C114 80070D14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C118 80070D18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C11C 80070D1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C120 80070D20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C124 80070D24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C128 80070D28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C12C 80070D2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C130 80070D30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C134 80070D34 0C016885 */  jal       func_8005A214
/* 4C138 80070D38 24040037 */   addiu    $a0, $zero, 0x37
/* 4C13C 80070D3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C140 80070D40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C144 80070D44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C148 80070D48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C14C 80070D4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C150 80070D50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C154 80070D54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C158 80070D58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C15C 80070D5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C160 80070D60 3C018008 */  lui       $at, %hi(D_8007F708)
/* 4C164 80070D64 8C21F708 */  lw        $at, %lo(D_8007F708)($at)
/* 4C168 80070D68 00200008 */  jr        $at
/* 4C16C 80070D6C 00000000 */   nop

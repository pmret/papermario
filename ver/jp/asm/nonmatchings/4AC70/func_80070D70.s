.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070D70
/* 4C170 80070D70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C174 80070D74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C178 80070D78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C17C 80070D7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C180 80070D80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C184 80070D84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C188 80070D88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C18C 80070D8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C190 80070D90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C194 80070D94 0C016885 */  jal       func_8005A214
/* 4C198 80070D98 24040038 */   addiu    $a0, $zero, 0x38
/* 4C19C 80070D9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C1A0 80070DA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C1A4 80070DA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C1A8 80070DA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C1AC 80070DAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C1B0 80070DB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C1B4 80070DB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C1B8 80070DB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C1BC 80070DBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C1C0 80070DC0 3C018008 */  lui       $at, %hi(D_8007F720)
/* 4C1C4 80070DC4 8C21F720 */  lw        $at, %lo(D_8007F720)($at)
/* 4C1C8 80070DC8 00200008 */  jr        $at
/* 4C1CC 80070DCC 00000000 */   nop

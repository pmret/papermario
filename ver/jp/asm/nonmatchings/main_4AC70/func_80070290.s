.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070290
/* 4B690 80070290 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B694 80070294 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B698 80070298 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B69C 8007029C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B6A0 800702A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B6A4 800702A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B6A8 800702A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B6AC 800702AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B6B0 800702B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B6B4 800702B4 0C016885 */  jal       func_8005A214
/* 4B6B8 800702B8 2404001B */   addiu    $a0, $zero, 0x1b
/* 4B6BC 800702BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B6C0 800702C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B6C4 800702C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B6C8 800702C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B6CC 800702CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B6D0 800702D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B6D4 800702D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B6D8 800702D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B6DC 800702DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B6E0 800702E0 3C018008 */  lui       $at, %hi(D_8007F468)
/* 4B6E4 800702E4 8C21F468 */  lw        $at, %lo(D_8007F468)($at)
/* 4B6E8 800702E8 00200008 */  jr        $at
/* 4B6EC 800702EC 00000000 */   nop

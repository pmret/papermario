.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072390
/* 4D790 80072390 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D794 80072394 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D798 80072398 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D79C 8007239C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D7A0 800723A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D7A4 800723A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D7A8 800723A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D7AC 800723AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D7B0 800723B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D7B4 800723B4 0C016885 */  jal       func_8005A214
/* 4D7B8 800723B8 24040073 */   addiu    $a0, $zero, 0x73
/* 4D7BC 800723BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D7C0 800723C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D7C4 800723C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D7C8 800723C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D7CC 800723CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D7D0 800723D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D7D4 800723D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D7D8 800723D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D7DC 800723DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D7E0 800723E0 3C018008 */  lui       $at, %hi(D_8007FCA8)
/* 4D7E4 800723E4 8C21FCA8 */  lw        $at, %lo(D_8007FCA8)($at)
/* 4D7E8 800723E8 00200008 */  jr        $at
/* 4D7EC 800723EC 00000000 */   nop

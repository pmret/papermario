.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070A70
/* 4BE70 80070A70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BE74 80070A74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BE78 80070A78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BE7C 80070A7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BE80 80070A80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BE84 80070A84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BE88 80070A88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BE8C 80070A8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BE90 80070A90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BE94 80070A94 0C016885 */  jal       func_8005A214
/* 4BE98 80070A98 24040030 */   addiu    $a0, $zero, 0x30
/* 4BE9C 80070A9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BEA0 80070AA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BEA4 80070AA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BEA8 80070AA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BEAC 80070AAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BEB0 80070AB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BEB4 80070AB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BEB8 80070AB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BEBC 80070ABC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BEC0 80070AC0 3C018008 */  lui       $at, %hi(D_8007F660)
/* 4BEC4 80070AC4 8C21F660 */  lw        $at, %lo(D_8007F660)($at)
/* 4BEC8 80070AC8 00200008 */  jr        $at
/* 4BECC 80070ACC 00000000 */   nop

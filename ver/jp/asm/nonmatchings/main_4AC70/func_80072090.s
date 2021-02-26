.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072090
/* 4D490 80072090 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D494 80072094 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D498 80072098 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D49C 8007209C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D4A0 800720A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D4A4 800720A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D4A8 800720A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D4AC 800720AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D4B0 800720B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D4B4 800720B4 0C016885 */  jal       func_8005A214
/* 4D4B8 800720B8 2404006B */   addiu    $a0, $zero, 0x6b
/* 4D4BC 800720BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D4C0 800720C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D4C4 800720C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D4C8 800720C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D4CC 800720CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D4D0 800720D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D4D4 800720D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D4D8 800720D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D4DC 800720DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D4E0 800720E0 3C018008 */  lui       $at, %hi(D_8007FBE8)
/* 4D4E4 800720E4 8C21FBE8 */  lw        $at, %lo(D_8007FBE8)($at)
/* 4D4E8 800720E8 00200008 */  jr        $at
/* 4D4EC 800720EC 00000000 */   nop

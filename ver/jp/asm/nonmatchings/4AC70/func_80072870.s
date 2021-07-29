.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072870
/* 4DC70 80072870 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DC74 80072874 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DC78 80072878 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DC7C 8007287C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DC80 80072880 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DC84 80072884 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DC88 80072888 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DC8C 8007288C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DC90 80072890 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DC94 80072894 0C016885 */  jal       func_8005A214
/* 4DC98 80072898 24040080 */   addiu    $a0, $zero, 0x80
/* 4DC9C 8007289C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DCA0 800728A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DCA4 800728A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DCA8 800728A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DCAC 800728AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DCB0 800728B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DCB4 800728B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DCB8 800728B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DCBC 800728BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DCC0 800728C0 3C018008 */  lui       $at, %hi(D_8007FDE0)
/* 4DCC4 800728C4 8C21FDE0 */  lw        $at, %lo(D_8007FDE0)($at)
/* 4DCC8 800728C8 00200008 */  jr        $at
/* 4DCCC 800728CC 00000000 */   nop

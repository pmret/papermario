.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800722D0
/* 4D6D0 800722D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D6D4 800722D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D6D8 800722D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D6DC 800722DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D6E0 800722E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D6E4 800722E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D6E8 800722E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D6EC 800722EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D6F0 800722F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D6F4 800722F4 0C016885 */  jal       func_8005A214
/* 4D6F8 800722F8 24040071 */   addiu    $a0, $zero, 0x71
/* 4D6FC 800722FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D700 80072300 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D704 80072304 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D708 80072308 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D70C 8007230C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D710 80072310 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D714 80072314 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D718 80072318 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D71C 8007231C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D720 80072320 3C018008 */  lui       $at, %hi(D_8007FC78)
/* 4D724 80072324 8C21FC78 */  lw        $at, %lo(D_8007FC78)($at)
/* 4D728 80072328 00200008 */  jr        $at
/* 4D72C 8007232C 00000000 */   nop

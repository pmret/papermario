.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800723F0
/* 4D7F0 800723F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D7F4 800723F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D7F8 800723F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D7FC 800723FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D800 80072400 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D804 80072404 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D808 80072408 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D80C 8007240C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D810 80072410 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D814 80072414 0C016885 */  jal       func_8005A214
/* 4D818 80072418 24040074 */   addiu    $a0, $zero, 0x74
/* 4D81C 8007241C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D820 80072420 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D824 80072424 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D828 80072428 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D82C 8007242C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D830 80072430 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D834 80072434 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D838 80072438 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D83C 8007243C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D840 80072440 3C018008 */  lui       $at, %hi(D_8007FCC0)
/* 4D844 80072444 8C21FCC0 */  lw        $at, %lo(D_8007FCC0)($at)
/* 4D848 80072448 00200008 */  jr        $at
/* 4D84C 8007244C 00000000 */   nop

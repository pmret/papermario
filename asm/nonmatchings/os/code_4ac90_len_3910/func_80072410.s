.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072410
/* 4D810 80072410 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D814 80072414 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D818 80072418 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D81C 8007241C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D820 80072420 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D824 80072424 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D828 80072428 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D82C 8007242C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D830 80072430 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D834 80072434 0C016959 */  jal       load_effect
/* 4D838 80072438 24040074 */   addiu    $a0, $zero, 0x74
/* 4D83C 8007243C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D840 80072440 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D844 80072444 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D848 80072448 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D84C 8007244C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D850 80072450 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D854 80072454 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D858 80072458 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D85C 8007245C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D860 80072460 3C018008 */  lui       $at, %hi(D_8007FCF0)
/* 4D864 80072464 8C21FCF0 */  lw        $at, %lo(D_8007FCF0)($at)
/* 4D868 80072468 00200008 */  jr        $at
/* 4D86C 8007246C 00000000 */   nop

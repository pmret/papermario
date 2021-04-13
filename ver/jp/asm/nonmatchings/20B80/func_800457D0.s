.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800457D0
/* 20BD0 800457D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20BD4 800457D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 20BD8 800457D8 0000882D */  daddu     $s1, $zero, $zero
/* 20BDC 800457DC AFB00010 */  sw        $s0, 0x10($sp)
/* 20BE0 800457E0 3C10800A */  lui       $s0, %hi(D_8009E9D0)
/* 20BE4 800457E4 2610E9D0 */  addiu     $s0, $s0, %lo(D_8009E9D0)
/* 20BE8 800457E8 AFBF0018 */  sw        $ra, 0x18($sp)
.L800457EC:
/* 20BEC 800457EC 8E040018 */  lw        $a0, 0x18($s0)
/* 20BF0 800457F0 50800004 */  beql      $a0, $zero, .L80045804
/* 20BF4 800457F4 A6000010 */   sh       $zero, 0x10($s0)
/* 20BF8 800457F8 0C00AB3B */  jal       func_8002ACEC
/* 20BFC 800457FC 00000000 */   nop
/* 20C00 80045800 A6000010 */  sh        $zero, 0x10($s0)
.L80045804:
/* 20C04 80045804 26310001 */  addiu     $s1, $s1, 1
/* 20C08 80045808 2A220020 */  slti      $v0, $s1, 0x20
/* 20C0C 8004580C 1440FFF7 */  bnez      $v0, .L800457EC
/* 20C10 80045810 2610001C */   addiu    $s0, $s0, 0x1c
/* 20C14 80045814 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20C18 80045818 8FB10014 */  lw        $s1, 0x14($sp)
/* 20C1C 8004581C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20C20 80045820 03E00008 */  jr        $ra
/* 20C24 80045824 27BD0020 */   addiu    $sp, $sp, 0x20

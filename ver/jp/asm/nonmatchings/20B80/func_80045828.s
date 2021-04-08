.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045828
/* 20C28 80045828 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20C2C 8004582C AFB10014 */  sw        $s1, 0x14($sp)
/* 20C30 80045830 0000882D */  daddu     $s1, $zero, $zero
/* 20C34 80045834 AFB00010 */  sw        $s0, 0x10($sp)
/* 20C38 80045838 3C10800A */  lui       $s0, %hi(D_8009E9D0)
/* 20C3C 8004583C 2610E9D0 */  addiu     $s0, $s0, %lo(D_8009E9D0)
/* 20C40 80045840 AFBF0018 */  sw        $ra, 0x18($sp)
.L80045844:
/* 20C44 80045844 86020010 */  lh        $v0, 0x10($s0)
/* 20C48 80045848 50400007 */  beql      $v0, $zero, .L80045868
/* 20C4C 8004584C 26310001 */   addiu    $s1, $s1, 1
/* 20C50 80045850 8E020004 */  lw        $v0, 4($s0)
/* 20C54 80045854 50400004 */  beql      $v0, $zero, .L80045868
/* 20C58 80045858 26310001 */   addiu    $s1, $s1, 1
/* 20C5C 8004585C 0040F809 */  jalr      $v0
/* 20C60 80045860 0200202D */   daddu    $a0, $s0, $zero
/* 20C64 80045864 26310001 */  addiu     $s1, $s1, 1
.L80045868:
/* 20C68 80045868 2A220020 */  slti      $v0, $s1, 0x20
/* 20C6C 8004586C 1440FFF5 */  bnez      $v0, .L80045844
/* 20C70 80045870 2610001C */   addiu    $s0, $s0, 0x1c
/* 20C74 80045874 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20C78 80045878 8FB10014 */  lw        $s1, 0x14($sp)
/* 20C7C 8004587C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20C80 80045880 03E00008 */  jr        $ra
/* 20C84 80045884 27BD0020 */   addiu    $sp, $sp, 0x20

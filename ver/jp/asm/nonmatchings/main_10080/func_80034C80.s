.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80034C80
/* 10080 80034C80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10084 80034C84 AFB00010 */  sw        $s0, 0x10($sp)
/* 10088 80034C88 3C10800A */  lui       $s0, %hi(D_8009E742)
/* 1008C 80034C8C 2610E742 */  addiu     $s0, $s0, %lo(D_8009E742)
/* 10090 80034C90 AFBF0014 */  sw        $ra, 0x14($sp)
/* 10094 80034C94 3C01800A */  lui       $at, %hi(D_8009E741)
/* 10098 80034C98 A020E741 */  sb        $zero, %lo(D_8009E741)($at)
/* 1009C 80034C9C 0C038056 */  jal       func_800E0158
/* 100A0 80034CA0 A6000000 */   sh       $zero, ($s0)
/* 100A4 80034CA4 0C009C15 */  jal       func_80027054
/* 100A8 80034CA8 24040002 */   addiu    $a0, $zero, 2
/* 100AC 80034CAC 86020000 */  lh        $v0, ($s0)
/* 100B0 80034CB0 44820000 */  mtc1      $v0, $f0
/* 100B4 80034CB4 00000000 */  nop
/* 100B8 80034CB8 46800020 */  cvt.s.w   $f0, $f0
/* 100BC 80034CBC 44050000 */  mfc1      $a1, $f0
/* 100C0 80034CC0 0C04F38E */  jal       func_8013CE38
/* 100C4 80034CC4 0000202D */   daddu    $a0, $zero, $zero
/* 100C8 80034CC8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 100CC 80034CCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 100D0 80034CD0 03E00008 */  jr        $ra
/* 100D4 80034CD4 27BD0018 */   addiu    $sp, $sp, 0x18

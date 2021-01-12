.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxSwapCfbFuncSet
/* 3B710 80060310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B714 80060314 AFB00010 */  sw        $s0, 0x10($sp)
/* 3B718 80060318 0080802D */  daddu     $s0, $a0, $zero
/* 3B71C 8006031C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3B720 80060320 0C018250 */  jal       osSetIntMask
/* 3B724 80060324 24040001 */   addiu    $a0, $zero, 1
/* 3B728 80060328 3C018007 */  lui       $at, %hi(D_800773F4)
/* 3B72C 8006032C AC3073F4 */  sw        $s0, %lo(D_800773F4)($at)
/* 3B730 80060330 0C018250 */  jal       osSetIntMask
/* 3B734 80060334 0040202D */   daddu    $a0, $v0, $zero
/* 3B738 80060338 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3B73C 8006033C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3B740 80060340 03E00008 */  jr        $ra
/* 3B744 80060344 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3B748 80060348 00000000 */  nop
/* 3B74C 8006034C 00000000 */  nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006032C
/* 3B72C 8006032C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3B730 80060330 AFB00040 */  sw        $s0, 0x40($sp)
/* 3B734 80060334 27B00010 */  addiu     $s0, $sp, 0x10
/* 3B738 80060338 0200202D */  daddu     $a0, $s0, $zero
/* 3B73C 8006033C 27A50038 */  addiu     $a1, $sp, 0x38
/* 3B740 80060340 24060001 */  addiu     $a2, $zero, 1
/* 3B744 80060344 24027F00 */  addiu     $v0, $zero, 0x7f00
/* 3B748 80060348 AFBF0044 */  sw        $ra, 0x44($sp)
/* 3B74C 8006034C A7A20028 */  sh        $v0, 0x28($sp)
/* 3B750 80060350 AFA00034 */  sw        $zero, 0x34($sp)
/* 3B754 80060354 0C019554 */  jal       func_80065550
/* 3B758 80060358 AFB0002C */   sw       $s0, 0x2c($sp)
/* 3B75C 8006035C 3C04800E */  lui       $a0, %hi(D_800D91D4)
/* 3B760 80060360 248491D4 */  addiu     $a0, $a0, %lo(D_800D91D4)
/* 3B764 80060364 27A50028 */  addiu     $a1, $sp, 0x28
/* 3B768 80060368 0C0195FC */  jal       func_800657F0
/* 3B76C 8006036C 24060001 */   addiu    $a2, $zero, 1
/* 3B770 80060370 0200202D */  daddu     $a0, $s0, $zero
/* 3B774 80060374 0000282D */  daddu     $a1, $zero, $zero
/* 3B778 80060378 0C0195B0 */  jal       func_800656C0
/* 3B77C 8006037C 24060001 */   addiu    $a2, $zero, 1
/* 3B780 80060380 8FBF0044 */  lw        $ra, 0x44($sp)
/* 3B784 80060384 8FB00040 */  lw        $s0, 0x40($sp)
/* 3B788 80060388 03E00008 */  jr        $ra
/* 3B78C 8006038C 27BD0048 */   addiu    $sp, $sp, 0x48

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240068_B9B4E8
/* B9B4E8 80240068 44806000 */  mtc1      $zero, $f12
/* B9B4EC 8024006C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B9B4F0 80240070 AFB00010 */  sw        $s0, 0x10($sp)
/* B9B4F4 80240074 0080802D */  daddu     $s0, $a0, $zero
/* B9B4F8 80240078 AFBF0014 */  sw        $ra, 0x14($sp)
/* B9B4FC 8024007C 0C038022 */  jal       func_800E0088
/* B9B500 80240080 46006386 */   mov.s    $f14, $f12
/* B9B504 80240084 4600008D */  trunc.w.s $f2, $f0
/* B9B508 80240088 E6020084 */  swc1      $f2, 0x84($s0)
/* B9B50C 8024008C 8FBF0014 */  lw        $ra, 0x14($sp)
/* B9B510 80240090 8FB00010 */  lw        $s0, 0x10($sp)
/* B9B514 80240094 24020002 */  addiu     $v0, $zero, 2
/* B9B518 80240098 03E00008 */  jr        $ra
/* B9B51C 8024009C 27BD0018 */   addiu    $sp, $sp, 0x18

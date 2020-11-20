.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetActorIdleSpeed
/* 199FB0 8026B6D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 199FB4 8026B6D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 199FB8 8026B6D8 0080902D */  daddu     $s2, $a0, $zero
/* 199FBC 8026B6DC AFBF001C */  sw        $ra, 0x1c($sp)
/* 199FC0 8026B6E0 AFB10014 */  sw        $s1, 0x14($sp)
/* 199FC4 8026B6E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 199FC8 8026B6E8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 199FCC 8026B6EC 8E51000C */  lw        $s1, 0xc($s2)
/* 199FD0 8026B6F0 8E250000 */  lw        $a1, ($s1)
/* 199FD4 8026B6F4 0C0B1EAF */  jal       get_variable
/* 199FD8 8026B6F8 26310004 */   addiu    $s1, $s1, 4
/* 199FDC 8026B6FC 0040802D */  daddu     $s0, $v0, $zero
/* 199FE0 8026B700 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 199FE4 8026B704 16020002 */  bne       $s0, $v0, .L8026B710
/* 199FE8 8026B708 00000000 */   nop
/* 199FEC 8026B70C 8E500148 */  lw        $s0, 0x148($s2)
.L8026B710:
/* 199FF0 8026B710 8E250000 */  lw        $a1, ($s1)
/* 199FF4 8026B714 0C0B210B */  jal       get_float_variable
/* 199FF8 8026B718 0240202D */   daddu    $a0, $s2, $zero
/* 199FFC 8026B71C 0200202D */  daddu     $a0, $s0, $zero
/* 19A000 8026B720 0C09A75B */  jal       get_actor
/* 19A004 8026B724 46000506 */   mov.s    $f20, $f0
/* 19A008 8026B728 E4540108 */  swc1      $f20, 0x108($v0)
/* 19A00C 8026B72C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19A010 8026B730 8FB20018 */  lw        $s2, 0x18($sp)
/* 19A014 8026B734 8FB10014 */  lw        $s1, 0x14($sp)
/* 19A018 8026B738 8FB00010 */  lw        $s0, 0x10($sp)
/* 19A01C 8026B73C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 19A020 8026B740 24020002 */  addiu     $v0, $zero, 2
/* 19A024 8026B744 03E00008 */  jr        $ra
/* 19A028 8026B748 27BD0028 */   addiu    $sp, $sp, 0x28

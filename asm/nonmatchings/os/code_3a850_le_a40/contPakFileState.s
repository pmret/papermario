.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel contPakFileState
/* 03ACA4 8005F8A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03ACA8 8005F8A8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03ACAC 8005F8AC 8C83000C */  lw    $v1, 0xc($a0)
/* 03ACB0 8005F8B0 8C620000 */  lw    $v0, ($v1)
/* 03ACB4 8005F8B4 8C660004 */  lw    $a2, 4($v1)
/* 03ACB8 8005F8B8 8C440000 */  lw    $a0, ($v0)
/* 03ACBC 8005F8BC 0C01A308 */  jal   osPfsFileState
/* 03ACC0 8005F8C0 8C450004 */   lw    $a1, 4($v0)
/* 03ACC4 8005F8C4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03ACC8 8005F8C8 03E00008 */  jr    $ra
/* 03ACCC 8005F8CC 27BD0018 */   addiu $sp, $sp, 0x18


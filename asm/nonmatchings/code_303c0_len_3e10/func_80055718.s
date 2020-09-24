.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055718
/* 30B18 80055718 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30B1C 8005571C AFB10014 */  sw        $s1, 0x14($sp)
/* 30B20 80055720 0080882D */  daddu     $s1, $a0, $zero
/* 30B24 80055724 AFBF0018 */  sw        $ra, 0x18($sp)
/* 30B28 80055728 0C01430C */  jal       func_80050C30
/* 30B2C 8005572C AFB00010 */   sw       $s0, 0x10($sp)
/* 30B30 80055730 0040802D */  daddu     $s0, $v0, $zero
/* 30B34 80055734 16000005 */  bnez      $s0, .L8005574C
/* 30B38 80055738 0200102D */   daddu    $v0, $s0, $zero
/* 30B3C 8005573C 0220202D */  daddu     $a0, $s1, $zero
/* 30B40 80055740 0C014319 */  jal       func_80050C64
/* 30B44 80055744 0000282D */   daddu    $a1, $zero, $zero
/* 30B48 80055748 0200102D */  daddu     $v0, $s0, $zero
.L8005574C:
/* 30B4C 8005574C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30B50 80055750 8FB10014 */  lw        $s1, 0x14($sp)
/* 30B54 80055754 8FB00010 */  lw        $s0, 0x10($sp)
/* 30B58 80055758 03E00008 */  jr        $ra
/* 30B5C 8005575C 27BD0020 */   addiu    $sp, $sp, 0x20

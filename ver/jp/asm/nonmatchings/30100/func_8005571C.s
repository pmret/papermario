.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005571C
/* 30B1C 8005571C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30B20 80055720 AFB00030 */  sw        $s0, 0x30($sp)
/* 30B24 80055724 3C108008 */  lui       $s0, %hi(D_80078D80)
/* 30B28 80055728 26108D80 */  addiu     $s0, $s0, %lo(D_80078D80)
/* 30B2C 8005572C 24020001 */  addiu     $v0, $zero, 1
/* 30B30 80055730 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30B34 80055734 AE020000 */  sw        $v0, ($s0)
/* 30B38 80055738 AFA40010 */  sw        $a0, 0x10($sp)
/* 30B3C 8005573C 27A40010 */  addiu     $a0, $sp, 0x10
/* 30B40 80055740 AFA50014 */  sw        $a1, 0x14($sp)
/* 30B44 80055744 AFA60018 */  sw        $a2, 0x18($sp)
/* 30B48 80055748 AFA7001C */  sw        $a3, 0x1c($sp)
/* 30B4C 8005574C AFA00020 */  sw        $zero, 0x20($sp)
/* 30B50 80055750 0C013524 */  jal       func_8004D490
/* 30B54 80055754 AFA00024 */   sw       $zero, 0x24($sp)
/* 30B58 80055758 AE000000 */  sw        $zero, ($s0)
/* 30B5C 8005575C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30B60 80055760 8FB00030 */  lw        $s0, 0x30($sp)
/* 30B64 80055764 03E00008 */  jr        $ra
/* 30B68 80055768 27BD0038 */   addiu    $sp, $sp, 0x38

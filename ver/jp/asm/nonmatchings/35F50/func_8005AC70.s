.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005AC70
/* 36070 8005AC70 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 36074 8005AC74 AFBF0024 */  sw        $ra, 0x24($sp)
/* 36078 8005AC78 AFB20020 */  sw        $s2, 0x20($sp)
/* 3607C 8005AC7C AFB1001C */  sw        $s1, 0x1c($sp)
/* 36080 8005AC80 0C016A28 */  jal       func_8005A8A0
/* 36084 8005AC84 AFB00018 */   sw       $s0, 0x18($sp)
/* 36088 8005AC88 3C04800E */  lui       $a0, %hi(D_800D91C0)
/* 3608C 8005AC8C 248491C0 */  addiu     $a0, $a0, %lo(D_800D91C0)
/* 36090 8005AC90 27A50010 */  addiu     $a1, $sp, 0x10
/* 36094 8005AC94 0C016A68 */  jal       func_8005A9A0
/* 36098 8005AC98 0040902D */   daddu    $s2, $v0, $zero
/* 3609C 8005AC9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 360A0 8005ACA0 0C00AB29 */  jal       func_8002ACA4
/* 360A4 8005ACA4 0040882D */   daddu    $s1, $v0, $zero
/* 360A8 8005ACA8 0220202D */  daddu     $a0, $s1, $zero
/* 360AC 8005ACAC 0040802D */  daddu     $s0, $v0, $zero
/* 360B0 8005ACB0 0C01BB74 */  jal       func_8006EDD0
/* 360B4 8005ACB4 0200282D */   daddu    $a1, $s0, $zero
/* 360B8 8005ACB8 0C00AB0E */  jal       func_8002AC38
/* 360BC 8005ACBC 0220202D */   daddu    $a0, $s1, $zero
/* 360C0 8005ACC0 8E020000 */  lw        $v0, ($s0)
/* 360C4 8005ACC4 0000202D */  daddu     $a0, $zero, $zero
/* 360C8 8005ACC8 AE420004 */  sw        $v0, 4($s2)
/* 360CC 8005ACCC 8E020004 */  lw        $v0, 4($s0)
/* 360D0 8005ACD0 0200282D */  daddu     $a1, $s0, $zero
/* 360D4 8005ACD4 0C016BBB */  jal       func_8005AEEC
/* 360D8 8005ACD8 AE420008 */   sw       $v0, 8($s2)
/* 360DC 8005ACDC 24040001 */  addiu     $a0, $zero, 1
/* 360E0 8005ACE0 0C016BBB */  jal       func_8005AEEC
/* 360E4 8005ACE4 0200282D */   daddu    $a1, $s0, $zero
/* 360E8 8005ACE8 0C00AB3B */  jal       func_8002ACEC
/* 360EC 8005ACEC 0200202D */   daddu    $a0, $s0, $zero
/* 360F0 8005ACF0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 360F4 8005ACF4 8FB20020 */  lw        $s2, 0x20($sp)
/* 360F8 8005ACF8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 360FC 8005ACFC 8FB00018 */  lw        $s0, 0x18($sp)
/* 36100 8005AD00 03E00008 */  jr        $ra
/* 36104 8005AD04 27BD0028 */   addiu    $sp, $sp, 0x28

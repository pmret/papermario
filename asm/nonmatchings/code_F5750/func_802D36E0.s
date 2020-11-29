.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D36E0
/* F8090 802D36E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F8094 802D36E4 AFB20018 */  sw        $s2, 0x18($sp)
/* F8098 802D36E8 0080902D */  daddu     $s2, $a0, $zero
/* F809C 802D36EC AFBF001C */  sw        $ra, 0x1c($sp)
/* F80A0 802D36F0 AFB10014 */  sw        $s1, 0x14($sp)
/* F80A4 802D36F4 AFB00010 */  sw        $s0, 0x10($sp)
/* F80A8 802D36F8 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F80AC 802D36FC F7B40020 */  sdc1      $f20, 0x20($sp)
/* F80B0 802D3700 8E50000C */  lw        $s0, 0xc($s2)
/* F80B4 802D3704 8E050000 */  lw        $a1, ($s0)
/* F80B8 802D3708 0C0B1EAF */  jal       get_variable
/* F80BC 802D370C 26100004 */   addiu    $s0, $s0, 4
/* F80C0 802D3710 8E050000 */  lw        $a1, ($s0)
/* F80C4 802D3714 26100004 */  addiu     $s0, $s0, 4
/* F80C8 802D3718 0240202D */  daddu     $a0, $s2, $zero
/* F80CC 802D371C 0C0B210B */  jal       get_float_variable
/* F80D0 802D3720 0040882D */   daddu    $s1, $v0, $zero
/* F80D4 802D3724 8E050000 */  lw        $a1, ($s0)
/* F80D8 802D3728 26100004 */  addiu     $s0, $s0, 4
/* F80DC 802D372C 0240202D */  daddu     $a0, $s2, $zero
/* F80E0 802D3730 0C0B210B */  jal       get_float_variable
/* F80E4 802D3734 46000586 */   mov.s    $f22, $f0
/* F80E8 802D3738 0240202D */  daddu     $a0, $s2, $zero
/* F80EC 802D373C 8E050000 */  lw        $a1, ($s0)
/* F80F0 802D3740 0C0B210B */  jal       get_float_variable
/* F80F4 802D3744 46000506 */   mov.s    $f20, $f0
/* F80F8 802D3748 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F80FC 802D374C 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F8100 802D3750 00118880 */  sll       $s1, $s1, 2
/* F8104 802D3754 02228821 */  addu      $s1, $s1, $v0
/* F8108 802D3758 8E230000 */  lw        $v1, ($s1)
/* F810C 802D375C E4760004 */  swc1      $f22, 4($v1)
/* F8110 802D3760 E4740008 */  swc1      $f20, 8($v1)
/* F8114 802D3764 E460000C */  swc1      $f0, 0xc($v1)
/* F8118 802D3768 8FBF001C */  lw        $ra, 0x1c($sp)
/* F811C 802D376C 8FB20018 */  lw        $s2, 0x18($sp)
/* F8120 802D3770 8FB10014 */  lw        $s1, 0x14($sp)
/* F8124 802D3774 8FB00010 */  lw        $s0, 0x10($sp)
/* F8128 802D3778 D7B60028 */  ldc1      $f22, 0x28($sp)
/* F812C 802D377C D7B40020 */  ldc1      $f20, 0x20($sp)
/* F8130 802D3780 24020002 */  addiu     $v0, $zero, 2
/* F8134 802D3784 03E00008 */  jr        $ra
/* F8138 802D3788 27BD0030 */   addiu    $sp, $sp, 0x30

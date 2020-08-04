.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetPanTarget
/* 0F07DC 802CBE2C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F07E0 802CBE30 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F07E4 802CBE34 0080902D */  daddu $s2, $a0, $zero
/* 0F07E8 802CBE38 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F07EC 802CBE3C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F07F0 802CBE40 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F07F4 802CBE44 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F07F8 802CBE48 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F07FC 802CBE4C 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0800 802CBE50 8E250000 */  lw    $a1, ($s1)
/* 0F0804 802CBE54 0C0B1EAF */  jal   get_variable
/* 0F0808 802CBE58 26310004 */   addiu $s1, $s1, 4
/* 0F080C 802CBE5C 8E250000 */  lw    $a1, ($s1)
/* 0F0810 802CBE60 26310004 */  addiu $s1, $s1, 4
/* 0F0814 802CBE64 0240202D */  daddu $a0, $s2, $zero
/* 0F0818 802CBE68 3C03800B */  lui   $v1, 0x800b
/* 0F081C 802CBE6C 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0820 802CBE70 00028080 */  sll   $s0, $v0, 2
/* 0F0824 802CBE74 02028021 */  addu  $s0, $s0, $v0
/* 0F0828 802CBE78 00108080 */  sll   $s0, $s0, 2
/* 0F082C 802CBE7C 02028023 */  subu  $s0, $s0, $v0
/* 0F0830 802CBE80 001010C0 */  sll   $v0, $s0, 3
/* 0F0834 802CBE84 02028021 */  addu  $s0, $s0, $v0
/* 0F0838 802CBE88 001080C0 */  sll   $s0, $s0, 3
/* 0F083C 802CBE8C 0C0B210B */  jal   get_float_variable
/* 0F0840 802CBE90 02038021 */   addu  $s0, $s0, $v1
/* 0F0844 802CBE94 8E250000 */  lw    $a1, ($s1)
/* 0F0848 802CBE98 26310004 */  addiu $s1, $s1, 4
/* 0F084C 802CBE9C 0240202D */  daddu $a0, $s2, $zero
/* 0F0850 802CBEA0 0C0B210B */  jal   get_float_variable
/* 0F0854 802CBEA4 46000586 */   mov.s $f22, $f0
/* 0F0858 802CBEA8 0240202D */  daddu $a0, $s2, $zero
/* 0F085C 802CBEAC 8E250000 */  lw    $a1, ($s1)
/* 0F0860 802CBEB0 0C0B210B */  jal   get_float_variable
/* 0F0864 802CBEB4 46000506 */   mov.s $f20, $f0
/* 0F0868 802CBEB8 24030001 */  addiu $v1, $zero, 1
/* 0F086C 802CBEBC E61604B0 */  swc1  $f22, 0x4b0($s0)
/* 0F0870 802CBEC0 E61404B4 */  swc1  $f20, 0x4b4($s0)
/* 0F0874 802CBEC4 E60004B8 */  swc1  $f0, 0x4b8($s0)
/* 0F0878 802CBEC8 A6030506 */  sh    $v1, 0x506($s0)
/* 0F087C 802CBECC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0880 802CBED0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0884 802CBED4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0888 802CBED8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F088C 802CBEDC D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F0890 802CBEE0 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F0894 802CBEE4 24020002 */  addiu $v0, $zero, 2
/* 0F0898 802CBEE8 03E00008 */  jr    $ra
/* 0F089C 802CBEEC 27BD0030 */   addiu $sp, $sp, 0x30


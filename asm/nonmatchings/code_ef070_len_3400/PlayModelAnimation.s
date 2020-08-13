.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel PlayModelAnimation
/* 0F181C 802CCE6C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1820 802CCE70 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F1824 802CCE74 0080882D */  daddu $s1, $a0, $zero
/* 0F1828 802CCE78 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F182C 802CCE7C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1830 802CCE80 8E30000C */  lw    $s0, 0xc($s1)
/* 0F1834 802CCE84 8E050000 */  lw    $a1, ($s0)
/* 0F1838 802CCE88 0C0B1EAF */  jal   get_variable
/* 0F183C 802CCE8C 26100004 */   addiu $s0, $s0, 4
/* 0F1840 802CCE90 0220202D */  daddu $a0, $s1, $zero
/* 0F1844 802CCE94 8E050000 */  lw    $a1, ($s0)
/* 0F1848 802CCE98 0C0B1EAF */  jal   get_variable
/* 0F184C 802CCE9C 0040802D */   daddu $s0, $v0, $zero
/* 0F1850 802CCEA0 3C03802E */  lui   $v1, 0x802e
/* 0F1854 802CCEA4 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F1858 802CCEA8 00108080 */  sll   $s0, $s0, 2
/* 0F185C 802CCEAC 02038021 */  addu  $s0, $s0, $v1
/* 0F1860 802CCEB0 8E030000 */  lw    $v1, ($s0)
/* 0F1864 802CCEB4 8C640000 */  lw    $a0, ($v1)
/* 0F1868 802CCEB8 0040282D */  daddu $a1, $v0, $zero
/* 0F186C 802CCEBC 0C048052 */  jal   play_model_animation
/* 0F1870 802CCEC0 AC650068 */   sw    $a1, 0x68($v1)
/* 0F1874 802CCEC4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F1878 802CCEC8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F187C 802CCECC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1880 802CCED0 24020002 */  addiu $v0, $zero, 2
/* 0F1884 802CCED4 03E00008 */  jr    $ra
/* 0F1888 802CCED8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F188C 802CCEDC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1890 802CCEE0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F1894 802CCEE4 0080902D */  daddu $s2, $a0, $zero
/* 0F1898 802CCEE8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F189C 802CCEEC AFB10014 */  sw    $s1, 0x14($sp)
/* 0F18A0 802CCEF0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F18A4 802CCEF4 8E50000C */  lw    $s0, 0xc($s2)
/* 0F18A8 802CCEF8 8E050000 */  lw    $a1, ($s0)
/* 0F18AC 802CCEFC 0C0B1EAF */  jal   get_variable
/* 0F18B0 802CCF00 26100004 */   addiu $s0, $s0, 4
/* 0F18B4 802CCF04 8E050000 */  lw    $a1, ($s0)
/* 0F18B8 802CCF08 26100004 */  addiu $s0, $s0, 4
/* 0F18BC 802CCF0C 0240202D */  daddu $a0, $s2, $zero
/* 0F18C0 802CCF10 0C0B1EAF */  jal   get_variable
/* 0F18C4 802CCF14 0040882D */   daddu $s1, $v0, $zero
/* 0F18C8 802CCF18 0240202D */  daddu $a0, $s2, $zero
/* 0F18CC 802CCF1C 8E050000 */  lw    $a1, ($s0)
/* 0F18D0 802CCF20 0C0B1EAF */  jal   get_variable
/* 0F18D4 802CCF24 0040802D */   daddu $s0, $v0, $zero
/* 0F18D8 802CCF28 3C03802E */  lui   $v1, 0x802e
/* 0F18DC 802CCF2C 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F18E0 802CCF30 00118880 */  sll   $s1, $s1, 2
/* 0F18E4 802CCF34 02238821 */  addu  $s1, $s1, $v1
/* 0F18E8 802CCF38 8E230000 */  lw    $v1, ($s1)
/* 0F18EC 802CCF3C 0200282D */  daddu $a1, $s0, $zero
/* 0F18F0 802CCF40 8C640000 */  lw    $a0, ($v1)
/* 0F18F4 802CCF44 0040302D */  daddu $a2, $v0, $zero
/* 0F18F8 802CCF48 0C048066 */  jal   func_80120198
/* 0F18FC 802CCF4C AC650068 */   sw    $a1, 0x68($v1)
/* 0F1900 802CCF50 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1904 802CCF54 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1908 802CCF58 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F190C 802CCF5C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1910 802CCF60 24020002 */  addiu $v0, $zero, 2
/* 0F1914 802CCF64 03E00008 */  jr    $ra
/* 0F1918 802CCF68 27BD0020 */   addiu $sp, $sp, 0x20


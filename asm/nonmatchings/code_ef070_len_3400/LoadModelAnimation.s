.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel LoadModelAnimation
/* 0F169C 802CCCEC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F16A0 802CCCF0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F16A4 802CCCF4 0080882D */  daddu $s1, $a0, $zero
/* 0F16A8 802CCCF8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F16AC 802CCCFC AFB20018 */  sw    $s2, 0x18($sp)
/* 0F16B0 802CCD00 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F16B4 802CCD04 8E30000C */  lw    $s0, 0xc($s1)
/* 0F16B8 802CCD08 8E050000 */  lw    $a1, ($s0)
/* 0F16BC 802CCD0C 0C0B1EAF */  jal   get_variable
/* 0F16C0 802CCD10 26100004 */   addiu $s0, $s0, 4
/* 0F16C4 802CCD14 0220202D */  daddu $a0, $s1, $zero
/* 0F16C8 802CCD18 8E050000 */  lw    $a1, ($s0)
/* 0F16CC 802CCD1C 0C0B1EAF */  jal   get_variable
/* 0F16D0 802CCD20 0040802D */   daddu $s0, $v0, $zero
/* 0F16D4 802CCD24 0040902D */  daddu $s2, $v0, $zero
/* 0F16D8 802CCD28 3C02802E */  lui   $v0, 0x802e
/* 0F16DC 802CCD2C 8C42AE30 */  lw    $v0, -0x51d0($v0)
/* 0F16E0 802CCD30 00108080 */  sll   $s0, $s0, 2
/* 0F16E4 802CCD34 02028021 */  addu  $s0, $s0, $v0
/* 0F16E8 802CCD38 8E100000 */  lw    $s0, ($s0)
/* 0F16EC 802CCD3C 0C04792E */  jal   func_8011E4B8
/* 0F16F0 802CCD40 0000202D */   daddu $a0, $zero, $zero
/* 0F16F4 802CCD44 0040882D */  daddu $s1, $v0, $zero
/* 0F16F8 802CCD48 0220202D */  daddu $a0, $s1, $zero
/* 0F16FC 802CCD4C 0C0480EB */  jal   func_801203AC
/* 0F1700 802CCD50 0240282D */   daddu $a1, $s2, $zero
/* 0F1704 802CCD54 3C013F80 */  lui   $at, 0x3f80
/* 0F1708 802CCD58 44810000 */  mtc1  $at, $f0
/* 0F170C 802CCD5C 26040028 */  addiu $a0, $s0, 0x28
/* 0F1710 802CCD60 AE110000 */  sw    $s1, ($s0)
/* 0F1714 802CCD64 AE000004 */  sw    $zero, 4($s0)
/* 0F1718 802CCD68 AE000008 */  sw    $zero, 8($s0)
/* 0F171C 802CCD6C AE00000C */  sw    $zero, 0xc($s0)
/* 0F1720 802CCD70 AE000010 */  sw    $zero, 0x10($s0)
/* 0F1724 802CCD74 AE000014 */  sw    $zero, 0x14($s0)
/* 0F1728 802CCD78 AE000018 */  sw    $zero, 0x18($s0)
/* 0F172C 802CCD7C E600001C */  swc1  $f0, 0x1c($s0)
/* 0F1730 802CCD80 E6000020 */  swc1  $f0, 0x20($s0)
/* 0F1734 802CCD84 E6000024 */  swc1  $f0, 0x24($s0)
/* 0F1738 802CCD88 0C019D10 */  jal   guMtxIdent
/* 0F173C 802CCD8C AE000068 */   sw    $zero, 0x68($s0)
/* 0F1740 802CCD90 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1744 802CCD94 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1748 802CCD98 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F174C 802CCD9C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1750 802CCDA0 24020002 */  addiu $v0, $zero, 2
/* 0F1754 802CCDA4 03E00008 */  jr    $ra
/* 0F1758 802CCDA8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F175C 802CCDAC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1760 802CCDB0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F1764 802CCDB4 0080882D */  daddu $s1, $a0, $zero
/* 0F1768 802CCDB8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F176C 802CCDBC AFB20018 */  sw    $s2, 0x18($sp)
/* 0F1770 802CCDC0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1774 802CCDC4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F1778 802CCDC8 8E050000 */  lw    $a1, ($s0)
/* 0F177C 802CCDCC 0C0B1EAF */  jal   get_variable
/* 0F1780 802CCDD0 26100004 */   addiu $s0, $s0, 4
/* 0F1784 802CCDD4 0220202D */  daddu $a0, $s1, $zero
/* 0F1788 802CCDD8 8E050000 */  lw    $a1, ($s0)
/* 0F178C 802CCDDC 0C0B1EAF */  jal   get_variable
/* 0F1790 802CCDE0 0040802D */   daddu $s0, $v0, $zero
/* 0F1794 802CCDE4 0040902D */  daddu $s2, $v0, $zero
/* 0F1798 802CCDE8 3C02802E */  lui   $v0, 0x802e
/* 0F179C 802CCDEC 8C42AE30 */  lw    $v0, -0x51d0($v0)
/* 0F17A0 802CCDF0 00108080 */  sll   $s0, $s0, 2
/* 0F17A4 802CCDF4 02028021 */  addu  $s0, $s0, $v0
/* 0F17A8 802CCDF8 8E100000 */  lw    $s0, ($s0)
/* 0F17AC 802CCDFC 0C04792E */  jal   func_8011E4B8
/* 0F17B0 802CCE00 0000202D */   daddu $a0, $zero, $zero
/* 0F17B4 802CCE04 0040882D */  daddu $s1, $v0, $zero
/* 0F17B8 802CCE08 0220202D */  daddu $a0, $s1, $zero
/* 0F17BC 802CCE0C 0C04811D */  jal   func_80120474
/* 0F17C0 802CCE10 0240282D */   daddu $a1, $s2, $zero
/* 0F17C4 802CCE14 3C013F80 */  lui   $at, 0x3f80
/* 0F17C8 802CCE18 44810000 */  mtc1  $at, $f0
/* 0F17CC 802CCE1C 26040028 */  addiu $a0, $s0, 0x28
/* 0F17D0 802CCE20 AE110000 */  sw    $s1, ($s0)
/* 0F17D4 802CCE24 AE000004 */  sw    $zero, 4($s0)
/* 0F17D8 802CCE28 AE000008 */  sw    $zero, 8($s0)
/* 0F17DC 802CCE2C AE00000C */  sw    $zero, 0xc($s0)
/* 0F17E0 802CCE30 AE000010 */  sw    $zero, 0x10($s0)
/* 0F17E4 802CCE34 AE000014 */  sw    $zero, 0x14($s0)
/* 0F17E8 802CCE38 AE000018 */  sw    $zero, 0x18($s0)
/* 0F17EC 802CCE3C E600001C */  swc1  $f0, 0x1c($s0)
/* 0F17F0 802CCE40 E6000020 */  swc1  $f0, 0x20($s0)
/* 0F17F4 802CCE44 E6000024 */  swc1  $f0, 0x24($s0)
/* 0F17F8 802CCE48 0C019D10 */  jal   guMtxIdent
/* 0F17FC 802CCE4C AE000068 */   sw    $zero, 0x68($s0)
/* 0F1800 802CCE50 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1804 802CCE54 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1808 802CCE58 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F180C 802CCE5C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1810 802CCE60 24020002 */  addiu $v0, $zero, 2
/* 0F1814 802CCE64 03E00008 */  jr    $ra
/* 0F1818 802CCE68 27BD0020 */   addiu $sp, $sp, 0x20


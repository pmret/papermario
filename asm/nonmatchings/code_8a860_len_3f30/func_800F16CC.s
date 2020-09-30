.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F16CC
/* 8AB7C 800F16CC 3C028011 */  lui       $v0, 0x8011
/* 8AB80 800F16D0 8042D68E */  lb        $v0, -0x2972($v0)
/* 8AB84 800F16D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8AB88 800F16D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8AB8C 800F16DC AFB20018 */  sw        $s2, 0x18($sp)
/* 8AB90 800F16E0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8AB94 800F16E4 1040002B */  beqz      $v0, .L800F1794
/* 8AB98 800F16E8 AFB00010 */   sw       $s0, 0x10($sp)
/* 8AB9C 800F16EC 3C028011 */  lui       $v0, 0x8011
/* 8ABA0 800F16F0 8C42D69C */  lw        $v0, -0x2964($v0)
/* 8ABA4 800F16F4 8C430318 */  lw        $v1, 0x318($v0)
/* 8ABA8 800F16F8 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8ABAC 800F16FC 10400020 */  beqz      $v0, .L800F1780
/* 8ABB0 800F1700 00031080 */   sll      $v0, $v1, 2
/* 8ABB4 800F1704 3C018011 */  lui       $at, 0x8011
/* 8ABB8 800F1708 00220821 */  addu      $at, $at, $v0
/* 8ABBC 800F170C 8C22C3A0 */  lw        $v0, -0x3c60($at)
/* 8ABC0 800F1710 00400008 */  jr        $v0
/* 8ABC4 800F1714 00000000 */   nop      
/* 8ABC8 800F1718 2404000E */  addiu     $a0, $zero, 0xe
/* 8ABCC 800F171C 3C108014 */  lui       $s0, %hi(D_80147474)
/* 8ABD0 800F1720 26107474 */  addiu     $s0, $s0, %lo(D_80147474)
/* 8ABD4 800F1724 0C051F9F */  jal       func_80147E7C
/* 8ABD8 800F1728 0200282D */   daddu    $a1, $s0, $zero
/* 8ABDC 800F172C 0803C5D3 */  j         .L800F174C
/* 8ABE0 800F1730 24040001 */   addiu    $a0, $zero, 1
/* 8ABE4 800F1734 2404000E */  addiu     $a0, $zero, 0xe
/* 8ABE8 800F1738 3C108014 */  lui       $s0, %hi(D_80147474)
/* 8ABEC 800F173C 26107474 */  addiu     $s0, $s0, %lo(D_80147474)
/* 8ABF0 800F1740 0C051F9F */  jal       func_80147E7C
/* 8ABF4 800F1744 0200282D */   daddu    $a1, $s0, $zero
/* 8ABF8 800F1748 24040002 */  addiu     $a0, $zero, 2
.L800F174C:
/* 8ABFC 800F174C 0C05272D */  jal       play_sound
/* 8AC00 800F1750 00000000 */   nop      
/* 8AC04 800F1754 24040013 */  addiu     $a0, $zero, 0x13
/* 8AC08 800F1758 0C051F9F */  jal       func_80147E7C
/* 8AC0C 800F175C 0200282D */   daddu    $a1, $s0, $zero
/* 8AC10 800F1760 0803C5E1 */  j         .L800F1784
/* 8AC14 800F1764 24040015 */   addiu    $a0, $zero, 0x15
/* 8AC18 800F1768 3C058014 */  lui       $a1, %hi(D_80147474)
/* 8AC1C 800F176C 24A57474 */  addiu     $a1, $a1, %lo(D_80147474)
/* 8AC20 800F1770 0C051F9F */  jal       func_80147E7C
/* 8AC24 800F1774 2404000E */   addiu    $a0, $zero, 0xe
/* 8AC28 800F1778 0C05272D */  jal       play_sound
/* 8AC2C 800F177C 24040001 */   addiu    $a0, $zero, 1
.L800F1780:
/* 8AC30 800F1780 24040015 */  addiu     $a0, $zero, 0x15
.L800F1784:
/* 8AC34 800F1784 3C058014 */  lui       $a1, %hi(D_80147474)
/* 8AC38 800F1788 24A57474 */  addiu     $a1, $a1, %lo(D_80147474)
/* 8AC3C 800F178C 0803C5FC */  j         .L800F17F0
/* 8AC40 800F1790 00000000 */   nop      
.L800F1794:
/* 8AC44 800F1794 3C028011 */  lui       $v0, 0x8011
/* 8AC48 800F1798 8C42D69C */  lw        $v0, -0x2964($v0)
/* 8AC4C 800F179C 8C430318 */  lw        $v1, 0x318($v0)
/* 8AC50 800F17A0 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8AC54 800F17A4 10400014 */  beqz      $v0, .L800F17F8
/* 8AC58 800F17A8 00031080 */   sll      $v0, $v1, 2
/* 8AC5C 800F17AC 3C018011 */  lui       $at, 0x8011
/* 8AC60 800F17B0 00220821 */  addu      $at, $at, $v0
/* 8AC64 800F17B4 8C22C3D8 */  lw        $v0, -0x3c28($at)
/* 8AC68 800F17B8 00400008 */  jr        $v0
/* 8AC6C 800F17BC 00000000 */   nop      
/* 8AC70 800F17C0 2404000E */  addiu     $a0, $zero, 0xe
/* 8AC74 800F17C4 0C051F9F */  jal       func_80147E7C
/* 8AC78 800F17C8 24050001 */   addiu    $a1, $zero, 1
/* 8AC7C 800F17CC 0803C5FB */  j         .L800F17EC
/* 8AC80 800F17D0 24040013 */   addiu    $a0, $zero, 0x13
/* 8AC84 800F17D4 2404000E */  addiu     $a0, $zero, 0xe
/* 8AC88 800F17D8 0C051F9F */  jal       func_80147E7C
/* 8AC8C 800F17DC 24050001 */   addiu    $a1, $zero, 1
/* 8AC90 800F17E0 0803C5FB */  j         .L800F17EC
/* 8AC94 800F17E4 24040013 */   addiu    $a0, $zero, 0x13
/* 8AC98 800F17E8 2404000E */  addiu     $a0, $zero, 0xe
.L800F17EC:
/* 8AC9C 800F17EC 24050001 */  addiu     $a1, $zero, 1
.L800F17F0:
/* 8ACA0 800F17F0 0C051F9F */  jal       func_80147E7C
/* 8ACA4 800F17F4 00000000 */   nop      
.L800F17F8:
/* 8ACA8 800F17F8 3C118011 */  lui       $s1, 0x8011
/* 8ACAC 800F17FC 2631D69C */  addiu     $s1, $s1, -0x2964
/* 8ACB0 800F1800 8E220000 */  lw        $v0, ($s1)
/* 8ACB4 800F1804 8C420318 */  lw        $v0, 0x318($v0)
/* 8ACB8 800F1808 24120003 */  addiu     $s2, $zero, 3
/* 8ACBC 800F180C 14520008 */  bne       $v0, $s2, .L800F1830
/* 8ACC0 800F1810 24040010 */   addiu    $a0, $zero, 0x10
/* 8ACC4 800F1814 3C108014 */  lui       $s0, %hi(D_80147474)
/* 8ACC8 800F1818 26107474 */  addiu     $s0, $s0, %lo(D_80147474)
/* 8ACCC 800F181C 0C051F9F */  jal       func_80147E7C
/* 8ACD0 800F1820 0200282D */   daddu    $a1, $s0, $zero
/* 8ACD4 800F1824 24040014 */  addiu     $a0, $zero, 0x14
/* 8ACD8 800F1828 0C051F9F */  jal       func_80147E7C
/* 8ACDC 800F182C 0200282D */   daddu    $a1, $s0, $zero
.L800F1830:
/* 8ACE0 800F1830 8E220000 */  lw        $v0, ($s1)
/* 8ACE4 800F1834 8C420318 */  lw        $v0, 0x318($v0)
/* 8ACE8 800F1838 24100004 */  addiu     $s0, $zero, 4
/* 8ACEC 800F183C 14500005 */  bne       $v0, $s0, .L800F1854
/* 8ACF0 800F1840 00000000 */   nop      
/* 8ACF4 800F1844 3C058014 */  lui       $a1, %hi(D_80147474)
/* 8ACF8 800F1848 24A57474 */  addiu     $a1, $a1, %lo(D_80147474)
/* 8ACFC 800F184C 0C051F9F */  jal       func_80147E7C
/* 8AD00 800F1850 24040012 */   addiu    $a0, $zero, 0x12
.L800F1854:
/* 8AD04 800F1854 8E220000 */  lw        $v0, ($s1)
/* 8AD08 800F1858 8C430318 */  lw        $v1, 0x318($v0)
/* 8AD0C 800F185C 24020005 */  addiu     $v0, $zero, 5
/* 8AD10 800F1860 14620006 */  bne       $v1, $v0, .L800F187C
/* 8AD14 800F1864 240500FF */   addiu    $a1, $zero, 0xff
/* 8AD18 800F1868 3C058014 */  lui       $a1, %hi(D_80147474)
/* 8AD1C 800F186C 24A57474 */  addiu     $a1, $a1, %lo(D_80147474)
/* 8AD20 800F1870 0C051F9F */  jal       func_80147E7C
/* 8AD24 800F1874 24040010 */   addiu    $a0, $zero, 0x10
/* 8AD28 800F1878 240500FF */  addiu     $a1, $zero, 0xff
.L800F187C:
/* 8AD2C 800F187C 00A0302D */  daddu     $a2, $a1, $zero
/* 8AD30 800F1880 3C048011 */  lui       $a0, 0x8011
/* 8AD34 800F1884 8C84D65C */  lw        $a0, -0x29a4($a0)
/* 8AD38 800F1888 0C0513BF */  jal       icon_set_tint
/* 8AD3C 800F188C 00A0382D */   daddu    $a3, $a1, $zero
/* 8AD40 800F1890 240500FF */  addiu     $a1, $zero, 0xff
/* 8AD44 800F1894 00A0302D */  daddu     $a2, $a1, $zero
/* 8AD48 800F1898 3C048011 */  lui       $a0, 0x8011
/* 8AD4C 800F189C 8C84D678 */  lw        $a0, -0x2988($a0)
/* 8AD50 800F18A0 0C0513BF */  jal       icon_set_tint
/* 8AD54 800F18A4 00A0382D */   daddu    $a3, $a1, $zero
/* 8AD58 800F18A8 240500FF */  addiu     $a1, $zero, 0xff
/* 8AD5C 800F18AC 00A0302D */  daddu     $a2, $a1, $zero
/* 8AD60 800F18B0 3C048011 */  lui       $a0, 0x8011
/* 8AD64 800F18B4 8C84D66C */  lw        $a0, -0x2994($a0)
/* 8AD68 800F18B8 0C0513BF */  jal       icon_set_tint
/* 8AD6C 800F18BC 00A0382D */   daddu    $a3, $a1, $zero
/* 8AD70 800F18C0 240500FF */  addiu     $a1, $zero, 0xff
/* 8AD74 800F18C4 00A0302D */  daddu     $a2, $a1, $zero
/* 8AD78 800F18C8 3C048011 */  lui       $a0, 0x8011
/* 8AD7C 800F18CC 8C84D670 */  lw        $a0, -0x2990($a0)
/* 8AD80 800F18D0 0C0513BF */  jal       icon_set_tint
/* 8AD84 800F18D4 00A0382D */   daddu    $a3, $a1, $zero
/* 8AD88 800F18D8 240500FF */  addiu     $a1, $zero, 0xff
/* 8AD8C 800F18DC 00A0302D */  daddu     $a2, $a1, $zero
/* 8AD90 800F18E0 3C048011 */  lui       $a0, 0x8011
/* 8AD94 800F18E4 8C84D674 */  lw        $a0, -0x298c($a0)
/* 8AD98 800F18E8 0C0513BF */  jal       icon_set_tint
/* 8AD9C 800F18EC 00A0382D */   daddu    $a3, $a1, $zero
/* 8ADA0 800F18F0 8E220000 */  lw        $v0, ($s1)
/* 8ADA4 800F18F4 8C420318 */  lw        $v0, 0x318($v0)
/* 8ADA8 800F18F8 1452000C */  bne       $v0, $s2, .L800F192C
/* 8ADAC 800F18FC 240500FF */   addiu    $a1, $zero, 0xff
/* 8ADB0 800F1900 00A0302D */  daddu     $a2, $a1, $zero
/* 8ADB4 800F1904 3C048011 */  lui       $a0, 0x8011
/* 8ADB8 800F1908 8C84D660 */  lw        $a0, -0x29a0($a0)
/* 8ADBC 800F190C 0C0513BF */  jal       icon_set_tint
/* 8ADC0 800F1910 00A0382D */   daddu    $a3, $a1, $zero
/* 8ADC4 800F1914 240500FF */  addiu     $a1, $zero, 0xff
/* 8ADC8 800F1918 00A0302D */  daddu     $a2, $a1, $zero
/* 8ADCC 800F191C 3C048011 */  lui       $a0, 0x8011
/* 8ADD0 800F1920 8C84D664 */  lw        $a0, -0x299c($a0)
/* 8ADD4 800F1924 0C0513BF */  jal       icon_set_tint
/* 8ADD8 800F1928 00A0382D */   daddu    $a3, $a1, $zero
.L800F192C:
/* 8ADDC 800F192C 8E220000 */  lw        $v0, ($s1)
/* 8ADE0 800F1930 8C420318 */  lw        $v0, 0x318($v0)
/* 8ADE4 800F1934 1450000C */  bne       $v0, $s0, .L800F1968
/* 8ADE8 800F1938 240500FF */   addiu    $a1, $zero, 0xff
/* 8ADEC 800F193C 00A0302D */  daddu     $a2, $a1, $zero
/* 8ADF0 800F1940 3C048011 */  lui       $a0, 0x8011
/* 8ADF4 800F1944 8C84D660 */  lw        $a0, -0x29a0($a0)
/* 8ADF8 800F1948 0C0513BF */  jal       icon_set_tint
/* 8ADFC 800F194C 00A0382D */   daddu    $a3, $a1, $zero
/* 8AE00 800F1950 240500FF */  addiu     $a1, $zero, 0xff
/* 8AE04 800F1954 00A0302D */  daddu     $a2, $a1, $zero
/* 8AE08 800F1958 3C048011 */  lui       $a0, 0x8011
/* 8AE0C 800F195C 8C84D664 */  lw        $a0, -0x299c($a0)
/* 8AE10 800F1960 0C0513BF */  jal       icon_set_tint
/* 8AE14 800F1964 00A0382D */   daddu    $a3, $a1, $zero
.L800F1968:
/* 8AE18 800F1968 8E220000 */  lw        $v0, ($s1)
/* 8AE1C 800F196C 8C430318 */  lw        $v1, 0x318($v0)
/* 8AE20 800F1970 24020001 */  addiu     $v0, $zero, 1
/* 8AE24 800F1974 10620003 */  beq       $v1, $v0, .L800F1984
/* 8AE28 800F1978 00000000 */   nop      
/* 8AE2C 800F197C 14700007 */  bne       $v1, $s0, .L800F199C
/* 8AE30 800F1980 00000000 */   nop      
.L800F1984:
/* 8AE34 800F1984 3C048011 */  lui       $a0, 0x8011
/* 8AE38 800F1988 8C84D668 */  lw        $a0, -0x2998($a0)
/* 8AE3C 800F198C 240500FF */  addiu     $a1, $zero, 0xff
/* 8AE40 800F1990 00A0302D */  daddu     $a2, $a1, $zero
/* 8AE44 800F1994 0C0513BF */  jal       icon_set_tint
/* 8AE48 800F1998 00A0382D */   daddu    $a3, $a1, $zero
.L800F199C:
/* 8AE4C 800F199C 3C028011 */  lui       $v0, 0x8011
/* 8AE50 800F19A0 8C42D69C */  lw        $v0, -0x2964($v0)
/* 8AE54 800F19A4 8C430318 */  lw        $v1, 0x318($v0)
/* 8AE58 800F19A8 24020005 */  addiu     $v0, $zero, 5
/* 8AE5C 800F19AC 14620006 */  bne       $v1, $v0, .L800F19C8
/* 8AE60 800F19B0 240500FF */   addiu    $a1, $zero, 0xff
/* 8AE64 800F19B4 3C048011 */  lui       $a0, 0x8011
/* 8AE68 800F19B8 8C84D660 */  lw        $a0, -0x29a0($a0)
/* 8AE6C 800F19BC 00A0302D */  daddu     $a2, $a1, $zero
/* 8AE70 800F19C0 0C0513BF */  jal       icon_set_tint
/* 8AE74 800F19C4 00A0382D */   daddu    $a3, $a1, $zero
.L800F19C8:
/* 8AE78 800F19C8 3C048011 */  lui       $a0, 0x8011
/* 8AE7C 800F19CC 8C84D66C */  lw        $a0, -0x2994($a0)
/* 8AE80 800F19D0 3C058010 */  lui       $a1, 0x8010
/* 8AE84 800F19D4 24A54A28 */  addiu     $a1, $a1, 0x4a28
/* 8AE88 800F19D8 0C0511FF */  jal       set_menu_icon_script
/* 8AE8C 800F19DC 00000000 */   nop      
/* 8AE90 800F19E0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8AE94 800F19E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 8AE98 800F19E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 8AE9C 800F19EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8AEA0 800F19F0 2402000A */  addiu     $v0, $zero, 0xa
/* 8AEA4 800F19F4 3C018011 */  lui       $at, 0x8011
/* 8AEA8 800F19F8 A022D690 */  sb        $v0, -0x2970($at)
/* 8AEAC 800F19FC 24020014 */  addiu     $v0, $zero, 0x14
/* 8AEB0 800F1A00 3C018011 */  lui       $at, 0x8011
/* 8AEB4 800F1A04 AC22D640 */  sw        $v0, -0x29c0($at)
/* 8AEB8 800F1A08 03E00008 */  jr        $ra
/* 8AEBC 800F1A0C 27BD0020 */   addiu    $sp, $sp, 0x20

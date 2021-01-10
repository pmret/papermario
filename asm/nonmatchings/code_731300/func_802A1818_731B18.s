.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1818_731B18
/* 731B18 802A1818 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 731B1C 802A181C AFB1001C */  sw        $s1, 0x1c($sp)
/* 731B20 802A1820 0080882D */  daddu     $s1, $a0, $zero
/* 731B24 802A1824 AFBF0028 */  sw        $ra, 0x28($sp)
/* 731B28 802A1828 AFB30024 */  sw        $s3, 0x24($sp)
/* 731B2C 802A182C AFB20020 */  sw        $s2, 0x20($sp)
/* 731B30 802A1830 AFB00018 */  sw        $s0, 0x18($sp)
/* 731B34 802A1834 8E30000C */  lw        $s0, 0xc($s1)
/* 731B38 802A1838 8E050000 */  lw        $a1, ($s0)
/* 731B3C 802A183C 0C0B1EAF */  jal       get_variable
/* 731B40 802A1840 26100004 */   addiu    $s0, $s0, 4
/* 731B44 802A1844 8E050000 */  lw        $a1, ($s0)
/* 731B48 802A1848 26100004 */  addiu     $s0, $s0, 4
/* 731B4C 802A184C 0220202D */  daddu     $a0, $s1, $zero
/* 731B50 802A1850 0C0B1EAF */  jal       get_variable
/* 731B54 802A1854 0040982D */   daddu    $s3, $v0, $zero
/* 731B58 802A1858 8E050000 */  lw        $a1, ($s0)
/* 731B5C 802A185C 26100004 */  addiu     $s0, $s0, 4
/* 731B60 802A1860 0220202D */  daddu     $a0, $s1, $zero
/* 731B64 802A1864 0C0B1EAF */  jal       get_variable
/* 731B68 802A1868 0040902D */   daddu    $s2, $v0, $zero
/* 731B6C 802A186C 0220202D */  daddu     $a0, $s1, $zero
/* 731B70 802A1870 8E050000 */  lw        $a1, ($s0)
/* 731B74 802A1874 0C0B1EAF */  jal       get_variable
/* 731B78 802A1878 0040802D */   daddu    $s0, $v0, $zero
/* 731B7C 802A187C 44930000 */  mtc1      $s3, $f0
/* 731B80 802A1880 00000000 */  nop       
/* 731B84 802A1884 46800020 */  cvt.s.w   $f0, $f0
/* 731B88 802A1888 44050000 */  mfc1      $a1, $f0
/* 731B8C 802A188C 44920000 */  mtc1      $s2, $f0
/* 731B90 802A1890 00000000 */  nop       
/* 731B94 802A1894 46800020 */  cvt.s.w   $f0, $f0
/* 731B98 802A1898 44060000 */  mfc1      $a2, $f0
/* 731B9C 802A189C 44900000 */  mtc1      $s0, $f0
/* 731BA0 802A18A0 00000000 */  nop       
/* 731BA4 802A18A4 46800020 */  cvt.s.w   $f0, $f0
/* 731BA8 802A18A8 44070000 */  mfc1      $a3, $f0
/* 731BAC 802A18AC 0000202D */  daddu     $a0, $zero, $zero
/* 731BB0 802A18B0 0C01C424 */  jal       func_80071090
/* 731BB4 802A18B4 AFA20010 */   sw       $v0, 0x10($sp)
/* 731BB8 802A18B8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 731BBC 802A18BC 8FB30024 */  lw        $s3, 0x24($sp)
/* 731BC0 802A18C0 8FB20020 */  lw        $s2, 0x20($sp)
/* 731BC4 802A18C4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 731BC8 802A18C8 8FB00018 */  lw        $s0, 0x18($sp)
/* 731BCC 802A18CC 24020002 */  addiu     $v0, $zero, 2
/* 731BD0 802A18D0 03E00008 */  jr        $ra
/* 731BD4 802A18D4 27BD0030 */   addiu    $sp, $sp, 0x30

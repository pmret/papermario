.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A18D8_731BD8
/* 731BD8 802A18D8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 731BDC 802A18DC AFB1001C */  sw        $s1, 0x1c($sp)
/* 731BE0 802A18E0 0080882D */  daddu     $s1, $a0, $zero
/* 731BE4 802A18E4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 731BE8 802A18E8 AFB30024 */  sw        $s3, 0x24($sp)
/* 731BEC 802A18EC AFB20020 */  sw        $s2, 0x20($sp)
/* 731BF0 802A18F0 AFB00018 */  sw        $s0, 0x18($sp)
/* 731BF4 802A18F4 8E30000C */  lw        $s0, 0xc($s1)
/* 731BF8 802A18F8 8E050000 */  lw        $a1, ($s0)
/* 731BFC 802A18FC 0C0B1EAF */  jal       get_variable
/* 731C00 802A1900 26100004 */   addiu    $s0, $s0, 4
/* 731C04 802A1904 8E050000 */  lw        $a1, ($s0)
/* 731C08 802A1908 26100004 */  addiu     $s0, $s0, 4
/* 731C0C 802A190C 0220202D */  daddu     $a0, $s1, $zero
/* 731C10 802A1910 0C0B1EAF */  jal       get_variable
/* 731C14 802A1914 0040982D */   daddu    $s3, $v0, $zero
/* 731C18 802A1918 8E050000 */  lw        $a1, ($s0)
/* 731C1C 802A191C 26100004 */  addiu     $s0, $s0, 4
/* 731C20 802A1920 0220202D */  daddu     $a0, $s1, $zero
/* 731C24 802A1924 0C0B1EAF */  jal       get_variable
/* 731C28 802A1928 0040902D */   daddu    $s2, $v0, $zero
/* 731C2C 802A192C 0220202D */  daddu     $a0, $s1, $zero
/* 731C30 802A1930 8E050000 */  lw        $a1, ($s0)
/* 731C34 802A1934 0C0B1EAF */  jal       get_variable
/* 731C38 802A1938 0040802D */   daddu    $s0, $v0, $zero
/* 731C3C 802A193C 44930000 */  mtc1      $s3, $f0
/* 731C40 802A1940 00000000 */  nop       
/* 731C44 802A1944 46800020 */  cvt.s.w   $f0, $f0
/* 731C48 802A1948 44050000 */  mfc1      $a1, $f0
/* 731C4C 802A194C 44920000 */  mtc1      $s2, $f0
/* 731C50 802A1950 00000000 */  nop       
/* 731C54 802A1954 46800020 */  cvt.s.w   $f0, $f0
/* 731C58 802A1958 44060000 */  mfc1      $a2, $f0
/* 731C5C 802A195C 44900000 */  mtc1      $s0, $f0
/* 731C60 802A1960 00000000 */  nop       
/* 731C64 802A1964 46800020 */  cvt.s.w   $f0, $f0
/* 731C68 802A1968 44070000 */  mfc1      $a3, $f0
/* 731C6C 802A196C 24040001 */  addiu     $a0, $zero, 1
/* 731C70 802A1970 0C01C424 */  jal       func_80071090
/* 731C74 802A1974 AFA20010 */   sw       $v0, 0x10($sp)
/* 731C78 802A1978 8FBF0028 */  lw        $ra, 0x28($sp)
/* 731C7C 802A197C 8FB30024 */  lw        $s3, 0x24($sp)
/* 731C80 802A1980 8FB20020 */  lw        $s2, 0x20($sp)
/* 731C84 802A1984 8FB1001C */  lw        $s1, 0x1c($sp)
/* 731C88 802A1988 8FB00018 */  lw        $s0, 0x18($sp)
/* 731C8C 802A198C 24020002 */  addiu     $v0, $zero, 2
/* 731C90 802A1990 03E00008 */  jr        $ra
/* 731C94 802A1994 27BD0030 */   addiu    $sp, $sp, 0x30

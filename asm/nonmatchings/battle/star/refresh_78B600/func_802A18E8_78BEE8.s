.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A18E8_78BEE8
/* 78BEE8 802A18E8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 78BEEC 802A18EC AFB1001C */  sw        $s1, 0x1c($sp)
/* 78BEF0 802A18F0 0080882D */  daddu     $s1, $a0, $zero
/* 78BEF4 802A18F4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 78BEF8 802A18F8 AFB30024 */  sw        $s3, 0x24($sp)
/* 78BEFC 802A18FC AFB20020 */  sw        $s2, 0x20($sp)
/* 78BF00 802A1900 AFB00018 */  sw        $s0, 0x18($sp)
/* 78BF04 802A1904 8E30000C */  lw        $s0, 0xc($s1)
/* 78BF08 802A1908 8E050000 */  lw        $a1, ($s0)
/* 78BF0C 802A190C 0C0B1EAF */  jal       get_variable
/* 78BF10 802A1910 26100004 */   addiu    $s0, $s0, 4
/* 78BF14 802A1914 8E050000 */  lw        $a1, ($s0)
/* 78BF18 802A1918 26100004 */  addiu     $s0, $s0, 4
/* 78BF1C 802A191C 0220202D */  daddu     $a0, $s1, $zero
/* 78BF20 802A1920 0C0B1EAF */  jal       get_variable
/* 78BF24 802A1924 0040982D */   daddu    $s3, $v0, $zero
/* 78BF28 802A1928 8E050000 */  lw        $a1, ($s0)
/* 78BF2C 802A192C 26100004 */  addiu     $s0, $s0, 4
/* 78BF30 802A1930 0220202D */  daddu     $a0, $s1, $zero
/* 78BF34 802A1934 0C0B1EAF */  jal       get_variable
/* 78BF38 802A1938 0040902D */   daddu    $s2, $v0, $zero
/* 78BF3C 802A193C 0220202D */  daddu     $a0, $s1, $zero
/* 78BF40 802A1940 8E050000 */  lw        $a1, ($s0)
/* 78BF44 802A1944 0C0B1EAF */  jal       get_variable
/* 78BF48 802A1948 0040802D */   daddu    $s0, $v0, $zero
/* 78BF4C 802A194C 44930000 */  mtc1      $s3, $f0
/* 78BF50 802A1950 00000000 */  nop
/* 78BF54 802A1954 46800020 */  cvt.s.w   $f0, $f0
/* 78BF58 802A1958 44050000 */  mfc1      $a1, $f0
/* 78BF5C 802A195C 44920000 */  mtc1      $s2, $f0
/* 78BF60 802A1960 00000000 */  nop
/* 78BF64 802A1964 46800020 */  cvt.s.w   $f0, $f0
/* 78BF68 802A1968 44060000 */  mfc1      $a2, $f0
/* 78BF6C 802A196C 44900000 */  mtc1      $s0, $f0
/* 78BF70 802A1970 00000000 */  nop
/* 78BF74 802A1974 46800020 */  cvt.s.w   $f0, $f0
/* 78BF78 802A1978 44070000 */  mfc1      $a3, $f0
/* 78BF7C 802A197C 0000202D */  daddu     $a0, $zero, $zero
/* 78BF80 802A1980 0C01C424 */  jal       func_80071090
/* 78BF84 802A1984 AFA20010 */   sw       $v0, 0x10($sp)
/* 78BF88 802A1988 8FBF0028 */  lw        $ra, 0x28($sp)
/* 78BF8C 802A198C 8FB30024 */  lw        $s3, 0x24($sp)
/* 78BF90 802A1990 8FB20020 */  lw        $s2, 0x20($sp)
/* 78BF94 802A1994 8FB1001C */  lw        $s1, 0x1c($sp)
/* 78BF98 802A1998 8FB00018 */  lw        $s0, 0x18($sp)
/* 78BF9C 802A199C 24020002 */  addiu     $v0, $zero, 2
/* 78BFA0 802A19A0 03E00008 */  jr        $ra
/* 78BFA4 802A19A4 27BD0030 */   addiu    $sp, $sp, 0x30

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A188C_72CE3C
/* 72CE3C 802A188C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 72CE40 802A1890 AFB10024 */  sw        $s1, 0x24($sp)
/* 72CE44 802A1894 0080882D */  daddu     $s1, $a0, $zero
/* 72CE48 802A1898 AFBF002C */  sw        $ra, 0x2c($sp)
/* 72CE4C 802A189C AFB20028 */  sw        $s2, 0x28($sp)
/* 72CE50 802A18A0 AFB00020 */  sw        $s0, 0x20($sp)
/* 72CE54 802A18A4 8E30000C */  lw        $s0, 0xc($s1)
/* 72CE58 802A18A8 8E050000 */  lw        $a1, ($s0)
/* 72CE5C 802A18AC 0C0B1EAF */  jal       get_variable
/* 72CE60 802A18B0 26100004 */   addiu    $s0, $s0, 4
/* 72CE64 802A18B4 8E050000 */  lw        $a1, ($s0)
/* 72CE68 802A18B8 26100004 */  addiu     $s0, $s0, 4
/* 72CE6C 802A18BC 0220202D */  daddu     $a0, $s1, $zero
/* 72CE70 802A18C0 0C0B1EAF */  jal       get_variable
/* 72CE74 802A18C4 0040902D */   daddu    $s2, $v0, $zero
/* 72CE78 802A18C8 0220202D */  daddu     $a0, $s1, $zero
/* 72CE7C 802A18CC 8E050000 */  lw        $a1, ($s0)
/* 72CE80 802A18D0 0C0B1EAF */  jal       get_variable
/* 72CE84 802A18D4 0040802D */   daddu    $s0, $v0, $zero
/* 72CE88 802A18D8 24040002 */  addiu     $a0, $zero, 2
/* 72CE8C 802A18DC 44921000 */  mtc1      $s2, $f2
/* 72CE90 802A18E0 00000000 */  nop
/* 72CE94 802A18E4 468010A0 */  cvt.s.w   $f2, $f2
/* 72CE98 802A18E8 44051000 */  mfc1      $a1, $f2
/* 72CE9C 802A18EC 44901000 */  mtc1      $s0, $f2
/* 72CEA0 802A18F0 00000000 */  nop
/* 72CEA4 802A18F4 468010A0 */  cvt.s.w   $f2, $f2
/* 72CEA8 802A18F8 44061000 */  mfc1      $a2, $f2
/* 72CEAC 802A18FC 44821000 */  mtc1      $v0, $f2
/* 72CEB0 802A1900 00000000 */  nop
/* 72CEB4 802A1904 468010A0 */  cvt.s.w   $f2, $f2
/* 72CEB8 802A1908 3C01BF80 */  lui       $at, 0xbf80
/* 72CEBC 802A190C 44810000 */  mtc1      $at, $f0
/* 72CEC0 802A1910 44071000 */  mfc1      $a3, $f2
/* 72CEC4 802A1914 24030005 */  addiu     $v1, $zero, 5
/* 72CEC8 802A1918 AFA00010 */  sw        $zero, 0x10($sp)
/* 72CECC 802A191C AFA00018 */  sw        $zero, 0x18($sp)
/* 72CED0 802A1920 AFA3001C */  sw        $v1, 0x1c($sp)
/* 72CED4 802A1924 0C01C064 */  jal       func_80070190
/* 72CED8 802A1928 E7A00014 */   swc1     $f0, 0x14($sp)
/* 72CEDC 802A192C 8FBF002C */  lw        $ra, 0x2c($sp)
/* 72CEE0 802A1930 8FB20028 */  lw        $s2, 0x28($sp)
/* 72CEE4 802A1934 8FB10024 */  lw        $s1, 0x24($sp)
/* 72CEE8 802A1938 8FB00020 */  lw        $s0, 0x20($sp)
/* 72CEEC 802A193C 24020002 */  addiu     $v0, $zero, 2
/* 72CEF0 802A1940 03E00008 */  jr        $ra
/* 72CEF4 802A1944 27BD0030 */   addiu    $sp, $sp, 0x30
/* 72CEF8 802A1948 00000000 */  nop
/* 72CEFC 802A194C 00000000 */  nop

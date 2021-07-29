.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242908_9D9928
/* 9D9928 80242908 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D992C 8024290C 3C058025 */  lui       $a1, %hi(D_802549B8)
/* 9D9930 80242910 8CA549B8 */  lw        $a1, %lo(D_802549B8)($a1)
/* 9D9934 80242914 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D9938 80242918 0C0B1EAF */  jal       get_variable
/* 9D993C 8024291C 0000202D */   daddu    $a0, $zero, $zero
/* 9D9940 80242920 0040182D */  daddu     $v1, $v0, $zero
/* 9D9944 80242924 24020001 */  addiu     $v0, $zero, 1
/* 9D9948 80242928 14620006 */  bne       $v1, $v0, .L80242944
/* 9D994C 8024292C 24020002 */   addiu    $v0, $zero, 2
/* 9D9950 80242930 44800000 */  mtc1      $zero, $f0
/* 9D9954 80242934 00000000 */  nop
/* 9D9958 80242938 44050000 */  mfc1      $a1, $f0
/* 9D995C 8024293C 08090A57 */  j         .L8024295C
/* 9D9960 80242940 0000202D */   daddu    $a0, $zero, $zero
.L80242944:
/* 9D9964 80242944 14620008 */  bne       $v1, $v0, .L80242968
/* 9D9968 80242948 24040001 */   addiu    $a0, $zero, 1
/* 9D996C 8024294C 44800000 */  mtc1      $zero, $f0
/* 9D9970 80242950 00000000 */  nop
/* 9D9974 80242954 44050000 */  mfc1      $a1, $f0
/* 9D9978 80242958 00000000 */  nop
.L8024295C:
/* 9D997C 8024295C 00A0302D */  daddu     $a2, $a1, $zero
/* 9D9980 80242960 0C01C5A4 */  jal       playFX_50
/* 9D9984 80242964 00A0382D */   daddu    $a3, $a1, $zero
.L80242968:
/* 9D9988 80242968 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D998C 8024296C 03E00008 */  jr        $ra
/* 9D9990 80242970 27BD0018 */   addiu    $sp, $sp, 0x18

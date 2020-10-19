.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242930
/* 9C7D10 80242930 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9C7D14 80242934 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 9C7D18 80242938 4485A000 */  mtc1      $a1, $f20
/* 9C7D1C 8024293C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 9C7D20 80242940 4486B000 */  mtc1      $a2, $f22
/* 9C7D24 80242944 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C7D28 80242948 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 9C7D2C 8024294C 4487C000 */  mtc1      $a3, $f24
/* 9C7D30 80242950 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9C7D34 80242954 0C019D28 */  jal       guMtxIdentF
/* 9C7D38 80242958 0080802D */   daddu    $s0, $a0, $zero
/* 9C7D3C 8024295C 4616A582 */  mul.s     $f22, $f20, $f22
/* 9C7D40 80242960 00000000 */  nop       
/* 9C7D44 80242964 4618A502 */  mul.s     $f20, $f20, $f24
/* 9C7D48 80242968 00000000 */  nop       
/* 9C7D4C 8024296C 3C013F80 */  lui       $at, 0x3f80
/* 9C7D50 80242970 44810000 */  mtc1      $at, $f0
/* 9C7D54 80242974 00000000 */  nop       
/* 9C7D58 80242978 E6000014 */  swc1      $f0, 0x14($s0)
/* 9C7D5C 8024297C E6160010 */  swc1      $f22, 0x10($s0)
/* 9C7D60 80242980 E6140018 */  swc1      $f20, 0x18($s0)
/* 9C7D64 80242984 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9C7D68 80242988 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C7D6C 8024298C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 9C7D70 80242990 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 9C7D74 80242994 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 9C7D78 80242998 03E00008 */  jr        $ra
/* 9C7D7C 8024299C 27BD0030 */   addiu    $sp, $sp, 0x30

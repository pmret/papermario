.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242078
/* 7ECD88 80242078 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 7ECD8C 8024207C AFB10014 */  sw        $s1, 0x14($sp)
/* 7ECD90 80242080 0080882D */  daddu     $s1, $a0, $zero
/* 7ECD94 80242084 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7ECD98 80242088 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECD9C 8024208C F7B80030 */  sdc1      $f24, 0x30($sp)
/* 7ECDA0 80242090 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 7ECDA4 80242094 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 7ECDA8 80242098 8E30000C */  lw        $s0, 0xc($s1)
/* 7ECDAC 8024209C 8E050000 */  lw        $a1, ($s0)
/* 7ECDB0 802420A0 0C0B1EAF */  jal       get_variable
/* 7ECDB4 802420A4 26100004 */   addiu    $s0, $s0, 4
/* 7ECDB8 802420A8 8E050000 */  lw        $a1, ($s0)
/* 7ECDBC 802420AC 26100004 */  addiu     $s0, $s0, 4
/* 7ECDC0 802420B0 4482C000 */  mtc1      $v0, $f24
/* 7ECDC4 802420B4 00000000 */  nop       
/* 7ECDC8 802420B8 4680C620 */  cvt.s.w   $f24, $f24
/* 7ECDCC 802420BC 0C0B1EAF */  jal       get_variable
/* 7ECDD0 802420C0 0220202D */   daddu    $a0, $s1, $zero
/* 7ECDD4 802420C4 8E050000 */  lw        $a1, ($s0)
/* 7ECDD8 802420C8 26100004 */  addiu     $s0, $s0, 4
/* 7ECDDC 802420CC 4482B000 */  mtc1      $v0, $f22
/* 7ECDE0 802420D0 00000000 */  nop       
/* 7ECDE4 802420D4 4680B5A0 */  cvt.s.w   $f22, $f22
/* 7ECDE8 802420D8 0C0B1EAF */  jal       get_variable
/* 7ECDEC 802420DC 0220202D */   daddu    $a0, $s1, $zero
/* 7ECDF0 802420E0 8E050000 */  lw        $a1, ($s0)
/* 7ECDF4 802420E4 4482A000 */  mtc1      $v0, $f20
/* 7ECDF8 802420E8 00000000 */  nop       
/* 7ECDFC 802420EC 4680A520 */  cvt.s.w   $f20, $f20
/* 7ECE00 802420F0 0C0B1EAF */  jal       get_variable
/* 7ECE04 802420F4 0220202D */   daddu    $a0, $s1, $zero
/* 7ECE08 802420F8 44820000 */  mtc1      $v0, $f0
/* 7ECE0C 802420FC 00000000 */  nop       
/* 7ECE10 80242100 46800020 */  cvt.s.w   $f0, $f0
/* 7ECE14 80242104 46160001 */  sub.s     $f0, $f0, $f22
/* 7ECE18 80242108 4618A501 */  sub.s     $f20, $f20, $f24
/* 7ECE1C 8024210C 46140003 */  div.s     $f0, $f0, $f20
/* 7ECE20 80242110 46180602 */  mul.s     $f24, $f0, $f24
/* 7ECE24 80242114 00000000 */  nop       
/* 7ECE28 80242118 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 7ECE2C 8024211C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 7ECE30 80242120 C4420028 */  lwc1      $f2, 0x28($v0)
/* 7ECE34 80242124 46020002 */  mul.s     $f0, $f0, $f2
/* 7ECE38 80242128 00000000 */  nop       
/* 7ECE3C 8024212C 4618B581 */  sub.s     $f22, $f22, $f24
/* 7ECE40 80242130 46160000 */  add.s     $f0, $f0, $f22
/* 7ECE44 80242134 C4420030 */  lwc1      $f2, 0x30($v0)
/* 7ECE48 80242138 4600103C */  c.lt.s    $f2, $f0
/* 7ECE4C 8024213C 00000000 */  nop       
/* 7ECE50 80242140 45000003 */  bc1f      .L80242150
/* 7ECE54 80242144 24020001 */   addiu    $v0, $zero, 1
/* 7ECE58 80242148 08090855 */  j         .L80242154
/* 7ECE5C 8024214C AE200084 */   sw       $zero, 0x84($s1)
.L80242150:
/* 7ECE60 80242150 AE220084 */  sw        $v0, 0x84($s1)
.L80242154:
/* 7ECE64 80242154 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7ECE68 80242158 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ECE6C 8024215C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECE70 80242160 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 7ECE74 80242164 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 7ECE78 80242168 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 7ECE7C 8024216C 24020002 */  addiu     $v0, $zero, 2
/* 7ECE80 80242170 03E00008 */  jr        $ra
/* 7ECE84 80242174 27BD0038 */   addiu    $sp, $sp, 0x38

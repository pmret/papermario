.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A19A8_78BFA8
/* 78BFA8 802A19A8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 78BFAC 802A19AC AFB1001C */  sw        $s1, 0x1c($sp)
/* 78BFB0 802A19B0 0080882D */  daddu     $s1, $a0, $zero
/* 78BFB4 802A19B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 78BFB8 802A19B8 AFB30024 */  sw        $s3, 0x24($sp)
/* 78BFBC 802A19BC AFB20020 */  sw        $s2, 0x20($sp)
/* 78BFC0 802A19C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 78BFC4 802A19C4 8E30000C */  lw        $s0, 0xc($s1)
/* 78BFC8 802A19C8 8E050000 */  lw        $a1, ($s0)
/* 78BFCC 802A19CC 0C0B1EAF */  jal       get_variable
/* 78BFD0 802A19D0 26100004 */   addiu    $s0, $s0, 4
/* 78BFD4 802A19D4 8E050000 */  lw        $a1, ($s0)
/* 78BFD8 802A19D8 26100004 */  addiu     $s0, $s0, 4
/* 78BFDC 802A19DC 0220202D */  daddu     $a0, $s1, $zero
/* 78BFE0 802A19E0 0C0B1EAF */  jal       get_variable
/* 78BFE4 802A19E4 0040982D */   daddu    $s3, $v0, $zero
/* 78BFE8 802A19E8 8E050000 */  lw        $a1, ($s0)
/* 78BFEC 802A19EC 26100004 */  addiu     $s0, $s0, 4
/* 78BFF0 802A19F0 0220202D */  daddu     $a0, $s1, $zero
/* 78BFF4 802A19F4 0C0B1EAF */  jal       get_variable
/* 78BFF8 802A19F8 0040902D */   daddu    $s2, $v0, $zero
/* 78BFFC 802A19FC 0220202D */  daddu     $a0, $s1, $zero
/* 78C000 802A1A00 8E050000 */  lw        $a1, ($s0)
/* 78C004 802A1A04 0C0B1EAF */  jal       get_variable
/* 78C008 802A1A08 0040802D */   daddu    $s0, $v0, $zero
/* 78C00C 802A1A0C 44930000 */  mtc1      $s3, $f0
/* 78C010 802A1A10 00000000 */  nop
/* 78C014 802A1A14 46800020 */  cvt.s.w   $f0, $f0
/* 78C018 802A1A18 44050000 */  mfc1      $a1, $f0
/* 78C01C 802A1A1C 44920000 */  mtc1      $s2, $f0
/* 78C020 802A1A20 00000000 */  nop
/* 78C024 802A1A24 46800020 */  cvt.s.w   $f0, $f0
/* 78C028 802A1A28 44060000 */  mfc1      $a2, $f0
/* 78C02C 802A1A2C 44900000 */  mtc1      $s0, $f0
/* 78C030 802A1A30 00000000 */  nop
/* 78C034 802A1A34 46800020 */  cvt.s.w   $f0, $f0
/* 78C038 802A1A38 44070000 */  mfc1      $a3, $f0
/* 78C03C 802A1A3C 24040001 */  addiu     $a0, $zero, 1
/* 78C040 802A1A40 0C01C424 */  jal       playFX_40
/* 78C044 802A1A44 AFA20010 */   sw       $v0, 0x10($sp)
/* 78C048 802A1A48 8FBF0028 */  lw        $ra, 0x28($sp)
/* 78C04C 802A1A4C 8FB30024 */  lw        $s3, 0x24($sp)
/* 78C050 802A1A50 8FB20020 */  lw        $s2, 0x20($sp)
/* 78C054 802A1A54 8FB1001C */  lw        $s1, 0x1c($sp)
/* 78C058 802A1A58 8FB00018 */  lw        $s0, 0x18($sp)
/* 78C05C 802A1A5C 24020002 */  addiu     $v0, $zero, 2
/* 78C060 802A1A60 03E00008 */  jr        $ra
/* 78C064 802A1A64 27BD0030 */   addiu    $sp, $sp, 0x30
/* 78C068 802A1A68 00000000 */  nop
/* 78C06C 802A1A6C 00000000 */  nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218224_59E904
/* 59E904 80218224 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 59E908 80218228 AFB10014 */  sw        $s1, 0x14($sp)
/* 59E90C 8021822C 0080882D */  daddu     $s1, $a0, $zero
/* 59E910 80218230 AFBF0020 */  sw        $ra, 0x20($sp)
/* 59E914 80218234 AFB3001C */  sw        $s3, 0x1c($sp)
/* 59E918 80218238 AFB20018 */  sw        $s2, 0x18($sp)
/* 59E91C 8021823C AFB00010 */  sw        $s0, 0x10($sp)
/* 59E920 80218240 8E30000C */  lw        $s0, 0xc($s1)
/* 59E924 80218244 8E050000 */  lw        $a1, ($s0)
/* 59E928 80218248 0C0B1EAF */  jal       get_variable
/* 59E92C 8021824C 26100004 */   addiu    $s0, $s0, 4
/* 59E930 80218250 8E050000 */  lw        $a1, ($s0)
/* 59E934 80218254 26100004 */  addiu     $s0, $s0, 4
/* 59E938 80218258 0220202D */  daddu     $a0, $s1, $zero
/* 59E93C 8021825C 0C0B1EAF */  jal       get_variable
/* 59E940 80218260 0040982D */   daddu    $s3, $v0, $zero
/* 59E944 80218264 8E050000 */  lw        $a1, ($s0)
/* 59E948 80218268 26100004 */  addiu     $s0, $s0, 4
/* 59E94C 8021826C 0220202D */  daddu     $a0, $s1, $zero
/* 59E950 80218270 0C0B1EAF */  jal       get_variable
/* 59E954 80218274 0040902D */   daddu    $s2, $v0, $zero
/* 59E958 80218278 8E050000 */  lw        $a1, ($s0)
/* 59E95C 8021827C 26100004 */  addiu     $s0, $s0, 4
/* 59E960 80218280 0C0B1EAF */  jal       get_variable
/* 59E964 80218284 0220202D */   daddu    $a0, $s1, $zero
/* 59E968 80218288 8E050000 */  lw        $a1, ($s0)
/* 59E96C 8021828C 0C0B1EAF */  jal       get_variable
/* 59E970 80218290 0220202D */   daddu    $a0, $s1, $zero
/* 59E974 80218294 44820000 */  mtc1      $v0, $f0
/* 59E978 80218298 00000000 */  nop       
/* 59E97C 8021829C 46800020 */  cvt.s.w   $f0, $f0
/* 59E980 802182A0 24020002 */  addiu     $v0, $zero, 2
/* 59E984 802182A4 3C048023 */  lui       $a0, %hi(D_8022ADD0)
/* 59E988 802182A8 2484ADD0 */  addiu     $a0, $a0, %lo(D_8022ADD0)
/* 59E98C 802182AC 00131900 */  sll       $v1, $s3, 4
/* 59E990 802182B0 00731823 */  subu      $v1, $v1, $s3
/* 59E994 802182B4 00031940 */  sll       $v1, $v1, 5
/* 59E998 802182B8 00641821 */  addu      $v1, $v1, $a0
/* 59E99C 802182BC 00529004 */  sllv      $s2, $s2, $v0
/* 59E9A0 802182C0 00721821 */  addu      $v1, $v1, $s2
/* 59E9A4 802182C4 E460006C */  swc1      $f0, 0x6c($v1)
/* 59E9A8 802182C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 59E9AC 802182CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 59E9B0 802182D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 59E9B4 802182D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 59E9B8 802182D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 59E9BC 802182DC 03E00008 */  jr        $ra
/* 59E9C0 802182E0 27BD0028 */   addiu    $sp, $sp, 0x28

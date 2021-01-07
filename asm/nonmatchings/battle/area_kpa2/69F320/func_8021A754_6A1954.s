.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A754_6A1954
/* 6A1954 8021A754 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A1958 8021A758 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A195C 8021A75C 0080802D */  daddu     $s0, $a0, $zero
/* 6A1960 8021A760 10A00003 */  beqz      $a1, .L8021A770
/* 6A1964 8021A764 AFBF0014 */   sw       $ra, 0x14($sp)
/* 6A1968 8021A768 24020014 */  addiu     $v0, $zero, 0x14
/* 6A196C 8021A76C AE020070 */  sw        $v0, 0x70($s0)
.L8021A770:
/* 6A1970 8021A770 0000202D */  daddu     $a0, $zero, $zero
/* 6A1974 8021A774 0080282D */  daddu     $a1, $a0, $zero
/* 6A1978 8021A778 8E020070 */  lw        $v0, 0x70($s0)
/* 6A197C 8021A77C 0080302D */  daddu     $a2, $a0, $zero
/* 6A1980 8021A780 00023880 */  sll       $a3, $v0, 2
/* 6A1984 8021A784 00E23821 */  addu      $a3, $a3, $v0
/* 6A1988 8021A788 00073840 */  sll       $a3, $a3, 1
/* 6A198C 8021A78C 0C046F97 */  jal       set_background_color_blend
/* 6A1990 8021A790 30E700FE */   andi     $a3, $a3, 0xfe
/* 6A1994 8021A794 8E020070 */  lw        $v0, 0x70($s0)
/* 6A1998 8021A798 2442FFFF */  addiu     $v0, $v0, -1
/* 6A199C 8021A79C 10400003 */  beqz      $v0, .L8021A7AC
/* 6A19A0 8021A7A0 AE020070 */   sw       $v0, 0x70($s0)
/* 6A19A4 8021A7A4 080869F1 */  j         .L8021A7C4
/* 6A19A8 8021A7A8 0000102D */   daddu    $v0, $zero, $zero
.L8021A7AC:
/* 6A19AC 8021A7AC 0000202D */  daddu     $a0, $zero, $zero
/* 6A19B0 8021A7B0 0080282D */  daddu     $a1, $a0, $zero
/* 6A19B4 8021A7B4 0080302D */  daddu     $a2, $a0, $zero
/* 6A19B8 8021A7B8 0C046F97 */  jal       set_background_color_blend
/* 6A19BC 8021A7BC 0080382D */   daddu    $a3, $a0, $zero
/* 6A19C0 8021A7C0 24020002 */  addiu     $v0, $zero, 2
.L8021A7C4:
/* 6A19C4 8021A7C4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6A19C8 8021A7C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A19CC 8021A7CC 03E00008 */  jr        $ra
/* 6A19D0 8021A7D0 27BD0018 */   addiu    $sp, $sp, 0x18

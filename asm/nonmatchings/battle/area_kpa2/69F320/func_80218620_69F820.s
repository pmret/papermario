.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218620_69F820
/* 69F820 80218620 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 69F824 80218624 AFB00010 */  sw        $s0, 0x10($sp)
/* 69F828 80218628 0080802D */  daddu     $s0, $a0, $zero
/* 69F82C 8021862C 10A00003 */  beqz      $a1, .L8021863C
/* 69F830 80218630 AFBF0014 */   sw       $ra, 0x14($sp)
/* 69F834 80218634 24020014 */  addiu     $v0, $zero, 0x14
/* 69F838 80218638 AE020070 */  sw        $v0, 0x70($s0)
.L8021863C:
/* 69F83C 8021863C 0000202D */  daddu     $a0, $zero, $zero
/* 69F840 80218640 0080282D */  daddu     $a1, $a0, $zero
/* 69F844 80218644 8E020070 */  lw        $v0, 0x70($s0)
/* 69F848 80218648 0080302D */  daddu     $a2, $a0, $zero
/* 69F84C 8021864C 00023880 */  sll       $a3, $v0, 2
/* 69F850 80218650 00E23821 */  addu      $a3, $a3, $v0
/* 69F854 80218654 00073840 */  sll       $a3, $a3, 1
/* 69F858 80218658 0C046F97 */  jal       set_background_color_blend
/* 69F85C 8021865C 30E700FE */   andi     $a3, $a3, 0xfe
/* 69F860 80218660 8E020070 */  lw        $v0, 0x70($s0)
/* 69F864 80218664 2442FFFF */  addiu     $v0, $v0, -1
/* 69F868 80218668 10400003 */  beqz      $v0, .L80218678
/* 69F86C 8021866C AE020070 */   sw       $v0, 0x70($s0)
/* 69F870 80218670 080861A4 */  j         .L80218690
/* 69F874 80218674 0000102D */   daddu    $v0, $zero, $zero
.L80218678:
/* 69F878 80218678 0000202D */  daddu     $a0, $zero, $zero
/* 69F87C 8021867C 0080282D */  daddu     $a1, $a0, $zero
/* 69F880 80218680 0080302D */  daddu     $a2, $a0, $zero
/* 69F884 80218684 0C046F97 */  jal       set_background_color_blend
/* 69F888 80218688 0080382D */   daddu    $a3, $a0, $zero
/* 69F88C 8021868C 24020002 */  addiu     $v0, $zero, 2
.L80218690:
/* 69F890 80218690 8FBF0014 */  lw        $ra, 0x14($sp)
/* 69F894 80218694 8FB00010 */  lw        $s0, 0x10($sp)
/* 69F898 80218698 03E00008 */  jr        $ra
/* 69F89C 8021869C 27BD0018 */   addiu    $sp, $sp, 0x18

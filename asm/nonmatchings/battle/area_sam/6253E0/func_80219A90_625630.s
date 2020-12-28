.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219A90_625630
/* 625630 80219A90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 625634 80219A94 AFB10014 */  sw        $s1, 0x14($sp)
/* 625638 80219A98 0080882D */  daddu     $s1, $a0, $zero
/* 62563C 80219A9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 625640 80219AA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 625644 80219AA4 8E30000C */  lw        $s0, 0xc($s1)
/* 625648 80219AA8 8E050000 */  lw        $a1, ($s0)
/* 62564C 80219AAC 0C0B1EAF */  jal       get_variable
/* 625650 80219AB0 26100004 */   addiu    $s0, $s0, 4
/* 625654 80219AB4 0220202D */  daddu     $a0, $s1, $zero
/* 625658 80219AB8 8E050000 */  lw        $a1, ($s0)
/* 62565C 80219ABC 0C0B1EAF */  jal       get_variable
/* 625660 80219AC0 0040802D */   daddu    $s0, $v0, $zero
/* 625664 80219AC4 0200202D */  daddu     $a0, $s0, $zero
/* 625668 80219AC8 0C00A3C2 */  jal       start_rumble
/* 62566C 80219ACC 0040282D */   daddu    $a1, $v0, $zero
/* 625670 80219AD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 625674 80219AD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 625678 80219AD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 62567C 80219ADC 24020002 */  addiu     $v0, $zero, 2
/* 625680 80219AE0 03E00008 */  jr        $ra
/* 625684 80219AE4 27BD0020 */   addiu    $sp, $sp, 0x20

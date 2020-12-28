.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219B20_4B2D10
/* 4B2D10 80219B20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B2D14 80219B24 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B2D18 80219B28 0080882D */  daddu     $s1, $a0, $zero
/* 4B2D1C 80219B2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B2D20 80219B30 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B2D24 80219B34 8E30000C */  lw        $s0, 0xc($s1)
/* 4B2D28 80219B38 8E050000 */  lw        $a1, ($s0)
/* 4B2D2C 80219B3C 0C0B1EAF */  jal       get_variable
/* 4B2D30 80219B40 26100004 */   addiu    $s0, $s0, 4
/* 4B2D34 80219B44 0220202D */  daddu     $a0, $s1, $zero
/* 4B2D38 80219B48 8E050000 */  lw        $a1, ($s0)
/* 4B2D3C 80219B4C 0C0B1EAF */  jal       get_variable
/* 4B2D40 80219B50 0040802D */   daddu    $s0, $v0, $zero
/* 4B2D44 80219B54 0200202D */  daddu     $a0, $s0, $zero
/* 4B2D48 80219B58 0C00A3C2 */  jal       start_rumble
/* 4B2D4C 80219B5C 0040282D */   daddu    $a1, $v0, $zero
/* 4B2D50 80219B60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B2D54 80219B64 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B2D58 80219B68 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B2D5C 80219B6C 24020002 */  addiu     $v0, $zero, 2
/* 4B2D60 80219B70 03E00008 */  jr        $ra
/* 4B2D64 80219B74 27BD0020 */   addiu    $sp, $sp, 0x20

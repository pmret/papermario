.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B20_5B1FD0
/* 5B1FD0 80218B20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B1FD4 80218B24 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B1FD8 80218B28 0080882D */  daddu     $s1, $a0, $zero
/* 5B1FDC 80218B2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 5B1FE0 80218B30 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B1FE4 80218B34 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1FE8 80218B38 8E050000 */  lw        $a1, ($s0)
/* 5B1FEC 80218B3C 0C0B1EAF */  jal       get_variable
/* 5B1FF0 80218B40 26100004 */   addiu    $s0, $s0, 4
/* 5B1FF4 80218B44 0220202D */  daddu     $a0, $s1, $zero
/* 5B1FF8 80218B48 8E050000 */  lw        $a1, ($s0)
/* 5B1FFC 80218B4C 0C0B1EAF */  jal       get_variable
/* 5B2000 80218B50 0040802D */   daddu    $s0, $v0, $zero
/* 5B2004 80218B54 0200202D */  daddu     $a0, $s0, $zero
/* 5B2008 80218B58 0C00A3C2 */  jal       start_rumble
/* 5B200C 80218B5C 0040282D */   daddu    $a1, $v0, $zero
/* 5B2010 80218B60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5B2014 80218B64 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B2018 80218B68 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B201C 80218B6C 24020002 */  addiu     $v0, $zero, 2
/* 5B2020 80218B70 03E00008 */  jr        $ra
/* 5B2024 80218B74 27BD0020 */   addiu    $sp, $sp, 0x20

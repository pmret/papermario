.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B950_6A2B50
/* 6A2B50 8021B950 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A2B54 8021B954 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A2B58 8021B958 0080882D */  daddu     $s1, $a0, $zero
/* 6A2B5C 8021B95C AFBF0018 */  sw        $ra, 0x18($sp)
/* 6A2B60 8021B960 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A2B64 8021B964 8E30000C */  lw        $s0, 0xc($s1)
/* 6A2B68 8021B968 8E050000 */  lw        $a1, ($s0)
/* 6A2B6C 8021B96C 0C0B1EAF */  jal       get_variable
/* 6A2B70 8021B970 26100004 */   addiu    $s0, $s0, 4
/* 6A2B74 8021B974 0220202D */  daddu     $a0, $s1, $zero
/* 6A2B78 8021B978 8E050000 */  lw        $a1, ($s0)
/* 6A2B7C 8021B97C 0C0B1EAF */  jal       get_variable
/* 6A2B80 8021B980 0040802D */   daddu    $s0, $v0, $zero
/* 6A2B84 8021B984 0200202D */  daddu     $a0, $s0, $zero
/* 6A2B88 8021B988 0C00A3C2 */  jal       start_rumble
/* 6A2B8C 8021B98C 0040282D */   daddu    $a1, $v0, $zero
/* 6A2B90 8021B990 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6A2B94 8021B994 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A2B98 8021B998 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A2B9C 8021B99C 24020002 */  addiu     $v0, $zero, 2
/* 6A2BA0 8021B9A0 03E00008 */  jr        $ra
/* 6A2BA4 8021B9A4 27BD0020 */   addiu    $sp, $sp, 0x20

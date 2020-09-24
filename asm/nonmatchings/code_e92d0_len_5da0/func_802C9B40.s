.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C9B40
/* EE4F0 802C9B40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE4F4 802C9B44 AFB10014 */  sw        $s1, 0x14($sp)
/* EE4F8 802C9B48 0080882D */  daddu     $s1, $a0, $zero
/* EE4FC 802C9B4C AFBF0018 */  sw        $ra, 0x18($sp)
/* EE500 802C9B50 AFB00010 */  sw        $s0, 0x10($sp)
/* EE504 802C9B54 8E30000C */  lw        $s0, 0xc($s1)
/* EE508 802C9B58 8E050000 */  lw        $a1, ($s0)
/* EE50C 802C9B5C 0C0B1EAF */  jal       get_variable
/* EE510 802C9B60 26100004 */   addiu    $s0, $s0, 4
/* EE514 802C9B64 8E100000 */  lw        $s0, ($s0)
/* EE518 802C9B68 0C046C24 */  jal       func_8011B090
/* EE51C 802C9B6C 0040202D */   daddu    $a0, $v0, $zero
/* EE520 802C9B70 0220202D */  daddu     $a0, $s1, $zero
/* EE524 802C9B74 0040302D */  daddu     $a2, $v0, $zero
/* EE528 802C9B78 0C0B2026 */  jal       set_variable
/* EE52C 802C9B7C 0200282D */   daddu    $a1, $s0, $zero
/* EE530 802C9B80 8FBF0018 */  lw        $ra, 0x18($sp)
/* EE534 802C9B84 8FB10014 */  lw        $s1, 0x14($sp)
/* EE538 802C9B88 8FB00010 */  lw        $s0, 0x10($sp)
/* EE53C 802C9B8C 24020002 */  addiu     $v0, $zero, 2
/* EE540 802C9B90 03E00008 */  jr        $ra
/* EE544 802C9B94 27BD0020 */   addiu    $sp, $sp, 0x20

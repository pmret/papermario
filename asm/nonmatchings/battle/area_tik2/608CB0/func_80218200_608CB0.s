.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218200_608CB0
/* 608CB0 80218200 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 608CB4 80218204 AFB10014 */  sw        $s1, 0x14($sp)
/* 608CB8 80218208 0080882D */  daddu     $s1, $a0, $zero
/* 608CBC 8021820C AFBF0018 */  sw        $ra, 0x18($sp)
/* 608CC0 80218210 AFB00010 */  sw        $s0, 0x10($sp)
/* 608CC4 80218214 8E30000C */  lw        $s0, 0xc($s1)
/* 608CC8 80218218 8E050000 */  lw        $a1, ($s0)
/* 608CCC 8021821C 0C0B1EAF */  jal       get_variable
/* 608CD0 80218220 26100004 */   addiu    $s0, $s0, 4
/* 608CD4 80218224 0220202D */  daddu     $a0, $s1, $zero
/* 608CD8 80218228 8E050000 */  lw        $a1, ($s0)
/* 608CDC 8021822C 0C0B1EAF */  jal       get_variable
/* 608CE0 80218230 0040802D */   daddu    $s0, $v0, $zero
/* 608CE4 80218234 0200202D */  daddu     $a0, $s0, $zero
/* 608CE8 80218238 0C00A3C2 */  jal       start_rumble
/* 608CEC 8021823C 0040282D */   daddu    $a1, $v0, $zero
/* 608CF0 80218240 8FBF0018 */  lw        $ra, 0x18($sp)
/* 608CF4 80218244 8FB10014 */  lw        $s1, 0x14($sp)
/* 608CF8 80218248 8FB00010 */  lw        $s0, 0x10($sp)
/* 608CFC 8021824C 24020002 */  addiu     $v0, $zero, 2
/* 608D00 80218250 03E00008 */  jr        $ra
/* 608D04 80218254 27BD0020 */   addiu    $sp, $sp, 0x20

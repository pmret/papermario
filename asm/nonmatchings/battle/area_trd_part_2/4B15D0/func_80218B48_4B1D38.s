.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B48_4B1D38
/* 4B1D38 80218B48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B1D3C 80218B4C AFB00010 */  sw        $s0, 0x10($sp)
/* 4B1D40 80218B50 0080802D */  daddu     $s0, $a0, $zero
/* 4B1D44 80218B54 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B1D48 80218B58 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B1D4C 80218B5C 8E040148 */  lw        $a0, 0x148($s0)
/* 4B1D50 80218B60 0C09A75B */  jal       get_actor
/* 4B1D54 80218B64 8E11000C */   lw       $s1, 0xc($s0)
/* 4B1D58 80218B68 0200202D */  daddu     $a0, $s0, $zero
/* 4B1D5C 80218B6C 8E250000 */  lw        $a1, ($s1)
/* 4B1D60 80218B70 0C0B1EAF */  jal       get_variable
/* 4B1D64 80218B74 0040802D */   daddu    $s0, $v0, $zero
/* 4B1D68 80218B78 A20201F0 */  sb        $v0, 0x1f0($s0)
/* 4B1D6C 80218B7C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B1D70 80218B80 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B1D74 80218B84 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B1D78 80218B88 24020002 */  addiu     $v0, $zero, 2
/* 4B1D7C 80218B8C 03E00008 */  jr        $ra
/* 4B1D80 80218B90 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4B1D84 80218B94 00000000 */  nop
/* 4B1D88 80218B98 00000000 */  nop
/* 4B1D8C 80218B9C 00000000 */  nop

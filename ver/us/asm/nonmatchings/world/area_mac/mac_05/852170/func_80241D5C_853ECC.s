.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D5C_853ECC
/* 853ECC 80241D5C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 853ED0 80241D60 AFBF0010 */  sw        $ra, 0x10($sp)
/* 853ED4 80241D64 8C82000C */  lw        $v0, 0xc($a0)
/* 853ED8 80241D68 0C0B1EAF */  jal       get_variable
/* 853EDC 80241D6C 8C450000 */   lw       $a1, ($v0)
/* 853EE0 80241D70 3C038025 */  lui       $v1, %hi(D_802529F0)
/* 853EE4 80241D74 8C6329F0 */  lw        $v1, %lo(D_802529F0)($v1)
/* 853EE8 80241D78 8C63000C */  lw        $v1, 0xc($v1)
/* 853EEC 80241D7C AC620034 */  sw        $v0, 0x34($v1)
/* 853EF0 80241D80 8FBF0010 */  lw        $ra, 0x10($sp)
/* 853EF4 80241D84 24020002 */  addiu     $v0, $zero, 2
/* 853EF8 80241D88 03E00008 */  jr        $ra
/* 853EFC 80241D8C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E48
/* 865988 80240E48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 86598C 80240E4C AFBF0010 */  sw        $ra, 0x10($sp)
/* 865990 80240E50 8C82000C */  lw        $v0, 0xc($a0)
/* 865994 80240E54 0C0B1EAF */  jal       get_variable
/* 865998 80240E58 8C450000 */   lw       $a1, ($v0)
/* 86599C 80240E5C 8C44000C */  lw        $a0, 0xc($v0)
/* 8659A0 80240E60 24030001 */  addiu     $v1, $zero, 1
/* 8659A4 80240E64 AC830004 */  sw        $v1, 4($a0)
/* 8659A8 80240E68 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8659AC 80240E6C 24020002 */  addiu     $v0, $zero, 2
/* 8659B0 80240E70 03E00008 */  jr        $ra
/* 8659B4 80240E74 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8659B8 80240E78 00000000 */  nop       
/* 8659BC 80240E7C 00000000 */  nop       

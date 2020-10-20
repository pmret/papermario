.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D3C_969EFC
/* 969EFC 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 969F00 80240D40 AFBF0010 */  sw        $ra, 0x10($sp)
/* 969F04 80240D44 8C82000C */  lw        $v0, 0xc($a0)
/* 969F08 80240D48 0C0B1EAF */  jal       get_variable
/* 969F0C 80240D4C 8C450000 */   lw       $a1, ($v0)
/* 969F10 80240D50 3C038025 */  lui       $v1, 0x8025
/* 969F14 80240D54 8C63EFC0 */  lw        $v1, -0x1040($v1)
/* 969F18 80240D58 8C63000C */  lw        $v1, 0xc($v1)
/* 969F1C 80240D5C AC620034 */  sw        $v0, 0x34($v1)
/* 969F20 80240D60 8FBF0010 */  lw        $ra, 0x10($sp)
/* 969F24 80240D64 24020002 */  addiu     $v0, $zero, 2
/* 969F28 80240D68 03E00008 */  jr        $ra
/* 969F2C 80240D6C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C24_9D9C44
/* 9D9C44 80242C24 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9C48 80242C28 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D9C4C 80242C2C 8C82000C */  lw        $v0, 0xc($a0)
/* 9D9C50 80242C30 0C0B1EAF */  jal       get_variable
/* 9D9C54 80242C34 8C450000 */   lw       $a1, ($v0)
/* 9D9C58 80242C38 3C018025 */  lui       $at, 0x8025
/* 9D9C5C 80242C3C AC2296F4 */  sw        $v0, -0x690c($at)
/* 9D9C60 80242C40 24020002 */  addiu     $v0, $zero, 2
/* 9D9C64 80242C44 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D9C68 80242C48 24030001 */  addiu     $v1, $zero, 1
/* 9D9C6C 80242C4C 3C018025 */  lui       $at, 0x8025
/* 9D9C70 80242C50 AC2396F0 */  sw        $v1, -0x6910($at)
/* 9D9C74 80242C54 03E00008 */  jr        $ra
/* 9D9C78 80242C58 27BD0018 */   addiu    $sp, $sp, 0x18

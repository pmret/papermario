.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243D28_8045A8
/* 8045A8 80243D28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8045AC 80243D2C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8045B0 80243D30 8C82000C */  lw        $v0, 0xc($a0)
/* 8045B4 80243D34 0C0B1EAF */  jal       get_variable
/* 8045B8 80243D38 8C450000 */   lw       $a1, ($v0)
/* 8045BC 80243D3C 3C018025 */  lui       $at, %hi(D_8024D948)
/* 8045C0 80243D40 AC22D948 */  sw        $v0, %lo(D_8024D948)($at)
/* 8045C4 80243D44 24020002 */  addiu     $v0, $zero, 2
/* 8045C8 80243D48 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8045CC 80243D4C 24030001 */  addiu     $v1, $zero, 1
/* 8045D0 80243D50 3C018025 */  lui       $at, %hi(D_8024D944)
/* 8045D4 80243D54 AC23D944 */  sw        $v1, %lo(D_8024D944)($at)
/* 8045D8 80243D58 03E00008 */  jr        $ra
/* 8045DC 80243D5C 27BD0018 */   addiu    $sp, $sp, 0x18

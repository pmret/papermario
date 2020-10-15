.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269550
/* 197E30 80269550 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197E34 80269554 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197E38 80269558 8C82000C */  lw        $v0, 0xc($a0)
/* 197E3C 8026955C 0C0B1EAF */  jal       get_variable
/* 197E40 80269560 8C450000 */   lw       $a1, ($v0)
/* 197E44 80269564 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197E48 80269568 3C01800E */  lui       $at, 0x800e
/* 197E4C 8026956C A022C0F6 */  sb        $v0, -0x3f0a($at)
/* 197E50 80269570 24020002 */  addiu     $v0, $zero, 2
/* 197E54 80269574 03E00008 */  jr        $ra
/* 197E58 80269578 27BD0018 */   addiu    $sp, $sp, 0x18

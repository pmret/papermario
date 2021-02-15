.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240930_97BF60
/* 97BF60 80240930 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 97BF64 80240934 AFBF0010 */  sw        $ra, 0x10($sp)
/* 97BF68 80240938 8C82000C */  lw        $v0, 0xc($a0)
/* 97BF6C 8024093C 0C0B1EAF */  jal       get_variable
/* 97BF70 80240940 8C450000 */   lw       $a1, ($v0)
/* 97BF74 80240944 0C03AC5A */  jal       func_800EB168
/* 97BF78 80240948 0040202D */   daddu    $a0, $v0, $zero
/* 97BF7C 8024094C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 97BF80 80240950 24020002 */  addiu     $v0, $zero, 2
/* 97BF84 80240954 03E00008 */  jr        $ra
/* 97BF88 80240958 27BD0018 */   addiu    $sp, $sp, 0x18

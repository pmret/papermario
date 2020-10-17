.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetBattleState
/* 19CA20 8026E140 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19CA24 8026E144 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19CA28 8026E148 8C82000C */  lw        $v0, 0xc($a0)
/* 19CA2C 8026E14C 3C06800E */  lui       $a2, 0x800e
/* 19CA30 8026E150 8CC6C068 */  lw        $a2, -0x3f98($a2)
/* 19CA34 8026E154 0C0B2026 */  jal       set_variable
/* 19CA38 8026E158 8C450000 */   lw       $a1, ($v0)
/* 19CA3C 8026E15C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19CA40 8026E160 24020002 */  addiu     $v0, $zero, 2
/* 19CA44 8026E164 03E00008 */  jr        $ra
/* 19CA48 8026E168 27BD0018 */   addiu    $sp, $sp, 0x18

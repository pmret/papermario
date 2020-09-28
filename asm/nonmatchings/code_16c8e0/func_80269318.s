.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269318
/* 197BF8 80269318 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197BFC 8026931C AFBF0010 */  sw        $ra, 0x10($sp)
/* 197C00 80269320 8C82000C */  lw        $v0, 0xc($a0)
/* 197C04 80269324 3C06800E */  lui       $a2, 0x800e
/* 197C08 80269328 80C6C0F3 */  lb        $a2, -0x3f0d($a2)
/* 197C0C 8026932C 0C0B2026 */  jal       set_variable
/* 197C10 80269330 8C450000 */   lw       $a1, ($v0)
/* 197C14 80269334 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197C18 80269338 24020002 */  addiu     $v0, $zero, 2
/* 197C1C 8026933C 03E00008 */  jr        $ra
/* 197C20 80269340 27BD0018 */   addiu    $sp, $sp, 0x18

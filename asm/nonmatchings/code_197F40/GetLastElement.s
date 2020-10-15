.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetLastElement
/* 198734 80269E54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 198738 80269E58 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19873C 80269E5C 8C82000C */  lw        $v0, 0xc($a0)
/* 198740 80269E60 3C06800E */  lui       $a2, 0x800e
/* 198744 80269E64 8CC6C1F8 */  lw        $a2, -0x3e08($a2)
/* 198748 80269E68 0C0B2026 */  jal       set_variable
/* 19874C 80269E6C 8C450000 */   lw       $a1, ($v0)
/* 198750 80269E70 8FBF0010 */  lw        $ra, 0x10($sp)
/* 198754 80269E74 24020002 */  addiu     $v0, $zero, 2
/* 198758 80269E78 03E00008 */  jr        $ra
/* 19875C 80269E7C 27BD0018 */   addiu    $sp, $sp, 0x18

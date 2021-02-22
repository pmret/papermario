.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_basic_npc
/* 13C44 80038844 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13C48 80038848 0000282D */  daddu     $a1, $zero, $zero
/* 13C4C 8003884C AFBF0010 */  sw        $ra, 0x10($sp)
/* 13C50 80038850 0C00E166 */  jal       _create_npc
/* 13C54 80038854 00A0302D */   daddu    $a2, $a1, $zero
/* 13C58 80038858 8FBF0010 */  lw        $ra, 0x10($sp)
/* 13C5C 8003885C 03E00008 */  jr        $ra
/* 13C60 80038860 27BD0018 */   addiu    $sp, $sp, 0x18

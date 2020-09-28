.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_partner_npc
/* 13C80 80038880 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13C84 80038884 0000282D */  daddu     $a1, $zero, $zero
/* 13C88 80038888 AFBF0010 */  sw        $ra, 0x10($sp)
/* 13C8C 8003888C 0C00E166 */  jal       _create_npc
/* 13C90 80038890 24060001 */   addiu    $a2, $zero, 1
/* 13C94 80038894 8FBF0010 */  lw        $ra, 0x10($sp)
/* 13C98 80038898 03E00008 */  jr        $ra
/* 13C9C 8003889C 27BD0018 */   addiu    $sp, $sp, 0x18

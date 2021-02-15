.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243068_96C228
/* 96C228 80243068 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C22C 8024306C 2404202B */  addiu     $a0, $zero, 0x202b
/* 96C230 80243070 0000282D */  daddu     $a1, $zero, $zero
/* 96C234 80243074 24060068 */  addiu     $a2, $zero, 0x68
/* 96C238 80243078 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C23C 8024307C 0C0526AE */  jal       _play_sound
/* 96C240 80243080 00A0382D */   daddu    $a3, $a1, $zero
/* 96C244 80243084 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C248 80243088 24020002 */  addiu     $v0, $zero, 2
/* 96C24C 8024308C 03E00008 */  jr        $ra
/* 96C250 80243090 27BD0018 */   addiu    $sp, $sp, 0x18

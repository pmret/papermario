.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024303C_96C1FC
/* 96C1FC 8024303C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C200 80243040 2404202A */  addiu     $a0, $zero, 0x202a
/* 96C204 80243044 0000282D */  daddu     $a1, $zero, $zero
/* 96C208 80243048 24060018 */  addiu     $a2, $zero, 0x18
/* 96C20C 8024304C AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C210 80243050 0C0526AE */  jal       _play_sound
/* 96C214 80243054 00A0382D */   daddu    $a3, $a1, $zero
/* 96C218 80243058 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C21C 8024305C 24020002 */  addiu     $v0, $zero, 2
/* 96C220 80243060 03E00008 */  jr        $ra
/* 96C224 80243064 27BD0018 */   addiu    $sp, $sp, 0x18

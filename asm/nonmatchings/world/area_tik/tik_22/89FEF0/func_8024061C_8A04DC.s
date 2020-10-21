.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_8A04DC
/* 8A04DC 8024061C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8A04E0 80240620 0000202D */  daddu     $a0, $zero, $zero
/* 8A04E4 80240624 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8A04E8 80240628 0C052AD8 */  jal       func_8014AB60
/* 8A04EC 8024062C 24050002 */   addiu    $a1, $zero, 2
/* 8A04F0 80240630 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8A04F4 80240634 24020002 */  addiu     $v0, $zero, 2
/* 8A04F8 80240638 03E00008 */  jr        $ra
/* 8A04FC 8024063C 27BD0018 */   addiu    $sp, $sp, 0x18

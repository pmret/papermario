.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024072C_C6885C
/* C6885C 8024072C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C68860 80240730 AFBF0010 */  sw        $ra, 0x10($sp)
/* C68864 80240734 8C82000C */  lw        $v0, 0xc($a0)
/* C68868 80240738 0C0B1EAF */  jal       get_variable
/* C6886C 8024073C 8C450000 */   lw       $a1, ($v0)
/* C68870 80240740 0C03AC5A */  jal       func_800EB168
/* C68874 80240744 0040202D */   daddu    $a0, $v0, $zero
/* C68878 80240748 8FBF0010 */  lw        $ra, 0x10($sp)
/* C6887C 8024074C 24020002 */  addiu     $v0, $zero, 2
/* C68880 80240750 03E00008 */  jr        $ra
/* C68884 80240754 27BD0018 */   addiu    $sp, $sp, 0x18

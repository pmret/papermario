.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_04_UnkFunc39
/* C68950 80240820 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C68954 80240824 AFBF0010 */  sw        $ra, 0x10($sp)
/* C68958 80240828 8C82000C */  lw        $v0, 0xc($a0)
/* C6895C 8024082C 0C0B1EAF */  jal       get_variable
/* C68960 80240830 8C450000 */   lw       $a1, ($v0)
/* C68964 80240834 0040202D */  daddu     $a0, $v0, $zero
/* C68968 80240838 8C830000 */  lw        $v1, ($a0)
/* C6896C 8024083C 34630010 */  ori       $v1, $v1, 0x10
/* C68970 80240840 AC830000 */  sw        $v1, ($a0)
/* C68974 80240844 8FBF0010 */  lw        $ra, 0x10($sp)
/* C68978 80240848 24020002 */  addiu     $v0, $zero, 2
/* C6897C 8024084C 03E00008 */  jr        $ra
/* C68980 80240850 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240604
/* A2A844 80240604 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2A848 80240608 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2A84C 8024060C 8C82000C */  lw        $v0, 0xc($a0)
/* A2A850 80240610 0C0B1EAF */  jal       get_variable
/* A2A854 80240614 8C450000 */   lw       $a1, ($v0)
/* A2A858 80240618 0C0B1059 */  jal       does_script_exist
/* A2A85C 8024061C 0040202D */   daddu    $a0, $v0, $zero
/* A2A860 80240620 2C420001 */  sltiu     $v0, $v0, 1
/* A2A864 80240624 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2A868 80240628 00021040 */  sll       $v0, $v0, 1
/* A2A86C 8024062C 03E00008 */  jr        $ra
/* A2A870 80240630 27BD0018 */   addiu    $sp, $sp, 0x18

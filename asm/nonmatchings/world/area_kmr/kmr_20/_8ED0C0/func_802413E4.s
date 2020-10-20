.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413E4
/* 8ED204 802413E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED208 802413E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED20C 802413EC 8C82000C */  lw        $v0, 0xc($a0)
/* 8ED210 802413F0 0C0B1EAF */  jal       get_variable
/* 8ED214 802413F4 8C450000 */   lw       $a1, ($v0)
/* 8ED218 802413F8 0C0B1059 */  jal       does_script_exist
/* 8ED21C 802413FC 0040202D */   daddu    $a0, $v0, $zero
/* 8ED220 80241400 2C420001 */  sltiu     $v0, $v0, 1
/* 8ED224 80241404 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED228 80241408 00021040 */  sll       $v0, $v0, 1
/* 8ED22C 8024140C 03E00008 */  jr        $ra
/* 8ED230 80241410 27BD0018 */   addiu    $sp, $sp, 0x18

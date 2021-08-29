.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BC4_6BC754
/* 6BC754 80218BC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6BC758 80218BC8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6BC75C 80218BCC 8C82000C */  lw        $v0, 0xc($a0)
/* 6BC760 80218BD0 0C0B1EAF */  jal       evt_get_variable
/* 6BC764 80218BD4 8C450000 */   lw       $a1, ($v0)
/* 6BC768 80218BD8 8C43000C */  lw        $v1, 0xc($v0)
/* 6BC76C 80218BDC 3C01C47A */  lui       $at, 0xc47a
/* 6BC770 80218BE0 44810000 */  mtc1      $at, $f0
/* 6BC774 80218BE4 00000000 */  nop
/* 6BC778 80218BE8 E4600008 */  swc1      $f0, 8($v1)
/* 6BC77C 80218BEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6BC780 80218BF0 24020002 */  addiu     $v0, $zero, 2
/* 6BC784 80218BF4 03E00008 */  jr        $ra
/* 6BC788 80218BF8 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802692EC
/* 197BCC 802692EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197BD0 802692F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197BD4 802692F4 8C82000C */  lw        $v0, 0xc($a0)
/* 197BD8 802692F8 0C0B1EAF */  jal       get_variable
/* 197BDC 802692FC 8C450000 */   lw       $a1, ($v0)
/* 197BE0 80269300 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197BE4 80269304 3C01800E */  lui       $at, 0x800e
/* 197BE8 80269308 A022C0F3 */  sb        $v0, -0x3f0d($at)
/* 197BEC 8026930C 24020002 */  addiu     $v0, $zero, 2
/* 197BF0 80269310 03E00008 */  jr        $ra
/* 197BF4 80269314 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218630_6DE3F0
/* 6DE3F0 80218630 94820086 */  lhu       $v0, 0x86($a0)
/* 6DE3F4 80218634 3C018028 */  lui       $at, %hi(D_802809F8)
/* 6DE3F8 80218638 A42209F8 */  sh        $v0, %lo(D_802809F8)($at)
/* 6DE3FC 8021863C 03E00008 */  jr        $ra
/* 6DE400 80218640 24020002 */   addiu    $v0, $zero, 2

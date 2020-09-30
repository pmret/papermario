.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80059C88
/* 35088 80059C88 8C82000C */  lw        $v0, 0xc($a0)
/* 3508C 80059C8C AC450004 */  sw        $a1, 4($v0)
/* 35090 80059C90 AC460008 */  sw        $a2, 8($v0)
/* 35094 80059C94 03E00008 */  jr        $ra
/* 35098 80059C98 AC47000C */   sw       $a3, 0xc($v0)

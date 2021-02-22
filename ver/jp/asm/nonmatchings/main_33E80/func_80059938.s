.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80059938
/* 34D38 80059938 8C82000C */  lw        $v0, 0xc($a0)
/* 34D3C 8005993C AC450004 */  sw        $a1, 4($v0)
/* 34D40 80059940 AC460008 */  sw        $a2, 8($v0)
/* 34D44 80059944 03E00008 */  jr        $ra
/* 34D48 80059948 AC47000C */   sw       $a3, 0xc($v0)

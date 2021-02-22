.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80051E80
/* 2D280 80051E80 8C830008 */  lw        $v1, 8($a0)
/* 2D284 80051E84 90620000 */  lbu       $v0, ($v1)
/* 2D288 80051E88 24630001 */  addiu     $v1, $v1, 1
/* 2D28C 80051E8C AC830008 */  sw        $v1, 8($a0)
/* 2D290 80051E90 03E00008 */  jr        $ra
/* 2D294 80051E94 304200FF */   andi     $v0, $v0, 0xff

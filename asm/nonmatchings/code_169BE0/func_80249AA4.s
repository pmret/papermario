.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80249AA4
/* 16A304 80249AA4 00042080 */  sll       $a0, $a0, 2
/* 16A308 80249AA8 3C028025 */  lui       $v0, 0x8025
/* 16A30C 80249AAC 00441021 */  addu      $v0, $v0, $a0
/* 16A310 80249AB0 03E00008 */  jr        $ra
/* 16A314 80249AB4 8C42B9D0 */   lw       $v0, -0x4630($v0)

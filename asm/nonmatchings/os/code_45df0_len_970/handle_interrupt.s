.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel handle_interrupt
/* 46008 8006AC08 03688024 */  and       $s0, $k1, $t0

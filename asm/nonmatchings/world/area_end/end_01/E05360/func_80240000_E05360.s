.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_E05360
/* E05360 80240000 03E00008 */  jr        $ra
/* E05364 80240004 0000102D */   daddu    $v0, $zero, $zero
/* E05368 80240008 00000000 */  nop
/* E0536C 8024000C 00000000 */  nop

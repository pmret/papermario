.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040
/* 7E73E0 80240040 03E00008 */  jr        $ra
/* 7E73E4 80240044 0000102D */   daddu    $v0, $zero, $zero

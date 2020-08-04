.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel is_partner_ability_active
/* 083568 800EA0B8 03E00008 */  jr    $ra
/* 08356C 800EA0BC 0000102D */   daddu $v0, $zero, $zero


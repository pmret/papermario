.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400BC_95407C
/* 95407C 802400BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 954080 802400C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 954084 802400C4 8C82000C */  lw        $v0, 0xc($a0)
/* 954088 802400C8 0C0B1EAF */  jal       evt_get_variable
/* 95408C 802400CC 8C450000 */   lw       $a1, ($v0)
/* 954090 802400D0 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* 954094 802400D4 0040202D */   daddu    $a0, $v0, $zero
/* 954098 802400D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95409C 802400DC 24020002 */  addiu     $v0, $zero, 2
/* 9540A0 802400E0 03E00008 */  jr        $ra
/* 9540A4 802400E4 27BD0018 */   addiu    $sp, $sp, 0x18

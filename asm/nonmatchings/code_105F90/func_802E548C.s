.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E548C
/* 106D0C 802E548C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106D10 802E5490 AFBF0010 */  sw        $ra, 0x10($sp)
/* 106D14 802E5494 0C0B9381 */  jal       func_802E4E04
/* 106D18 802E5498 0000282D */   daddu    $a1, $zero, $zero
/* 106D1C 802E549C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106D20 802E54A0 03E00008 */  jr        $ra
/* 106D24 802E54A4 27BD0018 */   addiu    $sp, $sp, 0x18

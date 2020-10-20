.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD4
/* 92AE84 80240BD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 92AE88 80240BD8 AFB00010 */  sw        $s0, 0x10($sp)
/* 92AE8C 80240BDC AFBF0014 */  sw        $ra, 0x14($sp)
/* 92AE90 80240BE0 0C039D7B */  jal       get_item_count
/* 92AE94 80240BE4 0080802D */   daddu    $s0, $a0, $zero
/* 92AE98 80240BE8 AE020084 */  sw        $v0, 0x84($s0)
/* 92AE9C 80240BEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 92AEA0 80240BF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 92AEA4 80240BF4 24020002 */  addiu     $v0, $zero, 2
/* 92AEA8 80240BF8 03E00008 */  jr        $ra
/* 92AEAC 80240BFC 27BD0018 */   addiu    $sp, $sp, 0x18

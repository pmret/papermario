.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD130_323A80
/* 323A80 802BD130 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 323A84 802BD134 AFBF0014 */  sw        $ra, 0x14($sp)
/* 323A88 802BD138 AFB00010 */  sw        $s0, 0x10($sp)
/* 323A8C 802BD13C 10A00003 */  beqz      $a1, .L802BD14C
/* 323A90 802BD140 8C90014C */   lw       $s0, 0x14c($a0)
/* 323A94 802BD144 0C03BB31 */  jal       func_800EECC4
/* 323A98 802BD148 0200202D */   daddu    $a0, $s0, $zero
.L802BD14C:
/* 323A9C 802BD14C 0C03BB3A */  jal       func_800EECE8
/* 323AA0 802BD150 0200202D */   daddu    $a0, $s0, $zero
/* 323AA4 802BD154 8FBF0014 */  lw        $ra, 0x14($sp)
/* 323AA8 802BD158 8FB00010 */  lw        $s0, 0x10($sp)
/* 323AAC 802BD15C 0002102B */  sltu      $v0, $zero, $v0
/* 323AB0 802BD160 03E00008 */  jr        $ra
/* 323AB4 802BD164 27BD0018 */   addiu    $sp, $sp, 0x18

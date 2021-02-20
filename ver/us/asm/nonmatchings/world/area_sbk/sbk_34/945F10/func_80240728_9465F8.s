.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240728_9465F8
/* 9465F8 80240728 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9465FC 8024072C AFB00010 */  sw        $s0, 0x10($sp)
/* 946600 80240730 0080802D */  daddu     $s0, $a0, $zero
/* 946604 80240734 AFBF0014 */  sw        $ra, 0x14($sp)
/* 946608 80240738 0C00EABB */  jal       get_npc_unsafe
/* 94660C 8024073C 8E04008C */   lw       $a0, 0x8c($s0)
/* 946610 80240740 0040282D */  daddu     $a1, $v0, $zero
/* 946614 80240744 8E040094 */  lw        $a0, 0x94($s0)
/* 946618 80240748 8CA30028 */  lw        $v1, 0x28($a1)
/* 94661C 8024074C ACA40028 */  sw        $a0, 0x28($a1)
/* 946620 80240750 8FBF0014 */  lw        $ra, 0x14($sp)
/* 946624 80240754 8FB00010 */  lw        $s0, 0x10($sp)
/* 946628 80240758 24020002 */  addiu     $v0, $zero, 2
/* 94662C 8024075C 3C018024 */  lui       $at, %hi(nok_02_GetNpcCollisionHeight)
/* 946630 80240760 AC2329A4 */  sw        $v1, %lo(nok_02_GetNpcCollisionHeight)($at)
/* 946634 80240764 03E00008 */  jr        $ra
/* 946638 80240768 27BD0018 */   addiu    $sp, $sp, 0x18

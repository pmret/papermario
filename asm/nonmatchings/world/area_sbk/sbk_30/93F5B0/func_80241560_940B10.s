.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241560_940B10
/* 940B10 80241560 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 940B14 80241564 AFB00010 */  sw        $s0, 0x10($sp)
/* 940B18 80241568 0080802D */  daddu     $s0, $a0, $zero
/* 940B1C 8024156C AFBF0014 */  sw        $ra, 0x14($sp)
/* 940B20 80241570 0C00EABB */  jal       get_npc_unsafe
/* 940B24 80241574 8E04008C */   lw       $a0, 0x8c($s0)
/* 940B28 80241578 0040282D */  daddu     $a1, $v0, $zero
/* 940B2C 8024157C 8E040094 */  lw        $a0, 0x94($s0)
/* 940B30 80241580 8CA30028 */  lw        $v1, 0x28($a1)
/* 940B34 80241584 ACA40028 */  sw        $a0, 0x28($a1)
/* 940B38 80241588 8FBF0014 */  lw        $ra, 0x14($sp)
/* 940B3C 8024158C 8FB00010 */  lw        $s0, 0x10($sp)
/* 940B40 80241590 24020002 */  addiu     $v0, $zero, 2
/* 940B44 80241594 3C018024 */  lui       $at, 0x8024
/* 940B48 80241598 AC234D88 */  sw        $v1, 0x4d88($at)
/* 940B4C 8024159C 03E00008 */  jr        $ra
/* 940B50 802415A0 27BD0018 */   addiu    $sp, $sp, 0x18

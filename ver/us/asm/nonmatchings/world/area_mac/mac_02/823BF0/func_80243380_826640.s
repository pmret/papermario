.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243380_826640
/* 826640 80243380 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 826644 80243384 AFB00010 */  sw        $s0, 0x10($sp)
/* 826648 80243388 0080802D */  daddu     $s0, $a0, $zero
/* 82664C 8024338C AFBF0014 */  sw        $ra, 0x14($sp)
/* 826650 80243390 0C00EABB */  jal       get_npc_unsafe
/* 826654 80243394 8E04008C */   lw       $a0, 0x8c($s0)
/* 826658 80243398 0040282D */  daddu     $a1, $v0, $zero
/* 82665C 8024339C 8E040094 */  lw        $a0, 0x94($s0)
/* 826660 802433A0 8CA30028 */  lw        $v1, 0x28($a1)
/* 826664 802433A4 ACA40028 */  sw        $a0, 0x28($a1)
/* 826668 802433A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 82666C 802433AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 826670 802433B0 24020002 */  addiu     $v0, $zero, 2
/* 826674 802433B4 3C018025 */  lui       $at, %hi(D_8024EA18)
/* 826678 802433B8 AC23EA18 */  sw        $v1, %lo(D_8024EA18)($at)
/* 82667C 802433BC 03E00008 */  jr        $ra
/* 826680 802433C0 27BD0018 */   addiu    $sp, $sp, 0x18

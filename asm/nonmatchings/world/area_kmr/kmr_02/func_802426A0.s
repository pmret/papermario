.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426A0
/* 8B2710 802426A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2714 802426A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B2718 802426A8 0080802D */  daddu     $s0, $a0, $zero
/* 8B271C 802426AC AFBF0014 */  sw        $ra, 0x14($sp)
/* 8B2720 802426B0 0C00EABB */  jal       get_npc_unsafe
/* 8B2724 802426B4 8E04008C */   lw       $a0, 0x8c($s0)
/* 8B2728 802426B8 0040282D */  daddu     $a1, $v0, $zero
/* 8B272C 802426BC 8E040094 */  lw        $a0, 0x94($s0)
/* 8B2730 802426C0 8CA30028 */  lw        $v1, 0x28($a1)
/* 8B2734 802426C4 ACA40028 */  sw        $a0, 0x28($a1)
/* 8B2738 802426C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8B273C 802426CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B2740 802426D0 24020002 */  addiu     $v0, $zero, 2
/* 8B2744 802426D4 3C018026 */  lui       $at, 0x8026
/* 8B2748 802426D8 AC23811C */  sw        $v1, -0x7ee4($at)
/* 8B274C 802426DC 03E00008 */  jr        $ra
/* 8B2750 802426E0 27BD0018 */   addiu    $sp, $sp, 0x18

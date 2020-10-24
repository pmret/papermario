.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426E4_8B2754
/* 8B2754 802426E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2758 802426E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B275C 802426EC 0C00EABB */  jal       get_npc_unsafe
/* 8B2760 802426F0 8C84008C */   lw       $a0, 0x8c($a0)
/* 8B2764 802426F4 3C038026 */  lui       $v1, 0x8026
/* 8B2768 802426F8 8C63811C */  lw        $v1, -0x7ee4($v1)
/* 8B276C 802426FC AC430028 */  sw        $v1, 0x28($v0)
/* 8B2770 80242700 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2774 80242704 24020002 */  addiu     $v0, $zero, 2
/* 8B2778 80242708 03E00008 */  jr        $ra
/* 8B277C 8024270C 27BD0018 */   addiu    $sp, $sp, 0x18

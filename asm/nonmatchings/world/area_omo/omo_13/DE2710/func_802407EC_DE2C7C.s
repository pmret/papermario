.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407EC_DE2C7C
/* DE2C7C 802407EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE2C80 802407F0 AFB10014 */  sw        $s1, 0x14($sp)
/* DE2C84 802407F4 0080882D */  daddu     $s1, $a0, $zero
/* DE2C88 802407F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DE2C8C 802407FC AFB00010 */  sw        $s0, 0x10($sp)
/* DE2C90 80240800 8E300148 */  lw        $s0, 0x148($s1)
/* DE2C94 80240804 0C00EABB */  jal       get_npc_unsafe
/* DE2C98 80240808 86040008 */   lh       $a0, 8($s0)
/* DE2C9C 8024080C 3C054387 */  lui       $a1, 0x4387
/* DE2CA0 80240810 0040202D */  daddu     $a0, $v0, $zero
/* DE2CA4 80240814 0C00ECD0 */  jal       set_npc_yaw
/* DE2CA8 80240818 A480008E */   sh       $zero, 0x8e($a0)
/* DE2CAC 8024081C 24020003 */  addiu     $v0, $zero, 3
/* DE2CB0 80240820 AE00006C */  sw        $zero, 0x6c($s0)
/* DE2CB4 80240824 AE220070 */  sw        $v0, 0x70($s1)
/* DE2CB8 80240828 8FBF0018 */  lw        $ra, 0x18($sp)
/* DE2CBC 8024082C 8FB10014 */  lw        $s1, 0x14($sp)
/* DE2CC0 80240830 8FB00010 */  lw        $s0, 0x10($sp)
/* DE2CC4 80240834 03E00008 */  jr        $ra
/* DE2CC8 80240838 27BD0020 */   addiu    $sp, $sp, 0x20

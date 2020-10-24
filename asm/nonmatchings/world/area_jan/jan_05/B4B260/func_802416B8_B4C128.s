.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416B8_B4C128
/* B4C128 802416B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4C12C 802416BC AFB10014 */  sw        $s1, 0x14($sp)
/* B4C130 802416C0 0080882D */  daddu     $s1, $a0, $zero
/* B4C134 802416C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B4C138 802416C8 AFB00010 */  sw        $s0, 0x10($sp)
/* B4C13C 802416CC 8E300148 */  lw        $s0, 0x148($s1)
/* B4C140 802416D0 0C00EABB */  jal       get_npc_unsafe
/* B4C144 802416D4 86040008 */   lh       $a0, 8($s0)
/* B4C148 802416D8 3C054387 */  lui       $a1, 0x4387
/* B4C14C 802416DC 0040202D */  daddu     $a0, $v0, $zero
/* B4C150 802416E0 0C00ECD0 */  jal       set_npc_yaw
/* B4C154 802416E4 A480008E */   sh       $zero, 0x8e($a0)
/* B4C158 802416E8 24020003 */  addiu     $v0, $zero, 3
/* B4C15C 802416EC AE00006C */  sw        $zero, 0x6c($s0)
/* B4C160 802416F0 AE220070 */  sw        $v0, 0x70($s1)
/* B4C164 802416F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B4C168 802416F8 8FB10014 */  lw        $s1, 0x14($sp)
/* B4C16C 802416FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B4C170 80241700 03E00008 */  jr        $ra
/* B4C174 80241704 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413C8
/* BE0158 802413C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE015C 802413CC AFB10014 */  sw        $s1, 0x14($sp)
/* BE0160 802413D0 0080882D */  daddu     $s1, $a0, $zero
/* BE0164 802413D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE0168 802413D8 AFB00010 */  sw        $s0, 0x10($sp)
/* BE016C 802413DC 8E30000C */  lw        $s0, 0xc($s1)
/* BE0170 802413E0 8E050000 */  lw        $a1, ($s0)
/* BE0174 802413E4 0C0B1EAF */  jal       get_variable
/* BE0178 802413E8 26100004 */   addiu    $s0, $s0, 4
/* BE017C 802413EC 0C00EAD2 */  jal       get_npc_safe
/* BE0180 802413F0 0040202D */   daddu    $a0, $v0, $zero
/* BE0184 802413F4 10400005 */  beqz      $v0, .L8024140C
/* BE0188 802413F8 00000000 */   nop      
/* BE018C 802413FC 8E050000 */  lw        $a1, ($s0)
/* BE0190 80241400 844600A8 */  lh        $a2, 0xa8($v0)
/* BE0194 80241404 0C0B2026 */  jal       set_variable
/* BE0198 80241408 0220202D */   daddu    $a0, $s1, $zero
.L8024140C:
/* BE019C 8024140C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE01A0 80241410 8FB10014 */  lw        $s1, 0x14($sp)
/* BE01A4 80241414 8FB00010 */  lw        $s0, 0x10($sp)
/* BE01A8 80241418 24020002 */  addiu     $v0, $zero, 2
/* BE01AC 8024141C 03E00008 */  jr        $ra
/* BE01B0 80241420 27BD0020 */   addiu    $sp, $sp, 0x20

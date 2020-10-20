.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433C4_C7A0A4
/* C7A0A4 802433C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7A0A8 802433C8 AFB10014 */  sw        $s1, 0x14($sp)
/* C7A0AC 802433CC 0080882D */  daddu     $s1, $a0, $zero
/* C7A0B0 802433D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C7A0B4 802433D4 AFB00010 */  sw        $s0, 0x10($sp)
/* C7A0B8 802433D8 8E30000C */  lw        $s0, 0xc($s1)
/* C7A0BC 802433DC 8E050000 */  lw        $a1, ($s0)
/* C7A0C0 802433E0 0C0B1EAF */  jal       get_variable
/* C7A0C4 802433E4 26100004 */   addiu    $s0, $s0, 4
/* C7A0C8 802433E8 0C00EAD2 */  jal       get_npc_safe
/* C7A0CC 802433EC 0040202D */   daddu    $a0, $v0, $zero
/* C7A0D0 802433F0 10400005 */  beqz      $v0, .L80243408
/* C7A0D4 802433F4 00000000 */   nop      
/* C7A0D8 802433F8 8E050000 */  lw        $a1, ($s0)
/* C7A0DC 802433FC 844600A8 */  lh        $a2, 0xa8($v0)
/* C7A0E0 80243400 0C0B2026 */  jal       set_variable
/* C7A0E4 80243404 0220202D */   daddu    $a0, $s1, $zero
.L80243408:
/* C7A0E8 80243408 8FBF0018 */  lw        $ra, 0x18($sp)
/* C7A0EC 8024340C 8FB10014 */  lw        $s1, 0x14($sp)
/* C7A0F0 80243410 8FB00010 */  lw        $s0, 0x10($sp)
/* C7A0F4 80243414 24020002 */  addiu     $v0, $zero, 2
/* C7A0F8 80243418 03E00008 */  jr        $ra
/* C7A0FC 8024341C 27BD0020 */   addiu    $sp, $sp, 0x20

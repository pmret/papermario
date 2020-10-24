.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024167C_DCE34C
/* DCE34C 8024167C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCE350 80241680 AFB10014 */  sw        $s1, 0x14($sp)
/* DCE354 80241684 0080882D */  daddu     $s1, $a0, $zero
/* DCE358 80241688 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCE35C 8024168C AFB00010 */  sw        $s0, 0x10($sp)
/* DCE360 80241690 8E300148 */  lw        $s0, 0x148($s1)
/* DCE364 80241694 0C00EABB */  jal       get_npc_unsafe
/* DCE368 80241698 86040008 */   lh       $a0, 8($s0)
/* DCE36C 8024169C 8E0300CC */  lw        $v1, 0xcc($s0)
/* DCE370 802416A0 3C014120 */  lui       $at, 0x4120
/* DCE374 802416A4 44812000 */  mtc1      $at, $f4
/* DCE378 802416A8 3C014000 */  lui       $at, 0x4000
/* DCE37C 802416AC 44810000 */  mtc1      $at, $f0
/* DCE380 802416B0 C442003C */  lwc1      $f2, 0x3c($v0)
/* DCE384 802416B4 8C640010 */  lw        $a0, 0x10($v1)
/* DCE388 802416B8 8C430000 */  lw        $v1, ($v0)
/* DCE38C 802416BC E444001C */  swc1      $f4, 0x1c($v0)
/* DCE390 802416C0 E4400014 */  swc1      $f0, 0x14($v0)
/* DCE394 802416C4 E4420064 */  swc1      $f2, 0x64($v0)
/* DCE398 802416C8 34630800 */  ori       $v1, $v1, 0x800
/* DCE39C 802416CC AC430000 */  sw        $v1, ($v0)
/* DCE3A0 802416D0 AC440028 */  sw        $a0, 0x28($v0)
/* DCE3A4 802416D4 2402000B */  addiu     $v0, $zero, 0xb
/* DCE3A8 802416D8 AE220070 */  sw        $v0, 0x70($s1)
/* DCE3AC 802416DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCE3B0 802416E0 8FB10014 */  lw        $s1, 0x14($sp)
/* DCE3B4 802416E4 8FB00010 */  lw        $s0, 0x10($sp)
/* DCE3B8 802416E8 03E00008 */  jr        $ra
/* DCE3BC 802416EC 27BD0020 */   addiu    $sp, $sp, 0x20

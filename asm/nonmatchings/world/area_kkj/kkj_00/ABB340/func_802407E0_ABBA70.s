.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407E0_ABBA70
/* ABBA70 802407E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ABBA74 802407E4 AFB10014 */  sw        $s1, 0x14($sp)
/* ABBA78 802407E8 0080882D */  daddu     $s1, $a0, $zero
/* ABBA7C 802407EC AFBF0018 */  sw        $ra, 0x18($sp)
/* ABBA80 802407F0 AFB00010 */  sw        $s0, 0x10($sp)
/* ABBA84 802407F4 8E300148 */  lw        $s0, 0x148($s1)
/* ABBA88 802407F8 0C00EABB */  jal       get_npc_unsafe
/* ABBA8C 802407FC 86040008 */   lh       $a0, 8($s0)
/* ABBA90 80240800 8E0300CC */  lw        $v1, 0xcc($s0)
/* ABBA94 80240804 3C014120 */  lui       $at, 0x4120
/* ABBA98 80240808 44812000 */  mtc1      $at, $f4
/* ABBA9C 8024080C 3C014000 */  lui       $at, 0x4000
/* ABBAA0 80240810 44810000 */  mtc1      $at, $f0
/* ABBAA4 80240814 C442003C */  lwc1      $f2, 0x3c($v0)
/* ABBAA8 80240818 8C640010 */  lw        $a0, 0x10($v1)
/* ABBAAC 8024081C 8C430000 */  lw        $v1, ($v0)
/* ABBAB0 80240820 E444001C */  swc1      $f4, 0x1c($v0)
/* ABBAB4 80240824 E4400014 */  swc1      $f0, 0x14($v0)
/* ABBAB8 80240828 E4420064 */  swc1      $f2, 0x64($v0)
/* ABBABC 8024082C 34630800 */  ori       $v1, $v1, 0x800
/* ABBAC0 80240830 AC430000 */  sw        $v1, ($v0)
/* ABBAC4 80240834 AC440028 */  sw        $a0, 0x28($v0)
/* ABBAC8 80240838 2402000B */  addiu     $v0, $zero, 0xb
/* ABBACC 8024083C AE220070 */  sw        $v0, 0x70($s1)
/* ABBAD0 80240840 8FBF0018 */  lw        $ra, 0x18($sp)
/* ABBAD4 80240844 8FB10014 */  lw        $s1, 0x14($sp)
/* ABBAD8 80240848 8FB00010 */  lw        $s0, 0x10($sp)
/* ABBADC 8024084C 03E00008 */  jr        $ra
/* ABBAE0 80240850 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240770_C9E690
/* C9E690 80240770 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9E694 80240774 AFB10014 */  sw        $s1, 0x14($sp)
/* C9E698 80240778 0080882D */  daddu     $s1, $a0, $zero
/* C9E69C 8024077C AFBF0018 */  sw        $ra, 0x18($sp)
/* C9E6A0 80240780 AFB00010 */  sw        $s0, 0x10($sp)
/* C9E6A4 80240784 8E300148 */  lw        $s0, 0x148($s1)
/* C9E6A8 80240788 0C00EABB */  jal       get_npc_unsafe
/* C9E6AC 8024078C 86040008 */   lh       $a0, 8($s0)
/* C9E6B0 80240790 8E0300CC */  lw        $v1, 0xcc($s0)
/* C9E6B4 80240794 3C014120 */  lui       $at, 0x4120
/* C9E6B8 80240798 44812000 */  mtc1      $at, $f4
/* C9E6BC 8024079C 3C014000 */  lui       $at, 0x4000
/* C9E6C0 802407A0 44810000 */  mtc1      $at, $f0
/* C9E6C4 802407A4 C442003C */  lwc1      $f2, 0x3c($v0)
/* C9E6C8 802407A8 8C640010 */  lw        $a0, 0x10($v1)
/* C9E6CC 802407AC 8C430000 */  lw        $v1, ($v0)
/* C9E6D0 802407B0 E444001C */  swc1      $f4, 0x1c($v0)
/* C9E6D4 802407B4 E4400014 */  swc1      $f0, 0x14($v0)
/* C9E6D8 802407B8 E4420064 */  swc1      $f2, 0x64($v0)
/* C9E6DC 802407BC 34630800 */  ori       $v1, $v1, 0x800
/* C9E6E0 802407C0 AC430000 */  sw        $v1, ($v0)
/* C9E6E4 802407C4 AC440028 */  sw        $a0, 0x28($v0)
/* C9E6E8 802407C8 2402000B */  addiu     $v0, $zero, 0xb
/* C9E6EC 802407CC AE220070 */  sw        $v0, 0x70($s1)
/* C9E6F0 802407D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C9E6F4 802407D4 8FB10014 */  lw        $s1, 0x14($sp)
/* C9E6F8 802407D8 8FB00010 */  lw        $s0, 0x10($sp)
/* C9E6FC 802407DC 03E00008 */  jr        $ra
/* C9E700 802407E0 27BD0020 */   addiu    $sp, $sp, 0x20

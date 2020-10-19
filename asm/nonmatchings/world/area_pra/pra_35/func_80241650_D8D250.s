.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241650_D8E8A0
/* D8E8A0 80241650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8E8A4 80241654 AFB10014 */  sw        $s1, 0x14($sp)
/* D8E8A8 80241658 0080882D */  daddu     $s1, $a0, $zero
/* D8E8AC 8024165C AFBF0018 */  sw        $ra, 0x18($sp)
/* D8E8B0 80241660 AFB00010 */  sw        $s0, 0x10($sp)
/* D8E8B4 80241664 8E300148 */  lw        $s0, 0x148($s1)
/* D8E8B8 80241668 0C00EABB */  jal       get_npc_unsafe
/* D8E8BC 8024166C 86040008 */   lh       $a0, 8($s0)
/* D8E8C0 80241670 8E0300CC */  lw        $v1, 0xcc($s0)
/* D8E8C4 80241674 3C014120 */  lui       $at, 0x4120
/* D8E8C8 80241678 44812000 */  mtc1      $at, $f4
/* D8E8CC 8024167C 3C014000 */  lui       $at, 0x4000
/* D8E8D0 80241680 44810000 */  mtc1      $at, $f0
/* D8E8D4 80241684 C442003C */  lwc1      $f2, 0x3c($v0)
/* D8E8D8 80241688 8C640010 */  lw        $a0, 0x10($v1)
/* D8E8DC 8024168C 8C430000 */  lw        $v1, ($v0)
/* D8E8E0 80241690 E444001C */  swc1      $f4, 0x1c($v0)
/* D8E8E4 80241694 E4400014 */  swc1      $f0, 0x14($v0)
/* D8E8E8 80241698 E4420064 */  swc1      $f2, 0x64($v0)
/* D8E8EC 8024169C 34630800 */  ori       $v1, $v1, 0x800
/* D8E8F0 802416A0 AC430000 */  sw        $v1, ($v0)
/* D8E8F4 802416A4 AC440028 */  sw        $a0, 0x28($v0)
/* D8E8F8 802416A8 2402000B */  addiu     $v0, $zero, 0xb
/* D8E8FC 802416AC AE220070 */  sw        $v0, 0x70($s1)
/* D8E900 802416B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8E904 802416B4 8FB10014 */  lw        $s1, 0x14($sp)
/* D8E908 802416B8 8FB00010 */  lw        $s0, 0x10($sp)
/* D8E90C 802416BC 03E00008 */  jr        $ra
/* D8E910 802416C0 27BD0020 */   addiu    $sp, $sp, 0x20

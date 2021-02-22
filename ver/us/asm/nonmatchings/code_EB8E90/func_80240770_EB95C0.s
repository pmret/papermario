.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240770_EB95C0
/* EB95C0 80240770 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB95C4 80240774 AFB10014 */  sw        $s1, 0x14($sp)
/* EB95C8 80240778 0080882D */  daddu     $s1, $a0, $zero
/* EB95CC 8024077C AFBF0018 */  sw        $ra, 0x18($sp)
/* EB95D0 80240780 AFB00010 */  sw        $s0, 0x10($sp)
/* EB95D4 80240784 8E300148 */  lw        $s0, 0x148($s1)
/* EB95D8 80240788 0C00F92F */  jal       func_8003E4BC
/* EB95DC 8024078C 86040008 */   lh       $a0, 8($s0)
/* EB95E0 80240790 8E0300CC */  lw        $v1, 0xcc($s0)
/* EB95E4 80240794 3C014120 */  lui       $at, 0x4120
/* EB95E8 80240798 44812000 */  mtc1      $at, $f4
/* EB95EC 8024079C 3C014000 */  lui       $at, 0x4000
/* EB95F0 802407A0 44810000 */  mtc1      $at, $f0
/* EB95F4 802407A4 C442003C */  lwc1      $f2, 0x3c($v0)
/* EB95F8 802407A8 8C640010 */  lw        $a0, 0x10($v1)
/* EB95FC 802407AC 8C430000 */  lw        $v1, ($v0)
/* EB9600 802407B0 E444001C */  swc1      $f4, 0x1c($v0)
/* EB9604 802407B4 E4400014 */  swc1      $f0, 0x14($v0)
/* EB9608 802407B8 E4420064 */  swc1      $f2, 0x64($v0)
/* EB960C 802407BC 34630800 */  ori       $v1, $v1, 0x800
/* EB9610 802407C0 AC430000 */  sw        $v1, ($v0)
/* EB9614 802407C4 AC440028 */  sw        $a0, 0x28($v0)
/* EB9618 802407C8 2402000B */  addiu     $v0, $zero, 0xb
/* EB961C 802407CC AE220070 */  sw        $v0, 0x70($s1)
/* EB9620 802407D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB9624 802407D4 8FB10014 */  lw        $s1, 0x14($sp)
/* EB9628 802407D8 8FB00010 */  lw        $s0, 0x10($sp)
/* EB962C 802407DC 03E00008 */  jr        $ra
/* EB9630 802407E0 27BD0020 */   addiu    $sp, $sp, 0x20

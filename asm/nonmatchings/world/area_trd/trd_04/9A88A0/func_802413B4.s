.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413B4
/* 9A97A4 802413B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A97A8 802413B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A97AC 802413BC 0080882D */  daddu     $s1, $a0, $zero
/* 9A97B0 802413C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9A97B4 802413C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A97B8 802413C8 8E300148 */  lw        $s0, 0x148($s1)
/* 9A97BC 802413CC 0C00EABB */  jal       get_npc_unsafe
/* 9A97C0 802413D0 86040008 */   lh       $a0, 8($s0)
/* 9A97C4 802413D4 8E0300CC */  lw        $v1, 0xcc($s0)
/* 9A97C8 802413D8 3C014120 */  lui       $at, 0x4120
/* 9A97CC 802413DC 44812000 */  mtc1      $at, $f4
/* 9A97D0 802413E0 3C014000 */  lui       $at, 0x4000
/* 9A97D4 802413E4 44810000 */  mtc1      $at, $f0
/* 9A97D8 802413E8 C442003C */  lwc1      $f2, 0x3c($v0)
/* 9A97DC 802413EC 8C640010 */  lw        $a0, 0x10($v1)
/* 9A97E0 802413F0 8C430000 */  lw        $v1, ($v0)
/* 9A97E4 802413F4 E444001C */  swc1      $f4, 0x1c($v0)
/* 9A97E8 802413F8 E4400014 */  swc1      $f0, 0x14($v0)
/* 9A97EC 802413FC E4420064 */  swc1      $f2, 0x64($v0)
/* 9A97F0 80241400 34630800 */  ori       $v1, $v1, 0x800
/* 9A97F4 80241404 AC430000 */  sw        $v1, ($v0)
/* 9A97F8 80241408 AC440028 */  sw        $a0, 0x28($v0)
/* 9A97FC 8024140C 2402000B */  addiu     $v0, $zero, 0xb
/* 9A9800 80241410 AE220070 */  sw        $v0, 0x70($s1)
/* 9A9804 80241414 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9A9808 80241418 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A980C 8024141C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A9810 80241420 03E00008 */  jr        $ra
/* 9A9814 80241424 27BD0020 */   addiu    $sp, $sp, 0x20

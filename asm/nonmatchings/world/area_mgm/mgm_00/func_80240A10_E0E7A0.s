.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A10_E0F1B0
/* E0F1B0 80240A10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0F1B4 80240A14 AFB10014 */  sw        $s1, 0x14($sp)
/* E0F1B8 80240A18 0080882D */  daddu     $s1, $a0, $zero
/* E0F1BC 80240A1C AFBF0018 */  sw        $ra, 0x18($sp)
/* E0F1C0 80240A20 AFB00010 */  sw        $s0, 0x10($sp)
/* E0F1C4 80240A24 8E300148 */  lw        $s0, 0x148($s1)
/* E0F1C8 80240A28 0C00EABB */  jal       get_npc_unsafe
/* E0F1CC 80240A2C 86040008 */   lh       $a0, 8($s0)
/* E0F1D0 80240A30 8E0300CC */  lw        $v1, 0xcc($s0)
/* E0F1D4 80240A34 3C014120 */  lui       $at, 0x4120
/* E0F1D8 80240A38 44812000 */  mtc1      $at, $f4
/* E0F1DC 80240A3C 3C014000 */  lui       $at, 0x4000
/* E0F1E0 80240A40 44810000 */  mtc1      $at, $f0
/* E0F1E4 80240A44 C442003C */  lwc1      $f2, 0x3c($v0)
/* E0F1E8 80240A48 8C640010 */  lw        $a0, 0x10($v1)
/* E0F1EC 80240A4C 8C430000 */  lw        $v1, ($v0)
/* E0F1F0 80240A50 E444001C */  swc1      $f4, 0x1c($v0)
/* E0F1F4 80240A54 E4400014 */  swc1      $f0, 0x14($v0)
/* E0F1F8 80240A58 E4420064 */  swc1      $f2, 0x64($v0)
/* E0F1FC 80240A5C 34630800 */  ori       $v1, $v1, 0x800
/* E0F200 80240A60 AC430000 */  sw        $v1, ($v0)
/* E0F204 80240A64 AC440028 */  sw        $a0, 0x28($v0)
/* E0F208 80240A68 2402000B */  addiu     $v0, $zero, 0xb
/* E0F20C 80240A6C AE220070 */  sw        $v0, 0x70($s1)
/* E0F210 80240A70 8FBF0018 */  lw        $ra, 0x18($sp)
/* E0F214 80240A74 8FB10014 */  lw        $s1, 0x14($sp)
/* E0F218 80240A78 8FB00010 */  lw        $s0, 0x10($sp)
/* E0F21C 80240A7C 03E00008 */  jr        $ra
/* E0F220 80240A80 27BD0020 */   addiu    $sp, $sp, 0x20

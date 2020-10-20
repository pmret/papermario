.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240810_A8D290
/* A8D290 80240810 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8D294 80240814 AFB10014 */  sw        $s1, 0x14($sp)
/* A8D298 80240818 0080882D */  daddu     $s1, $a0, $zero
/* A8D29C 8024081C AFBF0018 */  sw        $ra, 0x18($sp)
/* A8D2A0 80240820 AFB00010 */  sw        $s0, 0x10($sp)
/* A8D2A4 80240824 8E300148 */  lw        $s0, 0x148($s1)
/* A8D2A8 80240828 0C00EABB */  jal       get_npc_unsafe
/* A8D2AC 8024082C 86040008 */   lh       $a0, 8($s0)
/* A8D2B0 80240830 8E0300CC */  lw        $v1, 0xcc($s0)
/* A8D2B4 80240834 3C014120 */  lui       $at, 0x4120
/* A8D2B8 80240838 44812000 */  mtc1      $at, $f4
/* A8D2BC 8024083C 3C014000 */  lui       $at, 0x4000
/* A8D2C0 80240840 44810000 */  mtc1      $at, $f0
/* A8D2C4 80240844 C442003C */  lwc1      $f2, 0x3c($v0)
/* A8D2C8 80240848 8C640010 */  lw        $a0, 0x10($v1)
/* A8D2CC 8024084C 8C430000 */  lw        $v1, ($v0)
/* A8D2D0 80240850 E444001C */  swc1      $f4, 0x1c($v0)
/* A8D2D4 80240854 E4400014 */  swc1      $f0, 0x14($v0)
/* A8D2D8 80240858 E4420064 */  swc1      $f2, 0x64($v0)
/* A8D2DC 8024085C 34630800 */  ori       $v1, $v1, 0x800
/* A8D2E0 80240860 AC430000 */  sw        $v1, ($v0)
/* A8D2E4 80240864 AC440028 */  sw        $a0, 0x28($v0)
/* A8D2E8 80240868 2402000B */  addiu     $v0, $zero, 0xb
/* A8D2EC 8024086C AE220070 */  sw        $v0, 0x70($s1)
/* A8D2F0 80240870 8FBF0018 */  lw        $ra, 0x18($sp)
/* A8D2F4 80240874 8FB10014 */  lw        $s1, 0x14($sp)
/* A8D2F8 80240878 8FB00010 */  lw        $s0, 0x10($sp)
/* A8D2FC 8024087C 03E00008 */  jr        $ra
/* A8D300 80240880 27BD0020 */   addiu    $sp, $sp, 0x20

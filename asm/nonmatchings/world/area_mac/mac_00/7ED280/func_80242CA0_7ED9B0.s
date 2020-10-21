.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CA0_7ED9B0
/* 7ED9B0 80242CA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7ED9B4 80242CA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7ED9B8 80242CA8 0080882D */  daddu     $s1, $a0, $zero
/* 7ED9BC 80242CAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 7ED9C0 80242CB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ED9C4 80242CB4 8E300148 */  lw        $s0, 0x148($s1)
/* 7ED9C8 80242CB8 0C00EABB */  jal       get_npc_unsafe
/* 7ED9CC 80242CBC 86040008 */   lh       $a0, 8($s0)
/* 7ED9D0 80242CC0 8E0300CC */  lw        $v1, 0xcc($s0)
/* 7ED9D4 80242CC4 3C014120 */  lui       $at, 0x4120
/* 7ED9D8 80242CC8 44812000 */  mtc1      $at, $f4
/* 7ED9DC 80242CCC 3C014000 */  lui       $at, 0x4000
/* 7ED9E0 80242CD0 44810000 */  mtc1      $at, $f0
/* 7ED9E4 80242CD4 C442003C */  lwc1      $f2, 0x3c($v0)
/* 7ED9E8 80242CD8 8C640010 */  lw        $a0, 0x10($v1)
/* 7ED9EC 80242CDC 8C430000 */  lw        $v1, ($v0)
/* 7ED9F0 80242CE0 E444001C */  swc1      $f4, 0x1c($v0)
/* 7ED9F4 80242CE4 E4400014 */  swc1      $f0, 0x14($v0)
/* 7ED9F8 80242CE8 E4420064 */  swc1      $f2, 0x64($v0)
/* 7ED9FC 80242CEC 34630800 */  ori       $v1, $v1, 0x800
/* 7EDA00 80242CF0 AC430000 */  sw        $v1, ($v0)
/* 7EDA04 80242CF4 AC440028 */  sw        $a0, 0x28($v0)
/* 7EDA08 80242CF8 2402000B */  addiu     $v0, $zero, 0xb
/* 7EDA0C 80242CFC AE220070 */  sw        $v0, 0x70($s1)
/* 7EDA10 80242D00 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EDA14 80242D04 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EDA18 80242D08 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EDA1C 80242D0C 03E00008 */  jr        $ra
/* 7EDA20 80242D10 27BD0020 */   addiu    $sp, $sp, 0x20

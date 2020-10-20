.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C9C_DBDF4C
/* DBDF4C 80240C9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBDF50 80240CA0 AFB10014 */  sw        $s1, 0x14($sp)
/* DBDF54 80240CA4 0080882D */  daddu     $s1, $a0, $zero
/* DBDF58 80240CA8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DBDF5C 80240CAC AFB00010 */  sw        $s0, 0x10($sp)
/* DBDF60 80240CB0 8E300148 */  lw        $s0, 0x148($s1)
/* DBDF64 80240CB4 0C00EABB */  jal       get_npc_unsafe
/* DBDF68 80240CB8 86040008 */   lh       $a0, 8($s0)
/* DBDF6C 80240CBC 8E0300CC */  lw        $v1, 0xcc($s0)
/* DBDF70 80240CC0 3C014120 */  lui       $at, 0x4120
/* DBDF74 80240CC4 44812000 */  mtc1      $at, $f4
/* DBDF78 80240CC8 3C014000 */  lui       $at, 0x4000
/* DBDF7C 80240CCC 44810000 */  mtc1      $at, $f0
/* DBDF80 80240CD0 C442003C */  lwc1      $f2, 0x3c($v0)
/* DBDF84 80240CD4 8C640010 */  lw        $a0, 0x10($v1)
/* DBDF88 80240CD8 8C430000 */  lw        $v1, ($v0)
/* DBDF8C 80240CDC E444001C */  swc1      $f4, 0x1c($v0)
/* DBDF90 80240CE0 E4400014 */  swc1      $f0, 0x14($v0)
/* DBDF94 80240CE4 E4420064 */  swc1      $f2, 0x64($v0)
/* DBDF98 80240CE8 34630800 */  ori       $v1, $v1, 0x800
/* DBDF9C 80240CEC AC430000 */  sw        $v1, ($v0)
/* DBDFA0 80240CF0 AC440028 */  sw        $a0, 0x28($v0)
/* DBDFA4 80240CF4 2402000B */  addiu     $v0, $zero, 0xb
/* DBDFA8 80240CF8 AE220070 */  sw        $v0, 0x70($s1)
/* DBDFAC 80240CFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DBDFB0 80240D00 8FB10014 */  lw        $s1, 0x14($sp)
/* DBDFB4 80240D04 8FB00010 */  lw        $s0, 0x10($sp)
/* DBDFB8 80240D08 03E00008 */  jr        $ra
/* DBDFBC 80240D0C 27BD0020 */   addiu    $sp, $sp, 0x20

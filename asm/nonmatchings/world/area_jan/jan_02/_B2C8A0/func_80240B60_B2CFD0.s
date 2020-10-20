.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B60_B2CFD0
/* B2CFD0 80240B60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2CFD4 80240B64 AFB10014 */  sw        $s1, 0x14($sp)
/* B2CFD8 80240B68 0080882D */  daddu     $s1, $a0, $zero
/* B2CFDC 80240B6C AFBF0018 */  sw        $ra, 0x18($sp)
/* B2CFE0 80240B70 AFB00010 */  sw        $s0, 0x10($sp)
/* B2CFE4 80240B74 8E300148 */  lw        $s0, 0x148($s1)
/* B2CFE8 80240B78 0C00EABB */  jal       get_npc_unsafe
/* B2CFEC 80240B7C 86040008 */   lh       $a0, 8($s0)
/* B2CFF0 80240B80 8E0300CC */  lw        $v1, 0xcc($s0)
/* B2CFF4 80240B84 3C014120 */  lui       $at, 0x4120
/* B2CFF8 80240B88 44812000 */  mtc1      $at, $f4
/* B2CFFC 80240B8C 3C014000 */  lui       $at, 0x4000
/* B2D000 80240B90 44810000 */  mtc1      $at, $f0
/* B2D004 80240B94 C442003C */  lwc1      $f2, 0x3c($v0)
/* B2D008 80240B98 8C640010 */  lw        $a0, 0x10($v1)
/* B2D00C 80240B9C 8C430000 */  lw        $v1, ($v0)
/* B2D010 80240BA0 E444001C */  swc1      $f4, 0x1c($v0)
/* B2D014 80240BA4 E4400014 */  swc1      $f0, 0x14($v0)
/* B2D018 80240BA8 E4420064 */  swc1      $f2, 0x64($v0)
/* B2D01C 80240BAC 34630800 */  ori       $v1, $v1, 0x800
/* B2D020 80240BB0 AC430000 */  sw        $v1, ($v0)
/* B2D024 80240BB4 AC440028 */  sw        $a0, 0x28($v0)
/* B2D028 80240BB8 2402000B */  addiu     $v0, $zero, 0xb
/* B2D02C 80240BBC AE220070 */  sw        $v0, 0x70($s1)
/* B2D030 80240BC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2D034 80240BC4 8FB10014 */  lw        $s1, 0x14($sp)
/* B2D038 80240BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2D03C 80240BCC 03E00008 */  jr        $ra
/* B2D040 80240BD0 27BD0020 */   addiu    $sp, $sp, 0x20

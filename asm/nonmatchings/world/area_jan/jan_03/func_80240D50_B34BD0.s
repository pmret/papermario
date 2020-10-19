.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D50_B35920
/* B35920 80240D50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B35924 80240D54 AFB10014 */  sw        $s1, 0x14($sp)
/* B35928 80240D58 0080882D */  daddu     $s1, $a0, $zero
/* B3592C 80240D5C AFBF0018 */  sw        $ra, 0x18($sp)
/* B35930 80240D60 AFB00010 */  sw        $s0, 0x10($sp)
/* B35934 80240D64 8E300148 */  lw        $s0, 0x148($s1)
/* B35938 80240D68 0C00EABB */  jal       get_npc_unsafe
/* B3593C 80240D6C 86040008 */   lh       $a0, 8($s0)
/* B35940 80240D70 8E0300CC */  lw        $v1, 0xcc($s0)
/* B35944 80240D74 3C014120 */  lui       $at, 0x4120
/* B35948 80240D78 44812000 */  mtc1      $at, $f4
/* B3594C 80240D7C 3C014000 */  lui       $at, 0x4000
/* B35950 80240D80 44810000 */  mtc1      $at, $f0
/* B35954 80240D84 C442003C */  lwc1      $f2, 0x3c($v0)
/* B35958 80240D88 8C640010 */  lw        $a0, 0x10($v1)
/* B3595C 80240D8C 8C430000 */  lw        $v1, ($v0)
/* B35960 80240D90 E444001C */  swc1      $f4, 0x1c($v0)
/* B35964 80240D94 E4400014 */  swc1      $f0, 0x14($v0)
/* B35968 80240D98 E4420064 */  swc1      $f2, 0x64($v0)
/* B3596C 80240D9C 34630800 */  ori       $v1, $v1, 0x800
/* B35970 80240DA0 AC430000 */  sw        $v1, ($v0)
/* B35974 80240DA4 AC440028 */  sw        $a0, 0x28($v0)
/* B35978 80240DA8 2402000B */  addiu     $v0, $zero, 0xb
/* B3597C 80240DAC AE220070 */  sw        $v0, 0x70($s1)
/* B35980 80240DB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B35984 80240DB4 8FB10014 */  lw        $s1, 0x14($sp)
/* B35988 80240DB8 8FB00010 */  lw        $s0, 0x10($sp)
/* B3598C 80240DBC 03E00008 */  jr        $ra
/* B35990 80240DC0 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BC0_852D30
/* 852D30 80240BC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 852D34 80240BC4 AFB10014 */  sw        $s1, 0x14($sp)
/* 852D38 80240BC8 0080882D */  daddu     $s1, $a0, $zero
/* 852D3C 80240BCC AFBF0018 */  sw        $ra, 0x18($sp)
/* 852D40 80240BD0 AFB00010 */  sw        $s0, 0x10($sp)
/* 852D44 80240BD4 8E300148 */  lw        $s0, 0x148($s1)
/* 852D48 80240BD8 0C00EABB */  jal       get_npc_unsafe
/* 852D4C 80240BDC 86040008 */   lh       $a0, 8($s0)
/* 852D50 80240BE0 8E0300CC */  lw        $v1, 0xcc($s0)
/* 852D54 80240BE4 3C014120 */  lui       $at, 0x4120
/* 852D58 80240BE8 44812000 */  mtc1      $at, $f4
/* 852D5C 80240BEC 3C014000 */  lui       $at, 0x4000
/* 852D60 80240BF0 44810000 */  mtc1      $at, $f0
/* 852D64 80240BF4 C442003C */  lwc1      $f2, 0x3c($v0)
/* 852D68 80240BF8 8C640010 */  lw        $a0, 0x10($v1)
/* 852D6C 80240BFC 8C430000 */  lw        $v1, ($v0)
/* 852D70 80240C00 E444001C */  swc1      $f4, 0x1c($v0)
/* 852D74 80240C04 E4400014 */  swc1      $f0, 0x14($v0)
/* 852D78 80240C08 E4420064 */  swc1      $f2, 0x64($v0)
/* 852D7C 80240C0C 34630800 */  ori       $v1, $v1, 0x800
/* 852D80 80240C10 AC430000 */  sw        $v1, ($v0)
/* 852D84 80240C14 AC440028 */  sw        $a0, 0x28($v0)
/* 852D88 80240C18 2402000B */  addiu     $v0, $zero, 0xb
/* 852D8C 80240C1C AE220070 */  sw        $v0, 0x70($s1)
/* 852D90 80240C20 8FBF0018 */  lw        $ra, 0x18($sp)
/* 852D94 80240C24 8FB10014 */  lw        $s1, 0x14($sp)
/* 852D98 80240C28 8FB00010 */  lw        $s0, 0x10($sp)
/* 852D9C 80240C2C 03E00008 */  jr        $ra
/* 852DA0 80240C30 27BD0020 */   addiu    $sp, $sp, 0x20

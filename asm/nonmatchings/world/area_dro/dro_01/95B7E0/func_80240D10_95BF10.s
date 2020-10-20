.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D10_95BF10
/* 95BF10 80240D10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95BF14 80240D14 AFB10014 */  sw        $s1, 0x14($sp)
/* 95BF18 80240D18 0080882D */  daddu     $s1, $a0, $zero
/* 95BF1C 80240D1C AFBF0018 */  sw        $ra, 0x18($sp)
/* 95BF20 80240D20 AFB00010 */  sw        $s0, 0x10($sp)
/* 95BF24 80240D24 8E300148 */  lw        $s0, 0x148($s1)
/* 95BF28 80240D28 0C00EABB */  jal       get_npc_unsafe
/* 95BF2C 80240D2C 86040008 */   lh       $a0, 8($s0)
/* 95BF30 80240D30 8E0300CC */  lw        $v1, 0xcc($s0)
/* 95BF34 80240D34 3C014120 */  lui       $at, 0x4120
/* 95BF38 80240D38 44812000 */  mtc1      $at, $f4
/* 95BF3C 80240D3C 3C014000 */  lui       $at, 0x4000
/* 95BF40 80240D40 44810000 */  mtc1      $at, $f0
/* 95BF44 80240D44 C442003C */  lwc1      $f2, 0x3c($v0)
/* 95BF48 80240D48 8C640010 */  lw        $a0, 0x10($v1)
/* 95BF4C 80240D4C 8C430000 */  lw        $v1, ($v0)
/* 95BF50 80240D50 E444001C */  swc1      $f4, 0x1c($v0)
/* 95BF54 80240D54 E4400014 */  swc1      $f0, 0x14($v0)
/* 95BF58 80240D58 E4420064 */  swc1      $f2, 0x64($v0)
/* 95BF5C 80240D5C 34630800 */  ori       $v1, $v1, 0x800
/* 95BF60 80240D60 AC430000 */  sw        $v1, ($v0)
/* 95BF64 80240D64 AC440028 */  sw        $a0, 0x28($v0)
/* 95BF68 80240D68 2402000B */  addiu     $v0, $zero, 0xb
/* 95BF6C 80240D6C AE220070 */  sw        $v0, 0x70($s1)
/* 95BF70 80240D70 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95BF74 80240D74 8FB10014 */  lw        $s1, 0x14($sp)
/* 95BF78 80240D78 8FB00010 */  lw        $s0, 0x10($sp)
/* 95BF7C 80240D7C 03E00008 */  jr        $ra
/* 95BF80 80240D80 27BD0020 */   addiu    $sp, $sp, 0x20

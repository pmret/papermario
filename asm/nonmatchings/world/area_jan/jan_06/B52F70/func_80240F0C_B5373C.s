.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F0C_B5373C
/* B5373C 80240F0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B53740 80240F10 AFB10014 */  sw        $s1, 0x14($sp)
/* B53744 80240F14 0080882D */  daddu     $s1, $a0, $zero
/* B53748 80240F18 AFBF001C */  sw        $ra, 0x1c($sp)
/* B5374C 80240F1C AFB20018 */  sw        $s2, 0x18($sp)
/* B53750 80240F20 AFB00010 */  sw        $s0, 0x10($sp)
/* B53754 80240F24 8E220148 */  lw        $v0, 0x148($s1)
/* B53758 80240F28 00A0902D */  daddu     $s2, $a1, $zero
/* B5375C 80240F2C 84440008 */  lh        $a0, 8($v0)
/* B53760 80240F30 0C00EABB */  jal       get_npc_unsafe
/* B53764 80240F34 00C0802D */   daddu    $s0, $a2, $zero
/* B53768 80240F38 0220202D */  daddu     $a0, $s1, $zero
/* B5376C 80240F3C 0240282D */  daddu     $a1, $s2, $zero
/* B53770 80240F40 0200302D */  daddu     $a2, $s0, $zero
/* B53774 80240F44 0C0127DF */  jal       func_80049F7C
/* B53778 80240F48 0040802D */   daddu    $s0, $v0, $zero
/* B5377C 80240F4C 8E020000 */  lw        $v0, ($s0)
/* B53780 80240F50 24040005 */  addiu     $a0, $zero, 5
/* B53784 80240F54 34420800 */  ori       $v0, $v0, 0x800
/* B53788 80240F58 0C00A67F */  jal       rand_int
/* B5378C 80240F5C AE020000 */   sw       $v0, ($s0)
/* B53790 80240F60 44820000 */  mtc1      $v0, $f0
/* B53794 80240F64 00000000 */  nop       
/* B53798 80240F68 46800021 */  cvt.d.w   $f0, $f0
/* B5379C 80240F6C 3C014024 */  lui       $at, 0x4024
/* B537A0 80240F70 44811800 */  mtc1      $at, $f3
/* B537A4 80240F74 44801000 */  mtc1      $zero, $f2
/* B537A8 80240F78 3C013FC0 */  lui       $at, 0x3fc0
/* B537AC 80240F7C 44812000 */  mtc1      $at, $f4
/* B537B0 80240F80 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B537B4 80240F84 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B537B8 80240F88 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B537BC 80240F8C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B537C0 80240F90 46220000 */  add.d     $f0, $f0, $f2
/* B537C4 80240F94 E6040014 */  swc1      $f4, 0x14($s0)
/* B537C8 80240F98 46200020 */  cvt.s.d   $f0, $f0
/* B537CC 80240F9C E600001C */  swc1      $f0, 0x1c($s0)
/* B537D0 80240FA0 8C460028 */  lw        $a2, 0x28($v0)
/* B537D4 80240FA4 0C00A720 */  jal       atan2
/* B537D8 80240FA8 8C470030 */   lw       $a3, 0x30($v0)
/* B537DC 80240FAC 0200202D */  daddu     $a0, $s0, $zero
/* B537E0 80240FB0 3C05B000 */  lui       $a1, 0xb000
/* B537E4 80240FB4 34A50017 */  ori       $a1, $a1, 0x17
/* B537E8 80240FB8 0000302D */  daddu     $a2, $zero, $zero
/* B537EC 80240FBC E480000C */  swc1      $f0, 0xc($a0)
/* B537F0 80240FC0 C6400018 */  lwc1      $f0, 0x18($s2)
/* B537F4 80240FC4 2402000D */  addiu     $v0, $zero, 0xd
/* B537F8 80240FC8 E4800018 */  swc1      $f0, 0x18($a0)
/* B537FC 80240FCC 0C012530 */  jal       func_800494C0
/* B53800 80240FD0 AE220070 */   sw       $v0, 0x70($s1)
/* B53804 80240FD4 8FBF001C */  lw        $ra, 0x1c($sp)
/* B53808 80240FD8 8FB20018 */  lw        $s2, 0x18($sp)
/* B5380C 80240FDC 8FB10014 */  lw        $s1, 0x14($sp)
/* B53810 80240FE0 8FB00010 */  lw        $s0, 0x10($sp)
/* B53814 80240FE4 03E00008 */  jr        $ra
/* B53818 80240FE8 27BD0020 */   addiu    $sp, $sp, 0x20

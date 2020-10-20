.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407CC_A00DCC
/* A00DCC 802407CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A00DD0 802407D0 AFB10014 */  sw        $s1, 0x14($sp)
/* A00DD4 802407D4 0080882D */  daddu     $s1, $a0, $zero
/* A00DD8 802407D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* A00DDC 802407DC AFB20018 */  sw        $s2, 0x18($sp)
/* A00DE0 802407E0 AFB00010 */  sw        $s0, 0x10($sp)
/* A00DE4 802407E4 8E220148 */  lw        $v0, 0x148($s1)
/* A00DE8 802407E8 00A0902D */  daddu     $s2, $a1, $zero
/* A00DEC 802407EC 84440008 */  lh        $a0, 8($v0)
/* A00DF0 802407F0 0C00EABB */  jal       get_npc_unsafe
/* A00DF4 802407F4 00C0802D */   daddu    $s0, $a2, $zero
/* A00DF8 802407F8 0220202D */  daddu     $a0, $s1, $zero
/* A00DFC 802407FC 0240282D */  daddu     $a1, $s2, $zero
/* A00E00 80240800 0200302D */  daddu     $a2, $s0, $zero
/* A00E04 80240804 0C0127DF */  jal       func_80049F7C
/* A00E08 80240808 0040802D */   daddu    $s0, $v0, $zero
/* A00E0C 8024080C 8E020000 */  lw        $v0, ($s0)
/* A00E10 80240810 24040005 */  addiu     $a0, $zero, 5
/* A00E14 80240814 34420800 */  ori       $v0, $v0, 0x800
/* A00E18 80240818 0C00A67F */  jal       rand_int
/* A00E1C 8024081C AE020000 */   sw       $v0, ($s0)
/* A00E20 80240820 44820000 */  mtc1      $v0, $f0
/* A00E24 80240824 00000000 */  nop       
/* A00E28 80240828 46800021 */  cvt.d.w   $f0, $f0
/* A00E2C 8024082C 3C014024 */  lui       $at, 0x4024
/* A00E30 80240830 44811800 */  mtc1      $at, $f3
/* A00E34 80240834 44801000 */  mtc1      $zero, $f2
/* A00E38 80240838 3C013FC0 */  lui       $at, 0x3fc0
/* A00E3C 8024083C 44812000 */  mtc1      $at, $f4
/* A00E40 80240840 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A00E44 80240844 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A00E48 80240848 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A00E4C 8024084C C60E0040 */  lwc1      $f14, 0x40($s0)
/* A00E50 80240850 46220000 */  add.d     $f0, $f0, $f2
/* A00E54 80240854 E6040014 */  swc1      $f4, 0x14($s0)
/* A00E58 80240858 46200020 */  cvt.s.d   $f0, $f0
/* A00E5C 8024085C E600001C */  swc1      $f0, 0x1c($s0)
/* A00E60 80240860 8C460028 */  lw        $a2, 0x28($v0)
/* A00E64 80240864 0C00A720 */  jal       atan2
/* A00E68 80240868 8C470030 */   lw       $a3, 0x30($v0)
/* A00E6C 8024086C 0200202D */  daddu     $a0, $s0, $zero
/* A00E70 80240870 3C05B000 */  lui       $a1, 0xb000
/* A00E74 80240874 34A50017 */  ori       $a1, $a1, 0x17
/* A00E78 80240878 0000302D */  daddu     $a2, $zero, $zero
/* A00E7C 8024087C E480000C */  swc1      $f0, 0xc($a0)
/* A00E80 80240880 C6400018 */  lwc1      $f0, 0x18($s2)
/* A00E84 80240884 2402000D */  addiu     $v0, $zero, 0xd
/* A00E88 80240888 E4800018 */  swc1      $f0, 0x18($a0)
/* A00E8C 8024088C 0C012530 */  jal       func_800494C0
/* A00E90 80240890 AE220070 */   sw       $v0, 0x70($s1)
/* A00E94 80240894 8FBF001C */  lw        $ra, 0x1c($sp)
/* A00E98 80240898 8FB20018 */  lw        $s2, 0x18($sp)
/* A00E9C 8024089C 8FB10014 */  lw        $s1, 0x14($sp)
/* A00EA0 802408A0 8FB00010 */  lw        $s0, 0x10($sp)
/* A00EA4 802408A4 03E00008 */  jr        $ra
/* A00EA8 802408A8 27BD0020 */   addiu    $sp, $sp, 0x20

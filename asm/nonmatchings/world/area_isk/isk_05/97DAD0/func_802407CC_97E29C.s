.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407CC_97E29C
/* 97E29C 802407CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97E2A0 802407D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 97E2A4 802407D4 0080882D */  daddu     $s1, $a0, $zero
/* 97E2A8 802407D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 97E2AC 802407DC AFB20018 */  sw        $s2, 0x18($sp)
/* 97E2B0 802407E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 97E2B4 802407E4 8E220148 */  lw        $v0, 0x148($s1)
/* 97E2B8 802407E8 00A0902D */  daddu     $s2, $a1, $zero
/* 97E2BC 802407EC 84440008 */  lh        $a0, 8($v0)
/* 97E2C0 802407F0 0C00EABB */  jal       get_npc_unsafe
/* 97E2C4 802407F4 00C0802D */   daddu    $s0, $a2, $zero
/* 97E2C8 802407F8 0220202D */  daddu     $a0, $s1, $zero
/* 97E2CC 802407FC 0240282D */  daddu     $a1, $s2, $zero
/* 97E2D0 80240800 0200302D */  daddu     $a2, $s0, $zero
/* 97E2D4 80240804 0C0127DF */  jal       func_80049F7C
/* 97E2D8 80240808 0040802D */   daddu    $s0, $v0, $zero
/* 97E2DC 8024080C 8E020000 */  lw        $v0, ($s0)
/* 97E2E0 80240810 24040005 */  addiu     $a0, $zero, 5
/* 97E2E4 80240814 34420800 */  ori       $v0, $v0, 0x800
/* 97E2E8 80240818 0C00A67F */  jal       rand_int
/* 97E2EC 8024081C AE020000 */   sw       $v0, ($s0)
/* 97E2F0 80240820 44820000 */  mtc1      $v0, $f0
/* 97E2F4 80240824 00000000 */  nop       
/* 97E2F8 80240828 46800021 */  cvt.d.w   $f0, $f0
/* 97E2FC 8024082C 3C014024 */  lui       $at, 0x4024
/* 97E300 80240830 44811800 */  mtc1      $at, $f3
/* 97E304 80240834 44801000 */  mtc1      $zero, $f2
/* 97E308 80240838 3C013FC0 */  lui       $at, 0x3fc0
/* 97E30C 8024083C 44812000 */  mtc1      $at, $f4
/* 97E310 80240840 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 97E314 80240844 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 97E318 80240848 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 97E31C 8024084C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 97E320 80240850 46220000 */  add.d     $f0, $f0, $f2
/* 97E324 80240854 E6040014 */  swc1      $f4, 0x14($s0)
/* 97E328 80240858 46200020 */  cvt.s.d   $f0, $f0
/* 97E32C 8024085C E600001C */  swc1      $f0, 0x1c($s0)
/* 97E330 80240860 8C460028 */  lw        $a2, 0x28($v0)
/* 97E334 80240864 0C00A720 */  jal       atan2
/* 97E338 80240868 8C470030 */   lw       $a3, 0x30($v0)
/* 97E33C 8024086C 0200202D */  daddu     $a0, $s0, $zero
/* 97E340 80240870 3C05B000 */  lui       $a1, 0xb000
/* 97E344 80240874 34A50017 */  ori       $a1, $a1, 0x17
/* 97E348 80240878 0000302D */  daddu     $a2, $zero, $zero
/* 97E34C 8024087C E480000C */  swc1      $f0, 0xc($a0)
/* 97E350 80240880 C6400018 */  lwc1      $f0, 0x18($s2)
/* 97E354 80240884 2402000D */  addiu     $v0, $zero, 0xd
/* 97E358 80240888 E4800018 */  swc1      $f0, 0x18($a0)
/* 97E35C 8024088C 0C012530 */  jal       func_800494C0
/* 97E360 80240890 AE220070 */   sw       $v0, 0x70($s1)
/* 97E364 80240894 8FBF001C */  lw        $ra, 0x1c($sp)
/* 97E368 80240898 8FB20018 */  lw        $s2, 0x18($sp)
/* 97E36C 8024089C 8FB10014 */  lw        $s1, 0x14($sp)
/* 97E370 802408A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 97E374 802408A4 03E00008 */  jr        $ra
/* 97E378 802408A8 27BD0020 */   addiu    $sp, $sp, 0x20

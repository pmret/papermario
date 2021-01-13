.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024083C_B9843C
/* B9843C 8024083C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B98440 80240840 AFB10014 */  sw        $s1, 0x14($sp)
/* B98444 80240844 0080882D */  daddu     $s1, $a0, $zero
/* B98448 80240848 AFBF001C */  sw        $ra, 0x1c($sp)
/* B9844C 8024084C AFB20018 */  sw        $s2, 0x18($sp)
/* B98450 80240850 AFB00010 */  sw        $s0, 0x10($sp)
/* B98454 80240854 8E220148 */  lw        $v0, 0x148($s1)
/* B98458 80240858 00A0902D */  daddu     $s2, $a1, $zero
/* B9845C 8024085C 84440008 */  lh        $a0, 8($v0)
/* B98460 80240860 0C00EABB */  jal       get_npc_unsafe
/* B98464 80240864 00C0802D */   daddu    $s0, $a2, $zero
/* B98468 80240868 0220202D */  daddu     $a0, $s1, $zero
/* B9846C 8024086C 0240282D */  daddu     $a1, $s2, $zero
/* B98470 80240870 0200302D */  daddu     $a2, $s0, $zero
/* B98474 80240874 0C0127DF */  jal       func_80049F7C
/* B98478 80240878 0040802D */   daddu    $s0, $v0, $zero
/* B9847C 8024087C 8E020000 */  lw        $v0, ($s0)
/* B98480 80240880 24040005 */  addiu     $a0, $zero, 5
/* B98484 80240884 34420800 */  ori       $v0, $v0, 0x800
/* B98488 80240888 0C00A67F */  jal       rand_int
/* B9848C 8024088C AE020000 */   sw       $v0, ($s0)
/* B98490 80240890 44820000 */  mtc1      $v0, $f0
/* B98494 80240894 00000000 */  nop
/* B98498 80240898 46800021 */  cvt.d.w   $f0, $f0
/* B9849C 8024089C 3C014024 */  lui       $at, 0x4024
/* B984A0 802408A0 44811800 */  mtc1      $at, $f3
/* B984A4 802408A4 44801000 */  mtc1      $zero, $f2
/* B984A8 802408A8 3C013FC0 */  lui       $at, 0x3fc0
/* B984AC 802408AC 44812000 */  mtc1      $at, $f4
/* B984B0 802408B0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B984B4 802408B4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B984B8 802408B8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B984BC 802408BC C60E0040 */  lwc1      $f14, 0x40($s0)
/* B984C0 802408C0 46220000 */  add.d     $f0, $f0, $f2
/* B984C4 802408C4 E6040014 */  swc1      $f4, 0x14($s0)
/* B984C8 802408C8 46200020 */  cvt.s.d   $f0, $f0
/* B984CC 802408CC E600001C */  swc1      $f0, 0x1c($s0)
/* B984D0 802408D0 8C460028 */  lw        $a2, 0x28($v0)
/* B984D4 802408D4 0C00A720 */  jal       atan2
/* B984D8 802408D8 8C470030 */   lw       $a3, 0x30($v0)
/* B984DC 802408DC 0200202D */  daddu     $a0, $s0, $zero
/* B984E0 802408E0 3C05B000 */  lui       $a1, 0xb000
/* B984E4 802408E4 34A50017 */  ori       $a1, $a1, 0x17
/* B984E8 802408E8 0000302D */  daddu     $a2, $zero, $zero
/* B984EC 802408EC E480000C */  swc1      $f0, 0xc($a0)
/* B984F0 802408F0 C6400018 */  lwc1      $f0, 0x18($s2)
/* B984F4 802408F4 2402000D */  addiu     $v0, $zero, 0xd
/* B984F8 802408F8 E4800018 */  swc1      $f0, 0x18($a0)
/* B984FC 802408FC 0C012530 */  jal       func_800494C0
/* B98500 80240900 AE220070 */   sw       $v0, 0x70($s1)
/* B98504 80240904 8FBF001C */  lw        $ra, 0x1c($sp)
/* B98508 80240908 8FB20018 */  lw        $s2, 0x18($sp)
/* B9850C 8024090C 8FB10014 */  lw        $s1, 0x14($sp)
/* B98510 80240910 8FB00010 */  lw        $s0, 0x10($sp)
/* B98514 80240914 03E00008 */  jr        $ra
/* B98518 80240918 27BD0020 */   addiu    $sp, $sp, 0x20

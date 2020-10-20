.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024086C_BB366C
/* BB366C 8024086C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BB3670 80240870 AFB10014 */  sw        $s1, 0x14($sp)
/* BB3674 80240874 0080882D */  daddu     $s1, $a0, $zero
/* BB3678 80240878 AFBF001C */  sw        $ra, 0x1c($sp)
/* BB367C 8024087C AFB20018 */  sw        $s2, 0x18($sp)
/* BB3680 80240880 AFB00010 */  sw        $s0, 0x10($sp)
/* BB3684 80240884 8E220148 */  lw        $v0, 0x148($s1)
/* BB3688 80240888 00A0902D */  daddu     $s2, $a1, $zero
/* BB368C 8024088C 84440008 */  lh        $a0, 8($v0)
/* BB3690 80240890 0C00EABB */  jal       get_npc_unsafe
/* BB3694 80240894 00C0802D */   daddu    $s0, $a2, $zero
/* BB3698 80240898 0220202D */  daddu     $a0, $s1, $zero
/* BB369C 8024089C 0240282D */  daddu     $a1, $s2, $zero
/* BB36A0 802408A0 0200302D */  daddu     $a2, $s0, $zero
/* BB36A4 802408A4 0C0127DF */  jal       func_80049F7C
/* BB36A8 802408A8 0040802D */   daddu    $s0, $v0, $zero
/* BB36AC 802408AC 8E020000 */  lw        $v0, ($s0)
/* BB36B0 802408B0 24040005 */  addiu     $a0, $zero, 5
/* BB36B4 802408B4 34420800 */  ori       $v0, $v0, 0x800
/* BB36B8 802408B8 0C00A67F */  jal       rand_int
/* BB36BC 802408BC AE020000 */   sw       $v0, ($s0)
/* BB36C0 802408C0 44820000 */  mtc1      $v0, $f0
/* BB36C4 802408C4 00000000 */  nop       
/* BB36C8 802408C8 46800021 */  cvt.d.w   $f0, $f0
/* BB36CC 802408CC 3C014024 */  lui       $at, 0x4024
/* BB36D0 802408D0 44811800 */  mtc1      $at, $f3
/* BB36D4 802408D4 44801000 */  mtc1      $zero, $f2
/* BB36D8 802408D8 3C013FC0 */  lui       $at, 0x3fc0
/* BB36DC 802408DC 44812000 */  mtc1      $at, $f4
/* BB36E0 802408E0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BB36E4 802408E4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BB36E8 802408E8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BB36EC 802408EC C60E0040 */  lwc1      $f14, 0x40($s0)
/* BB36F0 802408F0 46220000 */  add.d     $f0, $f0, $f2
/* BB36F4 802408F4 E6040014 */  swc1      $f4, 0x14($s0)
/* BB36F8 802408F8 46200020 */  cvt.s.d   $f0, $f0
/* BB36FC 802408FC E600001C */  swc1      $f0, 0x1c($s0)
/* BB3700 80240900 8C460028 */  lw        $a2, 0x28($v0)
/* BB3704 80240904 0C00A720 */  jal       atan2
/* BB3708 80240908 8C470030 */   lw       $a3, 0x30($v0)
/* BB370C 8024090C 0200202D */  daddu     $a0, $s0, $zero
/* BB3710 80240910 3C05B000 */  lui       $a1, 0xb000
/* BB3714 80240914 34A50017 */  ori       $a1, $a1, 0x17
/* BB3718 80240918 0000302D */  daddu     $a2, $zero, $zero
/* BB371C 8024091C E480000C */  swc1      $f0, 0xc($a0)
/* BB3720 80240920 C6400018 */  lwc1      $f0, 0x18($s2)
/* BB3724 80240924 2402000D */  addiu     $v0, $zero, 0xd
/* BB3728 80240928 E4800018 */  swc1      $f0, 0x18($a0)
/* BB372C 8024092C 0C012530 */  jal       func_800494C0
/* BB3730 80240930 AE220070 */   sw       $v0, 0x70($s1)
/* BB3734 80240934 8FBF001C */  lw        $ra, 0x1c($sp)
/* BB3738 80240938 8FB20018 */  lw        $s2, 0x18($sp)
/* BB373C 8024093C 8FB10014 */  lw        $s1, 0x14($sp)
/* BB3740 80240940 8FB00010 */  lw        $s0, 0x10($sp)
/* BB3744 80240944 03E00008 */  jr        $ra
/* BB3748 80240948 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241070_B4BAE0
/* B4BAE0 80241070 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4BAE4 80241074 AFB10014 */  sw        $s1, 0x14($sp)
/* B4BAE8 80241078 0080882D */  daddu     $s1, $a0, $zero
/* B4BAEC 8024107C AFBF001C */  sw        $ra, 0x1c($sp)
/* B4BAF0 80241080 AFB20018 */  sw        $s2, 0x18($sp)
/* B4BAF4 80241084 AFB00010 */  sw        $s0, 0x10($sp)
/* B4BAF8 80241088 8E220148 */  lw        $v0, 0x148($s1)
/* B4BAFC 8024108C 00A0902D */  daddu     $s2, $a1, $zero
/* B4BB00 80241090 84440008 */  lh        $a0, 8($v0)
/* B4BB04 80241094 0C00EABB */  jal       get_npc_unsafe
/* B4BB08 80241098 00C0802D */   daddu    $s0, $a2, $zero
/* B4BB0C 8024109C 0220202D */  daddu     $a0, $s1, $zero
/* B4BB10 802410A0 0240282D */  daddu     $a1, $s2, $zero
/* B4BB14 802410A4 0200302D */  daddu     $a2, $s0, $zero
/* B4BB18 802410A8 0C0127DF */  jal       func_80049F7C
/* B4BB1C 802410AC 0040802D */   daddu    $s0, $v0, $zero
/* B4BB20 802410B0 8E020000 */  lw        $v0, ($s0)
/* B4BB24 802410B4 24040005 */  addiu     $a0, $zero, 5
/* B4BB28 802410B8 34420800 */  ori       $v0, $v0, 0x800
/* B4BB2C 802410BC 0C00A67F */  jal       rand_int
/* B4BB30 802410C0 AE020000 */   sw       $v0, ($s0)
/* B4BB34 802410C4 44820000 */  mtc1      $v0, $f0
/* B4BB38 802410C8 00000000 */  nop       
/* B4BB3C 802410CC 46800021 */  cvt.d.w   $f0, $f0
/* B4BB40 802410D0 3C014024 */  lui       $at, 0x4024
/* B4BB44 802410D4 44811800 */  mtc1      $at, $f3
/* B4BB48 802410D8 44801000 */  mtc1      $zero, $f2
/* B4BB4C 802410DC 3C013FC0 */  lui       $at, 0x3fc0
/* B4BB50 802410E0 44812000 */  mtc1      $at, $f4
/* B4BB54 802410E4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B4BB58 802410E8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B4BB5C 802410EC C60C0038 */  lwc1      $f12, 0x38($s0)
/* B4BB60 802410F0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B4BB64 802410F4 46220000 */  add.d     $f0, $f0, $f2
/* B4BB68 802410F8 E6040014 */  swc1      $f4, 0x14($s0)
/* B4BB6C 802410FC 46200020 */  cvt.s.d   $f0, $f0
/* B4BB70 80241100 E600001C */  swc1      $f0, 0x1c($s0)
/* B4BB74 80241104 8C460028 */  lw        $a2, 0x28($v0)
/* B4BB78 80241108 0C00A720 */  jal       atan2
/* B4BB7C 8024110C 8C470030 */   lw       $a3, 0x30($v0)
/* B4BB80 80241110 0200202D */  daddu     $a0, $s0, $zero
/* B4BB84 80241114 3C05B000 */  lui       $a1, 0xb000
/* B4BB88 80241118 34A50017 */  ori       $a1, $a1, 0x17
/* B4BB8C 8024111C 0000302D */  daddu     $a2, $zero, $zero
/* B4BB90 80241120 E480000C */  swc1      $f0, 0xc($a0)
/* B4BB94 80241124 C6400018 */  lwc1      $f0, 0x18($s2)
/* B4BB98 80241128 2402000D */  addiu     $v0, $zero, 0xd
/* B4BB9C 8024112C E4800018 */  swc1      $f0, 0x18($a0)
/* B4BBA0 80241130 0C012530 */  jal       func_800494C0
/* B4BBA4 80241134 AE220070 */   sw       $v0, 0x70($s1)
/* B4BBA8 80241138 8FBF001C */  lw        $ra, 0x1c($sp)
/* B4BBAC 8024113C 8FB20018 */  lw        $s2, 0x18($sp)
/* B4BBB0 80241140 8FB10014 */  lw        $s1, 0x14($sp)
/* B4BBB4 80241144 8FB00010 */  lw        $s0, 0x10($sp)
/* B4BBB8 80241148 03E00008 */  jr        $ra
/* B4BBBC 8024114C 27BD0020 */   addiu    $sp, $sp, 0x20

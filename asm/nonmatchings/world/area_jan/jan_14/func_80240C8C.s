.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C8C
/* B7ACDC 80240C8C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B7ACE0 80240C90 AFB10014 */  sw        $s1, 0x14($sp)
/* B7ACE4 80240C94 0080882D */  daddu     $s1, $a0, $zero
/* B7ACE8 80240C98 AFBF001C */  sw        $ra, 0x1c($sp)
/* B7ACEC 80240C9C AFB20018 */  sw        $s2, 0x18($sp)
/* B7ACF0 80240CA0 AFB00010 */  sw        $s0, 0x10($sp)
/* B7ACF4 80240CA4 8E220148 */  lw        $v0, 0x148($s1)
/* B7ACF8 80240CA8 00A0902D */  daddu     $s2, $a1, $zero
/* B7ACFC 80240CAC 84440008 */  lh        $a0, 8($v0)
/* B7AD00 80240CB0 0C00EABB */  jal       get_npc_unsafe
/* B7AD04 80240CB4 00C0802D */   daddu    $s0, $a2, $zero
/* B7AD08 80240CB8 0220202D */  daddu     $a0, $s1, $zero
/* B7AD0C 80240CBC 0240282D */  daddu     $a1, $s2, $zero
/* B7AD10 80240CC0 0200302D */  daddu     $a2, $s0, $zero
/* B7AD14 80240CC4 0C0127DF */  jal       func_80049F7C
/* B7AD18 80240CC8 0040802D */   daddu    $s0, $v0, $zero
/* B7AD1C 80240CCC 8E020000 */  lw        $v0, ($s0)
/* B7AD20 80240CD0 24040005 */  addiu     $a0, $zero, 5
/* B7AD24 80240CD4 34420800 */  ori       $v0, $v0, 0x800
/* B7AD28 80240CD8 0C00A67F */  jal       rand_int
/* B7AD2C 80240CDC AE020000 */   sw       $v0, ($s0)
/* B7AD30 80240CE0 44820000 */  mtc1      $v0, $f0
/* B7AD34 80240CE4 00000000 */  nop       
/* B7AD38 80240CE8 46800021 */  cvt.d.w   $f0, $f0
/* B7AD3C 80240CEC 3C014024 */  lui       $at, 0x4024
/* B7AD40 80240CF0 44811800 */  mtc1      $at, $f3
/* B7AD44 80240CF4 44801000 */  mtc1      $zero, $f2
/* B7AD48 80240CF8 3C013FC0 */  lui       $at, 0x3fc0
/* B7AD4C 80240CFC 44812000 */  mtc1      $at, $f4
/* B7AD50 80240D00 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B7AD54 80240D04 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B7AD58 80240D08 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B7AD5C 80240D0C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B7AD60 80240D10 46220000 */  add.d     $f0, $f0, $f2
/* B7AD64 80240D14 E6040014 */  swc1      $f4, 0x14($s0)
/* B7AD68 80240D18 46200020 */  cvt.s.d   $f0, $f0
/* B7AD6C 80240D1C E600001C */  swc1      $f0, 0x1c($s0)
/* B7AD70 80240D20 8C460028 */  lw        $a2, 0x28($v0)
/* B7AD74 80240D24 0C00A720 */  jal       atan2
/* B7AD78 80240D28 8C470030 */   lw       $a3, 0x30($v0)
/* B7AD7C 80240D2C 0200202D */  daddu     $a0, $s0, $zero
/* B7AD80 80240D30 3C05B000 */  lui       $a1, 0xb000
/* B7AD84 80240D34 34A50017 */  ori       $a1, $a1, 0x17
/* B7AD88 80240D38 0000302D */  daddu     $a2, $zero, $zero
/* B7AD8C 80240D3C E480000C */  swc1      $f0, 0xc($a0)
/* B7AD90 80240D40 C6400018 */  lwc1      $f0, 0x18($s2)
/* B7AD94 80240D44 2402000D */  addiu     $v0, $zero, 0xd
/* B7AD98 80240D48 E4800018 */  swc1      $f0, 0x18($a0)
/* B7AD9C 80240D4C 0C012530 */  jal       func_800494C0
/* B7ADA0 80240D50 AE220070 */   sw       $v0, 0x70($s1)
/* B7ADA4 80240D54 8FBF001C */  lw        $ra, 0x1c($sp)
/* B7ADA8 80240D58 8FB20018 */  lw        $s2, 0x18($sp)
/* B7ADAC 80240D5C 8FB10014 */  lw        $s1, 0x14($sp)
/* B7ADB0 80240D60 8FB00010 */  lw        $s0, 0x10($sp)
/* B7ADB4 80240D64 03E00008 */  jr        $ra
/* B7ADB8 80240D68 27BD0020 */   addiu    $sp, $sp, 0x20

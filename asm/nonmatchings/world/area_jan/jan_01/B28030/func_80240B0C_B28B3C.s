.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B0C_B28B3C
/* B28B3C 80240B0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B28B40 80240B10 AFB10014 */  sw        $s1, 0x14($sp)
/* B28B44 80240B14 0080882D */  daddu     $s1, $a0, $zero
/* B28B48 80240B18 AFBF001C */  sw        $ra, 0x1c($sp)
/* B28B4C 80240B1C AFB20018 */  sw        $s2, 0x18($sp)
/* B28B50 80240B20 AFB00010 */  sw        $s0, 0x10($sp)
/* B28B54 80240B24 8E220148 */  lw        $v0, 0x148($s1)
/* B28B58 80240B28 00A0902D */  daddu     $s2, $a1, $zero
/* B28B5C 80240B2C 84440008 */  lh        $a0, 8($v0)
/* B28B60 80240B30 0C00EABB */  jal       get_npc_unsafe
/* B28B64 80240B34 00C0802D */   daddu    $s0, $a2, $zero
/* B28B68 80240B38 0220202D */  daddu     $a0, $s1, $zero
/* B28B6C 80240B3C 0240282D */  daddu     $a1, $s2, $zero
/* B28B70 80240B40 0200302D */  daddu     $a2, $s0, $zero
/* B28B74 80240B44 0C0127DF */  jal       func_80049F7C
/* B28B78 80240B48 0040802D */   daddu    $s0, $v0, $zero
/* B28B7C 80240B4C 8E020000 */  lw        $v0, ($s0)
/* B28B80 80240B50 24040005 */  addiu     $a0, $zero, 5
/* B28B84 80240B54 34420800 */  ori       $v0, $v0, 0x800
/* B28B88 80240B58 0C00A67F */  jal       rand_int
/* B28B8C 80240B5C AE020000 */   sw       $v0, ($s0)
/* B28B90 80240B60 44820000 */  mtc1      $v0, $f0
/* B28B94 80240B64 00000000 */  nop
/* B28B98 80240B68 46800021 */  cvt.d.w   $f0, $f0
/* B28B9C 80240B6C 3C014024 */  lui       $at, 0x4024
/* B28BA0 80240B70 44811800 */  mtc1      $at, $f3
/* B28BA4 80240B74 44801000 */  mtc1      $zero, $f2
/* B28BA8 80240B78 3C013FC0 */  lui       $at, 0x3fc0
/* B28BAC 80240B7C 44812000 */  mtc1      $at, $f4
/* B28BB0 80240B80 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B28BB4 80240B84 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B28BB8 80240B88 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B28BBC 80240B8C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B28BC0 80240B90 46220000 */  add.d     $f0, $f0, $f2
/* B28BC4 80240B94 E6040014 */  swc1      $f4, 0x14($s0)
/* B28BC8 80240B98 46200020 */  cvt.s.d   $f0, $f0
/* B28BCC 80240B9C E600001C */  swc1      $f0, 0x1c($s0)
/* B28BD0 80240BA0 8C460028 */  lw        $a2, 0x28($v0)
/* B28BD4 80240BA4 0C00A720 */  jal       atan2
/* B28BD8 80240BA8 8C470030 */   lw       $a3, 0x30($v0)
/* B28BDC 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* B28BE0 80240BB0 3C05B000 */  lui       $a1, 0xb000
/* B28BE4 80240BB4 34A50017 */  ori       $a1, $a1, 0x17
/* B28BE8 80240BB8 0000302D */  daddu     $a2, $zero, $zero
/* B28BEC 80240BBC E480000C */  swc1      $f0, 0xc($a0)
/* B28BF0 80240BC0 C6400018 */  lwc1      $f0, 0x18($s2)
/* B28BF4 80240BC4 2402000D */  addiu     $v0, $zero, 0xd
/* B28BF8 80240BC8 E4800018 */  swc1      $f0, 0x18($a0)
/* B28BFC 80240BCC 0C012530 */  jal       func_800494C0
/* B28C00 80240BD0 AE220070 */   sw       $v0, 0x70($s1)
/* B28C04 80240BD4 8FBF001C */  lw        $ra, 0x1c($sp)
/* B28C08 80240BD8 8FB20018 */  lw        $s2, 0x18($sp)
/* B28C0C 80240BDC 8FB10014 */  lw        $s1, 0x14($sp)
/* B28C10 80240BE0 8FB00010 */  lw        $s0, 0x10($sp)
/* B28C14 80240BE4 03E00008 */  jr        $ra
/* B28C18 80240BE8 27BD0020 */   addiu    $sp, $sp, 0x20

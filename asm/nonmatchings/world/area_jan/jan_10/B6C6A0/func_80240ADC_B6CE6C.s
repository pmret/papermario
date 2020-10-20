.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ADC_B6CE6C
/* B6CE6C 80240ADC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B6CE70 80240AE0 AFB10014 */  sw        $s1, 0x14($sp)
/* B6CE74 80240AE4 0080882D */  daddu     $s1, $a0, $zero
/* B6CE78 80240AE8 AFBF001C */  sw        $ra, 0x1c($sp)
/* B6CE7C 80240AEC AFB20018 */  sw        $s2, 0x18($sp)
/* B6CE80 80240AF0 AFB00010 */  sw        $s0, 0x10($sp)
/* B6CE84 80240AF4 8E220148 */  lw        $v0, 0x148($s1)
/* B6CE88 80240AF8 00A0902D */  daddu     $s2, $a1, $zero
/* B6CE8C 80240AFC 84440008 */  lh        $a0, 8($v0)
/* B6CE90 80240B00 0C00EABB */  jal       get_npc_unsafe
/* B6CE94 80240B04 00C0802D */   daddu    $s0, $a2, $zero
/* B6CE98 80240B08 0220202D */  daddu     $a0, $s1, $zero
/* B6CE9C 80240B0C 0240282D */  daddu     $a1, $s2, $zero
/* B6CEA0 80240B10 0200302D */  daddu     $a2, $s0, $zero
/* B6CEA4 80240B14 0C0127DF */  jal       func_80049F7C
/* B6CEA8 80240B18 0040802D */   daddu    $s0, $v0, $zero
/* B6CEAC 80240B1C 8E020000 */  lw        $v0, ($s0)
/* B6CEB0 80240B20 24040005 */  addiu     $a0, $zero, 5
/* B6CEB4 80240B24 34420800 */  ori       $v0, $v0, 0x800
/* B6CEB8 80240B28 0C00A67F */  jal       rand_int
/* B6CEBC 80240B2C AE020000 */   sw       $v0, ($s0)
/* B6CEC0 80240B30 44820000 */  mtc1      $v0, $f0
/* B6CEC4 80240B34 00000000 */  nop       
/* B6CEC8 80240B38 46800021 */  cvt.d.w   $f0, $f0
/* B6CECC 80240B3C 3C014024 */  lui       $at, 0x4024
/* B6CED0 80240B40 44811800 */  mtc1      $at, $f3
/* B6CED4 80240B44 44801000 */  mtc1      $zero, $f2
/* B6CED8 80240B48 3C013FC0 */  lui       $at, 0x3fc0
/* B6CEDC 80240B4C 44812000 */  mtc1      $at, $f4
/* B6CEE0 80240B50 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B6CEE4 80240B54 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B6CEE8 80240B58 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B6CEEC 80240B5C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B6CEF0 80240B60 46220000 */  add.d     $f0, $f0, $f2
/* B6CEF4 80240B64 E6040014 */  swc1      $f4, 0x14($s0)
/* B6CEF8 80240B68 46200020 */  cvt.s.d   $f0, $f0
/* B6CEFC 80240B6C E600001C */  swc1      $f0, 0x1c($s0)
/* B6CF00 80240B70 8C460028 */  lw        $a2, 0x28($v0)
/* B6CF04 80240B74 0C00A720 */  jal       atan2
/* B6CF08 80240B78 8C470030 */   lw       $a3, 0x30($v0)
/* B6CF0C 80240B7C 0200202D */  daddu     $a0, $s0, $zero
/* B6CF10 80240B80 3C05B000 */  lui       $a1, 0xb000
/* B6CF14 80240B84 34A50017 */  ori       $a1, $a1, 0x17
/* B6CF18 80240B88 0000302D */  daddu     $a2, $zero, $zero
/* B6CF1C 80240B8C E480000C */  swc1      $f0, 0xc($a0)
/* B6CF20 80240B90 C6400018 */  lwc1      $f0, 0x18($s2)
/* B6CF24 80240B94 2402000D */  addiu     $v0, $zero, 0xd
/* B6CF28 80240B98 E4800018 */  swc1      $f0, 0x18($a0)
/* B6CF2C 80240B9C 0C012530 */  jal       func_800494C0
/* B6CF30 80240BA0 AE220070 */   sw       $v0, 0x70($s1)
/* B6CF34 80240BA4 8FBF001C */  lw        $ra, 0x1c($sp)
/* B6CF38 80240BA8 8FB20018 */  lw        $s2, 0x18($sp)
/* B6CF3C 80240BAC 8FB10014 */  lw        $s1, 0x14($sp)
/* B6CF40 80240BB0 8FB00010 */  lw        $s0, 0x10($sp)
/* B6CF44 80240BB4 03E00008 */  jr        $ra
/* B6CF48 80240BB8 27BD0020 */   addiu    $sp, $sp, 0x20

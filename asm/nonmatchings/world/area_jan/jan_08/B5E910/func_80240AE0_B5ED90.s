.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE0_B5ED90
/* B5ED90 80240AE0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B5ED94 80240AE4 AFB1001C */  sw        $s1, 0x1c($sp)
/* B5ED98 80240AE8 0080882D */  daddu     $s1, $a0, $zero
/* B5ED9C 80240AEC AFBF0020 */  sw        $ra, 0x20($sp)
/* B5EDA0 80240AF0 AFB00018 */  sw        $s0, 0x18($sp)
/* B5EDA4 80240AF4 8E30000C */  lw        $s0, 0xc($s1)
/* B5EDA8 80240AF8 8E050000 */  lw        $a1, ($s0)
/* B5EDAC 80240AFC 0C0B1EAF */  jal       get_variable
/* B5EDB0 80240B00 26100004 */   addiu    $s0, $s0, 4
/* B5EDB4 80240B04 0C04417A */  jal       get_entity_by_index
/* B5EDB8 80240B08 0040202D */   daddu    $a0, $v0, $zero
/* B5EDBC 80240B0C 8E100000 */  lw        $s0, ($s0)
/* B5EDC0 80240B10 C444004C */  lwc1      $f4, 0x4c($v0)
/* B5EDC4 80240B14 3C014148 */  lui       $at, 0x4148
/* B5EDC8 80240B18 44810000 */  mtc1      $at, $f0
/* B5EDCC 80240B1C 3C013F33 */  lui       $at, 0x3f33
/* B5EDD0 80240B20 34213333 */  ori       $at, $at, 0x3333
/* B5EDD4 80240B24 44811000 */  mtc1      $at, $f2
/* B5EDD8 80240B28 AFA00014 */  sw        $zero, 0x14($sp)
/* B5EDDC 80240B2C 46002100 */  add.s     $f4, $f4, $f0
/* B5EDE0 80240B30 E7A20010 */  swc1      $f2, 0x10($sp)
/* B5EDE4 80240B34 8C450048 */  lw        $a1, 0x48($v0)
/* B5EDE8 80240B38 8C470050 */  lw        $a3, 0x50($v0)
/* B5EDEC 80240B3C 44062000 */  mfc1      $a2, $f4
/* B5EDF0 80240B40 0C01C5D4 */  jal       func_80071750
/* B5EDF4 80240B44 0000202D */   daddu    $a0, $zero, $zero
/* B5EDF8 80240B48 0220202D */  daddu     $a0, $s1, $zero
/* B5EDFC 80240B4C 0200282D */  daddu     $a1, $s0, $zero
/* B5EE00 80240B50 0C0B2026 */  jal       set_variable
/* B5EE04 80240B54 0040302D */   daddu    $a2, $v0, $zero
/* B5EE08 80240B58 8FBF0020 */  lw        $ra, 0x20($sp)
/* B5EE0C 80240B5C 8FB1001C */  lw        $s1, 0x1c($sp)
/* B5EE10 80240B60 8FB00018 */  lw        $s0, 0x18($sp)
/* B5EE14 80240B64 24020002 */  addiu     $v0, $zero, 2
/* B5EE18 80240B68 03E00008 */  jr        $ra
/* B5EE1C 80240B6C 27BD0028 */   addiu    $sp, $sp, 0x28

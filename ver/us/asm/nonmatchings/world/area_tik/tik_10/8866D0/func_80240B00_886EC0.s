.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B00_886EC0
/* 886EC0 80240B00 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 886EC4 80240B04 AFB1001C */  sw        $s1, 0x1c($sp)
/* 886EC8 80240B08 0080882D */  daddu     $s1, $a0, $zero
/* 886ECC 80240B0C AFBF0020 */  sw        $ra, 0x20($sp)
/* 886ED0 80240B10 AFB00018 */  sw        $s0, 0x18($sp)
/* 886ED4 80240B14 8E30000C */  lw        $s0, 0xc($s1)
/* 886ED8 80240B18 8E050000 */  lw        $a1, ($s0)
/* 886EDC 80240B1C 0C0B1EAF */  jal       get_variable
/* 886EE0 80240B20 26100004 */   addiu    $s0, $s0, 4
/* 886EE4 80240B24 0C04417A */  jal       get_entity_by_index
/* 886EE8 80240B28 0040202D */   daddu    $a0, $v0, $zero
/* 886EEC 80240B2C 8E100000 */  lw        $s0, ($s0)
/* 886EF0 80240B30 C444004C */  lwc1      $f4, 0x4c($v0)
/* 886EF4 80240B34 3C014148 */  lui       $at, 0x4148
/* 886EF8 80240B38 44810000 */  mtc1      $at, $f0
/* 886EFC 80240B3C 3C013F33 */  lui       $at, 0x3f33
/* 886F00 80240B40 34213333 */  ori       $at, $at, 0x3333
/* 886F04 80240B44 44811000 */  mtc1      $at, $f2
/* 886F08 80240B48 AFA00014 */  sw        $zero, 0x14($sp)
/* 886F0C 80240B4C 46002100 */  add.s     $f4, $f4, $f0
/* 886F10 80240B50 E7A20010 */  swc1      $f2, 0x10($sp)
/* 886F14 80240B54 8C450048 */  lw        $a1, 0x48($v0)
/* 886F18 80240B58 8C470050 */  lw        $a3, 0x50($v0)
/* 886F1C 80240B5C 44062000 */  mfc1      $a2, $f4
/* 886F20 80240B60 0C01C5D4 */  jal       func_80071750
/* 886F24 80240B64 0000202D */   daddu    $a0, $zero, $zero
/* 886F28 80240B68 0220202D */  daddu     $a0, $s1, $zero
/* 886F2C 80240B6C 0200282D */  daddu     $a1, $s0, $zero
/* 886F30 80240B70 0C0B2026 */  jal       set_variable
/* 886F34 80240B74 0040302D */   daddu    $a2, $v0, $zero
/* 886F38 80240B78 8FBF0020 */  lw        $ra, 0x20($sp)
/* 886F3C 80240B7C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 886F40 80240B80 8FB00018 */  lw        $s0, 0x18($sp)
/* 886F44 80240B84 24020002 */  addiu     $v0, $zero, 2
/* 886F48 80240B88 03E00008 */  jr        $ra
/* 886F4C 80240B8C 27BD0028 */   addiu    $sp, $sp, 0x28

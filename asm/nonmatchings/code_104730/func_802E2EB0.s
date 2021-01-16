.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E2EB0
/* 104730 802E2EB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 104734 802E2EB4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 104738 802E2EB8 0080882D */  daddu     $s1, $a0, $zero
/* 10473C 802E2EBC AFBF0024 */  sw        $ra, 0x24($sp)
/* 104740 802E2EC0 AFB20020 */  sw        $s2, 0x20($sp)
/* 104744 802E2EC4 AFB00018 */  sw        $s0, 0x18($sp)
/* 104748 802E2EC8 8E220040 */  lw        $v0, 0x40($s1)
/* 10474C 802E2ECC C620004C */  lwc1      $f0, 0x4c($s1)
/* 104750 802E2ED0 0000802D */  daddu     $s0, $zero, $zero
/* 104754 802E2ED4 E4400038 */  swc1      $f0, 0x38($v0)
/* 104758 802E2ED8 92240004 */  lbu       $a0, 4($s1)
/* 10475C 802E2EDC 0C0441A9 */  jal       get_entity_type
/* 104760 802E2EE0 0200902D */   daddu    $s2, $s0, $zero
/* 104764 802E2EE4 0040182D */  daddu     $v1, $v0, $zero
/* 104768 802E2EE8 2462FFE8 */  addiu     $v0, $v1, -0x18
/* 10476C 802E2EEC 2C420003 */  sltiu     $v0, $v0, 3
/* 104770 802E2EF0 10400007 */  beqz      $v0, .L802E2F10
/* 104774 802E2EF4 2463FFF3 */   addiu    $v1, $v1, -0xd
/* 104778 802E2EF8 3C013F00 */  lui       $at, 0x3f00
/* 10477C 802E2EFC 44810000 */  mtc1      $at, $f0
/* 104780 802E2F00 00000000 */  nop
/* 104784 802E2F04 E6200054 */  swc1      $f0, 0x54($s1)
/* 104788 802E2F08 E6200058 */  swc1      $f0, 0x58($s1)
/* 10478C 802E2F0C E620005C */  swc1      $f0, 0x5c($s1)
.L802E2F10:
/* 104790 802E2F10 2C62000E */  sltiu     $v0, $v1, 0xe
/* 104794 802E2F14 10400023 */  beqz      $v0, .L802E2FA4
/* 104798 802E2F18 00031080 */   sll      $v0, $v1, 2
/* 10479C 802E2F1C 3C01802F */  lui       $at, %hi(jtbl_802EB160_10C9E0)
/* 1047A0 802E2F20 00220821 */  addu      $at, $at, $v0
/* 1047A4 802E2F24 8C22B160 */  lw        $v0, %lo(jtbl_802EB160_10C9E0)($at)
/* 1047A8 802E2F28 00400008 */  jr        $v0
/* 1047AC 802E2F2C 00000000 */   nop
glabel L802E2F30_1047B0
/* 1047B0 802E2F30 3C120A00 */  lui       $s2, 0xa00
/* 1047B4 802E2F34 265231E0 */  addiu     $s2, $s2, 0x31e0
/* 1047B8 802E2F38 3C100A00 */  lui       $s0, 0xa00
/* 1047BC 802E2F3C 26101508 */  addiu     $s0, $s0, 0x1508
/* 1047C0 802E2F40 080B8BE9 */  j         .L802E2FA4
/* 1047C4 802E2F44 00000000 */   nop
glabel L802E2F48_1047C8
/* 1047C8 802E2F48 3C120A00 */  lui       $s2, 0xa00
/* 1047CC 802E2F4C 265231B0 */  addiu     $s2, $s2, 0x31b0
/* 1047D0 802E2F50 3C100A00 */  lui       $s0, 0xa00
/* 1047D4 802E2F54 261014D8 */  addiu     $s0, $s0, 0x14d8
/* 1047D8 802E2F58 080B8BE9 */  j         .L802E2FA4
/* 1047DC 802E2F5C 00000000 */   nop
glabel L802E2F60_1047E0
/* 1047E0 802E2F60 3C120A00 */  lui       $s2, 0xa00
/* 1047E4 802E2F64 26522F78 */  addiu     $s2, $s2, 0x2f78
/* 1047E8 802E2F68 3C100A00 */  lui       $s0, 0xa00
/* 1047EC 802E2F6C 26101218 */  addiu     $s0, $s0, 0x1218
/* 1047F0 802E2F70 080B8BE9 */  j         .L802E2FA4
/* 1047F4 802E2F74 00000000 */   nop
glabel L802E2F78_1047F8
/* 1047F8 802E2F78 24040158 */  addiu     $a0, $zero, 0x158
/* 1047FC 802E2F7C C6200050 */  lwc1      $f0, 0x50($s1)
/* 104800 802E2F80 3C120A00 */  lui       $s2, 0xa00
/* 104804 802E2F84 26523F70 */  addiu     $s2, $s2, 0x3f70
/* 104808 802E2F88 E7A00010 */  swc1      $f0, 0x10($sp)
/* 10480C 802E2F8C 8E260048 */  lw        $a2, 0x48($s1)
/* 104810 802E2F90 8E27004C */  lw        $a3, 0x4c($s1)
/* 104814 802E2F94 3C100A00 */  lui       $s0, 0xa00
/* 104818 802E2F98 26102318 */  addiu     $s0, $s0, 0x2318
/* 10481C 802E2F9C 0C052757 */  jal       play_sound_at_position
/* 104820 802E2FA0 0000282D */   daddu    $a1, $zero, $zero
.L802E2FA4:
glabel L802E2FA4_104824
/* 104824 802E2FA4 12000004 */  beqz      $s0, .L802E2FB8
/* 104828 802E2FA8 0220202D */   daddu    $a0, $s1, $zero
/* 10482C 802E2FAC 0240282D */  daddu     $a1, $s2, $zero
/* 104830 802E2FB0 0C0B891B */  jal       func_802E246C
/* 104834 802E2FB4 0200302D */   daddu    $a2, $s0, $zero
.L802E2FB8:
/* 104838 802E2FB8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 10483C 802E2FBC 8FB20020 */  lw        $s2, 0x20($sp)
/* 104840 802E2FC0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 104844 802E2FC4 8FB00018 */  lw        $s0, 0x18($sp)
/* 104848 802E2FC8 03E00008 */  jr        $ra
/* 10484C 802E2FCC 27BD0028 */   addiu    $sp, $sp, 0x28

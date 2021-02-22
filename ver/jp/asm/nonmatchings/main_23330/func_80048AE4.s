.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80048AE4
/* 23EE4 80048AE4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 23EE8 80048AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* 23EEC 80048AEC 0080802D */  daddu     $s0, $a0, $zero
/* 23EF0 80048AF0 AFB20018 */  sw        $s2, 0x18($sp)
/* 23EF4 80048AF4 00A0902D */  daddu     $s2, $a1, $zero
/* 23EF8 80048AF8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 23EFC 80048AFC AFB10014 */  sw        $s1, 0x14($sp)
/* 23F00 80048B00 8E02003C */  lw        $v0, 0x3c($s0)
/* 23F04 80048B04 10400005 */  beqz      $v0, .L80048B1C
/* 23F08 80048B08 00C0882D */   daddu    $s1, $a2, $zero
/* 23F0C 80048B0C 8E040054 */  lw        $a0, 0x54($s0)
/* 23F10 80048B10 0C0B102B */  jal       func_802C40AC
/* 23F14 80048B14 00000000 */   nop
/* 23F18 80048B18 AE00003C */  sw        $zero, 0x3c($s0)
.L80048B1C:
/* 23F1C 80048B1C 8E0200BC */  lw        $v0, 0xbc($s0)
/* 23F20 80048B20 10400004 */  beqz      $v0, .L80048B34
/* 23F24 80048B24 00000000 */   nop
/* 23F28 80048B28 0C0B102B */  jal       func_802C40AC
/* 23F2C 80048B2C 8E0400C0 */   lw       $a0, 0xc0($s0)
/* 23F30 80048B30 AE0000BC */  sw        $zero, 0xbc($s0)
.L80048B34:
/* 23F34 80048B34 8E020024 */  lw        $v0, 0x24($s0)
/* 23F38 80048B38 1040000C */  beqz      $v0, .L80048B6C
/* 23F3C 80048B3C 2405000A */   addiu    $a1, $zero, 0xa
/* 23F40 80048B40 0040202D */  daddu     $a0, $v0, $zero
/* 23F44 80048B44 24060020 */  addiu     $a2, $zero, 0x20
/* 23F48 80048B48 0C0B0CF8 */  jal       func_802C33E0
/* 23F4C 80048B4C AE1100C8 */   sw       $s1, 0xc8($s0)
/* 23F50 80048B50 0040202D */  daddu     $a0, $v0, $zero
/* 23F54 80048B54 AE04003C */  sw        $a0, 0x3c($s0)
/* 23F58 80048B58 8C820144 */  lw        $v0, 0x144($a0)
/* 23F5C 80048B5C 86030008 */  lh        $v1, 8($s0)
/* 23F60 80048B60 AE020054 */  sw        $v0, 0x54($s0)
/* 23F64 80048B64 AC83014C */  sw        $v1, 0x14c($a0)
/* 23F68 80048B68 AC900148 */  sw        $s0, 0x148($a0)
.L80048B6C:
/* 23F6C 80048B6C 8E0200B8 */  lw        $v0, 0xb8($s0)
/* 23F70 80048B70 1040000C */  beqz      $v0, .L80048BA4
/* 23F74 80048B74 2405000A */   addiu    $a1, $zero, 0xa
/* 23F78 80048B78 0040202D */  daddu     $a0, $v0, $zero
/* 23F7C 80048B7C 24060020 */  addiu     $a2, $zero, 0x20
/* 23F80 80048B80 0C0B0CF8 */  jal       func_802C33E0
/* 23F84 80048B84 AE1200C4 */   sw       $s2, 0xc4($s0)
/* 23F88 80048B88 0040202D */  daddu     $a0, $v0, $zero
/* 23F8C 80048B8C AE0400BC */  sw        $a0, 0xbc($s0)
/* 23F90 80048B90 8C820144 */  lw        $v0, 0x144($a0)
/* 23F94 80048B94 86030008 */  lh        $v1, 8($s0)
/* 23F98 80048B98 AE0200C0 */  sw        $v0, 0xc0($s0)
/* 23F9C 80048B9C AC83014C */  sw        $v1, 0x14c($a0)
/* 23FA0 80048BA0 AC900148 */  sw        $s0, 0x148($a0)
.L80048BA4:
/* 23FA4 80048BA4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 23FA8 80048BA8 8FB20018 */  lw        $s2, 0x18($sp)
/* 23FAC 80048BAC 8FB10014 */  lw        $s1, 0x14($sp)
/* 23FB0 80048BB0 8FB00010 */  lw        $s0, 0x10($sp)
/* 23FB4 80048BB4 03E00008 */  jr        $ra
/* 23FB8 80048BB8 27BD0020 */   addiu    $sp, $sp, 0x20

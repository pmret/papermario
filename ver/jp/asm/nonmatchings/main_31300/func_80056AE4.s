.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056AE4
/* 31EE4 80056AE4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 31EE8 80056AE8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 31EEC 80056AEC 00E0982D */  daddu     $s3, $a3, $zero
/* 31EF0 80056AF0 AFB20018 */  sw        $s2, 0x18($sp)
/* 31EF4 80056AF4 00059400 */  sll       $s2, $a1, 0x10
/* 31EF8 80056AF8 00129403 */  sra       $s2, $s2, 0x10
/* 31EFC 80056AFC 0240282D */  daddu     $a1, $s2, $zero
/* 31F00 80056B00 AFB10014 */  sw        $s1, 0x14($sp)
/* 31F04 80056B04 00068C00 */  sll       $s1, $a2, 0x10
/* 31F08 80056B08 00118C03 */  sra       $s1, $s1, 0x10
/* 31F0C 80056B0C 308400FF */  andi      $a0, $a0, 0xff
/* 31F10 80056B10 00041040 */  sll       $v0, $a0, 1
/* 31F14 80056B14 3C038008 */  lui       $v1, %hi(D_80078E24)
/* 31F18 80056B18 8C638E24 */  lw        $v1, %lo(D_80078E24)($v1)
/* 31F1C 80056B1C 00441021 */  addu      $v0, $v0, $a0
/* 31F20 80056B20 AFBF0020 */  sw        $ra, 0x20($sp)
/* 31F24 80056B24 AFB00010 */  sw        $s0, 0x10($sp)
/* 31F28 80056B28 8C700020 */  lw        $s0, 0x20($v1)
/* 31F2C 80056B2C 000210C0 */  sll       $v0, $v0, 3
/* 31F30 80056B30 02028021 */  addu      $s0, $s0, $v0
/* 31F34 80056B34 8E040004 */  lw        $a0, 4($s0)
/* 31F38 80056B38 0C016554 */  jal       func_80059550
/* 31F3C 80056B3C 0220302D */   daddu    $a2, $s1, $zero
/* 31F40 80056B40 0240282D */  daddu     $a1, $s2, $zero
/* 31F44 80056B44 0220302D */  daddu     $a2, $s1, $zero
/* 31F48 80056B48 8E040008 */  lw        $a0, 8($s0)
/* 31F4C 80056B4C 0C016554 */  jal       func_80059550
/* 31F50 80056B50 0260382D */   daddu    $a3, $s3, $zero
/* 31F54 80056B54 8FBF0020 */  lw        $ra, 0x20($sp)
/* 31F58 80056B58 8FB3001C */  lw        $s3, 0x1c($sp)
/* 31F5C 80056B5C 8FB20018 */  lw        $s2, 0x18($sp)
/* 31F60 80056B60 8FB10014 */  lw        $s1, 0x14($sp)
/* 31F64 80056B64 8FB00010 */  lw        $s0, 0x10($sp)
/* 31F68 80056B68 03E00008 */  jr        $ra
/* 31F6C 80056B6C 27BD0028 */   addiu    $sp, $sp, 0x28

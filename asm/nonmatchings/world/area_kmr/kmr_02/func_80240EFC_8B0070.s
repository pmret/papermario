.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EFC_8B0F6C
/* 8B0F6C 80240EFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B0F70 80240F00 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B0F74 80240F04 0080882D */  daddu     $s1, $a0, $zero
/* 8B0F78 80240F08 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B0F7C 80240F0C AFB00010 */  sw        $s0, 0x10($sp)
/* 8B0F80 80240F10 8E30000C */  lw        $s0, 0xc($s1)
/* 8B0F84 80240F14 8E050000 */  lw        $a1, ($s0)
/* 8B0F88 80240F18 0C0B1EAF */  jal       get_variable
/* 8B0F8C 80240F1C 26100004 */   addiu    $s0, $s0, 4
/* 8B0F90 80240F20 0220202D */  daddu     $a0, $s1, $zero
/* 8B0F94 80240F24 8E050000 */  lw        $a1, ($s0)
/* 8B0F98 80240F28 0C0B210B */  jal       get_float_variable
/* 8B0F9C 80240F2C 0040802D */   daddu    $s0, $v0, $zero
/* 8B0FA0 80240F30 24020002 */  addiu     $v0, $zero, 2
/* 8B0FA4 80240F34 00501804 */  sllv      $v1, $s0, $v0
/* 8B0FA8 80240F38 00701821 */  addu      $v1, $v1, $s0
/* 8B0FAC 80240F3C 00431804 */  sllv      $v1, $v1, $v0
/* 8B0FB0 80240F40 00701823 */  subu      $v1, $v1, $s0
/* 8B0FB4 80240F44 000320C0 */  sll       $a0, $v1, 3
/* 8B0FB8 80240F48 00641821 */  addu      $v1, $v1, $a0
/* 8B0FBC 80240F4C 000318C0 */  sll       $v1, $v1, 3
/* 8B0FC0 80240F50 3C01800B */  lui       $at, 0x800b
/* 8B0FC4 80240F54 00230821 */  addu      $at, $at, $v1
/* 8B0FC8 80240F58 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 8B0FCC 80240F5C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B0FD0 80240F60 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B0FD4 80240F64 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B0FD8 80240F68 03E00008 */  jr        $ra
/* 8B0FDC 80240F6C 27BD0020 */   addiu    $sp, $sp, 0x20

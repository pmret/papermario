.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005ED70
/* 3A170 8005ED70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A174 8005ED74 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A178 8005ED78 3C10800E */  lui       $s0, %hi(D_800DAA88)
/* 3A17C 8005ED7C 8E10AA88 */  lw        $s0, %lo(D_800DAA88)($s0)
/* 3A180 8005ED80 AFB10014 */  sw        $s1, 0x14($sp)
/* 3A184 8005ED84 0080882D */  daddu     $s1, $a0, $zero
/* 3A188 8005ED88 1200000C */  beqz      $s0, .L8005EDBC
/* 3A18C 8005ED8C AFBF0018 */   sw       $ra, 0x18($sp)
.L8005ED90:
/* 3A190 8005ED90 96020008 */  lhu       $v0, 8($s0)
/* 3A194 8005ED94 96230000 */  lhu       $v1, ($s1)
/* 3A198 8005ED98 00431024 */  and       $v0, $v0, $v1
/* 3A19C 8005ED9C 10400004 */  beqz      $v0, .L8005EDB0
/* 3A1A0 8005EDA0 0220282D */   daddu    $a1, $s1, $zero
/* 3A1A4 8005EDA4 8E040004 */  lw        $a0, 4($s0)
/* 3A1A8 8005EDA8 0C0195FC */  jal       func_800657F0
/* 3A1AC 8005EDAC 0000302D */   daddu    $a2, $zero, $zero
.L8005EDB0:
/* 3A1B0 8005EDB0 8E100000 */  lw        $s0, ($s0)
/* 3A1B4 8005EDB4 1600FFF6 */  bnez      $s0, .L8005ED90
/* 3A1B8 8005EDB8 00000000 */   nop
.L8005EDBC:
/* 3A1BC 8005EDBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A1C0 8005EDC0 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A1C4 8005EDC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A1C8 8005EDC8 03E00008 */  jr        $ra
/* 3A1CC 8005EDCC 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_validate_file_checksum
/* 64F8 8002B0F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 64FC 8002B0FC AFB00010 */  sw        $s0, 0x10($sp)
/* 6500 8002B100 3C058007 */  lui       $a1, %hi(D_800745D0)
/* 6504 8002B104 24A545D0 */  addiu     $a1, $a1, %lo(D_800745D0)
/* 6508 8002B108 AFBF0014 */  sw        $ra, 0x14($sp)
/* 650C 8002B10C 0C01BB5C */  jal       strcmp
/* 6510 8002B110 0080802D */   daddu    $s0, $a0, $zero
/* 6514 8002B114 1440000B */  bnez      $v0, .L8002B144
/* 6518 8002B118 0000102D */   daddu    $v0, $zero, $zero
/* 651C 8002B11C 8E020034 */  lw        $v0, 0x34($s0)
/* 6520 8002B120 8E030030 */  lw        $v1, 0x30($s0)
/* 6524 8002B124 00021027 */  nor       $v0, $zero, $v0
/* 6528 8002B128 54620006 */  bnel      $v1, $v0, .L8002B144
/* 652C 8002B12C 0000102D */   daddu    $v0, $zero, $zero
/* 6530 8002B130 0C00AC34 */  jal       fio_calc_file_checksum
/* 6534 8002B134 0200202D */   daddu    $a0, $s0, $zero
/* 6538 8002B138 8E030030 */  lw        $v1, 0x30($s0)
/* 653C 8002B13C 00431026 */  xor       $v0, $v0, $v1
/* 6540 8002B140 2C420001 */  sltiu     $v0, $v0, 1
.L8002B144:
/* 6544 8002B144 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6548 8002B148 8FB00010 */  lw        $s0, 0x10($sp)
/* 654C 8002B14C 03E00008 */  jr        $ra
/* 6550 8002B150 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FD94
/* 2B194 8004FD94 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2B198 8004FD98 AFB10014 */  sw        $s1, 0x14($sp)
/* 2B19C 8004FD9C 0080882D */  daddu     $s1, $a0, $zero
/* 2B1A0 8004FDA0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 2B1A4 8004FDA4 AFB00010 */  sw        $s0, 0x10($sp)
/* 2B1A8 8004FDA8 962500D6 */  lhu       $a1, 0xd6($s1)
/* 2B1AC 8004FDAC 0C013F02 */  jal       func_8004FC08
/* 2B1B0 8004FDB0 963000D4 */   lhu      $s0, 0xd4($s1)
/* 2B1B4 8004FDB4 1E000002 */  bgtz      $s0, .L8004FDC0
/* 2B1B8 8004FDB8 0040202D */   daddu    $a0, $v0, $zero
/* 2B1BC 8004FDBC 24100001 */  addiu     $s0, $zero, 1
.L8004FDC0:
/* 2B1C0 8004FDC0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 2B1C4 8004FDC4 00821023 */  subu      $v0, $a0, $v0
/* 2B1C8 8004FDC8 16000002 */  bnez      $s0, .L8004FDD4
/* 2B1CC 8004FDCC 0050001A */   div      $zero, $v0, $s0
/* 2B1D0 8004FDD0 0007000D */  break     7
.L8004FDD4:
/* 2B1D4 8004FDD4 2401FFFF */   addiu    $at, $zero, -1
/* 2B1D8 8004FDD8 16010004 */  bne       $s0, $at, .L8004FDEC
/* 2B1DC 8004FDDC 3C018000 */   lui      $at, 0x8000
/* 2B1E0 8004FDE0 14410002 */  bne       $v0, $at, .L8004FDEC
/* 2B1E4 8004FDE4 00000000 */   nop      
/* 2B1E8 8004FDE8 0006000D */  break     6
.L8004FDEC:
/* 2B1EC 8004FDEC 00001012 */   mflo     $v0
/* 2B1F0 8004FDF0 AE3000BC */  sw        $s0, 0xbc($s1)
/* 2B1F4 8004FDF4 AE2400B8 */  sw        $a0, 0xb8($s1)
/* 2B1F8 8004FDF8 AE2200B4 */  sw        $v0, 0xb4($s1)
/* 2B1FC 8004FDFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 2B200 8004FE00 8FB10014 */  lw        $s1, 0x14($sp)
/* 2B204 8004FE04 8FB00010 */  lw        $s0, 0x10($sp)
/* 2B208 8004FE08 03E00008 */  jr        $ra
/* 2B20C 8004FE0C 27BD0020 */   addiu    $sp, $sp, 0x20

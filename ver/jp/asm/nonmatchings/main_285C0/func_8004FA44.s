.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FA44
/* 2AE44 8004FA44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2AE48 8004FA48 AFB10014 */  sw        $s1, 0x14($sp)
/* 2AE4C 8004FA4C 0080882D */  daddu     $s1, $a0, $zero
/* 2AE50 8004FA50 AFBF0018 */  sw        $ra, 0x18($sp)
/* 2AE54 8004FA54 AFB00010 */  sw        $s0, 0x10($sp)
/* 2AE58 8004FA58 962500D6 */  lhu       $a1, 0xd6($s1)
/* 2AE5C 8004FA5C 0C013E2E */  jal       func_8004F8B8
/* 2AE60 8004FA60 963000D4 */   lhu      $s0, 0xd4($s1)
/* 2AE64 8004FA64 1E000002 */  bgtz      $s0, .L8004FA70
/* 2AE68 8004FA68 0040202D */   daddu    $a0, $v0, $zero
/* 2AE6C 8004FA6C 24100001 */  addiu     $s0, $zero, 1
.L8004FA70:
/* 2AE70 8004FA70 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 2AE74 8004FA74 00821023 */  subu      $v0, $a0, $v0
/* 2AE78 8004FA78 16000002 */  bnez      $s0, .L8004FA84
/* 2AE7C 8004FA7C 0050001A */   div      $zero, $v0, $s0
/* 2AE80 8004FA80 0007000D */  break     7
.L8004FA84:
/* 2AE84 8004FA84 2401FFFF */   addiu    $at, $zero, -1
/* 2AE88 8004FA88 16010004 */  bne       $s0, $at, .L8004FA9C
/* 2AE8C 8004FA8C 3C018000 */   lui      $at, 0x8000
/* 2AE90 8004FA90 14410002 */  bne       $v0, $at, .L8004FA9C
/* 2AE94 8004FA94 00000000 */   nop
/* 2AE98 8004FA98 0006000D */  break     6
.L8004FA9C:
/* 2AE9C 8004FA9C 00001012 */   mflo     $v0
/* 2AEA0 8004FAA0 AE3000BC */  sw        $s0, 0xbc($s1)
/* 2AEA4 8004FAA4 AE2400B8 */  sw        $a0, 0xb8($s1)
/* 2AEA8 8004FAA8 AE2200B4 */  sw        $v0, 0xb4($s1)
/* 2AEAC 8004FAAC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 2AEB0 8004FAB0 8FB10014 */  lw        $s1, 0x14($sp)
/* 2AEB4 8004FAB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 2AEB8 8004FAB8 03E00008 */  jr        $ra
/* 2AEBC 8004FABC 27BD0020 */   addiu    $sp, $sp, 0x20

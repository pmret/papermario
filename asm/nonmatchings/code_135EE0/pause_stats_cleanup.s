.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_stats_cleanup
/* 13A2D4 80246F94 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13A2D8 80246F98 AFB10014 */  sw        $s1, 0x14($sp)
/* 13A2DC 80246F9C 0000882D */  daddu     $s1, $zero, $zero
/* 13A2E0 80246FA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 13A2E4 80246FA4 3C108027 */  lui       $s0, 0x8027
/* 13A2E8 80246FA8 26100150 */  addiu     $s0, $s0, 0x150
/* 13A2EC 80246FAC AFBF0018 */  sw        $ra, 0x18($sp)
.L80246FB0:
/* 13A2F0 80246FB0 8E040000 */  lw        $a0, ($s0)
/* 13A2F4 80246FB4 26100004 */  addiu     $s0, $s0, 4
/* 13A2F8 80246FB8 0C05123D */  jal       free_icon
/* 13A2FC 80246FBC 26310001 */   addiu    $s1, $s1, 1
/* 13A300 80246FC0 2A22000C */  slti      $v0, $s1, 0xc
/* 13A304 80246FC4 1440FFFA */  bnez      $v0, .L80246FB0
/* 13A308 80246FC8 00000000 */   nop      
/* 13A30C 80246FCC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 13A310 80246FD0 8FB10014 */  lw        $s1, 0x14($sp)
/* 13A314 80246FD4 8FB00010 */  lw        $s0, 0x10($sp)
/* 13A318 80246FD8 03E00008 */  jr        $ra
/* 13A31C 80246FDC 27BD0020 */   addiu    $sp, $sp, 0x20

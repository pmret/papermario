.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045B10
/* 20F10 80045B10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20F14 80045B14 AFB10014 */  sw        $s1, 0x14($sp)
/* 20F18 80045B18 0000882D */  daddu     $s1, $zero, $zero
/* 20F1C 80045B1C AFB00010 */  sw        $s0, 0x10($sp)
/* 20F20 80045B20 3C10800A */  lui       $s0, 0x800a
/* 20F24 80045B24 26100BC0 */  addiu     $s0, $s0, 0xbc0
/* 20F28 80045B28 AFBF0018 */  sw        $ra, 0x18($sp)
.L80045B2C:
/* 20F2C 80045B2C 8E040018 */  lw        $a0, 0x18($s0)
/* 20F30 80045B30 50800004 */  beql      $a0, $zero, .L80045B44
/* 20F34 80045B34 A6000010 */   sh       $zero, 0x10($s0)
/* 20F38 80045B38 0C00AB4B */  jal       heap_free
/* 20F3C 80045B3C 00000000 */   nop      
/* 20F40 80045B40 A6000010 */  sh        $zero, 0x10($s0)
.L80045B44:
/* 20F44 80045B44 26310001 */  addiu     $s1, $s1, 1
/* 20F48 80045B48 2A220020 */  slti      $v0, $s1, 0x20
/* 20F4C 80045B4C 1440FFF7 */  bnez      $v0, .L80045B2C
/* 20F50 80045B50 2610001C */   addiu    $s0, $s0, 0x1c
/* 20F54 80045B54 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20F58 80045B58 8FB10014 */  lw        $s1, 0x14($sp)
/* 20F5C 80045B5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20F60 80045B60 03E00008 */  jr        $ra
/* 20F64 80045B64 27BD0020 */   addiu    $sp, $sp, 0x20

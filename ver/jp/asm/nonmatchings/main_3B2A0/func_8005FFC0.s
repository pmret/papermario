.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FFC0
/* 3B3C0 8005FFC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B3C4 8005FFC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 3B3C8 8005FFC8 0080802D */  daddu     $s0, $a0, $zero
/* 3B3CC 8005FFCC AFBF0014 */  sw        $ra, 0x14($sp)
/* 3B3D0 8005FFD0 0C018244 */  jal       func_80060910
/* 3B3D4 8005FFD4 24040001 */   addiu    $a0, $zero, 1
/* 3B3D8 8005FFD8 3C018007 */  lui       $at, %hi(D_800773D4)
/* 3B3DC 8005FFDC AC3073D4 */  sw        $s0, %lo(D_800773D4)($at)
/* 3B3E0 8005FFE0 0C018244 */  jal       func_80060910
/* 3B3E4 8005FFE4 0040202D */   daddu    $a0, $v0, $zero
/* 3B3E8 8005FFE8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3B3EC 8005FFEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3B3F0 8005FFF0 03E00008 */  jr        $ra
/* 3B3F4 8005FFF4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3B3F8 8005FFF8 00000000 */  nop
/* 3B3FC 8005FFFC 00000000 */  nop

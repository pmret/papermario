.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C1D4
/* 75D4 8002C1D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 75D8 8002C1D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 75DC 8002C1DC 0080882D */  daddu     $s1, $a0, $zero
/* 75E0 8002C1E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 75E4 8002C1E4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 75E8 8002C1E8 0C01929D */  jal       memcpy
/* 75EC 8002C1EC 00C0802D */   daddu    $s0, $a2, $zero
/* 75F0 8002C1F0 02301021 */  addu      $v0, $s1, $s0
/* 75F4 8002C1F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 75F8 8002C1F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 75FC 8002C1FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7600 8002C200 03E00008 */  jr        $ra
/* 7604 8002C204 27BD0020 */   addiu    $sp, $sp, 0x20

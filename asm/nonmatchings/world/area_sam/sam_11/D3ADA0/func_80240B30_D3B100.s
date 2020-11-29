.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B30_D3B100
/* D3B100 80240B30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3B104 80240B34 AFBF0014 */  sw        $ra, 0x14($sp)
/* D3B108 80240B38 AFB00010 */  sw        $s0, 0x10($sp)
/* D3B10C 80240B3C 0C00EABB */  jal       get_npc_unsafe
/* D3B110 80240B40 8C84014C */   lw       $a0, 0x14c($a0)
/* D3B114 80240B44 24040008 */  addiu     $a0, $zero, 8
/* D3B118 80240B48 0040802D */  daddu     $s0, $v0, $zero
/* D3B11C 80240B4C 3C028024 */  lui       $v0, %hi(D_80240B9C)
/* D3B120 80240B50 24420B9C */  addiu     $v0, $v0, %lo(D_80240B9C)
/* D3B124 80240B54 0C00AB39 */  jal       heap_malloc
/* D3B128 80240B58 AE020008 */   sw       $v0, 8($s0)
/* D3B12C 80240B5C 0040182D */  daddu     $v1, $v0, $zero
/* D3B130 80240B60 AE030020 */  sw        $v1, 0x20($s0)
/* D3B134 80240B64 AC600000 */  sw        $zero, ($v1)
/* D3B138 80240B68 8FBF0014 */  lw        $ra, 0x14($sp)
/* D3B13C 80240B6C 8FB00010 */  lw        $s0, 0x10($sp)
/* D3B140 80240B70 24020001 */  addiu     $v0, $zero, 1
/* D3B144 80240B74 03E00008 */  jr        $ra
/* D3B148 80240B78 27BD0018 */   addiu    $sp, $sp, 0x18

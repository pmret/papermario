.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A60_CF85D0
/* CF85D0 80240A60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF85D4 80240A64 AFBF0014 */  sw        $ra, 0x14($sp)
/* CF85D8 80240A68 AFB00010 */  sw        $s0, 0x10($sp)
/* CF85DC 80240A6C 0C00EABB */  jal       get_npc_unsafe
/* CF85E0 80240A70 8C84014C */   lw       $a0, 0x14c($a0)
/* CF85E4 80240A74 24040008 */  addiu     $a0, $zero, 8
/* CF85E8 80240A78 0040802D */  daddu     $s0, $v0, $zero
/* CF85EC 80240A7C 3C028024 */  lui       $v0, %hi(func_80240ACC_CF863C)
/* CF85F0 80240A80 24420ACC */  addiu     $v0, $v0, %lo(func_80240ACC_CF863C)
/* CF85F4 80240A84 0C00AB39 */  jal       heap_malloc
/* CF85F8 80240A88 AE020008 */   sw       $v0, 8($s0)
/* CF85FC 80240A8C 0040182D */  daddu     $v1, $v0, $zero
/* CF8600 80240A90 AE030020 */  sw        $v1, 0x20($s0)
/* CF8604 80240A94 AC600000 */  sw        $zero, ($v1)
/* CF8608 80240A98 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF860C 80240A9C 8FB00010 */  lw        $s0, 0x10($sp)
/* CF8610 80240AA0 24020001 */  addiu     $v0, $zero, 1
/* CF8614 80240AA4 03E00008 */  jr        $ra
/* CF8618 80240AA8 27BD0018 */   addiu    $sp, $sp, 0x18

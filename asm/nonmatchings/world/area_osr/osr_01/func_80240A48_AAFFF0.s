.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A48_AB0A38
/* AB0A38 80240A48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB0A3C 80240A4C AFB00010 */  sw        $s0, 0x10($sp)
/* AB0A40 80240A50 0080802D */  daddu     $s0, $a0, $zero
/* AB0A44 80240A54 AFBF0014 */  sw        $ra, 0x14($sp)
/* AB0A48 80240A58 0C00EABB */  jal       get_npc_unsafe
/* AB0A4C 80240A5C 8E04008C */   lw       $a0, 0x8c($s0)
/* AB0A50 80240A60 0040282D */  daddu     $a1, $v0, $zero
/* AB0A54 80240A64 8E040094 */  lw        $a0, 0x94($s0)
/* AB0A58 80240A68 8CA30028 */  lw        $v1, 0x28($a1)
/* AB0A5C 80240A6C ACA40028 */  sw        $a0, 0x28($a1)
/* AB0A60 80240A70 8FBF0014 */  lw        $ra, 0x14($sp)
/* AB0A64 80240A74 8FB00010 */  lw        $s0, 0x10($sp)
/* AB0A68 80240A78 24020002 */  addiu     $v0, $zero, 2
/* AB0A6C 80240A7C 3C018024 */  lui       $at, 0x8024
/* AB0A70 80240A80 AC232344 */  sw        $v1, 0x2344($at)
/* AB0A74 80240A84 03E00008 */  jr        $ra
/* AB0A78 80240A88 27BD0018 */   addiu    $sp, $sp, 0x18

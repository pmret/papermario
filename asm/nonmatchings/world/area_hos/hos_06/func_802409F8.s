.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F8
/* A39ED8 802409F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A39EDC 802409FC AFB00010 */  sw        $s0, 0x10($sp)
/* A39EE0 80240A00 0080802D */  daddu     $s0, $a0, $zero
/* A39EE4 80240A04 AFBF0014 */  sw        $ra, 0x14($sp)
/* A39EE8 80240A08 0C00EABB */  jal       get_npc_unsafe
/* A39EEC 80240A0C 8E04008C */   lw       $a0, 0x8c($s0)
/* A39EF0 80240A10 0040282D */  daddu     $a1, $v0, $zero
/* A39EF4 80240A14 8E040094 */  lw        $a0, 0x94($s0)
/* A39EF8 80240A18 8CA30028 */  lw        $v1, 0x28($a1)
/* A39EFC 80240A1C ACA40028 */  sw        $a0, 0x28($a1)
/* A39F00 80240A20 8FBF0014 */  lw        $ra, 0x14($sp)
/* A39F04 80240A24 8FB00010 */  lw        $s0, 0x10($sp)
/* A39F08 80240A28 24020002 */  addiu     $v0, $zero, 2
/* A39F0C 80240A2C 3C018024 */  lui       $at, 0x8024
/* A39F10 80240A30 AC236424 */  sw        $v1, 0x6424($at)
/* A39F14 80240A34 03E00008 */  jr        $ra
/* A39F18 80240A38 27BD0018 */   addiu    $sp, $sp, 0x18

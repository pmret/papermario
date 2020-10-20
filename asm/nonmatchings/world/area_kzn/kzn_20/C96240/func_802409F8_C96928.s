.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F8_C96928
/* C96928 802409F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9692C 802409FC AFB00010 */  sw        $s0, 0x10($sp)
/* C96930 80240A00 0080802D */  daddu     $s0, $a0, $zero
/* C96934 80240A04 AFBF0014 */  sw        $ra, 0x14($sp)
/* C96938 80240A08 0C00EABB */  jal       get_npc_unsafe
/* C9693C 80240A0C 8E04008C */   lw       $a0, 0x8c($s0)
/* C96940 80240A10 0040282D */  daddu     $a1, $v0, $zero
/* C96944 80240A14 8E040094 */  lw        $a0, 0x94($s0)
/* C96948 80240A18 8CA30028 */  lw        $v1, 0x28($a1)
/* C9694C 80240A1C ACA40028 */  sw        $a0, 0x28($a1)
/* C96950 80240A20 8FBF0014 */  lw        $ra, 0x14($sp)
/* C96954 80240A24 8FB00010 */  lw        $s0, 0x10($sp)
/* C96958 80240A28 24020002 */  addiu     $v0, $zero, 2
/* C9695C 80240A2C 3C018024 */  lui       $at, 0x8024
/* C96960 80240A30 AC234494 */  sw        $v1, 0x4494($at)
/* C96964 80240A34 03E00008 */  jr        $ra
/* C96968 80240A38 27BD0018 */   addiu    $sp, $sp, 0x18

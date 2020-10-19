.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EC8_BBE068
/* BBE068 80240EC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBE06C 80240ECC AFB00010 */  sw        $s0, 0x10($sp)
/* BBE070 80240ED0 0080802D */  daddu     $s0, $a0, $zero
/* BBE074 80240ED4 AFBF0014 */  sw        $ra, 0x14($sp)
/* BBE078 80240ED8 0C00EABB */  jal       get_npc_unsafe
/* BBE07C 80240EDC 8E04008C */   lw       $a0, 0x8c($s0)
/* BBE080 80240EE0 0040282D */  daddu     $a1, $v0, $zero
/* BBE084 80240EE4 8E040094 */  lw        $a0, 0x94($s0)
/* BBE088 80240EE8 8CA30028 */  lw        $v1, 0x28($a1)
/* BBE08C 80240EEC ACA40028 */  sw        $a0, 0x28($a1)
/* BBE090 80240EF0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BBE094 80240EF4 8FB00010 */  lw        $s0, 0x10($sp)
/* BBE098 80240EF8 24020002 */  addiu     $v0, $zero, 2
/* BBE09C 80240EFC 3C018024 */  lui       $at, 0x8024
/* BBE0A0 80240F00 AC235AB4 */  sw        $v1, 0x5ab4($at)
/* BBE0A4 80240F04 03E00008 */  jr        $ra
/* BBE0A8 80240F08 27BD0018 */   addiu    $sp, $sp, 0x18

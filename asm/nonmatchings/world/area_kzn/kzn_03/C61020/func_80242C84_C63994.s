.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C84_C63994
/* C63994 80242C84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C63998 80242C88 AFB00010 */  sw        $s0, 0x10($sp)
/* C6399C 80242C8C 0080802D */  daddu     $s0, $a0, $zero
/* C639A0 80242C90 AFBF0014 */  sw        $ra, 0x14($sp)
/* C639A4 80242C94 0C00EABB */  jal       get_npc_unsafe
/* C639A8 80242C98 8E04008C */   lw       $a0, 0x8c($s0)
/* C639AC 80242C9C 0040282D */  daddu     $a1, $v0, $zero
/* C639B0 80242CA0 8E040094 */  lw        $a0, 0x94($s0)
/* C639B4 80242CA4 8CA30028 */  lw        $v1, 0x28($a1)
/* C639B8 80242CA8 ACA40028 */  sw        $a0, 0x28($a1)
/* C639BC 80242CAC 8FBF0014 */  lw        $ra, 0x14($sp)
/* C639C0 80242CB0 8FB00010 */  lw        $s0, 0x10($sp)
/* C639C4 80242CB4 24020002 */  addiu     $v0, $zero, 2
/* C639C8 80242CB8 3C018024 */  lui       $at, 0x8024
/* C639CC 80242CBC AC2375E4 */  sw        $v1, 0x75e4($at)
/* C639D0 80242CC0 03E00008 */  jr        $ra
/* C639D4 80242CC4 27BD0018 */   addiu    $sp, $sp, 0x18

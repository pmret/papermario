.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C84_C88734
/* C88734 80242C84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C88738 80242C88 AFB00010 */  sw        $s0, 0x10($sp)
/* C8873C 80242C8C 0080802D */  daddu     $s0, $a0, $zero
/* C88740 80242C90 AFBF0014 */  sw        $ra, 0x14($sp)
/* C88744 80242C94 0C00EABB */  jal       get_npc_unsafe
/* C88748 80242C98 8E04008C */   lw       $a0, 0x8c($s0)
/* C8874C 80242C9C 0040282D */  daddu     $a1, $v0, $zero
/* C88750 80242CA0 8E040094 */  lw        $a0, 0x94($s0)
/* C88754 80242CA4 8CA30028 */  lw        $v1, 0x28($a1)
/* C88758 80242CA8 ACA40028 */  sw        $a0, 0x28($a1)
/* C8875C 80242CAC 8FBF0014 */  lw        $ra, 0x14($sp)
/* C88760 80242CB0 8FB00010 */  lw        $s0, 0x10($sp)
/* C88764 80242CB4 24020002 */  addiu     $v0, $zero, 2
/* C88768 80242CB8 3C018024 */  lui       $at, %hi(D_802467B4)
/* C8876C 80242CBC AC2367B4 */  sw        $v1, %lo(D_802467B4)($at)
/* C88770 80242CC0 03E00008 */  jr        $ra
/* C88774 80242CC4 27BD0018 */   addiu    $sp, $sp, 0x18

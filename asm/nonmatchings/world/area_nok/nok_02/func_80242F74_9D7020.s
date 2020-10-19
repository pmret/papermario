.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F74_9D9F94
/* 9D9F94 80242F74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9F98 80242F78 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D9F9C 80242F7C 0080802D */  daddu     $s0, $a0, $zero
/* 9D9FA0 80242F80 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9D9FA4 80242F84 0C00EABB */  jal       get_npc_unsafe
/* 9D9FA8 80242F88 8E04008C */   lw       $a0, 0x8c($s0)
/* 9D9FAC 80242F8C 0040282D */  daddu     $a1, $v0, $zero
/* 9D9FB0 80242F90 8E040094 */  lw        $a0, 0x94($s0)
/* 9D9FB4 80242F94 8CA30028 */  lw        $v1, 0x28($a1)
/* 9D9FB8 80242F98 ACA40028 */  sw        $a0, 0x28($a1)
/* 9D9FBC 80242F9C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9D9FC0 80242FA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9FC4 80242FA4 24020002 */  addiu     $v0, $zero, 2
/* 9D9FC8 80242FA8 3C018025 */  lui       $at, 0x8025
/* 9D9FCC 80242FAC AC234B94 */  sw        $v1, 0x4b94($at)
/* 9D9FD0 80242FB0 03E00008 */  jr        $ra
/* 9D9FD4 80242FB4 27BD0018 */   addiu    $sp, $sp, 0x18

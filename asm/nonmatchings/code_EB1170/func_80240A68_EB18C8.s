.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A68_EB18C8
/* EB18C8 80240A68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB18CC 80240A6C 0000202D */  daddu     $a0, $zero, $zero
/* EB18D0 80240A70 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB18D4 80240A74 0C0166B2 */  jal       func_80059AC8
/* EB18D8 80240A78 24050001 */   addiu    $a1, $zero, 1
/* EB18DC 80240A7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB18E0 80240A80 24020002 */  addiu     $v0, $zero, 2
/* EB18E4 80240A84 03E00008 */  jr        $ra
/* EB18E8 80240A88 27BD0018 */   addiu    $sp, $sp, 0x18

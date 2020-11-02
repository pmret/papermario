.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A68_A39F48
/* A39F48 80240A68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A39F4C 80240A6C AFBF0010 */  sw        $ra, 0x10($sp)
/* A39F50 80240A70 8C82000C */  lw        $v0, 0xc($a0)
/* A39F54 80240A74 3C068011 */  lui       $a2, %hi(gPlayerData+0xF)
/* A39F58 80240A78 90C6F29F */  lbu       $a2, %lo(gPlayerData+0xF)($a2)
/* A39F5C 80240A7C 0C0B2026 */  jal       set_variable
/* A39F60 80240A80 8C450000 */   lw       $a1, ($v0)
/* A39F64 80240A84 8FBF0010 */  lw        $ra, 0x10($sp)
/* A39F68 80240A88 24020002 */  addiu     $v0, $zero, 2
/* A39F6C 80240A8C 03E00008 */  jr        $ra
/* A39F70 80240A90 27BD0018 */   addiu    $sp, $sp, 0x18

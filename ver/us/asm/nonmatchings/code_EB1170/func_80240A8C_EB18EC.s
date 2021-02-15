.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A8C_EB18EC
/* EB18EC 80240A8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB18F0 80240A90 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB18F4 80240A94 8C82000C */  lw        $v0, 0xc($a0)
/* EB18F8 80240A98 3C068017 */  lui       $a2, %hi(D_80169B12)
/* EB18FC 80240A9C 84C69B12 */  lh        $a2, %lo(D_80169B12)($a2)
/* EB1900 80240AA0 0C0B551A */  jal       func_802D5468
/* EB1904 80240AA4 8C450000 */   lw       $a1, ($v0)
/* EB1908 80240AA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB190C 80240AAC 24020002 */  addiu     $v0, $zero, 2
/* EB1910 80240AB0 03E00008 */  jr        $ra
/* EB1914 80240AB4 27BD0018 */   addiu    $sp, $sp, 0x18
/* EB1918 80240AB8 00000000 */  nop
/* EB191C 80240ABC 00000000 */  nop

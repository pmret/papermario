.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F8_EB1858
/* EB1858 802409F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB185C 802409FC AFB00010 */  sw        $s0, 0x10($sp)
/* EB1860 80240A00 0080802D */  daddu     $s0, $a0, $zero
/* EB1864 80240A04 AFBF0014 */  sw        $ra, 0x14($sp)
/* EB1868 80240A08 0C00F92F */  jal       func_8003E4BC
/* EB186C 80240A0C 8E04008C */   lw       $a0, 0x8c($s0)
/* EB1870 80240A10 0040282D */  daddu     $a1, $v0, $zero
/* EB1874 80240A14 8E040094 */  lw        $a0, 0x94($s0)
/* EB1878 80240A18 8CA30028 */  lw        $v1, 0x28($a1)
/* EB187C 80240A1C ACA40028 */  sw        $a0, 0x28($a1)
/* EB1880 80240A20 8FBF0014 */  lw        $ra, 0x14($sp)
/* EB1884 80240A24 8FB00010 */  lw        $s0, 0x10($sp)
/* EB1888 80240A28 24020002 */  addiu     $v0, $zero, 2
/* EB188C 80240A2C 3C018024 */  lui       $at, %hi(D_80244494)
/* EB1890 80240A30 AC234494 */  sw        $v1, %lo(D_80244494)($at)
/* EB1894 80240A34 03E00008 */  jr        $ra
/* EB1898 80240A38 27BD0018 */   addiu    $sp, $sp, 0x18

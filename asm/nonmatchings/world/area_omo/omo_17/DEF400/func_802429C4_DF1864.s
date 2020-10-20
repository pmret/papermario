.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429C4_DF1864
/* DF1864 802429C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF1868 802429C8 AFB00010 */  sw        $s0, 0x10($sp)
/* DF186C 802429CC 0080802D */  daddu     $s0, $a0, $zero
/* DF1870 802429D0 AFBF0014 */  sw        $ra, 0x14($sp)
/* DF1874 802429D4 8E020148 */  lw        $v0, 0x148($s0)
/* DF1878 802429D8 0C00EABB */  jal       get_npc_unsafe
/* DF187C 802429DC 84440008 */   lh       $a0, 8($v0)
/* DF1880 802429E0 9443008E */  lhu       $v1, 0x8e($v0)
/* DF1884 802429E4 2463FFFF */  addiu     $v1, $v1, -1
/* DF1888 802429E8 A443008E */  sh        $v1, 0x8e($v0)
/* DF188C 802429EC 00031C00 */  sll       $v1, $v1, 0x10
/* DF1890 802429F0 58600001 */  blezl     $v1, .L802429F8
/* DF1894 802429F4 AE000070 */   sw       $zero, 0x70($s0)
.L802429F8:
/* DF1898 802429F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* DF189C 802429FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DF18A0 80242A00 03E00008 */  jr        $ra
/* DF18A4 80242A04 27BD0018 */   addiu    $sp, $sp, 0x18

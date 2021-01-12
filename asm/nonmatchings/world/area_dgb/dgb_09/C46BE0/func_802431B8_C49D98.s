.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802431B8_C49D98
/* C49D98 802431B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C49D9C 802431BC AFB20018 */  sw        $s2, 0x18($sp)
/* C49DA0 802431C0 0080902D */  daddu     $s2, $a0, $zero
/* C49DA4 802431C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* C49DA8 802431C8 AFB10014 */  sw        $s1, 0x14($sp)
/* C49DAC 802431CC AFB00010 */  sw        $s0, 0x10($sp)
/* C49DB0 802431D0 8E500148 */  lw        $s0, 0x148($s2)
/* C49DB4 802431D4 86040008 */  lh        $a0, 8($s0)
/* C49DB8 802431D8 0C00EABB */  jal       get_npc_unsafe
/* C49DBC 802431DC 00A0882D */   daddu    $s1, $a1, $zero
/* C49DC0 802431E0 3C05FFDF */  lui       $a1, 0xffdf
/* C49DC4 802431E4 8E03006C */  lw        $v1, 0x6c($s0)
/* C49DC8 802431E8 2404FEFF */  addiu     $a0, $zero, -0x101
/* C49DCC 802431EC 00641824 */  and       $v1, $v1, $a0
/* C49DD0 802431F0 AE03006C */  sw        $v1, 0x6c($s0)
/* C49DD4 802431F4 8C430000 */  lw        $v1, ($v0)
/* C49DD8 802431F8 34A5FFFF */  ori       $a1, $a1, 0xffff
/* C49DDC 802431FC 00651824 */  and       $v1, $v1, $a1
/* C49DE0 80243200 AC430000 */  sw        $v1, ($v0)
/* C49DE4 80243204 C6200000 */  lwc1      $f0, ($s1)
/* C49DE8 80243208 46000021 */  cvt.d.s   $f0, $f0
/* C49DEC 8024320C 46200000 */  add.d     $f0, $f0, $f0
/* C49DF0 80243210 46200020 */  cvt.s.d   $f0, $f0
/* C49DF4 80243214 E4400018 */  swc1      $f0, 0x18($v0)
/* C49DF8 80243218 AE000074 */  sw        $zero, 0x74($s0)
/* C49DFC 8024321C C440003C */  lwc1      $f0, 0x3c($v0)
/* C49E00 80243220 3C014059 */  lui       $at, 0x4059
/* C49E04 80243224 44811800 */  mtc1      $at, $f3
/* C49E08 80243228 44801000 */  mtc1      $zero, $f2
/* C49E0C 8024322C 46000021 */  cvt.d.s   $f0, $f0
/* C49E10 80243230 46220002 */  mul.d     $f0, $f0, $f2
/* C49E14 80243234 00000000 */  nop
/* C49E18 80243238 2402001E */  addiu     $v0, $zero, 0x1e
/* C49E1C 8024323C 4620010D */  trunc.w.d $f4, $f0
/* C49E20 80243240 E604007C */  swc1      $f4, 0x7c($s0)
/* C49E24 80243244 AE420074 */  sw        $v0, 0x74($s2)
/* C49E28 80243248 8FBF001C */  lw        $ra, 0x1c($sp)
/* C49E2C 8024324C 8FB20018 */  lw        $s2, 0x18($sp)
/* C49E30 80243250 8FB10014 */  lw        $s1, 0x14($sp)
/* C49E34 80243254 8FB00010 */  lw        $s0, 0x10($sp)
/* C49E38 80243258 03E00008 */  jr        $ra
/* C49E3C 8024325C 27BD0020 */   addiu    $sp, $sp, 0x20

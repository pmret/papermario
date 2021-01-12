.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D94_C382C4
/* C382C4 80241D94 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C382C8 80241D98 AFB20018 */  sw        $s2, 0x18($sp)
/* C382CC 80241D9C 0080902D */  daddu     $s2, $a0, $zero
/* C382D0 80241DA0 AFBF001C */  sw        $ra, 0x1c($sp)
/* C382D4 80241DA4 AFB10014 */  sw        $s1, 0x14($sp)
/* C382D8 80241DA8 AFB00010 */  sw        $s0, 0x10($sp)
/* C382DC 80241DAC 8E500148 */  lw        $s0, 0x148($s2)
/* C382E0 80241DB0 86040008 */  lh        $a0, 8($s0)
/* C382E4 80241DB4 0C00EABB */  jal       get_npc_unsafe
/* C382E8 80241DB8 00A0882D */   daddu    $s1, $a1, $zero
/* C382EC 80241DBC 3C05FFDF */  lui       $a1, 0xffdf
/* C382F0 80241DC0 8E03006C */  lw        $v1, 0x6c($s0)
/* C382F4 80241DC4 2404FEFF */  addiu     $a0, $zero, -0x101
/* C382F8 80241DC8 00641824 */  and       $v1, $v1, $a0
/* C382FC 80241DCC AE03006C */  sw        $v1, 0x6c($s0)
/* C38300 80241DD0 8C430000 */  lw        $v1, ($v0)
/* C38304 80241DD4 34A5FFFF */  ori       $a1, $a1, 0xffff
/* C38308 80241DD8 00651824 */  and       $v1, $v1, $a1
/* C3830C 80241DDC AC430000 */  sw        $v1, ($v0)
/* C38310 80241DE0 C6200000 */  lwc1      $f0, ($s1)
/* C38314 80241DE4 46000021 */  cvt.d.s   $f0, $f0
/* C38318 80241DE8 46200000 */  add.d     $f0, $f0, $f0
/* C3831C 80241DEC 46200020 */  cvt.s.d   $f0, $f0
/* C38320 80241DF0 E4400018 */  swc1      $f0, 0x18($v0)
/* C38324 80241DF4 AE000074 */  sw        $zero, 0x74($s0)
/* C38328 80241DF8 C440003C */  lwc1      $f0, 0x3c($v0)
/* C3832C 80241DFC 3C014059 */  lui       $at, 0x4059
/* C38330 80241E00 44811800 */  mtc1      $at, $f3
/* C38334 80241E04 44801000 */  mtc1      $zero, $f2
/* C38338 80241E08 46000021 */  cvt.d.s   $f0, $f0
/* C3833C 80241E0C 46220002 */  mul.d     $f0, $f0, $f2
/* C38340 80241E10 00000000 */  nop
/* C38344 80241E14 2402001E */  addiu     $v0, $zero, 0x1e
/* C38348 80241E18 4620010D */  trunc.w.d $f4, $f0
/* C3834C 80241E1C E604007C */  swc1      $f4, 0x7c($s0)
/* C38350 80241E20 AE420074 */  sw        $v0, 0x74($s2)
/* C38354 80241E24 8FBF001C */  lw        $ra, 0x1c($sp)
/* C38358 80241E28 8FB20018 */  lw        $s2, 0x18($sp)
/* C3835C 80241E2C 8FB10014 */  lw        $s1, 0x14($sp)
/* C38360 80241E30 8FB00010 */  lw        $s0, 0x10($sp)
/* C38364 80241E34 03E00008 */  jr        $ra
/* C38368 80241E38 27BD0020 */   addiu    $sp, $sp, 0x20

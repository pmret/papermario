.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EF0_BFF770
/* BFF770 80241EF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BFF774 80241EF4 AFB20018 */  sw        $s2, 0x18($sp)
/* BFF778 80241EF8 0080902D */  daddu     $s2, $a0, $zero
/* BFF77C 80241EFC AFBF001C */  sw        $ra, 0x1c($sp)
/* BFF780 80241F00 AFB10014 */  sw        $s1, 0x14($sp)
/* BFF784 80241F04 AFB00010 */  sw        $s0, 0x10($sp)
/* BFF788 80241F08 8E500148 */  lw        $s0, 0x148($s2)
/* BFF78C 80241F0C 86040008 */  lh        $a0, 8($s0)
/* BFF790 80241F10 0C00EABB */  jal       get_npc_unsafe
/* BFF794 80241F14 00A0882D */   daddu    $s1, $a1, $zero
/* BFF798 80241F18 3C05FFDF */  lui       $a1, 0xffdf
/* BFF79C 80241F1C 8E03006C */  lw        $v1, 0x6c($s0)
/* BFF7A0 80241F20 2404FEFF */  addiu     $a0, $zero, -0x101
/* BFF7A4 80241F24 00641824 */  and       $v1, $v1, $a0
/* BFF7A8 80241F28 AE03006C */  sw        $v1, 0x6c($s0)
/* BFF7AC 80241F2C 8C430000 */  lw        $v1, ($v0)
/* BFF7B0 80241F30 34A5FFFF */  ori       $a1, $a1, 0xffff
/* BFF7B4 80241F34 00651824 */  and       $v1, $v1, $a1
/* BFF7B8 80241F38 AC430000 */  sw        $v1, ($v0)
/* BFF7BC 80241F3C C6200000 */  lwc1      $f0, ($s1)
/* BFF7C0 80241F40 46000021 */  cvt.d.s   $f0, $f0
/* BFF7C4 80241F44 46200000 */  add.d     $f0, $f0, $f0
/* BFF7C8 80241F48 46200020 */  cvt.s.d   $f0, $f0
/* BFF7CC 80241F4C E4400018 */  swc1      $f0, 0x18($v0)
/* BFF7D0 80241F50 AE000074 */  sw        $zero, 0x74($s0)
/* BFF7D4 80241F54 C440003C */  lwc1      $f0, 0x3c($v0)
/* BFF7D8 80241F58 3C014059 */  lui       $at, 0x4059
/* BFF7DC 80241F5C 44811800 */  mtc1      $at, $f3
/* BFF7E0 80241F60 44801000 */  mtc1      $zero, $f2
/* BFF7E4 80241F64 46000021 */  cvt.d.s   $f0, $f0
/* BFF7E8 80241F68 46220002 */  mul.d     $f0, $f0, $f2
/* BFF7EC 80241F6C 00000000 */  nop       
/* BFF7F0 80241F70 2402001E */  addiu     $v0, $zero, 0x1e
/* BFF7F4 80241F74 4620010D */  trunc.w.d $f4, $f0
/* BFF7F8 80241F78 E604007C */  swc1      $f4, 0x7c($s0)
/* BFF7FC 80241F7C AE420074 */  sw        $v0, 0x74($s2)
/* BFF800 80241F80 8FBF001C */  lw        $ra, 0x1c($sp)
/* BFF804 80241F84 8FB20018 */  lw        $s2, 0x18($sp)
/* BFF808 80241F88 8FB10014 */  lw        $s1, 0x14($sp)
/* BFF80C 80241F8C 8FB00010 */  lw        $s0, 0x10($sp)
/* BFF810 80241F90 03E00008 */  jr        $ra
/* BFF814 80241F94 27BD0020 */   addiu    $sp, $sp, 0x20

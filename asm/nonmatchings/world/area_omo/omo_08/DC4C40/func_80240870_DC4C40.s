.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_DC4C40
/* DC4C40 80240870 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DC4C44 80240874 AFB10014 */  sw        $s1, 0x14($sp)
/* DC4C48 80240878 0080882D */  daddu     $s1, $a0, $zero
/* DC4C4C 8024087C AFBF0018 */  sw        $ra, 0x18($sp)
/* DC4C50 80240880 AFB00010 */  sw        $s0, 0x10($sp)
/* DC4C54 80240884 8E300148 */  lw        $s0, 0x148($s1)
/* DC4C58 80240888 0C00EABB */  jal       get_npc_unsafe
/* DC4C5C 8024088C 86040008 */   lh       $a0, 8($s0)
/* DC4C60 80240890 C4400018 */  lwc1      $f0, 0x18($v0)
/* DC4C64 80240894 3C018025 */  lui       $at, %hi(D_80248760)
/* DC4C68 80240898 D4228760 */  ldc1      $f2, %lo(D_80248760)($at)
/* DC4C6C 8024089C 46000021 */  cvt.d.s   $f0, $f0
/* DC4C70 802408A0 46220002 */  mul.d     $f0, $f0, $f2
/* DC4C74 802408A4 00000000 */  nop       
/* DC4C78 802408A8 46200020 */  cvt.s.d   $f0, $f0
/* DC4C7C 802408AC E4400018 */  swc1      $f0, 0x18($v0)
/* DC4C80 802408B0 8E0300CC */  lw        $v1, 0xcc($s0)
/* DC4C84 802408B4 8C640030 */  lw        $a0, 0x30($v1)
/* DC4C88 802408B8 24030005 */  addiu     $v1, $zero, 5
/* DC4C8C 802408BC A443008E */  sh        $v1, 0x8e($v0)
/* DC4C90 802408C0 AC440028 */  sw        $a0, 0x28($v0)
/* DC4C94 802408C4 2402000F */  addiu     $v0, $zero, 0xf
/* DC4C98 802408C8 AE220070 */  sw        $v0, 0x70($s1)
/* DC4C9C 802408CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DC4CA0 802408D0 8FB10014 */  lw        $s1, 0x14($sp)
/* DC4CA4 802408D4 8FB00010 */  lw        $s0, 0x10($sp)
/* DC4CA8 802408D8 03E00008 */  jr        $ra
/* DC4CAC 802408DC 27BD0020 */   addiu    $sp, $sp, 0x20

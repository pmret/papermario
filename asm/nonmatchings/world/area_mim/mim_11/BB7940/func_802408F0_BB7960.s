.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408F0_BB7960
/* BB7960 802408F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BB7964 802408F4 AFB10014 */  sw        $s1, 0x14($sp)
/* BB7968 802408F8 0080882D */  daddu     $s1, $a0, $zero
/* BB796C 802408FC AFBF0018 */  sw        $ra, 0x18($sp)
/* BB7970 80240900 10A00005 */  beqz      $a1, .L80240918
/* BB7974 80240904 AFB00010 */   sw       $s0, 0x10($sp)
/* BB7978 80240908 8E24014C */  lw        $a0, 0x14c($s1)
/* BB797C 8024090C 0C00EAD2 */  jal       get_npc_safe
/* BB7980 80240910 AE200074 */   sw       $zero, 0x74($s1)
/* BB7984 80240914 AE220078 */  sw        $v0, 0x78($s1)
.L80240918:
/* BB7988 80240918 C62C0074 */  lwc1      $f12, 0x74($s1)
/* BB798C 8024091C 0C00A8BB */  jal       sin_deg
/* BB7990 80240920 8E300078 */   lw       $s0, 0x78($s1)
/* BB7994 80240924 3C0140C0 */  lui       $at, 0x40c0
/* BB7998 80240928 44811000 */  mtc1      $at, $f2
/* BB799C 8024092C 00000000 */  nop
/* BB79A0 80240930 46020002 */  mul.s     $f0, $f0, $f2
/* BB79A4 80240934 00000000 */  nop
/* BB79A8 80240938 3C014190 */  lui       $at, 0x4190
/* BB79AC 8024093C 44816000 */  mtc1      $at, $f12
/* BB79B0 80240940 4600010D */  trunc.w.s $f4, $f0
/* BB79B4 80240944 44022000 */  mfc1      $v0, $f4
/* BB79B8 80240948 00000000 */  nop
/* BB79BC 8024094C A20200AB */  sb        $v0, 0xab($s0)
/* BB79C0 80240950 C6200074 */  lwc1      $f0, 0x74($s1)
/* BB79C4 80240954 0C00A6C9 */  jal       clamp_angle
/* BB79C8 80240958 460C0300 */   add.s    $f12, $f0, $f12
/* BB79CC 8024095C E6200074 */  swc1      $f0, 0x74($s1)
/* BB79D0 80240960 8FBF0018 */  lw        $ra, 0x18($sp)
/* BB79D4 80240964 8FB10014 */  lw        $s1, 0x14($sp)
/* BB79D8 80240968 8FB00010 */  lw        $s0, 0x10($sp)
/* BB79DC 8024096C 0000102D */  daddu     $v0, $zero, $zero
/* BB79E0 80240970 03E00008 */  jr        $ra
/* BB79E4 80240974 27BD0020 */   addiu    $sp, $sp, 0x20
/* BB79E8 80240978 00000000 */  nop
/* BB79EC 8024097C 00000000 */  nop

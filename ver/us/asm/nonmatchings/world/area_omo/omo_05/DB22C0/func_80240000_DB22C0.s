.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DB22C0
/* DB22C0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB22C4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* DB22C8 80240008 0080882D */  daddu     $s1, $a0, $zero
/* DB22CC 8024000C AFBF0018 */  sw        $ra, 0x18($sp)
/* DB22D0 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* DB22D4 80240014 8E300148 */  lw        $s0, 0x148($s1)
/* DB22D8 80240018 0C00EABB */  jal       get_npc_unsafe
/* DB22DC 8024001C 86040008 */   lh       $a0, 8($s0)
/* DB22E0 80240020 C4400018 */  lwc1      $f0, 0x18($v0)
/* DB22E4 80240024 3C018024 */  lui       $at, %hi(D_802452B0_DB7570)
/* DB22E8 80240028 D42252B0 */  ldc1      $f2, %lo(D_802452B0_DB7570)($at)
/* DB22EC 8024002C 46000021 */  cvt.d.s   $f0, $f0
/* DB22F0 80240030 46220002 */  mul.d     $f0, $f0, $f2
/* DB22F4 80240034 00000000 */  nop
/* DB22F8 80240038 46200020 */  cvt.s.d   $f0, $f0
/* DB22FC 8024003C E4400018 */  swc1      $f0, 0x18($v0)
/* DB2300 80240040 8E0300CC */  lw        $v1, 0xcc($s0)
/* DB2304 80240044 8C640030 */  lw        $a0, 0x30($v1)
/* DB2308 80240048 24030005 */  addiu     $v1, $zero, 5
/* DB230C 8024004C A443008E */  sh        $v1, 0x8e($v0)
/* DB2310 80240050 AC440028 */  sw        $a0, 0x28($v0)
/* DB2314 80240054 2402000F */  addiu     $v0, $zero, 0xf
/* DB2318 80240058 AE220070 */  sw        $v0, 0x70($s1)
/* DB231C 8024005C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB2320 80240060 8FB10014 */  lw        $s1, 0x14($sp)
/* DB2324 80240064 8FB00010 */  lw        $s0, 0x10($sp)
/* DB2328 80240068 03E00008 */  jr        $ra
/* DB232C 8024006C 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80246BD0_DC3E80
.double 0.6

.section .text

glabel func_80240000_DBD2B0
/* DBD2B0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBD2B4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* DBD2B8 80240008 0080882D */  daddu     $s1, $a0, $zero
/* DBD2BC 8024000C AFBF0018 */  sw        $ra, 0x18($sp)
/* DBD2C0 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* DBD2C4 80240014 8E300148 */  lw        $s0, 0x148($s1)
/* DBD2C8 80240018 0C00EABB */  jal       get_npc_unsafe
/* DBD2CC 8024001C 86040008 */   lh       $a0, 8($s0)
/* DBD2D0 80240020 C4400018 */  lwc1      $f0, 0x18($v0)
/* DBD2D4 80240024 3C018024 */  lui       $at, %hi(D_80246BD0_DC3E80)
/* DBD2D8 80240028 D4226BD0 */  ldc1      $f2, %lo(D_80246BD0_DC3E80)($at)
/* DBD2DC 8024002C 46000021 */  cvt.d.s   $f0, $f0
/* DBD2E0 80240030 46220002 */  mul.d     $f0, $f0, $f2
/* DBD2E4 80240034 00000000 */  nop
/* DBD2E8 80240038 46200020 */  cvt.s.d   $f0, $f0
/* DBD2EC 8024003C E4400018 */  swc1      $f0, 0x18($v0)
/* DBD2F0 80240040 8E0300CC */  lw        $v1, 0xcc($s0)
/* DBD2F4 80240044 8C640030 */  lw        $a0, 0x30($v1)
/* DBD2F8 80240048 24030005 */  addiu     $v1, $zero, 5
/* DBD2FC 8024004C A443008E */  sh        $v1, 0x8e($v0)
/* DBD300 80240050 AC440028 */  sw        $a0, 0x28($v0)
/* DBD304 80240054 2402000F */  addiu     $v0, $zero, 0xf
/* DBD308 80240058 AE220070 */  sw        $v0, 0x70($s1)
/* DBD30C 8024005C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DBD310 80240060 8FB10014 */  lw        $s1, 0x14($sp)
/* DBD314 80240064 8FB00010 */  lw        $s0, 0x10($sp)
/* DBD318 80240068 03E00008 */  jr        $ra
/* DBD31C 8024006C 27BD0020 */   addiu    $sp, $sp, 0x20

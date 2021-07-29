.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243300_A2A1D0
.double 0.3, 0.0

.section .text

glabel func_80240000_A26ED0
/* A26ED0 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A26ED4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* A26ED8 80240008 3C118024 */  lui       $s1, %hi(D_802416F0_A285C0)
/* A26EDC 8024000C 263116F0 */  addiu     $s1, $s1, %lo(D_802416F0_A285C0)
/* A26EE0 80240010 AFBF0020 */  sw        $ra, 0x20($sp)
/* A26EE4 80240014 AFB3001C */  sw        $s3, 0x1c($sp)
/* A26EE8 80240018 AFB20018 */  sw        $s2, 0x18($sp)
/* A26EEC 8024001C AFB00010 */  sw        $s0, 0x10($sp)
/* A26EF0 80240020 96220000 */  lhu       $v0, ($s1)
/* A26EF4 80240024 3C013D00 */  lui       $at, 0x3d00
/* A26EF8 80240028 44810000 */  mtc1      $at, $f0
/* A26EFC 8024002C 44826000 */  mtc1      $v0, $f12
/* A26F00 80240030 00000000 */  nop
/* A26F04 80240034 46806320 */  cvt.s.w   $f12, $f12
/* A26F08 80240038 46006302 */  mul.s     $f12, $f12, $f0
/* A26F0C 8024003C 00000000 */  nop
/* A26F10 80240040 0C00A85B */  jal       sin_rad
/* A26F14 80240044 3C130001 */   lui      $s3, 1
/* A26F18 80240048 3C013F80 */  lui       $at, 0x3f80
/* A26F1C 8024004C 44811000 */  mtc1      $at, $f2
/* A26F20 80240050 00000000 */  nop
/* A26F24 80240054 46020000 */  add.s     $f0, $f0, $f2
/* A26F28 80240058 3C013E80 */  lui       $at, 0x3e80
/* A26F2C 8024005C 44811000 */  mtc1      $at, $f2
/* A26F30 80240060 00000000 */  nop
/* A26F34 80240064 46020002 */  mul.s     $f0, $f0, $f2
/* A26F38 80240068 00000000 */  nop
/* A26F3C 8024006C 3C013FE8 */  lui       $at, 0x3fe8
/* A26F40 80240070 44811800 */  mtc1      $at, $f3
/* A26F44 80240074 44801000 */  mtc1      $zero, $f2
/* A26F48 80240078 46000021 */  cvt.d.s   $f0, $f0
/* A26F4C 8024007C 46220000 */  add.d     $f0, $f0, $f2
/* A26F50 80240080 3C018024 */  lui       $at, %hi(D_80243300_A2A1D0)
/* A26F54 80240084 D4243300 */  ldc1      $f4, %lo(D_80243300_A2A1D0)($at)
/* A26F58 80240088 46200020 */  cvt.s.d   $f0, $f0
/* A26F5C 8024008C 460000A1 */  cvt.d.s   $f2, $f0
/* A26F60 80240090 46241082 */  mul.d     $f2, $f2, $f4
/* A26F64 80240094 00000000 */  nop
/* A26F68 80240098 36731630 */  ori       $s3, $s3, 0x1630
/* A26F6C 8024009C 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* A26F70 802400A0 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* A26F74 802400A4 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* A26F78 802400A8 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* A26F7C 802400AC 96040000 */  lhu       $a0, ($s0)
/* A26F80 802400B0 8E420000 */  lw        $v0, ($s2)
/* A26F84 802400B4 3C013FE0 */  lui       $at, 0x3fe0
/* A26F88 802400B8 44812800 */  mtc1      $at, $f5
/* A26F8C 802400BC 44802000 */  mtc1      $zero, $f4
/* A26F90 802400C0 00042180 */  sll       $a0, $a0, 6
/* A26F94 802400C4 46241080 */  add.d     $f2, $f2, $f4
/* A26F98 802400C8 00932021 */  addu      $a0, $a0, $s3
/* A26F9C 802400CC 00442021 */  addu      $a0, $v0, $a0
/* A26FA0 802400D0 462010A0 */  cvt.s.d   $f2, $f2
/* A26FA4 802400D4 44051000 */  mfc1      $a1, $f2
/* A26FA8 802400D8 44060000 */  mfc1      $a2, $f0
/* A26FAC 802400DC 0C019DC0 */  jal       guScale
/* A26FB0 802400E0 00A0382D */   daddu    $a3, $a1, $zero
/* A26FB4 802400E4 3C05DA38 */  lui       $a1, 0xda38
/* A26FB8 802400E8 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* A26FBC 802400EC 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* A26FC0 802400F0 34A50001 */  ori       $a1, $a1, 1
/* A26FC4 802400F4 8C820000 */  lw        $v0, ($a0)
/* A26FC8 802400F8 96030000 */  lhu       $v1, ($s0)
/* A26FCC 802400FC 0040302D */  daddu     $a2, $v0, $zero
/* A26FD0 80240100 24420008 */  addiu     $v0, $v0, 8
/* A26FD4 80240104 AC820000 */  sw        $v0, ($a0)
/* A26FD8 80240108 24620001 */  addiu     $v0, $v1, 1
/* A26FDC 8024010C 3063FFFF */  andi      $v1, $v1, 0xffff
/* A26FE0 80240110 00031980 */  sll       $v1, $v1, 6
/* A26FE4 80240114 00731821 */  addu      $v1, $v1, $s3
/* A26FE8 80240118 ACC50000 */  sw        $a1, ($a2)
/* A26FEC 8024011C A6020000 */  sh        $v0, ($s0)
/* A26FF0 80240120 8E420000 */  lw        $v0, ($s2)
/* A26FF4 80240124 96240000 */  lhu       $a0, ($s1)
/* A26FF8 80240128 00431021 */  addu      $v0, $v0, $v1
/* A26FFC 8024012C 24840001 */  addiu     $a0, $a0, 1
/* A27000 80240130 ACC20004 */  sw        $v0, 4($a2)
/* A27004 80240134 A6240000 */  sh        $a0, ($s1)
/* A27008 80240138 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2700C 8024013C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A27010 80240140 8FB20018 */  lw        $s2, 0x18($sp)
/* A27014 80240144 8FB10014 */  lw        $s1, 0x14($sp)
/* A27018 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* A2701C 8024014C 03E00008 */  jr        $ra
/* A27020 80240150 27BD0028 */   addiu    $sp, $sp, 0x28

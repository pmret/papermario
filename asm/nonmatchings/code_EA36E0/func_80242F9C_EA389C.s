.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F9C_EA389C
/* EA389C 80242F9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA38A0 80242FA0 AFB00010 */  sw        $s0, 0x10($sp)
/* EA38A4 80242FA4 0080802D */  daddu     $s0, $a0, $zero
/* EA38A8 80242FA8 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA38AC 80242FAC F7B40018 */  sdc1      $f20, 0x18($sp)
/* EA38B0 80242FB0 C60C0090 */  lwc1      $f12, 0x90($s0)
/* EA38B4 80242FB4 46806320 */  cvt.s.w   $f12, $f12
/* EA38B8 80242FB8 3C018024 */  lui       $at, %hi(D_802466B0)
/* EA38BC 80242FBC D43466B0 */  ldc1      $f20, %lo(D_802466B0)($at)
/* EA38C0 80242FC0 46006307 */  neg.s     $f12, $f12
/* EA38C4 80242FC4 46006321 */  cvt.d.s   $f12, $f12
/* EA38C8 80242FC8 46346301 */  sub.d     $f12, $f12, $f20
/* EA38CC 80242FCC 0C00AD90 */  jal       func_8002B640
/* EA38D0 80242FD0 46206320 */   cvt.s.d  $f12, $f12
/* EA38D4 80242FD4 3C014008 */  lui       $at, 0x4008
/* EA38D8 80242FD8 44811800 */  mtc1      $at, $f3
/* EA38DC 80242FDC 44801000 */  mtc1      $zero, $f2
/* EA38E0 80242FE0 46000021 */  cvt.d.s   $f0, $f0
/* EA38E4 80242FE4 46220002 */  mul.d     $f0, $f0, $f2
/* EA38E8 80242FE8 00000000 */  nop       
/* EA38EC 80242FEC C60C0090 */  lwc1      $f12, 0x90($s0)
/* EA38F0 80242FF0 46806320 */  cvt.s.w   $f12, $f12
/* EA38F4 80242FF4 46006307 */  neg.s     $f12, $f12
/* EA38F8 80242FF8 46006321 */  cvt.d.s   $f12, $f12
/* EA38FC 80242FFC 46346301 */  sub.d     $f12, $f12, $f20
/* EA3900 80243000 3C018024 */  lui       $at, %hi(D_802466B8)
/* EA3904 80243004 D42266B8 */  ldc1      $f2, %lo(D_802466B8)($at)
/* EA3908 80243008 46220001 */  sub.d     $f0, $f0, $f2
/* EA390C 8024300C 4620010D */  trunc.w.d $f4, $f0
/* EA3910 80243010 E6040098 */  swc1      $f4, 0x98($s0)
/* EA3914 80243014 0C00AD77 */  jal       func_8002B5DC
/* EA3918 80243018 46206320 */   cvt.s.d  $f12, $f12
/* EA391C 8024301C 3C014014 */  lui       $at, 0x4014
/* EA3920 80243020 44811800 */  mtc1      $at, $f3
/* EA3924 80243024 44801000 */  mtc1      $zero, $f2
/* EA3928 80243028 46000021 */  cvt.d.s   $f0, $f0
/* EA392C 8024302C 46220002 */  mul.d     $f0, $f0, $f2
/* EA3930 80243030 00000000 */  nop       
/* EA3934 80243034 4620010D */  trunc.w.d $f4, $f0
/* EA3938 80243038 E604009C */  swc1      $f4, 0x9c($s0)
/* EA393C 8024303C 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA3940 80243040 8FB00010 */  lw        $s0, 0x10($sp)
/* EA3944 80243044 D7B40018 */  ldc1      $f20, 0x18($sp)
/* EA3948 80243048 24020002 */  addiu     $v0, $zero, 2
/* EA394C 8024304C 03E00008 */  jr        $ra
/* EA3950 80243050 27BD0020 */   addiu    $sp, $sp, 0x20

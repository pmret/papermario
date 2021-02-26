.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002A190
/* 5590 8002A190 3C014622 */  lui       $at, 0x4622
/* 5594 8002A194 3421F983 */  ori       $at, $at, 0xf983
/* 5598 8002A198 44810000 */  mtc1      $at, $f0
/* 559C 8002A19C 00000000 */  nop
/* 55A0 8002A1A0 46006302 */  mul.s     $f12, $f12, $f0
/* 55A4 8002A1A4 00000000 */  nop
/* 55A8 8002A1A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 55AC 8002A1AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 55B0 8002A1B0 0C00A7FD */  jal       func_80029FF4
/* 55B4 8002A1B4 00000000 */   nop
/* 55B8 8002A1B8 0C0187B4 */  jal       func_80061ED0
/* 55BC 8002A1BC 3044FFFF */   andi     $a0, $v0, 0xffff
/* 55C0 8002A1C0 00021400 */  sll       $v0, $v0, 0x10
/* 55C4 8002A1C4 00021403 */  sra       $v0, $v0, 0x10
/* 55C8 8002A1C8 3C018009 */  lui       $at, %hi(D_80097D50)
/* 55CC 8002A1CC D4227D50 */  ldc1      $f2, %lo(D_80097D50)($at)
/* 55D0 8002A1D0 44820000 */  mtc1      $v0, $f0
/* 55D4 8002A1D4 00000000 */  nop
/* 55D8 8002A1D8 46800021 */  cvt.d.w   $f0, $f0
/* 55DC 8002A1DC 46220002 */  mul.d     $f0, $f0, $f2
/* 55E0 8002A1E0 00000000 */  nop
/* 55E4 8002A1E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 55E8 8002A1E8 46200020 */  cvt.s.d   $f0, $f0
/* 55EC 8002A1EC 03E00008 */  jr        $ra
/* 55F0 8002A1F0 27BD0018 */   addiu    $sp, $sp, 0x18

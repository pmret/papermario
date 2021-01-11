.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sin_rad
/* 556C 8002A16C 3C014622 */  lui       $at, 0x4622
/* 5570 8002A170 3421F983 */  ori       $at, $at, 0xf983
/* 5574 8002A174 44810000 */  mtc1      $at, $f0
/* 5578 8002A178 00000000 */  nop
/* 557C 8002A17C 46006302 */  mul.s     $f12, $f12, $f0
/* 5580 8002A180 00000000 */  nop
/* 5584 8002A184 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5588 8002A188 AFBF0010 */  sw        $ra, 0x10($sp)
/* 558C 8002A18C 0C00A80D */  jal       _wrap_trig_lookup_value
/* 5590 8002A190 00000000 */   nop
/* 5594 8002A194 0C01917C */  jal       sins
/* 5598 8002A198 3044FFFF */   andi     $a0, $v0, 0xffff
/* 559C 8002A19C 00021400 */  sll       $v0, $v0, 0x10
/* 55A0 8002A1A0 00021403 */  sra       $v0, $v0, 0x10
/* 55A4 8002A1A4 3C018009 */  lui       $at, %hi(D_80097D68)
/* 55A8 8002A1A8 D4227D68 */  ldc1      $f2, %lo(D_80097D68)($at)
/* 55AC 8002A1AC 44820000 */  mtc1      $v0, $f0
/* 55B0 8002A1B0 00000000 */  nop
/* 55B4 8002A1B4 46800021 */  cvt.d.w   $f0, $f0
/* 55B8 8002A1B8 46220002 */  mul.d     $f0, $f0, $f2
/* 55BC 8002A1BC 00000000 */  nop
/* 55C0 8002A1C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 55C4 8002A1C4 46200020 */  cvt.s.d   $f0, $f0
/* 55C8 8002A1C8 03E00008 */  jr        $ra
/* 55CC 8002A1CC 27BD0018 */   addiu    $sp, $sp, 0x18

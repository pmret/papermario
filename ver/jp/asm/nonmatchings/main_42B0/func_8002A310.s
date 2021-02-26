.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002A310
/* 5710 8002A310 3C014336 */  lui       $at, 0x4336
/* 5714 8002A314 34210B61 */  ori       $at, $at, 0xb61
/* 5718 8002A318 44810000 */  mtc1      $at, $f0
/* 571C 8002A31C 00000000 */  nop
/* 5720 8002A320 46006302 */  mul.s     $f12, $f12, $f0
/* 5724 8002A324 00000000 */  nop
/* 5728 8002A328 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 572C 8002A32C AFBF0010 */  sw        $ra, 0x10($sp)
/* 5730 8002A330 0C00A7FD */  jal       func_80029FF4
/* 5734 8002A334 00000000 */   nop
/* 5738 8002A338 0C0187B4 */  jal       func_80061ED0
/* 573C 8002A33C 3044FFFF */   andi     $a0, $v0, 0xffff
/* 5740 8002A340 00021400 */  sll       $v0, $v0, 0x10
/* 5744 8002A344 00021403 */  sra       $v0, $v0, 0x10
/* 5748 8002A348 3C018009 */  lui       $at, %hi(D_80097D68)
/* 574C 8002A34C D4227D68 */  ldc1      $f2, %lo(D_80097D68)($at)
/* 5750 8002A350 44820000 */  mtc1      $v0, $f0
/* 5754 8002A354 00000000 */  nop
/* 5758 8002A358 46800021 */  cvt.d.w   $f0, $f0
/* 575C 8002A35C 46220002 */  mul.d     $f0, $f0, $f2
/* 5760 8002A360 00000000 */  nop
/* 5764 8002A364 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5768 8002A368 46200020 */  cvt.s.d   $f0, $f0
/* 576C 8002A36C 03E00008 */  jr        $ra
/* 5770 8002A370 27BD0018 */   addiu    $sp, $sp, 0x18

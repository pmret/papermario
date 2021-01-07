.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sin_deg
/* 56EC 8002A2EC 3C014336 */  lui       $at, 0x4336
/* 56F0 8002A2F0 34210B61 */  ori       $at, $at, 0xb61
/* 56F4 8002A2F4 44810000 */  mtc1      $at, $f0
/* 56F8 8002A2F8 00000000 */  nop       
/* 56FC 8002A2FC 46006302 */  mul.s     $f12, $f12, $f0
/* 5700 8002A300 00000000 */  nop       
/* 5704 8002A304 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5708 8002A308 AFBF0010 */  sw        $ra, 0x10($sp)
/* 570C 8002A30C 0C00A80D */  jal       _wrap_trig_lookup_value
/* 5710 8002A310 00000000 */   nop      
/* 5714 8002A314 0C01917C */  jal       sins
/* 5718 8002A318 3044FFFF */   andi     $a0, $v0, 0xffff
/* 571C 8002A31C 00021400 */  sll       $v0, $v0, 0x10
/* 5720 8002A320 00021403 */  sra       $v0, $v0, 0x10
/* 5724 8002A324 3C018009 */  lui       $at, %hi(D_80097D80)
/* 5728 8002A328 D4227D80 */  ldc1      $f2, %lo(D_80097D80)($at)
/* 572C 8002A32C 44820000 */  mtc1      $v0, $f0
/* 5730 8002A330 00000000 */  nop       
/* 5734 8002A334 46800021 */  cvt.d.w   $f0, $f0
/* 5738 8002A338 46220002 */  mul.d     $f0, $f0, $f2
/* 573C 8002A33C 00000000 */  nop       
/* 5740 8002A340 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5744 8002A344 46200020 */  cvt.s.d   $f0, $f0
/* 5748 8002A348 03E00008 */  jr        $ra
/* 574C 8002A34C 27BD0018 */   addiu    $sp, $sp, 0x18

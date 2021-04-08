.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002A2AC
/* 56AC 8002A2AC 3C014336 */  lui       $at, 0x4336
/* 56B0 8002A2B0 34210B61 */  ori       $at, $at, 0xb61
/* 56B4 8002A2B4 44810000 */  mtc1      $at, $f0
/* 56B8 8002A2B8 00000000 */  nop
/* 56BC 8002A2BC 46006302 */  mul.s     $f12, $f12, $f0
/* 56C0 8002A2C0 00000000 */  nop
/* 56C4 8002A2C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 56C8 8002A2C8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 56CC 8002A2CC 0C00A7FD */  jal       func_80029FF4
/* 56D0 8002A2D0 00000000 */   nop
/* 56D4 8002A2D4 0C019170 */  jal       func_800645C0
/* 56D8 8002A2D8 3044FFFF */   andi     $a0, $v0, 0xffff
/* 56DC 8002A2DC 00021400 */  sll       $v0, $v0, 0x10
/* 56E0 8002A2E0 00021403 */  sra       $v0, $v0, 0x10
/* 56E4 8002A2E4 3C018009 */  lui       $at, %hi(D_80097D60)
/* 56E8 8002A2E8 D4227D60 */  ldc1      $f2, %lo(D_80097D60)($at)
/* 56EC 8002A2EC 44820000 */  mtc1      $v0, $f0
/* 56F0 8002A2F0 00000000 */  nop
/* 56F4 8002A2F4 46800021 */  cvt.d.w   $f0, $f0
/* 56F8 8002A2F8 46220002 */  mul.d     $f0, $f0, $f2
/* 56FC 8002A2FC 00000000 */  nop
/* 5700 8002A300 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5704 8002A304 46200020 */  cvt.s.d   $f0, $f0
/* 5708 8002A308 03E00008 */  jr        $ra
/* 570C 8002A30C 27BD0018 */   addiu    $sp, $sp, 0x18

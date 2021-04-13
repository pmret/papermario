.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002A074
/* 5474 8002A074 3C014622 */  lui       $at, 0x4622
/* 5478 8002A078 3421F983 */  ori       $at, $at, 0xf983
/* 547C 8002A07C 44810000 */  mtc1      $at, $f0
/* 5480 8002A080 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5484 8002A084 AFB10014 */  sw        $s1, 0x14($sp)
/* 5488 8002A088 00A0882D */  daddu     $s1, $a1, $zero
/* 548C 8002A08C AFB20018 */  sw        $s2, 0x18($sp)
/* 5490 8002A090 46006302 */  mul.s     $f12, $f12, $f0
/* 5494 8002A094 00000000 */  nop
/* 5498 8002A098 AFBF001C */  sw        $ra, 0x1c($sp)
/* 549C 8002A09C AFB00010 */  sw        $s0, 0x10($sp)
/* 54A0 8002A0A0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 54A4 8002A0A4 0C00A7FD */  jal       func_80029FF4
/* 54A8 8002A0A8 00C0902D */   daddu    $s2, $a2, $zero
/* 54AC 8002A0AC 3050FFFF */  andi      $s0, $v0, 0xffff
/* 54B0 8002A0B0 0C019170 */  jal       func_800645C0
/* 54B4 8002A0B4 0200202D */   daddu    $a0, $s0, $zero
/* 54B8 8002A0B8 00021400 */  sll       $v0, $v0, 0x10
/* 54BC 8002A0BC 00021403 */  sra       $v0, $v0, 0x10
/* 54C0 8002A0C0 3C018009 */  lui       $at, %hi(D_80097D40)
/* 54C4 8002A0C4 D4347D40 */  ldc1      $f20, %lo(D_80097D40)($at)
/* 54C8 8002A0C8 44820000 */  mtc1      $v0, $f0
/* 54CC 8002A0CC 00000000 */  nop
/* 54D0 8002A0D0 46800021 */  cvt.d.w   $f0, $f0
/* 54D4 8002A0D4 46340002 */  mul.d     $f0, $f0, $f20
/* 54D8 8002A0D8 00000000 */  nop
/* 54DC 8002A0DC 0200202D */  daddu     $a0, $s0, $zero
/* 54E0 8002A0E0 46200020 */  cvt.s.d   $f0, $f0
/* 54E4 8002A0E4 0C0187B4 */  jal       func_80061ED0
/* 54E8 8002A0E8 E6200000 */   swc1     $f0, ($s1)
/* 54EC 8002A0EC 00021400 */  sll       $v0, $v0, 0x10
/* 54F0 8002A0F0 00021403 */  sra       $v0, $v0, 0x10
/* 54F4 8002A0F4 44820000 */  mtc1      $v0, $f0
/* 54F8 8002A0F8 00000000 */  nop
/* 54FC 8002A0FC 46800021 */  cvt.d.w   $f0, $f0
/* 5500 8002A100 46340002 */  mul.d     $f0, $f0, $f20
/* 5504 8002A104 00000000 */  nop
/* 5508 8002A108 46200020 */  cvt.s.d   $f0, $f0
/* 550C 8002A10C E6400000 */  swc1      $f0, ($s2)
/* 5510 8002A110 8FBF001C */  lw        $ra, 0x1c($sp)
/* 5514 8002A114 8FB20018 */  lw        $s2, 0x18($sp)
/* 5518 8002A118 8FB10014 */  lw        $s1, 0x14($sp)
/* 551C 8002A11C 8FB00010 */  lw        $s0, 0x10($sp)
/* 5520 8002A120 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 5524 8002A124 03E00008 */  jr        $ra
/* 5528 8002A128 27BD0028 */   addiu    $sp, $sp, 0x28

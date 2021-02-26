.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002A12C
/* 552C 8002A12C 3C014622 */  lui       $at, 0x4622
/* 5530 8002A130 3421F983 */  ori       $at, $at, 0xf983
/* 5534 8002A134 44810000 */  mtc1      $at, $f0
/* 5538 8002A138 00000000 */  nop
/* 553C 8002A13C 46006302 */  mul.s     $f12, $f12, $f0
/* 5540 8002A140 00000000 */  nop
/* 5544 8002A144 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5548 8002A148 AFBF0010 */  sw        $ra, 0x10($sp)
/* 554C 8002A14C 0C00A7FD */  jal       func_80029FF4
/* 5550 8002A150 00000000 */   nop
/* 5554 8002A154 0C019170 */  jal       func_800645C0
/* 5558 8002A158 3044FFFF */   andi     $a0, $v0, 0xffff
/* 555C 8002A15C 00021400 */  sll       $v0, $v0, 0x10
/* 5560 8002A160 00021403 */  sra       $v0, $v0, 0x10
/* 5564 8002A164 3C018009 */  lui       $at, %hi(D_80097D48)
/* 5568 8002A168 D4227D48 */  ldc1      $f2, %lo(D_80097D48)($at)
/* 556C 8002A16C 44820000 */  mtc1      $v0, $f0
/* 5570 8002A170 00000000 */  nop
/* 5574 8002A174 46800021 */  cvt.d.w   $f0, $f0
/* 5578 8002A178 46220002 */  mul.d     $f0, $f0, $f2
/* 557C 8002A17C 00000000 */  nop
/* 5580 8002A180 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5584 8002A184 46200020 */  cvt.s.d   $f0, $f0
/* 5588 8002A188 03E00008 */  jr        $ra
/* 558C 8002A18C 27BD0018 */   addiu    $sp, $sp, 0x18

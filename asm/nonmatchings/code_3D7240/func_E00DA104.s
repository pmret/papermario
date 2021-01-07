.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DA104
/* 3D7344 E00DA104 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D7348 E00DA108 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D734C E00DA10C 8C850000 */  lw        $a1, ($a0)
/* 3D7350 E00DA110 8C83000C */  lw        $v1, 0xc($a0)
/* 3D7354 E00DA114 30A20010 */  andi      $v0, $a1, 0x10
/* 3D7358 E00DA118 10400005 */  beqz      $v0, .LE00DA130
/* 3D735C E00DA11C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D7360 E00DA120 00A21024 */  and       $v0, $a1, $v0
/* 3D7364 E00DA124 AC820000 */  sw        $v0, ($a0)
/* 3D7368 E00DA128 2402000A */  addiu     $v0, $zero, 0xa
/* 3D736C E00DA12C AC620010 */  sw        $v0, 0x10($v1)
.LE00DA130:
/* 3D7370 E00DA130 8C650010 */  lw        $a1, 0x10($v1)
/* 3D7374 E00DA134 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3D7378 E00DA138 10400002 */  beqz      $v0, .LE00DA144
/* 3D737C E00DA13C 24A2FFFF */   addiu    $v0, $a1, -1
/* 3D7380 E00DA140 AC620010 */  sw        $v0, 0x10($v1)
.LE00DA144:
/* 3D7384 E00DA144 8C620014 */  lw        $v0, 0x14($v1)
/* 3D7388 E00DA148 8C650010 */  lw        $a1, 0x10($v1)
/* 3D738C E00DA14C 24460001 */  addiu     $a2, $v0, 1
/* 3D7390 E00DA150 04A10005 */  bgez      $a1, .LE00DA168
/* 3D7394 E00DA154 AC660014 */   sw       $a2, 0x14($v1)
/* 3D7398 E00DA158 0C080128 */  jal       func_E02004A0
/* 3D739C E00DA15C 00000000 */   nop      
/* 3D73A0 E00DA160 08036875 */  j         .LE00DA1D4
/* 3D73A4 E00DA164 00000000 */   nop      
.LE00DA168:
/* 3D73A8 E00DA168 28A20004 */  slti      $v0, $a1, 4
/* 3D73AC E00DA16C 1040000B */  beqz      $v0, .LE00DA19C
/* 3D73B0 E00DA170 00000000 */   nop      
/* 3D73B4 E00DA174 C460002C */  lwc1      $f0, 0x2c($v1)
/* 3D73B8 E00DA178 3C013FE0 */  lui       $at, 0x3fe0
/* 3D73BC E00DA17C 44811800 */  mtc1      $at, $f3
/* 3D73C0 E00DA180 44801000 */  mtc1      $zero, $f2
/* 3D73C4 E00DA184 46000021 */  cvt.d.s   $f0, $f0
/* 3D73C8 E00DA188 46220002 */  mul.d     $f0, $f0, $f2
/* 3D73CC E00DA18C 00000000 */  nop       
/* 3D73D0 E00DA190 46200020 */  cvt.s.d   $f0, $f0
/* 3D73D4 E00DA194 08036875 */  j         .LE00DA1D4
/* 3D73D8 E00DA198 E460002C */   swc1     $f0, 0x2c($v1)
.LE00DA19C:
/* 3D73DC E00DA19C 3C013E4C */  lui       $at, 0x3e4c
/* 3D73E0 E00DA1A0 3421CCCD */  ori       $at, $at, 0xcccd
/* 3D73E4 E00DA1A4 44810000 */  mtc1      $at, $f0
/* 3D73E8 E00DA1A8 44861000 */  mtc1      $a2, $f2
/* 3D73EC E00DA1AC 00000000 */  nop       
/* 3D73F0 E00DA1B0 468010A0 */  cvt.s.w   $f2, $f2
/* 3D73F4 E00DA1B4 46001082 */  mul.s     $f2, $f2, $f0
/* 3D73F8 E00DA1B8 00000000 */  nop       
/* 3D73FC E00DA1BC 3C01E00E */  lui       $at, %hi(D_E00DA520)
/* 3D7400 E00DA1C0 D420A520 */  ldc1      $f0, %lo(D_E00DA520)($at)
/* 3D7404 E00DA1C4 460010A1 */  cvt.d.s   $f2, $f2
/* 3D7408 E00DA1C8 46201080 */  add.d     $f2, $f2, $f0
/* 3D740C E00DA1CC 462010A0 */  cvt.s.d   $f2, $f2
/* 3D7410 E00DA1D0 E462002C */  swc1      $f2, 0x2c($v1)
.LE00DA1D4:
/* 3D7414 E00DA1D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D7418 E00DA1D8 03E00008 */  jr        $ra
/* 3D741C E00DA1DC 27BD0018 */   addiu    $sp, $sp, 0x18

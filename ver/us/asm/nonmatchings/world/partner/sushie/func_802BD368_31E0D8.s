.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD368_31E0D8
/* 31E0D8 802BD368 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31E0DC 802BD36C 3C0142C8 */  lui       $at, 0x42c8
/* 31E0E0 802BD370 44810000 */  mtc1      $at, $f0
/* 31E0E4 802BD374 44864000 */  mtc1      $a2, $f8
/* 31E0E8 802BD378 C7A40048 */  lwc1      $f4, 0x48($sp)
/* 31E0EC 802BD37C C7A6004C */  lwc1      $f6, 0x4c($sp)
/* 31E0F0 802BD380 27A20020 */  addiu     $v0, $sp, 0x20
/* 31E0F4 802BD384 AFB00028 */  sw        $s0, 0x28($sp)
/* 31E0F8 802BD388 3C108016 */  lui       $s0, %hi(gCollisionStatus)
/* 31E0FC 802BD38C 2610A550 */  addiu     $s0, $s0, %lo(gCollisionStatus)
/* 31E100 802BD390 AFB1002C */  sw        $s1, 0x2c($sp)
/* 31E104 802BD394 0200882D */  daddu     $s1, $s0, $zero
/* 31E108 802BD398 AFA5003C */  sw        $a1, 0x3c($sp)
/* 31E10C 802BD39C 27A5003C */  addiu     $a1, $sp, 0x3c
/* 31E110 802BD3A0 AFA70044 */  sw        $a3, 0x44($sp)
/* 31E114 802BD3A4 27A70044 */  addiu     $a3, $sp, 0x44
/* 31E118 802BD3A8 AFBF0030 */  sw        $ra, 0x30($sp)
/* 31E11C 802BD3AC AFA60040 */  sw        $a2, 0x40($sp)
/* 31E120 802BD3B0 46004080 */  add.s     $f2, $f8, $f0
/* 31E124 802BD3B4 3C014348 */  lui       $at, 0x4348
/* 31E128 802BD3B8 44810000 */  mtc1      $at, $f0
/* 31E12C 802BD3BC 27A60040 */  addiu     $a2, $sp, 0x40
/* 31E130 802BD3C0 E7A20040 */  swc1      $f2, 0x40($sp)
/* 31E134 802BD3C4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31E138 802BD3C8 AFA20010 */  sw        $v0, 0x10($sp)
/* 31E13C 802BD3CC E7A40014 */  swc1      $f4, 0x14($sp)
/* 31E140 802BD3D0 0C0371DE */  jal       npc_raycast_down_ahead
/* 31E144 802BD3D4 E7A60018 */   swc1     $f6, 0x18($sp)
/* 31E148 802BD3D8 14400003 */  bnez      $v0, .L802BD3E8
/* 31E14C 802BD3DC 2402FFFF */   addiu    $v0, $zero, -1
/* 31E150 802BD3E0 080AF500 */  j         .L802BD400
/* 31E154 802BD3E4 A6020002 */   sh       $v0, 2($s0)
.L802BD3E8:
/* 31E158 802BD3E8 3C028011 */  lui       $v0, %hi(D_8010C97A)
/* 31E15C 802BD3EC 9442C97A */  lhu       $v0, %lo(D_8010C97A)($v0)
/* 31E160 802BD3F0 A6220002 */  sh        $v0, 2($s1)
/* 31E164 802BD3F4 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 31E168 802BD3F8 3C01802C */  lui       $at, %hi(D_802BFEE0)
/* 31E16C 802BD3FC E420FEE0 */  swc1      $f0, %lo(D_802BFEE0)($at)
.L802BD400:
/* 31E170 802BD400 8FBF0030 */  lw        $ra, 0x30($sp)
/* 31E174 802BD404 8FB1002C */  lw        $s1, 0x2c($sp)
/* 31E178 802BD408 8FB00028 */  lw        $s0, 0x28($sp)
/* 31E17C 802BD40C 03E00008 */  jr        $ra
/* 31E180 802BD410 27BD0038 */   addiu    $sp, $sp, 0x38

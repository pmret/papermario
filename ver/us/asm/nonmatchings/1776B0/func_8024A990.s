.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8029CC18
.double 0.4

.section .text

glabel func_8024A990
/* 179270 8024A990 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 179274 8024A994 AFB00020 */  sw        $s0, 0x20($sp)
/* 179278 8024A998 3C10800B */  lui       $s0, %hi(gCameras+0x558)
/* 17927C 8024A99C 261022D8 */  addiu     $s0, $s0, %lo(gCameras+0x558)
/* 179280 8024A9A0 3C02802A */  lui       $v0, %hi(BattleCam_TargetActor)
/* 179284 8024A9A4 9442F27C */  lhu       $v0, %lo(BattleCam_TargetActor)($v0)
/* 179288 8024A9A8 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 17928C 8024A9AC 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 179290 8024A9B0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 179294 8024A9B4 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 179298 8024A9B8 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 17929C 8024A9BC F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 1792A0 8024A9C0 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 1792A4 8024A9C4 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 1792A8 8024A9C8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 1792AC 8024A9CC 30430700 */  andi      $v1, $v0, 0x700
/* 1792B0 8024A9D0 304600FF */  andi      $a2, $v0, 0xff
/* 1792B4 8024A9D4 24020100 */  addiu     $v0, $zero, 0x100
/* 1792B8 8024A9D8 1062002B */  beq       $v1, $v0, .L8024AA88
/* 1792BC 8024A9DC 28620101 */   slti     $v0, $v1, 0x101
/* 1792C0 8024A9E0 10400005 */  beqz      $v0, .L8024A9F8
/* 1792C4 8024A9E4 24020200 */   addiu    $v0, $zero, 0x200
/* 1792C8 8024A9E8 10600007 */  beqz      $v1, .L8024AA08
/* 1792CC 8024A9EC 24020002 */   addiu    $v0, $zero, 2
/* 1792D0 8024A9F0 08092BEF */  j         .L8024AFBC
/* 1792D4 8024A9F4 00000000 */   nop
.L8024A9F8:
/* 1792D8 8024A9F8 10620026 */  beq       $v1, $v0, .L8024AA94
/* 1792DC 8024A9FC 24020002 */   addiu    $v0, $zero, 2
/* 1792E0 8024AA00 08092BEF */  j         .L8024AFBC
/* 1792E4 8024AA04 00000000 */   nop
.L8024AA08:
/* 1792E8 8024AA08 8C8400D8 */  lw        $a0, 0xd8($a0)
/* 1792EC 8024AA0C 14800005 */  bnez      $a0, .L8024AA24
/* 1792F0 8024AA10 00000000 */   nop
.L8024AA14:
/* 1792F4 8024AA14 0C093903 */  jal       func_8024E40C
/* 1792F8 8024AA18 24040002 */   addiu    $a0, $zero, 2
/* 1792FC 8024AA1C 08092BEF */  j         .L8024AFBC
/* 179300 8024AA20 0000102D */   daddu    $v0, $zero, $zero
.L8024AA24:
/* 179304 8024AA24 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 179308 8024AA28 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 17930C 8024AA2C 944200B0 */  lhu       $v0, 0xb0($v0)
/* 179310 8024AA30 C4820148 */  lwc1      $f2, 0x148($a0)
/* 179314 8024AA34 00021400 */  sll       $v0, $v0, 0x10
/* 179318 8024AA38 00021C03 */  sra       $v1, $v0, 0x10
/* 17931C 8024AA3C 000217C2 */  srl       $v0, $v0, 0x1f
/* 179320 8024AA40 00621821 */  addu      $v1, $v1, $v0
/* 179324 8024AA44 00031843 */  sra       $v1, $v1, 1
/* 179328 8024AA48 44830000 */  mtc1      $v1, $f0
/* 17932C 8024AA4C 00000000 */  nop
/* 179330 8024AA50 46800020 */  cvt.s.w   $f0, $f0
/* 179334 8024AA54 46001080 */  add.s     $f2, $f2, $f0
/* 179338 8024AA58 C49A0144 */  lwc1      $f26, 0x144($a0)
/* 17933C 8024AA5C E7A20010 */  swc1      $f2, 0x10($sp)
/* 179340 8024AA60 90820191 */  lbu       $v0, 0x191($a0)
/* 179344 8024AA64 90830190 */  lbu       $v1, 0x190($a0)
/* 179348 8024AA68 44824000 */  mtc1      $v0, $f8
/* 17934C 8024AA6C 00000000 */  nop
/* 179350 8024AA70 46804220 */  cvt.s.w   $f8, $f8
/* 179354 8024AA74 44833000 */  mtc1      $v1, $f6
/* 179358 8024AA78 00000000 */  nop
/* 17935C 8024AA7C 468031A0 */  cvt.s.w   $f6, $f6
/* 179360 8024AA80 08092ABB */  j         .L8024AAEC
/* 179364 8024AA84 46064080 */   add.s    $f2, $f8, $f6
.L8024AA88:
/* 179368 8024AA88 8C8400DC */  lw        $a0, 0xdc($a0)
/* 17936C 8024AA8C 08092AA8 */  j         .L8024AAA0
/* 179370 8024AA90 00000000 */   nop
.L8024AA94:
/* 179374 8024AA94 00061080 */  sll       $v0, $a2, 2
/* 179378 8024AA98 00441021 */  addu      $v0, $v0, $a0
/* 17937C 8024AA9C 8C4400E0 */  lw        $a0, 0xe0($v0)
.L8024AAA0:
/* 179380 8024AAA0 1080FFDC */  beqz      $a0, .L8024AA14
/* 179384 8024AAA4 00000000 */   nop
/* 179388 8024AAA8 90830191 */  lbu       $v1, 0x191($a0)
/* 17938C 8024AAAC C4820148 */  lwc1      $f2, 0x148($a0)
/* 179390 8024AAB0 00031042 */  srl       $v0, $v1, 1
/* 179394 8024AAB4 44820000 */  mtc1      $v0, $f0
/* 179398 8024AAB8 00000000 */  nop
/* 17939C 8024AABC 46800020 */  cvt.s.w   $f0, $f0
/* 1793A0 8024AAC0 46001080 */  add.s     $f2, $f2, $f0
/* 1793A4 8024AAC4 C49A0144 */  lwc1      $f26, 0x144($a0)
/* 1793A8 8024AAC8 E7A20010 */  swc1      $f2, 0x10($sp)
/* 1793AC 8024AACC 90820190 */  lbu       $v0, 0x190($a0)
/* 1793B0 8024AAD0 44834000 */  mtc1      $v1, $f8
/* 1793B4 8024AAD4 00000000 */  nop
/* 1793B8 8024AAD8 46804220 */  cvt.s.w   $f8, $f8
/* 1793BC 8024AADC 44823000 */  mtc1      $v0, $f6
/* 1793C0 8024AAE0 00000000 */  nop
/* 1793C4 8024AAE4 468031A0 */  cvt.s.w   $f6, $f6
/* 1793C8 8024AAE8 46064080 */  add.s     $f2, $f8, $f6
.L8024AAEC:
/* 1793CC 8024AAEC 3C013F00 */  lui       $at, 0x3f00
/* 1793D0 8024AAF0 44810000 */  mtc1      $at, $f0
/* 1793D4 8024AAF4 C49C014C */  lwc1      $f28, 0x14c($a0)
/* 1793D8 8024AAF8 46001782 */  mul.s     $f30, $f2, $f0
/* 1793DC 8024AAFC 00000000 */  nop
/* 1793E0 8024AB00 3C02802A */  lui       $v0, %hi(D_8029F2A6)
/* 1793E4 8024AB04 8042F2A6 */  lb        $v0, %lo(D_8029F2A6)($v0)
/* 1793E8 8024AB08 10400029 */  beqz      $v0, .L8024ABB0
/* 1793EC 8024AB0C 00000000 */   nop
/* 1793F0 8024AB10 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomLength)
/* 1793F4 8024AB14 C422F28C */  lwc1      $f2, %lo(BattleCam_TargetBoomLength)($at)
/* 1793F8 8024AB18 3C0143FA */  lui       $at, 0x43fa
/* 1793FC 8024AB1C 44810000 */  mtc1      $at, $f0
/* 179400 8024AB20 00000000 */  nop
/* 179404 8024AB24 46020001 */  sub.s     $f0, $f0, $f2
/* 179408 8024AB28 3C01802A */  lui       $at, %hi(D_8029CC18)
/* 17940C 8024AB2C D422CC18 */  ldc1      $f2, %lo(D_8029CC18)($at)
/* 179410 8024AB30 46000021 */  cvt.d.s   $f0, $f0
/* 179414 8024AB34 46220002 */  mul.d     $f0, $f0, $f2
/* 179418 8024AB38 00000000 */  nop
/* 17941C 8024AB3C 3C01403E */  lui       $at, 0x403e
/* 179420 8024AB40 44811800 */  mtc1      $at, $f3
/* 179424 8024AB44 44801000 */  mtc1      $zero, $f2
/* 179428 8024AB48 00000000 */  nop
/* 17942C 8024AB4C 46220000 */  add.d     $f0, $f0, $f2
/* 179430 8024AB50 46200120 */  cvt.s.d   $f4, $f0
/* 179434 8024AB54 46002007 */  neg.s     $f0, $f4
/* 179438 8024AB58 4600D03C */  c.lt.s    $f26, $f0
/* 17943C 8024AB5C 00000000 */  nop
/* 179440 8024AB60 45000008 */  bc1f      .L8024AB84
/* 179444 8024AB64 00000000 */   nop
/* 179448 8024AB68 461A0001 */  sub.s     $f0, $f0, $f26
/* 17944C 8024AB6C 3C013F00 */  lui       $at, 0x3f00
/* 179450 8024AB70 44811000 */  mtc1      $at, $f2
/* 179454 8024AB74 00000000 */  nop
/* 179458 8024AB78 46020002 */  mul.s     $f0, $f0, $f2
/* 17945C 8024AB7C 00000000 */  nop
/* 179460 8024AB80 4600D680 */  add.s     $f26, $f26, $f0
.L8024AB84:
/* 179464 8024AB84 461A203C */  c.lt.s    $f4, $f26
/* 179468 8024AB88 00000000 */  nop
/* 17946C 8024AB8C 45000008 */  bc1f      .L8024ABB0
/* 179470 8024AB90 00000000 */   nop
/* 179474 8024AB94 461A2001 */  sub.s     $f0, $f4, $f26
/* 179478 8024AB98 3C013F00 */  lui       $at, 0x3f00
/* 17947C 8024AB9C 44811000 */  mtc1      $at, $f2
/* 179480 8024ABA0 00000000 */  nop
/* 179484 8024ABA4 46020002 */  mul.s     $f0, $f0, $f2
/* 179488 8024ABA8 00000000 */  nop
/* 17948C 8024ABAC 4600D680 */  add.s     $f26, $f26, $f0
.L8024ABB0:
/* 179490 8024ABB0 10A00043 */  beqz      $a1, .L8024ACC0
/* 179494 8024ABB4 00000000 */   nop
/* 179498 8024ABB8 3C0141C0 */  lui       $at, 0x41c0
/* 17949C 8024ABBC 44810000 */  mtc1      $at, $f0
/* 1794A0 8024ABC0 00000000 */  nop
/* 1794A4 8024ABC4 46003181 */  sub.s     $f6, $f6, $f0
/* 1794A8 8024ABC8 46004201 */  sub.s     $f8, $f8, $f0
/* 1794AC 8024ABCC 44800000 */  mtc1      $zero, $f0
/* 1794B0 8024ABD0 00000000 */  nop
/* 1794B4 8024ABD4 4600303C */  c.lt.s    $f6, $f0
/* 1794B8 8024ABD8 00000000 */  nop
/* 1794BC 8024ABDC 45030001 */  bc1tl     .L8024ABE4
/* 1794C0 8024ABE0 46000186 */   mov.s    $f6, $f0
.L8024ABE4:
/* 1794C4 8024ABE4 4600403C */  c.lt.s    $f8, $f0
/* 1794C8 8024ABE8 00000000 */  nop
/* 1794CC 8024ABEC 45030001 */  bc1tl     .L8024ABF4
/* 1794D0 8024ABF0 46000206 */   mov.s    $f8, $f0
.L8024ABF4:
/* 1794D4 8024ABF4 86040026 */  lh        $a0, 0x26($s0)
/* 1794D8 8024ABF8 8602001E */  lh        $v0, 0x1e($s0)
/* 1794DC 8024ABFC 86030022 */  lh        $v1, 0x22($s0)
/* 1794E0 8024AC00 44820000 */  mtc1      $v0, $f0
/* 1794E4 8024AC04 00000000 */  nop
/* 1794E8 8024AC08 46800020 */  cvt.s.w   $f0, $f0
/* 1794EC 8024AC0C 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomLength)
/* 1794F0 8024AC10 E420F28C */  swc1      $f0, %lo(BattleCam_TargetBoomLength)($at)
/* 1794F4 8024AC14 44830000 */  mtc1      $v1, $f0
/* 1794F8 8024AC18 00000000 */  nop
/* 1794FC 8024AC1C 46800020 */  cvt.s.w   $f0, $f0
/* 179500 8024AC20 3C03802A */  lui       $v1, %hi(BattleCam_BoomLength)
/* 179504 8024AC24 2463F280 */  addiu     $v1, $v1, %lo(BattleCam_BoomLength)
/* 179508 8024AC28 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomPitch)
/* 17950C 8024AC2C E420F294 */  swc1      $f0, %lo(BattleCam_TargetBoomPitch)($at)
/* 179510 8024AC30 84620000 */  lh        $v0, ($v1)
/* 179514 8024AC34 46083000 */  add.s     $f0, $f6, $f8
/* 179518 8024AC38 44821000 */  mtc1      $v0, $f2
/* 17951C 8024AC3C 00000000 */  nop
/* 179520 8024AC40 468010A0 */  cvt.s.w   $f2, $f2
/* 179524 8024AC44 86020024 */  lh        $v0, 0x24($s0)
/* 179528 8024AC48 46001080 */  add.s     $f2, $f2, $f0
/* 17952C 8024AC4C 44820000 */  mtc1      $v0, $f0
/* 179530 8024AC50 00000000 */  nop
/* 179534 8024AC54 46800020 */  cvt.s.w   $f0, $f0
/* 179538 8024AC58 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomYaw)
/* 17953C 8024AC5C E420F290 */  swc1      $f0, %lo(BattleCam_TargetBoomYaw)($at)
/* 179540 8024AC60 4600148D */  trunc.w.s $f18, $f2
/* 179544 8024AC64 44029000 */  mfc1      $v0, $f18
/* 179548 8024AC68 04810002 */  bgez      $a0, .L8024AC74
/* 17954C 8024AC6C A4620000 */   sh       $v0, ($v1)
/* 179550 8024AC70 248400FF */  addiu     $a0, $a0, 0xff
.L8024AC74:
/* 179554 8024AC74 00041203 */  sra       $v0, $a0, 8
/* 179558 8024AC78 C6020054 */  lwc1      $f2, 0x54($s0)
/* 17955C 8024AC7C C6040058 */  lwc1      $f4, 0x58($s0)
/* 179560 8024AC80 C606005C */  lwc1      $f6, 0x5c($s0)
/* 179564 8024AC84 3C03802A */  lui       $v1, %hi(BattleCam_MoveTimeLeft)
/* 179568 8024AC88 9463F29E */  lhu       $v1, %lo(BattleCam_MoveTimeLeft)($v1)
/* 17956C 8024AC8C 44820000 */  mtc1      $v0, $f0
/* 179570 8024AC90 00000000 */  nop
/* 179574 8024AC94 46800020 */  cvt.s.w   $f0, $f0
/* 179578 8024AC98 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomZOffset)
/* 17957C 8024AC9C E420F298 */  swc1      $f0, %lo(BattleCam_TargetBoomZOffset)($at)
/* 179580 8024ACA0 3C01802A */  lui       $at, %hi(BattleCam_TargetPosX)
/* 179584 8024ACA4 E422F2A8 */  swc1      $f2, %lo(BattleCam_TargetPosX)($at)
/* 179588 8024ACA8 3C01802A */  lui       $at, %hi(BattleCam_TargetPosY)
/* 17958C 8024ACAC E424F2AC */  swc1      $f4, %lo(BattleCam_TargetPosY)($at)
/* 179590 8024ACB0 3C01802A */  lui       $at, %hi(BattleCam_TargetPosZ)
/* 179594 8024ACB4 E426F2B0 */  swc1      $f6, %lo(BattleCam_TargetPosZ)($at)
/* 179598 8024ACB8 3C01802A */  lui       $at, %hi(BattleCam_MoveTimeTotal)
/* 17959C 8024ACBC A423F2A0 */  sh        $v1, %lo(BattleCam_MoveTimeTotal)($at)
.L8024ACC0:
/* 1795A0 8024ACC0 3C02802A */  lui       $v0, %hi(BattleCam_UseLinearInterp)
/* 1795A4 8024ACC4 8042F2A5 */  lb        $v0, %lo(BattleCam_UseLinearInterp)($v0)
/* 1795A8 8024ACC8 14400027 */  bnez      $v0, .L8024AD68
/* 1795AC 8024ACCC 00000000 */   nop
/* 1795B0 8024ACD0 3C02802A */  lui       $v0, %hi(BattleCam_MoveTimeLeft)
/* 1795B4 8024ACD4 8442F29E */  lh        $v0, %lo(BattleCam_MoveTimeLeft)($v0)
/* 1795B8 8024ACD8 3C03802A */  lui       $v1, %hi(BattleCam_MoveTimeTotal)
/* 1795BC 8024ACDC 8463F2A0 */  lh        $v1, %lo(BattleCam_MoveTimeTotal)($v1)
/* 1795C0 8024ACE0 3C013F80 */  lui       $at, 0x3f80
/* 1795C4 8024ACE4 4481C000 */  mtc1      $at, $f24
/* 1795C8 8024ACE8 4482A000 */  mtc1      $v0, $f20
/* 1795CC 8024ACEC 00000000 */  nop
/* 1795D0 8024ACF0 4680A520 */  cvt.s.w   $f20, $f20
/* 1795D4 8024ACF4 44830000 */  mtc1      $v1, $f0
/* 1795D8 8024ACF8 00000000 */  nop
/* 1795DC 8024ACFC 46800020 */  cvt.s.w   $f0, $f0
/* 1795E0 8024AD00 4600A503 */  div.s     $f20, $f20, $f0
/* 1795E4 8024AD04 4614C301 */  sub.s     $f12, $f24, $f20
/* 1795E8 8024AD08 3C014049 */  lui       $at, 0x4049
/* 1795EC 8024AD0C 34210FD0 */  ori       $at, $at, 0xfd0
/* 1795F0 8024AD10 4481B000 */  mtc1      $at, $f22
/* 1795F4 8024AD14 00000000 */  nop
/* 1795F8 8024AD18 46166302 */  mul.s     $f12, $f12, $f22
/* 1795FC 8024AD1C 00000000 */  nop
/* 179600 8024AD20 3C013F00 */  lui       $at, 0x3f00
/* 179604 8024AD24 4481A000 */  mtc1      $at, $f20
/* 179608 8024AD28 00000000 */  nop
/* 17960C 8024AD2C 46146302 */  mul.s     $f12, $f12, $f20
/* 179610 8024AD30 0C00A85B */  jal       sin_rad
/* 179614 8024AD34 00000000 */   nop
/* 179618 8024AD38 46160002 */  mul.s     $f0, $f0, $f22
/* 17961C 8024AD3C 00000000 */  nop
/* 179620 8024AD40 46140302 */  mul.s     $f12, $f0, $f20
/* 179624 8024AD44 0C00A85B */  jal       sin_rad
/* 179628 8024AD48 00000000 */   nop
/* 17962C 8024AD4C 46160002 */  mul.s     $f0, $f0, $f22
/* 179630 8024AD50 00000000 */  nop
/* 179634 8024AD54 46140302 */  mul.s     $f12, $f0, $f20
/* 179638 8024AD58 0C00A85B */  jal       sin_rad
/* 17963C 8024AD5C 00000000 */   nop
/* 179640 8024AD60 08092B65 */  j         .L8024AD94
/* 179644 8024AD64 4600C501 */   sub.s    $f20, $f24, $f0
.L8024AD68:
/* 179648 8024AD68 3C02802A */  lui       $v0, %hi(BattleCam_MoveTimeLeft)
/* 17964C 8024AD6C 8442F29E */  lh        $v0, %lo(BattleCam_MoveTimeLeft)($v0)
/* 179650 8024AD70 3C03802A */  lui       $v1, %hi(BattleCam_MoveTimeTotal)
/* 179654 8024AD74 8463F2A0 */  lh        $v1, %lo(BattleCam_MoveTimeTotal)($v1)
/* 179658 8024AD78 4482A000 */  mtc1      $v0, $f20
/* 17965C 8024AD7C 00000000 */  nop
/* 179660 8024AD80 4680A520 */  cvt.s.w   $f20, $f20
/* 179664 8024AD84 44830000 */  mtc1      $v1, $f0
/* 179668 8024AD88 00000000 */  nop
/* 17966C 8024AD8C 46800020 */  cvt.s.w   $f0, $f0
/* 179670 8024AD90 4600A503 */  div.s     $f20, $f20, $f0
.L8024AD94:
/* 179674 8024AD94 3C02802A */  lui       $v0, %hi(D_8029F2A3)
/* 179678 8024AD98 8042F2A3 */  lb        $v0, %lo(D_8029F2A3)($v0)
/* 17967C 8024AD9C 10400013 */  beqz      $v0, .L8024ADEC
/* 179680 8024ADA0 00000000 */   nop
/* 179684 8024ADA4 3C01802A */  lui       $at, %hi(BattleCam_TargetPosX)
/* 179688 8024ADA8 C424F2A8 */  lwc1      $f4, %lo(BattleCam_TargetPosX)($at)
/* 17968C 8024ADAC 46142102 */  mul.s     $f4, $f4, $f20
/* 179690 8024ADB0 00000000 */  nop
/* 179694 8024ADB4 3C02802A */  lui       $v0, %hi(D_8029F2A7)
/* 179698 8024ADB8 8042F2A7 */  lb        $v0, %lo(D_8029F2A7)($v0)
/* 17969C 8024ADBC 44821000 */  mtc1      $v0, $f2
/* 1796A0 8024ADC0 00000000 */  nop
/* 1796A4 8024ADC4 468010A0 */  cvt.s.w   $f2, $f2
/* 1796A8 8024ADC8 4602D080 */  add.s     $f2, $f26, $f2
/* 1796AC 8024ADCC 3C013F80 */  lui       $at, 0x3f80
/* 1796B0 8024ADD0 44810000 */  mtc1      $at, $f0
/* 1796B4 8024ADD4 00000000 */  nop
/* 1796B8 8024ADD8 46140001 */  sub.s     $f0, $f0, $f20
/* 1796BC 8024ADDC 46001082 */  mul.s     $f2, $f2, $f0
/* 1796C0 8024ADE0 00000000 */  nop
/* 1796C4 8024ADE4 46022100 */  add.s     $f4, $f4, $f2
/* 1796C8 8024ADE8 E6040054 */  swc1      $f4, 0x54($s0)
.L8024ADEC:
/* 1796CC 8024ADEC 3C02802A */  lui       $v0, %hi(D_8029F2A2)
/* 1796D0 8024ADF0 8042F2A2 */  lb        $v0, %lo(D_8029F2A2)($v0)
/* 1796D4 8024ADF4 1040000E */  beqz      $v0, .L8024AE30
/* 1796D8 8024ADF8 00000000 */   nop
/* 1796DC 8024ADFC 3C01802A */  lui       $at, %hi(BattleCam_TargetPosY)
/* 1796E0 8024AE00 C422F2AC */  lwc1      $f2, %lo(BattleCam_TargetPosY)($at)
/* 1796E4 8024AE04 46141082 */  mul.s     $f2, $f2, $f20
/* 1796E8 8024AE08 00000000 */  nop
/* 1796EC 8024AE0C 3C013F80 */  lui       $at, 0x3f80
/* 1796F0 8024AE10 44810000 */  mtc1      $at, $f0
/* 1796F4 8024AE14 00000000 */  nop
/* 1796F8 8024AE18 46140001 */  sub.s     $f0, $f0, $f20
/* 1796FC 8024AE1C C7B20010 */  lwc1      $f18, 0x10($sp)
/* 179700 8024AE20 46009002 */  mul.s     $f0, $f18, $f0
/* 179704 8024AE24 00000000 */  nop
/* 179708 8024AE28 46001080 */  add.s     $f2, $f2, $f0
/* 17970C 8024AE2C E6020058 */  swc1      $f2, 0x58($s0)
.L8024AE30:
/* 179710 8024AE30 3C01802A */  lui       $at, %hi(BattleCam_TargetPosZ)
/* 179714 8024AE34 C430F2B0 */  lwc1      $f16, %lo(BattleCam_TargetPosZ)($at)
/* 179718 8024AE38 46148402 */  mul.s     $f16, $f16, $f20
/* 17971C 8024AE3C 00000000 */  nop
/* 179720 8024AE40 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomZOffset)
/* 179724 8024AE44 C42CF298 */  lwc1      $f12, %lo(BattleCam_TargetBoomZOffset)($at)
/* 179728 8024AE48 46146302 */  mul.s     $f12, $f12, $f20
/* 17972C 8024AE4C 00000000 */  nop
/* 179730 8024AE50 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomLength)
/* 179734 8024AE54 C42EF28C */  lwc1      $f14, %lo(BattleCam_TargetBoomLength)($at)
/* 179738 8024AE58 46147382 */  mul.s     $f14, $f14, $f20
/* 17973C 8024AE5C 00000000 */  nop
/* 179740 8024AE60 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomYaw)
/* 179744 8024AE64 C428F290 */  lwc1      $f8, %lo(BattleCam_TargetBoomYaw)($at)
/* 179748 8024AE68 46144202 */  mul.s     $f8, $f8, $f20
/* 17974C 8024AE6C 00000000 */  nop
/* 179750 8024AE70 3C01802A */  lui       $at, %hi(BattleCam_TargetBoomPitch)
/* 179754 8024AE74 C426F294 */  lwc1      $f6, %lo(BattleCam_TargetBoomPitch)($at)
/* 179758 8024AE78 46143182 */  mul.s     $f6, $f6, $f20
/* 17975C 8024AE7C 00000000 */  nop
/* 179760 8024AE80 3C013F80 */  lui       $at, 0x3f80
/* 179764 8024AE84 44812000 */  mtc1      $at, $f4
/* 179768 8024AE88 3C02802A */  lui       $v0, %hi(BattleCam_BoomZOffset)
/* 17976C 8024AE8C 8442F286 */  lh        $v0, %lo(BattleCam_BoomZOffset)($v0)
/* 179770 8024AE90 46142101 */  sub.s     $f4, $f4, $f20
/* 179774 8024AE94 44820000 */  mtc1      $v0, $f0
/* 179778 8024AE98 00000000 */  nop
/* 17977C 8024AE9C 46800020 */  cvt.s.w   $f0, $f0
/* 179780 8024AEA0 46040002 */  mul.s     $f0, $f0, $f4
/* 179784 8024AEA4 00000000 */  nop
/* 179788 8024AEA8 3C02802A */  lui       $v0, %hi(BattleCam_BoomLength)
/* 17978C 8024AEAC 8442F280 */  lh        $v0, %lo(BattleCam_BoomLength)($v0)
/* 179790 8024AEB0 4604E702 */  mul.s     $f28, $f28, $f4
/* 179794 8024AEB4 00000000 */  nop
/* 179798 8024AEB8 44825000 */  mtc1      $v0, $f10
/* 17979C 8024AEBC 00000000 */  nop
/* 1797A0 8024AEC0 468052A0 */  cvt.s.w   $f10, $f10
/* 1797A4 8024AEC4 3C02802A */  lui       $v0, %hi(BattleCam_BoomYaw)
/* 1797A8 8024AEC8 8442F282 */  lh        $v0, %lo(BattleCam_BoomYaw)($v0)
/* 1797AC 8024AECC 44821000 */  mtc1      $v0, $f2
/* 1797B0 8024AED0 00000000 */  nop
/* 1797B4 8024AED4 468010A0 */  cvt.s.w   $f2, $f2
/* 1797B8 8024AED8 46041082 */  mul.s     $f2, $f2, $f4
/* 1797BC 8024AEDC 00000000 */  nop
/* 1797C0 8024AEE0 46006300 */  add.s     $f12, $f12, $f0
/* 1797C4 8024AEE4 3C014380 */  lui       $at, 0x4380
/* 1797C8 8024AEE8 44810000 */  mtc1      $at, $f0
/* 1797CC 8024AEEC 00000000 */  nop
/* 1797D0 8024AEF0 46006302 */  mul.s     $f12, $f12, $f0
/* 1797D4 8024AEF4 00000000 */  nop
/* 1797D8 8024AEF8 3C014200 */  lui       $at, 0x4200
/* 1797DC 8024AEFC 44810000 */  mtc1      $at, $f0
/* 1797E0 8024AF00 00000000 */  nop
/* 1797E4 8024AF04 4600F001 */  sub.s     $f0, $f30, $f0
/* 1797E8 8024AF08 3C02802A */  lui       $v0, %hi(BattleCam_BoomPitch)
/* 1797EC 8024AF0C 8442F284 */  lh        $v0, %lo(BattleCam_BoomPitch)($v0)
/* 1797F0 8024AF10 46005280 */  add.s     $f10, $f10, $f0
/* 1797F4 8024AF14 44820000 */  mtc1      $v0, $f0
/* 1797F8 8024AF18 00000000 */  nop
/* 1797FC 8024AF1C 46800020 */  cvt.s.w   $f0, $f0
/* 179800 8024AF20 46040002 */  mul.s     $f0, $f0, $f4
/* 179804 8024AF24 00000000 */  nop
/* 179808 8024AF28 46045282 */  mul.s     $f10, $f10, $f4
/* 17980C 8024AF2C 00000000 */  nop
/* 179810 8024AF30 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 179814 8024AF34 461C8400 */  add.s     $f16, $f16, $f28
/* 179818 8024AF38 46024200 */  add.s     $f8, $f8, $f2
/* 17981C 8024AF3C 3C04802A */  lui       $a0, %hi(BattleCam_MoveTimeLeft)
/* 179820 8024AF40 2484F29E */  addiu     $a0, $a0, %lo(BattleCam_MoveTimeLeft)
/* 179824 8024AF44 E610005C */  swc1      $f16, 0x5c($s0)
/* 179828 8024AF48 46003180 */  add.s     $f6, $f6, $f0
/* 17982C 8024AF4C 4600448D */  trunc.w.s $f18, $f8
/* 179830 8024AF50 44029000 */  mfc1      $v0, $f18
/* 179834 8024AF54 00000000 */  nop
/* 179838 8024AF58 A6020024 */  sh        $v0, 0x24($s0)
/* 17983C 8024AF5C 460A7380 */  add.s     $f14, $f14, $f10
/* 179840 8024AF60 4600348D */  trunc.w.s $f18, $f6
/* 179844 8024AF64 44029000 */  mfc1      $v0, $f18
/* 179848 8024AF68 00000000 */  nop
/* 17984C 8024AF6C A6020022 */  sh        $v0, 0x22($s0)
/* 179850 8024AF70 4600748D */  trunc.w.s $f18, $f14
/* 179854 8024AF74 44029000 */  mfc1      $v0, $f18
/* 179858 8024AF78 00000000 */  nop
/* 17985C 8024AF7C A602001E */  sh        $v0, 0x1e($s0)
/* 179860 8024AF80 4600648D */  trunc.w.s $f18, $f12
/* 179864 8024AF84 44029000 */  mfc1      $v0, $f18
/* 179868 8024AF88 00000000 */  nop
/* 17986C 8024AF8C A6020026 */  sh        $v0, 0x26($s0)
/* 179870 8024AF90 84820000 */  lh        $v0, ($a0)
/* 179874 8024AF94 94830000 */  lhu       $v1, ($a0)
/* 179878 8024AF98 14400006 */  bnez      $v0, .L8024AFB4
/* 17987C 8024AF9C 2462FFFF */   addiu    $v0, $v1, -1
/* 179880 8024AFA0 24020001 */  addiu     $v0, $zero, 1
/* 179884 8024AFA4 3C01802A */  lui       $at, %hi(BattleCam_DoneMoving)
/* 179888 8024AFA8 A022F29C */  sb        $v0, %lo(BattleCam_DoneMoving)($at)
/* 17988C 8024AFAC 08092BEF */  j         .L8024AFBC
/* 179890 8024AFB0 0000102D */   daddu    $v0, $zero, $zero
.L8024AFB4:
/* 179894 8024AFB4 A4820000 */  sh        $v0, ($a0)
/* 179898 8024AFB8 0000102D */  daddu     $v0, $zero, $zero
.L8024AFBC:
/* 17989C 8024AFBC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1798A0 8024AFC0 8FB00020 */  lw        $s0, 0x20($sp)
/* 1798A4 8024AFC4 D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 1798A8 8024AFC8 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 1798AC 8024AFCC D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 1798B0 8024AFD0 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 1798B4 8024AFD4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 1798B8 8024AFD8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1798BC 8024AFDC 03E00008 */  jr        $ra
/* 1798C0 8024AFE0 27BD0058 */   addiu    $sp, $sp, 0x58

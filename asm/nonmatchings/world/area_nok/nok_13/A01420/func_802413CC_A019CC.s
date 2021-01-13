.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413CC_A019CC
/* A019CC 802413CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A019D0 802413D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A019D4 802413D4 24020001 */  addiu     $v0, $zero, 1
/* A019D8 802413D8 10A20014 */  beq       $a1, $v0, .L8024142C
/* A019DC 802413DC 0080182D */   daddu    $v1, $a0, $zero
/* A019E0 802413E0 28A20002 */  slti      $v0, $a1, 2
/* A019E4 802413E4 50400005 */  beql      $v0, $zero, .L802413FC
/* A019E8 802413E8 28A20005 */   slti     $v0, $a1, 5
/* A019EC 802413EC 10A00009 */  beqz      $a1, .L80241414
/* A019F0 802413F0 24050001 */   addiu    $a1, $zero, 1
/* A019F4 802413F4 08090521 */  j         .L80241484
/* A019F8 802413F8 00000000 */   nop
.L802413FC:
/* A019FC 802413FC 10400021 */  beqz      $v0, .L80241484
/* A01A00 80241400 28A20003 */   slti     $v0, $a1, 3
/* A01A04 80241404 1440001F */  bnez      $v0, .L80241484
/* A01A08 80241408 24050001 */   addiu    $a1, $zero, 1
/* A01A0C 8024140C 0809051B */  j         .L8024146C
/* A01A10 80241410 00000000 */   nop
.L80241414:
/* A01A14 80241414 3C048024 */  lui       $a0, %hi(func_80242134_88AD04)
/* A01A18 80241418 24842134 */  addiu     $a0, $a0, %lo(func_80242134_88AD04)
/* A01A1C 8024141C 0C0B0CF8 */  jal       start_script
/* A01A20 80241420 0000302D */   daddu    $a2, $zero, $zero
/* A01A24 80241424 08090520 */  j         .L80241480
/* A01A28 80241428 24030084 */   addiu    $v1, $zero, 0x84
.L8024142C:
/* A01A2C 8024142C 24040156 */  addiu     $a0, $zero, 0x156
/* A01A30 80241430 C4600000 */  lwc1      $f0, ($v1)
/* A01A34 80241434 46800020 */  cvt.s.w   $f0, $f0
/* A01A38 80241438 44050000 */  mfc1      $a1, $f0
/* A01A3C 8024143C C4600004 */  lwc1      $f0, 4($v1)
/* A01A40 80241440 46800020 */  cvt.s.w   $f0, $f0
/* A01A44 80241444 44060000 */  mfc1      $a2, $f0
/* A01A48 80241448 C4600008 */  lwc1      $f0, 8($v1)
/* A01A4C 8024144C 46800020 */  cvt.s.w   $f0, $f0
/* A01A50 80241450 44070000 */  mfc1      $a3, $f0
/* A01A54 80241454 24020003 */  addiu     $v0, $zero, 3
/* A01A58 80241458 AFA20010 */  sw        $v0, 0x10($sp)
/* A01A5C 8024145C 0C04C6A5 */  jal       make_item_entity_nodelay
/* A01A60 80241460 AFA00014 */   sw       $zero, 0x14($sp)
/* A01A64 80241464 08090521 */  j         .L80241484
/* A01A68 80241468 00000000 */   nop
.L8024146C:
/* A01A6C 8024146C 3C048024 */  lui       $a0, %hi(func_80242134_88AD04)
/* A01A70 80241470 24842134 */  addiu     $a0, $a0, %lo(func_80242134_88AD04)
/* A01A74 80241474 0C0B0CF8 */  jal       start_script
/* A01A78 80241478 0000302D */   daddu    $a2, $zero, $zero
/* A01A7C 8024147C 24030011 */  addiu     $v1, $zero, 0x11
.L80241480:
/* A01A80 80241480 AC430084 */  sw        $v1, 0x84($v0)
.L80241484:
/* A01A84 80241484 8FBF0018 */  lw        $ra, 0x18($sp)
/* A01A88 80241488 03E00008 */  jr        $ra
/* A01A8C 8024148C 27BD0020 */   addiu    $sp, $sp, 0x20

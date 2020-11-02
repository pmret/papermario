.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_C804B0
/* C804B0 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C804B4 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* C804B8 80240318 0080882D */  daddu     $s1, $a0, $zero
/* C804BC 8024031C AFBF001C */  sw        $ra, 0x1c($sp)
/* C804C0 80240320 AFB20018 */  sw        $s2, 0x18($sp)
/* C804C4 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* C804C8 80240328 8E30000C */  lw        $s0, 0xc($s1)
/* C804CC 8024032C 8E050000 */  lw        $a1, ($s0)
/* C804D0 80240330 0C0B1EAF */  jal       get_variable
/* C804D4 80240334 26100004 */   addiu    $s0, $s0, 4
/* C804D8 80240338 8E050000 */  lw        $a1, ($s0)
/* C804DC 8024033C 26100004 */  addiu     $s0, $s0, 4
/* C804E0 80240340 0220202D */  daddu     $a0, $s1, $zero
/* C804E4 80240344 0C0B1EAF */  jal       get_variable
/* C804E8 80240348 0040902D */   daddu    $s2, $v0, $zero
/* C804EC 8024034C 0220202D */  daddu     $a0, $s1, $zero
/* C804F0 80240350 8E050000 */  lw        $a1, ($s0)
/* C804F4 80240354 0C0B1EAF */  jal       get_variable
/* C804F8 80240358 0040882D */   daddu    $s1, $v0, $zero
/* C804FC 8024035C 0040802D */  daddu     $s0, $v0, $zero
/* C80500 80240360 3C028016 */  lui       $v0, %hi(gCollisionStatus)
/* C80504 80240364 2442A550 */  addiu     $v0, $v0, %lo(gCollisionStatus)
/* C80508 80240368 84430002 */  lh        $v1, 2($v0)
/* C8050C 8024036C 10710008 */  beq       $v1, $s1, .L80240390
/* C80510 80240370 00000000 */   nop      
/* C80514 80240374 84420004 */  lh        $v0, 4($v0)
/* C80518 80240378 10510005 */  beq       $v0, $s1, .L80240390
/* C8051C 8024037C 00000000 */   nop      
/* C80520 80240380 10700003 */  beq       $v1, $s0, .L80240390
/* C80524 80240384 00000000 */   nop      
/* C80528 80240388 14500007 */  bne       $v0, $s0, .L802403A8
/* C8052C 8024038C 00000000 */   nop      
.L80240390:
/* C80530 80240390 44920000 */  mtc1      $s2, $f0
/* C80534 80240394 00000000 */  nop       
/* C80538 80240398 46800020 */  cvt.s.w   $f0, $f0
/* C8053C 8024039C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C80540 802403A0 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C80544 802403A4 E440001C */  swc1      $f0, 0x1c($v0)
.L802403A8:
/* C80548 802403A8 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* C8054C 802403AC 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* C80550 802403B0 1040000E */  beqz      $v0, .L802403EC
/* C80554 802403B4 00000000 */   nop      
/* C80558 802403B8 0C00EABB */  jal       get_npc_unsafe
/* C8055C 802403BC 2404FFFC */   addiu    $a0, $zero, -4
/* C80560 802403C0 84430084 */  lh        $v1, 0x84($v0)
/* C80564 802403C4 10710003 */  beq       $v1, $s1, .L802403D4
/* C80568 802403C8 00000000 */   nop      
/* C8056C 802403CC 14700007 */  bne       $v1, $s0, .L802403EC
/* C80570 802403D0 00000000 */   nop      
.L802403D4:
/* C80574 802403D4 C4400038 */  lwc1      $f0, 0x38($v0)
/* C80578 802403D8 44921000 */  mtc1      $s2, $f2
/* C8057C 802403DC 00000000 */  nop       
/* C80580 802403E0 468010A0 */  cvt.s.w   $f2, $f2
/* C80584 802403E4 46020000 */  add.s     $f0, $f0, $f2
/* C80588 802403E8 E4400038 */  swc1      $f0, 0x38($v0)
.L802403EC:
/* C8058C 802403EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* C80590 802403F0 8FB20018 */  lw        $s2, 0x18($sp)
/* C80594 802403F4 8FB10014 */  lw        $s1, 0x14($sp)
/* C80598 802403F8 8FB00010 */  lw        $s0, 0x10($sp)
/* C8059C 802403FC 24020002 */  addiu     $v0, $zero, 2
/* C805A0 80240400 03E00008 */  jr        $ra
/* C805A4 80240404 27BD0020 */   addiu    $sp, $sp, 0x20

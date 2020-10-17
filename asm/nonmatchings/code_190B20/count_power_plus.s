.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel count_power_plus
/* 1923F0 80263B10 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1923F4 80263B14 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1923F8 80263B18 9042007E */  lbu       $v0, 0x7e($v0)
/* 1923FC 80263B1C 30420001 */  andi      $v0, $v0, 1
/* 192400 80263B20 10400003 */  beqz      $v0, .L80263B30
/* 192404 80263B24 0000382D */   daddu    $a3, $zero, $zero
/* 192408 80263B28 03E00008 */  jr        $ra
/* 19240C 80263B2C 0000102D */   daddu    $v0, $zero, $zero
.L80263B30:
/* 192410 80263B30 00E0302D */  daddu     $a2, $a3, $zero
/* 192414 80263B34 3C0C8008 */  lui       $t4, %hi(gItemTable)
/* 192418 80263B38 258C78E0 */  addiu     $t4, $t4, %lo(gItemTable)
/* 19241C 80263B3C 3C0B8009 */  lui       $t3, 0x8009
/* 192420 80263B40 256BF060 */  addiu     $t3, $t3, -0xfa0
/* 192424 80263B44 240A0007 */  addiu     $t2, $zero, 7
/* 192428 80263B48 2409003B */  addiu     $t1, $zero, 0x3b
/* 19242C 80263B4C 3C08800E */  lui       $t0, %hi(gBattleStatus)
/* 192430 80263B50 2508C070 */  addiu     $t0, $t0, %lo(gBattleStatus)
/* 192434 80263B54 30840080 */  andi      $a0, $a0, 0x80
/* 192438 80263B58 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 19243C 80263B5C 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
.L80263B60:
/* 192440 80263B60 84A20208 */  lh        $v0, 0x208($a1)
/* 192444 80263B64 00021140 */  sll       $v0, $v0, 5
/* 192448 80263B68 004C1021 */  addu      $v0, $v0, $t4
/* 19244C 80263B6C 9043001A */  lbu       $v1, 0x1a($v0)
/* 192450 80263B70 00031080 */  sll       $v0, $v1, 2
/* 192454 80263B74 00431021 */  addu      $v0, $v0, $v1
/* 192458 80263B78 00021080 */  sll       $v0, $v0, 2
/* 19245C 80263B7C 004B1021 */  addu      $v0, $v0, $t3
/* 192460 80263B80 80420010 */  lb        $v0, 0x10($v0)
/* 192464 80263B84 544A000B */  bnel      $v0, $t2, .L80263BB4
/* 192468 80263B88 24C60001 */   addiu    $a2, $a2, 1
/* 19246C 80263B8C 54690009 */  bnel      $v1, $t1, .L80263BB4
/* 192470 80263B90 24C60001 */   addiu    $a2, $a2, 1
/* 192474 80263B94 8D020000 */  lw        $v0, ($t0)
/* 192478 80263B98 30420010 */  andi      $v0, $v0, 0x10
/* 19247C 80263B9C 54400004 */  bnel      $v0, $zero, .L80263BB0
/* 192480 80263BA0 24E70001 */   addiu    $a3, $a3, 1
/* 192484 80263BA4 50800003 */  beql      $a0, $zero, .L80263BB4
/* 192488 80263BA8 24C60001 */   addiu    $a2, $a2, 1
/* 19248C 80263BAC 24E70001 */  addiu     $a3, $a3, 1
.L80263BB0:
/* 192490 80263BB0 24C60001 */  addiu     $a2, $a2, 1
.L80263BB4:
/* 192494 80263BB4 28C20040 */  slti      $v0, $a2, 0x40
/* 192498 80263BB8 1440FFE9 */  bnez      $v0, .L80263B60
/* 19249C 80263BBC 24A50002 */   addiu    $a1, $a1, 2
/* 1924A0 80263BC0 03E00008 */  jr        $ra
/* 1924A4 80263BC4 00E0102D */   daddu    $v0, $a3, $zero

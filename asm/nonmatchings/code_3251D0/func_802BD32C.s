.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD32C
/* 3253FC 802BD32C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 325400 802BD330 AFBF0014 */  sw        $ra, 0x14($sp)
/* 325404 802BD334 AFB00010 */  sw        $s0, 0x10($sp)
/* 325408 802BD338 8C82000C */  lw        $v0, 0xc($a0)
/* 32540C 802BD33C 0C0B1EAF */  jal       get_variable
/* 325410 802BD340 8C450000 */   lw       $a1, ($v0)
/* 325414 802BD344 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 325418 802BD348 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 32541C 802BD34C 80640002 */  lb        $a0, 2($v1)
/* 325420 802BD350 80650003 */  lb        $a1, 3($v1)
/* 325424 802BD354 00822021 */  addu      $a0, $a0, $v0
/* 325428 802BD358 00A4102A */  slt       $v0, $a1, $a0
/* 32542C 802BD35C 10400002 */  beqz      $v0, .L802BD368
/* 325430 802BD360 0060802D */   daddu    $s0, $v1, $zero
/* 325434 802BD364 00A0202D */  daddu     $a0, $a1, $zero
.L802BD368:
/* 325438 802BD368 58800001 */  blezl     $a0, .L802BD370
/* 32543C 802BD36C 24040001 */   addiu    $a0, $zero, 1
.L802BD370:
/* 325440 802BD370 A2040002 */  sb        $a0, 2($s0)
/* 325444 802BD374 8FBF0014 */  lw        $ra, 0x14($sp)
/* 325448 802BD378 8FB00010 */  lw        $s0, 0x10($sp)
/* 32544C 802BD37C 24020002 */  addiu     $v0, $zero, 2
/* 325450 802BD380 03E00008 */  jr        $ra
/* 325454 802BD384 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A149C_730A3C
/* 730A3C 802A149C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 730A40 802A14A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 730A44 802A14A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 730A48 802A14A8 8C82000C */  lw        $v0, 0xc($a0)
/* 730A4C 802A14AC 0C0B1EAF */  jal       get_variable
/* 730A50 802A14B0 8C450000 */   lw       $a1, ($v0)
/* 730A54 802A14B4 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 730A58 802A14B8 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 730A5C 802A14BC 80640002 */  lb        $a0, 2($v1)
/* 730A60 802A14C0 80650006 */  lb        $a1, 6($v1)
/* 730A64 802A14C4 00822021 */  addu      $a0, $a0, $v0
/* 730A68 802A14C8 00A4102A */  slt       $v0, $a1, $a0
/* 730A6C 802A14CC 10400002 */  beqz      $v0, .L802A14D8
/* 730A70 802A14D0 0060802D */   daddu    $s0, $v1, $zero
/* 730A74 802A14D4 00A0202D */  daddu     $a0, $a1, $zero
.L802A14D8:
/* 730A78 802A14D8 A2040005 */  sb        $a0, 5($s0)
/* 730A7C 802A14DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 730A80 802A14E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 730A84 802A14E4 24020002 */  addiu     $v0, $zero, 2
/* 730A88 802A14E8 03E00008 */  jr        $ra
/* 730A8C 802A14EC 27BD0018 */   addiu    $sp, $sp, 0x18

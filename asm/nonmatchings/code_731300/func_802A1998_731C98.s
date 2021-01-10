.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1998_731C98
/* 731C98 802A1998 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 731C9C 802A199C AFBF0014 */  sw        $ra, 0x14($sp)
/* 731CA0 802A19A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 731CA4 802A19A4 8C82000C */  lw        $v0, 0xc($a0)
/* 731CA8 802A19A8 0C0B1EAF */  jal       get_variable
/* 731CAC 802A19AC 8C450000 */   lw       $a1, ($v0)
/* 731CB0 802A19B0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 731CB4 802A19B4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 731CB8 802A19B8 80640002 */  lb        $a0, 2($v1)
/* 731CBC 802A19BC 80650003 */  lb        $a1, 3($v1)
/* 731CC0 802A19C0 00822021 */  addu      $a0, $a0, $v0
/* 731CC4 802A19C4 00A4102A */  slt       $v0, $a1, $a0
/* 731CC8 802A19C8 10400002 */  beqz      $v0, .L802A19D4
/* 731CCC 802A19CC 0060802D */   daddu    $s0, $v1, $zero
/* 731CD0 802A19D0 00A0202D */  daddu     $a0, $a1, $zero
.L802A19D4:
/* 731CD4 802A19D4 A2040002 */  sb        $a0, 2($s0)
/* 731CD8 802A19D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 731CDC 802A19DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 731CE0 802A19E0 24020002 */  addiu     $v0, $zero, 2
/* 731CE4 802A19E4 03E00008 */  jr        $ra
/* 731CE8 802A19E8 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A14D8_7251B8
/* 7251B8 802A14D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7251BC 802A14DC AFBF0014 */  sw        $ra, 0x14($sp)
/* 7251C0 802A14E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 7251C4 802A14E4 8C82000C */  lw        $v0, 0xc($a0)
/* 7251C8 802A14E8 0C0B1EAF */  jal       get_variable
/* 7251CC 802A14EC 8C450000 */   lw       $a1, ($v0)
/* 7251D0 802A14F0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 7251D4 802A14F4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 7251D8 802A14F8 80640005 */  lb        $a0, 5($v1)
/* 7251DC 802A14FC 80650006 */  lb        $a1, 6($v1)
/* 7251E0 802A1500 00822021 */  addu      $a0, $a0, $v0
/* 7251E4 802A1504 00A4102A */  slt       $v0, $a1, $a0
/* 7251E8 802A1508 10400002 */  beqz      $v0, .L802A1514
/* 7251EC 802A150C 0060802D */   daddu    $s0, $v1, $zero
/* 7251F0 802A1510 00A0202D */  daddu     $a0, $a1, $zero
.L802A1514:
/* 7251F4 802A1514 A2040005 */  sb        $a0, 5($s0)
/* 7251F8 802A1518 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7251FC 802A151C 8FB00010 */  lw        $s0, 0x10($sp)
/* 725200 802A1520 24020002 */  addiu     $v0, $zero, 2
/* 725204 802A1524 03E00008 */  jr        $ra
/* 725208 802A1528 27BD0018 */   addiu    $sp, $sp, 0x18
/* 72520C 802A152C 00000000 */  nop

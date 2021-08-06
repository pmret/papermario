.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDE10_31D980
/* 31D980 802BDE10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31D984 802BDE14 AFB00010 */  sw        $s0, 0x10($sp)
/* 31D988 802BDE18 0080802D */  daddu     $s0, $a0, $zero
/* 31D98C 802BDE1C 3C048011 */  lui       $a0, %hi(gPartnerActionStatus)
/* 31D990 802BDE20 2484EBB0 */  addiu     $a0, $a0, %lo(gPartnerActionStatus)
/* 31D994 802BDE24 AFBF0014 */  sw        $ra, 0x14($sp)
/* 31D998 802BDE28 80820001 */  lb        $v0, 1($a0)
/* 31D99C 802BDE2C 10400012 */  beqz      $v0, .L802BDE78
/* 31D9A0 802BDE30 0200182D */   daddu    $v1, $s0, $zero
/* 31D9A4 802BDE34 24820018 */  addiu     $v0, $a0, 0x18
/* 31D9A8 802BDE38 24840358 */  addiu     $a0, $a0, 0x358
.L802BDE3C:
/* 31D9AC 802BDE3C 8C450000 */  lw        $a1, ($v0)
/* 31D9B0 802BDE40 8C460004 */  lw        $a2, 4($v0)
/* 31D9B4 802BDE44 8C470008 */  lw        $a3, 8($v0)
/* 31D9B8 802BDE48 8C48000C */  lw        $t0, 0xc($v0)
/* 31D9BC 802BDE4C AC650000 */  sw        $a1, ($v1)
/* 31D9C0 802BDE50 AC660004 */  sw        $a2, 4($v1)
/* 31D9C4 802BDE54 AC670008 */  sw        $a3, 8($v1)
/* 31D9C8 802BDE58 AC68000C */  sw        $t0, 0xc($v1)
/* 31D9CC 802BDE5C 24420010 */  addiu     $v0, $v0, 0x10
/* 31D9D0 802BDE60 1444FFF6 */  bne       $v0, $a0, .L802BDE3C
/* 31D9D4 802BDE64 24630010 */   addiu    $v1, $v1, 0x10
/* 31D9D8 802BDE68 0C03ACC5 */  jal       partner_use_ability
/* 31D9DC 802BDE6C 00000000 */   nop
/* 31D9E0 802BDE70 0C0AF440 */  jal       func_802BD100_31CC70
/* 31D9E4 802BDE74 0200202D */   daddu    $a0, $s0, $zero
.L802BDE78:
/* 31D9E8 802BDE78 8FBF0014 */  lw        $ra, 0x14($sp)
/* 31D9EC 802BDE7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 31D9F0 802BDE80 03E00008 */  jr        $ra
/* 31D9F4 802BDE84 27BD0018 */   addiu    $sp, $sp, 0x18

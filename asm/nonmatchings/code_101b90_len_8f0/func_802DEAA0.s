.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DEAA0
/* 101B90 802DEAA0 00C0102D */  daddu     $v0, $a2, $zero
/* 101B94 802DEAA4 24C60010 */  addiu     $a2, $a2, 0x10
/* 101B98 802DEAA8 2408FFFF */  addiu     $t0, $zero, -1
/* 101B9C 802DEAAC 00052882 */  srl       $a1, $a1, 2
/* 101BA0 802DEAB0 00052880 */  sll       $a1, $a1, 2
/* 101BA4 802DEAB4 00021082 */  srl       $v0, $v0, 2
/* 101BA8 802DEAB8 00023880 */  sll       $a3, $v0, 2
.L802DEABC:
/* 101BAC 802DEABC 8CC20000 */  lw        $v0, ($a2)
/* 101BB0 802DEAC0 10480010 */  beq       $v0, $t0, .L802DEB04
/* 101BB4 802DEAC4 00452023 */   subu     $a0, $v0, $a1
/* 101BB8 802DEAC8 00872021 */  addu      $a0, $a0, $a3
/* 101BBC 802DEACC ACC40000 */  sw        $a0, ($a2)
.L802DEAD0:
/* 101BC0 802DEAD0 8C830000 */  lw        $v1, ($a0)
/* 101BC4 802DEAD4 10680009 */  beq       $v1, $t0, .L802DEAFC
/* 101BC8 802DEAD8 00651823 */   subu     $v1, $v1, $a1
/* 101BCC 802DEADC 00671821 */  addu      $v1, $v1, $a3
/* 101BD0 802DEAE0 AC830000 */  sw        $v1, ($a0)
/* 101BD4 802DEAE4 8C620000 */  lw        $v0, ($v1)
/* 101BD8 802DEAE8 24840004 */  addiu     $a0, $a0, 4
/* 101BDC 802DEAEC 00451023 */  subu      $v0, $v0, $a1
/* 101BE0 802DEAF0 00471021 */  addu      $v0, $v0, $a3
/* 101BE4 802DEAF4 080B7AB4 */  j         .L802DEAD0
/* 101BE8 802DEAF8 AC620000 */   sw       $v0, ($v1)
.L802DEAFC:
/* 101BEC 802DEAFC 080B7AAF */  j         .L802DEABC
/* 101BF0 802DEB00 24C60004 */   addiu    $a2, $a2, 4
.L802DEB04:
/* 101BF4 802DEB04 03E00008 */  jr        $ra
/* 101BF8 802DEB08 00000000 */   nop      

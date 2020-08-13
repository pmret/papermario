.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024AAA0
/* 13DDE0 8024AAA0 00A40018 */  mult  $a1, $a0
/* 13DDE4 8024AAA4 00005012 */  mflo  $t2
/* 13DDE8 8024AAA8 000A1040 */  sll   $v0, $t2, 1
/* 13DDEC 8024AAAC 3C038027 */  lui   $v1, 0x8027
/* 13DDF0 8024AAB0 00621821 */  addu  $v1, $v1, $v0
/* 13DDF4 8024AAB4 84630400 */  lh    $v1, 0x400($v1)
/* 13DDF8 8024AAB8 24027FFE */  addiu $v0, $zero, 0x7ffe
/* 13DDFC 8024AABC 10620012 */  beq   $v1, $v0, .L8024AB08
/* 13DE00 8024AAC0 3C020004 */   lui   $v0, 4
/* 13DE04 8024AAC4 3C038027 */  lui   $v1, 0x8027
/* 13DE08 8024AAC8 8C6300C0 */  lw    $v1, 0xc0($v1)
/* 13DE0C 8024AACC 00621024 */  and   $v0, $v1, $v0
/* 13DE10 8024AAD0 10400006 */  beqz  $v0, .L8024AAEC
/* 13DE14 8024AAD4 3C020008 */   lui   $v0, 8
/* 13DE18 8024AAD8 2508FFFF */  addiu $t0, $t0, -1
/* 13DE1C 8024AADC 0502000B */  bltzl $t0, .L8024AB0C
/* 13DE20 8024AAE0 2488FFFF */   addiu $t0, $a0, -1
/* 13DE24 8024AAE4 08092AC3 */  j     func_8024AB0C
/* 13DE28 8024AAE8 00000000 */   nop   


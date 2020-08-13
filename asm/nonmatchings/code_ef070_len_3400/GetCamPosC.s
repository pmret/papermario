.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCamPosC
/* 0F0BC4 802CC214 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0BC8 802CC218 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0BCC 802CC21C 0080902D */  daddu $s2, $a0, $zero
/* 0F0BD0 802CC220 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0BD4 802CC224 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0BD8 802CC228 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0BDC 802CC22C 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0BE0 802CC230 8E250000 */  lw    $a1, ($s1)
/* 0F0BE4 802CC234 0C0B1EAF */  jal   get_variable
/* 0F0BE8 802CC238 26310004 */   addiu $s1, $s1, 4
/* 0F0BEC 802CC23C 3C03800B */  lui   $v1, 0x800b
/* 0F0BF0 802CC240 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0BF4 802CC244 00028080 */  sll   $s0, $v0, 2
/* 0F0BF8 802CC248 02028021 */  addu  $s0, $s0, $v0
/* 0F0BFC 802CC24C 00108080 */  sll   $s0, $s0, 2
/* 0F0C00 802CC250 02028023 */  subu  $s0, $s0, $v0
/* 0F0C04 802CC254 001010C0 */  sll   $v0, $s0, 3
/* 0F0C08 802CC258 02028021 */  addu  $s0, $s0, $v0
/* 0F0C0C 802CC25C 001080C0 */  sll   $s0, $s0, 3
/* 0F0C10 802CC260 02038021 */  addu  $s0, $s0, $v1
/* 0F0C14 802CC264 8E250000 */  lw    $a1, ($s1)
/* 0F0C18 802CC268 8E0604E8 */  lw    $a2, 0x4e8($s0)
/* 0F0C1C 802CC26C 8E310004 */  lw    $s1, 4($s1)
/* 0F0C20 802CC270 0C0B2190 */  jal   set_float_variable
/* 0F0C24 802CC274 0240202D */   daddu $a0, $s2, $zero
/* 0F0C28 802CC278 0240202D */  daddu $a0, $s2, $zero
/* 0F0C2C 802CC27C 8E0604F4 */  lw    $a2, 0x4f4($s0)
/* 0F0C30 802CC280 0C0B2190 */  jal   set_float_variable
/* 0F0C34 802CC284 0220282D */   daddu $a1, $s1, $zero
/* 0F0C38 802CC288 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0C3C 802CC28C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0C40 802CC290 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0C44 802CC294 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0C48 802CC298 24020002 */  addiu $v0, $zero, 2
/* 0F0C4C 802CC29C 03E00008 */  jr    $ra
/* 0F0C50 802CC2A0 27BD0020 */   addiu $sp, $sp, 0x20


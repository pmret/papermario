.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel LoadActionCommand
/* 196AA0 802681C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 196AA4 802681C4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 196AA8 802681C8 8C82000C */  lw    $v0, 0xc($a0)
/* 196AAC 802681CC 0C0B1EAF */  jal   get_variable
/* 196AB0 802681D0 8C450000 */   lw    $a1, ($v0)
/* 196AB4 802681D4 3C068029 */  lui   $a2, 0x8029
/* 196AB8 802681D8 24C644C0 */  addiu $a2, $a2, 0x44c0
/* 196ABC 802681DC 00021840 */  sll   $v1, $v0, 1
/* 196AC0 802681E0 00621821 */  addu  $v1, $v1, $v0
/* 196AC4 802681E4 00031080 */  sll   $v0, $v1, 2
/* 196AC8 802681E8 00461021 */  addu  $v0, $v0, $a2
/* 196ACC 802681EC 8C440000 */  lw    $a0, ($v0)
/* 196AD0 802681F0 24620001 */  addiu $v0, $v1, 1
/* 196AD4 802681F4 00021080 */  sll   $v0, $v0, 2
/* 196AD8 802681F8 00461021 */  addu  $v0, $v0, $a2
/* 196ADC 802681FC 24630002 */  addiu $v1, $v1, 2
/* 196AE0 80268200 00031880 */  sll   $v1, $v1, 2
/* 196AE4 80268204 00661821 */  addu  $v1, $v1, $a2
/* 196AE8 80268208 8C450000 */  lw    $a1, ($v0)
/* 196AEC 8026820C 0C00A5CF */  jal   dma_copy
/* 196AF0 80268210 8C660000 */   lw    $a2, ($v1)
/* 196AF4 80268214 8FBF0010 */  lw    $ra, 0x10($sp)
/* 196AF8 80268218 24020002 */  addiu $v0, $zero, 2
/* 196AFC 8026821C 03E00008 */  jr    $ra
/* 196B00 80268220 27BD0018 */   addiu $sp, $sp, 0x18

/* 196B04 80268224 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 196B08 80268228 AFB00010 */  sw    $s0, 0x10($sp)
/* 196B0C 8026822C 0080802D */  daddu $s0, $a0, $zero
/* 196B10 80268230 3C02800E */  lui   $v0, 0x800e
/* 196B14 80268234 8C42C070 */  lw    $v0, -0x3f90($v0)
/* 196B18 80268238 3C030008 */  lui   $v1, 8
/* 196B1C 8026823C 00431024 */  and   $v0, $v0, $v1
/* 196B20 80268240 14400006 */  bnez  $v0, .L8026825C
/* 196B24 80268244 AFBF0014 */   sw    $ra, 0x14($sp)
/* 196B28 80268248 0C03A752 */  jal   is_ability_active
/* 196B2C 8026824C 0000202D */   daddu $a0, $zero, $zero
/* 196B30 80268250 00021840 */  sll   $v1, $v0, 1
/* 196B34 80268254 00621821 */  addu  $v1, $v1, $v0
/* 196B38 80268258 02038023 */  subu  $s0, $s0, $v1
.L8026825C:
/* 196B3C 8026825C 06020001 */  bltzl $s0, .L80268264
/* 196B40 80268260 0000802D */   daddu $s0, $zero, $zero
.L80268264:
/* 196B44 80268264 2A020008 */  slti  $v0, $s0, 8
/* 196B48 80268268 50400001 */  beql  $v0, $zero, .L80268270
/* 196B4C 8026826C 24100007 */   addiu $s0, $zero, 7
.L80268270:
/* 196B50 80268270 0200102D */  daddu $v0, $s0, $zero
/* 196B54 80268274 8FBF0014 */  lw    $ra, 0x14($sp)
/* 196B58 80268278 8FB00010 */  lw    $s0, 0x10($sp)
/* 196B5C 8026827C 03E00008 */  jr    $ra
/* 196B60 80268280 27BD0018 */   addiu $sp, $sp, 0x18


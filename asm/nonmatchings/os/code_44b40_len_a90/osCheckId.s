.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osCheckId
/* 0451D4 80069DD4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0451D8 80069DD8 AFB00030 */  sw    $s0, 0x30($sp)
/* 0451DC 80069DDC 00808021 */  addu  $s0, $a0, $zero
/* 0451E0 80069DE0 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0451E4 80069DE4 92020065 */  lbu   $v0, 0x65($s0)
/* 0451E8 80069DE8 1040000C */  beqz  $v0, .L80069E1C
/* 0451EC 80069DEC 00000000 */   nop   
/* 0451F0 80069DF0 0C01A5B4 */  jal   osPfsSelectBank
/* 0451F4 80069DF4 00002821 */   addu  $a1, $zero, $zero
/* 0451F8 80069DF8 00401821 */  addu  $v1, $v0, $zero
/* 0451FC 80069DFC 24020002 */  addiu $v0, $zero, 2
/* 045200 80069E00 14620004 */  bne   $v1, $v0, .L80069E14
/* 045204 80069E04 02002021 */   addu  $a0, $s0, $zero
/* 045208 80069E08 0C01A5B4 */  jal   osPfsSelectBank
/* 04520C 80069E0C 00002821 */   addu  $a1, $zero, $zero
/* 045210 80069E10 00401821 */  addu  $v1, $v0, $zero
.L80069E14:
/* 045214 80069E14 14600019 */  bnez  $v1, .L80069E7C
/* 045218 80069E18 00601021 */   addu  $v0, $v1, $zero
.L80069E1C:
/* 04521C 80069E1C 8E040004 */  lw    $a0, 4($s0)
/* 045220 80069E20 8E050008 */  lw    $a1, 8($s0)
/* 045224 80069E24 24060001 */  addiu $a2, $zero, 1
/* 045228 80069E28 0C01A874 */  jal   osContRamRead
/* 04522C 80069E2C 27A70010 */   addiu $a3, $sp, 0x10
/* 045230 80069E30 00401821 */  addu  $v1, $v0, $zero
/* 045234 80069E34 1060000B */  beqz  $v1, .L80069E64
/* 045238 80069E38 24020002 */   addiu $v0, $zero, 2
/* 04523C 80069E3C 1462000F */  bne   $v1, $v0, .L80069E7C
/* 045240 80069E40 00601021 */   addu  $v0, $v1, $zero
/* 045244 80069E44 8E040004 */  lw    $a0, 4($s0)
/* 045248 80069E48 8E050008 */  lw    $a1, 8($s0)
/* 04524C 80069E4C 24060001 */  addiu $a2, $zero, 1
/* 045250 80069E50 0C01A874 */  jal   osContRamRead
/* 045254 80069E54 27A70010 */   addiu $a3, $sp, 0x10
/* 045258 80069E58 00401821 */  addu  $v1, $v0, $zero
/* 04525C 80069E5C 14600007 */  bnez  $v1, .L80069E7C
/* 045260 80069E60 00000000 */   nop   
.L80069E64:
/* 045264 80069E64 2604000C */  addiu $a0, $s0, 0xc
/* 045268 80069E68 27A50010 */  addiu $a1, $sp, 0x10
/* 04526C 80069E6C 0C01AE1C */  jal   bcmp
/* 045270 80069E70 24060020 */   addiu $a2, $zero, 0x20
/* 045274 80069E74 0002102B */  sltu  $v0, $zero, $v0
/* 045278 80069E78 00021040 */  sll   $v0, $v0, 1
.L80069E7C:
/* 04527C 80069E7C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 045280 80069E80 8FB00030 */  lw    $s0, 0x30($sp)
/* 045284 80069E84 03E00008 */  jr    $ra
/* 045288 80069E88 27BD0038 */   addiu $sp, $sp, 0x38


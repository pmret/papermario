.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80069DB4
/* 451B4 80069DB4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 451B8 80069DB8 AFB00030 */  sw        $s0, 0x30($sp)
/* 451BC 80069DBC 00808021 */  addu      $s0, $a0, $zero
/* 451C0 80069DC0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 451C4 80069DC4 92020065 */  lbu       $v0, 0x65($s0)
/* 451C8 80069DC8 1040000C */  beqz      $v0, .L80069DFC
/* 451CC 80069DCC 00000000 */   nop
/* 451D0 80069DD0 0C01A5AC */  jal       func_800696B0
/* 451D4 80069DD4 00002821 */   addu     $a1, $zero, $zero
/* 451D8 80069DD8 00401821 */  addu      $v1, $v0, $zero
/* 451DC 80069DDC 24020002 */  addiu     $v0, $zero, 2
/* 451E0 80069DE0 14620004 */  bne       $v1, $v0, .L80069DF4
/* 451E4 80069DE4 02002021 */   addu     $a0, $s0, $zero
/* 451E8 80069DE8 0C01A5AC */  jal       func_800696B0
/* 451EC 80069DEC 00002821 */   addu     $a1, $zero, $zero
/* 451F0 80069DF0 00401821 */  addu      $v1, $v0, $zero
.L80069DF4:
/* 451F4 80069DF4 14600019 */  bnez      $v1, .L80069E5C
/* 451F8 80069DF8 00601021 */   addu     $v0, $v1, $zero
.L80069DFC:
/* 451FC 80069DFC 8E040004 */  lw        $a0, 4($s0)
/* 45200 80069E00 8E050008 */  lw        $a1, 8($s0)
/* 45204 80069E04 24060001 */  addiu     $a2, $zero, 1
/* 45208 80069E08 0C01A86C */  jal       func_8006A1B0
/* 4520C 80069E0C 27A70010 */   addiu    $a3, $sp, 0x10
/* 45210 80069E10 00401821 */  addu      $v1, $v0, $zero
/* 45214 80069E14 1060000B */  beqz      $v1, .L80069E44
/* 45218 80069E18 24020002 */   addiu    $v0, $zero, 2
/* 4521C 80069E1C 1462000F */  bne       $v1, $v0, .L80069E5C
/* 45220 80069E20 00601021 */   addu     $v0, $v1, $zero
/* 45224 80069E24 8E040004 */  lw        $a0, 4($s0)
/* 45228 80069E28 8E050008 */  lw        $a1, 8($s0)
/* 4522C 80069E2C 24060001 */  addiu     $a2, $zero, 1
/* 45230 80069E30 0C01A86C */  jal       func_8006A1B0
/* 45234 80069E34 27A70010 */   addiu    $a3, $sp, 0x10
/* 45238 80069E38 00401821 */  addu      $v1, $v0, $zero
/* 4523C 80069E3C 14600007 */  bnez      $v1, .L80069E5C
/* 45240 80069E40 00000000 */   nop
.L80069E44:
/* 45244 80069E44 2604000C */  addiu     $a0, $s0, 0xc
/* 45248 80069E48 27A50010 */  addiu     $a1, $sp, 0x10
/* 4524C 80069E4C 0C01AE14 */  jal       func_8006B850
/* 45250 80069E50 24060020 */   addiu    $a2, $zero, 0x20
/* 45254 80069E54 0002102B */  sltu      $v0, $zero, $v0
/* 45258 80069E58 00021040 */  sll       $v0, $v0, 1
.L80069E5C:
/* 4525C 80069E5C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 45260 80069E60 8FB00030 */  lw        $s0, 0x30($sp)
/* 45264 80069E64 03E00008 */  jr        $ra
/* 45268 80069E68 27BD0038 */   addiu    $sp, $sp, 0x38

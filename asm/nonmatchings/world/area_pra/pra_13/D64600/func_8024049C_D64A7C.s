.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024049C_D64A7C
/* D64A7C 8024049C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D64A80 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* D64A84 802404A4 0080802D */  daddu     $s0, $a0, $zero
/* D64A88 802404A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D64A8C 802404AC 8E020084 */  lw        $v0, 0x84($s0)
/* D64A90 802404B0 0440000E */  bltz      $v0, .L802404EC
/* D64A94 802404B4 28420002 */   slti     $v0, $v0, 2
/* D64A98 802404B8 1040000C */  beqz      $v0, .L802404EC
/* D64A9C 802404BC 00000000 */   nop
/* D64AA0 802404C0 3C058024 */  lui       $a1, %hi(func_80240500_D64AE0)
/* D64AA4 802404C4 24A50500 */  addiu     $a1, $a1, %lo(func_80240500_D64AE0)
/* D64AA8 802404C8 0C048C56 */  jal       bind_dynamic_entity_3
/* D64AAC 802404CC 0000202D */   daddu    $a0, $zero, $zero
/* D64AB0 802404D0 8E03013C */  lw        $v1, 0x13c($s0)
/* D64AB4 802404D4 AC620000 */  sw        $v0, ($v1)
/* D64AB8 802404D8 3C03800A */  lui       $v1, %hi(D_8009A650)
/* D64ABC 802404DC 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* D64AC0 802404E0 8C620000 */  lw        $v0, ($v1)
/* D64AC4 802404E4 34420080 */  ori       $v0, $v0, 0x80
/* D64AC8 802404E8 AC620000 */  sw        $v0, ($v1)
.L802404EC:
/* D64ACC 802404EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D64AD0 802404F0 8FB00010 */  lw        $s0, 0x10($sp)
/* D64AD4 802404F4 24020002 */  addiu     $v0, $zero, 2
/* D64AD8 802404F8 03E00008 */  jr        $ra
/* D64ADC 802404FC 27BD0018 */   addiu    $sp, $sp, 0x18

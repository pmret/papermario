.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024049C_D5048C
/* D5048C 8024049C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D50490 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* D50494 802404A4 0080802D */  daddu     $s0, $a0, $zero
/* D50498 802404A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D5049C 802404AC 8E020084 */  lw        $v0, 0x84($s0)
/* D504A0 802404B0 0440000E */  bltz      $v0, .L802404EC
/* D504A4 802404B4 28420002 */   slti     $v0, $v0, 2
/* D504A8 802404B8 1040000C */  beqz      $v0, .L802404EC
/* D504AC 802404BC 00000000 */   nop
/* D504B0 802404C0 3C058024 */  lui       $a1, %hi(func_80240500_D504F0)
/* D504B4 802404C4 24A50500 */  addiu     $a1, $a1, %lo(func_80240500_D504F0)
/* D504B8 802404C8 0C048C56 */  jal       create_dynamic_entity_world
/* D504BC 802404CC 0000202D */   daddu    $a0, $zero, $zero
/* D504C0 802404D0 8E03013C */  lw        $v1, 0x13c($s0)
/* D504C4 802404D4 AC620000 */  sw        $v0, ($v1)
/* D504C8 802404D8 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* D504CC 802404DC 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* D504D0 802404E0 8C620000 */  lw        $v0, ($v1)
/* D504D4 802404E4 34420080 */  ori       $v0, $v0, 0x80
/* D504D8 802404E8 AC620000 */  sw        $v0, ($v1)
.L802404EC:
/* D504DC 802404EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D504E0 802404F0 8FB00010 */  lw        $s0, 0x10($sp)
/* D504E4 802404F4 24020002 */  addiu     $v0, $zero, 2
/* D504E8 802404F8 03E00008 */  jr        $ra
/* D504EC 802404FC 27BD0018 */   addiu    $sp, $sp, 0x18

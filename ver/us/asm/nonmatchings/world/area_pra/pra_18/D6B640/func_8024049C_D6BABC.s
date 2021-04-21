.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_18_ReflectFloor
/* D6BABC 8024049C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6BAC0 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* D6BAC4 802404A4 0080802D */  daddu     $s0, $a0, $zero
/* D6BAC8 802404A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D6BACC 802404AC 8E020084 */  lw        $v0, 0x84($s0)
/* D6BAD0 802404B0 0440000E */  bltz      $v0, .L802404EC
/* D6BAD4 802404B4 28420002 */   slti     $v0, $v0, 2
/* D6BAD8 802404B8 1040000C */  beqz      $v0, .L802404EC
/* D6BADC 802404BC 00000000 */   nop
/* D6BAE0 802404C0 3C058024 */  lui       $a1, %hi(func_80240500_D6BB20)
/* D6BAE4 802404C4 24A50500 */  addiu     $a1, $a1, %lo(func_80240500_D6BB20)
/* D6BAE8 802404C8 0C048C56 */  jal       create_dynamic_entity_world
/* D6BAEC 802404CC 0000202D */   daddu    $a0, $zero, $zero
/* D6BAF0 802404D0 8E03013C */  lw        $v1, 0x13c($s0)
/* D6BAF4 802404D4 AC620000 */  sw        $v0, ($v1)
/* D6BAF8 802404D8 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* D6BAFC 802404DC 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* D6BB00 802404E0 8C620000 */  lw        $v0, ($v1)
/* D6BB04 802404E4 34420080 */  ori       $v0, $v0, 0x80
/* D6BB08 802404E8 AC620000 */  sw        $v0, ($v1)
.L802404EC:
/* D6BB0C 802404EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D6BB10 802404F0 8FB00010 */  lw        $s0, 0x10($sp)
/* D6BB14 802404F4 24020002 */  addiu     $v0, $zero, 2
/* D6BB18 802404F8 03E00008 */  jr        $ra
/* D6BB1C 802404FC 27BD0018 */   addiu    $sp, $sp, 0x18

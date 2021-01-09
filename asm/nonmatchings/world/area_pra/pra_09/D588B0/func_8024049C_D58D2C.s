.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024049C_D58D2C
/* D58D2C 8024049C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D58D30 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* D58D34 802404A4 0080802D */  daddu     $s0, $a0, $zero
/* D58D38 802404A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D58D3C 802404AC 8E020084 */  lw        $v0, 0x84($s0)
/* D58D40 802404B0 0440000E */  bltz      $v0, .L802404EC
/* D58D44 802404B4 28420002 */   slti     $v0, $v0, 2
/* D58D48 802404B8 1040000C */  beqz      $v0, .L802404EC
/* D58D4C 802404BC 00000000 */   nop      
/* D58D50 802404C0 3C058024 */  lui       $a1, %hi(func_80240500_D58914)
/* D58D54 802404C4 24A50500 */  addiu     $a1, $a1, %lo(func_80240500_D58914)
/* D58D58 802404C8 0C048C56 */  jal       bind_dynamic_entity_3
/* D58D5C 802404CC 0000202D */   daddu    $a0, $zero, $zero
/* D58D60 802404D0 8E03013C */  lw        $v1, 0x13c($s0)
/* D58D64 802404D4 AC620000 */  sw        $v0, ($v1)
/* D58D68 802404D8 3C03800A */  lui       $v1, %hi(D_8009A650)
/* D58D6C 802404DC 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* D58D70 802404E0 8C620000 */  lw        $v0, ($v1)
/* D58D74 802404E4 34420080 */  ori       $v0, $v0, 0x80
/* D58D78 802404E8 AC620000 */  sw        $v0, ($v1)
.L802404EC:
/* D58D7C 802404EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D58D80 802404F0 8FB00010 */  lw        $s0, 0x10($sp)
/* D58D84 802404F4 24020002 */  addiu     $v0, $zero, 2
/* D58D88 802404F8 03E00008 */  jr        $ra
/* D58D8C 802404FC 27BD0018 */   addiu    $sp, $sp, 0x18

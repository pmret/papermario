.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024049C_D5F74C
/* D5F74C 8024049C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D5F750 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* D5F754 802404A4 0080802D */  daddu     $s0, $a0, $zero
/* D5F758 802404A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D5F75C 802404AC 8E020084 */  lw        $v0, 0x84($s0)
/* D5F760 802404B0 0440000E */  bltz      $v0, .L802404EC
/* D5F764 802404B4 28420002 */   slti     $v0, $v0, 2
/* D5F768 802404B8 1040000C */  beqz      $v0, .L802404EC
/* D5F76C 802404BC 00000000 */   nop
/* D5F770 802404C0 3C058024 */  lui       $a1, %hi(func_80240500_D5F7B0)
/* D5F774 802404C4 24A50500 */  addiu     $a1, $a1, %lo(func_80240500_D5F7B0)
/* D5F778 802404C8 0C048C56 */  jal       bind_dynamic_entity_3
/* D5F77C 802404CC 0000202D */   daddu    $a0, $zero, $zero
/* D5F780 802404D0 8E03013C */  lw        $v1, 0x13c($s0)
/* D5F784 802404D4 AC620000 */  sw        $v0, ($v1)
/* D5F788 802404D8 3C03800A */  lui       $v1, %hi(D_8009A650)
/* D5F78C 802404DC 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* D5F790 802404E0 8C620000 */  lw        $v0, ($v1)
/* D5F794 802404E4 34420080 */  ori       $v0, $v0, 0x80
/* D5F798 802404E8 AC620000 */  sw        $v0, ($v1)
.L802404EC:
/* D5F79C 802404EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D5F7A0 802404F0 8FB00010 */  lw        $s0, 0x10($sp)
/* D5F7A4 802404F4 24020002 */  addiu     $v0, $zero, 2
/* D5F7A8 802404F8 03E00008 */  jr        $ra
/* D5F7AC 802404FC 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024049C_D6819C
/* D6819C 8024049C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D681A0 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* D681A4 802404A4 0080802D */  daddu     $s0, $a0, $zero
/* D681A8 802404A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D681AC 802404AC 8E020084 */  lw        $v0, 0x84($s0)
/* D681B0 802404B0 0440000E */  bltz      $v0, .L802404EC
/* D681B4 802404B4 28420002 */   slti     $v0, $v0, 2
/* D681B8 802404B8 1040000C */  beqz      $v0, .L802404EC
/* D681BC 802404BC 00000000 */   nop      
/* D681C0 802404C0 3C058024 */  lui       $a1, %hi(D_80240500)
/* D681C4 802404C4 24A50500 */  addiu     $a1, $a1, %lo(D_80240500)
/* D681C8 802404C8 0C048C56 */  jal       bind_dynamic_entity_3
/* D681CC 802404CC 0000202D */   daddu    $a0, $zero, $zero
/* D681D0 802404D0 8E03013C */  lw        $v1, 0x13c($s0)
/* D681D4 802404D4 AC620000 */  sw        $v0, ($v1)
/* D681D8 802404D8 3C03800A */  lui       $v1, %hi(D_8009A650)
/* D681DC 802404DC 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* D681E0 802404E0 8C620000 */  lw        $v0, ($v1)
/* D681E4 802404E4 34420080 */  ori       $v0, $v0, 0x80
/* D681E8 802404E8 AC620000 */  sw        $v0, ($v1)
.L802404EC:
/* D681EC 802404EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D681F0 802404F0 8FB00010 */  lw        $s0, 0x10($sp)
/* D681F4 802404F4 24020002 */  addiu     $v0, $zero, 2
/* D681F8 802404F8 03E00008 */  jr        $ra
/* D681FC 802404FC 27BD0018 */   addiu    $sp, $sp, 0x18

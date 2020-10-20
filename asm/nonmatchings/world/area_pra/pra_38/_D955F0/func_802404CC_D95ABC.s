.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404CC_D95ABC
/* D95ABC 802404CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D95AC0 802404D0 AFB00010 */  sw        $s0, 0x10($sp)
/* D95AC4 802404D4 0080802D */  daddu     $s0, $a0, $zero
/* D95AC8 802404D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D95ACC 802404DC 8E020084 */  lw        $v0, 0x84($s0)
/* D95AD0 802404E0 0440000E */  bltz      $v0, .L8024051C
/* D95AD4 802404E4 28420002 */   slti     $v0, $v0, 2
/* D95AD8 802404E8 1040000C */  beqz      $v0, .L8024051C
/* D95ADC 802404EC 00000000 */   nop      
/* D95AE0 802404F0 3C058024 */  lui       $a1, 0x8024
/* D95AE4 802404F4 24A50530 */  addiu     $a1, $a1, 0x530
/* D95AE8 802404F8 0C048C56 */  jal       bind_dynamic_entity_3
/* D95AEC 802404FC 0000202D */   daddu    $a0, $zero, $zero
/* D95AF0 80240500 8E03013C */  lw        $v1, 0x13c($s0)
/* D95AF4 80240504 AC620000 */  sw        $v0, ($v1)
/* D95AF8 80240508 3C03800A */  lui       $v1, %hi(D_8009A650)
/* D95AFC 8024050C 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* D95B00 80240510 8C620000 */  lw        $v0, ($v1)
/* D95B04 80240514 34420080 */  ori       $v0, $v0, 0x80
/* D95B08 80240518 AC620000 */  sw        $v0, ($v1)
.L8024051C:
/* D95B0C 8024051C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D95B10 80240520 8FB00010 */  lw        $s0, 0x10($sp)
/* D95B14 80240524 24020002 */  addiu     $v0, $zero, 2
/* D95B18 80240528 03E00008 */  jr        $ra
/* D95B1C 8024052C 27BD0018 */   addiu    $sp, $sp, 0x18

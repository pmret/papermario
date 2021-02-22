.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404CC_D97D5C
/* D97D5C 802404CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D97D60 802404D0 AFB00010 */  sw        $s0, 0x10($sp)
/* D97D64 802404D4 0080802D */  daddu     $s0, $a0, $zero
/* D97D68 802404D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D97D6C 802404DC 8E020084 */  lw        $v0, 0x84($s0)
/* D97D70 802404E0 0440000E */  bltz      $v0, .L8024051C
/* D97D74 802404E4 28420002 */   slti     $v0, $v0, 2
/* D97D78 802404E8 1040000C */  beqz      $v0, .L8024051C
/* D97D7C 802404EC 00000000 */   nop
/* D97D80 802404F0 3C058024 */  lui       $a1, %hi(func_80240530_D97DC0)
/* D97D84 802404F4 24A50530 */  addiu     $a1, $a1, %lo(func_80240530_D97DC0)
/* D97D88 802404F8 0C048C56 */  jal       bind_dynamic_entity_3
/* D97D8C 802404FC 0000202D */   daddu    $a0, $zero, $zero
/* D97D90 80240500 8E03013C */  lw        $v1, 0x13c($s0)
/* D97D94 80240504 AC620000 */  sw        $v0, ($v1)
/* D97D98 80240508 3C03800A */  lui       $v1, %hi(D_8009A650)
/* D97D9C 8024050C 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* D97DA0 80240510 8C620000 */  lw        $v0, ($v1)
/* D97DA4 80240514 34420080 */  ori       $v0, $v0, 0x80
/* D97DA8 80240518 AC620000 */  sw        $v0, ($v1)
.L8024051C:
/* D97DAC 8024051C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D97DB0 80240520 8FB00010 */  lw        $s0, 0x10($sp)
/* D97DB4 80240524 24020002 */  addiu     $v0, $zero, 2
/* D97DB8 80240528 03E00008 */  jr        $ra
/* D97DBC 8024052C 27BD0018 */   addiu    $sp, $sp, 0x18

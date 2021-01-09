.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404CC_D631DC
/* D631DC 802404CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D631E0 802404D0 AFB00010 */  sw        $s0, 0x10($sp)
/* D631E4 802404D4 0080802D */  daddu     $s0, $a0, $zero
/* D631E8 802404D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* D631EC 802404DC 8E020084 */  lw        $v0, 0x84($s0)
/* D631F0 802404E0 0440000E */  bltz      $v0, .L8024051C
/* D631F4 802404E4 28420002 */   slti     $v0, $v0, 2
/* D631F8 802404E8 1040000C */  beqz      $v0, .L8024051C
/* D631FC 802404EC 00000000 */   nop      
/* D63200 802404F0 3C058024 */  lui       $a1, %hi(func_80240530_D62D74)
/* D63204 802404F4 24A50530 */  addiu     $a1, $a1, %lo(func_80240530_D62D74)
/* D63208 802404F8 0C048C56 */  jal       bind_dynamic_entity_3
/* D6320C 802404FC 0000202D */   daddu    $a0, $zero, $zero
/* D63210 80240500 8E03013C */  lw        $v1, 0x13c($s0)
/* D63214 80240504 AC620000 */  sw        $v0, ($v1)
/* D63218 80240508 3C03800A */  lui       $v1, %hi(D_8009A650)
/* D6321C 8024050C 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* D63220 80240510 8C620000 */  lw        $v0, ($v1)
/* D63224 80240514 34420080 */  ori       $v0, $v0, 0x80
/* D63228 80240518 AC620000 */  sw        $v0, ($v1)
.L8024051C:
/* D6322C 8024051C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D63230 80240520 8FB00010 */  lw        $s0, 0x10($sp)
/* D63234 80240524 24020002 */  addiu     $v0, $zero, 2
/* D63238 80240528 03E00008 */  jr        $ra
/* D6323C 8024052C 27BD0018 */   addiu    $sp, $sp, 0x18

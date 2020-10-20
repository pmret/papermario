.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024025C_D78ADC
/* D78ADC 8024025C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D78AE0 80240260 AFB10014 */  sw        $s1, 0x14($sp)
/* D78AE4 80240264 0080882D */  daddu     $s1, $a0, $zero
/* D78AE8 80240268 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D78AEC 8024026C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D78AF0 80240270 AFBF0018 */  sw        $ra, 0x18($sp)
/* D78AF4 80240274 AFB00010 */  sw        $s0, 0x10($sp)
/* D78AF8 80240278 84430018 */  lh        $v1, 0x18($v0)
/* D78AFC 8024027C 14600005 */  bnez      $v1, .L80240294
/* D78B00 80240280 0040802D */   daddu    $s0, $v0, $zero
/* D78B04 80240284 3C05FD05 */  lui       $a1, 0xfd05
/* D78B08 80240288 34A50F80 */  ori       $a1, $a1, 0xf80
/* D78B0C 8024028C 0C0B2026 */  jal       set_variable
/* D78B10 80240290 0000302D */   daddu    $a2, $zero, $zero
.L80240294:
/* D78B14 80240294 86030018 */  lh        $v1, 0x18($s0)
/* D78B18 80240298 2402FF38 */  addiu     $v0, $zero, -0xc8
/* D78B1C 8024029C 14620005 */  bne       $v1, $v0, .L802402B4
/* D78B20 802402A0 0220202D */   daddu    $a0, $s1, $zero
/* D78B24 802402A4 3C05FD05 */  lui       $a1, 0xfd05
/* D78B28 802402A8 34A50F80 */  ori       $a1, $a1, 0xf80
/* D78B2C 802402AC 0C0B2026 */  jal       set_variable
/* D78B30 802402B0 24060001 */   addiu    $a2, $zero, 1
.L802402B4:
/* D78B34 802402B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D78B38 802402B8 8FB10014 */  lw        $s1, 0x14($sp)
/* D78B3C 802402BC 8FB00010 */  lw        $s0, 0x10($sp)
/* D78B40 802402C0 0000102D */  daddu     $v0, $zero, $zero
/* D78B44 802402C4 03E00008 */  jr        $ra
/* D78B48 802402C8 27BD0020 */   addiu    $sp, $sp, 0x20
/* D78B4C 802402CC 00000000 */  nop       

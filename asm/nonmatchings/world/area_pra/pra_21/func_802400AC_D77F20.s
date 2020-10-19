.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400AC_D77FCC
/* D77FCC 802400AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D77FD0 802400B0 AFB10014 */  sw        $s1, 0x14($sp)
/* D77FD4 802400B4 0080882D */  daddu     $s1, $a0, $zero
/* D77FD8 802400B8 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D77FDC 802400BC 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D77FE0 802400C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* D77FE4 802400C4 AFB00010 */  sw        $s0, 0x10($sp)
/* D77FE8 802400C8 84430018 */  lh        $v1, 0x18($v0)
/* D77FEC 802400CC 14600005 */  bnez      $v1, .L802400E4
/* D77FF0 802400D0 0040802D */   daddu    $s0, $v0, $zero
/* D77FF4 802400D4 3C05FD05 */  lui       $a1, 0xfd05
/* D77FF8 802400D8 34A50F80 */  ori       $a1, $a1, 0xf80
/* D77FFC 802400DC 0C0B2026 */  jal       set_variable
/* D78000 802400E0 0000302D */   daddu    $a2, $zero, $zero
.L802400E4:
/* D78004 802400E4 86030018 */  lh        $v1, 0x18($s0)
/* D78008 802400E8 2402FF38 */  addiu     $v0, $zero, -0xc8
/* D7800C 802400EC 14620005 */  bne       $v1, $v0, .L80240104
/* D78010 802400F0 0220202D */   daddu    $a0, $s1, $zero
/* D78014 802400F4 3C05FD05 */  lui       $a1, 0xfd05
/* D78018 802400F8 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7801C 802400FC 0C0B2026 */  jal       set_variable
/* D78020 80240100 24060001 */   addiu    $a2, $zero, 1
.L80240104:
/* D78024 80240104 8FBF0018 */  lw        $ra, 0x18($sp)
/* D78028 80240108 8FB10014 */  lw        $s1, 0x14($sp)
/* D7802C 8024010C 8FB00010 */  lw        $s0, 0x10($sp)
/* D78030 80240110 0000102D */  daddu     $v0, $zero, $zero
/* D78034 80240114 03E00008 */  jr        $ra
/* D78038 80240118 27BD0020 */   addiu    $sp, $sp, 0x20
/* D7803C 8024011C 00000000 */  nop       

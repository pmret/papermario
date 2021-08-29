.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AB8_63DC98
/* 63DC98 80218AB8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 63DC9C 80218ABC AFB10014 */  sw        $s1, 0x14($sp)
/* 63DCA0 80218AC0 0080882D */  daddu     $s1, $a0, $zero
/* 63DCA4 80218AC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 63DCA8 80218AC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 63DCAC 80218ACC 8E30000C */  lw        $s0, 0xc($s1)
/* 63DCB0 80218AD0 8E050000 */  lw        $a1, ($s0)
/* 63DCB4 80218AD4 0C0B1EAF */  jal       get_variable
/* 63DCB8 80218AD8 26100004 */   addiu    $s0, $s0, 4
/* 63DCBC 80218ADC 0040202D */  daddu     $a0, $v0, $zero
/* 63DCC0 80218AE0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 63DCC4 80218AE4 14820002 */  bne       $a0, $v0, .L80218AF0
/* 63DCC8 80218AE8 00000000 */   nop
/* 63DCCC 80218AEC 8E240148 */  lw        $a0, 0x148($s1)
.L80218AF0:
/* 63DCD0 80218AF0 0C09A75B */  jal       get_actor
/* 63DCD4 80218AF4 00000000 */   nop
/* 63DCD8 80218AF8 0040202D */  daddu     $a0, $v0, $zero
/* 63DCDC 80218AFC 90830136 */  lbu       $v1, 0x136($a0)
/* 63DCE0 80218B00 24020047 */  addiu     $v0, $zero, 0x47
/* 63DCE4 80218B04 1062000B */  beq       $v1, $v0, .L80218B34
/* 63DCE8 80218B08 0062102A */   slt      $v0, $v1, $v0
/* 63DCEC 80218B0C 54400011 */  bnel      $v0, $zero, .L80218B54
/* 63DCF0 80218B10 0220202D */   daddu    $a0, $s1, $zero
/* 63DCF4 80218B14 28620065 */  slti      $v0, $v1, 0x65
/* 63DCF8 80218B18 1040000D */  beqz      $v0, .L80218B50
/* 63DCFC 80218B1C 2862004D */   slti     $v0, $v1, 0x4d
/* 63DD00 80218B20 1440000C */  bnez      $v0, .L80218B54
/* 63DD04 80218B24 0220202D */   daddu    $a0, $s1, $zero
/* 63DD08 80218B28 8E050000 */  lw        $a1, ($s0)
/* 63DD0C 80218B2C 080862D7 */  j         .L80218B5C
/* 63DD10 80218B30 2406FFFF */   addiu    $a2, $zero, -1
.L80218B34:
/* 63DD14 80218B34 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 63DD18 80218B38 24020001 */  addiu     $v0, $zero, 1
/* 63DD1C 80218B3C 14620005 */  bne       $v1, $v0, .L80218B54
/* 63DD20 80218B40 0220202D */   daddu    $a0, $s1, $zero
/* 63DD24 80218B44 8E050000 */  lw        $a1, ($s0)
/* 63DD28 80218B48 080862D7 */  j         .L80218B5C
/* 63DD2C 80218B4C 2406FFFF */   addiu    $a2, $zero, -1
.L80218B50:
/* 63DD30 80218B50 0220202D */  daddu     $a0, $s1, $zero
.L80218B54:
/* 63DD34 80218B54 8E050000 */  lw        $a1, ($s0)
/* 63DD38 80218B58 0000302D */  daddu     $a2, $zero, $zero
.L80218B5C:
/* 63DD3C 80218B5C 0C0B2026 */  jal       evt_set_variable
/* 63DD40 80218B60 00000000 */   nop
/* 63DD44 80218B64 8FBF0018 */  lw        $ra, 0x18($sp)
/* 63DD48 80218B68 8FB10014 */  lw        $s1, 0x14($sp)
/* 63DD4C 80218B6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 63DD50 80218B70 24020002 */  addiu     $v0, $zero, 2
/* 63DD54 80218B74 03E00008 */  jr        $ra
/* 63DD58 80218B78 27BD0020 */   addiu    $sp, $sp, 0x20
/* 63DD5C 80218B7C 00000000 */  nop

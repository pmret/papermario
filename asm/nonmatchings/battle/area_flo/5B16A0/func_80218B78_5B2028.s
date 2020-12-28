.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B78_5B2028
/* 5B2028 80218B78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B202C 80218B7C AFB10014 */  sw        $s1, 0x14($sp)
/* 5B2030 80218B80 0080882D */  daddu     $s1, $a0, $zero
/* 5B2034 80218B84 AFBF0018 */  sw        $ra, 0x18($sp)
/* 5B2038 80218B88 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B203C 80218B8C 8E30000C */  lw        $s0, 0xc($s1)
/* 5B2040 80218B90 8E050000 */  lw        $a1, ($s0)
/* 5B2044 80218B94 0C0B1EAF */  jal       get_variable
/* 5B2048 80218B98 26100004 */   addiu    $s0, $s0, 4
/* 5B204C 80218B9C 0040202D */  daddu     $a0, $v0, $zero
/* 5B2050 80218BA0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 5B2054 80218BA4 14820002 */  bne       $a0, $v0, .L80218BB0
/* 5B2058 80218BA8 00000000 */   nop      
/* 5B205C 80218BAC 8E240148 */  lw        $a0, 0x148($s1)
.L80218BB0:
/* 5B2060 80218BB0 0C09A75B */  jal       get_actor
/* 5B2064 80218BB4 00000000 */   nop      
/* 5B2068 80218BB8 0040202D */  daddu     $a0, $v0, $zero
/* 5B206C 80218BBC 90830136 */  lbu       $v1, 0x136($a0)
/* 5B2070 80218BC0 24020047 */  addiu     $v0, $zero, 0x47
/* 5B2074 80218BC4 1062000B */  beq       $v1, $v0, .L80218BF4
/* 5B2078 80218BC8 0062102A */   slt      $v0, $v1, $v0
/* 5B207C 80218BCC 54400011 */  bnel      $v0, $zero, .L80218C14
/* 5B2080 80218BD0 0220202D */   daddu    $a0, $s1, $zero
/* 5B2084 80218BD4 28620065 */  slti      $v0, $v1, 0x65
/* 5B2088 80218BD8 1040000D */  beqz      $v0, .L80218C10
/* 5B208C 80218BDC 2862004D */   slti     $v0, $v1, 0x4d
/* 5B2090 80218BE0 1440000C */  bnez      $v0, .L80218C14
/* 5B2094 80218BE4 0220202D */   daddu    $a0, $s1, $zero
/* 5B2098 80218BE8 8E050000 */  lw        $a1, ($s0)
/* 5B209C 80218BEC 08086307 */  j         .L80218C1C
/* 5B20A0 80218BF0 2406FFFF */   addiu    $a2, $zero, -1
.L80218BF4:
/* 5B20A4 80218BF4 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 5B20A8 80218BF8 24020001 */  addiu     $v0, $zero, 1
/* 5B20AC 80218BFC 14620005 */  bne       $v1, $v0, .L80218C14
/* 5B20B0 80218C00 0220202D */   daddu    $a0, $s1, $zero
/* 5B20B4 80218C04 8E050000 */  lw        $a1, ($s0)
/* 5B20B8 80218C08 08086307 */  j         .L80218C1C
/* 5B20BC 80218C0C 2406FFFF */   addiu    $a2, $zero, -1
.L80218C10:
/* 5B20C0 80218C10 0220202D */  daddu     $a0, $s1, $zero
.L80218C14:
/* 5B20C4 80218C14 8E050000 */  lw        $a1, ($s0)
/* 5B20C8 80218C18 0000302D */  daddu     $a2, $zero, $zero
.L80218C1C:
/* 5B20CC 80218C1C 0C0B2026 */  jal       set_variable
/* 5B20D0 80218C20 00000000 */   nop      
/* 5B20D4 80218C24 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5B20D8 80218C28 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B20DC 80218C2C 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B20E0 80218C30 24020002 */  addiu     $v0, $zero, 2
/* 5B20E4 80218C34 03E00008 */  jr        $ra
/* 5B20E8 80218C38 27BD0020 */   addiu    $sp, $sp, 0x20
/* 5B20EC 80218C3C 00000000 */  nop       

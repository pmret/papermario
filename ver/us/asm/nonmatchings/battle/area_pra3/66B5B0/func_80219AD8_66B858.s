.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219AD8_66B858
/* 66B858 80219AD8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66B85C 80219ADC AFB10014 */  sw        $s1, 0x14($sp)
/* 66B860 80219AE0 0080882D */  daddu     $s1, $a0, $zero
/* 66B864 80219AE4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 66B868 80219AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* 66B86C 80219AEC 8E30000C */  lw        $s0, 0xc($s1)
/* 66B870 80219AF0 8E050000 */  lw        $a1, ($s0)
/* 66B874 80219AF4 0C0B1EAF */  jal       get_variable
/* 66B878 80219AF8 26100004 */   addiu    $s0, $s0, 4
/* 66B87C 80219AFC 0040202D */  daddu     $a0, $v0, $zero
/* 66B880 80219B00 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 66B884 80219B04 14820002 */  bne       $a0, $v0, .L80219B10
/* 66B888 80219B08 00000000 */   nop
/* 66B88C 80219B0C 8E240148 */  lw        $a0, 0x148($s1)
.L80219B10:
/* 66B890 80219B10 0C09A75B */  jal       get_actor
/* 66B894 80219B14 00000000 */   nop
/* 66B898 80219B18 0040202D */  daddu     $a0, $v0, $zero
/* 66B89C 80219B1C 90830136 */  lbu       $v1, 0x136($a0)
/* 66B8A0 80219B20 24020047 */  addiu     $v0, $zero, 0x47
/* 66B8A4 80219B24 1062000B */  beq       $v1, $v0, .L80219B54
/* 66B8A8 80219B28 0062102A */   slt      $v0, $v1, $v0
/* 66B8AC 80219B2C 54400011 */  bnel      $v0, $zero, .L80219B74
/* 66B8B0 80219B30 0220202D */   daddu    $a0, $s1, $zero
/* 66B8B4 80219B34 28620065 */  slti      $v0, $v1, 0x65
/* 66B8B8 80219B38 1040000D */  beqz      $v0, .L80219B70
/* 66B8BC 80219B3C 2862004D */   slti     $v0, $v1, 0x4d
/* 66B8C0 80219B40 1440000C */  bnez      $v0, .L80219B74
/* 66B8C4 80219B44 0220202D */   daddu    $a0, $s1, $zero
/* 66B8C8 80219B48 8E050000 */  lw        $a1, ($s0)
/* 66B8CC 80219B4C 080866DF */  j         .L80219B7C
/* 66B8D0 80219B50 2406FFFF */   addiu    $a2, $zero, -1
.L80219B54:
/* 66B8D4 80219B54 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 66B8D8 80219B58 24020001 */  addiu     $v0, $zero, 1
/* 66B8DC 80219B5C 14620005 */  bne       $v1, $v0, .L80219B74
/* 66B8E0 80219B60 0220202D */   daddu    $a0, $s1, $zero
/* 66B8E4 80219B64 8E050000 */  lw        $a1, ($s0)
/* 66B8E8 80219B68 080866DF */  j         .L80219B7C
/* 66B8EC 80219B6C 2406FFFF */   addiu    $a2, $zero, -1
.L80219B70:
/* 66B8F0 80219B70 0220202D */  daddu     $a0, $s1, $zero
.L80219B74:
/* 66B8F4 80219B74 8E050000 */  lw        $a1, ($s0)
/* 66B8F8 80219B78 0000302D */  daddu     $a2, $zero, $zero
.L80219B7C:
/* 66B8FC 80219B7C 0C0B2026 */  jal       evt_set_variable
/* 66B900 80219B80 00000000 */   nop
/* 66B904 80219B84 8FBF0018 */  lw        $ra, 0x18($sp)
/* 66B908 80219B88 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B90C 80219B8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B910 80219B90 24020002 */  addiu     $v0, $zero, 2
/* 66B914 80219B94 03E00008 */  jr        $ra
/* 66B918 80219B98 27BD0020 */   addiu    $sp, $sp, 0x20
/* 66B91C 80219B9C 00000000 */  nop

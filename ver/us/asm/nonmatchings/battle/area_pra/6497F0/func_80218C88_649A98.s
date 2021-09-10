.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C88_649A98
/* 649A98 80218C88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 649A9C 80218C8C AFB10014 */  sw        $s1, 0x14($sp)
/* 649AA0 80218C90 0080882D */  daddu     $s1, $a0, $zero
/* 649AA4 80218C94 AFBF0018 */  sw        $ra, 0x18($sp)
/* 649AA8 80218C98 AFB00010 */  sw        $s0, 0x10($sp)
/* 649AAC 80218C9C 8E30000C */  lw        $s0, 0xc($s1)
/* 649AB0 80218CA0 8E050000 */  lw        $a1, ($s0)
/* 649AB4 80218CA4 0C0B1EAF */  jal       evt_get_variable
/* 649AB8 80218CA8 26100004 */   addiu    $s0, $s0, 4
/* 649ABC 80218CAC 0040202D */  daddu     $a0, $v0, $zero
/* 649AC0 80218CB0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 649AC4 80218CB4 14820002 */  bne       $a0, $v0, .L80218CC0
/* 649AC8 80218CB8 00000000 */   nop
/* 649ACC 80218CBC 8E240148 */  lw        $a0, 0x148($s1)
.L80218CC0:
/* 649AD0 80218CC0 0C09A75B */  jal       get_actor
/* 649AD4 80218CC4 00000000 */   nop
/* 649AD8 80218CC8 0040202D */  daddu     $a0, $v0, $zero
/* 649ADC 80218CCC 90830136 */  lbu       $v1, 0x136($a0)
/* 649AE0 80218CD0 24020047 */  addiu     $v0, $zero, 0x47
/* 649AE4 80218CD4 1062000B */  beq       $v1, $v0, .L80218D04
/* 649AE8 80218CD8 0062102A */   slt      $v0, $v1, $v0
/* 649AEC 80218CDC 54400011 */  bnel      $v0, $zero, .L80218D24
/* 649AF0 80218CE0 0220202D */   daddu    $a0, $s1, $zero
/* 649AF4 80218CE4 28620065 */  slti      $v0, $v1, 0x65
/* 649AF8 80218CE8 1040000D */  beqz      $v0, .L80218D20
/* 649AFC 80218CEC 2862004D */   slti     $v0, $v1, 0x4d
/* 649B00 80218CF0 1440000C */  bnez      $v0, .L80218D24
/* 649B04 80218CF4 0220202D */   daddu    $a0, $s1, $zero
/* 649B08 80218CF8 8E050000 */  lw        $a1, ($s0)
/* 649B0C 80218CFC 0808634B */  j         .L80218D2C
/* 649B10 80218D00 2406FFFF */   addiu    $a2, $zero, -1
.L80218D04:
/* 649B14 80218D04 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 649B18 80218D08 24020001 */  addiu     $v0, $zero, 1
/* 649B1C 80218D0C 14620005 */  bne       $v1, $v0, .L80218D24
/* 649B20 80218D10 0220202D */   daddu    $a0, $s1, $zero
/* 649B24 80218D14 8E050000 */  lw        $a1, ($s0)
/* 649B28 80218D18 0808634B */  j         .L80218D2C
/* 649B2C 80218D1C 2406FFFF */   addiu    $a2, $zero, -1
.L80218D20:
/* 649B30 80218D20 0220202D */  daddu     $a0, $s1, $zero
.L80218D24:
/* 649B34 80218D24 8E050000 */  lw        $a1, ($s0)
/* 649B38 80218D28 0000302D */  daddu     $a2, $zero, $zero
.L80218D2C:
/* 649B3C 80218D2C 0C0B2026 */  jal       evt_set_variable
/* 649B40 80218D30 00000000 */   nop
/* 649B44 80218D34 8FBF0018 */  lw        $ra, 0x18($sp)
/* 649B48 80218D38 8FB10014 */  lw        $s1, 0x14($sp)
/* 649B4C 80218D3C 8FB00010 */  lw        $s0, 0x10($sp)
/* 649B50 80218D40 24020002 */  addiu     $v0, $zero, 2
/* 649B54 80218D44 03E00008 */  jr        $ra
/* 649B58 80218D48 27BD0020 */   addiu    $sp, $sp, 0x20
/* 649B5C 80218D4C 00000000 */  nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800449B0
/* 1FDB0 800449B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1FDB4 800449B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 1FDB8 800449B8 0080882D */  daddu     $s1, $a0, $zero
/* 1FDBC 800449BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 1FDC0 800449C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1FDC4 800449C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1FDC8 800449C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1FDCC 800449CC 8E30000C */  lw        $s0, 0xc($s1)
/* 1FDD0 800449D0 8E330148 */  lw        $s3, 0x148($s1)
/* 1FDD4 800449D4 8E050000 */  lw        $a1, ($s0)
/* 1FDD8 800449D8 0C0B1EAF */  jal       func_802C7ABC
/* 1FDDC 800449DC 26100004 */   addiu    $s0, $s0, 4
/* 1FDE0 800449E0 0040902D */  daddu     $s2, $v0, $zero
/* 1FDE4 800449E4 8E050000 */  lw        $a1, ($s0)
/* 1FDE8 800449E8 0C0B1EAF */  jal       func_802C7ABC
/* 1FDEC 800449EC 0220202D */   daddu    $a0, $s1, $zero
/* 1FDF0 800449F0 0040802D */  daddu     $s0, $v0, $zero
/* 1FDF4 800449F4 2402FFFF */  addiu     $v0, $zero, -1
/* 1FDF8 800449F8 16420002 */  bne       $s2, $v0, .L80044A04
/* 1FDFC 800449FC 00000000 */   nop
/* 1FE00 80044A00 86720008 */  lh        $s2, 8($s3)
.L80044A04:
/* 1FE04 80044A04 0C00FA6A */  jal       func_8003E9A8
/* 1FE08 80044A08 0240202D */   daddu    $a0, $s2, $zero
/* 1FE0C 80044A0C 12000008 */  beqz      $s0, .L80044A30
/* 1FE10 80044A10 0040982D */   daddu    $s3, $v0, $zero
/* 1FE14 80044A14 8E62003C */  lw        $v0, 0x3c($s3)
/* 1FE18 80044A18 1040000A */  beqz      $v0, .L80044A44
/* 1FE1C 80044A1C 00000000 */   nop
/* 1FE20 80044A20 0C0B1123 */  jal       func_802C448C
/* 1FE24 80044A24 8E640054 */   lw       $a0, 0x54($s3)
/* 1FE28 80044A28 08011291 */  j         .L80044A44
/* 1FE2C 80044A2C 00000000 */   nop
.L80044A30:
/* 1FE30 80044A30 8E62003C */  lw        $v0, 0x3c($s3)
/* 1FE34 80044A34 10400003 */  beqz      $v0, .L80044A44
/* 1FE38 80044A38 00000000 */   nop
/* 1FE3C 80044A3C 0C0B1108 */  jal       func_802C4420
/* 1FE40 80044A40 8E640054 */   lw       $a0, 0x54($s3)
.L80044A44:
/* 1FE44 80044A44 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1FE48 80044A48 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1FE4C 80044A4C 8FB20018 */  lw        $s2, 0x18($sp)
/* 1FE50 80044A50 8FB10014 */  lw        $s1, 0x14($sp)
/* 1FE54 80044A54 8FB00010 */  lw        $s0, 0x10($sp)
/* 1FE58 80044A58 24020002 */  addiu     $v0, $zero, 2
/* 1FE5C 80044A5C 03E00008 */  jr        $ra
/* 1FE60 80044A60 27BD0028 */   addiu    $sp, $sp, 0x28

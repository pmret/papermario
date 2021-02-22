.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EDD0
/* 3A1D0 8005EDD0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3A1D4 8005EDD4 3C05800E */  lui       $a1, %hi(D_800DAA9D)
/* 3A1D8 8005EDD8 24A5AA9D */  addiu     $a1, $a1, %lo(D_800DAA9D)
/* 3A1DC 8005EDDC 24030001 */  addiu     $v1, $zero, 1
/* 3A1E0 8005EDE0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3A1E4 8005EDE4 AFB40030 */  sw        $s4, 0x30($sp)
/* 3A1E8 8005EDE8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 3A1EC 8005EDEC AFB20028 */  sw        $s2, 0x28($sp)
/* 3A1F0 8005EDF0 AFB10024 */  sw        $s1, 0x24($sp)
/* 3A1F4 8005EDF4 AFB00020 */  sw        $s0, 0x20($sp)
/* 3A1F8 8005EDF8 90A20000 */  lbu       $v0, ($a1)
/* 3A1FC 8005EDFC 8C92000C */  lw        $s2, 0xc($a0)
/* 3A200 8005EE00 10430035 */  beq       $v0, $v1, .L8005EED8
/* 3A204 8005EE04 27B10010 */   addiu    $s1, $sp, 0x10
/* 3A208 8005EE08 24B4FA9F */  addiu     $s4, $a1, -0x561
/* 3A20C 8005EE0C 0060982D */  daddu     $s3, $v1, $zero
.L8005EE10:
/* 3A210 8005EE10 0C019A60 */  jal       func_80066980
/* 3A214 8005EE14 00000000 */   nop
/* 3A218 8005EE18 10520005 */  beq       $v0, $s2, .L8005EE30
/* 3A21C 8005EE1C 00000000 */   nop
/* 3A220 8005EE20 0C019A70 */  jal       func_800669C0
/* 3A224 8005EE24 00000000 */   nop
/* 3A228 8005EE28 1452002B */  bne       $v0, $s2, .L8005EED8
/* 3A22C 8005EE2C 00000000 */   nop
.L8005EE30:
/* 3A230 8005EE30 0C018244 */  jal       func_80060910
/* 3A234 8005EE34 24040001 */   addiu    $a0, $zero, 1
/* 3A238 8005EE38 AE340004 */  sw        $s4, 4($s1)
/* 3A23C 8005EE3C 3C03800E */  lui       $v1, %hi(D_800DAA88)
/* 3A240 8005EE40 8C63AA88 */  lw        $v1, %lo(D_800DAA88)($v1)
/* 3A244 8005EE44 AFA30010 */  sw        $v1, 0x10($sp)
/* 3A248 8005EE48 A6330008 */  sh        $s3, 8($s1)
/* 3A24C 8005EE4C 3C01800E */  lui       $at, %hi(D_800DAA88)
/* 3A250 8005EE50 AC31AA88 */  sw        $s1, %lo(D_800DAA88)($at)
/* 3A254 8005EE54 0C018244 */  jal       func_80060910
/* 3A258 8005EE58 0040202D */   daddu    $a0, $v0, $zero
/* 3A25C 8005EE5C 3C04800E */  lui       $a0, %hi(D_800DA53C)
/* 3A260 8005EE60 2484A53C */  addiu     $a0, $a0, %lo(D_800DA53C)
/* 3A264 8005EE64 0000282D */  daddu     $a1, $zero, $zero
/* 3A268 8005EE68 0C0195B0 */  jal       func_800656C0
/* 3A26C 8005EE6C 24060001 */   addiu    $a2, $zero, 1
/* 3A270 8005EE70 0C018244 */  jal       func_80060910
/* 3A274 8005EE74 24040001 */   addiu    $a0, $zero, 1
/* 3A278 8005EE78 0000282D */  daddu     $a1, $zero, $zero
/* 3A27C 8005EE7C 27B00010 */  addiu     $s0, $sp, 0x10
/* 3A280 8005EE80 3C03800E */  lui       $v1, %hi(D_800DAA88)
/* 3A284 8005EE84 8C63AA88 */  lw        $v1, %lo(D_800DAA88)($v1)
/* 3A288 8005EE88 1060000C */  beqz      $v1, .L8005EEBC
/* 3A28C 8005EE8C 0040202D */   daddu    $a0, $v0, $zero
.L8005EE90:
/* 3A290 8005EE90 54700007 */  bnel      $v1, $s0, .L8005EEB0
/* 3A294 8005EE94 0060282D */   daddu    $a1, $v1, $zero
/* 3A298 8005EE98 14A0000C */  bnez      $a1, .L8005EECC
/* 3A29C 8005EE9C 00000000 */   nop
/* 3A2A0 8005EEA0 8C620000 */  lw        $v0, ($v1)
/* 3A2A4 8005EEA4 3C01800E */  lui       $at, %hi(D_800DAA88)
/* 3A2A8 8005EEA8 08017BAF */  j         .L8005EEBC
/* 3A2AC 8005EEAC AC22AA88 */   sw       $v0, %lo(D_800DAA88)($at)
.L8005EEB0:
/* 3A2B0 8005EEB0 8CA30000 */  lw        $v1, ($a1)
/* 3A2B4 8005EEB4 1460FFF6 */  bnez      $v1, .L8005EE90
/* 3A2B8 8005EEB8 00000000 */   nop
.L8005EEBC:
/* 3A2BC 8005EEBC 0C018244 */  jal       func_80060910
/* 3A2C0 8005EEC0 00000000 */   nop
/* 3A2C4 8005EEC4 08017B84 */  j         .L8005EE10
/* 3A2C8 8005EEC8 00000000 */   nop
.L8005EECC:
/* 3A2CC 8005EECC 8C620000 */  lw        $v0, ($v1)
/* 3A2D0 8005EED0 08017BAF */  j         .L8005EEBC
/* 3A2D4 8005EED4 ACA20000 */   sw       $v0, ($a1)
.L8005EED8:
/* 3A2D8 8005EED8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3A2DC 8005EEDC 8FB40030 */  lw        $s4, 0x30($sp)
/* 3A2E0 8005EEE0 8FB3002C */  lw        $s3, 0x2c($sp)
/* 3A2E4 8005EEE4 8FB20028 */  lw        $s2, 0x28($sp)
/* 3A2E8 8005EEE8 8FB10024 */  lw        $s1, 0x24($sp)
/* 3A2EC 8005EEEC 8FB00020 */  lw        $s0, 0x20($sp)
/* 3A2F0 8005EEF0 03E00008 */  jr        $ra
/* 3A2F4 8005EEF4 27BD0038 */   addiu    $sp, $sp, 0x38
/* 3A2F8 8005EEF8 00000000 */  nop
/* 3A2FC 8005EEFC 00000000 */  nop

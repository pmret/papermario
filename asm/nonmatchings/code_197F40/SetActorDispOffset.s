.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetActorDispOffset
/* 19A2E4 8026BA04 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 19A2E8 8026BA08 AFB20018 */  sw        $s2, 0x18($sp)
/* 19A2EC 8026BA0C 0080902D */  daddu     $s2, $a0, $zero
/* 19A2F0 8026BA10 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19A2F4 8026BA14 AFB10014 */  sw        $s1, 0x14($sp)
/* 19A2F8 8026BA18 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A2FC 8026BA1C F7B80030 */  sdc1      $f24, 0x30($sp)
/* 19A300 8026BA20 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 19A304 8026BA24 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 19A308 8026BA28 8E50000C */  lw        $s0, 0xc($s2)
/* 19A30C 8026BA2C 8E050000 */  lw        $a1, ($s0)
/* 19A310 8026BA30 0C0B1EAF */  jal       get_variable
/* 19A314 8026BA34 26100004 */   addiu    $s0, $s0, 4
/* 19A318 8026BA38 0040882D */  daddu     $s1, $v0, $zero
/* 19A31C 8026BA3C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19A320 8026BA40 16220002 */  bne       $s1, $v0, .L8026BA4C
/* 19A324 8026BA44 00000000 */   nop      
/* 19A328 8026BA48 8E510148 */  lw        $s1, 0x148($s2)
.L8026BA4C:
/* 19A32C 8026BA4C 8E050000 */  lw        $a1, ($s0)
/* 19A330 8026BA50 26100004 */  addiu     $s0, $s0, 4
/* 19A334 8026BA54 0C0B210B */  jal       get_float_variable
/* 19A338 8026BA58 0240202D */   daddu    $a0, $s2, $zero
/* 19A33C 8026BA5C 8E050000 */  lw        $a1, ($s0)
/* 19A340 8026BA60 26100004 */  addiu     $s0, $s0, 4
/* 19A344 8026BA64 0240202D */  daddu     $a0, $s2, $zero
/* 19A348 8026BA68 0C0B210B */  jal       get_float_variable
/* 19A34C 8026BA6C 46000606 */   mov.s    $f24, $f0
/* 19A350 8026BA70 0240202D */  daddu     $a0, $s2, $zero
/* 19A354 8026BA74 8E050000 */  lw        $a1, ($s0)
/* 19A358 8026BA78 0C0B210B */  jal       get_float_variable
/* 19A35C 8026BA7C 46000586 */   mov.s    $f22, $f0
/* 19A360 8026BA80 0220202D */  daddu     $a0, $s1, $zero
/* 19A364 8026BA84 0C09A75B */  jal       get_actor
/* 19A368 8026BA88 46000506 */   mov.s    $f20, $f0
/* 19A36C 8026BA8C 0040202D */  daddu     $a0, $v0, $zero
/* 19A370 8026BA90 4600C08D */  trunc.w.s $f2, $f24
/* 19A374 8026BA94 44031000 */  mfc1      $v1, $f2
/* 19A378 8026BA98 00000000 */  nop       
/* 19A37C 8026BA9C A4830150 */  sh        $v1, 0x150($a0)
/* 19A380 8026BAA0 4600B08D */  trunc.w.s $f2, $f22
/* 19A384 8026BAA4 44031000 */  mfc1      $v1, $f2
/* 19A388 8026BAA8 00000000 */  nop       
/* 19A38C 8026BAAC A4830152 */  sh        $v1, 0x152($a0)
/* 19A390 8026BAB0 4600A08D */  trunc.w.s $f2, $f20
/* 19A394 8026BAB4 44031000 */  mfc1      $v1, $f2
/* 19A398 8026BAB8 00000000 */  nop       
/* 19A39C 8026BABC A4830154 */  sh        $v1, 0x154($a0)
/* 19A3A0 8026BAC0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19A3A4 8026BAC4 8FB20018 */  lw        $s2, 0x18($sp)
/* 19A3A8 8026BAC8 8FB10014 */  lw        $s1, 0x14($sp)
/* 19A3AC 8026BACC 8FB00010 */  lw        $s0, 0x10($sp)
/* 19A3B0 8026BAD0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 19A3B4 8026BAD4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 19A3B8 8026BAD8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 19A3BC 8026BADC 24020002 */  addiu     $v0, $zero, 2
/* 19A3C0 8026BAE0 03E00008 */  jr        $ra
/* 19A3C4 8026BAE4 27BD0038 */   addiu    $sp, $sp, 0x38

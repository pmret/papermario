.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10A4_77F2E4
/* 77F2E4 802A10A4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 77F2E8 802A10A8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 77F2EC 802A10AC 3C014170 */  lui       $at, 0x4170
/* 77F2F0 802A10B0 4481B000 */  mtc1      $at, $f22
/* 77F2F4 802A10B4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 77F2F8 802A10B8 3C0140A0 */  lui       $at, 0x40a0
/* 77F2FC 802A10BC 4481D000 */  mtc1      $at, $f26
/* 77F300 802A10C0 3C02800E */  lui       $v0, %hi(gBattleStatus+0xD8)
/* 77F304 802A10C4 8C42C148 */  lw        $v0, %lo(gBattleStatus+0xD8)($v0)
/* 77F308 802A10C8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 77F30C 802A10CC 3C013F80 */  lui       $at, 0x3f80
/* 77F310 802A10D0 4481C000 */  mtc1      $at, $f24
/* 77F314 802A10D4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 77F318 802A10D8 0000882D */  daddu     $s1, $zero, $zero
/* 77F31C 802A10DC AFB20020 */  sw        $s2, 0x20($sp)
/* 77F320 802A10E0 24120019 */  addiu     $s2, $zero, 0x19
/* 77F324 802A10E4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 77F328 802A10E8 AFB00018 */  sw        $s0, 0x18($sp)
/* 77F32C 802A10EC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 77F330 802A10F0 2450000C */  addiu     $s0, $v0, 0xc
.L802A10F4:
/* 77F334 802A10F4 0C00A67F */  jal       rand_int
/* 77F338 802A10F8 2404001E */   addiu    $a0, $zero, 0x1e
/* 77F33C 802A10FC C614000C */  lwc1      $f20, 0xc($s0)
/* 77F340 802A1100 44820000 */  mtc1      $v0, $f0
/* 77F344 802A1104 00000000 */  nop
/* 77F348 802A1108 46800020 */  cvt.s.w   $f0, $f0
/* 77F34C 802A110C 4600A500 */  add.s     $f20, $f20, $f0
/* 77F350 802A1110 24040014 */  addiu     $a0, $zero, 0x14
/* 77F354 802A1114 0C00A67F */  jal       rand_int
/* 77F358 802A1118 4616A501 */   sub.s    $f20, $f20, $f22
/* 77F35C 802A111C C6020010 */  lwc1      $f2, 0x10($s0)
/* 77F360 802A1120 44820000 */  mtc1      $v0, $f0
/* 77F364 802A1124 00000000 */  nop
/* 77F368 802A1128 46800020 */  cvt.s.w   $f0, $f0
/* 77F36C 802A112C 46001080 */  add.s     $f2, $f2, $f0
/* 77F370 802A1130 C6000014 */  lwc1      $f0, 0x14($s0)
/* 77F374 802A1134 461A0000 */  add.s     $f0, $f0, $f26
/* 77F378 802A1138 26310001 */  addiu     $s1, $s1, 1
/* 77F37C 802A113C 46161081 */  sub.s     $f2, $f2, $f22
/* 77F380 802A1140 4405A000 */  mfc1      $a1, $f20
/* 77F384 802A1144 44070000 */  mfc1      $a3, $f0
/* 77F388 802A1148 44061000 */  mfc1      $a2, $f2
/* 77F38C 802A114C 0000202D */  daddu     $a0, $zero, $zero
/* 77F390 802A1150 E7B80010 */  swc1      $f24, 0x10($sp)
/* 77F394 802A1154 0C01C7FC */  jal       func_80071FF0
/* 77F398 802A1158 AFB20014 */   sw       $s2, 0x14($sp)
/* 77F39C 802A115C 2A220014 */  slti      $v0, $s1, 0x14
/* 77F3A0 802A1160 1440FFE4 */  bnez      $v0, .L802A10F4
/* 77F3A4 802A1164 24020002 */   addiu    $v0, $zero, 2
/* 77F3A8 802A1168 8FBF0024 */  lw        $ra, 0x24($sp)
/* 77F3AC 802A116C 8FB20020 */  lw        $s2, 0x20($sp)
/* 77F3B0 802A1170 8FB1001C */  lw        $s1, 0x1c($sp)
/* 77F3B4 802A1174 8FB00018 */  lw        $s0, 0x18($sp)
/* 77F3B8 802A1178 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 77F3BC 802A117C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 77F3C0 802A1180 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 77F3C4 802A1184 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 77F3C8 802A1188 03E00008 */  jr        $ra
/* 77F3CC 802A118C 27BD0048 */   addiu    $sp, $sp, 0x48

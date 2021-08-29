.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ShowSleepBubble
/* FC9D8 802D8028 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* FC9DC 802D802C AFB1002C */  sw        $s1, 0x2c($sp)
/* FC9E0 802D8030 0080882D */  daddu     $s1, $a0, $zero
/* FC9E4 802D8034 AFBF003C */  sw        $ra, 0x3c($sp)
/* FC9E8 802D8038 AFB40038 */  sw        $s4, 0x38($sp)
/* FC9EC 802D803C AFB30034 */  sw        $s3, 0x34($sp)
/* FC9F0 802D8040 AFB20030 */  sw        $s2, 0x30($sp)
/* FC9F4 802D8044 AFB00028 */  sw        $s0, 0x28($sp)
/* FC9F8 802D8048 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* FC9FC 802D804C F7B80050 */  sdc1      $f24, 0x50($sp)
/* FCA00 802D8050 F7B60048 */  sdc1      $f22, 0x48($sp)
/* FCA04 802D8054 F7B40040 */  sdc1      $f20, 0x40($sp)
/* FCA08 802D8058 8E30000C */  lw        $s0, 0xc($s1)
/* FCA0C 802D805C 8E050000 */  lw        $a1, ($s0)
/* FCA10 802D8060 0C0B1EAF */  jal       get_variable
/* FCA14 802D8064 26100004 */   addiu    $s0, $s0, 4
/* FCA18 802D8068 8E050000 */  lw        $a1, ($s0)
/* FCA1C 802D806C 26100004 */  addiu     $s0, $s0, 4
/* FCA20 802D8070 0220202D */  daddu     $a0, $s1, $zero
/* FCA24 802D8074 0C0B1EAF */  jal       get_variable
/* FCA28 802D8078 0040982D */   daddu    $s3, $v0, $zero
/* FCA2C 802D807C 8E050000 */  lw        $a1, ($s0)
/* FCA30 802D8080 26100004 */  addiu     $s0, $s0, 4
/* FCA34 802D8084 0220202D */  daddu     $a0, $s1, $zero
/* FCA38 802D8088 0C0B210B */  jal       evt_get_float_variable
/* FCA3C 802D808C 0040A02D */   daddu    $s4, $v0, $zero
/* FCA40 802D8090 8E050000 */  lw        $a1, ($s0)
/* FCA44 802D8094 26100004 */  addiu     $s0, $s0, 4
/* FCA48 802D8098 0220202D */  daddu     $a0, $s1, $zero
/* FCA4C 802D809C 0C0B1EAF */  jal       get_variable
/* FCA50 802D80A0 46000686 */   mov.s    $f26, $f0
/* FCA54 802D80A4 8E050000 */  lw        $a1, ($s0)
/* FCA58 802D80A8 26100004 */  addiu     $s0, $s0, 4
/* FCA5C 802D80AC 0220202D */  daddu     $a0, $s1, $zero
/* FCA60 802D80B0 0C0B210B */  jal       evt_get_float_variable
/* FCA64 802D80B4 0040902D */   daddu    $s2, $v0, $zero
/* FCA68 802D80B8 8E050000 */  lw        $a1, ($s0)
/* FCA6C 802D80BC 26100004 */  addiu     $s0, $s0, 4
/* FCA70 802D80C0 0220202D */  daddu     $a0, $s1, $zero
/* FCA74 802D80C4 0C0B210B */  jal       evt_get_float_variable
/* FCA78 802D80C8 46000606 */   mov.s    $f24, $f0
/* FCA7C 802D80CC 8E050000 */  lw        $a1, ($s0)
/* FCA80 802D80D0 26100004 */  addiu     $s0, $s0, 4
/* FCA84 802D80D4 0220202D */  daddu     $a0, $s1, $zero
/* FCA88 802D80D8 0C0B210B */  jal       evt_get_float_variable
/* FCA8C 802D80DC 46000586 */   mov.s    $f22, $f0
/* FCA90 802D80E0 8E050000 */  lw        $a1, ($s0)
/* FCA94 802D80E4 26100004 */  addiu     $s0, $s0, 4
/* FCA98 802D80E8 0220202D */  daddu     $a0, $s1, $zero
/* FCA9C 802D80EC 0C0B210B */  jal       evt_get_float_variable
/* FCAA0 802D80F0 46000506 */   mov.s    $f20, $f0
/* FCAA4 802D80F4 8E100000 */  lw        $s0, ($s0)
/* FCAA8 802D80F8 12400006 */  beqz      $s2, .L802D8114
/* FCAAC 802D80FC 46000086 */   mov.s    $f2, $f0
/* FCAB0 802D8100 24020001 */  addiu     $v0, $zero, 1
/* FCAB4 802D8104 12420014 */  beq       $s2, $v0, .L802D8158
/* FCAB8 802D8108 4600C186 */   mov.s    $f6, $f24
/* FCABC 802D810C 080B6076 */  j         .L802D81D8
/* FCAC0 802D8110 4600B006 */   mov.s    $f0, $f22
.L802D8114:
/* FCAC4 802D8114 3C055555 */  lui       $a1, 0x5555
/* FCAC8 802D8118 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* FCACC 802D811C 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* FCAD0 802D8120 948200B0 */  lhu       $v0, 0xb0($a0)
/* FCAD4 802D8124 34A55556 */  ori       $a1, $a1, 0x5556
/* FCAD8 802D8128 00021400 */  sll       $v0, $v0, 0x10
/* FCADC 802D812C 00021C03 */  sra       $v1, $v0, 0x10
/* FCAE0 802D8130 00650018 */  mult      $v1, $a1
/* FCAE4 802D8134 C4860028 */  lwc1      $f6, 0x28($a0)
/* FCAE8 802D8138 C4880030 */  lwc1      $f8, 0x30($a0)
/* FCAEC 802D813C C482002C */  lwc1      $f2, 0x2c($a0)
/* FCAF0 802D8140 00031840 */  sll       $v1, $v1, 1
/* FCAF4 802D8144 00004010 */  mfhi      $t0
/* FCAF8 802D8148 000217C3 */  sra       $v0, $v0, 0x1f
/* FCAFC 802D814C 01021023 */  subu      $v0, $t0, $v0
/* FCB00 802D8150 080B6069 */  j         .L802D81A4
/* FCB04 802D8154 00650018 */   mult     $v1, $a1
.L802D8158:
/* FCB08 802D8158 0220202D */  daddu     $a0, $s1, $zero
/* FCB0C 802D815C 0C0B36B0 */  jal       resolve_npc
/* FCB10 802D8160 0260282D */   daddu    $a1, $s3, $zero
/* FCB14 802D8164 0040282D */  daddu     $a1, $v0, $zero
/* FCB18 802D8168 10A0002A */  beqz      $a1, .L802D8214
/* FCB1C 802D816C 3C045555 */   lui      $a0, 0x5555
/* FCB20 802D8170 94A200A8 */  lhu       $v0, 0xa8($a1)
/* FCB24 802D8174 34845556 */  ori       $a0, $a0, 0x5556
/* FCB28 802D8178 00021400 */  sll       $v0, $v0, 0x10
/* FCB2C 802D817C 00021C03 */  sra       $v1, $v0, 0x10
/* FCB30 802D8180 00640018 */  mult      $v1, $a0
/* FCB34 802D8184 C4A60038 */  lwc1      $f6, 0x38($a1)
/* FCB38 802D8188 C4A80040 */  lwc1      $f8, 0x40($a1)
/* FCB3C 802D818C C4A2003C */  lwc1      $f2, 0x3c($a1)
/* FCB40 802D8190 00031840 */  sll       $v1, $v1, 1
/* FCB44 802D8194 00004010 */  mfhi      $t0
/* FCB48 802D8198 000217C3 */  sra       $v0, $v0, 0x1f
/* FCB4C 802D819C 01021023 */  subu      $v0, $t0, $v0
/* FCB50 802D81A0 00640018 */  mult      $v1, $a0
.L802D81A4:
/* FCB54 802D81A4 00021400 */  sll       $v0, $v0, 0x10
/* FCB58 802D81A8 00021403 */  sra       $v0, $v0, 0x10
/* FCB5C 802D81AC 44822000 */  mtc1      $v0, $f4
/* FCB60 802D81B0 00000000 */  nop
/* FCB64 802D81B4 46802120 */  cvt.s.w   $f4, $f4
/* FCB68 802D81B8 00031FC3 */  sra       $v1, $v1, 0x1f
/* FCB6C 802D81BC 00004010 */  mfhi      $t0
/* FCB70 802D81C0 01031823 */  subu      $v1, $t0, $v1
/* FCB74 802D81C4 44830000 */  mtc1      $v1, $f0
/* FCB78 802D81C8 00000000 */  nop
/* FCB7C 802D81CC 46800020 */  cvt.s.w   $f0, $f0
/* FCB80 802D81D0 080B6078 */  j         .L802D81E0
/* FCB84 802D81D4 46001000 */   add.s    $f0, $f2, $f0
.L802D81D8:
/* FCB88 802D81D8 4600A206 */  mov.s     $f8, $f20
/* FCB8C 802D81DC 46001106 */  mov.s     $f4, $f2
.L802D81E0:
/* FCB90 802D81E0 0280202D */  daddu     $a0, $s4, $zero
/* FCB94 802D81E4 44053000 */  mfc1      $a1, $f6
/* FCB98 802D81E8 44060000 */  mfc1      $a2, $f0
/* FCB9C 802D81EC 44074000 */  mfc1      $a3, $f8
/* FCBA0 802D81F0 27A20020 */  addiu     $v0, $sp, 0x20
/* FCBA4 802D81F4 E7A40010 */  swc1      $f4, 0x10($sp)
/* FCBA8 802D81F8 E7BA0014 */  swc1      $f26, 0x14($sp)
/* FCBAC 802D81FC 0C01C1FC */  jal       fx_sleep_bubble
/* FCBB0 802D8200 AFA20018 */   sw       $v0, 0x18($sp)
/* FCBB4 802D8204 0220202D */  daddu     $a0, $s1, $zero
/* FCBB8 802D8208 8FA60020 */  lw        $a2, 0x20($sp)
/* FCBBC 802D820C 0C0B2026 */  jal       evt_set_variable
/* FCBC0 802D8210 0200282D */   daddu    $a1, $s0, $zero
.L802D8214:
/* FCBC4 802D8214 24020002 */  addiu     $v0, $zero, 2
/* FCBC8 802D8218 8FBF003C */  lw        $ra, 0x3c($sp)
/* FCBCC 802D821C 8FB40038 */  lw        $s4, 0x38($sp)
/* FCBD0 802D8220 8FB30034 */  lw        $s3, 0x34($sp)
/* FCBD4 802D8224 8FB20030 */  lw        $s2, 0x30($sp)
/* FCBD8 802D8228 8FB1002C */  lw        $s1, 0x2c($sp)
/* FCBDC 802D822C 8FB00028 */  lw        $s0, 0x28($sp)
/* FCBE0 802D8230 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* FCBE4 802D8234 D7B80050 */  ldc1      $f24, 0x50($sp)
/* FCBE8 802D8238 D7B60048 */  ldc1      $f22, 0x48($sp)
/* FCBEC 802D823C D7B40040 */  ldc1      $f20, 0x40($sp)
/* FCBF0 802D8240 03E00008 */  jr        $ra
/* FCBF4 802D8244 27BD0060 */   addiu    $sp, $sp, 0x60

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218F58_6BCAE8
/* 6BCAE8 80218F58 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 6BCAEC 80218F5C AFBF002C */  sw        $ra, 0x2c($sp)
/* 6BCAF0 80218F60 AFB20028 */  sw        $s2, 0x28($sp)
/* 6BCAF4 80218F64 AFB10024 */  sw        $s1, 0x24($sp)
/* 6BCAF8 80218F68 AFB00020 */  sw        $s0, 0x20($sp)
/* 6BCAFC 80218F6C F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6BCB00 80218F70 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6BCB04 80218F74 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6BCB08 80218F78 8C840148 */  lw        $a0, 0x148($a0)
/* 6BCB0C 80218F7C 0C09A75B */  jal       get_actor
/* 6BCB10 80218F80 00A0802D */   daddu    $s0, $a1, $zero
/* 6BCB14 80218F84 0040882D */  daddu     $s1, $v0, $zero
/* 6BCB18 80218F88 1200003D */  beqz      $s0, .L80219080
/* 6BCB1C 80218F8C 2632000C */   addiu    $s2, $s1, 0xc
/* 6BCB20 80218F90 0C00AB39 */  jal       heap_malloc
/* 6BCB24 80218F94 24040020 */   addiu    $a0, $zero, 0x20
/* 6BCB28 80218F98 0040802D */  daddu     $s0, $v0, $zero
/* 6BCB2C 80218F9C 24020001 */  addiu     $v0, $zero, 1
/* 6BCB30 80218FA0 26250144 */  addiu     $a1, $s1, 0x144
/* 6BCB34 80218FA4 26260148 */  addiu     $a2, $s1, 0x148
/* 6BCB38 80218FA8 AE300090 */  sw        $s0, 0x90($s1)
/* 6BCB3C 80218FAC AE020004 */  sw        $v0, 4($s0)
/* 6BCB40 80218FB0 AE000008 */  sw        $zero, 8($s0)
/* 6BCB44 80218FB4 AE02000C */  sw        $v0, 0xc($s0)
/* 6BCB48 80218FB8 AE000010 */  sw        $zero, 0x10($s0)
/* 6BCB4C 80218FBC 82230210 */  lb        $v1, 0x210($s1)
/* 6BCB50 80218FC0 2402000A */  addiu     $v0, $zero, 0xa
/* 6BCB54 80218FC4 10620005 */  beq       $v1, $v0, .L80218FDC
/* 6BCB58 80218FC8 2627014C */   addiu    $a3, $s1, 0x14c
/* 6BCB5C 80218FCC 3C013F80 */  lui       $at, 0x3f80
/* 6BCB60 80218FD0 44810000 */  mtc1      $at, $f0
/* 6BCB64 80218FD4 080863FC */  j         .L80218FF0
/* 6BCB68 80218FD8 E7A00010 */   swc1     $f0, 0x10($sp)
.L80218FDC:
/* 6BCB6C 80218FDC 3C013ECC */  lui       $at, 0x3ecc
/* 6BCB70 80218FE0 3421CCCD */  ori       $at, $at, 0xcccd
/* 6BCB74 80218FE4 44810000 */  mtc1      $at, $f0
/* 6BCB78 80218FE8 00000000 */  nop
/* 6BCB7C 80218FEC E7A00010 */  swc1      $f0, 0x10($sp)
.L80218FF0:
/* 6BCB80 80218FF0 24020005 */  addiu     $v0, $zero, 5
/* 6BCB84 80218FF4 AFA20014 */  sw        $v0, 0x14($sp)
/* 6BCB88 80218FF8 AFA00018 */  sw        $zero, 0x18($sp)
/* 6BCB8C 80218FFC 8CA50000 */  lw        $a1, ($a1)
/* 6BCB90 80219000 8CC60000 */  lw        $a2, ($a2)
/* 6BCB94 80219004 8CE70000 */  lw        $a3, ($a3)
/* 6BCB98 80219008 0C01C8EC */  jal       playFX_73
/* 6BCB9C 8021900C 0000202D */   daddu    $a0, $zero, $zero
/* 6BCBA0 80219010 26250144 */  addiu     $a1, $s1, 0x144
/* 6BCBA4 80219014 AE020014 */  sw        $v0, 0x14($s0)
/* 6BCBA8 80219018 82220210 */  lb        $v0, 0x210($s1)
/* 6BCBAC 8021901C 2403000A */  addiu     $v1, $zero, 0xa
/* 6BCBB0 80219020 10430005 */  beq       $v0, $v1, .L80219038
/* 6BCBB4 80219024 2627014C */   addiu    $a3, $s1, 0x14c
/* 6BCBB8 80219028 3C013F80 */  lui       $at, 0x3f80
/* 6BCBBC 8021902C 44810000 */  mtc1      $at, $f0
/* 6BCBC0 80219030 08086413 */  j         .L8021904C
/* 6BCBC4 80219034 E7A00010 */   swc1     $f0, 0x10($sp)
.L80219038:
/* 6BCBC8 80219038 3C013ECC */  lui       $at, 0x3ecc
/* 6BCBCC 8021903C 3421CCCD */  ori       $at, $at, 0xcccd
/* 6BCBD0 80219040 44810000 */  mtc1      $at, $f0
/* 6BCBD4 80219044 00000000 */  nop
/* 6BCBD8 80219048 E7A00010 */  swc1      $f0, 0x10($sp)
.L8021904C:
/* 6BCBDC 8021904C 24020005 */  addiu     $v0, $zero, 5
/* 6BCBE0 80219050 AFA20014 */  sw        $v0, 0x14($sp)
/* 6BCBE4 80219054 AFA00018 */  sw        $zero, 0x18($sp)
/* 6BCBE8 80219058 8CA50000 */  lw        $a1, ($a1)
/* 6BCBEC 8021905C 3C06C47A */  lui       $a2, 0xc47a
/* 6BCBF0 80219060 8CE70000 */  lw        $a3, ($a3)
/* 6BCBF4 80219064 0C01C8EC */  jal       playFX_73
/* 6BCBF8 80219068 24040001 */   addiu    $a0, $zero, 1
/* 6BCBFC 8021906C AE020018 */  sw        $v0, 0x18($s0)
/* 6BCC00 80219070 24020001 */  addiu     $v0, $zero, 1
/* 6BCC04 80219074 AE020000 */  sw        $v0, ($s0)
/* 6BCC08 80219078 82220210 */  lb        $v0, 0x210($s1)
/* 6BCC0C 8021907C AE02001C */  sw        $v0, 0x1c($s0)
.L80219080:
/* 6BCC10 80219080 8E500084 */  lw        $s0, 0x84($s2)
/* 6BCC14 80219084 8E020000 */  lw        $v0, ($s0)
/* 6BCC18 80219088 104000C9 */  beqz      $v0, .L802193B0
/* 6BCC1C 8021908C 24020002 */   addiu    $v0, $zero, 2
/* 6BCC20 80219090 8E020004 */  lw        $v0, 4($s0)
/* 6BCC24 80219094 1040000D */  beqz      $v0, .L802190CC
/* 6BCC28 80219098 24020008 */   addiu    $v0, $zero, 8
/* 6BCC2C 8021909C 82230210 */  lb        $v1, 0x210($s1)
/* 6BCC30 802190A0 1062000A */  beq       $v1, $v0, .L802190CC
/* 6BCC34 802190A4 00000000 */   nop
/* 6BCC38 802190A8 8E020008 */  lw        $v0, 8($s0)
/* 6BCC3C 802190AC 2442000F */  addiu     $v0, $v0, 0xf
/* 6BCC40 802190B0 44826000 */  mtc1      $v0, $f12
/* 6BCC44 802190B4 00000000 */  nop
/* 6BCC48 802190B8 46806320 */  cvt.s.w   $f12, $f12
/* 6BCC4C 802190BC 0C00A6C9 */  jal       clamp_angle
/* 6BCC50 802190C0 AE020008 */   sw       $v0, 8($s0)
/* 6BCC54 802190C4 4600018D */  trunc.w.s $f6, $f0
/* 6BCC58 802190C8 E6060008 */  swc1      $f6, 8($s0)
.L802190CC:
/* 6BCC5C 802190CC 3C0140C9 */  lui       $at, 0x40c9
/* 6BCC60 802190D0 34210FD0 */  ori       $at, $at, 0xfd0
/* 6BCC64 802190D4 44810000 */  mtc1      $at, $f0
/* 6BCC68 802190D8 C60C0008 */  lwc1      $f12, 8($s0)
/* 6BCC6C 802190DC 46806320 */  cvt.s.w   $f12, $f12
/* 6BCC70 802190E0 46006302 */  mul.s     $f12, $f12, $f0
/* 6BCC74 802190E4 00000000 */  nop
/* 6BCC78 802190E8 3C0143B4 */  lui       $at, 0x43b4
/* 6BCC7C 802190EC 44810000 */  mtc1      $at, $f0
/* 6BCC80 802190F0 0C00A85B */  jal       sin_rad
/* 6BCC84 802190F4 46006303 */   div.s    $f12, $f12, $f0
/* 6BCC88 802190F8 3C014040 */  lui       $at, 0x4040
/* 6BCC8C 802190FC 44811000 */  mtc1      $at, $f2
/* 6BCC90 80219100 00000000 */  nop
/* 6BCC94 80219104 46020002 */  mul.s     $f0, $f0, $f2
/* 6BCC98 80219108 00000000 */  nop
/* 6BCC9C 8021910C 86220152 */  lh        $v0, 0x152($s1)
/* 6BCCA0 80219110 44821000 */  mtc1      $v0, $f2
/* 6BCCA4 80219114 00000000 */  nop
/* 6BCCA8 80219118 468010A0 */  cvt.s.w   $f2, $f2
/* 6BCCAC 8021911C 4600018D */  trunc.w.s $f6, $f0
/* 6BCCB0 80219120 44033000 */  mfc1      $v1, $f6
/* 6BCCB4 80219124 00000000 */  nop
/* 6BCCB8 80219128 00031600 */  sll       $v0, $v1, 0x18
/* 6BCCBC 8021912C C6200148 */  lwc1      $f0, 0x148($s1)
/* 6BCCC0 80219130 00021603 */  sra       $v0, $v0, 0x18
/* 6BCCC4 80219134 A223019A */  sb        $v1, 0x19a($s1)
/* 6BCCC8 80219138 46020000 */  add.s     $f0, $f0, $f2
/* 6BCCCC 8021913C 44821000 */  mtc1      $v0, $f2
/* 6BCCD0 80219140 00000000 */  nop
/* 6BCCD4 80219144 468010A0 */  cvt.s.w   $f2, $f2
/* 6BCCD8 80219148 86220150 */  lh        $v0, 0x150($s1)
/* 6BCCDC 8021914C 46020000 */  add.s     $f0, $f0, $f2
/* 6BCCE0 80219150 2403000A */  addiu     $v1, $zero, 0xa
/* 6BCCE4 80219154 44821000 */  mtc1      $v0, $f2
/* 6BCCE8 80219158 00000000 */  nop
/* 6BCCEC 8021915C 468010A0 */  cvt.s.w   $f2, $f2
/* 6BCCF0 80219160 46000121 */  cvt.d.s   $f4, $f0
/* 6BCCF4 80219164 C6200144 */  lwc1      $f0, 0x144($s1)
/* 6BCCF8 80219168 82220210 */  lb        $v0, 0x210($s1)
/* 6BCCFC 8021916C 46020580 */  add.s     $f22, $f0, $f2
/* 6BCD00 80219170 3C018023 */  lui       $at, %hi(D_80228448_6CBFD8)
/* 6BCD04 80219174 D4208448 */  ldc1      $f0, %lo(D_80228448_6CBFD8)($at)
/* 6BCD08 80219178 50430006 */  beql      $v0, $v1, .L80219194
/* 6BCD0C 8021917C 46202000 */   add.d    $f0, $f4, $f0
/* 6BCD10 80219180 3C014028 */  lui       $at, 0x4028
/* 6BCD14 80219184 44810800 */  mtc1      $at, $f1
/* 6BCD18 80219188 44800000 */  mtc1      $zero, $f0
/* 6BCD1C 8021918C 00000000 */  nop
/* 6BCD20 80219190 46202000 */  add.d     $f0, $f4, $f0
.L80219194:
/* 6BCD24 80219194 46200520 */  cvt.s.d   $f20, $f0
/* 6BCD28 80219198 86220154 */  lh        $v0, 0x154($s1)
/* 6BCD2C 8021919C C620014C */  lwc1      $f0, 0x14c($s1)
/* 6BCD30 802191A0 44821000 */  mtc1      $v0, $f2
/* 6BCD34 802191A4 00000000 */  nop
/* 6BCD38 802191A8 468010A0 */  cvt.s.w   $f2, $f2
/* 6BCD3C 802191AC 8E02000C */  lw        $v0, 0xc($s0)
/* 6BCD40 802191B0 10400059 */  beqz      $v0, .L80219318
/* 6BCD44 802191B4 46020600 */   add.s    $f24, $f0, $f2
/* 6BCD48 802191B8 8E030010 */  lw        $v1, 0x10($s0)
/* 6BCD4C 802191BC 10600005 */  beqz      $v1, .L802191D4
/* 6BCD50 802191C0 24020001 */   addiu    $v0, $zero, 1
/* 6BCD54 802191C4 1062002A */  beq       $v1, $v0, .L80219270
/* 6BCD58 802191C8 00000000 */   nop
/* 6BCD5C 802191CC 080864D4 */  j         .L80219350
/* 6BCD60 802191D0 00000000 */   nop
.L802191D4:
/* 6BCD64 802191D4 8E020014 */  lw        $v0, 0x14($s0)
/* 6BCD68 802191D8 14400016 */  bnez      $v0, .L80219234
/* 6BCD6C 802191DC 2402000A */   addiu    $v0, $zero, 0xa
/* 6BCD70 802191E0 82230210 */  lb        $v1, 0x210($s1)
/* 6BCD74 802191E4 10620005 */  beq       $v1, $v0, .L802191FC
/* 6BCD78 802191E8 00000000 */   nop
/* 6BCD7C 802191EC 3C013F80 */  lui       $at, 0x3f80
/* 6BCD80 802191F0 44810000 */  mtc1      $at, $f0
/* 6BCD84 802191F4 08086484 */  j         .L80219210
/* 6BCD88 802191F8 E7A00010 */   swc1     $f0, 0x10($sp)
.L802191FC:
/* 6BCD8C 802191FC 3C013ECC */  lui       $at, 0x3ecc
/* 6BCD90 80219200 3421CCCD */  ori       $at, $at, 0xcccd
/* 6BCD94 80219204 44810000 */  mtc1      $at, $f0
/* 6BCD98 80219208 00000000 */  nop
/* 6BCD9C 8021920C E7A00010 */  swc1      $f0, 0x10($sp)
.L80219210:
/* 6BCDA0 80219210 0000202D */  daddu     $a0, $zero, $zero
/* 6BCDA4 80219214 4405B000 */  mfc1      $a1, $f22
/* 6BCDA8 80219218 4406A000 */  mfc1      $a2, $f20
/* 6BCDAC 8021921C 4407C000 */  mfc1      $a3, $f24
/* 6BCDB0 80219220 24020005 */  addiu     $v0, $zero, 5
/* 6BCDB4 80219224 AFA20014 */  sw        $v0, 0x14($sp)
/* 6BCDB8 80219228 0C01C8EC */  jal       playFX_73
/* 6BCDBC 8021922C AFA00018 */   sw       $zero, 0x18($sp)
/* 6BCDC0 80219230 AE020014 */  sw        $v0, 0x14($s0)
.L80219234:
/* 6BCDC4 80219234 8E030018 */  lw        $v1, 0x18($s0)
/* 6BCDC8 80219238 10600005 */  beqz      $v1, .L80219250
/* 6BCDCC 8021923C 00000000 */   nop
/* 6BCDD0 80219240 8C620000 */  lw        $v0, ($v1)
/* 6BCDD4 80219244 34420010 */  ori       $v0, $v0, 0x10
/* 6BCDD8 80219248 AC620000 */  sw        $v0, ($v1)
/* 6BCDDC 8021924C AE000018 */  sw        $zero, 0x18($s0)
.L80219250:
/* 6BCDE0 80219250 8E020014 */  lw        $v0, 0x14($s0)
/* 6BCDE4 80219254 8C42000C */  lw        $v0, 0xc($v0)
/* 6BCDE8 80219258 E4560004 */  swc1      $f22, 4($v0)
/* 6BCDEC 8021925C 8E020014 */  lw        $v0, 0x14($s0)
/* 6BCDF0 80219260 8C42000C */  lw        $v0, 0xc($v0)
/* 6BCDF4 80219264 E4540008 */  swc1      $f20, 8($v0)
/* 6BCDF8 80219268 080864C3 */  j         .L8021930C
/* 6BCDFC 8021926C 8E020014 */   lw       $v0, 0x14($s0)
.L80219270:
/* 6BCE00 80219270 8E030014 */  lw        $v1, 0x14($s0)
/* 6BCE04 80219274 10600005 */  beqz      $v1, .L8021928C
/* 6BCE08 80219278 00000000 */   nop
/* 6BCE0C 8021927C 8C620000 */  lw        $v0, ($v1)
/* 6BCE10 80219280 34420010 */  ori       $v0, $v0, 0x10
/* 6BCE14 80219284 AC620000 */  sw        $v0, ($v1)
/* 6BCE18 80219288 AE000014 */  sw        $zero, 0x14($s0)
.L8021928C:
/* 6BCE1C 8021928C 8E020018 */  lw        $v0, 0x18($s0)
/* 6BCE20 80219290 14400018 */  bnez      $v0, .L802192F4
/* 6BCE24 80219294 00000000 */   nop
/* 6BCE28 80219298 82230210 */  lb        $v1, 0x210($s1)
/* 6BCE2C 8021929C 2402000A */  addiu     $v0, $zero, 0xa
/* 6BCE30 802192A0 10620005 */  beq       $v1, $v0, .L802192B8
/* 6BCE34 802192A4 00000000 */   nop
/* 6BCE38 802192A8 3C013F80 */  lui       $at, 0x3f80
/* 6BCE3C 802192AC 44810000 */  mtc1      $at, $f0
/* 6BCE40 802192B0 080864B3 */  j         .L802192CC
/* 6BCE44 802192B4 E7A00010 */   swc1     $f0, 0x10($sp)
.L802192B8:
/* 6BCE48 802192B8 3C013ECC */  lui       $at, 0x3ecc
/* 6BCE4C 802192BC 3421CCCD */  ori       $at, $at, 0xcccd
/* 6BCE50 802192C0 44810000 */  mtc1      $at, $f0
/* 6BCE54 802192C4 00000000 */  nop
/* 6BCE58 802192C8 E7A00010 */  swc1      $f0, 0x10($sp)
.L802192CC:
/* 6BCE5C 802192CC 24040001 */  addiu     $a0, $zero, 1
/* 6BCE60 802192D0 4405B000 */  mfc1      $a1, $f22
/* 6BCE64 802192D4 4406A000 */  mfc1      $a2, $f20
/* 6BCE68 802192D8 4407C000 */  mfc1      $a3, $f24
/* 6BCE6C 802192DC 24020005 */  addiu     $v0, $zero, 5
/* 6BCE70 802192E0 AFA20014 */  sw        $v0, 0x14($sp)
/* 6BCE74 802192E4 0C01C8EC */  jal       playFX_73
/* 6BCE78 802192E8 AFA00018 */   sw       $zero, 0x18($sp)
/* 6BCE7C 802192EC AE020018 */  sw        $v0, 0x18($s0)
/* 6BCE80 802192F0 8E020018 */  lw        $v0, 0x18($s0)
.L802192F4:
/* 6BCE84 802192F4 8C42000C */  lw        $v0, 0xc($v0)
/* 6BCE88 802192F8 E4560004 */  swc1      $f22, 4($v0)
/* 6BCE8C 802192FC 8E020018 */  lw        $v0, 0x18($s0)
/* 6BCE90 80219300 8C42000C */  lw        $v0, 0xc($v0)
/* 6BCE94 80219304 E4540008 */  swc1      $f20, 8($v0)
/* 6BCE98 80219308 8E020018 */  lw        $v0, 0x18($s0)
.L8021930C:
/* 6BCE9C 8021930C 8C42000C */  lw        $v0, 0xc($v0)
/* 6BCEA0 80219310 080864D4 */  j         .L80219350
/* 6BCEA4 80219314 E458000C */   swc1     $f24, 0xc($v0)
.L80219318:
/* 6BCEA8 80219318 8E030014 */  lw        $v1, 0x14($s0)
/* 6BCEAC 8021931C 10600005 */  beqz      $v1, .L80219334
/* 6BCEB0 80219320 00000000 */   nop
/* 6BCEB4 80219324 8C620000 */  lw        $v0, ($v1)
/* 6BCEB8 80219328 34420010 */  ori       $v0, $v0, 0x10
/* 6BCEBC 8021932C AC620000 */  sw        $v0, ($v1)
/* 6BCEC0 80219330 AE000014 */  sw        $zero, 0x14($s0)
.L80219334:
/* 6BCEC4 80219334 8E030018 */  lw        $v1, 0x18($s0)
/* 6BCEC8 80219338 10600005 */  beqz      $v1, .L80219350
/* 6BCECC 8021933C 00000000 */   nop
/* 6BCED0 80219340 8C620000 */  lw        $v0, ($v1)
/* 6BCED4 80219344 34420010 */  ori       $v0, $v0, 0x10
/* 6BCED8 80219348 AC620000 */  sw        $v0, ($v1)
/* 6BCEDC 8021934C AE000018 */  sw        $zero, 0x18($s0)
.L80219350:
/* 6BCEE0 80219350 82230210 */  lb        $v1, 0x210($s1)
/* 6BCEE4 80219354 8E02001C */  lw        $v0, 0x1c($s0)
/* 6BCEE8 80219358 10430014 */  beq       $v0, $v1, .L802193AC
/* 6BCEEC 8021935C 0000102D */   daddu    $v0, $zero, $zero
/* 6BCEF0 80219360 8E02000C */  lw        $v0, 0xc($s0)
/* 6BCEF4 80219364 10400011 */  beqz      $v0, .L802193AC
/* 6BCEF8 80219368 0000102D */   daddu    $v0, $zero, $zero
/* 6BCEFC 8021936C 8E030014 */  lw        $v1, 0x14($s0)
/* 6BCF00 80219370 10600005 */  beqz      $v1, .L80219388
/* 6BCF04 80219374 00000000 */   nop
/* 6BCF08 80219378 8C620000 */  lw        $v0, ($v1)
/* 6BCF0C 8021937C 34420010 */  ori       $v0, $v0, 0x10
/* 6BCF10 80219380 AC620000 */  sw        $v0, ($v1)
/* 6BCF14 80219384 AE000014 */  sw        $zero, 0x14($s0)
.L80219388:
/* 6BCF18 80219388 8E030018 */  lw        $v1, 0x18($s0)
/* 6BCF1C 8021938C 10600005 */  beqz      $v1, .L802193A4
/* 6BCF20 80219390 00000000 */   nop
/* 6BCF24 80219394 8C620000 */  lw        $v0, ($v1)
/* 6BCF28 80219398 34420010 */  ori       $v0, $v0, 0x10
/* 6BCF2C 8021939C AC620000 */  sw        $v0, ($v1)
/* 6BCF30 802193A0 AE000018 */  sw        $zero, 0x18($s0)
.L802193A4:
/* 6BCF34 802193A4 82230210 */  lb        $v1, 0x210($s1)
/* 6BCF38 802193A8 0000102D */  daddu     $v0, $zero, $zero
.L802193AC:
/* 6BCF3C 802193AC AE03001C */  sw        $v1, 0x1c($s0)
.L802193B0:
/* 6BCF40 802193B0 8FBF002C */  lw        $ra, 0x2c($sp)
/* 6BCF44 802193B4 8FB20028 */  lw        $s2, 0x28($sp)
/* 6BCF48 802193B8 8FB10024 */  lw        $s1, 0x24($sp)
/* 6BCF4C 802193BC 8FB00020 */  lw        $s0, 0x20($sp)
/* 6BCF50 802193C0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6BCF54 802193C4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6BCF58 802193C8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6BCF5C 802193CC 03E00008 */  jr        $ra
/* 6BCF60 802193D0 27BD0048 */   addiu    $sp, $sp, 0x48

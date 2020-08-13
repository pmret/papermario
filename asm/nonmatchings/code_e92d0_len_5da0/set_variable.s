.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_variable
/* 0ECA48 802C8098 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0ECA4C 802C809C 0080382D */  daddu $a3, $a0, $zero
/* 0ECA50 802C80A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0ECA54 802C80A4 00A0802D */  daddu $s0, $a1, $zero
/* 0ECA58 802C80A8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0ECA5C 802C80AC 00C0902D */  daddu $s2, $a2, $zero
/* 0ECA60 802C80B0 3C02EFE8 */  lui   $v0, 0xefe8
/* 0ECA64 802C80B4 34422080 */  ori   $v0, $v0, 0x2080
/* 0ECA68 802C80B8 0050102A */  slt   $v0, $v0, $s0
/* 0ECA6C 802C80BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0ECA70 802C80C0 10400099 */  beqz  $v0, .L802C8328
/* 0ECA74 802C80C4 AFB10014 */   sw    $s1, 0x14($sp)
/* 0ECA78 802C80C8 3C02F2E3 */  lui   $v0, 0xf2e3
/* 0ECA7C 802C80CC 34421100 */  ori   $v0, $v0, 0x1100
/* 0ECA80 802C80D0 0050102A */  slt   $v0, $v0, $s0
/* 0ECA84 802C80D4 14400007 */  bnez  $v0, .L802C80F4
/* 0ECA88 802C80D8 3C02F414 */   lui   $v0, 0xf414
/* 0ECA8C 802C80DC 0C0B1248 */  jal   fixed_var_to_float
/* 0ECA90 802C80E0 0240202D */   daddu $a0, $s2, $zero
/* 0ECA94 802C80E4 4600008D */  trunc.w.s $f2, $f0
/* 0ECA98 802C80E8 44021000 */  mfc1  $v0, $f2
/* 0ECA9C 802C80EC 080B2105 */  j     .L802C8414
/* 0ECAA0 802C80F0 00000000 */   nop   

.L802C80F4:
/* 0ECAA4 802C80F4 34423E00 */  ori   $v0, $v0, 0x3e00
/* 0ECAA8 802C80F8 0050102A */  slt   $v0, $v0, $s0
/* 0ECAAC 802C80FC 54400017 */  bnel  $v0, $zero, .L802C815C
/* 0ECAB0 802C8100 3C02F545 */   lui   $v0, 0xf545
/* 0ECAB4 802C8104 3C020C84 */  lui   $v0, 0xc84
/* 0ECAB8 802C8108 34425880 */  ori   $v0, $v0, 0x5880
/* 0ECABC 802C810C 02028021 */  addu  $s0, $s0, $v0
/* 0ECAC0 802C8110 06010002 */  bgez  $s0, .L802C811C
/* 0ECAC4 802C8114 0200102D */   daddu $v0, $s0, $zero
/* 0ECAC8 802C8118 2602001F */  addiu $v0, $s0, 0x1f
.L802C811C:
/* 0ECACC 802C811C 00022943 */  sra   $a1, $v0, 5
/* 0ECAD0 802C8120 00A0202D */  daddu $a0, $a1, $zero
/* 0ECAD4 802C8124 00041140 */  sll   $v0, $a0, 5
/* 0ECAD8 802C8128 12400009 */  beqz  $s2, .L802C8150
/* 0ECADC 802C812C 02022823 */   subu  $a1, $s0, $v0
/* 0ECAE0 802C8130 8CE20140 */  lw    $v0, 0x140($a3)
/* 0ECAE4 802C8134 00042080 */  sll   $a0, $a0, 2
/* 0ECAE8 802C8138 00822021 */  addu  $a0, $a0, $v0
/* 0ECAEC 802C813C 24020001 */  addiu $v0, $zero, 1
/* 0ECAF0 802C8140 8C830000 */  lw    $v1, ($a0)
/* 0ECAF4 802C8144 00A21004 */  sllv  $v0, $v0, $a1
/* 0ECAF8 802C8148 080B20C9 */  j     .L802C8324
/* 0ECAFC 802C814C 00621825 */   or    $v1, $v1, $v0

.L802C8150:
/* 0ECB00 802C8150 8CE20140 */  lw    $v0, 0x140($a3)
/* 0ECB04 802C8154 080B20C3 */  j     .L802C830C
/* 0ECB08 802C8158 00042080 */   sll   $a0, $a0, 2

.L802C815C:
/* 0ECB0C 802C815C 34426B00 */  ori   $v0, $v0, 0x6b00
/* 0ECB10 802C8160 0050102A */  slt   $v0, $v0, $s0
/* 0ECB14 802C8164 1440000A */  bnez  $v0, .L802C8190
/* 0ECB18 802C8168 3C02F676 */   lui   $v0, 0xf676
/* 0ECB1C 802C816C 3C020B53 */  lui   $v0, 0xb53
/* 0ECB20 802C8170 34422B80 */  ori   $v0, $v0, 0x2b80
/* 0ECB24 802C8174 02028021 */  addu  $s0, $s0, $v0
/* 0ECB28 802C8178 8CE3013C */  lw    $v1, 0x13c($a3)
/* 0ECB2C 802C817C 00101080 */  sll   $v0, $s0, 2
/* 0ECB30 802C8180 00431021 */  addu  $v0, $v0, $v1
/* 0ECB34 802C8184 8C510000 */  lw    $s1, ($v0)
/* 0ECB38 802C8188 080B2104 */  j     .L802C8410
/* 0ECB3C 802C818C AC520000 */   sw    $s2, ($v0)

.L802C8190:
/* 0ECB40 802C8190 34429800 */  ori   $v0, $v0, 0x9800
/* 0ECB44 802C8194 0050102A */  slt   $v0, $v0, $s0
/* 0ECB48 802C8198 1440000C */  bnez  $v0, .L802C81CC
/* 0ECB4C 802C819C 3C02F7A7 */   lui   $v0, 0xf7a7
/* 0ECB50 802C81A0 3C020A21 */  lui   $v0, 0xa21
/* 0ECB54 802C81A4 3442FE80 */  ori   $v0, $v0, 0xfe80
/* 0ECB58 802C81A8 02028021 */  addu  $s0, $s0, $v0
/* 0ECB5C 802C81AC 0C05154E */  jal   get_global_byte
/* 0ECB60 802C81B0 0200202D */   daddu $a0, $s0, $zero
/* 0ECB64 802C81B4 0040882D */  daddu $s1, $v0, $zero
/* 0ECB68 802C81B8 0200202D */  daddu $a0, $s0, $zero
/* 0ECB6C 802C81BC 0C051548 */  jal   set_global_byte
/* 0ECB70 802C81C0 0240282D */   daddu $a1, $s2, $zero
/* 0ECB74 802C81C4 080B2105 */  j     .L802C8414
/* 0ECB78 802C81C8 0220102D */   daddu $v0, $s1, $zero

.L802C81CC:
/* 0ECB7C 802C81CC 3442C500 */  ori   $v0, $v0, 0xc500
/* 0ECB80 802C81D0 0050102A */  slt   $v0, $v0, $s0
/* 0ECB84 802C81D4 1440000C */  bnez  $v0, .L802C8208
/* 0ECB88 802C81D8 3C02F8D8 */   lui   $v0, 0xf8d8
/* 0ECB8C 802C81DC 3C0208F0 */  lui   $v0, 0x8f0
/* 0ECB90 802C81E0 3442D180 */  ori   $v0, $v0, 0xd180
/* 0ECB94 802C81E4 02028021 */  addu  $s0, $s0, $v0
/* 0ECB98 802C81E8 0C051594 */  jal   get_area_byte
/* 0ECB9C 802C81EC 0200202D */   daddu $a0, $s0, $zero
/* 0ECBA0 802C81F0 0040882D */  daddu $s1, $v0, $zero
/* 0ECBA4 802C81F4 0200202D */  daddu $a0, $s0, $zero
/* 0ECBA8 802C81F8 0C05158E */  jal   set_area_byte
/* 0ECBAC 802C81FC 0240282D */   daddu $a1, $s2, $zero
/* 0ECBB0 802C8200 080B2105 */  j     .L802C8414
/* 0ECBB4 802C8204 0220102D */   daddu $v0, $s1, $zero

.L802C8208:
/* 0ECBB8 802C8208 3442F200 */  ori   $v0, $v0, 0xf200
/* 0ECBBC 802C820C 0050102A */  slt   $v0, $v0, $s0
/* 0ECBC0 802C8210 14400010 */  bnez  $v0, .L802C8254
/* 0ECBC4 802C8214 3C02FA0A */   lui   $v0, 0xfa0a
/* 0ECBC8 802C8218 3C0207BF */  lui   $v0, 0x7bf
/* 0ECBCC 802C821C 3442A480 */  ori   $v0, $v0, 0xa480
/* 0ECBD0 802C8220 02028021 */  addu  $s0, $s0, $v0
/* 0ECBD4 802C8224 0C05152F */  jal   get_global_flag
/* 0ECBD8 802C8228 0200202D */   daddu $a0, $s0, $zero
/* 0ECBDC 802C822C 12400005 */  beqz  $s2, .L802C8244
/* 0ECBE0 802C8230 0040882D */   daddu $s1, $v0, $zero
/* 0ECBE4 802C8234 0C051514 */  jal   set_global_flag
/* 0ECBE8 802C8238 0200202D */   daddu $a0, $s0, $zero
/* 0ECBEC 802C823C 080B2105 */  j     .L802C8414
/* 0ECBF0 802C8240 0220102D */   daddu $v0, $s1, $zero

.L802C8244:
/* 0ECBF4 802C8244 0C0514F8 */  jal   clear_global_flag
/* 0ECBF8 802C8248 0200202D */   daddu $a0, $s0, $zero
/* 0ECBFC 802C824C 080B2105 */  j     .L802C8414
/* 0ECC00 802C8250 0220102D */   daddu $v0, $s1, $zero

.L802C8254:
/* 0ECC04 802C8254 34421F00 */  ori   $v0, $v0, 0x1f00
/* 0ECC08 802C8258 0050102A */  slt   $v0, $v0, $s0
/* 0ECC0C 802C825C 14400010 */  bnez  $v0, .L802C82A0
/* 0ECC10 802C8260 3C02FB3B */   lui   $v0, 0xfb3b
/* 0ECC14 802C8264 3C02068E */  lui   $v0, 0x68e
/* 0ECC18 802C8268 34427780 */  ori   $v0, $v0, 0x7780
/* 0ECC1C 802C826C 02028021 */  addu  $s0, $s0, $v0
/* 0ECC20 802C8270 0C05157C */  jal   get_area_flag
/* 0ECC24 802C8274 0200202D */   daddu $a0, $s0, $zero
/* 0ECC28 802C8278 12400005 */  beqz  $s2, .L802C8290
/* 0ECC2C 802C827C 0040882D */   daddu $s1, $v0, $zero
/* 0ECC30 802C8280 0C051568 */  jal   set_area_flag
/* 0ECC34 802C8284 0200202D */   daddu $a0, $s0, $zero
/* 0ECC38 802C8288 080B2105 */  j     .L802C8414
/* 0ECC3C 802C828C 0220102D */   daddu $v0, $s1, $zero

.L802C8290:
/* 0ECC40 802C8290 0C051553 */  jal   clear_area_flag
/* 0ECC44 802C8294 0200202D */   daddu $a0, $s0, $zero
/* 0ECC48 802C8298 080B2105 */  j     .L802C8414
/* 0ECC4C 802C829C 0220102D */   daddu $v0, $s1, $zero

.L802C82A0:
/* 0ECC50 802C82A0 34424C00 */  ori   $v0, $v0, 0x4c00
/* 0ECC54 802C82A4 0050102A */  slt   $v0, $v0, $s0
/* 0ECC58 802C82A8 54400021 */  bnel  $v0, $zero, .L802C8330
/* 0ECC5C 802C82AC 3C02FC6C */   lui   $v0, 0xfc6c
/* 0ECC60 802C82B0 3C02055D */  lui   $v0, 0x55d
/* 0ECC64 802C82B4 34424A80 */  ori   $v0, $v0, 0x4a80
/* 0ECC68 802C82B8 02028021 */  addu  $s0, $s0, $v0
/* 0ECC6C 802C82BC 06010002 */  bgez  $s0, .L802C82C8
/* 0ECC70 802C82C0 0200102D */   daddu $v0, $s0, $zero
/* 0ECC74 802C82C4 2602001F */  addiu $v0, $s0, 0x1f
.L802C82C8:
/* 0ECC78 802C82C8 00022943 */  sra   $a1, $v0, 5
/* 0ECC7C 802C82CC 00A0202D */  daddu $a0, $a1, $zero
/* 0ECC80 802C82D0 00041140 */  sll   $v0, $a0, 5
/* 0ECC84 802C82D4 1240000A */  beqz  $s2, .L802C8300
/* 0ECC88 802C82D8 02022823 */   subu  $a1, $s0, $v0
/* 0ECC8C 802C82DC 3C02802E */  lui   $v0, 0x802e
/* 0ECC90 802C82E0 8C42A480 */  lw    $v0, -0x5b80($v0)
/* 0ECC94 802C82E4 00042080 */  sll   $a0, $a0, 2
/* 0ECC98 802C82E8 00822021 */  addu  $a0, $a0, $v0
/* 0ECC9C 802C82EC 24020001 */  addiu $v0, $zero, 1
/* 0ECCA0 802C82F0 8C830000 */  lw    $v1, ($a0)
/* 0ECCA4 802C82F4 00A21004 */  sllv  $v0, $v0, $a1
/* 0ECCA8 802C82F8 080B20C9 */  j     .L802C8324
/* 0ECCAC 802C82FC 00621825 */   or    $v1, $v1, $v0

.L802C8300:
/* 0ECCB0 802C8300 3C02802E */  lui   $v0, 0x802e
/* 0ECCB4 802C8304 8C42A480 */  lw    $v0, -0x5b80($v0)
/* 0ECCB8 802C8308 00042080 */  sll   $a0, $a0, 2
.L802C830C:
/* 0ECCBC 802C830C 00822021 */  addu  $a0, $a0, $v0
/* 0ECCC0 802C8310 24020001 */  addiu $v0, $zero, 1
/* 0ECCC4 802C8314 00A21004 */  sllv  $v0, $v0, $a1
/* 0ECCC8 802C8318 8C830000 */  lw    $v1, ($a0)
/* 0ECCCC 802C831C 00021027 */  nor   $v0, $zero, $v0
/* 0ECCD0 802C8320 00621824 */  and   $v1, $v1, $v0
.L802C8324:
/* 0ECCD4 802C8324 AC830000 */  sw    $v1, ($a0)
.L802C8328:
/* 0ECCD8 802C8328 080B2105 */  j     .L802C8414
/* 0ECCDC 802C832C 0240102D */   daddu $v0, $s2, $zero

.L802C8330:
/* 0ECCE0 802C8330 34427900 */  ori   $v0, $v0, 0x7900
/* 0ECCE4 802C8334 0050102A */  slt   $v0, $v0, $s0
/* 0ECCE8 802C8338 5440001C */  bnel  $v0, $zero, .L802C83AC
/* 0ECCEC 802C833C 3C02FD9D */   lui   $v0, 0xfd9d
/* 0ECCF0 802C8340 3C02042C */  lui   $v0, 0x42c
/* 0ECCF4 802C8344 34421D80 */  ori   $v0, $v0, 0x1d80
/* 0ECCF8 802C8348 02028021 */  addu  $s0, $s0, $v0
/* 0ECCFC 802C834C 06010002 */  bgez  $s0, .L802C8358
/* 0ECD00 802C8350 0200102D */   daddu $v0, $s0, $zero
/* 0ECD04 802C8354 2602001F */  addiu $v0, $s0, 0x1f
.L802C8358:
/* 0ECD08 802C8358 00022943 */  sra   $a1, $v0, 5
/* 0ECD0C 802C835C 00A0182D */  daddu $v1, $a1, $zero
/* 0ECD10 802C8360 00031140 */  sll   $v0, $v1, 5
/* 0ECD14 802C8364 12400008 */  beqz  $s2, .L802C8388
/* 0ECD18 802C8368 02022823 */   subu  $a1, $s0, $v0
/* 0ECD1C 802C836C 00031080 */  sll   $v0, $v1, 2
/* 0ECD20 802C8370 00E21021 */  addu  $v0, $a3, $v0
/* 0ECD24 802C8374 24030001 */  addiu $v1, $zero, 1
/* 0ECD28 802C8378 8C4400C4 */  lw    $a0, 0xc4($v0)
/* 0ECD2C 802C837C 00A31804 */  sllv  $v1, $v1, $a1
/* 0ECD30 802C8380 080B20E9 */  j     .L802C83A4
/* 0ECD34 802C8384 00832025 */   or    $a0, $a0, $v1

.L802C8388:
/* 0ECD38 802C8388 00031080 */  sll   $v0, $v1, 2
/* 0ECD3C 802C838C 00E21021 */  addu  $v0, $a3, $v0
/* 0ECD40 802C8390 24030001 */  addiu $v1, $zero, 1
/* 0ECD44 802C8394 00A31804 */  sllv  $v1, $v1, $a1
/* 0ECD48 802C8398 8C4400C4 */  lw    $a0, 0xc4($v0)
/* 0ECD4C 802C839C 00031827 */  nor   $v1, $zero, $v1
/* 0ECD50 802C83A0 00832024 */  and   $a0, $a0, $v1
.L802C83A4:
/* 0ECD54 802C83A4 080B20CA */  j     .L802C8328
/* 0ECD58 802C83A8 AC4400C4 */   sw    $a0, 0xc4($v0)

.L802C83AC:
/* 0ECD5C 802C83AC 3442A600 */  ori   $v0, $v0, 0xa600
/* 0ECD60 802C83B0 0050102A */  slt   $v0, $v0, $s0
/* 0ECD64 802C83B4 1440000B */  bnez  $v0, .L802C83E4
/* 0ECD68 802C83B8 3C02FECE */   lui   $v0, 0xfece
/* 0ECD6C 802C83BC 3C0202FA */  lui   $v0, 0x2fa
/* 0ECD70 802C83C0 3442F080 */  ori   $v0, $v0, 0xf080
/* 0ECD74 802C83C4 02028021 */  addu  $s0, $s0, $v0
/* 0ECD78 802C83C8 3C03802E */  lui   $v1, 0x802e
/* 0ECD7C 802C83CC 8C63A484 */  lw    $v1, -0x5b7c($v1)
/* 0ECD80 802C83D0 00101080 */  sll   $v0, $s0, 2
/* 0ECD84 802C83D4 00431021 */  addu  $v0, $v0, $v1
/* 0ECD88 802C83D8 8C510000 */  lw    $s1, ($v0)
/* 0ECD8C 802C83DC 080B2104 */  j     .L802C8410
/* 0ECD90 802C83E0 AC520000 */   sw    $s2, ($v0)

.L802C83E4:
/* 0ECD94 802C83E4 3442D300 */  ori   $v0, $v0, 0xd300
/* 0ECD98 802C83E8 0050102A */  slt   $v0, $v0, $s0
/* 0ECD9C 802C83EC 14400009 */  bnez  $v0, .L802C8414
/* 0ECDA0 802C83F0 0240102D */   daddu $v0, $s2, $zero
/* 0ECDA4 802C83F4 3C0201C9 */  lui   $v0, 0x1c9
/* 0ECDA8 802C83F8 3442C380 */  ori   $v0, $v0, 0xc380
/* 0ECDAC 802C83FC 02028021 */  addu  $s0, $s0, $v0
/* 0ECDB0 802C8400 00101080 */  sll   $v0, $s0, 2
/* 0ECDB4 802C8404 00E21021 */  addu  $v0, $a3, $v0
/* 0ECDB8 802C8408 8C510084 */  lw    $s1, 0x84($v0)
/* 0ECDBC 802C840C AC520084 */  sw    $s2, 0x84($v0)
.L802C8410:
/* 0ECDC0 802C8410 0220102D */  daddu $v0, $s1, $zero
.L802C8414:
/* 0ECDC4 802C8414 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0ECDC8 802C8418 8FB20018 */  lw    $s2, 0x18($sp)
/* 0ECDCC 802C841C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0ECDD0 802C8420 8FB00010 */  lw    $s0, 0x10($sp)
/* 0ECDD4 802C8424 03E00008 */  jr    $ra
/* 0ECDD8 802C8428 27BD0020 */   addiu $sp, $sp, 0x20


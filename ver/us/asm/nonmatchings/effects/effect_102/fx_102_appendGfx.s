.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_102_appendGfx
/* 3D2060 E00CC9D0 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 3D2064 E00CC9D4 0080302D */  daddu     $a2, $a0, $zero
/* 3D2068 E00CC9D8 3C07DB06 */  lui       $a3, 0xdb06
/* 3D206C E00CC9DC 34E70024 */  ori       $a3, $a3, 0x24
/* 3D2070 E00CC9E0 27A40018 */  addiu     $a0, $sp, 0x18
/* 3D2074 E00CC9E4 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3D2078 E00CC9E8 3C110001 */  lui       $s1, 1
/* 3D207C E00CC9EC 36311630 */  ori       $s1, $s1, 0x1630
/* 3D2080 E00CC9F0 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3D2084 E00CC9F4 0000B02D */  daddu     $s6, $zero, $zero
/* 3D2088 E00CC9F8 27A20058 */  addiu     $v0, $sp, 0x58
/* 3D208C E00CC9FC AFB300AC */  sw        $s3, 0xac($sp)
/* 3D2090 E00CCA00 0040982D */  daddu     $s3, $v0, $zero
/* 3D2094 E00CCA04 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3D2098 E00CCA08 2442A674 */  addiu     $v0, $v0, %lo(gDisplayContext)
/* 3D209C E00CCA0C AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3D20A0 E00CCA10 0040F02D */  daddu     $fp, $v0, $zero
/* 3D20A4 E00CCA14 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 3D20A8 E00CCA18 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 3D20AC E00CCA1C AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3D20B0 E00CCA20 0040A82D */  daddu     $s5, $v0, $zero
/* 3D20B4 E00CCA24 AFB700BC */  sw        $s7, 0xbc($sp)
/* 3D20B8 E00CCA28 3C170001 */  lui       $s7, 1
/* 3D20BC E00CCA2C 36F71630 */  ori       $s7, $s7, 0x1630
/* 3D20C0 E00CCA30 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3D20C4 E00CCA34 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3D20C8 E00CCA38 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3D20CC E00CCA3C 0040A02D */  daddu     $s4, $v0, $zero
/* 3D20D0 E00CCA40 3C08800B */  lui       $t0, %hi(gCameras)
/* 3D20D4 E00CCA44 25081D80 */  addiu     $t0, $t0, %lo(gCameras)
/* 3D20D8 E00CCA48 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3D20DC E00CCA4C AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3D20E0 E00CCA50 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3D20E4 E00CCA54 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 3D20E8 E00CCA58 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 3D20EC E00CCA5C 8E850000 */  lw        $a1, ($s4)
/* 3D20F0 E00CCA60 4480A000 */  mtc1      $zero, $f20
/* 3D20F4 E00CCA64 3C013F80 */  lui       $at, 0x3f80
/* 3D20F8 E00CCA68 4481B000 */  mtc1      $at, $f22
/* 3D20FC E00CCA6C 8CC2000C */  lw        $v0, 0xc($a2)
/* 3D2100 E00CCA70 00A0182D */  daddu     $v1, $a1, $zero
/* 3D2104 E00CCA74 24A50008 */  addiu     $a1, $a1, 8
/* 3D2108 E00CCA78 0040902D */  daddu     $s2, $v0, $zero
/* 3D210C E00CCA7C AE850000 */  sw        $a1, ($s4)
/* 3D2110 E00CCA80 8E500024 */  lw        $s0, 0x24($s2)
/* 3D2114 E00CCA84 3C02E700 */  lui       $v0, 0xe700
/* 3D2118 E00CCA88 AC620000 */  sw        $v0, ($v1)
/* 3D211C E00CCA8C AC600004 */  sw        $zero, 4($v1)
/* 3D2120 E00CCA90 ACA70000 */  sw        $a3, ($a1)
/* 3D2124 E00CCA94 8CC30010 */  lw        $v1, 0x10($a2)
/* 3D2128 E00CCA98 24A20008 */  addiu     $v0, $a1, 8
/* 3D212C E00CCA9C AE820000 */  sw        $v0, ($s4)
/* 3D2130 E00CCAA0 8C62001C */  lw        $v0, 0x1c($v1)
/* 3D2134 E00CCAA4 3C038000 */  lui       $v1, 0x8000
/* 3D2138 E00CCAA8 00431021 */  addu      $v0, $v0, $v1
/* 3D213C E00CCAAC ACA20004 */  sw        $v0, 4($a1)
/* 3D2140 E00CCAB0 8E450004 */  lw        $a1, 4($s2)
/* 3D2144 E00CCAB4 8E460008 */  lw        $a2, 8($s2)
/* 3D2148 E00CCAB8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3D214C E00CCABC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3D2150 E00CCAC0 8E47000C */  lw        $a3, 0xc($s2)
/* 3D2154 E00CCAC4 00031080 */  sll       $v0, $v1, 2
/* 3D2158 E00CCAC8 00431021 */  addu      $v0, $v0, $v1
/* 3D215C E00CCACC 00021080 */  sll       $v0, $v0, 2
/* 3D2160 E00CCAD0 00431023 */  subu      $v0, $v0, $v1
/* 3D2164 E00CCAD4 000218C0 */  sll       $v1, $v0, 3
/* 3D2168 E00CCAD8 00431021 */  addu      $v0, $v0, $v1
/* 3D216C E00CCADC 000210C0 */  sll       $v0, $v0, 3
/* 3D2170 E00CCAE0 00481021 */  addu      $v0, $v0, $t0
/* 3D2174 E00CCAE4 0C080108 */  jal       shim_guTranslateF
/* 3D2178 E00CCAE8 AFA20098 */   sw       $v0, 0x98($sp)
/* 3D217C E00CCAEC 8E450028 */  lw        $a1, 0x28($s2)
/* 3D2180 E00CCAF0 0260202D */  daddu     $a0, $s3, $zero
/* 3D2184 E00CCAF4 00A0302D */  daddu     $a2, $a1, $zero
/* 3D2188 E00CCAF8 0C080110 */  jal       shim_guScaleF
/* 3D218C E00CCAFC 00A0382D */   daddu    $a3, $a1, $zero
/* 3D2190 E00CCB00 0260202D */  daddu     $a0, $s3, $zero
/* 3D2194 E00CCB04 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D2198 E00CCB08 0C080114 */  jal       shim_guMtxCatF
/* 3D219C E00CCB0C 00A0302D */   daddu    $a2, $a1, $zero
/* 3D21A0 E00CCB10 27A40018 */  addiu     $a0, $sp, 0x18
/* 3D21A4 E00CCB14 96A50000 */  lhu       $a1, ($s5)
/* 3D21A8 E00CCB18 8FC20000 */  lw        $v0, ($fp)
/* 3D21AC E00CCB1C 00052980 */  sll       $a1, $a1, 6
/* 3D21B0 E00CCB20 00B12821 */  addu      $a1, $a1, $s1
/* 3D21B4 E00CCB24 0C080118 */  jal       shim_guMtxF2L
/* 3D21B8 E00CCB28 00452821 */   addu     $a1, $v0, $a1
/* 3D21BC E00CCB2C 3C03DA38 */  lui       $v1, 0xda38
/* 3D21C0 E00CCB30 34630002 */  ori       $v1, $v1, 2
/* 3D21C4 E00CCB34 321000FF */  andi      $s0, $s0, 0xff
/* 3D21C8 E00CCB38 8E840000 */  lw        $a0, ($s4)
/* 3D21CC E00CCB3C 96A20000 */  lhu       $v0, ($s5)
/* 3D21D0 E00CCB40 0080282D */  daddu     $a1, $a0, $zero
/* 3D21D4 E00CCB44 24840008 */  addiu     $a0, $a0, 8
/* 3D21D8 E00CCB48 AE840000 */  sw        $a0, ($s4)
/* 3D21DC E00CCB4C ACA30000 */  sw        $v1, ($a1)
/* 3D21E0 E00CCB50 24430001 */  addiu     $v1, $v0, 1
/* 3D21E4 E00CCB54 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D21E8 E00CCB58 00021180 */  sll       $v0, $v0, 6
/* 3D21EC E00CCB5C A6A30000 */  sh        $v1, ($s5)
/* 3D21F0 E00CCB60 8FC30000 */  lw        $v1, ($fp)
/* 3D21F4 E00CCB64 00511021 */  addu      $v0, $v0, $s1
/* 3D21F8 E00CCB68 00621821 */  addu      $v1, $v1, $v0
/* 3D21FC E00CCB6C 24820008 */  addiu     $v0, $a0, 8
/* 3D2200 E00CCB70 ACA30004 */  sw        $v1, 4($a1)
/* 3D2204 E00CCB74 AE820000 */  sw        $v0, ($s4)
/* 3D2208 E00CCB78 3C02FA00 */  lui       $v0, 0xfa00
/* 3D220C E00CCB7C AC820000 */  sw        $v0, ($a0)
/* 3D2210 E00CCB80 9243001B */  lbu       $v1, 0x1b($s2)
/* 3D2214 E00CCB84 9245001F */  lbu       $a1, 0x1f($s2)
/* 3D2218 E00CCB88 92460023 */  lbu       $a2, 0x23($s2)
/* 3D221C E00CCB8C 24820010 */  addiu     $v0, $a0, 0x10
/* 3D2220 E00CCB90 AE820000 */  sw        $v0, ($s4)
/* 3D2224 E00CCB94 3C02FB00 */  lui       $v0, 0xfb00
/* 3D2228 E00CCB98 AC820008 */  sw        $v0, 8($a0)
/* 3D222C E00CCB9C 24820018 */  addiu     $v0, $a0, 0x18
/* 3D2230 E00CCBA0 AC80000C */  sw        $zero, 0xc($a0)
/* 3D2234 E00CCBA4 AE820000 */  sw        $v0, ($s4)
/* 3D2238 E00CCBA8 3C02DE00 */  lui       $v0, 0xde00
/* 3D223C E00CCBAC AC820010 */  sw        $v0, 0x10($a0)
/* 3D2240 E00CCBB0 3C020900 */  lui       $v0, 0x900
/* 3D2244 E00CCBB4 24420400 */  addiu     $v0, $v0, 0x400
/* 3D2248 E00CCBB8 AC820014 */  sw        $v0, 0x14($a0)
/* 3D224C E00CCBBC 00031E00 */  sll       $v1, $v1, 0x18
/* 3D2250 E00CCBC0 00052C00 */  sll       $a1, $a1, 0x10
/* 3D2254 E00CCBC4 00651825 */  or        $v1, $v1, $a1
/* 3D2258 E00CCBC8 00063200 */  sll       $a2, $a2, 8
/* 3D225C E00CCBCC 00661825 */  or        $v1, $v1, $a2
/* 3D2260 E00CCBD0 00701825 */  or        $v1, $v1, $s0
/* 3D2264 E00CCBD4 AC830004 */  sw        $v1, 4($a0)
.LE00CCBD8:
/* 3D2268 E00CCBD8 8E4306D0 */  lw        $v1, 0x6d0($s2)
/* 3D226C E00CCBDC 5060005F */  beql      $v1, $zero, .LE00CCD5C
/* 3D2270 E00CCBE0 26D60001 */   addiu    $s6, $s6, 1
/* 3D2274 E00CCBE4 24020007 */  addiu     $v0, $zero, 7
/* 3D2278 E00CCBE8 5062005C */  beql      $v1, $v0, .LE00CCD5C
/* 3D227C E00CCBEC 26D60001 */   addiu    $s6, $s6, 1
/* 3D2280 E00CCBF0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 3D2284 E00CCBF4 8E4504DC */  lw        $a1, 0x4dc($s2)
/* 3D2288 E00CCBF8 4406A000 */  mfc1      $a2, $f20
/* 3D228C E00CCBFC 4407B000 */  mfc1      $a3, $f22
/* 3D2290 E00CCC00 0C080104 */  jal       shim_guRotateF
/* 3D2294 E00CCC04 27A40018 */   addiu    $a0, $sp, 0x18
/* 3D2298 E00CCC08 8E45002C */  lw        $a1, 0x2c($s2)
/* 3D229C E00CCC0C 8E460090 */  lw        $a2, 0x90($s2)
/* 3D22A0 E00CCC10 8E4700F4 */  lw        $a3, 0xf4($s2)
/* 3D22A4 E00CCC14 0C080108 */  jal       shim_guTranslateF
/* 3D22A8 E00CCC18 0260202D */   daddu    $a0, $s3, $zero
/* 3D22AC E00CCC1C 0260202D */  daddu     $a0, $s3, $zero
/* 3D22B0 E00CCC20 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D22B4 E00CCC24 0C080114 */  jal       shim_guMtxCatF
/* 3D22B8 E00CCC28 00A0302D */   daddu    $a2, $a1, $zero
/* 3D22BC E00CCC2C 4406A000 */  mfc1      $a2, $f20
/* 3D22C0 E00CCC30 C64004DC */  lwc1      $f0, 0x4dc($s2)
/* 3D22C4 E00CCC34 4407B000 */  mfc1      $a3, $f22
/* 3D22C8 E00CCC38 46000007 */  neg.s     $f0, $f0
/* 3D22CC E00CCC3C 44050000 */  mfc1      $a1, $f0
/* 3D22D0 E00CCC40 0260202D */  daddu     $a0, $s3, $zero
/* 3D22D4 E00CCC44 0C080104 */  jal       shim_guRotateF
/* 3D22D8 E00CCC48 E7B40010 */   swc1     $f20, 0x10($sp)
/* 3D22DC E00CCC4C 0260202D */  daddu     $a0, $s3, $zero
/* 3D22E0 E00CCC50 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D22E4 E00CCC54 0C080114 */  jal       shim_guMtxCatF
/* 3D22E8 E00CCC58 00A0302D */   daddu    $a2, $a1, $zero
/* 3D22EC E00CCC5C E7B60010 */  swc1      $f22, 0x10($sp)
/* 3D22F0 E00CCC60 8E450478 */  lw        $a1, 0x478($s2)
/* 3D22F4 E00CCC64 4406A000 */  mfc1      $a2, $f20
/* 3D22F8 E00CCC68 4407A000 */  mfc1      $a3, $f20
/* 3D22FC E00CCC6C 0C080104 */  jal       shim_guRotateF
/* 3D2300 E00CCC70 0260202D */   daddu    $a0, $s3, $zero
/* 3D2304 E00CCC74 0260202D */  daddu     $a0, $s3, $zero
/* 3D2308 E00CCC78 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D230C E00CCC7C 0C080114 */  jal       shim_guMtxCatF
/* 3D2310 E00CCC80 00A0302D */   daddu    $a2, $a1, $zero
/* 3D2314 E00CCC84 8E4503B0 */  lw        $a1, 0x3b0($s2)
/* 3D2318 E00CCC88 8E460414 */  lw        $a2, 0x414($s2)
/* 3D231C E00CCC8C 4407B000 */  mfc1      $a3, $f22
/* 3D2320 E00CCC90 0C080110 */  jal       shim_guScaleF
/* 3D2324 E00CCC94 0260202D */   daddu    $a0, $s3, $zero
/* 3D2328 E00CCC98 0260202D */  daddu     $a0, $s3, $zero
/* 3D232C E00CCC9C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D2330 E00CCCA0 0C080114 */  jal       shim_guMtxCatF
/* 3D2334 E00CCCA4 00A0302D */   daddu    $a2, $a1, $zero
/* 3D2338 E00CCCA8 27A40018 */  addiu     $a0, $sp, 0x18
/* 3D233C E00CCCAC 96A50000 */  lhu       $a1, ($s5)
/* 3D2340 E00CCCB0 8FC20000 */  lw        $v0, ($fp)
/* 3D2344 E00CCCB4 00052980 */  sll       $a1, $a1, 6
/* 3D2348 E00CCCB8 00B72821 */  addu      $a1, $a1, $s7
/* 3D234C E00CCCBC 0C080118 */  jal       shim_guMtxF2L
/* 3D2350 E00CCCC0 00452821 */   addu     $a1, $v0, $a1
/* 3D2354 E00CCCC4 3C06DA38 */  lui       $a2, 0xda38
/* 3D2358 E00CCCC8 34C60001 */  ori       $a2, $a2, 1
/* 3D235C E00CCCCC 8E840000 */  lw        $a0, ($s4)
/* 3D2360 E00CCCD0 3C07D838 */  lui       $a3, 0xd838
/* 3D2364 E00CCCD4 0080282D */  daddu     $a1, $a0, $zero
/* 3D2368 E00CCCD8 24840008 */  addiu     $a0, $a0, 8
/* 3D236C E00CCCDC AE840000 */  sw        $a0, ($s4)
/* 3D2370 E00CCCE0 96A20000 */  lhu       $v0, ($s5)
/* 3D2374 E00CCCE4 3C03DA38 */  lui       $v1, 0xda38
/* 3D2378 E00CCCE8 ACA30000 */  sw        $v1, ($a1)
/* 3D237C E00CCCEC 24430001 */  addiu     $v1, $v0, 1
/* 3D2380 E00CCCF0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D2384 E00CCCF4 00021180 */  sll       $v0, $v0, 6
/* 3D2388 E00CCCF8 A6A30000 */  sh        $v1, ($s5)
/* 3D238C E00CCCFC 8FC30000 */  lw        $v1, ($fp)
/* 3D2390 E00CCD00 00571021 */  addu      $v0, $v0, $s7
/* 3D2394 E00CCD04 00621821 */  addu      $v1, $v1, $v0
/* 3D2398 E00CCD08 24820008 */  addiu     $v0, $a0, 8
/* 3D239C E00CCD0C ACA30004 */  sw        $v1, 4($a1)
/* 3D23A0 E00CCD10 AE820000 */  sw        $v0, ($s4)
/* 3D23A4 E00CCD14 24820010 */  addiu     $v0, $a0, 0x10
/* 3D23A8 E00CCD18 AC860000 */  sw        $a2, ($a0)
/* 3D23AC E00CCD1C AE820000 */  sw        $v0, ($s4)
/* 3D23B0 E00CCD20 8FA90098 */  lw        $t1, 0x98($sp)
/* 3D23B4 E00CCD24 34E70002 */  ori       $a3, $a3, 2
/* 3D23B8 E00CCD28 8D230204 */  lw        $v1, 0x204($t1)
/* 3D23BC E00CCD2C 3C02DE00 */  lui       $v0, 0xde00
/* 3D23C0 E00CCD30 AC820008 */  sw        $v0, 8($a0)
/* 3D23C4 E00CCD34 3C020900 */  lui       $v0, 0x900
/* 3D23C8 E00CCD38 24420518 */  addiu     $v0, $v0, 0x518
/* 3D23CC E00CCD3C AC82000C */  sw        $v0, 0xc($a0)
/* 3D23D0 E00CCD40 24820018 */  addiu     $v0, $a0, 0x18
/* 3D23D4 E00CCD44 AE820000 */  sw        $v0, ($s4)
/* 3D23D8 E00CCD48 24020040 */  addiu     $v0, $zero, 0x40
/* 3D23DC E00CCD4C AC870010 */  sw        $a3, 0x10($a0)
/* 3D23E0 E00CCD50 AC820014 */  sw        $v0, 0x14($a0)
/* 3D23E4 E00CCD54 AC830004 */  sw        $v1, 4($a0)
/* 3D23E8 E00CCD58 26D60001 */  addiu     $s6, $s6, 1
.LE00CCD5C:
/* 3D23EC E00CCD5C 2AC20019 */  slti      $v0, $s6, 0x19
/* 3D23F0 E00CCD60 1440FF9D */  bnez      $v0, .LE00CCBD8
/* 3D23F4 E00CCD64 26520004 */   addiu    $s2, $s2, 4
/* 3D23F8 E00CCD68 3C05D838 */  lui       $a1, 0xd838
/* 3D23FC E00CCD6C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3D2400 E00CCD70 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3D2404 E00CCD74 8C620000 */  lw        $v0, ($v1)
/* 3D2408 E00CCD78 34A50002 */  ori       $a1, $a1, 2
/* 3D240C E00CCD7C 0040202D */  daddu     $a0, $v0, $zero
/* 3D2410 E00CCD80 24420008 */  addiu     $v0, $v0, 8
/* 3D2414 E00CCD84 AC620000 */  sw        $v0, ($v1)
/* 3D2418 E00CCD88 24020040 */  addiu     $v0, $zero, 0x40
/* 3D241C E00CCD8C AC850000 */  sw        $a1, ($a0)
/* 3D2420 E00CCD90 AC820004 */  sw        $v0, 4($a0)
/* 3D2424 E00CCD94 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3D2428 E00CCD98 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3D242C E00CCD9C 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3D2430 E00CCDA0 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3D2434 E00CCDA4 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3D2438 E00CCDA8 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3D243C E00CCDAC 8FB300AC */  lw        $s3, 0xac($sp)
/* 3D2440 E00CCDB0 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3D2444 E00CCDB4 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3D2448 E00CCDB8 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3D244C E00CCDBC D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 3D2450 E00CCDC0 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 3D2454 E00CCDC4 03E00008 */  jr        $ra
/* 3D2458 E00CCDC8 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 3D245C E00CCDCC 00000000 */  nop

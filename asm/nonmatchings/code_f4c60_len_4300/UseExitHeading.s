.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UseExitHeading
/* F6B1C 802D216C 27BDFF98 */  addiu     $sp, $sp, -0x68
/* F6B20 802D2170 AFB30024 */  sw        $s3, 0x24($sp)
/* F6B24 802D2174 0080982D */  daddu     $s3, $a0, $zero
/* F6B28 802D2178 AFBF0030 */  sw        $ra, 0x30($sp)
/* F6B2C 802D217C AFB5002C */  sw        $s5, 0x2c($sp)
/* F6B30 802D2180 AFB40028 */  sw        $s4, 0x28($sp)
/* F6B34 802D2184 AFB20020 */  sw        $s2, 0x20($sp)
/* F6B38 802D2188 AFB1001C */  sw        $s1, 0x1c($sp)
/* F6B3C 802D218C AFB00018 */  sw        $s0, 0x18($sp)
/* F6B40 802D2190 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* F6B44 802D2194 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* F6B48 802D2198 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* F6B4C 802D219C F7B80048 */  sdc1      $f24, 0x48($sp)
/* F6B50 802D21A0 F7B60040 */  sdc1      $f22, 0x40($sp)
/* F6B54 802D21A4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* F6B58 802D21A8 8E70000C */  lw        $s0, 0xc($s3)
/* F6B5C 802D21AC 0C016AFA */  jal       get_current_map_header
/* F6B60 802D21B0 26750098 */   addiu    $s5, $s3, 0x98
/* F6B64 802D21B4 3C128011 */  lui       $s2, 0x8011
/* F6B68 802D21B8 2652EFC8 */  addiu     $s2, $s2, -0x1038
/* F6B6C 802D21BC 0C0389B1 */  jal       func_800E26C4
/* F6B70 802D21C0 0040A02D */   daddu    $s4, $v0, $zero
/* F6B74 802D21C4 1040007D */  beqz      $v0, .L802D23BC
/* F6B78 802D21C8 0000102D */   daddu    $v0, $zero, $zero
/* F6B7C 802D21CC 8E050000 */  lw        $a1, ($s0)
/* F6B80 802D21D0 26100004 */  addiu     $s0, $s0, 4
/* F6B84 802D21D4 0C0B1EAF */  jal       get_variable
/* F6B88 802D21D8 0260202D */   daddu    $a0, $s3, $zero
/* F6B8C 802D21DC 0040882D */  daddu     $s1, $v0, $zero
/* F6B90 802D21E0 8E050000 */  lw        $a1, ($s0)
/* F6B94 802D21E4 0C0B1EAF */  jal       get_variable
/* F6B98 802D21E8 0260202D */   daddu    $a0, $s3, $zero
/* F6B9C 802D21EC 0040802D */  daddu     $s0, $v0, $zero
/* F6BA0 802D21F0 00101100 */  sll       $v0, $s0, 4
/* F6BA4 802D21F4 4491C000 */  mtc1      $s1, $f24
/* F6BA8 802D21F8 00000000 */  nop       
/* F6BAC 802D21FC 4680C620 */  cvt.s.w   $f24, $f24
/* F6BB0 802D2200 8E460028 */  lw        $a2, 0x28($s2)
/* F6BB4 802D2204 8E830014 */  lw        $v1, 0x14($s4)
/* F6BB8 802D2208 3C014120 */  lui       $at, 0x4120
/* F6BBC 802D220C 44810000 */  mtc1      $at, $f0
/* F6BC0 802D2210 3C013F00 */  lui       $at, 0x3f00
/* F6BC4 802D2214 4481D000 */  mtc1      $at, $f26
/* F6BC8 802D2218 8E470030 */  lw        $a3, 0x30($s2)
/* F6BCC 802D221C 4600C580 */  add.s     $f22, $f24, $f0
/* F6BD0 802D2220 00431021 */  addu      $v0, $v0, $v1
/* F6BD4 802D2224 C45C0000 */  lwc1      $f28, ($v0)
/* F6BD8 802D2228 461AB502 */  mul.s     $f20, $f22, $f26
/* F6BDC 802D222C 00000000 */  nop       
/* F6BE0 802D2230 C45E0008 */  lwc1      $f30, 8($v0)
/* F6BE4 802D2234 4600E306 */  mov.s     $f12, $f28
/* F6BE8 802D2238 0C00A7B5 */  jal       dist2D
/* F6BEC 802D223C 4600F386 */   mov.s    $f14, $f30
/* F6BF0 802D2240 46140081 */  sub.s     $f2, $f0, $f20
/* F6BF4 802D2244 44800000 */  mtc1      $zero, $f0
/* F6BF8 802D2248 00000000 */  nop       
/* F6BFC 802D224C 4602003C */  c.lt.s    $f0, $f2
/* F6C00 802D2250 00000000 */  nop       
/* F6C04 802D2254 4502000B */  bc1fl     .L802D2284
/* F6C08 802D2258 00108100 */   sll      $s0, $s0, 4
/* F6C0C 802D225C 4602B03C */  c.lt.s    $f22, $f2
/* F6C10 802D2260 00000000 */  nop       
/* F6C14 802D2264 45030001 */  bc1tl     .L802D226C
/* F6C18 802D2268 4600B086 */   mov.s    $f2, $f22
.L802D226C:
/* F6C1C 802D226C 461A1002 */  mul.s     $f0, $f2, $f26
/* F6C20 802D2270 00000000 */  nop       
/* F6C24 802D2274 4600C001 */  sub.s     $f0, $f24, $f0
/* F6C28 802D2278 4600040D */  trunc.w.s $f16, $f0
/* F6C2C 802D227C 44118000 */  mfc1      $s1, $f16
/* F6C30 802D2280 00108100 */  sll       $s0, $s0, 4
.L802D2284:
/* F6C34 802D2284 8E820014 */  lw        $v0, 0x14($s4)
/* F6C38 802D2288 3C014334 */  lui       $at, 0x4334
/* F6C3C 802D228C 44816000 */  mtc1      $at, $f12
/* F6C40 802D2290 02021021 */  addu      $v0, $s0, $v0
/* F6C44 802D2294 C440000C */  lwc1      $f0, 0xc($v0)
/* F6C48 802D2298 0C00A6C9 */  jal       clamp_angle
/* F6C4C 802D229C 460C0300 */   add.s    $f12, $f0, $f12
/* F6C50 802D22A0 46000306 */  mov.s     $f12, $f0
/* F6C54 802D22A4 27A50010 */  addiu     $a1, $sp, 0x10
/* F6C58 802D22A8 0C00A88D */  jal       sin_cos_deg
/* F6C5C 802D22AC 27A60014 */   addiu    $a2, $sp, 0x14
/* F6C60 802D22B0 C7AA0010 */  lwc1      $f10, 0x10($sp)
/* F6C64 802D22B4 44913000 */  mtc1      $s1, $f6
/* F6C68 802D22B8 00000000 */  nop       
/* F6C6C 802D22BC 468031A0 */  cvt.s.w   $f6, $f6
/* F6C70 802D22C0 460A3302 */  mul.s     $f12, $f6, $f10
/* F6C74 802D22C4 00000000 */  nop       
/* F6C78 802D22C8 C7A80014 */  lwc1      $f8, 0x14($sp)
/* F6C7C 802D22CC 46083182 */  mul.s     $f6, $f6, $f8
/* F6C80 802D22D0 00000000 */  nop       
/* F6C84 802D22D4 C6420028 */  lwc1      $f2, 0x28($s2)
/* F6C88 802D22D8 461C1081 */  sub.s     $f2, $f2, $f28
/* F6C8C 802D22DC 46024082 */  mul.s     $f2, $f8, $f2
/* F6C90 802D22E0 00000000 */  nop       
/* F6C94 802D22E4 C6400030 */  lwc1      $f0, 0x30($s2)
/* F6C98 802D22E8 4600F001 */  sub.s     $f0, $f30, $f0
/* F6C9C 802D22EC 46005002 */  mul.s     $f0, $f10, $f0
/* F6CA0 802D22F0 00000000 */  nop       
/* F6CA4 802D22F4 46001081 */  sub.s     $f2, $f2, $f0
/* F6CA8 802D22F8 3C013E99 */  lui       $at, 0x3e99
/* F6CAC 802D22FC 3421999A */  ori       $at, $at, 0x999a
/* F6CB0 802D2300 44812000 */  mtc1      $at, $f4
/* F6CB4 802D2304 00000000 */  nop       
/* F6CB8 802D2308 46041102 */  mul.s     $f4, $f2, $f4
/* F6CBC 802D230C 00000000 */  nop       
/* F6CC0 802D2310 3C028007 */  lui       $v0, 0x8007
/* F6CC4 802D2314 8C42419C */  lw        $v0, 0x419c($v0)
/* F6CC8 802D2318 46082382 */  mul.s     $f14, $f4, $f8
/* F6CCC 802D231C 00000000 */  nop       
/* F6CD0 802D2320 E4420094 */  swc1      $f2, 0x94($v0)
/* F6CD4 802D2324 C6400028 */  lwc1      $f0, 0x28($s2)
/* F6CD8 802D2328 460C0000 */  add.s     $f0, $f0, $f12
/* F6CDC 802D232C 460E0001 */  sub.s     $f0, $f0, $f14
/* F6CE0 802D2330 460A2102 */  mul.s     $f4, $f4, $f10
/* F6CE4 802D2334 00000000 */  nop       
/* F6CE8 802D2338 4600040D */  trunc.w.s $f16, $f0
/* F6CEC 802D233C E6700088 */  swc1      $f16, 0x88($s3)
/* F6CF0 802D2340 C6400030 */  lwc1      $f0, 0x30($s2)
/* F6CF4 802D2344 46060001 */  sub.s     $f0, $f0, $f6
/* F6CF8 802D2348 3C038888 */  lui       $v1, 0x8888
/* F6CFC 802D234C 46040001 */  sub.s     $f0, $f0, $f4
/* F6D00 802D2350 34638889 */  ori       $v1, $v1, 0x8889
/* F6D04 802D2354 001127C3 */  sra       $a0, $s1, 0x1f
/* F6D08 802D2358 4600040D */  trunc.w.s $f16, $f0
/* F6D0C 802D235C E6700090 */  swc1      $f16, 0x90($s3)
/* F6D10 802D2360 8E820014 */  lw        $v0, 0x14($s4)
/* F6D14 802D2364 02230018 */  mult      $s1, $v1
/* F6D18 802D2368 02028021 */  addu      $s0, $s0, $v0
/* F6D1C 802D236C C6000004 */  lwc1      $f0, 4($s0)
/* F6D20 802D2370 24020002 */  addiu     $v0, $zero, 2
/* F6D24 802D2374 4600040D */  trunc.w.s $f16, $f0
/* F6D28 802D2378 E670008C */  swc1      $f16, 0x8c($s3)
/* F6D2C 802D237C 00004010 */  mfhi      $t0
/* F6D30 802D2380 01111821 */  addu      $v1, $t0, $s1
/* F6D34 802D2384 000318C3 */  sra       $v1, $v1, 3
/* F6D38 802D2388 00641823 */  subu      $v1, $v1, $a0
/* F6D3C 802D238C 44830000 */  mtc1      $v1, $f0
/* F6D40 802D2390 00000000 */  nop       
/* F6D44 802D2394 46800020 */  cvt.s.w   $f0, $f0
/* F6D48 802D2398 E6A00000 */  swc1      $f0, ($s5)
/* F6D4C 802D239C 8E430004 */  lw        $v1, 4($s2)
/* F6D50 802D23A0 3C040010 */  lui       $a0, 0x10
/* F6D54 802D23A4 00641825 */  or        $v1, $v1, $a0
/* F6D58 802D23A8 AE430004 */  sw        $v1, 4($s2)
/* F6D5C 802D23AC 8E430000 */  lw        $v1, ($s2)
/* F6D60 802D23B0 3C040400 */  lui       $a0, 0x400
/* F6D64 802D23B4 00641825 */  or        $v1, $v1, $a0
/* F6D68 802D23B8 AE430000 */  sw        $v1, ($s2)
.L802D23BC:
/* F6D6C 802D23BC 8FBF0030 */  lw        $ra, 0x30($sp)
/* F6D70 802D23C0 8FB5002C */  lw        $s5, 0x2c($sp)
/* F6D74 802D23C4 8FB40028 */  lw        $s4, 0x28($sp)
/* F6D78 802D23C8 8FB30024 */  lw        $s3, 0x24($sp)
/* F6D7C 802D23CC 8FB20020 */  lw        $s2, 0x20($sp)
/* F6D80 802D23D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* F6D84 802D23D4 8FB00018 */  lw        $s0, 0x18($sp)
/* F6D88 802D23D8 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* F6D8C 802D23DC D7BC0058 */  ldc1      $f28, 0x58($sp)
/* F6D90 802D23E0 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* F6D94 802D23E4 D7B80048 */  ldc1      $f24, 0x48($sp)
/* F6D98 802D23E8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* F6D9C 802D23EC D7B40038 */  ldc1      $f20, 0x38($sp)
/* F6DA0 802D23F0 03E00008 */  jr        $ra
/* F6DA4 802D23F4 27BD0068 */   addiu    $sp, $sp, 0x68

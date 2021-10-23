.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_117_update
/* 3E2078 E00EA198 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3E207C E00EA19C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3E2080 E00EA1A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 3E2084 E00EA1A4 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* 3E2088 E00EA1A8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 3E208C E00EA1AC F7B60020 */  sdc1      $f22, 0x20($sp)
/* 3E2090 E00EA1B0 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 3E2094 E00EA1B4 8C830000 */  lw        $v1, ($a0)
/* 3E2098 E00EA1B8 8C90000C */  lw        $s0, 0xc($a0)
/* 3E209C E00EA1BC 30620010 */  andi      $v0, $v1, 0x10
/* 3E20A0 E00EA1C0 10400005 */  beqz      $v0, .LE00EA1D8
/* 3E20A4 E00EA1C4 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3E20A8 E00EA1C8 00621024 */  and       $v0, $v1, $v0
/* 3E20AC E00EA1CC AC820000 */  sw        $v0, ($a0)
/* 3E20B0 E00EA1D0 24020010 */  addiu     $v0, $zero, 0x10
/* 3E20B4 E00EA1D4 AE020010 */  sw        $v0, 0x10($s0)
.LE00EA1D8:
/* 3E20B8 E00EA1D8 8E030010 */  lw        $v1, 0x10($s0)
/* 3E20BC E00EA1DC 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3E20C0 E00EA1E0 10400002 */  beqz      $v0, .LE00EA1EC
/* 3E20C4 E00EA1E4 2462FFFF */   addiu    $v0, $v1, -1
/* 3E20C8 E00EA1E8 AE020010 */  sw        $v0, 0x10($s0)
.LE00EA1EC:
/* 3E20CC E00EA1EC 3C030001 */  lui       $v1, 1
/* 3E20D0 E00EA1F0 8E020014 */  lw        $v0, 0x14($s0)
/* 3E20D4 E00EA1F4 3463A5E0 */  ori       $v1, $v1, 0xa5e0
/* 3E20D8 E00EA1F8 24420001 */  addiu     $v0, $v0, 1
/* 3E20DC E00EA1FC 0062182A */  slt       $v1, $v1, $v0
/* 3E20E0 E00EA200 10600002 */  beqz      $v1, .LE00EA20C
/* 3E20E4 E00EA204 AE020014 */   sw       $v0, 0x14($s0)
/* 3E20E8 E00EA208 AE000014 */  sw        $zero, 0x14($s0)
.LE00EA20C:
/* 3E20EC E00EA20C 8E030010 */  lw        $v1, 0x10($s0)
/* 3E20F0 E00EA210 04610005 */  bgez      $v1, .LE00EA228
/* 3E20F4 E00EA214 28620010 */   slti     $v0, $v1, 0x10
/* 3E20F8 E00EA218 0C080128 */  jal       shim_remove_effect
/* 3E20FC E00EA21C 00000000 */   nop
/* 3E2100 E00EA220 0803A940 */  j         .LE00EA500
/* 3E2104 E00EA224 00000000 */   nop
.LE00EA228:
/* 3E2108 E00EA228 8E040014 */  lw        $a0, 0x14($s0)
/* 3E210C E00EA22C 10400002 */  beqz      $v0, .LE00EA238
/* 3E2110 E00EA230 00031100 */   sll      $v0, $v1, 4
/* 3E2114 E00EA234 AE020024 */  sw        $v0, 0x24($s0)
.LE00EA238:
/* 3E2118 E00EA238 28820010 */  slti      $v0, $a0, 0x10
/* 3E211C E00EA23C 10400003 */  beqz      $v0, .LE00EA24C
/* 3E2120 E00EA240 00041100 */   sll      $v0, $a0, 4
/* 3E2124 E00EA244 2442000F */  addiu     $v0, $v0, 0xf
/* 3E2128 E00EA248 AE020024 */  sw        $v0, 0x24($s0)
.LE00EA24C:
/* 3E212C E00EA24C C6120048 */  lwc1      $f18, 0x48($s0)
/* 3E2130 E00EA250 C60E0068 */  lwc1      $f14, 0x68($s0)
/* 3E2134 E00EA254 46127381 */  sub.s     $f14, $f14, $f18
/* 3E2138 E00EA258 3C01E00F */  lui       $at, %hi(D_E00EAA60)
/* 3E213C E00EA25C D438AA60 */  ldc1      $f24, %lo(D_E00EAA60)($at)
/* 3E2140 E00EA260 460073A1 */  cvt.d.s   $f14, $f14
/* 3E2144 E00EA264 46387382 */  mul.d     $f14, $f14, $f24
/* 3E2148 E00EA268 00000000 */  nop
/* 3E214C E00EA26C C60C004C */  lwc1      $f12, 0x4c($s0)
/* 3E2150 E00EA270 C608006C */  lwc1      $f8, 0x6c($s0)
/* 3E2154 E00EA274 460C4201 */  sub.s     $f8, $f8, $f12
/* 3E2158 E00EA278 46004221 */  cvt.d.s   $f8, $f8
/* 3E215C E00EA27C 46384202 */  mul.d     $f8, $f8, $f24
/* 3E2160 E00EA280 00000000 */  nop
/* 3E2164 E00EA284 C60A0058 */  lwc1      $f10, 0x58($s0)
/* 3E2168 E00EA288 C6040070 */  lwc1      $f4, 0x70($s0)
/* 3E216C E00EA28C 460A2101 */  sub.s     $f4, $f4, $f10
/* 3E2170 E00EA290 46002121 */  cvt.d.s   $f4, $f4
/* 3E2174 E00EA294 46382102 */  mul.d     $f4, $f4, $f24
/* 3E2178 E00EA298 00000000 */  nop
/* 3E217C E00EA29C C610005C */  lwc1      $f16, 0x5c($s0)
/* 3E2180 E00EA2A0 C6060074 */  lwc1      $f6, 0x74($s0)
/* 3E2184 E00EA2A4 46103181 */  sub.s     $f6, $f6, $f16
/* 3E2188 E00EA2A8 460031A1 */  cvt.d.s   $f6, $f6
/* 3E218C E00EA2AC 46383182 */  mul.d     $f6, $f6, $f24
/* 3E2190 E00EA2B0 00000000 */  nop
/* 3E2194 E00EA2B4 C6140060 */  lwc1      $f20, 0x60($s0)
/* 3E2198 E00EA2B8 C6020078 */  lwc1      $f2, 0x78($s0)
/* 3E219C E00EA2BC 46141081 */  sub.s     $f2, $f2, $f20
/* 3E21A0 E00EA2C0 460010A1 */  cvt.d.s   $f2, $f2
/* 3E21A4 E00EA2C4 46381082 */  mul.d     $f2, $f2, $f24
/* 3E21A8 E00EA2C8 00000000 */  nop
/* 3E21AC E00EA2CC C6160064 */  lwc1      $f22, 0x64($s0)
/* 3E21B0 E00EA2D0 C600007C */  lwc1      $f0, 0x7c($s0)
/* 3E21B4 E00EA2D4 46160001 */  sub.s     $f0, $f0, $f22
/* 3E21B8 E00EA2D8 46000021 */  cvt.d.s   $f0, $f0
/* 3E21BC E00EA2DC 46380002 */  mul.d     $f0, $f0, $f24
/* 3E21C0 E00EA2E0 00000000 */  nop
/* 3E21C4 E00EA2E4 460094A1 */  cvt.d.s   $f18, $f18
/* 3E21C8 E00EA2E8 462E9480 */  add.d     $f18, $f18, $f14
/* 3E21CC E00EA2EC 46006321 */  cvt.d.s   $f12, $f12
/* 3E21D0 E00EA2F0 46286300 */  add.d     $f12, $f12, $f8
/* 3E21D4 E00EA2F4 460052A1 */  cvt.d.s   $f10, $f10
/* 3E21D8 E00EA2F8 46245280 */  add.d     $f10, $f10, $f4
/* 3E21DC E00EA2FC 46008421 */  cvt.d.s   $f16, $f16
/* 3E21E0 E00EA300 4600A521 */  cvt.d.s   $f20, $f20
/* 3E21E4 E00EA304 46268400 */  add.d     $f16, $f16, $f6
/* 3E21E8 E00EA308 4600B5A1 */  cvt.d.s   $f22, $f22
/* 3E21EC E00EA30C C6060040 */  lwc1      $f6, 0x40($s0)
/* 3E21F0 E00EA310 4622A500 */  add.d     $f20, $f20, $f2
/* 3E21F4 E00EA314 C6080044 */  lwc1      $f8, 0x44($s0)
/* 3E21F8 E00EA318 C6040050 */  lwc1      $f4, 0x50($s0)
/* 3E21FC E00EA31C 4620B580 */  add.d     $f22, $f22, $f0
/* 3E2200 E00EA320 462094A0 */  cvt.s.d   $f18, $f18
/* 3E2204 E00EA324 46206320 */  cvt.s.d   $f12, $f12
/* 3E2208 E00EA328 E6120048 */  swc1      $f18, 0x48($s0)
/* 3E220C E00EA32C 46009086 */  mov.s     $f2, $f18
/* 3E2210 E00EA330 46021080 */  add.s     $f2, $f2, $f2
/* 3E2214 E00EA334 E60C004C */  swc1      $f12, 0x4c($s0)
/* 3E2218 E00EA338 46006006 */  mov.s     $f0, $f12
/* 3E221C E00EA33C 46000000 */  add.s     $f0, $f0, $f0
/* 3E2220 E00EA340 462052A0 */  cvt.s.d   $f10, $f10
/* 3E2224 E00EA344 46208420 */  cvt.s.d   $f16, $f16
/* 3E2228 E00EA348 46023180 */  add.s     $f6, $f6, $f2
/* 3E222C E00EA34C 4620A520 */  cvt.s.d   $f20, $f20
/* 3E2230 E00EA350 4620B5A0 */  cvt.s.d   $f22, $f22
/* 3E2234 E00EA354 46004200 */  add.s     $f8, $f8, $f0
/* 3E2238 E00EA358 E60A0058 */  swc1      $f10, 0x58($s0)
/* 3E223C E00EA35C 46005006 */  mov.s     $f0, $f10
/* 3E2240 E00EA360 46000000 */  add.s     $f0, $f0, $f0
/* 3E2244 E00EA364 E610005C */  swc1      $f16, 0x5c($s0)
/* 3E2248 E00EA368 E6140060 */  swc1      $f20, 0x60($s0)
/* 3E224C E00EA36C 46002100 */  add.s     $f4, $f4, $f0
/* 3E2250 E00EA370 E6160064 */  swc1      $f22, 0x64($s0)
/* 3E2254 E00EA374 46008006 */  mov.s     $f0, $f16
/* 3E2258 E00EA378 46000000 */  add.s     $f0, $f0, $f0
/* 3E225C E00EA37C C6020054 */  lwc1      $f2, 0x54($s0)
/* 3E2260 E00EA380 44805000 */  mtc1      $zero, $f10
/* 3E2264 E00EA384 46001080 */  add.s     $f2, $f2, $f0
/* 3E2268 E00EA388 E6060040 */  swc1      $f6, 0x40($s0)
/* 3E226C E00EA38C E6080044 */  swc1      $f8, 0x44($s0)
/* 3E2270 E00EA390 460A303C */  c.lt.s    $f6, $f10
/* 3E2274 E00EA394 E6040050 */  swc1      $f4, 0x50($s0)
/* 3E2278 E00EA398 45000006 */  bc1f      .LE00EA3B4
/* 3E227C E00EA39C E6020054 */   swc1     $f2, 0x54($s0)
/* 3E2280 E00EA3A0 3C014380 */  lui       $at, 0x4380
/* 3E2284 E00EA3A4 44810000 */  mtc1      $at, $f0
/* 3E2288 E00EA3A8 00000000 */  nop
/* 3E228C E00EA3AC 46003000 */  add.s     $f0, $f6, $f0
/* 3E2290 E00EA3B0 E6000040 */  swc1      $f0, 0x40($s0)
.LE00EA3B4:
/* 3E2294 E00EA3B4 C6020044 */  lwc1      $f2, 0x44($s0)
/* 3E2298 E00EA3B8 460A103C */  c.lt.s    $f2, $f10
/* 3E229C E00EA3BC 00000000 */  nop
/* 3E22A0 E00EA3C0 45000006 */  bc1f      .LE00EA3DC
/* 3E22A4 E00EA3C4 00000000 */   nop
/* 3E22A8 E00EA3C8 3C014380 */  lui       $at, 0x4380
/* 3E22AC E00EA3CC 44810000 */  mtc1      $at, $f0
/* 3E22B0 E00EA3D0 00000000 */  nop
/* 3E22B4 E00EA3D4 46001000 */  add.s     $f0, $f2, $f0
/* 3E22B8 E00EA3D8 E6000044 */  swc1      $f0, 0x44($s0)
.LE00EA3DC:
/* 3E22BC E00EA3DC C6020050 */  lwc1      $f2, 0x50($s0)
/* 3E22C0 E00EA3E0 460A103C */  c.lt.s    $f2, $f10
/* 3E22C4 E00EA3E4 00000000 */  nop
/* 3E22C8 E00EA3E8 45000006 */  bc1f      .LE00EA404
/* 3E22CC E00EA3EC 00000000 */   nop
/* 3E22D0 E00EA3F0 3C014380 */  lui       $at, 0x4380
/* 3E22D4 E00EA3F4 44810000 */  mtc1      $at, $f0
/* 3E22D8 E00EA3F8 00000000 */  nop
/* 3E22DC E00EA3FC 46001000 */  add.s     $f0, $f2, $f0
/* 3E22E0 E00EA400 E6000050 */  swc1      $f0, 0x50($s0)
.LE00EA404:
/* 3E22E4 E00EA404 C6020054 */  lwc1      $f2, 0x54($s0)
/* 3E22E8 E00EA408 460A103C */  c.lt.s    $f2, $f10
/* 3E22EC E00EA40C 00000000 */  nop
/* 3E22F0 E00EA410 45000006 */  bc1f      .LE00EA42C
/* 3E22F4 E00EA414 00000000 */   nop
/* 3E22F8 E00EA418 3C014380 */  lui       $at, 0x4380
/* 3E22FC E00EA41C 44810000 */  mtc1      $at, $f0
/* 3E2300 E00EA420 00000000 */  nop
/* 3E2304 E00EA424 46001000 */  add.s     $f0, $f2, $f0
/* 3E2308 E00EA428 E6000054 */  swc1      $f0, 0x54($s0)
.LE00EA42C:
/* 3E230C E00EA42C C6000040 */  lwc1      $f0, 0x40($s0)
/* 3E2310 E00EA430 3C014380 */  lui       $at, 0x4380
/* 3E2314 E00EA434 44811000 */  mtc1      $at, $f2
/* 3E2318 E00EA438 00000000 */  nop
/* 3E231C E00EA43C 4600103C */  c.lt.s    $f2, $f0
/* 3E2320 E00EA440 00000000 */  nop
/* 3E2324 E00EA444 45000003 */  bc1f      .LE00EA454
/* 3E2328 E00EA448 00000000 */   nop
/* 3E232C E00EA44C 46020001 */  sub.s     $f0, $f0, $f2
/* 3E2330 E00EA450 E6000040 */  swc1      $f0, 0x40($s0)
.LE00EA454:
/* 3E2334 E00EA454 C6000044 */  lwc1      $f0, 0x44($s0)
/* 3E2338 E00EA458 4600103C */  c.lt.s    $f2, $f0
/* 3E233C E00EA45C 00000000 */  nop
/* 3E2340 E00EA460 45000003 */  bc1f      .LE00EA470
/* 3E2344 E00EA464 00000000 */   nop
/* 3E2348 E00EA468 46020001 */  sub.s     $f0, $f0, $f2
/* 3E234C E00EA46C E6000044 */  swc1      $f0, 0x44($s0)
.LE00EA470:
/* 3E2350 E00EA470 C6000050 */  lwc1      $f0, 0x50($s0)
/* 3E2354 E00EA474 4600103C */  c.lt.s    $f2, $f0
/* 3E2358 E00EA478 00000000 */  nop
/* 3E235C E00EA47C 45000003 */  bc1f      .LE00EA48C
/* 3E2360 E00EA480 00000000 */   nop
/* 3E2364 E00EA484 46020001 */  sub.s     $f0, $f0, $f2
/* 3E2368 E00EA488 E6000050 */  swc1      $f0, 0x50($s0)
.LE00EA48C:
/* 3E236C E00EA48C C6000054 */  lwc1      $f0, 0x54($s0)
/* 3E2370 E00EA490 4600103C */  c.lt.s    $f2, $f0
/* 3E2374 E00EA494 00000000 */  nop
/* 3E2378 E00EA498 45000003 */  bc1f      .LE00EA4A8
/* 3E237C E00EA49C 00041080 */   sll      $v0, $a0, 2
/* 3E2380 E00EA4A0 46020001 */  sub.s     $f0, $f0, $f2
/* 3E2384 E00EA4A4 E6000054 */  swc1      $f0, 0x54($s0)
.LE00EA4A8:
/* 3E2388 E00EA4A8 00441021 */  addu      $v0, $v0, $a0
/* 3E238C E00EA4AC 00021080 */  sll       $v0, $v0, 2
/* 3E2390 E00EA4B0 44826000 */  mtc1      $v0, $f12
/* 3E2394 E00EA4B4 00000000 */  nop
/* 3E2398 E00EA4B8 0C080140 */  jal       shim_sin_deg
/* 3E239C E00EA4BC 46806320 */   cvt.s.w  $f12, $f12
/* 3E23A0 E00EA4C0 C6040060 */  lwc1      $f4, 0x60($s0)
/* 3E23A4 E00EA4C4 C6020064 */  lwc1      $f2, 0x64($s0)
/* 3E23A8 E00EA4C8 46041081 */  sub.s     $f2, $f2, $f4
/* 3E23AC E00EA4CC 46020002 */  mul.s     $f0, $f0, $f2
/* 3E23B0 E00EA4D0 00000000 */  nop
/* 3E23B4 E00EA4D4 46020000 */  add.s     $f0, $f0, $f2
/* 3E23B8 E00EA4D8 3C013FE0 */  lui       $at, 0x3fe0
/* 3E23BC E00EA4DC 44811800 */  mtc1      $at, $f3
/* 3E23C0 E00EA4E0 44801000 */  mtc1      $zero, $f2
/* 3E23C4 E00EA4E4 46000021 */  cvt.d.s   $f0, $f0
/* 3E23C8 E00EA4E8 46220002 */  mul.d     $f0, $f0, $f2
/* 3E23CC E00EA4EC 00000000 */  nop
/* 3E23D0 E00EA4F0 46002121 */  cvt.d.s   $f4, $f4
/* 3E23D4 E00EA4F4 46202100 */  add.d     $f4, $f4, $f0
/* 3E23D8 E00EA4F8 4620268D */  trunc.w.d $f26, $f4
/* 3E23DC E00EA4FC E61A0034 */  swc1      $f26, 0x34($s0)
.LE00EA500:
/* 3E23E0 E00EA500 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3E23E4 E00EA504 8FB00010 */  lw        $s0, 0x10($sp)
/* 3E23E8 E00EA508 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* 3E23EC E00EA50C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 3E23F0 E00EA510 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 3E23F4 E00EA514 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 3E23F8 E00EA518 03E00008 */  jr        $ra
/* 3E23FC E00EA51C 27BD0038 */   addiu    $sp, $sp, 0x38

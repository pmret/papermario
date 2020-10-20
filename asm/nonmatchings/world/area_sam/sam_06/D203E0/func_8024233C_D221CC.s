.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024233C_D221CC
/* D221CC 8024233C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D221D0 80242340 AFB1001C */  sw        $s1, 0x1c($sp)
/* D221D4 80242344 0080882D */  daddu     $s1, $a0, $zero
/* D221D8 80242348 AFBF0034 */  sw        $ra, 0x34($sp)
/* D221DC 8024234C AFB60030 */  sw        $s6, 0x30($sp)
/* D221E0 80242350 AFB5002C */  sw        $s5, 0x2c($sp)
/* D221E4 80242354 AFB40028 */  sw        $s4, 0x28($sp)
/* D221E8 80242358 AFB30024 */  sw        $s3, 0x24($sp)
/* D221EC 8024235C AFB20020 */  sw        $s2, 0x20($sp)
/* D221F0 80242360 AFB00018 */  sw        $s0, 0x18($sp)
/* D221F4 80242364 F7B60040 */  sdc1      $f22, 0x40($sp)
/* D221F8 80242368 F7B40038 */  sdc1      $f20, 0x38($sp)
/* D221FC 8024236C 8E30000C */  lw        $s0, 0xc($s1)
/* D22200 80242370 8E160000 */  lw        $s6, ($s0)
/* D22204 80242374 26100004 */  addiu     $s0, $s0, 4
/* D22208 80242378 0C0B1EAF */  jal       get_variable
/* D2220C 8024237C 02C0282D */   daddu    $a1, $s6, $zero
/* D22210 80242380 44820000 */  mtc1      $v0, $f0
/* D22214 80242384 00000000 */  nop       
/* D22218 80242388 46800020 */  cvt.s.w   $f0, $f0
/* D2221C 8024238C E7A00010 */  swc1      $f0, 0x10($sp)
/* D22220 80242390 8E140000 */  lw        $s4, ($s0)
/* D22224 80242394 26100004 */  addiu     $s0, $s0, 4
/* D22228 80242398 0220202D */  daddu     $a0, $s1, $zero
/* D2222C 8024239C 0C0B1EAF */  jal       get_variable
/* D22230 802423A0 0280282D */   daddu    $a1, $s4, $zero
/* D22234 802423A4 0220202D */  daddu     $a0, $s1, $zero
/* D22238 802423A8 8E150000 */  lw        $s5, ($s0)
/* D2223C 802423AC 4482B000 */  mtc1      $v0, $f22
/* D22240 802423B0 00000000 */  nop       
/* D22244 802423B4 4680B5A0 */  cvt.s.w   $f22, $f22
/* D22248 802423B8 0C0B1EAF */  jal       get_variable
/* D2224C 802423BC 02A0282D */   daddu    $a1, $s5, $zero
/* D22250 802423C0 2404FFFC */  addiu     $a0, $zero, -4
/* D22254 802423C4 44820000 */  mtc1      $v0, $f0
/* D22258 802423C8 00000000 */  nop       
/* D2225C 802423CC 46800020 */  cvt.s.w   $f0, $f0
/* D22260 802423D0 0C00EABB */  jal       get_npc_unsafe
/* D22264 802423D4 E7A00014 */   swc1     $f0, 0x14($sp)
/* D22268 802423D8 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* D2226C 802423DC 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* D22270 802423E0 3C014334 */  lui       $at, 0x4334
/* D22274 802423E4 44816000 */  mtc1      $at, $f12
/* D22278 802423E8 00041880 */  sll       $v1, $a0, 2
/* D2227C 802423EC 00641821 */  addu      $v1, $v1, $a0
/* D22280 802423F0 00031880 */  sll       $v1, $v1, 2
/* D22284 802423F4 00641823 */  subu      $v1, $v1, $a0
/* D22288 802423F8 000320C0 */  sll       $a0, $v1, 3
/* D2228C 802423FC 00641821 */  addu      $v1, $v1, $a0
/* D22290 80242400 000318C0 */  sll       $v1, $v1, 3
/* D22294 80242404 3C01800B */  lui       $at, 0x800b
/* D22298 80242408 00230821 */  addu      $at, $at, $v1
/* D2229C 8024240C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* D222A0 80242410 460C0300 */  add.s     $f12, $f0, $f12
/* D222A4 80242414 0C00A6C9 */  jal       clamp_angle
/* D222A8 80242418 0040982D */   daddu    $s3, $v0, $zero
/* D222AC 8024241C 27B00010 */  addiu     $s0, $sp, 0x10
/* D222B0 80242420 0200202D */  daddu     $a0, $s0, $zero
/* D222B4 80242424 27B20014 */  addiu     $s2, $sp, 0x14
/* D222B8 80242428 0240282D */  daddu     $a1, $s2, $zero
/* D222BC 8024242C 3C064170 */  lui       $a2, 0x4170
/* D222C0 80242430 8E67000C */  lw        $a3, 0xc($s3)
/* D222C4 80242434 0C00A7E7 */  jal       add_vec2D_polar
/* D222C8 80242438 46000506 */   mov.s    $f20, $f0
/* D222CC 8024243C 0200202D */  daddu     $a0, $s0, $zero
/* D222D0 80242440 3C064120 */  lui       $a2, 0x4120
/* D222D4 80242444 4407A000 */  mfc1      $a3, $f20
/* D222D8 80242448 0C00A7E7 */  jal       add_vec2D_polar
/* D222DC 8024244C 0240282D */   daddu    $a1, $s2, $zero
/* D222E0 80242450 0220202D */  daddu     $a0, $s1, $zero
/* D222E4 80242454 C7A00010 */  lwc1      $f0, 0x10($sp)
/* D222E8 80242458 4600008D */  trunc.w.s $f2, $f0
/* D222EC 8024245C 44061000 */  mfc1      $a2, $f2
/* D222F0 80242460 0C0B2026 */  jal       set_variable
/* D222F4 80242464 02C0282D */   daddu    $a1, $s6, $zero
/* D222F8 80242468 0220202D */  daddu     $a0, $s1, $zero
/* D222FC 8024246C 4600B08D */  trunc.w.s $f2, $f22
/* D22300 80242470 44061000 */  mfc1      $a2, $f2
/* D22304 80242474 0C0B2026 */  jal       set_variable
/* D22308 80242478 0280282D */   daddu    $a1, $s4, $zero
/* D2230C 8024247C 0220202D */  daddu     $a0, $s1, $zero
/* D22310 80242480 C7A00014 */  lwc1      $f0, 0x14($sp)
/* D22314 80242484 4600008D */  trunc.w.s $f2, $f0
/* D22318 80242488 44061000 */  mfc1      $a2, $f2
/* D2231C 8024248C 0C0B2026 */  jal       set_variable
/* D22320 80242490 02A0282D */   daddu    $a1, $s5, $zero
/* D22324 80242494 8FBF0034 */  lw        $ra, 0x34($sp)
/* D22328 80242498 8FB60030 */  lw        $s6, 0x30($sp)
/* D2232C 8024249C 8FB5002C */  lw        $s5, 0x2c($sp)
/* D22330 802424A0 8FB40028 */  lw        $s4, 0x28($sp)
/* D22334 802424A4 8FB30024 */  lw        $s3, 0x24($sp)
/* D22338 802424A8 8FB20020 */  lw        $s2, 0x20($sp)
/* D2233C 802424AC 8FB1001C */  lw        $s1, 0x1c($sp)
/* D22340 802424B0 8FB00018 */  lw        $s0, 0x18($sp)
/* D22344 802424B4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* D22348 802424B8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* D2234C 802424BC 24020002 */  addiu     $v0, $zero, 2
/* D22350 802424C0 03E00008 */  jr        $ra
/* D22354 802424C4 27BD0048 */   addiu    $sp, $sp, 0x48

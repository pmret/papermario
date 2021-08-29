.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel IdleRunToGoal
/* 1A8B44 8027A264 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 1A8B48 8027A268 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A8B4C 8027A26C 0080902D */  daddu     $s2, $a0, $zero
/* 1A8B50 8027A270 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A8B54 8027A274 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A8B58 8027A278 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A8B5C 8027A27C F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 1A8B60 8027A280 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 1A8B64 8027A284 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 1A8B68 8027A288 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 1A8B6C 8027A28C 8E51000C */  lw        $s1, 0xc($s2)
/* 1A8B70 8027A290 54A00001 */  bnel      $a1, $zero, .L8027A298
/* 1A8B74 8027A294 AE400070 */   sw       $zero, 0x70($s2)
.L8027A298:
/* 1A8B78 8027A298 8E420070 */  lw        $v0, 0x70($s2)
/* 1A8B7C 8027A29C 14400055 */  bnez      $v0, .L8027A3F4
/* 1A8B80 8027A2A0 00000000 */   nop
/* 1A8B84 8027A2A4 8E250000 */  lw        $a1, ($s1)
/* 1A8B88 8027A2A8 26310004 */  addiu     $s1, $s1, 4
/* 1A8B8C 8027A2AC 0C0B1EAF */  jal       evt_get_variable
/* 1A8B90 8027A2B0 0240202D */   daddu    $a0, $s2, $zero
/* 1A8B94 8027A2B4 0040202D */  daddu     $a0, $v0, $zero
/* 1A8B98 8027A2B8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1A8B9C 8027A2BC 14820002 */  bne       $a0, $v0, .L8027A2C8
/* 1A8BA0 8027A2C0 00000000 */   nop
/* 1A8BA4 8027A2C4 8E440148 */  lw        $a0, 0x148($s2)
.L8027A2C8:
/* 1A8BA8 8027A2C8 0C09A75B */  jal       get_actor
/* 1A8BAC 8027A2CC 00000000 */   nop
/* 1A8BB0 8027A2D0 0040802D */  daddu     $s0, $v0, $zero
/* 1A8BB4 8027A2D4 AE500074 */  sw        $s0, 0x74($s2)
/* 1A8BB8 8027A2D8 8E250000 */  lw        $a1, ($s1)
/* 1A8BBC 8027A2DC 0C0B1EAF */  jal       evt_get_variable
/* 1A8BC0 8027A2E0 0240202D */   daddu    $a0, $s2, $zero
/* 1A8BC4 8027A2E4 C61600D4 */  lwc1      $f22, 0xd4($s0)
/* 1A8BC8 8027A2E8 C61800DC */  lwc1      $f24, 0xdc($s0)
/* 1A8BCC 8027A2EC C6000144 */  lwc1      $f0, 0x144($s0)
/* 1A8BD0 8027A2F0 C614014C */  lwc1      $f20, 0x14c($s0)
/* 1A8BD4 8027A2F4 C60200D8 */  lwc1      $f2, 0xd8($s0)
/* 1A8BD8 8027A2F8 4406B000 */  mfc1      $a2, $f22
/* 1A8BDC 8027A2FC 4407C000 */  mfc1      $a3, $f24
/* 1A8BE0 8027A300 261100C8 */  addiu     $s1, $s0, 0xc8
/* 1A8BE4 8027A304 A6020120 */  sh        $v0, 0x120($s0)
/* 1A8BE8 8027A308 E60000C8 */  swc1      $f0, 0xc8($s0)
/* 1A8BEC 8027A30C C6000148 */  lwc1      $f0, 0x148($s0)
/* 1A8BF0 8027A310 C61A00C8 */  lwc1      $f26, 0xc8($s0)
/* 1A8BF4 8027A314 4600A386 */  mov.s     $f14, $f20
/* 1A8BF8 8027A318 E61400D0 */  swc1      $f20, 0xd0($s0)
/* 1A8BFC 8027A31C E61600E0 */  swc1      $f22, 0xe0($s0)
/* 1A8C00 8027A320 E60200E4 */  swc1      $f2, 0xe4($s0)
/* 1A8C04 8027A324 E61800E8 */  swc1      $f24, 0xe8($s0)
/* 1A8C08 8027A328 4600D306 */  mov.s     $f12, $f26
/* 1A8C0C 8027A32C 0C00A720 */  jal       atan2
/* 1A8C10 8027A330 E60000CC */   swc1     $f0, 0xcc($s0)
/* 1A8C14 8027A334 4600D306 */  mov.s     $f12, $f26
/* 1A8C18 8027A338 4406B000 */  mfc1      $a2, $f22
/* 1A8C1C 8027A33C 4407C000 */  mfc1      $a3, $f24
/* 1A8C20 8027A340 4600A386 */  mov.s     $f14, $f20
/* 1A8C24 8027A344 0C00A7B5 */  jal       dist2D
/* 1A8C28 8027A348 E6000110 */   swc1     $f0, 0x110($s0)
/* 1A8C2C 8027A34C 86020120 */  lh        $v0, 0x120($s0)
/* 1A8C30 8027A350 46000086 */  mov.s     $f2, $f0
/* 1A8C34 8027A354 14400018 */  bnez      $v0, .L8027A3B8
/* 1A8C38 8027A358 E6020114 */   swc1     $f2, 0x114($s0)
/* 1A8C3C 8027A35C C6000108 */  lwc1      $f0, 0x108($s0)
/* 1A8C40 8027A360 46001003 */  div.s     $f0, $f2, $f0
/* 1A8C44 8027A364 4600020D */  trunc.w.s $f8, $f0
/* 1A8C48 8027A368 44024000 */  mfc1      $v0, $f8
/* 1A8C4C 8027A36C 00000000 */  nop
/* 1A8C50 8027A370 A6020120 */  sh        $v0, 0x120($s0)
/* 1A8C54 8027A374 00021400 */  sll       $v0, $v0, 0x10
/* 1A8C58 8027A378 14400002 */  bnez      $v0, .L8027A384
/* 1A8C5C 8027A37C 24020001 */   addiu    $v0, $zero, 1
/* 1A8C60 8027A380 A6020120 */  sh        $v0, 0x120($s0)
.L8027A384:
/* 1A8C64 8027A384 86020120 */  lh        $v0, 0x120($s0)
/* 1A8C68 8027A388 C6020108 */  lwc1      $f2, 0x108($s0)
/* 1A8C6C 8027A38C 44823000 */  mtc1      $v0, $f6
/* 1A8C70 8027A390 00000000 */  nop
/* 1A8C74 8027A394 468031A0 */  cvt.s.w   $f6, $f6
/* 1A8C78 8027A398 46023102 */  mul.s     $f4, $f6, $f2
/* 1A8C7C 8027A39C 00000000 */  nop
/* 1A8C80 8027A3A0 C6000114 */  lwc1      $f0, 0x114($s0)
/* 1A8C84 8027A3A4 46040001 */  sub.s     $f0, $f0, $f4
/* 1A8C88 8027A3A8 46060003 */  div.s     $f0, $f0, $f6
/* 1A8C8C 8027A3AC 46001080 */  add.s     $f2, $f2, $f0
/* 1A8C90 8027A3B0 0809E8F3 */  j         .L8027A3CC
/* 1A8C94 8027A3B4 E6020108 */   swc1     $f2, 0x108($s0)
.L8027A3B8:
/* 1A8C98 8027A3B8 44820000 */  mtc1      $v0, $f0
/* 1A8C9C 8027A3BC 00000000 */  nop
/* 1A8CA0 8027A3C0 46800020 */  cvt.s.w   $f0, $f0
/* 1A8CA4 8027A3C4 46001003 */  div.s     $f0, $f2, $f0
/* 1A8CA8 8027A3C8 E6000108 */  swc1      $f0, 0x108($s0)
.L8027A3CC:
/* 1A8CAC 8027A3CC 860201B4 */  lh        $v0, 0x1b4($s0)
/* 1A8CB0 8027A3D0 04420002 */  bltzl     $v0, .L8027A3DC
/* 1A8CB4 8027A3D4 00021027 */   nor      $v0, $zero, $v0
/* 1A8CB8 8027A3D8 24420001 */  addiu     $v0, $v0, 1
.L8027A3DC:
/* 1A8CBC 8027A3DC 44820000 */  mtc1      $v0, $f0
/* 1A8CC0 8027A3E0 00000000 */  nop
/* 1A8CC4 8027A3E4 46800020 */  cvt.s.w   $f0, $f0
/* 1A8CC8 8027A3E8 E620004C */  swc1      $f0, 0x4c($s1)
/* 1A8CCC 8027A3EC 24020001 */  addiu     $v0, $zero, 1
/* 1A8CD0 8027A3F0 AE420070 */  sw        $v0, 0x70($s2)
.L8027A3F4:
/* 1A8CD4 8027A3F4 8E500074 */  lw        $s0, 0x74($s2)
/* 1A8CD8 8027A3F8 261100C8 */  addiu     $s1, $s0, 0xc8
/* 1A8CDC 8027A3FC 8E050108 */  lw        $a1, 0x108($s0)
/* 1A8CE0 8027A400 8E060110 */  lw        $a2, 0x110($s0)
/* 1A8CE4 8027A404 0C099096 */  jal       add_xz_vec3f_copy2
/* 1A8CE8 8027A408 0220202D */   daddu    $a0, $s1, $zero
/* 1A8CEC 8027A40C C6020108 */  lwc1      $f2, 0x108($s0)
/* 1A8CF0 8027A410 3C014080 */  lui       $at, 0x4080
/* 1A8CF4 8027A414 44810000 */  mtc1      $at, $f0
/* 1A8CF8 8027A418 00000000 */  nop
/* 1A8CFC 8027A41C 4600103C */  c.lt.s    $f2, $f0
/* 1A8D00 8027A420 00000000 */  nop
/* 1A8D04 8027A424 45000007 */  bc1f      .L8027A444
/* 1A8D08 8027A428 0000202D */   daddu    $a0, $zero, $zero
/* 1A8D0C 8027A42C C6000110 */  lwc1      $f0, 0x110($s0)
/* 1A8D10 8027A430 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A8D14 8027A434 8E0500C8 */  lw        $a1, 0xc8($s0)
/* 1A8D18 8027A438 8E0600CC */  lw        $a2, 0xcc($s0)
/* 1A8D1C 8027A43C 0809E917 */  j         .L8027A45C
/* 1A8D20 8027A440 8E0700D0 */   lw       $a3, 0xd0($s0)
.L8027A444:
/* 1A8D24 8027A444 C6000110 */  lwc1      $f0, 0x110($s0)
/* 1A8D28 8027A448 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A8D2C 8027A44C 8E0500C8 */  lw        $a1, 0xc8($s0)
/* 1A8D30 8027A450 8E0600CC */  lw        $a2, 0xcc($s0)
/* 1A8D34 8027A454 8E0700D0 */  lw        $a3, 0xd0($s0)
/* 1A8D38 8027A458 24040001 */  addiu     $a0, $zero, 1
.L8027A45C:
/* 1A8D3C 8027A45C 0C0990BC */  jal       play_movement_dust_effects
/* 1A8D40 8027A460 00000000 */   nop
/* 1A8D44 8027A464 C6200000 */  lwc1      $f0, ($s1)
/* 1A8D48 8027A468 E6000144 */  swc1      $f0, 0x144($s0)
/* 1A8D4C 8027A46C C6200008 */  lwc1      $f0, 8($s1)
/* 1A8D50 8027A470 E600014C */  swc1      $f0, 0x14c($s0)
/* 1A8D54 8027A474 96220058 */  lhu       $v0, 0x58($s1)
/* 1A8D58 8027A478 2442FFFF */  addiu     $v0, $v0, -1
/* 1A8D5C 8027A47C A6220058 */  sh        $v0, 0x58($s1)
/* 1A8D60 8027A480 00021400 */  sll       $v0, $v0, 0x10
/* 1A8D64 8027A484 1C40000D */  bgtz      $v0, .L8027A4BC
/* 1A8D68 8027A488 0000102D */   daddu    $v0, $zero, $zero
/* 1A8D6C 8027A48C C6200018 */  lwc1      $f0, 0x18($s1)
/* 1A8D70 8027A490 8E04019C */  lw        $a0, 0x19c($s0)
/* 1A8D74 8027A494 E6000144 */  swc1      $f0, 0x144($s0)
/* 1A8D78 8027A498 C6200020 */  lwc1      $f0, 0x20($s1)
/* 1A8D7C 8027A49C 10800006 */  beqz      $a0, .L8027A4B8
/* 1A8D80 8027A4A0 E600014C */   swc1     $f0, 0x14c($s0)
/* 1A8D84 8027A4A4 8E0201A0 */  lw        $v0, 0x1a0($s0)
/* 1A8D88 8027A4A8 14400004 */  bnez      $v0, .L8027A4BC
/* 1A8D8C 8027A4AC 24020001 */   addiu    $v0, $zero, 1
/* 1A8D90 8027A4B0 0C0154F0 */  jal       snd_stop_sound
/* 1A8D94 8027A4B4 00000000 */   nop
.L8027A4B8:
/* 1A8D98 8027A4B8 24020001 */  addiu     $v0, $zero, 1
.L8027A4BC:
/* 1A8D9C 8027A4BC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A8DA0 8027A4C0 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A8DA4 8027A4C4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A8DA8 8027A4C8 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A8DAC 8027A4CC D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 1A8DB0 8027A4D0 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 1A8DB4 8027A4D4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 1A8DB8 8027A4D8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1A8DBC 8027A4DC 03E00008 */  jr        $ra
/* 1A8DC0 8027A4E0 27BD0048 */   addiu    $sp, $sp, 0x48

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008E204
/* 38F064 E008E204 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 38F068 E008E208 AFB3001C */  sw        $s3, 0x1c($sp)
/* 38F06C E008E20C 0080982D */  daddu     $s3, $a0, $zero
/* 38F070 E008E210 AFBF0020 */  sw        $ra, 0x20($sp)
/* 38F074 E008E214 AFB20018 */  sw        $s2, 0x18($sp)
/* 38F078 E008E218 AFB10014 */  sw        $s1, 0x14($sp)
/* 38F07C E008E21C AFB00010 */  sw        $s0, 0x10($sp)
/* 38F080 E008E220 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 38F084 E008E224 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 38F088 E008E228 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 38F08C E008E22C F7B80038 */  sdc1      $f24, 0x38($sp)
/* 38F090 E008E230 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 38F094 E008E234 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 38F098 E008E238 8E64000C */  lw        $a0, 0xc($s3)
/* 38F09C E008E23C 8C830018 */  lw        $v1, 0x18($a0)
/* 38F0A0 E008E240 28620064 */  slti      $v0, $v1, 0x64
/* 38F0A4 E008E244 10400002 */  beqz      $v0, .LE008E250
/* 38F0A8 E008E248 2462FFFF */   addiu    $v0, $v1, -1
/* 38F0AC E008E24C AC820018 */  sw        $v0, 0x18($a0)
.LE008E250:
/* 38F0B0 E008E250 8C82001C */  lw        $v0, 0x1c($a0)
/* 38F0B4 E008E254 8C830018 */  lw        $v1, 0x18($a0)
/* 38F0B8 E008E258 24420001 */  addiu     $v0, $v0, 1
/* 38F0BC E008E25C 04610005 */  bgez      $v1, .LE008E274
/* 38F0C0 E008E260 AC82001C */   sw       $v0, 0x1c($a0)
/* 38F0C4 E008E264 0C080128 */  jal       func_E02004A0
/* 38F0C8 E008E268 0260202D */   daddu    $a0, $s3, $zero
/* 38F0CC E008E26C 08023919 */  j         .LE008E464
/* 38F0D0 E008E270 00000000 */   nop
.LE008E274:
/* 38F0D4 E008E274 0040182D */  daddu     $v1, $v0, $zero
/* 38F0D8 E008E278 28620015 */  slti      $v0, $v1, 0x15
/* 38F0DC E008E27C 10400004 */  beqz      $v0, .LE008E290
/* 38F0E0 E008E280 00031040 */   sll      $v0, $v1, 1
/* 38F0E4 E008E284 00431021 */  addu      $v0, $v0, $v1
/* 38F0E8 E008E288 080238A5 */  j         .LE008E294
/* 38F0EC E008E28C 00021080 */   sll      $v0, $v0, 2
.LE008E290:
/* 38F0F0 E008E290 240200FF */  addiu     $v0, $zero, 0xff
.LE008E294:
/* 38F0F4 E008E294 AC820014 */  sw        $v0, 0x14($a0)
/* 38F0F8 E008E298 30620001 */  andi      $v0, $v1, 1
/* 38F0FC E008E29C 1040000A */  beqz      $v0, .LE008E2C8
/* 38F100 E008E2A0 00000000 */   nop
/* 38F104 E008E2A4 3C013FE0 */  lui       $at, 0x3fe0
/* 38F108 E008E2A8 44811800 */  mtc1      $at, $f3
/* 38F10C E008E2AC 44801000 */  mtc1      $zero, $f2
/* 38F110 E008E2B0 C4800014 */  lwc1      $f0, 0x14($a0)
/* 38F114 E008E2B4 46800021 */  cvt.d.w   $f0, $f0
/* 38F118 E008E2B8 46220002 */  mul.d     $f0, $f0, $f2
/* 38F11C E008E2BC 00000000 */  nop
/* 38F120 E008E2C0 4620018D */  trunc.w.d $f6, $f0
/* 38F124 E008E2C4 E4860014 */  swc1      $f6, 0x14($a0)
.LE008E2C8:
/* 38F128 E008E2C8 8C83001C */  lw        $v1, 0x1c($a0)
/* 38F12C E008E2CC 8E620008 */  lw        $v0, 8($s3)
/* 38F130 E008E2D0 24110001 */  addiu     $s1, $zero, 1
/* 38F134 E008E2D4 0222102A */  slt       $v0, $s1, $v0
/* 38F138 E008E2D8 10400062 */  beqz      $v0, .LE008E464
/* 38F13C E008E2DC 24840048 */   addiu    $a0, $a0, 0x48
/* 38F140 E008E2E0 00719024 */  and       $s2, $v1, $s1
/* 38F144 E008E2E4 24900024 */  addiu     $s0, $a0, 0x24
/* 38F148 E008E2E8 4480E000 */  mtc1      $zero, $f28
/* 38F14C E008E2EC 3C014000 */  lui       $at, 0x4000
/* 38F150 E008E2F0 4481F000 */  mtc1      $at, $f30
.LE008E2F4:
/* 38F154 E008E2F4 C614FFFC */  lwc1      $f20, -4($s0)
/* 38F158 E008E2F8 C6180008 */  lwc1      $f24, 8($s0)
/* 38F15C E008E2FC C61A0000 */  lwc1      $f26, ($s0)
/* 38F160 E008E300 0C080140 */  jal       func_E0200500
/* 38F164 E008E304 4600A306 */   mov.s    $f12, $f20
/* 38F168 E008E308 4600A306 */  mov.s     $f12, $f20
/* 38F16C E008E30C 0C080144 */  jal       func_E0200510
/* 38F170 E008E310 46000586 */   mov.s    $f22, $f0
/* 38F174 E008E314 4600D306 */  mov.s     $f12, $f26
/* 38F178 E008E318 0C080140 */  jal       func_E0200500
/* 38F17C E008E31C 46000506 */   mov.s    $f20, $f0
/* 38F180 E008E320 4600D306 */  mov.s     $f12, $f26
/* 38F184 E008E324 0C080144 */  jal       func_E0200510
/* 38F188 E008E328 46000686 */   mov.s    $f26, $f0
/* 38F18C E008E32C 4616C582 */  mul.s     $f22, $f24, $f22
/* 38F190 E008E330 00000000 */  nop
/* 38F194 E008E334 4614C502 */  mul.s     $f20, $f24, $f20
/* 38F198 E008E338 00000000 */  nop
/* 38F19C E008E33C 461AC602 */  mul.s     $f24, $f24, $f26
/* 38F1A0 E008E340 00000000 */  nop
/* 38F1A4 E008E344 4600B582 */  mul.s     $f22, $f22, $f0
/* 38F1A8 E008E348 00000000 */  nop
/* 38F1AC E008E34C 4600A502 */  mul.s     $f20, $f20, $f0
/* 38F1B0 E008E350 00000000 */  nop
/* 38F1B4 E008E354 3C0142C8 */  lui       $at, 0x42c8
/* 38F1B8 E008E358 44813000 */  mtc1      $at, $f6
/* 38F1BC E008E35C C6000008 */  lwc1      $f0, 8($s0)
/* 38F1C0 E008E360 46003001 */  sub.s     $f0, $f6, $f0
/* 38F1C4 E008E364 3C01437F */  lui       $at, 0x437f
/* 38F1C8 E008E368 44811000 */  mtc1      $at, $f2
/* 38F1CC E008E36C 00000000 */  nop
/* 38F1D0 E008E370 46020002 */  mul.s     $f0, $f0, $f2
/* 38F1D4 E008E374 00000000 */  nop
/* 38F1D8 E008E378 E618FFEC */  swc1      $f24, -0x14($s0)
/* 38F1DC E008E37C 46000000 */  add.s     $f0, $f0, $f0
/* 38F1E0 E008E380 E616FFE4 */  swc1      $f22, -0x1c($s0)
/* 38F1E4 E008E384 E614FFE8 */  swc1      $f20, -0x18($s0)
/* 38F1E8 E008E388 46060003 */  div.s     $f0, $f0, $f6
/* 38F1EC E008E38C 4600018D */  trunc.w.s $f6, $f0
/* 38F1F0 E008E390 44023000 */  mfc1      $v0, $f6
/* 38F1F4 E008E394 00000000 */  nop
/* 38F1F8 E008E398 AE02FFF0 */  sw        $v0, -0x10($s0)
/* 38F1FC E008E39C 28420100 */  slti      $v0, $v0, 0x100
/* 38F200 E008E3A0 14400004 */  bnez      $v0, .LE008E3B4
/* 38F204 E008E3A4 32220003 */   andi     $v0, $s1, 3
/* 38F208 E008E3A8 240200FF */  addiu     $v0, $zero, 0xff
/* 38F20C E008E3AC AE02FFF0 */  sw        $v0, -0x10($s0)
/* 38F210 E008E3B0 32220003 */  andi      $v0, $s1, 3
.LE008E3B4:
/* 38F214 E008E3B4 00021040 */  sll       $v0, $v0, 1
/* 38F218 E008E3B8 C6000008 */  lwc1      $f0, 8($s0)
/* 38F21C E008E3BC 3C0142A0 */  lui       $at, 0x42a0
/* 38F220 E008E3C0 44811000 */  mtc1      $at, $f2
/* 38F224 E008E3C4 24420002 */  addiu     $v0, $v0, 2
/* 38F228 E008E3C8 46020003 */  div.s     $f0, $f0, $f2
/* 38F22C E008E3CC 3C01E009 */  lui       $at, %hi(D_E008E8A0)
/* 38F230 E008E3D0 D422E8A0 */  ldc1      $f2, %lo(D_E008E8A0)($at)
/* 38F234 E008E3D4 46000021 */  cvt.d.s   $f0, $f0
/* 38F238 E008E3D8 46220000 */  add.d     $f0, $f0, $f2
/* 38F23C E008E3DC C6040008 */  lwc1      $f4, 8($s0)
/* 38F240 E008E3E0 44821000 */  mtc1      $v0, $f2
/* 38F244 E008E3E4 00000000 */  nop
/* 38F248 E008E3E8 468010A0 */  cvt.s.w   $f2, $f2
/* 38F24C E008E3EC 46022101 */  sub.s     $f4, $f4, $f2
/* 38F250 E008E3F0 46200020 */  cvt.s.d   $f0, $f0
/* 38F254 E008E3F4 461C203C */  c.lt.s    $f4, $f28
/* 38F258 E008E3F8 E6000004 */  swc1      $f0, 4($s0)
/* 38F25C E008E3FC 45000003 */  bc1f      .LE008E40C
/* 38F260 E008E400 E6040008 */   swc1     $f4, 8($s0)
/* 38F264 E008E404 E61C0008 */  swc1      $f28, 8($s0)
/* 38F268 E008E408 E61C0004 */  swc1      $f28, 4($s0)
.LE008E40C:
/* 38F26C E008E40C C600FFFC */  lwc1      $f0, -4($s0)
/* 38F270 E008E410 52400005 */  beql      $s2, $zero, .LE008E428
/* 38F274 E008E414 461E0000 */   add.s    $f0, $f0, $f30
/* 38F278 E008E418 3C0140A0 */  lui       $at, 0x40a0
/* 38F27C E008E41C 44813000 */  mtc1      $at, $f6
/* 38F280 E008E420 00000000 */  nop
/* 38F284 E008E424 46060000 */  add.s     $f0, $f0, $f6
.LE008E428:
/* 38F288 E008E428 E600FFFC */  swc1      $f0, -4($s0)
/* 38F28C E008E42C 12400003 */  beqz      $s2, .LE008E43C
/* 38F290 E008E430 C6000000 */   lwc1     $f0, ($s0)
/* 38F294 E008E434 08023913 */  j         .LE008E44C
/* 38F298 E008E438 461E0000 */   add.s    $f0, $f0, $f30
.LE008E43C:
/* 38F29C E008E43C 3C0140A0 */  lui       $at, 0x40a0
/* 38F2A0 E008E440 44813000 */  mtc1      $at, $f6
/* 38F2A4 E008E444 00000000 */  nop
/* 38F2A8 E008E448 46060000 */  add.s     $f0, $f0, $f6
.LE008E44C:
/* 38F2AC E008E44C E6000000 */  swc1      $f0, ($s0)
/* 38F2B0 E008E450 26310001 */  addiu     $s1, $s1, 1
/* 38F2B4 E008E454 8E620008 */  lw        $v0, 8($s3)
/* 38F2B8 E008E458 0222102A */  slt       $v0, $s1, $v0
/* 38F2BC E008E45C 1440FFA5 */  bnez      $v0, .LE008E2F4
/* 38F2C0 E008E460 26100048 */   addiu    $s0, $s0, 0x48
.LE008E464:
/* 38F2C4 E008E464 8FBF0020 */  lw        $ra, 0x20($sp)
/* 38F2C8 E008E468 8FB3001C */  lw        $s3, 0x1c($sp)
/* 38F2CC E008E46C 8FB20018 */  lw        $s2, 0x18($sp)
/* 38F2D0 E008E470 8FB10014 */  lw        $s1, 0x14($sp)
/* 38F2D4 E008E474 8FB00010 */  lw        $s0, 0x10($sp)
/* 38F2D8 E008E478 D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 38F2DC E008E47C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 38F2E0 E008E480 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 38F2E4 E008E484 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 38F2E8 E008E488 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 38F2EC E008E48C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 38F2F0 E008E490 03E00008 */  jr        $ra
/* 38F2F4 E008E494 27BD0058 */   addiu    $sp, $sp, 0x58

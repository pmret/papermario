.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_AF7C5C
/* AF7C5C 8024030C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* AF7C60 80240310 AFB10014 */  sw        $s1, 0x14($sp)
/* AF7C64 80240314 0080882D */  daddu     $s1, $a0, $zero
/* AF7C68 80240318 AFBF0024 */  sw        $ra, 0x24($sp)
/* AF7C6C 8024031C AFB40020 */  sw        $s4, 0x20($sp)
/* AF7C70 80240320 AFB3001C */  sw        $s3, 0x1c($sp)
/* AF7C74 80240324 AFB20018 */  sw        $s2, 0x18($sp)
/* AF7C78 80240328 AFB00010 */  sw        $s0, 0x10($sp)
/* AF7C7C 8024032C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* AF7C80 80240330 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* AF7C84 80240334 F7B80038 */  sdc1      $f24, 0x38($sp)
/* AF7C88 80240338 F7B60030 */  sdc1      $f22, 0x30($sp)
/* AF7C8C 8024033C F7B40028 */  sdc1      $f20, 0x28($sp)
/* AF7C90 80240340 8E30000C */  lw        $s0, 0xc($s1)
/* AF7C94 80240344 8E130000 */  lw        $s3, ($s0)
/* AF7C98 80240348 26100004 */  addiu     $s0, $s0, 4
/* AF7C9C 8024034C 0C0B1EAF */  jal       get_variable
/* AF7CA0 80240350 0260282D */   daddu    $a1, $s3, $zero
/* AF7CA4 80240354 4482E000 */  mtc1      $v0, $f28
/* AF7CA8 80240358 00000000 */  nop       
/* AF7CAC 8024035C 4680E720 */  cvt.s.w   $f28, $f28
/* AF7CB0 80240360 8E140000 */  lw        $s4, ($s0)
/* AF7CB4 80240364 26100004 */  addiu     $s0, $s0, 4
/* AF7CB8 80240368 0220202D */  daddu     $a0, $s1, $zero
/* AF7CBC 8024036C 0C0B1EAF */  jal       get_variable
/* AF7CC0 80240370 0280282D */   daddu    $a1, $s4, $zero
/* AF7CC4 80240374 4482D000 */  mtc1      $v0, $f26
/* AF7CC8 80240378 00000000 */  nop       
/* AF7CCC 8024037C 4680D6A0 */  cvt.s.w   $f26, $f26
/* AF7CD0 80240380 8E100000 */  lw        $s0, ($s0)
/* AF7CD4 80240384 0220202D */  daddu     $a0, $s1, $zero
/* AF7CD8 80240388 0C0B1EAF */  jal       get_variable
/* AF7CDC 8024038C 0200282D */   daddu    $a1, $s0, $zero
/* AF7CE0 80240390 4482C000 */  mtc1      $v0, $f24
/* AF7CE4 80240394 00000000 */  nop       
/* AF7CE8 80240398 4680C620 */  cvt.s.w   $f24, $f24
/* AF7CEC 8024039C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AF7CF0 802403A0 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AF7CF4 802403A4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* AF7CF8 802403A8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* AF7CFC 802403AC C64200A8 */  lwc1      $f2, 0xa8($s2)
/* AF7D00 802403B0 44800000 */  mtc1      $zero, $f0
/* AF7D04 802403B4 00031080 */  sll       $v0, $v1, 2
/* AF7D08 802403B8 00431021 */  addu      $v0, $v0, $v1
/* AF7D0C 802403BC 00021080 */  sll       $v0, $v0, 2
/* AF7D10 802403C0 00431023 */  subu      $v0, $v0, $v1
/* AF7D14 802403C4 000218C0 */  sll       $v1, $v0, 3
/* AF7D18 802403C8 00431021 */  addu      $v0, $v0, $v1
/* AF7D1C 802403CC 000210C0 */  sll       $v0, $v0, 3
/* AF7D20 802403D0 46001032 */  c.eq.s    $f2, $f0
/* AF7D24 802403D4 3C01800B */  lui       $at, 0x800b
/* AF7D28 802403D8 00220821 */  addu      $at, $at, $v0
/* AF7D2C 802403DC C4361DEC */  lwc1      $f22, 0x1dec($at)
/* AF7D30 802403E0 45000005 */  bc1f      .L802403F8
/* AF7D34 802403E4 00000000 */   nop      
/* AF7D38 802403E8 3C0142C8 */  lui       $at, 0x42c8
/* AF7D3C 802403EC 44810000 */  mtc1      $at, $f0
/* AF7D40 802403F0 08090102 */  j         .L80240408
/* AF7D44 802403F4 4600B581 */   sub.s    $f22, $f22, $f0
.L802403F8:
/* AF7D48 802403F8 3C0142C8 */  lui       $at, 0x42c8
/* AF7D4C 802403FC 44810000 */  mtc1      $at, $f0
/* AF7D50 80240400 00000000 */  nop       
/* AF7D54 80240404 4600B580 */  add.s     $f22, $f22, $f0
.L80240408:
/* AF7D58 80240408 0C00A6C9 */  jal       clamp_angle
/* AF7D5C 8024040C 4600B306 */   mov.s    $f12, $f22
/* AF7D60 80240410 46000586 */  mov.s     $f22, $f0
/* AF7D64 80240414 3C014170 */  lui       $at, 0x4170
/* AF7D68 80240418 4481A000 */  mtc1      $at, $f20
/* AF7D6C 8024041C 0C00A8BB */  jal       sin_deg
/* AF7D70 80240420 4600B306 */   mov.s    $f12, $f22
/* AF7D74 80240424 46140002 */  mul.s     $f0, $f0, $f20
/* AF7D78 80240428 00000000 */  nop       
/* AF7D7C 8024042C 864200B0 */  lh        $v0, 0xb0($s2)
/* AF7D80 80240430 3C013F00 */  lui       $at, 0x3f00
/* AF7D84 80240434 44812000 */  mtc1      $at, $f4
/* AF7D88 80240438 44821000 */  mtc1      $v0, $f2
/* AF7D8C 8024043C 00000000 */  nop       
/* AF7D90 80240440 468010A0 */  cvt.s.w   $f2, $f2
/* AF7D94 80240444 46041082 */  mul.s     $f2, $f2, $f4
/* AF7D98 80240448 00000000 */  nop       
/* AF7D9C 8024044C 4600E700 */  add.s     $f28, $f28, $f0
/* AF7DA0 80240450 4602D680 */  add.s     $f26, $f26, $f2
/* AF7DA4 80240454 0C00A8D4 */  jal       cos_deg
/* AF7DA8 80240458 4600B306 */   mov.s    $f12, $f22
/* AF7DAC 8024045C 46140002 */  mul.s     $f0, $f0, $f20
/* AF7DB0 80240460 00000000 */  nop       
/* AF7DB4 80240464 0220202D */  daddu     $a0, $s1, $zero
/* AF7DB8 80240468 0260282D */  daddu     $a1, $s3, $zero
/* AF7DBC 8024046C 4600E18D */  trunc.w.s $f6, $f28
/* AF7DC0 80240470 44063000 */  mfc1      $a2, $f6
/* AF7DC4 80240474 0C0B2026 */  jal       set_variable
/* AF7DC8 80240478 4600C601 */   sub.s    $f24, $f24, $f0
/* AF7DCC 8024047C 0220202D */  daddu     $a0, $s1, $zero
/* AF7DD0 80240480 4600D18D */  trunc.w.s $f6, $f26
/* AF7DD4 80240484 44063000 */  mfc1      $a2, $f6
/* AF7DD8 80240488 0C0B2026 */  jal       set_variable
/* AF7DDC 8024048C 0280282D */   daddu    $a1, $s4, $zero
/* AF7DE0 80240490 0220202D */  daddu     $a0, $s1, $zero
/* AF7DE4 80240494 4600C18D */  trunc.w.s $f6, $f24
/* AF7DE8 80240498 44063000 */  mfc1      $a2, $f6
/* AF7DEC 8024049C 0C0B2026 */  jal       set_variable
/* AF7DF0 802404A0 0200282D */   daddu    $a1, $s0, $zero
/* AF7DF4 802404A4 8FBF0024 */  lw        $ra, 0x24($sp)
/* AF7DF8 802404A8 8FB40020 */  lw        $s4, 0x20($sp)
/* AF7DFC 802404AC 8FB3001C */  lw        $s3, 0x1c($sp)
/* AF7E00 802404B0 8FB20018 */  lw        $s2, 0x18($sp)
/* AF7E04 802404B4 8FB10014 */  lw        $s1, 0x14($sp)
/* AF7E08 802404B8 8FB00010 */  lw        $s0, 0x10($sp)
/* AF7E0C 802404BC D7BC0048 */  ldc1      $f28, 0x48($sp)
/* AF7E10 802404C0 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* AF7E14 802404C4 D7B80038 */  ldc1      $f24, 0x38($sp)
/* AF7E18 802404C8 D7B60030 */  ldc1      $f22, 0x30($sp)
/* AF7E1C 802404CC D7B40028 */  ldc1      $f20, 0x28($sp)
/* AF7E20 802404D0 24020002 */  addiu     $v0, $zero, 2
/* AF7E24 802404D4 03E00008 */  jr        $ra
/* AF7E28 802404D8 27BD0050 */   addiu    $sp, $sp, 0x50

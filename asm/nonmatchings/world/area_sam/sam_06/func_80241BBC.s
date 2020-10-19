.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BBC
/* D21A4C 80241BBC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D21A50 80241BC0 AFB10014 */  sw        $s1, 0x14($sp)
/* D21A54 80241BC4 0080882D */  daddu     $s1, $a0, $zero
/* D21A58 80241BC8 AFBF0024 */  sw        $ra, 0x24($sp)
/* D21A5C 80241BCC AFB40020 */  sw        $s4, 0x20($sp)
/* D21A60 80241BD0 AFB3001C */  sw        $s3, 0x1c($sp)
/* D21A64 80241BD4 AFB20018 */  sw        $s2, 0x18($sp)
/* D21A68 80241BD8 AFB00010 */  sw        $s0, 0x10($sp)
/* D21A6C 80241BDC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* D21A70 80241BE0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* D21A74 80241BE4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* D21A78 80241BE8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D21A7C 80241BEC F7B40028 */  sdc1      $f20, 0x28($sp)
/* D21A80 80241BF0 8E30000C */  lw        $s0, 0xc($s1)
/* D21A84 80241BF4 8E130000 */  lw        $s3, ($s0)
/* D21A88 80241BF8 26100004 */  addiu     $s0, $s0, 4
/* D21A8C 80241BFC 0C0B1EAF */  jal       get_variable
/* D21A90 80241C00 0260282D */   daddu    $a1, $s3, $zero
/* D21A94 80241C04 4482E000 */  mtc1      $v0, $f28
/* D21A98 80241C08 00000000 */  nop       
/* D21A9C 80241C0C 4680E720 */  cvt.s.w   $f28, $f28
/* D21AA0 80241C10 8E140000 */  lw        $s4, ($s0)
/* D21AA4 80241C14 26100004 */  addiu     $s0, $s0, 4
/* D21AA8 80241C18 0220202D */  daddu     $a0, $s1, $zero
/* D21AAC 80241C1C 0C0B1EAF */  jal       get_variable
/* D21AB0 80241C20 0280282D */   daddu    $a1, $s4, $zero
/* D21AB4 80241C24 4482D000 */  mtc1      $v0, $f26
/* D21AB8 80241C28 00000000 */  nop       
/* D21ABC 80241C2C 4680D6A0 */  cvt.s.w   $f26, $f26
/* D21AC0 80241C30 8E100000 */  lw        $s0, ($s0)
/* D21AC4 80241C34 0220202D */  daddu     $a0, $s1, $zero
/* D21AC8 80241C38 0C0B1EAF */  jal       get_variable
/* D21ACC 80241C3C 0200282D */   daddu    $a1, $s0, $zero
/* D21AD0 80241C40 4482C000 */  mtc1      $v0, $f24
/* D21AD4 80241C44 00000000 */  nop       
/* D21AD8 80241C48 4680C620 */  cvt.s.w   $f24, $f24
/* D21ADC 80241C4C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D21AE0 80241C50 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D21AE4 80241C54 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* D21AE8 80241C58 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* D21AEC 80241C5C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* D21AF0 80241C60 44800000 */  mtc1      $zero, $f0
/* D21AF4 80241C64 00031080 */  sll       $v0, $v1, 2
/* D21AF8 80241C68 00431021 */  addu      $v0, $v0, $v1
/* D21AFC 80241C6C 00021080 */  sll       $v0, $v0, 2
/* D21B00 80241C70 00431023 */  subu      $v0, $v0, $v1
/* D21B04 80241C74 000218C0 */  sll       $v1, $v0, 3
/* D21B08 80241C78 00431021 */  addu      $v0, $v0, $v1
/* D21B0C 80241C7C 000210C0 */  sll       $v0, $v0, 3
/* D21B10 80241C80 46001032 */  c.eq.s    $f2, $f0
/* D21B14 80241C84 3C01800B */  lui       $at, 0x800b
/* D21B18 80241C88 00220821 */  addu      $at, $at, $v0
/* D21B1C 80241C8C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D21B20 80241C90 45000005 */  bc1f      .L80241CA8
/* D21B24 80241C94 00000000 */   nop      
/* D21B28 80241C98 3C0142C8 */  lui       $at, 0x42c8
/* D21B2C 80241C9C 44810000 */  mtc1      $at, $f0
/* D21B30 80241CA0 0809072E */  j         .L80241CB8
/* D21B34 80241CA4 4600B581 */   sub.s    $f22, $f22, $f0
.L80241CA8:
/* D21B38 80241CA8 3C0142C8 */  lui       $at, 0x42c8
/* D21B3C 80241CAC 44810000 */  mtc1      $at, $f0
/* D21B40 80241CB0 00000000 */  nop       
/* D21B44 80241CB4 4600B580 */  add.s     $f22, $f22, $f0
.L80241CB8:
/* D21B48 80241CB8 0C00A6C9 */  jal       clamp_angle
/* D21B4C 80241CBC 4600B306 */   mov.s    $f12, $f22
/* D21B50 80241CC0 46000586 */  mov.s     $f22, $f0
/* D21B54 80241CC4 3C014170 */  lui       $at, 0x4170
/* D21B58 80241CC8 4481A000 */  mtc1      $at, $f20
/* D21B5C 80241CCC 0C00A8BB */  jal       sin_deg
/* D21B60 80241CD0 4600B306 */   mov.s    $f12, $f22
/* D21B64 80241CD4 46140002 */  mul.s     $f0, $f0, $f20
/* D21B68 80241CD8 00000000 */  nop       
/* D21B6C 80241CDC 864200B0 */  lh        $v0, 0xb0($s2)
/* D21B70 80241CE0 3C013F00 */  lui       $at, 0x3f00
/* D21B74 80241CE4 44812000 */  mtc1      $at, $f4
/* D21B78 80241CE8 44821000 */  mtc1      $v0, $f2
/* D21B7C 80241CEC 00000000 */  nop       
/* D21B80 80241CF0 468010A0 */  cvt.s.w   $f2, $f2
/* D21B84 80241CF4 46041082 */  mul.s     $f2, $f2, $f4
/* D21B88 80241CF8 00000000 */  nop       
/* D21B8C 80241CFC 4600E700 */  add.s     $f28, $f28, $f0
/* D21B90 80241D00 4602D680 */  add.s     $f26, $f26, $f2
/* D21B94 80241D04 0C00A8D4 */  jal       cos_deg
/* D21B98 80241D08 4600B306 */   mov.s    $f12, $f22
/* D21B9C 80241D0C 46140002 */  mul.s     $f0, $f0, $f20
/* D21BA0 80241D10 00000000 */  nop       
/* D21BA4 80241D14 0220202D */  daddu     $a0, $s1, $zero
/* D21BA8 80241D18 0260282D */  daddu     $a1, $s3, $zero
/* D21BAC 80241D1C 4600E18D */  trunc.w.s $f6, $f28
/* D21BB0 80241D20 44063000 */  mfc1      $a2, $f6
/* D21BB4 80241D24 0C0B2026 */  jal       set_variable
/* D21BB8 80241D28 4600C601 */   sub.s    $f24, $f24, $f0
/* D21BBC 80241D2C 0220202D */  daddu     $a0, $s1, $zero
/* D21BC0 80241D30 4600D18D */  trunc.w.s $f6, $f26
/* D21BC4 80241D34 44063000 */  mfc1      $a2, $f6
/* D21BC8 80241D38 0C0B2026 */  jal       set_variable
/* D21BCC 80241D3C 0280282D */   daddu    $a1, $s4, $zero
/* D21BD0 80241D40 0220202D */  daddu     $a0, $s1, $zero
/* D21BD4 80241D44 4600C18D */  trunc.w.s $f6, $f24
/* D21BD8 80241D48 44063000 */  mfc1      $a2, $f6
/* D21BDC 80241D4C 0C0B2026 */  jal       set_variable
/* D21BE0 80241D50 0200282D */   daddu    $a1, $s0, $zero
/* D21BE4 80241D54 8FBF0024 */  lw        $ra, 0x24($sp)
/* D21BE8 80241D58 8FB40020 */  lw        $s4, 0x20($sp)
/* D21BEC 80241D5C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D21BF0 80241D60 8FB20018 */  lw        $s2, 0x18($sp)
/* D21BF4 80241D64 8FB10014 */  lw        $s1, 0x14($sp)
/* D21BF8 80241D68 8FB00010 */  lw        $s0, 0x10($sp)
/* D21BFC 80241D6C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* D21C00 80241D70 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* D21C04 80241D74 D7B80038 */  ldc1      $f24, 0x38($sp)
/* D21C08 80241D78 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D21C0C 80241D7C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D21C10 80241D80 24020002 */  addiu     $v0, $zero, 2
/* D21C14 80241D84 03E00008 */  jr        $ra
/* D21C18 80241D88 27BD0050 */   addiu    $sp, $sp, 0x50

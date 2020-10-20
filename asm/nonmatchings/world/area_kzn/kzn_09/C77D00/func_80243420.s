.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243420
/* C7A100 80243420 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C7A104 80243424 AFB10014 */  sw        $s1, 0x14($sp)
/* C7A108 80243428 0080882D */  daddu     $s1, $a0, $zero
/* C7A10C 8024342C AFBF0024 */  sw        $ra, 0x24($sp)
/* C7A110 80243430 AFB40020 */  sw        $s4, 0x20($sp)
/* C7A114 80243434 AFB3001C */  sw        $s3, 0x1c($sp)
/* C7A118 80243438 AFB20018 */  sw        $s2, 0x18($sp)
/* C7A11C 8024343C AFB00010 */  sw        $s0, 0x10($sp)
/* C7A120 80243440 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* C7A124 80243444 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* C7A128 80243448 F7B80038 */  sdc1      $f24, 0x38($sp)
/* C7A12C 8024344C F7B60030 */  sdc1      $f22, 0x30($sp)
/* C7A130 80243450 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C7A134 80243454 8E30000C */  lw        $s0, 0xc($s1)
/* C7A138 80243458 8E130000 */  lw        $s3, ($s0)
/* C7A13C 8024345C 26100004 */  addiu     $s0, $s0, 4
/* C7A140 80243460 0C0B1EAF */  jal       get_variable
/* C7A144 80243464 0260282D */   daddu    $a1, $s3, $zero
/* C7A148 80243468 4482E000 */  mtc1      $v0, $f28
/* C7A14C 8024346C 00000000 */  nop       
/* C7A150 80243470 4680E720 */  cvt.s.w   $f28, $f28
/* C7A154 80243474 8E140000 */  lw        $s4, ($s0)
/* C7A158 80243478 26100004 */  addiu     $s0, $s0, 4
/* C7A15C 8024347C 0220202D */  daddu     $a0, $s1, $zero
/* C7A160 80243480 0C0B1EAF */  jal       get_variable
/* C7A164 80243484 0280282D */   daddu    $a1, $s4, $zero
/* C7A168 80243488 4482D000 */  mtc1      $v0, $f26
/* C7A16C 8024348C 00000000 */  nop       
/* C7A170 80243490 4680D6A0 */  cvt.s.w   $f26, $f26
/* C7A174 80243494 8E100000 */  lw        $s0, ($s0)
/* C7A178 80243498 0220202D */  daddu     $a0, $s1, $zero
/* C7A17C 8024349C 0C0B1EAF */  jal       get_variable
/* C7A180 802434A0 0200282D */   daddu    $a1, $s0, $zero
/* C7A184 802434A4 4482C000 */  mtc1      $v0, $f24
/* C7A188 802434A8 00000000 */  nop       
/* C7A18C 802434AC 4680C620 */  cvt.s.w   $f24, $f24
/* C7A190 802434B0 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* C7A194 802434B4 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* C7A198 802434B8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* C7A19C 802434BC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* C7A1A0 802434C0 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* C7A1A4 802434C4 44800000 */  mtc1      $zero, $f0
/* C7A1A8 802434C8 00031080 */  sll       $v0, $v1, 2
/* C7A1AC 802434CC 00431021 */  addu      $v0, $v0, $v1
/* C7A1B0 802434D0 00021080 */  sll       $v0, $v0, 2
/* C7A1B4 802434D4 00431023 */  subu      $v0, $v0, $v1
/* C7A1B8 802434D8 000218C0 */  sll       $v1, $v0, 3
/* C7A1BC 802434DC 00431021 */  addu      $v0, $v0, $v1
/* C7A1C0 802434E0 000210C0 */  sll       $v0, $v0, 3
/* C7A1C4 802434E4 46001032 */  c.eq.s    $f2, $f0
/* C7A1C8 802434E8 3C01800B */  lui       $at, 0x800b
/* C7A1CC 802434EC 00220821 */  addu      $at, $at, $v0
/* C7A1D0 802434F0 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* C7A1D4 802434F4 45000005 */  bc1f      .L8024350C
/* C7A1D8 802434F8 00000000 */   nop      
/* C7A1DC 802434FC 3C0142C8 */  lui       $at, 0x42c8
/* C7A1E0 80243500 44810000 */  mtc1      $at, $f0
/* C7A1E4 80243504 08090D47 */  j         .L8024351C
/* C7A1E8 80243508 4600B581 */   sub.s    $f22, $f22, $f0
.L8024350C:
/* C7A1EC 8024350C 3C0142C8 */  lui       $at, 0x42c8
/* C7A1F0 80243510 44810000 */  mtc1      $at, $f0
/* C7A1F4 80243514 00000000 */  nop       
/* C7A1F8 80243518 4600B580 */  add.s     $f22, $f22, $f0
.L8024351C:
/* C7A1FC 8024351C 0C00A6C9 */  jal       clamp_angle
/* C7A200 80243520 4600B306 */   mov.s    $f12, $f22
/* C7A204 80243524 46000586 */  mov.s     $f22, $f0
/* C7A208 80243528 3C014170 */  lui       $at, 0x4170
/* C7A20C 8024352C 4481A000 */  mtc1      $at, $f20
/* C7A210 80243530 0C00A8BB */  jal       sin_deg
/* C7A214 80243534 4600B306 */   mov.s    $f12, $f22
/* C7A218 80243538 46140002 */  mul.s     $f0, $f0, $f20
/* C7A21C 8024353C 00000000 */  nop       
/* C7A220 80243540 864200B0 */  lh        $v0, 0xb0($s2)
/* C7A224 80243544 3C013F00 */  lui       $at, 0x3f00
/* C7A228 80243548 44812000 */  mtc1      $at, $f4
/* C7A22C 8024354C 44821000 */  mtc1      $v0, $f2
/* C7A230 80243550 00000000 */  nop       
/* C7A234 80243554 468010A0 */  cvt.s.w   $f2, $f2
/* C7A238 80243558 46041082 */  mul.s     $f2, $f2, $f4
/* C7A23C 8024355C 00000000 */  nop       
/* C7A240 80243560 4600E700 */  add.s     $f28, $f28, $f0
/* C7A244 80243564 4602D680 */  add.s     $f26, $f26, $f2
/* C7A248 80243568 0C00A8D4 */  jal       cos_deg
/* C7A24C 8024356C 4600B306 */   mov.s    $f12, $f22
/* C7A250 80243570 46140002 */  mul.s     $f0, $f0, $f20
/* C7A254 80243574 00000000 */  nop       
/* C7A258 80243578 0220202D */  daddu     $a0, $s1, $zero
/* C7A25C 8024357C 0260282D */  daddu     $a1, $s3, $zero
/* C7A260 80243580 4600E18D */  trunc.w.s $f6, $f28
/* C7A264 80243584 44063000 */  mfc1      $a2, $f6
/* C7A268 80243588 0C0B2026 */  jal       set_variable
/* C7A26C 8024358C 4600C601 */   sub.s    $f24, $f24, $f0
/* C7A270 80243590 0220202D */  daddu     $a0, $s1, $zero
/* C7A274 80243594 4600D18D */  trunc.w.s $f6, $f26
/* C7A278 80243598 44063000 */  mfc1      $a2, $f6
/* C7A27C 8024359C 0C0B2026 */  jal       set_variable
/* C7A280 802435A0 0280282D */   daddu    $a1, $s4, $zero
/* C7A284 802435A4 0220202D */  daddu     $a0, $s1, $zero
/* C7A288 802435A8 4600C18D */  trunc.w.s $f6, $f24
/* C7A28C 802435AC 44063000 */  mfc1      $a2, $f6
/* C7A290 802435B0 0C0B2026 */  jal       set_variable
/* C7A294 802435B4 0200282D */   daddu    $a1, $s0, $zero
/* C7A298 802435B8 8FBF0024 */  lw        $ra, 0x24($sp)
/* C7A29C 802435BC 8FB40020 */  lw        $s4, 0x20($sp)
/* C7A2A0 802435C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C7A2A4 802435C4 8FB20018 */  lw        $s2, 0x18($sp)
/* C7A2A8 802435C8 8FB10014 */  lw        $s1, 0x14($sp)
/* C7A2AC 802435CC 8FB00010 */  lw        $s0, 0x10($sp)
/* C7A2B0 802435D0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* C7A2B4 802435D4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* C7A2B8 802435D8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* C7A2BC 802435DC D7B60030 */  ldc1      $f22, 0x30($sp)
/* C7A2C0 802435E0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C7A2C4 802435E4 24020002 */  addiu     $v0, $zero, 2
/* C7A2C8 802435E8 03E00008 */  jr        $ra
/* C7A2CC 802435EC 27BD0050 */   addiu    $sp, $sp, 0x50

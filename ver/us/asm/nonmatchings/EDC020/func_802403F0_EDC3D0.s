.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_EDC3D0
/* EDC3D0 802403F0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EDC3D4 802403F4 AFB10014 */  sw        $s1, 0x14($sp)
/* EDC3D8 802403F8 0080882D */  daddu     $s1, $a0, $zero
/* EDC3DC 802403FC AFBF0024 */  sw        $ra, 0x24($sp)
/* EDC3E0 80240400 AFB40020 */  sw        $s4, 0x20($sp)
/* EDC3E4 80240404 AFB3001C */  sw        $s3, 0x1c($sp)
/* EDC3E8 80240408 AFB20018 */  sw        $s2, 0x18($sp)
/* EDC3EC 8024040C AFB00010 */  sw        $s0, 0x10($sp)
/* EDC3F0 80240410 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* EDC3F4 80240414 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* EDC3F8 80240418 F7B80038 */  sdc1      $f24, 0x38($sp)
/* EDC3FC 8024041C F7B60030 */  sdc1      $f22, 0x30($sp)
/* EDC400 80240420 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EDC404 80240424 8E30000C */  lw        $s0, 0xc($s1)
/* EDC408 80240428 8E130000 */  lw        $s3, ($s0)
/* EDC40C 8024042C 26100004 */  addiu     $s0, $s0, 4
/* EDC410 80240430 0C0B53A3 */  jal       dead_evt_get_variable
/* EDC414 80240434 0260282D */   daddu    $a1, $s3, $zero
/* EDC418 80240438 4482E000 */  mtc1      $v0, $f28
/* EDC41C 8024043C 00000000 */  nop
/* EDC420 80240440 4680E720 */  cvt.s.w   $f28, $f28
/* EDC424 80240444 8E140000 */  lw        $s4, ($s0)
/* EDC428 80240448 26100004 */  addiu     $s0, $s0, 4
/* EDC42C 8024044C 0220202D */  daddu     $a0, $s1, $zero
/* EDC430 80240450 0C0B53A3 */  jal       dead_evt_get_variable
/* EDC434 80240454 0280282D */   daddu    $a1, $s4, $zero
/* EDC438 80240458 4482D000 */  mtc1      $v0, $f26
/* EDC43C 8024045C 00000000 */  nop
/* EDC440 80240460 4680D6A0 */  cvt.s.w   $f26, $f26
/* EDC444 80240464 8E100000 */  lw        $s0, ($s0)
/* EDC448 80240468 0220202D */  daddu     $a0, $s1, $zero
/* EDC44C 8024046C 0C0B53A3 */  jal       dead_evt_get_variable
/* EDC450 80240470 0200282D */   daddu    $a1, $s0, $zero
/* EDC454 80240474 4482C000 */  mtc1      $v0, $f24
/* EDC458 80240478 00000000 */  nop
/* EDC45C 8024047C 4680C620 */  cvt.s.w   $f24, $f24
/* EDC460 80240480 3C128011 */  lui       $s2, %hi(dead_gPlayerStatus)
/* EDC464 80240484 26527578 */  addiu     $s2, $s2, %lo(dead_gPlayerStatus)
/* EDC468 80240488 3C038008 */  lui       $v1, %hi(D_8007C760)
/* EDC46C 8024048C 8C63C760 */  lw        $v1, %lo(D_8007C760)($v1)
/* EDC470 80240490 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* EDC474 80240494 44800000 */  mtc1      $zero, $f0
/* EDC478 80240498 00031080 */  sll       $v0, $v1, 2
/* EDC47C 8024049C 00431021 */  addu      $v0, $v0, $v1
/* EDC480 802404A0 00021080 */  sll       $v0, $v0, 2
/* EDC484 802404A4 00431023 */  subu      $v0, $v0, $v1
/* EDC488 802404A8 000218C0 */  sll       $v1, $v0, 3
/* EDC48C 802404AC 00431021 */  addu      $v0, $v0, $v1
/* EDC490 802404B0 000210C0 */  sll       $v0, $v0, 3
/* EDC494 802404B4 46001032 */  c.eq.s    $f2, $f0
/* EDC498 802404B8 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EDC49C 802404BC 00220821 */  addu      $at, $at, $v0
/* EDC4A0 802404C0 C4368DEC */  lwc1      $f22, %lo(D_800B8DEC)($at)
/* EDC4A4 802404C4 45000005 */  bc1f      .L802404DC
/* EDC4A8 802404C8 00000000 */   nop
/* EDC4AC 802404CC 3C0142C8 */  lui       $at, 0x42c8
/* EDC4B0 802404D0 44810000 */  mtc1      $at, $f0
/* EDC4B4 802404D4 0809013B */  j         .L802404EC
/* EDC4B8 802404D8 4600B581 */   sub.s    $f22, $f22, $f0
.L802404DC:
/* EDC4BC 802404DC 3C0142C8 */  lui       $at, 0x42c8
/* EDC4C0 802404E0 44810000 */  mtc1      $at, $f0
/* EDC4C4 802404E4 00000000 */  nop
/* EDC4C8 802404E8 4600B580 */  add.s     $f22, $f22, $f0
.L802404EC:
/* EDC4CC 802404EC 0C00AB85 */  jal       dead_clamp_angle
/* EDC4D0 802404F0 4600B306 */   mov.s    $f12, $f22
/* EDC4D4 802404F4 46000586 */  mov.s     $f22, $f0
/* EDC4D8 802404F8 3C014170 */  lui       $at, 0x4170
/* EDC4DC 802404FC 4481A000 */  mtc1      $at, $f20
/* EDC4E0 80240500 0C00AD77 */  jal       dead_sin_deg
/* EDC4E4 80240504 4600B306 */   mov.s    $f12, $f22
/* EDC4E8 80240508 46140002 */  mul.s     $f0, $f0, $f20
/* EDC4EC 8024050C 00000000 */  nop
/* EDC4F0 80240510 864200B0 */  lh        $v0, 0xb0($s2)
/* EDC4F4 80240514 3C013F00 */  lui       $at, 0x3f00
/* EDC4F8 80240518 44812000 */  mtc1      $at, $f4
/* EDC4FC 8024051C 44821000 */  mtc1      $v0, $f2
/* EDC500 80240520 00000000 */  nop
/* EDC504 80240524 468010A0 */  cvt.s.w   $f2, $f2
/* EDC508 80240528 46041082 */  mul.s     $f2, $f2, $f4
/* EDC50C 8024052C 00000000 */  nop
/* EDC510 80240530 4600E700 */  add.s     $f28, $f28, $f0
/* EDC514 80240534 4602D680 */  add.s     $f26, $f26, $f2
/* EDC518 80240538 0C00AD90 */  jal       dead_cos_deg
/* EDC51C 8024053C 4600B306 */   mov.s    $f12, $f22
/* EDC520 80240540 46140002 */  mul.s     $f0, $f0, $f20
/* EDC524 80240544 00000000 */  nop
/* EDC528 80240548 0220202D */  daddu     $a0, $s1, $zero
/* EDC52C 8024054C 0260282D */  daddu     $a1, $s3, $zero
/* EDC530 80240550 4600E18D */  trunc.w.s $f6, $f28
/* EDC534 80240554 44063000 */  mfc1      $a2, $f6
/* EDC538 80240558 0C0B551A */  jal       dead_evt_set_variable
/* EDC53C 8024055C 4600C601 */   sub.s    $f24, $f24, $f0
/* EDC540 80240560 0220202D */  daddu     $a0, $s1, $zero
/* EDC544 80240564 4600D18D */  trunc.w.s $f6, $f26
/* EDC548 80240568 44063000 */  mfc1      $a2, $f6
/* EDC54C 8024056C 0C0B551A */  jal       dead_evt_set_variable
/* EDC550 80240570 0280282D */   daddu    $a1, $s4, $zero
/* EDC554 80240574 0220202D */  daddu     $a0, $s1, $zero
/* EDC558 80240578 4600C18D */  trunc.w.s $f6, $f24
/* EDC55C 8024057C 44063000 */  mfc1      $a2, $f6
/* EDC560 80240580 0C0B551A */  jal       dead_evt_set_variable
/* EDC564 80240584 0200282D */   daddu    $a1, $s0, $zero
/* EDC568 80240588 8FBF0024 */  lw        $ra, 0x24($sp)
/* EDC56C 8024058C 8FB40020 */  lw        $s4, 0x20($sp)
/* EDC570 80240590 8FB3001C */  lw        $s3, 0x1c($sp)
/* EDC574 80240594 8FB20018 */  lw        $s2, 0x18($sp)
/* EDC578 80240598 8FB10014 */  lw        $s1, 0x14($sp)
/* EDC57C 8024059C 8FB00010 */  lw        $s0, 0x10($sp)
/* EDC580 802405A0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* EDC584 802405A4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* EDC588 802405A8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* EDC58C 802405AC D7B60030 */  ldc1      $f22, 0x30($sp)
/* EDC590 802405B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* EDC594 802405B4 24020002 */  addiu     $v0, $zero, 2
/* EDC598 802405B8 03E00008 */  jr        $ra
/* EDC59C 802405BC 27BD0050 */   addiu    $sp, $sp, 0x50

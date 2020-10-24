.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242358_DCF028
/* DCF028 80242358 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DCF02C 8024235C AFB10014 */  sw        $s1, 0x14($sp)
/* DCF030 80242360 0080882D */  daddu     $s1, $a0, $zero
/* DCF034 80242364 3C05800B */  lui       $a1, %hi(gCameras)
/* DCF038 80242368 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* DCF03C 8024236C AFBF0020 */  sw        $ra, 0x20($sp)
/* DCF040 80242370 AFB3001C */  sw        $s3, 0x1c($sp)
/* DCF044 80242374 AFB20018 */  sw        $s2, 0x18($sp)
/* DCF048 80242378 AFB00010 */  sw        $s0, 0x10($sp)
/* DCF04C 8024237C F7B40028 */  sdc1      $f20, 0x28($sp)
/* DCF050 80242380 8E330148 */  lw        $s3, 0x148($s1)
/* DCF054 80242384 3C03800A */  lui       $v1, 0x800a
/* DCF058 80242388 8463A634 */  lh        $v1, -0x59cc($v1)
/* DCF05C 8024238C 8E30000C */  lw        $s0, 0xc($s1)
/* DCF060 80242390 00031080 */  sll       $v0, $v1, 2
/* DCF064 80242394 00431021 */  addu      $v0, $v0, $v1
/* DCF068 80242398 00021080 */  sll       $v0, $v0, 2
/* DCF06C 8024239C 00431023 */  subu      $v0, $v0, $v1
/* DCF070 802423A0 000218C0 */  sll       $v1, $v0, 3
/* DCF074 802423A4 00431021 */  addu      $v0, $v0, $v1
/* DCF078 802423A8 000210C0 */  sll       $v0, $v0, 3
/* DCF07C 802423AC 86640008 */  lh        $a0, 8($s3)
/* DCF080 802423B0 0C00EABB */  jal       get_npc_unsafe
/* DCF084 802423B4 00459021 */   addu     $s2, $v0, $a1
/* DCF088 802423B8 0220202D */  daddu     $a0, $s1, $zero
/* DCF08C 802423BC 8E050000 */  lw        $a1, ($s0)
/* DCF090 802423C0 0C0B1EAF */  jal       get_variable
/* DCF094 802423C4 0040802D */   daddu    $s0, $v0, $zero
/* DCF098 802423C8 0260202D */  daddu     $a0, $s3, $zero
/* DCF09C 802423CC 8C460024 */  lw        $a2, 0x24($v0)
/* DCF0A0 802423D0 8C470028 */  lw        $a3, 0x28($v0)
/* DCF0A4 802423D4 0C0124FB */  jal       func_800493EC
/* DCF0A8 802423D8 0000282D */   daddu    $a1, $zero, $zero
/* DCF0AC 802423DC 10400052 */  beqz      $v0, .L80242528
/* DCF0B0 802423E0 2402FFFF */   addiu    $v0, $zero, -1
/* DCF0B4 802423E4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* DCF0B8 802423E8 C60E000C */  lwc1      $f14, 0xc($s0)
/* DCF0BC 802423EC 3C014387 */  lui       $at, 0x4387
/* DCF0C0 802423F0 4481A000 */  mtc1      $at, $f20
/* DCF0C4 802423F4 0C00A70A */  jal       get_clamped_angle_diff
/* DCF0C8 802423F8 00000000 */   nop      
/* DCF0CC 802423FC 0C00A6C9 */  jal       clamp_angle
/* DCF0D0 80242400 46000306 */   mov.s    $f12, $f0
/* DCF0D4 80242404 3C018025 */  lui       $at, 0x8025
/* DCF0D8 80242408 D422AB10 */  ldc1      $f2, -0x54f0($at)
/* DCF0DC 8024240C 46000021 */  cvt.d.s   $f0, $f0
/* DCF0E0 80242410 4622003C */  c.lt.d    $f0, $f2
/* DCF0E4 80242414 00000000 */  nop       
/* DCF0E8 80242418 45000003 */  bc1f      .L80242428
/* DCF0EC 8024241C 00000000 */   nop      
/* DCF0F0 80242420 3C0142B4 */  lui       $at, 0x42b4
/* DCF0F4 80242424 4481A000 */  mtc1      $at, $f20
.L80242428:
/* DCF0F8 80242428 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* DCF0FC 8024242C 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* DCF100 80242430 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DCF104 80242434 8E220000 */  lw        $v0, ($s1)
/* DCF108 80242438 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DCF10C 8024243C 8C460028 */  lw        $a2, 0x28($v0)
/* DCF110 80242440 0C00A720 */  jal       atan2
/* DCF114 80242444 8C470030 */   lw       $a3, 0x30($v0)
/* DCF118 80242448 4600A306 */  mov.s     $f12, $f20
/* DCF11C 8024244C 0C00A70A */  jal       get_clamped_angle_diff
/* DCF120 80242450 46000386 */   mov.s    $f14, $f0
/* DCF124 80242454 46000005 */  abs.s     $f0, $f0
/* DCF128 80242458 3C018025 */  lui       $at, 0x8025
/* DCF12C 8024245C D422AB18 */  ldc1      $f2, -0x54e8($at)
/* DCF130 80242460 46000021 */  cvt.d.s   $f0, $f0
/* DCF134 80242464 4620103C */  c.lt.d    $f2, $f0
/* DCF138 80242468 00000000 */  nop       
/* DCF13C 8024246C 4501002E */  bc1t      .L80242528
/* DCF140 80242470 2402FFFF */   addiu    $v0, $zero, -1
/* DCF144 80242474 8E220000 */  lw        $v0, ($s1)
/* DCF148 80242478 C600003C */  lwc1      $f0, 0x3c($s0)
/* DCF14C 8024247C C442002C */  lwc1      $f2, 0x2c($v0)
/* DCF150 80242480 860200A8 */  lh        $v0, 0xa8($s0)
/* DCF154 80242484 46020001 */  sub.s     $f0, $f0, $f2
/* DCF158 80242488 44821000 */  mtc1      $v0, $f2
/* DCF15C 8024248C 00000000 */  nop       
/* DCF160 80242490 468010A1 */  cvt.d.w   $f2, $f2
/* DCF164 80242494 46221080 */  add.d     $f2, $f2, $f2
/* DCF168 80242498 46000005 */  abs.s     $f0, $f0
/* DCF16C 8024249C 46000021 */  cvt.d.s   $f0, $f0
/* DCF170 802424A0 4620103E */  c.le.d    $f2, $f0
/* DCF174 802424A4 00000000 */  nop       
/* DCF178 802424A8 4501001F */  bc1t      .L80242528
/* DCF17C 802424AC 2402FFFF */   addiu    $v0, $zero, -1
/* DCF180 802424B0 3C038011 */  lui       $v1, 0x8011
/* DCF184 802424B4 8063EBB3 */  lb        $v1, -0x144d($v1)
/* DCF188 802424B8 24020009 */  addiu     $v0, $zero, 9
/* DCF18C 802424BC 10620019 */  beq       $v1, $v0, .L80242524
/* DCF190 802424C0 24020007 */   addiu    $v0, $zero, 7
/* DCF194 802424C4 14620005 */  bne       $v1, $v0, .L802424DC
/* DCF198 802424C8 2402FFFF */   addiu    $v0, $zero, -1
/* DCF19C 802424CC 0809094A */  j         .L80242528
/* DCF1A0 802424D0 00000000 */   nop      
.L802424D4:
/* DCF1A4 802424D4 0809094A */  j         .L80242528
/* DCF1A8 802424D8 0240102D */   daddu    $v0, $s2, $zero
.L802424DC:
/* DCF1AC 802424DC 8E620078 */  lw        $v0, 0x78($s3)
/* DCF1B0 802424E0 18400010 */  blez      $v0, .L80242524
/* DCF1B4 802424E4 0000882D */   daddu    $s1, $zero, $zero
.L802424E8:
/* DCF1B8 802424E8 86620008 */  lh        $v0, 8($s3)
/* DCF1BC 802424EC 00511021 */  addu      $v0, $v0, $s1
/* DCF1C0 802424F0 24520001 */  addiu     $s2, $v0, 1
/* DCF1C4 802424F4 0C00FB3A */  jal       get_enemy
/* DCF1C8 802424F8 0240202D */   daddu    $a0, $s2, $zero
/* DCF1CC 802424FC 0240202D */  daddu     $a0, $s2, $zero
/* DCF1D0 80242500 0C00EABB */  jal       get_npc_unsafe
/* DCF1D4 80242504 0040802D */   daddu    $s0, $v0, $zero
/* DCF1D8 80242508 8E02006C */  lw        $v0, 0x6c($s0)
/* DCF1DC 8024250C 1040FFF1 */  beqz      $v0, .L802424D4
/* DCF1E0 80242510 26310001 */   addiu    $s1, $s1, 1
/* DCF1E4 80242514 8E620078 */  lw        $v0, 0x78($s3)
/* DCF1E8 80242518 0222102A */  slt       $v0, $s1, $v0
/* DCF1EC 8024251C 1440FFF2 */  bnez      $v0, .L802424E8
/* DCF1F0 80242520 00000000 */   nop      
.L80242524:
/* DCF1F4 80242524 2402FFFF */  addiu     $v0, $zero, -1
.L80242528:
/* DCF1F8 80242528 8FBF0020 */  lw        $ra, 0x20($sp)
/* DCF1FC 8024252C 8FB3001C */  lw        $s3, 0x1c($sp)
/* DCF200 80242530 8FB20018 */  lw        $s2, 0x18($sp)
/* DCF204 80242534 8FB10014 */  lw        $s1, 0x14($sp)
/* DCF208 80242538 8FB00010 */  lw        $s0, 0x10($sp)
/* DCF20C 8024253C D7B40028 */  ldc1      $f20, 0x28($sp)
/* DCF210 80242540 03E00008 */  jr        $ra
/* DCF214 80242544 27BD0030 */   addiu    $sp, $sp, 0x30

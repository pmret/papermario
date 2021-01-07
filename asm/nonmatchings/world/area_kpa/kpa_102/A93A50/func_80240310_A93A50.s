.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_A93A50
/* A93A50 80240310 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A93A54 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* A93A58 80240318 0080882D */  daddu     $s1, $a0, $zero
/* A93A5C 8024031C 3C05800B */  lui       $a1, %hi(gCameras)
/* A93A60 80240320 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A93A64 80240324 AFBF0020 */  sw        $ra, 0x20($sp)
/* A93A68 80240328 AFB3001C */  sw        $s3, 0x1c($sp)
/* A93A6C 8024032C AFB20018 */  sw        $s2, 0x18($sp)
/* A93A70 80240330 AFB00010 */  sw        $s0, 0x10($sp)
/* A93A74 80240334 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A93A78 80240338 8E330148 */  lw        $s3, 0x148($s1)
/* A93A7C 8024033C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* A93A80 80240340 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* A93A84 80240344 8E30000C */  lw        $s0, 0xc($s1)
/* A93A88 80240348 00031080 */  sll       $v0, $v1, 2
/* A93A8C 8024034C 00431021 */  addu      $v0, $v0, $v1
/* A93A90 80240350 00021080 */  sll       $v0, $v0, 2
/* A93A94 80240354 00431023 */  subu      $v0, $v0, $v1
/* A93A98 80240358 000218C0 */  sll       $v1, $v0, 3
/* A93A9C 8024035C 00431021 */  addu      $v0, $v0, $v1
/* A93AA0 80240360 000210C0 */  sll       $v0, $v0, 3
/* A93AA4 80240364 86640008 */  lh        $a0, 8($s3)
/* A93AA8 80240368 0C00EABB */  jal       get_npc_unsafe
/* A93AAC 8024036C 00459021 */   addu     $s2, $v0, $a1
/* A93AB0 80240370 0220202D */  daddu     $a0, $s1, $zero
/* A93AB4 80240374 8E050000 */  lw        $a1, ($s0)
/* A93AB8 80240378 0C0B1EAF */  jal       get_variable
/* A93ABC 8024037C 0040802D */   daddu    $s0, $v0, $zero
/* A93AC0 80240380 0260202D */  daddu     $a0, $s3, $zero
/* A93AC4 80240384 8C460024 */  lw        $a2, 0x24($v0)
/* A93AC8 80240388 8C470028 */  lw        $a3, 0x28($v0)
/* A93ACC 8024038C 0C0124FB */  jal       func_800493EC
/* A93AD0 80240390 0000282D */   daddu    $a1, $zero, $zero
/* A93AD4 80240394 10400052 */  beqz      $v0, .L802404E0
/* A93AD8 80240398 2402FFFF */   addiu    $v0, $zero, -1
/* A93ADC 8024039C C64C006C */  lwc1      $f12, 0x6c($s2)
/* A93AE0 802403A0 C60E000C */  lwc1      $f14, 0xc($s0)
/* A93AE4 802403A4 3C014387 */  lui       $at, 0x4387
/* A93AE8 802403A8 4481A000 */  mtc1      $at, $f20
/* A93AEC 802403AC 0C00A70A */  jal       get_clamped_angle_diff
/* A93AF0 802403B0 00000000 */   nop      
/* A93AF4 802403B4 0C00A6C9 */  jal       clamp_angle
/* A93AF8 802403B8 46000306 */   mov.s    $f12, $f0
/* A93AFC 802403BC 3C018024 */  lui       $at, %hi(D_80245B20)
/* A93B00 802403C0 D4225B20 */  ldc1      $f2, %lo(D_80245B20)($at)
/* A93B04 802403C4 46000021 */  cvt.d.s   $f0, $f0
/* A93B08 802403C8 4622003C */  c.lt.d    $f0, $f2
/* A93B0C 802403CC 00000000 */  nop       
/* A93B10 802403D0 45000003 */  bc1f      .L802403E0
/* A93B14 802403D4 00000000 */   nop      
/* A93B18 802403D8 3C0142B4 */  lui       $at, 0x42b4
/* A93B1C 802403DC 4481A000 */  mtc1      $at, $f20
.L802403E0:
/* A93B20 802403E0 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A93B24 802403E4 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A93B28 802403E8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A93B2C 802403EC 8E220000 */  lw        $v0, ($s1)
/* A93B30 802403F0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A93B34 802403F4 8C460028 */  lw        $a2, 0x28($v0)
/* A93B38 802403F8 0C00A720 */  jal       atan2
/* A93B3C 802403FC 8C470030 */   lw       $a3, 0x30($v0)
/* A93B40 80240400 4600A306 */  mov.s     $f12, $f20
/* A93B44 80240404 0C00A70A */  jal       get_clamped_angle_diff
/* A93B48 80240408 46000386 */   mov.s    $f14, $f0
/* A93B4C 8024040C 46000005 */  abs.s     $f0, $f0
/* A93B50 80240410 3C018024 */  lui       $at, %hi(D_80245B28)
/* A93B54 80240414 D4225B28 */  ldc1      $f2, %lo(D_80245B28)($at)
/* A93B58 80240418 46000021 */  cvt.d.s   $f0, $f0
/* A93B5C 8024041C 4620103C */  c.lt.d    $f2, $f0
/* A93B60 80240420 00000000 */  nop       
/* A93B64 80240424 4501002E */  bc1t      .L802404E0
/* A93B68 80240428 2402FFFF */   addiu    $v0, $zero, -1
/* A93B6C 8024042C 8E220000 */  lw        $v0, ($s1)
/* A93B70 80240430 C600003C */  lwc1      $f0, 0x3c($s0)
/* A93B74 80240434 C442002C */  lwc1      $f2, 0x2c($v0)
/* A93B78 80240438 860200A8 */  lh        $v0, 0xa8($s0)
/* A93B7C 8024043C 46020001 */  sub.s     $f0, $f0, $f2
/* A93B80 80240440 44821000 */  mtc1      $v0, $f2
/* A93B84 80240444 00000000 */  nop       
/* A93B88 80240448 468010A1 */  cvt.d.w   $f2, $f2
/* A93B8C 8024044C 46221080 */  add.d     $f2, $f2, $f2
/* A93B90 80240450 46000005 */  abs.s     $f0, $f0
/* A93B94 80240454 46000021 */  cvt.d.s   $f0, $f0
/* A93B98 80240458 4620103E */  c.le.d    $f2, $f0
/* A93B9C 8024045C 00000000 */  nop       
/* A93BA0 80240460 4501001F */  bc1t      .L802404E0
/* A93BA4 80240464 2402FFFF */   addiu    $v0, $zero, -1
/* A93BA8 80240468 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* A93BAC 8024046C 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* A93BB0 80240470 24020009 */  addiu     $v0, $zero, 9
/* A93BB4 80240474 10620019 */  beq       $v1, $v0, .L802404DC
/* A93BB8 80240478 24020007 */   addiu    $v0, $zero, 7
/* A93BBC 8024047C 14620005 */  bne       $v1, $v0, .L80240494
/* A93BC0 80240480 2402FFFF */   addiu    $v0, $zero, -1
/* A93BC4 80240484 08090138 */  j         .L802404E0
/* A93BC8 80240488 00000000 */   nop      
.L8024048C:
/* A93BCC 8024048C 08090138 */  j         .L802404E0
/* A93BD0 80240490 0240102D */   daddu    $v0, $s2, $zero
.L80240494:
/* A93BD4 80240494 8E620078 */  lw        $v0, 0x78($s3)
/* A93BD8 80240498 18400010 */  blez      $v0, .L802404DC
/* A93BDC 8024049C 0000882D */   daddu    $s1, $zero, $zero
.L802404A0:
/* A93BE0 802404A0 86620008 */  lh        $v0, 8($s3)
/* A93BE4 802404A4 00511021 */  addu      $v0, $v0, $s1
/* A93BE8 802404A8 24520001 */  addiu     $s2, $v0, 1
/* A93BEC 802404AC 0C00FB3A */  jal       get_enemy
/* A93BF0 802404B0 0240202D */   daddu    $a0, $s2, $zero
/* A93BF4 802404B4 0240202D */  daddu     $a0, $s2, $zero
/* A93BF8 802404B8 0C00EABB */  jal       get_npc_unsafe
/* A93BFC 802404BC 0040802D */   daddu    $s0, $v0, $zero
/* A93C00 802404C0 8E02006C */  lw        $v0, 0x6c($s0)
/* A93C04 802404C4 1040FFF1 */  beqz      $v0, .L8024048C
/* A93C08 802404C8 26310001 */   addiu    $s1, $s1, 1
/* A93C0C 802404CC 8E620078 */  lw        $v0, 0x78($s3)
/* A93C10 802404D0 0222102A */  slt       $v0, $s1, $v0
/* A93C14 802404D4 1440FFF2 */  bnez      $v0, .L802404A0
/* A93C18 802404D8 00000000 */   nop      
.L802404DC:
/* A93C1C 802404DC 2402FFFF */  addiu     $v0, $zero, -1
.L802404E0:
/* A93C20 802404E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* A93C24 802404E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* A93C28 802404E8 8FB20018 */  lw        $s2, 0x18($sp)
/* A93C2C 802404EC 8FB10014 */  lw        $s1, 0x14($sp)
/* A93C30 802404F0 8FB00010 */  lw        $s0, 0x10($sp)
/* A93C34 802404F4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A93C38 802404F8 03E00008 */  jr        $ra
/* A93C3C 802404FC 27BD0030 */   addiu    $sp, $sp, 0x30

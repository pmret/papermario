.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243240_A9C7D0
.double 180.0

glabel D_80243248_A9C7D8
.double 75.0

.section .text

glabel func_80240170_A99700
/* A99700 80240170 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A99704 80240174 AFB10014 */  sw        $s1, 0x14($sp)
/* A99708 80240178 0080882D */  daddu     $s1, $a0, $zero
/* A9970C 8024017C 3C05800B */  lui       $a1, %hi(gCameras)
/* A99710 80240180 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A99714 80240184 AFBF0020 */  sw        $ra, 0x20($sp)
/* A99718 80240188 AFB3001C */  sw        $s3, 0x1c($sp)
/* A9971C 8024018C AFB20018 */  sw        $s2, 0x18($sp)
/* A99720 80240190 AFB00010 */  sw        $s0, 0x10($sp)
/* A99724 80240194 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A99728 80240198 8E330148 */  lw        $s3, 0x148($s1)
/* A9972C 8024019C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A99730 802401A0 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A99734 802401A4 8E30000C */  lw        $s0, 0xc($s1)
/* A99738 802401A8 00031080 */  sll       $v0, $v1, 2
/* A9973C 802401AC 00431021 */  addu      $v0, $v0, $v1
/* A99740 802401B0 00021080 */  sll       $v0, $v0, 2
/* A99744 802401B4 00431023 */  subu      $v0, $v0, $v1
/* A99748 802401B8 000218C0 */  sll       $v1, $v0, 3
/* A9974C 802401BC 00431021 */  addu      $v0, $v0, $v1
/* A99750 802401C0 000210C0 */  sll       $v0, $v0, 3
/* A99754 802401C4 86640008 */  lh        $a0, 8($s3)
/* A99758 802401C8 0C00EABB */  jal       get_npc_unsafe
/* A9975C 802401CC 00459021 */   addu     $s2, $v0, $a1
/* A99760 802401D0 0220202D */  daddu     $a0, $s1, $zero
/* A99764 802401D4 8E050000 */  lw        $a1, ($s0)
/* A99768 802401D8 0C0B1EAF */  jal       get_variable
/* A9976C 802401DC 0040802D */   daddu    $s0, $v0, $zero
/* A99770 802401E0 0260202D */  daddu     $a0, $s3, $zero
/* A99774 802401E4 8C460024 */  lw        $a2, 0x24($v0)
/* A99778 802401E8 8C470028 */  lw        $a3, 0x28($v0)
/* A9977C 802401EC 0C0124FB */  jal       func_800493EC
/* A99780 802401F0 0000282D */   daddu    $a1, $zero, $zero
/* A99784 802401F4 10400052 */  beqz      $v0, .L80240340
/* A99788 802401F8 2402FFFF */   addiu    $v0, $zero, -1
/* A9978C 802401FC C64C006C */  lwc1      $f12, 0x6c($s2)
/* A99790 80240200 C60E000C */  lwc1      $f14, 0xc($s0)
/* A99794 80240204 3C014387 */  lui       $at, 0x4387
/* A99798 80240208 4481A000 */  mtc1      $at, $f20
/* A9979C 8024020C 0C00A70A */  jal       get_clamped_angle_diff
/* A997A0 80240210 00000000 */   nop
/* A997A4 80240214 0C00A6C9 */  jal       clamp_angle
/* A997A8 80240218 46000306 */   mov.s    $f12, $f0
/* A997AC 8024021C 3C018024 */  lui       $at, %hi(D_80243240_A9C7D0)
/* A997B0 80240220 D4223240 */  ldc1      $f2, %lo(D_80243240_A9C7D0)($at)
/* A997B4 80240224 46000021 */  cvt.d.s   $f0, $f0
/* A997B8 80240228 4622003C */  c.lt.d    $f0, $f2
/* A997BC 8024022C 00000000 */  nop
/* A997C0 80240230 45000003 */  bc1f      .L80240240
/* A997C4 80240234 00000000 */   nop
/* A997C8 80240238 3C0142B4 */  lui       $at, 0x42b4
/* A997CC 8024023C 4481A000 */  mtc1      $at, $f20
.L80240240:
/* A997D0 80240240 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A997D4 80240244 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A997D8 80240248 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A997DC 8024024C 8E220000 */  lw        $v0, ($s1)
/* A997E0 80240250 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A997E4 80240254 8C460028 */  lw        $a2, 0x28($v0)
/* A997E8 80240258 0C00A720 */  jal       atan2
/* A997EC 8024025C 8C470030 */   lw       $a3, 0x30($v0)
/* A997F0 80240260 4600A306 */  mov.s     $f12, $f20
/* A997F4 80240264 0C00A70A */  jal       get_clamped_angle_diff
/* A997F8 80240268 46000386 */   mov.s    $f14, $f0
/* A997FC 8024026C 46000005 */  abs.s     $f0, $f0
/* A99800 80240270 3C018024 */  lui       $at, %hi(D_80243248_A9C7D8)
/* A99804 80240274 D4223248 */  ldc1      $f2, %lo(D_80243248_A9C7D8)($at)
/* A99808 80240278 46000021 */  cvt.d.s   $f0, $f0
/* A9980C 8024027C 4620103C */  c.lt.d    $f2, $f0
/* A99810 80240280 00000000 */  nop
/* A99814 80240284 4501002E */  bc1t      .L80240340
/* A99818 80240288 2402FFFF */   addiu    $v0, $zero, -1
/* A9981C 8024028C 8E220000 */  lw        $v0, ($s1)
/* A99820 80240290 C600003C */  lwc1      $f0, 0x3c($s0)
/* A99824 80240294 C442002C */  lwc1      $f2, 0x2c($v0)
/* A99828 80240298 860200A8 */  lh        $v0, 0xa8($s0)
/* A9982C 8024029C 46020001 */  sub.s     $f0, $f0, $f2
/* A99830 802402A0 44821000 */  mtc1      $v0, $f2
/* A99834 802402A4 00000000 */  nop
/* A99838 802402A8 468010A1 */  cvt.d.w   $f2, $f2
/* A9983C 802402AC 46221080 */  add.d     $f2, $f2, $f2
/* A99840 802402B0 46000005 */  abs.s     $f0, $f0
/* A99844 802402B4 46000021 */  cvt.d.s   $f0, $f0
/* A99848 802402B8 4620103E */  c.le.d    $f2, $f0
/* A9984C 802402BC 00000000 */  nop
/* A99850 802402C0 4501001F */  bc1t      .L80240340
/* A99854 802402C4 2402FFFF */   addiu    $v0, $zero, -1
/* A99858 802402C8 3C038011 */  lui       $v1, %hi(gPartnerActionStatus+0x3)
/* A9985C 802402CC 8063EBB3 */  lb        $v1, %lo(gPartnerActionStatus+0x3)($v1)
/* A99860 802402D0 24020009 */  addiu     $v0, $zero, 9
/* A99864 802402D4 10620019 */  beq       $v1, $v0, .L8024033C
/* A99868 802402D8 24020007 */   addiu    $v0, $zero, 7
/* A9986C 802402DC 14620005 */  bne       $v1, $v0, .L802402F4
/* A99870 802402E0 2402FFFF */   addiu    $v0, $zero, -1
/* A99874 802402E4 080900D0 */  j         .L80240340
/* A99878 802402E8 00000000 */   nop
.L802402EC:
/* A9987C 802402EC 080900D0 */  j         .L80240340
/* A99880 802402F0 0240102D */   daddu    $v0, $s2, $zero
.L802402F4:
/* A99884 802402F4 8E620078 */  lw        $v0, 0x78($s3)
/* A99888 802402F8 18400010 */  blez      $v0, .L8024033C
/* A9988C 802402FC 0000882D */   daddu    $s1, $zero, $zero
.L80240300:
/* A99890 80240300 86620008 */  lh        $v0, 8($s3)
/* A99894 80240304 00511021 */  addu      $v0, $v0, $s1
/* A99898 80240308 24520001 */  addiu     $s2, $v0, 1
/* A9989C 8024030C 0C00FB3A */  jal       get_enemy
/* A998A0 80240310 0240202D */   daddu    $a0, $s2, $zero
/* A998A4 80240314 0240202D */  daddu     $a0, $s2, $zero
/* A998A8 80240318 0C00EABB */  jal       get_npc_unsafe
/* A998AC 8024031C 0040802D */   daddu    $s0, $v0, $zero
/* A998B0 80240320 8E02006C */  lw        $v0, 0x6c($s0)
/* A998B4 80240324 1040FFF1 */  beqz      $v0, .L802402EC
/* A998B8 80240328 26310001 */   addiu    $s1, $s1, 1
/* A998BC 8024032C 8E620078 */  lw        $v0, 0x78($s3)
/* A998C0 80240330 0222102A */  slt       $v0, $s1, $v0
/* A998C4 80240334 1440FFF2 */  bnez      $v0, .L80240300
/* A998C8 80240338 00000000 */   nop
.L8024033C:
/* A998CC 8024033C 2402FFFF */  addiu     $v0, $zero, -1
.L80240340:
/* A998D0 80240340 8FBF0020 */  lw        $ra, 0x20($sp)
/* A998D4 80240344 8FB3001C */  lw        $s3, 0x1c($sp)
/* A998D8 80240348 8FB20018 */  lw        $s2, 0x18($sp)
/* A998DC 8024034C 8FB10014 */  lw        $s1, 0x14($sp)
/* A998E0 80240350 8FB00010 */  lw        $s0, 0x10($sp)
/* A998E4 80240354 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A998E8 80240358 03E00008 */  jr        $ra
/* A998EC 8024035C 27BD0030 */   addiu    $sp, $sp, 0x30

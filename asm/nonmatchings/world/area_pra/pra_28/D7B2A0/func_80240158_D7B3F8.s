.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_D7B3F8
/* D7B3F8 80240158 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D7B3FC 8024015C AFB00040 */  sw        $s0, 0x40($sp)
/* D7B400 80240160 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D7B404 80240164 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D7B408 80240168 AFB20048 */  sw        $s2, 0x48($sp)
/* D7B40C 8024016C AFBF004C */  sw        $ra, 0x4c($sp)
/* D7B410 80240170 AFB10044 */  sw        $s1, 0x44($sp)
/* D7B414 80240174 8E020000 */  lw        $v0, ($s0)
/* D7B418 80240178 821100BE */  lb        $s1, 0xbe($s0)
/* D7B41C 8024017C 30420001 */  andi      $v0, $v0, 1
/* D7B420 80240180 10400061 */  beqz      $v0, .L80240308
/* D7B424 80240184 27B20020 */   addiu    $s2, $sp, 0x20
/* D7B428 80240188 8E0400CC */  lw        $a0, 0xcc($s0)
/* D7B42C 8024018C 0C044181 */  jal       get_shadow_by_index
/* D7B430 80240190 00000000 */   nop      
/* D7B434 80240194 0C048B77 */  jal       func_80122DDC
/* D7B438 80240198 84440008 */   lh       $a0, 8($v0)
/* D7B43C 8024019C 8C430000 */  lw        $v1, ($v0)
/* D7B440 802401A0 34630200 */  ori       $v1, $v1, 0x200
/* D7B444 802401A4 AC430000 */  sw        $v1, ($v0)
/* D7B448 802401A8 8E050028 */  lw        $a1, 0x28($s0)
/* D7B44C 802401AC 8E06002C */  lw        $a2, 0x2c($s0)
/* D7B450 802401B0 27A20030 */  addiu     $v0, $sp, 0x30
/* D7B454 802401B4 AFA20010 */  sw        $v0, 0x10($sp)
/* D7B458 802401B8 27A20034 */  addiu     $v0, $sp, 0x34
/* D7B45C 802401BC AFA20014 */  sw        $v0, 0x14($sp)
/* D7B460 802401C0 C6000030 */  lwc1      $f0, 0x30($s0)
/* D7B464 802401C4 3C04800A */  lui       $a0, 0x800a
/* D7B468 802401C8 8484A634 */  lh        $a0, -0x59cc($a0)
/* D7B46C 802401CC 46000007 */  neg.s     $f0, $f0
/* D7B470 802401D0 44070000 */  mfc1      $a3, $f0
/* D7B474 802401D4 27A20038 */  addiu     $v0, $sp, 0x38
/* D7B478 802401D8 0C00B94E */  jal       get_screen_coords
/* D7B47C 802401DC AFA20018 */   sw       $v0, 0x18($sp)
/* D7B480 802401E0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D7B484 802401E4 0C090014 */  jal       func_80240050_D7B2F0
/* D7B488 802401E8 00000000 */   nop      
/* D7B48C 802401EC C6020080 */  lwc1      $f2, 0x80($s0)
/* D7B490 802401F0 3C014307 */  lui       $at, 0x4307
/* D7B494 802401F4 44810000 */  mtc1      $at, $f0
/* D7B498 802401F8 00000000 */  nop       
/* D7B49C 802401FC 4602003C */  c.lt.s    $f0, $f2
/* D7B4A0 80240200 00000000 */  nop       
/* D7B4A4 80240204 4500000B */  bc1f      .L80240234
/* D7B4A8 80240208 24040002 */   addiu    $a0, $zero, 2
/* D7B4AC 8024020C 3C014361 */  lui       $at, 0x4361
/* D7B4B0 80240210 44810000 */  mtc1      $at, $f0
/* D7B4B4 80240214 00000000 */  nop       
/* D7B4B8 80240218 4600103C */  c.lt.s    $f2, $f0
/* D7B4BC 8024021C 00000000 */  nop       
/* D7B4C0 80240220 45000004 */  bc1f      .L80240234
/* D7B4C4 80240224 00000000 */   nop      
/* D7B4C8 80240228 0C090021 */  jal       func_80240084_D7B324
/* D7B4CC 8024022C 0040202D */   daddu    $a0, $v0, $zero
/* D7B4D0 80240230 24040002 */  addiu     $a0, $zero, 2
.L80240234:
/* D7B4D4 80240234 3C063F80 */  lui       $a2, 0x3f80
/* D7B4D8 80240238 0C0B76A3 */  jal       func_802DDA8C
/* D7B4DC 8024023C 0040282D */   daddu    $a1, $v0, $zero
/* D7B4E0 80240240 8E020000 */  lw        $v0, ($s0)
/* D7B4E4 80240244 3C030002 */  lui       $v1, 2
/* D7B4E8 80240248 00431024 */  and       $v0, $v0, $v1
/* D7B4EC 8024024C 54400022 */  bnel      $v0, $zero, .L802402D8
/* D7B4F0 80240250 24110011 */   addiu    $s1, $zero, 0x11
/* D7B4F4 80240254 9203000E */  lbu       $v1, 0xe($s0)
/* D7B4F8 80240258 3C02802E */  lui       $v0, 0x802e
/* D7B4FC 8024025C 90429D70 */  lbu       $v0, -0x6290($v0)
/* D7B500 80240260 10620018 */  beq       $v1, $v0, .L802402C4
/* D7B504 80240264 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D7B508 80240268 1040000B */  beqz      $v0, .L80240298
/* D7B50C 8024026C 24110011 */   addiu    $s1, $zero, 0x11
/* D7B510 80240270 24040002 */  addiu     $a0, $zero, 2
/* D7B514 80240274 2405FFFF */  addiu     $a1, $zero, -1
/* D7B518 80240278 24060007 */  addiu     $a2, $zero, 7
/* D7B51C 8024027C 0060102D */  daddu     $v0, $v1, $zero
/* D7B520 80240280 0000382D */  daddu     $a3, $zero, $zero
/* D7B524 80240284 AFA00010 */  sw        $zero, 0x10($sp)
/* D7B528 80240288 AFA00014 */  sw        $zero, 0x14($sp)
/* D7B52C 8024028C AFA0001C */  sw        $zero, 0x1c($sp)
/* D7B530 80240290 080900AF */  j         .L802402BC
/* D7B534 80240294 AFA20018 */   sw       $v0, 0x18($sp)
.L80240298:
/* D7B538 80240298 2411000D */  addiu     $s1, $zero, 0xd
/* D7B53C 8024029C 24040002 */  addiu     $a0, $zero, 2
/* D7B540 802402A0 2405FFFF */  addiu     $a1, $zero, -1
/* D7B544 802402A4 0000302D */  daddu     $a2, $zero, $zero
/* D7B548 802402A8 00C0382D */  daddu     $a3, $a2, $zero
/* D7B54C 802402AC AFA00010 */  sw        $zero, 0x10($sp)
/* D7B550 802402B0 AFA00014 */  sw        $zero, 0x14($sp)
/* D7B554 802402B4 AFA00018 */  sw        $zero, 0x18($sp)
/* D7B558 802402B8 AFA0001C */  sw        $zero, 0x1c($sp)
.L802402BC:
/* D7B55C 802402BC 0C0B77B9 */  jal       func_802DDEE4
/* D7B560 802402C0 00000000 */   nop      
.L802402C4:
/* D7B564 802402C4 9202000E */  lbu       $v0, 0xe($s0)
/* D7B568 802402C8 3C01802E */  lui       $at, 0x802e
/* D7B56C 802402CC A0229D70 */  sb        $v0, -0x6290($at)
/* D7B570 802402D0 080900B9 */  j         .L802402E4
/* D7B574 802402D4 0240202D */   daddu    $a0, $s2, $zero
.L802402D8:
/* D7B578 802402D8 3C01802E */  lui       $at, 0x802e
/* D7B57C 802402DC A0209D70 */  sb        $zero, -0x6290($at)
/* D7B580 802402E0 0240202D */  daddu     $a0, $s2, $zero
.L802402E4:
/* D7B584 802402E4 AC910000 */  sw        $s1, ($a0)
/* D7B588 802402E8 AC900008 */  sw        $s0, 8($a0)
/* D7B58C 802402EC 8FA20038 */  lw        $v0, 0x38($sp)
/* D7B590 802402F0 3C038024 */  lui       $v1, 0x8024
/* D7B594 802402F4 24630320 */  addiu     $v1, $v1, 0x320
/* D7B598 802402F8 AC83000C */  sw        $v1, 0xc($a0)
/* D7B59C 802402FC 00021023 */  negu      $v0, $v0
/* D7B5A0 80240300 0C047644 */  jal       queue_render_task
/* D7B5A4 80240304 AC820004 */   sw       $v0, 4($a0)
.L80240308:
/* D7B5A8 80240308 8FBF004C */  lw        $ra, 0x4c($sp)
/* D7B5AC 8024030C 8FB20048 */  lw        $s2, 0x48($sp)
/* D7B5B0 80240310 8FB10044 */  lw        $s1, 0x44($sp)
/* D7B5B4 80240314 8FB00040 */  lw        $s0, 0x40($sp)
/* D7B5B8 80240318 03E00008 */  jr        $ra
/* D7B5BC 8024031C 27BD0050 */   addiu    $sp, $sp, 0x50

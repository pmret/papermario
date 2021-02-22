.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D8D378
/* D8D378 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D8D37C 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D8D380 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D8D384 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D8D388 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D8D38C 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D8D390 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D8D394 80240144 8E020000 */  lw        $v0, ($s0)
/* D8D398 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D8D39C 8024014C 30420001 */  andi      $v0, $v0, 1
/* D8D3A0 80240150 10400061 */  beqz      $v0, .L802402D8
/* D8D3A4 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D8D3A8 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D8D3AC 8024015C 0C044181 */  jal       get_shadow_by_index
/* D8D3B0 80240160 00000000 */   nop
/* D8D3B4 80240164 0C048B77 */  jal       func_80122DDC
/* D8D3B8 80240168 84440008 */   lh       $a0, 8($v0)
/* D8D3BC 8024016C 8C430000 */  lw        $v1, ($v0)
/* D8D3C0 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D8D3C4 80240174 AC430000 */  sw        $v1, ($v0)
/* D8D3C8 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D8D3CC 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D8D3D0 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D8D3D4 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D8D3D8 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D8D3DC 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D8D3E0 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D8D3E4 80240194 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D8D3E8 80240198 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D8D3EC 8024019C 46000007 */  neg.s     $f0, $f0
/* D8D3F0 802401A0 44070000 */  mfc1      $a3, $f0
/* D8D3F4 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D8D3F8 802401A8 0C00B94E */  jal       get_screen_coords
/* D8D3FC 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D8D400 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D8D404 802401B4 0C090008 */  jal       pra_35_UnkFunc2
/* D8D408 802401B8 00000000 */   nop
/* D8D40C 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D8D410 802401C0 3C014307 */  lui       $at, 0x4307
/* D8D414 802401C4 44810000 */  mtc1      $at, $f0
/* D8D418 802401C8 00000000 */  nop
/* D8D41C 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D8D420 802401D0 00000000 */  nop
/* D8D424 802401D4 4500000B */  bc1f      .L80240204
/* D8D428 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D8D42C 802401DC 3C014361 */  lui       $at, 0x4361
/* D8D430 802401E0 44810000 */  mtc1      $at, $f0
/* D8D434 802401E4 00000000 */  nop
/* D8D438 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D8D43C 802401EC 00000000 */  nop
/* D8D440 802401F0 45000004 */  bc1f      .L80240204
/* D8D444 802401F4 00000000 */   nop
/* D8D448 802401F8 0C090015 */  jal       pra_35_UnkFunc3
/* D8D44C 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D8D450 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D8D454 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D8D458 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D8D45C 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D8D460 80240210 8E020000 */  lw        $v0, ($s0)
/* D8D464 80240214 3C030002 */  lui       $v1, 2
/* D8D468 80240218 00431024 */  and       $v0, $v0, $v1
/* D8D46C 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D8D470 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D8D474 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D8D478 80240228 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D8D47C 8024022C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D8D480 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D8D484 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D8D488 80240238 1040000B */  beqz      $v0, .L80240268
/* D8D48C 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D8D490 80240240 24040002 */  addiu     $a0, $zero, 2
/* D8D494 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D8D498 80240248 24060007 */  addiu     $a2, $zero, 7
/* D8D49C 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D8D4A0 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D8D4A4 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D8D4A8 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D8D4AC 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D8D4B0 80240260 080900A3 */  j         .L8024028C
/* D8D4B4 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D8D4B8 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D8D4BC 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D8D4C0 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D8D4C4 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D8D4C8 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D8D4CC 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D8D4D0 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D8D4D4 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D8D4D8 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D8D4DC 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D8D4E0 80240290 00000000 */   nop
.L80240294:
/* D8D4E4 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D8D4E8 80240298 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D8D4EC 8024029C A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D8D4F0 802402A0 080900AD */  j         .L802402B4
/* D8D4F4 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D8D4F8 802402A8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D8D4FC 802402AC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D8D500 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D8D504 802402B4 AC910000 */  sw        $s1, ($a0)
/* D8D508 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D8D50C 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D8D510 802402C0 3C038024 */  lui       $v1, %hi(func_802402F0_D8D540)
/* D8D514 802402C4 246302F0 */  addiu     $v1, $v1, %lo(func_802402F0_D8D540)
/* D8D518 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D8D51C 802402CC 00021023 */  negu      $v0, $v0
/* D8D520 802402D0 0C047644 */  jal       queue_render_task
/* D8D524 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D8D528 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D8D52C 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D8D530 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D8D534 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D8D538 802402E8 03E00008 */  jr        $ra
/* D8D53C 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50

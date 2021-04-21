.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D5F3D8
/* D5F3D8 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D5F3DC 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D5F3E0 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D5F3E4 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D5F3E8 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D5F3EC 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D5F3F0 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D5F3F4 80240144 8E020000 */  lw        $v0, ($s0)
/* D5F3F8 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D5F3FC 8024014C 30420001 */  andi      $v0, $v0, 1
/* D5F400 80240150 10400061 */  beqz      $v0, .L802402D8
/* D5F404 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D5F408 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D5F40C 8024015C 0C044181 */  jal       get_shadow_by_index
/* D5F410 80240160 00000000 */   nop
/* D5F414 80240164 0C048B77 */  jal       get_entity_model
/* D5F418 80240168 84440008 */   lh       $a0, 8($v0)
/* D5F41C 8024016C 8C430000 */  lw        $v1, ($v0)
/* D5F420 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D5F424 80240174 AC430000 */  sw        $v1, ($v0)
/* D5F428 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D5F42C 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D5F430 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D5F434 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D5F438 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D5F43C 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D5F440 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D5F444 80240194 3C04800A */  lui       $a0, %hi(gCurrentCamID)
/* D5F448 80240198 8484A634 */  lh        $a0, %lo(gCurrentCamID)($a0)
/* D5F44C 8024019C 46000007 */  neg.s     $f0, $f0
/* D5F450 802401A0 44070000 */  mfc1      $a3, $f0
/* D5F454 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D5F458 802401A8 0C00B94E */  jal       get_screen_coords
/* D5F45C 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D5F460 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D5F464 802401B4 0C090008 */  jal       pra_10_UnkFunc2
/* D5F468 802401B8 00000000 */   nop
/* D5F46C 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D5F470 802401C0 3C014307 */  lui       $at, 0x4307
/* D5F474 802401C4 44810000 */  mtc1      $at, $f0
/* D5F478 802401C8 00000000 */  nop
/* D5F47C 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D5F480 802401D0 00000000 */  nop
/* D5F484 802401D4 4500000B */  bc1f      .L80240204
/* D5F488 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D5F48C 802401DC 3C014361 */  lui       $at, 0x4361
/* D5F490 802401E0 44810000 */  mtc1      $at, $f0
/* D5F494 802401E4 00000000 */  nop
/* D5F498 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D5F49C 802401EC 00000000 */  nop
/* D5F4A0 802401F0 45000004 */  bc1f      .L80240204
/* D5F4A4 802401F4 00000000 */   nop
/* D5F4A8 802401F8 0C090015 */  jal       pra_10_UnkFunc3
/* D5F4AC 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D5F4B0 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D5F4B4 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D5F4B8 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D5F4BC 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D5F4C0 80240210 8E020000 */  lw        $v0, ($s0)
/* D5F4C4 80240214 3C030002 */  lui       $v1, 2
/* D5F4C8 80240218 00431024 */  and       $v0, $v0, $v1
/* D5F4CC 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D5F4D0 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D5F4D4 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D5F4D8 80240228 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D5F4DC 8024022C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D5F4E0 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D5F4E4 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D5F4E8 80240238 1040000B */  beqz      $v0, .L80240268
/* D5F4EC 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D5F4F0 80240240 24040002 */  addiu     $a0, $zero, 2
/* D5F4F4 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D5F4F8 80240248 24060007 */  addiu     $a2, $zero, 7
/* D5F4FC 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D5F500 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D5F504 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D5F508 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D5F50C 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D5F510 80240260 080900A3 */  j         .L8024028C
/* D5F514 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D5F518 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D5F51C 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D5F520 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D5F524 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D5F528 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D5F52C 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D5F530 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D5F534 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D5F538 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D5F53C 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D5F540 80240290 00000000 */   nop
.L80240294:
/* D5F544 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D5F548 80240298 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D5F54C 8024029C A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D5F550 802402A0 080900AD */  j         .L802402B4
/* D5F554 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D5F558 802402A8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D5F55C 802402AC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D5F560 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D5F564 802402B4 AC910000 */  sw        $s1, ($a0)
/* D5F568 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D5F56C 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D5F570 802402C0 3C038024 */  lui       $v1, %hi(func_802402F0_D5F5A0)
/* D5F574 802402C4 246302F0 */  addiu     $v1, $v1, %lo(func_802402F0_D5F5A0)
/* D5F578 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D5F57C 802402CC 00021023 */  negu      $v0, $v0
/* D5F580 802402D0 0C047644 */  jal       queue_render_task
/* D5F584 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D5F588 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D5F58C 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D5F590 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D5F594 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D5F598 802402E8 03E00008 */  jr        $ra
/* D5F59C 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50

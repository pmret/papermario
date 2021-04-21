.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D8B4D8
/* D8B4D8 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D8B4DC 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D8B4E0 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D8B4E4 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D8B4E8 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D8B4EC 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D8B4F0 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D8B4F4 80240144 8E020000 */  lw        $v0, ($s0)
/* D8B4F8 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D8B4FC 8024014C 30420001 */  andi      $v0, $v0, 1
/* D8B500 80240150 10400061 */  beqz      $v0, .L802402D8
/* D8B504 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D8B508 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D8B50C 8024015C 0C044181 */  jal       get_shadow_by_index
/* D8B510 80240160 00000000 */   nop
/* D8B514 80240164 0C048B77 */  jal       get_entity_model
/* D8B518 80240168 84440008 */   lh       $a0, 8($v0)
/* D8B51C 8024016C 8C430000 */  lw        $v1, ($v0)
/* D8B520 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D8B524 80240174 AC430000 */  sw        $v1, ($v0)
/* D8B528 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D8B52C 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D8B530 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D8B534 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D8B538 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D8B53C 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D8B540 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D8B544 80240194 3C04800A */  lui       $a0, %hi(gCurrentCamID)
/* D8B548 80240198 8484A634 */  lh        $a0, %lo(gCurrentCamID)($a0)
/* D8B54C 8024019C 46000007 */  neg.s     $f0, $f0
/* D8B550 802401A0 44070000 */  mfc1      $a3, $f0
/* D8B554 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D8B558 802401A8 0C00B94E */  jal       get_screen_coords
/* D8B55C 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D8B560 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D8B564 802401B4 0C090008 */  jal       pra_34_UnkFunc2
/* D8B568 802401B8 00000000 */   nop
/* D8B56C 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D8B570 802401C0 3C014307 */  lui       $at, 0x4307
/* D8B574 802401C4 44810000 */  mtc1      $at, $f0
/* D8B578 802401C8 00000000 */  nop
/* D8B57C 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D8B580 802401D0 00000000 */  nop
/* D8B584 802401D4 4500000B */  bc1f      .L80240204
/* D8B588 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D8B58C 802401DC 3C014361 */  lui       $at, 0x4361
/* D8B590 802401E0 44810000 */  mtc1      $at, $f0
/* D8B594 802401E4 00000000 */  nop
/* D8B598 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D8B59C 802401EC 00000000 */  nop
/* D8B5A0 802401F0 45000004 */  bc1f      .L80240204
/* D8B5A4 802401F4 00000000 */   nop
/* D8B5A8 802401F8 0C090015 */  jal       pra_34_UnkFunc3
/* D8B5AC 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D8B5B0 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D8B5B4 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D8B5B8 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D8B5BC 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D8B5C0 80240210 8E020000 */  lw        $v0, ($s0)
/* D8B5C4 80240214 3C030002 */  lui       $v1, 2
/* D8B5C8 80240218 00431024 */  and       $v0, $v0, $v1
/* D8B5CC 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D8B5D0 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D8B5D4 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D8B5D8 80240228 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D8B5DC 8024022C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D8B5E0 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D8B5E4 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D8B5E8 80240238 1040000B */  beqz      $v0, .L80240268
/* D8B5EC 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D8B5F0 80240240 24040002 */  addiu     $a0, $zero, 2
/* D8B5F4 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D8B5F8 80240248 24060007 */  addiu     $a2, $zero, 7
/* D8B5FC 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D8B600 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D8B604 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D8B608 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D8B60C 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D8B610 80240260 080900A3 */  j         .L8024028C
/* D8B614 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D8B618 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D8B61C 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D8B620 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D8B624 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D8B628 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D8B62C 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D8B630 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D8B634 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D8B638 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D8B63C 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D8B640 80240290 00000000 */   nop
.L80240294:
/* D8B644 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D8B648 80240298 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D8B64C 8024029C A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D8B650 802402A0 080900AD */  j         .L802402B4
/* D8B654 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D8B658 802402A8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D8B65C 802402AC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D8B660 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D8B664 802402B4 AC910000 */  sw        $s1, ($a0)
/* D8B668 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D8B66C 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D8B670 802402C0 3C038024 */  lui       $v1, %hi(func_802402F0_D8B6A0)
/* D8B674 802402C4 246302F0 */  addiu     $v1, $v1, %lo(func_802402F0_D8B6A0)
/* D8B678 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D8B67C 802402CC 00021023 */  negu      $v0, $v0
/* D8B680 802402D0 0C047644 */  jal       queue_render_task
/* D8B684 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D8B688 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D8B68C 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D8B690 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D8B694 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D8B698 802402E8 03E00008 */  jr        $ra
/* D8B69C 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50

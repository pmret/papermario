.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D589B8
/* D589B8 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D589BC 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D589C0 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D589C4 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D589C8 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D589CC 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D589D0 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D589D4 80240144 8E020000 */  lw        $v0, ($s0)
/* D589D8 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D589DC 8024014C 30420001 */  andi      $v0, $v0, 1
/* D589E0 80240150 10400061 */  beqz      $v0, .L802402D8
/* D589E4 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D589E8 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D589EC 8024015C 0C044181 */  jal       get_shadow_by_index
/* D589F0 80240160 00000000 */   nop
/* D589F4 80240164 0C048B77 */  jal       get_entity_model
/* D589F8 80240168 84440008 */   lh       $a0, 8($v0)
/* D589FC 8024016C 8C430000 */  lw        $v1, ($v0)
/* D58A00 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D58A04 80240174 AC430000 */  sw        $v1, ($v0)
/* D58A08 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D58A0C 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D58A10 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D58A14 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D58A18 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D58A1C 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D58A20 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D58A24 80240194 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D58A28 80240198 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D58A2C 8024019C 46000007 */  neg.s     $f0, $f0
/* D58A30 802401A0 44070000 */  mfc1      $a3, $f0
/* D58A34 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D58A38 802401A8 0C00B94E */  jal       get_screen_coords
/* D58A3C 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D58A40 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D58A44 802401B4 0C090008 */  jal       pra_09_UnkFunc2
/* D58A48 802401B8 00000000 */   nop
/* D58A4C 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D58A50 802401C0 3C014307 */  lui       $at, 0x4307
/* D58A54 802401C4 44810000 */  mtc1      $at, $f0
/* D58A58 802401C8 00000000 */  nop
/* D58A5C 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D58A60 802401D0 00000000 */  nop
/* D58A64 802401D4 4500000B */  bc1f      .L80240204
/* D58A68 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D58A6C 802401DC 3C014361 */  lui       $at, 0x4361
/* D58A70 802401E0 44810000 */  mtc1      $at, $f0
/* D58A74 802401E4 00000000 */  nop
/* D58A78 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D58A7C 802401EC 00000000 */  nop
/* D58A80 802401F0 45000004 */  bc1f      .L80240204
/* D58A84 802401F4 00000000 */   nop
/* D58A88 802401F8 0C090015 */  jal       pra_09_UnkFunc3
/* D58A8C 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D58A90 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D58A94 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D58A98 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D58A9C 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D58AA0 80240210 8E020000 */  lw        $v0, ($s0)
/* D58AA4 80240214 3C030002 */  lui       $v1, 2
/* D58AA8 80240218 00431024 */  and       $v0, $v0, $v1
/* D58AAC 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D58AB0 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D58AB4 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D58AB8 80240228 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D58ABC 8024022C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D58AC0 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D58AC4 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D58AC8 80240238 1040000B */  beqz      $v0, .L80240268
/* D58ACC 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D58AD0 80240240 24040002 */  addiu     $a0, $zero, 2
/* D58AD4 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D58AD8 80240248 24060007 */  addiu     $a2, $zero, 7
/* D58ADC 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D58AE0 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D58AE4 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D58AE8 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D58AEC 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D58AF0 80240260 080900A3 */  j         .L8024028C
/* D58AF4 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D58AF8 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D58AFC 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D58B00 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D58B04 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D58B08 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D58B0C 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D58B10 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D58B14 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D58B18 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D58B1C 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D58B20 80240290 00000000 */   nop
.L80240294:
/* D58B24 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D58B28 80240298 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D58B2C 8024029C A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D58B30 802402A0 080900AD */  j         .L802402B4
/* D58B34 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D58B38 802402A8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D58B3C 802402AC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D58B40 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D58B44 802402B4 AC910000 */  sw        $s1, ($a0)
/* D58B48 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D58B4C 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D58B50 802402C0 3C038024 */  lui       $v1, %hi(func_802402F0_D58B80)
/* D58B54 802402C4 246302F0 */  addiu     $v1, $v1, %lo(func_802402F0_D58B80)
/* D58B58 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D58B5C 802402CC 00021023 */  negu      $v0, $v0
/* D58B60 802402D0 0C047644 */  jal       queue_render_task
/* D58B64 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D58B68 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D58B6C 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D58B70 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D58B74 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D58B78 802402E8 03E00008 */  jr        $ra
/* D58B7C 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50

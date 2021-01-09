.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D4D168
/* D4D168 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D4D16C 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D4D170 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D4D174 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D4D178 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D4D17C 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D4D180 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D4D184 80240144 8E020000 */  lw        $v0, ($s0)
/* D4D188 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D4D18C 8024014C 30420001 */  andi      $v0, $v0, 1
/* D4D190 80240150 10400061 */  beqz      $v0, .L802402D8
/* D4D194 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D4D198 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D4D19C 8024015C 0C044181 */  jal       get_shadow_by_index
/* D4D1A0 80240160 00000000 */   nop      
/* D4D1A4 80240164 0C048B77 */  jal       func_80122DDC
/* D4D1A8 80240168 84440008 */   lh       $a0, 8($v0)
/* D4D1AC 8024016C 8C430000 */  lw        $v1, ($v0)
/* D4D1B0 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D4D1B4 80240174 AC430000 */  sw        $v1, ($v0)
/* D4D1B8 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D4D1BC 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D4D1C0 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D4D1C4 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D4D1C8 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D4D1CC 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D4D1D0 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D4D1D4 80240194 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D4D1D8 80240198 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D4D1DC 8024019C 46000007 */  neg.s     $f0, $f0
/* D4D1E0 802401A0 44070000 */  mfc1      $a3, $f0
/* D4D1E4 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D4D1E8 802401A8 0C00B94E */  jal       get_screen_coords
/* D4D1EC 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D4D1F0 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D4D1F4 802401B4 0C090008 */  jal       func_80240020_D4D060
/* D4D1F8 802401B8 00000000 */   nop      
/* D4D1FC 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D4D200 802401C0 3C014307 */  lui       $at, 0x4307
/* D4D204 802401C4 44810000 */  mtc1      $at, $f0
/* D4D208 802401C8 00000000 */  nop       
/* D4D20C 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D4D210 802401D0 00000000 */  nop       
/* D4D214 802401D4 4500000B */  bc1f      .L80240204
/* D4D218 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D4D21C 802401DC 3C014361 */  lui       $at, 0x4361
/* D4D220 802401E0 44810000 */  mtc1      $at, $f0
/* D4D224 802401E4 00000000 */  nop       
/* D4D228 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D4D22C 802401EC 00000000 */  nop       
/* D4D230 802401F0 45000004 */  bc1f      .L80240204
/* D4D234 802401F4 00000000 */   nop      
/* D4D238 802401F8 0C090015 */  jal       func_80240054_D4D094
/* D4D23C 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D4D240 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D4D244 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D4D248 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D4D24C 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D4D250 80240210 8E020000 */  lw        $v0, ($s0)
/* D4D254 80240214 3C030002 */  lui       $v1, 2
/* D4D258 80240218 00431024 */  and       $v0, $v0, $v1
/* D4D25C 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D4D260 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D4D264 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D4D268 80240228 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D4D26C 8024022C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D4D270 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D4D274 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D4D278 80240238 1040000B */  beqz      $v0, .L80240268
/* D4D27C 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D4D280 80240240 24040002 */  addiu     $a0, $zero, 2
/* D4D284 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D4D288 80240248 24060007 */  addiu     $a2, $zero, 7
/* D4D28C 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D4D290 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D4D294 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D4D298 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D4D29C 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D4D2A0 80240260 080900A3 */  j         .L8024028C
/* D4D2A4 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D4D2A8 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D4D2AC 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D4D2B0 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D4D2B4 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D4D2B8 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D4D2BC 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D4D2C0 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D4D2C4 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D4D2C8 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D4D2CC 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D4D2D0 80240290 00000000 */   nop      
.L80240294:
/* D4D2D4 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D4D2D8 80240298 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D4D2DC 8024029C A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D4D2E0 802402A0 080900AD */  j         .L802402B4
/* D4D2E4 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D4D2E8 802402A8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D4D2EC 802402AC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D4D2F0 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D4D2F4 802402B4 AC910000 */  sw        $s1, ($a0)
/* D4D2F8 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D4D2FC 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D4D300 802402C0 3C038024 */  lui       $v1, %hi(func_802402F0_D4D228)
/* D4D304 802402C4 246302F0 */  addiu     $v1, $v1, %lo(func_802402F0_D4D228)
/* D4D308 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D4D30C 802402CC 00021023 */  negu      $v0, $v0
/* D4D310 802402D0 0C047644 */  jal       queue_render_task
/* D4D314 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D4D318 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D4D31C 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D4D320 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D4D324 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D4D328 802402E8 03E00008 */  jr        $ra
/* D4D32C 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50

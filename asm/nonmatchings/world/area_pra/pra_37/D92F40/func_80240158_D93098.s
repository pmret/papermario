.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_D93098
/* D93098 80240158 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D9309C 8024015C AFB00040 */  sw        $s0, 0x40($sp)
/* D930A0 80240160 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D930A4 80240164 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D930A8 80240168 AFB20048 */  sw        $s2, 0x48($sp)
/* D930AC 8024016C AFBF004C */  sw        $ra, 0x4c($sp)
/* D930B0 80240170 AFB10044 */  sw        $s1, 0x44($sp)
/* D930B4 80240174 8E020000 */  lw        $v0, ($s0)
/* D930B8 80240178 821100BE */  lb        $s1, 0xbe($s0)
/* D930BC 8024017C 30420001 */  andi      $v0, $v0, 1
/* D930C0 80240180 10400061 */  beqz      $v0, .L80240308
/* D930C4 80240184 27B20020 */   addiu    $s2, $sp, 0x20
/* D930C8 80240188 8E0400CC */  lw        $a0, 0xcc($s0)
/* D930CC 8024018C 0C044181 */  jal       get_shadow_by_index
/* D930D0 80240190 00000000 */   nop
/* D930D4 80240194 0C048B77 */  jal       func_80122DDC
/* D930D8 80240198 84440008 */   lh       $a0, 8($v0)
/* D930DC 8024019C 8C430000 */  lw        $v1, ($v0)
/* D930E0 802401A0 34630200 */  ori       $v1, $v1, 0x200
/* D930E4 802401A4 AC430000 */  sw        $v1, ($v0)
/* D930E8 802401A8 8E050028 */  lw        $a1, 0x28($s0)
/* D930EC 802401AC 8E06002C */  lw        $a2, 0x2c($s0)
/* D930F0 802401B0 27A20030 */  addiu     $v0, $sp, 0x30
/* D930F4 802401B4 AFA20010 */  sw        $v0, 0x10($sp)
/* D930F8 802401B8 27A20034 */  addiu     $v0, $sp, 0x34
/* D930FC 802401BC AFA20014 */  sw        $v0, 0x14($sp)
/* D93100 802401C0 C6000030 */  lwc1      $f0, 0x30($s0)
/* D93104 802401C4 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D93108 802401C8 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D9310C 802401CC 46000007 */  neg.s     $f0, $f0
/* D93110 802401D0 44070000 */  mfc1      $a3, $f0
/* D93114 802401D4 27A20038 */  addiu     $v0, $sp, 0x38
/* D93118 802401D8 0C00B94E */  jal       get_screen_coords
/* D9311C 802401DC AFA20018 */   sw       $v0, 0x18($sp)
/* D93120 802401E0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D93124 802401E4 0C090014 */  jal       pra_37_UnkFunc2
/* D93128 802401E8 00000000 */   nop
/* D9312C 802401EC C6020080 */  lwc1      $f2, 0x80($s0)
/* D93130 802401F0 3C014307 */  lui       $at, 0x4307
/* D93134 802401F4 44810000 */  mtc1      $at, $f0
/* D93138 802401F8 00000000 */  nop
/* D9313C 802401FC 4602003C */  c.lt.s    $f0, $f2
/* D93140 80240200 00000000 */  nop
/* D93144 80240204 4500000B */  bc1f      .L80240234
/* D93148 80240208 24040002 */   addiu    $a0, $zero, 2
/* D9314C 8024020C 3C014361 */  lui       $at, 0x4361
/* D93150 80240210 44810000 */  mtc1      $at, $f0
/* D93154 80240214 00000000 */  nop
/* D93158 80240218 4600103C */  c.lt.s    $f2, $f0
/* D9315C 8024021C 00000000 */  nop
/* D93160 80240220 45000004 */  bc1f      .L80240234
/* D93164 80240224 00000000 */   nop
/* D93168 80240228 0C090021 */  jal       func_80240084_D92FC4
/* D9316C 8024022C 0040202D */   daddu    $a0, $v0, $zero
/* D93170 80240230 24040002 */  addiu     $a0, $zero, 2
.L80240234:
/* D93174 80240234 3C063F80 */  lui       $a2, 0x3f80
/* D93178 80240238 0C0B76A3 */  jal       func_802DDA8C
/* D9317C 8024023C 0040282D */   daddu    $a1, $v0, $zero
/* D93180 80240240 8E020000 */  lw        $v0, ($s0)
/* D93184 80240244 3C030002 */  lui       $v1, 2
/* D93188 80240248 00431024 */  and       $v0, $v0, $v1
/* D9318C 8024024C 54400022 */  bnel      $v0, $zero, .L802402D8
/* D93190 80240250 24110011 */   addiu    $s1, $zero, 0x11
/* D93194 80240254 9203000E */  lbu       $v1, 0xe($s0)
/* D93198 80240258 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D9319C 8024025C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D931A0 80240260 10620018 */  beq       $v1, $v0, .L802402C4
/* D931A4 80240264 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D931A8 80240268 1040000B */  beqz      $v0, .L80240298
/* D931AC 8024026C 24110011 */   addiu    $s1, $zero, 0x11
/* D931B0 80240270 24040002 */  addiu     $a0, $zero, 2
/* D931B4 80240274 2405FFFF */  addiu     $a1, $zero, -1
/* D931B8 80240278 24060007 */  addiu     $a2, $zero, 7
/* D931BC 8024027C 0060102D */  daddu     $v0, $v1, $zero
/* D931C0 80240280 0000382D */  daddu     $a3, $zero, $zero
/* D931C4 80240284 AFA00010 */  sw        $zero, 0x10($sp)
/* D931C8 80240288 AFA00014 */  sw        $zero, 0x14($sp)
/* D931CC 8024028C AFA0001C */  sw        $zero, 0x1c($sp)
/* D931D0 80240290 080900AF */  j         .L802402BC
/* D931D4 80240294 AFA20018 */   sw       $v0, 0x18($sp)
.L80240298:
/* D931D8 80240298 2411000D */  addiu     $s1, $zero, 0xd
/* D931DC 8024029C 24040002 */  addiu     $a0, $zero, 2
/* D931E0 802402A0 2405FFFF */  addiu     $a1, $zero, -1
/* D931E4 802402A4 0000302D */  daddu     $a2, $zero, $zero
/* D931E8 802402A8 00C0382D */  daddu     $a3, $a2, $zero
/* D931EC 802402AC AFA00010 */  sw        $zero, 0x10($sp)
/* D931F0 802402B0 AFA00014 */  sw        $zero, 0x14($sp)
/* D931F4 802402B4 AFA00018 */  sw        $zero, 0x18($sp)
/* D931F8 802402B8 AFA0001C */  sw        $zero, 0x1c($sp)
.L802402BC:
/* D931FC 802402BC 0C0B77B9 */  jal       func_802DDEE4
/* D93200 802402C0 00000000 */   nop
.L802402C4:
/* D93204 802402C4 9202000E */  lbu       $v0, 0xe($s0)
/* D93208 802402C8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D9320C 802402CC A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D93210 802402D0 080900B9 */  j         .L802402E4
/* D93214 802402D4 0240202D */   daddu    $a0, $s2, $zero
.L802402D8:
/* D93218 802402D8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D9321C 802402DC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D93220 802402E0 0240202D */  daddu     $a0, $s2, $zero
.L802402E4:
/* D93224 802402E4 AC910000 */  sw        $s1, ($a0)
/* D93228 802402E8 AC900008 */  sw        $s0, 8($a0)
/* D9322C 802402EC 8FA20038 */  lw        $v0, 0x38($sp)
/* D93230 802402F0 3C038024 */  lui       $v1, %hi(func_80240320_D93260)
/* D93234 802402F4 24630320 */  addiu     $v1, $v1, %lo(func_80240320_D93260)
/* D93238 802402F8 AC83000C */  sw        $v1, 0xc($a0)
/* D9323C 802402FC 00021023 */  negu      $v0, $v0
/* D93240 80240300 0C047644 */  jal       queue_render_task
/* D93244 80240304 AC820004 */   sw       $v0, 4($a0)
.L80240308:
/* D93248 80240308 8FBF004C */  lw        $ra, 0x4c($sp)
/* D9324C 8024030C 8FB20048 */  lw        $s2, 0x48($sp)
/* D93250 80240310 8FB10044 */  lw        $s1, 0x44($sp)
/* D93254 80240314 8FB00040 */  lw        $s0, 0x40($sp)
/* D93258 80240318 03E00008 */  jr        $ra
/* D9325C 8024031C 27BD0050 */   addiu    $sp, $sp, 0x50

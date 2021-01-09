.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D6EAD8
/* D6EAD8 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D6EADC 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D6EAE0 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D6EAE4 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D6EAE8 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D6EAEC 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D6EAF0 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D6EAF4 80240144 8E020000 */  lw        $v0, ($s0)
/* D6EAF8 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D6EAFC 8024014C 30420001 */  andi      $v0, $v0, 1
/* D6EB00 80240150 10400061 */  beqz      $v0, .L802402D8
/* D6EB04 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D6EB08 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D6EB0C 8024015C 0C044181 */  jal       get_shadow_by_index
/* D6EB10 80240160 00000000 */   nop      
/* D6EB14 80240164 0C048B77 */  jal       func_80122DDC
/* D6EB18 80240168 84440008 */   lh       $a0, 8($v0)
/* D6EB1C 8024016C 8C430000 */  lw        $v1, ($v0)
/* D6EB20 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D6EB24 80240174 AC430000 */  sw        $v1, ($v0)
/* D6EB28 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D6EB2C 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D6EB30 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D6EB34 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D6EB38 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D6EB3C 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D6EB40 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D6EB44 80240194 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D6EB48 80240198 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D6EB4C 8024019C 46000007 */  neg.s     $f0, $f0
/* D6EB50 802401A0 44070000 */  mfc1      $a3, $f0
/* D6EB54 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D6EB58 802401A8 0C00B94E */  jal       get_screen_coords
/* D6EB5C 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D6EB60 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D6EB64 802401B4 0C090008 */  jal       func_80240020_D6E9D0
/* D6EB68 802401B8 00000000 */   nop      
/* D6EB6C 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D6EB70 802401C0 3C014307 */  lui       $at, 0x4307
/* D6EB74 802401C4 44810000 */  mtc1      $at, $f0
/* D6EB78 802401C8 00000000 */  nop       
/* D6EB7C 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D6EB80 802401D0 00000000 */  nop       
/* D6EB84 802401D4 4500000B */  bc1f      .L80240204
/* D6EB88 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D6EB8C 802401DC 3C014361 */  lui       $at, 0x4361
/* D6EB90 802401E0 44810000 */  mtc1      $at, $f0
/* D6EB94 802401E4 00000000 */  nop       
/* D6EB98 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D6EB9C 802401EC 00000000 */  nop       
/* D6EBA0 802401F0 45000004 */  bc1f      .L80240204
/* D6EBA4 802401F4 00000000 */   nop      
/* D6EBA8 802401F8 0C090015 */  jal       func_80240054_D6EA04
/* D6EBAC 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D6EBB0 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D6EBB4 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D6EBB8 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D6EBBC 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D6EBC0 80240210 8E020000 */  lw        $v0, ($s0)
/* D6EBC4 80240214 3C030002 */  lui       $v1, 2
/* D6EBC8 80240218 00431024 */  and       $v0, $v0, $v1
/* D6EBCC 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D6EBD0 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D6EBD4 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D6EBD8 80240228 3C02802E */  lui       $v0, %hi(D_802D9D70)
/* D6EBDC 8024022C 90429D70 */  lbu       $v0, %lo(D_802D9D70)($v0)
/* D6EBE0 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D6EBE4 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D6EBE8 80240238 1040000B */  beqz      $v0, .L80240268
/* D6EBEC 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D6EBF0 80240240 24040002 */  addiu     $a0, $zero, 2
/* D6EBF4 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D6EBF8 80240248 24060007 */  addiu     $a2, $zero, 7
/* D6EBFC 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D6EC00 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D6EC04 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D6EC08 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D6EC0C 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D6EC10 80240260 080900A3 */  j         .L8024028C
/* D6EC14 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D6EC18 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D6EC1C 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D6EC20 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D6EC24 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D6EC28 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D6EC2C 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D6EC30 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D6EC34 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D6EC38 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D6EC3C 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D6EC40 80240290 00000000 */   nop      
.L80240294:
/* D6EC44 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D6EC48 80240298 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D6EC4C 8024029C A0229D70 */  sb        $v0, %lo(D_802D9D70)($at)
/* D6EC50 802402A0 080900AD */  j         .L802402B4
/* D6EC54 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D6EC58 802402A8 3C01802E */  lui       $at, %hi(D_802D9D70)
/* D6EC5C 802402AC A0209D70 */  sb        $zero, %lo(D_802D9D70)($at)
/* D6EC60 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D6EC64 802402B4 AC910000 */  sw        $s1, ($a0)
/* D6EC68 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D6EC6C 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D6EC70 802402C0 3C038024 */  lui       $v1, %hi(func_802402F0_D6EB98)
/* D6EC74 802402C4 246302F0 */  addiu     $v1, $v1, %lo(func_802402F0_D6EB98)
/* D6EC78 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D6EC7C 802402CC 00021023 */  negu      $v0, $v0
/* D6EC80 802402D0 0C047644 */  jal       queue_render_task
/* D6EC84 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D6EC88 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D6EC8C 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D6EC90 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D6EC94 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D6EC98 802402E8 03E00008 */  jr        $ra
/* D6EC9C 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50

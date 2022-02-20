.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_907A70
/* 907A70 80240040 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 907A74 80240044 AFB30024 */  sw        $s3, 0x24($sp)
/* 907A78 80240048 0080982D */  daddu     $s3, $a0, $zero
/* 907A7C 8024004C AFB00018 */  sw        $s0, 0x18($sp)
/* 907A80 80240050 00A0802D */  daddu     $s0, $a1, $zero
/* 907A84 80240054 AFBF0028 */  sw        $ra, 0x28($sp)
/* 907A88 80240058 AFB20020 */  sw        $s2, 0x20($sp)
/* 907A8C 8024005C AFB1001C */  sw        $s1, 0x1c($sp)
/* 907A90 80240060 8E71000C */  lw        $s1, 0xc($s3)
/* 907A94 80240064 0C00EAD2 */  jal       get_npc_safe
/* 907A98 80240068 0000202D */   daddu    $a0, $zero, $zero
/* 907A9C 8024006C 12000037 */  beqz      $s0, .L8024014C
/* 907AA0 80240070 0040902D */   daddu    $s2, $v0, $zero
/* 907AA4 80240074 0C00AB39 */  jal       heap_malloc
/* 907AA8 80240078 24040030 */   addiu    $a0, $zero, 0x30
/* 907AAC 8024007C 0040802D */  daddu     $s0, $v0, $zero
/* 907AB0 80240080 0260202D */  daddu     $a0, $s3, $zero
/* 907AB4 80240084 3C05FD05 */  lui       $a1, 0xfd05
/* 907AB8 80240088 34A50F80 */  ori       $a1, $a1, 0xf80
/* 907ABC 8024008C 0200302D */  daddu     $a2, $s0, $zero
/* 907AC0 80240090 0C0B2026 */  jal       evt_set_variable
/* 907AC4 80240094 AE700060 */   sw       $s0, 0x60($s3)
/* 907AC8 80240098 8E250000 */  lw        $a1, ($s1)
/* 907ACC 8024009C 26310004 */  addiu     $s1, $s1, 4
/* 907AD0 802400A0 0C0B1EAF */  jal       evt_get_variable
/* 907AD4 802400A4 0260202D */   daddu    $a0, $s3, $zero
/* 907AD8 802400A8 A6020022 */  sh        $v0, 0x22($s0)
/* 907ADC 802400AC 8E250000 */  lw        $a1, ($s1)
/* 907AE0 802400B0 26310004 */  addiu     $s1, $s1, 4
/* 907AE4 802400B4 0C0B210B */  jal       evt_get_float_variable
/* 907AE8 802400B8 0260202D */   daddu    $a0, $s3, $zero
/* 907AEC 802400BC E6000000 */  swc1      $f0, ($s0)
/* 907AF0 802400C0 8E250000 */  lw        $a1, ($s1)
/* 907AF4 802400C4 26310004 */  addiu     $s1, $s1, 4
/* 907AF8 802400C8 0C0B210B */  jal       evt_get_float_variable
/* 907AFC 802400CC 0260202D */   daddu    $a0, $s3, $zero
/* 907B00 802400D0 E6000004 */  swc1      $f0, 4($s0)
/* 907B04 802400D4 8E250000 */  lw        $a1, ($s1)
/* 907B08 802400D8 0C0B210B */  jal       evt_get_float_variable
/* 907B0C 802400DC 0260202D */   daddu    $a0, $s3, $zero
/* 907B10 802400E0 E6000008 */  swc1      $f0, 8($s0)
/* 907B14 802400E4 3C013F80 */  lui       $at, 0x3f80
/* 907B18 802400E8 44810000 */  mtc1      $at, $f0
/* 907B1C 802400EC 24020016 */  addiu     $v0, $zero, 0x16
/* 907B20 802400F0 AE000010 */  sw        $zero, 0x10($s0)
/* 907B24 802400F4 A600001C */  sh        $zero, 0x1c($s0)
/* 907B28 802400F8 A6000024 */  sh        $zero, 0x24($s0)
/* 907B2C 802400FC A600001E */  sh        $zero, 0x1e($s0)
/* 907B30 80240100 A24000AC */  sb        $zero, 0xac($s2)
/* 907B34 80240104 A24200AA */  sb        $v0, 0xaa($s2)
/* 907B38 80240108 AFA00014 */  sw        $zero, 0x14($sp)
/* 907B3C 8024010C E7A00010 */  swc1      $f0, 0x10($sp)
/* 907B40 80240110 8E050000 */  lw        $a1, ($s0)
/* 907B44 80240114 8E060004 */  lw        $a2, 4($s0)
/* 907B48 80240118 8E070008 */  lw        $a3, 8($s0)
/* 907B4C 8024011C 0C01C9AC */  jal       fx_spirit_card
/* 907B50 80240120 24040001 */   addiu    $a0, $zero, 1
/* 907B54 80240124 AE020028 */  sw        $v0, 0x28($s0)
/* 907B58 80240128 8C43000C */  lw        $v1, 0xc($v0)
/* 907B5C 8024012C 92020023 */  lbu       $v0, 0x23($s0)
/* 907B60 80240130 A0620034 */  sb        $v0, 0x34($v1)
/* 907B64 80240134 8E020028 */  lw        $v0, 0x28($s0)
/* 907B68 80240138 8C42000C */  lw        $v0, 0xc($v0)
/* 907B6C 8024013C 3C048024 */  lui       $a0, %hi(func_80240DA4_9087D4)
/* 907B70 80240140 24840DA4 */  addiu     $a0, $a0, %lo(func_80240DA4_9087D4)
/* 907B74 80240144 0C00AFC1 */  jal       set_curtain_draw_callback
/* 907B78 80240148 AC400020 */   sw       $zero, 0x20($v0)
.L8024014C:
/* 907B7C 8024014C 8E700060 */  lw        $s0, 0x60($s3)
/* 907B80 80240150 3C014120 */  lui       $at, 0x4120
/* 907B84 80240154 44811000 */  mtc1      $at, $f2
/* 907B88 80240158 C6000000 */  lwc1      $f0, ($s0)
/* 907B8C 8024015C E6400038 */  swc1      $f0, 0x38($s2)
/* 907B90 80240160 C6000004 */  lwc1      $f0, 4($s0)
/* 907B94 80240164 E640003C */  swc1      $f0, 0x3c($s2)
/* 907B98 80240168 C6000008 */  lwc1      $f0, 8($s0)
/* 907B9C 8024016C 0000882D */  daddu     $s1, $zero, $zero
/* 907BA0 80240170 46020000 */  add.s     $f0, $f0, $f2
/* 907BA4 80240174 0260202D */  daddu     $a0, $s3, $zero
/* 907BA8 80240178 3C05FAA2 */  lui       $a1, 0xfaa2
/* 907BAC 8024017C E6400040 */  swc1      $f0, 0x40($s2)
/* 907BB0 80240180 C6000010 */  lwc1      $f0, 0x10($s0)
/* 907BB4 80240184 34A5B58B */  ori       $a1, $a1, 0xb58b
/* 907BB8 80240188 0C0B1EAF */  jal       evt_get_variable
/* 907BBC 8024018C E6400048 */   swc1     $f0, 0x48($s2)
/* 907BC0 80240190 14400018 */  bnez      $v0, .L802401F4
/* 907BC4 80240194 00000000 */   nop
/* 907BC8 80240198 C6020010 */  lwc1      $f2, 0x10($s0)
/* 907BCC 8024019C 3C0142B4 */  lui       $at, 0x42b4
/* 907BD0 802401A0 44810000 */  mtc1      $at, $f0
/* 907BD4 802401A4 00000000 */  nop
/* 907BD8 802401A8 4602003C */  c.lt.s    $f0, $f2
/* 907BDC 802401AC 00000000 */  nop
/* 907BE0 802401B0 45000008 */  bc1f      .L802401D4
/* 907BE4 802401B4 00000000 */   nop
/* 907BE8 802401B8 3C014387 */  lui       $at, 0x4387
/* 907BEC 802401BC 44810000 */  mtc1      $at, $f0
/* 907BF0 802401C0 00000000 */  nop
/* 907BF4 802401C4 4600103C */  c.lt.s    $f2, $f0
/* 907BF8 802401C8 00000000 */  nop
/* 907BFC 802401CC 45030001 */  bc1tl     .L802401D4
/* 907C00 802401D0 24110001 */   addiu    $s1, $zero, 1
.L802401D4:
/* 907C04 802401D4 86020022 */  lh        $v0, 0x22($s0)
/* 907C08 802401D8 00111880 */  sll       $v1, $s1, 2
/* 907C0C 802401DC 000210C0 */  sll       $v0, $v0, 3
/* 907C10 802401E0 00621821 */  addu      $v1, $v1, $v0
/* 907C14 802401E4 3C028024 */  lui       $v0, %hi(D_8024168C_9090BC)
/* 907C18 802401E8 00431021 */  addu      $v0, $v0, $v1
/* 907C1C 802401EC 8C42168C */  lw        $v0, %lo(D_8024168C_9090BC)($v0)
/* 907C20 802401F0 AE420028 */  sw        $v0, 0x28($s2)
.L802401F4:
/* 907C24 802401F4 8E020028 */  lw        $v0, 0x28($s0)
/* 907C28 802401F8 10400016 */  beqz      $v0, .L80240254
/* 907C2C 802401FC 00000000 */   nop
/* 907C30 80240200 8C42000C */  lw        $v0, 0xc($v0)
/* 907C34 80240204 C6000010 */  lwc1      $f0, 0x10($s0)
/* 907C38 80240208 3C014000 */  lui       $at, 0x4000
/* 907C3C 8024020C 44811000 */  mtc1      $at, $f2
/* 907C40 80240210 E4400024 */  swc1      $f0, 0x24($v0)
/* 907C44 80240214 C6000000 */  lwc1      $f0, ($s0)
/* 907C48 80240218 8E020028 */  lw        $v0, 0x28($s0)
/* 907C4C 8024021C 46020001 */  sub.s     $f0, $f0, $f2
/* 907C50 80240220 8C42000C */  lw        $v0, 0xc($v0)
/* 907C54 80240224 3C014170 */  lui       $at, 0x4170
/* 907C58 80240228 44811000 */  mtc1      $at, $f2
/* 907C5C 8024022C E4400004 */  swc1      $f0, 4($v0)
/* 907C60 80240230 C6000004 */  lwc1      $f0, 4($s0)
/* 907C64 80240234 8E020028 */  lw        $v0, 0x28($s0)
/* 907C68 80240238 46020000 */  add.s     $f0, $f0, $f2
/* 907C6C 8024023C 8C42000C */  lw        $v0, 0xc($v0)
/* 907C70 80240240 E4400008 */  swc1      $f0, 8($v0)
/* 907C74 80240244 8E020028 */  lw        $v0, 0x28($s0)
/* 907C78 80240248 C6000008 */  lwc1      $f0, 8($s0)
/* 907C7C 8024024C 8C42000C */  lw        $v0, 0xc($v0)
/* 907C80 80240250 E440000C */  swc1      $f0, 0xc($v0)
.L80240254:
/* 907C84 80240254 8FBF0028 */  lw        $ra, 0x28($sp)
/* 907C88 80240258 8FB30024 */  lw        $s3, 0x24($sp)
/* 907C8C 8024025C 8FB20020 */  lw        $s2, 0x20($sp)
/* 907C90 80240260 8FB1001C */  lw        $s1, 0x1c($sp)
/* 907C94 80240264 8FB00018 */  lw        $s0, 0x18($sp)
/* 907C98 80240268 0000102D */  daddu     $v0, $zero, $zero
/* 907C9C 8024026C 03E00008 */  jr        $ra
/* 907CA0 80240270 27BD0030 */   addiu    $sp, $sp, 0x30

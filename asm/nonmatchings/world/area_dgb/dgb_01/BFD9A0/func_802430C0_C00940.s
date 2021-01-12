.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802430C0_C00940
/* C00940 802430C0 27BDFF98 */  addiu     $sp, $sp, -0x68
/* C00944 802430C4 AFB40058 */  sw        $s4, 0x58($sp)
/* C00948 802430C8 0080A02D */  daddu     $s4, $a0, $zero
/* C0094C 802430CC AFBF0060 */  sw        $ra, 0x60($sp)
/* C00950 802430D0 AFB5005C */  sw        $s5, 0x5c($sp)
/* C00954 802430D4 AFB30054 */  sw        $s3, 0x54($sp)
/* C00958 802430D8 AFB20050 */  sw        $s2, 0x50($sp)
/* C0095C 802430DC AFB1004C */  sw        $s1, 0x4c($sp)
/* C00960 802430E0 AFB00048 */  sw        $s0, 0x48($sp)
/* C00964 802430E4 8E910148 */  lw        $s1, 0x148($s4)
/* C00968 802430E8 86240008 */  lh        $a0, 8($s1)
/* C0096C 802430EC 0C00EABB */  jal       get_npc_unsafe
/* C00970 802430F0 00A0802D */   daddu    $s0, $a1, $zero
/* C00974 802430F4 8E83000C */  lw        $v1, 0xc($s4)
/* C00978 802430F8 0280202D */  daddu     $a0, $s4, $zero
/* C0097C 802430FC 8C650000 */  lw        $a1, ($v1)
/* C00980 80243100 0C0B1EAF */  jal       get_variable
/* C00984 80243104 0040902D */   daddu    $s2, $v0, $zero
/* C00988 80243108 AFA00018 */  sw        $zero, 0x18($sp)
/* C0098C 8024310C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C00990 80243110 8C630094 */  lw        $v1, 0x94($v1)
/* C00994 80243114 AFA3001C */  sw        $v1, 0x1c($sp)
/* C00998 80243118 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C0099C 8024311C 8C630080 */  lw        $v1, 0x80($v1)
/* C009A0 80243120 AFA30020 */  sw        $v1, 0x20($sp)
/* C009A4 80243124 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C009A8 80243128 8C630088 */  lw        $v1, 0x88($v1)
/* C009AC 8024312C AFA30024 */  sw        $v1, 0x24($sp)
/* C009B0 80243130 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C009B4 80243134 8C63008C */  lw        $v1, 0x8c($v1)
/* C009B8 80243138 27B50018 */  addiu     $s5, $sp, 0x18
/* C009BC 8024313C AFA30028 */  sw        $v1, 0x28($sp)
/* C009C0 80243140 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C009C4 80243144 3C014282 */  lui       $at, 0x4282
/* C009C8 80243148 44810000 */  mtc1      $at, $f0
/* C009CC 8024314C 8C630090 */  lw        $v1, 0x90($v1)
/* C009D0 80243150 0040982D */  daddu     $s3, $v0, $zero
/* C009D4 80243154 E7A00030 */  swc1      $f0, 0x30($sp)
/* C009D8 80243158 A7A00034 */  sh        $zero, 0x34($sp)
/* C009DC 8024315C 16000005 */  bnez      $s0, .L80243174
/* C009E0 80243160 AFA3002C */   sw       $v1, 0x2c($sp)
/* C009E4 80243164 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C009E8 80243168 30420004 */  andi      $v0, $v0, 4
/* C009EC 8024316C 10400044 */  beqz      $v0, .L80243280
/* C009F0 80243170 00000000 */   nop
.L80243174:
/* C009F4 80243174 2404F7FF */  addiu     $a0, $zero, -0x801
/* C009F8 80243178 AE800070 */  sw        $zero, 0x70($s4)
/* C009FC 8024317C A640008E */  sh        $zero, 0x8e($s2)
/* C00A00 80243180 8E2200CC */  lw        $v0, 0xcc($s1)
/* C00A04 80243184 8E430000 */  lw        $v1, ($s2)
/* C00A08 80243188 8C420000 */  lw        $v0, ($v0)
/* C00A0C 8024318C 00641824 */  and       $v1, $v1, $a0
/* C00A10 80243190 AE430000 */  sw        $v1, ($s2)
/* C00A14 80243194 AE420028 */  sw        $v0, 0x28($s2)
/* C00A18 80243198 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C00A1C 8024319C 8C420098 */  lw        $v0, 0x98($v0)
/* C00A20 802431A0 54400005 */  bnel      $v0, $zero, .L802431B8
/* C00A24 802431A4 2402FDFF */   addiu    $v0, $zero, -0x201
/* C00A28 802431A8 34620200 */  ori       $v0, $v1, 0x200
/* C00A2C 802431AC 2403FFF7 */  addiu     $v1, $zero, -9
/* C00A30 802431B0 08090C70 */  j         .L802431C0
/* C00A34 802431B4 00431024 */   and      $v0, $v0, $v1
.L802431B8:
/* C00A38 802431B8 00621024 */  and       $v0, $v1, $v0
/* C00A3C 802431BC 34420008 */  ori       $v0, $v0, 8
.L802431C0:
/* C00A40 802431C0 AE420000 */  sw        $v0, ($s2)
/* C00A44 802431C4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C00A48 802431C8 30420004 */  andi      $v0, $v0, 4
/* C00A4C 802431CC 10400008 */  beqz      $v0, .L802431F0
/* C00A50 802431D0 24020063 */   addiu    $v0, $zero, 0x63
/* C00A54 802431D4 AE820070 */  sw        $v0, 0x70($s4)
/* C00A58 802431D8 AE800074 */  sw        $zero, 0x74($s4)
/* C00A5C 802431DC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C00A60 802431E0 2403FFFB */  addiu     $v1, $zero, -5
/* C00A64 802431E4 00431024 */  and       $v0, $v0, $v1
/* C00A68 802431E8 08090C87 */  j         .L8024321C
/* C00A6C 802431EC AE2200B0 */   sw       $v0, 0xb0($s1)
.L802431F0:
/* C00A70 802431F0 8E220000 */  lw        $v0, ($s1)
/* C00A74 802431F4 3C034000 */  lui       $v1, 0x4000
/* C00A78 802431F8 00431024 */  and       $v0, $v0, $v1
/* C00A7C 802431FC 10400007 */  beqz      $v0, .L8024321C
/* C00A80 80243200 3C03BFFF */   lui      $v1, 0xbfff
/* C00A84 80243204 2402000C */  addiu     $v0, $zero, 0xc
/* C00A88 80243208 AE820070 */  sw        $v0, 0x70($s4)
/* C00A8C 8024320C 8E220000 */  lw        $v0, ($s1)
/* C00A90 80243210 3463FFFF */  ori       $v1, $v1, 0xffff
/* C00A94 80243214 00431024 */  and       $v0, $v0, $v1
/* C00A98 80243218 AE220000 */  sw        $v0, ($s1)
.L8024321C:
/* C00A9C 8024321C 27A50038 */  addiu     $a1, $sp, 0x38
/* C00AA0 80243220 27A6003C */  addiu     $a2, $sp, 0x3c
/* C00AA4 80243224 C6400038 */  lwc1      $f0, 0x38($s2)
/* C00AA8 80243228 864200A8 */  lh        $v0, 0xa8($s2)
/* C00AAC 8024322C 3C0142C8 */  lui       $at, 0x42c8
/* C00AB0 80243230 44812000 */  mtc1      $at, $f4
/* C00AB4 80243234 44823000 */  mtc1      $v0, $f6
/* C00AB8 80243238 00000000 */  nop
/* C00ABC 8024323C 468031A0 */  cvt.s.w   $f6, $f6
/* C00AC0 80243240 27A20044 */  addiu     $v0, $sp, 0x44
/* C00AC4 80243244 E7A00038 */  swc1      $f0, 0x38($sp)
/* C00AC8 80243248 C640003C */  lwc1      $f0, 0x3c($s2)
/* C00ACC 8024324C C6420040 */  lwc1      $f2, 0x40($s2)
/* C00AD0 80243250 46060000 */  add.s     $f0, $f0, $f6
/* C00AD4 80243254 E7A40044 */  swc1      $f4, 0x44($sp)
/* C00AD8 80243258 E7A20040 */  swc1      $f2, 0x40($sp)
/* C00ADC 8024325C E7A0003C */  swc1      $f0, 0x3c($sp)
/* C00AE0 80243260 AFA20010 */  sw        $v0, 0x10($sp)
/* C00AE4 80243264 8E440080 */  lw        $a0, 0x80($s2)
/* C00AE8 80243268 0C0372DF */  jal       func_800DCB7C
/* C00AEC 8024326C 27A70040 */   addiu    $a3, $sp, 0x40
/* C00AF0 80243270 10400003 */  beqz      $v0, .L80243280
/* C00AF4 80243274 00000000 */   nop
/* C00AF8 80243278 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* C00AFC 8024327C E640003C */  swc1      $f0, 0x3c($s2)
.L80243280:
/* C00B00 80243280 8E830070 */  lw        $v1, 0x70($s4)
/* C00B04 80243284 2C620064 */  sltiu     $v0, $v1, 0x64
/* C00B08 80243288 10400042 */  beqz      $v0, .L80243394
/* C00B0C 8024328C 00031080 */   sll      $v0, $v1, 2
/* C00B10 80243290 3C018026 */  lui       $at, %hi(jtbl_80263520_C20DA0)
/* C00B14 80243294 00220821 */  addu      $at, $at, $v0
/* C00B18 80243298 8C223520 */  lw        $v0, %lo(jtbl_80263520_C20DA0)($at)
/* C00B1C 8024329C 00400008 */  jr        $v0
/* C00B20 802432A0 00000000 */   nop
glabel L802432A4_C00B24
/* C00B24 802432A4 0280202D */  daddu     $a0, $s4, $zero
/* C00B28 802432A8 0260282D */  daddu     $a1, $s3, $zero
/* C00B2C 802432AC 0C09094B */  jal       func_8024252C_BFFDAC
/* C00B30 802432B0 02A0302D */   daddu    $a2, $s5, $zero
glabel L802432B4_C00B34
/* C00B34 802432B4 0280202D */  daddu     $a0, $s4, $zero
/* C00B38 802432B8 0260282D */  daddu     $a1, $s3, $zero
/* C00B3C 802432BC 0C0909A1 */  jal       func_80242684_BFFF04
/* C00B40 802432C0 02A0302D */   daddu    $a2, $s5, $zero
/* C00B44 802432C4 08090CE5 */  j         .L80243394
/* C00B48 802432C8 00000000 */   nop
glabel L802432CC_C00B4C
/* C00B4C 802432CC 0280202D */  daddu     $a0, $s4, $zero
/* C00B50 802432D0 0260282D */  daddu     $a1, $s3, $zero
/* C00B54 802432D4 0C090A4B */  jal       dup_dgb_01_UnkNpcAIFunc1
/* C00B58 802432D8 02A0302D */   daddu    $a2, $s5, $zero
glabel L802432DC_C00B5C
/* C00B5C 802432DC 0280202D */  daddu     $a0, $s4, $zero
/* C00B60 802432E0 0260282D */  daddu     $a1, $s3, $zero
/* C00B64 802432E4 0C090A7B */  jal       func_802429EC_C0026C
/* C00B68 802432E8 02A0302D */   daddu    $a2, $s5, $zero
/* C00B6C 802432EC 08090CE5 */  j         .L80243394
/* C00B70 802432F0 00000000 */   nop
glabel L802432F4_C00B74
/* C00B74 802432F4 0280202D */  daddu     $a0, $s4, $zero
/* C00B78 802432F8 0260282D */  daddu     $a1, $s3, $zero
/* C00B7C 802432FC 0C090AEA */  jal       func_80242BA8_C00428
/* C00B80 80243300 02A0302D */   daddu    $a2, $s5, $zero
/* C00B84 80243304 08090CE5 */  j         .L80243394
/* C00B88 80243308 00000000 */   nop
glabel L8024330C_C00B8C
/* C00B8C 8024330C 0280202D */  daddu     $a0, $s4, $zero
/* C00B90 80243310 0260282D */  daddu     $a1, $s3, $zero
/* C00B94 80243314 0C090B17 */  jal       dgb_01_NpcJumpFunc2
/* C00B98 80243318 02A0302D */   daddu    $a2, $s5, $zero
glabel L8024331C_C00B9C
/* C00B9C 8024331C 0280202D */  daddu     $a0, $s4, $zero
/* C00BA0 80243320 0260282D */  daddu     $a1, $s3, $zero
/* C00BA4 80243324 0C090B34 */  jal       dgb_01_NpcJumpFunc
/* C00BA8 80243328 02A0302D */   daddu    $a2, $s5, $zero
/* C00BAC 8024332C 08090CE5 */  j         .L80243394
/* C00BB0 80243330 00000000 */   nop
glabel L80243334_C00BB4
/* C00BB4 80243334 0280202D */  daddu     $a0, $s4, $zero
/* C00BB8 80243338 0260282D */  daddu     $a1, $s3, $zero
/* C00BBC 8024333C 0C090B52 */  jal       func_80242D48_C005C8
/* C00BC0 80243340 02A0302D */   daddu    $a2, $s5, $zero
glabel L80243344_C00BC4
/* C00BC4 80243344 0280202D */  daddu     $a0, $s4, $zero
/* C00BC8 80243348 0260282D */  daddu     $a1, $s3, $zero
/* C00BCC 8024334C 0C090B9E */  jal       func_80242E78_C006F8
/* C00BD0 80243350 02A0302D */   daddu    $a2, $s5, $zero
/* C00BD4 80243354 08090CE5 */  j         .L80243394
/* C00BD8 80243358 00000000 */   nop
glabel L8024335C_C00BDC
/* C00BDC 8024335C 0280202D */  daddu     $a0, $s4, $zero
/* C00BE0 80243360 0260282D */  daddu     $a1, $s3, $zero
/* C00BE4 80243364 0C090BE6 */  jal       dgb_01_UnkNpcDurationFlagFunc
/* C00BE8 80243368 02A0302D */   daddu    $a2, $s5, $zero
/* C00BEC 8024336C 08090CE5 */  j         .L80243394
/* C00BF0 80243370 00000000 */   nop
glabel L80243374_C00BF4
/* C00BF4 80243374 0280202D */  daddu     $a0, $s4, $zero
/* C00BF8 80243378 0260282D */  daddu     $a1, $s3, $zero
/* C00BFC 8024337C 0C090C00 */  jal       func_80243000_C00880
/* C00C00 80243380 02A0302D */   daddu    $a2, $s5, $zero
/* C00C04 80243384 08090CE5 */  j         .L80243394
/* C00C08 80243388 00000000 */   nop
glabel L8024338C_C00C0C
/* C00C0C 8024338C 0C0129CF */  jal       func_8004A73C
/* C00C10 80243390 0280202D */   daddu    $a0, $s4, $zero
.L80243394:
glabel L80243394_C00C14
/* C00C14 80243394 8FBF0060 */  lw        $ra, 0x60($sp)
/* C00C18 80243398 8FB5005C */  lw        $s5, 0x5c($sp)
/* C00C1C 8024339C 8FB40058 */  lw        $s4, 0x58($sp)
/* C00C20 802433A0 8FB30054 */  lw        $s3, 0x54($sp)
/* C00C24 802433A4 8FB20050 */  lw        $s2, 0x50($sp)
/* C00C28 802433A8 8FB1004C */  lw        $s1, 0x4c($sp)
/* C00C2C 802433AC 8FB00048 */  lw        $s0, 0x48($sp)
/* C00C30 802433B0 0000102D */  daddu     $v0, $zero, $zero
/* C00C34 802433B4 03E00008 */  jr        $ra
/* C00C38 802433B8 27BD0068 */   addiu    $sp, $sp, 0x68

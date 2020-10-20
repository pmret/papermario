.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243104
/* 7EDE14 80243104 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 7EDE18 80243108 AFB40058 */  sw        $s4, 0x58($sp)
/* 7EDE1C 8024310C 0080A02D */  daddu     $s4, $a0, $zero
/* 7EDE20 80243110 AFBF0060 */  sw        $ra, 0x60($sp)
/* 7EDE24 80243114 AFB5005C */  sw        $s5, 0x5c($sp)
/* 7EDE28 80243118 AFB30054 */  sw        $s3, 0x54($sp)
/* 7EDE2C 8024311C AFB20050 */  sw        $s2, 0x50($sp)
/* 7EDE30 80243120 AFB1004C */  sw        $s1, 0x4c($sp)
/* 7EDE34 80243124 AFB00048 */  sw        $s0, 0x48($sp)
/* 7EDE38 80243128 8E910148 */  lw        $s1, 0x148($s4)
/* 7EDE3C 8024312C 86240008 */  lh        $a0, 8($s1)
/* 7EDE40 80243130 0C00EABB */  jal       get_npc_unsafe
/* 7EDE44 80243134 00A0802D */   daddu    $s0, $a1, $zero
/* 7EDE48 80243138 8E83000C */  lw        $v1, 0xc($s4)
/* 7EDE4C 8024313C 0280202D */  daddu     $a0, $s4, $zero
/* 7EDE50 80243140 8C650000 */  lw        $a1, ($v1)
/* 7EDE54 80243144 0C0B1EAF */  jal       get_variable
/* 7EDE58 80243148 0040902D */   daddu    $s2, $v0, $zero
/* 7EDE5C 8024314C AFA00018 */  sw        $zero, 0x18($sp)
/* 7EDE60 80243150 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 7EDE64 80243154 8C630094 */  lw        $v1, 0x94($v1)
/* 7EDE68 80243158 AFA3001C */  sw        $v1, 0x1c($sp)
/* 7EDE6C 8024315C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 7EDE70 80243160 8C630080 */  lw        $v1, 0x80($v1)
/* 7EDE74 80243164 AFA30020 */  sw        $v1, 0x20($sp)
/* 7EDE78 80243168 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 7EDE7C 8024316C 8C630088 */  lw        $v1, 0x88($v1)
/* 7EDE80 80243170 AFA30024 */  sw        $v1, 0x24($sp)
/* 7EDE84 80243174 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 7EDE88 80243178 8C63008C */  lw        $v1, 0x8c($v1)
/* 7EDE8C 8024317C 27B50018 */  addiu     $s5, $sp, 0x18
/* 7EDE90 80243180 AFA30028 */  sw        $v1, 0x28($sp)
/* 7EDE94 80243184 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 7EDE98 80243188 3C014282 */  lui       $at, 0x4282
/* 7EDE9C 8024318C 44810000 */  mtc1      $at, $f0
/* 7EDEA0 80243190 8C630090 */  lw        $v1, 0x90($v1)
/* 7EDEA4 80243194 0040982D */  daddu     $s3, $v0, $zero
/* 7EDEA8 80243198 E7A00030 */  swc1      $f0, 0x30($sp)
/* 7EDEAC 8024319C A7A00034 */  sh        $zero, 0x34($sp)
/* 7EDEB0 802431A0 16000005 */  bnez      $s0, .L802431B8
/* 7EDEB4 802431A4 AFA3002C */   sw       $v1, 0x2c($sp)
/* 7EDEB8 802431A8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 7EDEBC 802431AC 30420004 */  andi      $v0, $v0, 4
/* 7EDEC0 802431B0 10400044 */  beqz      $v0, .L802432C4
/* 7EDEC4 802431B4 00000000 */   nop      
.L802431B8:
/* 7EDEC8 802431B8 2404F7FF */  addiu     $a0, $zero, -0x801
/* 7EDECC 802431BC AE800070 */  sw        $zero, 0x70($s4)
/* 7EDED0 802431C0 A640008E */  sh        $zero, 0x8e($s2)
/* 7EDED4 802431C4 8E2200CC */  lw        $v0, 0xcc($s1)
/* 7EDED8 802431C8 8E430000 */  lw        $v1, ($s2)
/* 7EDEDC 802431CC 8C420000 */  lw        $v0, ($v0)
/* 7EDEE0 802431D0 00641824 */  and       $v1, $v1, $a0
/* 7EDEE4 802431D4 AE430000 */  sw        $v1, ($s2)
/* 7EDEE8 802431D8 AE420028 */  sw        $v0, 0x28($s2)
/* 7EDEEC 802431DC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 7EDEF0 802431E0 8C420098 */  lw        $v0, 0x98($v0)
/* 7EDEF4 802431E4 54400005 */  bnel      $v0, $zero, .L802431FC
/* 7EDEF8 802431E8 2402FDFF */   addiu    $v0, $zero, -0x201
/* 7EDEFC 802431EC 34620200 */  ori       $v0, $v1, 0x200
/* 7EDF00 802431F0 2403FFF7 */  addiu     $v1, $zero, -9
/* 7EDF04 802431F4 08090C81 */  j         .L80243204
/* 7EDF08 802431F8 00431024 */   and      $v0, $v0, $v1
.L802431FC:
/* 7EDF0C 802431FC 00621024 */  and       $v0, $v1, $v0
/* 7EDF10 80243200 34420008 */  ori       $v0, $v0, 8
.L80243204:
/* 7EDF14 80243204 AE420000 */  sw        $v0, ($s2)
/* 7EDF18 80243208 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 7EDF1C 8024320C 30420004 */  andi      $v0, $v0, 4
/* 7EDF20 80243210 10400008 */  beqz      $v0, .L80243234
/* 7EDF24 80243214 24020063 */   addiu    $v0, $zero, 0x63
/* 7EDF28 80243218 AE820070 */  sw        $v0, 0x70($s4)
/* 7EDF2C 8024321C AE800074 */  sw        $zero, 0x74($s4)
/* 7EDF30 80243220 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 7EDF34 80243224 2403FFFB */  addiu     $v1, $zero, -5
/* 7EDF38 80243228 00431024 */  and       $v0, $v0, $v1
/* 7EDF3C 8024322C 08090C98 */  j         .L80243260
/* 7EDF40 80243230 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80243234:
/* 7EDF44 80243234 8E220000 */  lw        $v0, ($s1)
/* 7EDF48 80243238 3C034000 */  lui       $v1, 0x4000
/* 7EDF4C 8024323C 00431024 */  and       $v0, $v0, $v1
/* 7EDF50 80243240 10400007 */  beqz      $v0, .L80243260
/* 7EDF54 80243244 3C03BFFF */   lui      $v1, 0xbfff
/* 7EDF58 80243248 2402000C */  addiu     $v0, $zero, 0xc
/* 7EDF5C 8024324C AE820070 */  sw        $v0, 0x70($s4)
/* 7EDF60 80243250 8E220000 */  lw        $v0, ($s1)
/* 7EDF64 80243254 3463FFFF */  ori       $v1, $v1, 0xffff
/* 7EDF68 80243258 00431024 */  and       $v0, $v0, $v1
/* 7EDF6C 8024325C AE220000 */  sw        $v0, ($s1)
.L80243260:
/* 7EDF70 80243260 27A50038 */  addiu     $a1, $sp, 0x38
/* 7EDF74 80243264 27A6003C */  addiu     $a2, $sp, 0x3c
/* 7EDF78 80243268 C6400038 */  lwc1      $f0, 0x38($s2)
/* 7EDF7C 8024326C 864200A8 */  lh        $v0, 0xa8($s2)
/* 7EDF80 80243270 3C0142C8 */  lui       $at, 0x42c8
/* 7EDF84 80243274 44812000 */  mtc1      $at, $f4
/* 7EDF88 80243278 44823000 */  mtc1      $v0, $f6
/* 7EDF8C 8024327C 00000000 */  nop       
/* 7EDF90 80243280 468031A0 */  cvt.s.w   $f6, $f6
/* 7EDF94 80243284 27A20044 */  addiu     $v0, $sp, 0x44
/* 7EDF98 80243288 E7A00038 */  swc1      $f0, 0x38($sp)
/* 7EDF9C 8024328C C640003C */  lwc1      $f0, 0x3c($s2)
/* 7EDFA0 80243290 C6420040 */  lwc1      $f2, 0x40($s2)
/* 7EDFA4 80243294 46060000 */  add.s     $f0, $f0, $f6
/* 7EDFA8 80243298 E7A40044 */  swc1      $f4, 0x44($sp)
/* 7EDFAC 8024329C E7A20040 */  swc1      $f2, 0x40($sp)
/* 7EDFB0 802432A0 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 7EDFB4 802432A4 AFA20010 */  sw        $v0, 0x10($sp)
/* 7EDFB8 802432A8 8E440080 */  lw        $a0, 0x80($s2)
/* 7EDFBC 802432AC 0C0372DF */  jal       func_800DCB7C
/* 7EDFC0 802432B0 27A70040 */   addiu    $a3, $sp, 0x40
/* 7EDFC4 802432B4 10400003 */  beqz      $v0, .L802432C4
/* 7EDFC8 802432B8 00000000 */   nop      
/* 7EDFCC 802432BC C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 7EDFD0 802432C0 E640003C */  swc1      $f0, 0x3c($s2)
.L802432C4:
/* 7EDFD4 802432C4 8E830070 */  lw        $v1, 0x70($s4)
/* 7EDFD8 802432C8 2C620064 */  sltiu     $v0, $v1, 0x64
/* 7EDFDC 802432CC 10400042 */  beqz      $v0, .L802433D8
/* 7EDFE0 802432D0 00031080 */   sll      $v0, $v1, 2
/* 7EDFE4 802432D4 3C018025 */  lui       $at, 0x8025
/* 7EDFE8 802432D8 00220821 */  addu      $at, $at, $v0
/* 7EDFEC 802432DC 8C2259D0 */  lw        $v0, 0x59d0($at)
/* 7EDFF0 802432E0 00400008 */  jr        $v0
/* 7EDFF4 802432E4 00000000 */   nop      
/* 7EDFF8 802432E8 0280202D */  daddu     $a0, $s4, $zero
/* 7EDFFC 802432EC 0260282D */  daddu     $a1, $s3, $zero
/* 7EE000 802432F0 0C09095C */  jal       func_80242570
/* 7EE004 802432F4 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE008 802432F8 0280202D */  daddu     $a0, $s4, $zero
/* 7EE00C 802432FC 0260282D */  daddu     $a1, $s3, $zero
/* 7EE010 80243300 0C0909B2 */  jal       func_802426C8
/* 7EE014 80243304 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE018 80243308 08090CF6 */  j         .L802433D8
/* 7EE01C 8024330C 00000000 */   nop      
/* 7EE020 80243310 0280202D */  daddu     $a0, $s4, $zero
/* 7EE024 80243314 0260282D */  daddu     $a1, $s3, $zero
/* 7EE028 80243318 0C090A5C */  jal       func_80242970
/* 7EE02C 8024331C 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE030 80243320 0280202D */  daddu     $a0, $s4, $zero
/* 7EE034 80243324 0260282D */  daddu     $a1, $s3, $zero
/* 7EE038 80243328 0C090A8C */  jal       func_80242A30
/* 7EE03C 8024332C 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE040 80243330 08090CF6 */  j         .L802433D8
/* 7EE044 80243334 00000000 */   nop      
/* 7EE048 80243338 0280202D */  daddu     $a0, $s4, $zero
/* 7EE04C 8024333C 0260282D */  daddu     $a1, $s3, $zero
/* 7EE050 80243340 0C090AFB */  jal       func_80242BEC
/* 7EE054 80243344 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE058 80243348 08090CF6 */  j         .L802433D8
/* 7EE05C 8024334C 00000000 */   nop      
/* 7EE060 80243350 0280202D */  daddu     $a0, $s4, $zero
/* 7EE064 80243354 0260282D */  daddu     $a1, $s3, $zero
/* 7EE068 80243358 0C090B28 */  jal       func_80242CA0
/* 7EE06C 8024335C 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE070 80243360 0280202D */  daddu     $a0, $s4, $zero
/* 7EE074 80243364 0260282D */  daddu     $a1, $s3, $zero
/* 7EE078 80243368 0C090B45 */  jal       func_80242D14
/* 7EE07C 8024336C 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE080 80243370 08090CF6 */  j         .L802433D8
/* 7EE084 80243374 00000000 */   nop      
/* 7EE088 80243378 0280202D */  daddu     $a0, $s4, $zero
/* 7EE08C 8024337C 0260282D */  daddu     $a1, $s3, $zero
/* 7EE090 80243380 0C090B63 */  jal       func_80242D8C
/* 7EE094 80243384 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE098 80243388 0280202D */  daddu     $a0, $s4, $zero
/* 7EE09C 8024338C 0260282D */  daddu     $a1, $s3, $zero
/* 7EE0A0 80243390 0C090BAF */  jal       func_80242EBC
/* 7EE0A4 80243394 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE0A8 80243398 08090CF6 */  j         .L802433D8
/* 7EE0AC 8024339C 00000000 */   nop      
/* 7EE0B0 802433A0 0280202D */  daddu     $a0, $s4, $zero
/* 7EE0B4 802433A4 0260282D */  daddu     $a1, $s3, $zero
/* 7EE0B8 802433A8 0C090BF7 */  jal       func_80242FDC
/* 7EE0BC 802433AC 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE0C0 802433B0 08090CF6 */  j         .L802433D8
/* 7EE0C4 802433B4 00000000 */   nop      
/* 7EE0C8 802433B8 0280202D */  daddu     $a0, $s4, $zero
/* 7EE0CC 802433BC 0260282D */  daddu     $a1, $s3, $zero
/* 7EE0D0 802433C0 0C090C11 */  jal       func_80243044
/* 7EE0D4 802433C4 02A0302D */   daddu    $a2, $s5, $zero
/* 7EE0D8 802433C8 08090CF6 */  j         .L802433D8
/* 7EE0DC 802433CC 00000000 */   nop      
/* 7EE0E0 802433D0 0C0129CF */  jal       func_8004A73C
/* 7EE0E4 802433D4 0280202D */   daddu    $a0, $s4, $zero
.L802433D8:
/* 7EE0E8 802433D8 8FBF0060 */  lw        $ra, 0x60($sp)
/* 7EE0EC 802433DC 8FB5005C */  lw        $s5, 0x5c($sp)
/* 7EE0F0 802433E0 8FB40058 */  lw        $s4, 0x58($sp)
/* 7EE0F4 802433E4 8FB30054 */  lw        $s3, 0x54($sp)
/* 7EE0F8 802433E8 8FB20050 */  lw        $s2, 0x50($sp)
/* 7EE0FC 802433EC 8FB1004C */  lw        $s1, 0x4c($sp)
/* 7EE100 802433F0 8FB00048 */  lw        $s0, 0x48($sp)
/* 7EE104 802433F4 0000102D */  daddu     $v0, $zero, $zero
/* 7EE108 802433F8 03E00008 */  jr        $ra
/* 7EE10C 802433FC 27BD0068 */   addiu    $sp, $sp, 0x68

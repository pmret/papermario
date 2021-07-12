.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802461B0_AFDB00
.word L80240720_AF8070, L802408B8_AF8208, L80240ACC_AF841C, L80240ACC_AF841C, L80240ACC_AF841C, L80240ACC_AF841C, L80240ACC_AF841C, L80240ACC_AF841C, L80240ACC_AF841C, L80240ACC_AF841C, L80240938_AF8288, L8024096C_AF82BC, L80240A78_AF83C8

.section .text

glabel func_802406C4_AF8014
/* AF8014 802406C4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* AF8018 802406C8 AFB50024 */  sw        $s5, 0x24($sp)
/* AF801C 802406CC 0080A82D */  daddu     $s5, $a0, $zero
/* AF8020 802406D0 AFBF0028 */  sw        $ra, 0x28($sp)
/* AF8024 802406D4 AFB40020 */  sw        $s4, 0x20($sp)
/* AF8028 802406D8 AFB3001C */  sw        $s3, 0x1c($sp)
/* AF802C 802406DC AFB20018 */  sw        $s2, 0x18($sp)
/* AF8030 802406E0 AFB10014 */  sw        $s1, 0x14($sp)
/* AF8034 802406E4 AFB00010 */  sw        $s0, 0x10($sp)
/* AF8038 802406E8 10A00003 */  beqz      $a1, .L802406F8
/* AF803C 802406EC 8EA6000C */   lw       $a2, 0xc($s5)
/* AF8040 802406F0 3C018024 */  lui       $at, %hi(D_80246558_C60C98)
/* AF8044 802406F4 AC206558 */  sw        $zero, %lo(D_80246558_C60C98)($at)
.L802406F8:
/* AF8048 802406F8 3C038024 */  lui       $v1, %hi(D_80246558_C60C98)
/* AF804C 802406FC 8C636558 */  lw        $v1, %lo(D_80246558_C60C98)($v1)
/* AF8050 80240700 2C62000D */  sltiu     $v0, $v1, 0xd
/* AF8054 80240704 104000F1 */  beqz      $v0, L80240ACC_AF841C
/* AF8058 80240708 00031080 */   sll      $v0, $v1, 2
/* AF805C 8024070C 3C018024 */  lui       $at, %hi(jtbl_802461B0_AFDB00)
/* AF8060 80240710 00220821 */  addu      $at, $at, $v0
/* AF8064 80240714 8C2261B0 */  lw        $v0, %lo(jtbl_802461B0_AFDB00)($at)
/* AF8068 80240718 00400008 */  jr        $v0
/* AF806C 8024071C 00000000 */   nop
glabel L80240720_AF8070
/* AF8070 80240720 02A0202D */  daddu     $a0, $s5, $zero
/* AF8074 80240724 8CC50000 */  lw        $a1, ($a2)
/* AF8078 80240728 0C0B1EAF */  jal       get_variable
/* AF807C 8024072C 24140009 */   addiu    $s4, $zero, 9
/* AF8080 80240730 3C058024 */  lui       $a1, %hi(func_802406A0_AF7FF0)
/* AF8084 80240734 24A506A0 */  addiu     $a1, $a1, %lo(func_802406A0_AF7FF0)
/* AF8088 80240738 3C018024 */  lui       $at, %hi(D_80246534)
/* AF808C 8024073C AC226534 */  sw        $v0, %lo(D_80246534)($at)
/* AF8090 80240740 0C048C8F */  jal       create_generic_entity_frontUI
/* AF8094 80240744 0000202D */   daddu    $a0, $zero, $zero
/* AF8098 80240748 3C038024 */  lui       $v1, %hi(D_8024659C)
/* AF809C 8024074C 2463659C */  addiu     $v1, $v1, %lo(D_8024659C)
/* AF80A0 80240750 3C018024 */  lui       $at, %hi(D_80246554)
/* AF80A4 80240754 AC226554 */  sw        $v0, %lo(D_80246554)($at)
/* AF80A8 80240758 3C018024 */  lui       $at, %hi(dgb_08_npcGroup_80246528)
/* AF80AC 8024075C AC206528 */  sw        $zero, %lo(dgb_08_npcGroup_80246528)($at)
/* AF80B0 80240760 3C018024 */  lui       $at, %hi(D_80246530)
/* AF80B4 80240764 AC206530 */  sw        $zero, %lo(D_80246530)($at)
.L80240768:
/* AF80B8 80240768 AC600000 */  sw        $zero, ($v1)
/* AF80BC 8024076C 2694FFFF */  addiu     $s4, $s4, -1
/* AF80C0 80240770 0681FFFD */  bgez      $s4, .L80240768
/* AF80C4 80240774 2463FFFC */   addiu    $v1, $v1, -4
/* AF80C8 80240778 2414000A */  addiu     $s4, $zero, 0xa
/* AF80CC 8024077C 3C048011 */  lui       $a0, %hi(D_80108B28)
/* AF80D0 80240780 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* AF80D4 80240784 3C038024 */  lui       $v1, %hi(D_80246538_C8BFE8)
/* AF80D8 80240788 24636538 */  addiu     $v1, $v1, %lo(D_80246538_C8BFE8)
/* AF80DC 8024078C 2402000C */  addiu     $v0, $zero, 0xc
/* AF80E0 80240790 AC620004 */  sw        $v0, 4($v1)
/* AF80E4 80240794 24020018 */  addiu     $v0, $zero, 0x18
/* AF80E8 80240798 AC620008 */  sw        $v0, 8($v1)
/* AF80EC 8024079C 24020024 */  addiu     $v0, $zero, 0x24
/* AF80F0 802407A0 AC62000C */  sw        $v0, 0xc($v1)
/* AF80F4 802407A4 24020030 */  addiu     $v0, $zero, 0x30
/* AF80F8 802407A8 AC620010 */  sw        $v0, 0x10($v1)
/* AF80FC 802407AC 2402003C */  addiu     $v0, $zero, 0x3c
/* AF8100 802407B0 AC620014 */  sw        $v0, 0x14($v1)
/* AF8104 802407B4 24020005 */  addiu     $v0, $zero, 5
/* AF8108 802407B8 3C118024 */  lui       $s1, %hi(D_8024655C)
/* AF810C 802407BC 2631655C */  addiu     $s1, $s1, %lo(D_8024655C)
/* AF8110 802407C0 3C018024 */  lui       $at, %hi(D_80246550_C8C000)
/* AF8114 802407C4 AC226550 */  sw        $v0, %lo(D_80246550_C8C000)($at)
/* AF8118 802407C8 2402FFD0 */  addiu     $v0, $zero, -0x30
/* AF811C 802407CC 3C108024 */  lui       $s0, %hi(D_80246560_C8C010)
/* AF8120 802407D0 26106560 */  addiu     $s0, $s0, %lo(D_80246560_C8C010)
/* AF8124 802407D4 3C018024 */  lui       $at, %hi(D_802465A0)
/* AF8128 802407D8 AC2065A0 */  sw        $zero, %lo(D_802465A0)($at)
/* AF812C 802407DC AC600000 */  sw        $zero, ($v1)
/* AF8130 802407E0 AE220000 */  sw        $v0, ($s1)
/* AF8134 802407E4 24020040 */  addiu     $v0, $zero, 0x40
/* AF8138 802407E8 0C050529 */  jal       create_hud_element
/* AF813C 802407EC AE020000 */   sw       $v0, ($s0)
/* AF8140 802407F0 0040982D */  daddu     $s3, $v0, $zero
/* AF8144 802407F4 0260202D */  daddu     $a0, $s3, $zero
/* AF8148 802407F8 8E250000 */  lw        $a1, ($s1)
/* AF814C 802407FC 8E060000 */  lw        $a2, ($s0)
/* AF8150 80240800 3C128024 */  lui       $s2, %hi(D_80246568_C8C018)
/* AF8154 80240804 26526568 */  addiu     $s2, $s2, %lo(D_80246568_C8C018)
/* AF8158 80240808 0C051261 */  jal       set_hud_element_render_pos
/* AF815C 8024080C AE530000 */   sw       $s3, ($s2)
/* AF8160 80240810 0260202D */  daddu     $a0, $s3, $zero
/* AF8164 80240814 0C051277 */  jal       set_hud_element_render_depth
/* AF8168 80240818 0000282D */   daddu    $a1, $zero, $zero
/* AF816C 8024081C 0260202D */  daddu     $a0, $s3, $zero
/* AF8170 80240820 0C051280 */  jal       set_hud_element_flags
/* AF8174 80240824 24050082 */   addiu    $a1, $zero, 0x82
/* AF8178 80240828 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* AF817C 8024082C 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* AF8180 80240830 0C050529 */  jal       create_hud_element
/* AF8184 80240834 00000000 */   nop
/* AF8188 80240838 0040982D */  daddu     $s3, $v0, $zero
/* AF818C 8024083C 8E250000 */  lw        $a1, ($s1)
/* AF8190 80240840 8E060000 */  lw        $a2, ($s0)
/* AF8194 80240844 0260202D */  daddu     $a0, $s3, $zero
/* AF8198 80240848 AE530004 */  sw        $s3, 4($s2)
/* AF819C 8024084C 0C051261 */  jal       set_hud_element_render_pos
/* AF81A0 80240850 24C6001C */   addiu    $a2, $a2, 0x1c
/* AF81A4 80240854 0260202D */  daddu     $a0, $s3, $zero
/* AF81A8 80240858 0C051277 */  jal       set_hud_element_render_depth
/* AF81AC 8024085C 0000282D */   daddu    $a1, $zero, $zero
/* AF81B0 80240860 0260202D */  daddu     $a0, $s3, $zero
/* AF81B4 80240864 0C051280 */  jal       set_hud_element_flags
/* AF81B8 80240868 24050082 */   addiu    $a1, $zero, 0x82
/* AF81BC 8024086C 8E530000 */  lw        $s3, ($s2)
/* AF81C0 80240870 240500FF */  addiu     $a1, $zero, 0xff
/* AF81C4 80240874 0C0513AC */  jal       set_hud_element_alpha
/* AF81C8 80240878 0260202D */   daddu    $a0, $s3, $zero
/* AF81CC 8024087C 0260202D */  daddu     $a0, $s3, $zero
/* AF81D0 80240880 0C05128B */  jal       clear_hud_element_flags
/* AF81D4 80240884 24050002 */   addiu    $a1, $zero, 2
/* AF81D8 80240888 8E530004 */  lw        $s3, 4($s2)
/* AF81DC 8024088C 240500FF */  addiu     $a1, $zero, 0xff
/* AF81E0 80240890 0C0513AC */  jal       set_hud_element_alpha
/* AF81E4 80240894 0260202D */   daddu    $a0, $s3, $zero
/* AF81E8 80240898 0260202D */  daddu     $a0, $s3, $zero
/* AF81EC 8024089C 0C05128B */  jal       clear_hud_element_flags
/* AF81F0 802408A0 24050002 */   addiu    $a1, $zero, 2
/* AF81F4 802408A4 24020001 */  addiu     $v0, $zero, 1
/* AF81F8 802408A8 3C018024 */  lui       $at, %hi(D_80246558_C60C98)
/* AF81FC 802408AC AC226558 */  sw        $v0, %lo(D_80246558_C60C98)($at)
/* AF8200 802408B0 080902B3 */  j         L80240ACC_AF841C
/* AF8204 802408B4 AEB40070 */   sw       $s4, 0x70($s5)
glabel L802408B8_AF8208
/* AF8208 802408B8 3C128024 */  lui       $s2, %hi(D_8024655C)
/* AF820C 802408BC 2652655C */  addiu     $s2, $s2, %lo(D_8024655C)
/* AF8210 802408C0 8E420000 */  lw        $v0, ($s2)
/* AF8214 802408C4 24420014 */  addiu     $v0, $v0, 0x14
/* AF8218 802408C8 AE420000 */  sw        $v0, ($s2)
/* AF821C 802408CC 28420033 */  slti      $v0, $v0, 0x33
/* AF8220 802408D0 14400002 */  bnez      $v0, .L802408DC
/* AF8224 802408D4 24020032 */   addiu    $v0, $zero, 0x32
/* AF8228 802408D8 AE420000 */  sw        $v0, ($s2)
.L802408DC:
/* AF822C 802408DC 3C118024 */  lui       $s1, %hi(D_80246568_C8C018)
/* AF8230 802408E0 26316568 */  addiu     $s1, $s1, %lo(D_80246568_C8C018)
/* AF8234 802408E4 3C108024 */  lui       $s0, %hi(D_80246560_C8C010)
/* AF8238 802408E8 26106560 */  addiu     $s0, $s0, %lo(D_80246560_C8C010)
/* AF823C 802408EC 8E240000 */  lw        $a0, ($s1)
/* AF8240 802408F0 8E450000 */  lw        $a1, ($s2)
/* AF8244 802408F4 0C051261 */  jal       set_hud_element_render_pos
/* AF8248 802408F8 8E060000 */   lw       $a2, ($s0)
/* AF824C 802408FC 8E240004 */  lw        $a0, 4($s1)
/* AF8250 80240900 8E060000 */  lw        $a2, ($s0)
/* AF8254 80240904 8E450000 */  lw        $a1, ($s2)
/* AF8258 80240908 0C051261 */  jal       set_hud_element_render_pos
/* AF825C 8024090C 24C6001C */   addiu    $a2, $a2, 0x1c
/* AF8260 80240910 8EA20070 */  lw        $v0, 0x70($s5)
/* AF8264 80240914 10400003 */  beqz      $v0, .L80240924
/* AF8268 80240918 2442FFFF */   addiu    $v0, $v0, -1
/* AF826C 8024091C 080902B3 */  j         L80240ACC_AF841C
/* AF8270 80240920 AEA20070 */   sw       $v0, 0x70($s5)
.L80240924:
/* AF8274 80240924 2402000A */  addiu     $v0, $zero, 0xa
/* AF8278 80240928 3C018024 */  lui       $at, %hi(D_80246558_C60C98)
/* AF827C 8024092C AC226558 */  sw        $v0, %lo(D_80246558_C60C98)($at)
/* AF8280 80240930 080902B3 */  j         L80240ACC_AF841C
/* AF8284 80240934 00000000 */   nop
glabel L80240938_AF8288
/* AF8288 80240938 3C048024 */  lui       $a0, %hi(D_80246568_C8C018)
/* AF828C 8024093C 8C846568 */  lw        $a0, %lo(D_80246568_C8C018)($a0)
/* AF8290 80240940 3C058011 */  lui       $a1, %hi(D_80108B80)
/* AF8294 80240944 24A58B80 */  addiu     $a1, $a1, %lo(D_80108B80)
/* AF8298 80240948 0C0511FF */  jal       set_hud_element_script
/* AF829C 8024094C 00000000 */   nop
/* AF82A0 80240950 2402000B */  addiu     $v0, $zero, 0xb
/* AF82A4 80240954 3C018024 */  lui       $at, %hi(dgb_08_npcGroup_80246528)
/* AF82A8 80240958 AC206528 */  sw        $zero, %lo(dgb_08_npcGroup_80246528)($at)
/* AF82AC 8024095C 3C018024 */  lui       $at, %hi(D_8024652C)
/* AF82B0 80240960 AC20652C */  sw        $zero, %lo(D_8024652C)($at)
/* AF82B4 80240964 3C018024 */  lui       $at, %hi(D_80246558_C60C98)
/* AF82B8 80240968 AC226558 */  sw        $v0, %lo(D_80246558_C60C98)($at)
glabel L8024096C_AF82BC
/* AF82BC 8024096C 3C038024 */  lui       $v1, %hi(D_80246550_C8C000)
/* AF82C0 80240970 8C636550 */  lw        $v1, %lo(D_80246550_C8C000)($v1)
/* AF82C4 80240974 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AF82C8 80240978 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AF82CC 8024097C 00031880 */  sll       $v1, $v1, 2
/* AF82D0 80240980 8C420010 */  lw        $v0, 0x10($v0)
/* AF82D4 80240984 3C048024 */  lui       $a0, %hi(D_80246538_C8BFE8)
/* AF82D8 80240988 00832021 */  addu      $a0, $a0, $v1
/* AF82DC 8024098C 8C846538 */  lw        $a0, %lo(D_80246538_C8BFE8)($a0)
/* AF82E0 80240990 30428000 */  andi      $v0, $v0, 0x8000
/* AF82E4 80240994 10400006 */  beqz      $v0, .L802409B0
/* AF82E8 80240998 00000000 */   nop
/* AF82EC 8024099C 3C038024 */  lui       $v1, %hi(dgb_08_npcGroup_80246528)
/* AF82F0 802409A0 24636528 */  addiu     $v1, $v1, %lo(dgb_08_npcGroup_80246528)
/* AF82F4 802409A4 8C620000 */  lw        $v0, ($v1)
/* AF82F8 802409A8 24420001 */  addiu     $v0, $v0, 1
/* AF82FC 802409AC AC620000 */  sw        $v0, ($v1)
.L802409B0:
/* AF8300 802409B0 3C038024 */  lui       $v1, %hi(dgb_08_npcGroup_80246528)
/* AF8304 802409B4 24636528 */  addiu     $v1, $v1, %lo(dgb_08_npcGroup_80246528)
/* AF8308 802409B8 8C620000 */  lw        $v0, ($v1)
/* AF830C 802409BC 0082102A */  slt       $v0, $a0, $v0
/* AF8310 802409C0 54400001 */  bnel      $v0, $zero, .L802409C8
/* AF8314 802409C4 AC640000 */   sw       $a0, ($v1)
.L802409C8:
/* AF8318 802409C8 3C048024 */  lui       $a0, %hi(D_8024652C)
/* AF831C 802409CC 2484652C */  addiu     $a0, $a0, %lo(D_8024652C)
/* AF8320 802409D0 8C830000 */  lw        $v1, ($a0)
/* AF8324 802409D4 24020002 */  addiu     $v0, $zero, 2
/* AF8328 802409D8 14620003 */  bne       $v1, $v0, .L802409E8
/* AF832C 802409DC 0000A02D */   daddu    $s4, $zero, $zero
/* AF8330 802409E0 24020003 */  addiu     $v0, $zero, 3
/* AF8334 802409E4 AC820000 */  sw        $v0, ($a0)
.L802409E8:
/* AF8338 802409E8 3C038024 */  lui       $v1, %hi(D_80246578)
/* AF833C 802409EC 24636578 */  addiu     $v1, $v1, %lo(D_80246578)
.L802409F0:
/* AF8340 802409F0 8C620000 */  lw        $v0, ($v1)
/* AF8344 802409F4 14400006 */  bnez      $v0, .L80240A10
/* AF8348 802409F8 2A82000A */   slti     $v0, $s4, 0xa
/* AF834C 802409FC 26940001 */  addiu     $s4, $s4, 1
/* AF8350 80240A00 2A82000A */  slti      $v0, $s4, 0xa
/* AF8354 80240A04 1440FFFA */  bnez      $v0, .L802409F0
/* AF8358 80240A08 24630004 */   addiu    $v1, $v1, 4
/* AF835C 80240A0C 2A82000A */  slti      $v0, $s4, 0xa
.L80240A10:
/* AF8360 80240A10 14400006 */  bnez      $v0, .L80240A2C
/* AF8364 80240A14 24020003 */   addiu    $v0, $zero, 3
/* AF8368 80240A18 24020002 */  addiu     $v0, $zero, 2
/* AF836C 80240A1C 3C018024 */  lui       $at, %hi(D_8024652C)
/* AF8370 80240A20 AC22652C */  sw        $v0, %lo(D_8024652C)($at)
/* AF8374 80240A24 08090291 */  j         .L80240A44
/* AF8378 80240A28 00000000 */   nop
.L80240A2C:
/* AF837C 80240A2C 3C048024 */  lui       $a0, %hi(D_8024652C)
/* AF8380 80240A30 2484652C */  addiu     $a0, $a0, %lo(D_8024652C)
/* AF8384 80240A34 8C830000 */  lw        $v1, ($a0)
/* AF8388 80240A38 10620002 */  beq       $v1, $v0, .L80240A44
/* AF838C 80240A3C 24020002 */   addiu    $v0, $zero, 2
/* AF8390 80240A40 AC820000 */  sw        $v0, ($a0)
.L80240A44:
/* AF8394 80240A44 3C038024 */  lui       $v1, %hi(D_80246534)
/* AF8398 80240A48 24636534 */  addiu     $v1, $v1, %lo(D_80246534)
/* AF839C 80240A4C 8C620000 */  lw        $v0, ($v1)
/* AF83A0 80240A50 2442FFFF */  addiu     $v0, $v0, -1
/* AF83A4 80240A54 1440001D */  bnez      $v0, L80240ACC_AF841C
/* AF83A8 80240A58 AC620000 */   sw       $v0, ($v1)
/* AF83AC 80240A5C 24020005 */  addiu     $v0, $zero, 5
/* AF83B0 80240A60 AC620000 */  sw        $v0, ($v1)
/* AF83B4 80240A64 2402000C */  addiu     $v0, $zero, 0xc
/* AF83B8 80240A68 3C018024 */  lui       $at, %hi(D_80246558_C60C98)
/* AF83BC 80240A6C AC226558 */  sw        $v0, %lo(D_80246558_C60C98)($at)
/* AF83C0 80240A70 080902B3 */  j         L80240ACC_AF841C
/* AF83C4 80240A74 00000000 */   nop
glabel L80240A78_AF83C8
/* AF83C8 80240A78 3C038024 */  lui       $v1, %hi(D_80246534)
/* AF83CC 80240A7C 24636534 */  addiu     $v1, $v1, %lo(D_80246534)
/* AF83D0 80240A80 8C620000 */  lw        $v0, ($v1)
/* AF83D4 80240A84 54400010 */  bnel      $v0, $zero, .L80240AC8
/* AF83D8 80240A88 2442FFFF */   addiu    $v0, $v0, -1
/* AF83DC 80240A8C 3C028024 */  lui       $v0, %hi(dgb_08_npcGroup_80246528)
/* AF83E0 80240A90 8C426528 */  lw        $v0, %lo(dgb_08_npcGroup_80246528)($v0)
/* AF83E4 80240A94 3C108024 */  lui       $s0, %hi(D_80246568_C8C018)
/* AF83E8 80240A98 26106568 */  addiu     $s0, $s0, %lo(D_80246568_C8C018)
/* AF83EC 80240A9C AEA20084 */  sw        $v0, 0x84($s5)
/* AF83F0 80240AA0 0C05123D */  jal       free_hud_element
/* AF83F4 80240AA4 8E040000 */   lw       $a0, ($s0)
/* AF83F8 80240AA8 0C05123D */  jal       free_hud_element
/* AF83FC 80240AAC 8E040004 */   lw       $a0, 4($s0)
/* AF8400 80240AB0 3C048024 */  lui       $a0, %hi(D_80246554)
/* AF8404 80240AB4 8C846554 */  lw        $a0, %lo(D_80246554)($a0)
/* AF8408 80240AB8 0C048D70 */  jal       free_generic_entity
/* AF840C 80240ABC 00000000 */   nop
/* AF8410 80240AC0 080902CA */  j         .L80240B28
/* AF8414 80240AC4 24020002 */   addiu    $v0, $zero, 2
.L80240AC8:
/* AF8418 80240AC8 AC620000 */  sw        $v0, ($v1)
glabel L80240ACC_AF841C
/* AF841C 80240ACC 3C058024 */  lui       $a1, %hi(D_802465A0)
/* AF8420 80240AD0 24A565A0 */  addiu     $a1, $a1, %lo(D_802465A0)
/* AF8424 80240AD4 8CA20000 */  lw        $v0, ($a1)
/* AF8428 80240AD8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AF842C 80240ADC 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AF8430 80240AE0 00022080 */  sll       $a0, $v0, 2
/* AF8434 80240AE4 8C630010 */  lw        $v1, 0x10($v1)
/* AF8438 80240AE8 24420001 */  addiu     $v0, $v0, 1
/* AF843C 80240AEC ACA20000 */  sw        $v0, ($a1)
/* AF8440 80240AF0 2842000A */  slti      $v0, $v0, 0xa
/* AF8444 80240AF4 30638000 */  andi      $v1, $v1, 0x8000
/* AF8448 80240AF8 3C018024 */  lui       $at, %hi(D_80246578)
/* AF844C 80240AFC 00240821 */  addu      $at, $at, $a0
/* AF8450 80240B00 AC236578 */  sw        $v1, %lo(D_80246578)($at)
/* AF8454 80240B04 50400001 */  beql      $v0, $zero, .L80240B0C
/* AF8458 80240B08 ACA00000 */   sw       $zero, ($a1)
.L80240B0C:
/* AF845C 80240B0C 02A0202D */  daddu     $a0, $s5, $zero
/* AF8460 80240B10 3C05F70F */  lui       $a1, 0xf70f
/* AF8464 80240B14 3C068024 */  lui       $a2, %hi(D_8024652C)
/* AF8468 80240B18 8CC6652C */  lw        $a2, %lo(D_8024652C)($a2)
/* AF846C 80240B1C 0C0B2026 */  jal       set_variable
/* AF8470 80240B20 34A52E83 */   ori      $a1, $a1, 0x2e83
/* AF8474 80240B24 0000102D */  daddu     $v0, $zero, $zero
.L80240B28:
/* AF8478 80240B28 8FBF0028 */  lw        $ra, 0x28($sp)
/* AF847C 80240B2C 8FB50024 */  lw        $s5, 0x24($sp)
/* AF8480 80240B30 8FB40020 */  lw        $s4, 0x20($sp)
/* AF8484 80240B34 8FB3001C */  lw        $s3, 0x1c($sp)
/* AF8488 80240B38 8FB20018 */  lw        $s2, 0x18($sp)
/* AF848C 80240B3C 8FB10014 */  lw        $s1, 0x14($sp)
/* AF8490 80240B40 8FB00010 */  lw        $s0, 0x10($sp)
/* AF8494 80240B44 03E00008 */  jr        $ra
/* AF8498 80240B48 27BD0030 */   addiu    $sp, $sp, 0x30

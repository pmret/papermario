.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8ABF90
/* 8ABF90 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8ABF94 80240004 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8ABF98 80240008 0080882D */  daddu     $s1, $a0, $zero
/* 8ABF9C 8024000C AFBF0020 */  sw        $ra, 0x20($sp)
/* 8ABFA0 80240010 AFB00018 */  sw        $s0, 0x18($sp)
/* 8ABFA4 80240014 10A0003B */  beqz      $a1, .L80240104
/* 8ABFA8 80240018 8E30000C */   lw       $s0, 0xc($s1)
/* 8ABFAC 8024001C 3C048024 */  lui       $a0, %hi(D_802440E0)
/* 8ABFB0 80240020 248440E0 */  addiu     $a0, $a0, %lo(D_802440E0)
/* 8ABFB4 80240024 3C058024 */  lui       $a1, %hi(D_802440E1)
/* 8ABFB8 80240028 24A540E1 */  addiu     $a1, $a1, %lo(D_802440E1)
/* 8ABFBC 8024002C 3C068024 */  lui       $a2, %hi(D_802440E2)
/* 8ABFC0 80240030 24C640E2 */  addiu     $a2, $a2, %lo(D_802440E2)
/* 8ABFC4 80240034 3C078024 */  lui       $a3, %hi(D_802440E3)
/* 8ABFC8 80240038 24E740E3 */  addiu     $a3, $a3, %lo(D_802440E3)
/* 8ABFCC 8024003C 3C028024 */  lui       $v0, %hi(dgb_09_extraAnimationList_802440E4)
/* 8ABFD0 80240040 244240E4 */  addiu     $v0, $v0, %lo(dgb_09_extraAnimationList_802440E4)
/* 8ABFD4 80240044 AFA20010 */  sw        $v0, 0x10($sp)
/* 8ABFD8 80240048 3C028024 */  lui       $v0, %hi(D_802440E5)
/* 8ABFDC 8024004C 244240E5 */  addiu     $v0, $v0, %lo(D_802440E5)
/* 8ABFE0 80240050 0C046FF5 */  jal       get_model_env_color_parameters
/* 8ABFE4 80240054 AFA20014 */   sw       $v0, 0x14($sp)
/* 8ABFE8 80240058 8E050000 */  lw        $a1, ($s0)
/* 8ABFEC 8024005C 26100004 */  addiu     $s0, $s0, 4
/* 8ABFF0 80240060 0C0B1EAF */  jal       get_variable
/* 8ABFF4 80240064 0220202D */   daddu    $a0, $s1, $zero
/* 8ABFF8 80240068 3C018024 */  lui       $at, %hi(mac_01_GetPlayerCoins)
/* 8ABFFC 8024006C AC2240E8 */  sw        $v0, %lo(mac_01_GetPlayerCoins)($at)
/* 8AC000 80240070 8E050000 */  lw        $a1, ($s0)
/* 8AC004 80240074 26100004 */  addiu     $s0, $s0, 4
/* 8AC008 80240078 0C0B1EAF */  jal       get_variable
/* 8AC00C 8024007C 0220202D */   daddu    $a0, $s1, $zero
/* 8AC010 80240080 3C018024 */  lui       $at, %hi(dgb_09_npcAISettings_802440EC)
/* 8AC014 80240084 AC2240EC */  sw        $v0, %lo(dgb_09_npcAISettings_802440EC)($at)
/* 8AC018 80240088 8E050000 */  lw        $a1, ($s0)
/* 8AC01C 8024008C 26100004 */  addiu     $s0, $s0, 4
/* 8AC020 80240090 0C0B1EAF */  jal       get_variable
/* 8AC024 80240094 0220202D */   daddu    $a0, $s1, $zero
/* 8AC028 80240098 3C018024 */  lui       $at, %hi(D_802440F0_BC1290)
/* 8AC02C 8024009C AC2240F0 */  sw        $v0, %lo(D_802440F0_BC1290)($at)
/* 8AC030 802400A0 8E050000 */  lw        $a1, ($s0)
/* 8AC034 802400A4 26100004 */  addiu     $s0, $s0, 4
/* 8AC038 802400A8 0C0B1EAF */  jal       get_variable
/* 8AC03C 802400AC 0220202D */   daddu    $a0, $s1, $zero
/* 8AC040 802400B0 3C018024 */  lui       $at, %hi(flo_16_npcGroup_802440F4)
/* 8AC044 802400B4 AC2240F4 */  sw        $v0, %lo(flo_16_npcGroup_802440F4)($at)
/* 8AC048 802400B8 8E050000 */  lw        $a1, ($s0)
/* 8AC04C 802400BC 26100004 */  addiu     $s0, $s0, 4
/* 8AC050 802400C0 0C0B1EAF */  jal       get_variable
/* 8AC054 802400C4 0220202D */   daddu    $a0, $s1, $zero
/* 8AC058 802400C8 3C018024 */  lui       $at, %hi(D_802440F8)
/* 8AC05C 802400CC AC2240F8 */  sw        $v0, %lo(D_802440F8)($at)
/* 8AC060 802400D0 8E050000 */  lw        $a1, ($s0)
/* 8AC064 802400D4 26100004 */  addiu     $s0, $s0, 4
/* 8AC068 802400D8 0C0B1EAF */  jal       get_variable
/* 8AC06C 802400DC 0220202D */   daddu    $a0, $s1, $zero
/* 8AC070 802400E0 3C018024 */  lui       $at, %hi(func_802440FC_80497C)
/* 8AC074 802400E4 AC2240FC */  sw        $v0, %lo(func_802440FC_80497C)($at)
/* 8AC078 802400E8 8E050000 */  lw        $a1, ($s0)
/* 8AC07C 802400EC 0C0B1EAF */  jal       get_variable
/* 8AC080 802400F0 0220202D */   daddu    $a0, $s1, $zero
/* 8AC084 802400F4 3C018024 */  lui       $at, %hi(dgb_08_npcAI_80244100)
/* 8AC088 802400F8 AC224100 */  sw        $v0, %lo(dgb_08_npcAI_80244100)($at)
/* 8AC08C 802400FC 3C018024 */  lui       $at, %hi(D_80244104)
/* 8AC090 80240100 AC204104 */  sw        $zero, %lo(D_80244104)($at)
.L80240104:
/* 8AC094 80240104 3C118024 */  lui       $s1, %hi(dgb_08_npcAI_80244100)
/* 8AC098 80240108 26314100 */  addiu     $s1, $s1, %lo(dgb_08_npcAI_80244100)
/* 8AC09C 8024010C 8E2F0000 */  lw        $t7, ($s1)
/* 8AC0A0 80240110 19E00088 */  blez      $t7, .L80240334
/* 8AC0A4 80240114 00000000 */   nop
/* 8AC0A8 80240118 3C108024 */  lui       $s0, %hi(D_80244104)
/* 8AC0AC 8024011C 26104104 */  addiu     $s0, $s0, %lo(D_80244104)
/* 8AC0B0 80240120 8E030000 */  lw        $v1, ($s0)
/* 8AC0B4 80240124 3C048024 */  lui       $a0, %hi(D_802440E0)
/* 8AC0B8 80240128 908440E0 */  lbu       $a0, %lo(D_802440E0)($a0)
/* 8AC0BC 8024012C 3C028024 */  lui       $v0, %hi(mac_01_GetPlayerCoins)
/* 8AC0C0 80240130 8C4240E8 */  lw        $v0, %lo(mac_01_GetPlayerCoins)($v0)
/* 8AC0C4 80240134 24630001 */  addiu     $v1, $v1, 1
/* 8AC0C8 80240138 00441023 */  subu      $v0, $v0, $a0
/* 8AC0CC 8024013C 00430018 */  mult      $v0, $v1
/* 8AC0D0 80240140 00004012 */  mflo      $t0
/* 8AC0D4 80240144 00000000 */  nop
/* 8AC0D8 80240148 15E00002 */  bnez      $t7, .L80240154
/* 8AC0DC 8024014C 010F001A */   div      $zero, $t0, $t7
/* 8AC0E0 80240150 0007000D */  break     7
.L80240154:
/* 8AC0E4 80240154 2401FFFF */   addiu    $at, $zero, -1
/* 8AC0E8 80240158 15E10004 */  bne       $t7, $at, .L8024016C
/* 8AC0EC 8024015C 3C018000 */   lui      $at, 0x8000
/* 8AC0F0 80240160 15010002 */  bne       $t0, $at, .L8024016C
/* 8AC0F4 80240164 00000000 */   nop
/* 8AC0F8 80240168 0006000D */  break     6
.L8024016C:
/* 8AC0FC 8024016C 00007012 */   mflo     $t6
/* 8AC100 80240170 3C058024 */  lui       $a1, %hi(D_802440E1)
/* 8AC104 80240174 90A540E1 */  lbu       $a1, %lo(D_802440E1)($a1)
/* 8AC108 80240178 3C028024 */  lui       $v0, %hi(dgb_09_npcAISettings_802440EC)
/* 8AC10C 8024017C 8C4240EC */  lw        $v0, %lo(dgb_09_npcAISettings_802440EC)($v0)
/* 8AC110 80240180 00451023 */  subu      $v0, $v0, $a1
/* 8AC114 80240184 00430018 */  mult      $v0, $v1
/* 8AC118 80240188 00004012 */  mflo      $t0
/* 8AC11C 8024018C 00000000 */  nop
/* 8AC120 80240190 15E00002 */  bnez      $t7, .L8024019C
/* 8AC124 80240194 010F001A */   div      $zero, $t0, $t7
/* 8AC128 80240198 0007000D */  break     7
.L8024019C:
/* 8AC12C 8024019C 2401FFFF */   addiu    $at, $zero, -1
/* 8AC130 802401A0 15E10004 */  bne       $t7, $at, .L802401B4
/* 8AC134 802401A4 3C018000 */   lui      $at, 0x8000
/* 8AC138 802401A8 15010002 */  bne       $t0, $at, .L802401B4
/* 8AC13C 802401AC 00000000 */   nop
/* 8AC140 802401B0 0006000D */  break     6
.L802401B4:
/* 8AC144 802401B4 00006812 */   mflo     $t5
/* 8AC148 802401B8 3C068024 */  lui       $a2, %hi(D_802440E2)
/* 8AC14C 802401BC 90C640E2 */  lbu       $a2, %lo(D_802440E2)($a2)
/* 8AC150 802401C0 3C028024 */  lui       $v0, %hi(D_802440F0_BC1290)
/* 8AC154 802401C4 8C4240F0 */  lw        $v0, %lo(D_802440F0_BC1290)($v0)
/* 8AC158 802401C8 00461023 */  subu      $v0, $v0, $a2
/* 8AC15C 802401CC 00430018 */  mult      $v0, $v1
/* 8AC160 802401D0 00004012 */  mflo      $t0
/* 8AC164 802401D4 00000000 */  nop
/* 8AC168 802401D8 15E00002 */  bnez      $t7, .L802401E4
/* 8AC16C 802401DC 010F001A */   div      $zero, $t0, $t7
/* 8AC170 802401E0 0007000D */  break     7
.L802401E4:
/* 8AC174 802401E4 2401FFFF */   addiu    $at, $zero, -1
/* 8AC178 802401E8 15E10004 */  bne       $t7, $at, .L802401FC
/* 8AC17C 802401EC 3C018000 */   lui      $at, 0x8000
/* 8AC180 802401F0 15010002 */  bne       $t0, $at, .L802401FC
/* 8AC184 802401F4 00000000 */   nop
/* 8AC188 802401F8 0006000D */  break     6
.L802401FC:
/* 8AC18C 802401FC 00006012 */   mflo     $t4
/* 8AC190 80240200 3C078024 */  lui       $a3, %hi(D_802440E3)
/* 8AC194 80240204 90E740E3 */  lbu       $a3, %lo(D_802440E3)($a3)
/* 8AC198 80240208 3C028024 */  lui       $v0, %hi(flo_16_npcGroup_802440F4)
/* 8AC19C 8024020C 8C4240F4 */  lw        $v0, %lo(flo_16_npcGroup_802440F4)($v0)
/* 8AC1A0 80240210 00471023 */  subu      $v0, $v0, $a3
/* 8AC1A4 80240214 00430018 */  mult      $v0, $v1
/* 8AC1A8 80240218 00004012 */  mflo      $t0
/* 8AC1AC 8024021C 00000000 */  nop
/* 8AC1B0 80240220 15E00002 */  bnez      $t7, .L8024022C
/* 8AC1B4 80240224 010F001A */   div      $zero, $t0, $t7
/* 8AC1B8 80240228 0007000D */  break     7
.L8024022C:
/* 8AC1BC 8024022C 2401FFFF */   addiu    $at, $zero, -1
/* 8AC1C0 80240230 15E10004 */  bne       $t7, $at, .L80240244
/* 8AC1C4 80240234 3C018000 */   lui      $at, 0x8000
/* 8AC1C8 80240238 15010002 */  bne       $t0, $at, .L80240244
/* 8AC1CC 8024023C 00000000 */   nop
/* 8AC1D0 80240240 0006000D */  break     6
.L80240244:
/* 8AC1D4 80240244 00005812 */   mflo     $t3
/* 8AC1D8 80240248 3C098024 */  lui       $t1, %hi(dgb_09_extraAnimationList_802440E4)
/* 8AC1DC 8024024C 912940E4 */  lbu       $t1, %lo(dgb_09_extraAnimationList_802440E4)($t1)
/* 8AC1E0 80240250 3C028024 */  lui       $v0, %hi(D_802440F8)
/* 8AC1E4 80240254 8C4240F8 */  lw        $v0, %lo(D_802440F8)($v0)
/* 8AC1E8 80240258 00491023 */  subu      $v0, $v0, $t1
/* 8AC1EC 8024025C 00430018 */  mult      $v0, $v1
/* 8AC1F0 80240260 00004012 */  mflo      $t0
/* 8AC1F4 80240264 00000000 */  nop
/* 8AC1F8 80240268 15E00002 */  bnez      $t7, .L80240274
/* 8AC1FC 8024026C 010F001A */   div      $zero, $t0, $t7
/* 8AC200 80240270 0007000D */  break     7
.L80240274:
/* 8AC204 80240274 2401FFFF */   addiu    $at, $zero, -1
/* 8AC208 80240278 15E10004 */  bne       $t7, $at, .L8024028C
/* 8AC20C 8024027C 3C018000 */   lui      $at, 0x8000
/* 8AC210 80240280 15010002 */  bne       $t0, $at, .L8024028C
/* 8AC214 80240284 00000000 */   nop
/* 8AC218 80240288 0006000D */  break     6
.L8024028C:
/* 8AC21C 8024028C 00005012 */   mflo     $t2
/* 8AC220 80240290 3C088024 */  lui       $t0, %hi(D_802440E5)
/* 8AC224 80240294 910840E5 */  lbu       $t0, %lo(D_802440E5)($t0)
/* 8AC228 80240298 3C028024 */  lui       $v0, %hi(func_802440FC_80497C)
/* 8AC22C 8024029C 8C4240FC */  lw        $v0, %lo(func_802440FC_80497C)($v0)
/* 8AC230 802402A0 00481023 */  subu      $v0, $v0, $t0
/* 8AC234 802402A4 00430018 */  mult      $v0, $v1
/* 8AC238 802402A8 0000C812 */  mflo      $t9
/* 8AC23C 802402AC 00000000 */  nop
/* 8AC240 802402B0 15E00002 */  bnez      $t7, .L802402BC
/* 8AC244 802402B4 032F001A */   div      $zero, $t9, $t7
/* 8AC248 802402B8 0007000D */  break     7
.L802402BC:
/* 8AC24C 802402BC 2401FFFF */   addiu    $at, $zero, -1
/* 8AC250 802402C0 15E10004 */  bne       $t7, $at, .L802402D4
/* 8AC254 802402C4 3C018000 */   lui      $at, 0x8000
/* 8AC258 802402C8 17210002 */  bne       $t9, $at, .L802402D4
/* 8AC25C 802402CC 00000000 */   nop
/* 8AC260 802402D0 0006000D */  break     6
.L802402D4:
/* 8AC264 802402D4 00001012 */   mflo     $v0
/* 8AC268 802402D8 AE030000 */  sw        $v1, ($s0)
/* 8AC26C 802402DC 008E2021 */  addu      $a0, $a0, $t6
/* 8AC270 802402E0 308400FF */  andi      $a0, $a0, 0xff
/* 8AC274 802402E4 00AD2821 */  addu      $a1, $a1, $t5
/* 8AC278 802402E8 30A500FF */  andi      $a1, $a1, 0xff
/* 8AC27C 802402EC 00CC3021 */  addu      $a2, $a2, $t4
/* 8AC280 802402F0 30C600FF */  andi      $a2, $a2, 0xff
/* 8AC284 802402F4 00EB3821 */  addu      $a3, $a3, $t3
/* 8AC288 802402F8 30E700FF */  andi      $a3, $a3, 0xff
/* 8AC28C 802402FC 012A4821 */  addu      $t1, $t1, $t2
/* 8AC290 80240300 312900FF */  andi      $t1, $t1, 0xff
/* 8AC294 80240304 AFA90010 */  sw        $t1, 0x10($sp)
/* 8AC298 80240308 01024021 */  addu      $t0, $t0, $v0
/* 8AC29C 8024030C 310800FF */  andi      $t0, $t0, 0xff
/* 8AC2A0 80240310 0C046FE6 */  jal       set_model_env_color_parameters
/* 8AC2A4 80240314 AFA80014 */   sw       $t0, 0x14($sp)
/* 8AC2A8 80240318 8E020000 */  lw        $v0, ($s0)
/* 8AC2AC 8024031C 8E230000 */  lw        $v1, ($s1)
/* 8AC2B0 80240320 0043102A */  slt       $v0, $v0, $v1
/* 8AC2B4 80240324 14400013 */  bnez      $v0, .L80240374
/* 8AC2B8 80240328 0000102D */   daddu    $v0, $zero, $zero
/* 8AC2BC 8024032C 080900DD */  j         .L80240374
/* 8AC2C0 80240330 24020002 */   addiu    $v0, $zero, 2
.L80240334:
/* 8AC2C4 80240334 3C028024 */  lui       $v0, %hi(D_802440FB)
/* 8AC2C8 80240338 904240FB */  lbu       $v0, %lo(D_802440FB)($v0)
/* 8AC2CC 8024033C 3C048024 */  lui       $a0, %hi(D_802440EB)
/* 8AC2D0 80240340 908440EB */  lbu       $a0, %lo(D_802440EB)($a0)
/* 8AC2D4 80240344 3C058024 */  lui       $a1, %hi(D_802440EF)
/* 8AC2D8 80240348 90A540EF */  lbu       $a1, %lo(D_802440EF)($a1)
/* 8AC2DC 8024034C 3C068024 */  lui       $a2, %hi(D_802440F3)
/* 8AC2E0 80240350 90C640F3 */  lbu       $a2, %lo(D_802440F3)($a2)
/* 8AC2E4 80240354 3C078024 */  lui       $a3, %hi(D_802440F7)
/* 8AC2E8 80240358 90E740F7 */  lbu       $a3, %lo(D_802440F7)($a3)
/* 8AC2EC 8024035C 3C038024 */  lui       $v1, %hi(D_802440FF)
/* 8AC2F0 80240360 906340FF */  lbu       $v1, %lo(D_802440FF)($v1)
/* 8AC2F4 80240364 AFA20010 */  sw        $v0, 0x10($sp)
/* 8AC2F8 80240368 0C046FE6 */  jal       set_model_env_color_parameters
/* 8AC2FC 8024036C AFA30014 */   sw       $v1, 0x14($sp)
/* 8AC300 80240370 24020002 */  addiu     $v0, $zero, 2
.L80240374:
/* 8AC304 80240374 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8AC308 80240378 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8AC30C 8024037C 8FB00018 */  lw        $s0, 0x18($sp)
/* 8AC310 80240380 03E00008 */  jr        $ra
/* 8AC314 80240384 27BD0028 */   addiu    $sp, $sp, 0x28

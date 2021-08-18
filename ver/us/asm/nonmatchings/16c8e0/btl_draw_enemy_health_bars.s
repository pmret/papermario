.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_draw_enemy_health_bars
/* 16E880 8023FFA0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 16E884 8023FFA4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 16E888 8023FFA8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 16E88C 8023FFAC AFBF0054 */  sw        $ra, 0x54($sp)
/* 16E890 8023FFB0 AFBE0050 */  sw        $fp, 0x50($sp)
/* 16E894 8023FFB4 AFB7004C */  sw        $s7, 0x4c($sp)
/* 16E898 8023FFB8 AFB60048 */  sw        $s6, 0x48($sp)
/* 16E89C 8023FFBC AFB50044 */  sw        $s5, 0x44($sp)
/* 16E8A0 8023FFC0 AFB40040 */  sw        $s4, 0x40($sp)
/* 16E8A4 8023FFC4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 16E8A8 8023FFC8 AFB20038 */  sw        $s2, 0x38($sp)
/* 16E8AC 8023FFCC AFB10034 */  sw        $s1, 0x34($sp)
/* 16E8B0 8023FFD0 AFB00030 */  sw        $s0, 0x30($sp)
/* 16E8B4 8023FFD4 8042007C */  lb        $v0, 0x7c($v0)
/* 16E8B8 8023FFD8 104000EC */  beqz      $v0, .L8024038C
/* 16E8BC 8023FFDC 00000000 */   nop
/* 16E8C0 8023FFE0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 16E8C4 8023FFE4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 16E8C8 8023FFE8 30420001 */  andi      $v0, $v0, 1
/* 16E8CC 8023FFEC 104000E7 */  beqz      $v0, .L8024038C
/* 16E8D0 8023FFF0 0000B82D */   daddu    $s7, $zero, $zero
/* 16E8D4 8023FFF4 27B60020 */  addiu     $s6, $sp, 0x20
/* 16E8D8 8023FFF8 27B50024 */  addiu     $s5, $sp, 0x24
/* 16E8DC 8023FFFC 241E0008 */  addiu     $fp, $zero, 8
/* 16E8E0 80240000 00171080 */  sll       $v0, $s7, 2
.L80240004:
/* 16E8E4 80240004 3C08800E */  lui       $t0, %hi(gBattleStatus)
/* 16E8E8 80240008 2508C070 */  addiu     $t0, $t0, %lo(gBattleStatus)
/* 16E8EC 8024000C 01021021 */  addu      $v0, $t0, $v0
/* 16E8F0 80240010 8C5300E0 */  lw        $s3, 0xe0($v0)
/* 16E8F4 80240014 526000DA */  beql      $s3, $zero, .L80240380
/* 16E8F8 80240018 26F70001 */   addiu    $s7, $s7, 1
/* 16E8FC 8024001C 827401B8 */  lb        $s4, 0x1b8($s3)
/* 16E900 80240020 826301B9 */  lb        $v1, 0x1b9($s3)
/* 16E904 80240024 00141040 */  sll       $v0, $s4, 1
/* 16E908 80240028 00541021 */  addu      $v0, $v0, $s4
/* 16E90C 8024002C 000210C0 */  sll       $v0, $v0, 3
/* 16E910 80240030 00541021 */  addu      $v0, $v0, $s4
/* 16E914 80240034 14600002 */  bnez      $v1, .L80240040
/* 16E918 80240038 0043001A */   div      $zero, $v0, $v1
/* 16E91C 8024003C 0007000D */  break     7
.L80240040:
/* 16E920 80240040 2401FFFF */   addiu    $at, $zero, -1
/* 16E924 80240044 14610004 */  bne       $v1, $at, .L80240058
/* 16E928 80240048 3C018000 */   lui      $at, 0x8000
/* 16E92C 8024004C 14410002 */  bne       $v0, $at, .L80240058
/* 16E930 80240050 00000000 */   nop
/* 16E934 80240054 0006000D */  break     6
.L80240058:
/* 16E938 80240058 00008812 */   mflo     $s1
/* 16E93C 8024005C 826201BC */  lb        $v0, 0x1bc($s3)
/* 16E940 80240060 926301BC */  lbu       $v1, 0x1bc($s3)
/* 16E944 80240064 0222102A */  slt       $v0, $s1, $v0
/* 16E948 80240068 10400008 */  beqz      $v0, .L8024008C
/* 16E94C 8024006C 2462FFFE */   addiu    $v0, $v1, -2
/* 16E950 80240070 A26201BC */  sb        $v0, 0x1bc($s3)
/* 16E954 80240074 00021600 */  sll       $v0, $v0, 0x18
/* 16E958 80240078 00021603 */  sra       $v0, $v0, 0x18
/* 16E95C 8024007C 0051102A */  slt       $v0, $v0, $s1
/* 16E960 80240080 1040000E */  beqz      $v0, .L802400BC
/* 16E964 80240084 3C020004 */   lui      $v0, 4
/* 16E968 80240088 A27101BC */  sb        $s1, 0x1bc($s3)
.L8024008C:
/* 16E96C 8024008C 826201BC */  lb        $v0, 0x1bc($s3)
/* 16E970 80240090 926301BC */  lbu       $v1, 0x1bc($s3)
/* 16E974 80240094 0051102A */  slt       $v0, $v0, $s1
/* 16E978 80240098 10400007 */  beqz      $v0, .L802400B8
/* 16E97C 8024009C 24620002 */   addiu    $v0, $v1, 2
/* 16E980 802400A0 A26201BC */  sb        $v0, 0x1bc($s3)
/* 16E984 802400A4 00021600 */  sll       $v0, $v0, 0x18
/* 16E988 802400A8 00021603 */  sra       $v0, $v0, 0x18
/* 16E98C 802400AC 0222102A */  slt       $v0, $s1, $v0
/* 16E990 802400B0 54400001 */  bnel      $v0, $zero, .L802400B8
/* 16E994 802400B4 A27101BC */   sb       $s1, 0x1bc($s3)
.L802400B8:
/* 16E998 802400B8 3C020004 */  lui       $v0, 4
.L802400BC:
/* 16E99C 802400BC 8E630000 */  lw        $v1, ($s3)
/* 16E9A0 802400C0 34424000 */  ori       $v0, $v0, 0x4000
/* 16E9A4 802400C4 00621024 */  and       $v0, $v1, $v0
/* 16E9A8 802400C8 544000AD */  bnel      $v0, $zero, .L80240380
/* 16E9AC 802400CC 26F70001 */   addiu    $s7, $s7, 1
/* 16E9B0 802400D0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 16E9B4 802400D4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 16E9B8 802400D8 30420002 */  andi      $v0, $v0, 2
/* 16E9BC 802400DC 14400004 */  bnez      $v0, .L802400F0
/* 16E9C0 802400E0 3C020008 */   lui      $v0, 8
/* 16E9C4 802400E4 00621024 */  and       $v0, $v1, $v0
/* 16E9C8 802400E8 504000A5 */  beql      $v0, $zero, .L80240380
/* 16E9CC 802400EC 26F70001 */   addiu    $s7, $s7, 1
.L802400F0:
/* 16E9D0 802400F0 0C094F08 */  jal       is_actor_hp_bar_visible
/* 16E9D4 802400F4 0260202D */   daddu    $a0, $s3, $zero
/* 16E9D8 802400F8 504000A1 */  beql      $v0, $zero, .L80240380
/* 16E9DC 802400FC 26F70001 */   addiu    $s7, $s7, 1
/* 16E9E0 80240100 86620156 */  lh        $v0, 0x156($s3)
/* 16E9E4 80240104 8663015A */  lh        $v1, 0x15a($s3)
/* 16E9E8 80240108 44822000 */  mtc1      $v0, $f4
/* 16E9EC 8024010C 00000000 */  nop
/* 16E9F0 80240110 46802120 */  cvt.s.w   $f4, $f4
/* 16E9F4 80240114 86620158 */  lh        $v0, 0x158($s3)
/* 16E9F8 80240118 44831000 */  mtc1      $v1, $f2
/* 16E9FC 8024011C 00000000 */  nop
/* 16EA00 80240120 468010A0 */  cvt.s.w   $f2, $f2
/* 16EA04 80240124 44820000 */  mtc1      $v0, $f0
/* 16EA08 80240128 00000000 */  nop
/* 16EA0C 8024012C 46800020 */  cvt.s.w   $f0, $f0
/* 16EA10 80240130 2842FE0C */  slti      $v0, $v0, -0x1f4
/* 16EA14 80240134 54400092 */  bnel      $v0, $zero, .L80240380
/* 16EA18 80240138 26F70001 */   addiu    $s7, $s7, 1
/* 16EA1C 8024013C 24040001 */  addiu     $a0, $zero, 1
/* 16EA20 80240140 44052000 */  mfc1      $a1, $f4
/* 16EA24 80240144 44060000 */  mfc1      $a2, $f0
/* 16EA28 80240148 44071000 */  mfc1      $a3, $f2
/* 16EA2C 8024014C 27A20028 */  addiu     $v0, $sp, 0x28
/* 16EA30 80240150 AFB60010 */  sw        $s6, 0x10($sp)
/* 16EA34 80240154 AFB50014 */  sw        $s5, 0x14($sp)
/* 16EA38 80240158 0C00B94E */  jal       get_screen_coords
/* 16EA3C 8024015C AFA20018 */   sw       $v0, 0x18($sp)
/* 16EA40 80240160 2405000A */  addiu     $a1, $zero, 0xa
/* 16EA44 80240164 3C10802A */  lui       $s0, %hi(D_8029EFBC)
/* 16EA48 80240168 8E10EFBC */  lw        $s0, %lo(D_8029EFBC)($s0)
/* 16EA4C 8024016C 8FA20024 */  lw        $v0, 0x24($sp)
/* 16EA50 80240170 0200202D */  daddu     $a0, $s0, $zero
/* 16EA54 80240174 24420010 */  addiu     $v0, $v0, 0x10
/* 16EA58 80240178 0C051277 */  jal       set_hud_element_render_depth
/* 16EA5C 8024017C AFA20024 */   sw       $v0, 0x24($sp)
/* 16EA60 80240180 3C058029 */  lui       $a1, %hi(D_80291F80)
/* 16EA64 80240184 24A51F80 */  addiu     $a1, $a1, %lo(D_80291F80)
/* 16EA68 80240188 0C0511FF */  jal       set_hud_element_anim
/* 16EA6C 8024018C 0200202D */   daddu    $a0, $s0, $zero
/* 16EA70 80240190 8FA50020 */  lw        $a1, 0x20($sp)
/* 16EA74 80240194 8FA60024 */  lw        $a2, 0x24($sp)
/* 16EA78 80240198 0C051261 */  jal       set_hud_element_render_pos
/* 16EA7C 8024019C 0200202D */   daddu    $a0, $s0, $zero
/* 16EA80 802401A0 0C0511EA */  jal       draw_hud_element_clipped
/* 16EA84 802401A4 0200202D */   daddu    $a0, $s0, $zero
/* 16EA88 802401A8 3C026666 */  lui       $v0, 0x6666
/* 16EA8C 802401AC 34426667 */  ori       $v0, $v0, 0x6667
/* 16EA90 802401B0 02820018 */  mult      $s4, $v0
/* 16EA94 802401B4 001417C3 */  sra       $v0, $s4, 0x1f
/* 16EA98 802401B8 00004010 */  mfhi      $t0
/* 16EA9C 802401BC 00081883 */  sra       $v1, $t0, 2
/* 16EAA0 802401C0 00628823 */  subu      $s1, $v1, $v0
/* 16EAA4 802401C4 00119080 */  sll       $s2, $s1, 2
/* 16EAA8 802401C8 02511021 */  addu      $v0, $s2, $s1
/* 16EAAC 802401CC 00021040 */  sll       $v0, $v0, 1
/* 16EAB0 802401D0 1A200021 */  blez      $s1, .L80240258
/* 16EAB4 802401D4 0282A023 */   subu     $s4, $s4, $v0
/* 16EAB8 802401D8 3C10802A */  lui       $s0, %hi(D_8029EFBC)
/* 16EABC 802401DC 8E10EFBC */  lw        $s0, %lo(D_8029EFBC)($s0)
/* 16EAC0 802401E0 2405000A */  addiu     $a1, $zero, 0xa
/* 16EAC4 802401E4 0C051277 */  jal       set_hud_element_render_depth
/* 16EAC8 802401E8 0200202D */   daddu    $a0, $s0, $zero
/* 16EACC 802401EC 3C088028 */  lui       $t0, %hi(D_802809FC)
/* 16EAD0 802401F0 250809FC */  addiu     $t0, $t0, %lo(D_802809FC)
/* 16EAD4 802401F4 02481021 */  addu      $v0, $s2, $t0
/* 16EAD8 802401F8 8C450000 */  lw        $a1, ($v0)
/* 16EADC 802401FC 0C0511FF */  jal       set_hud_element_anim
/* 16EAE0 80240200 0200202D */   daddu    $a0, $s0, $zero
/* 16EAE4 80240204 0000202D */  daddu     $a0, $zero, $zero
/* 16EAE8 80240208 0080282D */  daddu     $a1, $a0, $zero
/* 16EAEC 8024020C 96C20002 */  lhu       $v0, 2($s6)
/* 16EAF0 80240210 0080302D */  daddu     $a2, $a0, $zero
/* 16EAF4 80240214 AFA20010 */  sw        $v0, 0x10($sp)
/* 16EAF8 80240218 96A20002 */  lhu       $v0, 2($s5)
/* 16EAFC 8024021C 0080382D */  daddu     $a3, $a0, $zero
/* 16EB00 80240220 AFBE0018 */  sw        $fp, 0x18($sp)
/* 16EB04 80240224 AFBE001C */  sw        $fp, 0x1c($sp)
/* 16EB08 80240228 24420002 */  addiu     $v0, $v0, 2
/* 16EB0C 8024022C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 16EB10 80240230 0C099E8F */  jal       btl_draw_prim_quad
/* 16EB14 80240234 AFA20014 */   sw       $v0, 0x14($sp)
/* 16EB18 80240238 0200202D */  daddu     $a0, $s0, $zero
/* 16EB1C 8024023C 8FA50020 */  lw        $a1, 0x20($sp)
/* 16EB20 80240240 8FA60024 */  lw        $a2, 0x24($sp)
/* 16EB24 80240244 24A50004 */  addiu     $a1, $a1, 4
/* 16EB28 80240248 0C051261 */  jal       set_hud_element_render_pos
/* 16EB2C 8024024C 24C60006 */   addiu    $a2, $a2, 6
/* 16EB30 80240250 0C0511F1 */  jal       draw_hud_element_2
/* 16EB34 80240254 0200202D */   daddu    $a0, $s0, $zero
.L80240258:
/* 16EB38 80240258 3C10802A */  lui       $s0, %hi(D_8029EFBC)
/* 16EB3C 8024025C 8E10EFBC */  lw        $s0, %lo(D_8029EFBC)($s0)
/* 16EB40 80240260 2405000A */  addiu     $a1, $zero, 0xa
/* 16EB44 80240264 0C051277 */  jal       set_hud_element_render_depth
/* 16EB48 80240268 0200202D */   daddu    $a0, $s0, $zero
/* 16EB4C 8024026C 00141080 */  sll       $v0, $s4, 2
/* 16EB50 80240270 3C088028 */  lui       $t0, %hi(D_802809FC)
/* 16EB54 80240274 250809FC */  addiu     $t0, $t0, %lo(D_802809FC)
/* 16EB58 80240278 00481021 */  addu      $v0, $v0, $t0
/* 16EB5C 8024027C 8C450000 */  lw        $a1, ($v0)
/* 16EB60 80240280 0C0511FF */  jal       set_hud_element_anim
/* 16EB64 80240284 0200202D */   daddu    $a0, $s0, $zero
/* 16EB68 80240288 0000202D */  daddu     $a0, $zero, $zero
/* 16EB6C 8024028C 0080282D */  daddu     $a1, $a0, $zero
/* 16EB70 80240290 96C20002 */  lhu       $v0, 2($s6)
/* 16EB74 80240294 0080302D */  daddu     $a2, $a0, $zero
/* 16EB78 80240298 24420006 */  addiu     $v0, $v0, 6
/* 16EB7C 8024029C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 16EB80 802402A0 AFA20010 */  sw        $v0, 0x10($sp)
/* 16EB84 802402A4 96A20002 */  lhu       $v0, 2($s5)
/* 16EB88 802402A8 0080382D */  daddu     $a3, $a0, $zero
/* 16EB8C 802402AC AFBE0018 */  sw        $fp, 0x18($sp)
/* 16EB90 802402B0 AFBE001C */  sw        $fp, 0x1c($sp)
/* 16EB94 802402B4 24420002 */  addiu     $v0, $v0, 2
/* 16EB98 802402B8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 16EB9C 802402BC 0C099E8F */  jal       btl_draw_prim_quad
/* 16EBA0 802402C0 AFA20014 */   sw       $v0, 0x14($sp)
/* 16EBA4 802402C4 0200202D */  daddu     $a0, $s0, $zero
/* 16EBA8 802402C8 8FA50020 */  lw        $a1, 0x20($sp)
/* 16EBAC 802402CC 8FA60024 */  lw        $a2, 0x24($sp)
/* 16EBB0 802402D0 24A5000A */  addiu     $a1, $a1, 0xa
/* 16EBB4 802402D4 0C051261 */  jal       set_hud_element_render_pos
/* 16EBB8 802402D8 24C60006 */   addiu    $a2, $a2, 6
/* 16EBBC 802402DC 0C0511F1 */  jal       draw_hud_element_2
/* 16EBC0 802402E0 0200202D */   daddu    $a0, $s0, $zero
/* 16EBC4 802402E4 240400A8 */  addiu     $a0, $zero, 0xa8
/* 16EBC8 802402E8 0000282D */  daddu     $a1, $zero, $zero
/* 16EBCC 802402EC 00A0302D */  daddu     $a2, $a1, $zero
/* 16EBD0 802402F0 240700FF */  addiu     $a3, $zero, 0xff
/* 16EBD4 802402F4 24030019 */  addiu     $v1, $zero, 0x19
/* 16EBD8 802402F8 827101BC */  lb        $s1, 0x1bc($s3)
/* 16EBDC 802402FC 96C20002 */  lhu       $v0, 2($s6)
/* 16EBE0 80240300 00718823 */  subu      $s1, $v1, $s1
/* 16EBE4 80240304 2442000B */  addiu     $v0, $v0, 0xb
/* 16EBE8 80240308 00511023 */  subu      $v0, $v0, $s1
/* 16EBEC 8024030C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 16EBF0 80240310 3230FFFF */  andi      $s0, $s1, 0xffff
/* 16EBF4 80240314 AFA20010 */  sw        $v0, 0x10($sp)
/* 16EBF8 80240318 96A30002 */  lhu       $v1, 2($s5)
/* 16EBFC 8024031C 24020001 */  addiu     $v0, $zero, 1
/* 16EC00 80240320 AFB00018 */  sw        $s0, 0x18($sp)
/* 16EC04 80240324 AFA2001C */  sw        $v0, 0x1c($sp)
/* 16EC08 80240328 2463FFF9 */  addiu     $v1, $v1, -7
/* 16EC0C 8024032C 3063FFFF */  andi      $v1, $v1, 0xffff
/* 16EC10 80240330 0C099E8F */  jal       btl_draw_prim_quad
/* 16EC14 80240334 AFA30014 */   sw       $v1, 0x14($sp)
/* 16EC18 80240338 240400FF */  addiu     $a0, $zero, 0xff
/* 16EC1C 8024033C 0000282D */  daddu     $a1, $zero, $zero
/* 16EC20 80240340 00A0302D */  daddu     $a2, $a1, $zero
/* 16EC24 80240344 96C20002 */  lhu       $v0, 2($s6)
/* 16EC28 80240348 0080382D */  daddu     $a3, $a0, $zero
/* 16EC2C 8024034C 2442000B */  addiu     $v0, $v0, 0xb
/* 16EC30 80240350 00511023 */  subu      $v0, $v0, $s1
/* 16EC34 80240354 3042FFFF */  andi      $v0, $v0, 0xffff
/* 16EC38 80240358 AFA20010 */  sw        $v0, 0x10($sp)
/* 16EC3C 8024035C 96A30002 */  lhu       $v1, 2($s5)
/* 16EC40 80240360 24020004 */  addiu     $v0, $zero, 4
/* 16EC44 80240364 AFB00018 */  sw        $s0, 0x18($sp)
/* 16EC48 80240368 AFA2001C */  sw        $v0, 0x1c($sp)
/* 16EC4C 8024036C 2463FFFA */  addiu     $v1, $v1, -6
/* 16EC50 80240370 3063FFFF */  andi      $v1, $v1, 0xffff
/* 16EC54 80240374 0C099E8F */  jal       btl_draw_prim_quad
/* 16EC58 80240378 AFA30014 */   sw       $v1, 0x14($sp)
/* 16EC5C 8024037C 26F70001 */  addiu     $s7, $s7, 1
.L80240380:
/* 16EC60 80240380 2AE20018 */  slti      $v0, $s7, 0x18
/* 16EC64 80240384 1440FF1F */  bnez      $v0, .L80240004
/* 16EC68 80240388 00171080 */   sll      $v0, $s7, 2
.L8024038C:
/* 16EC6C 8024038C 8FBF0054 */  lw        $ra, 0x54($sp)
/* 16EC70 80240390 8FBE0050 */  lw        $fp, 0x50($sp)
/* 16EC74 80240394 8FB7004C */  lw        $s7, 0x4c($sp)
/* 16EC78 80240398 8FB60048 */  lw        $s6, 0x48($sp)
/* 16EC7C 8024039C 8FB50044 */  lw        $s5, 0x44($sp)
/* 16EC80 802403A0 8FB40040 */  lw        $s4, 0x40($sp)
/* 16EC84 802403A4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 16EC88 802403A8 8FB20038 */  lw        $s2, 0x38($sp)
/* 16EC8C 802403AC 8FB10034 */  lw        $s1, 0x34($sp)
/* 16EC90 802403B0 8FB00030 */  lw        $s0, 0x30($sp)
/* 16EC94 802403B4 03E00008 */  jr        $ra
/* 16EC98 802403B8 27BD0058 */   addiu    $sp, $sp, 0x58

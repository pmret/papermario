.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029D550
.word L80260208_18EAE8, L80260300_18EBE0, L80260774_18F054, L80260774_18F054, L80260800_18F0E0, L80260838_18F118, L80260838_18F118, L80260838_18F118, L80260300_18EBE0, L80260300_18EBE0, L80260838_18F118, L80260838_18F118, L80260838_18F118, L80260838_18F118, L80260810_18F0F0, 0

.section .text

glabel btl_state_draw_celebration
/* 18EA9C 802601BC 3C02800E */  lui       $v0, %hi(gBattleStatus+0x46C)
/* 18EAA0 802601C0 8C42C4DC */  lw        $v0, %lo(gBattleStatus+0x46C)($v0)
/* 18EAA4 802601C4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 18EAA8 802601C8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 18EAAC 802601CC AFB50024 */  sw        $s5, 0x24($sp)
/* 18EAB0 802601D0 AFB40020 */  sw        $s4, 0x20($sp)
/* 18EAB4 802601D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 18EAB8 802601D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 18EABC 802601DC AFB10014 */  sw        $s1, 0x14($sp)
/* 18EAC0 802601E0 2443FFF9 */  addiu     $v1, $v0, -7
/* 18EAC4 802601E4 2C62000F */  sltiu     $v0, $v1, 0xf
/* 18EAC8 802601E8 10400193 */  beqz      $v0, L80260838_18F118
/* 18EACC 802601EC AFB00010 */   sw       $s0, 0x10($sp)
/* 18EAD0 802601F0 00031080 */  sll       $v0, $v1, 2
/* 18EAD4 802601F4 3C01802A */  lui       $at, %hi(jtbl_8029D550)
/* 18EAD8 802601F8 00220821 */  addu      $at, $at, $v0
/* 18EADC 802601FC 8C22D550 */  lw        $v0, %lo(jtbl_8029D550)($at)
/* 18EAE0 80260200 00400008 */  jr        $v0
/* 18EAE4 80260204 00000000 */   nop
glabel L80260208_18EAE8
/* 18EAE8 80260208 0C097FE3 */  jal       btl_draw_upgrade_windows
/* 18EAEC 8026020C 0000202D */   daddu    $a0, $zero, $zero
/* 18EAF0 80260210 24050080 */  addiu     $a1, $zero, 0x80
/* 18EAF4 80260214 00A0302D */  daddu     $a2, $a1, $zero
/* 18EAF8 80260218 00A0382D */  daddu     $a3, $a1, $zero
/* 18EAFC 8026021C 0000982D */  daddu     $s3, $zero, $zero
/* 18EB00 80260220 3C15802A */  lui       $s5, %hi(D_8029FA90)
/* 18EB04 80260224 26B5FA90 */  addiu     $s5, $s5, %lo(D_8029FA90)
/* 18EB08 80260228 3C10802A */  lui       $s0, %hi(D_8029FA80)
/* 18EB0C 8026022C 2610FA80 */  addiu     $s0, $s0, %lo(D_8029FA80)
/* 18EB10 80260230 8E110000 */  lw        $s1, ($s0)
/* 18EB14 80260234 0260A02D */  daddu     $s4, $s3, $zero
/* 18EB18 80260238 0C0513BF */  jal       set_hud_element_tint
/* 18EB1C 8026023C 0220202D */   daddu    $a0, $s1, $zero
/* 18EB20 80260240 0C0511EA */  jal       draw_hud_element_clipped
/* 18EB24 80260244 0220202D */   daddu    $a0, $s1, $zero
/* 18EB28 80260248 24050080 */  addiu     $a1, $zero, 0x80
/* 18EB2C 8026024C 00A0302D */  daddu     $a2, $a1, $zero
/* 18EB30 80260250 8E11000C */  lw        $s1, 0xc($s0)
/* 18EB34 80260254 00A0382D */  daddu     $a3, $a1, $zero
/* 18EB38 80260258 0C0513BF */  jal       set_hud_element_tint
/* 18EB3C 8026025C 0220202D */   daddu    $a0, $s1, $zero
/* 18EB40 80260260 0C0511EA */  jal       draw_hud_element_clipped
/* 18EB44 80260264 0220202D */   daddu    $a0, $s1, $zero
/* 18EB48 80260268 24050080 */  addiu     $a1, $zero, 0x80
/* 18EB4C 8026026C 00A0302D */  daddu     $a2, $a1, $zero
/* 18EB50 80260270 8E110004 */  lw        $s1, 4($s0)
/* 18EB54 80260274 00A0382D */  daddu     $a3, $a1, $zero
/* 18EB58 80260278 0C0513BF */  jal       set_hud_element_tint
/* 18EB5C 8026027C 0220202D */   daddu    $a0, $s1, $zero
/* 18EB60 80260280 0C0511EA */  jal       draw_hud_element_clipped
/* 18EB64 80260284 0220202D */   daddu    $a0, $s1, $zero
/* 18EB68 80260288 24050080 */  addiu     $a1, $zero, 0x80
/* 18EB6C 8026028C 00A0302D */  daddu     $a2, $a1, $zero
/* 18EB70 80260290 8E110008 */  lw        $s1, 8($s0)
/* 18EB74 80260294 00A0382D */  daddu     $a3, $a1, $zero
/* 18EB78 80260298 0C0513BF */  jal       set_hud_element_tint
/* 18EB7C 8026029C 0220202D */   daddu    $a0, $s1, $zero
/* 18EB80 802602A0 0C0511EA */  jal       draw_hud_element_clipped
/* 18EB84 802602A4 0220202D */   daddu    $a0, $s1, $zero
.L802602A8:
/* 18EB88 802602A8 0000902D */  daddu     $s2, $zero, $zero
/* 18EB8C 802602AC 0280802D */  daddu     $s0, $s4, $zero
/* 18EB90 802602B0 02151021 */  addu      $v0, $s0, $s5
.L802602B4:
/* 18EB94 802602B4 8C510000 */  lw        $s1, ($v0)
/* 18EB98 802602B8 24050080 */  addiu     $a1, $zero, 0x80
/* 18EB9C 802602BC 00A0302D */  daddu     $a2, $a1, $zero
/* 18EBA0 802602C0 00A0382D */  daddu     $a3, $a1, $zero
/* 18EBA4 802602C4 26100004 */  addiu     $s0, $s0, 4
/* 18EBA8 802602C8 26520001 */  addiu     $s2, $s2, 1
/* 18EBAC 802602CC 0C0513BF */  jal       set_hud_element_tint
/* 18EBB0 802602D0 0220202D */   daddu    $a0, $s1, $zero
/* 18EBB4 802602D4 0C0511EA */  jal       draw_hud_element_clipped
/* 18EBB8 802602D8 0220202D */   daddu    $a0, $s1, $zero
/* 18EBBC 802602DC 2A420007 */  slti      $v0, $s2, 7
/* 18EBC0 802602E0 1440FFF4 */  bnez      $v0, .L802602B4
/* 18EBC4 802602E4 02151021 */   addu     $v0, $s0, $s5
/* 18EBC8 802602E8 26730001 */  addiu     $s3, $s3, 1
/* 18EBCC 802602EC 2A620003 */  slti      $v0, $s3, 3
/* 18EBD0 802602F0 1440FFED */  bnez      $v0, .L802602A8
/* 18EBD4 802602F4 2694001C */   addiu    $s4, $s4, 0x1c
/* 18EBD8 802602F8 0809820E */  j         L80260838_18F118
/* 18EBDC 802602FC 00000000 */   nop
glabel L80260300_18EBE0
/* 18EBE0 80260300 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 18EBE4 80260304 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 18EBE8 80260308 80430048 */  lb        $v1, 0x48($v0)
/* 18EBEC 8026030C 24020001 */  addiu     $v0, $zero, 1
/* 18EBF0 80260310 1062006B */  beq       $v1, $v0, .L802604C0
/* 18EBF4 80260314 28620002 */   slti     $v0, $v1, 2
/* 18EBF8 80260318 104000A9 */  beqz      $v0, .L802605C0
/* 18EBFC 8026031C 241500D0 */   addiu    $s5, $zero, 0xd0
/* 18EC00 80260320 146000A8 */  bnez      $v1, .L802605C4
/* 18EC04 80260324 24050080 */   addiu    $a1, $zero, 0x80
/* 18EC08 80260328 24150098 */  addiu     $s5, $zero, 0x98
/* 18EC0C 8026032C 240500FF */  addiu     $a1, $zero, 0xff
/* 18EC10 80260330 00A0302D */  daddu     $a2, $a1, $zero
/* 18EC14 80260334 00A0382D */  daddu     $a3, $a1, $zero
/* 18EC18 80260338 3C10802A */  lui       $s0, %hi(D_8029FA80)
/* 18EC1C 8026033C 2610FA80 */  addiu     $s0, $s0, %lo(D_8029FA80)
/* 18EC20 80260340 8E040000 */  lw        $a0, ($s0)
/* 18EC24 80260344 3C11802A */  lui       $s1, %hi(D_8029FA90)
/* 18EC28 80260348 2631FA90 */  addiu     $s1, $s1, %lo(D_8029FA90)
/* 18EC2C 8026034C 0C0513BF */  jal       set_hud_element_tint
/* 18EC30 80260350 0000902D */   daddu    $s2, $zero, $zero
/* 18EC34 80260354 24050080 */  addiu     $a1, $zero, 0x80
/* 18EC38 80260358 00A0302D */  daddu     $a2, $a1, $zero
/* 18EC3C 8026035C 8E04000C */  lw        $a0, 0xc($s0)
/* 18EC40 80260360 0C0513BF */  jal       set_hud_element_tint
/* 18EC44 80260364 00A0382D */   daddu    $a3, $a1, $zero
/* 18EC48 80260368 24050080 */  addiu     $a1, $zero, 0x80
/* 18EC4C 8026036C 00A0302D */  daddu     $a2, $a1, $zero
/* 18EC50 80260370 8E040004 */  lw        $a0, 4($s0)
/* 18EC54 80260374 0C0513BF */  jal       set_hud_element_tint
/* 18EC58 80260378 00A0382D */   daddu    $a3, $a1, $zero
/* 18EC5C 8026037C 24050080 */  addiu     $a1, $zero, 0x80
/* 18EC60 80260380 00A0302D */  daddu     $a2, $a1, $zero
/* 18EC64 80260384 8E040008 */  lw        $a0, 8($s0)
/* 18EC68 80260388 0C0513BF */  jal       set_hud_element_tint
/* 18EC6C 8026038C 00A0382D */   daddu    $a3, $a1, $zero
.L80260390:
/* 18EC70 80260390 8E240000 */  lw        $a0, ($s1)
/* 18EC74 80260394 24050080 */  addiu     $a1, $zero, 0x80
/* 18EC78 80260398 00A0302D */  daddu     $a2, $a1, $zero
/* 18EC7C 8026039C 00A0382D */  daddu     $a3, $a1, $zero
/* 18EC80 802603A0 26310004 */  addiu     $s1, $s1, 4
/* 18EC84 802603A4 0C0513BF */  jal       set_hud_element_tint
/* 18EC88 802603A8 26520001 */   addiu    $s2, $s2, 1
/* 18EC8C 802603AC 2A420007 */  slti      $v0, $s2, 7
/* 18EC90 802603B0 1440FFF7 */  bnez      $v0, .L80260390
/* 18EC94 802603B4 00000000 */   nop
/* 18EC98 802603B8 0000902D */  daddu     $s2, $zero, $zero
/* 18EC9C 802603BC 3C10802A */  lui       $s0, %hi(D_8029FA90)
/* 18ECA0 802603C0 2610FA90 */  addiu     $s0, $s0, %lo(D_8029FA90)
.L802603C4:
/* 18ECA4 802603C4 8E04001C */  lw        $a0, 0x1c($s0)
/* 18ECA8 802603C8 240500FF */  addiu     $a1, $zero, 0xff
/* 18ECAC 802603CC 00A0302D */  daddu     $a2, $a1, $zero
/* 18ECB0 802603D0 00A0382D */  daddu     $a3, $a1, $zero
/* 18ECB4 802603D4 26100004 */  addiu     $s0, $s0, 4
/* 18ECB8 802603D8 0C0513BF */  jal       set_hud_element_tint
/* 18ECBC 802603DC 26520001 */   addiu    $s2, $s2, 1
/* 18ECC0 802603E0 2A420007 */  slti      $v0, $s2, 7
/* 18ECC4 802603E4 1440FFF7 */  bnez      $v0, .L802603C4
/* 18ECC8 802603E8 00000000 */   nop
/* 18ECCC 802603EC 0000902D */  daddu     $s2, $zero, $zero
/* 18ECD0 802603F0 3C10802A */  lui       $s0, %hi(D_8029FA90)
/* 18ECD4 802603F4 2610FA90 */  addiu     $s0, $s0, %lo(D_8029FA90)
.L802603F8:
/* 18ECD8 802603F8 8E040038 */  lw        $a0, 0x38($s0)
/* 18ECDC 802603FC 24050080 */  addiu     $a1, $zero, 0x80
/* 18ECE0 80260400 00A0302D */  daddu     $a2, $a1, $zero
/* 18ECE4 80260404 00A0382D */  daddu     $a3, $a1, $zero
/* 18ECE8 80260408 26100004 */  addiu     $s0, $s0, 4
/* 18ECEC 8026040C 0C0513BF */  jal       set_hud_element_tint
/* 18ECF0 80260410 26520001 */   addiu    $s2, $s2, 1
/* 18ECF4 80260414 2A420007 */  slti      $v0, $s2, 7
/* 18ECF8 80260418 1440FFF7 */  bnez      $v0, .L802603F8
/* 18ECFC 8026041C 00000000 */   nop
/* 18ED00 80260420 3C10802A */  lui       $s0, %hi(D_8029FA80)
/* 18ED04 80260424 2610FA80 */  addiu     $s0, $s0, %lo(D_8029FA80)
/* 18ED08 80260428 8E110000 */  lw        $s1, ($s0)
/* 18ED0C 8026042C 0C05122C */  jal       get_hud_element_script
/* 18ED10 80260430 0220202D */   daddu    $a0, $s1, $zero
/* 18ED14 80260434 3C05802B */  lui       $a1, %hi(D_802A9F34)
/* 18ED18 80260438 24A59F34 */  addiu     $a1, $a1, %lo(D_802A9F34)
/* 18ED1C 8026043C 10450003 */  beq       $v0, $a1, .L8026044C
/* 18ED20 80260440 00000000 */   nop
/* 18ED24 80260444 0C0511FF */  jal       set_hud_element_script
/* 18ED28 80260448 0220202D */   daddu    $a0, $s1, $zero
.L8026044C:
/* 18ED2C 8026044C 8E11000C */  lw        $s1, 0xc($s0)
/* 18ED30 80260450 0C05122C */  jal       get_hud_element_script
/* 18ED34 80260454 0220202D */   daddu    $a0, $s1, $zero
/* 18ED38 80260458 3C05802B */  lui       $a1, %hi(D_802A9F84)
/* 18ED3C 8026045C 24A59F84 */  addiu     $a1, $a1, %lo(D_802A9F84)
/* 18ED40 80260460 10450003 */  beq       $v0, $a1, .L80260470
/* 18ED44 80260464 00000000 */   nop
/* 18ED48 80260468 0C0511FF */  jal       set_hud_element_script
/* 18ED4C 8026046C 0220202D */   daddu    $a0, $s1, $zero
.L80260470:
/* 18ED50 80260470 8E110004 */  lw        $s1, 4($s0)
/* 18ED54 80260474 0C05122C */  jal       get_hud_element_script
/* 18ED58 80260478 0220202D */   daddu    $a0, $s1, $zero
/* 18ED5C 8026047C 3C05802B */  lui       $a1, %hi(D_802A9F5C)
/* 18ED60 80260480 24A59F5C */  addiu     $a1, $a1, %lo(D_802A9F5C)
/* 18ED64 80260484 10450003 */  beq       $v0, $a1, .L80260494
/* 18ED68 80260488 00000000 */   nop
/* 18ED6C 8026048C 0C0511FF */  jal       set_hud_element_script
/* 18ED70 80260490 0220202D */   daddu    $a0, $s1, $zero
.L80260494:
/* 18ED74 80260494 8E110008 */  lw        $s1, 8($s0)
/* 18ED78 80260498 0C05122C */  jal       get_hud_element_script
/* 18ED7C 8026049C 0220202D */   daddu    $a0, $s1, $zero
/* 18ED80 802604A0 3C05802B */  lui       $a1, %hi(D_802A9FAC)
/* 18ED84 802604A4 24A59FAC */  addiu     $a1, $a1, %lo(D_802A9FAC)
/* 18ED88 802604A8 10450082 */  beq       $v0, $a1, .L802606B4
/* 18ED8C 802604AC 00000000 */   nop
/* 18ED90 802604B0 0C0511FF */  jal       set_hud_element_script
/* 18ED94 802604B4 0220202D */   daddu    $a0, $s1, $zero
/* 18ED98 802604B8 080981AD */  j         .L802606B4
/* 18ED9C 802604BC 00000000 */   nop
.L802604C0:
/* 18EDA0 802604C0 241500B4 */  addiu     $s5, $zero, 0xb4
/* 18EDA4 802604C4 24050080 */  addiu     $a1, $zero, 0x80
/* 18EDA8 802604C8 00A0302D */  daddu     $a2, $a1, $zero
/* 18EDAC 802604CC 00A0382D */  daddu     $a3, $a1, $zero
/* 18EDB0 802604D0 3C10802A */  lui       $s0, %hi(D_8029FA80)
/* 18EDB4 802604D4 2610FA80 */  addiu     $s0, $s0, %lo(D_8029FA80)
/* 18EDB8 802604D8 8E040000 */  lw        $a0, ($s0)
/* 18EDBC 802604DC 3C11802A */  lui       $s1, %hi(D_8029FA90)
/* 18EDC0 802604E0 2631FA90 */  addiu     $s1, $s1, %lo(D_8029FA90)
/* 18EDC4 802604E4 0C0513BF */  jal       set_hud_element_tint
/* 18EDC8 802604E8 0000902D */   daddu    $s2, $zero, $zero
/* 18EDCC 802604EC 240500FF */  addiu     $a1, $zero, 0xff
/* 18EDD0 802604F0 00A0302D */  daddu     $a2, $a1, $zero
/* 18EDD4 802604F4 8E04000C */  lw        $a0, 0xc($s0)
/* 18EDD8 802604F8 0C0513BF */  jal       set_hud_element_tint
/* 18EDDC 802604FC 00A0382D */   daddu    $a3, $a1, $zero
/* 18EDE0 80260500 240500FF */  addiu     $a1, $zero, 0xff
/* 18EDE4 80260504 00A0302D */  daddu     $a2, $a1, $zero
/* 18EDE8 80260508 8E040004 */  lw        $a0, 4($s0)
/* 18EDEC 8026050C 0C0513BF */  jal       set_hud_element_tint
/* 18EDF0 80260510 00A0382D */   daddu    $a3, $a1, $zero
/* 18EDF4 80260514 24050080 */  addiu     $a1, $zero, 0x80
/* 18EDF8 80260518 00A0302D */  daddu     $a2, $a1, $zero
/* 18EDFC 8026051C 8E040008 */  lw        $a0, 8($s0)
/* 18EE00 80260520 0C0513BF */  jal       set_hud_element_tint
/* 18EE04 80260524 00A0382D */   daddu    $a3, $a1, $zero
.L80260528:
/* 18EE08 80260528 8E240000 */  lw        $a0, ($s1)
/* 18EE0C 8026052C 240500FF */  addiu     $a1, $zero, 0xff
/* 18EE10 80260530 00A0302D */  daddu     $a2, $a1, $zero
/* 18EE14 80260534 00A0382D */  daddu     $a3, $a1, $zero
/* 18EE18 80260538 26310004 */  addiu     $s1, $s1, 4
/* 18EE1C 8026053C 0C0513BF */  jal       set_hud_element_tint
/* 18EE20 80260540 26520001 */   addiu    $s2, $s2, 1
/* 18EE24 80260544 2A420007 */  slti      $v0, $s2, 7
/* 18EE28 80260548 1440FFF7 */  bnez      $v0, .L80260528
/* 18EE2C 8026054C 00000000 */   nop
/* 18EE30 80260550 0000902D */  daddu     $s2, $zero, $zero
/* 18EE34 80260554 3C10802A */  lui       $s0, %hi(D_8029FA90)
/* 18EE38 80260558 2610FA90 */  addiu     $s0, $s0, %lo(D_8029FA90)
.L8026055C:
/* 18EE3C 8026055C 8E04001C */  lw        $a0, 0x1c($s0)
/* 18EE40 80260560 24050080 */  addiu     $a1, $zero, 0x80
/* 18EE44 80260564 00A0302D */  daddu     $a2, $a1, $zero
/* 18EE48 80260568 00A0382D */  daddu     $a3, $a1, $zero
/* 18EE4C 8026056C 26100004 */  addiu     $s0, $s0, 4
/* 18EE50 80260570 0C0513BF */  jal       set_hud_element_tint
/* 18EE54 80260574 26520001 */   addiu    $s2, $s2, 1
/* 18EE58 80260578 2A420007 */  slti      $v0, $s2, 7
/* 18EE5C 8026057C 1440FFF7 */  bnez      $v0, .L8026055C
/* 18EE60 80260580 00000000 */   nop
/* 18EE64 80260584 0000902D */  daddu     $s2, $zero, $zero
/* 18EE68 80260588 3C10802A */  lui       $s0, %hi(D_8029FA90)
/* 18EE6C 8026058C 2610FA90 */  addiu     $s0, $s0, %lo(D_8029FA90)
.L80260590:
/* 18EE70 80260590 8E040038 */  lw        $a0, 0x38($s0)
/* 18EE74 80260594 24050080 */  addiu     $a1, $zero, 0x80
/* 18EE78 80260598 00A0302D */  daddu     $a2, $a1, $zero
/* 18EE7C 8026059C 00A0382D */  daddu     $a3, $a1, $zero
/* 18EE80 802605A0 26100004 */  addiu     $s0, $s0, 4
/* 18EE84 802605A4 0C0513BF */  jal       set_hud_element_tint
/* 18EE88 802605A8 26520001 */   addiu    $s2, $s2, 1
/* 18EE8C 802605AC 2A420007 */  slti      $v0, $s2, 7
/* 18EE90 802605B0 10400040 */  beqz      $v0, .L802606B4
/* 18EE94 802605B4 00000000 */   nop
/* 18EE98 802605B8 08098164 */  j         .L80260590
/* 18EE9C 802605BC 00000000 */   nop
.L802605C0:
/* 18EEA0 802605C0 24050080 */  addiu     $a1, $zero, 0x80
.L802605C4:
/* 18EEA4 802605C4 00A0302D */  daddu     $a2, $a1, $zero
/* 18EEA8 802605C8 00A0382D */  daddu     $a3, $a1, $zero
/* 18EEAC 802605CC 3C10802A */  lui       $s0, %hi(D_8029FA80)
/* 18EEB0 802605D0 2610FA80 */  addiu     $s0, $s0, %lo(D_8029FA80)
/* 18EEB4 802605D4 8E040000 */  lw        $a0, ($s0)
/* 18EEB8 802605D8 3C11802A */  lui       $s1, %hi(D_8029FA90)
/* 18EEBC 802605DC 2631FA90 */  addiu     $s1, $s1, %lo(D_8029FA90)
/* 18EEC0 802605E0 0C0513BF */  jal       set_hud_element_tint
/* 18EEC4 802605E4 0000902D */   daddu    $s2, $zero, $zero
/* 18EEC8 802605E8 24050080 */  addiu     $a1, $zero, 0x80
/* 18EECC 802605EC 00A0302D */  daddu     $a2, $a1, $zero
/* 18EED0 802605F0 8E04000C */  lw        $a0, 0xc($s0)
/* 18EED4 802605F4 0C0513BF */  jal       set_hud_element_tint
/* 18EED8 802605F8 00A0382D */   daddu    $a3, $a1, $zero
/* 18EEDC 802605FC 24050080 */  addiu     $a1, $zero, 0x80
/* 18EEE0 80260600 00A0302D */  daddu     $a2, $a1, $zero
/* 18EEE4 80260604 8E040004 */  lw        $a0, 4($s0)
/* 18EEE8 80260608 0C0513BF */  jal       set_hud_element_tint
/* 18EEEC 8026060C 00A0382D */   daddu    $a3, $a1, $zero
/* 18EEF0 80260610 240500FF */  addiu     $a1, $zero, 0xff
/* 18EEF4 80260614 00A0302D */  daddu     $a2, $a1, $zero
/* 18EEF8 80260618 8E040008 */  lw        $a0, 8($s0)
/* 18EEFC 8026061C 0C0513BF */  jal       set_hud_element_tint
/* 18EF00 80260620 00A0382D */   daddu    $a3, $a1, $zero
.L80260624:
/* 18EF04 80260624 8E240000 */  lw        $a0, ($s1)
/* 18EF08 80260628 24050080 */  addiu     $a1, $zero, 0x80
/* 18EF0C 8026062C 00A0302D */  daddu     $a2, $a1, $zero
/* 18EF10 80260630 00A0382D */  daddu     $a3, $a1, $zero
/* 18EF14 80260634 26310004 */  addiu     $s1, $s1, 4
/* 18EF18 80260638 0C0513BF */  jal       set_hud_element_tint
/* 18EF1C 8026063C 26520001 */   addiu    $s2, $s2, 1
/* 18EF20 80260640 2A420007 */  slti      $v0, $s2, 7
/* 18EF24 80260644 1440FFF7 */  bnez      $v0, .L80260624
/* 18EF28 80260648 00000000 */   nop
/* 18EF2C 8026064C 0000902D */  daddu     $s2, $zero, $zero
/* 18EF30 80260650 3C10802A */  lui       $s0, %hi(D_8029FA90)
/* 18EF34 80260654 2610FA90 */  addiu     $s0, $s0, %lo(D_8029FA90)
.L80260658:
/* 18EF38 80260658 8E04001C */  lw        $a0, 0x1c($s0)
/* 18EF3C 8026065C 24050080 */  addiu     $a1, $zero, 0x80
/* 18EF40 80260660 00A0302D */  daddu     $a2, $a1, $zero
/* 18EF44 80260664 00A0382D */  daddu     $a3, $a1, $zero
/* 18EF48 80260668 26100004 */  addiu     $s0, $s0, 4
/* 18EF4C 8026066C 0C0513BF */  jal       set_hud_element_tint
/* 18EF50 80260670 26520001 */   addiu    $s2, $s2, 1
/* 18EF54 80260674 2A420007 */  slti      $v0, $s2, 7
/* 18EF58 80260678 1440FFF7 */  bnez      $v0, .L80260658
/* 18EF5C 8026067C 00000000 */   nop
/* 18EF60 80260680 0000902D */  daddu     $s2, $zero, $zero
/* 18EF64 80260684 3C10802A */  lui       $s0, %hi(D_8029FA90)
/* 18EF68 80260688 2610FA90 */  addiu     $s0, $s0, %lo(D_8029FA90)
.L8026068C:
/* 18EF6C 8026068C 8E040038 */  lw        $a0, 0x38($s0)
/* 18EF70 80260690 240500FF */  addiu     $a1, $zero, 0xff
/* 18EF74 80260694 00A0302D */  daddu     $a2, $a1, $zero
/* 18EF78 80260698 00A0382D */  daddu     $a3, $a1, $zero
/* 18EF7C 8026069C 26100004 */  addiu     $s0, $s0, 4
/* 18EF80 802606A0 0C0513BF */  jal       set_hud_element_tint
/* 18EF84 802606A4 26520001 */   addiu    $s2, $s2, 1
/* 18EF88 802606A8 2A420007 */  slti      $v0, $s2, 7
/* 18EF8C 802606AC 1440FFF7 */  bnez      $v0, .L8026068C
/* 18EF90 802606B0 00000000 */   nop
.L802606B4:
/* 18EF94 802606B4 0C097FE3 */  jal       btl_draw_upgrade_windows
/* 18EF98 802606B8 24040001 */   addiu    $a0, $zero, 1
/* 18EF9C 802606BC 3C10802A */  lui       $s0, %hi(D_8029FA80)
/* 18EFA0 802606C0 2610FA80 */  addiu     $s0, $s0, %lo(D_8029FA80)
/* 18EFA4 802606C4 8E040000 */  lw        $a0, ($s0)
/* 18EFA8 802606C8 0C0511EA */  jal       draw_hud_element_clipped
/* 18EFAC 802606CC 0000982D */   daddu    $s3, $zero, $zero
/* 18EFB0 802606D0 8E04000C */  lw        $a0, 0xc($s0)
/* 18EFB4 802606D4 0C0511EA */  jal       draw_hud_element_clipped
/* 18EFB8 802606D8 0260882D */   daddu    $s1, $s3, $zero
/* 18EFBC 802606DC 8E040004 */  lw        $a0, 4($s0)
/* 18EFC0 802606E0 3C14802A */  lui       $s4, %hi(D_8029FA90)
/* 18EFC4 802606E4 2694FA90 */  addiu     $s4, $s4, %lo(D_8029FA90)
/* 18EFC8 802606E8 0C0511EA */  jal       draw_hud_element_clipped
/* 18EFCC 802606EC 00000000 */   nop
/* 18EFD0 802606F0 0C0511EA */  jal       draw_hud_element_clipped
/* 18EFD4 802606F4 8E040008 */   lw       $a0, 8($s0)
.L802606F8:
/* 18EFD8 802606F8 0000902D */  daddu     $s2, $zero, $zero
/* 18EFDC 802606FC 0220802D */  daddu     $s0, $s1, $zero
/* 18EFE0 80260700 02141021 */  addu      $v0, $s0, $s4
.L80260704:
/* 18EFE4 80260704 8C440000 */  lw        $a0, ($v0)
/* 18EFE8 80260708 26100004 */  addiu     $s0, $s0, 4
/* 18EFEC 8026070C 0C0511EA */  jal       draw_hud_element_clipped
/* 18EFF0 80260710 26520001 */   addiu    $s2, $s2, 1
/* 18EFF4 80260714 2A420007 */  slti      $v0, $s2, 7
/* 18EFF8 80260718 1440FFFA */  bnez      $v0, .L80260704
/* 18EFFC 8026071C 02141021 */   addu     $v0, $s0, $s4
/* 18F000 80260720 26730001 */  addiu     $s3, $s3, 1
/* 18F004 80260724 2A620003 */  slti      $v0, $s3, 3
/* 18F008 80260728 1440FFF3 */  bnez      $v0, .L802606F8
/* 18F00C 8026072C 2631001C */   addiu    $s1, $s1, 0x1c
/* 18F010 80260730 0C051086 */  jal       func_80144218
/* 18F014 80260734 2404FFFF */   addiu    $a0, $zero, -1
/* 18F018 80260738 44951000 */  mtc1      $s5, $f2
/* 18F01C 8026073C 00000000 */  nop
/* 18F020 80260740 468010A0 */  cvt.s.w   $f2, $f2
/* 18F024 80260744 44071000 */  mfc1      $a3, $f2
/* 18F028 80260748 44800000 */  mtc1      $zero, $f0
/* 18F02C 8026074C 3C11802A */  lui       $s1, %hi(D_8029FAE8)
/* 18F030 80260750 8E31FAE8 */  lw        $s1, %lo(D_8029FAE8)($s1)
/* 18F034 80260754 44050000 */  mfc1      $a1, $f0
/* 18F038 80260758 0220202D */  daddu     $a0, $s1, $zero
/* 18F03C 8026075C 0C051489 */  jal       set_hud_element_transform_rotation
/* 18F040 80260760 00A0302D */   daddu    $a2, $a1, $zero
/* 18F044 80260764 0C05108E */  jal       func_80144238
/* 18F048 80260768 0220202D */   daddu    $a0, $s1, $zero
/* 18F04C 8026076C 0809820E */  j         L80260838_18F118
/* 18F050 80260770 00000000 */   nop
glabel L80260774_18F054
/* 18F054 80260774 0C097FE3 */  jal       btl_draw_upgrade_windows
/* 18F058 80260778 24040001 */   addiu    $a0, $zero, 1
/* 18F05C 8026077C 3C10802A */  lui       $s0, %hi(D_8029FA80)
/* 18F060 80260780 2610FA80 */  addiu     $s0, $s0, %lo(D_8029FA80)
/* 18F064 80260784 8E040000 */  lw        $a0, ($s0)
/* 18F068 80260788 0C0511EA */  jal       draw_hud_element_clipped
/* 18F06C 8026078C 0000982D */   daddu    $s3, $zero, $zero
/* 18F070 80260790 8E04000C */  lw        $a0, 0xc($s0)
/* 18F074 80260794 0C0511EA */  jal       draw_hud_element_clipped
/* 18F078 80260798 0260882D */   daddu    $s1, $s3, $zero
/* 18F07C 8026079C 8E040004 */  lw        $a0, 4($s0)
/* 18F080 802607A0 3C14802A */  lui       $s4, %hi(D_8029FA90)
/* 18F084 802607A4 2694FA90 */  addiu     $s4, $s4, %lo(D_8029FA90)
/* 18F088 802607A8 0C0511EA */  jal       draw_hud_element_clipped
/* 18F08C 802607AC 00000000 */   nop
/* 18F090 802607B0 0C0511EA */  jal       draw_hud_element_clipped
/* 18F094 802607B4 8E040008 */   lw       $a0, 8($s0)
.L802607B8:
/* 18F098 802607B8 0000902D */  daddu     $s2, $zero, $zero
/* 18F09C 802607BC 0220802D */  daddu     $s0, $s1, $zero
/* 18F0A0 802607C0 02141021 */  addu      $v0, $s0, $s4
.L802607C4:
/* 18F0A4 802607C4 8C440000 */  lw        $a0, ($v0)
/* 18F0A8 802607C8 26100004 */  addiu     $s0, $s0, 4
/* 18F0AC 802607CC 0C0511EA */  jal       draw_hud_element_clipped
/* 18F0B0 802607D0 26520001 */   addiu    $s2, $s2, 1
/* 18F0B4 802607D4 2A420007 */  slti      $v0, $s2, 7
/* 18F0B8 802607D8 1440FFFA */  bnez      $v0, .L802607C4
/* 18F0BC 802607DC 02141021 */   addu     $v0, $s0, $s4
/* 18F0C0 802607E0 26730001 */  addiu     $s3, $s3, 1
/* 18F0C4 802607E4 2A620003 */  slti      $v0, $s3, 3
/* 18F0C8 802607E8 1440FFF3 */  bnez      $v0, .L802607B8
/* 18F0CC 802607EC 2631001C */   addiu    $s1, $s1, 0x1c
/* 18F0D0 802607F0 3C018028 */  lui       $at, %hi(D_80284150)
/* 18F0D4 802607F4 C4224150 */  lwc1      $f2, %lo(D_80284150)($at)
/* 18F0D8 802607F8 0809820B */  j         .L8026082C
/* 18F0DC 802607FC 468010A0 */   cvt.s.w  $f2, $f2
glabel L80260800_18F0E0
/* 18F0E0 80260800 3C018028 */  lui       $at, %hi(D_80284150)
/* 18F0E4 80260804 C4224150 */  lwc1      $f2, %lo(D_80284150)($at)
/* 18F0E8 80260808 0809820B */  j         .L8026082C
/* 18F0EC 8026080C 468010A0 */   cvt.s.w  $f2, $f2
glabel L80260810_18F0F0
/* 18F0F0 80260810 3C058028 */  lui       $a1, %hi(D_80284150)
/* 18F0F4 80260814 8CA54150 */  lw        $a1, %lo(D_80284150)($a1)
/* 18F0F8 80260818 10A00007 */  beqz      $a1, L80260838_18F118
/* 18F0FC 8026081C 00000000 */   nop
/* 18F100 80260820 44851000 */  mtc1      $a1, $f2
/* 18F104 80260824 00000000 */  nop
/* 18F108 80260828 468010A0 */  cvt.s.w   $f2, $f2
.L8026082C:
/* 18F10C 8026082C 44051000 */  mfc1      $a1, $f2
/* 18F110 80260830 0C04DF62 */  jal       set_screen_overlay_params_front
/* 18F114 80260834 0000202D */   daddu    $a0, $zero, $zero
glabel L80260838_18F118
/* 18F118 80260838 3C03800E */  lui       $v1, %hi(gBattleStatus+0x46C)
/* 18F11C 8026083C 8C63C4DC */  lw        $v1, %lo(gBattleStatus+0x46C)($v1)
/* 18F120 80260840 28620007 */  slti      $v0, $v1, 7
/* 18F124 80260844 14400037 */  bnez      $v0, .L80260924
/* 18F128 80260848 2862000A */   slti     $v0, $v1, 0xa
/* 18F12C 8026084C 14400005 */  bnez      $v0, .L80260864
/* 18F130 80260850 2402000A */   addiu    $v0, $zero, 0xa
/* 18F134 80260854 1062001B */  beq       $v1, $v0, .L802608C4
/* 18F138 80260858 00000000 */   nop
/* 18F13C 8026085C 08098249 */  j         .L80260924
/* 18F140 80260860 00000000 */   nop
.L80260864:
/* 18F144 80260864 3C06802A */  lui       $a2, %hi(D_8029FB8C)
/* 18F148 80260868 24C6FB8C */  addiu     $a2, $a2, %lo(D_8029FB8C)
/* 18F14C 8026086C 3C05802A */  lui       $a1, %hi(D_8029FB88)
/* 18F150 80260870 24A5FB88 */  addiu     $a1, $a1, %lo(D_8029FB88)
/* 18F154 80260874 8CC30000 */  lw        $v1, ($a2)
/* 18F158 80260878 8CA20000 */  lw        $v0, ($a1)
/* 18F15C 8026087C 24640002 */  addiu     $a0, $v1, 2
/* 18F160 80260880 00441021 */  addu      $v0, $v0, $a0
/* 18F164 80260884 ACC40000 */  sw        $a0, ($a2)
/* 18F168 80260888 ACA20000 */  sw        $v0, ($a1)
/* 18F16C 8026088C 284200C9 */  slti      $v0, $v0, 0xc9
/* 18F170 80260890 5440001C */  bnel      $v0, $zero, .L80260904
/* 18F174 80260894 240600B0 */   addiu    $a2, $zero, 0xb0
/* 18F178 80260898 3C035555 */  lui       $v1, 0x5555
/* 18F17C 8026089C 34635556 */  ori       $v1, $v1, 0x5556
/* 18F180 802608A0 00041023 */  negu      $v0, $a0
/* 18F184 802608A4 00430018 */  mult      $v0, $v1
/* 18F188 802608A8 240300C8 */  addiu     $v1, $zero, 0xc8
/* 18F18C 802608AC 000217C3 */  sra       $v0, $v0, 0x1f
/* 18F190 802608B0 ACA30000 */  sw        $v1, ($a1)
/* 18F194 802608B4 00004010 */  mfhi      $t0
/* 18F198 802608B8 01021023 */  subu      $v0, $t0, $v0
/* 18F19C 802608BC 08098240 */  j         .L80260900
/* 18F1A0 802608C0 ACC20000 */   sw       $v0, ($a2)
.L802608C4:
/* 18F1A4 802608C4 3C02802A */  lui       $v0, %hi(D_8029FB8C)
/* 18F1A8 802608C8 2442FB8C */  addiu     $v0, $v0, %lo(D_8029FB8C)
/* 18F1AC 802608CC 3C05802A */  lui       $a1, %hi(D_8029FB88)
/* 18F1B0 802608D0 24A5FB88 */  addiu     $a1, $a1, %lo(D_8029FB88)
/* 18F1B4 802608D4 8C430000 */  lw        $v1, ($v0)
/* 18F1B8 802608D8 8CA40000 */  lw        $a0, ($a1)
/* 18F1BC 802608DC 24630004 */  addiu     $v1, $v1, 4
/* 18F1C0 802608E0 00832021 */  addu      $a0, $a0, $v1
/* 18F1C4 802608E4 AC430000 */  sw        $v1, ($v0)
/* 18F1C8 802608E8 ACA40000 */  sw        $a0, ($a1)
/* 18F1CC 802608EC 288401F5 */  slti      $a0, $a0, 0x1f5
/* 18F1D0 802608F0 14800004 */  bnez      $a0, .L80260904
/* 18F1D4 802608F4 240600B0 */   addiu    $a2, $zero, 0xb0
/* 18F1D8 802608F8 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 18F1DC 802608FC ACA20000 */  sw        $v0, ($a1)
.L80260900:
/* 18F1E0 80260900 240600B0 */  addiu     $a2, $zero, 0xb0
.L80260904:
/* 18F1E4 80260904 3C11802A */  lui       $s1, %hi(D_8029FB48)
/* 18F1E8 80260908 8E31FB48 */  lw        $s1, %lo(D_8029FB48)($s1)
/* 18F1EC 8026090C 8CA50000 */  lw        $a1, ($a1)
/* 18F1F0 80260910 0220202D */  daddu     $a0, $s1, $zero
/* 18F1F4 80260914 0C051261 */  jal       set_hud_element_render_pos
/* 18F1F8 80260918 24A5FFD5 */   addiu    $a1, $a1, -0x2b
/* 18F1FC 8026091C 0C0511EA */  jal       draw_hud_element_clipped
/* 18F200 80260920 0220202D */   daddu    $a0, $s1, $zero
.L80260924:
/* 18F204 80260924 8FBF0028 */  lw        $ra, 0x28($sp)
/* 18F208 80260928 8FB50024 */  lw        $s5, 0x24($sp)
/* 18F20C 8026092C 8FB40020 */  lw        $s4, 0x20($sp)
/* 18F210 80260930 8FB3001C */  lw        $s3, 0x1c($sp)
/* 18F214 80260934 8FB20018 */  lw        $s2, 0x18($sp)
/* 18F218 80260938 8FB10014 */  lw        $s1, 0x14($sp)
/* 18F21C 8026093C 8FB00010 */  lw        $s0, 0x10($sp)
/* 18F220 80260940 03E00008 */  jr        $ra
/* 18F224 80260944 27BD0030 */   addiu    $sp, $sp, 0x30

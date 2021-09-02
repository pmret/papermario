.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_draw_movelist
/* 13F078 8024BD38 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 13F07C 8024BD3C AFBE0048 */  sw        $fp, 0x48($sp)
/* 13F080 8024BD40 00C0F02D */  daddu     $fp, $a2, $zero
/* 13F084 8024BD44 AFBF004C */  sw        $ra, 0x4c($sp)
/* 13F088 8024BD48 AFB70044 */  sw        $s7, 0x44($sp)
/* 13F08C 8024BD4C AFB60040 */  sw        $s6, 0x40($sp)
/* 13F090 8024BD50 AFB5003C */  sw        $s5, 0x3c($sp)
/* 13F094 8024BD54 AFB40038 */  sw        $s4, 0x38($sp)
/* 13F098 8024BD58 AFB30034 */  sw        $s3, 0x34($sp)
/* 13F09C 8024BD5C AFB20030 */  sw        $s2, 0x30($sp)
/* 13F0A0 8024BD60 AFB1002C */  sw        $s1, 0x2c($sp)
/* 13F0A4 8024BD64 AFB00028 */  sw        $s0, 0x28($sp)
/* 13F0A8 8024BD68 0C039D59 */  jal       get_player_data
/* 13F0AC 8024BD6C AFA50054 */   sw       $a1, 0x54($sp)
/* 13F0B0 8024BD70 3C038027 */  lui       $v1, %hi(D_802706A0)
/* 13F0B4 8024BD74 8C6306A0 */  lw        $v1, %lo(D_802706A0)($v1)
/* 13F0B8 8024BD78 00031880 */  sll       $v1, $v1, 2
/* 13F0BC 8024BD7C 3C018027 */  lui       $at, %hi(D_80270680)
/* 13F0C0 8024BD80 00230821 */  addu      $at, $at, $v1
/* 13F0C4 8024BD84 8C230680 */  lw        $v1, %lo(D_80270680)($at)
/* 13F0C8 8024BD88 00031880 */  sll       $v1, $v1, 2
/* 13F0CC 8024BD8C 3C018025 */  lui       $at, %hi(D_8024F6B0)
/* 13F0D0 8024BD90 00230821 */  addu      $at, $at, $v1
/* 13F0D4 8024BD94 8C23F6B0 */  lw        $v1, %lo(D_8024F6B0)($at)
/* 13F0D8 8024BD98 000318C0 */  sll       $v1, $v1, 3
/* 13F0DC 8024BD9C 00431021 */  addu      $v0, $v0, $v1
/* 13F0E0 8024BDA0 80550015 */  lb        $s5, 0x15($v0)
/* 13F0E4 8024BDA4 24020002 */  addiu     $v0, $zero, 2
/* 13F0E8 8024BDA8 16A20003 */  bne       $s5, $v0, .L8024BDB8
/* 13F0EC 8024BDAC 24020001 */   addiu    $v0, $zero, 1
/* 13F0F0 8024BDB0 08092F74 */  j         .L8024BDD0
/* 13F0F4 8024BDB4 24150004 */   addiu    $s5, $zero, 4
.L8024BDB8:
/* 13F0F8 8024BDB8 16A20003 */  bne       $s5, $v0, .L8024BDC8
/* 13F0FC 8024BDBC 00000000 */   nop
/* 13F100 8024BDC0 08092F74 */  j         .L8024BDD0
/* 13F104 8024BDC4 24150003 */   addiu    $s5, $zero, 3
.L8024BDC8:
/* 13F108 8024BDC8 52A00001 */  beql      $s5, $zero, .L8024BDD0
/* 13F10C 8024BDCC 24150002 */   addiu    $s5, $zero, 2
.L8024BDD0:
/* 13F110 8024BDD0 0000902D */  daddu     $s2, $zero, $zero
/* 13F114 8024BDD4 2417001D */  addiu     $s7, $zero, 0x1d
/* 13F118 8024BDD8 24140016 */  addiu     $s4, $zero, 0x16
/* 13F11C 8024BDDC 2416001C */  addiu     $s6, $zero, 0x1c
/* 13F120 8024BDE0 8FA80054 */  lw        $t0, 0x54($sp)
/* 13F124 8024BDE4 24130002 */  addiu     $s3, $zero, 2
/* 13F128 8024BDE8 25080015 */  addiu     $t0, $t0, 0x15
/* 13F12C 8024BDEC AFA80020 */  sw        $t0, 0x20($sp)
.L8024BDF0:
/* 13F130 8024BDF0 0255102A */  slt       $v0, $s2, $s5
/* 13F134 8024BDF4 1040006D */  beqz      $v0, .L8024BFAC
/* 13F138 8024BDF8 03D43021 */   addu     $a2, $fp, $s4
/* 13F13C 8024BDFC 16400011 */  bnez      $s2, .L8024BE44
/* 13F140 8024BE00 00000000 */   nop
/* 13F144 8024BE04 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13F148 8024BE08 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13F14C 8024BE0C 3C088027 */  lui       $t0, %hi(D_80270680)
/* 13F150 8024BE10 25080680 */  addiu     $t0, $t0, %lo(D_80270680)
/* 13F154 8024BE14 00021080 */  sll       $v0, $v0, 2
/* 13F158 8024BE18 00481021 */  addu      $v0, $v0, $t0
/* 13F15C 8024BE1C 8C420000 */  lw        $v0, ($v0)
/* 13F160 8024BE20 3C088025 */  lui       $t0, %hi(D_8024F6F0)
/* 13F164 8024BE24 2508F6F0 */  addiu     $t0, $t0, %lo(D_8024F6F0)
/* 13F168 8024BE28 00021080 */  sll       $v0, $v0, 2
/* 13F16C 8024BE2C 00481021 */  addu      $v0, $v0, $t0
/* 13F170 8024BE30 8C430000 */  lw        $v1, ($v0)
/* 13F174 8024BE34 3C088009 */  lui       $t0, %hi(D_8008F060)
/* 13F178 8024BE38 2508F060 */  addiu     $t0, $t0, %lo(D_8008F060)
/* 13F17C 8024BE3C 08092FA1 */  j         .L8024BE84
/* 13F180 8024BE40 00031080 */   sll      $v0, $v1, 2
.L8024BE44:
/* 13F184 8024BE44 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13F188 8024BE48 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13F18C 8024BE4C 3C088027 */  lui       $t0, %hi(D_80270680)
/* 13F190 8024BE50 25080680 */  addiu     $t0, $t0, %lo(D_80270680)
/* 13F194 8024BE54 00021080 */  sll       $v0, $v0, 2
/* 13F198 8024BE58 00481021 */  addu      $v0, $v0, $t0
/* 13F19C 8024BE5C 8C420000 */  lw        $v0, ($v0)
/* 13F1A0 8024BE60 3C088025 */  lui       $t0, %hi(D_8024F6F0)
/* 13F1A4 8024BE64 2508F6F0 */  addiu     $t0, $t0, %lo(D_8024F6F0)
/* 13F1A8 8024BE68 00021080 */  sll       $v0, $v0, 2
/* 13F1AC 8024BE6C 00481021 */  addu      $v0, $v0, $t0
/* 13F1B0 8024BE70 8C430000 */  lw        $v1, ($v0)
/* 13F1B4 8024BE74 3C088009 */  lui       $t0, %hi(D_8008F060)
/* 13F1B8 8024BE78 2508F060 */  addiu     $t0, $t0, %lo(D_8008F060)
/* 13F1BC 8024BE7C 00731821 */  addu      $v1, $v1, $s3
/* 13F1C0 8024BE80 00031080 */  sll       $v0, $v1, 2
.L8024BE84:
/* 13F1C4 8024BE84 00431021 */  addu      $v0, $v0, $v1
/* 13F1C8 8024BE88 00021080 */  sll       $v0, $v0, 2
/* 13F1CC 8024BE8C 00481021 */  addu      $v0, $v0, $t0
/* 13F1D0 8024BE90 8C440000 */  lw        $a0, ($v0)
/* 13F1D4 8024BE94 1A400016 */  blez      $s2, .L8024BEF0
/* 13F1D8 8024BE98 240700FF */   addiu    $a3, $zero, 0xff
/* 13F1DC 8024BE9C 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13F1E0 8024BEA0 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13F1E4 8024BEA4 3C088027 */  lui       $t0, %hi(D_80270680)
/* 13F1E8 8024BEA8 25080680 */  addiu     $t0, $t0, %lo(D_80270680)
/* 13F1EC 8024BEAC 00021080 */  sll       $v0, $v0, 2
/* 13F1F0 8024BEB0 00481021 */  addu      $v0, $v0, $t0
/* 13F1F4 8024BEB4 8C420000 */  lw        $v0, ($v0)
/* 13F1F8 8024BEB8 3C088025 */  lui       $t0, %hi(D_8024F6F0)
/* 13F1FC 8024BEBC 2508F6F0 */  addiu     $t0, $t0, %lo(D_8024F6F0)
/* 13F200 8024BEC0 00021080 */  sll       $v0, $v0, 2
/* 13F204 8024BEC4 00481021 */  addu      $v0, $v0, $t0
/* 13F208 8024BEC8 8C430000 */  lw        $v1, ($v0)
/* 13F20C 8024BECC 3C088009 */  lui       $t0, %hi(D_8008F060)
/* 13F210 8024BED0 2508F060 */  addiu     $t0, $t0, %lo(D_8008F060)
/* 13F214 8024BED4 00731821 */  addu      $v1, $v1, $s3
/* 13F218 8024BED8 00031080 */  sll       $v0, $v1, 2
/* 13F21C 8024BEDC 00431021 */  addu      $v0, $v0, $v1
/* 13F220 8024BEE0 00021080 */  sll       $v0, $v0, 2
/* 13F224 8024BEE4 00481021 */  addu      $v0, $v0, $t0
/* 13F228 8024BEE8 08092FBD */  j         .L8024BEF4
/* 13F22C 8024BEEC 80510011 */   lb       $s1, 0x11($v0)
.L8024BEF0:
/* 13F230 8024BEF0 0000882D */  daddu     $s1, $zero, $zero
.L8024BEF4:
/* 13F234 8024BEF4 8FA50020 */  lw        $a1, 0x20($sp)
/* 13F238 8024BEF8 2408000A */  addiu     $t0, $zero, 0xa
/* 13F23C 8024BEFC AFA80010 */  sw        $t0, 0x10($sp)
/* 13F240 8024BF00 24080001 */  addiu     $t0, $zero, 1
/* 13F244 8024BF04 0C04993B */  jal       draw_msg
/* 13F248 8024BF08 AFA80014 */   sw       $t0, 0x14($sp)
/* 13F24C 8024BF0C 26500004 */  addiu     $s0, $s2, 4
/* 13F250 8024BF10 00108080 */  sll       $s0, $s0, 2
/* 13F254 8024BF14 3C088027 */  lui       $t0, %hi(D_80270640)
/* 13F258 8024BF18 25080640 */  addiu     $t0, $t0, %lo(D_80270640)
/* 13F25C 8024BF1C 02088021 */  addu      $s0, $s0, $t0
/* 13F260 8024BF20 8E040000 */  lw        $a0, ($s0)
/* 13F264 8024BF24 0C051308 */  jal       set_hud_element_scale
/* 13F268 8024BF28 3C053F00 */   lui      $a1, 0x3f00
/* 13F26C 8024BF2C 03D63021 */  addu      $a2, $fp, $s6
/* 13F270 8024BF30 8FA80054 */  lw        $t0, 0x54($sp)
/* 13F274 8024BF34 8E040000 */  lw        $a0, ($s0)
/* 13F278 8024BF38 0C051261 */  jal       set_hud_element_render_pos
/* 13F27C 8024BF3C 2505000C */   addiu    $a1, $t0, 0xc
/* 13F280 8024BF40 8E040000 */  lw        $a0, ($s0)
/* 13F284 8024BF44 0C0511F8 */  jal       draw_hud_element_3
/* 13F288 8024BF48 00000000 */   nop
/* 13F28C 8024BF4C 12200017 */  beqz      $s1, .L8024BFAC
/* 13F290 8024BF50 0220202D */   daddu    $a0, $s1, $zero
/* 13F294 8024BF54 03D43021 */  addu      $a2, $fp, $s4
/* 13F298 8024BF58 24070001 */  addiu     $a3, $zero, 1
/* 13F29C 8024BF5C 8FA80054 */  lw        $t0, 0x54($sp)
/* 13F2A0 8024BF60 240200FF */  addiu     $v0, $zero, 0xff
/* 13F2A4 8024BF64 AFA20014 */  sw        $v0, 0x14($sp)
/* 13F2A8 8024BF68 24020003 */  addiu     $v0, $zero, 3
/* 13F2AC 8024BF6C AFA20018 */  sw        $v0, 0x18($sp)
/* 13F2B0 8024BF70 2505007D */  addiu     $a1, $t0, 0x7d
/* 13F2B4 8024BF74 2408000A */  addiu     $t0, $zero, 0xa
/* 13F2B8 8024BF78 0C049DA7 */  jal       draw_number
/* 13F2BC 8024BF7C AFA80010 */   sw       $t0, 0x10($sp)
/* 13F2C0 8024BF80 1A20000A */  blez      $s1, .L8024BFAC
/* 13F2C4 8024BF84 03D73021 */   addu     $a2, $fp, $s7
/* 13F2C8 8024BF88 8FA80054 */  lw        $t0, 0x54($sp)
/* 13F2CC 8024BF8C 3C048027 */  lui       $a0, %hi(D_80270640)
/* 13F2D0 8024BF90 8C840640 */  lw        $a0, %lo(D_80270640)($a0)
/* 13F2D4 8024BF94 0C051261 */  jal       set_hud_element_render_pos
/* 13F2D8 8024BF98 25050086 */   addiu    $a1, $t0, 0x86
/* 13F2DC 8024BF9C 3C048027 */  lui       $a0, %hi(D_80270640)
/* 13F2E0 8024BFA0 8C840640 */  lw        $a0, %lo(D_80270640)($a0)
/* 13F2E4 8024BFA4 0C0511F8 */  jal       draw_hud_element_3
/* 13F2E8 8024BFA8 00000000 */   nop
.L8024BFAC:
/* 13F2EC 8024BFAC 26F7000D */  addiu     $s7, $s7, 0xd
/* 13F2F0 8024BFB0 2694000D */  addiu     $s4, $s4, 0xd
/* 13F2F4 8024BFB4 26D6000D */  addiu     $s6, $s6, 0xd
/* 13F2F8 8024BFB8 26520001 */  addiu     $s2, $s2, 1
/* 13F2FC 8024BFBC 2A420004 */  slti      $v0, $s2, 4
/* 13F300 8024BFC0 1440FF8B */  bnez      $v0, .L8024BDF0
/* 13F304 8024BFC4 26730001 */   addiu    $s3, $s3, 1
/* 13F308 8024BFC8 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 13F30C 8024BFCC 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 13F310 8024BFD0 24020004 */  addiu     $v0, $zero, 4
/* 13F314 8024BFD4 14620010 */  bne       $v1, $v0, .L8024C018
/* 13F318 8024BFD8 24020001 */   addiu    $v0, $zero, 1
/* 13F31C 8024BFDC 3C038027 */  lui       $v1, %hi(D_802706AC)
/* 13F320 8024BFE0 8C6306AC */  lw        $v1, %lo(D_802706AC)($v1)
/* 13F324 8024BFE4 1462000C */  bne       $v1, $v0, .L8024C018
/* 13F328 8024BFE8 24040024 */   addiu    $a0, $zero, 0x24
/* 13F32C 8024BFEC 8FA80054 */  lw        $t0, 0x54($sp)
/* 13F330 8024BFF0 3C028027 */  lui       $v0, %hi(D_802706A4)
/* 13F334 8024BFF4 8C4206A4 */  lw        $v0, %lo(D_802706A4)($v0)
/* 13F338 8024BFF8 2505FFFE */  addiu     $a1, $t0, -2
/* 13F33C 8024BFFC 00023040 */  sll       $a2, $v0, 1
/* 13F340 8024C000 00C23021 */  addu      $a2, $a2, $v0
/* 13F344 8024C004 00063080 */  sll       $a2, $a2, 2
/* 13F348 8024C008 00C23021 */  addu      $a2, $a2, $v0
/* 13F34C 8024C00C 24C6001C */  addiu     $a2, $a2, 0x1c
/* 13F350 8024C010 0C090B41 */  jal       func_80242D04
/* 13F354 8024C014 03C63021 */   addu     $a2, $fp, $a2
.L8024C018:
/* 13F358 8024C018 8FBF004C */  lw        $ra, 0x4c($sp)
/* 13F35C 8024C01C 8FBE0048 */  lw        $fp, 0x48($sp)
/* 13F360 8024C020 8FB70044 */  lw        $s7, 0x44($sp)
/* 13F364 8024C024 8FB60040 */  lw        $s6, 0x40($sp)
/* 13F368 8024C028 8FB5003C */  lw        $s5, 0x3c($sp)
/* 13F36C 8024C02C 8FB40038 */  lw        $s4, 0x38($sp)
/* 13F370 8024C030 8FB30034 */  lw        $s3, 0x34($sp)
/* 13F374 8024C034 8FB20030 */  lw        $s2, 0x30($sp)
/* 13F378 8024C038 8FB1002C */  lw        $s1, 0x2c($sp)
/* 13F37C 8024C03C 8FB00028 */  lw        $s0, 0x28($sp)
/* 13F380 8024C040 03E00008 */  jr        $ra
/* 13F384 8024C044 27BD0050 */   addiu    $sp, $sp, 0x50

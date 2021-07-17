.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_init
/* 1373A0 80244060 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1373A4 80244064 3C040013 */  lui       $a0, 0x13
/* 1373A8 80244068 24841340 */  addiu     $a0, $a0, 0x1340
/* 1373AC 8024406C 3C050013 */  lui       $a1, 0x13
/* 1373B0 80244070 24A55EE0 */  addiu     $a1, $a1, 0x5ee0
/* 1373B4 80244074 3C068024 */  lui       $a2, %hi(get_dpad_input_radial)
/* 1373B8 80244078 24C6E000 */  addiu     $a2, $a2, %lo(get_dpad_input_radial)
/* 1373BC 8024407C AFBF0028 */  sw        $ra, 0x28($sp)
/* 1373C0 80244080 AFB50024 */  sw        $s5, 0x24($sp)
/* 1373C4 80244084 AFB40020 */  sw        $s4, 0x20($sp)
/* 1373C8 80244088 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1373CC 8024408C AFB20018 */  sw        $s2, 0x18($sp)
/* 1373D0 80244090 AFB10014 */  sw        $s1, 0x14($sp)
/* 1373D4 80244094 0C00A5CF */  jal       dma_copy
/* 1373D8 80244098 AFB00010 */   sw       $s0, 0x10($sp)
/* 1373DC 8024409C 0000882D */  daddu     $s1, $zero, $zero
/* 1373E0 802440A0 3C138024 */  lui       $s3, %hi(D_80241ECC)
/* 1373E4 802440A4 26731ECC */  addiu     $s3, $s3, %lo(D_80241ECC)
/* 1373E8 802440A8 3C108025 */  lui       $s0, %hi(gPauseMenuIconScripts)
/* 1373EC 802440AC 2610EF60 */  addiu     $s0, $s0, %lo(gPauseMenuIconScripts)
/* 1373F0 802440B0 3C128027 */  lui       $s2, %hi(gPauseMenuCommonIconIDs)
/* 1373F4 802440B4 265200E8 */  addiu     $s2, $s2, %lo(gPauseMenuCommonIconIDs)
.L802440B8:
/* 1373F8 802440B8 0C050529 */  jal       create_hud_element
/* 1373FC 802440BC 8E040000 */   lw       $a0, ($s0)
/* 137400 802440C0 0040202D */  daddu     $a0, $v0, $zero
/* 137404 802440C4 AE440000 */  sw        $a0, ($s2)
/* 137408 802440C8 8E020000 */  lw        $v0, ($s0)
/* 13740C 802440CC 54530003 */  bnel      $v0, $s3, .L802440DC
/* 137410 802440D0 24050080 */   addiu    $a1, $zero, 0x80
/* 137414 802440D4 3C052000 */  lui       $a1, 0x2000
/* 137418 802440D8 34A50080 */  ori       $a1, $a1, 0x80
.L802440DC:
/* 13741C 802440DC 0C051280 */  jal       set_hud_element_flags
/* 137420 802440E0 26100004 */   addiu    $s0, $s0, 4
/* 137424 802440E4 26310001 */  addiu     $s1, $s1, 1
/* 137428 802440E8 2A220008 */  slti      $v0, $s1, 8
/* 13742C 802440EC 1440FFF2 */  bnez      $v0, .L802440B8
/* 137430 802440F0 26520004 */   addiu    $s2, $s2, 4
/* 137434 802440F4 3C048025 */  lui       $a0, %hi(D_8024F114)
/* 137438 802440F8 2484F114 */  addiu     $a0, $a0, %lo(D_8024F114)
/* 13743C 802440FC 24050004 */  addiu     $a1, $zero, 4
/* 137440 80244100 3C108025 */  lui       $s0, %hi(gPauseMenuTabs)
/* 137444 80244104 2610EF80 */  addiu     $s0, $s0, %lo(gPauseMenuTabs)
/* 137448 80244108 3C028027 */  lui       $v0, %hi(gPauseMenuCommonIconIDs)
/* 13744C 8024410C 8C4200E8 */  lw        $v0, %lo(gPauseMenuCommonIconIDs)($v0)
/* 137450 80244110 3C018027 */  lui       $at, %hi(D_802700D0)
/* 137454 80244114 AC2200D0 */  sw        $v0, %lo(D_802700D0)($at)
/* 137458 80244118 0C051FCC */  jal       setup_pause_menu_tab
/* 13745C 8024411C 0000882D */   daddu    $s1, $zero, $zero
/* 137460 80244120 3C018027 */  lui       $at, %hi(D_80270108)
/* 137464 80244124 AC200108 */  sw        $zero, %lo(D_80270108)($at)
/* 137468 80244128 3C018027 */  lui       $at, %hi(D_80270110)
/* 13746C 8024412C AC200110 */  sw        $zero, %lo(D_80270110)($at)
/* 137470 80244130 3C018027 */  lui       $at, %hi(D_80270114)
/* 137474 80244134 AC200114 */  sw        $zero, %lo(D_80270114)($at)
/* 137478 80244138 3C018027 */  lui       $at, %hi(D_8027010C)
/* 13747C 8024413C AC20010C */  sw        $zero, %lo(D_8027010C)($at)
/* 137480 80244140 3C018027 */  lui       $at, %hi(D_80270118)
/* 137484 80244144 AC200118 */  sw        $zero, %lo(D_80270118)($at)
/* 137488 80244148 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13748C 8024414C AC2000C8 */  sw        $zero, %lo(gPauseMenuCurrentDescString)($at)
/* 137490 80244150 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 137494 80244154 AC2000CC */  sw        $zero, %lo(gPauseMenuCurrentDescIconScript)($at)
/* 137498 80244158 3C018027 */  lui       $at, %hi(gPauseMenuCurrentTab)
/* 13749C 8024415C A02000D4 */  sb        $zero, %lo(gPauseMenuCurrentTab)($at)
.L80244160:
/* 1374A0 80244160 8E040000 */  lw        $a0, ($s0)
/* 1374A4 80244164 8C82000C */  lw        $v0, 0xc($a0)
/* 1374A8 80244168 10400003 */  beqz      $v0, .L80244178
/* 1374AC 8024416C 26310001 */   addiu    $s1, $s1, 1
/* 1374B0 80244170 0040F809 */  jalr      $v0
/* 1374B4 80244174 00000000 */   nop
.L80244178:
/* 1374B8 80244178 2A220007 */  slti      $v0, $s1, 7
/* 1374BC 8024417C 1440FFF8 */  bnez      $v0, .L80244160
/* 1374C0 80244180 26100004 */   addiu    $s0, $s0, 4
/* 1374C4 80244184 241400E1 */  addiu     $s4, $zero, 0xe1
/* 1374C8 80244188 24110006 */  addiu     $s1, $zero, 6
/* 1374CC 8024418C 3C158016 */  lui       $s5, %hi(gUIPanels)
/* 1374D0 80244190 26B59D50 */  addiu     $s5, $s5, %lo(gUIPanels)
/* 1374D4 80244194 241303C0 */  addiu     $s3, $zero, 0x3c0
/* 1374D8 80244198 2412001E */  addiu     $s2, $zero, 0x1e
/* 1374DC 8024419C 3C108025 */  lui       $s0, %hi(D_8024EF98)
/* 1374E0 802441A0 2610EF98 */  addiu     $s0, $s0, %lo(D_8024EF98)
.L802441A4:
/* 1374E4 802441A4 8E020000 */  lw        $v0, ($s0)
/* 1374E8 802441A8 90420000 */  lbu       $v0, ($v0)
/* 1374EC 802441AC 14400006 */  bnez      $v0, .L802441C8
/* 1374F0 802441B0 02751821 */   addu     $v1, $s3, $s5
/* 1374F4 802441B4 0240202D */  daddu     $a0, $s2, $zero
/* 1374F8 802441B8 0C051F9F */  jal       set_window_update
/* 1374FC 802441BC 24050002 */   addiu    $a1, $zero, 2
/* 137500 802441C0 08091076 */  j         .L802441D8
/* 137504 802441C4 2673FFE0 */   addiu    $s3, $s3, -0x20
.L802441C8:
/* 137508 802441C8 2682000E */  addiu     $v0, $s4, 0xe
/* 13750C 802441CC A462000C */  sh        $v0, 0xc($v1)
/* 137510 802441D0 2694FFD3 */  addiu     $s4, $s4, -0x2d
/* 137514 802441D4 2673FFE0 */  addiu     $s3, $s3, -0x20
.L802441D8:
/* 137518 802441D8 2652FFFF */  addiu     $s2, $s2, -1
/* 13751C 802441DC 2631FFFF */  addiu     $s1, $s1, -1
/* 137520 802441E0 1E20FFF0 */  bgtz      $s1, .L802441A4
/* 137524 802441E4 2610FFFC */   addiu    $s0, $s0, -4
/* 137528 802441E8 3C028025 */  lui       $v0, %hi(gPauseMenuTabs)
/* 13752C 802441EC 8C42EF80 */  lw        $v0, %lo(gPauseMenuTabs)($v0)
/* 137530 802441F0 0000202D */  daddu     $a0, $zero, $zero
/* 137534 802441F4 80420001 */  lb        $v0, 1($v0)
/* 137538 802441F8 3C05F840 */  lui       $a1, 0xf840
/* 13753C 802441FC 00021140 */  sll       $v0, $v0, 5
/* 137540 80244200 3C018016 */  lui       $at, %hi(D_8015A07C)
/* 137544 80244204 00220821 */  addu      $at, $at, $v0
/* 137548 80244208 8422A07C */  lh        $v0, %lo(D_8015A07C)($at)
/* 13754C 8024420C 24420006 */  addiu     $v0, $v0, 6
/* 137550 80244210 3C018016 */  lui       $at, %hi(D_8015A2BC)
/* 137554 80244214 A422A2BC */  sh        $v0, %lo(D_8015A2BC)($at)
/* 137558 80244218 0C0B1EAF */  jal       get_variable
/* 13755C 8024421C 34A55BDE */   ori      $a1, $a1, 0x5bde
/* 137560 80244220 10400013 */  beqz      $v0, .L80244270
/* 137564 80244224 0000882D */   daddu    $s1, $zero, $zero
/* 137568 80244228 3C128027 */  lui       $s2, %hi(D_8027011C)
/* 13756C 8024422C 2652011C */  addiu     $s2, $s2, %lo(D_8027011C)
/* 137570 80244230 3C108025 */  lui       $s0, %hi(D_8024F0CC)
/* 137574 80244234 2610F0CC */  addiu     $s0, $s0, %lo(D_8024F0CC)
.L80244238:
/* 137578 80244238 0200282D */  daddu     $a1, $s0, $zero
/* 13757C 8024423C 8E040000 */  lw        $a0, ($s0)
/* 137580 80244240 26100010 */  addiu     $s0, $s0, 0x10
/* 137584 80244244 0C0B783B */  jal       spr_load_npc_sprite
/* 137588 80244248 26310001 */   addiu    $s1, $s1, 1
/* 13758C 8024424C AE420000 */  sw        $v0, ($s2)
/* 137590 80244250 2A220003 */  slti      $v0, $s1, 3
/* 137594 80244254 1440FFF8 */  bnez      $v0, .L80244238
/* 137598 80244258 26520004 */   addiu    $s2, $s2, 4
/* 13759C 8024425C 24040018 */  addiu     $a0, $zero, 0x18
/* 1375A0 80244260 0C051F9F */  jal       set_window_update
/* 1375A4 80244264 24050001 */   addiu    $a1, $zero, 1
/* 1375A8 80244268 0C05272D */  jal       sfx_play_sound
/* 1375AC 8024426C 24040009 */   addiu    $a0, $zero, 9
.L80244270:
/* 1375B0 80244270 2404002C */  addiu     $a0, $zero, 0x2c
/* 1375B4 80244274 0C051F5C */  jal       update_window_hierarchy
/* 1375B8 80244278 24050040 */   addiu    $a1, $zero, 0x40
/* 1375BC 8024427C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 1375C0 80244280 8FB50024 */  lw        $s5, 0x24($sp)
/* 1375C4 80244284 8FB40020 */  lw        $s4, 0x20($sp)
/* 1375C8 80244288 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1375CC 8024428C 8FB20018 */  lw        $s2, 0x18($sp)
/* 1375D0 80244290 8FB10014 */  lw        $s1, 0x14($sp)
/* 1375D4 80244294 8FB00010 */  lw        $s0, 0x10($sp)
/* 1375D8 80244298 03E00008 */  jr        $ra
/* 1375DC 8024429C 27BD0030 */   addiu    $sp, $sp, 0x30

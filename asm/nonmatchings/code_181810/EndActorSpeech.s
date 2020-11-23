.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EndActorSpeech
/* 181BB0 802532D0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 181BB4 802532D4 AFB20038 */  sw        $s2, 0x38($sp)
/* 181BB8 802532D8 0080902D */  daddu     $s2, $a0, $zero
/* 181BBC 802532DC AFBF0040 */  sw        $ra, 0x40($sp)
/* 181BC0 802532E0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 181BC4 802532E4 AFB10034 */  sw        $s1, 0x34($sp)
/* 181BC8 802532E8 AFB00030 */  sw        $s0, 0x30($sp)
/* 181BCC 802532EC 10A00029 */  beqz      $a1, .L80253394
/* 181BD0 802532F0 8E50000C */   lw       $s0, 0xc($s2)
/* 181BD4 802532F4 8E050000 */  lw        $a1, ($s0)
/* 181BD8 802532F8 0C0B1EAF */  jal       get_variable
/* 181BDC 802532FC 26100004 */   addiu    $s0, $s0, 4
/* 181BE0 80253300 0040882D */  daddu     $s1, $v0, $zero
/* 181BE4 80253304 8E050000 */  lw        $a1, ($s0)
/* 181BE8 80253308 26100004 */  addiu     $s0, $s0, 4
/* 181BEC 8025330C 0C0B1EAF */  jal       get_variable
/* 181BF0 80253310 0240202D */   daddu    $a0, $s2, $zero
/* 181BF4 80253314 8E050000 */  lw        $a1, ($s0)
/* 181BF8 80253318 26100004 */  addiu     $s0, $s0, 4
/* 181BFC 8025331C 0240202D */  daddu     $a0, $s2, $zero
/* 181C00 80253320 0C0B1EAF */  jal       get_variable
/* 181C04 80253324 0040982D */   daddu    $s3, $v0, $zero
/* 181C08 80253328 3C01802A */  lui       $at, %hi(gSpeakingActorTalkAnim)
/* 181C0C 8025332C AC22FA6C */  sw        $v0, %lo(gSpeakingActorTalkAnim)($at)
/* 181C10 80253330 8E050000 */  lw        $a1, ($s0)
/* 181C14 80253334 0C0B1EAF */  jal       get_variable
/* 181C18 80253338 0240202D */   daddu    $a0, $s2, $zero
/* 181C1C 8025333C 3C01802A */  lui       $at, %hi(gSpeakingActorIdleAnim)
/* 181C20 80253340 AC22FA70 */  sw        $v0, %lo(gSpeakingActorIdleAnim)($at)
/* 181C24 80253344 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 181C28 80253348 16220002 */  bne       $s1, $v0, .L80253354
/* 181C2C 8025334C 00000000 */   nop      
/* 181C30 80253350 8E510148 */  lw        $s1, 0x148($s2)
.L80253354:
/* 181C34 80253354 0C09A75B */  jal       get_actor
/* 181C38 80253358 0220202D */   daddu    $a0, $s1, $zero
/* 181C3C 8025335C 0040882D */  daddu     $s1, $v0, $zero
/* 181C40 80253360 0220202D */  daddu     $a0, $s1, $zero
/* 181C44 80253364 0C099117 */  jal       get_actor_part
/* 181C48 80253368 0260282D */   daddu    $a1, $s3, $zero
/* 181C4C 8025336C 3C04802A */  lui       $a0, %hi(gSpeakingActorPrintCtx)
/* 181C50 80253370 8C84FA60 */  lw        $a0, %lo(gSpeakingActorPrintCtx)($a0)
/* 181C54 80253374 3C01802A */  lui       $at, %hi(gSpeakingActor)
/* 181C58 80253378 AC31FA74 */  sw        $s1, %lo(gSpeakingActor)($at)
/* 181C5C 8025337C 3C01802A */  lui       $at, %hi(gSpeakingActorPart)
/* 181C60 80253380 AC22FA78 */  sw        $v0, %lo(gSpeakingActorPart)($at)
/* 181C64 80253384 0C04971C */  jal       close_message
/* 181C68 80253388 00000000 */   nop      
/* 181C6C 8025338C 0C03A6D5 */  jal       increment_status_menu_disabled
/* 181C70 80253390 AE400070 */   sw       $zero, 0x70($s2)
.L80253394:
/* 181C74 80253394 8E420070 */  lw        $v0, 0x70($s2)
/* 181C78 80253398 14400060 */  bnez      $v0, .L8025351C
/* 181C7C 8025339C 0000102D */   daddu    $v0, $zero, $zero
/* 181C80 802533A0 3C11802A */  lui       $s1, %hi(gSpeakingActor)
/* 181C84 802533A4 8E31FA74 */  lw        $s1, %lo(gSpeakingActor)($s1)
/* 181C88 802533A8 3C12802A */  lui       $s2, %hi(gSpeakingActorPart)
/* 181C8C 802533AC 8E52FA78 */  lw        $s2, %lo(gSpeakingActorPart)($s2)
/* 181C90 802533B0 86220150 */  lh        $v0, 0x150($s1)
/* 181C94 802533B4 C6200144 */  lwc1      $f0, 0x144($s1)
/* 181C98 802533B8 44821000 */  mtc1      $v0, $f2
/* 181C9C 802533BC 00000000 */  nop       
/* 181CA0 802533C0 468010A0 */  cvt.s.w   $f2, $f2
/* 181CA4 802533C4 8E220000 */  lw        $v0, ($s1)
/* 181CA8 802533C8 30428000 */  andi      $v0, $v0, 0x8000
/* 181CAC 802533CC 1440000D */  bnez      $v0, .L80253404
/* 181CB0 802533D0 46020100 */   add.s    $f4, $f0, $f2
/* 181CB4 802533D4 86220152 */  lh        $v0, 0x152($s1)
/* 181CB8 802533D8 C6200148 */  lwc1      $f0, 0x148($s1)
/* 181CBC 802533DC 44821000 */  mtc1      $v0, $f2
/* 181CC0 802533E0 00000000 */  nop       
/* 181CC4 802533E4 468010A0 */  cvt.s.w   $f2, $f2
/* 181CC8 802533E8 92220191 */  lbu       $v0, 0x191($s1)
/* 181CCC 802533EC 46020000 */  add.s     $f0, $f0, $f2
/* 181CD0 802533F0 44821000 */  mtc1      $v0, $f2
/* 181CD4 802533F4 00000000 */  nop       
/* 181CD8 802533F8 468010A0 */  cvt.s.w   $f2, $f2
/* 181CDC 802533FC 08094D0D */  j         .L80253434
/* 181CE0 80253400 46001000 */   add.s    $f0, $f2, $f0
.L80253404:
/* 181CE4 80253404 86220152 */  lh        $v0, 0x152($s1)
/* 181CE8 80253408 C6220148 */  lwc1      $f2, 0x148($s1)
/* 181CEC 8025340C 44820000 */  mtc1      $v0, $f0
/* 181CF0 80253410 00000000 */  nop       
/* 181CF4 80253414 46800020 */  cvt.s.w   $f0, $f0
/* 181CF8 80253418 92220191 */  lbu       $v0, 0x191($s1)
/* 181CFC 8025341C 46001080 */  add.s     $f2, $f2, $f0
/* 181D00 80253420 00021042 */  srl       $v0, $v0, 1
/* 181D04 80253424 44820000 */  mtc1      $v0, $f0
/* 181D08 80253428 00000000 */  nop       
/* 181D0C 8025342C 46800020 */  cvt.s.w   $f0, $f0
/* 181D10 80253430 46001000 */  add.s     $f0, $f2, $f0
.L80253434:
/* 181D14 80253434 24040001 */  addiu     $a0, $zero, 1
/* 181D18 80253438 44052000 */  mfc1      $a1, $f4
/* 181D1C 8025343C 44060000 */  mfc1      $a2, $f0
/* 181D20 80253440 86230154 */  lh        $v1, 0x154($s1)
/* 181D24 80253444 C622014C */  lwc1      $f2, 0x14c($s1)
/* 181D28 80253448 27A20020 */  addiu     $v0, $sp, 0x20
/* 181D2C 8025344C AFA20010 */  sw        $v0, 0x10($sp)
/* 181D30 80253450 44830000 */  mtc1      $v1, $f0
/* 181D34 80253454 00000000 */  nop       
/* 181D38 80253458 46800020 */  cvt.s.w   $f0, $f0
/* 181D3C 8025345C 46001080 */  add.s     $f2, $f2, $f0
/* 181D40 80253460 27A20024 */  addiu     $v0, $sp, 0x24
/* 181D44 80253464 AFA20014 */  sw        $v0, 0x14($sp)
/* 181D48 80253468 44071000 */  mfc1      $a3, $f2
/* 181D4C 8025346C 27A20028 */  addiu     $v0, $sp, 0x28
/* 181D50 80253470 0C00B94E */  jal       get_screen_coords
/* 181D54 80253474 AFA20018 */   sw       $v0, 0x18($sp)
/* 181D58 80253478 3C10802A */  lui       $s0, %hi(gSpeakingActorPrintCtx)
/* 181D5C 8025347C 2610FA60 */  addiu     $s0, $s0, %lo(gSpeakingActorPrintCtx)
/* 181D60 80253480 8E040000 */  lw        $a0, ($s0)
/* 181D64 80253484 8FA50020 */  lw        $a1, 0x20($sp)
/* 181D68 80253488 0C0496AE */  jal       clamp_printer_coords
/* 181D6C 8025348C 8FA60024 */   lw       $a2, 0x24($sp)
/* 181D70 80253490 8E020000 */  lw        $v0, ($s0)
/* 181D74 80253494 8C4304FC */  lw        $v1, 0x4fc($v0)
/* 181D78 80253498 30620040 */  andi      $v0, $v1, 0x40
/* 181D7C 8025349C 10400005 */  beqz      $v0, .L802534B4
/* 181D80 802534A0 30620080 */   andi     $v0, $v1, 0x80
/* 181D84 802534A4 0C03A6CC */  jal       decrement_status_menu_disabled
/* 181D88 802534A8 00000000 */   nop      
/* 181D8C 802534AC 08094D47 */  j         .L8025351C
/* 181D90 802534B0 24020001 */   addiu    $v0, $zero, 1
.L802534B4:
/* 181D94 802534B4 10400005 */  beqz      $v0, .L802534CC
/* 181D98 802534B8 00000000 */   nop      
/* 181D9C 802534BC 3C06802A */  lui       $a2, %hi(gSpeakingActorTalkAnim)
/* 181DA0 802534C0 8CC6FA6C */  lw        $a2, %lo(gSpeakingActorTalkAnim)($a2)
/* 181DA4 802534C4 08094D35 */  j         .L802534D4
/* 181DA8 802534C8 00000000 */   nop      
.L802534CC:
/* 181DAC 802534CC 3C06802A */  lui       $a2, %hi(gSpeakingActorIdleAnim)
/* 181DB0 802534D0 8CC6FA70 */  lw        $a2, %lo(gSpeakingActorIdleAnim)($a2)
.L802534D4:
/* 181DB4 802534D4 04C00003 */  bltz      $a2, .L802534E4
/* 181DB8 802534D8 0220202D */   daddu    $a0, $s1, $zero
/* 181DBC 802534DC 0C098F82 */  jal       func_80263E08
/* 181DC0 802534E0 0240282D */   daddu    $a1, $s2, $zero
.L802534E4:
/* 181DC4 802534E4 3C03802A */  lui       $v1, %hi(gSpeakingActorPrintIsDone)
/* 181DC8 802534E8 8C63FA68 */  lw        $v1, %lo(gSpeakingActorPrintIsDone)($v1)
/* 181DCC 802534EC 24020001 */  addiu     $v0, $zero, 1
/* 181DD0 802534F0 1462000A */  bne       $v1, $v0, .L8025351C
/* 181DD4 802534F4 0000102D */   daddu    $v0, $zero, $zero
/* 181DD8 802534F8 0C03A6CC */  jal       decrement_status_menu_disabled
/* 181DDC 802534FC 00000000 */   nop      
/* 181DE0 80253500 24020001 */  addiu     $v0, $zero, 1
/* 181DE4 80253504 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 181DE8 80253508 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 181DEC 8025350C 8C640000 */  lw        $a0, ($v1)
/* 181DF0 80253510 2405FFEF */  addiu     $a1, $zero, -0x11
/* 181DF4 80253514 00852024 */  and       $a0, $a0, $a1
/* 181DF8 80253518 AC640000 */  sw        $a0, ($v1)
.L8025351C:
/* 181DFC 8025351C 8FBF0040 */  lw        $ra, 0x40($sp)
/* 181E00 80253520 8FB3003C */  lw        $s3, 0x3c($sp)
/* 181E04 80253524 8FB20038 */  lw        $s2, 0x38($sp)
/* 181E08 80253528 8FB10034 */  lw        $s1, 0x34($sp)
/* 181E0C 8025352C 8FB00030 */  lw        $s0, 0x30($sp)
/* 181E10 80253530 03E00008 */  jr        $ra
/* 181E14 80253534 27BD0048 */   addiu    $sp, $sp, 0x48

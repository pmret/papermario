.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_update_defeat
/* 173D20 80245440 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 173D24 80245444 AFB1001C */  sw        $s1, 0x1c($sp)
/* 173D28 80245448 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 173D2C 8024544C 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 173D30 80245450 AFB30024 */  sw        $s3, 0x24($sp)
/* 173D34 80245454 3C13800E */  lui       $s3, %hi(gBattleState2)
/* 173D38 80245458 2673C4DC */  addiu     $s3, $s3, %lo(gBattleState2)
/* 173D3C 8024545C 24020001 */  addiu     $v0, $zero, 1
/* 173D40 80245460 AFBF0028 */  sw        $ra, 0x28($sp)
/* 173D44 80245464 AFB20020 */  sw        $s2, 0x20($sp)
/* 173D48 80245468 AFB00018 */  sw        $s0, 0x18($sp)
/* 173D4C 8024546C 8E3000D8 */  lw        $s0, 0xd8($s1)
/* 173D50 80245470 8E630000 */  lw        $v1, ($s3)
/* 173D54 80245474 8E3200DC */  lw        $s2, 0xdc($s1)
/* 173D58 80245478 1062004D */  beq       $v1, $v0, .L802455B0
/* 173D5C 8024547C 28620002 */   slti     $v0, $v1, 2
/* 173D60 80245480 10400005 */  beqz      $v0, .L80245498
/* 173D64 80245484 24020002 */   addiu    $v0, $zero, 2
/* 173D68 80245488 10600007 */  beqz      $v1, .L802454A8
/* 173D6C 8024548C 2404FFF7 */   addiu    $a0, $zero, -9
/* 173D70 80245490 0809158F */  j         .L8024563C
/* 173D74 80245494 00000000 */   nop
.L80245498:
/* 173D78 80245498 1062005E */  beq       $v1, $v0, .L80245614
/* 173D7C 8024549C 00000000 */   nop
/* 173D80 802454A0 0809158F */  j         .L8024563C
/* 173D84 802454A4 00000000 */   nop
.L802454A8:
/* 173D88 802454A8 8E220000 */  lw        $v0, ($s1)
/* 173D8C 802454AC 00441024 */  and       $v0, $v0, $a0
/* 173D90 802454B0 AE220000 */  sw        $v0, ($s1)
/* 173D94 802454B4 8E220004 */  lw        $v0, 4($s1)
/* 173D98 802454B8 2403FFFD */  addiu     $v1, $zero, -3
/* 173D9C 802454BC A220008C */  sb        $zero, 0x8c($s1)
/* 173DA0 802454C0 00431024 */  and       $v0, $v0, $v1
/* 173DA4 802454C4 2403FFFB */  addiu     $v1, $zero, -5
/* 173DA8 802454C8 00431024 */  and       $v0, $v0, $v1
/* 173DAC 802454CC 00441024 */  and       $v0, $v0, $a0
/* 173DB0 802454D0 2403FFEF */  addiu     $v1, $zero, -0x11
/* 173DB4 802454D4 00431024 */  and       $v0, $v0, $v1
/* 173DB8 802454D8 AE220004 */  sw        $v0, 4($s1)
/* 173DBC 802454DC 82030210 */  lb        $v1, 0x210($s0)
/* 173DC0 802454E0 10600013 */  beqz      $v1, .L80245530
/* 173DC4 802454E4 24020007 */   addiu    $v0, $zero, 7
/* 173DC8 802454E8 14620008 */  bne       $v1, $v0, .L8024550C
/* 173DCC 802454EC 00000000 */   nop
/* 173DD0 802454F0 0C05272D */  jal       sfx_play_sound
/* 173DD4 802454F4 240400E7 */   addiu    $a0, $zero, 0xe7
/* 173DD8 802454F8 8E030228 */  lw        $v1, 0x228($s0)
/* 173DDC 802454FC 8C620000 */  lw        $v0, ($v1)
/* 173DE0 80245500 34420010 */  ori       $v0, $v0, 0x10
/* 173DE4 80245504 AC620000 */  sw        $v0, ($v1)
/* 173DE8 80245508 AE000228 */  sw        $zero, 0x228($s0)
.L8024550C:
/* 173DEC 8024550C 86040436 */  lh        $a0, 0x436($s0)
/* 173DF0 80245510 A2000210 */  sb        $zero, 0x210($s0)
/* 173DF4 80245514 0C011E26 */  jal       remove_status_1
/* 173DF8 80245518 A2000211 */   sb       $zero, 0x211($s0)
/* 173DFC 8024551C 8E020440 */  lw        $v0, 0x440($s0)
/* 173E00 80245520 A2000216 */  sb        $zero, 0x216($s0)
/* 173E04 80245524 A2000217 */  sb        $zero, 0x217($s0)
/* 173E08 80245528 8C42000C */  lw        $v0, 0xc($v0)
/* 173E0C 8024552C AC40003C */  sw        $zero, 0x3c($v0)
.L80245530:
/* 173E10 80245530 0C093903 */  jal       func_8024E40C
/* 173E14 80245534 24040019 */   addiu    $a0, $zero, 0x19
/* 173E18 80245538 0C09390F */  jal       btl_cam_target_actor
/* 173E1C 8024553C 0000202D */   daddu    $a0, $zero, $zero
/* 173E20 80245540 3C048028 */  lui       $a0, %hi(PlayerScriptDispatcher)
/* 173E24 80245544 24844EBC */  addiu     $a0, $a0, %lo(PlayerScriptDispatcher)
/* 173E28 80245548 2405000A */  addiu     $a1, $zero, 0xa
/* 173E2C 8024554C 0000302D */  daddu     $a2, $zero, $zero
/* 173E30 80245550 24020004 */  addiu     $v0, $zero, 4
/* 173E34 80245554 0C0B0CF8 */  jal       start_script
/* 173E38 80245558 A22201A7 */   sb       $v0, 0x1a7($s1)
/* 173E3C 8024555C 0040202D */  daddu     $a0, $v0, $zero
/* 173E40 80245560 AE0401D4 */  sw        $a0, 0x1d4($s0)
/* 173E44 80245564 8C820144 */  lw        $v0, 0x144($a0)
/* 173E48 80245568 AE0201E4 */  sw        $v0, 0x1e4($s0)
/* 173E4C 8024556C 1240000B */  beqz      $s2, .L8024559C
/* 173E50 80245570 AC800148 */   sw       $zero, 0x148($a0)
/* 173E54 80245574 2405000A */  addiu     $a1, $zero, 0xa
/* 173E58 80245578 8E4401C4 */  lw        $a0, 0x1c4($s2)
/* 173E5C 8024557C 0C0B0CF8 */  jal       start_script
/* 173E60 80245580 0000302D */   daddu    $a2, $zero, $zero
/* 173E64 80245584 0040202D */  daddu     $a0, $v0, $zero
/* 173E68 80245588 AE4401D4 */  sw        $a0, 0x1d4($s2)
/* 173E6C 8024558C 8C820144 */  lw        $v0, 0x144($a0)
/* 173E70 80245590 AE4201E4 */  sw        $v0, 0x1e4($s2)
/* 173E74 80245594 24020100 */  addiu     $v0, $zero, 0x100
/* 173E78 80245598 AC820148 */  sw        $v0, 0x148($a0)
.L8024559C:
/* 173E7C 8024559C 24020001 */  addiu     $v0, $zero, 1
/* 173E80 802455A0 3C01800E */  lui       $at, %hi(gBattleState2)
/* 173E84 802455A4 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 173E88 802455A8 0809158F */  j         .L8024563C
/* 173E8C 802455AC 00000000 */   nop
.L802455B0:
/* 173E90 802455B0 0C0B1059 */  jal       does_script_exist
/* 173E94 802455B4 8E0401E4 */   lw       $a0, 0x1e4($s0)
/* 173E98 802455B8 14400020 */  bnez      $v0, .L8024563C
/* 173E9C 802455BC 00000000 */   nop
/* 173EA0 802455C0 8222008C */  lb        $v0, 0x8c($s1)
/* 173EA4 802455C4 1440001D */  bnez      $v0, .L8024563C
/* 173EA8 802455C8 00000000 */   nop
/* 173EAC 802455CC 0C039D91 */  jal       find_item
/* 173EB0 802455D0 24040095 */   addiu    $a0, $zero, 0x95
/* 173EB4 802455D4 04400017 */  bltz      $v0, .L80245634
/* 173EB8 802455D8 2405000A */   addiu    $a1, $zero, 0xa
/* 173EBC 802455DC 3C048028 */  lui       $a0, %hi(PlayerScriptDispatcher)
/* 173EC0 802455E0 24844EBC */  addiu     $a0, $a0, %lo(PlayerScriptDispatcher)
/* 173EC4 802455E4 0000302D */  daddu     $a2, $zero, $zero
/* 173EC8 802455E8 24020008 */  addiu     $v0, $zero, 8
/* 173ECC 802455EC 0C0B0CF8 */  jal       start_script
/* 173ED0 802455F0 A22201A7 */   sb       $v0, 0x1a7($s1)
/* 173ED4 802455F4 0040202D */  daddu     $a0, $v0, $zero
/* 173ED8 802455F8 AE0401D4 */  sw        $a0, 0x1d4($s0)
/* 173EDC 802455FC 8C830144 */  lw        $v1, 0x144($a0)
/* 173EE0 80245600 24020002 */  addiu     $v0, $zero, 2
/* 173EE4 80245604 AE620000 */  sw        $v0, ($s3)
/* 173EE8 80245608 AE0301E4 */  sw        $v1, 0x1e4($s0)
/* 173EEC 8024560C 0809158F */  j         .L8024563C
/* 173EF0 80245610 AC800148 */   sw       $zero, 0x148($a0)
.L80245614:
/* 173EF4 80245614 8E0401E4 */  lw        $a0, 0x1e4($s0)
/* 173EF8 80245618 0C0B1059 */  jal       does_script_exist
/* 173EFC 8024561C 00000000 */   nop
/* 173F00 80245620 14400006 */  bnez      $v0, .L8024563C
/* 173F04 80245624 00000000 */   nop
/* 173F08 80245628 8222008C */  lb        $v0, 0x8c($s1)
/* 173F0C 8024562C 14400003 */  bnez      $v0, .L8024563C
/* 173F10 80245630 00000000 */   nop
.L80245634:
/* 173F14 80245634 2402000A */  addiu     $v0, $zero, 0xa
/* 173F18 80245638 AE620000 */  sw        $v0, ($s3)
.L8024563C:
/* 173F1C 8024563C 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 173F20 80245640 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 173F24 80245644 2402000A */  addiu     $v0, $zero, 0xa
/* 173F28 80245648 14620012 */  bne       $v1, $v0, .L80245694
/* 173F2C 8024564C 24030001 */   addiu    $v1, $zero, 1
/* 173F30 80245650 3C02800B */  lui       $v0, %hi(gCurrentEncounter)
/* 173F34 80245654 24420F10 */  addiu     $v0, $v0, %lo(gCurrentEncounter)
/* 173F38 80245658 A0430009 */  sb        $v1, 9($v0)
/* 173F3C 8024565C 3C02800E */  lui       $v0, %hi(gBattleStatus+0x4)
/* 173F40 80245660 8C42C074 */  lw        $v0, %lo(gBattleStatus+0x4)($v0)
/* 173F44 80245664 3C030200 */  lui       $v1, 0x200
/* 173F48 80245668 00431024 */  and       $v0, $v0, $v1
/* 173F4C 8024566C 14400007 */  bnez      $v0, .L8024568C
/* 173F50 80245670 24020008 */   addiu    $v0, $zero, 8
/* 173F54 80245674 AFA20010 */  sw        $v0, 0x10($sp)
/* 173F58 80245678 0000202D */  daddu     $a0, $zero, $zero
/* 173F5C 8024567C 2405FFFF */  addiu     $a1, $zero, -1
/* 173F60 80245680 0080302D */  daddu     $a2, $a0, $zero
/* 173F64 80245684 0C052A46 */  jal       bgm_set_song
/* 173F68 80245688 240705DC */   addiu    $a3, $zero, 0x5dc
.L8024568C:
/* 173F6C 8024568C 0C090464 */  jal       btl_set_state
/* 173F70 80245690 24040020 */   addiu    $a0, $zero, 0x20
.L80245694:
/* 173F74 80245694 8FBF0028 */  lw        $ra, 0x28($sp)
/* 173F78 80245698 8FB30024 */  lw        $s3, 0x24($sp)
/* 173F7C 8024569C 8FB20020 */  lw        $s2, 0x20($sp)
/* 173F80 802456A0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 173F84 802456A4 8FB00018 */  lw        $s0, 0x18($sp)
/* 173F88 802456A8 03E00008 */  jr        $ra
/* 173F8C 802456AC 27BD0030 */   addiu    $sp, $sp, 0x30

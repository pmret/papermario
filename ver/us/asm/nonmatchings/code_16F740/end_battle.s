.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8029CAAC
.word 0x67765F30, 0x31000000, 0x00000000

glabel jtbl_8029CAB8
.word L80244AA8_173388, L80244B40_173420, L80244B88_173468, L80244C0C_1734EC, L80244C28_173508, 0

.section .text

glabel end_battle
/* 173330 80244A50 3C03800E */  lui       $v1, %hi(gBattleStatus+0x46C)
/* 173334 80244A54 8C63C4DC */  lw        $v1, %lo(gBattleStatus+0x46C)($v1)
/* 173338 80244A58 3C06800E */  lui       $a2, %hi(gBattleStatus+0x48C)
/* 17333C 80244A5C 8CC6C4FC */  lw        $a2, %lo(gBattleStatus+0x48C)($a2)
/* 173340 80244A60 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 173344 80244A64 AFB30024 */  sw        $s3, 0x24($sp)
/* 173348 80244A68 3C13800B */  lui       $s3, %hi(gCurrentEncounter)
/* 17334C 80244A6C 26730F10 */  addiu     $s3, $s3, %lo(gCurrentEncounter)
/* 173350 80244A70 AFB20020 */  sw        $s2, 0x20($sp)
/* 173354 80244A74 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 173358 80244A78 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 17335C 80244A7C AFBF0028 */  sw        $ra, 0x28($sp)
/* 173360 80244A80 AFB1001C */  sw        $s1, 0x1c($sp)
/* 173364 80244A84 2C620005 */  sltiu     $v0, $v1, 5
/* 173368 80244A88 104000BA */  beqz      $v0, .L80244D74
/* 17336C 80244A8C AFB00018 */   sw       $s0, 0x18($sp)
/* 173370 80244A90 00031080 */  sll       $v0, $v1, 2
/* 173374 80244A94 3C01802A */  lui       $at, %hi(jtbl_8029CAB8)
/* 173378 80244A98 00220821 */  addu      $at, $at, $v0
/* 17337C 80244A9C 8C22CAB8 */  lw        $v0, %lo(jtbl_8029CAB8)($at)
/* 173380 80244AA0 00400008 */  jr        $v0
/* 173384 80244AA4 00000000 */   nop
glabel L80244AA8_173388
/* 173388 80244AA8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 17338C 80244AAC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 173390 80244AB0 3C048028 */  lui       $a0, %hi(D_80280A30)
/* 173394 80244AB4 24840A30 */  addiu     $a0, $a0, %lo(D_80280A30)
/* 173398 80244AB8 AC800000 */  sw        $zero, ($a0)
/* 17339C 80244ABC 80430074 */  lb        $v1, 0x74($v0)
/* 1733A0 80244AC0 24020002 */  addiu     $v0, $zero, 2
/* 1733A4 80244AC4 14620002 */  bne       $v1, $v0, .L80244AD0
/* 1733A8 80244AC8 240200FF */   addiu    $v0, $zero, 0xff
/* 1733AC 80244ACC AC820000 */  sw        $v0, ($a0)
.L80244AD0:
/* 1733B0 80244AD0 82630009 */  lb        $v1, 9($s3)
/* 1733B4 80244AD4 24020001 */  addiu     $v0, $zero, 1
/* 1733B8 80244AD8 14620015 */  bne       $v1, $v0, .L80244B30
/* 1733BC 80244ADC 3C030080 */   lui      $v1, 0x80
/* 1733C0 80244AE0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1733C4 80244AE4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1733C8 80244AE8 00431024 */  and       $v0, $v0, $v1
/* 1733CC 80244AEC 14400010 */  bnez      $v0, .L80244B30
/* 1733D0 80244AF0 24020001 */   addiu    $v0, $zero, 1
/* 1733D4 80244AF4 0C093980 */  jal       unfreeze_cam
/* 1733D8 80244AF8 00000000 */   nop
/* 1733DC 80244AFC 0C093903 */  jal       func_8024E40C
/* 1733E0 80244B00 24040001 */   addiu    $a0, $zero, 1
/* 1733E4 80244B04 0000202D */  daddu     $a0, $zero, $zero
/* 1733E8 80244B08 0080282D */  daddu     $a1, $a0, $zero
/* 1733EC 80244B0C 0080302D */  daddu     $a2, $a0, $zero
/* 1733F0 80244B10 0C04DF84 */  jal       set_transition_stencil_color
/* 1733F4 80244B14 0080382D */   daddu    $a3, $a0, $zero
/* 1733F8 80244B18 0000202D */  daddu     $a0, $zero, $zero
/* 1733FC 80244B1C 0080282D */  daddu     $a1, $a0, $zero
/* 173400 80244B20 240600A0 */  addiu     $a2, $zero, 0xa0
/* 173404 80244B24 0C04DF93 */  jal       set_transition_stencil_center
/* 173408 80244B28 24070078 */   addiu    $a3, $zero, 0x78
/* 17340C 80244B2C 24020001 */  addiu     $v0, $zero, 1
.L80244B30:
/* 173410 80244B30 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 173414 80244B34 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 173418 80244B38 0809135D */  j         .L80244D74
/* 17341C 80244B3C 00000000 */   nop
glabel L80244B40_173420
/* 173420 80244B40 3C048028 */  lui       $a0, %hi(D_80280A30)
/* 173424 80244B44 24840A30 */  addiu     $a0, $a0, %lo(D_80280A30)
/* 173428 80244B48 8C830000 */  lw        $v1, ($a0)
/* 17342C 80244B4C 240500FF */  addiu     $a1, $zero, 0xff
/* 173430 80244B50 14650005 */  bne       $v1, $a1, .L80244B68
/* 173434 80244B54 24020002 */   addiu    $v0, $zero, 2
/* 173438 80244B58 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 17343C 80244B5C AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 173440 80244B60 0809135D */  j         .L80244D74
/* 173444 80244B64 00000000 */   nop
.L80244B68:
/* 173448 80244B68 8242008D */  lb        $v0, 0x8d($s2)
/* 17344C 80244B6C 00621021 */  addu      $v0, $v1, $v0
/* 173450 80244B70 AC820000 */  sw        $v0, ($a0)
/* 173454 80244B74 28420100 */  slti      $v0, $v0, 0x100
/* 173458 80244B78 5040007E */  beql      $v0, $zero, .L80244D74
/* 17345C 80244B7C AC850000 */   sw       $a1, ($a0)
/* 173460 80244B80 0809135D */  j         .L80244D74
/* 173464 80244B84 00000000 */   nop
glabel L80244B88_173468
/* 173468 80244B88 240200FF */  addiu     $v0, $zero, 0xff
/* 17346C 80244B8C 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 173470 80244B90 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 173474 80244B94 2403FFFE */  addiu     $v1, $zero, -2
/* 173478 80244B98 3C018028 */  lui       $at, %hi(D_80280A30)
/* 17347C 80244B9C AC220A30 */  sw        $v0, %lo(D_80280A30)($at)
/* 173480 80244BA0 8C820000 */  lw        $v0, ($a0)
/* 173484 80244BA4 3C05800E */  lui       $a1, %hi(D_800DC064)
/* 173488 80244BA8 8CA5C064 */  lw        $a1, %lo(D_800DC064)($a1)
/* 17348C 80244BAC 00431024 */  and       $v0, $v0, $v1
/* 173490 80244BB0 14A00004 */  bnez      $a1, .L80244BC4
/* 173494 80244BB4 AC820000 */   sw       $v0, ($a0)
/* 173498 80244BB8 8CC4000C */  lw        $a0, 0xc($a2)
/* 17349C 80244BBC 080912F2 */  j         .L80244BC8
/* 1734A0 80244BC0 00000000 */   nop
.L80244BC4:
/* 1734A4 80244BC4 8CA40004 */  lw        $a0, 4($a1)
.L80244BC8:
/* 1734A8 80244BC8 8C840010 */  lw        $a0, 0x10($a0)
/* 1734AC 80244BCC 14800006 */  bnez      $a0, .L80244BE8
/* 1734B0 80244BD0 2405000A */   addiu    $a1, $zero, 0xa
/* 1734B4 80244BD4 24020004 */  addiu     $v0, $zero, 4
/* 1734B8 80244BD8 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 1734BC 80244BDC AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 1734C0 80244BE0 0809135D */  j         .L80244D74
/* 1734C4 80244BE4 00000000 */   nop
.L80244BE8:
/* 1734C8 80244BE8 0C0B0CF8 */  jal       start_script
/* 1734CC 80244BEC 0000302D */   daddu    $a2, $zero, $zero
/* 1734D0 80244BF0 AE4200BC */  sw        $v0, 0xbc($s2)
/* 1734D4 80244BF4 8C430144 */  lw        $v1, 0x144($v0)
/* 1734D8 80244BF8 24020003 */  addiu     $v0, $zero, 3
/* 1734DC 80244BFC 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 1734E0 80244C00 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 1734E4 80244C04 0809135D */  j         .L80244D74
/* 1734E8 80244C08 AE4300C0 */   sw       $v1, 0xc0($s2)
glabel L80244C0C_1734EC
/* 1734EC 80244C0C 8E4400C0 */  lw        $a0, 0xc0($s2)
/* 1734F0 80244C10 0C0B1059 */  jal       does_script_exist
/* 1734F4 80244C14 00000000 */   nop
/* 1734F8 80244C18 14400056 */  bnez      $v0, .L80244D74
/* 1734FC 80244C1C 24020004 */   addiu    $v0, $zero, 4
/* 173500 80244C20 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 173504 80244C24 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
glabel L80244C28_173508
/* 173508 80244C28 0C0B1045 */  jal       kill_all_scripts
/* 17350C 80244C2C 0000882D */   daddu    $s1, $zero, $zero
/* 173510 80244C30 0240802D */  daddu     $s0, $s2, $zero
.L80244C34:
/* 173514 80244C34 8E0400E0 */  lw        $a0, 0xe0($s0)
/* 173518 80244C38 10800003 */  beqz      $a0, .L80244C48
/* 17351C 80244C3C 26310001 */   addiu    $s1, $s1, 1
/* 173520 80244C40 0C0902EF */  jal       delete_actor
/* 173524 80244C44 00000000 */   nop
.L80244C48:
/* 173528 80244C48 2A220018 */  slti      $v0, $s1, 0x18
/* 17352C 80244C4C 1440FFF9 */  bnez      $v0, .L80244C34
/* 173530 80244C50 26100004 */   addiu    $s0, $s0, 4
/* 173534 80244C54 8E4400DC */  lw        $a0, 0xdc($s2)
/* 173538 80244C58 10800003 */  beqz      $a0, .L80244C68
/* 17353C 80244C5C 00000000 */   nop
/* 173540 80244C60 0C0902EF */  jal       delete_actor
/* 173544 80244C64 00000000 */   nop
.L80244C68:
/* 173548 80244C68 0C09035A */  jal       delete_player_actor
/* 17354C 80244C6C 8E4400D8 */   lw       $a0, 0xd8($s2)
/* 173550 80244C70 8243008A */  lb        $v1, 0x8a($s2)
/* 173554 80244C74 24020004 */  addiu     $v0, $zero, 4
/* 173558 80244C78 14620003 */  bne       $v1, $v0, .L80244C88
/* 17355C 80244C7C 24020001 */   addiu    $v0, $zero, 1
/* 173560 80244C80 A262000B */  sb        $v0, 0xb($s3)
/* 173564 80244C84 A240008A */  sb        $zero, 0x8a($s2)
.L80244C88:
/* 173568 80244C88 9242007B */  lbu       $v0, 0x7b($s2)
/* 17356C 80244C8C 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 173570 80244C90 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 173574 80244C94 A262000C */  sb        $v0, 0xc($s3)
/* 173578 80244C98 8E020004 */  lw        $v0, 4($s0)
/* 17357C 80244C9C 3C031000 */  lui       $v1, 0x1000
/* 173580 80244CA0 00431024 */  and       $v0, $v0, $v1
/* 173584 80244CA4 10400002 */  beqz      $v0, .L80244CB0
/* 173588 80244CA8 24020001 */   addiu    $v0, $zero, 1
/* 17358C 80244CAC A2620013 */  sb        $v0, 0x13($s3)
.L80244CB0:
/* 173590 80244CB0 0C016938 */  jal       remove_all_effects
/* 173594 80244CB4 00000000 */   nop
/* 173598 80244CB8 0C051FB1 */  jal       set_windows_visible
/* 17359C 80244CBC 0000202D */   daddu    $a0, $zero, $zero
/* 1735A0 80244CC0 8E020004 */  lw        $v0, 4($s0)
/* 1735A4 80244CC4 30420040 */  andi      $v0, $v0, 0x40
/* 1735A8 80244CC8 10400003 */  beqz      $v0, .L80244CD8
/* 1735AC 80244CCC 00000000 */   nop
/* 1735B0 80244CD0 0C03A6CC */  jal       decrement_status_menu_disabled
/* 1735B4 80244CD4 00000000 */   nop
.L80244CD8:
/* 1735B8 80244CD8 82630009 */  lb        $v1, 9($s3)
/* 1735BC 80244CDC 24020001 */  addiu     $v0, $zero, 1
/* 1735C0 80244CE0 14620019 */  bne       $v1, $v0, .L80244D48
/* 1735C4 80244CE4 3C030080 */   lui      $v1, 0x80
/* 1735C8 80244CE8 8E020000 */  lw        $v0, ($s0)
/* 1735CC 80244CEC 00431024 */  and       $v0, $v0, $v1
/* 1735D0 80244CF0 14400015 */  bnez      $v0, .L80244D48
/* 1735D4 80244CF4 00000000 */   nop
/* 1735D8 80244CF8 0C090464 */  jal       func_80241190
/* 1735DC 80244CFC 0000202D */   daddu    $a0, $zero, $zero
/* 1735E0 80244D00 3C04802A */  lui       $a0, %hi(D_8029CAAC)
/* 1735E4 80244D04 2484CAAC */  addiu     $a0, $a0, %lo(D_8029CAAC)
/* 1735E8 80244D08 27A50010 */  addiu     $a1, $sp, 0x10
/* 1735EC 80244D0C 3C02800E */  lui       $v0, %hi(gBattleState)
/* 1735F0 80244D10 8C42C068 */  lw        $v0, %lo(gBattleState)($v0)
/* 1735F4 80244D14 3C01800E */  lui       $at, %hi(gBattleStatus+0x460)
/* 1735F8 80244D18 AC22C4D0 */  sw        $v0, %lo(gBattleStatus+0x460)($at)
/* 1735FC 80244D1C 0C016AFE */  jal       get_map_IDs_by_name
/* 173600 80244D20 27A60012 */   addiu    $a2, $sp, 0x12
/* 173604 80244D24 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 173608 80244D28 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 17360C 80244D2C 97A30010 */  lhu       $v1, 0x10($sp)
/* 173610 80244D30 97A50012 */  lhu       $a1, 0x12($sp)
/* 173614 80244D34 24040006 */  addiu     $a0, $zero, 6
/* 173618 80244D38 A4430086 */  sh        $v1, 0x86($v0)
/* 17361C 80244D3C A445008C */  sh        $a1, 0x8c($v0)
/* 173620 80244D40 0809135B */  j         .L80244D6C
/* 173624 80244D44 A440008E */   sh       $zero, 0x8e($v0)
.L80244D48:
/* 173628 80244D48 0C090464 */  jal       func_80241190
/* 17362C 80244D4C 0000202D */   daddu    $a0, $zero, $zero
/* 173630 80244D50 3C02800E */  lui       $v0, %hi(gBattleState)
/* 173634 80244D54 8C42C068 */  lw        $v0, %lo(gBattleState)($v0)
/* 173638 80244D58 3C01800E */  lui       $at, %hi(gBattleStatus+0x460)
/* 17363C 80244D5C AC22C4D0 */  sw        $v0, %lo(gBattleStatus+0x460)($at)
/* 173640 80244D60 0C00F945 */  jal       func_8003E514
/* 173644 80244D64 24040001 */   addiu    $a0, $zero, 1
/* 173648 80244D68 24040009 */  addiu     $a0, $zero, 9
.L80244D6C:
/* 17364C 80244D6C 0C00CD3C */  jal       set_game_mode
/* 173650 80244D70 00000000 */   nop
.L80244D74:
/* 173654 80244D74 8FBF0028 */  lw        $ra, 0x28($sp)
/* 173658 80244D78 8FB30024 */  lw        $s3, 0x24($sp)
/* 17365C 80244D7C 8FB20020 */  lw        $s2, 0x20($sp)
/* 173660 80244D80 8FB1001C */  lw        $s1, 0x1c($sp)
/* 173664 80244D84 8FB00018 */  lw        $s0, 0x18($sp)
/* 173668 80244D88 03E00008 */  jr        $ra
/* 17366C 80244D8C 27BD0030 */   addiu    $sp, $sp, 0x30

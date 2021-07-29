.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029CBE0
.word L80248B54_177434, L80248BA4_177484, L80248C0C_1774EC, L80248C90_177570, L80248CAC_17758C, 0, 0, 0

.section .text

glabel btl_state_update_end_demo_battle
/* 1773E8 80248B08 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 1773EC 80248B0C 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 1773F0 80248B10 3C06800E */  lui       $a2, %hi(D_800DC4FC)
/* 1773F4 80248B14 8CC6C4FC */  lw        $a2, %lo(D_800DC4FC)($a2)
/* 1773F8 80248B18 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1773FC 80248B1C AFB20018 */  sw        $s2, 0x18($sp)
/* 177400 80248B20 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 177404 80248B24 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 177408 80248B28 AFBF001C */  sw        $ra, 0x1c($sp)
/* 17740C 80248B2C AFB10014 */  sw        $s1, 0x14($sp)
/* 177410 80248B30 2C620005 */  sltiu     $v0, $v1, 5
/* 177414 80248B34 1040008A */  beqz      $v0, .L80248D60
/* 177418 80248B38 AFB00010 */   sw       $s0, 0x10($sp)
/* 17741C 80248B3C 00031080 */  sll       $v0, $v1, 2
/* 177420 80248B40 3C01802A */  lui       $at, %hi(jtbl_8029CBE0)
/* 177424 80248B44 00220821 */  addu      $at, $at, $v0
/* 177428 80248B48 8C22CBE0 */  lw        $v0, %lo(jtbl_8029CBE0)($at)
/* 17742C 80248B4C 00400008 */  jr        $v0
/* 177430 80248B50 00000000 */   nop
glabel L80248B54_177434
/* 177434 80248B54 3C038028 */  lui       $v1, %hi(D_802809F6)
/* 177438 80248B58 846309F6 */  lh        $v1, %lo(D_802809F6)($v1)
/* 17743C 80248B5C 2402FFFF */  addiu     $v0, $zero, -1
/* 177440 80248B60 3C018028 */  lui       $at, %hi(D_80280A30)
/* 177444 80248B64 AC200A30 */  sw        $zero, %lo(D_80280A30)($at)
/* 177448 80248B68 1462000A */  bne       $v1, $v0, .L80248B94
/* 17744C 80248B6C 24020001 */   addiu    $v0, $zero, 1
/* 177450 80248B70 3C048028 */  lui       $a0, %hi(D_802809F8)
/* 177454 80248B74 248409F8 */  addiu     $a0, $a0, %lo(D_802809F8)
/* 177458 80248B78 84820000 */  lh        $v0, ($a0)
/* 17745C 80248B7C 94830000 */  lhu       $v1, ($a0)
/* 177460 80248B80 10400003 */  beqz      $v0, .L80248B90
/* 177464 80248B84 2462FFFF */   addiu    $v0, $v1, -1
/* 177468 80248B88 08092358 */  j         .L80248D60
/* 17746C 80248B8C A4820000 */   sh       $v0, ($a0)
.L80248B90:
/* 177470 80248B90 24020001 */  addiu     $v0, $zero, 1
.L80248B94:
/* 177474 80248B94 3C01800E */  lui       $at, %hi(gBattleState2)
/* 177478 80248B98 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 17747C 80248B9C 08092358 */  j         .L80248D60
/* 177480 80248BA0 00000000 */   nop
glabel L80248BA4_177484
/* 177484 80248BA4 3C038028 */  lui       $v1, %hi(D_802809F6)
/* 177488 80248BA8 846309F6 */  lh        $v1, %lo(D_802809F6)($v1)
/* 17748C 80248BAC 2402FFFF */  addiu     $v0, $zero, -1
/* 177490 80248BB0 10620005 */  beq       $v1, $v0, .L80248BC8
/* 177494 80248BB4 240200FF */   addiu    $v0, $zero, 0xff
/* 177498 80248BB8 14620069 */  bne       $v1, $v0, .L80248D60
/* 17749C 80248BBC 24020002 */   addiu    $v0, $zero, 2
/* 1774A0 80248BC0 080922F9 */  j         .L80248BE4
/* 1774A4 80248BC4 00000000 */   nop
.L80248BC8:
/* 1774A8 80248BC8 3C038028 */  lui       $v1, %hi(D_80280A30)
/* 1774AC 80248BCC 24630A30 */  addiu     $v1, $v1, %lo(D_80280A30)
/* 1774B0 80248BD0 8C620000 */  lw        $v0, ($v1)
/* 1774B4 80248BD4 240400FF */  addiu     $a0, $zero, 0xff
/* 1774B8 80248BD8 14440006 */  bne       $v0, $a0, .L80248BF4
/* 1774BC 80248BDC 24420032 */   addiu    $v0, $v0, 0x32
/* 1774C0 80248BE0 24020002 */  addiu     $v0, $zero, 2
.L80248BE4:
/* 1774C4 80248BE4 3C01800E */  lui       $at, %hi(gBattleState2)
/* 1774C8 80248BE8 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 1774CC 80248BEC 08092358 */  j         .L80248D60
/* 1774D0 80248BF0 00000000 */   nop
.L80248BF4:
/* 1774D4 80248BF4 AC620000 */  sw        $v0, ($v1)
/* 1774D8 80248BF8 28420100 */  slti      $v0, $v0, 0x100
/* 1774DC 80248BFC 50400058 */  beql      $v0, $zero, .L80248D60
/* 1774E0 80248C00 AC640000 */   sw       $a0, ($v1)
/* 1774E4 80248C04 08092358 */  j         .L80248D60
/* 1774E8 80248C08 00000000 */   nop
glabel L80248C0C_1774EC
/* 1774EC 80248C0C 240200FF */  addiu     $v0, $zero, 0xff
/* 1774F0 80248C10 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 1774F4 80248C14 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 1774F8 80248C18 2403FFFE */  addiu     $v1, $zero, -2
/* 1774FC 80248C1C 3C018028 */  lui       $at, %hi(D_80280A30)
/* 177500 80248C20 AC220A30 */  sw        $v0, %lo(D_80280A30)($at)
/* 177504 80248C24 8C820000 */  lw        $v0, ($a0)
/* 177508 80248C28 3C05800E */  lui       $a1, %hi(D_800DC064)
/* 17750C 80248C2C 8CA5C064 */  lw        $a1, %lo(D_800DC064)($a1)
/* 177510 80248C30 00431024 */  and       $v0, $v0, $v1
/* 177514 80248C34 14A00004 */  bnez      $a1, .L80248C48
/* 177518 80248C38 AC820000 */   sw       $v0, ($a0)
/* 17751C 80248C3C 8CC4000C */  lw        $a0, 0xc($a2)
/* 177520 80248C40 08092313 */  j         .L80248C4C
/* 177524 80248C44 00000000 */   nop
.L80248C48:
/* 177528 80248C48 8CA40004 */  lw        $a0, 4($a1)
.L80248C4C:
/* 17752C 80248C4C 8C840010 */  lw        $a0, 0x10($a0)
/* 177530 80248C50 14800006 */  bnez      $a0, .L80248C6C
/* 177534 80248C54 2405000A */   addiu    $a1, $zero, 0xa
/* 177538 80248C58 24020004 */  addiu     $v0, $zero, 4
/* 17753C 80248C5C 3C01800E */  lui       $at, %hi(gBattleState2)
/* 177540 80248C60 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 177544 80248C64 08092358 */  j         .L80248D60
/* 177548 80248C68 00000000 */   nop
.L80248C6C:
/* 17754C 80248C6C 0C0B0CF8 */  jal       start_script
/* 177550 80248C70 0000302D */   daddu    $a2, $zero, $zero
/* 177554 80248C74 AE4200BC */  sw        $v0, 0xbc($s2)
/* 177558 80248C78 8C430144 */  lw        $v1, 0x144($v0)
/* 17755C 80248C7C 24020003 */  addiu     $v0, $zero, 3
/* 177560 80248C80 3C01800E */  lui       $at, %hi(gBattleState2)
/* 177564 80248C84 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 177568 80248C88 08092358 */  j         .L80248D60
/* 17756C 80248C8C AE4300C0 */   sw       $v1, 0xc0($s2)
glabel L80248C90_177570
/* 177570 80248C90 8E4400C0 */  lw        $a0, 0xc0($s2)
/* 177574 80248C94 0C0B1059 */  jal       does_script_exist
/* 177578 80248C98 00000000 */   nop
/* 17757C 80248C9C 14400030 */  bnez      $v0, .L80248D60
/* 177580 80248CA0 24020004 */   addiu    $v0, $zero, 4
/* 177584 80248CA4 3C01800E */  lui       $at, %hi(gBattleState2)
/* 177588 80248CA8 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
glabel L80248CAC_17758C
/* 17758C 80248CAC 0C0B1045 */  jal       kill_all_scripts
/* 177590 80248CB0 0000882D */   daddu    $s1, $zero, $zero
/* 177594 80248CB4 0240802D */  daddu     $s0, $s2, $zero
.L80248CB8:
/* 177598 80248CB8 8E0400E0 */  lw        $a0, 0xe0($s0)
/* 17759C 80248CBC 10800003 */  beqz      $a0, .L80248CCC
/* 1775A0 80248CC0 26310001 */   addiu    $s1, $s1, 1
/* 1775A4 80248CC4 0C0902EF */  jal       btl_delete_actor
/* 1775A8 80248CC8 00000000 */   nop
.L80248CCC:
/* 1775AC 80248CCC 2A220018 */  slti      $v0, $s1, 0x18
/* 1775B0 80248CD0 1440FFF9 */  bnez      $v0, .L80248CB8
/* 1775B4 80248CD4 26100004 */   addiu    $s0, $s0, 4
/* 1775B8 80248CD8 8E4400DC */  lw        $a0, 0xdc($s2)
/* 1775BC 80248CDC 10800003 */  beqz      $a0, .L80248CEC
/* 1775C0 80248CE0 00000000 */   nop
/* 1775C4 80248CE4 0C0902EF */  jal       btl_delete_actor
/* 1775C8 80248CE8 00000000 */   nop
.L80248CEC:
/* 1775CC 80248CEC 0C09035A */  jal       btl_delete_player_actor
/* 1775D0 80248CF0 8E4400D8 */   lw       $a0, 0xd8($s2)
/* 1775D4 80248CF4 0C016938 */  jal       remove_all_effects
/* 1775D8 80248CF8 00000000 */   nop
/* 1775DC 80248CFC 0C051FB1 */  jal       set_windows_visible
/* 1775E0 80248D00 0000202D */   daddu    $a0, $zero, $zero
/* 1775E4 80248D04 3C02800E */  lui       $v0, %hi(gBattleStatus+0x4)
/* 1775E8 80248D08 8C42C074 */  lw        $v0, %lo(gBattleStatus+0x4)($v0)
/* 1775EC 80248D0C 30420040 */  andi      $v0, $v0, 0x40
/* 1775F0 80248D10 10400003 */  beqz      $v0, .L80248D20
/* 1775F4 80248D14 00000000 */   nop
/* 1775F8 80248D18 0C03A6CC */  jal       decrement_status_menu_disabled
/* 1775FC 80248D1C 00000000 */   nop
.L80248D20:
/* 177600 80248D20 3C038028 */  lui       $v1, %hi(D_802809F6)
/* 177604 80248D24 846309F6 */  lh        $v1, %lo(D_802809F6)($v1)
/* 177608 80248D28 2402FFFF */  addiu     $v0, $zero, -1
/* 17760C 80248D2C 10620004 */  beq       $v1, $v0, .L80248D40
/* 177610 80248D30 24020012 */   addiu    $v0, $zero, 0x12
/* 177614 80248D34 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 177618 80248D38 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 17761C 80248D3C A0620072 */  sb        $v0, 0x72($v1)
.L80248D40:
/* 177620 80248D40 0C090464 */  jal       btl_set_state
/* 177624 80248D44 0000202D */   daddu    $a0, $zero, $zero
/* 177628 80248D48 3C02800E */  lui       $v0, %hi(gBattleState)
/* 17762C 80248D4C 8C42C068 */  lw        $v0, %lo(gBattleState)($v0)
/* 177630 80248D50 3C01800E */  lui       $at, %hi(D_800DC4D0)
/* 177634 80248D54 AC22C4D0 */  sw        $v0, %lo(D_800DC4D0)($at)
/* 177638 80248D58 0C00CD3C */  jal       set_game_mode
/* 17763C 80248D5C 24040009 */   addiu    $a0, $zero, 9
.L80248D60:
/* 177640 80248D60 8FBF001C */  lw        $ra, 0x1c($sp)
/* 177644 80248D64 8FB20018 */  lw        $s2, 0x18($sp)
/* 177648 80248D68 8FB10014 */  lw        $s1, 0x14($sp)
/* 17764C 80248D6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 177650 80248D70 03E00008 */  jr        $ra
/* 177654 80248D74 27BD0020 */   addiu    $sp, $sp, 0x20

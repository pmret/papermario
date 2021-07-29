.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029CB30
.word L80246B8C_17546C, L80246FFC_1758DC, L80246C5C_17553C, L80246CFC_1755DC, L80246FFC_1758DC, L80246FFC_1758DC, L80246FFC_1758DC, L80246FFC_1758DC, L80246FFC_1758DC, L80246FFC_1758DC, L80246FFC_1758DC, L80246FA0_175880, L80246FD4_1758B4, 0

glabel jtbl_8029CB68
.word L802470BC_17599C, L802470E4_1759C4, L802470C4_1759A4, L802470CC_1759AC, L802470F4_1759D4, L802470D4_1759B4, L802470DC_1759BC, L802470EC_1759CC

.section .text

glabel btl_state_update_partner_move
/* 175414 80246B34 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 175418 80246B38 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 17541C 80246B3C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 175420 80246B40 AFB50024 */  sw        $s5, 0x24($sp)
/* 175424 80246B44 3C15800E */  lui       $s5, %hi(gBattleStatus)
/* 175428 80246B48 26B5C070 */  addiu     $s5, $s5, %lo(gBattleStatus)
/* 17542C 80246B4C AFBF0028 */  sw        $ra, 0x28($sp)
/* 175430 80246B50 AFB40020 */  sw        $s4, 0x20($sp)
/* 175434 80246B54 AFB3001C */  sw        $s3, 0x1c($sp)
/* 175438 80246B58 AFB20018 */  sw        $s2, 0x18($sp)
/* 17543C 80246B5C AFB10014 */  sw        $s1, 0x14($sp)
/* 175440 80246B60 AFB00010 */  sw        $s0, 0x10($sp)
/* 175444 80246B64 8EB200D8 */  lw        $s2, 0xd8($s5)
/* 175448 80246B68 8EB400DC */  lw        $s4, 0xdc($s5)
/* 17544C 80246B6C 2C62000D */  sltiu     $v0, $v1, 0xd
/* 175450 80246B70 10400122 */  beqz      $v0, L80246FFC_1758DC
/* 175454 80246B74 00031080 */   sll      $v0, $v1, 2
/* 175458 80246B78 3C01802A */  lui       $at, %hi(jtbl_8029CB30)
/* 17545C 80246B7C 00220821 */  addu      $at, $at, $v0
/* 175460 80246B80 8C22CB30 */  lw        $v0, %lo(jtbl_8029CB30)($at)
/* 175464 80246B84 00400008 */  jr        $v0
/* 175468 80246B88 00000000 */   nop
glabel L80246B8C_17546C
/* 17546C 80246B8C 16800005 */  bnez      $s4, .L80246BA4
/* 175470 80246B90 2402007F */   addiu    $v0, $zero, 0x7f
/* 175474 80246B94 0C090464 */  jal       btl_set_state
/* 175478 80246B98 24040009 */   addiu    $a0, $zero, 9
/* 17547C 80246B9C 08091BFF */  j         L80246FFC_1758DC
/* 175480 80246BA0 00000000 */   nop
.L80246BA4:
/* 175484 80246BA4 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 175488 80246BA8 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 17548C 80246BAC A2A0008C */  sb        $zero, 0x8c($s5)
/* 175490 80246BB0 A2A20086 */  sb        $v0, 0x86($s5)
/* 175494 80246BB4 A2A20087 */  sb        $v0, 0x87($s5)
/* 175498 80246BB8 A2A0019A */  sb        $zero, 0x19a($s5)
/* 17549C 80246BBC 8E020000 */  lw        $v0, ($s0)
/* 1754A0 80246BC0 2403EFFF */  addiu     $v1, $zero, -0x1001
/* 1754A4 80246BC4 00431024 */  and       $v0, $v0, $v1
/* 1754A8 80246BC8 2403FFFD */  addiu     $v1, $zero, -3
/* 1754AC 80246BCC 00431024 */  and       $v0, $v0, $v1
/* 1754B0 80246BD0 0C098F18 */  jal       reset_actor_turn_info
/* 1754B4 80246BD4 AE020000 */   sw       $v0, ($s0)
/* 1754B8 80246BD8 3C03F7FF */  lui       $v1, 0xf7ff
/* 1754BC 80246BDC 8E820000 */  lw        $v0, ($s4)
/* 1754C0 80246BE0 3463FFFF */  ori       $v1, $v1, 0xffff
/* 1754C4 80246BE4 A280021C */  sb        $zero, 0x21c($s4)
/* 1754C8 80246BE8 00431024 */  and       $v0, $v0, $v1
/* 1754CC 80246BEC AE820000 */  sw        $v0, ($s4)
/* 1754D0 80246BF0 8E420000 */  lw        $v0, ($s2)
/* 1754D4 80246BF4 0000882D */  daddu     $s1, $zero, $zero
/* 1754D8 80246BF8 00431024 */  and       $v0, $v0, $v1
/* 1754DC 80246BFC 0C098EF2 */  jal       deduct_current_move_fp
/* 1754E0 80246C00 AE420000 */   sw       $v0, ($s2)
/* 1754E4 80246C04 0C09390F */  jal       btl_cam_target_actor
/* 1754E8 80246C08 24040100 */   addiu    $a0, $zero, 0x100
/* 1754EC 80246C0C 3C04FFDF */  lui       $a0, 0xffdf
/* 1754F0 80246C10 3484FFFF */  ori       $a0, $a0, 0xffff
/* 1754F4 80246C14 02A0282D */  daddu     $a1, $s5, $zero
/* 1754F8 80246C18 8E020004 */  lw        $v0, 4($s0)
/* 1754FC 80246C1C 8E030000 */  lw        $v1, ($s0)
/* 175500 80246C20 34420010 */  ori       $v0, $v0, 0x10
/* 175504 80246C24 00641824 */  and       $v1, $v1, $a0
/* 175508 80246C28 AE020004 */  sw        $v0, 4($s0)
/* 17550C 80246C2C AE030000 */  sw        $v1, ($s0)
.L80246C30:
/* 175510 80246C30 8CB000E0 */  lw        $s0, 0xe0($a1)
/* 175514 80246C34 56000001 */  bnel      $s0, $zero, .L80246C3C
/* 175518 80246C38 A200021C */   sb       $zero, 0x21c($s0)
.L80246C3C:
/* 17551C 80246C3C 26310001 */  addiu     $s1, $s1, 1
/* 175520 80246C40 2A220018 */  slti      $v0, $s1, 0x18
/* 175524 80246C44 1440FFFA */  bnez      $v0, .L80246C30
/* 175528 80246C48 24A50004 */   addiu    $a1, $a1, 4
/* 17552C 80246C4C 0C093903 */  jal       func_8024E40C
/* 175530 80246C50 24040002 */   addiu    $a0, $zero, 2
/* 175534 80246C54 08091BFD */  j         .L80246FF4
/* 175538 80246C58 24020002 */   addiu    $v0, $zero, 2
glabel L80246C5C_17553C
/* 17553C 80246C5C 0000882D */  daddu     $s1, $zero, $zero
/* 175540 80246C60 3C05FFF7 */  lui       $a1, 0xfff7
/* 175544 80246C64 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 175548 80246C68 3C04F7FF */  lui       $a0, 0xf7ff
/* 17554C 80246C6C 3484FFFF */  ori       $a0, $a0, 0xffff
/* 175550 80246C70 02A0182D */  daddu     $v1, $s5, $zero
.L80246C74:
/* 175554 80246C74 8C7000E0 */  lw        $s0, 0xe0($v1)
/* 175558 80246C78 12000005 */  beqz      $s0, .L80246C90
/* 17555C 80246C7C 26310001 */   addiu    $s1, $s1, 1
/* 175560 80246C80 8E020000 */  lw        $v0, ($s0)
/* 175564 80246C84 00451024 */  and       $v0, $v0, $a1
/* 175568 80246C88 00441024 */  and       $v0, $v0, $a0
/* 17556C 80246C8C AE020000 */  sw        $v0, ($s0)
.L80246C90:
/* 175570 80246C90 2A220018 */  slti      $v0, $s1, 0x18
/* 175574 80246C94 1440FFF7 */  bnez      $v0, .L80246C74
/* 175578 80246C98 24630004 */   addiu    $v1, $v1, 4
/* 17557C 80246C9C 0C03A6D5 */  jal       increment_status_menu_disabled
/* 175580 80246CA0 00000000 */   nop
/* 175584 80246CA4 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 175588 80246CA8 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 17558C 80246CAC 8C620000 */  lw        $v0, ($v1)
/* 175590 80246CB0 34420100 */  ori       $v0, $v0, 0x100
/* 175594 80246CB4 0C098F18 */  jal       reset_actor_turn_info
/* 175598 80246CB8 AC620000 */   sw       $v0, ($v1)
/* 17559C 80246CBC 0C099EA7 */  jal       reset_all_actor_sounds
/* 1755A0 80246CC0 0280202D */   daddu    $a0, $s4, $zero
/* 1755A4 80246CC4 2405000A */  addiu     $a1, $zero, 0xa
/* 1755A8 80246CC8 A2A001A7 */  sb        $zero, 0x1a7($s5)
/* 1755AC 80246CCC 8E8401C4 */  lw        $a0, 0x1c4($s4)
/* 1755B0 80246CD0 0C0B0CF8 */  jal       start_script
/* 1755B4 80246CD4 0000302D */   daddu    $a2, $zero, $zero
/* 1755B8 80246CD8 AE8201D4 */  sw        $v0, 0x1d4($s4)
/* 1755BC 80246CDC 8C440144 */  lw        $a0, 0x144($v0)
/* 1755C0 80246CE0 24030003 */  addiu     $v1, $zero, 3
/* 1755C4 80246CE4 3C01800E */  lui       $at, %hi(gBattleState2)
/* 1755C8 80246CE8 AC23C4DC */  sw        $v1, %lo(gBattleState2)($at)
/* 1755CC 80246CEC 24030100 */  addiu     $v1, $zero, 0x100
/* 1755D0 80246CF0 AE8401E4 */  sw        $a0, 0x1e4($s4)
/* 1755D4 80246CF4 08091BFF */  j         L80246FFC_1758DC
/* 1755D8 80246CF8 AC430148 */   sw       $v1, 0x148($v0)
glabel L80246CFC_1755DC
/* 1755DC 80246CFC 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1755E0 80246D00 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1755E4 80246D04 3C030020 */  lui       $v1, 0x20
/* 1755E8 80246D08 00431024 */  and       $v0, $v0, $v1
/* 1755EC 80246D0C 1440000A */  bnez      $v0, .L80246D38
/* 1755F0 80246D10 00000000 */   nop
/* 1755F4 80246D14 8E8201D4 */  lw        $v0, 0x1d4($s4)
/* 1755F8 80246D18 50400007 */  beql      $v0, $zero, .L80246D38
/* 1755FC 80246D1C AE8001D4 */   sw       $zero, 0x1d4($s4)
/* 175600 80246D20 8E8401E4 */  lw        $a0, 0x1e4($s4)
/* 175604 80246D24 0C0B1059 */  jal       does_script_exist
/* 175608 80246D28 00000000 */   nop
/* 17560C 80246D2C 144000B3 */  bnez      $v0, L80246FFC_1758DC
/* 175610 80246D30 00000000 */   nop
/* 175614 80246D34 AE8001D4 */  sw        $zero, 0x1d4($s4)
.L80246D38:
/* 175618 80246D38 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 17561C 80246D3C 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 175620 80246D40 8C820000 */  lw        $v0, ($a0)
/* 175624 80246D44 2403FEFF */  addiu     $v1, $zero, -0x101
/* 175628 80246D48 00431024 */  and       $v0, $v0, $v1
/* 17562C 80246D4C AC820000 */  sw        $v0, ($a0)
/* 175630 80246D50 8E8201D8 */  lw        $v0, 0x1d8($s4)
/* 175634 80246D54 50400007 */  beql      $v0, $zero, .L80246D74
/* 175638 80246D58 AE8001D8 */   sw       $zero, 0x1d8($s4)
/* 17563C 80246D5C 8E8401E8 */  lw        $a0, 0x1e8($s4)
/* 175640 80246D60 0C0B1059 */  jal       does_script_exist
/* 175644 80246D64 00000000 */   nop
/* 175648 80246D68 144000A4 */  bnez      $v0, L80246FFC_1758DC
/* 17564C 80246D6C 00000000 */   nop
/* 175650 80246D70 AE8001D8 */  sw        $zero, 0x1d8($s4)
.L80246D74:
/* 175654 80246D74 8E4201D8 */  lw        $v0, 0x1d8($s2)
/* 175658 80246D78 50400007 */  beql      $v0, $zero, .L80246D98
/* 17565C 80246D7C AE4001D8 */   sw       $zero, 0x1d8($s2)
/* 175660 80246D80 8E4401E8 */  lw        $a0, 0x1e8($s2)
/* 175664 80246D84 0C0B1059 */  jal       does_script_exist
/* 175668 80246D88 00000000 */   nop
/* 17566C 80246D8C 1440009B */  bnez      $v0, L80246FFC_1758DC
/* 175670 80246D90 00000000 */   nop
/* 175674 80246D94 AE4001D8 */  sw        $zero, 0x1d8($s2)
.L80246D98:
/* 175678 80246D98 0000982D */  daddu     $s3, $zero, $zero
/* 17567C 80246D9C 0260882D */  daddu     $s1, $s3, $zero
/* 175680 80246DA0 02A0902D */  daddu     $s2, $s5, $zero
.L80246DA4:
/* 175684 80246DA4 8E5000E0 */  lw        $s0, 0xe0($s2)
/* 175688 80246DA8 5200000B */  beql      $s0, $zero, .L80246DD8
/* 17568C 80246DAC 26310001 */   addiu    $s1, $s1, 1
/* 175690 80246DB0 8E0201D4 */  lw        $v0, 0x1d4($s0)
/* 175694 80246DB4 50400008 */  beql      $v0, $zero, .L80246DD8
/* 175698 80246DB8 26310001 */   addiu    $s1, $s1, 1
/* 17569C 80246DBC 8E0401E4 */  lw        $a0, 0x1e4($s0)
/* 1756A0 80246DC0 0C0B1059 */  jal       does_script_exist
/* 1756A4 80246DC4 00000000 */   nop
/* 1756A8 80246DC8 50400002 */  beql      $v0, $zero, .L80246DD4
/* 1756AC 80246DCC AE0001D4 */   sw       $zero, 0x1d4($s0)
/* 1756B0 80246DD0 24130001 */  addiu     $s3, $zero, 1
.L80246DD4:
/* 1756B4 80246DD4 26310001 */  addiu     $s1, $s1, 1
.L80246DD8:
/* 1756B8 80246DD8 2A220018 */  slti      $v0, $s1, 0x18
/* 1756BC 80246DDC 1440FFF1 */  bnez      $v0, .L80246DA4
/* 1756C0 80246DE0 26520004 */   addiu    $s2, $s2, 4
/* 1756C4 80246DE4 16600085 */  bnez      $s3, L80246FFC_1758DC
/* 1756C8 80246DE8 0000882D */   daddu    $s1, $zero, $zero
/* 1756CC 80246DEC 02A0902D */  daddu     $s2, $s5, $zero
.L80246DF0:
/* 1756D0 80246DF0 8E5000E0 */  lw        $s0, 0xe0($s2)
/* 1756D4 80246DF4 5200000B */  beql      $s0, $zero, .L80246E24
/* 1756D8 80246DF8 26310001 */   addiu    $s1, $s1, 1
/* 1756DC 80246DFC 8E0201D8 */  lw        $v0, 0x1d8($s0)
/* 1756E0 80246E00 50400008 */  beql      $v0, $zero, .L80246E24
/* 1756E4 80246E04 26310001 */   addiu    $s1, $s1, 1
/* 1756E8 80246E08 8E0401E8 */  lw        $a0, 0x1e8($s0)
/* 1756EC 80246E0C 0C0B1059 */  jal       does_script_exist
/* 1756F0 80246E10 00000000 */   nop
/* 1756F4 80246E14 50400002 */  beql      $v0, $zero, .L80246E20
/* 1756F8 80246E18 AE0001D8 */   sw       $zero, 0x1d8($s0)
/* 1756FC 80246E1C 24130001 */  addiu     $s3, $zero, 1
.L80246E20:
/* 175700 80246E20 26310001 */  addiu     $s1, $s1, 1
.L80246E24:
/* 175704 80246E24 2A220018 */  slti      $v0, $s1, 0x18
/* 175708 80246E28 1440FFF1 */  bnez      $v0, .L80246DF0
/* 17570C 80246E2C 26520004 */   addiu    $s2, $s2, 4
/* 175710 80246E30 16600072 */  bnez      $s3, L80246FFC_1758DC
/* 175714 80246E34 0000882D */   daddu    $s1, $zero, $zero
/* 175718 80246E38 3C04FFF7 */  lui       $a0, 0xfff7
/* 17571C 80246E3C 3484FFFF */  ori       $a0, $a0, 0xffff
/* 175720 80246E40 02A0182D */  daddu     $v1, $s5, $zero
.L80246E44:
/* 175724 80246E44 8C7000E0 */  lw        $s0, 0xe0($v1)
/* 175728 80246E48 12000004 */  beqz      $s0, .L80246E5C
/* 17572C 80246E4C 26310001 */   addiu    $s1, $s1, 1
/* 175730 80246E50 8E020000 */  lw        $v0, ($s0)
/* 175734 80246E54 00441024 */  and       $v0, $v0, $a0
/* 175738 80246E58 AE020000 */  sw        $v0, ($s0)
.L80246E5C:
/* 17573C 80246E5C 2A220018 */  slti      $v0, $s1, 0x18
/* 175740 80246E60 1440FFF8 */  bnez      $v0, .L80246E44
/* 175744 80246E64 24630004 */   addiu    $v1, $v1, 4
/* 175748 80246E68 82A2008C */  lb        $v0, 0x8c($s5)
/* 17574C 80246E6C 14400063 */  bnez      $v0, L80246FFC_1758DC
/* 175750 80246E70 00000000 */   nop
/* 175754 80246E74 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 175758 80246E78 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 17575C 80246E7C 904200AA */  lbu       $v0, 0xaa($v0)
/* 175760 80246E80 30420001 */  andi      $v0, $v0, 1
/* 175764 80246E84 10400005 */  beqz      $v0, .L80246E9C
/* 175768 80246E88 00000000 */   nop
/* 17576C 80246E8C 0C090464 */  jal       btl_set_state
/* 175770 80246E90 24040023 */   addiu    $a0, $zero, 0x23
/* 175774 80246E94 08091BFF */  j         L80246FFC_1758DC
/* 175778 80246E98 00000000 */   nop
.L80246E9C:
/* 17577C 80246E9C 0C03A6CC */  jal       decrement_status_menu_disabled
/* 175780 80246EA0 00000000 */   nop
/* 175784 80246EA4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 175788 80246EA8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 17578C 80246EAC 80430012 */  lb        $v1, 0x12($v0)
/* 175790 80246EB0 24020001 */  addiu     $v0, $zero, 1
/* 175794 80246EB4 1462000E */  bne       $v1, $v0, .L80246EF0
/* 175798 80246EB8 24020005 */   addiu    $v0, $zero, 5
/* 17579C 80246EBC 82A30178 */  lb        $v1, 0x178($s5)
/* 1757A0 80246EC0 1462000B */  bne       $v1, $v0, .L80246EF0
/* 1757A4 80246EC4 24020087 */   addiu    $v0, $zero, 0x87
/* 1757A8 80246EC8 86A3017C */  lh        $v1, 0x17c($s5)
/* 1757AC 80246ECC 10620008 */  beq       $v1, $v0, .L80246EF0
/* 1757B0 80246ED0 3C04BFFF */   lui      $a0, 0xbfff
/* 1757B4 80246ED4 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1757B8 80246ED8 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1757BC 80246EDC A2800220 */  sb        $zero, 0x220($s4)
/* 1757C0 80246EE0 8C620000 */  lw        $v0, ($v1)
/* 1757C4 80246EE4 3484FFFF */  ori       $a0, $a0, 0xffff
/* 1757C8 80246EE8 00441024 */  and       $v0, $v0, $a0
/* 1757CC 80246EEC AC620000 */  sw        $v0, ($v1)
.L80246EF0:
/* 1757D0 80246EF0 0C098D19 */  jal       btl_check_player_defeated
/* 1757D4 80246EF4 00000000 */   nop
/* 1757D8 80246EF8 144000BD */  bnez      $v0, .L802471F0
/* 1757DC 80246EFC 0000882D */   daddu    $s1, $zero, $zero
/* 1757E0 80246F00 3C060040 */  lui       $a2, 0x40
/* 1757E4 80246F04 3C050C00 */  lui       $a1, 0xc00
/* 1757E8 80246F08 02A0202D */  daddu     $a0, $s5, $zero
.L80246F0C:
/* 1757EC 80246F0C 8C9000E0 */  lw        $s0, 0xe0($a0)
/* 1757F0 80246F10 12000007 */  beqz      $s0, .L80246F30
/* 1757F4 80246F14 26310001 */   addiu    $s1, $s1, 1
/* 1757F8 80246F18 8E030000 */  lw        $v1, ($s0)
/* 1757FC 80246F1C 00661024 */  and       $v0, $v1, $a2
/* 175800 80246F20 14400003 */  bnez      $v0, .L80246F30
/* 175804 80246F24 00000000 */   nop
/* 175808 80246F28 00651025 */  or        $v0, $v1, $a1
/* 17580C 80246F2C AE020000 */  sw        $v0, ($s0)
.L80246F30:
/* 175810 80246F30 2A220018 */  slti      $v0, $s1, 0x18
/* 175814 80246F34 1440FFF5 */  bnez      $v0, .L80246F0C
/* 175818 80246F38 24840004 */   addiu    $a0, $a0, 4
/* 17581C 80246F3C 0C099DDF */  jal       btl_update_ko_status
/* 175820 80246F40 00000000 */   nop
/* 175824 80246F44 8283021C */  lb        $v1, 0x21c($s4)
/* 175828 80246F48 2402000D */  addiu     $v0, $zero, 0xd
/* 17582C 80246F4C 14620029 */  bne       $v1, $v0, .L80246FF4
/* 175830 80246F50 24020014 */   addiu    $v0, $zero, 0x14
/* 175834 80246F54 0C098CFA */  jal       btl_are_all_enemies_defeated
/* 175838 80246F58 00000000 */   nop
/* 17583C 80246F5C 14400025 */  bnez      $v0, .L80246FF4
/* 175840 80246F60 24020014 */   addiu    $v0, $zero, 0x14
/* 175844 80246F64 0C093903 */  jal       func_8024E40C
/* 175848 80246F68 24040036 */   addiu    $a0, $zero, 0x36
/* 17584C 80246F6C 24040023 */  addiu     $a0, $zero, 0x23
/* 175850 80246F70 0C093E58 */  jal       btl_show_battle_message
/* 175854 80246F74 2405003C */   addiu    $a1, $zero, 0x3c
/* 175858 80246F78 2402000B */  addiu     $v0, $zero, 0xb
/* 17585C 80246F7C A280021C */  sb        $zero, 0x21c($s4)
/* 175860 80246F80 A280021D */  sb        $zero, 0x21d($s4)
/* 175864 80246F84 3C01800E */  lui       $at, %hi(gBattleState2)
/* 175868 80246F88 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 17586C 80246F8C 8E820000 */  lw        $v0, ($s4)
/* 175870 80246F90 3C030800 */  lui       $v1, 0x800
/* 175874 80246F94 00431025 */  or        $v0, $v0, $v1
/* 175878 80246F98 08091BFF */  j         L80246FFC_1758DC
/* 17587C 80246F9C AE820000 */   sw       $v0, ($s4)
glabel L80246FA0_175880
/* 175880 80246FA0 0C093EAD */  jal       btl_is_popup_displayed
/* 175884 80246FA4 00000000 */   nop
/* 175888 80246FA8 14400014 */  bnez      $v0, L80246FFC_1758DC
/* 17588C 80246FAC 00000000 */   nop
/* 175890 80246FB0 0C093903 */  jal       func_8024E40C
/* 175894 80246FB4 24040002 */   addiu    $a0, $zero, 2
/* 175898 80246FB8 0C093936 */  jal       btl_cam_move
/* 17589C 80246FBC 2404000F */   addiu    $a0, $zero, 0xf
/* 1758A0 80246FC0 2402000A */  addiu     $v0, $zero, 0xa
/* 1758A4 80246FC4 3C01802A */  lui       $at, %hi(D_8029F248)
/* 1758A8 80246FC8 AC22F248 */  sw        $v0, %lo(D_8029F248)($at)
/* 1758AC 80246FCC 08091BFD */  j         .L80246FF4
/* 1758B0 80246FD0 2402000C */   addiu    $v0, $zero, 0xc
glabel L80246FD4_1758B4
/* 1758B4 80246FD4 3C03802A */  lui       $v1, %hi(D_8029F248)
/* 1758B8 80246FD8 2463F248 */  addiu     $v1, $v1, %lo(D_8029F248)
/* 1758BC 80246FDC 8C620000 */  lw        $v0, ($v1)
/* 1758C0 80246FE0 10400003 */  beqz      $v0, .L80246FF0
/* 1758C4 80246FE4 2442FFFF */   addiu    $v0, $v0, -1
/* 1758C8 80246FE8 08091BFF */  j         L80246FFC_1758DC
/* 1758CC 80246FEC AC620000 */   sw       $v0, ($v1)
.L80246FF0:
/* 1758D0 80246FF0 24020014 */  addiu     $v0, $zero, 0x14
.L80246FF4:
/* 1758D4 80246FF4 3C01800E */  lui       $at, %hi(gBattleState2)
/* 1758D8 80246FF8 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
glabel L80246FFC_1758DC
/* 1758DC 80246FFC 3C10800E */  lui       $s0, %hi(gBattleState2)
/* 1758E0 80247000 2610C4DC */  addiu     $s0, $s0, %lo(gBattleState2)
/* 1758E4 80247004 8E030000 */  lw        $v1, ($s0)
/* 1758E8 80247008 24020015 */  addiu     $v0, $zero, 0x15
/* 1758EC 8024700C 10620052 */  beq       $v1, $v0, .L80247158
/* 1758F0 80247010 28620016 */   slti     $v0, $v1, 0x16
/* 1758F4 80247014 10400005 */  beqz      $v0, .L8024702C
/* 1758F8 80247018 24020014 */   addiu    $v0, $zero, 0x14
/* 1758FC 8024701C 10620008 */  beq       $v1, $v0, .L80247040
/* 175900 80247020 0000982D */   daddu    $s3, $zero, $zero
/* 175904 80247024 08091C6C */  j         .L802471B0
/* 175908 80247028 00000000 */   nop
.L8024702C:
/* 17590C 8024702C 24020016 */  addiu     $v0, $zero, 0x16
/* 175910 80247030 10620056 */  beq       $v1, $v0, .L8024718C
/* 175914 80247034 00000000 */   nop
/* 175918 80247038 08091C6C */  j         .L802471B0
/* 17591C 8024703C 00000000 */   nop
.L80247040:
/* 175920 80247040 0260882D */  daddu     $s1, $s3, $zero
/* 175924 80247044 02A0182D */  daddu     $v1, $s5, $zero
.L80247048:
/* 175928 80247048 8C7000E0 */  lw        $s0, 0xe0($v1)
/* 17592C 8024704C 12000004 */  beqz      $s0, .L80247060
/* 175930 80247050 26310001 */   addiu    $s1, $s1, 1
/* 175934 80247054 8202021C */  lb        $v0, 0x21c($s0)
/* 175938 80247058 54400004 */  bnel      $v0, $zero, .L8024706C
/* 17593C 8024705C 24130001 */   addiu    $s3, $zero, 1
.L80247060:
/* 175940 80247060 2A220018 */  slti      $v0, $s1, 0x18
/* 175944 80247064 1440FFF8 */  bnez      $v0, .L80247048
/* 175948 80247068 24630004 */   addiu    $v1, $v1, 4
.L8024706C:
/* 17594C 8024706C 16600005 */  bnez      $s3, .L80247084
/* 175950 80247070 2402001E */   addiu    $v0, $zero, 0x1e
/* 175954 80247074 3C01800E */  lui       $at, %hi(gBattleState2)
/* 175958 80247078 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 17595C 8024707C 08091C6C */  j         .L802471B0
/* 175960 80247080 00000000 */   nop
.L80247084:
/* 175964 80247084 0C093903 */  jal       func_8024E40C
/* 175968 80247088 24040003 */   addiu    $a0, $zero, 3
/* 17596C 8024708C 9202021C */  lbu       $v0, 0x21c($s0)
/* 175970 80247090 2442FFFC */  addiu     $v0, $v0, -4
/* 175974 80247094 00021600 */  sll       $v0, $v0, 0x18
/* 175978 80247098 00021E03 */  sra       $v1, $v0, 0x18
/* 17597C 8024709C 2C620008 */  sltiu     $v0, $v1, 8
/* 175980 802470A0 10400016 */  beqz      $v0, .L802470FC
/* 175984 802470A4 00031080 */   sll      $v0, $v1, 2
/* 175988 802470A8 3C01802A */  lui       $at, %hi(jtbl_8029CB68)
/* 17598C 802470AC 00220821 */  addu      $at, $at, $v0
/* 175990 802470B0 8C22CB68 */  lw        $v0, %lo(jtbl_8029CB68)($at)
/* 175994 802470B4 00400008 */  jr        $v0
/* 175998 802470B8 00000000 */   nop
glabel L802470BC_17599C
/* 17599C 802470BC 08091C43 */  j         .L8024710C
/* 1759A0 802470C0 24100012 */   addiu    $s0, $zero, 0x12
glabel L802470C4_1759A4
/* 1759A4 802470C4 08091C43 */  j         .L8024710C
/* 1759A8 802470C8 24100013 */   addiu    $s0, $zero, 0x13
glabel L802470CC_1759AC
/* 1759AC 802470CC 08091C43 */  j         .L8024710C
/* 1759B0 802470D0 24100014 */   addiu    $s0, $zero, 0x14
glabel L802470D4_1759B4
/* 1759B4 802470D4 08091C43 */  j         .L8024710C
/* 1759B8 802470D8 24100015 */   addiu    $s0, $zero, 0x15
glabel L802470DC_1759BC
/* 1759BC 802470DC 08091C43 */  j         .L8024710C
/* 1759C0 802470E0 24100016 */   addiu    $s0, $zero, 0x16
glabel L802470E4_1759C4
/* 1759C4 802470E4 08091C43 */  j         .L8024710C
/* 1759C8 802470E8 24100017 */   addiu    $s0, $zero, 0x17
glabel L802470EC_1759CC
/* 1759CC 802470EC 08091C43 */  j         .L8024710C
/* 1759D0 802470F0 24100018 */   addiu    $s0, $zero, 0x18
glabel L802470F4_1759D4
/* 1759D4 802470F4 08091C43 */  j         .L8024710C
/* 1759D8 802470F8 24100019 */   addiu    $s0, $zero, 0x19
.L802470FC:
/* 1759DC 802470FC 0000802D */  daddu     $s0, $zero, $zero
/* 1759E0 80247100 24020014 */  addiu     $v0, $zero, 0x14
/* 1759E4 80247104 3C01800E */  lui       $at, %hi(gBattleState2)
/* 1759E8 80247108 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L8024710C:
/* 1759EC 8024710C 0C05272D */  jal       sfx_play_sound
/* 1759F0 80247110 24042107 */   addiu    $a0, $zero, 0x2107
/* 1759F4 80247114 0200202D */  daddu     $a0, $s0, $zero
/* 1759F8 80247118 0C093E58 */  jal       btl_show_battle_message
/* 1759FC 8024711C 2405003C */   addiu    $a1, $zero, 0x3c
/* 175A00 80247120 0000882D */  daddu     $s1, $zero, $zero
/* 175A04 80247124 02A0182D */  daddu     $v1, $s5, $zero
.L80247128:
/* 175A08 80247128 8C7000E0 */  lw        $s0, 0xe0($v1)
/* 175A0C 8024712C 56000001 */  bnel      $s0, $zero, .L80247134
/* 175A10 80247130 A200021C */   sb       $zero, 0x21c($s0)
.L80247134:
/* 175A14 80247134 26310001 */  addiu     $s1, $s1, 1
/* 175A18 80247138 2A220018 */  slti      $v0, $s1, 0x18
/* 175A1C 8024713C 1440FFFA */  bnez      $v0, .L80247128
/* 175A20 80247140 24630004 */   addiu    $v1, $v1, 4
/* 175A24 80247144 24020015 */  addiu     $v0, $zero, 0x15
/* 175A28 80247148 3C01800E */  lui       $at, %hi(gBattleState2)
/* 175A2C 8024714C AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 175A30 80247150 08091C6C */  j         .L802471B0
/* 175A34 80247154 00000000 */   nop
.L80247158:
/* 175A38 80247158 0C093EAD */  jal       btl_is_popup_displayed
/* 175A3C 8024715C 00000000 */   nop
/* 175A40 80247160 14400013 */  bnez      $v0, .L802471B0
/* 175A44 80247164 00000000 */   nop
/* 175A48 80247168 0C093903 */  jal       func_8024E40C
/* 175A4C 8024716C 24040002 */   addiu    $a0, $zero, 2
/* 175A50 80247170 0C093936 */  jal       btl_cam_move
/* 175A54 80247174 2404000F */   addiu    $a0, $zero, 0xf
/* 175A58 80247178 2402000A */  addiu     $v0, $zero, 0xa
/* 175A5C 8024717C 3C01802A */  lui       $at, %hi(D_8029F248)
/* 175A60 80247180 AC22F248 */  sw        $v0, %lo(D_8029F248)($at)
/* 175A64 80247184 08091C6B */  j         .L802471AC
/* 175A68 80247188 24020016 */   addiu    $v0, $zero, 0x16
.L8024718C:
/* 175A6C 8024718C 3C03802A */  lui       $v1, %hi(D_8029F248)
/* 175A70 80247190 2463F248 */  addiu     $v1, $v1, %lo(D_8029F248)
/* 175A74 80247194 8C620000 */  lw        $v0, ($v1)
/* 175A78 80247198 10400003 */  beqz      $v0, .L802471A8
/* 175A7C 8024719C 2442FFFF */   addiu    $v0, $v0, -1
/* 175A80 802471A0 08091C6C */  j         .L802471B0
/* 175A84 802471A4 AC620000 */   sw       $v0, ($v1)
.L802471A8:
/* 175A88 802471A8 2402001E */  addiu     $v0, $zero, 0x1e
.L802471AC:
/* 175A8C 802471AC AE020000 */  sw        $v0, ($s0)
.L802471B0:
/* 175A90 802471B0 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 175A94 802471B4 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 175A98 802471B8 2402001E */  addiu     $v0, $zero, 0x1e
/* 175A9C 802471BC 1462000C */  bne       $v1, $v0, .L802471F0
/* 175AA0 802471C0 00000000 */   nop
/* 175AA4 802471C4 8E8201D4 */  lw        $v0, 0x1d4($s4)
/* 175AA8 802471C8 50400007 */  beql      $v0, $zero, .L802471E8
/* 175AAC 802471CC AE8001D4 */   sw       $zero, 0x1d4($s4)
/* 175AB0 802471D0 8E8401E4 */  lw        $a0, 0x1e4($s4)
/* 175AB4 802471D4 0C0B1059 */  jal       does_script_exist
/* 175AB8 802471D8 00000000 */   nop
/* 175ABC 802471DC 14400004 */  bnez      $v0, .L802471F0
/* 175AC0 802471E0 00000000 */   nop
/* 175AC4 802471E4 AE8001D4 */  sw        $zero, 0x1d4($s4)
.L802471E8:
/* 175AC8 802471E8 0C090464 */  jal       btl_set_state
/* 175ACC 802471EC 24040017 */   addiu    $a0, $zero, 0x17
.L802471F0:
/* 175AD0 802471F0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 175AD4 802471F4 8FB50024 */  lw        $s5, 0x24($sp)
/* 175AD8 802471F8 8FB40020 */  lw        $s4, 0x20($sp)
/* 175ADC 802471FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 175AE0 80247200 8FB20018 */  lw        $s2, 0x18($sp)
/* 175AE4 80247204 8FB10014 */  lw        $s1, 0x14($sp)
/* 175AE8 80247208 8FB00010 */  lw        $s0, 0x10($sp)
/* 175AEC 8024720C 03E00008 */  jr        $ra
/* 175AF0 80247210 27BD0030 */   addiu    $sp, $sp, 0x30

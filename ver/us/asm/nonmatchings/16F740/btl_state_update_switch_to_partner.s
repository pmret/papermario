.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_update_switch_to_partner
/* 1717E0 80242F00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1717E4 80242F04 AFB00010 */  sw        $s0, 0x10($sp)
/* 1717E8 80242F08 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 1717EC 80242F0C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 1717F0 80242F10 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1717F4 80242F14 AFB20018 */  sw        $s2, 0x18($sp)
/* 1717F8 80242F18 AFB10014 */  sw        $s1, 0x14($sp)
/* 1717FC 80242F1C 8E1100D8 */  lw        $s1, 0xd8($s0)
/* 171800 80242F20 3C02800E */  lui       $v0, %hi(gBattleState2)
/* 171804 80242F24 8C42C4DC */  lw        $v0, %lo(gBattleState2)($v0)
/* 171808 80242F28 14400025 */  bnez      $v0, .L80242FC0
/* 17180C 80242F2C 8E1200DC */   lw       $s2, 0xdc($s0)
/* 171810 80242F30 0C098F18 */  jal       reset_actor_turn_info
/* 171814 80242F34 00000000 */   nop
/* 171818 80242F38 0000282D */  daddu     $a1, $zero, $zero
/* 17181C 80242F3C 3C070008 */  lui       $a3, 8
/* 171820 80242F40 3C060800 */  lui       $a2, 0x800
/* 171824 80242F44 0200202D */  daddu     $a0, $s0, $zero
/* 171828 80242F48 2402007F */  addiu     $v0, $zero, 0x7f
/* 17182C 80242F4C A0820086 */  sb        $v0, 0x86($a0)
/* 171830 80242F50 A0820087 */  sb        $v0, 0x87($a0)
/* 171834 80242F54 8C820000 */  lw        $v0, ($a0)
/* 171838 80242F58 00E0182D */  daddu     $v1, $a3, $zero
/* 17183C 80242F5C A480017C */  sh        $zero, 0x17c($a0)
/* 171840 80242F60 00431025 */  or        $v0, $v0, $v1
/* 171844 80242F64 AC820000 */  sw        $v0, ($a0)
/* 171848 80242F68 34420008 */  ori       $v0, $v0, 8
/* 17184C 80242F6C AC820000 */  sw        $v0, ($a0)
/* 171850 80242F70 8E220000 */  lw        $v0, ($s1)
/* 171854 80242F74 3C030C00 */  lui       $v1, 0xc00
/* 171858 80242F78 00431025 */  or        $v0, $v0, $v1
/* 17185C 80242F7C AE220000 */  sw        $v0, ($s1)
/* 171860 80242F80 8E420000 */  lw        $v0, ($s2)
/* 171864 80242F84 00C0182D */  daddu     $v1, $a2, $zero
/* 171868 80242F88 00461025 */  or        $v0, $v0, $a2
/* 17186C 80242F8C AE420000 */  sw        $v0, ($s2)
.L80242F90:
/* 171870 80242F90 8C8300E0 */  lw        $v1, 0xe0($a0)
/* 171874 80242F94 10600005 */  beqz      $v1, .L80242FAC
/* 171878 80242F98 24A50001 */   addiu    $a1, $a1, 1
/* 17187C 80242F9C 8C620000 */  lw        $v0, ($v1)
/* 171880 80242FA0 00471025 */  or        $v0, $v0, $a3
/* 171884 80242FA4 00461025 */  or        $v0, $v0, $a2
/* 171888 80242FA8 AC620000 */  sw        $v0, ($v1)
.L80242FAC:
/* 17188C 80242FAC 28A20018 */  slti      $v0, $a1, 0x18
/* 171890 80242FB0 1440FFF7 */  bnez      $v0, .L80242F90
/* 171894 80242FB4 24840004 */   addiu    $a0, $a0, 4
/* 171898 80242FB8 0C090464 */  jal       btl_set_state
/* 17189C 80242FBC 2404000C */   addiu    $a0, $zero, 0xc
.L80242FC0:
/* 1718A0 80242FC0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1718A4 80242FC4 8FB20018 */  lw        $s2, 0x18($sp)
/* 1718A8 80242FC8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1718AC 80242FCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1718B0 80242FD0 03E00008 */  jr        $ra
/* 1718B4 80242FD4 27BD0020 */   addiu    $sp, $sp, 0x20

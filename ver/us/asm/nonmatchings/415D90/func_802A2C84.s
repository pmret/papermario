.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_802AB808
.word L802A38AC_41863C, L802A3718_4184A8, L802A2CE4_417A74, L802A3490_418220, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A38DC_41866C, L802A3974_418704, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A399C_41872C, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3A20_4187B0, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3C6C_4189FC, L802A3A78_418808, L802A3A9C_41882C, L802A3BC0_418950, 0

.section .text

glabel func_802A2C84
/* 417A14 802A2C84 3C02802B */  lui       $v0, %hi(battle_menu_moveState)
/* 417A18 802A2C88 9042D108 */  lbu       $v0, %lo(battle_menu_moveState)($v0)
/* 417A1C 802A2C8C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 417A20 802A2C90 AFB1002C */  sw        $s1, 0x2c($sp)
/* 417A24 802A2C94 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 417A28 802A2C98 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 417A2C 802A2C9C AFBF0044 */  sw        $ra, 0x44($sp)
/* 417A30 802A2CA0 AFB60040 */  sw        $s6, 0x40($sp)
/* 417A34 802A2CA4 AFB5003C */  sw        $s5, 0x3c($sp)
/* 417A38 802A2CA8 AFB40038 */  sw        $s4, 0x38($sp)
/* 417A3C 802A2CAC AFB30034 */  sw        $s3, 0x34($sp)
/* 417A40 802A2CB0 AFB20030 */  sw        $s2, 0x30($sp)
/* 417A44 802A2CB4 24420002 */  addiu     $v0, $v0, 2
/* 417A48 802A2CB8 00021600 */  sll       $v0, $v0, 0x18
/* 417A4C 802A2CBC 00021E03 */  sra       $v1, $v0, 0x18
/* 417A50 802A2CC0 2C62002D */  sltiu     $v0, $v1, 0x2d
/* 417A54 802A2CC4 104003E9 */  beqz      $v0, L802A3C6C_4189FC
/* 417A58 802A2CC8 AFB00028 */   sw       $s0, 0x28($sp)
/* 417A5C 802A2CCC 00031080 */  sll       $v0, $v1, 2
/* 417A60 802A2CD0 3C01802B */  lui       $at, %hi(jtbl_802AB808)
/* 417A64 802A2CD4 00220821 */  addu      $at, $at, $v0
/* 417A68 802A2CD8 8C22B808 */  lw        $v0, %lo(jtbl_802AB808)($at)
/* 417A6C 802A2CDC 00400008 */  jr        $v0
/* 417A70 802A2CE0 00000000 */   nop
dlabel L802A2CE4_417A74
/* 417A74 802A2CE4 3C05802B */  lui       $a1, %hi(battle_menu_moveScrollLine)
/* 417A78 802A2CE8 80A5D10C */  lb        $a1, %lo(battle_menu_moveScrollLine)($a1)
/* 417A7C 802A2CEC 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorPos)
/* 417A80 802A2CF0 8084D109 */  lb        $a0, %lo(battle_menu_moveCursorPos)($a0)
/* 417A84 802A2CF4 24020014 */  addiu     $v0, $zero, 0x14
/* 417A88 802A2CF8 3C01802B */  lui       $at, %hi(battle_menu_moveX)
/* 417A8C 802A2CFC A422D1F0 */  sh        $v0, %lo(battle_menu_moveX)($at)
/* 417A90 802A2D00 24020044 */  addiu     $v0, $zero, 0x44
/* 417A94 802A2D04 3C01802B */  lui       $at, %hi(battle_menu_moveY)
/* 417A98 802A2D08 A422D1F2 */  sh        $v0, %lo(battle_menu_moveY)($at)
/* 417A9C 802A2D0C 00051823 */  negu      $v1, $a1
/* 417AA0 802A2D10 00031040 */  sll       $v0, $v1, 1
/* 417AA4 802A2D14 00431021 */  addu      $v0, $v0, $v1
/* 417AA8 802A2D18 00021080 */  sll       $v0, $v0, 2
/* 417AAC 802A2D1C 00431021 */  addu      $v0, $v0, $v1
/* 417AB0 802A2D20 00852023 */  subu      $a0, $a0, $a1
/* 417AB4 802A2D24 3C01802B */  lui       $at, %hi(battle_menu_moveScrollOffset)
/* 417AB8 802A2D28 A422D110 */  sh        $v0, %lo(battle_menu_moveScrollOffset)($at)
/* 417ABC 802A2D2C 00041040 */  sll       $v0, $a0, 1
/* 417AC0 802A2D30 00441021 */  addu      $v0, $v0, $a0
/* 417AC4 802A2D34 00021080 */  sll       $v0, $v0, 2
/* 417AC8 802A2D38 3C05802B */  lui       $a1, %hi(battle_menu_moveOptionCount)
/* 417ACC 802A2D3C 24A5D4A4 */  addiu     $a1, $a1, %lo(battle_menu_moveOptionCount)
/* 417AD0 802A2D40 8CA30000 */  lw        $v1, ($a1)
/* 417AD4 802A2D44 00441021 */  addu      $v0, $v0, $a0
/* 417AD8 802A2D48 3C01802B */  lui       $at, %hi(D_802AD112)
/* 417ADC 802A2D4C A422D112 */  sh        $v0, %lo(D_802AD112)($at)
/* 417AE0 802A2D50 18600009 */  blez      $v1, .L802A2D78
/* 417AE4 802A2D54 0000802D */   daddu    $s0, $zero, $zero
/* 417AE8 802A2D58 3C03802B */  lui       $v1, %hi(battle_menu_moveOptionIndexMap)
/* 417AEC 802A2D5C 2463D1F8 */  addiu     $v1, $v1, %lo(battle_menu_moveOptionIndexMap)
.L802A2D60:
/* 417AF0 802A2D60 AC700000 */  sw        $s0, ($v1)
/* 417AF4 802A2D64 8CA20000 */  lw        $v0, ($a1)
/* 417AF8 802A2D68 26100001 */  addiu     $s0, $s0, 1
/* 417AFC 802A2D6C 0202102A */  slt       $v0, $s0, $v0
/* 417B00 802A2D70 1440FFFB */  bnez      $v0, .L802A2D60
/* 417B04 802A2D74 24630004 */   addiu    $v1, $v1, 4
.L802A2D78:
/* 417B08 802A2D78 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 417B0C 802A2D7C 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 417B10 802A2D80 14400042 */  bnez      $v0, .L802A2E8C
/* 417B14 802A2D84 00000000 */   nop
/* 417B18 802A2D88 3C03802B */  lui       $v1, %hi(battle_menu_moveOptionCount)
/* 417B1C 802A2D8C 8C63D4A4 */  lw        $v1, %lo(battle_menu_moveOptionCount)($v1)
/* 417B20 802A2D90 2462FFFF */  addiu     $v0, $v1, -1
/* 417B24 802A2D94 1840003D */  blez      $v0, .L802A2E8C
/* 417B28 802A2D98 0000802D */   daddu    $s0, $zero, $zero
/* 417B2C 802A2D9C 0060882D */  daddu     $s1, $v1, $zero
/* 417B30 802A2DA0 3C0E802B */  lui       $t6, %hi(battle_menu_moveOptionSortPriorities)
/* 417B34 802A2DA4 25CED5D0 */  addiu     $t6, $t6, %lo(battle_menu_moveOptionSortPriorities)
/* 417B38 802A2DA8 3C0D802B */  lui       $t5, %hi(battle_menu_moveOptionDisplayCosts)
/* 417B3C 802A2DAC 25ADD320 */  addiu     $t5, $t5, %lo(battle_menu_moveOptionDisplayCosts)
/* 417B40 802A2DB0 3C0C802B */  lui       $t4, %hi(battle_menu_moveOptionBPCosts)
/* 417B44 802A2DB4 258CD440 */  addiu     $t4, $t4, %lo(battle_menu_moveOptionBPCosts)
/* 417B48 802A2DB8 3C0F802B */  lui       $t7, %hi(battle_menu_moveOptionIndexMap)
/* 417B4C 802A2DBC 25EFD1F8 */  addiu     $t7, $t7, %lo(battle_menu_moveOptionIndexMap)
/* 417B50 802A2DC0 01E0502D */  daddu     $t2, $t7, $zero
.L802A2DC4:
/* 417B54 802A2DC4 26090001 */  addiu     $t1, $s0, 1
/* 417B58 802A2DC8 0131102A */  slt       $v0, $t1, $s1
/* 417B5C 802A2DCC 10400028 */  beqz      $v0, .L802A2E70
/* 417B60 802A2DD0 00091080 */   sll      $v0, $t1, 2
/* 417B64 802A2DD4 0140402D */  daddu     $t0, $t2, $zero
/* 417B68 802A2DD8 3C0B802B */  lui       $t3, %hi(battle_menu_moveOptionCount)
/* 417B6C 802A2DDC 8D6BD4A4 */  lw        $t3, %lo(battle_menu_moveOptionCount)($t3)
/* 417B70 802A2DE0 004F3821 */  addu      $a3, $v0, $t7
.L802A2DE4:
/* 417B74 802A2DE4 8D060000 */  lw        $a2, ($t0)
/* 417B78 802A2DE8 8CE40000 */  lw        $a0, ($a3)
/* 417B7C 802A2DEC 00CE1021 */  addu      $v0, $a2, $t6
/* 417B80 802A2DF0 008E1821 */  addu      $v1, $a0, $t6
/* 417B84 802A2DF4 80450000 */  lb        $a1, ($v0)
/* 417B88 802A2DF8 80630000 */  lb        $v1, ($v1)
/* 417B8C 802A2DFC 00A3102A */  slt       $v0, $a1, $v1
/* 417B90 802A2E00 54400018 */  bnel      $v0, $zero, .L802A2E64
/* 417B94 802A2E04 25290001 */   addiu    $t1, $t1, 1
/* 417B98 802A2E08 14A30011 */  bne       $a1, $v1, .L802A2E50
/* 417B9C 802A2E0C 00063080 */   sll      $a2, $a2, 2
/* 417BA0 802A2E10 00CD1821 */  addu      $v1, $a2, $t5
/* 417BA4 802A2E14 00042080 */  sll       $a0, $a0, 2
/* 417BA8 802A2E18 008D1021 */  addu      $v0, $a0, $t5
/* 417BAC 802A2E1C 8C630000 */  lw        $v1, ($v1)
/* 417BB0 802A2E20 8C450000 */  lw        $a1, ($v0)
/* 417BB4 802A2E24 0065102A */  slt       $v0, $v1, $a1
/* 417BB8 802A2E28 5440000E */  bnel      $v0, $zero, .L802A2E64
/* 417BBC 802A2E2C 25290001 */   addiu    $t1, $t1, 1
/* 417BC0 802A2E30 14650007 */  bne       $v1, $a1, .L802A2E50
/* 417BC4 802A2E34 00CC1021 */   addu     $v0, $a2, $t4
/* 417BC8 802A2E38 008C2021 */  addu      $a0, $a0, $t4
/* 417BCC 802A2E3C 8C430000 */  lw        $v1, ($v0)
/* 417BD0 802A2E40 8C820000 */  lw        $v0, ($a0)
/* 417BD4 802A2E44 0062182A */  slt       $v1, $v1, $v0
/* 417BD8 802A2E48 54600006 */  bnel      $v1, $zero, .L802A2E64
/* 417BDC 802A2E4C 25290001 */   addiu    $t1, $t1, 1
.L802A2E50:
/* 417BE0 802A2E50 8CE20000 */  lw        $v0, ($a3)
/* 417BE4 802A2E54 8D030000 */  lw        $v1, ($t0)
/* 417BE8 802A2E58 AD020000 */  sw        $v0, ($t0)
/* 417BEC 802A2E5C ACE30000 */  sw        $v1, ($a3)
/* 417BF0 802A2E60 25290001 */  addiu     $t1, $t1, 1
.L802A2E64:
/* 417BF4 802A2E64 012B102A */  slt       $v0, $t1, $t3
/* 417BF8 802A2E68 1440FFDE */  bnez      $v0, .L802A2DE4
/* 417BFC 802A2E6C 24E70004 */   addiu    $a3, $a3, 4
.L802A2E70:
/* 417C00 802A2E70 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 417C04 802A2E74 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 417C08 802A2E78 26100001 */  addiu     $s0, $s0, 1
/* 417C0C 802A2E7C 2442FFFF */  addiu     $v0, $v0, -1
/* 417C10 802A2E80 0202102A */  slt       $v0, $s0, $v0
/* 417C14 802A2E84 1440FFCF */  bnez      $v0, .L802A2DC4
/* 417C18 802A2E88 254A0004 */   addiu    $t2, $t2, 4
.L802A2E8C:
/* 417C1C 802A2E8C 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 417C20 802A2E90 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 417C24 802A2E94 1840001C */  blez      $v0, .L802A2F08
/* 417C28 802A2E98 0000802D */   daddu    $s0, $zero, $zero
/* 417C2C 802A2E9C 3C14802B */  lui       $s4, %hi(battle_menu_moveOptionIconScripts)
/* 417C30 802A2EA0 2694D260 */  addiu     $s4, $s4, %lo(battle_menu_moveOptionIconScripts)
/* 417C34 802A2EA4 3C13802B */  lui       $s3, %hi(battle_menu_moveOptionIconIDs)
/* 417C38 802A2EA8 2673D128 */  addiu     $s3, $s3, %lo(battle_menu_moveOptionIconIDs)
/* 417C3C 802A2EAC 3C11802B */  lui       $s1, %hi(battle_menu_moveOptionIndexMap)
/* 417C40 802A2EB0 2631D1F8 */  addiu     $s1, $s1, %lo(battle_menu_moveOptionIndexMap)
.L802A2EB4:
/* 417C44 802A2EB4 8E220000 */  lw        $v0, ($s1)
/* 417C48 802A2EB8 26310004 */  addiu     $s1, $s1, 4
/* 417C4C 802A2EBC 00021080 */  sll       $v0, $v0, 2
/* 417C50 802A2EC0 00541021 */  addu      $v0, $v0, $s4
/* 417C54 802A2EC4 8C440000 */  lw        $a0, ($v0)
/* 417C58 802A2EC8 0C050529 */  jal       create_hud_element
/* 417C5C 802A2ECC 26100001 */   addiu    $s0, $s0, 1
/* 417C60 802A2ED0 0040902D */  daddu     $s2, $v0, $zero
/* 417C64 802A2ED4 3C053EE6 */  lui       $a1, 0x3ee6
/* 417C68 802A2ED8 34A56666 */  ori       $a1, $a1, 0x6666
/* 417C6C 802A2EDC 0240202D */  daddu     $a0, $s2, $zero
/* 417C70 802A2EE0 0C051308 */  jal       set_hud_element_scale
/* 417C74 802A2EE4 AE720000 */   sw       $s2, ($s3)
/* 417C78 802A2EE8 0240202D */  daddu     $a0, $s2, $zero
/* 417C7C 802A2EEC 0C051280 */  jal       set_hud_element_flags
/* 417C80 802A2EF0 34058080 */   ori      $a1, $zero, 0x8080
/* 417C84 802A2EF4 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 417C88 802A2EF8 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 417C8C 802A2EFC 0202102A */  slt       $v0, $s0, $v0
/* 417C90 802A2F00 1440FFEC */  bnez      $v0, .L802A2EB4
/* 417C94 802A2F04 26730004 */   addiu    $s3, $s3, 4
.L802A2F08:
/* 417C98 802A2F08 3C048010 */  lui       $a0, %hi(D_80104A28)
/* 417C9C 802A2F0C 24844A28 */  addiu     $a0, $a0, %lo(D_80104A28)
/* 417CA0 802A2F10 0C050529 */  jal       create_hud_element
/* 417CA4 802A2F14 00000000 */   nop
/* 417CA8 802A2F18 0040902D */  daddu     $s2, $v0, $zero
/* 417CAC 802A2F1C 0240202D */  daddu     $a0, $s2, $zero
/* 417CB0 802A2F20 3C052000 */  lui       $a1, 0x2000
/* 417CB4 802A2F24 3C01802B */  lui       $at, %hi(battle_menu_moveCursorIcon)
/* 417CB8 802A2F28 AC32D118 */  sw        $s2, %lo(battle_menu_moveCursorIcon)($at)
/* 417CBC 802A2F2C 0C051280 */  jal       set_hud_element_flags
/* 417CC0 802A2F30 34A50080 */   ori      $a1, $a1, 0x80
/* 417CC4 802A2F34 3C11802B */  lui       $s1, %hi(battle_menu_moveX)
/* 417CC8 802A2F38 2631D1F0 */  addiu     $s1, $s1, %lo(battle_menu_moveX)
/* 417CCC 802A2F3C 3C10802B */  lui       $s0, %hi(battle_menu_moveY)
/* 417CD0 802A2F40 2610D1F2 */  addiu     $s0, $s0, %lo(battle_menu_moveY)
/* 417CD4 802A2F44 86250000 */  lh        $a1, ($s1)
/* 417CD8 802A2F48 86060000 */  lh        $a2, ($s0)
/* 417CDC 802A2F4C 0C051261 */  jal       set_hud_element_render_pos
/* 417CE0 802A2F50 0240202D */   daddu    $a0, $s2, $zero
/* 417CE4 802A2F54 3C048010 */  lui       $a0, %hi(D_801077E4)
/* 417CE8 802A2F58 248477E4 */  addiu     $a0, $a0, %lo(D_801077E4)
/* 417CEC 802A2F5C 0C050529 */  jal       create_hud_element
/* 417CF0 802A2F60 00000000 */   nop
/* 417CF4 802A2F64 0040902D */  daddu     $s2, $v0, $zero
/* 417CF8 802A2F68 0240202D */  daddu     $a0, $s2, $zero
/* 417CFC 802A2F6C 3C052000 */  lui       $a1, 0x2000
/* 417D00 802A2F70 3C01802B */  lui       $at, %hi(battle_menu_moveUpArrowIcon)
/* 417D04 802A2F74 AC32D11C */  sw        $s2, %lo(battle_menu_moveUpArrowIcon)($at)
/* 417D08 802A2F78 0C051280 */  jal       set_hud_element_flags
/* 417D0C 802A2F7C 34A50080 */   ori      $a1, $a1, 0x80
/* 417D10 802A2F80 0240202D */  daddu     $a0, $s2, $zero
/* 417D14 802A2F84 86250000 */  lh        $a1, ($s1)
/* 417D18 802A2F88 86060000 */  lh        $a2, ($s0)
/* 417D1C 802A2F8C 24A50027 */  addiu     $a1, $a1, 0x27
/* 417D20 802A2F90 0C051261 */  jal       set_hud_element_render_pos
/* 417D24 802A2F94 24C6FFF9 */   addiu    $a2, $a2, -7
/* 417D28 802A2F98 3C048010 */  lui       $a0, %hi(D_80107798)
/* 417D2C 802A2F9C 24847798 */  addiu     $a0, $a0, %lo(D_80107798)
/* 417D30 802A2FA0 0C050529 */  jal       create_hud_element
/* 417D34 802A2FA4 00000000 */   nop
/* 417D38 802A2FA8 0040902D */  daddu     $s2, $v0, $zero
/* 417D3C 802A2FAC 0240202D */  daddu     $a0, $s2, $zero
/* 417D40 802A2FB0 3C052000 */  lui       $a1, 0x2000
/* 417D44 802A2FB4 3C01802B */  lui       $at, %hi(battle_menu_moveDownArrowIcon)
/* 417D48 802A2FB8 AC32D120 */  sw        $s2, %lo(battle_menu_moveDownArrowIcon)($at)
/* 417D4C 802A2FBC 0C051280 */  jal       set_hud_element_flags
/* 417D50 802A2FC0 34A50080 */   ori      $a1, $a1, 0x80
/* 417D54 802A2FC4 0240202D */  daddu     $a0, $s2, $zero
/* 417D58 802A2FC8 86250000 */  lh        $a1, ($s1)
/* 417D5C 802A2FCC 86060000 */  lh        $a2, ($s0)
/* 417D60 802A2FD0 24A50027 */  addiu     $a1, $a1, 0x27
/* 417D64 802A2FD4 0C051261 */  jal       set_hud_element_render_pos
/* 417D68 802A2FD8 24C6004E */   addiu    $a2, $a2, 0x4e
/* 417D6C 802A2FDC 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 417D70 802A2FE0 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 417D74 802A2FE4 1440000A */  bnez      $v0, .L802A3010
/* 417D78 802A2FE8 00000000 */   nop
/* 417D7C 802A2FEC 3C048011 */  lui       $a0, %hi(D_80108538)
/* 417D80 802A2FF0 24848538 */  addiu     $a0, $a0, %lo(D_80108538)
/* 417D84 802A2FF4 0C050529 */  jal       create_hud_element
/* 417D88 802A2FF8 00000000 */   nop
/* 417D8C 802A2FFC 0040902D */  daddu     $s2, $v0, $zero
/* 417D90 802A3000 3C01802B */  lui       $at, %hi(battle_menu_moveTitleIcon)
/* 417D94 802A3004 AC22D188 */  sw        $v0, %lo(battle_menu_moveTitleIcon)($at)
/* 417D98 802A3008 080A8C0F */  j         .L802A303C
/* 417D9C 802A300C 0240202D */   daddu    $a0, $s2, $zero
.L802A3010:
/* 417DA0 802A3010 3C048011 */  lui       $a0, %hi(D_80108974)
/* 417DA4 802A3014 24848974 */  addiu     $a0, $a0, %lo(D_80108974)
/* 417DA8 802A3018 0C050529 */  jal       create_hud_element
/* 417DAC 802A301C 00000000 */   nop
/* 417DB0 802A3020 0040902D */  daddu     $s2, $v0, $zero
/* 417DB4 802A3024 3C053F40 */  lui       $a1, 0x3f40
/* 417DB8 802A3028 3C01802B */  lui       $at, %hi(battle_menu_moveTitleIcon)
/* 417DBC 802A302C AC32D188 */  sw        $s2, %lo(battle_menu_moveTitleIcon)($at)
/* 417DC0 802A3030 0C051308 */  jal       set_hud_element_scale
/* 417DC4 802A3034 0240202D */   daddu    $a0, $s2, $zero
/* 417DC8 802A3038 0240202D */  daddu     $a0, $s2, $zero
.L802A303C:
/* 417DCC 802A303C 0C051280 */  jal       set_hud_element_flags
/* 417DD0 802A3040 24050080 */   addiu    $a1, $zero, 0x80
/* 417DD4 802A3044 0240202D */  daddu     $a0, $s2, $zero
/* 417DD8 802A3048 3C05802B */  lui       $a1, %hi(battle_menu_moveX)
/* 417DDC 802A304C 84A5D1F0 */  lh        $a1, %lo(battle_menu_moveX)($a1)
/* 417DE0 802A3050 3C06802B */  lui       $a2, %hi(battle_menu_moveY)
/* 417DE4 802A3054 84C6D1F2 */  lh        $a2, %lo(battle_menu_moveY)($a2)
/* 417DE8 802A3058 0C051261 */  jal       set_hud_element_render_pos
/* 417DEC 802A305C 24A50038 */   addiu    $a1, $a1, 0x38
/* 417DF0 802A3060 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 417DF4 802A3064 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 417DF8 802A3068 1840004B */  blez      $v0, .L802A3198
/* 417DFC 802A306C 0000802D */   daddu    $s0, $zero, $zero
/* 417E00 802A3070 24160001 */  addiu     $s6, $zero, 1
/* 417E04 802A3074 3C13802B */  lui       $s3, %hi(battle_menu_moveOptionCostUnitIconIDs)
/* 417E08 802A3078 2673D190 */  addiu     $s3, $s3, %lo(battle_menu_moveOptionCostUnitIconIDs)
/* 417E0C 802A307C 0260A82D */  daddu     $s5, $s3, $zero
/* 417E10 802A3080 0200882D */  daddu     $s1, $s0, $zero
/* 417E14 802A3084 3C14802B */  lui       $s4, %hi(battle_menu_moveOptionDisplayCostReductionColors)
/* 417E18 802A3088 2694D3E0 */  addiu     $s4, $s4, %lo(battle_menu_moveOptionDisplayCostReductionColors)
.L802A308C:
/* 417E1C 802A308C 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 417E20 802A3090 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 417E24 802A3094 14400014 */  bnez      $v0, .L802A30E8
/* 417E28 802A3098 00000000 */   nop
/* 417E2C 802A309C 8E820000 */  lw        $v0, ($s4)
/* 417E30 802A30A0 10400005 */  beqz      $v0, .L802A30B8
/* 417E34 802A30A4 00000000 */   nop
/* 417E38 802A30A8 10560007 */  beq       $v0, $s6, .L802A30C8
/* 417E3C 802A30AC 00000000 */   nop
/* 417E40 802A30B0 080A8C36 */  j         .L802A30D8
/* 417E44 802A30B4 00000000 */   nop
.L802A30B8:
/* 417E48 802A30B8 3C048010 */  lui       $a0, %hi(D_80107638)
/* 417E4C 802A30BC 24847638 */  addiu     $a0, $a0, %lo(D_80107638)
/* 417E50 802A30C0 080A8C47 */  j         .L802A311C
/* 417E54 802A30C4 00000000 */   nop
.L802A30C8:
/* 417E58 802A30C8 3C048010 */  lui       $a0, %hi(D_80107664)
/* 417E5C 802A30CC 24847664 */  addiu     $a0, $a0, %lo(D_80107664)
/* 417E60 802A30D0 080A8C47 */  j         .L802A311C
/* 417E64 802A30D4 00000000 */   nop
.L802A30D8:
/* 417E68 802A30D8 3C048010 */  lui       $a0, %hi(D_80107690)
/* 417E6C 802A30DC 24847690 */  addiu     $a0, $a0, %lo(D_80107690)
/* 417E70 802A30E0 080A8C4F */  j         .L802A313C
/* 417E74 802A30E4 00000000 */   nop
.L802A30E8:
/* 417E78 802A30E8 8E820000 */  lw        $v0, ($s4)
/* 417E7C 802A30EC 10400005 */  beqz      $v0, .L802A3104
/* 417E80 802A30F0 00000000 */   nop
/* 417E84 802A30F4 10560007 */  beq       $v0, $s6, .L802A3114
/* 417E88 802A30F8 00000000 */   nop
/* 417E8C 802A30FC 080A8C4D */  j         .L802A3134
/* 417E90 802A3100 00000000 */   nop
.L802A3104:
/* 417E94 802A3104 3C048010 */  lui       $a0, %hi(D_801076E8)
/* 417E98 802A3108 248476E8 */  addiu     $a0, $a0, %lo(D_801076E8)
/* 417E9C 802A310C 080A8C47 */  j         .L802A311C
/* 417EA0 802A3110 00000000 */   nop
.L802A3114:
/* 417EA4 802A3114 3C048010 */  lui       $a0, %hi(D_80107714)
/* 417EA8 802A3118 24847714 */  addiu     $a0, $a0, %lo(D_80107714)
.L802A311C:
/* 417EAC 802A311C 0C050529 */  jal       create_hud_element
/* 417EB0 802A3120 00000000 */   nop
/* 417EB4 802A3124 0040902D */  daddu     $s2, $v0, $zero
/* 417EB8 802A3128 02351021 */  addu      $v0, $s1, $s5
/* 417EBC 802A312C 080A8C53 */  j         .L802A314C
/* 417EC0 802A3130 AC520000 */   sw       $s2, ($v0)
.L802A3134:
/* 417EC4 802A3134 3C048010 */  lui       $a0, %hi(D_80107740)
/* 417EC8 802A3138 24847740 */  addiu     $a0, $a0, %lo(D_80107740)
.L802A313C:
/* 417ECC 802A313C 0C050529 */  jal       create_hud_element
/* 417ED0 802A3140 00000000 */   nop
/* 417ED4 802A3144 0040902D */  daddu     $s2, $v0, $zero
/* 417ED8 802A3148 AE720000 */  sw        $s2, ($s3)
.L802A314C:
/* 417EDC 802A314C 0240202D */  daddu     $a0, $s2, $zero
/* 417EE0 802A3150 0C051280 */  jal       set_hud_element_flags
/* 417EE4 802A3154 24050080 */   addiu    $a1, $zero, 0x80
/* 417EE8 802A3158 0240202D */  daddu     $a0, $s2, $zero
/* 417EEC 802A315C 26730004 */  addiu     $s3, $s3, 4
/* 417EF0 802A3160 26310004 */  addiu     $s1, $s1, 4
/* 417EF4 802A3164 26940004 */  addiu     $s4, $s4, 4
/* 417EF8 802A3168 3C05802B */  lui       $a1, %hi(battle_menu_moveX)
/* 417EFC 802A316C 84A5D1F0 */  lh        $a1, %lo(battle_menu_moveX)($a1)
/* 417F00 802A3170 3C06802B */  lui       $a2, %hi(battle_menu_moveY)
/* 417F04 802A3174 84C6D1F2 */  lh        $a2, %lo(battle_menu_moveY)($a2)
/* 417F08 802A3178 0C051261 */  jal       set_hud_element_render_pos
/* 417F0C 802A317C 24A50038 */   addiu    $a1, $a1, 0x38
/* 417F10 802A3180 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 417F14 802A3184 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 417F18 802A3188 26100001 */  addiu     $s0, $s0, 1
/* 417F1C 802A318C 0202102A */  slt       $v0, $s0, $v0
/* 417F20 802A3190 1440FFBE */  bnez      $v0, .L802A308C
/* 417F24 802A3194 00000000 */   nop
.L802A3198:
/* 417F28 802A3198 3C13802B */  lui       $s3, %hi(battle_menu_moveX)
/* 417F2C 802A319C 8673D1F0 */  lh        $s3, %lo(battle_menu_moveX)($s3)
/* 417F30 802A31A0 2402000A */  addiu     $v0, $zero, 0xa
/* 417F34 802A31A4 3C01802B */  lui       $at, %hi(battle_menu_moveTextColor)
/* 417F38 802A31A8 A422D114 */  sh        $v0, %lo(battle_menu_moveTextColor)($at)
/* 417F3C 802A31AC 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 417F40 802A31B0 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 417F44 802A31B4 3C12802B */  lui       $s2, %hi(battle_menu_moveY)
/* 417F48 802A31B8 8652D1F2 */  lh        $s2, %lo(battle_menu_moveY)($s2)
/* 417F4C 802A31BC 14400028 */  bnez      $v0, .L802A3260
/* 417F50 802A31C0 24040001 */   addiu    $a0, $zero, 1
/* 417F54 802A31C4 0260282D */  daddu     $a1, $s3, $zero
/* 417F58 802A31C8 0240302D */  daddu     $a2, $s2, $zero
/* 417F5C 802A31CC 24070096 */  addiu     $a3, $zero, 0x96
/* 417F60 802A31D0 3C02802A */  lui       $v0, %hi(func_802A3C98)
/* 417F64 802A31D4 24423C98 */  addiu     $v0, $v0, %lo(func_802A3C98)
/* 417F68 802A31D8 3C03802B */  lui       $v1, %hi(D_802AD10E)
/* 417F6C 802A31DC 8063D10E */  lb        $v1, %lo(D_802AD10E)($v1)
/* 417F70 802A31E0 2410FFFF */  addiu     $s0, $zero, -1
/* 417F74 802A31E4 AFA00014 */  sw        $zero, 0x14($sp)
/* 417F78 802A31E8 AFA20018 */  sw        $v0, 0x18($sp)
/* 417F7C 802A31EC AFA0001C */  sw        $zero, 0x1c($sp)
/* 417F80 802A31F0 AFB00020 */  sw        $s0, 0x20($sp)
/* 417F84 802A31F4 00831004 */  sllv      $v0, $v1, $a0
/* 417F88 802A31F8 00431021 */  addu      $v0, $v0, $v1
/* 417F8C 802A31FC 00021080 */  sll       $v0, $v0, 2
/* 417F90 802A3200 00431021 */  addu      $v0, $v0, $v1
/* 417F94 802A3204 2442001C */  addiu     $v0, $v0, 0x1c
/* 417F98 802A3208 0C051F32 */  jal       set_window_properties
/* 417F9C 802A320C AFA20010 */   sw       $v0, 0x10($sp)
/* 417FA0 802A3210 24040002 */  addiu     $a0, $zero, 2
/* 417FA4 802A3214 26650010 */  addiu     $a1, $s3, 0x10
/* 417FA8 802A3218 2646FFFA */  addiu     $a2, $s2, -6
/* 417FAC 802A321C 2407005A */  addiu     $a3, $zero, 0x5a
/* 417FB0 802A3220 24020010 */  addiu     $v0, $zero, 0x10
/* 417FB4 802A3224 24110001 */  addiu     $s1, $zero, 1
/* 417FB8 802A3228 AFA20010 */  sw        $v0, 0x10($sp)
/* 417FBC 802A322C 3C02802A */  lui       $v0, %hi(func_802A43DC)
/* 417FC0 802A3230 244243DC */  addiu     $v0, $v0, %lo(func_802A43DC)
/* 417FC4 802A3234 AFB10014 */  sw        $s1, 0x14($sp)
/* 417FC8 802A3238 AFA20018 */  sw        $v0, 0x18($sp)
/* 417FCC 802A323C AFA0001C */  sw        $zero, 0x1c($sp)
/* 417FD0 802A3240 0C051F32 */  jal       set_window_properties
/* 417FD4 802A3244 AFB00020 */   sw       $s0, 0x20($sp)
/* 417FD8 802A3248 24040003 */  addiu     $a0, $zero, 3
/* 417FDC 802A324C 26650072 */  addiu     $a1, $s3, 0x72
/* 417FE0 802A3250 2646FFF4 */  addiu     $a2, $s2, -0xc
/* 417FE4 802A3254 24070020 */  addiu     $a3, $zero, 0x20
/* 417FE8 802A3258 080A8CBE */  j         .L802A32F8
/* 417FEC 802A325C 00E0102D */   daddu    $v0, $a3, $zero
.L802A3260:
/* 417FF0 802A3260 0260282D */  daddu     $a1, $s3, $zero
/* 417FF4 802A3264 0240302D */  daddu     $a2, $s2, $zero
/* 417FF8 802A3268 24070090 */  addiu     $a3, $zero, 0x90
/* 417FFC 802A326C 3C02802A */  lui       $v0, %hi(func_802A3C98)
/* 418000 802A3270 24423C98 */  addiu     $v0, $v0, %lo(func_802A3C98)
/* 418004 802A3274 3C03802B */  lui       $v1, %hi(D_802AD10E)
/* 418008 802A3278 8063D10E */  lb        $v1, %lo(D_802AD10E)($v1)
/* 41800C 802A327C 2410FFFF */  addiu     $s0, $zero, -1
/* 418010 802A3280 AFA00014 */  sw        $zero, 0x14($sp)
/* 418014 802A3284 AFA20018 */  sw        $v0, 0x18($sp)
/* 418018 802A3288 AFA0001C */  sw        $zero, 0x1c($sp)
/* 41801C 802A328C AFB00020 */  sw        $s0, 0x20($sp)
/* 418020 802A3290 00831004 */  sllv      $v0, $v1, $a0
/* 418024 802A3294 00431021 */  addu      $v0, $v0, $v1
/* 418028 802A3298 00021080 */  sll       $v0, $v0, 2
/* 41802C 802A329C 00431021 */  addu      $v0, $v0, $v1
/* 418030 802A32A0 2442001C */  addiu     $v0, $v0, 0x1c
/* 418034 802A32A4 0C051F32 */  jal       set_window_properties
/* 418038 802A32A8 AFA20010 */   sw       $v0, 0x10($sp)
/* 41803C 802A32AC 24040004 */  addiu     $a0, $zero, 4
/* 418040 802A32B0 2665000A */  addiu     $a1, $s3, 0xa
/* 418044 802A32B4 2646FFFA */  addiu     $a2, $s2, -6
/* 418048 802A32B8 24070064 */  addiu     $a3, $zero, 0x64
/* 41804C 802A32BC 24020010 */  addiu     $v0, $zero, 0x10
/* 418050 802A32C0 24110001 */  addiu     $s1, $zero, 1
/* 418054 802A32C4 AFA20010 */  sw        $v0, 0x10($sp)
/* 418058 802A32C8 3C02802A */  lui       $v0, %hi(func_802A43DC)
/* 41805C 802A32CC 244243DC */  addiu     $v0, $v0, %lo(func_802A43DC)
/* 418060 802A32D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 418064 802A32D4 AFA20018 */  sw        $v0, 0x18($sp)
/* 418068 802A32D8 AFA0001C */  sw        $zero, 0x1c($sp)
/* 41806C 802A32DC 0C051F32 */  jal       set_window_properties
/* 418070 802A32E0 AFB00020 */   sw       $s0, 0x20($sp)
/* 418074 802A32E4 24040005 */  addiu     $a0, $zero, 5
/* 418078 802A32E8 2665006E */  addiu     $a1, $s3, 0x6e
/* 41807C 802A32EC 2646FFF4 */  addiu     $a2, $s2, -0xc
/* 418080 802A32F0 24070020 */  addiu     $a3, $zero, 0x20
/* 418084 802A32F4 24020023 */  addiu     $v0, $zero, 0x23
.L802A32F8:
/* 418088 802A32F8 AFA20010 */  sw        $v0, 0x10($sp)
/* 41808C 802A32FC 3C02802A */  lui       $v0, %hi(func_802A4448)
/* 418090 802A3300 24424448 */  addiu     $v0, $v0, %lo(func_802A4448)
/* 418094 802A3304 AFB10014 */  sw        $s1, 0x14($sp)
/* 418098 802A3308 AFA20018 */  sw        $v0, 0x18($sp)
/* 41809C 802A330C AFA0001C */  sw        $zero, 0x1c($sp)
/* 4180A0 802A3310 0C051F32 */  jal       set_window_properties
/* 4180A4 802A3314 AFB00020 */   sw       $s0, 0x20($sp)
/* 4180A8 802A3318 24130014 */  addiu     $s3, $zero, 0x14
/* 4180AC 802A331C 24040008 */  addiu     $a0, $zero, 8
/* 4180B0 802A3320 0260282D */  daddu     $a1, $s3, $zero
/* 4180B4 802A3324 240600BA */  addiu     $a2, $zero, 0xba
/* 4180B8 802A3328 24070118 */  addiu     $a3, $zero, 0x118
/* 4180BC 802A332C 24020020 */  addiu     $v0, $zero, 0x20
/* 4180C0 802A3330 AFA20010 */  sw        $v0, 0x10($sp)
/* 4180C4 802A3334 3C02802A */  lui       $v0, %hi(func_802A4494)
/* 4180C8 802A3338 24424494 */  addiu     $v0, $v0, %lo(func_802A4494)
/* 4180CC 802A333C AFA20018 */  sw        $v0, 0x18($sp)
/* 4180D0 802A3340 2402FFFF */  addiu     $v0, $zero, -1
/* 4180D4 802A3344 AFB30014 */  sw        $s3, 0x14($sp)
/* 4180D8 802A3348 AFA0001C */  sw        $zero, 0x1c($sp)
/* 4180DC 802A334C 0C051F32 */  jal       set_window_properties
/* 4180E0 802A3350 AFA20020 */   sw       $v0, 0x20($sp)
/* 4180E4 802A3354 24040001 */  addiu     $a0, $zero, 1
/* 4180E8 802A3358 0C051F9F */  jal       set_window_update
/* 4180EC 802A335C 0080282D */   daddu    $a1, $a0, $zero
/* 4180F0 802A3360 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 4180F4 802A3364 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 4180F8 802A3368 54400006 */  bnel      $v0, $zero, .L802A3384
/* 4180FC 802A336C 24040004 */   addiu    $a0, $zero, 4
/* 418100 802A3370 24040002 */  addiu     $a0, $zero, 2
/* 418104 802A3374 0C051F9F */  jal       set_window_update
/* 418108 802A3378 24050001 */   addiu    $a1, $zero, 1
/* 41810C 802A337C 080A8CE4 */  j         .L802A3390
/* 418110 802A3380 24040003 */   addiu    $a0, $zero, 3
.L802A3384:
/* 418114 802A3384 0C051F9F */  jal       set_window_update
/* 418118 802A3388 24050001 */   addiu    $a1, $zero, 1
/* 41811C 802A338C 24040005 */  addiu     $a0, $zero, 5
.L802A3390:
/* 418120 802A3390 0C051F9F */  jal       set_window_update
/* 418124 802A3394 24050001 */   addiu    $a1, $zero, 1
/* 418128 802A3398 24040008 */  addiu     $a0, $zero, 8
/* 41812C 802A339C 0C051F9F */  jal       set_window_update
/* 418130 802A33A0 24050001 */   addiu    $a1, $zero, 1
/* 418134 802A33A4 3C05802B */  lui       $a1, %hi(battle_menu_moveScrollLine)
/* 418138 802A33A8 24A5D10C */  addiu     $a1, $a1, %lo(battle_menu_moveScrollLine)
/* 41813C 802A33AC 3C06802B */  lui       $a2, %hi(battle_menu_moveOptionCount)
/* 418140 802A33B0 24C6D4A4 */  addiu     $a2, $a2, %lo(battle_menu_moveOptionCount)
/* 418144 802A33B4 3C08802B */  lui       $t0, %hi(battle_menu_moveCursorPos)
/* 418148 802A33B8 8108D109 */  lb        $t0, %lo(battle_menu_moveCursorPos)($t0)
/* 41814C 802A33BC 3C07802B */  lui       $a3, %hi(D_802AD10D)
/* 418150 802A33C0 80E7D10D */  lb        $a3, %lo(D_802AD10D)($a3)
.L802A33C4:
/* 418154 802A33C4 80A20000 */  lb        $v0, ($a1)
/* 418158 802A33C8 90A30000 */  lbu       $v1, ($a1)
/* 41815C 802A33CC 00471021 */  addu      $v0, $v0, $a3
/* 418160 802A33D0 2442FFFF */  addiu     $v0, $v0, -1
/* 418164 802A33D4 0102102A */  slt       $v0, $t0, $v0
/* 418168 802A33D8 14400010 */  bnez      $v0, .L802A341C
/* 41816C 802A33DC 0000202D */   daddu    $a0, $zero, $zero
/* 418170 802A33E0 24630001 */  addiu     $v1, $v1, 1
/* 418174 802A33E4 A0A30000 */  sb        $v1, ($a1)
/* 418178 802A33E8 00031E00 */  sll       $v1, $v1, 0x18
/* 41817C 802A33EC 8CC20000 */  lw        $v0, ($a2)
/* 418180 802A33F0 00031E03 */  sra       $v1, $v1, 0x18
/* 418184 802A33F4 2442FFFA */  addiu     $v0, $v0, -6
/* 418188 802A33F8 0043102A */  slt       $v0, $v0, $v1
/* 41818C 802A33FC 50400007 */  beql      $v0, $zero, .L802A341C
/* 418190 802A3400 24040001 */   addiu    $a0, $zero, 1
/* 418194 802A3404 90C20003 */  lbu       $v0, 3($a2)
/* 418198 802A3408 2442FFFA */  addiu     $v0, $v0, -6
/* 41819C 802A340C A0A20000 */  sb        $v0, ($a1)
/* 4181A0 802A3410 00021600 */  sll       $v0, $v0, 0x18
/* 4181A4 802A3414 04420001 */  bltzl     $v0, .L802A341C
/* 4181A8 802A3418 A0A00000 */   sb       $zero, ($a1)
.L802A341C:
/* 4181AC 802A341C 1480FFE9 */  bnez      $a0, .L802A33C4
/* 4181B0 802A3420 24020001 */   addiu    $v0, $zero, 1
/* 4181B4 802A3424 3C03802B */  lui       $v1, %hi(battle_menu_moveScrollLine)
/* 4181B8 802A3428 9063D10C */  lbu       $v1, %lo(battle_menu_moveScrollLine)($v1)
/* 4181BC 802A342C 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorPos)
/* 4181C0 802A3430 8084D109 */  lb        $a0, %lo(battle_menu_moveCursorPos)($a0)
/* 4181C4 802A3434 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 4181C8 802A3438 A022D108 */  sb        $v0, %lo(battle_menu_moveState)($at)
/* 4181CC 802A343C 24620006 */  addiu     $v0, $v1, 6
/* 4181D0 802A3440 00031E00 */  sll       $v1, $v1, 0x18
/* 4181D4 802A3444 00031E03 */  sra       $v1, $v1, 0x18
/* 4181D8 802A3448 00032823 */  negu      $a1, $v1
/* 4181DC 802A344C 3C01802B */  lui       $at, %hi(D_802AD10D)
/* 4181E0 802A3450 A022D10D */  sb        $v0, %lo(D_802AD10D)($at)
/* 4181E4 802A3454 00051040 */  sll       $v0, $a1, 1
/* 4181E8 802A3458 00451021 */  addu      $v0, $v0, $a1
/* 4181EC 802A345C 00021080 */  sll       $v0, $v0, 2
/* 4181F0 802A3460 00451021 */  addu      $v0, $v0, $a1
/* 4181F4 802A3464 00832023 */  subu      $a0, $a0, $v1
/* 4181F8 802A3468 3C01802B */  lui       $at, %hi(battle_menu_moveScrollOffset)
/* 4181FC 802A346C A422D110 */  sh        $v0, %lo(battle_menu_moveScrollOffset)($at)
/* 418200 802A3470 00041040 */  sll       $v0, $a0, 1
/* 418204 802A3474 00441021 */  addu      $v0, $v0, $a0
/* 418208 802A3478 00021080 */  sll       $v0, $v0, 2
/* 41820C 802A347C 00441021 */  addu      $v0, $v0, $a0
/* 418210 802A3480 3C01802B */  lui       $at, %hi(D_802AD112)
/* 418214 802A3484 A422D112 */  sh        $v0, %lo(D_802AD112)($at)
/* 418218 802A3488 080A8F1C */  j         .L802A3C70
/* 41821C 802A348C 0000102D */   daddu    $v0, $zero, $zero
dlabel L802A3490_418220
/* 418220 802A3490 3C050001 */  lui       $a1, 1
/* 418224 802A3494 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorPos)
/* 418228 802A3498 2484D109 */  addiu     $a0, $a0, %lo(battle_menu_moveCursorPos)
/* 41822C 802A349C 34A52000 */  ori       $a1, $a1, 0x2000
/* 418230 802A34A0 8E220218 */  lw        $v0, 0x218($s1)
/* 418234 802A34A4 90830000 */  lbu       $v1, ($a0)
/* 418238 802A34A8 00451024 */  and       $v0, $v0, $a1
/* 41823C 802A34AC 3C01802B */  lui       $at, %hi(D_802AD10A)
/* 418240 802A34B0 A023D10A */  sb        $v1, %lo(D_802AD10A)($at)
/* 418244 802A34B4 10400008 */  beqz      $v0, .L802A34D8
/* 418248 802A34B8 00031600 */   sll      $v0, $v1, 0x18
/* 41824C 802A34BC 1C400005 */  bgtz      $v0, .L802A34D4
/* 418250 802A34C0 2462FFFF */   addiu    $v0, $v1, -1
/* 418254 802A34C4 8E220214 */  lw        $v0, 0x214($s1)
/* 418258 802A34C8 00451024 */  and       $v0, $v0, $a1
/* 41825C 802A34CC 10400002 */  beqz      $v0, .L802A34D8
/* 418260 802A34D0 2462FFFF */   addiu    $v0, $v1, -1
.L802A34D4:
/* 418264 802A34D4 A0820000 */  sb        $v0, ($a0)
.L802A34D8:
/* 418268 802A34D8 3C060002 */  lui       $a2, 2
/* 41826C 802A34DC 8E220218 */  lw        $v0, 0x218($s1)
/* 418270 802A34E0 34C60010 */  ori       $a2, $a2, 0x10
/* 418274 802A34E4 00461024 */  and       $v0, $v0, $a2
/* 418278 802A34E8 10400010 */  beqz      $v0, .L802A352C
/* 41827C 802A34EC 00000000 */   nop
/* 418280 802A34F0 3C05802B */  lui       $a1, %hi(battle_menu_moveCursorPos)
/* 418284 802A34F4 24A5D109 */  addiu     $a1, $a1, %lo(battle_menu_moveCursorPos)
/* 418288 802A34F8 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 41828C 802A34FC 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 418290 802A3500 80A30000 */  lb        $v1, ($a1)
/* 418294 802A3504 90A40000 */  lbu       $a0, ($a1)
/* 418298 802A3508 2442FFFF */  addiu     $v0, $v0, -1
/* 41829C 802A350C 0062182A */  slt       $v1, $v1, $v0
/* 4182A0 802A3510 14600005 */  bnez      $v1, .L802A3528
/* 4182A4 802A3514 24820001 */   addiu    $v0, $a0, 1
/* 4182A8 802A3518 8E220214 */  lw        $v0, 0x214($s1)
/* 4182AC 802A351C 00461024 */  and       $v0, $v0, $a2
/* 4182B0 802A3520 10400002 */  beqz      $v0, .L802A352C
/* 4182B4 802A3524 24820001 */   addiu    $v0, $a0, 1
.L802A3528:
/* 4182B8 802A3528 A0A20000 */  sb        $v0, ($a1)
.L802A352C:
/* 4182BC 802A352C 3C10802B */  lui       $s0, %hi(battle_menu_moveCursorPos)
/* 4182C0 802A3530 2610D109 */  addiu     $s0, $s0, %lo(battle_menu_moveCursorPos)
/* 4182C4 802A3534 82020000 */  lb        $v0, ($s0)
/* 4182C8 802A3538 04410005 */  bgez      $v0, .L802A3550
/* 4182CC 802A353C 00000000 */   nop
/* 4182D0 802A3540 3C02802B */  lui       $v0, %hi(D_802AD4A7)
/* 4182D4 802A3544 9042D4A7 */  lbu       $v0, %lo(D_802AD4A7)($v0)
/* 4182D8 802A3548 2442FFFF */  addiu     $v0, $v0, -1
/* 4182DC 802A354C A2020000 */  sb        $v0, ($s0)
.L802A3550:
/* 4182E0 802A3550 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 4182E4 802A3554 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 4182E8 802A3558 82030000 */  lb        $v1, ($s0)
/* 4182EC 802A355C 2442FFFF */  addiu     $v0, $v0, -1
/* 4182F0 802A3560 0043102A */  slt       $v0, $v0, $v1
/* 4182F4 802A3564 54400001 */  bnel      $v0, $zero, .L802A356C
/* 4182F8 802A3568 A2000000 */   sb       $zero, ($s0)
.L802A356C:
/* 4182FC 802A356C 3C03802B */  lui       $v1, %hi(D_802AD10A)
/* 418300 802A3570 8063D10A */  lb        $v1, %lo(D_802AD10A)($v1)
/* 418304 802A3574 82020000 */  lb        $v0, ($s0)
/* 418308 802A3578 10620009 */  beq       $v1, $v0, .L802A35A0
/* 41830C 802A357C 00031080 */   sll      $v0, $v1, 2
/* 418310 802A3580 3C04802B */  lui       $a0, %hi(battle_menu_moveOptionIconIDs)
/* 418314 802A3584 00822021 */  addu      $a0, $a0, $v0
/* 418318 802A3588 8C84D128 */  lw        $a0, %lo(battle_menu_moveOptionIconIDs)($a0)
/* 41831C 802A358C 3C053EE6 */  lui       $a1, 0x3ee6
/* 418320 802A3590 0C051308 */  jal       set_hud_element_scale
/* 418324 802A3594 34A56666 */   ori      $a1, $a1, 0x6666
/* 418328 802A3598 0C05272D */  jal       sfx_play_sound
/* 41832C 802A359C 240400C7 */   addiu    $a0, $zero, 0xc7
.L802A35A0:
/* 418330 802A35A0 3C04802B */  lui       $a0, %hi(battle_menu_moveScrollLine)
/* 418334 802A35A4 2484D10C */  addiu     $a0, $a0, %lo(battle_menu_moveScrollLine)
/* 418338 802A35A8 80820000 */  lb        $v0, ($a0)
/* 41833C 802A35AC 82030000 */  lb        $v1, ($s0)
/* 418340 802A35B0 24420001 */  addiu     $v0, $v0, 1
/* 418344 802A35B4 0062182A */  slt       $v1, $v1, $v0
/* 418348 802A35B8 90820000 */  lbu       $v0, ($a0)
/* 41834C 802A35BC 10600005 */  beqz      $v1, .L802A35D4
/* 418350 802A35C0 2442FFFF */   addiu    $v0, $v0, -1
/* 418354 802A35C4 A0820000 */  sb        $v0, ($a0)
/* 418358 802A35C8 00021600 */  sll       $v0, $v0, 0x18
/* 41835C 802A35CC 04420001 */  bltzl     $v0, .L802A35D4
/* 418360 802A35D0 A0800000 */   sb       $zero, ($a0)
.L802A35D4:
/* 418364 802A35D4 3C02802B */  lui       $v0, %hi(D_802AD10D)
/* 418368 802A35D8 8042D10D */  lb        $v0, %lo(D_802AD10D)($v0)
/* 41836C 802A35DC 3C03802B */  lui       $v1, %hi(battle_menu_moveCursorPos)
/* 418370 802A35E0 8063D109 */  lb        $v1, %lo(battle_menu_moveCursorPos)($v1)
/* 418374 802A35E4 2442FFFF */  addiu     $v0, $v0, -1
/* 418378 802A35E8 0062182A */  slt       $v1, $v1, $v0
/* 41837C 802A35EC 14600015 */  bnez      $v1, .L802A3644
/* 418380 802A35F0 00000000 */   nop
/* 418384 802A35F4 3C04802B */  lui       $a0, %hi(battle_menu_moveScrollLine)
/* 418388 802A35F8 2484D10C */  addiu     $a0, $a0, %lo(battle_menu_moveScrollLine)
/* 41838C 802A35FC 90820000 */  lbu       $v0, ($a0)
/* 418390 802A3600 3C05802B */  lui       $a1, %hi(battle_menu_moveOptionCount)
/* 418394 802A3604 24A5D4A4 */  addiu     $a1, $a1, %lo(battle_menu_moveOptionCount)
/* 418398 802A3608 24420001 */  addiu     $v0, $v0, 1
/* 41839C 802A360C A0820000 */  sb        $v0, ($a0)
/* 4183A0 802A3610 00021600 */  sll       $v0, $v0, 0x18
/* 4183A4 802A3614 8CA30000 */  lw        $v1, ($a1)
/* 4183A8 802A3618 00021603 */  sra       $v0, $v0, 0x18
/* 4183AC 802A361C 2463FFFA */  addiu     $v1, $v1, -6
/* 4183B0 802A3620 0062182A */  slt       $v1, $v1, $v0
/* 4183B4 802A3624 10600007 */  beqz      $v1, .L802A3644
/* 4183B8 802A3628 00000000 */   nop
/* 4183BC 802A362C 90A20003 */  lbu       $v0, 3($a1)
/* 4183C0 802A3630 2442FFFA */  addiu     $v0, $v0, -6
/* 4183C4 802A3634 A0820000 */  sb        $v0, ($a0)
/* 4183C8 802A3638 00021600 */  sll       $v0, $v0, 0x18
/* 4183CC 802A363C 04420001 */  bltzl     $v0, .L802A3644
/* 4183D0 802A3640 A0800000 */   sb       $zero, ($a0)
.L802A3644:
/* 4183D4 802A3644 3C02802B */  lui       $v0, %hi(battle_menu_moveScrollLine)
/* 4183D8 802A3648 9042D10C */  lbu       $v0, %lo(battle_menu_moveScrollLine)($v0)
/* 4183DC 802A364C 8E230214 */  lw        $v1, 0x214($s1)
/* 4183E0 802A3650 24420006 */  addiu     $v0, $v0, 6
/* 4183E4 802A3654 3C01802B */  lui       $at, %hi(D_802AD10D)
/* 4183E8 802A3658 A022D10D */  sb        $v0, %lo(D_802AD10D)($at)
/* 4183EC 802A365C 30628000 */  andi      $v0, $v1, 0x8000
/* 4183F0 802A3660 10400025 */  beqz      $v0, .L802A36F8
/* 4183F4 802A3664 30624000 */   andi     $v0, $v1, 0x4000
/* 4183F8 802A3668 3C11802B */  lui       $s1, %hi(battle_menu_moveCursorPos)
/* 4183FC 802A366C 2631D109 */  addiu     $s1, $s1, %lo(battle_menu_moveCursorPos)
/* 418400 802A3670 82220000 */  lb        $v0, ($s1)
/* 418404 802A3674 00021080 */  sll       $v0, $v0, 2
/* 418408 802A3678 3C01802B */  lui       $at, %hi(battle_menu_moveOptionIndexMap)
/* 41840C 802A367C 00220821 */  addu      $at, $at, $v0
/* 418410 802A3680 8C22D1F8 */  lw        $v0, %lo(battle_menu_moveOptionIndexMap)($at)
/* 418414 802A3684 3C10802B */  lui       $s0, %hi(battle_menu_moveOptionIndexMap)
/* 418418 802A3688 2610D1F8 */  addiu     $s0, $s0, %lo(battle_menu_moveOptionIndexMap)
/* 41841C 802A368C 00021080 */  sll       $v0, $v0, 2
/* 418420 802A3690 3C03802B */  lui       $v1, %hi(battle_menu_moveOptionsEnabled)
/* 418424 802A3694 00621821 */  addu      $v1, $v1, $v0
/* 418428 802A3698 8C63D510 */  lw        $v1, %lo(battle_menu_moveOptionsEnabled)($v1)
/* 41842C 802A369C 24020001 */  addiu     $v0, $zero, 1
/* 418430 802A36A0 14620005 */  bne       $v1, $v0, .L802A36B8
/* 418434 802A36A4 00000000 */   nop
/* 418438 802A36A8 0C05272D */  jal       sfx_play_sound
/* 41843C 802A36AC 240400C9 */   addiu    $a0, $zero, 0xc9
/* 418440 802A36B0 080A8F19 */  j         .L802A3C64
/* 418444 802A36B4 2402FFFF */   addiu    $v0, $zero, -1
.L802A36B8:
/* 418448 802A36B8 0C05272D */  jal       sfx_play_sound
/* 41844C 802A36BC 2404021D */   addiu    $a0, $zero, 0x21d
/* 418450 802A36C0 82220000 */  lb        $v0, ($s1)
/* 418454 802A36C4 00021080 */  sll       $v0, $v0, 2
/* 418458 802A36C8 00501021 */  addu      $v0, $v0, $s0
/* 41845C 802A36CC 8C420000 */  lw        $v0, ($v0)
/* 418460 802A36D0 3C03802B */  lui       $v1, %hi(D_802AD258)
/* 418464 802A36D4 2463D258 */  addiu     $v1, $v1, %lo(D_802AD258)
/* 418468 802A36D8 AC600000 */  sw        $zero, ($v1)
/* 41846C 802A36DC 3C01802B */  lui       $at, %hi(battle_menu_moveOptionCantUseTypes)
/* 418470 802A36E0 00220821 */  addu      $at, $at, $v0
/* 418474 802A36E4 8022D5E8 */  lb        $v0, %lo(battle_menu_moveOptionCantUseTypes)($at)
/* 418478 802A36E8 54400001 */  bnel      $v0, $zero, .L802A36F0
/* 41847C 802A36EC AC620000 */   sw       $v0, ($v1)
.L802A36F0:
/* 418480 802A36F0 080A8F19 */  j         .L802A3C64
/* 418484 802A36F4 24020028 */   addiu    $v0, $zero, 0x28
.L802A36F8:
/* 418488 802A36F8 1040015D */  beqz      $v0, .L802A3C70
/* 41848C 802A36FC 0000102D */   daddu    $v0, $zero, $zero
/* 418490 802A3700 0C05272D */  jal       sfx_play_sound
/* 418494 802A3704 240400CA */   addiu    $a0, $zero, 0xca
/* 418498 802A3708 0C0A89F9 */  jal       func_802A27E4
/* 41849C 802A370C 00000000 */   nop
/* 4184A0 802A3710 080A8F19 */  j         .L802A3C64
/* 4184A4 802A3714 2402FFFE */   addiu    $v0, $zero, -2
dlabel L802A3718_4184A8
/* 4184A8 802A3718 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 4184AC 802A371C 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 4184B0 802A3720 1840000F */  blez      $v0, .L802A3760
/* 4184B4 802A3724 0000802D */   daddu    $s0, $zero, $zero
/* 4184B8 802A3728 3C11802B */  lui       $s1, %hi(battle_menu_moveOptionIconIDs)
/* 4184BC 802A372C 2631D128 */  addiu     $s1, $s1, %lo(battle_menu_moveOptionIconIDs)
/* 4184C0 802A3730 240500A0 */  addiu     $a1, $zero, 0xa0
.L802A3734:
/* 4184C4 802A3734 00A0302D */  daddu     $a2, $a1, $zero
/* 4184C8 802A3738 00A0382D */  daddu     $a3, $a1, $zero
/* 4184CC 802A373C 8E240000 */  lw        $a0, ($s1)
/* 4184D0 802A3740 0C0513BF */  jal       set_hud_element_tint
/* 4184D4 802A3744 26310004 */   addiu    $s1, $s1, 4
/* 4184D8 802A3748 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 4184DC 802A374C 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 4184E0 802A3750 26100001 */  addiu     $s0, $s0, 1
/* 4184E4 802A3754 0202102A */  slt       $v0, $s0, $v0
/* 4184E8 802A3758 1440FFF6 */  bnez      $v0, .L802A3734
/* 4184EC 802A375C 240500A0 */   addiu    $a1, $zero, 0xa0
.L802A3760:
/* 4184F0 802A3760 240500A0 */  addiu     $a1, $zero, 0xa0
/* 4184F4 802A3764 00A0302D */  daddu     $a2, $a1, $zero
/* 4184F8 802A3768 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorIcon)
/* 4184FC 802A376C 8C84D118 */  lw        $a0, %lo(battle_menu_moveCursorIcon)($a0)
/* 418500 802A3770 0C0513BF */  jal       set_hud_element_tint
/* 418504 802A3774 00A0382D */   daddu    $a3, $a1, $zero
/* 418508 802A3778 240500A0 */  addiu     $a1, $zero, 0xa0
/* 41850C 802A377C 00A0302D */  daddu     $a2, $a1, $zero
/* 418510 802A3780 3C04802B */  lui       $a0, %hi(battle_menu_moveUpArrowIcon)
/* 418514 802A3784 8C84D11C */  lw        $a0, %lo(battle_menu_moveUpArrowIcon)($a0)
/* 418518 802A3788 0C0513BF */  jal       set_hud_element_tint
/* 41851C 802A378C 00A0382D */   daddu    $a3, $a1, $zero
/* 418520 802A3790 240500A0 */  addiu     $a1, $zero, 0xa0
/* 418524 802A3794 00A0302D */  daddu     $a2, $a1, $zero
/* 418528 802A3798 3C04802B */  lui       $a0, %hi(battle_menu_moveDownArrowIcon)
/* 41852C 802A379C 8C84D120 */  lw        $a0, %lo(battle_menu_moveDownArrowIcon)($a0)
/* 418530 802A37A0 0C0513BF */  jal       set_hud_element_tint
/* 418534 802A37A4 00A0382D */   daddu    $a3, $a1, $zero
/* 418538 802A37A8 240500A0 */  addiu     $a1, $zero, 0xa0
/* 41853C 802A37AC 00A0302D */  daddu     $a2, $a1, $zero
/* 418540 802A37B0 3C04802B */  lui       $a0, %hi(battle_menu_moveTitleIcon)
/* 418544 802A37B4 8C84D188 */  lw        $a0, %lo(battle_menu_moveTitleIcon)($a0)
/* 418548 802A37B8 0C0513BF */  jal       set_hud_element_tint
/* 41854C 802A37BC 00A0382D */   daddu    $a3, $a1, $zero
/* 418550 802A37C0 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 418554 802A37C4 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 418558 802A37C8 1840000F */  blez      $v0, .L802A3808
/* 41855C 802A37CC 0000802D */   daddu    $s0, $zero, $zero
/* 418560 802A37D0 3C11802B */  lui       $s1, %hi(battle_menu_moveOptionCostUnitIconIDs)
/* 418564 802A37D4 2631D190 */  addiu     $s1, $s1, %lo(battle_menu_moveOptionCostUnitIconIDs)
/* 418568 802A37D8 240500A0 */  addiu     $a1, $zero, 0xa0
.L802A37DC:
/* 41856C 802A37DC 00A0302D */  daddu     $a2, $a1, $zero
/* 418570 802A37E0 00A0382D */  daddu     $a3, $a1, $zero
/* 418574 802A37E4 8E240000 */  lw        $a0, ($s1)
/* 418578 802A37E8 0C0513BF */  jal       set_hud_element_tint
/* 41857C 802A37EC 26310004 */   addiu    $s1, $s1, 4
/* 418580 802A37F0 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 418584 802A37F4 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 418588 802A37F8 26100001 */  addiu     $s0, $s0, 1
/* 41858C 802A37FC 0202102A */  slt       $v0, $s0, $v0
/* 418590 802A3800 5440FFF6 */  bnel      $v0, $zero, .L802A37DC
/* 418594 802A3804 240500A0 */   addiu    $a1, $zero, 0xa0
.L802A3808:
/* 418598 802A3808 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorIcon)
/* 41859C 802A380C 8C84D118 */  lw        $a0, %lo(battle_menu_moveCursorIcon)($a0)
/* 4185A0 802A3810 3C058010 */  lui       $a1, %hi(D_80104A00)
/* 4185A4 802A3814 24A54A00 */  addiu     $a1, $a1, %lo(D_80104A00)
/* 4185A8 802A3818 0C0511FF */  jal       set_hud_element_anim
/* 4185AC 802A381C 00000000 */   nop
/* 4185B0 802A3820 24040001 */  addiu     $a0, $zero, 1
/* 4185B4 802A3824 2402000D */  addiu     $v0, $zero, 0xd
/* 4185B8 802A3828 3C01802B */  lui       $at, %hi(battle_menu_moveTextColor)
/* 4185BC 802A382C A422D114 */  sh        $v0, %lo(battle_menu_moveTextColor)($at)
/* 4185C0 802A3830 0C051F9F */  jal       set_window_update
/* 4185C4 802A3834 24050004 */   addiu    $a1, $zero, 4
/* 4185C8 802A3838 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 4185CC 802A383C 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 4185D0 802A3840 54400006 */  bnel      $v0, $zero, .L802A385C
/* 4185D4 802A3844 24040004 */   addiu    $a0, $zero, 4
/* 4185D8 802A3848 24040002 */  addiu     $a0, $zero, 2
/* 4185DC 802A384C 0C051F9F */  jal       set_window_update
/* 4185E0 802A3850 24050004 */   addiu    $a1, $zero, 4
/* 4185E4 802A3854 080A8E1A */  j         .L802A3868
/* 4185E8 802A3858 24040003 */   addiu    $a0, $zero, 3
.L802A385C:
/* 4185EC 802A385C 0C051F9F */  jal       set_window_update
/* 4185F0 802A3860 0080282D */   daddu    $a1, $a0, $zero
/* 4185F4 802A3864 24040005 */  addiu     $a0, $zero, 5
.L802A3868:
/* 4185F8 802A3868 0C051F9F */  jal       set_window_update
/* 4185FC 802A386C 24050004 */   addiu    $a1, $zero, 4
/* 418600 802A3870 24040008 */  addiu     $a0, $zero, 8
/* 418604 802A3874 0C051F9F */  jal       set_window_update
/* 418608 802A3878 24050002 */   addiu    $a1, $zero, 2
/* 41860C 802A387C 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 418610 802A3880 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 418614 802A3884 14400005 */  bnez      $v0, .L802A389C
/* 418618 802A3888 00000000 */   nop
/* 41861C 802A388C 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 418620 802A3890 00000000 */   nop
/* 418624 802A3894 080A8E5D */  j         L802A3974_418704
/* 418628 802A3898 00000000 */   nop
.L802A389C:
/* 41862C 802A389C 0C03A6A5 */  jal       status_menu_stop_blinking_sp
/* 418630 802A38A0 00000000 */   nop
/* 418634 802A38A4 080A8E5D */  j         L802A3974_418704
/* 418638 802A38A8 00000000 */   nop
dlabel L802A38AC_41863C
/* 41863C 802A38AC 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 418640 802A38B0 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 418644 802A38B4 14400005 */  bnez      $v0, .L802A38CC
/* 418648 802A38B8 00000000 */   nop
/* 41864C 802A38BC 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 418650 802A38C0 00000000 */   nop
/* 418654 802A38C4 080A8F1C */  j         .L802A3C70
/* 418658 802A38C8 240200FF */   addiu    $v0, $zero, 0xff
.L802A38CC:
/* 41865C 802A38CC 0C03A6A5 */  jal       status_menu_stop_blinking_sp
/* 418660 802A38D0 00000000 */   nop
/* 418664 802A38D4 080A8F1C */  j         .L802A3C70
/* 418668 802A38D8 240200FF */   addiu    $v0, $zero, 0xff
dlabel L802A38DC_41866C
/* 41866C 802A38DC 24040001 */  addiu     $a0, $zero, 1
/* 418670 802A38E0 0C051F9F */  jal       set_window_update
/* 418674 802A38E4 24050002 */   addiu    $a1, $zero, 2
/* 418678 802A38E8 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 41867C 802A38EC 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 418680 802A38F0 54400006 */  bnel      $v0, $zero, .L802A390C
/* 418684 802A38F4 24040004 */   addiu    $a0, $zero, 4
/* 418688 802A38F8 24040002 */  addiu     $a0, $zero, 2
/* 41868C 802A38FC 0C051F9F */  jal       set_window_update
/* 418690 802A3900 0080282D */   daddu    $a1, $a0, $zero
/* 418694 802A3904 080A8E46 */  j         .L802A3918
/* 418698 802A3908 24040003 */   addiu    $a0, $zero, 3
.L802A390C:
/* 41869C 802A390C 0C051F9F */  jal       set_window_update
/* 4186A0 802A3910 24050002 */   addiu    $a1, $zero, 2
/* 4186A4 802A3914 24040005 */  addiu     $a0, $zero, 5
.L802A3918:
/* 4186A8 802A3918 0C051F9F */  jal       set_window_update
/* 4186AC 802A391C 24050002 */   addiu    $a1, $zero, 2
/* 4186B0 802A3920 24040008 */  addiu     $a0, $zero, 8
/* 4186B4 802A3924 0C051F9F */  jal       set_window_update
/* 4186B8 802A3928 24050002 */   addiu    $a1, $zero, 2
/* 4186BC 802A392C 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 4186C0 802A3930 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 4186C4 802A3934 14400005 */  bnez      $v0, .L802A394C
/* 4186C8 802A3938 00000000 */   nop
/* 4186CC 802A393C 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 4186D0 802A3940 00000000 */   nop
/* 4186D4 802A3944 080A8E55 */  j         .L802A3954
/* 4186D8 802A3948 00000000 */   nop
.L802A394C:
/* 4186DC 802A394C 0C03A6A5 */  jal       status_menu_stop_blinking_sp
/* 4186E0 802A3950 00000000 */   nop
.L802A3954:
/* 4186E4 802A3954 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorPos)
/* 4186E8 802A3958 8084D109 */  lb        $a0, %lo(battle_menu_moveCursorPos)($a0)
/* 4186EC 802A395C 00041080 */  sll       $v0, $a0, 2
/* 4186F0 802A3960 3C01802B */  lui       $at, %hi(battle_menu_moveOptionIndexMap)
/* 4186F4 802A3964 00220821 */  addu      $at, $at, $v0
/* 4186F8 802A3968 8C22D1F8 */  lw        $v0, %lo(battle_menu_moveOptionIndexMap)($at)
/* 4186FC 802A396C 080A8E82 */  j         .L802A3A08
/* 418700 802A3970 2403000B */   addiu    $v1, $zero, 0xb
dlabel L802A3974_418704
/* 418704 802A3974 3C03802B */  lui       $v1, %hi(battle_menu_moveCursorPos)
/* 418708 802A3978 8063D109 */  lb        $v1, %lo(battle_menu_moveCursorPos)($v1)
/* 41870C 802A397C 00031080 */  sll       $v0, $v1, 2
/* 418710 802A3980 3C01802B */  lui       $at, %hi(battle_menu_moveOptionIndexMap)
/* 418714 802A3984 00220821 */  addu      $at, $at, $v0
/* 418718 802A3988 8C22D1F8 */  lw        $v0, %lo(battle_menu_moveOptionIndexMap)($at)
/* 41871C 802A398C 3C01802B */  lui       $at, %hi(battle_menu_moveOptionActive)
/* 418720 802A3990 AC23D600 */  sw        $v1, %lo(battle_menu_moveOptionActive)($at)
/* 418724 802A3994 080A8F1C */  j         .L802A3C70
/* 418728 802A3998 24420001 */   addiu    $v0, $v0, 1
dlabel L802A399C_41872C
/* 41872C 802A399C 24040001 */  addiu     $a0, $zero, 1
/* 418730 802A39A0 0C051F9F */  jal       set_window_update
/* 418734 802A39A4 0080282D */   daddu    $a1, $a0, $zero
/* 418738 802A39A8 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 41873C 802A39AC 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 418740 802A39B0 54400006 */  bnel      $v0, $zero, .L802A39CC
/* 418744 802A39B4 24040004 */   addiu    $a0, $zero, 4
/* 418748 802A39B8 24040002 */  addiu     $a0, $zero, 2
/* 41874C 802A39BC 0C051F9F */  jal       set_window_update
/* 418750 802A39C0 24050001 */   addiu    $a1, $zero, 1
/* 418754 802A39C4 080A8E76 */  j         .L802A39D8
/* 418758 802A39C8 24040003 */   addiu    $a0, $zero, 3
.L802A39CC:
/* 41875C 802A39CC 0C051F9F */  jal       set_window_update
/* 418760 802A39D0 24050001 */   addiu    $a1, $zero, 1
/* 418764 802A39D4 24040005 */  addiu     $a0, $zero, 5
.L802A39D8:
/* 418768 802A39D8 0C051F9F */  jal       set_window_update
/* 41876C 802A39DC 24050001 */   addiu    $a1, $zero, 1
/* 418770 802A39E0 24040008 */  addiu     $a0, $zero, 8
/* 418774 802A39E4 0C051F9F */  jal       set_window_update
/* 418778 802A39E8 24050001 */   addiu    $a1, $zero, 1
/* 41877C 802A39EC 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorPos)
/* 418780 802A39F0 8084D109 */  lb        $a0, %lo(battle_menu_moveCursorPos)($a0)
/* 418784 802A39F4 00041080 */  sll       $v0, $a0, 2
/* 418788 802A39F8 3C01802B */  lui       $at, %hi(battle_menu_moveOptionIndexMap)
/* 41878C 802A39FC 00220821 */  addu      $at, $at, $v0
/* 418790 802A3A00 8C22D1F8 */  lw        $v0, %lo(battle_menu_moveOptionIndexMap)($at)
/* 418794 802A3A04 24030001 */  addiu     $v1, $zero, 1
.L802A3A08:
/* 418798 802A3A08 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 41879C 802A3A0C A023D108 */  sb        $v1, %lo(battle_menu_moveState)($at)
/* 4187A0 802A3A10 3C01802B */  lui       $at, %hi(battle_menu_moveOptionActive)
/* 4187A4 802A3A14 AC24D600 */  sw        $a0, %lo(battle_menu_moveOptionActive)($at)
/* 4187A8 802A3A18 080A8F1C */  j         .L802A3C70
/* 4187AC 802A3A1C 24420001 */   addiu    $v0, $v0, 1
dlabel L802A3A20_4187B0
/* 4187B0 802A3A20 24040001 */  addiu     $a0, $zero, 1
/* 4187B4 802A3A24 0C051F9F */  jal       set_window_update
/* 4187B8 802A3A28 24050009 */   addiu    $a1, $zero, 9
/* 4187BC 802A3A2C 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 4187C0 802A3A30 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 4187C4 802A3A34 54400006 */  bnel      $v0, $zero, .L802A3A50
/* 4187C8 802A3A38 24040004 */   addiu    $a0, $zero, 4
/* 4187CC 802A3A3C 24040002 */  addiu     $a0, $zero, 2
/* 4187D0 802A3A40 0C051F9F */  jal       set_window_update
/* 4187D4 802A3A44 24050009 */   addiu    $a1, $zero, 9
/* 4187D8 802A3A48 080A8E97 */  j         .L802A3A5C
/* 4187DC 802A3A4C 24040003 */   addiu    $a0, $zero, 3
.L802A3A50:
/* 4187E0 802A3A50 0C051F9F */  jal       set_window_update
/* 4187E4 802A3A54 24050009 */   addiu    $a1, $zero, 9
/* 4187E8 802A3A58 24040005 */  addiu     $a0, $zero, 5
.L802A3A5C:
/* 4187EC 802A3A5C 0C051F9F */  jal       set_window_update
/* 4187F0 802A3A60 24050009 */   addiu    $a1, $zero, 9
/* 4187F4 802A3A64 24040008 */  addiu     $a0, $zero, 8
/* 4187F8 802A3A68 0C051F9F */  jal       set_window_update
/* 4187FC 802A3A6C 24050002 */   addiu    $a1, $zero, 2
/* 418800 802A3A70 080A8F19 */  j         .L802A3C64
/* 418804 802A3A74 2402FFFF */   addiu    $v0, $zero, -1
dlabel L802A3A78_418808
/* 418808 802A3A78 2402FFFF */  addiu     $v0, $zero, -1
/* 41880C 802A3A7C 0040182D */  daddu     $v1, $v0, $zero
/* 418810 802A3A80 3C01802B */  lui       $at, %hi(battle_menu_moveOptionActive)
/* 418814 802A3A84 AC23D600 */  sw        $v1, %lo(battle_menu_moveOptionActive)($at)
/* 418818 802A3A88 24030029 */  addiu     $v1, $zero, 0x29
/* 41881C 802A3A8C 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 418820 802A3A90 A023D108 */  sb        $v1, %lo(battle_menu_moveState)($at)
/* 418824 802A3A94 080A8F1C */  j         .L802A3C70
/* 418828 802A3A98 00000000 */   nop
dlabel L802A3A9C_41882C
/* 41882C 802A3A9C 24040001 */  addiu     $a0, $zero, 1
/* 418830 802A3AA0 0C051F9F */  jal       set_window_update
/* 418834 802A3AA4 24050002 */   addiu    $a1, $zero, 2
/* 418838 802A3AA8 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 41883C 802A3AAC 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 418840 802A3AB0 54400006 */  bnel      $v0, $zero, .L802A3ACC
/* 418844 802A3AB4 24040004 */   addiu    $a0, $zero, 4
/* 418848 802A3AB8 24040002 */  addiu     $a0, $zero, 2
/* 41884C 802A3ABC 0C051F9F */  jal       set_window_update
/* 418850 802A3AC0 0080282D */   daddu    $a1, $a0, $zero
/* 418854 802A3AC4 080A8EB6 */  j         .L802A3AD8
/* 418858 802A3AC8 24040003 */   addiu    $a0, $zero, 3
.L802A3ACC:
/* 41885C 802A3ACC 0C051F9F */  jal       set_window_update
/* 418860 802A3AD0 24050002 */   addiu    $a1, $zero, 2
/* 418864 802A3AD4 24040005 */  addiu     $a0, $zero, 5
.L802A3AD8:
/* 418868 802A3AD8 0C051F9F */  jal       set_window_update
/* 41886C 802A3ADC 24050002 */   addiu    $a1, $zero, 2
/* 418870 802A3AE0 24040008 */  addiu     $a0, $zero, 8
/* 418874 802A3AE4 0C051F9F */  jal       set_window_update
/* 418878 802A3AE8 24050002 */   addiu    $a1, $zero, 2
/* 41887C 802A3AEC 3C11001D */  lui       $s1, 0x1d
/* 418880 802A3AF0 3C02802B */  lui       $v0, %hi(D_802AD258)
/* 418884 802A3AF4 8C42D258 */  lw        $v0, %lo(D_802AD258)($v0)
/* 418888 802A3AF8 14400008 */  bnez      $v0, .L802A3B1C
/* 41888C 802A3AFC 363100C3 */   ori      $s1, $s1, 0xc3
/* 418890 802A3B00 3C11001D */  lui       $s1, 0x1d
/* 418894 802A3B04 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 418898 802A3B08 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 41889C 802A3B0C 14400003 */  bnez      $v0, .L802A3B1C
/* 4188A0 802A3B10 363100A0 */   ori      $s1, $s1, 0xa0
/* 4188A4 802A3B14 3C11001D */  lui       $s1, 0x1d
/* 4188A8 802A3B18 3631009F */  ori       $s1, $s1, 0x9f
.L802A3B1C:
/* 4188AC 802A3B1C 0220202D */  daddu     $a0, $s1, $zero
/* 4188B0 802A3B20 0C04991D */  jal       get_msg_width
/* 4188B4 802A3B24 0000282D */   daddu    $a1, $zero, $zero
/* 4188B8 802A3B28 24500017 */  addiu     $s0, $v0, 0x17
/* 4188BC 802A3B2C 001017C2 */  srl       $v0, $s0, 0x1f
/* 4188C0 802A3B30 02021021 */  addu      $v0, $s0, $v0
/* 4188C4 802A3B34 00021043 */  sra       $v0, $v0, 1
/* 4188C8 802A3B38 240300A0 */  addiu     $v1, $zero, 0xa0
/* 4188CC 802A3B3C 00629823 */  subu      $s3, $v1, $v0
/* 4188D0 802A3B40 0C04992C */  jal       get_msg_lines
/* 4188D4 802A3B44 0220202D */   daddu    $a0, $s1, $zero
/* 4188D8 802A3B48 24040009 */  addiu     $a0, $zero, 9
/* 4188DC 802A3B4C 0260282D */  daddu     $a1, $s3, $zero
/* 4188E0 802A3B50 24060050 */  addiu     $a2, $zero, 0x50
/* 4188E4 802A3B54 0200382D */  daddu     $a3, $s0, $zero
/* 4188E8 802A3B58 2442FFFF */  addiu     $v0, $v0, -1
/* 4188EC 802A3B5C 00021040 */  sll       $v0, $v0, 1
/* 4188F0 802A3B60 3C03802B */  lui       $v1, %hi(D_802AB340)
/* 4188F4 802A3B64 00621821 */  addu      $v1, $v1, $v0
/* 4188F8 802A3B68 8463B340 */  lh        $v1, %lo(D_802AB340)($v1)
/* 4188FC 802A3B6C 24020014 */  addiu     $v0, $zero, 0x14
/* 418900 802A3B70 AFA20014 */  sw        $v0, 0x14($sp)
/* 418904 802A3B74 3C02802A */  lui       $v0, %hi(func_802A4534)
/* 418908 802A3B78 24424534 */  addiu     $v0, $v0, %lo(func_802A4534)
/* 41890C 802A3B7C AFA20018 */  sw        $v0, 0x18($sp)
/* 418910 802A3B80 2402FFFF */  addiu     $v0, $zero, -1
/* 418914 802A3B84 AFA0001C */  sw        $zero, 0x1c($sp)
/* 418918 802A3B88 AFA20020 */  sw        $v0, 0x20($sp)
/* 41891C 802A3B8C 0C051F32 */  jal       set_window_properties
/* 418920 802A3B90 AFA30010 */   sw       $v1, 0x10($sp)
/* 418924 802A3B94 24040009 */  addiu     $a0, $zero, 9
/* 418928 802A3B98 0C051F9F */  jal       set_window_update
/* 41892C 802A3B9C 24050001 */   addiu    $a1, $zero, 1
/* 418930 802A3BA0 2403003C */  addiu     $v1, $zero, 0x3c
/* 418934 802A3BA4 3C01802B */  lui       $at, %hi(D_802AD10B)
/* 418938 802A3BA8 A023D10B */  sb        $v1, %lo(D_802AD10B)($at)
/* 41893C 802A3BAC 2403002A */  addiu     $v1, $zero, 0x2a
/* 418940 802A3BB0 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 418944 802A3BB4 A023D108 */  sb        $v1, %lo(battle_menu_moveState)($at)
/* 418948 802A3BB8 080A8F1C */  j         .L802A3C70
/* 41894C 802A3BBC 2402FFFF */   addiu    $v0, $zero, -1
dlabel L802A3BC0_418950
/* 418950 802A3BC0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 418954 802A3BC4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 418958 802A3BC8 8C420010 */  lw        $v0, 0x10($v0)
/* 41895C 802A3BCC 3042C000 */  andi      $v0, $v0, 0xc000
/* 418960 802A3BD0 10400003 */  beqz      $v0, .L802A3BE0
/* 418964 802A3BD4 00000000 */   nop
/* 418968 802A3BD8 3C01802B */  lui       $at, %hi(D_802AD10B)
/* 41896C 802A3BDC A020D10B */  sb        $zero, %lo(D_802AD10B)($at)
.L802A3BE0:
/* 418970 802A3BE0 3C04802B */  lui       $a0, %hi(D_802AD10B)
/* 418974 802A3BE4 2484D10B */  addiu     $a0, $a0, %lo(D_802AD10B)
/* 418978 802A3BE8 80820000 */  lb        $v0, ($a0)
/* 41897C 802A3BEC 90830000 */  lbu       $v1, ($a0)
/* 418980 802A3BF0 10400004 */  beqz      $v0, .L802A3C04
/* 418984 802A3BF4 2462FFFF */   addiu    $v0, $v1, -1
/* 418988 802A3BF8 A0820000 */  sb        $v0, ($a0)
/* 41898C 802A3BFC 080A8F1C */  j         .L802A3C70
/* 418990 802A3C00 2402FFFF */   addiu    $v0, $zero, -1
.L802A3C04:
/* 418994 802A3C04 24040009 */  addiu     $a0, $zero, 9
/* 418998 802A3C08 0C051F9F */  jal       set_window_update
/* 41899C 802A3C0C 24050002 */   addiu    $a1, $zero, 2
/* 4189A0 802A3C10 24040001 */  addiu     $a0, $zero, 1
/* 4189A4 802A3C14 0C051F9F */  jal       set_window_update
/* 4189A8 802A3C18 0080282D */   daddu    $a1, $a0, $zero
/* 4189AC 802A3C1C 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 4189B0 802A3C20 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 4189B4 802A3C24 54400006 */  bnel      $v0, $zero, .L802A3C40
/* 4189B8 802A3C28 24040004 */   addiu    $a0, $zero, 4
/* 4189BC 802A3C2C 24040002 */  addiu     $a0, $zero, 2
/* 4189C0 802A3C30 0C051F9F */  jal       set_window_update
/* 4189C4 802A3C34 24050001 */   addiu    $a1, $zero, 1
/* 4189C8 802A3C38 080A8F13 */  j         .L802A3C4C
/* 4189CC 802A3C3C 24040003 */   addiu    $a0, $zero, 3
.L802A3C40:
/* 4189D0 802A3C40 0C051F9F */  jal       set_window_update
/* 4189D4 802A3C44 24050001 */   addiu    $a1, $zero, 1
/* 4189D8 802A3C48 24040005 */  addiu     $a0, $zero, 5
.L802A3C4C:
/* 4189DC 802A3C4C 0C051F9F */  jal       set_window_update
/* 4189E0 802A3C50 24050001 */   addiu    $a1, $zero, 1
/* 4189E4 802A3C54 24040008 */  addiu     $a0, $zero, 8
/* 4189E8 802A3C58 0C051F9F */  jal       set_window_update
/* 4189EC 802A3C5C 24050001 */   addiu    $a1, $zero, 1
/* 4189F0 802A3C60 24020001 */  addiu     $v0, $zero, 1
.L802A3C64:
/* 4189F4 802A3C64 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 4189F8 802A3C68 A022D108 */  sb        $v0, %lo(battle_menu_moveState)($at)
dlabel L802A3C6C_4189FC
/* 4189FC 802A3C6C 0000102D */  daddu     $v0, $zero, $zero
.L802A3C70:
/* 418A00 802A3C70 8FBF0044 */  lw        $ra, 0x44($sp)
/* 418A04 802A3C74 8FB60040 */  lw        $s6, 0x40($sp)
/* 418A08 802A3C78 8FB5003C */  lw        $s5, 0x3c($sp)
/* 418A0C 802A3C7C 8FB40038 */  lw        $s4, 0x38($sp)
/* 418A10 802A3C80 8FB30034 */  lw        $s3, 0x34($sp)
/* 418A14 802A3C84 8FB20030 */  lw        $s2, 0x30($sp)
/* 418A18 802A3C88 8FB1002C */  lw        $s1, 0x2c($sp)
/* 418A1C 802A3C8C 8FB00028 */  lw        $s0, 0x28($sp)
/* 418A20 802A3C90 03E00008 */  jr        $ra
/* 418A24 802A3C94 27BD0048 */   addiu    $sp, $sp, 0x48

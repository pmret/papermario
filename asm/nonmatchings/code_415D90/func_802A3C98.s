.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A3C98
/* 418A28 802A3C98 3C02802B */  lui       $v0, %hi(battle_menu_moveState)
/* 418A2C 802A3C9C 9042D108 */  lbu       $v0, %lo(battle_menu_moveState)($v0)
/* 418A30 802A3CA0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 418A34 802A3CA4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 418A38 802A3CA8 AFBE0040 */  sw        $fp, 0x40($sp)
/* 418A3C 802A3CAC AFB7003C */  sw        $s7, 0x3c($sp)
/* 418A40 802A3CB0 AFB60038 */  sw        $s6, 0x38($sp)
/* 418A44 802A3CB4 AFB50034 */  sw        $s5, 0x34($sp)
/* 418A48 802A3CB8 AFB40030 */  sw        $s4, 0x30($sp)
/* 418A4C 802A3CBC AFB3002C */  sw        $s3, 0x2c($sp)
/* 418A50 802A3CC0 AFB20028 */  sw        $s2, 0x28($sp)
/* 418A54 802A3CC4 AFB10024 */  sw        $s1, 0x24($sp)
/* 418A58 802A3CC8 AFB00020 */  sw        $s0, 0x20($sp)
/* 418A5C 802A3CCC AFA5004C */  sw        $a1, 0x4c($sp)
/* 418A60 802A3CD0 24420001 */  addiu     $v0, $v0, 1
/* 418A64 802A3CD4 00021600 */  sll       $v0, $v0, 0x18
/* 418A68 802A3CD8 00021E03 */  sra       $v1, $v0, 0x18
/* 418A6C 802A3CDC 2C62002B */  sltiu     $v0, $v1, 0x2b
/* 418A70 802A3CE0 104001B2 */  beqz      $v0, .L802A43AC
/* 418A74 802A3CE4 AFA60050 */   sw       $a2, 0x50($sp)
/* 418A78 802A3CE8 00031080 */  sll       $v0, $v1, 2
/* 418A7C 802A3CEC 3C01802B */  lui       $at, %hi(jtbl_802AB8C0)
/* 418A80 802A3CF0 00220821 */  addu      $at, $at, $v0
/* 418A84 802A3CF4 8C22B8C0 */  lw        $v0, %lo(jtbl_802AB8C0)($at)
/* 418A88 802A3CF8 00400008 */  jr        $v0
/* 418A8C 802A3CFC 00000000 */   nop
glabel L802A3D00_418A90
/* 418A90 802A3D00 3C03802B */  lui       $v1, %hi(battle_menu_moveScrollLine)
/* 418A94 802A3D04 8063D10C */  lb        $v1, %lo(battle_menu_moveScrollLine)($v1)
/* 418A98 802A3D08 3C08802B */  lui       $t0, %hi(battle_menu_moveScrollOffset)
/* 418A9C 802A3D0C 8508D110 */  lh        $t0, %lo(battle_menu_moveScrollOffset)($t0)
/* 418AA0 802A3D10 3C013FE0 */  lui       $at, 0x3fe0
/* 418AA4 802A3D14 44811800 */  mtc1      $at, $f3
/* 418AA8 802A3D18 44801000 */  mtc1      $zero, $f2
/* 418AAC 802A3D1C 00031823 */  negu      $v1, $v1
/* 418AB0 802A3D20 00031040 */  sll       $v0, $v1, 1
/* 418AB4 802A3D24 00431021 */  addu      $v0, $v0, $v1
/* 418AB8 802A3D28 00021080 */  sll       $v0, $v0, 2
/* 418ABC 802A3D2C 00438821 */  addu      $s1, $v0, $v1
/* 418AC0 802A3D30 02281023 */  subu      $v0, $s1, $t0
/* 418AC4 802A3D34 44820000 */  mtc1      $v0, $f0
/* 418AC8 802A3D38 00000000 */  nop
/* 418ACC 802A3D3C 46800021 */  cvt.d.w   $f0, $f0
/* 418AD0 802A3D40 46220002 */  mul.d     $f0, $f0, $f2
/* 418AD4 802A3D44 00000000 */  nop
/* 418AD8 802A3D48 4620018D */  trunc.w.d $f6, $f0
/* 418ADC 802A3D4C 44023000 */  mfc1      $v0, $f6
/* 418AE0 802A3D50 00000000 */  nop
/* 418AE4 802A3D54 14400002 */  bnez      $v0, .L802A3D60
/* 418AE8 802A3D58 01024021 */   addu     $t0, $t0, $v0
/* 418AEC 802A3D5C 0220402D */  daddu     $t0, $s1, $zero
.L802A3D60:
/* 418AF0 802A3D60 0000982D */  daddu     $s3, $zero, $zero
/* 418AF4 802A3D64 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 418AF8 802A3D68 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 418AFC 802A3D6C 3C05802B */  lui       $a1, %hi(battle_menu_moveScrollOffset)
/* 418B00 802A3D70 24A5D110 */  addiu     $a1, $a1, %lo(battle_menu_moveScrollOffset)
/* 418B04 802A3D74 8FA9004C */  lw        $t1, 0x4c($sp)
/* 418B08 802A3D78 8CC40000 */  lw        $a0, ($a2)
/* 418B0C 802A3D7C 3C03802B */  lui       $v1, %hi(D_802AD10E)
/* 418B10 802A3D80 8063D10E */  lb        $v1, %lo(D_802AD10E)($v1)
/* 418B14 802A3D84 3C014080 */  lui       $at, 0x4080
/* 418B18 802A3D88 44812000 */  mtc1      $at, $f4
/* 418B1C 802A3D8C 25350002 */  addiu     $s5, $t1, 2
/* 418B20 802A3D90 44951000 */  mtc1      $s5, $f2
/* 418B24 802A3D94 00000000 */  nop
/* 418B28 802A3D98 468010A0 */  cvt.s.w   $f2, $f2
/* 418B2C 802A3D9C 00031040 */  sll       $v0, $v1, 1
/* 418B30 802A3DA0 00431021 */  addu      $v0, $v0, $v1
/* 418B34 802A3DA4 00021080 */  sll       $v0, $v0, 2
/* 418B38 802A3DA8 00431021 */  addu      $v0, $v0, $v1
/* 418B3C 802A3DAC 24420001 */  addiu     $v0, $v0, 1
/* 418B40 802A3DB0 0080382D */  daddu     $a3, $a0, $zero
/* 418B44 802A3DB4 8FA90050 */  lw        $t1, 0x50($sp)
/* 418B48 802A3DB8 46041082 */  mul.s     $f2, $f2, $f4
/* 418B4C 802A3DBC 00000000 */  nop
/* 418B50 802A3DC0 25310012 */  addiu     $s1, $t1, 0x12
/* 418B54 802A3DC4 8FA9004C */  lw        $t1, 0x4c($sp)
/* 418B58 802A3DC8 24840008 */  addiu     $a0, $a0, 8
/* 418B5C 802A3DCC A4A80000 */  sh        $t0, ($a1)
/* 418B60 802A3DD0 02224021 */  addu      $t0, $s1, $v0
/* 418B64 802A3DD4 44910000 */  mtc1      $s1, $f0
/* 418B68 802A3DD8 00000000 */  nop
/* 418B6C 802A3DDC 46800020 */  cvt.s.w   $f0, $f0
/* 418B70 802A3DE0 46040002 */  mul.s     $f0, $f0, $f4
/* 418B74 802A3DE4 00000000 */  nop
/* 418B78 802A3DE8 84A20000 */  lh        $v0, ($a1)
/* 418B7C 802A3DEC 2535001F */  addiu     $s5, $t1, 0x1f
/* 418B80 802A3DF0 8FA90050 */  lw        $t1, 0x50($sp)
/* 418B84 802A3DF4 24420013 */  addiu     $v0, $v0, 0x13
/* 418B88 802A3DF8 ACC40000 */  sw        $a0, ($a2)
/* 418B8C 802A3DFC 01228821 */  addu      $s1, $t1, $v0
/* 418B90 802A3E00 4600118D */  trunc.w.s $f6, $f2
/* 418B94 802A3E04 44033000 */  mfc1      $v1, $f6
/* 418B98 802A3E08 00000000 */  nop
/* 418B9C 802A3E0C 30630FFF */  andi      $v1, $v1, 0xfff
/* 418BA0 802A3E10 00031B00 */  sll       $v1, $v1, 0xc
/* 418BA4 802A3E14 4600018D */  trunc.w.s $f6, $f0
/* 418BA8 802A3E18 44043000 */  mfc1      $a0, $f6
/* 418BAC 802A3E1C 00000000 */  nop
/* 418BB0 802A3E20 30840FFF */  andi      $a0, $a0, 0xfff
/* 418BB4 802A3E24 8FA9004C */  lw        $t1, 0x4c($sp)
/* 418BB8 802A3E28 44880000 */  mtc1      $t0, $f0
/* 418BBC 802A3E2C 00000000 */  nop
/* 418BC0 802A3E30 46800020 */  cvt.s.w   $f0, $f0
/* 418BC4 802A3E34 25220099 */  addiu     $v0, $t1, 0x99
/* 418BC8 802A3E38 44821000 */  mtc1      $v0, $f2
/* 418BCC 802A3E3C 00000000 */  nop
/* 418BD0 802A3E40 468010A0 */  cvt.s.w   $f2, $f2
/* 418BD4 802A3E44 46041082 */  mul.s     $f2, $f2, $f4
/* 418BD8 802A3E48 00000000 */  nop
/* 418BDC 802A3E4C 3C02ED00 */  lui       $v0, 0xed00
/* 418BE0 802A3E50 00822025 */  or        $a0, $a0, $v0
/* 418BE4 802A3E54 00641825 */  or        $v1, $v1, $a0
/* 418BE8 802A3E58 3C04802B */  lui       $a0, %hi(battle_menu_moveOptionCount)
/* 418BEC 802A3E5C 8C84D4A4 */  lw        $a0, %lo(battle_menu_moveOptionCount)($a0)
/* 418BF0 802A3E60 46040002 */  mul.s     $f0, $f0, $f4
/* 418BF4 802A3E64 00000000 */  nop
/* 418BF8 802A3E68 ACE30000 */  sw        $v1, ($a3)
/* 418BFC 802A3E6C 4600118D */  trunc.w.s $f6, $f2
/* 418C00 802A3E70 44023000 */  mfc1      $v0, $f6
/* 418C04 802A3E74 00000000 */  nop
/* 418C08 802A3E78 30420FFF */  andi      $v0, $v0, 0xfff
/* 418C0C 802A3E7C 00021300 */  sll       $v0, $v0, 0xc
/* 418C10 802A3E80 4600018D */  trunc.w.s $f6, $f0
/* 418C14 802A3E84 44033000 */  mfc1      $v1, $f6
/* 418C18 802A3E88 00000000 */  nop
/* 418C1C 802A3E8C 30630FFF */  andi      $v1, $v1, 0xfff
/* 418C20 802A3E90 00431025 */  or        $v0, $v0, $v1
/* 418C24 802A3E94 188000BC */  blez      $a0, .L802A4188
/* 418C28 802A3E98 ACE20004 */   sw       $v0, 4($a3)
/* 418C2C 802A3E9C 3C16802B */  lui       $s6, %hi(battle_menu_moveOptionsEnabled)
/* 418C30 802A3EA0 26D6D510 */  addiu     $s6, $s6, %lo(battle_menu_moveOptionsEnabled)
/* 418C34 802A3EA4 3C1E802B */  lui       $fp, %hi(battle_menu_moveOptionDisplayCosts)
/* 418C38 802A3EA8 27DED320 */  addiu     $fp, $fp, %lo(battle_menu_moveOptionDisplayCosts)
/* 418C3C 802A3EAC 3C14802B */  lui       $s4, %hi(battle_menu_moveOptionIndexMap)
/* 418C40 802A3EB0 2694D1F8 */  addiu     $s4, $s4, %lo(battle_menu_moveOptionIndexMap)
/* 418C44 802A3EB4 0260B82D */  daddu     $s7, $s3, $zero
.L802A3EB8:
/* 418C48 802A3EB8 3C03802B */  lui       $v1, %hi(battle_menu_moveScrollLine)
/* 418C4C 802A3EBC 8063D10C */  lb        $v1, %lo(battle_menu_moveScrollLine)($v1)
/* 418C50 802A3EC0 2462FFFF */  addiu     $v0, $v1, -1
/* 418C54 802A3EC4 0262102A */  slt       $v0, $s3, $v0
/* 418C58 802A3EC8 544000A7 */  bnel      $v0, $zero, .L802A4168
/* 418C5C 802A3ECC 2631000D */   addiu    $s1, $s1, 0xd
/* 418C60 802A3ED0 3C02802B */  lui       $v0, %hi(D_802AD10E)
/* 418C64 802A3ED4 8042D10E */  lb        $v0, %lo(D_802AD10E)($v0)
/* 418C68 802A3ED8 00621021 */  addu      $v0, $v1, $v0
/* 418C6C 802A3EDC 0053102A */  slt       $v0, $v0, $s3
/* 418C70 802A3EE0 544000A1 */  bnel      $v0, $zero, .L802A4168
/* 418C74 802A3EE4 2631000D */   addiu    $s1, $s1, 0xd
/* 418C78 802A3EE8 8E820000 */  lw        $v0, ($s4)
/* 418C7C 802A3EEC 00022080 */  sll       $a0, $v0, 2
/* 418C80 802A3EF0 00961021 */  addu      $v0, $a0, $s6
/* 418C84 802A3EF4 8C420000 */  lw        $v0, ($v0)
/* 418C88 802A3EF8 3C08802B */  lui       $t0, %hi(battle_menu_moveTextColor)
/* 418C8C 802A3EFC 8508D114 */  lh        $t0, %lo(battle_menu_moveTextColor)($t0)
/* 418C90 802A3F00 58400001 */  blezl     $v0, .L802A3F08
/* 418C94 802A3F04 2408000B */   addiu    $t0, $zero, 0xb
.L802A3F08:
/* 418C98 802A3F08 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionNames)
/* 418C9C 802A3F0C 2442D2C0 */  addiu     $v0, $v0, %lo(battle_menu_moveOptionNames)
/* 418CA0 802A3F10 00822021 */  addu      $a0, $a0, $v0
/* 418CA4 802A3F14 8C820000 */  lw        $v0, ($a0)
/* 418CA8 802A3F18 04400009 */  bltz      $v0, .L802A3F40
/* 418CAC 802A3F1C 02A0282D */   daddu    $a1, $s5, $zero
/* 418CB0 802A3F20 3C07802B */  lui       $a3, %hi(battle_menu_moveTextOpacity)
/* 418CB4 802A3F24 84E7D116 */  lh        $a3, %lo(battle_menu_moveTextOpacity)($a3)
/* 418CB8 802A3F28 24020001 */  addiu     $v0, $zero, 1
/* 418CBC 802A3F2C AFA80010 */  sw        $t0, 0x10($sp)
/* 418CC0 802A3F30 AFA20014 */  sw        $v0, 0x14($sp)
/* 418CC4 802A3F34 8C840000 */  lw        $a0, ($a0)
/* 418CC8 802A3F38 0C04993B */  jal       draw_string
/* 418CCC 802A3F3C 0220302D */   daddu    $a2, $s1, $zero
.L802A3F40:
/* 418CD0 802A3F40 8E820000 */  lw        $v0, ($s4)
/* 418CD4 802A3F44 00021880 */  sll       $v1, $v0, 2
/* 418CD8 802A3F48 3C04802B */  lui       $a0, %hi(battle_menu_moveOptionDisplayCostReductions)
/* 418CDC 802A3F4C 00832021 */  addu      $a0, $a0, $v1
/* 418CE0 802A3F50 8C84D380 */  lw        $a0, %lo(battle_menu_moveOptionDisplayCostReductions)($a0)
/* 418CE4 802A3F54 007E1021 */  addu      $v0, $v1, $fp
/* 418CE8 802A3F58 8C420000 */  lw        $v0, ($v0)
/* 418CEC 802A3F5C 10400003 */  beqz      $v0, .L802A3F6C
/* 418CF0 802A3F60 00449023 */   subu     $s2, $v0, $a0
/* 418CF4 802A3F64 5A400001 */  blezl     $s2, .L802A3F6C
/* 418CF8 802A3F68 24120001 */   addiu    $s2, $zero, 1
.L802A3F6C:
/* 418CFC 802A3F6C 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 418D00 802A3F70 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 418D04 802A3F74 14400015 */  bnez      $v0, .L802A3FCC
/* 418D08 802A3F78 00000000 */   nop
/* 418D0C 802A3F7C 3C02802B */  lui       $v0, %hi(battle_menu_moveCursorPos)
/* 418D10 802A3F80 8042D109 */  lb        $v0, %lo(battle_menu_moveCursorPos)($v0)
/* 418D14 802A3F84 16620025 */  bne       $s3, $v0, .L802A401C
/* 418D18 802A3F88 00131080 */   sll      $v0, $s3, 2
/* 418D1C 802A3F8C 12400007 */  beqz      $s2, .L802A3FAC
/* 418D20 802A3F90 00000000 */   nop
/* 418D24 802A3F94 8E820000 */  lw        $v0, ($s4)
/* 418D28 802A3F98 00021080 */  sll       $v0, $v0, 2
/* 418D2C 802A3F9C 00561021 */  addu      $v0, $v0, $s6
/* 418D30 802A3FA0 8C420000 */  lw        $v0, ($v0)
/* 418D34 802A3FA4 1C400005 */  bgtz      $v0, .L802A3FBC
/* 418D38 802A3FA8 00000000 */   nop
.L802A3FAC:
/* 418D3C 802A3FAC 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 418D40 802A3FB0 00000000 */   nop
/* 418D44 802A3FB4 080A9007 */  j         .L802A401C
/* 418D48 802A3FB8 00131080 */   sll      $v0, $s3, 2
.L802A3FBC:
/* 418D4C 802A3FBC 0C03A663 */  jal       status_menu_start_blinking_fp
/* 418D50 802A3FC0 00000000 */   nop
/* 418D54 802A3FC4 080A9007 */  j         .L802A401C
/* 418D58 802A3FC8 00131080 */   sll      $v0, $s3, 2
.L802A3FCC:
/* 418D5C 802A3FCC 3C02802B */  lui       $v0, %hi(battle_menu_moveCursorPos)
/* 418D60 802A3FD0 8042D109 */  lb        $v0, %lo(battle_menu_moveCursorPos)($v0)
/* 418D64 802A3FD4 16620011 */  bne       $s3, $v0, .L802A401C
/* 418D68 802A3FD8 00131080 */   sll      $v0, $s3, 2
/* 418D6C 802A3FDC 12400007 */  beqz      $s2, .L802A3FFC
/* 418D70 802A3FE0 00000000 */   nop
/* 418D74 802A3FE4 8E820000 */  lw        $v0, ($s4)
/* 418D78 802A3FE8 00021880 */  sll       $v1, $v0, 2
/* 418D7C 802A3FEC 00761021 */  addu      $v0, $v1, $s6
/* 418D80 802A3FF0 8C420000 */  lw        $v0, ($v0)
/* 418D84 802A3FF4 1C400005 */  bgtz      $v0, .L802A400C
/* 418D88 802A3FF8 007E1021 */   addu     $v0, $v1, $fp
.L802A3FFC:
/* 418D8C 802A3FFC 0C03A6A5 */  jal       status_menu_stop_blinking_sp
/* 418D90 802A4000 00000000 */   nop
/* 418D94 802A4004 080A9007 */  j         .L802A401C
/* 418D98 802A4008 00131080 */   sll      $v0, $s3, 2
.L802A400C:
/* 418D9C 802A400C 8C440000 */  lw        $a0, ($v0)
/* 418DA0 802A4010 0C03A6AE */  jal       status_menu_start_blinking_sp_bars
/* 418DA4 802A4014 00000000 */   nop
/* 418DA8 802A4018 00131080 */  sll       $v0, $s3, 2
.L802A401C:
/* 418DAC 802A401C 3C03802B */  lui       $v1, %hi(battle_menu_moveOptionDisplayCostReductionColors)
/* 418DB0 802A4020 00621821 */  addu      $v1, $v1, $v0
/* 418DB4 802A4024 8C63D3E0 */  lw        $v1, %lo(battle_menu_moveOptionDisplayCostReductionColors)($v1)
/* 418DB8 802A4028 10600005 */  beqz      $v1, .L802A4040
/* 418DBC 802A402C 24020001 */   addiu    $v0, $zero, 1
/* 418DC0 802A4030 10620005 */  beq       $v1, $v0, .L802A4048
/* 418DC4 802A4034 24080038 */   addiu    $t0, $zero, 0x38
/* 418DC8 802A4038 080A9013 */  j         .L802A404C
/* 418DCC 802A403C 00000000 */   nop
.L802A4040:
/* 418DD0 802A4040 080A9013 */  j         .L802A404C
/* 418DD4 802A4044 2408000A */   addiu    $t0, $zero, 0xa
.L802A4048:
/* 418DD8 802A4048 24080037 */  addiu     $t0, $zero, 0x37
.L802A404C:
/* 418DDC 802A404C 8E820000 */  lw        $v0, ($s4)
/* 418DE0 802A4050 00021880 */  sll       $v1, $v0, 2
/* 418DE4 802A4054 00761021 */  addu      $v0, $v1, $s6
/* 418DE8 802A4058 8C420000 */  lw        $v0, ($v0)
/* 418DEC 802A405C 58400001 */  blezl     $v0, .L802A4064
/* 418DF0 802A4060 2408000B */   addiu    $t0, $zero, 0xb
.L802A4064:
/* 418DF4 802A4064 007E1021 */  addu      $v0, $v1, $fp
/* 418DF8 802A4068 8C420000 */  lw        $v0, ($v0)
/* 418DFC 802A406C 5040003E */  beql      $v0, $zero, .L802A4168
/* 418E00 802A4070 2631000D */   addiu    $s1, $s1, 0xd
/* 418E04 802A4074 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 418E08 802A4078 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 418E0C 802A407C 3C10802B */  lui       $s0, %hi(battle_menu_moveOptionCostUnitIconIDs)
/* 418E10 802A4080 02178021 */  addu      $s0, $s0, $s7
/* 418E14 802A4084 8E10D190 */  lw        $s0, %lo(battle_menu_moveOptionCostUnitIconIDs)($s0)
/* 418E18 802A4088 14400018 */  bnez      $v0, .L802A40EC
/* 418E1C 802A408C 0240202D */   daddu    $a0, $s2, $zero
/* 418E20 802A4090 26A5006C */  addiu     $a1, $s5, 0x6c
/* 418E24 802A4094 0220302D */  daddu     $a2, $s1, $zero
/* 418E28 802A4098 24070001 */  addiu     $a3, $zero, 1
/* 418E2C 802A409C 3C03802B */  lui       $v1, %hi(battle_menu_moveTextOpacity)
/* 418E30 802A40A0 8463D116 */  lh        $v1, %lo(battle_menu_moveTextOpacity)($v1)
/* 418E34 802A40A4 24020003 */  addiu     $v0, $zero, 3
/* 418E38 802A40A8 AFA80010 */  sw        $t0, 0x10($sp)
/* 418E3C 802A40AC AFA20018 */  sw        $v0, 0x18($sp)
/* 418E40 802A40B0 0C049DA7 */  jal       draw_number
/* 418E44 802A40B4 AFA30014 */   sw       $v1, 0x14($sp)
/* 418E48 802A40B8 8E820000 */  lw        $v0, ($s4)
/* 418E4C 802A40BC 00021080 */  sll       $v0, $v0, 2
/* 418E50 802A40C0 00561021 */  addu      $v0, $v0, $s6
/* 418E54 802A40C4 8C420000 */  lw        $v0, ($v0)
/* 418E58 802A40C8 5C400006 */  bgtzl     $v0, .L802A40E4
/* 418E5C 802A40CC 0200202D */   daddu    $a0, $s0, $zero
/* 418E60 802A40D0 3C058010 */  lui       $a1, %hi(D_801076BC)
/* 418E64 802A40D4 24A576BC */  addiu     $a1, $a1, %lo(D_801076BC)
/* 418E68 802A40D8 0C0511FF */  jal       set_menu_icon_script
/* 418E6C 802A40DC 0200202D */   daddu    $a0, $s0, $zero
/* 418E70 802A40E0 0200202D */  daddu     $a0, $s0, $zero
.L802A40E4:
/* 418E74 802A40E4 080A9051 */  j         .L802A4144
/* 418E78 802A40E8 26A50074 */   addiu    $a1, $s5, 0x74
.L802A40EC:
/* 418E7C 802A40EC 26A5005D */  addiu     $a1, $s5, 0x5d
/* 418E80 802A40F0 0220302D */  daddu     $a2, $s1, $zero
/* 418E84 802A40F4 24070001 */  addiu     $a3, $zero, 1
/* 418E88 802A40F8 3C03802B */  lui       $v1, %hi(battle_menu_moveTextOpacity)
/* 418E8C 802A40FC 8463D116 */  lh        $v1, %lo(battle_menu_moveTextOpacity)($v1)
/* 418E90 802A4100 24020003 */  addiu     $v0, $zero, 3
/* 418E94 802A4104 AFA80010 */  sw        $t0, 0x10($sp)
/* 418E98 802A4108 AFA20018 */  sw        $v0, 0x18($sp)
/* 418E9C 802A410C 0C049DA7 */  jal       draw_number
/* 418EA0 802A4110 AFA30014 */   sw       $v1, 0x14($sp)
/* 418EA4 802A4114 8E820000 */  lw        $v0, ($s4)
/* 418EA8 802A4118 00021080 */  sll       $v0, $v0, 2
/* 418EAC 802A411C 00561021 */  addu      $v0, $v0, $s6
/* 418EB0 802A4120 8C420000 */  lw        $v0, ($v0)
/* 418EB4 802A4124 5C400006 */  bgtzl     $v0, .L802A4140
/* 418EB8 802A4128 0200202D */   daddu    $a0, $s0, $zero
/* 418EBC 802A412C 3C058010 */  lui       $a1, %hi(D_8010776C)
/* 418EC0 802A4130 24A5776C */  addiu     $a1, $a1, %lo(D_8010776C)
/* 418EC4 802A4134 0C0511FF */  jal       set_menu_icon_script
/* 418EC8 802A4138 0200202D */   daddu    $a0, $s0, $zero
/* 418ECC 802A413C 0200202D */  daddu     $a0, $s0, $zero
.L802A4140:
/* 418ED0 802A4140 26A50066 */  addiu     $a1, $s5, 0x66
.L802A4144:
/* 418ED4 802A4144 0C051261 */  jal       set_icon_render_pos
/* 418ED8 802A4148 26260007 */   addiu    $a2, $s1, 7
/* 418EDC 802A414C 3C05802B */  lui       $a1, %hi(battle_menu_moveTextOpacity)
/* 418EE0 802A4150 84A5D116 */  lh        $a1, %lo(battle_menu_moveTextOpacity)($a1)
/* 418EE4 802A4154 0C0513AC */  jal       icon_set_opacity
/* 418EE8 802A4158 0200202D */   daddu    $a0, $s0, $zero
/* 418EEC 802A415C 0C0511F8 */  jal       draw_icon_2
/* 418EF0 802A4160 0200202D */   daddu    $a0, $s0, $zero
/* 418EF4 802A4164 2631000D */  addiu     $s1, $s1, 0xd
.L802A4168:
/* 418EF8 802A4168 26730001 */  addiu     $s3, $s3, 1
/* 418EFC 802A416C 26940004 */  addiu     $s4, $s4, 4
/* 418F00 802A4170 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 418F04 802A4174 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 418F08 802A4178 0262102A */  slt       $v0, $s3, $v0
/* 418F0C 802A417C 1440FF4E */  bnez      $v0, .L802A3EB8
/* 418F10 802A4180 26F70004 */   addiu    $s7, $s7, 4
/* 418F14 802A4184 0000982D */  daddu     $s3, $zero, $zero
.L802A4188:
/* 418F18 802A4188 8FA9004C */  lw        $t1, 0x4c($sp)
/* 418F1C 802A418C 3C02802B */  lui       $v0, %hi(battle_menu_moveScrollOffset)
/* 418F20 802A4190 8442D110 */  lh        $v0, %lo(battle_menu_moveScrollOffset)($v0)
/* 418F24 802A4194 25350018 */  addiu     $s5, $t1, 0x18
/* 418F28 802A4198 8FA90050 */  lw        $t1, 0x50($sp)
/* 418F2C 802A419C 3C03802B */  lui       $v1, %hi(battle_menu_moveOptionCount)
/* 418F30 802A41A0 8C63D4A4 */  lw        $v1, %lo(battle_menu_moveOptionCount)($v1)
/* 418F34 802A41A4 00491021 */  addu      $v0, $v0, $t1
/* 418F38 802A41A8 18600022 */  blez      $v1, .L802A4234
/* 418F3C 802A41AC 24510018 */   addiu    $s1, $v0, 0x18
/* 418F40 802A41B0 3C12802B */  lui       $s2, %hi(battle_menu_moveOptionIconIDs)
/* 418F44 802A41B4 2652D128 */  addiu     $s2, $s2, %lo(battle_menu_moveOptionIconIDs)
.L802A41B8:
/* 418F48 802A41B8 3C03802B */  lui       $v1, %hi(battle_menu_moveScrollLine)
/* 418F4C 802A41BC 8063D10C */  lb        $v1, %lo(battle_menu_moveScrollLine)($v1)
/* 418F50 802A41C0 2462FFFF */  addiu     $v0, $v1, -1
/* 418F54 802A41C4 0262102A */  slt       $v0, $s3, $v0
/* 418F58 802A41C8 54400014 */  bnel      $v0, $zero, .L802A421C
/* 418F5C 802A41CC 2631000D */   addiu    $s1, $s1, 0xd
/* 418F60 802A41D0 3C02802B */  lui       $v0, %hi(D_802AD10E)
/* 418F64 802A41D4 8042D10E */  lb        $v0, %lo(D_802AD10E)($v0)
/* 418F68 802A41D8 00621021 */  addu      $v0, $v1, $v0
/* 418F6C 802A41DC 0053102A */  slt       $v0, $v0, $s3
/* 418F70 802A41E0 10400003 */  beqz      $v0, .L802A41F0
/* 418F74 802A41E4 02A0282D */   daddu    $a1, $s5, $zero
/* 418F78 802A41E8 080A9087 */  j         .L802A421C
/* 418F7C 802A41EC 2631000D */   addiu    $s1, $s1, 0xd
.L802A41F0:
/* 418F80 802A41F0 0220302D */  daddu     $a2, $s1, $zero
/* 418F84 802A41F4 8E500000 */  lw        $s0, ($s2)
/* 418F88 802A41F8 2631000D */  addiu     $s1, $s1, 0xd
/* 418F8C 802A41FC 0C051261 */  jal       set_icon_render_pos
/* 418F90 802A4200 0200202D */   daddu    $a0, $s0, $zero
/* 418F94 802A4204 3C05802B */  lui       $a1, %hi(battle_menu_moveTextOpacity)
/* 418F98 802A4208 84A5D116 */  lh        $a1, %lo(battle_menu_moveTextOpacity)($a1)
/* 418F9C 802A420C 0C0513AC */  jal       icon_set_opacity
/* 418FA0 802A4210 0200202D */   daddu    $a0, $s0, $zero
/* 418FA4 802A4214 0C0511F8 */  jal       draw_icon_2
/* 418FA8 802A4218 0200202D */   daddu    $a0, $s0, $zero
.L802A421C:
/* 418FAC 802A421C 26730001 */  addiu     $s3, $s3, 1
/* 418FB0 802A4220 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 418FB4 802A4224 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 418FB8 802A4228 0262102A */  slt       $v0, $s3, $v0
/* 418FBC 802A422C 1440FFE2 */  bnez      $v0, .L802A41B8
/* 418FC0 802A4230 26520004 */   addiu    $s2, $s2, 4
.L802A4234:
/* 418FC4 802A4234 8FA9004C */  lw        $t1, 0x4c($sp)
/* 418FC8 802A4238 3C03802B */  lui       $v1, %hi(battle_menu_moveCursorPos)
/* 418FCC 802A423C 8063D109 */  lb        $v1, %lo(battle_menu_moveCursorPos)($v1)
/* 418FD0 802A4240 3C02802B */  lui       $v0, %hi(battle_menu_moveScrollLine)
/* 418FD4 802A4244 8042D10C */  lb        $v0, %lo(battle_menu_moveScrollLine)($v0)
/* 418FD8 802A4248 3C08802B */  lui       $t0, %hi(D_802AD112)
/* 418FDC 802A424C 8508D112 */  lh        $t0, %lo(D_802AD112)($t0)
/* 418FE0 802A4250 2535000A */  addiu     $s5, $t1, 0xa
/* 418FE4 802A4254 00621823 */  subu      $v1, $v1, $v0
/* 418FE8 802A4258 00031040 */  sll       $v0, $v1, 1
/* 418FEC 802A425C 00431021 */  addu      $v0, $v0, $v1
/* 418FF0 802A4260 00021080 */  sll       $v0, $v0, 2
/* 418FF4 802A4264 00438821 */  addu      $s1, $v0, $v1
/* 418FF8 802A4268 02281023 */  subu      $v0, $s1, $t0
/* 418FFC 802A426C 44820000 */  mtc1      $v0, $f0
/* 419000 802A4270 00000000 */  nop
/* 419004 802A4274 46800021 */  cvt.d.w   $f0, $f0
/* 419008 802A4278 4620018D */  trunc.w.d $f6, $f0
/* 41900C 802A427C 44023000 */  mfc1      $v0, $f6
/* 419010 802A4280 00000000 */  nop
/* 419014 802A4284 14400002 */  bnez      $v0, .L802A4290
/* 419018 802A4288 01024021 */   addu     $t0, $t0, $v0
/* 41901C 802A428C 0220402D */  daddu     $t0, $s1, $zero
.L802A4290:
/* 419020 802A4290 02A0282D */  daddu     $a1, $s5, $zero
/* 419024 802A4294 00083400 */  sll       $a2, $t0, 0x10
/* 419028 802A4298 00063403 */  sra       $a2, $a2, 0x10
/* 41902C 802A429C 3C10802B */  lui       $s0, %hi(battle_menu_moveCursorIcon)
/* 419030 802A42A0 8E10D118 */  lw        $s0, %lo(battle_menu_moveCursorIcon)($s0)
/* 419034 802A42A4 8FA90050 */  lw        $t1, 0x50($sp)
/* 419038 802A42A8 24C6001A */  addiu     $a2, $a2, 0x1a
/* 41903C 802A42AC 3C01802B */  lui       $at, %hi(D_802AD112)
/* 419040 802A42B0 A428D112 */  sh        $t0, %lo(D_802AD112)($at)
/* 419044 802A42B4 01263021 */  addu      $a2, $t1, $a2
/* 419048 802A42B8 0C051261 */  jal       set_icon_render_pos
/* 41904C 802A42BC 0200202D */   daddu    $a0, $s0, $zero
/* 419050 802A42C0 3C11802B */  lui       $s1, %hi(battle_menu_moveTextOpacity)
/* 419054 802A42C4 2631D116 */  addiu     $s1, $s1, %lo(battle_menu_moveTextOpacity)
/* 419058 802A42C8 86250000 */  lh        $a1, ($s1)
/* 41905C 802A42CC 0C0513AC */  jal       icon_set_opacity
/* 419060 802A42D0 0200202D */   daddu    $a0, $s0, $zero
/* 419064 802A42D4 0C0511F8 */  jal       draw_icon_2
/* 419068 802A42D8 0200202D */   daddu    $a0, $s0, $zero
/* 41906C 802A42DC 3C02802B */  lui       $v0, %hi(battle_menu_moveScrollLine)
/* 419070 802A42E0 8042D10C */  lb        $v0, %lo(battle_menu_moveScrollLine)($v0)
/* 419074 802A42E4 1840000E */  blez      $v0, .L802A4320
/* 419078 802A42E8 00000000 */   nop
/* 41907C 802A42EC 8FA9004C */  lw        $t1, 0x4c($sp)
/* 419080 802A42F0 3C10802B */  lui       $s0, %hi(battle_menu_moveUpArrowIcon)
/* 419084 802A42F4 8E10D11C */  lw        $s0, %lo(battle_menu_moveUpArrowIcon)($s0)
/* 419088 802A42F8 25250048 */  addiu     $a1, $t1, 0x48
/* 41908C 802A42FC 8FA90050 */  lw        $t1, 0x50($sp)
/* 419090 802A4300 0200202D */  daddu     $a0, $s0, $zero
/* 419094 802A4304 0C051261 */  jal       set_icon_render_pos
/* 419098 802A4308 2526000F */   addiu    $a2, $t1, 0xf
/* 41909C 802A430C 86250000 */  lh        $a1, ($s1)
/* 4190A0 802A4310 0C0513AC */  jal       icon_set_opacity
/* 4190A4 802A4314 0200202D */   daddu    $a0, $s0, $zero
/* 4190A8 802A4318 0C0511EA */  jal       draw_icon_0
/* 4190AC 802A431C 0200202D */   daddu    $a0, $s0, $zero
.L802A4320:
/* 4190B0 802A4320 3C02802B */  lui       $v0, %hi(D_802AD10D)
/* 4190B4 802A4324 8042D10D */  lb        $v0, %lo(D_802AD10D)($v0)
/* 4190B8 802A4328 3C03802B */  lui       $v1, %hi(battle_menu_moveOptionCount)
/* 4190BC 802A432C 8C63D4A4 */  lw        $v1, %lo(battle_menu_moveOptionCount)($v1)
/* 4190C0 802A4330 0043102A */  slt       $v0, $v0, $v1
/* 4190C4 802A4334 1040000E */  beqz      $v0, .L802A4370
/* 4190C8 802A4338 00000000 */   nop
/* 4190CC 802A433C 8FA9004C */  lw        $t1, 0x4c($sp)
/* 4190D0 802A4340 3C10802B */  lui       $s0, %hi(battle_menu_moveDownArrowIcon)
/* 4190D4 802A4344 8E10D120 */  lw        $s0, %lo(battle_menu_moveDownArrowIcon)($s0)
/* 4190D8 802A4348 25250048 */  addiu     $a1, $t1, 0x48
/* 4190DC 802A434C 8FA90050 */  lw        $t1, 0x50($sp)
/* 4190E0 802A4350 0200202D */  daddu     $a0, $s0, $zero
/* 4190E4 802A4354 0C051261 */  jal       set_icon_render_pos
/* 4190E8 802A4358 25260064 */   addiu    $a2, $t1, 0x64
/* 4190EC 802A435C 86250000 */  lh        $a1, ($s1)
/* 4190F0 802A4360 0C0513AC */  jal       icon_set_opacity
/* 4190F4 802A4364 0200202D */   daddu    $a0, $s0, $zero
/* 4190F8 802A4368 0C0511EA */  jal       draw_icon_0
/* 4190FC 802A436C 0200202D */   daddu    $a0, $s0, $zero
.L802A4370:
/* 419100 802A4370 3C03802B */  lui       $v1, %hi(battle_menu_moveState)
/* 419104 802A4374 8063D108 */  lb        $v1, %lo(battle_menu_moveState)($v1)
/* 419108 802A4378 2402FFFF */  addiu     $v0, $zero, -1
/* 41910C 802A437C 1462000B */  bne       $v1, $v0, .L802A43AC
/* 419110 802A4380 00000000 */   nop
/* 419114 802A4384 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 419118 802A4388 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 41911C 802A438C 14400005 */  bnez      $v0, .L802A43A4
/* 419120 802A4390 00000000 */   nop
/* 419124 802A4394 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 419128 802A4398 00000000 */   nop
/* 41912C 802A439C 080A90EB */  j         .L802A43AC
/* 419130 802A43A0 00000000 */   nop
.L802A43A4:
/* 419134 802A43A4 0C03A6A5 */  jal       status_menu_stop_blinking_sp
/* 419138 802A43A8 00000000 */   nop
.L802A43AC:
glabel L802A43AC_41913C
/* 41913C 802A43AC 8FBF0044 */  lw        $ra, 0x44($sp)
/* 419140 802A43B0 8FBE0040 */  lw        $fp, 0x40($sp)
/* 419144 802A43B4 8FB7003C */  lw        $s7, 0x3c($sp)
/* 419148 802A43B8 8FB60038 */  lw        $s6, 0x38($sp)
/* 41914C 802A43BC 8FB50034 */  lw        $s5, 0x34($sp)
/* 419150 802A43C0 8FB40030 */  lw        $s4, 0x30($sp)
/* 419154 802A43C4 8FB3002C */  lw        $s3, 0x2c($sp)
/* 419158 802A43C8 8FB20028 */  lw        $s2, 0x28($sp)
/* 41915C 802A43CC 8FB10024 */  lw        $s1, 0x24($sp)
/* 419160 802A43D0 8FB00020 */  lw        $s0, 0x20($sp)
/* 419164 802A43D4 03E00008 */  jr        $ra
/* 419168 802A43D8 27BD0048 */   addiu    $sp, $sp, 0x48

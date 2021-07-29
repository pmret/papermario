.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel title_screen_draw_logo
/* 12D94 80037994 27BDFFF8 */  addiu     $sp, $sp, -8
/* 12D98 80037998 0000602D */  daddu     $t4, $zero, $zero
/* 12D9C 8003799C 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 12DA0 800379A0 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 12DA4 800379A4 0040402D */  daddu     $t0, $v0, $zero
/* 12DA8 800379A8 3C19800A */  lui       $t9, %hi(D_800A0978)
/* 12DAC 800379AC 27390978 */  addiu     $t9, $t9, %lo(D_800A0978)
/* 12DB0 800379B0 3C0DF518 */  lui       $t5, 0xf518
/* 12DB4 800379B4 35AD6400 */  ori       $t5, $t5, 0x6400
/* 12DB8 800379B8 3C18E441 */  lui       $t8, 0xe441
/* 12DBC 800379BC 3C0F000F */  lui       $t7, 0xf
/* 12DC0 800379C0 0180582D */  daddu     $t3, $t4, $zero
/* 12DC4 800379C4 0180502D */  daddu     $t2, $t4, $zero
/* 12DC8 800379C8 3C02DE00 */  lui       $v0, 0xde00
/* 12DCC 800379CC AFB00000 */  sw        $s0, ($sp)
/* 12DD0 800379D0 8D030000 */  lw        $v1, ($t0)
/* 12DD4 800379D4 3C01C2C8 */  lui       $at, 0xc2c8
/* 12DD8 800379D8 44810000 */  mtc1      $at, $f0
/* 12DDC 800379DC 0060202D */  daddu     $a0, $v1, $zero
/* 12DE0 800379E0 24630008 */  addiu     $v1, $v1, 8
/* 12DE4 800379E4 AD030000 */  sw        $v1, ($t0)
/* 12DE8 800379E8 AC820000 */  sw        $v0, ($a0)
/* 12DEC 800379EC 3C028007 */  lui       $v0, %hi(D_80077A50)
/* 12DF0 800379F0 24427A50 */  addiu     $v0, $v0, %lo(D_80077A50)
/* 12DF4 800379F4 AC820004 */  sw        $v0, 4($a0)
/* 12DF8 800379F8 24620008 */  addiu     $v0, $v1, 8
/* 12DFC 800379FC 46006302 */  mul.s     $f12, $f12, $f0
/* 12E00 80037A00 00000000 */  nop
/* 12E04 80037A04 AD020000 */  sw        $v0, ($t0)
/* 12E08 80037A08 3C02E700 */  lui       $v0, 0xe700
/* 12E0C 80037A0C AC620000 */  sw        $v0, ($v1)
/* 12E10 80037A10 AC600004 */  sw        $zero, 4($v1)
/* 12E14 80037A14 4600608D */  trunc.w.s $f2, $f12
/* 12E18 80037A18 440E1000 */  mfc1      $t6, $f2
/* 12E1C 80037A1C 00000000 */  nop
/* 12E20 80037A20 25C9000F */  addiu     $t1, $t6, 0xf
.L80037A24:
/* 12E24 80037A24 3C04FD18 */  lui       $a0, 0xfd18
/* 12E28 80037A28 348400C7 */  ori       $a0, $a0, 0xc7
/* 12E2C 80037A2C 3C050731 */  lui       $a1, 0x731
/* 12E30 80037A30 34A5C004 */  ori       $a1, $a1, 0xc004
/* 12E34 80037A34 3C060031 */  lui       $a2, 0x31
/* 12E38 80037A38 34C6C004 */  ori       $a2, $a2, 0xc004
/* 12E3C 80037A3C 8D070000 */  lw        $a3, ($t0)
/* 12E40 80037A40 8F220000 */  lw        $v0, ($t9)
/* 12E44 80037A44 00E0182D */  daddu     $v1, $a3, $zero
/* 12E48 80037A48 24E70008 */  addiu     $a3, $a3, 8
/* 12E4C 80037A4C 004A1021 */  addu      $v0, $v0, $t2
/* 12E50 80037A50 AD070000 */  sw        $a3, ($t0)
/* 12E54 80037A54 AC620004 */  sw        $v0, 4($v1)
/* 12E58 80037A58 24E20008 */  addiu     $v0, $a3, 8
/* 12E5C 80037A5C AC640000 */  sw        $a0, ($v1)
/* 12E60 80037A60 AD020000 */  sw        $v0, ($t0)
/* 12E64 80037A64 3C020700 */  lui       $v0, 0x700
/* 12E68 80037A68 ACE20004 */  sw        $v0, 4($a3)
/* 12E6C 80037A6C 24E20010 */  addiu     $v0, $a3, 0x10
/* 12E70 80037A70 ACED0000 */  sw        $t5, ($a3)
/* 12E74 80037A74 AD020000 */  sw        $v0, ($t0)
/* 12E78 80037A78 3C02E600 */  lui       $v0, 0xe600
/* 12E7C 80037A7C ACE20008 */  sw        $v0, 8($a3)
/* 12E80 80037A80 24E20018 */  addiu     $v0, $a3, 0x18
/* 12E84 80037A84 ACE0000C */  sw        $zero, 0xc($a3)
/* 12E88 80037A88 AD020000 */  sw        $v0, ($t0)
/* 12E8C 80037A8C 3C02F400 */  lui       $v0, 0xf400
/* 12E90 80037A90 ACE20010 */  sw        $v0, 0x10($a3)
/* 12E94 80037A94 24E20020 */  addiu     $v0, $a3, 0x20
/* 12E98 80037A98 ACE50014 */  sw        $a1, 0x14($a3)
/* 12E9C 80037A9C AD020000 */  sw        $v0, ($t0)
/* 12EA0 80037AA0 3C02E700 */  lui       $v0, 0xe700
/* 12EA4 80037AA4 ACE20018 */  sw        $v0, 0x18($a3)
/* 12EA8 80037AA8 24E20028 */  addiu     $v0, $a3, 0x28
/* 12EAC 80037AAC 24E30030 */  addiu     $v1, $a3, 0x30
/* 12EB0 80037AB0 ACE0001C */  sw        $zero, 0x1c($a3)
/* 12EB4 80037AB4 AD020000 */  sw        $v0, ($t0)
/* 12EB8 80037AB8 3C02F200 */  lui       $v0, 0xf200
/* 12EBC 80037ABC ACED0020 */  sw        $t5, 0x20($a3)
/* 12EC0 80037AC0 ACE00024 */  sw        $zero, 0x24($a3)
/* 12EC4 80037AC4 AD030000 */  sw        $v1, ($t0)
/* 12EC8 80037AC8 ACE20028 */  sw        $v0, 0x28($a3)
/* 12ECC 80037ACC 24E20038 */  addiu     $v0, $a3, 0x38
/* 12ED0 80037AD0 ACE6002C */  sw        $a2, 0x2c($a3)
/* 12ED4 80037AD4 AD020000 */  sw        $v0, ($t0)
/* 12ED8 80037AD8 25C20011 */  addiu     $v0, $t6, 0x11
/* 12EDC 80037ADC 01621021 */  addu      $v0, $t3, $v0
/* 12EE0 80037AE0 00021480 */  sll       $v0, $v0, 0x12
/* 12EE4 80037AE4 00021403 */  sra       $v0, $v0, 0x10
/* 12EE8 80037AE8 18400004 */  blez      $v0, .L80037AFC
/* 12EEC 80037AEC 30420FFF */   andi     $v0, $v0, 0xfff
/* 12EF0 80037AF0 00581025 */  or        $v0, $v0, $t8
/* 12EF4 80037AF4 0800DEC0 */  j         .L80037B00
/* 12EF8 80037AF8 ACE20030 */   sw       $v0, 0x30($a3)
.L80037AFC:
/* 12EFC 80037AFC ACF80030 */  sw        $t8, 0x30($a3)
.L80037B00:
/* 12F00 80037B00 00091480 */  sll       $v0, $t1, 0x12
/* 12F04 80037B04 00021403 */  sra       $v0, $v0, 0x10
/* 12F08 80037B08 18400004 */  blez      $v0, .L80037B1C
/* 12F0C 80037B0C 30420FFF */   andi     $v0, $v0, 0xfff
/* 12F10 80037B10 004F1025 */  or        $v0, $v0, $t7
/* 12F14 80037B14 0800DEC8 */  j         .L80037B20
/* 12F18 80037B18 AC620004 */   sw       $v0, 4($v1)
.L80037B1C:
/* 12F1C 80037B1C AC6F0004 */  sw        $t7, 4($v1)
.L80037B20:
/* 12F20 80037B20 8D030000 */  lw        $v1, ($t0)
/* 12F24 80037B24 24620008 */  addiu     $v0, $v1, 8
/* 12F28 80037B28 AD020000 */  sw        $v0, ($t0)
/* 12F2C 80037B2C 3C02E100 */  lui       $v0, 0xe100
/* 12F30 80037B30 AC620000 */  sw        $v0, ($v1)
/* 12F34 80037B34 00091080 */  sll       $v0, $t1, 2
/* 12F38 80037B38 04430008 */  bgezl     $v0, .L80037B5C
/* 12F3C 80037B3C AC600004 */   sw       $zero, 4($v1)
/* 12F40 80037B40 00091480 */  sll       $v0, $t1, 0x12
/* 12F44 80037B44 00021343 */  sra       $v0, $v0, 0xd
/* 12F48 80037B48 5C400001 */  bgtzl     $v0, .L80037B50
/* 12F4C 80037B4C 0000102D */   daddu    $v0, $zero, $zero
.L80037B50:
/* 12F50 80037B50 00021023 */  negu      $v0, $v0
/* 12F54 80037B54 3042FFFF */  andi      $v0, $v0, 0xffff
/* 12F58 80037B58 AC620004 */  sw        $v0, 4($v1)
.L80037B5C:
/* 12F5C 80037B5C 3C040400 */  lui       $a0, 0x400
/* 12F60 80037B60 34840400 */  ori       $a0, $a0, 0x400
/* 12F64 80037B64 25290002 */  addiu     $t1, $t1, 2
/* 12F68 80037B68 256B0002 */  addiu     $t3, $t3, 2
/* 12F6C 80037B6C 254A0640 */  addiu     $t2, $t2, 0x640
/* 12F70 80037B70 8D020000 */  lw        $v0, ($t0)
/* 12F74 80037B74 258C0001 */  addiu     $t4, $t4, 1
/* 12F78 80037B78 0040182D */  daddu     $v1, $v0, $zero
/* 12F7C 80037B7C 24420008 */  addiu     $v0, $v0, 8
/* 12F80 80037B80 AD020000 */  sw        $v0, ($t0)
/* 12F84 80037B84 3C02F100 */  lui       $v0, 0xf100
/* 12F88 80037B88 AC620000 */  sw        $v0, ($v1)
/* 12F8C 80037B8C 29820038 */  slti      $v0, $t4, 0x38
/* 12F90 80037B90 1440FFA4 */  bnez      $v0, .L80037A24
/* 12F94 80037B94 AC640004 */   sw       $a0, 4($v1)
/* 12F98 80037B98 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 12F9C 80037B9C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 12FA0 80037BA0 8C620000 */  lw        $v0, ($v1)
/* 12FA4 80037BA4 0040202D */  daddu     $a0, $v0, $zero
/* 12FA8 80037BA8 24420008 */  addiu     $v0, $v0, 8
/* 12FAC 80037BAC AC620000 */  sw        $v0, ($v1)
/* 12FB0 80037BB0 3C02E700 */  lui       $v0, 0xe700
/* 12FB4 80037BB4 AC820000 */  sw        $v0, ($a0)
/* 12FB8 80037BB8 AC800004 */  sw        $zero, 4($a0)
/* 12FBC 80037BBC 8FB00000 */  lw        $s0, ($sp)
/* 12FC0 80037BC0 03E00008 */  jr        $ra
/* 12FC4 80037BC4 27BD0008 */   addiu    $sp, $sp, 8

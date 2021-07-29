.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ShowShopOwnerDialog
/* 7E1A50 80280BD0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E1A54 80280BD4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E1A58 80280BD8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7E1A5C 80280BDC AFB10014 */  sw        $s1, 0x14($sp)
/* 7E1A60 80280BE0 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E1A64 80280BE4 3C128011 */  lui       $s2, %hi(gPlayerData)
/* 7E1A68 80280BE8 2652F290 */  addiu     $s2, $s2, %lo(gPlayerData)
/* 7E1A6C 80280BEC AFBF0020 */  sw        $ra, 0x20($sp)
/* 7E1A70 80280BF0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7E1A74 80280BF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E1A78 80280BF8 8C500144 */  lw        $s0, 0x144($v0)
/* 7E1A7C 80280BFC 10A00006 */  beqz      $a1, .L80280C18
/* 7E1A80 80280C00 0080882D */   daddu    $s1, $a0, $zero
/* 7E1A84 80280C04 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E1A88 80280C08 24040004 */   addiu    $a0, $zero, 4
/* 7E1A8C 80280C0C AE220074 */  sw        $v0, 0x74($s1)
/* 7E1A90 80280C10 24020004 */  addiu     $v0, $zero, 4
/* 7E1A94 80280C14 AE220070 */  sw        $v0, 0x70($s1)
.L80280C18:
/* 7E1A98 80280C18 8E230070 */  lw        $v1, 0x70($s1)
/* 7E1A9C 80280C1C 24130020 */  addiu     $s3, $zero, 0x20
/* 7E1AA0 80280C20 10730117 */  beq       $v1, $s3, .L80281080
/* 7E1AA4 80280C24 28620021 */   slti     $v0, $v1, 0x21
/* 7E1AA8 80280C28 10400027 */  beqz      $v0, .L80280CC8
/* 7E1AAC 80280C2C 24020007 */   addiu    $v0, $zero, 7
/* 7E1AB0 80280C30 1062018C */  beq       $v1, $v0, .L80281264
/* 7E1AB4 80280C34 28620008 */   slti     $v0, $v1, 8
/* 7E1AB8 80280C38 10400011 */  beqz      $v0, .L80280C80
/* 7E1ABC 80280C3C 24020003 */   addiu    $v0, $zero, 3
/* 7E1AC0 80280C40 106200D9 */  beq       $v1, $v0, .L80280FA8
/* 7E1AC4 80280C44 28620004 */   slti     $v0, $v1, 4
/* 7E1AC8 80280C48 10400007 */  beqz      $v0, .L80280C68
/* 7E1ACC 80280C4C 24020004 */   addiu    $v0, $zero, 4
/* 7E1AD0 80280C50 106001DC */  beqz      $v1, .L802813C4
/* 7E1AD4 80280C54 24020002 */   addiu    $v0, $zero, 2
/* 7E1AD8 80280C58 106200AF */  beq       $v1, $v0, .L80280F18
/* 7E1ADC 80280C5C 0000102D */   daddu    $v0, $zero, $zero
/* 7E1AE0 80280C60 080A0506 */  j         .L80281418
/* 7E1AE4 80280C64 00000000 */   nop
.L80280C68:
/* 7E1AE8 80280C68 1062003F */  beq       $v1, $v0, .L80280D68
/* 7E1AEC 80280C6C 24020005 */   addiu    $v0, $zero, 5
/* 7E1AF0 80280C70 1062012B */  beq       $v1, $v0, .L80281120
/* 7E1AF4 80280C74 0000102D */   daddu    $v0, $zero, $zero
/* 7E1AF8 80280C78 080A0506 */  j         .L80281418
/* 7E1AFC 80280C7C 00000000 */   nop
.L80280C80:
/* 7E1B00 80280C80 2402000C */  addiu     $v0, $zero, 0xc
/* 7E1B04 80280C84 10620108 */  beq       $v1, $v0, .L802810A8
/* 7E1B08 80280C88 2862000D */   slti     $v0, $v1, 0xd
/* 7E1B0C 80280C8C 10400007 */  beqz      $v0, .L80280CAC
/* 7E1B10 80280C90 24020009 */   addiu    $v0, $zero, 9
/* 7E1B14 80280C94 106201CB */  beq       $v1, $v0, .L802813C4
/* 7E1B18 80280C98 2402000A */   addiu    $v0, $zero, 0xa
/* 7E1B1C 80280C9C 106201D1 */  beq       $v1, $v0, .L802813E4
/* 7E1B20 80280CA0 0000102D */   daddu    $v0, $zero, $zero
/* 7E1B24 80280CA4 080A0506 */  j         .L80281418
/* 7E1B28 80280CA8 00000000 */   nop
.L80280CAC:
/* 7E1B2C 80280CAC 24020015 */  addiu     $v0, $zero, 0x15
/* 7E1B30 80280CB0 106200A0 */  beq       $v1, $v0, .L80280F34
/* 7E1B34 80280CB4 2402001F */   addiu    $v0, $zero, 0x1f
/* 7E1B38 80280CB8 106200C5 */  beq       $v1, $v0, .L80280FD0
/* 7E1B3C 80280CBC 0000102D */   daddu    $v0, $zero, $zero
/* 7E1B40 80280CC0 080A0506 */  j         .L80281418
/* 7E1B44 80280CC4 00000000 */   nop
.L80280CC8:
/* 7E1B48 80280CC8 24020047 */  addiu     $v0, $zero, 0x47
/* 7E1B4C 80280CCC 1062016F */  beq       $v1, $v0, .L8028128C
/* 7E1B50 80280CD0 28620048 */   slti     $v0, $v1, 0x48
/* 7E1B54 80280CD4 10400012 */  beqz      $v0, .L80280D20
/* 7E1B58 80280CD8 24020033 */   addiu    $v0, $zero, 0x33
/* 7E1B5C 80280CDC 10620117 */  beq       $v1, $v0, .L8028113C
/* 7E1B60 80280CE0 28620034 */   slti     $v0, $v1, 0x34
/* 7E1B64 80280CE4 10400007 */  beqz      $v0, .L80280D04
/* 7E1B68 80280CE8 24020029 */   addiu    $v0, $zero, 0x29
/* 7E1B6C 80280CEC 10620027 */  beq       $v1, $v0, .L80280D8C
/* 7E1B70 80280CF0 2402002A */   addiu    $v0, $zero, 0x2a
/* 7E1B74 80280CF4 106201B3 */  beq       $v1, $v0, .L802813C4
/* 7E1B78 80280CF8 0000102D */   daddu    $v0, $zero, $zero
/* 7E1B7C 80280CFC 080A0506 */  j         .L80281418
/* 7E1B80 80280D00 00000000 */   nop
.L80280D04:
/* 7E1B84 80280D04 24020034 */  addiu     $v0, $zero, 0x34
/* 7E1B88 80280D08 10620133 */  beq       $v1, $v0, .L802811D8
/* 7E1B8C 80280D0C 24020035 */   addiu    $v0, $zero, 0x35
/* 7E1B90 80280D10 1062013B */  beq       $v1, $v0, .L80281200
/* 7E1B94 80280D14 0000102D */   daddu    $v0, $zero, $zero
/* 7E1B98 80280D18 080A0506 */  j         .L80281418
/* 7E1B9C 80280D1C 00000000 */   nop
.L80280D20:
/* 7E1BA0 80280D20 240200C9 */  addiu     $v0, $zero, 0xc9
/* 7E1BA4 80280D24 10620072 */  beq       $v1, $v0, .L80280EF0
/* 7E1BA8 80280D28 286200CA */   slti     $v0, $v1, 0xca
/* 7E1BAC 80280D2C 10400007 */  beqz      $v0, .L80280D4C
/* 7E1BB0 80280D30 24020048 */   addiu    $v0, $zero, 0x48
/* 7E1BB4 80280D34 1062017E */  beq       $v1, $v0, .L80281330
/* 7E1BB8 80280D38 24020049 */   addiu    $v0, $zero, 0x49
/* 7E1BBC 80280D3C 1062018C */  beq       $v1, $v0, .L80281370
/* 7E1BC0 80280D40 0000102D */   daddu    $v0, $zero, $zero
/* 7E1BC4 80280D44 080A0506 */  j         .L80281418
/* 7E1BC8 80280D48 00000000 */   nop
.L80280D4C:
/* 7E1BCC 80280D4C 240201F5 */  addiu     $v0, $zero, 0x1f5
/* 7E1BD0 80280D50 106200EA */  beq       $v1, $v0, .L802810FC
/* 7E1BD4 80280D54 240202BD */   addiu    $v0, $zero, 0x2bd
/* 7E1BD8 80280D58 10620138 */  beq       $v1, $v0, .L8028123C
/* 7E1BDC 80280D5C 0000102D */   daddu    $v0, $zero, $zero
/* 7E1BE0 80280D60 080A0506 */  j         .L80281418
/* 7E1BE4 80280D64 00000000 */   nop
.L80280D68:
/* 7E1BE8 80280D68 0C0B1059 */  jal       does_script_exist
/* 7E1BEC 80280D6C 8E240074 */   lw       $a0, 0x74($s1)
/* 7E1BF0 80280D70 144001A9 */  bnez      $v0, .L80281418
/* 7E1BF4 80280D74 0000102D */   daddu    $v0, $zero, $zero
/* 7E1BF8 80280D78 3C04001E */  lui       $a0, 0x1e
/* 7E1BFC 80280D7C 34840003 */  ori       $a0, $a0, 3
/* 7E1C00 80280D80 26250078 */  addiu     $a1, $s1, 0x78
/* 7E1C04 80280D84 080A04D5 */  j         .L80281354
/* 7E1C08 80280D88 24020029 */   addiu    $v0, $zero, 0x29
.L80280D8C:
/* 7E1C0C 80280D8C 8E240078 */  lw        $a0, 0x78($s1)
/* 7E1C10 80280D90 24020001 */  addiu     $v0, $zero, 1
/* 7E1C14 80280D94 148201A0 */  bne       $a0, $v0, .L80281418
/* 7E1C18 80280D98 0000102D */   daddu    $v0, $zero, $zero
/* 7E1C1C 80280D9C 3C028028 */  lui       $v0, %hi(D_80286538)
/* 7E1C20 80280DA0 8C426538 */  lw        $v0, %lo(D_80286538)($v0)
/* 7E1C24 80280DA4 904304E8 */  lbu       $v1, 0x4e8($v0)
/* 7E1C28 80280DA8 10640012 */  beq       $v1, $a0, .L80280DF4
/* 7E1C2C 80280DAC 28620002 */   slti     $v0, $v1, 2
/* 7E1C30 80280DB0 10400005 */  beqz      $v0, .L80280DC8
/* 7E1C34 80280DB4 24020002 */   addiu    $v0, $zero, 2
/* 7E1C38 80280DB8 10600009 */  beqz      $v1, .L80280DE0
/* 7E1C3C 80280DBC 00000000 */   nop
/* 7E1C40 80280DC0 080A03B6 */  j         .L80280ED8
/* 7E1C44 80280DC4 00000000 */   nop
.L80280DC8:
/* 7E1C48 80280DC8 10620018 */  beq       $v1, $v0, .L80280E2C
/* 7E1C4C 80280DCC 24020003 */   addiu    $v0, $zero, 3
/* 7E1C50 80280DD0 1062002D */  beq       $v1, $v0, .L80280E88
/* 7E1C54 80280DD4 00000000 */   nop
/* 7E1C58 80280DD8 080A03B6 */  j         .L80280ED8
/* 7E1C5C 80280DDC 00000000 */   nop
.L80280DE0:
/* 7E1C60 80280DE0 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1C64 80280DE4 24040005 */   addiu    $a0, $zero, 5
/* 7E1C68 80280DE8 AE220074 */  sw        $v0, 0x74($s1)
/* 7E1C6C 80280DEC 080A0505 */  j         .L80281414
/* 7E1C70 80280DF0 AE200070 */   sw       $zero, 0x70($s1)
.L80280DF4:
/* 7E1C74 80280DF4 0C039D7B */  jal       get_item_count
/* 7E1C78 80280DF8 00000000 */   nop
/* 7E1C7C 80280DFC 14400005 */  bnez      $v0, .L80280E14
/* 7E1C80 80280E00 00000000 */   nop
/* 7E1C84 80280E04 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1C88 80280E08 24040006 */   addiu    $a0, $zero, 6
/* 7E1C8C 80280E0C 080A04EE */  j         .L802813B8
/* 7E1C90 80280E10 AE220074 */   sw       $v0, 0x74($s1)
.L80280E14:
/* 7E1C94 80280E14 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1C98 80280E18 24040007 */   addiu    $a0, $zero, 7
/* 7E1C9C 80280E1C AE220074 */  sw        $v0, 0x74($s1)
/* 7E1CA0 80280E20 240200C9 */  addiu     $v0, $zero, 0xc9
/* 7E1CA4 80280E24 080A0505 */  j         .L80281414
/* 7E1CA8 80280E28 AE220070 */   sw       $v0, 0x70($s1)
.L80280E2C:
/* 7E1CAC 80280E2C 0C039D7B */  jal       get_item_count
/* 7E1CB0 80280E30 00000000 */   nop
/* 7E1CB4 80280E34 14400005 */  bnez      $v0, .L80280E4C
/* 7E1CB8 80280E38 00000000 */   nop
/* 7E1CBC 80280E3C 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1CC0 80280E40 2404000C */   addiu    $a0, $zero, 0xc
/* 7E1CC4 80280E44 080A04EE */  j         .L802813B8
/* 7E1CC8 80280E48 AE220074 */   sw       $v0, 0x74($s1)
.L80280E4C:
/* 7E1CCC 80280E4C 0C039E12 */  jal       get_stored_empty_count
/* 7E1CD0 80280E50 00000000 */   nop
/* 7E1CD4 80280E54 14400005 */  bnez      $v0, .L80280E6C
/* 7E1CD8 80280E58 00000000 */   nop
/* 7E1CDC 80280E5C 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1CE0 80280E60 2404000D */   addiu    $a0, $zero, 0xd
/* 7E1CE4 80280E64 080A04EE */  j         .L802813B8
/* 7E1CE8 80280E68 AE220074 */   sw       $v0, 0x74($s1)
.L80280E6C:
/* 7E1CEC 80280E6C 0C039E12 */  jal       get_stored_empty_count
/* 7E1CF0 80280E70 00000000 */   nop
/* 7E1CF4 80280E74 2404000E */  addiu     $a0, $zero, 0xe
/* 7E1CF8 80280E78 0C0A0082 */  jal       shop_owner_continue_speech_with_quantity
/* 7E1CFC 80280E7C 0040282D */   daddu    $a1, $v0, $zero
/* 7E1D00 80280E80 080A048C */  j         .L80281230
/* 7E1D04 80280E84 AE220074 */   sw       $v0, 0x74($s1)
.L80280E88:
/* 7E1D08 80280E88 0C039E05 */  jal       get_stored_count
/* 7E1D0C 80280E8C 00000000 */   nop
/* 7E1D10 80280E90 14400005 */  bnez      $v0, .L80280EA8
/* 7E1D14 80280E94 00000000 */   nop
/* 7E1D18 80280E98 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1D1C 80280E9C 24040011 */   addiu    $a0, $zero, 0x11
/* 7E1D20 80280EA0 080A04EE */  j         .L802813B8
/* 7E1D24 80280EA4 AE220074 */   sw       $v0, 0x74($s1)
.L80280EA8:
/* 7E1D28 80280EA8 0C039D88 */  jal       get_item_empty_count
/* 7E1D2C 80280EAC 00000000 */   nop
/* 7E1D30 80280EB0 14400005 */  bnez      $v0, .L80280EC8
/* 7E1D34 80280EB4 00000000 */   nop
/* 7E1D38 80280EB8 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1D3C 80280EBC 24040012 */   addiu    $a0, $zero, 0x12
/* 7E1D40 80280EC0 080A04EE */  j         .L802813B8
/* 7E1D44 80280EC4 AE220074 */   sw       $v0, 0x74($s1)
.L80280EC8:
/* 7E1D48 80280EC8 0C0A005F */  jal       shop_owner_continue_speech
/* 7E1D4C 80280ECC 24040013 */   addiu    $a0, $zero, 0x13
/* 7E1D50 80280ED0 080A04E8 */  j         .L802813A0
/* 7E1D54 80280ED4 AE220074 */   sw       $v0, 0x74($s1)
.L80280ED8:
/* 7E1D58 80280ED8 0C0A00D7 */  jal       shop_owner_end_speech
/* 7E1D5C 80280EDC 00000000 */   nop
/* 7E1D60 80280EE0 AE220074 */  sw        $v0, 0x74($s1)
/* 7E1D64 80280EE4 2402002A */  addiu     $v0, $zero, 0x2a
/* 7E1D68 80280EE8 080A0505 */  j         .L80281414
/* 7E1D6C 80280EEC AE220070 */   sw       $v0, 0x70($s1)
.L80280EF0:
/* 7E1D70 80280EF0 8E240074 */  lw        $a0, 0x74($s1)
/* 7E1D74 80280EF4 0C0B1059 */  jal       does_script_exist
/* 7E1D78 80280EF8 00000000 */   nop
/* 7E1D7C 80280EFC 14400146 */  bnez      $v0, .L80281418
/* 7E1D80 80280F00 0000102D */   daddu    $v0, $zero, $zero
/* 7E1D84 80280F04 0C0A0255 */  jal       shop_open_item_select_popup
/* 7E1D88 80280F08 0000202D */   daddu    $a0, $zero, $zero
/* 7E1D8C 80280F0C 24020002 */  addiu     $v0, $zero, 2
/* 7E1D90 80280F10 080A0505 */  j         .L80281414
/* 7E1D94 80280F14 AE220070 */   sw       $v0, 0x70($s1)
.L80280F18:
/* 7E1D98 80280F18 0C0A02B1 */  jal       shop_update_item_select_popup
/* 7E1D9C 80280F1C 2604000C */   addiu    $a0, $s0, 0xc
/* 7E1DA0 80280F20 24030001 */  addiu     $v1, $zero, 1
/* 7E1DA4 80280F24 1443013C */  bne       $v0, $v1, .L80281418
/* 7E1DA8 80280F28 0000102D */   daddu    $v0, $zero, $zero
/* 7E1DAC 80280F2C 080A049F */  j         .L8028127C
/* 7E1DB0 80280F30 24020015 */   addiu    $v0, $zero, 0x15
.L80280F34:
/* 7E1DB4 80280F34 8E220074 */  lw        $v0, 0x74($s1)
/* 7E1DB8 80280F38 1C4000D7 */  bgtz      $v0, .L80281298
/* 7E1DBC 80280F3C 2442FFFF */   addiu    $v0, $v0, -1
/* 7E1DC0 80280F40 0C0A02D1 */  jal       shop_close_item_select_popup
/* 7E1DC4 80280F44 00000000 */   nop
/* 7E1DC8 80280F48 8E02000C */  lw        $v0, 0xc($s0)
/* 7E1DCC 80280F4C 04400012 */  bltz      $v0, .L80280F98
/* 7E1DD0 80280F50 00021040 */   sll      $v0, $v0, 1
/* 7E1DD4 80280F54 00521021 */  addu      $v0, $v0, $s2
/* 7E1DD8 80280F58 844401B4 */  lh        $a0, 0x1b4($v0)
/* 7E1DDC 80280F5C 3C028008 */  lui       $v0, %hi(gItemTable)
/* 7E1DE0 80280F60 244278E0 */  addiu     $v0, $v0, %lo(gItemTable)
/* 7E1DE4 80280F64 00048140 */  sll       $s0, $a0, 5
/* 7E1DE8 80280F68 0C0A02DE */  jal       shop_get_sell_price
/* 7E1DEC 80280F6C 02028021 */   addu     $s0, $s0, $v0
/* 7E1DF0 80280F70 24040008 */  addiu     $a0, $zero, 8
/* 7E1DF4 80280F74 0040302D */  daddu     $a2, $v0, $zero
/* 7E1DF8 80280F78 8E050000 */  lw        $a1, ($s0)
/* 7E1DFC 80280F7C 0C0A0022 */  jal       shop_owner_buy_dialog
/* 7E1E00 80280F80 2407FFFF */   addiu    $a3, $zero, -1
/* 7E1E04 80280F84 0C03A546 */  jal       show_coin_counter
/* 7E1E08 80280F88 AE220074 */   sw       $v0, 0x74($s1)
/* 7E1E0C 80280F8C 24020003 */  addiu     $v0, $zero, 3
/* 7E1E10 80280F90 080A0505 */  j         .L80281414
/* 7E1E14 80280F94 AE220070 */   sw       $v0, 0x70($s1)
.L80280F98:
/* 7E1E18 80280F98 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E1E1C 80280F9C 24040016 */   addiu    $a0, $zero, 0x16
/* 7E1E20 80280FA0 080A04EE */  j         .L802813B8
/* 7E1E24 80280FA4 AE220074 */   sw       $v0, 0x74($s1)
.L80280FA8:
/* 7E1E28 80280FA8 8E240074 */  lw        $a0, 0x74($s1)
/* 7E1E2C 80280FAC 0C0B1059 */  jal       does_script_exist
/* 7E1E30 80280FB0 00000000 */   nop
/* 7E1E34 80280FB4 14400118 */  bnez      $v0, .L80281418
/* 7E1E38 80280FB8 0000102D */   daddu    $v0, $zero, $zero
/* 7E1E3C 80280FBC 3C04001E */  lui       $a0, 0x1e
/* 7E1E40 80280FC0 34840002 */  ori       $a0, $a0, 2
/* 7E1E44 80280FC4 26250078 */  addiu     $a1, $s1, 0x78
/* 7E1E48 80280FC8 080A04D5 */  j         .L80281354
/* 7E1E4C 80280FCC 2402001F */   addiu    $v0, $zero, 0x1f
.L80280FD0:
/* 7E1E50 80280FD0 8E230078 */  lw        $v1, 0x78($s1)
/* 7E1E54 80280FD4 24020001 */  addiu     $v0, $zero, 1
/* 7E1E58 80280FD8 1462010F */  bne       $v1, $v0, .L80281418
/* 7E1E5C 80280FDC 0000102D */   daddu    $v0, $zero, $zero
/* 7E1E60 80280FE0 3C028028 */  lui       $v0, %hi(D_80286538)
/* 7E1E64 80280FE4 8C426538 */  lw        $v0, %lo(D_80286538)($v0)
/* 7E1E68 80280FE8 904204E8 */  lbu       $v0, 0x4e8($v0)
/* 7E1E6C 80280FEC 1440001D */  bnez      $v0, .L80281064
/* 7E1E70 80280FF0 00000000 */   nop
/* 7E1E74 80280FF4 8E02000C */  lw        $v0, 0xc($s0)
/* 7E1E78 80280FF8 00021040 */  sll       $v0, $v0, 1
/* 7E1E7C 80280FFC 00521021 */  addu      $v0, $v0, $s2
/* 7E1E80 80281000 0C0A02DE */  jal       shop_get_sell_price
/* 7E1E84 80281004 844401B4 */   lh       $a0, 0x1b4($v0)
/* 7E1E88 80281008 0C03A830 */  jal       add_coins
/* 7E1E8C 8028100C 0040202D */   daddu    $a0, $v0, $zero
/* 7E1E90 80281010 8E02000C */  lw        $v0, 0xc($s0)
/* 7E1E94 80281014 00021040 */  sll       $v0, $v0, 1
/* 7E1E98 80281018 00521021 */  addu      $v0, $v0, $s2
/* 7E1E9C 8028101C 0C039D7B */  jal       get_item_count
/* 7E1EA0 80281020 A44001B4 */   sh       $zero, 0x1b4($v0)
/* 7E1EA4 80281024 14400009 */  bnez      $v0, .L8028104C
/* 7E1EA8 80281028 00000000 */   nop
/* 7E1EAC 8028102C 0C0A00B4 */  jal       shop_owner_reset_speech
/* 7E1EB0 80281030 2404000B */   addiu    $a0, $zero, 0xb
/* 7E1EB4 80281034 AE220074 */  sw        $v0, 0x74($s1)
/* 7E1EB8 80281038 24020009 */  addiu     $v0, $zero, 9
/* 7E1EBC 8028103C 0C03A5A6 */  jal       hide_coin_counter
/* 7E1EC0 80281040 AE220070 */   sw       $v0, 0x70($s1)
/* 7E1EC4 80281044 080A0506 */  j         .L80281418
/* 7E1EC8 80281048 0000102D */   daddu    $v0, $zero, $zero
.L8028104C:
/* 7E1ECC 8028104C 0C0A00B4 */  jal       shop_owner_reset_speech
/* 7E1ED0 80281050 2404000A */   addiu    $a0, $zero, 0xa
/* 7E1ED4 80281054 AE220074 */  sw        $v0, 0x74($s1)
/* 7E1ED8 80281058 24020020 */  addiu     $v0, $zero, 0x20
/* 7E1EDC 8028105C 080A0505 */  j         .L80281414
/* 7E1EE0 80281060 AE220070 */   sw       $v0, 0x70($s1)
.L80281064:
/* 7E1EE4 80281064 0C0A00B4 */  jal       shop_owner_reset_speech
/* 7E1EE8 80281068 24040009 */   addiu    $a0, $zero, 9
/* 7E1EEC 8028106C AE220074 */  sw        $v0, 0x74($s1)
/* 7E1EF0 80281070 0C03A5A6 */  jal       hide_coin_counter
/* 7E1EF4 80281074 AE330070 */   sw       $s3, 0x70($s1)
/* 7E1EF8 80281078 080A0506 */  j         .L80281418
/* 7E1EFC 8028107C 0000102D */   daddu    $v0, $zero, $zero
.L80281080:
/* 7E1F00 80281080 8E240074 */  lw        $a0, 0x74($s1)
/* 7E1F04 80281084 0C0B1059 */  jal       does_script_exist
/* 7E1F08 80281088 00000000 */   nop
/* 7E1F0C 8028108C 144000E2 */  bnez      $v0, .L80281418
/* 7E1F10 80281090 0000102D */   daddu    $v0, $zero, $zero
/* 7E1F14 80281094 3C04001E */  lui       $a0, 0x1e
/* 7E1F18 80281098 34840004 */  ori       $a0, $a0, 4
/* 7E1F1C 8028109C 26250078 */  addiu     $a1, $s1, 0x78
/* 7E1F20 802810A0 080A04D5 */  j         .L80281354
/* 7E1F24 802810A4 2402000C */   addiu    $v0, $zero, 0xc
.L802810A8:
/* 7E1F28 802810A8 8E230078 */  lw        $v1, 0x78($s1)
/* 7E1F2C 802810AC 24020001 */  addiu     $v0, $zero, 1
/* 7E1F30 802810B0 146200D9 */  bne       $v1, $v0, .L80281418
/* 7E1F34 802810B4 0000102D */   daddu    $v0, $zero, $zero
/* 7E1F38 802810B8 3C028028 */  lui       $v0, %hi(D_80286538)
/* 7E1F3C 802810BC 8C426538 */  lw        $v0, %lo(D_80286538)($v0)
/* 7E1F40 802810C0 904204E8 */  lbu       $v0, 0x4e8($v0)
/* 7E1F44 802810C4 14400009 */  bnez      $v0, .L802810EC
/* 7E1F48 802810C8 00000000 */   nop
/* 7E1F4C 802810CC 0C0A00D7 */  jal       shop_owner_end_speech
/* 7E1F50 802810D0 00000000 */   nop
/* 7E1F54 802810D4 AE220074 */  sw        $v0, 0x74($s1)
/* 7E1F58 802810D8 240200C9 */  addiu     $v0, $zero, 0xc9
/* 7E1F5C 802810DC 0C03A5B2 */  jal       func_800E96C8
/* 7E1F60 802810E0 AE220070 */   sw       $v0, 0x70($s1)
/* 7E1F64 802810E4 080A0506 */  j         .L80281418
/* 7E1F68 802810E8 0000102D */   daddu    $v0, $zero, $zero
.L802810EC:
/* 7E1F6C 802810EC 0C03A5B2 */  jal       func_800E96C8
/* 7E1F70 802810F0 00000000 */   nop
/* 7E1F74 802810F4 080A04EB */  j         .L802813AC
/* 7E1F78 802810F8 00000000 */   nop
.L802810FC:
/* 7E1F7C 802810FC 0C0B1059 */  jal       does_script_exist
/* 7E1F80 80281100 8E240074 */   lw       $a0, 0x74($s1)
/* 7E1F84 80281104 144000C4 */  bnez      $v0, .L80281418
/* 7E1F88 80281108 0000102D */   daddu    $v0, $zero, $zero
/* 7E1F8C 8028110C 0C0A0255 */  jal       shop_open_item_select_popup
/* 7E1F90 80281110 24040001 */   addiu    $a0, $zero, 1
/* 7E1F94 80281114 24020005 */  addiu     $v0, $zero, 5
/* 7E1F98 80281118 080A0505 */  j         .L80281414
/* 7E1F9C 8028111C AE220070 */   sw       $v0, 0x70($s1)
.L80281120:
/* 7E1FA0 80281120 0C0A02B1 */  jal       shop_update_item_select_popup
/* 7E1FA4 80281124 2604000C */   addiu    $a0, $s0, 0xc
/* 7E1FA8 80281128 24030001 */  addiu     $v1, $zero, 1
/* 7E1FAC 8028112C 144300BA */  bne       $v0, $v1, .L80281418
/* 7E1FB0 80281130 0000102D */   daddu    $v0, $zero, $zero
/* 7E1FB4 80281134 080A049F */  j         .L8028127C
/* 7E1FB8 80281138 24020033 */   addiu    $v0, $zero, 0x33
.L8028113C:
/* 7E1FBC 8028113C 8E220074 */  lw        $v0, 0x74($s1)
/* 7E1FC0 80281140 1C400055 */  bgtz      $v0, .L80281298
/* 7E1FC4 80281144 2442FFFF */   addiu    $v0, $v0, -1
/* 7E1FC8 80281148 0C0A02D1 */  jal       shop_close_item_select_popup
/* 7E1FCC 8028114C 00000000 */   nop
/* 7E1FD0 80281150 8E02000C */  lw        $v0, 0xc($s0)
/* 7E1FD4 80281154 0440001C */  bltz      $v0, .L802811C8
/* 7E1FD8 80281158 00021040 */   sll      $v0, $v0, 1
/* 7E1FDC 8028115C 00521021 */  addu      $v0, $v0, $s2
/* 7E1FE0 80281160 0C039DF1 */  jal       store_item
/* 7E1FE4 80281164 844401B4 */   lh       $a0, 0x1b4($v0)
/* 7E1FE8 80281168 04400005 */  bltz      $v0, .L80281180
/* 7E1FEC 8028116C 00000000 */   nop
/* 7E1FF0 80281170 8E02000C */  lw        $v0, 0xc($s0)
/* 7E1FF4 80281174 00021040 */  sll       $v0, $v0, 1
/* 7E1FF8 80281178 00521021 */  addu      $v0, $v0, $s2
/* 7E1FFC 8028117C A44001B4 */  sh        $zero, 0x1b4($v0)
.L80281180:
/* 7E2000 80281180 0C039D7B */  jal       get_item_count
/* 7E2004 80281184 00000000 */   nop
/* 7E2008 80281188 10400005 */  beqz      $v0, .L802811A0
/* 7E200C 8028118C 00000000 */   nop
/* 7E2010 80281190 0C039E12 */  jal       get_stored_empty_count
/* 7E2014 80281194 00000000 */   nop
/* 7E2018 80281198 14400005 */  bnez      $v0, .L802811B0
/* 7E201C 8028119C 00000000 */   nop
.L802811A0:
/* 7E2020 802811A0 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E2024 802811A4 2404000F */   addiu    $a0, $zero, 0xf
/* 7E2028 802811A8 080A04EE */  j         .L802813B8
/* 7E202C 802811AC AE220074 */   sw       $v0, 0x74($s1)
.L802811B0:
/* 7E2030 802811B0 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E2034 802811B4 24040010 */   addiu    $a0, $zero, 0x10
/* 7E2038 802811B8 AE220074 */  sw        $v0, 0x74($s1)
/* 7E203C 802811BC 24020034 */  addiu     $v0, $zero, 0x34
/* 7E2040 802811C0 080A0505 */  j         .L80281414
/* 7E2044 802811C4 AE220070 */   sw       $v0, 0x70($s1)
.L802811C8:
/* 7E2048 802811C8 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E204C 802811CC 24040016 */   addiu    $a0, $zero, 0x16
/* 7E2050 802811D0 080A04EE */  j         .L802813B8
/* 7E2054 802811D4 AE220074 */   sw       $v0, 0x74($s1)
.L802811D8:
/* 7E2058 802811D8 8E240074 */  lw        $a0, 0x74($s1)
/* 7E205C 802811DC 0C0B1059 */  jal       does_script_exist
/* 7E2060 802811E0 00000000 */   nop
/* 7E2064 802811E4 1440008C */  bnez      $v0, .L80281418
/* 7E2068 802811E8 0000102D */   daddu    $v0, $zero, $zero
/* 7E206C 802811EC 3C04001E */  lui       $a0, 0x1e
/* 7E2070 802811F0 34840005 */  ori       $a0, $a0, 5
/* 7E2074 802811F4 26250078 */  addiu     $a1, $s1, 0x78
/* 7E2078 802811F8 080A04D5 */  j         .L80281354
/* 7E207C 802811FC 24020035 */   addiu    $v0, $zero, 0x35
.L80281200:
/* 7E2080 80281200 8E230078 */  lw        $v1, 0x78($s1)
/* 7E2084 80281204 24020001 */  addiu     $v0, $zero, 1
/* 7E2088 80281208 14620083 */  bne       $v1, $v0, .L80281418
/* 7E208C 8028120C 0000102D */   daddu    $v0, $zero, $zero
/* 7E2090 80281210 3C028028 */  lui       $v0, %hi(D_80286538)
/* 7E2094 80281214 8C426538 */  lw        $v0, %lo(D_80286538)($v0)
/* 7E2098 80281218 904204E8 */  lbu       $v0, 0x4e8($v0)
/* 7E209C 8028121C 14400063 */  bnez      $v0, .L802813AC
/* 7E20A0 80281220 00000000 */   nop
/* 7E20A4 80281224 0C0A00D7 */  jal       shop_owner_end_speech
/* 7E20A8 80281228 00000000 */   nop
/* 7E20AC 8028122C AE220074 */  sw        $v0, 0x74($s1)
.L80281230:
/* 7E20B0 80281230 240201F5 */  addiu     $v0, $zero, 0x1f5
/* 7E20B4 80281234 080A0505 */  j         .L80281414
/* 7E20B8 80281238 AE220070 */   sw       $v0, 0x70($s1)
.L8028123C:
/* 7E20BC 8028123C 8E240074 */  lw        $a0, 0x74($s1)
/* 7E20C0 80281240 0C0B1059 */  jal       does_script_exist
/* 7E20C4 80281244 00000000 */   nop
/* 7E20C8 80281248 14400073 */  bnez      $v0, .L80281418
/* 7E20CC 8028124C 0000102D */   daddu    $v0, $zero, $zero
/* 7E20D0 80281250 0C0A0255 */  jal       shop_open_item_select_popup
/* 7E20D4 80281254 24040002 */   addiu    $a0, $zero, 2
/* 7E20D8 80281258 24020007 */  addiu     $v0, $zero, 7
/* 7E20DC 8028125C 080A0505 */  j         .L80281414
/* 7E20E0 80281260 AE220070 */   sw       $v0, 0x70($s1)
.L80281264:
/* 7E20E4 80281264 0C0A02B1 */  jal       shop_update_item_select_popup
/* 7E20E8 80281268 2604000C */   addiu    $a0, $s0, 0xc
/* 7E20EC 8028126C 24030001 */  addiu     $v1, $zero, 1
/* 7E20F0 80281270 14430069 */  bne       $v0, $v1, .L80281418
/* 7E20F4 80281274 0000102D */   daddu    $v0, $zero, $zero
/* 7E20F8 80281278 24020047 */  addiu     $v0, $zero, 0x47
.L8028127C:
/* 7E20FC 8028127C AE220070 */  sw        $v0, 0x70($s1)
/* 7E2100 80281280 2402000F */  addiu     $v0, $zero, 0xf
/* 7E2104 80281284 080A0505 */  j         .L80281414
/* 7E2108 80281288 AE220074 */   sw       $v0, 0x74($s1)
.L8028128C:
/* 7E210C 8028128C 8E220074 */  lw        $v0, 0x74($s1)
/* 7E2110 80281290 18400003 */  blez      $v0, .L802812A0
/* 7E2114 80281294 2442FFFF */   addiu    $v0, $v0, -1
.L80281298:
/* 7E2118 80281298 080A0505 */  j         .L80281414
/* 7E211C 8028129C AE220074 */   sw       $v0, 0x74($s1)
.L802812A0:
/* 7E2120 802812A0 0C0A02D1 */  jal       shop_close_item_select_popup
/* 7E2124 802812A4 00000000 */   nop
/* 7E2128 802812A8 8E02000C */  lw        $v0, 0xc($s0)
/* 7E212C 802812AC 0440001C */  bltz      $v0, .L80281320
/* 7E2130 802812B0 00021040 */   sll      $v0, $v0, 1
/* 7E2134 802812B4 00521021 */  addu      $v0, $v0, $s2
/* 7E2138 802812B8 0C039D5D */  jal       add_item
/* 7E213C 802812BC 844401C8 */   lh       $a0, 0x1c8($v0)
/* 7E2140 802812C0 04400005 */  bltz      $v0, .L802812D8
/* 7E2144 802812C4 00000000 */   nop
/* 7E2148 802812C8 8E02000C */  lw        $v0, 0xc($s0)
/* 7E214C 802812CC 00021040 */  sll       $v0, $v0, 1
/* 7E2150 802812D0 00521021 */  addu      $v0, $v0, $s2
/* 7E2154 802812D4 A44001C8 */  sh        $zero, 0x1c8($v0)
.L802812D8:
/* 7E2158 802812D8 0C039D88 */  jal       get_item_empty_count
/* 7E215C 802812DC 00000000 */   nop
/* 7E2160 802812E0 10400005 */  beqz      $v0, .L802812F8
/* 7E2164 802812E4 00000000 */   nop
/* 7E2168 802812E8 0C039E05 */  jal       get_stored_count
/* 7E216C 802812EC 00000000 */   nop
/* 7E2170 802812F0 14400005 */  bnez      $v0, .L80281308
/* 7E2174 802812F4 00000000 */   nop
.L802812F8:
/* 7E2178 802812F8 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E217C 802812FC 24040014 */   addiu    $a0, $zero, 0x14
/* 7E2180 80281300 080A04EE */  j         .L802813B8
/* 7E2184 80281304 AE220074 */   sw       $v0, 0x74($s1)
.L80281308:
/* 7E2188 80281308 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E218C 8028130C 24040015 */   addiu    $a0, $zero, 0x15
/* 7E2190 80281310 AE220074 */  sw        $v0, 0x74($s1)
/* 7E2194 80281314 24020048 */  addiu     $v0, $zero, 0x48
/* 7E2198 80281318 080A0505 */  j         .L80281414
/* 7E219C 8028131C AE220070 */   sw       $v0, 0x70($s1)
.L80281320:
/* 7E21A0 80281320 0C0A0000 */  jal       shop_owner_begin_speech
/* 7E21A4 80281324 24040016 */   addiu    $a0, $zero, 0x16
/* 7E21A8 80281328 080A04EE */  j         .L802813B8
/* 7E21AC 8028132C AE220074 */   sw       $v0, 0x74($s1)
.L80281330:
/* 7E21B0 80281330 8E240074 */  lw        $a0, 0x74($s1)
/* 7E21B4 80281334 0C0B1059 */  jal       does_script_exist
/* 7E21B8 80281338 00000000 */   nop
/* 7E21BC 8028133C 14400036 */  bnez      $v0, .L80281418
/* 7E21C0 80281340 0000102D */   daddu    $v0, $zero, $zero
/* 7E21C4 80281344 3C04001E */  lui       $a0, 0x1e
/* 7E21C8 80281348 34840005 */  ori       $a0, $a0, 5
/* 7E21CC 8028134C 26250078 */  addiu     $a1, $s1, 0x78
/* 7E21D0 80281350 24020049 */  addiu     $v0, $zero, 0x49
.L80281354:
/* 7E21D4 80281354 AE220070 */  sw        $v0, 0x70($s1)
/* 7E21D8 80281358 0C049640 */  jal       msg_get_printer_for_string
/* 7E21DC 8028135C AE200078 */   sw       $zero, 0x78($s1)
/* 7E21E0 80281360 3C018028 */  lui       $at, %hi(D_80286538)
/* 7E21E4 80281364 AC226538 */  sw        $v0, %lo(D_80286538)($at)
/* 7E21E8 80281368 080A0506 */  j         .L80281418
/* 7E21EC 8028136C 0000102D */   daddu    $v0, $zero, $zero
.L80281370:
/* 7E21F0 80281370 8E230078 */  lw        $v1, 0x78($s1)
/* 7E21F4 80281374 24020001 */  addiu     $v0, $zero, 1
/* 7E21F8 80281378 14620027 */  bne       $v1, $v0, .L80281418
/* 7E21FC 8028137C 0000102D */   daddu    $v0, $zero, $zero
/* 7E2200 80281380 3C028028 */  lui       $v0, %hi(D_80286538)
/* 7E2204 80281384 8C426538 */  lw        $v0, %lo(D_80286538)($v0)
/* 7E2208 80281388 904204E8 */  lbu       $v0, 0x4e8($v0)
/* 7E220C 8028138C 14400007 */  bnez      $v0, .L802813AC
/* 7E2210 80281390 00000000 */   nop
/* 7E2214 80281394 0C0A00D7 */  jal       shop_owner_end_speech
/* 7E2218 80281398 00000000 */   nop
/* 7E221C 8028139C AE220074 */  sw        $v0, 0x74($s1)
.L802813A0:
/* 7E2220 802813A0 240202BD */  addiu     $v0, $zero, 0x2bd
/* 7E2224 802813A4 080A0505 */  j         .L80281414
/* 7E2228 802813A8 AE220070 */   sw       $v0, 0x70($s1)
.L802813AC:
/* 7E222C 802813AC 0C0A00B4 */  jal       shop_owner_reset_speech
/* 7E2230 802813B0 24040016 */   addiu    $a0, $zero, 0x16
/* 7E2234 802813B4 AE220074 */  sw        $v0, 0x74($s1)
.L802813B8:
/* 7E2238 802813B8 24020009 */  addiu     $v0, $zero, 9
/* 7E223C 802813BC 080A0505 */  j         .L80281414
/* 7E2240 802813C0 AE220070 */   sw       $v0, 0x70($s1)
.L802813C4:
/* 7E2244 802813C4 8E240074 */  lw        $a0, 0x74($s1)
/* 7E2248 802813C8 0C0B1059 */  jal       does_script_exist
/* 7E224C 802813CC 00000000 */   nop
/* 7E2250 802813D0 14400011 */  bnez      $v0, .L80281418
/* 7E2254 802813D4 0000102D */   daddu    $v0, $zero, $zero
/* 7E2258 802813D8 2402000A */  addiu     $v0, $zero, 0xa
/* 7E225C 802813DC 080A0505 */  j         .L80281414
/* 7E2260 802813E0 AE220070 */   sw       $v0, 0x70($s1)
.L802813E4:
/* 7E2264 802813E4 8E020010 */  lw        $v0, 0x10($s0)
/* 7E2268 802813E8 10400006 */  beqz      $v0, .L80281404
/* 7E226C 802813EC 00000000 */   nop
/* 7E2270 802813F0 8C440014 */  lw        $a0, 0x14($v0)
/* 7E2274 802813F4 10800003 */  beqz      $a0, .L80281404
/* 7E2278 802813F8 24050001 */   addiu    $a1, $zero, 1
/* 7E227C 802813FC 0C0B0CF8 */  jal       start_script
/* 7E2280 80281400 0000302D */   daddu    $a2, $zero, $zero
.L80281404:
/* 7E2284 80281404 0C03A5E3 */  jal       open_status_menu_short
/* 7E2288 80281408 00000000 */   nop
/* 7E228C 8028140C 080A0506 */  j         .L80281418
/* 7E2290 80281410 24020001 */   addiu    $v0, $zero, 1
.L80281414:
/* 7E2294 80281414 0000102D */  daddu     $v0, $zero, $zero
.L80281418:
/* 7E2298 80281418 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7E229C 8028141C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7E22A0 80281420 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E22A4 80281424 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E22A8 80281428 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E22AC 8028142C 03E00008 */  jr        $ra
/* 7E22B0 80281430 27BD0028 */   addiu    $sp, $sp, 0x28

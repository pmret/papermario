.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242918
/* CD9BF8 80242918 27BDFF68 */  addiu     $sp, $sp, -0x98
/* CD9BFC 8024291C AFB5007C */  sw        $s5, 0x7c($sp)
/* CD9C00 80242920 0080A82D */  daddu     $s5, $a0, $zero
/* CD9C04 80242924 AFBF0080 */  sw        $ra, 0x80($sp)
/* CD9C08 80242928 AFB40078 */  sw        $s4, 0x78($sp)
/* CD9C0C 8024292C AFB30074 */  sw        $s3, 0x74($sp)
/* CD9C10 80242930 AFB20070 */  sw        $s2, 0x70($sp)
/* CD9C14 80242934 AFB1006C */  sw        $s1, 0x6c($sp)
/* CD9C18 80242938 AFB00068 */  sw        $s0, 0x68($sp)
/* CD9C1C 8024293C F7B60090 */  sdc1      $f22, 0x90($sp)
/* CD9C20 80242940 F7B40088 */  sdc1      $f20, 0x88($sp)
/* CD9C24 80242944 8EB20148 */  lw        $s2, 0x148($s5)
/* CD9C28 80242948 86440008 */  lh        $a0, 8($s2)
/* CD9C2C 8024294C 0C00EABB */  jal       get_npc_unsafe
/* CD9C30 80242950 00A0802D */   daddu    $s0, $a1, $zero
/* CD9C34 80242954 8EA3000C */  lw        $v1, 0xc($s5)
/* CD9C38 80242958 02A0202D */  daddu     $a0, $s5, $zero
/* CD9C3C 8024295C 8C650000 */  lw        $a1, ($v1)
/* CD9C40 80242960 0C0B1EAF */  jal       get_variable
/* CD9C44 80242964 0040882D */   daddu    $s1, $v0, $zero
/* CD9C48 80242968 AFA00028 */  sw        $zero, 0x28($sp)
/* CD9C4C 8024296C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD9C50 80242970 8C630030 */  lw        $v1, 0x30($v1)
/* CD9C54 80242974 AFA3002C */  sw        $v1, 0x2c($sp)
/* CD9C58 80242978 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD9C5C 8024297C 8C63001C */  lw        $v1, 0x1c($v1)
/* CD9C60 80242980 AFA30030 */  sw        $v1, 0x30($sp)
/* CD9C64 80242984 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD9C68 80242988 8C630024 */  lw        $v1, 0x24($v1)
/* CD9C6C 8024298C AFA30034 */  sw        $v1, 0x34($sp)
/* CD9C70 80242990 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD9C74 80242994 8C630028 */  lw        $v1, 0x28($v1)
/* CD9C78 80242998 27B40028 */  addiu     $s4, $sp, 0x28
/* CD9C7C 8024299C AFA30038 */  sw        $v1, 0x38($sp)
/* CD9C80 802429A0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD9C84 802429A4 3C014282 */  lui       $at, 0x4282
/* CD9C88 802429A8 44810000 */  mtc1      $at, $f0
/* CD9C8C 802429AC 8C63002C */  lw        $v1, 0x2c($v1)
/* CD9C90 802429B0 0040982D */  daddu     $s3, $v0, $zero
/* CD9C94 802429B4 E7A00040 */  swc1      $f0, 0x40($sp)
/* CD9C98 802429B8 A7A00044 */  sh        $zero, 0x44($sp)
/* CD9C9C 802429BC 12000007 */  beqz      $s0, .L802429DC
/* CD9CA0 802429C0 AFA3003C */   sw       $v1, 0x3c($sp)
/* CD9CA4 802429C4 8E4200B0 */  lw        $v0, 0xb0($s2)
/* CD9CA8 802429C8 862300A8 */  lh        $v1, 0xa8($s1)
/* CD9CAC 802429CC 34420008 */  ori       $v0, $v0, 8
/* CD9CB0 802429D0 AE430084 */  sw        $v1, 0x84($s2)
/* CD9CB4 802429D4 08090A7B */  j         .L802429EC
/* CD9CB8 802429D8 AE4200B0 */   sw       $v0, 0xb0($s2)
.L802429DC:
/* CD9CBC 802429DC 8E430094 */  lw        $v1, 0x94($s2)
/* CD9CC0 802429E0 24020064 */  addiu     $v0, $zero, 0x64
/* CD9CC4 802429E4 1462001C */  bne       $v1, $v0, .L80242A58
/* CD9CC8 802429E8 00000000 */   nop      
.L802429EC:
/* CD9CCC 802429EC 24020064 */  addiu     $v0, $zero, 0x64
/* CD9CD0 802429F0 2404F7FF */  addiu     $a0, $zero, -0x801
/* CD9CD4 802429F4 AEA20070 */  sw        $v0, 0x70($s5)
/* CD9CD8 802429F8 A620008E */  sh        $zero, 0x8e($s1)
/* CD9CDC 802429FC 8E4300CC */  lw        $v1, 0xcc($s2)
/* CD9CE0 80242A00 8E220000 */  lw        $v0, ($s1)
/* CD9CE4 80242A04 3C01C47A */  lui       $at, 0xc47a
/* CD9CE8 80242A08 44810000 */  mtc1      $at, $f0
/* CD9CEC 80242A0C 8C630000 */  lw        $v1, ($v1)
/* CD9CF0 80242A10 00441024 */  and       $v0, $v0, $a0
/* CD9CF4 80242A14 AE220000 */  sw        $v0, ($s1)
/* CD9CF8 80242A18 AE230028 */  sw        $v1, 0x28($s1)
/* CD9CFC 80242A1C 8E420000 */  lw        $v0, ($s2)
/* CD9D00 80242A20 3C030020 */  lui       $v1, 0x20
/* CD9D04 80242A24 00431025 */  or        $v0, $v0, $v1
/* CD9D08 80242A28 AE420000 */  sw        $v0, ($s2)
/* CD9D0C 80242A2C 8E220000 */  lw        $v0, ($s1)
/* CD9D10 80242A30 2403FDFF */  addiu     $v1, $zero, -0x201
/* CD9D14 80242A34 00431024 */  and       $v0, $v0, $v1
/* CD9D18 80242A38 34420008 */  ori       $v0, $v0, 8
/* CD9D1C 80242A3C AE220000 */  sw        $v0, ($s1)
/* CD9D20 80242A40 2402FFFF */  addiu     $v0, $zero, -1
/* CD9D24 80242A44 AE400094 */  sw        $zero, 0x94($s2)
/* CD9D28 80242A48 AE420098 */  sw        $v0, 0x98($s2)
/* CD9D2C 80242A4C AE200038 */  sw        $zero, 0x38($s1)
/* CD9D30 80242A50 E620003C */  swc1      $f0, 0x3c($s1)
/* CD9D34 80242A54 AE200040 */  sw        $zero, 0x40($s1)
.L80242A58:
/* CD9D38 80242A58 8E4200B0 */  lw        $v0, 0xb0($s2)
/* CD9D3C 80242A5C 30420004 */  andi      $v0, $v0, 4
/* CD9D40 80242A60 10400030 */  beqz      $v0, .L80242B24
/* CD9D44 80242A64 2403FFFB */   addiu    $v1, $zero, -5
/* CD9D48 80242A68 A620008E */  sh        $zero, 0x8e($s1)
/* CD9D4C 80242A6C 96420086 */  lhu       $v0, 0x86($s2)
/* CD9D50 80242A70 A62200A8 */  sh        $v0, 0xa8($s1)
/* CD9D54 80242A74 8E4200B0 */  lw        $v0, 0xb0($s2)
/* CD9D58 80242A78 00431024 */  and       $v0, $v0, $v1
/* CD9D5C 80242A7C AE4200B0 */  sw        $v0, 0xb0($s2)
/* CD9D60 80242A80 8E220000 */  lw        $v0, ($s1)
/* CD9D64 80242A84 30420800 */  andi      $v0, $v0, 0x800
/* CD9D68 80242A88 1040000A */  beqz      $v0, .L80242AB4
/* CD9D6C 80242A8C 3C02004A */   lui      $v0, 0x4a
/* CD9D70 80242A90 3C013F80 */  lui       $at, 0x3f80
/* CD9D74 80242A94 44810000 */  mtc1      $at, $f0
/* CD9D78 80242A98 34420018 */  ori       $v0, $v0, 0x18
/* CD9D7C 80242A9C AE220028 */  sw        $v0, 0x28($s1)
/* CD9D80 80242AA0 24020066 */  addiu     $v0, $zero, 0x66
/* CD9D84 80242AA4 AE200018 */  sw        $zero, 0x18($s1)
/* CD9D88 80242AA8 AE20001C */  sw        $zero, 0x1c($s1)
/* CD9D8C 80242AAC 08090AC8 */  j         .L80242B20
/* CD9D90 80242AB0 E6200014 */   swc1     $f0, 0x14($s1)
.L80242AB4:
/* CD9D94 80242AB4 24040002 */  addiu     $a0, $zero, 2
/* CD9D98 80242AB8 0220282D */  daddu     $a1, $s1, $zero
/* CD9D9C 80242ABC 0000302D */  daddu     $a2, $zero, $zero
/* CD9DA0 80242AC0 862300A8 */  lh        $v1, 0xa8($s1)
/* CD9DA4 80242AC4 3C013F80 */  lui       $at, 0x3f80
/* CD9DA8 80242AC8 44810000 */  mtc1      $at, $f0
/* CD9DAC 80242ACC 3C014000 */  lui       $at, 0x4000
/* CD9DB0 80242AD0 44811000 */  mtc1      $at, $f2
/* CD9DB4 80242AD4 3C01C1A0 */  lui       $at, 0xc1a0
/* CD9DB8 80242AD8 44812000 */  mtc1      $at, $f4
/* CD9DBC 80242ADC 24020028 */  addiu     $v0, $zero, 0x28
/* CD9DC0 80242AE0 AFA2001C */  sw        $v0, 0x1c($sp)
/* CD9DC4 80242AE4 44834000 */  mtc1      $v1, $f8
/* CD9DC8 80242AE8 00000000 */  nop       
/* CD9DCC 80242AEC 46804220 */  cvt.s.w   $f8, $f8
/* CD9DD0 80242AF0 44074000 */  mfc1      $a3, $f8
/* CD9DD4 80242AF4 27A20048 */  addiu     $v0, $sp, 0x48
/* CD9DD8 80242AF8 AFA20020 */  sw        $v0, 0x20($sp)
/* CD9DDC 80242AFC E7A00010 */  swc1      $f0, 0x10($sp)
/* CD9DE0 80242B00 E7A20014 */  swc1      $f2, 0x14($sp)
/* CD9DE4 80242B04 0C01BFA4 */  jal       fx_emote
/* CD9DE8 80242B08 E7A40018 */   swc1     $f4, 0x18($sp)
/* CD9DEC 80242B0C 8E4200CC */  lw        $v0, 0xcc($s2)
/* CD9DF0 80242B10 8C420000 */  lw        $v0, ($v0)
/* CD9DF4 80242B14 AE220028 */  sw        $v0, 0x28($s1)
/* CD9DF8 80242B18 240200C8 */  addiu     $v0, $zero, 0xc8
/* CD9DFC 80242B1C AEA00074 */  sw        $zero, 0x74($s5)
.L80242B20:
/* CD9E00 80242B20 AEA20070 */  sw        $v0, 0x70($s5)
.L80242B24:
/* CD9E04 80242B24 27A2004C */  addiu     $v0, $sp, 0x4c
/* CD9E08 80242B28 AFA20010 */  sw        $v0, 0x10($sp)
/* CD9E0C 80242B2C 27A20050 */  addiu     $v0, $sp, 0x50
/* CD9E10 80242B30 AFA20014 */  sw        $v0, 0x14($sp)
/* CD9E14 80242B34 27A20054 */  addiu     $v0, $sp, 0x54
/* CD9E18 80242B38 AFA20018 */  sw        $v0, 0x18($sp)
/* CD9E1C 80242B3C 8E250038 */  lw        $a1, 0x38($s1)
/* CD9E20 80242B40 8E26003C */  lw        $a2, 0x3c($s1)
/* CD9E24 80242B44 8E270040 */  lw        $a3, 0x40($s1)
/* CD9E28 80242B48 0C00B94E */  jal       get_screen_coords
/* CD9E2C 80242B4C 0000202D */   daddu    $a0, $zero, $zero
/* CD9E30 80242B50 8EA20070 */  lw        $v0, 0x70($s5)
/* CD9E34 80242B54 28420064 */  slti      $v0, $v0, 0x64
/* CD9E38 80242B58 10400007 */  beqz      $v0, .L80242B78
/* CD9E3C 80242B5C 00000000 */   nop      
/* CD9E40 80242B60 8FA2004C */  lw        $v0, 0x4c($sp)
/* CD9E44 80242B64 24420032 */  addiu     $v0, $v0, 0x32
/* CD9E48 80242B68 2C4201A5 */  sltiu     $v0, $v0, 0x1a5
/* CD9E4C 80242B6C 14400002 */  bnez      $v0, .L80242B78
/* CD9E50 80242B70 2402006E */   addiu    $v0, $zero, 0x6e
/* CD9E54 80242B74 AEA20070 */  sw        $v0, 0x70($s5)
.L80242B78:
/* CD9E58 80242B78 8EA30070 */  lw        $v1, 0x70($s5)
/* CD9E5C 80242B7C 2402000F */  addiu     $v0, $zero, 0xf
/* CD9E60 80242B80 1062006B */  beq       $v1, $v0, .L80242D30
/* CD9E64 80242B84 28620010 */   slti     $v0, $v1, 0x10
/* CD9E68 80242B88 10400016 */  beqz      $v0, .L80242BE4
/* CD9E6C 80242B8C 24020003 */   addiu    $v0, $zero, 3
/* CD9E70 80242B90 10620051 */  beq       $v1, $v0, .L80242CD8
/* CD9E74 80242B94 28620004 */   slti     $v0, $v1, 4
/* CD9E78 80242B98 10400009 */  beqz      $v0, .L80242BC0
/* CD9E7C 80242B9C 24020001 */   addiu    $v0, $zero, 1
/* CD9E80 80242BA0 10620044 */  beq       $v1, $v0, .L80242CB4
/* CD9E84 80242BA4 28620002 */   slti     $v0, $v1, 2
/* CD9E88 80242BA8 50400048 */  beql      $v0, $zero, .L80242CCC
/* CD9E8C 80242BAC 02A0202D */   daddu    $a0, $s5, $zero
/* CD9E90 80242BB0 50600027 */  beql      $v1, $zero, .L80242C50
/* CD9E94 80242BB4 02A0202D */   daddu    $a0, $s5, $zero
/* CD9E98 80242BB8 08090C79 */  j         .L802431E4
/* CD9E9C 80242BBC 00000000 */   nop      
.L80242BC0:
/* CD9EA0 80242BC0 2402000D */  addiu     $v0, $zero, 0xd
/* CD9EA4 80242BC4 1062004D */  beq       $v1, $v0, .L80242CFC
/* CD9EA8 80242BC8 2862000E */   slti     $v0, $v1, 0xe
/* CD9EAC 80242BCC 10400052 */  beqz      $v0, .L80242D18
/* CD9EB0 80242BD0 2402000C */   addiu    $v0, $zero, 0xc
/* CD9EB4 80242BD4 10620046 */  beq       $v1, $v0, .L80242CF0
/* CD9EB8 80242BD8 02A0202D */   daddu    $a0, $s5, $zero
/* CD9EBC 80242BDC 08090C79 */  j         .L802431E4
/* CD9EC0 80242BE0 00000000 */   nop      
.L80242BE4:
/* CD9EC4 80242BE4 24020067 */  addiu     $v0, $zero, 0x67
/* CD9EC8 80242BE8 10620158 */  beq       $v1, $v0, .L8024314C
/* CD9ECC 80242BEC 28620068 */   slti     $v0, $v1, 0x68
/* CD9ED0 80242BF0 10400009 */  beqz      $v0, .L80242C18
/* CD9ED4 80242BF4 24020065 */   addiu    $v0, $zero, 0x65
/* CD9ED8 80242BF8 1062008F */  beq       $v1, $v0, .L80242E38
/* CD9EDC 80242BFC 28620066 */   slti     $v0, $v1, 0x66
/* CD9EE0 80242C00 104000A9 */  beqz      $v0, .L80242EA8
/* CD9EE4 80242C04 24020064 */   addiu    $v0, $zero, 0x64
/* CD9EE8 80242C08 1062004F */  beq       $v1, $v0, .L80242D48
/* CD9EEC 80242C0C 24020002 */   addiu    $v0, $zero, 2
/* CD9EF0 80242C10 08090C79 */  j         .L802431E4
/* CD9EF4 80242C14 00000000 */   nop      
.L80242C18:
/* CD9EF8 80242C18 2404006F */  addiu     $a0, $zero, 0x6f
/* CD9EFC 80242C1C 10640166 */  beq       $v1, $a0, .L802431B8
/* CD9F00 80242C20 28620070 */   slti     $v0, $v1, 0x70
/* CD9F04 80242C24 10400005 */  beqz      $v0, .L80242C3C
/* CD9F08 80242C28 2402006E */   addiu    $v0, $zero, 0x6e
/* CD9F0C 80242C2C 10620156 */  beq       $v1, $v0, .L80243188
/* CD9F10 80242C30 2402001E */   addiu    $v0, $zero, 0x1e
/* CD9F14 80242C34 08090C79 */  j         .L802431E4
/* CD9F18 80242C38 00000000 */   nop      
.L80242C3C:
/* CD9F1C 80242C3C 240200C8 */  addiu     $v0, $zero, 0xc8
/* CD9F20 80242C40 10620166 */  beq       $v1, $v0, .L802431DC
/* CD9F24 80242C44 00000000 */   nop      
/* CD9F28 80242C48 08090C79 */  j         .L802431E4
/* CD9F2C 80242C4C 00000000 */   nop      
.L80242C50:
/* CD9F30 80242C50 0260282D */  daddu     $a1, $s3, $zero
/* CD9F34 80242C54 0C012568 */  jal       func_800495A0
/* CD9F38 80242C58 0280302D */   daddu    $a2, $s4, $zero
/* CD9F3C 80242C5C 96420086 */  lhu       $v0, 0x86($s2)
/* CD9F40 80242C60 A62200A8 */  sh        $v0, 0xa8($s1)
/* CD9F44 80242C64 8E4200A0 */  lw        $v0, 0xa0($s2)
/* CD9F48 80242C68 10400013 */  beqz      $v0, .L80242CB8
/* CD9F4C 80242C6C 02A0202D */   daddu    $a0, $s5, $zero
/* CD9F50 80242C70 C620003C */  lwc1      $f0, 0x3c($s1)
/* CD9F54 80242C74 44801000 */  mtc1      $zero, $f2
/* CD9F58 80242C78 44801800 */  mtc1      $zero, $f3
/* CD9F5C 80242C7C 46000021 */  cvt.d.s   $f0, $f0
/* CD9F60 80242C80 4622003E */  c.le.d    $f0, $f2
/* CD9F64 80242C84 00000000 */  nop       
/* CD9F68 80242C88 45000005 */  bc1f      .L80242CA0
/* CD9F6C 80242C8C 2403FDFF */   addiu    $v1, $zero, -0x201
/* CD9F70 80242C90 8E220000 */  lw        $v0, ($s1)
/* CD9F74 80242C94 00431024 */  and       $v0, $v0, $v1
/* CD9F78 80242C98 08090B2C */  j         .L80242CB0
/* CD9F7C 80242C9C 34420008 */   ori      $v0, $v0, 8
.L80242CA0:
/* CD9F80 80242CA0 8E220000 */  lw        $v0, ($s1)
/* CD9F84 80242CA4 2403FFF7 */  addiu     $v1, $zero, -9
/* CD9F88 80242CA8 34420200 */  ori       $v0, $v0, 0x200
/* CD9F8C 80242CAC 00431024 */  and       $v0, $v0, $v1
.L80242CB0:
/* CD9F90 80242CB0 AE220000 */  sw        $v0, ($s1)
.L80242CB4:
/* CD9F94 80242CB4 02A0202D */  daddu     $a0, $s5, $zero
.L80242CB8:
/* CD9F98 80242CB8 0260282D */  daddu     $a1, $s3, $zero
/* CD9F9C 80242CBC 0C0125AE */  jal       func_800496B8
/* CD9FA0 80242CC0 0280302D */   daddu    $a2, $s4, $zero
/* CD9FA4 80242CC4 08090C79 */  j         .L802431E4
/* CD9FA8 80242CC8 00000000 */   nop      
.L80242CCC:
/* CD9FAC 80242CCC 0260282D */  daddu     $a1, $s3, $zero
/* CD9FB0 80242CD0 0C0126D1 */  jal       func_80049B44
/* CD9FB4 80242CD4 0280302D */   daddu    $a2, $s4, $zero
.L80242CD8:
/* CD9FB8 80242CD8 02A0202D */  daddu     $a0, $s5, $zero
/* CD9FBC 80242CDC 0260282D */  daddu     $a1, $s3, $zero
/* CD9FC0 80242CE0 0C012701 */  jal       func_80049C04
/* CD9FC4 80242CE4 0280302D */   daddu    $a2, $s4, $zero
/* CD9FC8 80242CE8 08090C79 */  j         .L802431E4
/* CD9FCC 80242CEC 00000000 */   nop      
.L80242CF0:
/* CD9FD0 80242CF0 0260282D */  daddu     $a1, $s3, $zero
/* CD9FD4 80242CF4 0C090851 */  jal       func_80242144
/* CD9FD8 80242CF8 0280302D */   daddu    $a2, $s4, $zero
.L80242CFC:
/* CD9FDC 80242CFC 02A0202D */  daddu     $a0, $s5, $zero
/* CD9FE0 80242D00 0260282D */  daddu     $a1, $s3, $zero
/* CD9FE4 80242D04 0C090870 */  jal       func_802421C0
/* CD9FE8 80242D08 0280302D */   daddu    $a2, $s4, $zero
/* CD9FEC 80242D0C 96420086 */  lhu       $v0, 0x86($s2)
/* CD9FF0 80242D10 08090C79 */  j         .L802431E4
/* CD9FF4 80242D14 A62200A8 */   sh       $v0, 0xa8($s1)
.L80242D18:
/* CD9FF8 80242D18 02A0202D */  daddu     $a0, $s5, $zero
/* CD9FFC 80242D1C 0260282D */  daddu     $a1, $s3, $zero
/* CDA000 80242D20 0C0908BD */  jal       func_802422F4
/* CDA004 80242D24 0280302D */   daddu    $a2, $s4, $zero
/* CDA008 80242D28 08090C79 */  j         .L802431E4
/* CDA00C 80242D2C 00000000 */   nop      
.L80242D30:
/* CDA010 80242D30 02A0202D */  daddu     $a0, $s5, $zero
/* CDA014 80242D34 0260282D */  daddu     $a1, $s3, $zero
/* CDA018 80242D38 0C090916 */  jal       func_80242458
/* CDA01C 80242D3C 0280302D */   daddu    $a2, $s4, $zero
/* CDA020 80242D40 08090C79 */  j         .L802431E4
/* CDA024 80242D44 00000000 */   nop      
.L80242D48:
/* CDA028 80242D48 8E430094 */  lw        $v1, 0x94($s2)
/* CDA02C 80242D4C 14620125 */  bne       $v1, $v0, .L802431E4
/* CDA030 80242D50 00000000 */   nop      
/* CDA034 80242D54 0C00FB3A */  jal       get_enemy
/* CDA038 80242D58 8E440098 */   lw       $a0, 0x98($s2)
/* CDA03C 80242D5C 0C00EABB */  jal       get_npc_unsafe
/* CDA040 80242D60 84440008 */   lh       $a0, 8($v0)
/* CDA044 80242D64 C440000C */  lwc1      $f0, 0xc($v0)
/* CDA048 80242D68 3C018024 */  lui       $at, 0x8024
/* CDA04C 80242D6C D42253B8 */  ldc1      $f2, 0x53b8($at)
/* CDA050 80242D70 46000021 */  cvt.d.s   $f0, $f0
/* CDA054 80242D74 4622003C */  c.lt.d    $f0, $f2
/* CDA058 80242D78 00000000 */  nop       
/* CDA05C 80242D7C 45000008 */  bc1f      .L80242DA0
/* CDA060 80242D80 00000000 */   nop      
/* CDA064 80242D84 C4400038 */  lwc1      $f0, 0x38($v0)
/* CDA068 80242D88 3C014028 */  lui       $at, 0x4028
/* CDA06C 80242D8C 44811800 */  mtc1      $at, $f3
/* CDA070 80242D90 44801000 */  mtc1      $zero, $f2
/* CDA074 80242D94 46000021 */  cvt.d.s   $f0, $f0
/* CDA078 80242D98 08090B6E */  j         .L80242DB8
/* CDA07C 80242D9C 46220000 */   add.d    $f0, $f0, $f2
.L80242DA0:
/* CDA080 80242DA0 C4400038 */  lwc1      $f0, 0x38($v0)
/* CDA084 80242DA4 3C014028 */  lui       $at, 0x4028
/* CDA088 80242DA8 44811800 */  mtc1      $at, $f3
/* CDA08C 80242DAC 44801000 */  mtc1      $zero, $f2
/* CDA090 80242DB0 46000021 */  cvt.d.s   $f0, $f0
/* CDA094 80242DB4 46220001 */  sub.d     $f0, $f0, $f2
.L80242DB8:
/* CDA098 80242DB8 46200020 */  cvt.s.d   $f0, $f0
/* CDA09C 80242DBC E6200038 */  swc1      $f0, 0x38($s1)
/* CDA0A0 80242DC0 3C04004A */  lui       $a0, 0x4a
/* CDA0A4 80242DC4 C440003C */  lwc1      $f0, 0x3c($v0)
/* CDA0A8 80242DC8 3C014039 */  lui       $at, 0x4039
/* CDA0AC 80242DCC 44811800 */  mtc1      $at, $f3
/* CDA0B0 80242DD0 44801000 */  mtc1      $zero, $f2
/* CDA0B4 80242DD4 46000021 */  cvt.d.s   $f0, $f0
/* CDA0B8 80242DD8 46220000 */  add.d     $f0, $f0, $f2
/* CDA0BC 80242DDC 34840018 */  ori       $a0, $a0, 0x18
/* CDA0C0 80242DE0 3C013FF0 */  lui       $at, 0x3ff0
/* CDA0C4 80242DE4 44811800 */  mtc1      $at, $f3
/* CDA0C8 80242DE8 44801000 */  mtc1      $zero, $f2
/* CDA0CC 80242DEC 46200020 */  cvt.s.d   $f0, $f0
/* CDA0D0 80242DF0 E620003C */  swc1      $f0, 0x3c($s1)
/* CDA0D4 80242DF4 C4400040 */  lwc1      $f0, 0x40($v0)
/* CDA0D8 80242DF8 8E220000 */  lw        $v0, ($s1)
/* CDA0DC 80242DFC 2403FFFD */  addiu     $v1, $zero, -3
/* CDA0E0 80242E00 AE200048 */  sw        $zero, 0x48($s1)
/* CDA0E4 80242E04 AE200034 */  sw        $zero, 0x34($s1)
/* CDA0E8 80242E08 AE240028 */  sw        $a0, 0x28($s1)
/* CDA0EC 80242E0C 34420008 */  ori       $v0, $v0, 8
/* CDA0F0 80242E10 00431024 */  and       $v0, $v0, $v1
/* CDA0F4 80242E14 2403FDFF */  addiu     $v1, $zero, -0x201
/* CDA0F8 80242E18 00431024 */  and       $v0, $v0, $v1
/* CDA0FC 80242E1C 46000021 */  cvt.d.s   $f0, $f0
/* CDA100 80242E20 46220000 */  add.d     $f0, $f0, $f2
/* CDA104 80242E24 AE220000 */  sw        $v0, ($s1)
/* CDA108 80242E28 24020065 */  addiu     $v0, $zero, 0x65
/* CDA10C 80242E2C 46200020 */  cvt.s.d   $f0, $f0
/* CDA110 80242E30 E6200040 */  swc1      $f0, 0x40($s1)
/* CDA114 80242E34 AEA20070 */  sw        $v0, 0x70($s5)
.L80242E38:
/* CDA118 80242E38 8E430094 */  lw        $v1, 0x94($s2)
/* CDA11C 80242E3C 24020003 */  addiu     $v0, $zero, 3
/* CDA120 80242E40 146200E8 */  bne       $v1, $v0, .L802431E4
/* CDA124 80242E44 24020004 */   addiu    $v0, $zero, 4
/* CDA128 80242E48 AE420094 */  sw        $v0, 0x94($s2)
/* CDA12C 80242E4C C62C0038 */  lwc1      $f12, 0x38($s1)
/* CDA130 80242E50 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CDA134 80242E54 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CDA138 80242E58 C62E0040 */  lwc1      $f14, 0x40($s1)
/* CDA13C 80242E5C 8C460028 */  lw        $a2, 0x28($v0)
/* CDA140 80242E60 0C00A720 */  jal       atan2
/* CDA144 80242E64 8C470030 */   lw       $a3, 0x30($v0)
/* CDA148 80242E68 3C014020 */  lui       $at, 0x4020
/* CDA14C 80242E6C 44811000 */  mtc1      $at, $f2
/* CDA150 80242E70 3C014100 */  lui       $at, 0x4100
/* CDA154 80242E74 44812000 */  mtc1      $at, $f4
/* CDA158 80242E78 3C013F4C */  lui       $at, 0x3f4c
/* CDA15C 80242E7C 3421CCCD */  ori       $at, $at, 0xcccd
/* CDA160 80242E80 44813000 */  mtc1      $at, $f6
/* CDA164 80242E84 8E220000 */  lw        $v0, ($s1)
/* CDA168 80242E88 E620000C */  swc1      $f0, 0xc($s1)
/* CDA16C 80242E8C 34420800 */  ori       $v0, $v0, 0x800
/* CDA170 80242E90 AE220000 */  sw        $v0, ($s1)
/* CDA174 80242E94 24020066 */  addiu     $v0, $zero, 0x66
/* CDA178 80242E98 E6220018 */  swc1      $f2, 0x18($s1)
/* CDA17C 80242E9C E624001C */  swc1      $f4, 0x1c($s1)
/* CDA180 80242EA0 E6260014 */  swc1      $f6, 0x14($s1)
/* CDA184 80242EA4 AEA20070 */  sw        $v0, 0x70($s5)
.L80242EA8:
/* CDA188 80242EA8 C6200018 */  lwc1      $f0, 0x18($s1)
/* CDA18C 80242EAC 44801000 */  mtc1      $zero, $f2
/* CDA190 80242EB0 44801800 */  mtc1      $zero, $f3
/* CDA194 80242EB4 46000021 */  cvt.d.s   $f0, $f0
/* CDA198 80242EB8 4620103C */  c.lt.d    $f2, $f0
/* CDA19C 80242EBC 00000000 */  nop       
/* CDA1A0 80242EC0 4500001F */  bc1f      .L80242F40
/* CDA1A4 80242EC4 27A50058 */   addiu    $a1, $sp, 0x58
/* CDA1A8 80242EC8 C6200038 */  lwc1      $f0, 0x38($s1)
/* CDA1AC 80242ECC C622003C */  lwc1      $f2, 0x3c($s1)
/* CDA1B0 80242ED0 C6240040 */  lwc1      $f4, 0x40($s1)
/* CDA1B4 80242ED4 C6260018 */  lwc1      $f6, 0x18($s1)
/* CDA1B8 80242ED8 E7A00058 */  swc1      $f0, 0x58($sp)
/* CDA1BC 80242EDC E7A2005C */  swc1      $f2, 0x5c($sp)
/* CDA1C0 80242EE0 E7A40060 */  swc1      $f4, 0x60($sp)
/* CDA1C4 80242EE4 E7A60010 */  swc1      $f6, 0x10($sp)
/* CDA1C8 80242EE8 C620000C */  lwc1      $f0, 0xc($s1)
/* CDA1CC 80242EEC E7A00014 */  swc1      $f0, 0x14($sp)
/* CDA1D0 80242EF0 862200A8 */  lh        $v0, 0xa8($s1)
/* CDA1D4 80242EF4 44820000 */  mtc1      $v0, $f0
/* CDA1D8 80242EF8 00000000 */  nop       
/* CDA1DC 80242EFC 46800020 */  cvt.s.w   $f0, $f0
/* CDA1E0 80242F00 E7A00018 */  swc1      $f0, 0x18($sp)
/* CDA1E4 80242F04 862200A6 */  lh        $v0, 0xa6($s1)
/* CDA1E8 80242F08 27A6005C */  addiu     $a2, $sp, 0x5c
/* CDA1EC 80242F0C 44820000 */  mtc1      $v0, $f0
/* CDA1F0 80242F10 00000000 */  nop       
/* CDA1F4 80242F14 46800020 */  cvt.s.w   $f0, $f0
/* CDA1F8 80242F18 E7A0001C */  swc1      $f0, 0x1c($sp)
/* CDA1FC 80242F1C 8E240080 */  lw        $a0, 0x80($s1)
/* CDA200 80242F20 0C037711 */  jal       func_800DDC44
/* CDA204 80242F24 27A70060 */   addiu    $a3, $sp, 0x60
/* CDA208 80242F28 54400005 */  bnel      $v0, $zero, .L80242F40
/* CDA20C 80242F2C AE200018 */   sw       $zero, 0x18($s1)
/* CDA210 80242F30 8E250018 */  lw        $a1, 0x18($s1)
/* CDA214 80242F34 8E26000C */  lw        $a2, 0xc($s1)
/* CDA218 80242F38 0C00EA95 */  jal       npc_move_heading
/* CDA21C 80242F3C 0220202D */   daddu    $a0, $s1, $zero
.L80242F40:
/* CDA220 80242F40 C620001C */  lwc1      $f0, 0x1c($s1)
/* CDA224 80242F44 4480B000 */  mtc1      $zero, $f22
/* CDA228 80242F48 4480B800 */  mtc1      $zero, $f23
/* CDA22C 80242F4C 46000021 */  cvt.d.s   $f0, $f0
/* CDA230 80242F50 4636003C */  c.lt.d    $f0, $f22
/* CDA234 80242F54 00000000 */  nop       
/* CDA238 80242F58 45000074 */  bc1f      .L8024312C
/* CDA23C 80242F5C 27A50058 */   addiu    $a1, $sp, 0x58
/* CDA240 80242F60 27A6005C */  addiu     $a2, $sp, 0x5c
/* CDA244 80242F64 27A20064 */  addiu     $v0, $sp, 0x64
/* CDA248 80242F68 C622003C */  lwc1      $f2, 0x3c($s1)
/* CDA24C 80242F6C C6260038 */  lwc1      $f6, 0x38($s1)
/* CDA250 80242F70 3C01402A */  lui       $at, 0x402a
/* CDA254 80242F74 4481A800 */  mtc1      $at, $f21
/* CDA258 80242F78 4480A000 */  mtc1      $zero, $f20
/* CDA25C 80242F7C 460010A1 */  cvt.d.s   $f2, $f2
/* CDA260 80242F80 46341080 */  add.d     $f2, $f2, $f20
/* CDA264 80242F84 C620001C */  lwc1      $f0, 0x1c($s1)
/* CDA268 80242F88 C6240040 */  lwc1      $f4, 0x40($s1)
/* CDA26C 80242F8C 46000005 */  abs.s     $f0, $f0
/* CDA270 80242F90 E7A40060 */  swc1      $f4, 0x60($sp)
/* CDA274 80242F94 3C014030 */  lui       $at, 0x4030
/* CDA278 80242F98 44812800 */  mtc1      $at, $f5
/* CDA27C 80242F9C 44802000 */  mtc1      $zero, $f4
/* CDA280 80242FA0 46000021 */  cvt.d.s   $f0, $f0
/* CDA284 80242FA4 E7A60058 */  swc1      $f6, 0x58($sp)
/* CDA288 80242FA8 46240000 */  add.d     $f0, $f0, $f4
/* CDA28C 80242FAC 462010A0 */  cvt.s.d   $f2, $f2
/* CDA290 80242FB0 E7A2005C */  swc1      $f2, 0x5c($sp)
/* CDA294 80242FB4 46200020 */  cvt.s.d   $f0, $f0
/* CDA298 80242FB8 E7A00064 */  swc1      $f0, 0x64($sp)
/* CDA29C 80242FBC AFA20010 */  sw        $v0, 0x10($sp)
/* CDA2A0 80242FC0 8E240080 */  lw        $a0, 0x80($s1)
/* CDA2A4 80242FC4 0C0372DF */  jal       func_800DCB7C
/* CDA2A8 80242FC8 27A70060 */   addiu    $a3, $sp, 0x60
/* CDA2AC 80242FCC 10400057 */  beqz      $v0, .L8024312C
/* CDA2B0 80242FD0 00000000 */   nop      
/* CDA2B4 80242FD4 C620001C */  lwc1      $f0, 0x1c($s1)
/* CDA2B8 80242FD8 C7A20064 */  lwc1      $f2, 0x64($sp)
/* CDA2BC 80242FDC 46000005 */  abs.s     $f0, $f0
/* CDA2C0 80242FE0 46000021 */  cvt.d.s   $f0, $f0
/* CDA2C4 80242FE4 46340000 */  add.d     $f0, $f0, $f20
/* CDA2C8 80242FE8 460010A1 */  cvt.d.s   $f2, $f2
/* CDA2CC 80242FEC 4620103E */  c.le.d    $f2, $f0
/* CDA2D0 80242FF0 00000000 */  nop       
/* CDA2D4 80242FF4 4500004D */  bc1f      .L8024312C
/* CDA2D8 80242FF8 00000000 */   nop      
/* CDA2DC 80242FFC C7A0005C */  lwc1      $f0, 0x5c($sp)
/* CDA2E0 80243000 E620003C */  swc1      $f0, 0x3c($s1)
/* CDA2E4 80243004 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CDA2E8 80243008 C6200038 */  lwc1      $f0, 0x38($s1)
/* CDA2EC 8024300C 4600020D */  trunc.w.s $f8, $f0
/* CDA2F0 80243010 E4480000 */  swc1      $f8, ($v0)
/* CDA2F4 80243014 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CDA2F8 80243018 C620003C */  lwc1      $f0, 0x3c($s1)
/* CDA2FC 8024301C 4600020D */  trunc.w.s $f8, $f0
/* CDA300 80243020 E4480004 */  swc1      $f8, 4($v0)
/* CDA304 80243024 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CDA308 80243028 C6200040 */  lwc1      $f0, 0x40($s1)
/* CDA30C 8024302C 4600020D */  trunc.w.s $f8, $f0
/* CDA310 80243030 E4480008 */  swc1      $f8, 8($v0)
/* CDA314 80243034 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CDA318 80243038 C6200038 */  lwc1      $f0, 0x38($s1)
/* CDA31C 8024303C 4600020D */  trunc.w.s $f8, $f0
/* CDA320 80243040 E448001C */  swc1      $f8, 0x1c($v0)
/* CDA324 80243044 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CDA328 80243048 C620003C */  lwc1      $f0, 0x3c($s1)
/* CDA32C 8024304C 4600020D */  trunc.w.s $f8, $f0
/* CDA330 80243050 E4480020 */  swc1      $f8, 0x20($v0)
/* CDA334 80243054 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CDA338 80243058 C6200040 */  lwc1      $f0, 0x40($s1)
/* CDA33C 8024305C 4600020D */  trunc.w.s $f8, $f0
/* CDA340 80243060 E4480024 */  swc1      $f8, 0x24($v0)
/* CDA344 80243064 8E4300A0 */  lw        $v1, 0xa0($s2)
/* CDA348 80243068 24020005 */  addiu     $v0, $zero, 5
/* CDA34C 8024306C 1060000B */  beqz      $v1, .L8024309C
/* CDA350 80243070 AE420094 */   sw       $v0, 0x94($s2)
/* CDA354 80243074 C620003C */  lwc1      $f0, 0x3c($s1)
/* CDA358 80243078 46000021 */  cvt.d.s   $f0, $f0
/* CDA35C 8024307C 4636003E */  c.le.d    $f0, $f22
/* CDA360 80243080 00000000 */  nop       
/* CDA364 80243084 4501000D */  bc1t      .L802430BC
/* CDA368 80243088 2403FFF7 */   addiu    $v1, $zero, -9
/* CDA36C 8024308C 8E220000 */  lw        $v0, ($s1)
/* CDA370 80243090 34420200 */  ori       $v0, $v0, 0x200
/* CDA374 80243094 08090C33 */  j         .L802430CC
/* CDA378 80243098 00431024 */   and      $v0, $v0, $v1
.L8024309C:
/* CDA37C 8024309C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CDA380 802430A0 8C420034 */  lw        $v0, 0x34($v0)
/* CDA384 802430A4 14400005 */  bnez      $v0, .L802430BC
/* CDA388 802430A8 2403FFF7 */   addiu    $v1, $zero, -9
/* CDA38C 802430AC 8E220000 */  lw        $v0, ($s1)
/* CDA390 802430B0 34420200 */  ori       $v0, $v0, 0x200
/* CDA394 802430B4 08090C33 */  j         .L802430CC
/* CDA398 802430B8 00431024 */   and      $v0, $v0, $v1
.L802430BC:
/* CDA39C 802430BC 8E220000 */  lw        $v0, ($s1)
/* CDA3A0 802430C0 2403FDFF */  addiu     $v1, $zero, -0x201
/* CDA3A4 802430C4 00431024 */  and       $v0, $v0, $v1
/* CDA3A8 802430C8 34420008 */  ori       $v0, $v0, 8
.L802430CC:
/* CDA3AC 802430CC AE220000 */  sw        $v0, ($s1)
/* CDA3B0 802430D0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CDA3B4 802430D4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* CDA3B8 802430D8 8E220000 */  lw        $v0, ($s1)
/* CDA3BC 802430DC 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* CDA3C0 802430E0 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* CDA3C4 802430E4 3C030004 */  lui       $v1, 4
/* CDA3C8 802430E8 AE20001C */  sw        $zero, 0x1c($s1)
/* CDA3CC 802430EC 00431025 */  or        $v0, $v0, $v1
/* CDA3D0 802430F0 2403F7FF */  addiu     $v1, $zero, -0x801
/* CDA3D4 802430F4 00431024 */  and       $v0, $v0, $v1
/* CDA3D8 802430F8 AE220000 */  sw        $v0, ($s1)
/* CDA3DC 802430FC 8C860028 */  lw        $a2, 0x28($a0)
/* CDA3E0 80243100 0C00A720 */  jal       atan2
/* CDA3E4 80243104 8C870030 */   lw       $a3, 0x30($a0)
/* CDA3E8 80243108 3C02004A */  lui       $v0, 0x4a
/* CDA3EC 8024310C 3442001A */  ori       $v0, $v0, 0x1a
/* CDA3F0 80243110 AE220028 */  sw        $v0, 0x28($s1)
/* CDA3F4 80243114 24020003 */  addiu     $v0, $zero, 3
/* CDA3F8 80243118 A622008E */  sh        $v0, 0x8e($s1)
/* CDA3FC 8024311C 24020067 */  addiu     $v0, $zero, 0x67
/* CDA400 80243120 E620000C */  swc1      $f0, 0xc($s1)
/* CDA404 80243124 08090C79 */  j         .L802431E4
/* CDA408 80243128 AEA20070 */   sw       $v0, 0x70($s5)
.L8024312C:
/* CDA40C 8024312C C624003C */  lwc1      $f4, 0x3c($s1)
/* CDA410 80243130 C620001C */  lwc1      $f0, 0x1c($s1)
/* CDA414 80243134 46002100 */  add.s     $f4, $f4, $f0
/* CDA418 80243138 C6220014 */  lwc1      $f2, 0x14($s1)
/* CDA41C 8024313C 46020001 */  sub.s     $f0, $f0, $f2
/* CDA420 80243140 E624003C */  swc1      $f4, 0x3c($s1)
/* CDA424 80243144 08090C79 */  j         .L802431E4
/* CDA428 80243148 E620001C */   swc1     $f0, 0x1c($s1)
.L8024314C:
/* CDA42C 8024314C 9622008E */  lhu       $v0, 0x8e($s1)
/* CDA430 80243150 2442FFFF */  addiu     $v0, $v0, -1
/* CDA434 80243154 A622008E */  sh        $v0, 0x8e($s1)
/* CDA438 80243158 00021400 */  sll       $v0, $v0, 0x10
/* CDA43C 8024315C 1C400021 */  bgtz      $v0, .L802431E4
/* CDA440 80243160 3C03004A */   lui      $v1, 0x4a
/* CDA444 80243164 3C04FFFB */  lui       $a0, 0xfffb
/* CDA448 80243168 3484FFFF */  ori       $a0, $a0, 0xffff
/* CDA44C 8024316C 8E220000 */  lw        $v0, ($s1)
/* CDA450 80243170 34630001 */  ori       $v1, $v1, 1
/* CDA454 80243174 AE230028 */  sw        $v1, 0x28($s1)
/* CDA458 80243178 00441024 */  and       $v0, $v0, $a0
/* CDA45C 8024317C AE220000 */  sw        $v0, ($s1)
/* CDA460 80243180 08090C79 */  j         .L802431E4
/* CDA464 80243184 AEA00070 */   sw       $zero, 0x70($s5)
.L80243188:
/* CDA468 80243188 3C01C47A */  lui       $at, 0xc47a
/* CDA46C 8024318C 44810000 */  mtc1      $at, $f0
/* CDA470 80243190 8E230000 */  lw        $v1, ($s1)
/* CDA474 80243194 A622008E */  sh        $v0, 0x8e($s1)
/* CDA478 80243198 2402FDFF */  addiu     $v0, $zero, -0x201
/* CDA47C 8024319C AE200038 */  sw        $zero, 0x38($s1)
/* CDA480 802431A0 AE200040 */  sw        $zero, 0x40($s1)
/* CDA484 802431A4 3463000A */  ori       $v1, $v1, 0xa
/* CDA488 802431A8 00621824 */  and       $v1, $v1, $v0
/* CDA48C 802431AC E620003C */  swc1      $f0, 0x3c($s1)
/* CDA490 802431B0 AE230000 */  sw        $v1, ($s1)
/* CDA494 802431B4 AEA40070 */  sw        $a0, 0x70($s5)
.L802431B8:
/* CDA498 802431B8 9622008E */  lhu       $v0, 0x8e($s1)
/* CDA49C 802431BC 2442FFFF */  addiu     $v0, $v0, -1
/* CDA4A0 802431C0 A622008E */  sh        $v0, 0x8e($s1)
/* CDA4A4 802431C4 00021400 */  sll       $v0, $v0, 0x10
/* CDA4A8 802431C8 1C400006 */  bgtz      $v0, .L802431E4
/* CDA4AC 802431CC 24020064 */   addiu    $v0, $zero, 0x64
/* CDA4B0 802431D0 AE400094 */  sw        $zero, 0x94($s2)
/* CDA4B4 802431D4 08090C79 */  j         .L802431E4
/* CDA4B8 802431D8 AEA20070 */   sw       $v0, 0x70($s5)
.L802431DC:
/* CDA4BC 802431DC 0C0129CF */  jal       func_8004A73C
/* CDA4C0 802431E0 02A0202D */   daddu    $a0, $s5, $zero
.L802431E4:
/* CDA4C4 802431E4 8FBF0080 */  lw        $ra, 0x80($sp)
/* CDA4C8 802431E8 8FB5007C */  lw        $s5, 0x7c($sp)
/* CDA4CC 802431EC 8FB40078 */  lw        $s4, 0x78($sp)
/* CDA4D0 802431F0 8FB30074 */  lw        $s3, 0x74($sp)
/* CDA4D4 802431F4 8FB20070 */  lw        $s2, 0x70($sp)
/* CDA4D8 802431F8 8FB1006C */  lw        $s1, 0x6c($sp)
/* CDA4DC 802431FC 8FB00068 */  lw        $s0, 0x68($sp)
/* CDA4E0 80243200 D7B60090 */  ldc1      $f22, 0x90($sp)
/* CDA4E4 80243204 D7B40088 */  ldc1      $f20, 0x88($sp)
/* CDA4E8 80243208 0000102D */  daddu     $v0, $zero, $zero
/* CDA4EC 8024320C 03E00008 */  jr        $ra
/* CDA4F0 80243210 27BD0098 */   addiu    $sp, $sp, 0x98
/* CDA4F4 80243214 00000000 */  nop       
/* CDA4F8 80243218 00000000 */  nop       
/* CDA4FC 8024321C 00000000 */  nop       

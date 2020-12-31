.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A6C_CC627C
/* CC627C 80242A6C 27BDFF68 */  addiu     $sp, $sp, -0x98
/* CC6280 80242A70 AFB5007C */  sw        $s5, 0x7c($sp)
/* CC6284 80242A74 0080A82D */  daddu     $s5, $a0, $zero
/* CC6288 80242A78 AFBF0080 */  sw        $ra, 0x80($sp)
/* CC628C 80242A7C AFB40078 */  sw        $s4, 0x78($sp)
/* CC6290 80242A80 AFB30074 */  sw        $s3, 0x74($sp)
/* CC6294 80242A84 AFB20070 */  sw        $s2, 0x70($sp)
/* CC6298 80242A88 AFB1006C */  sw        $s1, 0x6c($sp)
/* CC629C 80242A8C AFB00068 */  sw        $s0, 0x68($sp)
/* CC62A0 80242A90 F7B60090 */  sdc1      $f22, 0x90($sp)
/* CC62A4 80242A94 F7B40088 */  sdc1      $f20, 0x88($sp)
/* CC62A8 80242A98 8EB20148 */  lw        $s2, 0x148($s5)
/* CC62AC 80242A9C 86440008 */  lh        $a0, 8($s2)
/* CC62B0 80242AA0 0C00EABB */  jal       get_npc_unsafe
/* CC62B4 80242AA4 00A0802D */   daddu    $s0, $a1, $zero
/* CC62B8 80242AA8 8EA3000C */  lw        $v1, 0xc($s5)
/* CC62BC 80242AAC 02A0202D */  daddu     $a0, $s5, $zero
/* CC62C0 80242AB0 8C650000 */  lw        $a1, ($v1)
/* CC62C4 80242AB4 0C0B1EAF */  jal       get_variable
/* CC62C8 80242AB8 0040882D */   daddu    $s1, $v0, $zero
/* CC62CC 80242ABC AFA00028 */  sw        $zero, 0x28($sp)
/* CC62D0 80242AC0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC62D4 80242AC4 8C630030 */  lw        $v1, 0x30($v1)
/* CC62D8 80242AC8 AFA3002C */  sw        $v1, 0x2c($sp)
/* CC62DC 80242ACC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC62E0 80242AD0 8C63001C */  lw        $v1, 0x1c($v1)
/* CC62E4 80242AD4 AFA30030 */  sw        $v1, 0x30($sp)
/* CC62E8 80242AD8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC62EC 80242ADC 8C630024 */  lw        $v1, 0x24($v1)
/* CC62F0 80242AE0 AFA30034 */  sw        $v1, 0x34($sp)
/* CC62F4 80242AE4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC62F8 80242AE8 8C630028 */  lw        $v1, 0x28($v1)
/* CC62FC 80242AEC 27B40028 */  addiu     $s4, $sp, 0x28
/* CC6300 80242AF0 AFA30038 */  sw        $v1, 0x38($sp)
/* CC6304 80242AF4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC6308 80242AF8 3C014282 */  lui       $at, 0x4282
/* CC630C 80242AFC 44810000 */  mtc1      $at, $f0
/* CC6310 80242B00 8C63002C */  lw        $v1, 0x2c($v1)
/* CC6314 80242B04 0040982D */  daddu     $s3, $v0, $zero
/* CC6318 80242B08 E7A00040 */  swc1      $f0, 0x40($sp)
/* CC631C 80242B0C A7A00044 */  sh        $zero, 0x44($sp)
/* CC6320 80242B10 12000007 */  beqz      $s0, .L80242B30
/* CC6324 80242B14 AFA3003C */   sw       $v1, 0x3c($sp)
/* CC6328 80242B18 8E4200B0 */  lw        $v0, 0xb0($s2)
/* CC632C 80242B1C 862300A8 */  lh        $v1, 0xa8($s1)
/* CC6330 80242B20 34420008 */  ori       $v0, $v0, 8
/* CC6334 80242B24 AE430084 */  sw        $v1, 0x84($s2)
/* CC6338 80242B28 08090AD0 */  j         .L80242B40
/* CC633C 80242B2C AE4200B0 */   sw       $v0, 0xb0($s2)
.L80242B30:
/* CC6340 80242B30 8E430094 */  lw        $v1, 0x94($s2)
/* CC6344 80242B34 24020064 */  addiu     $v0, $zero, 0x64
/* CC6348 80242B38 1462001C */  bne       $v1, $v0, .L80242BAC
/* CC634C 80242B3C 00000000 */   nop
.L80242B40:
/* CC6350 80242B40 24020064 */  addiu     $v0, $zero, 0x64
/* CC6354 80242B44 2404F7FF */  addiu     $a0, $zero, -0x801
/* CC6358 80242B48 AEA20070 */  sw        $v0, 0x70($s5)
/* CC635C 80242B4C A620008E */  sh        $zero, 0x8e($s1)
/* CC6360 80242B50 8E4300CC */  lw        $v1, 0xcc($s2)
/* CC6364 80242B54 8E220000 */  lw        $v0, ($s1)
/* CC6368 80242B58 3C01C47A */  lui       $at, 0xc47a
/* CC636C 80242B5C 44810000 */  mtc1      $at, $f0
/* CC6370 80242B60 8C630000 */  lw        $v1, ($v1)
/* CC6374 80242B64 00441024 */  and       $v0, $v0, $a0
/* CC6378 80242B68 AE220000 */  sw        $v0, ($s1)
/* CC637C 80242B6C AE230028 */  sw        $v1, 0x28($s1)
/* CC6380 80242B70 8E420000 */  lw        $v0, ($s2)
/* CC6384 80242B74 3C030020 */  lui       $v1, 0x20
/* CC6388 80242B78 00431025 */  or        $v0, $v0, $v1
/* CC638C 80242B7C AE420000 */  sw        $v0, ($s2)
/* CC6390 80242B80 8E220000 */  lw        $v0, ($s1)
/* CC6394 80242B84 2403FDFF */  addiu     $v1, $zero, -0x201
/* CC6398 80242B88 00431024 */  and       $v0, $v0, $v1
/* CC639C 80242B8C 34420008 */  ori       $v0, $v0, 8
/* CC63A0 80242B90 AE220000 */  sw        $v0, ($s1)
/* CC63A4 80242B94 2402FFFF */  addiu     $v0, $zero, -1
/* CC63A8 80242B98 AE400094 */  sw        $zero, 0x94($s2)
/* CC63AC 80242B9C AE420098 */  sw        $v0, 0x98($s2)
/* CC63B0 80242BA0 AE200038 */  sw        $zero, 0x38($s1)
/* CC63B4 80242BA4 E620003C */  swc1      $f0, 0x3c($s1)
/* CC63B8 80242BA8 AE200040 */  sw        $zero, 0x40($s1)
.L80242BAC:
/* CC63BC 80242BAC 8E4200B0 */  lw        $v0, 0xb0($s2)
/* CC63C0 80242BB0 30420004 */  andi      $v0, $v0, 4
/* CC63C4 80242BB4 10400030 */  beqz      $v0, .L80242C78
/* CC63C8 80242BB8 2403FFFB */   addiu    $v1, $zero, -5
/* CC63CC 80242BBC A620008E */  sh        $zero, 0x8e($s1)
/* CC63D0 80242BC0 96420086 */  lhu       $v0, 0x86($s2)
/* CC63D4 80242BC4 A62200A8 */  sh        $v0, 0xa8($s1)
/* CC63D8 80242BC8 8E4200B0 */  lw        $v0, 0xb0($s2)
/* CC63DC 80242BCC 00431024 */  and       $v0, $v0, $v1
/* CC63E0 80242BD0 AE4200B0 */  sw        $v0, 0xb0($s2)
/* CC63E4 80242BD4 8E220000 */  lw        $v0, ($s1)
/* CC63E8 80242BD8 30420800 */  andi      $v0, $v0, 0x800
/* CC63EC 80242BDC 1040000A */  beqz      $v0, .L80242C08
/* CC63F0 80242BE0 3C02004A */   lui      $v0, 0x4a
/* CC63F4 80242BE4 3C013F80 */  lui       $at, 0x3f80
/* CC63F8 80242BE8 44810000 */  mtc1      $at, $f0
/* CC63FC 80242BEC 34420018 */  ori       $v0, $v0, 0x18
/* CC6400 80242BF0 AE220028 */  sw        $v0, 0x28($s1)
/* CC6404 80242BF4 24020066 */  addiu     $v0, $zero, 0x66
/* CC6408 80242BF8 AE200018 */  sw        $zero, 0x18($s1)
/* CC640C 80242BFC AE20001C */  sw        $zero, 0x1c($s1)
/* CC6410 80242C00 08090B1D */  j         .L80242C74
/* CC6414 80242C04 E6200014 */   swc1     $f0, 0x14($s1)
.L80242C08:
/* CC6418 80242C08 24040002 */  addiu     $a0, $zero, 2
/* CC641C 80242C0C 0220282D */  daddu     $a1, $s1, $zero
/* CC6420 80242C10 0000302D */  daddu     $a2, $zero, $zero
/* CC6424 80242C14 862300A8 */  lh        $v1, 0xa8($s1)
/* CC6428 80242C18 3C013F80 */  lui       $at, 0x3f80
/* CC642C 80242C1C 44810000 */  mtc1      $at, $f0
/* CC6430 80242C20 3C014000 */  lui       $at, 0x4000
/* CC6434 80242C24 44811000 */  mtc1      $at, $f2
/* CC6438 80242C28 3C01C1A0 */  lui       $at, 0xc1a0
/* CC643C 80242C2C 44812000 */  mtc1      $at, $f4
/* CC6440 80242C30 24020028 */  addiu     $v0, $zero, 0x28
/* CC6444 80242C34 AFA2001C */  sw        $v0, 0x1c($sp)
/* CC6448 80242C38 44834000 */  mtc1      $v1, $f8
/* CC644C 80242C3C 00000000 */  nop
/* CC6450 80242C40 46804220 */  cvt.s.w   $f8, $f8
/* CC6454 80242C44 44074000 */  mfc1      $a3, $f8
/* CC6458 80242C48 27A20048 */  addiu     $v0, $sp, 0x48
/* CC645C 80242C4C AFA20020 */  sw        $v0, 0x20($sp)
/* CC6460 80242C50 E7A00010 */  swc1      $f0, 0x10($sp)
/* CC6464 80242C54 E7A20014 */  swc1      $f2, 0x14($sp)
/* CC6468 80242C58 0C01BFA4 */  jal       fx_emote
/* CC646C 80242C5C E7A40018 */   swc1     $f4, 0x18($sp)
/* CC6470 80242C60 8E4200CC */  lw        $v0, 0xcc($s2)
/* CC6474 80242C64 8C420000 */  lw        $v0, ($v0)
/* CC6478 80242C68 AE220028 */  sw        $v0, 0x28($s1)
/* CC647C 80242C6C 240200C8 */  addiu     $v0, $zero, 0xc8
/* CC6480 80242C70 AEA00074 */  sw        $zero, 0x74($s5)
.L80242C74:
/* CC6484 80242C74 AEA20070 */  sw        $v0, 0x70($s5)
.L80242C78:
/* CC6488 80242C78 27A2004C */  addiu     $v0, $sp, 0x4c
/* CC648C 80242C7C AFA20010 */  sw        $v0, 0x10($sp)
/* CC6490 80242C80 27A20050 */  addiu     $v0, $sp, 0x50
/* CC6494 80242C84 AFA20014 */  sw        $v0, 0x14($sp)
/* CC6498 80242C88 27A20054 */  addiu     $v0, $sp, 0x54
/* CC649C 80242C8C AFA20018 */  sw        $v0, 0x18($sp)
/* CC64A0 80242C90 8E250038 */  lw        $a1, 0x38($s1)
/* CC64A4 80242C94 8E26003C */  lw        $a2, 0x3c($s1)
/* CC64A8 80242C98 8E270040 */  lw        $a3, 0x40($s1)
/* CC64AC 80242C9C 0C00B94E */  jal       get_screen_coords
/* CC64B0 80242CA0 0000202D */   daddu    $a0, $zero, $zero
/* CC64B4 80242CA4 8EA20070 */  lw        $v0, 0x70($s5)
/* CC64B8 80242CA8 28420064 */  slti      $v0, $v0, 0x64
/* CC64BC 80242CAC 10400007 */  beqz      $v0, .L80242CCC
/* CC64C0 80242CB0 00000000 */   nop
/* CC64C4 80242CB4 8FA2004C */  lw        $v0, 0x4c($sp)
/* CC64C8 80242CB8 24420032 */  addiu     $v0, $v0, 0x32
/* CC64CC 80242CBC 2C4201A5 */  sltiu     $v0, $v0, 0x1a5
/* CC64D0 80242CC0 14400002 */  bnez      $v0, .L80242CCC
/* CC64D4 80242CC4 2402006E */   addiu    $v0, $zero, 0x6e
/* CC64D8 80242CC8 AEA20070 */  sw        $v0, 0x70($s5)
.L80242CCC:
/* CC64DC 80242CCC 8EA30070 */  lw        $v1, 0x70($s5)
/* CC64E0 80242CD0 2402000F */  addiu     $v0, $zero, 0xf
/* CC64E4 80242CD4 1062006B */  beq       $v1, $v0, .L80242E84
/* CC64E8 80242CD8 28620010 */   slti     $v0, $v1, 0x10
/* CC64EC 80242CDC 10400016 */  beqz      $v0, .L80242D38
/* CC64F0 80242CE0 24020003 */   addiu    $v0, $zero, 3
/* CC64F4 80242CE4 10620051 */  beq       $v1, $v0, .L80242E2C
/* CC64F8 80242CE8 28620004 */   slti     $v0, $v1, 4
/* CC64FC 80242CEC 10400009 */  beqz      $v0, .L80242D14
/* CC6500 80242CF0 24020001 */   addiu    $v0, $zero, 1
/* CC6504 80242CF4 10620044 */  beq       $v1, $v0, .L80242E08
/* CC6508 80242CF8 28620002 */   slti     $v0, $v1, 2
/* CC650C 80242CFC 50400048 */  beql      $v0, $zero, .L80242E20
/* CC6510 80242D00 02A0202D */   daddu    $a0, $s5, $zero
/* CC6514 80242D04 50600027 */  beql      $v1, $zero, .L80242DA4
/* CC6518 80242D08 02A0202D */   daddu    $a0, $s5, $zero
/* CC651C 80242D0C 08090CCE */  j         .L80243338
/* CC6520 80242D10 00000000 */   nop
.L80242D14:
/* CC6524 80242D14 2402000D */  addiu     $v0, $zero, 0xd
/* CC6528 80242D18 1062004D */  beq       $v1, $v0, .L80242E50
/* CC652C 80242D1C 2862000E */   slti     $v0, $v1, 0xe
/* CC6530 80242D20 10400052 */  beqz      $v0, .L80242E6C
/* CC6534 80242D24 2402000C */   addiu    $v0, $zero, 0xc
/* CC6538 80242D28 10620046 */  beq       $v1, $v0, .L80242E44
/* CC653C 80242D2C 02A0202D */   daddu    $a0, $s5, $zero
/* CC6540 80242D30 08090CCE */  j         .L80243338
/* CC6544 80242D34 00000000 */   nop
.L80242D38:
/* CC6548 80242D38 24020067 */  addiu     $v0, $zero, 0x67
/* CC654C 80242D3C 10620158 */  beq       $v1, $v0, .L802432A0
/* CC6550 80242D40 28620068 */   slti     $v0, $v1, 0x68
/* CC6554 80242D44 10400009 */  beqz      $v0, .L80242D6C
/* CC6558 80242D48 24020065 */   addiu    $v0, $zero, 0x65
/* CC655C 80242D4C 1062008F */  beq       $v1, $v0, .L80242F8C
/* CC6560 80242D50 28620066 */   slti     $v0, $v1, 0x66
/* CC6564 80242D54 104000A9 */  beqz      $v0, .L80242FFC
/* CC6568 80242D58 24020064 */   addiu    $v0, $zero, 0x64
/* CC656C 80242D5C 1062004F */  beq       $v1, $v0, .L80242E9C
/* CC6570 80242D60 24020002 */   addiu    $v0, $zero, 2
/* CC6574 80242D64 08090CCE */  j         .L80243338
/* CC6578 80242D68 00000000 */   nop
.L80242D6C:
/* CC657C 80242D6C 2404006F */  addiu     $a0, $zero, 0x6f
/* CC6580 80242D70 10640166 */  beq       $v1, $a0, .L8024330C
/* CC6584 80242D74 28620070 */   slti     $v0, $v1, 0x70
/* CC6588 80242D78 10400005 */  beqz      $v0, .L80242D90
/* CC658C 80242D7C 2402006E */   addiu    $v0, $zero, 0x6e
/* CC6590 80242D80 10620156 */  beq       $v1, $v0, .L802432DC
/* CC6594 80242D84 2402001E */   addiu    $v0, $zero, 0x1e
/* CC6598 80242D88 08090CCE */  j         .L80243338
/* CC659C 80242D8C 00000000 */   nop
.L80242D90:
/* CC65A0 80242D90 240200C8 */  addiu     $v0, $zero, 0xc8
/* CC65A4 80242D94 10620166 */  beq       $v1, $v0, .L80243330
/* CC65A8 80242D98 00000000 */   nop
/* CC65AC 80242D9C 08090CCE */  j         .L80243338
/* CC65B0 80242DA0 00000000 */   nop
.L80242DA4:
/* CC65B4 80242DA4 0260282D */  daddu     $a1, $s3, $zero
/* CC65B8 80242DA8 0C012568 */  jal       func_800495A0
/* CC65BC 80242DAC 0280302D */   daddu    $a2, $s4, $zero
/* CC65C0 80242DB0 96420086 */  lhu       $v0, 0x86($s2)
/* CC65C4 80242DB4 A62200A8 */  sh        $v0, 0xa8($s1)
/* CC65C8 80242DB8 8E4200A0 */  lw        $v0, 0xa0($s2)
/* CC65CC 80242DBC 10400013 */  beqz      $v0, .L80242E0C
/* CC65D0 80242DC0 02A0202D */   daddu    $a0, $s5, $zero
/* CC65D4 80242DC4 C620003C */  lwc1      $f0, 0x3c($s1)
/* CC65D8 80242DC8 44801000 */  mtc1      $zero, $f2
/* CC65DC 80242DCC 44801800 */  mtc1      $zero, $f3
/* CC65E0 80242DD0 46000021 */  cvt.d.s   $f0, $f0
/* CC65E4 80242DD4 4622003E */  c.le.d    $f0, $f2
/* CC65E8 80242DD8 00000000 */  nop
/* CC65EC 80242DDC 45000005 */  bc1f      .L80242DF4
/* CC65F0 80242DE0 2403FDFF */   addiu    $v1, $zero, -0x201
/* CC65F4 80242DE4 8E220000 */  lw        $v0, ($s1)
/* CC65F8 80242DE8 00431024 */  and       $v0, $v0, $v1
/* CC65FC 80242DEC 08090B81 */  j         .L80242E04
/* CC6600 80242DF0 34420008 */   ori      $v0, $v0, 8
.L80242DF4:
/* CC6604 80242DF4 8E220000 */  lw        $v0, ($s1)
/* CC6608 80242DF8 2403FFF7 */  addiu     $v1, $zero, -9
/* CC660C 80242DFC 34420200 */  ori       $v0, $v0, 0x200
/* CC6610 80242E00 00431024 */  and       $v0, $v0, $v1
.L80242E04:
/* CC6614 80242E04 AE220000 */  sw        $v0, ($s1)
.L80242E08:
/* CC6618 80242E08 02A0202D */  daddu     $a0, $s5, $zero
.L80242E0C:
/* CC661C 80242E0C 0260282D */  daddu     $a1, $s3, $zero
/* CC6620 80242E10 0C0125AE */  jal       func_800496B8
/* CC6624 80242E14 0280302D */   daddu    $a2, $s4, $zero
/* CC6628 80242E18 08090CCE */  j         .L80243338
/* CC662C 80242E1C 00000000 */   nop
.L80242E20:
/* CC6630 80242E20 0260282D */  daddu     $a1, $s3, $zero
/* CC6634 80242E24 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* CC6638 80242E28 0280302D */   daddu    $a2, $s4, $zero
.L80242E2C:
/* CC663C 80242E2C 02A0202D */  daddu     $a0, $s5, $zero
/* CC6640 80242E30 0260282D */  daddu     $a1, $s3, $zero
/* CC6644 80242E34 0C012701 */  jal       func_80049C04
/* CC6648 80242E38 0280302D */   daddu    $a2, $s4, $zero
/* CC664C 80242E3C 08090CCE */  j         .L80243338
/* CC6650 80242E40 00000000 */   nop
.L80242E44:
/* CC6654 80242E44 0260282D */  daddu     $a1, $s3, $zero
/* CC6658 80242E48 0C0908A6 */  jal       flo_13_set_script_owner_npc_anim
/* CC665C 80242E4C 0280302D */   daddu    $a2, $s4, $zero
.L80242E50:
/* CC6660 80242E50 02A0202D */  daddu     $a0, $s5, $zero
/* CC6664 80242E54 0260282D */  daddu     $a1, $s3, $zero
/* CC6668 80242E58 0C0908C5 */  jal       func_80242314_CC5B24
/* CC666C 80242E5C 0280302D */   daddu    $a2, $s4, $zero
/* CC6670 80242E60 96420086 */  lhu       $v0, 0x86($s2)
/* CC6674 80242E64 08090CCE */  j         .L80243338
/* CC6678 80242E68 A62200A8 */   sh       $v0, 0xa8($s1)
.L80242E6C:
/* CC667C 80242E6C 02A0202D */  daddu     $a0, $s5, $zero
/* CC6680 80242E70 0260282D */  daddu     $a1, $s3, $zero
/* CC6684 80242E74 0C090912 */  jal       func_80242448_CC5C58
/* CC6688 80242E78 0280302D */   daddu    $a2, $s4, $zero
/* CC668C 80242E7C 08090CCE */  j         .L80243338
/* CC6690 80242E80 00000000 */   nop
.L80242E84:
/* CC6694 80242E84 02A0202D */  daddu     $a0, $s5, $zero
/* CC6698 80242E88 0260282D */  daddu     $a1, $s3, $zero
/* CC669C 80242E8C 0C09096B */  jal       flo_13_set_script_owner_npc_col_height
/* CC66A0 80242E90 0280302D */   daddu    $a2, $s4, $zero
/* CC66A4 80242E94 08090CCE */  j         .L80243338
/* CC66A8 80242E98 00000000 */   nop
.L80242E9C:
/* CC66AC 80242E9C 8E430094 */  lw        $v1, 0x94($s2)
/* CC66B0 80242EA0 14620125 */  bne       $v1, $v0, .L80243338
/* CC66B4 80242EA4 00000000 */   nop
/* CC66B8 80242EA8 0C00FB3A */  jal       get_enemy
/* CC66BC 80242EAC 8E440098 */   lw       $a0, 0x98($s2)
/* CC66C0 80242EB0 0C00EABB */  jal       get_npc_unsafe
/* CC66C4 80242EB4 84440008 */   lh       $a0, 8($v0)
/* CC66C8 80242EB8 C440000C */  lwc1      $f0, 0xc($v0)
/* CC66CC 80242EBC 3C018024 */  lui       $at, %hi(D_80247AE8)
/* CC66D0 80242EC0 D4227AE8 */  ldc1      $f2, %lo(D_80247AE8)($at)
/* CC66D4 80242EC4 46000021 */  cvt.d.s   $f0, $f0
/* CC66D8 80242EC8 4622003C */  c.lt.d    $f0, $f2
/* CC66DC 80242ECC 00000000 */  nop
/* CC66E0 80242ED0 45000008 */  bc1f      .L80242EF4
/* CC66E4 80242ED4 00000000 */   nop
/* CC66E8 80242ED8 C4400038 */  lwc1      $f0, 0x38($v0)
/* CC66EC 80242EDC 3C014028 */  lui       $at, 0x4028
/* CC66F0 80242EE0 44811800 */  mtc1      $at, $f3
/* CC66F4 80242EE4 44801000 */  mtc1      $zero, $f2
/* CC66F8 80242EE8 46000021 */  cvt.d.s   $f0, $f0
/* CC66FC 80242EEC 08090BC3 */  j         .L80242F0C
/* CC6700 80242EF0 46220000 */   add.d    $f0, $f0, $f2
.L80242EF4:
/* CC6704 80242EF4 C4400038 */  lwc1      $f0, 0x38($v0)
/* CC6708 80242EF8 3C014028 */  lui       $at, 0x4028
/* CC670C 80242EFC 44811800 */  mtc1      $at, $f3
/* CC6710 80242F00 44801000 */  mtc1      $zero, $f2
/* CC6714 80242F04 46000021 */  cvt.d.s   $f0, $f0
/* CC6718 80242F08 46220001 */  sub.d     $f0, $f0, $f2
.L80242F0C:
/* CC671C 80242F0C 46200020 */  cvt.s.d   $f0, $f0
/* CC6720 80242F10 E6200038 */  swc1      $f0, 0x38($s1)
/* CC6724 80242F14 3C04004A */  lui       $a0, 0x4a
/* CC6728 80242F18 C440003C */  lwc1      $f0, 0x3c($v0)
/* CC672C 80242F1C 3C014039 */  lui       $at, 0x4039
/* CC6730 80242F20 44811800 */  mtc1      $at, $f3
/* CC6734 80242F24 44801000 */  mtc1      $zero, $f2
/* CC6738 80242F28 46000021 */  cvt.d.s   $f0, $f0
/* CC673C 80242F2C 46220000 */  add.d     $f0, $f0, $f2
/* CC6740 80242F30 34840018 */  ori       $a0, $a0, 0x18
/* CC6744 80242F34 3C013FF0 */  lui       $at, 0x3ff0
/* CC6748 80242F38 44811800 */  mtc1      $at, $f3
/* CC674C 80242F3C 44801000 */  mtc1      $zero, $f2
/* CC6750 80242F40 46200020 */  cvt.s.d   $f0, $f0
/* CC6754 80242F44 E620003C */  swc1      $f0, 0x3c($s1)
/* CC6758 80242F48 C4400040 */  lwc1      $f0, 0x40($v0)
/* CC675C 80242F4C 8E220000 */  lw        $v0, ($s1)
/* CC6760 80242F50 2403FFFD */  addiu     $v1, $zero, -3
/* CC6764 80242F54 AE200048 */  sw        $zero, 0x48($s1)
/* CC6768 80242F58 AE200034 */  sw        $zero, 0x34($s1)
/* CC676C 80242F5C AE240028 */  sw        $a0, 0x28($s1)
/* CC6770 80242F60 34420008 */  ori       $v0, $v0, 8
/* CC6774 80242F64 00431024 */  and       $v0, $v0, $v1
/* CC6778 80242F68 2403FDFF */  addiu     $v1, $zero, -0x201
/* CC677C 80242F6C 00431024 */  and       $v0, $v0, $v1
/* CC6780 80242F70 46000021 */  cvt.d.s   $f0, $f0
/* CC6784 80242F74 46220000 */  add.d     $f0, $f0, $f2
/* CC6788 80242F78 AE220000 */  sw        $v0, ($s1)
/* CC678C 80242F7C 24020065 */  addiu     $v0, $zero, 0x65
/* CC6790 80242F80 46200020 */  cvt.s.d   $f0, $f0
/* CC6794 80242F84 E6200040 */  swc1      $f0, 0x40($s1)
/* CC6798 80242F88 AEA20070 */  sw        $v0, 0x70($s5)
.L80242F8C:
/* CC679C 80242F8C 8E430094 */  lw        $v1, 0x94($s2)
/* CC67A0 80242F90 24020003 */  addiu     $v0, $zero, 3
/* CC67A4 80242F94 146200E8 */  bne       $v1, $v0, .L80243338
/* CC67A8 80242F98 24020004 */   addiu    $v0, $zero, 4
/* CC67AC 80242F9C AE420094 */  sw        $v0, 0x94($s2)
/* CC67B0 80242FA0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CC67B4 80242FA4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CC67B8 80242FA8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CC67BC 80242FAC C62E0040 */  lwc1      $f14, 0x40($s1)
/* CC67C0 80242FB0 8C460028 */  lw        $a2, 0x28($v0)
/* CC67C4 80242FB4 0C00A720 */  jal       atan2
/* CC67C8 80242FB8 8C470030 */   lw       $a3, 0x30($v0)
/* CC67CC 80242FBC 3C014020 */  lui       $at, 0x4020
/* CC67D0 80242FC0 44811000 */  mtc1      $at, $f2
/* CC67D4 80242FC4 3C014100 */  lui       $at, 0x4100
/* CC67D8 80242FC8 44812000 */  mtc1      $at, $f4
/* CC67DC 80242FCC 3C013F4C */  lui       $at, 0x3f4c
/* CC67E0 80242FD0 3421CCCD */  ori       $at, $at, 0xcccd
/* CC67E4 80242FD4 44813000 */  mtc1      $at, $f6
/* CC67E8 80242FD8 8E220000 */  lw        $v0, ($s1)
/* CC67EC 80242FDC E620000C */  swc1      $f0, 0xc($s1)
/* CC67F0 80242FE0 34420800 */  ori       $v0, $v0, 0x800
/* CC67F4 80242FE4 AE220000 */  sw        $v0, ($s1)
/* CC67F8 80242FE8 24020066 */  addiu     $v0, $zero, 0x66
/* CC67FC 80242FEC E6220018 */  swc1      $f2, 0x18($s1)
/* CC6800 80242FF0 E624001C */  swc1      $f4, 0x1c($s1)
/* CC6804 80242FF4 E6260014 */  swc1      $f6, 0x14($s1)
/* CC6808 80242FF8 AEA20070 */  sw        $v0, 0x70($s5)
.L80242FFC:
/* CC680C 80242FFC C6200018 */  lwc1      $f0, 0x18($s1)
/* CC6810 80243000 44801000 */  mtc1      $zero, $f2
/* CC6814 80243004 44801800 */  mtc1      $zero, $f3
/* CC6818 80243008 46000021 */  cvt.d.s   $f0, $f0
/* CC681C 8024300C 4620103C */  c.lt.d    $f2, $f0
/* CC6820 80243010 00000000 */  nop
/* CC6824 80243014 4500001F */  bc1f      .L80243094
/* CC6828 80243018 27A50058 */   addiu    $a1, $sp, 0x58
/* CC682C 8024301C C6200038 */  lwc1      $f0, 0x38($s1)
/* CC6830 80243020 C622003C */  lwc1      $f2, 0x3c($s1)
/* CC6834 80243024 C6240040 */  lwc1      $f4, 0x40($s1)
/* CC6838 80243028 C6260018 */  lwc1      $f6, 0x18($s1)
/* CC683C 8024302C E7A00058 */  swc1      $f0, 0x58($sp)
/* CC6840 80243030 E7A2005C */  swc1      $f2, 0x5c($sp)
/* CC6844 80243034 E7A40060 */  swc1      $f4, 0x60($sp)
/* CC6848 80243038 E7A60010 */  swc1      $f6, 0x10($sp)
/* CC684C 8024303C C620000C */  lwc1      $f0, 0xc($s1)
/* CC6850 80243040 E7A00014 */  swc1      $f0, 0x14($sp)
/* CC6854 80243044 862200A8 */  lh        $v0, 0xa8($s1)
/* CC6858 80243048 44820000 */  mtc1      $v0, $f0
/* CC685C 8024304C 00000000 */  nop
/* CC6860 80243050 46800020 */  cvt.s.w   $f0, $f0
/* CC6864 80243054 E7A00018 */  swc1      $f0, 0x18($sp)
/* CC6868 80243058 862200A6 */  lh        $v0, 0xa6($s1)
/* CC686C 8024305C 27A6005C */  addiu     $a2, $sp, 0x5c
/* CC6870 80243060 44820000 */  mtc1      $v0, $f0
/* CC6874 80243064 00000000 */  nop
/* CC6878 80243068 46800020 */  cvt.s.w   $f0, $f0
/* CC687C 8024306C E7A0001C */  swc1      $f0, 0x1c($sp)
/* CC6880 80243070 8E240080 */  lw        $a0, 0x80($s1)
/* CC6884 80243074 0C037711 */  jal       func_800DDC44
/* CC6888 80243078 27A70060 */   addiu    $a3, $sp, 0x60
/* CC688C 8024307C 54400005 */  bnel      $v0, $zero, .L80243094
/* CC6890 80243080 AE200018 */   sw       $zero, 0x18($s1)
/* CC6894 80243084 8E250018 */  lw        $a1, 0x18($s1)
/* CC6898 80243088 8E26000C */  lw        $a2, 0xc($s1)
/* CC689C 8024308C 0C00EA95 */  jal       npc_move_heading
/* CC68A0 80243090 0220202D */   daddu    $a0, $s1, $zero
.L80243094:
/* CC68A4 80243094 C620001C */  lwc1      $f0, 0x1c($s1)
/* CC68A8 80243098 4480B000 */  mtc1      $zero, $f22
/* CC68AC 8024309C 4480B800 */  mtc1      $zero, $f23
/* CC68B0 802430A0 46000021 */  cvt.d.s   $f0, $f0
/* CC68B4 802430A4 4636003C */  c.lt.d    $f0, $f22
/* CC68B8 802430A8 00000000 */  nop
/* CC68BC 802430AC 45000074 */  bc1f      .L80243280
/* CC68C0 802430B0 27A50058 */   addiu    $a1, $sp, 0x58
/* CC68C4 802430B4 27A6005C */  addiu     $a2, $sp, 0x5c
/* CC68C8 802430B8 27A20064 */  addiu     $v0, $sp, 0x64
/* CC68CC 802430BC C622003C */  lwc1      $f2, 0x3c($s1)
/* CC68D0 802430C0 C6260038 */  lwc1      $f6, 0x38($s1)
/* CC68D4 802430C4 3C01402A */  lui       $at, 0x402a
/* CC68D8 802430C8 4481A800 */  mtc1      $at, $f21
/* CC68DC 802430CC 4480A000 */  mtc1      $zero, $f20
/* CC68E0 802430D0 460010A1 */  cvt.d.s   $f2, $f2
/* CC68E4 802430D4 46341080 */  add.d     $f2, $f2, $f20
/* CC68E8 802430D8 C620001C */  lwc1      $f0, 0x1c($s1)
/* CC68EC 802430DC C6240040 */  lwc1      $f4, 0x40($s1)
/* CC68F0 802430E0 46000005 */  abs.s     $f0, $f0
/* CC68F4 802430E4 E7A40060 */  swc1      $f4, 0x60($sp)
/* CC68F8 802430E8 3C014030 */  lui       $at, 0x4030
/* CC68FC 802430EC 44812800 */  mtc1      $at, $f5
/* CC6900 802430F0 44802000 */  mtc1      $zero, $f4
/* CC6904 802430F4 46000021 */  cvt.d.s   $f0, $f0
/* CC6908 802430F8 E7A60058 */  swc1      $f6, 0x58($sp)
/* CC690C 802430FC 46240000 */  add.d     $f0, $f0, $f4
/* CC6910 80243100 462010A0 */  cvt.s.d   $f2, $f2
/* CC6914 80243104 E7A2005C */  swc1      $f2, 0x5c($sp)
/* CC6918 80243108 46200020 */  cvt.s.d   $f0, $f0
/* CC691C 8024310C E7A00064 */  swc1      $f0, 0x64($sp)
/* CC6920 80243110 AFA20010 */  sw        $v0, 0x10($sp)
/* CC6924 80243114 8E240080 */  lw        $a0, 0x80($s1)
/* CC6928 80243118 0C0372DF */  jal       func_800DCB7C
/* CC692C 8024311C 27A70060 */   addiu    $a3, $sp, 0x60
/* CC6930 80243120 10400057 */  beqz      $v0, .L80243280
/* CC6934 80243124 00000000 */   nop
/* CC6938 80243128 C620001C */  lwc1      $f0, 0x1c($s1)
/* CC693C 8024312C C7A20064 */  lwc1      $f2, 0x64($sp)
/* CC6940 80243130 46000005 */  abs.s     $f0, $f0
/* CC6944 80243134 46000021 */  cvt.d.s   $f0, $f0
/* CC6948 80243138 46340000 */  add.d     $f0, $f0, $f20
/* CC694C 8024313C 460010A1 */  cvt.d.s   $f2, $f2
/* CC6950 80243140 4620103E */  c.le.d    $f2, $f0
/* CC6954 80243144 00000000 */  nop
/* CC6958 80243148 4500004D */  bc1f      .L80243280
/* CC695C 8024314C 00000000 */   nop
/* CC6960 80243150 C7A0005C */  lwc1      $f0, 0x5c($sp)
/* CC6964 80243154 E620003C */  swc1      $f0, 0x3c($s1)
/* CC6968 80243158 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CC696C 8024315C C6200038 */  lwc1      $f0, 0x38($s1)
/* CC6970 80243160 4600020D */  trunc.w.s $f8, $f0
/* CC6974 80243164 E4480000 */  swc1      $f8, ($v0)
/* CC6978 80243168 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CC697C 8024316C C620003C */  lwc1      $f0, 0x3c($s1)
/* CC6980 80243170 4600020D */  trunc.w.s $f8, $f0
/* CC6984 80243174 E4480004 */  swc1      $f8, 4($v0)
/* CC6988 80243178 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CC698C 8024317C C6200040 */  lwc1      $f0, 0x40($s1)
/* CC6990 80243180 4600020D */  trunc.w.s $f8, $f0
/* CC6994 80243184 E4480008 */  swc1      $f8, 8($v0)
/* CC6998 80243188 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CC699C 8024318C C6200038 */  lwc1      $f0, 0x38($s1)
/* CC69A0 80243190 4600020D */  trunc.w.s $f8, $f0
/* CC69A4 80243194 E448001C */  swc1      $f8, 0x1c($v0)
/* CC69A8 80243198 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CC69AC 8024319C C620003C */  lwc1      $f0, 0x3c($s1)
/* CC69B0 802431A0 4600020D */  trunc.w.s $f8, $f0
/* CC69B4 802431A4 E4480020 */  swc1      $f8, 0x20($v0)
/* CC69B8 802431A8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CC69BC 802431AC C6200040 */  lwc1      $f0, 0x40($s1)
/* CC69C0 802431B0 4600020D */  trunc.w.s $f8, $f0
/* CC69C4 802431B4 E4480024 */  swc1      $f8, 0x24($v0)
/* CC69C8 802431B8 8E4300A0 */  lw        $v1, 0xa0($s2)
/* CC69CC 802431BC 24020005 */  addiu     $v0, $zero, 5
/* CC69D0 802431C0 1060000B */  beqz      $v1, .L802431F0
/* CC69D4 802431C4 AE420094 */   sw       $v0, 0x94($s2)
/* CC69D8 802431C8 C620003C */  lwc1      $f0, 0x3c($s1)
/* CC69DC 802431CC 46000021 */  cvt.d.s   $f0, $f0
/* CC69E0 802431D0 4636003E */  c.le.d    $f0, $f22
/* CC69E4 802431D4 00000000 */  nop
/* CC69E8 802431D8 4501000D */  bc1t      .L80243210
/* CC69EC 802431DC 2403FFF7 */   addiu    $v1, $zero, -9
/* CC69F0 802431E0 8E220000 */  lw        $v0, ($s1)
/* CC69F4 802431E4 34420200 */  ori       $v0, $v0, 0x200
/* CC69F8 802431E8 08090C88 */  j         .L80243220
/* CC69FC 802431EC 00431024 */   and      $v0, $v0, $v1
.L802431F0:
/* CC6A00 802431F0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* CC6A04 802431F4 8C420034 */  lw        $v0, 0x34($v0)
/* CC6A08 802431F8 14400005 */  bnez      $v0, .L80243210
/* CC6A0C 802431FC 2403FFF7 */   addiu    $v1, $zero, -9
/* CC6A10 80243200 8E220000 */  lw        $v0, ($s1)
/* CC6A14 80243204 34420200 */  ori       $v0, $v0, 0x200
/* CC6A18 80243208 08090C88 */  j         .L80243220
/* CC6A1C 8024320C 00431024 */   and      $v0, $v0, $v1
.L80243210:
/* CC6A20 80243210 8E220000 */  lw        $v0, ($s1)
/* CC6A24 80243214 2403FDFF */  addiu     $v1, $zero, -0x201
/* CC6A28 80243218 00431024 */  and       $v0, $v0, $v1
/* CC6A2C 8024321C 34420008 */  ori       $v0, $v0, 8
.L80243220:
/* CC6A30 80243220 AE220000 */  sw        $v0, ($s1)
/* CC6A34 80243224 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CC6A38 80243228 C62E0040 */  lwc1      $f14, 0x40($s1)
/* CC6A3C 8024322C 8E220000 */  lw        $v0, ($s1)
/* CC6A40 80243230 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* CC6A44 80243234 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* CC6A48 80243238 3C030004 */  lui       $v1, 4
/* CC6A4C 8024323C AE20001C */  sw        $zero, 0x1c($s1)
/* CC6A50 80243240 00431025 */  or        $v0, $v0, $v1
/* CC6A54 80243244 2403F7FF */  addiu     $v1, $zero, -0x801
/* CC6A58 80243248 00431024 */  and       $v0, $v0, $v1
/* CC6A5C 8024324C AE220000 */  sw        $v0, ($s1)
/* CC6A60 80243250 8C860028 */  lw        $a2, 0x28($a0)
/* CC6A64 80243254 0C00A720 */  jal       atan2
/* CC6A68 80243258 8C870030 */   lw       $a3, 0x30($a0)
/* CC6A6C 8024325C 3C02004A */  lui       $v0, 0x4a
/* CC6A70 80243260 3442001A */  ori       $v0, $v0, 0x1a
/* CC6A74 80243264 AE220028 */  sw        $v0, 0x28($s1)
/* CC6A78 80243268 24020003 */  addiu     $v0, $zero, 3
/* CC6A7C 8024326C A622008E */  sh        $v0, 0x8e($s1)
/* CC6A80 80243270 24020067 */  addiu     $v0, $zero, 0x67
/* CC6A84 80243274 E620000C */  swc1      $f0, 0xc($s1)
/* CC6A88 80243278 08090CCE */  j         .L80243338
/* CC6A8C 8024327C AEA20070 */   sw       $v0, 0x70($s5)
.L80243280:
/* CC6A90 80243280 C624003C */  lwc1      $f4, 0x3c($s1)
/* CC6A94 80243284 C620001C */  lwc1      $f0, 0x1c($s1)
/* CC6A98 80243288 46002100 */  add.s     $f4, $f4, $f0
/* CC6A9C 8024328C C6220014 */  lwc1      $f2, 0x14($s1)
/* CC6AA0 80243290 46020001 */  sub.s     $f0, $f0, $f2
/* CC6AA4 80243294 E624003C */  swc1      $f4, 0x3c($s1)
/* CC6AA8 80243298 08090CCE */  j         .L80243338
/* CC6AAC 8024329C E620001C */   swc1     $f0, 0x1c($s1)
.L802432A0:
/* CC6AB0 802432A0 9622008E */  lhu       $v0, 0x8e($s1)
/* CC6AB4 802432A4 2442FFFF */  addiu     $v0, $v0, -1
/* CC6AB8 802432A8 A622008E */  sh        $v0, 0x8e($s1)
/* CC6ABC 802432AC 00021400 */  sll       $v0, $v0, 0x10
/* CC6AC0 802432B0 1C400021 */  bgtz      $v0, .L80243338
/* CC6AC4 802432B4 3C03004A */   lui      $v1, 0x4a
/* CC6AC8 802432B8 3C04FFFB */  lui       $a0, 0xfffb
/* CC6ACC 802432BC 3484FFFF */  ori       $a0, $a0, 0xffff
/* CC6AD0 802432C0 8E220000 */  lw        $v0, ($s1)
/* CC6AD4 802432C4 34630001 */  ori       $v1, $v1, 1
/* CC6AD8 802432C8 AE230028 */  sw        $v1, 0x28($s1)
/* CC6ADC 802432CC 00441024 */  and       $v0, $v0, $a0
/* CC6AE0 802432D0 AE220000 */  sw        $v0, ($s1)
/* CC6AE4 802432D4 08090CCE */  j         .L80243338
/* CC6AE8 802432D8 AEA00070 */   sw       $zero, 0x70($s5)
.L802432DC:
/* CC6AEC 802432DC 3C01C47A */  lui       $at, 0xc47a
/* CC6AF0 802432E0 44810000 */  mtc1      $at, $f0
/* CC6AF4 802432E4 8E230000 */  lw        $v1, ($s1)
/* CC6AF8 802432E8 A622008E */  sh        $v0, 0x8e($s1)
/* CC6AFC 802432EC 2402FDFF */  addiu     $v0, $zero, -0x201
/* CC6B00 802432F0 AE200038 */  sw        $zero, 0x38($s1)
/* CC6B04 802432F4 AE200040 */  sw        $zero, 0x40($s1)
/* CC6B08 802432F8 3463000A */  ori       $v1, $v1, 0xa
/* CC6B0C 802432FC 00621824 */  and       $v1, $v1, $v0
/* CC6B10 80243300 E620003C */  swc1      $f0, 0x3c($s1)
/* CC6B14 80243304 AE230000 */  sw        $v1, ($s1)
/* CC6B18 80243308 AEA40070 */  sw        $a0, 0x70($s5)
.L8024330C:
/* CC6B1C 8024330C 9622008E */  lhu       $v0, 0x8e($s1)
/* CC6B20 80243310 2442FFFF */  addiu     $v0, $v0, -1
/* CC6B24 80243314 A622008E */  sh        $v0, 0x8e($s1)
/* CC6B28 80243318 00021400 */  sll       $v0, $v0, 0x10
/* CC6B2C 8024331C 1C400006 */  bgtz      $v0, .L80243338
/* CC6B30 80243320 24020064 */   addiu    $v0, $zero, 0x64
/* CC6B34 80243324 AE400094 */  sw        $zero, 0x94($s2)
/* CC6B38 80243328 08090CCE */  j         .L80243338
/* CC6B3C 8024332C AEA20070 */   sw       $v0, 0x70($s5)
.L80243330:
/* CC6B40 80243330 0C0129CF */  jal       func_8004A73C
/* CC6B44 80243334 02A0202D */   daddu    $a0, $s5, $zero
.L80243338:
/* CC6B48 80243338 8FBF0080 */  lw        $ra, 0x80($sp)
/* CC6B4C 8024333C 8FB5007C */  lw        $s5, 0x7c($sp)
/* CC6B50 80243340 8FB40078 */  lw        $s4, 0x78($sp)
/* CC6B54 80243344 8FB30074 */  lw        $s3, 0x74($sp)
/* CC6B58 80243348 8FB20070 */  lw        $s2, 0x70($sp)
/* CC6B5C 8024334C 8FB1006C */  lw        $s1, 0x6c($sp)
/* CC6B60 80243350 8FB00068 */  lw        $s0, 0x68($sp)
/* CC6B64 80243354 D7B60090 */  ldc1      $f22, 0x90($sp)
/* CC6B68 80243358 D7B40088 */  ldc1      $f20, 0x88($sp)
/* CC6B6C 8024335C 0000102D */  daddu     $v0, $zero, $zero
/* CC6B70 80243360 03E00008 */  jr        $ra
/* CC6B74 80243364 27BD0098 */   addiu    $sp, $sp, 0x98

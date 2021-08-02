.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245468_EF7A78
.double 180.0

.section .text

glabel func_8024299C_EF4FAC
/* EF4FAC 8024299C 27BDFF68 */  addiu     $sp, $sp, -0x98
/* EF4FB0 802429A0 AFB5007C */  sw        $s5, 0x7c($sp)
/* EF4FB4 802429A4 0080A82D */  daddu     $s5, $a0, $zero
/* EF4FB8 802429A8 AFBF0080 */  sw        $ra, 0x80($sp)
/* EF4FBC 802429AC AFB40078 */  sw        $s4, 0x78($sp)
/* EF4FC0 802429B0 AFB30074 */  sw        $s3, 0x74($sp)
/* EF4FC4 802429B4 AFB20070 */  sw        $s2, 0x70($sp)
/* EF4FC8 802429B8 AFB1006C */  sw        $s1, 0x6c($sp)
/* EF4FCC 802429BC AFB00068 */  sw        $s0, 0x68($sp)
/* EF4FD0 802429C0 F7B60090 */  sdc1      $f22, 0x90($sp)
/* EF4FD4 802429C4 F7B40088 */  sdc1      $f20, 0x88($sp)
/* EF4FD8 802429C8 8EB20148 */  lw        $s2, 0x148($s5)
/* EF4FDC 802429CC 86440008 */  lh        $a0, 8($s2)
/* EF4FE0 802429D0 0C00F92F */  jal       dead_get_npc_unsafe
/* EF4FE4 802429D4 00A0802D */   daddu    $s0, $a1, $zero
/* EF4FE8 802429D8 8EA3000C */  lw        $v1, 0xc($s5)
/* EF4FEC 802429DC 02A0202D */  daddu     $a0, $s5, $zero
/* EF4FF0 802429E0 8C650000 */  lw        $a1, ($v1)
/* EF4FF4 802429E4 0C0B53A3 */  jal       dead_get_variable
/* EF4FF8 802429E8 0040882D */   daddu    $s1, $v0, $zero
/* EF4FFC 802429EC AFA00028 */  sw        $zero, 0x28($sp)
/* EF5000 802429F0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF5004 802429F4 8C630030 */  lw        $v1, 0x30($v1)
/* EF5008 802429F8 AFA3002C */  sw        $v1, 0x2c($sp)
/* EF500C 802429FC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF5010 80242A00 8C63001C */  lw        $v1, 0x1c($v1)
/* EF5014 80242A04 AFA30030 */  sw        $v1, 0x30($sp)
/* EF5018 80242A08 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF501C 80242A0C 8C630024 */  lw        $v1, 0x24($v1)
/* EF5020 80242A10 AFA30034 */  sw        $v1, 0x34($sp)
/* EF5024 80242A14 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF5028 80242A18 8C630028 */  lw        $v1, 0x28($v1)
/* EF502C 80242A1C AFA30038 */  sw        $v1, 0x38($sp)
/* EF5030 80242A20 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF5034 80242A24 3C014282 */  lui       $at, 0x4282
/* EF5038 80242A28 44810000 */  mtc1      $at, $f0
/* EF503C 80242A2C 8C63002C */  lw        $v1, 0x2c($v1)
/* EF5040 80242A30 E7A00040 */  swc1      $f0, 0x40($sp)
/* EF5044 80242A34 A7A00044 */  sh        $zero, 0x44($sp)
/* EF5048 80242A38 AFA3003C */  sw        $v1, 0x3c($sp)
/* EF504C 80242A3C C6200038 */  lwc1      $f0, 0x38($s1)
/* EF5050 80242A40 E6400108 */  swc1      $f0, 0x108($s2)
/* EF5054 80242A44 C620003C */  lwc1      $f0, 0x3c($s1)
/* EF5058 80242A48 27B40028 */  addiu     $s4, $sp, 0x28
/* EF505C 80242A4C E640010C */  swc1      $f0, 0x10c($s2)
/* EF5060 80242A50 3C0138D1 */  lui       $at, 0x38d1
/* EF5064 80242A54 3421B717 */  ori       $at, $at, 0xb717
/* EF5068 80242A58 44810000 */  mtc1      $at, $f0
/* EF506C 80242A5C C6220040 */  lwc1      $f2, 0x40($s1)
/* EF5070 80242A60 0040982D */  daddu     $s3, $v0, $zero
/* EF5074 80242A64 E6400114 */  swc1      $f0, 0x114($s2)
/* EF5078 80242A68 E6400118 */  swc1      $f0, 0x118($s2)
/* EF507C 80242A6C 12000007 */  beqz      $s0, .L80242A8C
/* EF5080 80242A70 E6420110 */   swc1     $f2, 0x110($s2)
/* EF5084 80242A74 8E4200B0 */  lw        $v0, 0xb0($s2)
/* EF5088 80242A78 862300A8 */  lh        $v1, 0xa8($s1)
/* EF508C 80242A7C 34420008 */  ori       $v0, $v0, 8
/* EF5090 80242A80 AE430084 */  sw        $v1, 0x84($s2)
/* EF5094 80242A84 08090AA7 */  j         .L80242A9C
/* EF5098 80242A88 AE4200B0 */   sw       $v0, 0xb0($s2)
.L80242A8C:
/* EF509C 80242A8C 8E430094 */  lw        $v1, 0x94($s2)
/* EF50A0 80242A90 24020064 */  addiu     $v0, $zero, 0x64
/* EF50A4 80242A94 1462001C */  bne       $v1, $v0, .L80242B08
/* EF50A8 80242A98 00000000 */   nop
.L80242A9C:
/* EF50AC 80242A9C 24020064 */  addiu     $v0, $zero, 0x64
/* EF50B0 80242AA0 2404F7FF */  addiu     $a0, $zero, -0x801
/* EF50B4 80242AA4 AEA20070 */  sw        $v0, 0x70($s5)
/* EF50B8 80242AA8 A620008E */  sh        $zero, 0x8e($s1)
/* EF50BC 80242AAC 8E4300CC */  lw        $v1, 0xcc($s2)
/* EF50C0 80242AB0 8E220000 */  lw        $v0, ($s1)
/* EF50C4 80242AB4 3C01C47A */  lui       $at, 0xc47a
/* EF50C8 80242AB8 44810000 */  mtc1      $at, $f0
/* EF50CC 80242ABC 8C630000 */  lw        $v1, ($v1)
/* EF50D0 80242AC0 00441024 */  and       $v0, $v0, $a0
/* EF50D4 80242AC4 AE220000 */  sw        $v0, ($s1)
/* EF50D8 80242AC8 AE230028 */  sw        $v1, 0x28($s1)
/* EF50DC 80242ACC 8E420000 */  lw        $v0, ($s2)
/* EF50E0 80242AD0 3C030020 */  lui       $v1, 0x20
/* EF50E4 80242AD4 00431025 */  or        $v0, $v0, $v1
/* EF50E8 80242AD8 AE420000 */  sw        $v0, ($s2)
/* EF50EC 80242ADC 8E220000 */  lw        $v0, ($s1)
/* EF50F0 80242AE0 2403FDFF */  addiu     $v1, $zero, -0x201
/* EF50F4 80242AE4 00431024 */  and       $v0, $v0, $v1
/* EF50F8 80242AE8 34420008 */  ori       $v0, $v0, 8
/* EF50FC 80242AEC AE220000 */  sw        $v0, ($s1)
/* EF5100 80242AF0 2402FFFF */  addiu     $v0, $zero, -1
/* EF5104 80242AF4 AE400094 */  sw        $zero, 0x94($s2)
/* EF5108 80242AF8 AE420098 */  sw        $v0, 0x98($s2)
/* EF510C 80242AFC AE200038 */  sw        $zero, 0x38($s1)
/* EF5110 80242B00 E620003C */  swc1      $f0, 0x3c($s1)
/* EF5114 80242B04 AE200040 */  sw        $zero, 0x40($s1)
.L80242B08:
/* EF5118 80242B08 8E4200B0 */  lw        $v0, 0xb0($s2)
/* EF511C 80242B0C 30420004 */  andi      $v0, $v0, 4
/* EF5120 80242B10 10400030 */  beqz      $v0, .L80242BD4
/* EF5124 80242B14 2403FFFB */   addiu    $v1, $zero, -5
/* EF5128 80242B18 A620008E */  sh        $zero, 0x8e($s1)
/* EF512C 80242B1C 96420086 */  lhu       $v0, 0x86($s2)
/* EF5130 80242B20 A62200A8 */  sh        $v0, 0xa8($s1)
/* EF5134 80242B24 8E4200B0 */  lw        $v0, 0xb0($s2)
/* EF5138 80242B28 00431024 */  and       $v0, $v0, $v1
/* EF513C 80242B2C AE4200B0 */  sw        $v0, 0xb0($s2)
/* EF5140 80242B30 8E220000 */  lw        $v0, ($s1)
/* EF5144 80242B34 30420800 */  andi      $v0, $v0, 0x800
/* EF5148 80242B38 1040000A */  beqz      $v0, .L80242B64
/* EF514C 80242B3C 3C02004A */   lui      $v0, 0x4a
/* EF5150 80242B40 3C013F80 */  lui       $at, 0x3f80
/* EF5154 80242B44 44810000 */  mtc1      $at, $f0
/* EF5158 80242B48 34420018 */  ori       $v0, $v0, 0x18
/* EF515C 80242B4C AE220028 */  sw        $v0, 0x28($s1)
/* EF5160 80242B50 24020066 */  addiu     $v0, $zero, 0x66
/* EF5164 80242B54 AE200018 */  sw        $zero, 0x18($s1)
/* EF5168 80242B58 AE20001C */  sw        $zero, 0x1c($s1)
/* EF516C 80242B5C 08090AF4 */  j         .L80242BD0
/* EF5170 80242B60 E6200014 */   swc1     $f0, 0x14($s1)
.L80242B64:
/* EF5174 80242B64 24040002 */  addiu     $a0, $zero, 2
/* EF5178 80242B68 0220282D */  daddu     $a1, $s1, $zero
/* EF517C 80242B6C 0000302D */  daddu     $a2, $zero, $zero
/* EF5180 80242B70 862300A8 */  lh        $v1, 0xa8($s1)
/* EF5184 80242B74 3C013F80 */  lui       $at, 0x3f80
/* EF5188 80242B78 44810000 */  mtc1      $at, $f0
/* EF518C 80242B7C 3C014000 */  lui       $at, 0x4000
/* EF5190 80242B80 44811000 */  mtc1      $at, $f2
/* EF5194 80242B84 3C01C1A0 */  lui       $at, 0xc1a0
/* EF5198 80242B88 44812000 */  mtc1      $at, $f4
/* EF519C 80242B8C 24020028 */  addiu     $v0, $zero, 0x28
/* EF51A0 80242B90 AFA2001C */  sw        $v0, 0x1c($sp)
/* EF51A4 80242B94 44834000 */  mtc1      $v1, $f8
/* EF51A8 80242B98 00000000 */  nop
/* EF51AC 80242B9C 46804220 */  cvt.s.w   $f8, $f8
/* EF51B0 80242BA0 44074000 */  mfc1      $a3, $f8
/* EF51B4 80242BA4 27A20048 */  addiu     $v0, $sp, 0x48
/* EF51B8 80242BA8 AFA20020 */  sw        $v0, 0x20($sp)
/* EF51BC 80242BAC E7A00010 */  swc1      $f0, 0x10($sp)
/* EF51C0 80242BB0 E7A20014 */  swc1      $f2, 0x14($sp)
/* EF51C4 80242BB4 0C01D444 */  jal       func_80075110
/* EF51C8 80242BB8 E7A40018 */   swc1     $f4, 0x18($sp)
/* EF51CC 80242BBC 8E4200CC */  lw        $v0, 0xcc($s2)
/* EF51D0 80242BC0 8C420000 */  lw        $v0, ($v0)
/* EF51D4 80242BC4 AE220028 */  sw        $v0, 0x28($s1)
/* EF51D8 80242BC8 240200C8 */  addiu     $v0, $zero, 0xc8
/* EF51DC 80242BCC AEA00074 */  sw        $zero, 0x74($s5)
.L80242BD0:
/* EF51E0 80242BD0 AEA20070 */  sw        $v0, 0x70($s5)
.L80242BD4:
/* EF51E4 80242BD4 27A2004C */  addiu     $v0, $sp, 0x4c
/* EF51E8 80242BD8 AFA20010 */  sw        $v0, 0x10($sp)
/* EF51EC 80242BDC 27A20050 */  addiu     $v0, $sp, 0x50
/* EF51F0 80242BE0 AFA20014 */  sw        $v0, 0x14($sp)
/* EF51F4 80242BE4 27A20054 */  addiu     $v0, $sp, 0x54
/* EF51F8 80242BE8 AFA20018 */  sw        $v0, 0x18($sp)
/* EF51FC 80242BEC 8E250038 */  lw        $a1, 0x38($s1)
/* EF5200 80242BF0 8E26003C */  lw        $a2, 0x3c($s1)
/* EF5204 80242BF4 8E270040 */  lw        $a3, 0x40($s1)
/* EF5208 80242BF8 0C00BF2F */  jal       func_8002FCBC
/* EF520C 80242BFC 0000202D */   daddu    $a0, $zero, $zero
/* EF5210 80242C00 8EA20070 */  lw        $v0, 0x70($s5)
/* EF5214 80242C04 28420064 */  slti      $v0, $v0, 0x64
/* EF5218 80242C08 10400007 */  beqz      $v0, .L80242C28
/* EF521C 80242C0C 00000000 */   nop
/* EF5220 80242C10 8FA2004C */  lw        $v0, 0x4c($sp)
/* EF5224 80242C14 24420032 */  addiu     $v0, $v0, 0x32
/* EF5228 80242C18 2C4201A5 */  sltiu     $v0, $v0, 0x1a5
/* EF522C 80242C1C 14400002 */  bnez      $v0, .L80242C28
/* EF5230 80242C20 2402006E */   addiu    $v0, $zero, 0x6e
/* EF5234 80242C24 AEA20070 */  sw        $v0, 0x70($s5)
.L80242C28:
/* EF5238 80242C28 8EA30070 */  lw        $v1, 0x70($s5)
/* EF523C 80242C2C 2402000F */  addiu     $v0, $zero, 0xf
/* EF5240 80242C30 1062006B */  beq       $v1, $v0, .L80242DE0
/* EF5244 80242C34 28620010 */   slti     $v0, $v1, 0x10
/* EF5248 80242C38 10400016 */  beqz      $v0, .L80242C94
/* EF524C 80242C3C 24020003 */   addiu    $v0, $zero, 3
/* EF5250 80242C40 10620051 */  beq       $v1, $v0, .L80242D88
/* EF5254 80242C44 28620004 */   slti     $v0, $v1, 4
/* EF5258 80242C48 10400009 */  beqz      $v0, .L80242C70
/* EF525C 80242C4C 24020001 */   addiu    $v0, $zero, 1
/* EF5260 80242C50 10620044 */  beq       $v1, $v0, .L80242D64
/* EF5264 80242C54 28620002 */   slti     $v0, $v1, 2
/* EF5268 80242C58 50400048 */  beql      $v0, $zero, .L80242D7C
/* EF526C 80242C5C 02A0202D */   daddu    $a0, $s5, $zero
/* EF5270 80242C60 50600027 */  beql      $v1, $zero, .L80242D00
/* EF5274 80242C64 02A0202D */   daddu    $a0, $s5, $zero
/* EF5278 80242C68 08090CA5 */  j         .L80243294
/* EF527C 80242C6C 00000000 */   nop
.L80242C70:
/* EF5280 80242C70 2402000D */  addiu     $v0, $zero, 0xd
/* EF5284 80242C74 1062004D */  beq       $v1, $v0, .L80242DAC
/* EF5288 80242C78 2862000E */   slti     $v0, $v1, 0xe
/* EF528C 80242C7C 10400052 */  beqz      $v0, .L80242DC8
/* EF5290 80242C80 2402000C */   addiu    $v0, $zero, 0xc
/* EF5294 80242C84 10620046 */  beq       $v1, $v0, .L80242DA0
/* EF5298 80242C88 02A0202D */   daddu    $a0, $s5, $zero
/* EF529C 80242C8C 08090CA5 */  j         .L80243294
/* EF52A0 80242C90 00000000 */   nop
.L80242C94:
/* EF52A4 80242C94 24020067 */  addiu     $v0, $zero, 0x67
/* EF52A8 80242C98 10620158 */  beq       $v1, $v0, .L802431FC
/* EF52AC 80242C9C 28620068 */   slti     $v0, $v1, 0x68
/* EF52B0 80242CA0 10400009 */  beqz      $v0, .L80242CC8
/* EF52B4 80242CA4 24020065 */   addiu    $v0, $zero, 0x65
/* EF52B8 80242CA8 1062008F */  beq       $v1, $v0, .L80242EE8
/* EF52BC 80242CAC 28620066 */   slti     $v0, $v1, 0x66
/* EF52C0 80242CB0 104000A9 */  beqz      $v0, .L80242F58
/* EF52C4 80242CB4 24020064 */   addiu    $v0, $zero, 0x64
/* EF52C8 80242CB8 1062004F */  beq       $v1, $v0, .L80242DF8
/* EF52CC 80242CBC 24020002 */   addiu    $v0, $zero, 2
/* EF52D0 80242CC0 08090CA5 */  j         .L80243294
/* EF52D4 80242CC4 00000000 */   nop
.L80242CC8:
/* EF52D8 80242CC8 2404006F */  addiu     $a0, $zero, 0x6f
/* EF52DC 80242CCC 10640166 */  beq       $v1, $a0, .L80243268
/* EF52E0 80242CD0 28620070 */   slti     $v0, $v1, 0x70
/* EF52E4 80242CD4 10400005 */  beqz      $v0, .L80242CEC
/* EF52E8 80242CD8 2402006E */   addiu    $v0, $zero, 0x6e
/* EF52EC 80242CDC 10620156 */  beq       $v1, $v0, .L80243238
/* EF52F0 80242CE0 2402001E */   addiu    $v0, $zero, 0x1e
/* EF52F4 80242CE4 08090CA5 */  j         .L80243294
/* EF52F8 80242CE8 00000000 */   nop
.L80242CEC:
/* EF52FC 80242CEC 240200C8 */  addiu     $v0, $zero, 0xc8
/* EF5300 80242CF0 10620166 */  beq       $v1, $v0, .L8024328C
/* EF5304 80242CF4 00000000 */   nop
/* EF5308 80242CF8 08090CA5 */  j         .L80243294
/* EF530C 80242CFC 00000000 */   nop
.L80242D00:
/* EF5310 80242D00 0260282D */  daddu     $a1, $s3, $zero
/* EF5314 80242D04 0C013670 */  jal       func_8004D9C0
/* EF5318 80242D08 0280302D */   daddu    $a2, $s4, $zero
/* EF531C 80242D0C 96420086 */  lhu       $v0, 0x86($s2)
/* EF5320 80242D10 A62200A8 */  sh        $v0, 0xa8($s1)
/* EF5324 80242D14 8E4200A0 */  lw        $v0, 0xa0($s2)
/* EF5328 80242D18 10400013 */  beqz      $v0, .L80242D68
/* EF532C 80242D1C 02A0202D */   daddu    $a0, $s5, $zero
/* EF5330 80242D20 C620003C */  lwc1      $f0, 0x3c($s1)
/* EF5334 80242D24 44801000 */  mtc1      $zero, $f2
/* EF5338 80242D28 44801800 */  mtc1      $zero, $f3
/* EF533C 80242D2C 46000021 */  cvt.d.s   $f0, $f0
/* EF5340 80242D30 4622003E */  c.le.d    $f0, $f2
/* EF5344 80242D34 00000000 */  nop
/* EF5348 80242D38 45000005 */  bc1f      .L80242D50
/* EF534C 80242D3C 2403FDFF */   addiu    $v1, $zero, -0x201
/* EF5350 80242D40 8E220000 */  lw        $v0, ($s1)
/* EF5354 80242D44 00431024 */  and       $v0, $v0, $v1
/* EF5358 80242D48 08090B58 */  j         .L80242D60
/* EF535C 80242D4C 34420008 */   ori      $v0, $v0, 8
.L80242D50:
/* EF5360 80242D50 8E220000 */  lw        $v0, ($s1)
/* EF5364 80242D54 2403FFF7 */  addiu     $v1, $zero, -9
/* EF5368 80242D58 34420200 */  ori       $v0, $v0, 0x200
/* EF536C 80242D5C 00431024 */  and       $v0, $v0, $v1
.L80242D60:
/* EF5370 80242D60 AE220000 */  sw        $v0, ($s1)
.L80242D64:
/* EF5374 80242D64 02A0202D */  daddu     $a0, $s5, $zero
.L80242D68:
/* EF5378 80242D68 0260282D */  daddu     $a1, $s3, $zero
/* EF537C 80242D6C 0C0136B6 */  jal       func_8004DAD8
/* EF5380 80242D70 0280302D */   daddu    $a2, $s4, $zero
/* EF5384 80242D74 08090CA5 */  j         .L80243294
/* EF5388 80242D78 00000000 */   nop
.L80242D7C:
/* EF538C 80242D7C 0260282D */  daddu     $a1, $s3, $zero
/* EF5390 80242D80 0C0137D9 */  jal       func_8004DF64
/* EF5394 80242D84 0280302D */   daddu    $a2, $s4, $zero
.L80242D88:
/* EF5398 80242D88 02A0202D */  daddu     $a0, $s5, $zero
/* EF539C 80242D8C 0260282D */  daddu     $a1, $s3, $zero
/* EF53A0 80242D90 0C013809 */  jal       func_8004E024
/* EF53A4 80242D94 0280302D */   daddu    $a2, $s4, $zero
/* EF53A8 80242D98 08090CA5 */  j         .L80243294
/* EF53AC 80242D9C 00000000 */   nop
.L80242DA0:
/* EF53B0 80242DA0 0260282D */  daddu     $a1, $s3, $zero
/* EF53B4 80242DA4 0C090867 */  jal       func_8024219C_EF47AC
/* EF53B8 80242DA8 0280302D */   daddu    $a2, $s4, $zero
.L80242DAC:
/* EF53BC 80242DAC 02A0202D */  daddu     $a0, $s5, $zero
/* EF53C0 80242DB0 0260282D */  daddu     $a1, $s3, $zero
/* EF53C4 80242DB4 0C090886 */  jal       func_80242218_EF4828
/* EF53C8 80242DB8 0280302D */   daddu    $a2, $s4, $zero
/* EF53CC 80242DBC 96420086 */  lhu       $v0, 0x86($s2)
/* EF53D0 80242DC0 08090CA5 */  j         .L80243294
/* EF53D4 80242DC4 A62200A8 */   sh       $v0, 0xa8($s1)
.L80242DC8:
/* EF53D8 80242DC8 02A0202D */  daddu     $a0, $s5, $zero
/* EF53DC 80242DCC 0260282D */  daddu     $a1, $s3, $zero
/* EF53E0 80242DD0 0C0908D3 */  jal       func_8024234C_EF495C
/* EF53E4 80242DD4 0280302D */   daddu    $a2, $s4, $zero
/* EF53E8 80242DD8 08090CA5 */  j         .L80243294
/* EF53EC 80242DDC 00000000 */   nop
.L80242DE0:
/* EF53F0 80242DE0 02A0202D */  daddu     $a0, $s5, $zero
/* EF53F4 80242DE4 0260282D */  daddu     $a1, $s3, $zero
/* EF53F8 80242DE8 0C09092C */  jal       func_802424B0_EF4AC0
/* EF53FC 80242DEC 0280302D */   daddu    $a2, $s4, $zero
/* EF5400 80242DF0 08090CA5 */  j         .L80243294
/* EF5404 80242DF4 00000000 */   nop
.L80242DF8:
/* EF5408 80242DF8 8E430094 */  lw        $v1, 0x94($s2)
/* EF540C 80242DFC 14620125 */  bne       $v1, $v0, .L80243294
/* EF5410 80242E00 00000000 */   nop
/* EF5414 80242E04 0C010ABD */  jal       func_80042AF4
/* EF5418 80242E08 8E440098 */   lw       $a0, 0x98($s2)
/* EF541C 80242E0C 0C00F92F */  jal       dead_get_npc_unsafe
/* EF5420 80242E10 84440008 */   lh       $a0, 8($v0)
/* EF5424 80242E14 C440000C */  lwc1      $f0, 0xc($v0)
/* EF5428 80242E18 3C018024 */  lui       $at, %hi(D_80245468_EF7A78)
/* EF542C 80242E1C D4225468 */  ldc1      $f2, %lo(D_80245468_EF7A78)($at)
/* EF5430 80242E20 46000021 */  cvt.d.s   $f0, $f0
/* EF5434 80242E24 4622003C */  c.lt.d    $f0, $f2
/* EF5438 80242E28 00000000 */  nop
/* EF543C 80242E2C 45000008 */  bc1f      .L80242E50
/* EF5440 80242E30 00000000 */   nop
/* EF5444 80242E34 C4400038 */  lwc1      $f0, 0x38($v0)
/* EF5448 80242E38 3C014028 */  lui       $at, 0x4028
/* EF544C 80242E3C 44811800 */  mtc1      $at, $f3
/* EF5450 80242E40 44801000 */  mtc1      $zero, $f2
/* EF5454 80242E44 46000021 */  cvt.d.s   $f0, $f0
/* EF5458 80242E48 08090B9A */  j         .L80242E68
/* EF545C 80242E4C 46220000 */   add.d    $f0, $f0, $f2
.L80242E50:
/* EF5460 80242E50 C4400038 */  lwc1      $f0, 0x38($v0)
/* EF5464 80242E54 3C014028 */  lui       $at, 0x4028
/* EF5468 80242E58 44811800 */  mtc1      $at, $f3
/* EF546C 80242E5C 44801000 */  mtc1      $zero, $f2
/* EF5470 80242E60 46000021 */  cvt.d.s   $f0, $f0
/* EF5474 80242E64 46220001 */  sub.d     $f0, $f0, $f2
.L80242E68:
/* EF5478 80242E68 46200020 */  cvt.s.d   $f0, $f0
/* EF547C 80242E6C E6200038 */  swc1      $f0, 0x38($s1)
/* EF5480 80242E70 3C04004A */  lui       $a0, 0x4a
/* EF5484 80242E74 C440003C */  lwc1      $f0, 0x3c($v0)
/* EF5488 80242E78 3C014039 */  lui       $at, 0x4039
/* EF548C 80242E7C 44811800 */  mtc1      $at, $f3
/* EF5490 80242E80 44801000 */  mtc1      $zero, $f2
/* EF5494 80242E84 46000021 */  cvt.d.s   $f0, $f0
/* EF5498 80242E88 46220000 */  add.d     $f0, $f0, $f2
/* EF549C 80242E8C 34840018 */  ori       $a0, $a0, 0x18
/* EF54A0 80242E90 3C013FF0 */  lui       $at, 0x3ff0
/* EF54A4 80242E94 44811800 */  mtc1      $at, $f3
/* EF54A8 80242E98 44801000 */  mtc1      $zero, $f2
/* EF54AC 80242E9C 46200020 */  cvt.s.d   $f0, $f0
/* EF54B0 80242EA0 E620003C */  swc1      $f0, 0x3c($s1)
/* EF54B4 80242EA4 C4400040 */  lwc1      $f0, 0x40($v0)
/* EF54B8 80242EA8 8E220000 */  lw        $v0, ($s1)
/* EF54BC 80242EAC 2403FFFD */  addiu     $v1, $zero, -3
/* EF54C0 80242EB0 AE200048 */  sw        $zero, 0x48($s1)
/* EF54C4 80242EB4 AE200034 */  sw        $zero, 0x34($s1)
/* EF54C8 80242EB8 AE240028 */  sw        $a0, 0x28($s1)
/* EF54CC 80242EBC 34420008 */  ori       $v0, $v0, 8
/* EF54D0 80242EC0 00431024 */  and       $v0, $v0, $v1
/* EF54D4 80242EC4 2403FDFF */  addiu     $v1, $zero, -0x201
/* EF54D8 80242EC8 00431024 */  and       $v0, $v0, $v1
/* EF54DC 80242ECC 46000021 */  cvt.d.s   $f0, $f0
/* EF54E0 80242ED0 46220000 */  add.d     $f0, $f0, $f2
/* EF54E4 80242ED4 AE220000 */  sw        $v0, ($s1)
/* EF54E8 80242ED8 24020065 */  addiu     $v0, $zero, 0x65
/* EF54EC 80242EDC 46200020 */  cvt.s.d   $f0, $f0
/* EF54F0 80242EE0 E6200040 */  swc1      $f0, 0x40($s1)
/* EF54F4 80242EE4 AEA20070 */  sw        $v0, 0x70($s5)
.L80242EE8:
/* EF54F8 80242EE8 8E430094 */  lw        $v1, 0x94($s2)
/* EF54FC 80242EEC 24020003 */  addiu     $v0, $zero, 3
/* EF5500 80242EF0 146200E8 */  bne       $v1, $v0, .L80243294
/* EF5504 80242EF4 24020004 */   addiu    $v0, $zero, 4
/* EF5508 80242EF8 AE420094 */  sw        $v0, 0x94($s2)
/* EF550C 80242EFC C62C0038 */  lwc1      $f12, 0x38($s1)
/* EF5510 80242F00 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EF5514 80242F04 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EF5518 80242F08 C62E0040 */  lwc1      $f14, 0x40($s1)
/* EF551C 80242F0C 8C460028 */  lw        $a2, 0x28($v0)
/* EF5520 80242F10 0C00ABDC */  jal       fio_validate_header_checksums
/* EF5524 80242F14 8C470030 */   lw       $a3, 0x30($v0)
/* EF5528 80242F18 3C014020 */  lui       $at, 0x4020
/* EF552C 80242F1C 44811000 */  mtc1      $at, $f2
/* EF5530 80242F20 3C014100 */  lui       $at, 0x4100
/* EF5534 80242F24 44812000 */  mtc1      $at, $f4
/* EF5538 80242F28 3C013F4C */  lui       $at, 0x3f4c
/* EF553C 80242F2C 3421CCCD */  ori       $at, $at, 0xcccd
/* EF5540 80242F30 44813000 */  mtc1      $at, $f6
/* EF5544 80242F34 8E220000 */  lw        $v0, ($s1)
/* EF5548 80242F38 E620000C */  swc1      $f0, 0xc($s1)
/* EF554C 80242F3C 34420800 */  ori       $v0, $v0, 0x800
/* EF5550 80242F40 AE220000 */  sw        $v0, ($s1)
/* EF5554 80242F44 24020066 */  addiu     $v0, $zero, 0x66
/* EF5558 80242F48 E6220018 */  swc1      $f2, 0x18($s1)
/* EF555C 80242F4C E624001C */  swc1      $f4, 0x1c($s1)
/* EF5560 80242F50 E6260014 */  swc1      $f6, 0x14($s1)
/* EF5564 80242F54 AEA20070 */  sw        $v0, 0x70($s5)
.L80242F58:
/* EF5568 80242F58 C6200018 */  lwc1      $f0, 0x18($s1)
/* EF556C 80242F5C 44801000 */  mtc1      $zero, $f2
/* EF5570 80242F60 44801800 */  mtc1      $zero, $f3
/* EF5574 80242F64 46000021 */  cvt.d.s   $f0, $f0
/* EF5578 80242F68 4620103C */  c.lt.d    $f2, $f0
/* EF557C 80242F6C 00000000 */  nop
/* EF5580 80242F70 4500001F */  bc1f      .L80242FF0
/* EF5584 80242F74 27A50058 */   addiu    $a1, $sp, 0x58
/* EF5588 80242F78 C6200038 */  lwc1      $f0, 0x38($s1)
/* EF558C 80242F7C C622003C */  lwc1      $f2, 0x3c($s1)
/* EF5590 80242F80 C6240040 */  lwc1      $f4, 0x40($s1)
/* EF5594 80242F84 C6260018 */  lwc1      $f6, 0x18($s1)
/* EF5598 80242F88 E7A00058 */  swc1      $f0, 0x58($sp)
/* EF559C 80242F8C E7A2005C */  swc1      $f2, 0x5c($sp)
/* EF55A0 80242F90 E7A40060 */  swc1      $f4, 0x60($sp)
/* EF55A4 80242F94 E7A60010 */  swc1      $f6, 0x10($sp)
/* EF55A8 80242F98 C620000C */  lwc1      $f0, 0xc($s1)
/* EF55AC 80242F9C E7A00014 */  swc1      $f0, 0x14($sp)
/* EF55B0 80242FA0 862200A8 */  lh        $v0, 0xa8($s1)
/* EF55B4 80242FA4 44820000 */  mtc1      $v0, $f0
/* EF55B8 80242FA8 00000000 */  nop
/* EF55BC 80242FAC 46800020 */  cvt.s.w   $f0, $f0
/* EF55C0 80242FB0 E7A00018 */  swc1      $f0, 0x18($sp)
/* EF55C4 80242FB4 862200A6 */  lh        $v0, 0xa6($s1)
/* EF55C8 80242FB8 27A6005C */  addiu     $a2, $sp, 0x5c
/* EF55CC 80242FBC 44820000 */  mtc1      $v0, $f0
/* EF55D0 80242FC0 00000000 */  nop
/* EF55D4 80242FC4 46800020 */  cvt.s.w   $f0, $f0
/* EF55D8 80242FC8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* EF55DC 80242FCC 8E240080 */  lw        $a0, 0x80($s1)
/* EF55E0 80242FD0 0C0394C1 */  jal       func_800E5304
/* EF55E4 80242FD4 27A70060 */   addiu    $a3, $sp, 0x60
/* EF55E8 80242FD8 54400005 */  bnel      $v0, $zero, .L80242FF0
/* EF55EC 80242FDC AE200018 */   sw       $zero, 0x18($s1)
/* EF55F0 80242FE0 8E250018 */  lw        $a1, 0x18($s1)
/* EF55F4 80242FE4 8E26000C */  lw        $a2, 0xc($s1)
/* EF55F8 80242FE8 0C00F909 */  jal       func_8003E424
/* EF55FC 80242FEC 0220202D */   daddu    $a0, $s1, $zero
.L80242FF0:
/* EF5600 80242FF0 C620001C */  lwc1      $f0, 0x1c($s1)
/* EF5604 80242FF4 4480B000 */  mtc1      $zero, $f22
/* EF5608 80242FF8 4480B800 */  mtc1      $zero, $f23
/* EF560C 80242FFC 46000021 */  cvt.d.s   $f0, $f0
/* EF5610 80243000 4636003C */  c.lt.d    $f0, $f22
/* EF5614 80243004 00000000 */  nop
/* EF5618 80243008 45000074 */  bc1f      .L802431DC
/* EF561C 8024300C 27A50058 */   addiu    $a1, $sp, 0x58
/* EF5620 80243010 27A6005C */  addiu     $a2, $sp, 0x5c
/* EF5624 80243014 27A20064 */  addiu     $v0, $sp, 0x64
/* EF5628 80243018 C622003C */  lwc1      $f2, 0x3c($s1)
/* EF562C 8024301C C6260038 */  lwc1      $f6, 0x38($s1)
/* EF5630 80243020 3C01402A */  lui       $at, 0x402a
/* EF5634 80243024 4481A800 */  mtc1      $at, $f21
/* EF5638 80243028 4480A000 */  mtc1      $zero, $f20
/* EF563C 8024302C 460010A1 */  cvt.d.s   $f2, $f2
/* EF5640 80243030 46341080 */  add.d     $f2, $f2, $f20
/* EF5644 80243034 C620001C */  lwc1      $f0, 0x1c($s1)
/* EF5648 80243038 C6240040 */  lwc1      $f4, 0x40($s1)
/* EF564C 8024303C 46000005 */  abs.s     $f0, $f0
/* EF5650 80243040 E7A40060 */  swc1      $f4, 0x60($sp)
/* EF5654 80243044 3C014030 */  lui       $at, 0x4030
/* EF5658 80243048 44812800 */  mtc1      $at, $f5
/* EF565C 8024304C 44802000 */  mtc1      $zero, $f4
/* EF5660 80243050 46000021 */  cvt.d.s   $f0, $f0
/* EF5664 80243054 E7A60058 */  swc1      $f6, 0x58($sp)
/* EF5668 80243058 46240000 */  add.d     $f0, $f0, $f4
/* EF566C 8024305C 462010A0 */  cvt.s.d   $f2, $f2
/* EF5670 80243060 E7A2005C */  swc1      $f2, 0x5c($sp)
/* EF5674 80243064 46200020 */  cvt.s.d   $f0, $f0
/* EF5678 80243068 E7A00064 */  swc1      $f0, 0x64($sp)
/* EF567C 8024306C AFA20010 */  sw        $v0, 0x10($sp)
/* EF5680 80243070 8E240080 */  lw        $a0, 0x80($s1)
/* EF5684 80243074 0C03908F */  jal       func_800E423C
/* EF5688 80243078 27A70060 */   addiu    $a3, $sp, 0x60
/* EF568C 8024307C 10400057 */  beqz      $v0, .L802431DC
/* EF5690 80243080 00000000 */   nop
/* EF5694 80243084 C620001C */  lwc1      $f0, 0x1c($s1)
/* EF5698 80243088 C7A20064 */  lwc1      $f2, 0x64($sp)
/* EF569C 8024308C 46000005 */  abs.s     $f0, $f0
/* EF56A0 80243090 46000021 */  cvt.d.s   $f0, $f0
/* EF56A4 80243094 46340000 */  add.d     $f0, $f0, $f20
/* EF56A8 80243098 460010A1 */  cvt.d.s   $f2, $f2
/* EF56AC 8024309C 4620103E */  c.le.d    $f2, $f0
/* EF56B0 802430A0 00000000 */  nop
/* EF56B4 802430A4 4500004D */  bc1f      .L802431DC
/* EF56B8 802430A8 00000000 */   nop
/* EF56BC 802430AC C7A0005C */  lwc1      $f0, 0x5c($sp)
/* EF56C0 802430B0 E620003C */  swc1      $f0, 0x3c($s1)
/* EF56C4 802430B4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EF56C8 802430B8 C6200038 */  lwc1      $f0, 0x38($s1)
/* EF56CC 802430BC 4600020D */  trunc.w.s $f8, $f0
/* EF56D0 802430C0 E4480000 */  swc1      $f8, ($v0)
/* EF56D4 802430C4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EF56D8 802430C8 C620003C */  lwc1      $f0, 0x3c($s1)
/* EF56DC 802430CC 4600020D */  trunc.w.s $f8, $f0
/* EF56E0 802430D0 E4480004 */  swc1      $f8, 4($v0)
/* EF56E4 802430D4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EF56E8 802430D8 C6200040 */  lwc1      $f0, 0x40($s1)
/* EF56EC 802430DC 4600020D */  trunc.w.s $f8, $f0
/* EF56F0 802430E0 E4480008 */  swc1      $f8, 8($v0)
/* EF56F4 802430E4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EF56F8 802430E8 C6200038 */  lwc1      $f0, 0x38($s1)
/* EF56FC 802430EC 4600020D */  trunc.w.s $f8, $f0
/* EF5700 802430F0 E448001C */  swc1      $f8, 0x1c($v0)
/* EF5704 802430F4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EF5708 802430F8 C620003C */  lwc1      $f0, 0x3c($s1)
/* EF570C 802430FC 4600020D */  trunc.w.s $f8, $f0
/* EF5710 80243100 E4480020 */  swc1      $f8, 0x20($v0)
/* EF5714 80243104 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EF5718 80243108 C6200040 */  lwc1      $f0, 0x40($s1)
/* EF571C 8024310C 4600020D */  trunc.w.s $f8, $f0
/* EF5720 80243110 E4480024 */  swc1      $f8, 0x24($v0)
/* EF5724 80243114 8E4300A0 */  lw        $v1, 0xa0($s2)
/* EF5728 80243118 24020005 */  addiu     $v0, $zero, 5
/* EF572C 8024311C 1060000B */  beqz      $v1, .L8024314C
/* EF5730 80243120 AE420094 */   sw       $v0, 0x94($s2)
/* EF5734 80243124 C620003C */  lwc1      $f0, 0x3c($s1)
/* EF5738 80243128 46000021 */  cvt.d.s   $f0, $f0
/* EF573C 8024312C 4636003E */  c.le.d    $f0, $f22
/* EF5740 80243130 00000000 */  nop
/* EF5744 80243134 4501000D */  bc1t      .L8024316C
/* EF5748 80243138 2403FFF7 */   addiu    $v1, $zero, -9
/* EF574C 8024313C 8E220000 */  lw        $v0, ($s1)
/* EF5750 80243140 34420200 */  ori       $v0, $v0, 0x200
/* EF5754 80243144 08090C5F */  j         .L8024317C
/* EF5758 80243148 00431024 */   and      $v0, $v0, $v1
.L8024314C:
/* EF575C 8024314C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* EF5760 80243150 8C420034 */  lw        $v0, 0x34($v0)
/* EF5764 80243154 14400005 */  bnez      $v0, .L8024316C
/* EF5768 80243158 2403FFF7 */   addiu    $v1, $zero, -9
/* EF576C 8024315C 8E220000 */  lw        $v0, ($s1)
/* EF5770 80243160 34420200 */  ori       $v0, $v0, 0x200
/* EF5774 80243164 08090C5F */  j         .L8024317C
/* EF5778 80243168 00431024 */   and      $v0, $v0, $v1
.L8024316C:
/* EF577C 8024316C 8E220000 */  lw        $v0, ($s1)
/* EF5780 80243170 2403FDFF */  addiu     $v1, $zero, -0x201
/* EF5784 80243174 00431024 */  and       $v0, $v0, $v1
/* EF5788 80243178 34420008 */  ori       $v0, $v0, 8
.L8024317C:
/* EF578C 8024317C AE220000 */  sw        $v0, ($s1)
/* EF5790 80243180 C62C0038 */  lwc1      $f12, 0x38($s1)
/* EF5794 80243184 C62E0040 */  lwc1      $f14, 0x40($s1)
/* EF5798 80243188 8E220000 */  lw        $v0, ($s1)
/* EF579C 8024318C 3C048010 */  lui       $a0, %hi(dead_gPlayerStatusPtr)
/* EF57A0 80243190 8C84FC90 */  lw        $a0, %lo(dead_gPlayerStatusPtr)($a0)
/* EF57A4 80243194 3C030004 */  lui       $v1, 4
/* EF57A8 80243198 AE20001C */  sw        $zero, 0x1c($s1)
/* EF57AC 8024319C 00431025 */  or        $v0, $v0, $v1
/* EF57B0 802431A0 2403F7FF */  addiu     $v1, $zero, -0x801
/* EF57B4 802431A4 00431024 */  and       $v0, $v0, $v1
/* EF57B8 802431A8 AE220000 */  sw        $v0, ($s1)
/* EF57BC 802431AC 8C860028 */  lw        $a2, 0x28($a0)
/* EF57C0 802431B0 0C00ABDC */  jal       fio_validate_header_checksums
/* EF57C4 802431B4 8C870030 */   lw       $a3, 0x30($a0)
/* EF57C8 802431B8 3C02004A */  lui       $v0, 0x4a
/* EF57CC 802431BC 3442001A */  ori       $v0, $v0, 0x1a
/* EF57D0 802431C0 AE220028 */  sw        $v0, 0x28($s1)
/* EF57D4 802431C4 24020003 */  addiu     $v0, $zero, 3
/* EF57D8 802431C8 A622008E */  sh        $v0, 0x8e($s1)
/* EF57DC 802431CC 24020067 */  addiu     $v0, $zero, 0x67
/* EF57E0 802431D0 E620000C */  swc1      $f0, 0xc($s1)
/* EF57E4 802431D4 08090CA5 */  j         .L80243294
/* EF57E8 802431D8 AEA20070 */   sw       $v0, 0x70($s5)
.L802431DC:
/* EF57EC 802431DC C624003C */  lwc1      $f4, 0x3c($s1)
/* EF57F0 802431E0 C620001C */  lwc1      $f0, 0x1c($s1)
/* EF57F4 802431E4 46002100 */  add.s     $f4, $f4, $f0
/* EF57F8 802431E8 C6220014 */  lwc1      $f2, 0x14($s1)
/* EF57FC 802431EC 46020001 */  sub.s     $f0, $f0, $f2
/* EF5800 802431F0 E624003C */  swc1      $f4, 0x3c($s1)
/* EF5804 802431F4 08090CA5 */  j         .L80243294
/* EF5808 802431F8 E620001C */   swc1     $f0, 0x1c($s1)
.L802431FC:
/* EF580C 802431FC 9622008E */  lhu       $v0, 0x8e($s1)
/* EF5810 80243200 2442FFFF */  addiu     $v0, $v0, -1
/* EF5814 80243204 A622008E */  sh        $v0, 0x8e($s1)
/* EF5818 80243208 00021400 */  sll       $v0, $v0, 0x10
/* EF581C 8024320C 1C400021 */  bgtz      $v0, .L80243294
/* EF5820 80243210 3C03004A */   lui      $v1, 0x4a
/* EF5824 80243214 3C04FFFB */  lui       $a0, 0xfffb
/* EF5828 80243218 3484FFFF */  ori       $a0, $a0, 0xffff
/* EF582C 8024321C 8E220000 */  lw        $v0, ($s1)
/* EF5830 80243220 34630001 */  ori       $v1, $v1, 1
/* EF5834 80243224 AE230028 */  sw        $v1, 0x28($s1)
/* EF5838 80243228 00441024 */  and       $v0, $v0, $a0
/* EF583C 8024322C AE220000 */  sw        $v0, ($s1)
/* EF5840 80243230 08090CA5 */  j         .L80243294
/* EF5844 80243234 AEA00070 */   sw       $zero, 0x70($s5)
.L80243238:
/* EF5848 80243238 3C01C47A */  lui       $at, 0xc47a
/* EF584C 8024323C 44810000 */  mtc1      $at, $f0
/* EF5850 80243240 8E230000 */  lw        $v1, ($s1)
/* EF5854 80243244 A622008E */  sh        $v0, 0x8e($s1)
/* EF5858 80243248 2402FDFF */  addiu     $v0, $zero, -0x201
/* EF585C 8024324C AE200038 */  sw        $zero, 0x38($s1)
/* EF5860 80243250 AE200040 */  sw        $zero, 0x40($s1)
/* EF5864 80243254 3463000A */  ori       $v1, $v1, 0xa
/* EF5868 80243258 00621824 */  and       $v1, $v1, $v0
/* EF586C 8024325C E620003C */  swc1      $f0, 0x3c($s1)
/* EF5870 80243260 AE230000 */  sw        $v1, ($s1)
/* EF5874 80243264 AEA40070 */  sw        $a0, 0x70($s5)
.L80243268:
/* EF5878 80243268 9622008E */  lhu       $v0, 0x8e($s1)
/* EF587C 8024326C 2442FFFF */  addiu     $v0, $v0, -1
/* EF5880 80243270 A622008E */  sh        $v0, 0x8e($s1)
/* EF5884 80243274 00021400 */  sll       $v0, $v0, 0x10
/* EF5888 80243278 1C400006 */  bgtz      $v0, .L80243294
/* EF588C 8024327C 24020064 */   addiu    $v0, $zero, 0x64
/* EF5890 80243280 AE400094 */  sw        $zero, 0x94($s2)
/* EF5894 80243284 08090CA5 */  j         .L80243294
/* EF5898 80243288 AEA20070 */   sw       $v0, 0x70($s5)
.L8024328C:
/* EF589C 8024328C 0C013AE3 */  jal       func_8004EB8C
/* EF58A0 80243290 02A0202D */   daddu    $a0, $s5, $zero
.L80243294:
/* EF58A4 80243294 8FBF0080 */  lw        $ra, 0x80($sp)
/* EF58A8 80243298 8FB5007C */  lw        $s5, 0x7c($sp)
/* EF58AC 8024329C 8FB40078 */  lw        $s4, 0x78($sp)
/* EF58B0 802432A0 8FB30074 */  lw        $s3, 0x74($sp)
/* EF58B4 802432A4 8FB20070 */  lw        $s2, 0x70($sp)
/* EF58B8 802432A8 8FB1006C */  lw        $s1, 0x6c($sp)
/* EF58BC 802432AC 8FB00068 */  lw        $s0, 0x68($sp)
/* EF58C0 802432B0 D7B60090 */  ldc1      $f22, 0x90($sp)
/* EF58C4 802432B4 D7B40088 */  ldc1      $f20, 0x88($sp)
/* EF58C8 802432B8 0000102D */  daddu     $v0, $zero, $zero
/* EF58CC 802432BC 03E00008 */  jr        $ra
/* EF58D0 802432C0 27BD0098 */   addiu    $sp, $sp, 0x98
/* EF58D4 802432C4 00000000 */  nop
/* EF58D8 802432C8 00000000 */  nop
/* EF58DC 802432CC 00000000 */  nop

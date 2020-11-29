.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BA8_D9E078
/* D9E078 80240BA8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* D9E07C 80240BAC AFB30054 */  sw        $s3, 0x54($sp)
/* D9E080 80240BB0 0080982D */  daddu     $s3, $a0, $zero
/* D9E084 80240BB4 AFBF0060 */  sw        $ra, 0x60($sp)
/* D9E088 80240BB8 AFB5005C */  sw        $s5, 0x5c($sp)
/* D9E08C 80240BBC AFB40058 */  sw        $s4, 0x58($sp)
/* D9E090 80240BC0 AFB20050 */  sw        $s2, 0x50($sp)
/* D9E094 80240BC4 AFB1004C */  sw        $s1, 0x4c($sp)
/* D9E098 80240BC8 AFB00048 */  sw        $s0, 0x48($sp)
/* D9E09C 80240BCC 8E710148 */  lw        $s1, 0x148($s3)
/* D9E0A0 80240BD0 86240008 */  lh        $a0, 8($s1)
/* D9E0A4 80240BD4 0C00EABB */  jal       get_npc_unsafe
/* D9E0A8 80240BD8 00A0802D */   daddu    $s0, $a1, $zero
/* D9E0AC 80240BDC 8E63000C */  lw        $v1, 0xc($s3)
/* D9E0B0 80240BE0 0260202D */  daddu     $a0, $s3, $zero
/* D9E0B4 80240BE4 8C650000 */  lw        $a1, ($v1)
/* D9E0B8 80240BE8 0C0B1EAF */  jal       get_variable
/* D9E0BC 80240BEC 0040902D */   daddu    $s2, $v0, $zero
/* D9E0C0 80240BF0 AFA00018 */  sw        $zero, 0x18($sp)
/* D9E0C4 80240BF4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9E0C8 80240BF8 8C630030 */  lw        $v1, 0x30($v1)
/* D9E0CC 80240BFC AFA3001C */  sw        $v1, 0x1c($sp)
/* D9E0D0 80240C00 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9E0D4 80240C04 8C63001C */  lw        $v1, 0x1c($v1)
/* D9E0D8 80240C08 AFA30020 */  sw        $v1, 0x20($sp)
/* D9E0DC 80240C0C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9E0E0 80240C10 8C630024 */  lw        $v1, 0x24($v1)
/* D9E0E4 80240C14 AFA30024 */  sw        $v1, 0x24($sp)
/* D9E0E8 80240C18 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9E0EC 80240C1C 8C630028 */  lw        $v1, 0x28($v1)
/* D9E0F0 80240C20 27B50018 */  addiu     $s5, $sp, 0x18
/* D9E0F4 80240C24 AFA30028 */  sw        $v1, 0x28($sp)
/* D9E0F8 80240C28 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D9E0FC 80240C2C 3C014282 */  lui       $at, 0x4282
/* D9E100 80240C30 44810000 */  mtc1      $at, $f0
/* D9E104 80240C34 8C63002C */  lw        $v1, 0x2c($v1)
/* D9E108 80240C38 0040A02D */  daddu     $s4, $v0, $zero
/* D9E10C 80240C3C E7A00030 */  swc1      $f0, 0x30($sp)
/* D9E110 80240C40 A7A00034 */  sh        $zero, 0x34($sp)
/* D9E114 80240C44 16000005 */  bnez      $s0, .L80240C5C
/* D9E118 80240C48 AFA3002C */   sw       $v1, 0x2c($sp)
/* D9E11C 80240C4C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D9E120 80240C50 30420004 */  andi      $v0, $v0, 4
/* D9E124 80240C54 10400044 */  beqz      $v0, .L80240D68
/* D9E128 80240C58 00000000 */   nop      
.L80240C5C:
/* D9E12C 80240C5C 2404F7FF */  addiu     $a0, $zero, -0x801
/* D9E130 80240C60 AE600070 */  sw        $zero, 0x70($s3)
/* D9E134 80240C64 A640008E */  sh        $zero, 0x8e($s2)
/* D9E138 80240C68 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9E13C 80240C6C 8E430000 */  lw        $v1, ($s2)
/* D9E140 80240C70 8C420000 */  lw        $v0, ($v0)
/* D9E144 80240C74 00641824 */  and       $v1, $v1, $a0
/* D9E148 80240C78 AE430000 */  sw        $v1, ($s2)
/* D9E14C 80240C7C AE420028 */  sw        $v0, 0x28($s2)
/* D9E150 80240C80 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9E154 80240C84 8C420034 */  lw        $v0, 0x34($v0)
/* D9E158 80240C88 54400005 */  bnel      $v0, $zero, .L80240CA0
/* D9E15C 80240C8C 2402FDFF */   addiu    $v0, $zero, -0x201
/* D9E160 80240C90 34620200 */  ori       $v0, $v1, 0x200
/* D9E164 80240C94 2403FFF7 */  addiu     $v1, $zero, -9
/* D9E168 80240C98 0809032A */  j         .L80240CA8
/* D9E16C 80240C9C 00431024 */   and      $v0, $v0, $v1
.L80240CA0:
/* D9E170 80240CA0 00621024 */  and       $v0, $v1, $v0
/* D9E174 80240CA4 34420008 */  ori       $v0, $v0, 8
.L80240CA8:
/* D9E178 80240CA8 AE420000 */  sw        $v0, ($s2)
/* D9E17C 80240CAC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D9E180 80240CB0 30420004 */  andi      $v0, $v0, 4
/* D9E184 80240CB4 10400004 */  beqz      $v0, .L80240CC8
/* D9E188 80240CB8 24020063 */   addiu    $v0, $zero, 0x63
/* D9E18C 80240CBC AE620070 */  sw        $v0, 0x70($s3)
/* D9E190 80240CC0 08090338 */  j         .L80240CE0
/* D9E194 80240CC4 AE600074 */   sw       $zero, 0x74($s3)
.L80240CC8:
/* D9E198 80240CC8 8E220000 */  lw        $v0, ($s1)
/* D9E19C 80240CCC 3C034000 */  lui       $v1, 0x4000
/* D9E1A0 80240CD0 00431024 */  and       $v0, $v0, $v1
/* D9E1A4 80240CD4 10400002 */  beqz      $v0, .L80240CE0
/* D9E1A8 80240CD8 2402000C */   addiu    $v0, $zero, 0xc
/* D9E1AC 80240CDC AE620070 */  sw        $v0, 0x70($s3)
.L80240CE0:
/* D9E1B0 80240CE0 3C06BFFF */  lui       $a2, 0xbfff
/* D9E1B4 80240CE4 34C6FFFF */  ori       $a2, $a2, 0xffff
/* D9E1B8 80240CE8 27A50038 */  addiu     $a1, $sp, 0x38
/* D9E1BC 80240CEC 2404FFFB */  addiu     $a0, $zero, -5
/* D9E1C0 80240CF0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D9E1C4 80240CF4 8E230000 */  lw        $v1, ($s1)
/* D9E1C8 80240CF8 3C0142C8 */  lui       $at, 0x42c8
/* D9E1CC 80240CFC 44810000 */  mtc1      $at, $f0
/* D9E1D0 80240D00 00441024 */  and       $v0, $v0, $a0
/* D9E1D4 80240D04 00661824 */  and       $v1, $v1, $a2
/* D9E1D8 80240D08 AE2200B0 */  sw        $v0, 0xb0($s1)
/* D9E1DC 80240D0C AE230000 */  sw        $v1, ($s1)
/* D9E1E0 80240D10 864200A8 */  lh        $v0, 0xa8($s2)
/* D9E1E4 80240D14 27A70040 */  addiu     $a3, $sp, 0x40
/* D9E1E8 80240D18 E7A00044 */  swc1      $f0, 0x44($sp)
/* D9E1EC 80240D1C C6460038 */  lwc1      $f6, 0x38($s2)
/* D9E1F0 80240D20 C640003C */  lwc1      $f0, 0x3c($s2)
/* D9E1F4 80240D24 C6420040 */  lwc1      $f2, 0x40($s2)
/* D9E1F8 80240D28 44822000 */  mtc1      $v0, $f4
/* D9E1FC 80240D2C 00000000 */  nop       
/* D9E200 80240D30 46802120 */  cvt.s.w   $f4, $f4
/* D9E204 80240D34 27A20044 */  addiu     $v0, $sp, 0x44
/* D9E208 80240D38 46040000 */  add.s     $f0, $f0, $f4
/* D9E20C 80240D3C E7A60038 */  swc1      $f6, 0x38($sp)
/* D9E210 80240D40 E7A20040 */  swc1      $f2, 0x40($sp)
/* D9E214 80240D44 E7A0003C */  swc1      $f0, 0x3c($sp)
/* D9E218 80240D48 AFA20010 */  sw        $v0, 0x10($sp)
/* D9E21C 80240D4C 8E440080 */  lw        $a0, 0x80($s2)
/* D9E220 80240D50 0C0372DF */  jal       func_800DCB7C
/* D9E224 80240D54 27A6003C */   addiu    $a2, $sp, 0x3c
/* D9E228 80240D58 10400003 */  beqz      $v0, .L80240D68
/* D9E22C 80240D5C 00000000 */   nop      
/* D9E230 80240D60 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* D9E234 80240D64 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D68:
/* D9E238 80240D68 8E630070 */  lw        $v1, 0x70($s3)
/* D9E23C 80240D6C 2C620064 */  sltiu     $v0, $v1, 0x64
/* D9E240 80240D70 10400050 */  beqz      $v0, .L80240EB4
/* D9E244 80240D74 00031080 */   sll      $v0, $v1, 2
/* D9E248 80240D78 3C018024 */  lui       $at, %hi(D_80247880)
/* D9E24C 80240D7C 00220821 */  addu      $at, $at, $v0
/* D9E250 80240D80 8C227880 */  lw        $v0, %lo(D_80247880)($at)
/* D9E254 80240D84 00400008 */  jr        $v0
/* D9E258 80240D88 00000000 */   nop      
/* D9E25C 80240D8C 0260202D */  daddu     $a0, $s3, $zero
/* D9E260 80240D90 0280282D */  daddu     $a1, $s4, $zero
/* D9E264 80240D94 0C012568 */  jal       func_800495A0
/* D9E268 80240D98 02A0302D */   daddu    $a2, $s5, $zero
/* D9E26C 80240D9C 0260202D */  daddu     $a0, $s3, $zero
/* D9E270 80240DA0 0280282D */  daddu     $a1, $s4, $zero
/* D9E274 80240DA4 0C0125AE */  jal       func_800496B8
/* D9E278 80240DA8 02A0302D */   daddu    $a2, $s5, $zero
/* D9E27C 80240DAC 080903AD */  j         .L80240EB4
/* D9E280 80240DB0 00000000 */   nop      
/* D9E284 80240DB4 0260202D */  daddu     $a0, $s3, $zero
/* D9E288 80240DB8 0280282D */  daddu     $a1, $s4, $zero
/* D9E28C 80240DBC 0C0126D1 */  jal       func_80049B44
/* D9E290 80240DC0 02A0302D */   daddu    $a2, $s5, $zero
/* D9E294 80240DC4 0260202D */  daddu     $a0, $s3, $zero
/* D9E298 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* D9E29C 80240DCC 0C012701 */  jal       func_80049C04
/* D9E2A0 80240DD0 02A0302D */   daddu    $a2, $s5, $zero
/* D9E2A4 80240DD4 080903AD */  j         .L80240EB4
/* D9E2A8 80240DD8 00000000 */   nop      
/* D9E2AC 80240DDC 0260202D */  daddu     $a0, $s3, $zero
/* D9E2B0 80240DE0 0280282D */  daddu     $a1, $s4, $zero
/* D9E2B4 80240DE4 0C01278F */  jal       func_80049E3C
/* D9E2B8 80240DE8 02A0302D */   daddu    $a2, $s5, $zero
/* D9E2BC 80240DEC 0260202D */  daddu     $a0, $s3, $zero
/* D9E2C0 80240DF0 0280282D */  daddu     $a1, $s4, $zero
/* D9E2C4 80240DF4 0C0127B3 */  jal       func_80049ECC
/* D9E2C8 80240DF8 02A0302D */   daddu    $a2, $s5, $zero
/* D9E2CC 80240DFC 080903AD */  j         .L80240EB4
/* D9E2D0 80240E00 00000000 */   nop      
/* D9E2D4 80240E04 0260202D */  daddu     $a0, $s3, $zero
/* D9E2D8 80240E08 0280282D */  daddu     $a1, $s4, $zero
/* D9E2DC 80240E0C 0C0127DF */  jal       func_80049F7C
/* D9E2E0 80240E10 02A0302D */   daddu    $a2, $s5, $zero
/* D9E2E4 80240E14 0260202D */  daddu     $a0, $s3, $zero
/* D9E2E8 80240E18 0280282D */  daddu     $a1, $s4, $zero
/* D9E2EC 80240E1C 0C012849 */  jal       func_8004A124
/* D9E2F0 80240E20 02A0302D */   daddu    $a2, $s5, $zero
/* D9E2F4 80240E24 8E630070 */  lw        $v1, 0x70($s3)
/* D9E2F8 80240E28 2402000E */  addiu     $v0, $zero, 0xe
/* D9E2FC 80240E2C 14620021 */  bne       $v1, $v0, .L80240EB4
/* D9E300 80240E30 00000000 */   nop      
/* D9E304 80240E34 0260202D */  daddu     $a0, $s3, $zero
/* D9E308 80240E38 0280282D */  daddu     $a1, $s4, $zero
/* D9E30C 80240E3C 0C09025C */  jal       func_80240970_D9DE40
/* D9E310 80240E40 02A0302D */   daddu    $a2, $s5, $zero
/* D9E314 80240E44 8E630070 */  lw        $v1, 0x70($s3)
/* D9E318 80240E48 2402000F */  addiu     $v0, $zero, 0xf
/* D9E31C 80240E4C 14620019 */  bne       $v1, $v0, .L80240EB4
/* D9E320 80240E50 00000000 */   nop      
/* D9E324 80240E54 0260202D */  daddu     $a0, $s3, $zero
/* D9E328 80240E58 0280282D */  daddu     $a1, $s4, $zero
/* D9E32C 80240E5C 0C090278 */  jal       func_802409E0_D9DEB0
/* D9E330 80240E60 02A0302D */   daddu    $a2, $s5, $zero
/* D9E334 80240E64 8E630070 */  lw        $v1, 0x70($s3)
/* D9E338 80240E68 24020010 */  addiu     $v0, $zero, 0x10
/* D9E33C 80240E6C 14620011 */  bne       $v1, $v0, .L80240EB4
/* D9E340 80240E70 00000000 */   nop      
/* D9E344 80240E74 0260202D */  daddu     $a0, $s3, $zero
/* D9E348 80240E78 0280282D */  daddu     $a1, $s4, $zero
/* D9E34C 80240E7C 0C0902AC */  jal       func_80240AB0_D9DF80
/* D9E350 80240E80 02A0302D */   daddu    $a2, $s5, $zero
/* D9E354 80240E84 8E630070 */  lw        $v1, 0x70($s3)
/* D9E358 80240E88 24020011 */  addiu     $v0, $zero, 0x11
/* D9E35C 80240E8C 14620009 */  bne       $v1, $v0, .L80240EB4
/* D9E360 80240E90 00000000 */   nop      
/* D9E364 80240E94 0260202D */  daddu     $a0, $s3, $zero
/* D9E368 80240E98 0280282D */  daddu     $a1, $s4, $zero
/* D9E36C 80240E9C 0C0902D2 */  jal       func_80240B48_D9E018
/* D9E370 80240EA0 02A0302D */   daddu    $a2, $s5, $zero
/* D9E374 80240EA4 080903AD */  j         .L80240EB4
/* D9E378 80240EA8 00000000 */   nop      
/* D9E37C 80240EAC 0C0129CF */  jal       func_8004A73C
/* D9E380 80240EB0 0260202D */   daddu    $a0, $s3, $zero
.L80240EB4:
/* D9E384 80240EB4 8FBF0060 */  lw        $ra, 0x60($sp)
/* D9E388 80240EB8 8FB5005C */  lw        $s5, 0x5c($sp)
/* D9E38C 80240EBC 8FB40058 */  lw        $s4, 0x58($sp)
/* D9E390 80240EC0 8FB30054 */  lw        $s3, 0x54($sp)
/* D9E394 80240EC4 8FB20050 */  lw        $s2, 0x50($sp)
/* D9E398 80240EC8 8FB1004C */  lw        $s1, 0x4c($sp)
/* D9E39C 80240ECC 8FB00048 */  lw        $s0, 0x48($sp)
/* D9E3A0 80240ED0 0000102D */  daddu     $v0, $zero, $zero
/* D9E3A4 80240ED4 03E00008 */  jr        $ra
/* D9E3A8 80240ED8 27BD0068 */   addiu    $sp, $sp, 0x68

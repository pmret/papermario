.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B14_9A9F04
/* 9A9F04 80241B14 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 9A9F08 80241B18 AFB3005C */  sw        $s3, 0x5c($sp)
/* 9A9F0C 80241B1C 0080982D */  daddu     $s3, $a0, $zero
/* 9A9F10 80241B20 AFBF0068 */  sw        $ra, 0x68($sp)
/* 9A9F14 80241B24 AFB50064 */  sw        $s5, 0x64($sp)
/* 9A9F18 80241B28 AFB40060 */  sw        $s4, 0x60($sp)
/* 9A9F1C 80241B2C AFB20058 */  sw        $s2, 0x58($sp)
/* 9A9F20 80241B30 AFB10054 */  sw        $s1, 0x54($sp)
/* 9A9F24 80241B34 AFB00050 */  sw        $s0, 0x50($sp)
/* 9A9F28 80241B38 8E710148 */  lw        $s1, 0x148($s3)
/* 9A9F2C 80241B3C 86240008 */  lh        $a0, 8($s1)
/* 9A9F30 80241B40 0C00EABB */  jal       get_npc_unsafe
/* 9A9F34 80241B44 00A0802D */   daddu    $s0, $a1, $zero
/* 9A9F38 80241B48 8E63000C */  lw        $v1, 0xc($s3)
/* 9A9F3C 80241B4C 0260202D */  daddu     $a0, $s3, $zero
/* 9A9F40 80241B50 8C650000 */  lw        $a1, ($v1)
/* 9A9F44 80241B54 0C0B1EAF */  jal       get_variable
/* 9A9F48 80241B58 0040902D */   daddu    $s2, $v0, $zero
/* 9A9F4C 80241B5C AFA00028 */  sw        $zero, 0x28($sp)
/* 9A9F50 80241B60 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9F54 80241B64 8C630094 */  lw        $v1, 0x94($v1)
/* 9A9F58 80241B68 AFA3002C */  sw        $v1, 0x2c($sp)
/* 9A9F5C 80241B6C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9F60 80241B70 8C630080 */  lw        $v1, 0x80($v1)
/* 9A9F64 80241B74 AFA30030 */  sw        $v1, 0x30($sp)
/* 9A9F68 80241B78 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9F6C 80241B7C 8C630088 */  lw        $v1, 0x88($v1)
/* 9A9F70 80241B80 AFA30034 */  sw        $v1, 0x34($sp)
/* 9A9F74 80241B84 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9F78 80241B88 8C63008C */  lw        $v1, 0x8c($v1)
/* 9A9F7C 80241B8C 27B50028 */  addiu     $s5, $sp, 0x28
/* 9A9F80 80241B90 AFA30038 */  sw        $v1, 0x38($sp)
/* 9A9F84 80241B94 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9F88 80241B98 3C0142C8 */  lui       $at, 0x42c8
/* 9A9F8C 80241B9C 44810000 */  mtc1      $at, $f0
/* 9A9F90 80241BA0 8C630090 */  lw        $v1, 0x90($v1)
/* 9A9F94 80241BA4 0040A02D */  daddu     $s4, $v0, $zero
/* 9A9F98 80241BA8 E7A00040 */  swc1      $f0, 0x40($sp)
/* 9A9F9C 80241BAC A7A00044 */  sh        $zero, 0x44($sp)
/* 9A9FA0 80241BB0 12000007 */  beqz      $s0, .L80241BD0
/* 9A9FA4 80241BB4 AFA3003C */   sw       $v1, 0x3c($sp)
/* 9A9FA8 80241BB8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A9FAC 80241BBC 864300A8 */  lh        $v1, 0xa8($s2)
/* 9A9FB0 80241BC0 34420008 */  ori       $v0, $v0, 8
/* 9A9FB4 80241BC4 AE230084 */  sw        $v1, 0x84($s1)
/* 9A9FB8 80241BC8 080906F8 */  j         .L80241BE0
/* 9A9FBC 80241BCC AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241BD0:
/* 9A9FC0 80241BD0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A9FC4 80241BD4 30420004 */  andi      $v0, $v0, 4
/* 9A9FC8 80241BD8 10400048 */  beqz      $v0, .L80241CFC
/* 9A9FCC 80241BDC 00000000 */   nop      
.L80241BE0:
/* 9A9FD0 80241BE0 A640008E */  sh        $zero, 0x8e($s2)
/* 9A9FD4 80241BE4 AE600070 */  sw        $zero, 0x70($s3)
/* 9A9FD8 80241BE8 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9A9FDC 80241BEC 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9A9FE0 80241BF0 A2200007 */  sb        $zero, 7($s1)
/* 9A9FE4 80241BF4 8E420000 */  lw        $v0, ($s2)
/* 9A9FE8 80241BF8 8C630000 */  lw        $v1, ($v1)
/* 9A9FEC 80241BFC 00441024 */  and       $v0, $v0, $a0
/* 9A9FF0 80241C00 AE420000 */  sw        $v0, ($s2)
/* 9A9FF4 80241C04 AE430028 */  sw        $v1, 0x28($s2)
/* 9A9FF8 80241C08 96220086 */  lhu       $v0, 0x86($s1)
/* 9A9FFC 80241C0C A64200A8 */  sh        $v0, 0xa8($s2)
/* 9AA000 80241C10 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9AA004 80241C14 A22000B5 */  sb        $zero, 0xb5($s1)
/* 9AA008 80241C18 AE20008C */  sw        $zero, 0x8c($s1)
/* 9AA00C 80241C1C 8C420098 */  lw        $v0, 0x98($v0)
/* 9AA010 80241C20 14400006 */  bnez      $v0, .L80241C3C
/* 9AA014 80241C24 2403FDFF */   addiu    $v1, $zero, -0x201
/* 9AA018 80241C28 8E420000 */  lw        $v0, ($s2)
/* 9AA01C 80241C2C 2403FFF7 */  addiu     $v1, $zero, -9
/* 9AA020 80241C30 34420200 */  ori       $v0, $v0, 0x200
/* 9AA024 80241C34 08090712 */  j         .L80241C48
/* 9AA028 80241C38 00431024 */   and      $v0, $v0, $v1
.L80241C3C:
/* 9AA02C 80241C3C 8E420000 */  lw        $v0, ($s2)
/* 9AA030 80241C40 00431024 */  and       $v0, $v0, $v1
/* 9AA034 80241C44 34420008 */  ori       $v0, $v0, 8
.L80241C48:
/* 9AA038 80241C48 AE420000 */  sw        $v0, ($s2)
/* 9AA03C 80241C4C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9AA040 80241C50 30420004 */  andi      $v0, $v0, 4
/* 9AA044 80241C54 1040001E */  beqz      $v0, .L80241CD0
/* 9AA048 80241C58 24040002 */   addiu    $a0, $zero, 2
/* 9AA04C 80241C5C 0240282D */  daddu     $a1, $s2, $zero
/* 9AA050 80241C60 0000302D */  daddu     $a2, $zero, $zero
/* 9AA054 80241C64 24020063 */  addiu     $v0, $zero, 0x63
/* 9AA058 80241C68 AE620070 */  sw        $v0, 0x70($s3)
/* 9AA05C 80241C6C AE600074 */  sw        $zero, 0x74($s3)
/* 9AA060 80241C70 864300A8 */  lh        $v1, 0xa8($s2)
/* 9AA064 80241C74 3C013F80 */  lui       $at, 0x3f80
/* 9AA068 80241C78 44810000 */  mtc1      $at, $f0
/* 9AA06C 80241C7C 3C014000 */  lui       $at, 0x4000
/* 9AA070 80241C80 44811000 */  mtc1      $at, $f2
/* 9AA074 80241C84 3C01C1A0 */  lui       $at, 0xc1a0
/* 9AA078 80241C88 44812000 */  mtc1      $at, $f4
/* 9AA07C 80241C8C 24020028 */  addiu     $v0, $zero, 0x28
/* 9AA080 80241C90 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9AA084 80241C94 44833000 */  mtc1      $v1, $f6
/* 9AA088 80241C98 00000000 */  nop       
/* 9AA08C 80241C9C 468031A0 */  cvt.s.w   $f6, $f6
/* 9AA090 80241CA0 44073000 */  mfc1      $a3, $f6
/* 9AA094 80241CA4 27A20048 */  addiu     $v0, $sp, 0x48
/* 9AA098 80241CA8 AFA20020 */  sw        $v0, 0x20($sp)
/* 9AA09C 80241CAC E7A00010 */  swc1      $f0, 0x10($sp)
/* 9AA0A0 80241CB0 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9AA0A4 80241CB4 0C01BFA4 */  jal       fx_emote
/* 9AA0A8 80241CB8 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9AA0AC 80241CBC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9AA0B0 80241CC0 2403FFFB */  addiu     $v1, $zero, -5
/* 9AA0B4 80241CC4 00431024 */  and       $v0, $v0, $v1
/* 9AA0B8 80241CC8 0809073F */  j         .L80241CFC
/* 9AA0BC 80241CCC AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241CD0:
/* 9AA0C0 80241CD0 8E220000 */  lw        $v0, ($s1)
/* 9AA0C4 80241CD4 3C034000 */  lui       $v1, 0x4000
/* 9AA0C8 80241CD8 00431024 */  and       $v0, $v0, $v1
/* 9AA0CC 80241CDC 10400007 */  beqz      $v0, .L80241CFC
/* 9AA0D0 80241CE0 3C03BFFF */   lui      $v1, 0xbfff
/* 9AA0D4 80241CE4 2402000C */  addiu     $v0, $zero, 0xc
/* 9AA0D8 80241CE8 AE620070 */  sw        $v0, 0x70($s3)
/* 9AA0DC 80241CEC 8E220000 */  lw        $v0, ($s1)
/* 9AA0E0 80241CF0 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9AA0E4 80241CF4 00431024 */  and       $v0, $v0, $v1
/* 9AA0E8 80241CF8 AE220000 */  sw        $v0, ($s1)
.L80241CFC:
/* 9AA0EC 80241CFC 8E630070 */  lw        $v1, 0x70($s3)
/* 9AA0F0 80241D00 2C620064 */  sltiu     $v0, $v1, 0x64
/* 9AA0F4 80241D04 1040003A */  beqz      $v0, .L80241DF0
/* 9AA0F8 80241D08 00031080 */   sll      $v0, $v1, 2
/* 9AA0FC 80241D0C 3C018024 */  lui       $at, %hi(D_802460E0)
/* 9AA100 80241D10 00220821 */  addu      $at, $at, $v0
/* 9AA104 80241D14 8C2260E0 */  lw        $v0, %lo(D_802460E0)($at)
/* 9AA108 80241D18 00400008 */  jr        $v0
/* 9AA10C 80241D1C 00000000 */   nop      
/* 9AA110 80241D20 0260202D */  daddu     $a0, $s3, $zero
/* 9AA114 80241D24 0280282D */  daddu     $a1, $s4, $zero
/* 9AA118 80241D28 0C090321 */  jal       func_80240C84_9A9074
/* 9AA11C 80241D2C 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA120 80241D30 96220086 */  lhu       $v0, 0x86($s1)
/* 9AA124 80241D34 A64200A8 */  sh        $v0, 0xa8($s2)
/* 9AA128 80241D38 0260202D */  daddu     $a0, $s3, $zero
/* 9AA12C 80241D3C 0280282D */  daddu     $a1, $s4, $zero
/* 9AA130 80241D40 0C090377 */  jal       func_80240DDC_9A91CC
/* 9AA134 80241D44 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA138 80241D48 0809077C */  j         .L80241DF0
/* 9AA13C 80241D4C 00000000 */   nop      
/* 9AA140 80241D50 0260202D */  daddu     $a0, $s3, $zero
/* 9AA144 80241D54 0280282D */  daddu     $a1, $s4, $zero
/* 9AA148 80241D58 0C090421 */  jal       trd_04_UnkNpcAIFunc1
/* 9AA14C 80241D5C 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA150 80241D60 0260202D */  daddu     $a0, $s3, $zero
/* 9AA154 80241D64 0280282D */  daddu     $a1, $s4, $zero
/* 9AA158 80241D68 0C090451 */  jal       func_80241144_9A9534
/* 9AA15C 80241D6C 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA160 80241D70 0809077C */  j         .L80241DF0
/* 9AA164 80241D74 00000000 */   nop      
/* 9AA168 80241D78 0260202D */  daddu     $a0, $s3, $zero
/* 9AA16C 80241D7C 0280282D */  daddu     $a1, $s4, $zero
/* 9AA170 80241D80 0C0904C0 */  jal       func_80241300_9A96F0
/* 9AA174 80241D84 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA178 80241D88 0809077C */  j         .L80241DF0
/* 9AA17C 80241D8C 00000000 */   nop      
/* 9AA180 80241D90 0260202D */  daddu     $a0, $s3, $zero
/* 9AA184 80241D94 0280282D */  daddu     $a1, $s4, $zero
/* 9AA188 80241D98 0C09012C */  jal       func_802404B0_9A88A0
/* 9AA18C 80241D9C 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA190 80241DA0 0260202D */  daddu     $a0, $s3, $zero
/* 9AA194 80241DA4 0280282D */  daddu     $a1, $s4, $zero
/* 9AA198 80241DA8 0C09014B */  jal       func_8024052C_9A891C
/* 9AA19C 80241DAC 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA1A0 80241DB0 0809077C */  j         .L80241DF0
/* 9AA1A4 80241DB4 00000000 */   nop      
/* 9AA1A8 80241DB8 0260202D */  daddu     $a0, $s3, $zero
/* 9AA1AC 80241DBC 0280282D */  daddu     $a1, $s4, $zero
/* 9AA1B0 80241DC0 0C090198 */  jal       func_80240660_9A8A50
/* 9AA1B4 80241DC4 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA1B8 80241DC8 0809077C */  j         .L80241DF0
/* 9AA1BC 80241DCC 00000000 */   nop      
/* 9AA1C0 80241DD0 0260202D */  daddu     $a0, $s3, $zero
/* 9AA1C4 80241DD4 0280282D */  daddu     $a1, $s4, $zero
/* 9AA1C8 80241DD8 0C0901F1 */  jal       func_802407C4_9A8BB4
/* 9AA1CC 80241DDC 02A0302D */   daddu    $a2, $s5, $zero
/* 9AA1D0 80241DE0 0809077C */  j         .L80241DF0
/* 9AA1D4 80241DE4 00000000 */   nop      
/* 9AA1D8 80241DE8 0C0129CF */  jal       func_8004A73C
/* 9AA1DC 80241DEC 0260202D */   daddu    $a0, $s3, $zero
.L80241DF0:
/* 9AA1E0 80241DF0 8FBF0068 */  lw        $ra, 0x68($sp)
/* 9AA1E4 80241DF4 8FB50064 */  lw        $s5, 0x64($sp)
/* 9AA1E8 80241DF8 8FB40060 */  lw        $s4, 0x60($sp)
/* 9AA1EC 80241DFC 8FB3005C */  lw        $s3, 0x5c($sp)
/* 9AA1F0 80241E00 8FB20058 */  lw        $s2, 0x58($sp)
/* 9AA1F4 80241E04 8FB10054 */  lw        $s1, 0x54($sp)
/* 9AA1F8 80241E08 8FB00050 */  lw        $s0, 0x50($sp)
/* 9AA1FC 80241E0C 0000102D */  daddu     $v0, $zero, $zero
/* 9AA200 80241E10 03E00008 */  jr        $ra
/* 9AA204 80241E14 27BD0070 */   addiu    $sp, $sp, 0x70

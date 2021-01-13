.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D58_C79A38
/* C79A38 80242D58 27BDFF90 */  addiu     $sp, $sp, -0x70
/* C79A3C 80242D5C AFB3005C */  sw        $s3, 0x5c($sp)
/* C79A40 80242D60 0080982D */  daddu     $s3, $a0, $zero
/* C79A44 80242D64 AFBF0068 */  sw        $ra, 0x68($sp)
/* C79A48 80242D68 AFB50064 */  sw        $s5, 0x64($sp)
/* C79A4C 80242D6C AFB40060 */  sw        $s4, 0x60($sp)
/* C79A50 80242D70 AFB20058 */  sw        $s2, 0x58($sp)
/* C79A54 80242D74 AFB10054 */  sw        $s1, 0x54($sp)
/* C79A58 80242D78 AFB00050 */  sw        $s0, 0x50($sp)
/* C79A5C 80242D7C 8E710148 */  lw        $s1, 0x148($s3)
/* C79A60 80242D80 86240008 */  lh        $a0, 8($s1)
/* C79A64 80242D84 0C00EABB */  jal       get_npc_unsafe
/* C79A68 80242D88 00A0802D */   daddu    $s0, $a1, $zero
/* C79A6C 80242D8C 8E63000C */  lw        $v1, 0xc($s3)
/* C79A70 80242D90 0260202D */  daddu     $a0, $s3, $zero
/* C79A74 80242D94 8C650000 */  lw        $a1, ($v1)
/* C79A78 80242D98 0C0B1EAF */  jal       get_variable
/* C79A7C 80242D9C 0040902D */   daddu    $s2, $v0, $zero
/* C79A80 80242DA0 AFA00028 */  sw        $zero, 0x28($sp)
/* C79A84 80242DA4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C79A88 80242DA8 8C630030 */  lw        $v1, 0x30($v1)
/* C79A8C 80242DAC AFA3002C */  sw        $v1, 0x2c($sp)
/* C79A90 80242DB0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C79A94 80242DB4 8C63001C */  lw        $v1, 0x1c($v1)
/* C79A98 80242DB8 AFA30030 */  sw        $v1, 0x30($sp)
/* C79A9C 80242DBC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C79AA0 80242DC0 8C630024 */  lw        $v1, 0x24($v1)
/* C79AA4 80242DC4 AFA30034 */  sw        $v1, 0x34($sp)
/* C79AA8 80242DC8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C79AAC 80242DCC 8C630028 */  lw        $v1, 0x28($v1)
/* C79AB0 80242DD0 27B50028 */  addiu     $s5, $sp, 0x28
/* C79AB4 80242DD4 AFA30038 */  sw        $v1, 0x38($sp)
/* C79AB8 80242DD8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C79ABC 80242DDC 3C0142C8 */  lui       $at, 0x42c8
/* C79AC0 80242DE0 44810000 */  mtc1      $at, $f0
/* C79AC4 80242DE4 8C63002C */  lw        $v1, 0x2c($v1)
/* C79AC8 80242DE8 0040A02D */  daddu     $s4, $v0, $zero
/* C79ACC 80242DEC E7A00040 */  swc1      $f0, 0x40($sp)
/* C79AD0 80242DF0 A7A00044 */  sh        $zero, 0x44($sp)
/* C79AD4 80242DF4 12000009 */  beqz      $s0, .L80242E1C
/* C79AD8 80242DF8 AFA3003C */   sw       $v1, 0x3c($sp)
/* C79ADC 80242DFC 864300A8 */  lh        $v1, 0xa8($s2)
/* C79AE0 80242E00 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C79AE4 80242E04 AE20008C */  sw        $zero, 0x8c($s1)
/* C79AE8 80242E08 A22000B5 */  sb        $zero, 0xb5($s1)
/* C79AEC 80242E0C 34420008 */  ori       $v0, $v0, 8
/* C79AF0 80242E10 AE230084 */  sw        $v1, 0x84($s1)
/* C79AF4 80242E14 08090B8B */  j         .L80242E2C
/* C79AF8 80242E18 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80242E1C:
/* C79AFC 80242E1C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C79B00 80242E20 30420004 */  andi      $v0, $v0, 4
/* C79B04 80242E24 10400047 */  beqz      $v0, .L80242F44
/* C79B08 80242E28 00000000 */   nop
.L80242E2C:
/* C79B0C 80242E2C AE600070 */  sw        $zero, 0x70($s3)
/* C79B10 80242E30 A640008E */  sh        $zero, 0x8e($s2)
/* C79B14 80242E34 8E2300CC */  lw        $v1, 0xcc($s1)
/* C79B18 80242E38 2404F7FF */  addiu     $a0, $zero, -0x801
/* C79B1C 80242E3C A2200007 */  sb        $zero, 7($s1)
/* C79B20 80242E40 8E420000 */  lw        $v0, ($s2)
/* C79B24 80242E44 8C630000 */  lw        $v1, ($v1)
/* C79B28 80242E48 00441024 */  and       $v0, $v0, $a0
/* C79B2C 80242E4C AE420000 */  sw        $v0, ($s2)
/* C79B30 80242E50 AE430028 */  sw        $v1, 0x28($s2)
/* C79B34 80242E54 96220086 */  lhu       $v0, 0x86($s1)
/* C79B38 80242E58 A64200A8 */  sh        $v0, 0xa8($s2)
/* C79B3C 80242E5C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C79B40 80242E60 AE200090 */  sw        $zero, 0x90($s1)
/* C79B44 80242E64 8C420034 */  lw        $v0, 0x34($v0)
/* C79B48 80242E68 14400006 */  bnez      $v0, .L80242E84
/* C79B4C 80242E6C 2403FDFF */   addiu    $v1, $zero, -0x201
/* C79B50 80242E70 8E420000 */  lw        $v0, ($s2)
/* C79B54 80242E74 2403FFF7 */  addiu     $v1, $zero, -9
/* C79B58 80242E78 34420200 */  ori       $v0, $v0, 0x200
/* C79B5C 80242E7C 08090BA4 */  j         .L80242E90
/* C79B60 80242E80 00431024 */   and      $v0, $v0, $v1
.L80242E84:
/* C79B64 80242E84 8E420000 */  lw        $v0, ($s2)
/* C79B68 80242E88 00431024 */  and       $v0, $v0, $v1
/* C79B6C 80242E8C 34420008 */  ori       $v0, $v0, 8
.L80242E90:
/* C79B70 80242E90 AE420000 */  sw        $v0, ($s2)
/* C79B74 80242E94 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C79B78 80242E98 30420004 */  andi      $v0, $v0, 4
/* C79B7C 80242E9C 1040001E */  beqz      $v0, .L80242F18
/* C79B80 80242EA0 24040002 */   addiu    $a0, $zero, 2
/* C79B84 80242EA4 0240282D */  daddu     $a1, $s2, $zero
/* C79B88 80242EA8 0000302D */  daddu     $a2, $zero, $zero
/* C79B8C 80242EAC 24020063 */  addiu     $v0, $zero, 0x63
/* C79B90 80242EB0 AE620070 */  sw        $v0, 0x70($s3)
/* C79B94 80242EB4 AE600074 */  sw        $zero, 0x74($s3)
/* C79B98 80242EB8 864300A8 */  lh        $v1, 0xa8($s2)
/* C79B9C 80242EBC 3C013F80 */  lui       $at, 0x3f80
/* C79BA0 80242EC0 44810000 */  mtc1      $at, $f0
/* C79BA4 80242EC4 3C014000 */  lui       $at, 0x4000
/* C79BA8 80242EC8 44811000 */  mtc1      $at, $f2
/* C79BAC 80242ECC 3C01C1A0 */  lui       $at, 0xc1a0
/* C79BB0 80242ED0 44812000 */  mtc1      $at, $f4
/* C79BB4 80242ED4 24020028 */  addiu     $v0, $zero, 0x28
/* C79BB8 80242ED8 AFA2001C */  sw        $v0, 0x1c($sp)
/* C79BBC 80242EDC 44833000 */  mtc1      $v1, $f6
/* C79BC0 80242EE0 00000000 */  nop
/* C79BC4 80242EE4 468031A0 */  cvt.s.w   $f6, $f6
/* C79BC8 80242EE8 44073000 */  mfc1      $a3, $f6
/* C79BCC 80242EEC 27A20048 */  addiu     $v0, $sp, 0x48
/* C79BD0 80242EF0 AFA20020 */  sw        $v0, 0x20($sp)
/* C79BD4 80242EF4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C79BD8 80242EF8 E7A20014 */  swc1      $f2, 0x14($sp)
/* C79BDC 80242EFC 0C01BFA4 */  jal       fx_emote
/* C79BE0 80242F00 E7A40018 */   swc1     $f4, 0x18($sp)
/* C79BE4 80242F04 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C79BE8 80242F08 2403FFFB */  addiu     $v1, $zero, -5
/* C79BEC 80242F0C 00431024 */  and       $v0, $v0, $v1
/* C79BF0 80242F10 08090BD1 */  j         .L80242F44
/* C79BF4 80242F14 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80242F18:
/* C79BF8 80242F18 8E220000 */  lw        $v0, ($s1)
/* C79BFC 80242F1C 3C034000 */  lui       $v1, 0x4000
/* C79C00 80242F20 00431024 */  and       $v0, $v0, $v1
/* C79C04 80242F24 10400007 */  beqz      $v0, .L80242F44
/* C79C08 80242F28 3C03BFFF */   lui      $v1, 0xbfff
/* C79C0C 80242F2C 2402000C */  addiu     $v0, $zero, 0xc
/* C79C10 80242F30 AE620070 */  sw        $v0, 0x70($s3)
/* C79C14 80242F34 8E220000 */  lw        $v0, ($s1)
/* C79C18 80242F38 3463FFFF */  ori       $v1, $v1, 0xffff
/* C79C1C 80242F3C 00431024 */  and       $v0, $v0, $v1
/* C79C20 80242F40 AE220000 */  sw        $v0, ($s1)
.L80242F44:
/* C79C24 80242F44 8E220090 */  lw        $v0, 0x90($s1)
/* C79C28 80242F48 1840000C */  blez      $v0, .L80242F7C
/* C79C2C 80242F4C 2442FFFF */   addiu    $v0, $v0, -1
/* C79C30 80242F50 14400087 */  bnez      $v0, .L80243170
/* C79C34 80242F54 AE220090 */   sw       $v0, 0x90($s1)
/* C79C38 80242F58 3C03FFAA */  lui       $v1, 0xffaa
/* C79C3C 80242F5C 8E420028 */  lw        $v0, 0x28($s2)
/* C79C40 80242F60 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* C79C44 80242F64 00431021 */  addu      $v0, $v0, $v1
/* C79C48 80242F68 2C420002 */  sltiu     $v0, $v0, 2
/* C79C4C 80242F6C 10400003 */  beqz      $v0, .L80242F7C
/* C79C50 80242F70 3C020055 */   lui      $v0, 0x55
/* C79C54 80242F74 3442000C */  ori       $v0, $v0, 0xc
/* C79C58 80242F78 AE420028 */  sw        $v0, 0x28($s2)
.L80242F7C:
/* C79C5C 80242F7C 8E630070 */  lw        $v1, 0x70($s3)
/* C79C60 80242F80 2402000C */  addiu     $v0, $zero, 0xc
/* C79C64 80242F84 10620048 */  beq       $v1, $v0, .L802430A8
/* C79C68 80242F88 2862000D */   slti     $v0, $v1, 0xd
/* C79C6C 80242F8C 1040000F */  beqz      $v0, .L80242FCC
/* C79C70 80242F90 24100001 */   addiu    $s0, $zero, 1
/* C79C74 80242F94 1070001E */  beq       $v1, $s0, .L80243010
/* C79C78 80242F98 28620002 */   slti     $v0, $v1, 2
/* C79C7C 80242F9C 10400005 */  beqz      $v0, .L80242FB4
/* C79C80 80242FA0 24020002 */   addiu    $v0, $zero, 2
/* C79C84 80242FA4 10600015 */  beqz      $v1, .L80242FFC
/* C79C88 80242FA8 0260202D */   daddu    $a0, $s3, $zero
/* C79C8C 80242FAC 08090C41 */  j         .L80243104
/* C79C90 80242FB0 00000000 */   nop
.L80242FB4:
/* C79C94 80242FB4 1062001C */  beq       $v1, $v0, .L80243028
/* C79C98 80242FB8 24020003 */   addiu    $v0, $zero, 3
/* C79C9C 80242FBC 10620035 */  beq       $v1, $v0, .L80243094
/* C79CA0 80242FC0 0260202D */   daddu    $a0, $s3, $zero
/* C79CA4 80242FC4 08090C41 */  j         .L80243104
/* C79CA8 80242FC8 00000000 */   nop
.L80242FCC:
/* C79CAC 80242FCC 2402000E */  addiu     $v0, $zero, 0xe
/* C79CB0 80242FD0 1062003F */  beq       $v1, $v0, .L802430D0
/* C79CB4 80242FD4 0062102A */   slt      $v0, $v1, $v0
/* C79CB8 80242FD8 14400038 */  bnez      $v0, .L802430BC
/* C79CBC 80242FDC 0260202D */   daddu    $a0, $s3, $zero
/* C79CC0 80242FE0 2402000F */  addiu     $v0, $zero, 0xf
/* C79CC4 80242FE4 10620040 */  beq       $v1, $v0, .L802430E8
/* C79CC8 80242FE8 24020063 */   addiu    $v0, $zero, 0x63
/* C79CCC 80242FEC 10620043 */  beq       $v1, $v0, .L802430FC
/* C79CD0 80242FF0 00000000 */   nop
/* C79CD4 80242FF4 08090C41 */  j         .L80243104
/* C79CD8 80242FF8 00000000 */   nop
.L80242FFC:
/* C79CDC 80242FFC 0280282D */  daddu     $a1, $s4, $zero
/* C79CE0 80243000 0C012568 */  jal       func_800495A0
/* C79CE4 80243004 02A0302D */   daddu    $a2, $s5, $zero
/* C79CE8 80243008 96220086 */  lhu       $v0, 0x86($s1)
/* C79CEC 8024300C A64200A8 */  sh        $v0, 0xa8($s2)
.L80243010:
/* C79CF0 80243010 0260202D */  daddu     $a0, $s3, $zero
/* C79CF4 80243014 0280282D */  daddu     $a1, $s4, $zero
/* C79CF8 80243018 0C0125AE */  jal       func_800496B8
/* C79CFC 8024301C 02A0302D */   daddu    $a2, $s5, $zero
/* C79D00 80243020 08090C41 */  j         .L80243104
/* C79D04 80243024 00000000 */   nop
.L80243028:
/* C79D08 80243028 0260202D */  daddu     $a0, $s3, $zero
/* C79D0C 8024302C 0280282D */  daddu     $a1, $s4, $zero
/* C79D10 80243030 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* C79D14 80243034 02A0302D */   daddu    $a2, $s5, $zero
/* C79D18 80243038 8E230088 */  lw        $v1, 0x88($s1)
/* C79D1C 8024303C 24020006 */  addiu     $v0, $zero, 6
/* C79D20 80243040 14620014 */  bne       $v1, $v0, .L80243094
/* C79D24 80243044 0260202D */   daddu    $a0, $s3, $zero
/* C79D28 80243048 0C00A67F */  jal       rand_int
/* C79D2C 8024304C 24040064 */   addiu    $a0, $zero, 0x64
/* C79D30 80243050 28420021 */  slti      $v0, $v0, 0x21
/* C79D34 80243054 5040000F */  beql      $v0, $zero, .L80243094
/* C79D38 80243058 0260202D */   daddu    $a0, $s3, $zero
/* C79D3C 8024305C 8E22008C */  lw        $v0, 0x8c($s1)
/* C79D40 80243060 10400005 */  beqz      $v0, .L80243078
/* C79D44 80243064 3C020055 */   lui      $v0, 0x55
/* C79D48 80243068 3442002F */  ori       $v0, $v0, 0x2f
/* C79D4C 8024306C AE20008C */  sw        $zero, 0x8c($s1)
/* C79D50 80243070 08090C21 */  j         .L80243084
/* C79D54 80243074 A22000B5 */   sb       $zero, 0xb5($s1)
.L80243078:
/* C79D58 80243078 3442002E */  ori       $v0, $v0, 0x2e
/* C79D5C 8024307C AE30008C */  sw        $s0, 0x8c($s1)
/* C79D60 80243080 A23000B5 */  sb        $s0, 0xb5($s1)
.L80243084:
/* C79D64 80243084 AE420028 */  sw        $v0, 0x28($s2)
/* C79D68 80243088 24020007 */  addiu     $v0, $zero, 7
/* C79D6C 8024308C 08090C5C */  j         .L80243170
/* C79D70 80243090 AE220090 */   sw       $v0, 0x90($s1)
.L80243094:
/* C79D74 80243094 0280282D */  daddu     $a1, $s4, $zero
/* C79D78 80243098 0C012701 */  jal       func_80049C04
/* C79D7C 8024309C 02A0302D */   daddu    $a2, $s5, $zero
/* C79D80 802430A0 08090C41 */  j         .L80243104
/* C79D84 802430A4 00000000 */   nop
.L802430A8:
/* C79D88 802430A8 0260202D */  daddu     $a0, $s3, $zero
/* C79D8C 802430AC 0280282D */  daddu     $a1, $s4, $zero
/* C79D90 802430B0 0C090A71 */  jal       kzn_09_set_script_owner_npc_anim
/* C79D94 802430B4 02A0302D */   daddu    $a2, $s5, $zero
/* C79D98 802430B8 0260202D */  daddu     $a0, $s3, $zero
.L802430BC:
/* C79D9C 802430BC 0280282D */  daddu     $a1, $s4, $zero
/* C79DA0 802430C0 0C090A90 */  jal       func_80242A40_C79720
/* C79DA4 802430C4 02A0302D */   daddu    $a2, $s5, $zero
/* C79DA8 802430C8 08090C41 */  j         .L80243104
/* C79DAC 802430CC 00000000 */   nop
.L802430D0:
/* C79DB0 802430D0 0260202D */  daddu     $a0, $s3, $zero
/* C79DB4 802430D4 0280282D */  daddu     $a1, $s4, $zero
/* C79DB8 802430D8 0C090ADD */  jal       kzn_09_UnkNpcAIFunc12
/* C79DBC 802430DC 02A0302D */   daddu    $a2, $s5, $zero
/* C79DC0 802430E0 08090C41 */  j         .L80243104
/* C79DC4 802430E4 00000000 */   nop
.L802430E8:
/* C79DC8 802430E8 0280282D */  daddu     $a1, $s4, $zero
/* C79DCC 802430EC 0C090B36 */  jal       func_80242CD8_C799B8
/* C79DD0 802430F0 02A0302D */   daddu    $a2, $s5, $zero
/* C79DD4 802430F4 08090C41 */  j         .L80243104
/* C79DD8 802430F8 00000000 */   nop
.L802430FC:
/* C79DDC 802430FC 0C0129CF */  jal       func_8004A73C
/* C79DE0 80243100 0260202D */   daddu    $a0, $s3, $zero
.L80243104:
/* C79DE4 80243104 8E230088 */  lw        $v1, 0x88($s1)
/* C79DE8 80243108 24020006 */  addiu     $v0, $zero, 6
/* C79DEC 8024310C 14620019 */  bne       $v1, $v0, .L80243174
/* C79DF0 80243110 0000102D */   daddu    $v0, $zero, $zero
/* C79DF4 80243114 8E22008C */  lw        $v0, 0x8c($s1)
/* C79DF8 80243118 10400003 */  beqz      $v0, .L80243128
/* C79DFC 8024311C 24020001 */   addiu    $v0, $zero, 1
/* C79E00 80243120 08090C4B */  j         .L8024312C
/* C79E04 80243124 A22200B5 */   sb       $v0, 0xb5($s1)
.L80243128:
/* C79E08 80243128 A22000B5 */  sb        $zero, 0xb5($s1)
.L8024312C:
/* C79E0C 8024312C 8E22008C */  lw        $v0, 0x8c($s1)
/* C79E10 80243130 1040000F */  beqz      $v0, .L80243170
/* C79E14 80243134 3C03FFAA */   lui      $v1, 0xffaa
/* C79E18 80243138 8E420028 */  lw        $v0, 0x28($s2)
/* C79E1C 8024313C 3463FFFC */  ori       $v1, $v1, 0xfffc
/* C79E20 80243140 00431821 */  addu      $v1, $v0, $v1
/* C79E24 80243144 2C620015 */  sltiu     $v0, $v1, 0x15
/* C79E28 80243148 10400009 */  beqz      $v0, .L80243170
/* C79E2C 8024314C 00031080 */   sll      $v0, $v1, 2
/* C79E30 80243150 3C018024 */  lui       $at, %hi(jtbl_80247440_C7E120)
/* C79E34 80243154 00220821 */  addu      $at, $at, $v0
/* C79E38 80243158 8C227440 */  lw        $v0, %lo(jtbl_80247440_C7E120)($at)
/* C79E3C 8024315C 00400008 */  jr        $v0
/* C79E40 80243160 00000000 */   nop
glabel L80243164_C79E44
/* C79E44 80243164 8E420028 */  lw        $v0, 0x28($s2)
/* C79E48 80243168 24420001 */  addiu     $v0, $v0, 1
/* C79E4C 8024316C AE420028 */  sw        $v0, 0x28($s2)
.L80243170:
glabel L80243170_C79E50
/* C79E50 80243170 0000102D */  daddu     $v0, $zero, $zero
.L80243174:
/* C79E54 80243174 8FBF0068 */  lw        $ra, 0x68($sp)
/* C79E58 80243178 8FB50064 */  lw        $s5, 0x64($sp)
/* C79E5C 8024317C 8FB40060 */  lw        $s4, 0x60($sp)
/* C79E60 80243180 8FB3005C */  lw        $s3, 0x5c($sp)
/* C79E64 80243184 8FB20058 */  lw        $s2, 0x58($sp)
/* C79E68 80243188 8FB10054 */  lw        $s1, 0x54($sp)
/* C79E6C 8024318C 8FB00050 */  lw        $s0, 0x50($sp)
/* C79E70 80243190 03E00008 */  jr        $ra
/* C79E74 80243194 27BD0070 */   addiu    $sp, $sp, 0x70

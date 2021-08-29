.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80242C58_91B808
.word L80241144_919CF4, L80241154_919D04, L80241174_919D24, L80241194_919D44, L802411B4_919D64, L802411C4_919D74, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802411DC_919D8C, L802411FC_919DAC, L8024121C_919DCC, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L80241240_919DF0, L80241250_919E00, L80241268_919E18, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L80241280_919E30, L802412A0_919E50, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412F8_919EA8, L802412B8_919E68, L802412C8_919E78, L802412E8_919E98, 0

.section .text

glabel func_80240FD0_919B80
/* 919B80 80240FD0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 919B84 80240FD4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 919B88 80240FD8 0080982D */  daddu     $s3, $a0, $zero
/* 919B8C 80240FDC AFBF0048 */  sw        $ra, 0x48($sp)
/* 919B90 80240FE0 AFB50044 */  sw        $s5, 0x44($sp)
/* 919B94 80240FE4 AFB40040 */  sw        $s4, 0x40($sp)
/* 919B98 80240FE8 AFB20038 */  sw        $s2, 0x38($sp)
/* 919B9C 80240FEC AFB10034 */  sw        $s1, 0x34($sp)
/* 919BA0 80240FF0 AFB00030 */  sw        $s0, 0x30($sp)
/* 919BA4 80240FF4 8E720148 */  lw        $s2, 0x148($s3)
/* 919BA8 80240FF8 86440008 */  lh        $a0, 8($s2)
/* 919BAC 80240FFC 0C00EABB */  jal       get_npc_unsafe
/* 919BB0 80241000 00A0882D */   daddu    $s1, $a1, $zero
/* 919BB4 80241004 0260202D */  daddu     $a0, $s3, $zero
/* 919BB8 80241008 8E70000C */  lw        $s0, 0xc($s3)
/* 919BBC 8024100C 0040A82D */  daddu     $s5, $v0, $zero
/* 919BC0 80241010 8E050000 */  lw        $a1, ($s0)
/* 919BC4 80241014 0C0B1EAF */  jal       evt_get_variable
/* 919BC8 80241018 26100004 */   addiu    $s0, $s0, 4
/* 919BCC 8024101C 0260202D */  daddu     $a0, $s3, $zero
/* 919BD0 80241020 8E050000 */  lw        $a1, ($s0)
/* 919BD4 80241024 0C0B1EAF */  jal       evt_get_variable
/* 919BD8 80241028 0040A02D */   daddu    $s4, $v0, $zero
/* 919BDC 8024102C AE420094 */  sw        $v0, 0x94($s2)
/* 919BE0 80241030 AFA00010 */  sw        $zero, 0x10($sp)
/* 919BE4 80241034 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 919BE8 80241038 8C420030 */  lw        $v0, 0x30($v0)
/* 919BEC 8024103C AFA20014 */  sw        $v0, 0x14($sp)
/* 919BF0 80241040 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 919BF4 80241044 8C42001C */  lw        $v0, 0x1c($v0)
/* 919BF8 80241048 AFA20018 */  sw        $v0, 0x18($sp)
/* 919BFC 8024104C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 919C00 80241050 8C420024 */  lw        $v0, 0x24($v0)
/* 919C04 80241054 AFA2001C */  sw        $v0, 0x1c($sp)
/* 919C08 80241058 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 919C0C 8024105C 8C420028 */  lw        $v0, 0x28($v0)
/* 919C10 80241060 AFA20020 */  sw        $v0, 0x20($sp)
/* 919C14 80241064 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 919C18 80241068 3C014220 */  lui       $at, 0x4220
/* 919C1C 8024106C 44810000 */  mtc1      $at, $f0
/* 919C20 80241070 8C42002C */  lw        $v0, 0x2c($v0)
/* 919C24 80241074 27B00010 */  addiu     $s0, $sp, 0x10
/* 919C28 80241078 E7A00028 */  swc1      $f0, 0x28($sp)
/* 919C2C 8024107C A7A0002C */  sh        $zero, 0x2c($sp)
/* 919C30 80241080 12200012 */  beqz      $s1, .L802410CC
/* 919C34 80241084 AFA20024 */   sw       $v0, 0x24($sp)
/* 919C38 80241088 AE600070 */  sw        $zero, 0x70($s3)
/* 919C3C 8024108C 8EA30000 */  lw        $v1, ($s5)
/* 919C40 80241090 2402F7FF */  addiu     $v0, $zero, -0x801
/* 919C44 80241094 A6A0008E */  sh        $zero, 0x8e($s5)
/* 919C48 80241098 00621824 */  and       $v1, $v1, $v0
/* 919C4C 8024109C AEA30000 */  sw        $v1, ($s5)
/* 919C50 802410A0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 919C54 802410A4 8C420034 */  lw        $v0, 0x34($v0)
/* 919C58 802410A8 54400005 */  bnel      $v0, $zero, .L802410C0
/* 919C5C 802410AC 2402FDFF */   addiu    $v0, $zero, -0x201
/* 919C60 802410B0 34620200 */  ori       $v0, $v1, 0x200
/* 919C64 802410B4 2403FFF7 */  addiu     $v1, $zero, -9
/* 919C68 802410B8 08090432 */  j         .L802410C8
/* 919C6C 802410BC 00431024 */   and      $v0, $v0, $v1
.L802410C0:
/* 919C70 802410C0 00621024 */  and       $v0, $v1, $v0
/* 919C74 802410C4 34420008 */  ori       $v0, $v0, 8
.L802410C8:
/* 919C78 802410C8 AEA20000 */  sw        $v0, ($s5)
.L802410CC:
/* 919C7C 802410CC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 919C80 802410D0 30620004 */  andi      $v0, $v1, 4
/* 919C84 802410D4 10400007 */  beqz      $v0, .L802410F4
/* 919C88 802410D8 00000000 */   nop
/* 919C8C 802410DC 824200B4 */  lb        $v0, 0xb4($s2)
/* 919C90 802410E0 14400086 */  bnez      $v0, .L802412FC
/* 919C94 802410E4 0000102D */   daddu    $v0, $zero, $zero
/* 919C98 802410E8 2402FFFB */  addiu     $v0, $zero, -5
/* 919C9C 802410EC 00621024 */  and       $v0, $v1, $v0
/* 919CA0 802410F0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802410F4:
/* 919CA4 802410F4 8E620070 */  lw        $v0, 0x70($s3)
/* 919CA8 802410F8 2442FFF4 */  addiu     $v0, $v0, -0xc
/* 919CAC 802410FC 2C420003 */  sltiu     $v0, $v0, 3
/* 919CB0 80241100 10400007 */  beqz      $v0, .L80241120
/* 919CB4 80241104 0260202D */   daddu    $a0, $s3, $zero
/* 919CB8 80241108 0280282D */  daddu     $a1, $s4, $zero
/* 919CBC 8024110C 0C0900D0 */  jal       func_80240340_918EF0
/* 919CC0 80241110 0200302D */   daddu    $a2, $s0, $zero
/* 919CC4 80241114 10400002 */  beqz      $v0, .L80241120
/* 919CC8 80241118 24020014 */   addiu    $v0, $zero, 0x14
/* 919CCC 8024111C AE620070 */  sw        $v0, 0x70($s3)
.L80241120:
/* 919CD0 80241120 8E630070 */  lw        $v1, 0x70($s3)
/* 919CD4 80241124 2C620035 */  sltiu     $v0, $v1, 0x35
/* 919CD8 80241128 10400073 */  beqz      $v0, L802412F8_919EA8
/* 919CDC 8024112C 00031080 */   sll      $v0, $v1, 2
/* 919CE0 80241130 3C018024 */  lui       $at, %hi(jtbl_80242C58_91B808)
/* 919CE4 80241134 00220821 */  addu      $at, $at, $v0
/* 919CE8 80241138 8C222C58 */  lw        $v0, %lo(jtbl_80242C58_91B808)($at)
/* 919CEC 8024113C 00400008 */  jr        $v0
/* 919CF0 80241140 00000000 */   nop
glabel L80241144_919CF4
/* 919CF4 80241144 0260202D */  daddu     $a0, $s3, $zero
/* 919CF8 80241148 0280282D */  daddu     $a1, $s4, $zero
/* 919CFC 8024114C 0C090128 */  jal       iwa_03_UnkNpcAIFunc18
/* 919D00 80241150 0200302D */   daddu    $a2, $s0, $zero
glabel L80241154_919D04
/* 919D04 80241154 0260202D */  daddu     $a0, $s3, $zero
/* 919D08 80241158 0280282D */  daddu     $a1, $s4, $zero
/* 919D0C 8024115C 0C090145 */  jal       func_80240514_9190C4
/* 919D10 80241160 0200302D */   daddu    $a2, $s0, $zero
/* 919D14 80241164 8E630070 */  lw        $v1, 0x70($s3)
/* 919D18 80241168 24020002 */  addiu     $v0, $zero, 2
/* 919D1C 8024116C 14620063 */  bne       $v1, $v0, .L802412FC
/* 919D20 80241170 0000102D */   daddu    $v0, $zero, $zero
glabel L80241174_919D24
/* 919D24 80241174 0260202D */  daddu     $a0, $s3, $zero
/* 919D28 80241178 0280282D */  daddu     $a1, $s4, $zero
/* 919D2C 8024117C 0C090191 */  jal       iwa_03_UnkNpcAIFunc21
/* 919D30 80241180 0200302D */   daddu    $a2, $s0, $zero
/* 919D34 80241184 8E630070 */  lw        $v1, 0x70($s3)
/* 919D38 80241188 24020003 */  addiu     $v0, $zero, 3
/* 919D3C 8024118C 1462005B */  bne       $v1, $v0, .L802412FC
/* 919D40 80241190 0000102D */   daddu    $v0, $zero, $zero
glabel L80241194_919D44
/* 919D44 80241194 0260202D */  daddu     $a0, $s3, $zero
/* 919D48 80241198 0280282D */  daddu     $a1, $s4, $zero
/* 919D4C 8024119C 0C0901B8 */  jal       iwa_03_UnkNpcAIFunc20
/* 919D50 802411A0 0200302D */   daddu    $a2, $s0, $zero
/* 919D54 802411A4 8E630070 */  lw        $v1, 0x70($s3)
/* 919D58 802411A8 24020004 */  addiu     $v0, $zero, 4
/* 919D5C 802411AC 14620053 */  bne       $v1, $v0, .L802412FC
/* 919D60 802411B0 0000102D */   daddu    $v0, $zero, $zero
glabel L802411B4_919D64
/* 919D64 802411B4 0260202D */  daddu     $a0, $s3, $zero
/* 919D68 802411B8 0280282D */  daddu     $a1, $s4, $zero
/* 919D6C 802411BC 0C0901DA */  jal       iwa_03_UnkNpcAIFunc22
/* 919D70 802411C0 0200302D */   daddu    $a2, $s0, $zero
glabel L802411C4_919D74
/* 919D74 802411C4 0260202D */  daddu     $a0, $s3, $zero
/* 919D78 802411C8 0280282D */  daddu     $a1, $s4, $zero
/* 919D7C 802411CC 0C090204 */  jal       iwa_03_UnkFunc8
/* 919D80 802411D0 0200302D */   daddu    $a2, $s0, $zero
/* 919D84 802411D4 080904BF */  j         .L802412FC
/* 919D88 802411D8 0000102D */   daddu    $v0, $zero, $zero
glabel L802411DC_919D8C
/* 919D8C 802411DC 0260202D */  daddu     $a0, $s3, $zero
/* 919D90 802411E0 0280282D */  daddu     $a1, $s4, $zero
/* 919D94 802411E4 0C0127DF */  jal       func_80049F7C
/* 919D98 802411E8 0200302D */   daddu    $a2, $s0, $zero
/* 919D9C 802411EC 8E630070 */  lw        $v1, 0x70($s3)
/* 919DA0 802411F0 2402000D */  addiu     $v0, $zero, 0xd
/* 919DA4 802411F4 14620041 */  bne       $v1, $v0, .L802412FC
/* 919DA8 802411F8 0000102D */   daddu    $v0, $zero, $zero
glabel L802411FC_919DAC
/* 919DAC 802411FC 0260202D */  daddu     $a0, $s3, $zero
/* 919DB0 80241200 0280282D */  daddu     $a1, $s4, $zero
/* 919DB4 80241204 0C012849 */  jal       func_8004A124
/* 919DB8 80241208 0200302D */   daddu    $a2, $s0, $zero
/* 919DBC 8024120C 8E630070 */  lw        $v1, 0x70($s3)
/* 919DC0 80241210 2402000E */  addiu     $v0, $zero, 0xe
/* 919DC4 80241214 14620039 */  bne       $v1, $v0, .L802412FC
/* 919DC8 80241218 0000102D */   daddu    $v0, $zero, $zero
glabel L8024121C_919DCC
/* 919DCC 8024121C 96A2008E */  lhu       $v0, 0x8e($s5)
/* 919DD0 80241220 2442FFFF */  addiu     $v0, $v0, -1
/* 919DD4 80241224 A6A2008E */  sh        $v0, 0x8e($s5)
/* 919DD8 80241228 00021400 */  sll       $v0, $v0, 0x10
/* 919DDC 8024122C 14400033 */  bnez      $v0, .L802412FC
/* 919DE0 80241230 0000102D */   daddu    $v0, $zero, $zero
/* 919DE4 80241234 24020028 */  addiu     $v0, $zero, 0x28
/* 919DE8 80241238 080904BE */  j         L802412F8_919EA8
/* 919DEC 8024123C AE620070 */   sw       $v0, 0x70($s3)
glabel L80241240_919DF0
/* 919DF0 80241240 0260202D */  daddu     $a0, $s3, $zero
/* 919DF4 80241244 0280282D */  daddu     $a1, $s4, $zero
/* 919DF8 80241248 0C090261 */  jal       iwa_03_UnkNpcAIFunc16
/* 919DFC 8024124C 0200302D */   daddu    $a2, $s0, $zero
glabel L80241250_919E00
/* 919E00 80241250 0260202D */  daddu     $a0, $s3, $zero
/* 919E04 80241254 0280282D */  daddu     $a1, $s4, $zero
/* 919E08 80241258 0C090275 */  jal       func_802409D4_919584
/* 919E0C 8024125C 0200302D */   daddu    $a2, $s0, $zero
/* 919E10 80241260 080904BF */  j         .L802412FC
/* 919E14 80241264 0000102D */   daddu    $v0, $zero, $zero
glabel L80241268_919E18
/* 919E18 80241268 0260202D */  daddu     $a0, $s3, $zero
/* 919E1C 8024126C 0280282D */  daddu     $a1, $s4, $zero
/* 919E20 80241270 0C0902DD */  jal       iwa_03_UnkFunc10
/* 919E24 80241274 0200302D */   daddu    $a2, $s0, $zero
/* 919E28 80241278 080904BF */  j         .L802412FC
/* 919E2C 8024127C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241280_919E30
/* 919E30 80241280 0260202D */  daddu     $a0, $s3, $zero
/* 919E34 80241284 0280282D */  daddu     $a1, $s4, $zero
/* 919E38 80241288 0C090331 */  jal       func_80240CC4_919874
/* 919E3C 8024128C 0200302D */   daddu    $a2, $s0, $zero
/* 919E40 80241290 8E630070 */  lw        $v1, 0x70($s3)
/* 919E44 80241294 24020029 */  addiu     $v0, $zero, 0x29
/* 919E48 80241298 14620018 */  bne       $v1, $v0, .L802412FC
/* 919E4C 8024129C 0000102D */   daddu    $v0, $zero, $zero
glabel L802412A0_919E50
/* 919E50 802412A0 0260202D */  daddu     $a0, $s3, $zero
/* 919E54 802412A4 0280282D */  daddu     $a1, $s4, $zero
/* 919E58 802412A8 0C09035C */  jal       iwa_03_UnkFunc9
/* 919E5C 802412AC 0200302D */   daddu    $a2, $s0, $zero
/* 919E60 802412B0 080904BF */  j         .L802412FC
/* 919E64 802412B4 0000102D */   daddu    $v0, $zero, $zero
glabel L802412B8_919E68
/* 919E68 802412B8 0260202D */  daddu     $a0, $s3, $zero
/* 919E6C 802412BC 0280282D */  daddu     $a1, $s4, $zero
/* 919E70 802412C0 0C0903AA */  jal       iwa_03_UnkNpcAIFunc19
/* 919E74 802412C4 0200302D */   daddu    $a2, $s0, $zero
glabel L802412C8_919E78
/* 919E78 802412C8 0260202D */  daddu     $a0, $s3, $zero
/* 919E7C 802412CC 0280282D */  daddu     $a1, $s4, $zero
/* 919E80 802412D0 0C0903C9 */  jal       iwa_03_UnkNpcAIFunc17
/* 919E84 802412D4 0200302D */   daddu    $a2, $s0, $zero
/* 919E88 802412D8 8E630070 */  lw        $v1, 0x70($s3)
/* 919E8C 802412DC 24020034 */  addiu     $v0, $zero, 0x34
/* 919E90 802412E0 14620006 */  bne       $v1, $v0, .L802412FC
/* 919E94 802412E4 0000102D */   daddu    $v0, $zero, $zero
glabel L802412E8_919E98
/* 919E98 802412E8 0260202D */  daddu     $a0, $s3, $zero
/* 919E9C 802412EC 0280282D */  daddu     $a1, $s4, $zero
/* 919EA0 802412F0 0C0903E3 */  jal       iwa_03_UnkDurationCheck
/* 919EA4 802412F4 0200302D */   daddu    $a2, $s0, $zero
glabel L802412F8_919EA8
/* 919EA8 802412F8 0000102D */  daddu     $v0, $zero, $zero
.L802412FC:
/* 919EAC 802412FC 8FBF0048 */  lw        $ra, 0x48($sp)
/* 919EB0 80241300 8FB50044 */  lw        $s5, 0x44($sp)
/* 919EB4 80241304 8FB40040 */  lw        $s4, 0x40($sp)
/* 919EB8 80241308 8FB3003C */  lw        $s3, 0x3c($sp)
/* 919EBC 8024130C 8FB20038 */  lw        $s2, 0x38($sp)
/* 919EC0 80241310 8FB10034 */  lw        $s1, 0x34($sp)
/* 919EC4 80241314 8FB00030 */  lw        $s0, 0x30($sp)
/* 919EC8 80241318 03E00008 */  jr        $ra
/* 919ECC 8024131C 27BD0050 */   addiu    $sp, $sp, 0x50

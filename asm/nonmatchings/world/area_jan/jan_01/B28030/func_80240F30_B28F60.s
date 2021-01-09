.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F30_B28F60
/* B28F60 80240F30 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B28F64 80240F34 AFB3003C */  sw        $s3, 0x3c($sp)
/* B28F68 80240F38 0080982D */  daddu     $s3, $a0, $zero
/* B28F6C 80240F3C AFBF0048 */  sw        $ra, 0x48($sp)
/* B28F70 80240F40 AFB50044 */  sw        $s5, 0x44($sp)
/* B28F74 80240F44 AFB40040 */  sw        $s4, 0x40($sp)
/* B28F78 80240F48 AFB20038 */  sw        $s2, 0x38($sp)
/* B28F7C 80240F4C AFB10034 */  sw        $s1, 0x34($sp)
/* B28F80 80240F50 AFB00030 */  sw        $s0, 0x30($sp)
/* B28F84 80240F54 8E720148 */  lw        $s2, 0x148($s3)
/* B28F88 80240F58 86440008 */  lh        $a0, 8($s2)
/* B28F8C 80240F5C 8E70000C */  lw        $s0, 0xc($s3)
/* B28F90 80240F60 0C00EABB */  jal       get_npc_unsafe
/* B28F94 80240F64 00A0882D */   daddu    $s1, $a1, $zero
/* B28F98 80240F68 8E050000 */  lw        $a1, ($s0)
/* B28F9C 80240F6C 26100004 */  addiu     $s0, $s0, 4
/* B28FA0 80240F70 0260202D */  daddu     $a0, $s3, $zero
/* B28FA4 80240F74 0C0B1EAF */  jal       get_variable
/* B28FA8 80240F78 0040A82D */   daddu    $s5, $v0, $zero
/* B28FAC 80240F7C 0260202D */  daddu     $a0, $s3, $zero
/* B28FB0 80240F80 8E050000 */  lw        $a1, ($s0)
/* B28FB4 80240F84 0C0B1EAF */  jal       get_variable
/* B28FB8 80240F88 0040A02D */   daddu    $s4, $v0, $zero
/* B28FBC 80240F8C AE420094 */  sw        $v0, 0x94($s2)
/* B28FC0 80240F90 AFA00010 */  sw        $zero, 0x10($sp)
/* B28FC4 80240F94 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B28FC8 80240F98 8C420030 */  lw        $v0, 0x30($v0)
/* B28FCC 80240F9C AFA20014 */  sw        $v0, 0x14($sp)
/* B28FD0 80240FA0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B28FD4 80240FA4 8C42001C */  lw        $v0, 0x1c($v0)
/* B28FD8 80240FA8 AFA20018 */  sw        $v0, 0x18($sp)
/* B28FDC 80240FAC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B28FE0 80240FB0 8C420024 */  lw        $v0, 0x24($v0)
/* B28FE4 80240FB4 AFA2001C */  sw        $v0, 0x1c($sp)
/* B28FE8 80240FB8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B28FEC 80240FBC 8C420028 */  lw        $v0, 0x28($v0)
/* B28FF0 80240FC0 AFA20020 */  sw        $v0, 0x20($sp)
/* B28FF4 80240FC4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B28FF8 80240FC8 3C0142C8 */  lui       $at, 0x42c8
/* B28FFC 80240FCC 44810000 */  mtc1      $at, $f0
/* B29000 80240FD0 8C42002C */  lw        $v0, 0x2c($v0)
/* B29004 80240FD4 27B00010 */  addiu     $s0, $sp, 0x10
/* B29008 80240FD8 E7A00028 */  swc1      $f0, 0x28($sp)
/* B2900C 80240FDC A7A0002C */  sh        $zero, 0x2c($sp)
/* B29010 80240FE0 12200019 */  beqz      $s1, .L80241048
/* B29014 80240FE4 AFA20024 */   sw       $v0, 0x24($sp)
/* B29018 80240FE8 AE600070 */  sw        $zero, 0x70($s3)
/* B2901C 80240FEC A6A0008E */  sh        $zero, 0x8e($s5)
/* B29020 80240FF0 AE600074 */  sw        $zero, 0x74($s3)
/* B29024 80240FF4 8EA20000 */  lw        $v0, ($s5)
/* B29028 80240FF8 2403F7FF */  addiu     $v1, $zero, -0x801
/* B2902C 80240FFC 00431024 */  and       $v0, $v0, $v1
/* B29030 80241000 2403FDFF */  addiu     $v1, $zero, -0x201
/* B29034 80241004 00431024 */  and       $v0, $v0, $v1
/* B29038 80241008 34420008 */  ori       $v0, $v0, 8
/* B2903C 8024100C AEA20000 */  sw        $v0, ($s5)
/* B29040 80241010 8E4200B0 */  lw        $v0, 0xb0($s2)
/* B29044 80241014 34420018 */  ori       $v0, $v0, 0x18
/* B29048 80241018 AE4200B0 */  sw        $v0, 0xb0($s2)
/* B2904C 8024101C 8E420000 */  lw        $v0, ($s2)
/* B29050 80241020 3C034000 */  lui       $v1, 0x4000
/* B29054 80241024 00431024 */  and       $v0, $v0, $v1
/* B29058 80241028 10400007 */  beqz      $v0, .L80241048
/* B2905C 8024102C 3C03BFFF */   lui      $v1, 0xbfff
/* B29060 80241030 2402000C */  addiu     $v0, $zero, 0xc
/* B29064 80241034 AE620070 */  sw        $v0, 0x70($s3)
/* B29068 80241038 8E420000 */  lw        $v0, ($s2)
/* B2906C 8024103C 3463FFFF */  ori       $v1, $v1, 0xffff
/* B29070 80241040 00431024 */  and       $v0, $v0, $v1
/* B29074 80241044 AE420000 */  sw        $v0, ($s2)
.L80241048:
/* B29078 80241048 8E4300B0 */  lw        $v1, 0xb0($s2)
/* B2907C 8024104C 30620004 */  andi      $v0, $v1, 4
/* B29080 80241050 10400007 */  beqz      $v0, .L80241070
/* B29084 80241054 00000000 */   nop      
/* B29088 80241058 824200B4 */  lb        $v0, 0xb4($s2)
/* B2908C 8024105C 14400034 */  bnez      $v0, .L80241130
/* B29090 80241060 0000102D */   daddu    $v0, $zero, $zero
/* B29094 80241064 2402FFFB */  addiu     $v0, $zero, -5
/* B29098 80241068 00621024 */  and       $v0, $v1, $v0
/* B2909C 8024106C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241070:
/* B290A0 80241070 8E630070 */  lw        $v1, 0x70($s3)
/* B290A4 80241074 2C62000F */  sltiu     $v0, $v1, 0xf
/* B290A8 80241078 1040002C */  beqz      $v0, .L8024112C
/* B290AC 8024107C 00031080 */   sll      $v0, $v1, 2
/* B290B0 80241080 3C018024 */  lui       $at, %hi(D_802443F8)
/* B290B4 80241084 00220821 */  addu      $at, $at, $v0
/* B290B8 80241088 8C2243F8 */  lw        $v0, %lo(D_802443F8)($at)
/* B290BC 8024108C 00400008 */  jr        $v0
/* B290C0 80241090 00000000 */   nop      
/* B290C4 80241094 0260202D */  daddu     $a0, $s3, $zero
/* B290C8 80241098 0280282D */  daddu     $a1, $s4, $zero
/* B290CC 8024109C 0C0900D0 */  jal       func_80240340_B28370
/* B290D0 802410A0 0200302D */   daddu    $a2, $s0, $zero
/* B290D4 802410A4 0260202D */  daddu     $a0, $s3, $zero
/* B290D8 802410A8 0280282D */  daddu     $a1, $s4, $zero
/* B290DC 802410AC 0C09015C */  jal       func_80240570_B285A0
/* B290E0 802410B0 0200302D */   daddu    $a2, $s0, $zero
/* B290E4 802410B4 0809044C */  j         .L80241130
/* B290E8 802410B8 0000102D */   daddu    $v0, $zero, $zero
/* B290EC 802410BC 0260202D */  daddu     $a0, $s3, $zero
/* B290F0 802410C0 0280282D */  daddu     $a1, $s4, $zero
/* B290F4 802410C4 0C09022A */  jal       func_802408A8_B288D8
/* B290F8 802410C8 0200302D */   daddu    $a2, $s0, $zero
/* B290FC 802410CC 8E630070 */  lw        $v1, 0x70($s3)
/* B29100 802410D0 24020003 */  addiu     $v0, $zero, 3
/* B29104 802410D4 14620016 */  bne       $v1, $v0, .L80241130
/* B29108 802410D8 0000102D */   daddu    $v0, $zero, $zero
/* B2910C 802410DC 0260202D */  daddu     $a0, $s3, $zero
/* B29110 802410E0 0280282D */  daddu     $a1, $s4, $zero
/* B29114 802410E4 0C09025A */  jal       func_80240968_B28998
/* B29118 802410E8 0200302D */   daddu    $a2, $s0, $zero
/* B2911C 802410EC 0809044C */  j         .L80241130
/* B29120 802410F0 0000102D */   daddu    $v0, $zero, $zero
/* B29124 802410F4 0260202D */  daddu     $a0, $s3, $zero
/* B29128 802410F8 0280282D */  daddu     $a1, $s4, $zero
/* B2912C 802410FC 0C0902C3 */  jal       func_80240B0C_B28B3C
/* B29130 80241100 0200302D */   daddu    $a2, $s0, $zero
/* B29134 80241104 0260202D */  daddu     $a0, $s3, $zero
/* B29138 80241108 0280282D */  daddu     $a1, $s4, $zero
/* B2913C 8024110C 0C0902FB */  jal       func_80240BEC_B28C1C
/* B29140 80241110 0200302D */   daddu    $a2, $s0, $zero
/* B29144 80241114 0809044C */  j         .L80241130
/* B29148 80241118 0000102D */   daddu    $v0, $zero, $zero
/* B2914C 8024111C 0260202D */  daddu     $a0, $s3, $zero
/* B29150 80241120 0280282D */  daddu     $a1, $s4, $zero
/* B29154 80241124 0C0903BB */  jal       func_80240EEC_B28F1C
/* B29158 80241128 0200302D */   daddu    $a2, $s0, $zero
.L8024112C:
/* B2915C 8024112C 0000102D */  daddu     $v0, $zero, $zero
.L80241130:
/* B29160 80241130 8FBF0048 */  lw        $ra, 0x48($sp)
/* B29164 80241134 8FB50044 */  lw        $s5, 0x44($sp)
/* B29168 80241138 8FB40040 */  lw        $s4, 0x40($sp)
/* B2916C 8024113C 8FB3003C */  lw        $s3, 0x3c($sp)
/* B29170 80241140 8FB20038 */  lw        $s2, 0x38($sp)
/* B29174 80241144 8FB10034 */  lw        $s1, 0x34($sp)
/* B29178 80241148 8FB00030 */  lw        $s0, 0x30($sp)
/* B2917C 8024114C 03E00008 */  jr        $ra
/* B29180 80241150 27BD0050 */   addiu    $sp, $sp, 0x50

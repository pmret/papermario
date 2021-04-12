.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024215C_CD3F8C
/* CD3F8C 8024215C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CD3F90 80242160 AFB40040 */  sw        $s4, 0x40($sp)
/* CD3F94 80242164 0080A02D */  daddu     $s4, $a0, $zero
/* CD3F98 80242168 AFBF0048 */  sw        $ra, 0x48($sp)
/* CD3F9C 8024216C AFB50044 */  sw        $s5, 0x44($sp)
/* CD3FA0 80242170 AFB3003C */  sw        $s3, 0x3c($sp)
/* CD3FA4 80242174 AFB20038 */  sw        $s2, 0x38($sp)
/* CD3FA8 80242178 AFB10034 */  sw        $s1, 0x34($sp)
/* CD3FAC 8024217C AFB00030 */  sw        $s0, 0x30($sp)
/* CD3FB0 80242180 8E920148 */  lw        $s2, 0x148($s4)
/* CD3FB4 80242184 86440008 */  lh        $a0, 8($s2)
/* CD3FB8 80242188 8E90000C */  lw        $s0, 0xc($s4)
/* CD3FBC 8024218C 0C00EABB */  jal       get_npc_unsafe
/* CD3FC0 80242190 00A0882D */   daddu    $s1, $a1, $zero
/* CD3FC4 80242194 0280202D */  daddu     $a0, $s4, $zero
/* CD3FC8 80242198 8E050000 */  lw        $a1, ($s0)
/* CD3FCC 8024219C 0C0B1EAF */  jal       get_variable
/* CD3FD0 802421A0 0040A82D */   daddu    $s5, $v0, $zero
/* CD3FD4 802421A4 AFA00010 */  sw        $zero, 0x10($sp)
/* CD3FD8 802421A8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD3FDC 802421AC 8C630030 */  lw        $v1, 0x30($v1)
/* CD3FE0 802421B0 AFA30014 */  sw        $v1, 0x14($sp)
/* CD3FE4 802421B4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD3FE8 802421B8 8C63001C */  lw        $v1, 0x1c($v1)
/* CD3FEC 802421BC AFA30018 */  sw        $v1, 0x18($sp)
/* CD3FF0 802421C0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD3FF4 802421C4 8C630024 */  lw        $v1, 0x24($v1)
/* CD3FF8 802421C8 AFA3001C */  sw        $v1, 0x1c($sp)
/* CD3FFC 802421CC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD4000 802421D0 8C630028 */  lw        $v1, 0x28($v1)
/* CD4004 802421D4 27B30010 */  addiu     $s3, $sp, 0x10
/* CD4008 802421D8 AFA30020 */  sw        $v1, 0x20($sp)
/* CD400C 802421DC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CD4010 802421E0 3C0142F0 */  lui       $at, 0x42f0
/* CD4014 802421E4 44810000 */  mtc1      $at, $f0
/* CD4018 802421E8 8C63002C */  lw        $v1, 0x2c($v1)
/* CD401C 802421EC 0040802D */  daddu     $s0, $v0, $zero
/* CD4020 802421F0 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD4024 802421F4 A7A0002C */  sh        $zero, 0x2c($sp)
/* CD4028 802421F8 12200006 */  beqz      $s1, .L80242214
/* CD402C 802421FC AFA30024 */   sw       $v1, 0x24($sp)
/* CD4030 80242200 02A0202D */  daddu     $a0, $s5, $zero
/* CD4034 80242204 0240282D */  daddu     $a1, $s2, $zero
/* CD4038 80242208 0280302D */  daddu     $a2, $s4, $zero
/* CD403C 8024220C 0C09080E */  jal       flo_16_UnkFunc5
/* CD4040 80242210 0200382D */   daddu    $a3, $s0, $zero
.L80242214:
/* CD4044 80242214 2402FFFE */  addiu     $v0, $zero, -2
/* CD4048 80242218 A2A200AB */  sb        $v0, 0xab($s5)
/* CD404C 8024221C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CD4050 80242220 30620004 */  andi      $v0, $v1, 4
/* CD4054 80242224 10400007 */  beqz      $v0, .L80242244
/* CD4058 80242228 00000000 */   nop
/* CD405C 8024222C 824200B4 */  lb        $v0, 0xb4($s2)
/* CD4060 80242230 1440003C */  bnez      $v0, .L80242324
/* CD4064 80242234 0000102D */   daddu    $v0, $zero, $zero
/* CD4068 80242238 2402FFFB */  addiu     $v0, $zero, -5
/* CD406C 8024223C 00621024 */  and       $v0, $v1, $v0
/* CD4070 80242240 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242244:
/* CD4074 80242244 8E830070 */  lw        $v1, 0x70($s4)
/* CD4078 80242248 2C62000F */  sltiu     $v0, $v1, 0xf
/* CD407C 8024224C 10400034 */  beqz      $v0, L80242320_CD4150
/* CD4080 80242250 00031080 */   sll      $v0, $v1, 2
/* CD4084 80242254 3C018024 */  lui       $at, %hi(jtbl_80245408_CD7238)
/* CD4088 80242258 00220821 */  addu      $at, $at, $v0
/* CD408C 8024225C 8C225408 */  lw        $v0, %lo(jtbl_80245408_CD7238)($at)
/* CD4090 80242260 00400008 */  jr        $v0
/* CD4094 80242264 00000000 */   nop
glabel L80242268_CD4098
/* CD4098 80242268 0280202D */  daddu     $a0, $s4, $zero
/* CD409C 8024226C 0200282D */  daddu     $a1, $s0, $zero
/* CD40A0 80242270 0C090394 */  jal       func_80240E50_CD2C80
/* CD40A4 80242274 0260302D */   daddu    $a2, $s3, $zero
glabel L80242278_CD40A8
/* CD40A8 80242278 0280202D */  daddu     $a0, $s4, $zero
/* CD40AC 8024227C 0200282D */  daddu     $a1, $s0, $zero
/* CD40B0 80242280 0C090400 */  jal       func_80241000_CD2E30
/* CD40B4 80242284 0260302D */   daddu    $a2, $s3, $zero
/* CD40B8 80242288 080908C9 */  j         .L80242324
/* CD40BC 8024228C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242290_CD40C0
/* CD40C0 80242290 0280202D */  daddu     $a0, $s4, $zero
/* CD40C4 80242294 0200282D */  daddu     $a1, $s0, $zero
/* CD40C8 80242298 0C09058A */  jal       flo_16_UnkNpcAIFunc1
/* CD40CC 8024229C 0260302D */   daddu    $a2, $s3, $zero
glabel L802422A0_CD40D0
/* CD40D0 802422A0 0280202D */  daddu     $a0, $s4, $zero
/* CD40D4 802422A4 0200282D */  daddu     $a1, $s0, $zero
/* CD40D8 802422A8 0C0905BA */  jal       flo_16_UnkFunc4
/* CD40DC 802422AC 0260302D */   daddu    $a2, $s3, $zero
/* CD40E0 802422B0 080908C9 */  j         .L80242324
/* CD40E4 802422B4 0000102D */   daddu    $v0, $zero, $zero
glabel L802422B8_CD40E8
/* CD40E8 802422B8 0280202D */  daddu     $a0, $s4, $zero
/* CD40EC 802422BC 0200282D */  daddu     $a1, $s0, $zero
/* CD40F0 802422C0 0C09068B */  jal       flo_16_UnkNpcAIFunc2
/* CD40F4 802422C4 0260302D */   daddu    $a2, $s3, $zero
glabel L802422C8_CD40F8
/* CD40F8 802422C8 0280202D */  daddu     $a0, $s4, $zero
/* CD40FC 802422CC 0200282D */  daddu     $a1, $s0, $zero
/* CD4100 802422D0 0C0906A9 */  jal       func_80241AA4_CD38D4
/* CD4104 802422D4 0260302D */   daddu    $a2, $s3, $zero
/* CD4108 802422D8 080908C9 */  j         .L80242324
/* CD410C 802422DC 0000102D */   daddu    $v0, $zero, $zero
glabel L802422E0_CD4110
/* CD4110 802422E0 0280202D */  daddu     $a0, $s4, $zero
/* CD4114 802422E4 0200282D */  daddu     $a1, $s0, $zero
/* CD4118 802422E8 0C0906C4 */  jal       flo_16_UnkNpcAIFunc14
/* CD411C 802422EC 0260302D */   daddu    $a2, $s3, $zero
/* CD4120 802422F0 080908C9 */  j         .L80242324
/* CD4124 802422F4 0000102D */   daddu    $v0, $zero, $zero
glabel L802422F8_CD4128
/* CD4128 802422F8 0280202D */  daddu     $a0, $s4, $zero
/* CD412C 802422FC 0200282D */  daddu     $a1, $s0, $zero
/* CD4130 80242300 0C090711 */  jal       flo_16_UnkNpcAIFunc3
/* CD4134 80242304 0260302D */   daddu    $a2, $s3, $zero
/* CD4138 80242308 080908C9 */  j         .L80242324
/* CD413C 8024230C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242310_CD4140
/* CD4140 80242310 0280202D */  daddu     $a0, $s4, $zero
/* CD4144 80242314 0200282D */  daddu     $a1, $s0, $zero
/* CD4148 80242318 0C09072A */  jal       flo_16_UnkFunc6
/* CD414C 8024231C 0260302D */   daddu    $a2, $s3, $zero
glabel L80242320_CD4150
/* CD4150 80242320 0000102D */  daddu     $v0, $zero, $zero
.L80242324:
/* CD4154 80242324 8FBF0048 */  lw        $ra, 0x48($sp)
/* CD4158 80242328 8FB50044 */  lw        $s5, 0x44($sp)
/* CD415C 8024232C 8FB40040 */  lw        $s4, 0x40($sp)
/* CD4160 80242330 8FB3003C */  lw        $s3, 0x3c($sp)
/* CD4164 80242334 8FB20038 */  lw        $s2, 0x38($sp)
/* CD4168 80242338 8FB10034 */  lw        $s1, 0x34($sp)
/* CD416C 8024233C 8FB00030 */  lw        $s0, 0x30($sp)
/* CD4170 80242340 03E00008 */  jr        $ra
/* CD4174 80242344 27BD0050 */   addiu    $sp, $sp, 0x50

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_17_func_80241C64_CD8F44
/* CD8F44 80241C64 27BDFF98 */  addiu     $sp, $sp, -0x68
/* CD8F48 80241C68 AFB40050 */  sw        $s4, 0x50($sp)
/* CD8F4C 80241C6C 0080A02D */  daddu     $s4, $a0, $zero
/* CD8F50 80241C70 AFBF005C */  sw        $ra, 0x5c($sp)
/* CD8F54 80241C74 AFB60058 */  sw        $s6, 0x58($sp)
/* CD8F58 80241C78 AFB50054 */  sw        $s5, 0x54($sp)
/* CD8F5C 80241C7C AFB3004C */  sw        $s3, 0x4c($sp)
/* CD8F60 80241C80 AFB20048 */  sw        $s2, 0x48($sp)
/* CD8F64 80241C84 AFB10044 */  sw        $s1, 0x44($sp)
/* CD8F68 80241C88 AFB00040 */  sw        $s0, 0x40($sp)
/* CD8F6C 80241C8C F7B40060 */  sdc1      $f20, 0x60($sp)
/* CD8F70 80241C90 8E930148 */  lw        $s3, 0x148($s4)
/* CD8F74 80241C94 86640008 */  lh        $a0, 8($s3)
/* CD8F78 80241C98 8E90000C */  lw        $s0, 0xc($s4)
/* CD8F7C 80241C9C 0C00EABB */  jal       get_npc_unsafe
/* CD8F80 80241CA0 00A0882D */   daddu    $s1, $a1, $zero
/* CD8F84 80241CA4 0280202D */  daddu     $a0, $s4, $zero
/* CD8F88 80241CA8 8E050000 */  lw        $a1, ($s0)
/* CD8F8C 80241CAC 0C0B1EAF */  jal       evt_get_variable
/* CD8F90 80241CB0 0040902D */   daddu    $s2, $v0, $zero
/* CD8F94 80241CB4 AFA00020 */  sw        $zero, 0x20($sp)
/* CD8F98 80241CB8 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CD8F9C 80241CBC 8C630030 */  lw        $v1, 0x30($v1)
/* CD8FA0 80241CC0 AFA30024 */  sw        $v1, 0x24($sp)
/* CD8FA4 80241CC4 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CD8FA8 80241CC8 8C63001C */  lw        $v1, 0x1c($v1)
/* CD8FAC 80241CCC AFA30028 */  sw        $v1, 0x28($sp)
/* CD8FB0 80241CD0 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CD8FB4 80241CD4 8C630024 */  lw        $v1, 0x24($v1)
/* CD8FB8 80241CD8 AFA3002C */  sw        $v1, 0x2c($sp)
/* CD8FBC 80241CDC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CD8FC0 80241CE0 8C630028 */  lw        $v1, 0x28($v1)
/* CD8FC4 80241CE4 27B50020 */  addiu     $s5, $sp, 0x20
/* CD8FC8 80241CE8 AFA30030 */  sw        $v1, 0x30($sp)
/* CD8FCC 80241CEC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* CD8FD0 80241CF0 3C0142F0 */  lui       $at, 0x42f0
/* CD8FD4 80241CF4 44810000 */  mtc1      $at, $f0
/* CD8FD8 80241CF8 8C63002C */  lw        $v1, 0x2c($v1)
/* CD8FDC 80241CFC 0040B02D */  daddu     $s6, $v0, $zero
/* CD8FE0 80241D00 E7A00038 */  swc1      $f0, 0x38($sp)
/* CD8FE4 80241D04 A7A0003C */  sh        $zero, 0x3c($sp)
/* CD8FE8 80241D08 12200007 */  beqz      $s1, .L80241D28
/* CD8FEC 80241D0C AFA30034 */   sw       $v1, 0x34($sp)
/* CD8FF0 80241D10 0240202D */  daddu     $a0, $s2, $zero
/* CD8FF4 80241D14 0260282D */  daddu     $a1, $s3, $zero
/* CD8FF8 80241D18 0280302D */  daddu     $a2, $s4, $zero
/* CD8FFC 80241D1C 0C090496 */  jal       flo_17_UnkFunc5
/* CD9000 80241D20 02C0382D */   daddu    $a3, $s6, $zero
/* CD9004 80241D24 AE800070 */  sw        $zero, 0x70($s4)
.L80241D28:
/* CD9008 80241D28 2402FFFD */  addiu     $v0, $zero, -3
/* CD900C 80241D2C A24200AB */  sb        $v0, 0xab($s2)
/* CD9010 80241D30 8E6300B0 */  lw        $v1, 0xb0($s3)
/* CD9014 80241D34 30620004 */  andi      $v0, $v1, 4
/* CD9018 80241D38 10400007 */  beqz      $v0, .L80241D58
/* CD901C 80241D3C 00000000 */   nop
/* CD9020 80241D40 826200B4 */  lb        $v0, 0xb4($s3)
/* CD9024 80241D44 144000F4 */  bnez      $v0, .L80242118
/* CD9028 80241D48 0000102D */   daddu    $v0, $zero, $zero
/* CD902C 80241D4C 2402FFFB */  addiu     $v0, $zero, -5
/* CD9030 80241D50 00621024 */  and       $v0, $v1, $v0
/* CD9034 80241D54 AE6200B0 */  sw        $v0, 0xb0($s3)
.L80241D58:
/* CD9038 80241D58 8E830070 */  lw        $v1, 0x70($s4)
/* CD903C 80241D5C 24020001 */  addiu     $v0, $zero, 1
/* CD9040 80241D60 10620011 */  beq       $v1, $v0, .L80241DA8
/* CD9044 80241D64 28620002 */   slti     $v0, $v1, 2
/* CD9048 80241D68 10400005 */  beqz      $v0, .L80241D80
/* CD904C 80241D6C 24020002 */   addiu    $v0, $zero, 2
/* CD9050 80241D70 10600009 */  beqz      $v1, .L80241D98
/* CD9054 80241D74 2402000C */   addiu    $v0, $zero, 0xc
/* CD9058 80241D78 0809077A */  j         .L80241DE8
/* CD905C 80241D7C 00000000 */   nop
.L80241D80:
/* CD9060 80241D80 1062000F */  beq       $v1, $v0, .L80241DC0
/* CD9064 80241D84 24020003 */   addiu    $v0, $zero, 3
/* CD9068 80241D88 10620012 */  beq       $v1, $v0, .L80241DD4
/* CD906C 80241D8C 0280202D */   daddu    $a0, $s4, $zero
/* CD9070 80241D90 08090778 */  j         .L80241DE0
/* CD9074 80241D94 00000000 */   nop
.L80241D98:
/* CD9078 80241D98 0280202D */  daddu     $a0, $s4, $zero
/* CD907C 80241D9C 02C0282D */  daddu     $a1, $s6, $zero
/* CD9080 80241DA0 0C09001C */  jal       flo_17_UnkNpcAIFunc23
/* CD9084 80241DA4 02A0302D */   daddu    $a2, $s5, $zero
.L80241DA8:
/* CD9088 80241DA8 0280202D */  daddu     $a0, $s4, $zero
/* CD908C 80241DAC 02C0282D */  daddu     $a1, $s6, $zero
/* CD9090 80241DB0 0C09056C */  jal       flo_17_func_802415B0_CD8890
/* CD9094 80241DB4 02A0302D */   daddu    $a2, $s5, $zero
/* CD9098 80241DB8 08090778 */  j         .L80241DE0
/* CD909C 80241DBC 00000000 */   nop
.L80241DC0:
/* CD90A0 80241DC0 0280202D */  daddu     $a0, $s4, $zero
/* CD90A4 80241DC4 02C0282D */  daddu     $a1, $s6, $zero
/* CD90A8 80241DC8 0C090212 */  jal       flo_17_UnkNpcAIFunc1
/* CD90AC 80241DCC 02A0302D */   daddu    $a2, $s5, $zero
/* CD90B0 80241DD0 0280202D */  daddu     $a0, $s4, $zero
.L80241DD4:
/* CD90B4 80241DD4 02C0282D */  daddu     $a1, $s6, $zero
/* CD90B8 80241DD8 0C090685 */  jal       flo_17_func_80241A14_CD8CF4
/* CD90BC 80241DDC 02A0302D */   daddu    $a2, $s5, $zero
.L80241DE0:
/* CD90C0 80241DE0 8E830070 */  lw        $v1, 0x70($s4)
/* CD90C4 80241DE4 2402000C */  addiu     $v0, $zero, 0xc
.L80241DE8:
/* CD90C8 80241DE8 1462001A */  bne       $v1, $v0, .L80241E54
/* CD90CC 80241DEC 00000000 */   nop
/* CD90D0 80241DF0 C64C0038 */  lwc1      $f12, 0x38($s2)
/* CD90D4 80241DF4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD90D8 80241DF8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD90DC 80241DFC C64E0040 */  lwc1      $f14, 0x40($s2)
/* CD90E0 80241E00 8C460028 */  lw        $a2, 0x28($v0)
/* CD90E4 80241E04 0C00A720 */  jal       atan2
/* CD90E8 80241E08 8C470030 */   lw       $a3, 0x30($v0)
/* CD90EC 80241E0C 0C09055A */  jal       flo_17_func_80241568_CD8848
/* CD90F0 80241E10 E640000C */   swc1     $f0, 0xc($s2)
/* CD90F4 80241E14 0440000F */  bltz      $v0, .L80241E54
/* CD90F8 80241E18 AE62007C */   sw       $v0, 0x7c($s3)
/* CD90FC 80241E1C 0C00FB3A */  jal       get_enemy
/* CD9100 80241E20 0040202D */   daddu    $a0, $v0, $zero
/* CD9104 80241E24 3C030049 */  lui       $v1, 0x49
/* CD9108 80241E28 0040202D */  daddu     $a0, $v0, $zero
/* CD910C 80241E2C 24020001 */  addiu     $v0, $zero, 1
/* CD9110 80241E30 AC820094 */  sw        $v0, 0x94($a0)
/* CD9114 80241E34 86620008 */  lh        $v0, 8($s3)
/* CD9118 80241E38 34630014 */  ori       $v1, $v1, 0x14
/* CD911C 80241E3C AC820098 */  sw        $v0, 0x98($a0)
/* CD9120 80241E40 2402000F */  addiu     $v0, $zero, 0xf
/* CD9124 80241E44 A642008E */  sh        $v0, 0x8e($s2)
/* CD9128 80241E48 2402001E */  addiu     $v0, $zero, 0x1e
/* CD912C 80241E4C AE430028 */  sw        $v1, 0x28($s2)
/* CD9130 80241E50 AE820070 */  sw        $v0, 0x70($s4)
.L80241E54:
/* CD9134 80241E54 8E830070 */  lw        $v1, 0x70($s4)
/* CD9138 80241E58 2402000D */  addiu     $v0, $zero, 0xd
/* CD913C 80241E5C 10620010 */  beq       $v1, $v0, .L80241EA0
/* CD9140 80241E60 2862000E */   slti     $v0, $v1, 0xe
/* CD9144 80241E64 10400005 */  beqz      $v0, .L80241E7C
/* CD9148 80241E68 2402000C */   addiu    $v0, $zero, 0xc
/* CD914C 80241E6C 10620008 */  beq       $v1, $v0, .L80241E90
/* CD9150 80241E70 2410001F */   addiu    $s0, $zero, 0x1f
/* CD9154 80241E74 080907B3 */  j         .L80241ECC
/* CD9158 80241E78 00000000 */   nop
.L80241E7C:
/* CD915C 80241E7C 2402000E */  addiu     $v0, $zero, 0xe
/* CD9160 80241E80 1062000D */  beq       $v1, $v0, .L80241EB8
/* CD9164 80241E84 0280202D */   daddu    $a0, $s4, $zero
/* CD9168 80241E88 080907B1 */  j         .L80241EC4
/* CD916C 80241E8C 00000000 */   nop
.L80241E90:
/* CD9170 80241E90 0280202D */  daddu     $a0, $s4, $zero
/* CD9174 80241E94 02C0282D */  daddu     $a1, $s6, $zero
/* CD9178 80241E98 0C09034C */  jal       flo_17_UnkNpcAIFunc14
/* CD917C 80241E9C 02A0302D */   daddu    $a2, $s5, $zero
.L80241EA0:
/* CD9180 80241EA0 0280202D */  daddu     $a0, $s4, $zero
/* CD9184 80241EA4 02C0282D */  daddu     $a1, $s6, $zero
/* CD9188 80241EA8 0C090399 */  jal       flo_17_UnkNpcAIFunc3
/* CD918C 80241EAC 02A0302D */   daddu    $a2, $s5, $zero
/* CD9190 80241EB0 080907B1 */  j         .L80241EC4
/* CD9194 80241EB4 00000000 */   nop
.L80241EB8:
/* CD9198 80241EB8 02C0282D */  daddu     $a1, $s6, $zero
/* CD919C 80241EBC 0C0903B2 */  jal       flo_17_UnkFunc6
/* CD91A0 80241EC0 02A0302D */   daddu    $a2, $s5, $zero
.L80241EC4:
/* CD91A4 80241EC4 8E830070 */  lw        $v1, 0x70($s4)
/* CD91A8 80241EC8 2410001F */  addiu     $s0, $zero, 0x1f
.L80241ECC:
/* CD91AC 80241ECC 1070001B */  beq       $v1, $s0, .L80241F3C
/* CD91B0 80241ED0 28620020 */   slti     $v0, $v1, 0x20
/* CD91B4 80241ED4 10400005 */  beqz      $v0, .L80241EEC
/* CD91B8 80241ED8 2402001E */   addiu    $v0, $zero, 0x1e
/* CD91BC 80241EDC 1062000A */  beq       $v1, $v0, .L80241F08
/* CD91C0 80241EE0 00000000 */   nop
/* CD91C4 80241EE4 080907EE */  j         .L80241FB8
/* CD91C8 80241EE8 00000000 */   nop
.L80241EEC:
/* CD91CC 80241EEC 24020020 */  addiu     $v0, $zero, 0x20
/* CD91D0 80241EF0 10620022 */  beq       $v1, $v0, .L80241F7C
/* CD91D4 80241EF4 24020021 */   addiu    $v0, $zero, 0x21
/* CD91D8 80241EF8 10620029 */  beq       $v1, $v0, .L80241FA0
/* CD91DC 80241EFC 00000000 */   nop
/* CD91E0 80241F00 080907EE */  j         .L80241FB8
/* CD91E4 80241F04 00000000 */   nop
.L80241F08:
/* CD91E8 80241F08 9642008E */  lhu       $v0, 0x8e($s2)
/* CD91EC 80241F0C 2442FFFF */  addiu     $v0, $v0, -1
/* CD91F0 80241F10 A642008E */  sh        $v0, 0x8e($s2)
/* CD91F4 80241F14 00021400 */  sll       $v0, $v0, 0x10
/* CD91F8 80241F18 1C400027 */  bgtz      $v0, .L80241FB8
/* CD91FC 80241F1C 00000000 */   nop
/* CD9200 80241F20 0C00FB3A */  jal       get_enemy
/* CD9204 80241F24 8E64007C */   lw       $a0, 0x7c($s3)
/* CD9208 80241F28 24030002 */  addiu     $v1, $zero, 2
/* CD920C 80241F2C AC430094 */  sw        $v1, 0x94($v0)
/* CD9210 80241F30 24020005 */  addiu     $v0, $zero, 5
/* CD9214 80241F34 A642008E */  sh        $v0, 0x8e($s2)
/* CD9218 80241F38 AE900070 */  sw        $s0, 0x70($s4)
.L80241F3C:
/* CD921C 80241F3C 9642008E */  lhu       $v0, 0x8e($s2)
/* CD9220 80241F40 2442FFFF */  addiu     $v0, $v0, -1
/* CD9224 80241F44 A642008E */  sh        $v0, 0x8e($s2)
/* CD9228 80241F48 00021400 */  sll       $v0, $v0, 0x10
/* CD922C 80241F4C 1C40001A */  bgtz      $v0, .L80241FB8
/* CD9230 80241F50 3C020049 */   lui      $v0, 0x49
/* CD9234 80241F54 34420015 */  ori       $v0, $v0, 0x15
/* CD9238 80241F58 AE420028 */  sw        $v0, 0x28($s2)
/* CD923C 80241F5C 0C00FB3A */  jal       get_enemy
/* CD9240 80241F60 8E64007C */   lw       $a0, 0x7c($s3)
/* CD9244 80241F64 24030003 */  addiu     $v1, $zero, 3
/* CD9248 80241F68 AC430094 */  sw        $v1, 0x94($v0)
/* CD924C 80241F6C 2402000A */  addiu     $v0, $zero, 0xa
/* CD9250 80241F70 A642008E */  sh        $v0, 0x8e($s2)
/* CD9254 80241F74 24020020 */  addiu     $v0, $zero, 0x20
/* CD9258 80241F78 AE820070 */  sw        $v0, 0x70($s4)
.L80241F7C:
/* CD925C 80241F7C 9642008E */  lhu       $v0, 0x8e($s2)
/* CD9260 80241F80 2442FFFF */  addiu     $v0, $v0, -1
/* CD9264 80241F84 A642008E */  sh        $v0, 0x8e($s2)
/* CD9268 80241F88 00021400 */  sll       $v0, $v0, 0x10
/* CD926C 80241F8C 1C40000A */  bgtz      $v0, .L80241FB8
/* CD9270 80241F90 24020003 */   addiu    $v0, $zero, 3
/* CD9274 80241F94 A642008E */  sh        $v0, 0x8e($s2)
/* CD9278 80241F98 24020021 */  addiu     $v0, $zero, 0x21
/* CD927C 80241F9C AE820070 */  sw        $v0, 0x70($s4)
.L80241FA0:
/* CD9280 80241FA0 9642008E */  lhu       $v0, 0x8e($s2)
/* CD9284 80241FA4 2442FFFF */  addiu     $v0, $v0, -1
/* CD9288 80241FA8 A642008E */  sh        $v0, 0x8e($s2)
/* CD928C 80241FAC 00021400 */  sll       $v0, $v0, 0x10
/* CD9290 80241FB0 58400001 */  blezl     $v0, .L80241FB8
/* CD9294 80241FB4 AE800070 */   sw       $zero, 0x70($s4)
.L80241FB8:
/* CD9298 80241FB8 8E820070 */  lw        $v0, 0x70($s4)
/* CD929C 80241FBC 2442FFE2 */  addiu     $v0, $v0, -0x1e
/* CD92A0 80241FC0 2C420002 */  sltiu     $v0, $v0, 2
/* CD92A4 80241FC4 10400054 */  beqz      $v0, .L80242118
/* CD92A8 80241FC8 0000102D */   daddu    $v0, $zero, $zero
/* CD92AC 80241FCC 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* CD92B0 80241FD0 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* CD92B4 80241FD4 C64C0038 */  lwc1      $f12, 0x38($s2)
/* CD92B8 80241FD8 8E020000 */  lw        $v0, ($s0)
/* CD92BC 80241FDC C64E0040 */  lwc1      $f14, 0x40($s2)
/* CD92C0 80241FE0 8C460028 */  lw        $a2, 0x28($v0)
/* CD92C4 80241FE4 0C00A720 */  jal       atan2
/* CD92C8 80241FE8 8C470030 */   lw       $a3, 0x30($v0)
/* CD92CC 80241FEC 8E460038 */  lw        $a2, 0x38($s2)
/* CD92D0 80241FF0 8E470040 */  lw        $a3, 0x40($s2)
/* CD92D4 80241FF4 8E020000 */  lw        $v0, ($s0)
/* CD92D8 80241FF8 E640000C */  swc1      $f0, 0xc($s2)
/* CD92DC 80241FFC C44C0028 */  lwc1      $f12, 0x28($v0)
/* CD92E0 80242000 0C00A7B5 */  jal       dist2D
/* CD92E4 80242004 C44E0030 */   lwc1     $f14, 0x30($v0)
/* CD92E8 80242008 C6A20008 */  lwc1      $f2, 8($s5)
/* CD92EC 8024200C 468010A0 */  cvt.s.w   $f2, $f2
/* CD92F0 80242010 44051000 */  mfc1      $a1, $f2
/* CD92F4 80242014 C6A2000C */  lwc1      $f2, 0xc($s5)
/* CD92F8 80242018 468010A0 */  cvt.s.w   $f2, $f2
/* CD92FC 8024201C 44061000 */  mfc1      $a2, $f2
/* CD9300 80242020 C6420040 */  lwc1      $f2, 0x40($s2)
/* CD9304 80242024 E7A20010 */  swc1      $f2, 0x10($sp)
/* CD9308 80242028 C6A20010 */  lwc1      $f2, 0x10($s5)
/* CD930C 8024202C 468010A0 */  cvt.s.w   $f2, $f2
/* CD9310 80242030 E7A20014 */  swc1      $f2, 0x14($sp)
/* CD9314 80242034 C6A20014 */  lwc1      $f2, 0x14($s5)
/* CD9318 80242038 468010A0 */  cvt.s.w   $f2, $f2
/* CD931C 8024203C E7A20018 */  swc1      $f2, 0x18($sp)
/* CD9320 80242040 8EA40004 */  lw        $a0, 4($s5)
/* CD9324 80242044 8E470038 */  lw        $a3, 0x38($s2)
/* CD9328 80242048 0C0123F5 */  jal       is_point_within_region
/* CD932C 8024204C 46000506 */   mov.s    $f20, $f0
/* CD9330 80242050 14400031 */  bnez      $v0, .L80242118
/* CD9334 80242054 0000102D */   daddu    $v0, $zero, $zero
/* CD9338 80242058 3C01403E */  lui       $at, 0x403e
/* CD933C 8024205C 44810800 */  mtc1      $at, $f1
/* CD9340 80242060 44800000 */  mtc1      $zero, $f0
/* CD9344 80242064 4600A0A1 */  cvt.d.s   $f2, $f20
/* CD9348 80242068 4622003C */  c.lt.d    $f0, $f2
/* CD934C 8024206C 00000000 */  nop
/* CD9350 80242070 45000029 */  bc1f      .L80242118
/* CD9354 80242074 00000000 */   nop
/* CD9358 80242078 8642008C */  lh        $v0, 0x8c($s2)
/* CD935C 8024207C 54400026 */  bnel      $v0, $zero, .L80242118
/* CD9360 80242080 0000102D */   daddu    $v0, $zero, $zero
/* CD9364 80242084 3C014034 */  lui       $at, 0x4034
/* CD9368 80242088 44810800 */  mtc1      $at, $f1
/* CD936C 8024208C 44800000 */  mtc1      $zero, $f0
/* CD9370 80242090 00000000 */  nop
/* CD9374 80242094 46201001 */  sub.d     $f0, $f2, $f0
/* CD9378 80242098 44801000 */  mtc1      $zero, $f2
/* CD937C 8024209C 44801800 */  mtc1      $zero, $f3
/* CD9380 802420A0 46200120 */  cvt.s.d   $f4, $f0
/* CD9384 802420A4 46002021 */  cvt.d.s   $f0, $f4
/* CD9388 802420A8 4622003C */  c.lt.d    $f0, $f2
/* CD938C 802420AC 00000000 */  nop
/* CD9390 802420B0 45000002 */  bc1f      .L802420BC
/* CD9394 802420B4 00000000 */   nop
/* CD9398 802420B8 44802000 */  mtc1      $zero, $f4
.L802420BC:
/* CD939C 802420BC 3C014069 */  lui       $at, 0x4069
/* CD93A0 802420C0 44811800 */  mtc1      $at, $f3
/* CD93A4 802420C4 44801000 */  mtc1      $zero, $f2
/* CD93A8 802420C8 46002021 */  cvt.d.s   $f0, $f4
/* CD93AC 802420CC 4620103C */  c.lt.d    $f2, $f0
/* CD93B0 802420D0 00000000 */  nop
/* CD93B4 802420D4 45000003 */  bc1f      .L802420E4
/* CD93B8 802420D8 240200C8 */   addiu    $v0, $zero, 0xc8
/* CD93BC 802420DC 3C014348 */  lui       $at, 0x4348
/* CD93C0 802420E0 44812000 */  mtc1      $at, $f4
.L802420E4:
/* CD93C4 802420E4 AFA20010 */  sw        $v0, 0x10($sp)
/* CD93C8 802420E8 8EC50000 */  lw        $a1, ($s6)
/* CD93CC 802420EC 8EC60018 */  lw        $a2, 0x18($s6)
/* CD93D0 802420F0 4600218D */  trunc.w.s $f6, $f4
/* CD93D4 802420F4 44073000 */  mfc1      $a3, $f6
/* CD93D8 802420F8 0C00A8ED */  jal       update_lerp
/* CD93DC 802420FC 0000202D */   daddu    $a0, $zero, $zero
/* CD93E0 80242100 44050000 */  mfc1      $a1, $f0
/* CD93E4 80242104 8E46000C */  lw        $a2, 0xc($s2)
/* CD93E8 80242108 0240202D */  daddu     $a0, $s2, $zero
/* CD93EC 8024210C 0C00EA95 */  jal       npc_move_heading
/* CD93F0 80242110 AC850018 */   sw       $a1, 0x18($a0)
/* CD93F4 80242114 0000102D */  daddu     $v0, $zero, $zero
.L80242118:
/* CD93F8 80242118 8FBF005C */  lw        $ra, 0x5c($sp)
/* CD93FC 8024211C 8FB60058 */  lw        $s6, 0x58($sp)
/* CD9400 80242120 8FB50054 */  lw        $s5, 0x54($sp)
/* CD9404 80242124 8FB40050 */  lw        $s4, 0x50($sp)
/* CD9408 80242128 8FB3004C */  lw        $s3, 0x4c($sp)
/* CD940C 8024212C 8FB20048 */  lw        $s2, 0x48($sp)
/* CD9410 80242130 8FB10044 */  lw        $s1, 0x44($sp)
/* CD9414 80242134 8FB00040 */  lw        $s0, 0x40($sp)
/* CD9418 80242138 D7B40060 */  ldc1      $f20, 0x60($sp)
/* CD941C 8024213C 03E00008 */  jr        $ra
/* CD9420 80242140 27BD0068 */   addiu    $sp, $sp, 0x68

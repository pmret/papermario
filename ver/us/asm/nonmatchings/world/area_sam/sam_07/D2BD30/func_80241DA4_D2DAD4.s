.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DA4_D2DAD4
/* D2DAD4 80241DA4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D2DAD8 80241DA8 AFB20038 */  sw        $s2, 0x38($sp)
/* D2DADC 80241DAC 0080902D */  daddu     $s2, $a0, $zero
/* D2DAE0 80241DB0 AFBF0048 */  sw        $ra, 0x48($sp)
/* D2DAE4 80241DB4 AFB50044 */  sw        $s5, 0x44($sp)
/* D2DAE8 80241DB8 AFB40040 */  sw        $s4, 0x40($sp)
/* D2DAEC 80241DBC AFB3003C */  sw        $s3, 0x3c($sp)
/* D2DAF0 80241DC0 AFB10034 */  sw        $s1, 0x34($sp)
/* D2DAF4 80241DC4 AFB00030 */  sw        $s0, 0x30($sp)
/* D2DAF8 80241DC8 8E510148 */  lw        $s1, 0x148($s2)
/* D2DAFC 80241DCC 86240008 */  lh        $a0, 8($s1)
/* D2DB00 80241DD0 0C00EABB */  jal       get_npc_unsafe
/* D2DB04 80241DD4 00A0802D */   daddu    $s0, $a1, $zero
/* D2DB08 80241DD8 8E43000C */  lw        $v1, 0xc($s2)
/* D2DB0C 80241DDC 0240202D */  daddu     $a0, $s2, $zero
/* D2DB10 80241DE0 8C650000 */  lw        $a1, ($v1)
/* D2DB14 80241DE4 0C0B1EAF */  jal       evt_get_variable
/* D2DB18 80241DE8 0040A82D */   daddu    $s5, $v0, $zero
/* D2DB1C 80241DEC AFA00010 */  sw        $zero, 0x10($sp)
/* D2DB20 80241DF0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D2DB24 80241DF4 8C630030 */  lw        $v1, 0x30($v1)
/* D2DB28 80241DF8 AFA30014 */  sw        $v1, 0x14($sp)
/* D2DB2C 80241DFC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D2DB30 80241E00 8C63001C */  lw        $v1, 0x1c($v1)
/* D2DB34 80241E04 AFA30018 */  sw        $v1, 0x18($sp)
/* D2DB38 80241E08 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D2DB3C 80241E0C 8C630024 */  lw        $v1, 0x24($v1)
/* D2DB40 80241E10 AFA3001C */  sw        $v1, 0x1c($sp)
/* D2DB44 80241E14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D2DB48 80241E18 8C630028 */  lw        $v1, 0x28($v1)
/* D2DB4C 80241E1C 27B40010 */  addiu     $s4, $sp, 0x10
/* D2DB50 80241E20 AFA30020 */  sw        $v1, 0x20($sp)
/* D2DB54 80241E24 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D2DB58 80241E28 3C014348 */  lui       $at, 0x4348
/* D2DB5C 80241E2C 44810000 */  mtc1      $at, $f0
/* D2DB60 80241E30 8C63002C */  lw        $v1, 0x2c($v1)
/* D2DB64 80241E34 0040982D */  daddu     $s3, $v0, $zero
/* D2DB68 80241E38 E7A00028 */  swc1      $f0, 0x28($sp)
/* D2DB6C 80241E3C A7A0002C */  sh        $zero, 0x2c($sp)
/* D2DB70 80241E40 16000005 */  bnez      $s0, .L80241E58
/* D2DB74 80241E44 AFA30024 */   sw       $v1, 0x24($sp)
/* D2DB78 80241E48 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D2DB7C 80241E4C 30420004 */  andi      $v0, $v0, 4
/* D2DB80 80241E50 10400011 */  beqz      $v0, .L80241E98
/* D2DB84 80241E54 00000000 */   nop
.L80241E58:
/* D2DB88 80241E58 AE400070 */  sw        $zero, 0x70($s2)
/* D2DB8C 80241E5C A6A0008E */  sh        $zero, 0x8e($s5)
/* D2DB90 80241E60 8E2200CC */  lw        $v0, 0xcc($s1)
/* D2DB94 80241E64 8C420000 */  lw        $v0, ($v0)
/* D2DB98 80241E68 AEA20028 */  sw        $v0, 0x28($s5)
/* D2DB9C 80241E6C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D2DBA0 80241E70 30420004 */  andi      $v0, $v0, 4
/* D2DBA4 80241E74 10400008 */  beqz      $v0, .L80241E98
/* D2DBA8 80241E78 AE20006C */   sw       $zero, 0x6c($s1)
/* D2DBAC 80241E7C 24020063 */  addiu     $v0, $zero, 0x63
/* D2DBB0 80241E80 AE420070 */  sw        $v0, 0x70($s2)
/* D2DBB4 80241E84 AE400074 */  sw        $zero, 0x74($s2)
/* D2DBB8 80241E88 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D2DBBC 80241E8C 2403FFFB */  addiu     $v1, $zero, -5
/* D2DBC0 80241E90 00431024 */  and       $v0, $v0, $v1
/* D2DBC4 80241E94 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241E98:
/* D2DBC8 80241E98 8E430070 */  lw        $v1, 0x70($s2)
/* D2DBCC 80241E9C 2410000B */  addiu     $s0, $zero, 0xb
/* D2DBD0 80241EA0 1070002A */  beq       $v1, $s0, .L80241F4C
/* D2DBD4 80241EA4 2862000C */   slti     $v0, $v1, 0xc
/* D2DBD8 80241EA8 1040000D */  beqz      $v0, .L80241EE0
/* D2DBDC 80241EAC 24020001 */   addiu    $v0, $zero, 1
/* D2DBE0 80241EB0 1062001A */  beq       $v1, $v0, .L80241F1C
/* D2DBE4 80241EB4 28620002 */   slti     $v0, $v1, 2
/* D2DBE8 80241EB8 10400005 */  beqz      $v0, .L80241ED0
/* D2DBEC 80241EBC 2402000A */   addiu    $v0, $zero, 0xa
/* D2DBF0 80241EC0 10600013 */  beqz      $v1, .L80241F10
/* D2DBF4 80241EC4 0240202D */   daddu    $a0, $s2, $zero
/* D2DBF8 80241EC8 080907F3 */  j         .L80241FCC
/* D2DBFC 80241ECC 00000000 */   nop
.L80241ED0:
/* D2DC00 80241ED0 10620018 */  beq       $v1, $v0, .L80241F34
/* D2DC04 80241ED4 0240202D */   daddu    $a0, $s2, $zero
/* D2DC08 80241ED8 080907F3 */  j         .L80241FCC
/* D2DC0C 80241EDC 00000000 */   nop
.L80241EE0:
/* D2DC10 80241EE0 2402000D */  addiu     $v0, $zero, 0xd
/* D2DC14 80241EE4 10620029 */  beq       $v1, $v0, .L80241F8C
/* D2DC18 80241EE8 0062102A */   slt      $v0, $v1, $v0
/* D2DC1C 80241EEC 14400020 */  bnez      $v0, .L80241F70
/* D2DC20 80241EF0 0240202D */   daddu    $a0, $s2, $zero
/* D2DC24 80241EF4 2402000E */  addiu     $v0, $zero, 0xe
/* D2DC28 80241EF8 1062002D */  beq       $v1, $v0, .L80241FB0
/* D2DC2C 80241EFC 24020063 */   addiu    $v0, $zero, 0x63
/* D2DC30 80241F00 10620030 */  beq       $v1, $v0, .L80241FC4
/* D2DC34 80241F04 00000000 */   nop
/* D2DC38 80241F08 080907F3 */  j         .L80241FCC
/* D2DC3C 80241F0C 00000000 */   nop
.L80241F10:
/* D2DC40 80241F10 0260282D */  daddu     $a1, $s3, $zero
/* D2DC44 80241F14 0C0903C8 */  jal       func_80240F20_D2CC50
/* D2DC48 80241F18 0280302D */   daddu    $a2, $s4, $zero
.L80241F1C:
/* D2DC4C 80241F1C 0240202D */  daddu     $a0, $s2, $zero
/* D2DC50 80241F20 0260282D */  daddu     $a1, $s3, $zero
/* D2DC54 80241F24 0C0903E3 */  jal       func_80240F8C_D2CCBC
/* D2DC58 80241F28 0280302D */   daddu    $a2, $s4, $zero
/* D2DC5C 80241F2C 080907F3 */  j         .L80241FCC
/* D2DC60 80241F30 00000000 */   nop
.L80241F34:
/* D2DC64 80241F34 0260282D */  daddu     $a1, $s3, $zero
/* D2DC68 80241F38 0C090422 */  jal       func_80241088_D2CDB8
/* D2DC6C 80241F3C 0280302D */   daddu    $a2, $s4, $zero
/* D2DC70 80241F40 8E420070 */  lw        $v0, 0x70($s2)
/* D2DC74 80241F44 14500021 */  bne       $v0, $s0, .L80241FCC
/* D2DC78 80241F48 00000000 */   nop
.L80241F4C:
/* D2DC7C 80241F4C 0240202D */  daddu     $a0, $s2, $zero
/* D2DC80 80241F50 0260282D */  daddu     $a1, $s3, $zero
/* D2DC84 80241F54 0C0906B2 */  jal       sam_07_UnkNpcDurationFlagFunc3
/* D2DC88 80241F58 0280302D */   daddu    $a2, $s4, $zero
/* D2DC8C 80241F5C 8E430070 */  lw        $v1, 0x70($s2)
/* D2DC90 80241F60 2402000C */  addiu     $v0, $zero, 0xc
/* D2DC94 80241F64 14620019 */  bne       $v1, $v0, .L80241FCC
/* D2DC98 80241F68 00000000 */   nop
/* D2DC9C 80241F6C 0240202D */  daddu     $a0, $s2, $zero
.L80241F70:
/* D2DCA0 80241F70 0260282D */  daddu     $a1, $s3, $zero
/* D2DCA4 80241F74 0C0906D6 */  jal       func_80241B58_D2D888
/* D2DCA8 80241F78 0280302D */   daddu    $a2, $s4, $zero
/* D2DCAC 80241F7C 8E430070 */  lw        $v1, 0x70($s2)
/* D2DCB0 80241F80 2402000D */  addiu     $v0, $zero, 0xd
/* D2DCB4 80241F84 14620011 */  bne       $v1, $v0, .L80241FCC
/* D2DCB8 80241F88 00000000 */   nop
.L80241F8C:
/* D2DCBC 80241F8C 0240202D */  daddu     $a0, $s2, $zero
/* D2DCC0 80241F90 0260282D */  daddu     $a1, $s3, $zero
/* D2DCC4 80241F94 0C090716 */  jal       sam_07_UnkNpcDurationFlagFunc2
/* D2DCC8 80241F98 0280302D */   daddu    $a2, $s4, $zero
/* D2DCCC 80241F9C 8E430070 */  lw        $v1, 0x70($s2)
/* D2DCD0 80241FA0 2402000E */  addiu     $v0, $zero, 0xe
/* D2DCD4 80241FA4 14620009 */  bne       $v1, $v0, .L80241FCC
/* D2DCD8 80241FA8 00000000 */   nop
/* D2DCDC 80241FAC 0240202D */  daddu     $a0, $s2, $zero
.L80241FB0:
/* D2DCE0 80241FB0 0260282D */  daddu     $a1, $s3, $zero
/* D2DCE4 80241FB4 0C09072E */  jal       sam_07_UnkNpcAIFunc30
/* D2DCE8 80241FB8 0280302D */   daddu    $a2, $s4, $zero
/* D2DCEC 80241FBC 080907F3 */  j         .L80241FCC
/* D2DCF0 80241FC0 00000000 */   nop
.L80241FC4:
/* D2DCF4 80241FC4 0C0129CF */  jal       func_8004A73C
/* D2DCF8 80241FC8 0240202D */   daddu    $a0, $s2, $zero
.L80241FCC:
/* D2DCFC 80241FCC 8FBF0048 */  lw        $ra, 0x48($sp)
/* D2DD00 80241FD0 8FB50044 */  lw        $s5, 0x44($sp)
/* D2DD04 80241FD4 8FB40040 */  lw        $s4, 0x40($sp)
/* D2DD08 80241FD8 8FB3003C */  lw        $s3, 0x3c($sp)
/* D2DD0C 80241FDC 8FB20038 */  lw        $s2, 0x38($sp)
/* D2DD10 80241FE0 8FB10034 */  lw        $s1, 0x34($sp)
/* D2DD14 80241FE4 8FB00030 */  lw        $s0, 0x30($sp)
/* D2DD18 80241FE8 0000102D */  daddu     $v0, $zero, $zero
/* D2DD1C 80241FEC 03E00008 */  jr        $ra
/* D2DD20 80241FF0 27BD0050 */   addiu    $sp, $sp, 0x50
/* D2DD24 80241FF4 00000000 */  nop
/* D2DD28 80241FF8 00000000 */  nop
/* D2DD2C 80241FFC 00000000 */  nop

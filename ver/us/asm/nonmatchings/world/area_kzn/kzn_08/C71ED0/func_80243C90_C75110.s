.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243C90_C75110
/* C75110 80243C90 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C75114 80243C94 AFB20038 */  sw        $s2, 0x38($sp)
/* C75118 80243C98 0080902D */  daddu     $s2, $a0, $zero
/* C7511C 80243C9C AFBF0048 */  sw        $ra, 0x48($sp)
/* C75120 80243CA0 AFB50044 */  sw        $s5, 0x44($sp)
/* C75124 80243CA4 AFB40040 */  sw        $s4, 0x40($sp)
/* C75128 80243CA8 AFB3003C */  sw        $s3, 0x3c($sp)
/* C7512C 80243CAC AFB10034 */  sw        $s1, 0x34($sp)
/* C75130 80243CB0 AFB00030 */  sw        $s0, 0x30($sp)
/* C75134 80243CB4 8E510148 */  lw        $s1, 0x148($s2)
/* C75138 80243CB8 86240008 */  lh        $a0, 8($s1)
/* C7513C 80243CBC 0C00EABB */  jal       get_npc_unsafe
/* C75140 80243CC0 00A0802D */   daddu    $s0, $a1, $zero
/* C75144 80243CC4 8E43000C */  lw        $v1, 0xc($s2)
/* C75148 80243CC8 0240202D */  daddu     $a0, $s2, $zero
/* C7514C 80243CCC 8C650000 */  lw        $a1, ($v1)
/* C75150 80243CD0 0C0B1EAF */  jal       evt_get_variable
/* C75154 80243CD4 0040A82D */   daddu    $s5, $v0, $zero
/* C75158 80243CD8 AFA00010 */  sw        $zero, 0x10($sp)
/* C7515C 80243CDC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C75160 80243CE0 8C630030 */  lw        $v1, 0x30($v1)
/* C75164 80243CE4 AFA30014 */  sw        $v1, 0x14($sp)
/* C75168 80243CE8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C7516C 80243CEC 8C63001C */  lw        $v1, 0x1c($v1)
/* C75170 80243CF0 AFA30018 */  sw        $v1, 0x18($sp)
/* C75174 80243CF4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C75178 80243CF8 8C630024 */  lw        $v1, 0x24($v1)
/* C7517C 80243CFC AFA3001C */  sw        $v1, 0x1c($sp)
/* C75180 80243D00 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C75184 80243D04 8C630028 */  lw        $v1, 0x28($v1)
/* C75188 80243D08 27B40010 */  addiu     $s4, $sp, 0x10
/* C7518C 80243D0C AFA30020 */  sw        $v1, 0x20($sp)
/* C75190 80243D10 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C75194 80243D14 3C014348 */  lui       $at, 0x4348
/* C75198 80243D18 44810000 */  mtc1      $at, $f0
/* C7519C 80243D1C 8C63002C */  lw        $v1, 0x2c($v1)
/* C751A0 80243D20 0040982D */  daddu     $s3, $v0, $zero
/* C751A4 80243D24 E7A00028 */  swc1      $f0, 0x28($sp)
/* C751A8 80243D28 A7A0002C */  sh        $zero, 0x2c($sp)
/* C751AC 80243D2C 16000005 */  bnez      $s0, .L80243D44
/* C751B0 80243D30 AFA30024 */   sw       $v1, 0x24($sp)
/* C751B4 80243D34 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C751B8 80243D38 30420004 */  andi      $v0, $v0, 4
/* C751BC 80243D3C 10400011 */  beqz      $v0, .L80243D84
/* C751C0 80243D40 00000000 */   nop
.L80243D44:
/* C751C4 80243D44 AE400070 */  sw        $zero, 0x70($s2)
/* C751C8 80243D48 A6A0008E */  sh        $zero, 0x8e($s5)
/* C751CC 80243D4C 8E2200CC */  lw        $v0, 0xcc($s1)
/* C751D0 80243D50 8C420000 */  lw        $v0, ($v0)
/* C751D4 80243D54 AEA20028 */  sw        $v0, 0x28($s5)
/* C751D8 80243D58 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C751DC 80243D5C 30420004 */  andi      $v0, $v0, 4
/* C751E0 80243D60 10400008 */  beqz      $v0, .L80243D84
/* C751E4 80243D64 AE20006C */   sw       $zero, 0x6c($s1)
/* C751E8 80243D68 24020063 */  addiu     $v0, $zero, 0x63
/* C751EC 80243D6C AE420070 */  sw        $v0, 0x70($s2)
/* C751F0 80243D70 AE400074 */  sw        $zero, 0x74($s2)
/* C751F4 80243D74 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C751F8 80243D78 2403FFFB */  addiu     $v1, $zero, -5
/* C751FC 80243D7C 00431024 */  and       $v0, $v0, $v1
/* C75200 80243D80 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80243D84:
/* C75204 80243D84 8E430070 */  lw        $v1, 0x70($s2)
/* C75208 80243D88 2410000B */  addiu     $s0, $zero, 0xb
/* C7520C 80243D8C 1070002A */  beq       $v1, $s0, .L80243E38
/* C75210 80243D90 2862000C */   slti     $v0, $v1, 0xc
/* C75214 80243D94 1040000D */  beqz      $v0, .L80243DCC
/* C75218 80243D98 24020001 */   addiu    $v0, $zero, 1
/* C7521C 80243D9C 1062001A */  beq       $v1, $v0, .L80243E08
/* C75220 80243DA0 28620002 */   slti     $v0, $v1, 2
/* C75224 80243DA4 10400005 */  beqz      $v0, .L80243DBC
/* C75228 80243DA8 2402000A */   addiu    $v0, $zero, 0xa
/* C7522C 80243DAC 10600013 */  beqz      $v1, .L80243DFC
/* C75230 80243DB0 0240202D */   daddu    $a0, $s2, $zero
/* C75234 80243DB4 08090FAE */  j         .L80243EB8
/* C75238 80243DB8 00000000 */   nop
.L80243DBC:
/* C7523C 80243DBC 10620018 */  beq       $v1, $v0, .L80243E20
/* C75240 80243DC0 0240202D */   daddu    $a0, $s2, $zero
/* C75244 80243DC4 08090FAE */  j         .L80243EB8
/* C75248 80243DC8 00000000 */   nop
.L80243DCC:
/* C7524C 80243DCC 2402000D */  addiu     $v0, $zero, 0xd
/* C75250 80243DD0 10620029 */  beq       $v1, $v0, .L80243E78
/* C75254 80243DD4 0062102A */   slt      $v0, $v1, $v0
/* C75258 80243DD8 14400020 */  bnez      $v0, .L80243E5C
/* C7525C 80243DDC 0240202D */   daddu    $a0, $s2, $zero
/* C75260 80243DE0 2402000E */  addiu     $v0, $zero, 0xe
/* C75264 80243DE4 1062002D */  beq       $v1, $v0, .L80243E9C
/* C75268 80243DE8 24020063 */   addiu    $v0, $zero, 0x63
/* C7526C 80243DEC 10620030 */  beq       $v1, $v0, .L80243EB0
/* C75270 80243DF0 00000000 */   nop
/* C75274 80243DF4 08090FAE */  j         .L80243EB8
/* C75278 80243DF8 00000000 */   nop
.L80243DFC:
/* C7527C 80243DFC 0260282D */  daddu     $a1, $s3, $zero
/* C75280 80243E00 0C090B83 */  jal       kzn_08_UnkNpcAIFunc31
/* C75284 80243E04 0280302D */   daddu    $a2, $s4, $zero
.L80243E08:
/* C75288 80243E08 0240202D */  daddu     $a0, $s2, $zero
/* C7528C 80243E0C 0260282D */  daddu     $a1, $s3, $zero
/* C75290 80243E10 0C090B9E */  jal       kzn_08_UnkNpcAIFunc32
/* C75294 80243E14 0280302D */   daddu    $a2, $s4, $zero
/* C75298 80243E18 08090FAE */  j         .L80243EB8
/* C7529C 80243E1C 00000000 */   nop
.L80243E20:
/* C752A0 80243E20 0260282D */  daddu     $a1, $s3, $zero
/* C752A4 80243E24 0C090BDD */  jal       func_80242F74_C743F4
/* C752A8 80243E28 0280302D */   daddu    $a2, $s4, $zero
/* C752AC 80243E2C 8E420070 */  lw        $v0, 0x70($s2)
/* C752B0 80243E30 14500021 */  bne       $v0, $s0, .L80243EB8
/* C752B4 80243E34 00000000 */   nop
.L80243E38:
/* C752B8 80243E38 0240202D */  daddu     $a0, $s2, $zero
/* C752BC 80243E3C 0260282D */  daddu     $a1, $s3, $zero
/* C752C0 80243E40 0C090E6D */  jal       kzn_08_UnkNpcDurationFlagFunc3
/* C752C4 80243E44 0280302D */   daddu    $a2, $s4, $zero
/* C752C8 80243E48 8E430070 */  lw        $v1, 0x70($s2)
/* C752CC 80243E4C 2402000C */  addiu     $v0, $zero, 0xc
/* C752D0 80243E50 14620019 */  bne       $v1, $v0, .L80243EB8
/* C752D4 80243E54 00000000 */   nop
/* C752D8 80243E58 0240202D */  daddu     $a0, $s2, $zero
.L80243E5C:
/* C752DC 80243E5C 0260282D */  daddu     $a1, $s3, $zero
/* C752E0 80243E60 0C090E91 */  jal       kzn_08_UnkNpcAIFunc33
/* C752E4 80243E64 0280302D */   daddu    $a2, $s4, $zero
/* C752E8 80243E68 8E430070 */  lw        $v1, 0x70($s2)
/* C752EC 80243E6C 2402000D */  addiu     $v0, $zero, 0xd
/* C752F0 80243E70 14620011 */  bne       $v1, $v0, .L80243EB8
/* C752F4 80243E74 00000000 */   nop
.L80243E78:
/* C752F8 80243E78 0240202D */  daddu     $a0, $s2, $zero
/* C752FC 80243E7C 0260282D */  daddu     $a1, $s3, $zero
/* C75300 80243E80 0C090ED1 */  jal       kzn_08_UnkNpcDurationFlagFunc2
/* C75304 80243E84 0280302D */   daddu    $a2, $s4, $zero
/* C75308 80243E88 8E430070 */  lw        $v1, 0x70($s2)
/* C7530C 80243E8C 2402000E */  addiu     $v0, $zero, 0xe
/* C75310 80243E90 14620009 */  bne       $v1, $v0, .L80243EB8
/* C75314 80243E94 00000000 */   nop
/* C75318 80243E98 0240202D */  daddu     $a0, $s2, $zero
.L80243E9C:
/* C7531C 80243E9C 0260282D */  daddu     $a1, $s3, $zero
/* C75320 80243EA0 0C090EE9 */  jal       kzn_08_UnkNpcAIFunc30
/* C75324 80243EA4 0280302D */   daddu    $a2, $s4, $zero
/* C75328 80243EA8 08090FAE */  j         .L80243EB8
/* C7532C 80243EAC 00000000 */   nop
.L80243EB0:
/* C75330 80243EB0 0C0129CF */  jal       func_8004A73C
/* C75334 80243EB4 0240202D */   daddu    $a0, $s2, $zero
.L80243EB8:
/* C75338 80243EB8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C7533C 80243EBC 8FB50044 */  lw        $s5, 0x44($sp)
/* C75340 80243EC0 8FB40040 */  lw        $s4, 0x40($sp)
/* C75344 80243EC4 8FB3003C */  lw        $s3, 0x3c($sp)
/* C75348 80243EC8 8FB20038 */  lw        $s2, 0x38($sp)
/* C7534C 80243ECC 8FB10034 */  lw        $s1, 0x34($sp)
/* C75350 80243ED0 8FB00030 */  lw        $s0, 0x30($sp)
/* C75354 80243ED4 0000102D */  daddu     $v0, $zero, $zero
/* C75358 80243ED8 03E00008 */  jr        $ra
/* C7535C 80243EDC 27BD0050 */   addiu    $sp, $sp, 0x50

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C54_B95094
/* B95094 80241C54 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B95098 80241C58 AFB20038 */  sw        $s2, 0x38($sp)
/* B9509C 80241C5C 0080902D */  daddu     $s2, $a0, $zero
/* B950A0 80241C60 AFBF0048 */  sw        $ra, 0x48($sp)
/* B950A4 80241C64 AFB50044 */  sw        $s5, 0x44($sp)
/* B950A8 80241C68 AFB40040 */  sw        $s4, 0x40($sp)
/* B950AC 80241C6C AFB3003C */  sw        $s3, 0x3c($sp)
/* B950B0 80241C70 AFB10034 */  sw        $s1, 0x34($sp)
/* B950B4 80241C74 AFB00030 */  sw        $s0, 0x30($sp)
/* B950B8 80241C78 8E510148 */  lw        $s1, 0x148($s2)
/* B950BC 80241C7C 86240008 */  lh        $a0, 8($s1)
/* B950C0 80241C80 0C00EABB */  jal       get_npc_unsafe
/* B950C4 80241C84 00A0802D */   daddu    $s0, $a1, $zero
/* B950C8 80241C88 8E43000C */  lw        $v1, 0xc($s2)
/* B950CC 80241C8C 0240202D */  daddu     $a0, $s2, $zero
/* B950D0 80241C90 8C650000 */  lw        $a1, ($v1)
/* B950D4 80241C94 0C0B1EAF */  jal       get_variable
/* B950D8 80241C98 0040A82D */   daddu    $s5, $v0, $zero
/* B950DC 80241C9C AFA00010 */  sw        $zero, 0x10($sp)
/* B950E0 80241CA0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B950E4 80241CA4 8C630030 */  lw        $v1, 0x30($v1)
/* B950E8 80241CA8 AFA30014 */  sw        $v1, 0x14($sp)
/* B950EC 80241CAC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B950F0 80241CB0 8C63001C */  lw        $v1, 0x1c($v1)
/* B950F4 80241CB4 AFA30018 */  sw        $v1, 0x18($sp)
/* B950F8 80241CB8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B950FC 80241CBC 8C630024 */  lw        $v1, 0x24($v1)
/* B95100 80241CC0 AFA3001C */  sw        $v1, 0x1c($sp)
/* B95104 80241CC4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B95108 80241CC8 8C630028 */  lw        $v1, 0x28($v1)
/* B9510C 80241CCC 27B40010 */  addiu     $s4, $sp, 0x10
/* B95110 80241CD0 AFA30020 */  sw        $v1, 0x20($sp)
/* B95114 80241CD4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B95118 80241CD8 3C014348 */  lui       $at, 0x4348
/* B9511C 80241CDC 44810000 */  mtc1      $at, $f0
/* B95120 80241CE0 8C63002C */  lw        $v1, 0x2c($v1)
/* B95124 80241CE4 0040982D */  daddu     $s3, $v0, $zero
/* B95128 80241CE8 E7A00028 */  swc1      $f0, 0x28($sp)
/* B9512C 80241CEC A7A0002C */  sh        $zero, 0x2c($sp)
/* B95130 80241CF0 16000005 */  bnez      $s0, .L80241D08
/* B95134 80241CF4 AFA30024 */   sw       $v1, 0x24($sp)
/* B95138 80241CF8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B9513C 80241CFC 30420004 */  andi      $v0, $v0, 4
/* B95140 80241D00 10400011 */  beqz      $v0, .L80241D48
/* B95144 80241D04 00000000 */   nop
.L80241D08:
/* B95148 80241D08 AE400070 */  sw        $zero, 0x70($s2)
/* B9514C 80241D0C A6A0008E */  sh        $zero, 0x8e($s5)
/* B95150 80241D10 8E2200CC */  lw        $v0, 0xcc($s1)
/* B95154 80241D14 8C420000 */  lw        $v0, ($v0)
/* B95158 80241D18 AEA20028 */  sw        $v0, 0x28($s5)
/* B9515C 80241D1C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B95160 80241D20 30420004 */  andi      $v0, $v0, 4
/* B95164 80241D24 10400008 */  beqz      $v0, .L80241D48
/* B95168 80241D28 AE20006C */   sw       $zero, 0x6c($s1)
/* B9516C 80241D2C 24020063 */  addiu     $v0, $zero, 0x63
/* B95170 80241D30 AE420070 */  sw        $v0, 0x70($s2)
/* B95174 80241D34 AE400074 */  sw        $zero, 0x74($s2)
/* B95178 80241D38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B9517C 80241D3C 2403FFFB */  addiu     $v1, $zero, -5
/* B95180 80241D40 00431024 */  and       $v0, $v0, $v1
/* B95184 80241D44 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241D48:
/* B95188 80241D48 8E430070 */  lw        $v1, 0x70($s2)
/* B9518C 80241D4C 2410000B */  addiu     $s0, $zero, 0xb
/* B95190 80241D50 1070002A */  beq       $v1, $s0, .L80241DFC
/* B95194 80241D54 2862000C */   slti     $v0, $v1, 0xc
/* B95198 80241D58 1040000D */  beqz      $v0, .L80241D90
/* B9519C 80241D5C 24020001 */   addiu    $v0, $zero, 1
/* B951A0 80241D60 1062001A */  beq       $v1, $v0, .L80241DCC
/* B951A4 80241D64 28620002 */   slti     $v0, $v1, 2
/* B951A8 80241D68 10400005 */  beqz      $v0, .L80241D80
/* B951AC 80241D6C 2402000A */   addiu    $v0, $zero, 0xa
/* B951B0 80241D70 10600013 */  beqz      $v1, .L80241DC0
/* B951B4 80241D74 0240202D */   daddu    $a0, $s2, $zero
/* B951B8 80241D78 0809079F */  j         .L80241E7C
/* B951BC 80241D7C 00000000 */   nop
.L80241D80:
/* B951C0 80241D80 10620018 */  beq       $v1, $v0, .L80241DE4
/* B951C4 80241D84 0240202D */   daddu    $a0, $s2, $zero
/* B951C8 80241D88 0809079F */  j         .L80241E7C
/* B951CC 80241D8C 00000000 */   nop
.L80241D90:
/* B951D0 80241D90 2402000D */  addiu     $v0, $zero, 0xd
/* B951D4 80241D94 10620029 */  beq       $v1, $v0, .L80241E3C
/* B951D8 80241D98 0062102A */   slt      $v0, $v1, $v0
/* B951DC 80241D9C 14400020 */  bnez      $v0, .L80241E20
/* B951E0 80241DA0 0240202D */   daddu    $a0, $s2, $zero
/* B951E4 80241DA4 2402000E */  addiu     $v0, $zero, 0xe
/* B951E8 80241DA8 1062002D */  beq       $v1, $v0, .L80241E60
/* B951EC 80241DAC 24020063 */   addiu    $v0, $zero, 0x63
/* B951F0 80241DB0 10620030 */  beq       $v1, $v0, .L80241E74
/* B951F4 80241DB4 00000000 */   nop
/* B951F8 80241DB8 0809079F */  j         .L80241E7C
/* B951FC 80241DBC 00000000 */   nop
.L80241DC0:
/* B95200 80241DC0 0260282D */  daddu     $a1, $s3, $zero
/* B95204 80241DC4 0C090374 */  jal       func_80240DD0_B94210
/* B95208 80241DC8 0280302D */   daddu    $a2, $s4, $zero
.L80241DCC:
/* B9520C 80241DCC 0240202D */  daddu     $a0, $s2, $zero
/* B95210 80241DD0 0260282D */  daddu     $a1, $s3, $zero
/* B95214 80241DD4 0C09038F */  jal       func_80240E3C_B9427C
/* B95218 80241DD8 0280302D */   daddu    $a2, $s4, $zero
/* B9521C 80241DDC 0809079F */  j         .L80241E7C
/* B95220 80241DE0 00000000 */   nop
.L80241DE4:
/* B95224 80241DE4 0260282D */  daddu     $a1, $s3, $zero
/* B95228 80241DE8 0C0903CE */  jal       func_80240F38_B94378
/* B9522C 80241DEC 0280302D */   daddu    $a2, $s4, $zero
/* B95230 80241DF0 8E420070 */  lw        $v0, 0x70($s2)
/* B95234 80241DF4 14500021 */  bne       $v0, $s0, .L80241E7C
/* B95238 80241DF8 00000000 */   nop
.L80241DFC:
/* B9523C 80241DFC 0240202D */  daddu     $a0, $s2, $zero
/* B95240 80241E00 0260282D */  daddu     $a1, $s3, $zero
/* B95244 80241E04 0C09065E */  jal       func_80241978_B94DB8
/* B95248 80241E08 0280302D */   daddu    $a2, $s4, $zero
/* B9524C 80241E0C 8E430070 */  lw        $v1, 0x70($s2)
/* B95250 80241E10 2402000C */  addiu     $v0, $zero, 0xc
/* B95254 80241E14 14620019 */  bne       $v1, $v0, .L80241E7C
/* B95258 80241E18 00000000 */   nop
/* B9525C 80241E1C 0240202D */  daddu     $a0, $s2, $zero
.L80241E20:
/* B95260 80241E20 0260282D */  daddu     $a1, $s3, $zero
/* B95264 80241E24 0C090682 */  jal       func_80241A08_B94E48
/* B95268 80241E28 0280302D */   daddu    $a2, $s4, $zero
/* B9526C 80241E2C 8E430070 */  lw        $v1, 0x70($s2)
/* B95270 80241E30 2402000D */  addiu     $v0, $zero, 0xd
/* B95274 80241E34 14620011 */  bne       $v1, $v0, .L80241E7C
/* B95278 80241E38 00000000 */   nop
.L80241E3C:
/* B9527C 80241E3C 0240202D */  daddu     $a0, $s2, $zero
/* B95280 80241E40 0260282D */  daddu     $a1, $s3, $zero
/* B95284 80241E44 0C0906C2 */  jal       func_80241B08_B94F48
/* B95288 80241E48 0280302D */   daddu    $a2, $s4, $zero
/* B9528C 80241E4C 8E430070 */  lw        $v1, 0x70($s2)
/* B95290 80241E50 2402000E */  addiu     $v0, $zero, 0xe
/* B95294 80241E54 14620009 */  bne       $v1, $v0, .L80241E7C
/* B95298 80241E58 00000000 */   nop
/* B9529C 80241E5C 0240202D */  daddu     $a0, $s2, $zero
.L80241E60:
/* B952A0 80241E60 0260282D */  daddu     $a1, $s3, $zero
/* B952A4 80241E64 0C0906DA */  jal       func_80241B68_B94FA8
/* B952A8 80241E68 0280302D */   daddu    $a2, $s4, $zero
/* B952AC 80241E6C 0809079F */  j         .L80241E7C
/* B952B0 80241E70 00000000 */   nop
.L80241E74:
/* B952B4 80241E74 0C0129CF */  jal       func_8004A73C
/* B952B8 80241E78 0240202D */   daddu    $a0, $s2, $zero
.L80241E7C:
/* B952BC 80241E7C 8FBF0048 */  lw        $ra, 0x48($sp)
/* B952C0 80241E80 8FB50044 */  lw        $s5, 0x44($sp)
/* B952C4 80241E84 8FB40040 */  lw        $s4, 0x40($sp)
/* B952C8 80241E88 8FB3003C */  lw        $s3, 0x3c($sp)
/* B952CC 80241E8C 8FB20038 */  lw        $s2, 0x38($sp)
/* B952D0 80241E90 8FB10034 */  lw        $s1, 0x34($sp)
/* B952D4 80241E94 8FB00030 */  lw        $s0, 0x30($sp)
/* B952D8 80241E98 0000102D */  daddu     $v0, $zero, $zero
/* B952DC 80241E9C 03E00008 */  jr        $ra
/* B952E0 80241EA0 27BD0050 */   addiu    $sp, $sp, 0x50
/* B952E4 80241EA4 00000000 */  nop
/* B952E8 80241EA8 00000000 */  nop
/* B952EC 80241EAC 00000000 */  nop

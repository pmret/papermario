.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004AAB8
/* 25EB8 8004AAB8 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 25EBC 8004AABC AFB00088 */  sw        $s0, 0x88($sp)
/* 25EC0 8004AAC0 27B00020 */  addiu     $s0, $sp, 0x20
/* 25EC4 8004AAC4 0200202D */  daddu     $a0, $s0, $zero
/* 25EC8 8004AAC8 27A50038 */  addiu     $a1, $sp, 0x38
/* 25ECC 8004AACC 24060008 */  addiu     $a2, $zero, 8
/* 25ED0 8004AAD0 AFBF00AC */  sw        $ra, 0xac($sp)
/* 25ED4 8004AAD4 AFBE00A8 */  sw        $fp, 0xa8($sp)
/* 25ED8 8004AAD8 AFB700A4 */  sw        $s7, 0xa4($sp)
/* 25EDC 8004AADC AFB600A0 */  sw        $s6, 0xa0($sp)
/* 25EE0 8004AAE0 AFB5009C */  sw        $s5, 0x9c($sp)
/* 25EE4 8004AAE4 AFB40098 */  sw        $s4, 0x98($sp)
/* 25EE8 8004AAE8 AFB30094 */  sw        $s3, 0x94($sp)
/* 25EEC 8004AAEC AFB20090 */  sw        $s2, 0x90($sp)
/* 25EF0 8004AAF0 0C019554 */  jal       func_80065550
/* 25EF4 8004AAF4 AFB1008C */   sw       $s1, 0x8c($sp)
/* 25EF8 8004AAF8 27B10058 */  addiu     $s1, $sp, 0x58
/* 25EFC 8004AAFC 0220202D */  daddu     $a0, $s1, $zero
/* 25F00 8004AB00 27A50070 */  addiu     $a1, $sp, 0x70
/* 25F04 8004AB04 0C019554 */  jal       func_80065550
/* 25F08 8004AB08 24060001 */   addiu    $a2, $zero, 1
/* 25F0C 8004AB0C 27A40010 */  addiu     $a0, $sp, 0x10
/* 25F10 8004AB10 0200282D */  daddu     $a1, $s0, $zero
/* 25F14 8004AB14 0C017AB8 */  jal       func_8005EAE0
/* 25F18 8004AB18 24060003 */   addiu    $a2, $zero, 3
/* 25F1C 8004AB1C 0000902D */  daddu     $s2, $zero, $zero
/* 25F20 8004AB20 0240982D */  daddu     $s3, $s2, $zero
/* 25F24 8004AB24 0240A82D */  daddu     $s5, $s2, $zero
/* 25F28 8004AB28 3C14800A */  lui       $s4, %hi(D_800A1320)
/* 25F2C 8004AB2C 8E941320 */  lw        $s4, %lo(D_800A1320)($s4)
/* 25F30 8004AB30 3C1E800A */  lui       $fp, %hi(D_800A1438)
/* 25F34 8004AB34 8FDE1438 */  lw        $fp, %lo(D_800A1438)($fp)
/* 25F38 8004AB38 3C178008 */  lui       $s7, %hi(D_80078140)
/* 25F3C 8004AB3C 26F78140 */  addiu     $s7, $s7, %lo(D_80078140)
/* 25F40 8004AB40 AFB10080 */  sw        $s1, 0x80($sp)
/* 25F44 8004AB44 3C11800A */  lui       $s1, %hi(D_800A1330)
/* 25F48 8004AB48 26311330 */  addiu     $s1, $s1, %lo(D_800A1330)
/* 25F4C 8004AB4C AFA00078 */  sw        $zero, 0x78($sp)
.L8004AB50:
/* 25F50 8004AB50 27A40020 */  addiu     $a0, $sp, 0x20
.L8004AB54:
/* 25F54 8004AB54 27A50074 */  addiu     $a1, $sp, 0x74
.L8004AB58:
/* 25F58 8004AB58 0C0195B0 */  jal       func_800656C0
/* 25F5C 8004AB5C 24060001 */   addiu    $a2, $zero, 1
/* 25F60 8004AB60 8FA20074 */  lw        $v0, 0x74($sp)
/* 25F64 8004AB64 84430000 */  lh        $v1, ($v0)
/* 25F68 8004AB68 24080001 */  addiu     $t0, $zero, 1
/* 25F6C 8004AB6C 10680005 */  beq       $v1, $t0, .L8004AB84
/* 25F70 8004AB70 24020002 */   addiu    $v0, $zero, 2
/* 25F74 8004AB74 1062005F */  beq       $v1, $v0, .L8004ACF4
/* 25F78 8004AB78 27A40020 */   addiu    $a0, $sp, 0x20
/* 25F7C 8004AB7C 08012AD6 */  j         .L8004AB58
/* 25F80 8004AB80 27A50074 */   addiu    $a1, $sp, 0x74
.L8004AB84:
/* 25F84 8004AB84 8FA20078 */  lw        $v0, 0x78($sp)
/* 25F88 8004AB88 10400021 */  beqz      $v0, .L8004AC10
/* 25F8C 8004AB8C 24080001 */   addiu    $t0, $zero, 1
/* 25F90 8004AB90 3C028008 */  lui       $v0, %hi(D_80078150)
/* 25F94 8004AB94 90428150 */  lbu       $v0, %lo(D_80078150)($v0)
/* 25F98 8004AB98 1448001D */  bne       $v0, $t0, .L8004AC10
/* 25F9C 8004AB9C 0100302D */   daddu    $a2, $t0, $zero
/* 25FA0 8004ABA0 8FA80080 */  lw        $t0, 0x80($sp)
/* 25FA4 8004ABA4 3C04800E */  lui       $a0, %hi(D_800DA424)
/* 25FA8 8004ABA8 2484A424 */  addiu     $a0, $a0, %lo(D_800DA424)
/* 25FAC 8004ABAC AE340040 */  sw        $s4, 0x40($s1)
/* 25FB0 8004ABB0 AE280050 */  sw        $t0, 0x50($s1)
/* 25FB4 8004ABB4 8FA8007C */  lw        $t0, 0x7c($sp)
/* 25FB8 8004ABB8 0220282D */  daddu     $a1, $s1, $zero
/* 25FBC 8004ABBC 01141023 */  subu      $v0, $t0, $s4
/* 25FC0 8004ABC0 000210C3 */  sra       $v0, $v0, 3
/* 25FC4 8004ABC4 000210C0 */  sll       $v0, $v0, 3
/* 25FC8 8004ABC8 0C0195FC */  jal       func_800657F0
/* 25FCC 8004ABCC AE220044 */   sw       $v0, 0x44($s1)
/* 25FD0 8004ABD0 0C012BC6 */  jal       func_8004AF18
/* 25FD4 8004ABD4 26730001 */   addiu    $s3, $s3, 1
/* 25FD8 8004ABD8 0000282D */  daddu     $a1, $zero, $zero
/* 25FDC 8004ABDC 8FA40080 */  lw        $a0, 0x80($sp)
/* 25FE0 8004ABE0 0C0195B0 */  jal       func_800656C0
/* 25FE4 8004ABE4 24060001 */   addiu    $a2, $zero, 1
/* 25FE8 8004ABE8 24080003 */  addiu     $t0, $zero, 3
/* 25FEC 8004ABEC 52680001 */  beql      $s3, $t0, .L8004ABF4
/* 25FF0 8004ABF0 0000982D */   daddu    $s3, $zero, $zero
.L8004ABF4:
/* 25FF4 8004ABF4 26520001 */  addiu     $s2, $s2, 1
/* 25FF8 8004ABF8 24080003 */  addiu     $t0, $zero, 3
/* 25FFC 8004ABFC 16480004 */  bne       $s2, $t0, .L8004AC10
/* 26000 8004AC00 26310058 */   addiu    $s1, $s1, 0x58
/* 26004 8004AC04 3C11800A */  lui       $s1, %hi(D_800A1330)
/* 26008 8004AC08 26311330 */  addiu     $s1, $s1, %lo(D_800A1330)
/* 2600C 8004AC0C 0000902D */  daddu     $s2, $zero, $zero
.L8004AC10:
/* 26010 8004AC10 0C018548 */  jal       func_80061520
/* 26014 8004AC14 00000000 */   nop
/* 26018 8004AC18 04410003 */  bgez      $v0, .L8004AC28
/* 2601C 8004AC1C 00000000 */   nop
/* 26020 8004AC20 08012AD4 */  j         .L8004AB50
/* 26024 8004AC24 0000B02D */   daddu    $s6, $zero, $zero
.L8004AC28:
/* 26028 8004AC28 0C018544 */  jal       func_80061510
/* 2602C 8004AC2C 00000000 */   nop
/* 26030 8004AC30 8FA30078 */  lw        $v1, 0x78($sp)
/* 26034 8004AC34 10600011 */  beqz      $v1, .L8004AC7C
/* 26038 8004AC38 00028082 */   srl      $s0, $v0, 2
/* 2603C 8004AC3C 3C028008 */  lui       $v0, %hi(D_80078150)
/* 26040 8004AC40 90428150 */  lbu       $v0, %lo(D_80078150)($v0)
/* 26044 8004AC44 24080001 */  addiu     $t0, $zero, 1
/* 26048 8004AC48 1448000D */  bne       $v0, $t0, .L8004AC80
/* 2604C 8004AC4C 2A0200B8 */   slti     $v0, $s0, 0xb8
/* 26050 8004AC50 03C0202D */  daddu     $a0, $fp, $zero
/* 26054 8004AC54 0C018594 */  jal       func_80061650
/* 26058 8004AC58 00152880 */   sll      $a1, $s5, 2
/* 2605C 8004AC5C 00121080 */  sll       $v0, $s2, 2
/* 26060 8004AC60 3C14800A */  lui       $s4, %hi(D_800A1320)
/* 26064 8004AC64 0282A021 */  addu      $s4, $s4, $v0
/* 26068 8004AC68 8E941320 */  lw        $s4, %lo(D_800A1320)($s4)
/* 2606C 8004AC6C 00131080 */  sll       $v0, $s3, 2
/* 26070 8004AC70 3C1E800A */  lui       $fp, %hi(D_800A1438)
/* 26074 8004AC74 03C2F021 */  addu      $fp, $fp, $v0
/* 26078 8004AC78 8FDE1438 */  lw        $fp, %lo(D_800A1438)($fp)
.L8004AC7C:
/* 2607C 8004AC7C 2A0200B8 */  slti      $v0, $s0, 0xb8
.L8004AC80:
/* 26080 8004AC80 14400003 */  bnez      $v0, .L8004AC90
/* 26084 8004AC84 00000000 */   nop
/* 26088 8004AC88 12C00005 */  beqz      $s6, .L8004ACA0
/* 2608C 8004AC8C 24160001 */   addiu    $s6, $zero, 1
.L8004AC90:
/* 26090 8004AC90 3C15800A */  lui       $s5, %hi(D_800A1444)
/* 26094 8004AC94 8EB51444 */  lw        $s5, %lo(D_800A1444)($s5)
/* 26098 8004AC98 08012B2A */  j         .L8004ACA8
/* 2609C 8004AC9C 0000B02D */   daddu    $s6, $zero, $zero
.L8004ACA0:
/* 260A0 8004ACA0 3C15800A */  lui       $s5, %hi(D_800A1448)
/* 260A4 8004ACA4 8EB51448 */  lw        $s5, %lo(D_800A1448)($s5)
.L8004ACA8:
/* 260A8 8004ACA8 0C018798 */  jal       func_80061E60
/* 260AC 8004ACAC 03C0202D */   daddu    $a0, $fp, $zero
/* 260B0 8004ACB0 0280202D */  daddu     $a0, $s4, $zero
/* 260B4 8004ACB4 27A50078 */  addiu     $a1, $sp, 0x78
/* 260B8 8004ACB8 0040302D */  daddu     $a2, $v0, $zero
/* 260BC 8004ACBC 0C01589C */  jal       func_80056270
/* 260C0 8004ACC0 02A0382D */   daddu    $a3, $s5, $zero
/* 260C4 8004ACC4 3C038008 */  lui       $v1, %hi(D_80078144)
/* 260C8 8004ACC8 8C638144 */  lw        $v1, %lo(D_80078144)($v1)
/* 260CC 8004ACCC 1060FFA0 */  beqz      $v1, .L8004AB50
/* 260D0 8004ACD0 AFA2007C */   sw       $v0, 0x7c($sp)
/* 260D4 8004ACD4 92E20000 */  lbu       $v0, ($s7)
/* 260D8 8004ACD8 1040FF9E */  beqz      $v0, .L8004AB54
/* 260DC 8004ACDC 27A40020 */   addiu    $a0, $sp, 0x20
/* 260E0 8004ACE0 0040282D */  daddu     $a1, $v0, $zero
/* 260E4 8004ACE4 0060F809 */  jalr      $v1
/* 260E8 8004ACE8 24040001 */   addiu    $a0, $zero, 1
/* 260EC 8004ACEC 08012B45 */  j         .L8004AD14
/* 260F0 8004ACF0 00000000 */   nop
.L8004ACF4:
/* 260F4 8004ACF4 3C028008 */  lui       $v0, %hi(D_80078144)
/* 260F8 8004ACF8 8C428144 */  lw        $v0, %lo(D_80078144)($v0)
/* 260FC 8004ACFC 10400005 */  beqz      $v0, .L8004AD14
/* 26100 8004AD00 00000000 */   nop
/* 26104 8004AD04 3C058008 */  lui       $a1, %hi(D_80078140)
/* 26108 8004AD08 90A58140 */  lbu       $a1, %lo(D_80078140)($a1)
/* 2610C 8004AD0C 0040F809 */  jalr      $v0
/* 26110 8004AD10 24040002 */   addiu    $a0, $zero, 2
.L8004AD14:
/* 26114 8004AD14 92E20000 */  lbu       $v0, ($s7)
/* 26118 8004AD18 24420001 */  addiu     $v0, $v0, 1
/* 2611C 8004AD1C 08012AD4 */  j         .L8004AB50
/* 26120 8004AD20 A2E20000 */   sb       $v0, ($s7)
/* 26124 8004AD24 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 26128 8004AD28 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2612C 8004AD2C 0080982D */  daddu     $s3, $a0, $zero
/* 26130 8004AD30 30E700FF */  andi      $a3, $a3, 0xff
/* 26134 8004AD34 AFBF0020 */  sw        $ra, 0x20($sp)
/* 26138 8004AD38 AFB20018 */  sw        $s2, 0x18($sp)
/* 2613C 8004AD3C AFB10014 */  sw        $s1, 0x14($sp)
/* 26140 8004AD40 14E00005 */  bnez      $a3, .L8004AD58
/* 26144 8004AD44 AFB00010 */   sw       $s0, 0x10($sp)
/* 26148 8004AD48 0C018798 */  jal       func_80061E60
/* 2614C 8004AD4C 00000000 */   nop
/* 26150 8004AD50 08012BAE */  j         .L8004AEB8
/* 26154 8004AD54 00000000 */   nop
.L8004AD58:
/* 26158 8004AD58 0000802D */  daddu     $s0, $zero, $zero
/* 2615C 8004AD5C 3C11800A */  lui       $s1, %hi(D_800A19E4)
/* 26160 8004AD60 8E3119E4 */  lw        $s1, %lo(D_800A19E4)($s1)
/* 26164 8004AD64 1220000B */  beqz      $s1, .L8004AD94
/* 26168 8004AD68 02652821 */   addu     $a1, $s3, $a1
.L8004AD6C:
/* 2616C 8004AD6C 8E220008 */  lw        $v0, 8($s1)
/* 26170 8004AD70 24430500 */  addiu     $v1, $v0, 0x500
/* 26174 8004AD74 0262102B */  sltu      $v0, $s3, $v0
/* 26178 8004AD78 14400006 */  bnez      $v0, .L8004AD94
/* 2617C 8004AD7C 0065102A */   slt      $v0, $v1, $a1
/* 26180 8004AD80 1040001F */  beqz      $v0, .L8004AE00
/* 26184 8004AD84 0220802D */   daddu    $s0, $s1, $zero
/* 26188 8004AD88 8E310000 */  lw        $s1, ($s1)
/* 2618C 8004AD8C 1620FFF7 */  bnez      $s1, .L8004AD6C
/* 26190 8004AD90 00000000 */   nop
.L8004AD94:
/* 26194 8004AD94 3C12800A */  lui       $s2, %hi(D_800A19E0)
/* 26198 8004AD98 265219E0 */  addiu     $s2, $s2, %lo(D_800A19E0)
/* 2619C 8004AD9C 8E510008 */  lw        $s1, 8($s2)
/* 261A0 8004ADA0 16200006 */  bnez      $s1, .L8004ADBC
/* 261A4 8004ADA4 0220202D */   daddu    $a0, $s1, $zero
/* 261A8 8004ADA8 8E440004 */  lw        $a0, 4($s2)
/* 261AC 8004ADAC 0C018798 */  jal       func_80061E60
/* 261B0 8004ADB0 00000000 */   nop
/* 261B4 8004ADB4 08012BAE */  j         .L8004AEB8
/* 261B8 8004ADB8 00000000 */   nop
.L8004ADBC:
/* 261BC 8004ADBC 8E220000 */  lw        $v0, ($s1)
/* 261C0 8004ADC0 0C012C2F */  jal       func_8004B0BC
/* 261C4 8004ADC4 AE420008 */   sw       $v0, 8($s2)
/* 261C8 8004ADC8 12000005 */  beqz      $s0, .L8004ADE0
/* 261CC 8004ADCC 0220202D */   daddu    $a0, $s1, $zero
/* 261D0 8004ADD0 0C012C27 */  jal       func_8004B09C
/* 261D4 8004ADD4 0200282D */   daddu    $a1, $s0, $zero
/* 261D8 8004ADD8 08012B8D */  j         .L8004AE34
/* 261DC 8004ADDC 00000000 */   nop
.L8004ADE0:
/* 261E0 8004ADE0 8E450004 */  lw        $a1, 4($s2)
/* 261E4 8004ADE4 10A00010 */  beqz      $a1, .L8004AE28
/* 261E8 8004ADE8 00A0802D */   daddu    $s0, $a1, $zero
/* 261EC 8004ADEC AE510004 */  sw        $s1, 4($s2)
/* 261F0 8004ADF0 AE300000 */  sw        $s0, ($s1)
/* 261F4 8004ADF4 AE200004 */  sw        $zero, 4($s1)
/* 261F8 8004ADF8 08012B8D */  j         .L8004AE34
/* 261FC 8004ADFC AE110004 */   sw       $s1, 4($s0)
.L8004AE00:
/* 26200 8004AE00 8E240010 */  lw        $a0, 0x10($s1)
/* 26204 8004AE04 8E220008 */  lw        $v0, 8($s1)
/* 26208 8004AE08 3C038008 */  lui       $v1, %hi(D_8007814C)
/* 2620C 8004AE0C 8C63814C */  lw        $v1, %lo(D_8007814C)($v1)
/* 26210 8004AE10 00932021 */  addu      $a0, $a0, $s3
/* 26214 8004AE14 00822023 */  subu      $a0, $a0, $v0
/* 26218 8004AE18 0C018798 */  jal       func_80061E60
/* 2621C 8004AE1C AE23000C */   sw       $v1, 0xc($s1)
/* 26220 8004AE20 08012BAE */  j         .L8004AEB8
/* 26224 8004AE24 00000000 */   nop
.L8004AE28:
/* 26228 8004AE28 AE510004 */  sw        $s1, 4($s2)
/* 2622C 8004AE2C AE200000 */  sw        $zero, ($s1)
/* 26230 8004AE30 AE200004 */  sw        $zero, 4($s1)
.L8004AE34:
/* 26234 8004AE34 3C048008 */  lui       $a0, %hi(D_80078148)
/* 26238 8004AE38 24848148 */  addiu     $a0, $a0, %lo(D_80078148)
/* 2623C 8004AE3C 32700001 */  andi      $s0, $s3, 1
/* 26240 8004AE40 02709823 */  subu      $s3, $s3, $s0
/* 26244 8004AE44 3C02800A */  lui       $v0, %hi(D_800A1530)
/* 26248 8004AE48 24421530 */  addiu     $v0, $v0, %lo(D_800A1530)
/* 2624C 8004AE4C 8C830000 */  lw        $v1, ($a0)
/* 26250 8004AE50 8E320010 */  lw        $s2, 0x10($s1)
/* 26254 8004AE54 0000302D */  daddu     $a2, $zero, $zero
/* 26258 8004AE58 AE330008 */  sw        $s3, 8($s1)
/* 2625C 8004AE5C 00032840 */  sll       $a1, $v1, 1
/* 26260 8004AE60 00A32821 */  addu      $a1, $a1, $v1
/* 26264 8004AE64 000528C0 */  sll       $a1, $a1, 3
/* 26268 8004AE68 00A22821 */  addu      $a1, $a1, $v0
/* 2626C 8004AE6C 3C028008 */  lui       $v0, %hi(D_8007814C)
/* 26270 8004AE70 8C42814C */  lw        $v0, %lo(D_8007814C)($v0)
/* 26274 8004AE74 24630001 */  addiu     $v1, $v1, 1
/* 26278 8004AE78 AE22000C */  sw        $v0, 0xc($s1)
/* 2627C 8004AE7C AC830000 */  sw        $v1, ($a0)
/* 26280 8004AE80 A0A00002 */  sb        $zero, 2($a1)
/* 26284 8004AE84 3C04800A */  lui       $a0, %hi(carthandle)
/* 26288 8004AE88 8C84A618 */  lw        $a0, %lo(carthandle)($a0)
/* 2628C 8004AE8C 3C02800A */  lui       $v0, %hi(D_800A1450)
/* 26290 8004AE90 24421450 */  addiu     $v0, $v0, %lo(D_800A1450)
/* 26294 8004AE94 ACA20004 */  sw        $v0, 4($a1)
/* 26298 8004AE98 24020500 */  addiu     $v0, $zero, 0x500
/* 2629C 8004AE9C ACB20008 */  sw        $s2, 8($a1)
/* 262A0 8004AEA0 ACB3000C */  sw        $s3, 0xc($a1)
/* 262A4 8004AEA4 0C01837C */  jal       func_80060DF0
/* 262A8 8004AEA8 ACA20010 */   sw       $v0, 0x10($a1)
/* 262AC 8004AEAC 0C018798 */  jal       func_80061E60
/* 262B0 8004AEB0 0240202D */   daddu    $a0, $s2, $zero
/* 262B4 8004AEB4 00501021 */  addu      $v0, $v0, $s0
.L8004AEB8:
/* 262B8 8004AEB8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 262BC 8004AEBC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 262C0 8004AEC0 8FB20018 */  lw        $s2, 0x18($sp)
/* 262C4 8004AEC4 8FB10014 */  lw        $s1, 0x14($sp)
/* 262C8 8004AEC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 262CC 8004AECC 03E00008 */  jr        $ra
/* 262D0 8004AED0 27BD0028 */   addiu    $sp, $sp, 0x28

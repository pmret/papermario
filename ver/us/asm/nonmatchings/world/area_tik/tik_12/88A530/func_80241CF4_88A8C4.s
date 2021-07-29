.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802449D8_88D5A8
.word L80242100_88ACD0, L8024210C_88ACDC, L8024210C_88ACDC, L8024210C_88ACDC, L8024210C_88ACDC, L8024210C_88ACDC, L8024210C_88ACDC, L8024210C_88ACDC, L80242100_88ACD0, L8024210C_88ACDC, L80242100_88ACD0, L8024210C_88ACDC, L80242100_88ACD0, L8024210C_88ACDC, L80242100_88ACD0, L8024210C_88ACDC, L8024210C_88ACDC, L8024210C_88ACDC, L80242100_88ACD0, L8024210C_88ACDC, L80242100_88ACD0, 0

.section .text

glabel func_80241CF4_88A8C4
/* 88A8C4 80241CF4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 88A8C8 80241CF8 AFB3005C */  sw        $s3, 0x5c($sp)
/* 88A8CC 80241CFC 0080982D */  daddu     $s3, $a0, $zero
/* 88A8D0 80241D00 AFBF0068 */  sw        $ra, 0x68($sp)
/* 88A8D4 80241D04 AFB50064 */  sw        $s5, 0x64($sp)
/* 88A8D8 80241D08 AFB40060 */  sw        $s4, 0x60($sp)
/* 88A8DC 80241D0C AFB20058 */  sw        $s2, 0x58($sp)
/* 88A8E0 80241D10 AFB10054 */  sw        $s1, 0x54($sp)
/* 88A8E4 80241D14 AFB00050 */  sw        $s0, 0x50($sp)
/* 88A8E8 80241D18 8E710148 */  lw        $s1, 0x148($s3)
/* 88A8EC 80241D1C 86240008 */  lh        $a0, 8($s1)
/* 88A8F0 80241D20 0C00EABB */  jal       get_npc_unsafe
/* 88A8F4 80241D24 00A0802D */   daddu    $s0, $a1, $zero
/* 88A8F8 80241D28 8E63000C */  lw        $v1, 0xc($s3)
/* 88A8FC 80241D2C 0260202D */  daddu     $a0, $s3, $zero
/* 88A900 80241D30 8C650000 */  lw        $a1, ($v1)
/* 88A904 80241D34 0C0B1EAF */  jal       get_variable
/* 88A908 80241D38 0040902D */   daddu    $s2, $v0, $zero
/* 88A90C 80241D3C AFA00028 */  sw        $zero, 0x28($sp)
/* 88A910 80241D40 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 88A914 80241D44 8C630030 */  lw        $v1, 0x30($v1)
/* 88A918 80241D48 AFA3002C */  sw        $v1, 0x2c($sp)
/* 88A91C 80241D4C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 88A920 80241D50 8C63001C */  lw        $v1, 0x1c($v1)
/* 88A924 80241D54 AFA30030 */  sw        $v1, 0x30($sp)
/* 88A928 80241D58 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 88A92C 80241D5C 8C630024 */  lw        $v1, 0x24($v1)
/* 88A930 80241D60 AFA30034 */  sw        $v1, 0x34($sp)
/* 88A934 80241D64 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 88A938 80241D68 8C630028 */  lw        $v1, 0x28($v1)
/* 88A93C 80241D6C 27B50028 */  addiu     $s5, $sp, 0x28
/* 88A940 80241D70 AFA30038 */  sw        $v1, 0x38($sp)
/* 88A944 80241D74 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 88A948 80241D78 3C0142C8 */  lui       $at, 0x42c8
/* 88A94C 80241D7C 44810000 */  mtc1      $at, $f0
/* 88A950 80241D80 8C63002C */  lw        $v1, 0x2c($v1)
/* 88A954 80241D84 0040A02D */  daddu     $s4, $v0, $zero
/* 88A958 80241D88 E7A00040 */  swc1      $f0, 0x40($sp)
/* 88A95C 80241D8C A7A00044 */  sh        $zero, 0x44($sp)
/* 88A960 80241D90 12000009 */  beqz      $s0, .L80241DB8
/* 88A964 80241D94 AFA3003C */   sw       $v1, 0x3c($sp)
/* 88A968 80241D98 864300A8 */  lh        $v1, 0xa8($s2)
/* 88A96C 80241D9C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 88A970 80241DA0 AE20008C */  sw        $zero, 0x8c($s1)
/* 88A974 80241DA4 A22000B5 */  sb        $zero, 0xb5($s1)
/* 88A978 80241DA8 34420008 */  ori       $v0, $v0, 8
/* 88A97C 80241DAC AE230084 */  sw        $v1, 0x84($s1)
/* 88A980 80241DB0 08090772 */  j         .L80241DC8
/* 88A984 80241DB4 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241DB8:
/* 88A988 80241DB8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 88A98C 80241DBC 30420004 */  andi      $v0, $v0, 4
/* 88A990 80241DC0 10400047 */  beqz      $v0, .L80241EE0
/* 88A994 80241DC4 00000000 */   nop
.L80241DC8:
/* 88A998 80241DC8 AE600070 */  sw        $zero, 0x70($s3)
/* 88A99C 80241DCC A640008E */  sh        $zero, 0x8e($s2)
/* 88A9A0 80241DD0 8E2300CC */  lw        $v1, 0xcc($s1)
/* 88A9A4 80241DD4 2404F7FF */  addiu     $a0, $zero, -0x801
/* 88A9A8 80241DD8 A2200007 */  sb        $zero, 7($s1)
/* 88A9AC 80241DDC 8E420000 */  lw        $v0, ($s2)
/* 88A9B0 80241DE0 8C630000 */  lw        $v1, ($v1)
/* 88A9B4 80241DE4 00441024 */  and       $v0, $v0, $a0
/* 88A9B8 80241DE8 AE420000 */  sw        $v0, ($s2)
/* 88A9BC 80241DEC AE430028 */  sw        $v1, 0x28($s2)
/* 88A9C0 80241DF0 96220086 */  lhu       $v0, 0x86($s1)
/* 88A9C4 80241DF4 A64200A8 */  sh        $v0, 0xa8($s2)
/* 88A9C8 80241DF8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 88A9CC 80241DFC AE200090 */  sw        $zero, 0x90($s1)
/* 88A9D0 80241E00 8C420034 */  lw        $v0, 0x34($v0)
/* 88A9D4 80241E04 14400006 */  bnez      $v0, .L80241E20
/* 88A9D8 80241E08 2403FDFF */   addiu    $v1, $zero, -0x201
/* 88A9DC 80241E0C 8E420000 */  lw        $v0, ($s2)
/* 88A9E0 80241E10 2403FFF7 */  addiu     $v1, $zero, -9
/* 88A9E4 80241E14 34420200 */  ori       $v0, $v0, 0x200
/* 88A9E8 80241E18 0809078B */  j         .L80241E2C
/* 88A9EC 80241E1C 00431024 */   and      $v0, $v0, $v1
.L80241E20:
/* 88A9F0 80241E20 8E420000 */  lw        $v0, ($s2)
/* 88A9F4 80241E24 00431024 */  and       $v0, $v0, $v1
/* 88A9F8 80241E28 34420008 */  ori       $v0, $v0, 8
.L80241E2C:
/* 88A9FC 80241E2C AE420000 */  sw        $v0, ($s2)
/* 88AA00 80241E30 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 88AA04 80241E34 30420004 */  andi      $v0, $v0, 4
/* 88AA08 80241E38 1040001E */  beqz      $v0, .L80241EB4
/* 88AA0C 80241E3C 24040002 */   addiu    $a0, $zero, 2
/* 88AA10 80241E40 0240282D */  daddu     $a1, $s2, $zero
/* 88AA14 80241E44 0000302D */  daddu     $a2, $zero, $zero
/* 88AA18 80241E48 24020063 */  addiu     $v0, $zero, 0x63
/* 88AA1C 80241E4C AE620070 */  sw        $v0, 0x70($s3)
/* 88AA20 80241E50 AE600074 */  sw        $zero, 0x74($s3)
/* 88AA24 80241E54 864300A8 */  lh        $v1, 0xa8($s2)
/* 88AA28 80241E58 3C013F80 */  lui       $at, 0x3f80
/* 88AA2C 80241E5C 44810000 */  mtc1      $at, $f0
/* 88AA30 80241E60 3C014000 */  lui       $at, 0x4000
/* 88AA34 80241E64 44811000 */  mtc1      $at, $f2
/* 88AA38 80241E68 3C01C1A0 */  lui       $at, 0xc1a0
/* 88AA3C 80241E6C 44812000 */  mtc1      $at, $f4
/* 88AA40 80241E70 24020028 */  addiu     $v0, $zero, 0x28
/* 88AA44 80241E74 AFA2001C */  sw        $v0, 0x1c($sp)
/* 88AA48 80241E78 44833000 */  mtc1      $v1, $f6
/* 88AA4C 80241E7C 00000000 */  nop
/* 88AA50 80241E80 468031A0 */  cvt.s.w   $f6, $f6
/* 88AA54 80241E84 44073000 */  mfc1      $a3, $f6
/* 88AA58 80241E88 27A20048 */  addiu     $v0, $sp, 0x48
/* 88AA5C 80241E8C AFA20020 */  sw        $v0, 0x20($sp)
/* 88AA60 80241E90 E7A00010 */  swc1      $f0, 0x10($sp)
/* 88AA64 80241E94 E7A20014 */  swc1      $f2, 0x14($sp)
/* 88AA68 80241E98 0C01BFA4 */  jal       fx_emote
/* 88AA6C 80241E9C E7A40018 */   swc1     $f4, 0x18($sp)
/* 88AA70 80241EA0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 88AA74 80241EA4 2403FFFB */  addiu     $v1, $zero, -5
/* 88AA78 80241EA8 00431024 */  and       $v0, $v0, $v1
/* 88AA7C 80241EAC 080907B8 */  j         .L80241EE0
/* 88AA80 80241EB0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241EB4:
/* 88AA84 80241EB4 8E220000 */  lw        $v0, ($s1)
/* 88AA88 80241EB8 3C034000 */  lui       $v1, 0x4000
/* 88AA8C 80241EBC 00431024 */  and       $v0, $v0, $v1
/* 88AA90 80241EC0 10400007 */  beqz      $v0, .L80241EE0
/* 88AA94 80241EC4 3C03BFFF */   lui      $v1, 0xbfff
/* 88AA98 80241EC8 2402000C */  addiu     $v0, $zero, 0xc
/* 88AA9C 80241ECC AE620070 */  sw        $v0, 0x70($s3)
/* 88AAA0 80241ED0 8E220000 */  lw        $v0, ($s1)
/* 88AAA4 80241ED4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 88AAA8 80241ED8 00431024 */  and       $v0, $v0, $v1
/* 88AAAC 80241EDC AE220000 */  sw        $v0, ($s1)
.L80241EE0:
/* 88AAB0 80241EE0 8E220090 */  lw        $v0, 0x90($s1)
/* 88AAB4 80241EE4 1840000C */  blez      $v0, .L80241F18
/* 88AAB8 80241EE8 2442FFFF */   addiu    $v0, $v0, -1
/* 88AABC 80241EEC 14400087 */  bnez      $v0, L8024210C_88ACDC
/* 88AAC0 80241EF0 AE220090 */   sw       $v0, 0x90($s1)
/* 88AAC4 80241EF4 3C03FFAA */  lui       $v1, 0xffaa
/* 88AAC8 80241EF8 8E420028 */  lw        $v0, 0x28($s2)
/* 88AACC 80241EFC 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* 88AAD0 80241F00 00431021 */  addu      $v0, $v0, $v1
/* 88AAD4 80241F04 2C420002 */  sltiu     $v0, $v0, 2
/* 88AAD8 80241F08 10400003 */  beqz      $v0, .L80241F18
/* 88AADC 80241F0C 3C020055 */   lui      $v0, 0x55
/* 88AAE0 80241F10 3442000C */  ori       $v0, $v0, 0xc
/* 88AAE4 80241F14 AE420028 */  sw        $v0, 0x28($s2)
.L80241F18:
/* 88AAE8 80241F18 8E630070 */  lw        $v1, 0x70($s3)
/* 88AAEC 80241F1C 2402000C */  addiu     $v0, $zero, 0xc
/* 88AAF0 80241F20 10620048 */  beq       $v1, $v0, .L80242044
/* 88AAF4 80241F24 2862000D */   slti     $v0, $v1, 0xd
/* 88AAF8 80241F28 1040000F */  beqz      $v0, .L80241F68
/* 88AAFC 80241F2C 24100001 */   addiu    $s0, $zero, 1
/* 88AB00 80241F30 1070001E */  beq       $v1, $s0, .L80241FAC
/* 88AB04 80241F34 28620002 */   slti     $v0, $v1, 2
/* 88AB08 80241F38 10400005 */  beqz      $v0, .L80241F50
/* 88AB0C 80241F3C 24020002 */   addiu    $v0, $zero, 2
/* 88AB10 80241F40 10600015 */  beqz      $v1, .L80241F98
/* 88AB14 80241F44 0260202D */   daddu    $a0, $s3, $zero
/* 88AB18 80241F48 08090828 */  j         .L802420A0
/* 88AB1C 80241F4C 00000000 */   nop
.L80241F50:
/* 88AB20 80241F50 1062001C */  beq       $v1, $v0, .L80241FC4
/* 88AB24 80241F54 24020003 */   addiu    $v0, $zero, 3
/* 88AB28 80241F58 10620035 */  beq       $v1, $v0, .L80242030
/* 88AB2C 80241F5C 0260202D */   daddu    $a0, $s3, $zero
/* 88AB30 80241F60 08090828 */  j         .L802420A0
/* 88AB34 80241F64 00000000 */   nop
.L80241F68:
/* 88AB38 80241F68 2402000E */  addiu     $v0, $zero, 0xe
/* 88AB3C 80241F6C 1062003F */  beq       $v1, $v0, .L8024206C
/* 88AB40 80241F70 0062102A */   slt      $v0, $v1, $v0
/* 88AB44 80241F74 14400038 */  bnez      $v0, .L80242058
/* 88AB48 80241F78 0260202D */   daddu    $a0, $s3, $zero
/* 88AB4C 80241F7C 2402000F */  addiu     $v0, $zero, 0xf
/* 88AB50 80241F80 10620040 */  beq       $v1, $v0, .L80242084
/* 88AB54 80241F84 24020063 */   addiu    $v0, $zero, 0x63
/* 88AB58 80241F88 10620043 */  beq       $v1, $v0, .L80242098
/* 88AB5C 80241F8C 00000000 */   nop
/* 88AB60 80241F90 08090828 */  j         .L802420A0
/* 88AB64 80241F94 00000000 */   nop
.L80241F98:
/* 88AB68 80241F98 0280282D */  daddu     $a1, $s4, $zero
/* 88AB6C 80241F9C 0C012568 */  jal       func_800495A0
/* 88AB70 80241FA0 02A0302D */   daddu    $a2, $s5, $zero
/* 88AB74 80241FA4 96220086 */  lhu       $v0, 0x86($s1)
/* 88AB78 80241FA8 A64200A8 */  sh        $v0, 0xa8($s2)
.L80241FAC:
/* 88AB7C 80241FAC 0260202D */  daddu     $a0, $s3, $zero
/* 88AB80 80241FB0 0280282D */  daddu     $a1, $s4, $zero
/* 88AB84 80241FB4 0C0125AE */  jal       func_800496B8
/* 88AB88 80241FB8 02A0302D */   daddu    $a2, $s5, $zero
/* 88AB8C 80241FBC 08090828 */  j         .L802420A0
/* 88AB90 80241FC0 00000000 */   nop
.L80241FC4:
/* 88AB94 80241FC4 0260202D */  daddu     $a0, $s3, $zero
/* 88AB98 80241FC8 0280282D */  daddu     $a1, $s4, $zero
/* 88AB9C 80241FCC 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* 88ABA0 80241FD0 02A0302D */   daddu    $a2, $s5, $zero
/* 88ABA4 80241FD4 8E230088 */  lw        $v1, 0x88($s1)
/* 88ABA8 80241FD8 24020006 */  addiu     $v0, $zero, 6
/* 88ABAC 80241FDC 14620014 */  bne       $v1, $v0, .L80242030
/* 88ABB0 80241FE0 0260202D */   daddu    $a0, $s3, $zero
/* 88ABB4 80241FE4 0C00A67F */  jal       rand_int
/* 88ABB8 80241FE8 24040064 */   addiu    $a0, $zero, 0x64
/* 88ABBC 80241FEC 28420021 */  slti      $v0, $v0, 0x21
/* 88ABC0 80241FF0 5040000F */  beql      $v0, $zero, .L80242030
/* 88ABC4 80241FF4 0260202D */   daddu    $a0, $s3, $zero
/* 88ABC8 80241FF8 8E22008C */  lw        $v0, 0x8c($s1)
/* 88ABCC 80241FFC 10400005 */  beqz      $v0, .L80242014
/* 88ABD0 80242000 3C020055 */   lui      $v0, 0x55
/* 88ABD4 80242004 3442002F */  ori       $v0, $v0, 0x2f
/* 88ABD8 80242008 AE20008C */  sw        $zero, 0x8c($s1)
/* 88ABDC 8024200C 08090808 */  j         .L80242020
/* 88ABE0 80242010 A22000B5 */   sb       $zero, 0xb5($s1)
.L80242014:
/* 88ABE4 80242014 3442002E */  ori       $v0, $v0, 0x2e
/* 88ABE8 80242018 AE30008C */  sw        $s0, 0x8c($s1)
/* 88ABEC 8024201C A23000B5 */  sb        $s0, 0xb5($s1)
.L80242020:
/* 88ABF0 80242020 AE420028 */  sw        $v0, 0x28($s2)
/* 88ABF4 80242024 24020007 */  addiu     $v0, $zero, 7
/* 88ABF8 80242028 08090843 */  j         L8024210C_88ACDC
/* 88ABFC 8024202C AE220090 */   sw       $v0, 0x90($s1)
.L80242030:
/* 88AC00 80242030 0280282D */  daddu     $a1, $s4, $zero
/* 88AC04 80242034 0C012701 */  jal       func_80049C04
/* 88AC08 80242038 02A0302D */   daddu    $a2, $s5, $zero
/* 88AC0C 8024203C 08090828 */  j         .L802420A0
/* 88AC10 80242040 00000000 */   nop
.L80242044:
/* 88AC14 80242044 0260202D */  daddu     $a0, $s3, $zero
/* 88AC18 80242048 0280282D */  daddu     $a1, $s4, $zero
/* 88AC1C 8024204C 0C090658 */  jal       tik_12_set_script_owner_npc_anim
/* 88AC20 80242050 02A0302D */   daddu    $a2, $s5, $zero
/* 88AC24 80242054 0260202D */  daddu     $a0, $s3, $zero
.L80242058:
/* 88AC28 80242058 0280282D */  daddu     $a1, $s4, $zero
/* 88AC2C 8024205C 0C090677 */  jal       tik_12_UnkDistFunc
/* 88AC30 80242060 02A0302D */   daddu    $a2, $s5, $zero
/* 88AC34 80242064 08090828 */  j         .L802420A0
/* 88AC38 80242068 00000000 */   nop
.L8024206C:
/* 88AC3C 8024206C 0260202D */  daddu     $a0, $s3, $zero
/* 88AC40 80242070 0280282D */  daddu     $a1, $s4, $zero
/* 88AC44 80242074 0C0906C4 */  jal       tik_12_UnkNpcAIFunc12
/* 88AC48 80242078 02A0302D */   daddu    $a2, $s5, $zero
/* 88AC4C 8024207C 08090828 */  j         .L802420A0
/* 88AC50 80242080 00000000 */   nop
.L80242084:
/* 88AC54 80242084 0280282D */  daddu     $a1, $s4, $zero
/* 88AC58 80242088 0C09071D */  jal       tik_12_set_script_owner_npc_col_height
/* 88AC5C 8024208C 02A0302D */   daddu    $a2, $s5, $zero
/* 88AC60 80242090 08090828 */  j         .L802420A0
/* 88AC64 80242094 00000000 */   nop
.L80242098:
/* 88AC68 80242098 0C0129CF */  jal       func_8004A73C
/* 88AC6C 8024209C 0260202D */   daddu    $a0, $s3, $zero
.L802420A0:
/* 88AC70 802420A0 8E230088 */  lw        $v1, 0x88($s1)
/* 88AC74 802420A4 24020006 */  addiu     $v0, $zero, 6
/* 88AC78 802420A8 14620019 */  bne       $v1, $v0, .L80242110
/* 88AC7C 802420AC 0000102D */   daddu    $v0, $zero, $zero
/* 88AC80 802420B0 8E22008C */  lw        $v0, 0x8c($s1)
/* 88AC84 802420B4 10400003 */  beqz      $v0, .L802420C4
/* 88AC88 802420B8 24020001 */   addiu    $v0, $zero, 1
/* 88AC8C 802420BC 08090832 */  j         .L802420C8
/* 88AC90 802420C0 A22200B5 */   sb       $v0, 0xb5($s1)
.L802420C4:
/* 88AC94 802420C4 A22000B5 */  sb        $zero, 0xb5($s1)
.L802420C8:
/* 88AC98 802420C8 8E22008C */  lw        $v0, 0x8c($s1)
/* 88AC9C 802420CC 1040000F */  beqz      $v0, L8024210C_88ACDC
/* 88ACA0 802420D0 3C03FFAA */   lui      $v1, 0xffaa
/* 88ACA4 802420D4 8E420028 */  lw        $v0, 0x28($s2)
/* 88ACA8 802420D8 3463FFFC */  ori       $v1, $v1, 0xfffc
/* 88ACAC 802420DC 00431821 */  addu      $v1, $v0, $v1
/* 88ACB0 802420E0 2C620015 */  sltiu     $v0, $v1, 0x15
/* 88ACB4 802420E4 10400009 */  beqz      $v0, L8024210C_88ACDC
/* 88ACB8 802420E8 00031080 */   sll      $v0, $v1, 2
/* 88ACBC 802420EC 3C018024 */  lui       $at, %hi(jtbl_802449D8_88D5A8)
/* 88ACC0 802420F0 00220821 */  addu      $at, $at, $v0
/* 88ACC4 802420F4 8C2249D8 */  lw        $v0, %lo(jtbl_802449D8_88D5A8)($at)
/* 88ACC8 802420F8 00400008 */  jr        $v0
/* 88ACCC 802420FC 00000000 */   nop
glabel L80242100_88ACD0
/* 88ACD0 80242100 8E420028 */  lw        $v0, 0x28($s2)
/* 88ACD4 80242104 24420001 */  addiu     $v0, $v0, 1
/* 88ACD8 80242108 AE420028 */  sw        $v0, 0x28($s2)
glabel L8024210C_88ACDC
/* 88ACDC 8024210C 0000102D */  daddu     $v0, $zero, $zero
.L80242110:
/* 88ACE0 80242110 8FBF0068 */  lw        $ra, 0x68($sp)
/* 88ACE4 80242114 8FB50064 */  lw        $s5, 0x64($sp)
/* 88ACE8 80242118 8FB40060 */  lw        $s4, 0x60($sp)
/* 88ACEC 8024211C 8FB3005C */  lw        $s3, 0x5c($sp)
/* 88ACF0 80242120 8FB20058 */  lw        $s2, 0x58($sp)
/* 88ACF4 80242124 8FB10054 */  lw        $s1, 0x54($sp)
/* 88ACF8 80242128 8FB00050 */  lw        $s0, 0x50($sp)
/* 88ACFC 8024212C 03E00008 */  jr        $ra
/* 88AD00 80242130 27BD0070 */   addiu    $sp, $sp, 0x70

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219CF0_4B2EE0
/* 4B2EE0 80219CF0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 4B2EE4 80219CF4 AFB20058 */  sw        $s2, 0x58($sp)
/* 4B2EE8 80219CF8 0080902D */  daddu     $s2, $a0, $zero
/* 4B2EEC 80219CFC AFBF005C */  sw        $ra, 0x5c($sp)
/* 4B2EF0 80219D00 AFB10054 */  sw        $s1, 0x54($sp)
/* 4B2EF4 80219D04 AFB00050 */  sw        $s0, 0x50($sp)
/* 4B2EF8 80219D08 8E50000C */  lw        $s0, 0xc($s2)
/* 4B2EFC 80219D0C 0C09A75B */  jal       get_actor
/* 4B2F00 80219D10 24040204 */   addiu    $a0, $zero, 0x204
/* 4B2F04 80219D14 8C510094 */  lw        $s1, 0x94($v0)
/* 4B2F08 80219D18 24020003 */  addiu     $v0, $zero, 3
/* 4B2F0C 80219D1C 1222001D */  beq       $s1, $v0, .L80219D94
/* 4B2F10 80219D20 2A220004 */   slti     $v0, $s1, 4
/* 4B2F14 80219D24 10400005 */  beqz      $v0, .L80219D3C
/* 4B2F18 80219D28 24020002 */   addiu    $v0, $zero, 2
/* 4B2F1C 80219D2C 12220008 */  beq       $s1, $v0, .L80219D50
/* 4B2F20 80219D30 0000202D */   daddu    $a0, $zero, $zero
/* 4B2F24 80219D34 080867A0 */  j         .L80219E80
/* 4B2F28 80219D38 2622FFFF */   addiu    $v0, $s1, -1
.L80219D3C:
/* 4B2F2C 80219D3C 24020004 */  addiu     $v0, $zero, 4
/* 4B2F30 80219D40 1222002D */  beq       $s1, $v0, .L80219DF8
/* 4B2F34 80219D44 0000202D */   daddu    $a0, $zero, $zero
/* 4B2F38 80219D48 080867A0 */  j         .L80219E80
/* 4B2F3C 80219D4C 2622FFFF */   addiu    $v0, $s1, -1
.L80219D50:
/* 4B2F40 80219D50 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B2F44 80219D54 24040003 */   addiu    $a0, $zero, 3
/* 4B2F48 80219D58 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B2F4C 80219D5C E7A00020 */  swc1      $f0, 0x20($sp)
/* 4B2F50 80219D60 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B2F54 80219D64 E7A00024 */  swc1      $f0, 0x24($sp)
/* 4B2F58 80219D68 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B2F5C 80219D6C 24040006 */  addiu     $a0, $zero, 6
/* 4B2F60 80219D70 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B2F64 80219D74 E7A00028 */   swc1     $f0, 0x28($sp)
/* 4B2F68 80219D78 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B2F6C 80219D7C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 4B2F70 80219D80 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B2F74 80219D84 E7A00030 */  swc1      $f0, 0x30($sp)
/* 4B2F78 80219D88 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B2F7C 80219D8C 0808679E */  j         .L80219E78
/* 4B2F80 80219D90 E7A00034 */   swc1     $f0, 0x34($sp)
.L80219D94:
/* 4B2F84 80219D94 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B2F88 80219D98 24040003 */   addiu    $a0, $zero, 3
/* 4B2F8C 80219D9C C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B2F90 80219DA0 E7A00020 */  swc1      $f0, 0x20($sp)
/* 4B2F94 80219DA4 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B2F98 80219DA8 E7A00024 */  swc1      $f0, 0x24($sp)
/* 4B2F9C 80219DAC C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B2FA0 80219DB0 24040005 */  addiu     $a0, $zero, 5
/* 4B2FA4 80219DB4 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B2FA8 80219DB8 E7A00028 */   swc1     $f0, 0x28($sp)
/* 4B2FAC 80219DBC C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B2FB0 80219DC0 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 4B2FB4 80219DC4 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B2FB8 80219DC8 E7A00030 */  swc1      $f0, 0x30($sp)
/* 4B2FBC 80219DCC C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B2FC0 80219DD0 24040006 */  addiu     $a0, $zero, 6
/* 4B2FC4 80219DD4 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B2FC8 80219DD8 E7A00034 */   swc1     $f0, 0x34($sp)
/* 4B2FCC 80219DDC C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B2FD0 80219DE0 E7A00038 */  swc1      $f0, 0x38($sp)
/* 4B2FD4 80219DE4 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B2FD8 80219DE8 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 4B2FDC 80219DEC C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B2FE0 80219DF0 0808679E */  j         .L80219E78
/* 4B2FE4 80219DF4 E7A00040 */   swc1     $f0, 0x40($sp)
.L80219DF8:
/* 4B2FE8 80219DF8 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B2FEC 80219DFC 24040003 */   addiu    $a0, $zero, 3
/* 4B2FF0 80219E00 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B2FF4 80219E04 E7A00020 */  swc1      $f0, 0x20($sp)
/* 4B2FF8 80219E08 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B2FFC 80219E0C E7A00024 */  swc1      $f0, 0x24($sp)
/* 4B3000 80219E10 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B3004 80219E14 24040004 */  addiu     $a0, $zero, 4
/* 4B3008 80219E18 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B300C 80219E1C E7A00028 */   swc1     $f0, 0x28($sp)
/* 4B3010 80219E20 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B3014 80219E24 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 4B3018 80219E28 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B301C 80219E2C E7A00030 */  swc1      $f0, 0x30($sp)
/* 4B3020 80219E30 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B3024 80219E34 24040005 */  addiu     $a0, $zero, 5
/* 4B3028 80219E38 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B302C 80219E3C E7A00034 */   swc1     $f0, 0x34($sp)
/* 4B3030 80219E40 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B3034 80219E44 E7A00038 */  swc1      $f0, 0x38($sp)
/* 4B3038 80219E48 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B303C 80219E4C E7A0003C */  swc1      $f0, 0x3c($sp)
/* 4B3040 80219E50 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B3044 80219E54 24040006 */  addiu     $a0, $zero, 6
/* 4B3048 80219E58 0C086714 */  jal       b_area_trd_part_2_yellow_ninja_koopa_UnkEnemyFunc
/* 4B304C 80219E5C E7A00040 */   swc1     $f0, 0x40($sp)
/* 4B3050 80219E60 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B3054 80219E64 E7A00044 */  swc1      $f0, 0x44($sp)
/* 4B3058 80219E68 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B305C 80219E6C E7A00048 */  swc1      $f0, 0x48($sp)
/* 4B3060 80219E70 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B3064 80219E74 E7A0004C */  swc1      $f0, 0x4c($sp)
.L80219E78:
/* 4B3068 80219E78 0000202D */  daddu     $a0, $zero, $zero
/* 4B306C 80219E7C 2622FFFF */  addiu     $v0, $s1, -1
.L80219E80:
/* 4B3070 80219E80 1840002A */  blez      $v0, .L80219F2C
/* 4B3074 80219E84 0040482D */   daddu    $t1, $v0, $zero
/* 4B3078 80219E88 27A80020 */  addiu     $t0, $sp, 0x20
/* 4B307C 80219E8C 0100382D */  daddu     $a3, $t0, $zero
.L80219E90:
/* 4B3080 80219E90 0091102A */  slt       $v0, $a0, $s1
/* 4B3084 80219E94 10400021 */  beqz      $v0, .L80219F1C
/* 4B3088 80219E98 0080302D */   daddu    $a2, $a0, $zero
/* 4B308C 80219E9C 00E0282D */  daddu     $a1, $a3, $zero
/* 4B3090 80219EA0 00041040 */  sll       $v0, $a0, 1
/* 4B3094 80219EA4 00441021 */  addu      $v0, $v0, $a0
/* 4B3098 80219EA8 00021080 */  sll       $v0, $v0, 2
/* 4B309C 80219EAC 00481821 */  addu      $v1, $v0, $t0
.L80219EB0:
/* 4B30A0 80219EB0 C4A20000 */  lwc1      $f2, ($a1)
/* 4B30A4 80219EB4 C4600000 */  lwc1      $f0, ($v1)
/* 4B30A8 80219EB8 4600103C */  c.lt.s    $f2, $f0
/* 4B30AC 80219EBC 00000000 */  nop
/* 4B30B0 80219EC0 45000013 */  bc1f      .L80219F10
/* 4B30B4 80219EC4 24C60001 */   addiu    $a2, $a2, 1
/* 4B30B8 80219EC8 8CAA0000 */  lw        $t2, ($a1)
/* 4B30BC 80219ECC 8CAB0004 */  lw        $t3, 4($a1)
/* 4B30C0 80219ED0 8CAC0008 */  lw        $t4, 8($a1)
/* 4B30C4 80219ED4 AFAA0010 */  sw        $t2, 0x10($sp)
/* 4B30C8 80219ED8 AFAB0014 */  sw        $t3, 0x14($sp)
/* 4B30CC 80219EDC AFAC0018 */  sw        $t4, 0x18($sp)
/* 4B30D0 80219EE0 8C6A0000 */  lw        $t2, ($v1)
/* 4B30D4 80219EE4 8C6B0004 */  lw        $t3, 4($v1)
/* 4B30D8 80219EE8 8C6C0008 */  lw        $t4, 8($v1)
/* 4B30DC 80219EEC ACAA0000 */  sw        $t2, ($a1)
/* 4B30E0 80219EF0 ACAB0004 */  sw        $t3, 4($a1)
/* 4B30E4 80219EF4 ACAC0008 */  sw        $t4, 8($a1)
/* 4B30E8 80219EF8 8FAA0010 */  lw        $t2, 0x10($sp)
/* 4B30EC 80219EFC 8FAB0014 */  lw        $t3, 0x14($sp)
/* 4B30F0 80219F00 8FAC0018 */  lw        $t4, 0x18($sp)
/* 4B30F4 80219F04 AC6A0000 */  sw        $t2, ($v1)
/* 4B30F8 80219F08 AC6B0004 */  sw        $t3, 4($v1)
/* 4B30FC 80219F0C AC6C0008 */  sw        $t4, 8($v1)
.L80219F10:
/* 4B3100 80219F10 00D1102A */  slt       $v0, $a2, $s1
/* 4B3104 80219F14 1440FFE6 */  bnez      $v0, .L80219EB0
/* 4B3108 80219F18 2463000C */   addiu    $v1, $v1, 0xc
.L80219F1C:
/* 4B310C 80219F1C 24840001 */  addiu     $a0, $a0, 1
/* 4B3110 80219F20 0089102A */  slt       $v0, $a0, $t1
/* 4B3114 80219F24 1440FFDA */  bnez      $v0, .L80219E90
/* 4B3118 80219F28 24E7000C */   addiu    $a3, $a3, 0xc
.L80219F2C:
/* 4B311C 80219F2C 8E440148 */  lw        $a0, 0x148($s2)
/* 4B3120 80219F30 0C09A75B */  jal       get_actor
/* 4B3124 80219F34 00000000 */   nop
/* 4B3128 80219F38 24040003 */  addiu     $a0, $zero, 3
/* 4B312C 80219F3C 8C43008C */  lw        $v1, 0x8c($v0)
/* 4B3130 80219F40 12240034 */  beq       $s1, $a0, .L8021A014
/* 4B3134 80219F44 2A220004 */   slti     $v0, $s1, 4
/* 4B3138 80219F48 10400005 */  beqz      $v0, .L80219F60
/* 4B313C 80219F4C 24020002 */   addiu    $v0, $zero, 2
/* 4B3140 80219F50 12220008 */  beq       $s1, $v0, .L80219F74
/* 4B3144 80219F54 00000000 */   nop
/* 4B3148 80219F58 0808689B */  j         .L8021A26C
/* 4B314C 80219F5C 00000000 */   nop
.L80219F60:
/* 4B3150 80219F60 24020004 */  addiu     $v0, $zero, 4
/* 4B3154 80219F64 1222006B */  beq       $s1, $v0, .L8021A114
/* 4B3158 80219F68 00000000 */   nop
/* 4B315C 80219F6C 0808689B */  j         .L8021A26C
/* 4B3160 80219F70 00000000 */   nop
.L80219F74:
/* 4B3164 80219F74 10640005 */  beq       $v1, $a0, .L80219F8C
/* 4B3168 80219F78 24020006 */   addiu    $v0, $zero, 6
/* 4B316C 80219F7C 10620014 */  beq       $v1, $v0, .L80219FD0
/* 4B3170 80219F80 00000000 */   nop
/* 4B3174 80219F84 0808689B */  j         .L8021A26C
/* 4B3178 80219F88 00000000 */   nop
.L80219F8C:
/* 4B317C 80219F8C 8E050000 */  lw        $a1, ($s0)
/* 4B3180 80219F90 26100004 */  addiu     $s0, $s0, 4
/* 4B3184 80219F94 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 4B3188 80219F98 4600010D */  trunc.w.s $f4, $f0
/* 4B318C 80219F9C 44062000 */  mfc1      $a2, $f4
/* 4B3190 80219FA0 0C0B2026 */  jal       evt_set_variable
/* 4B3194 80219FA4 0240202D */   daddu    $a0, $s2, $zero
/* 4B3198 80219FA8 8E050000 */  lw        $a1, ($s0)
/* 4B319C 80219FAC 26100004 */  addiu     $s0, $s0, 4
/* 4B31A0 80219FB0 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 4B31A4 80219FB4 4600010D */  trunc.w.s $f4, $f0
/* 4B31A8 80219FB8 44062000 */  mfc1      $a2, $f4
/* 4B31AC 80219FBC 0C0B2026 */  jal       evt_set_variable
/* 4B31B0 80219FC0 0240202D */   daddu    $a0, $s2, $zero
/* 4B31B4 80219FC4 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 4B31B8 80219FC8 08086896 */  j         .L8021A258
/* 4B31BC 80219FCC 0240202D */   daddu    $a0, $s2, $zero
.L80219FD0:
/* 4B31C0 80219FD0 8E050000 */  lw        $a1, ($s0)
/* 4B31C4 80219FD4 26100004 */  addiu     $s0, $s0, 4
/* 4B31C8 80219FD8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 4B31CC 80219FDC 4600010D */  trunc.w.s $f4, $f0
/* 4B31D0 80219FE0 44062000 */  mfc1      $a2, $f4
/* 4B31D4 80219FE4 0C0B2026 */  jal       evt_set_variable
/* 4B31D8 80219FE8 0240202D */   daddu    $a0, $s2, $zero
/* 4B31DC 80219FEC 8E050000 */  lw        $a1, ($s0)
/* 4B31E0 80219FF0 26100004 */  addiu     $s0, $s0, 4
/* 4B31E4 80219FF4 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 4B31E8 80219FF8 4600010D */  trunc.w.s $f4, $f0
/* 4B31EC 80219FFC 44062000 */  mfc1      $a2, $f4
/* 4B31F0 8021A000 0C0B2026 */  jal       evt_set_variable
/* 4B31F4 8021A004 0240202D */   daddu    $a0, $s2, $zero
/* 4B31F8 8021A008 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 4B31FC 8021A00C 08086896 */  j         .L8021A258
/* 4B3200 8021A010 0240202D */   daddu    $a0, $s2, $zero
.L8021A014:
/* 4B3204 8021A014 24020005 */  addiu     $v0, $zero, 5
/* 4B3208 8021A018 1062001C */  beq       $v1, $v0, .L8021A08C
/* 4B320C 8021A01C 28620006 */   slti     $v0, $v1, 6
/* 4B3210 8021A020 10400005 */  beqz      $v0, .L8021A038
/* 4B3214 8021A024 24020006 */   addiu    $v0, $zero, 6
/* 4B3218 8021A028 10640007 */  beq       $v1, $a0, .L8021A048
/* 4B321C 8021A02C 00000000 */   nop
/* 4B3220 8021A030 0808689B */  j         .L8021A26C
/* 4B3224 8021A034 00000000 */   nop
.L8021A038:
/* 4B3228 8021A038 10620025 */  beq       $v1, $v0, .L8021A0D0
/* 4B322C 8021A03C 00000000 */   nop
/* 4B3230 8021A040 0808689B */  j         .L8021A26C
/* 4B3234 8021A044 00000000 */   nop
.L8021A048:
/* 4B3238 8021A048 8E050000 */  lw        $a1, ($s0)
/* 4B323C 8021A04C 26100004 */  addiu     $s0, $s0, 4
/* 4B3240 8021A050 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 4B3244 8021A054 4600010D */  trunc.w.s $f4, $f0
/* 4B3248 8021A058 44062000 */  mfc1      $a2, $f4
/* 4B324C 8021A05C 0C0B2026 */  jal       evt_set_variable
/* 4B3250 8021A060 0240202D */   daddu    $a0, $s2, $zero
/* 4B3254 8021A064 8E050000 */  lw        $a1, ($s0)
/* 4B3258 8021A068 26100004 */  addiu     $s0, $s0, 4
/* 4B325C 8021A06C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 4B3260 8021A070 4600010D */  trunc.w.s $f4, $f0
/* 4B3264 8021A074 44062000 */  mfc1      $a2, $f4
/* 4B3268 8021A078 0C0B2026 */  jal       evt_set_variable
/* 4B326C 8021A07C 0240202D */   daddu    $a0, $s2, $zero
/* 4B3270 8021A080 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 4B3274 8021A084 08086896 */  j         .L8021A258
/* 4B3278 8021A088 0240202D */   daddu    $a0, $s2, $zero
.L8021A08C:
/* 4B327C 8021A08C 8E050000 */  lw        $a1, ($s0)
/* 4B3280 8021A090 26100004 */  addiu     $s0, $s0, 4
/* 4B3284 8021A094 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 4B3288 8021A098 4600010D */  trunc.w.s $f4, $f0
/* 4B328C 8021A09C 44062000 */  mfc1      $a2, $f4
/* 4B3290 8021A0A0 0C0B2026 */  jal       evt_set_variable
/* 4B3294 8021A0A4 0240202D */   daddu    $a0, $s2, $zero
/* 4B3298 8021A0A8 8E050000 */  lw        $a1, ($s0)
/* 4B329C 8021A0AC 26100004 */  addiu     $s0, $s0, 4
/* 4B32A0 8021A0B0 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 4B32A4 8021A0B4 4600010D */  trunc.w.s $f4, $f0
/* 4B32A8 8021A0B8 44062000 */  mfc1      $a2, $f4
/* 4B32AC 8021A0BC 0C0B2026 */  jal       evt_set_variable
/* 4B32B0 8021A0C0 0240202D */   daddu    $a0, $s2, $zero
/* 4B32B4 8021A0C4 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 4B32B8 8021A0C8 08086896 */  j         .L8021A258
/* 4B32BC 8021A0CC 0240202D */   daddu    $a0, $s2, $zero
.L8021A0D0:
/* 4B32C0 8021A0D0 8E050000 */  lw        $a1, ($s0)
/* 4B32C4 8021A0D4 26100004 */  addiu     $s0, $s0, 4
/* 4B32C8 8021A0D8 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 4B32CC 8021A0DC 4600010D */  trunc.w.s $f4, $f0
/* 4B32D0 8021A0E0 44062000 */  mfc1      $a2, $f4
/* 4B32D4 8021A0E4 0C0B2026 */  jal       evt_set_variable
/* 4B32D8 8021A0E8 0240202D */   daddu    $a0, $s2, $zero
/* 4B32DC 8021A0EC 8E050000 */  lw        $a1, ($s0)
/* 4B32E0 8021A0F0 26100004 */  addiu     $s0, $s0, 4
/* 4B32E4 8021A0F4 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 4B32E8 8021A0F8 4600010D */  trunc.w.s $f4, $f0
/* 4B32EC 8021A0FC 44062000 */  mfc1      $a2, $f4
/* 4B32F0 8021A100 0C0B2026 */  jal       evt_set_variable
/* 4B32F4 8021A104 0240202D */   daddu    $a0, $s2, $zero
/* 4B32F8 8021A108 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 4B32FC 8021A10C 08086896 */  j         .L8021A258
/* 4B3300 8021A110 0240202D */   daddu    $a0, $s2, $zero
.L8021A114:
/* 4B3304 8021A114 1071001E */  beq       $v1, $s1, .L8021A190
/* 4B3308 8021A118 28620005 */   slti     $v0, $v1, 5
/* 4B330C 8021A11C 10400005 */  beqz      $v0, .L8021A134
/* 4B3310 8021A120 24020005 */   addiu    $v0, $zero, 5
/* 4B3314 8021A124 10640009 */  beq       $v1, $a0, .L8021A14C
/* 4B3318 8021A128 00000000 */   nop
/* 4B331C 8021A12C 0808689B */  j         .L8021A26C
/* 4B3320 8021A130 00000000 */   nop
.L8021A134:
/* 4B3324 8021A134 10620027 */  beq       $v1, $v0, .L8021A1D4
/* 4B3328 8021A138 24020006 */   addiu    $v0, $zero, 6
/* 4B332C 8021A13C 10620036 */  beq       $v1, $v0, .L8021A218
/* 4B3330 8021A140 00000000 */   nop
/* 4B3334 8021A144 0808689B */  j         .L8021A26C
/* 4B3338 8021A148 00000000 */   nop
.L8021A14C:
/* 4B333C 8021A14C 8E050000 */  lw        $a1, ($s0)
/* 4B3340 8021A150 26100004 */  addiu     $s0, $s0, 4
/* 4B3344 8021A154 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 4B3348 8021A158 4600010D */  trunc.w.s $f4, $f0
/* 4B334C 8021A15C 44062000 */  mfc1      $a2, $f4
/* 4B3350 8021A160 0C0B2026 */  jal       evt_set_variable
/* 4B3354 8021A164 0240202D */   daddu    $a0, $s2, $zero
/* 4B3358 8021A168 8E050000 */  lw        $a1, ($s0)
/* 4B335C 8021A16C 26100004 */  addiu     $s0, $s0, 4
/* 4B3360 8021A170 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 4B3364 8021A174 4600010D */  trunc.w.s $f4, $f0
/* 4B3368 8021A178 44062000 */  mfc1      $a2, $f4
/* 4B336C 8021A17C 0C0B2026 */  jal       evt_set_variable
/* 4B3370 8021A180 0240202D */   daddu    $a0, $s2, $zero
/* 4B3374 8021A184 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 4B3378 8021A188 08086896 */  j         .L8021A258
/* 4B337C 8021A18C 0240202D */   daddu    $a0, $s2, $zero
.L8021A190:
/* 4B3380 8021A190 8E050000 */  lw        $a1, ($s0)
/* 4B3384 8021A194 26100004 */  addiu     $s0, $s0, 4
/* 4B3388 8021A198 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 4B338C 8021A19C 4600010D */  trunc.w.s $f4, $f0
/* 4B3390 8021A1A0 44062000 */  mfc1      $a2, $f4
/* 4B3394 8021A1A4 0C0B2026 */  jal       evt_set_variable
/* 4B3398 8021A1A8 0240202D */   daddu    $a0, $s2, $zero
/* 4B339C 8021A1AC 8E050000 */  lw        $a1, ($s0)
/* 4B33A0 8021A1B0 26100004 */  addiu     $s0, $s0, 4
/* 4B33A4 8021A1B4 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 4B33A8 8021A1B8 4600010D */  trunc.w.s $f4, $f0
/* 4B33AC 8021A1BC 44062000 */  mfc1      $a2, $f4
/* 4B33B0 8021A1C0 0C0B2026 */  jal       evt_set_variable
/* 4B33B4 8021A1C4 0240202D */   daddu    $a0, $s2, $zero
/* 4B33B8 8021A1C8 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 4B33BC 8021A1CC 08086896 */  j         .L8021A258
/* 4B33C0 8021A1D0 0240202D */   daddu    $a0, $s2, $zero
.L8021A1D4:
/* 4B33C4 8021A1D4 8E050000 */  lw        $a1, ($s0)
/* 4B33C8 8021A1D8 26100004 */  addiu     $s0, $s0, 4
/* 4B33CC 8021A1DC C7A00038 */  lwc1      $f0, 0x38($sp)
/* 4B33D0 8021A1E0 4600010D */  trunc.w.s $f4, $f0
/* 4B33D4 8021A1E4 44062000 */  mfc1      $a2, $f4
/* 4B33D8 8021A1E8 0C0B2026 */  jal       evt_set_variable
/* 4B33DC 8021A1EC 0240202D */   daddu    $a0, $s2, $zero
/* 4B33E0 8021A1F0 8E050000 */  lw        $a1, ($s0)
/* 4B33E4 8021A1F4 26100004 */  addiu     $s0, $s0, 4
/* 4B33E8 8021A1F8 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 4B33EC 8021A1FC 4600010D */  trunc.w.s $f4, $f0
/* 4B33F0 8021A200 44062000 */  mfc1      $a2, $f4
/* 4B33F4 8021A204 0C0B2026 */  jal       evt_set_variable
/* 4B33F8 8021A208 0240202D */   daddu    $a0, $s2, $zero
/* 4B33FC 8021A20C C7A00040 */  lwc1      $f0, 0x40($sp)
/* 4B3400 8021A210 08086896 */  j         .L8021A258
/* 4B3404 8021A214 0240202D */   daddu    $a0, $s2, $zero
.L8021A218:
/* 4B3408 8021A218 8E050000 */  lw        $a1, ($s0)
/* 4B340C 8021A21C 26100004 */  addiu     $s0, $s0, 4
/* 4B3410 8021A220 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 4B3414 8021A224 4600010D */  trunc.w.s $f4, $f0
/* 4B3418 8021A228 44062000 */  mfc1      $a2, $f4
/* 4B341C 8021A22C 0C0B2026 */  jal       evt_set_variable
/* 4B3420 8021A230 0240202D */   daddu    $a0, $s2, $zero
/* 4B3424 8021A234 8E050000 */  lw        $a1, ($s0)
/* 4B3428 8021A238 26100004 */  addiu     $s0, $s0, 4
/* 4B342C 8021A23C C7A00048 */  lwc1      $f0, 0x48($sp)
/* 4B3430 8021A240 4600010D */  trunc.w.s $f4, $f0
/* 4B3434 8021A244 44062000 */  mfc1      $a2, $f4
/* 4B3438 8021A248 0C0B2026 */  jal       evt_set_variable
/* 4B343C 8021A24C 0240202D */   daddu    $a0, $s2, $zero
/* 4B3440 8021A250 0240202D */  daddu     $a0, $s2, $zero
/* 4B3444 8021A254 C7A0004C */  lwc1      $f0, 0x4c($sp)
.L8021A258:
/* 4B3448 8021A258 8E050000 */  lw        $a1, ($s0)
/* 4B344C 8021A25C 4600010D */  trunc.w.s $f4, $f0
/* 4B3450 8021A260 44062000 */  mfc1      $a2, $f4
/* 4B3454 8021A264 0C0B2026 */  jal       evt_set_variable
/* 4B3458 8021A268 00000000 */   nop
.L8021A26C:
/* 4B345C 8021A26C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 4B3460 8021A270 8FB20058 */  lw        $s2, 0x58($sp)
/* 4B3464 8021A274 8FB10054 */  lw        $s1, 0x54($sp)
/* 4B3468 8021A278 8FB00050 */  lw        $s0, 0x50($sp)
/* 4B346C 8021A27C 24020002 */  addiu     $v0, $zero, 2
/* 4B3470 8021A280 03E00008 */  jr        $ra
/* 4B3474 8021A284 27BD0060 */   addiu    $sp, $sp, 0x60

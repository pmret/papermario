.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802D2F34
/* 0F78E4 802D2F34 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F78E8 802D2F38 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0F78EC 802D2F3C 4485B000 */  mtc1  $a1, $f22
/* 0F78F0 802D2F40 3C0140C9 */  lui   $at, 0x40c9
/* 0F78F4 802D2F44 34210FD0 */  ori   $at, $at, 0xfd0
/* 0F78F8 802D2F48 44810000 */  mtc1  $at, $f0
/* 0F78FC 802D2F4C 44862000 */  mtc1  $a2, $f4
/* 0F7900 802D2F50 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0F7904 802D2F54 46002502 */  mul.s $f20, $f4, $f0
/* 0F7908 802D2F58 00000000 */  nop   
/* 0F790C 802D2F5C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7910 802D2F60 3C0143B4 */  lui   $at, 0x43b4
/* 0F7914 802D2F64 44810000 */  mtc1  $at, $f0
/* 0F7918 802D2F68 0080802D */  daddu $s0, $a0, $zero
/* 0F791C 802D2F6C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F7920 802D2F70 4600A503 */  div.s $f20, $f20, $f0
/* 0F7924 802D2F74 0C00A85B */  jal   sin_rad
/* 0F7928 802D2F78 4600A306 */   mov.s $f12, $f20
/* 0F792C 802D2F7C 4600A306 */  mov.s $f12, $f20
/* 0F7930 802D2F80 0C00A874 */  jal   cos_rad
/* 0F7934 802D2F84 46000506 */   mov.s $f20, $f0
/* 0F7938 802D2F88 4614B502 */  mul.s $f20, $f22, $f20
/* 0F793C 802D2F8C 00000000 */  nop   
/* 0F7940 802D2F90 4600B587 */  neg.s $f22, $f22
/* 0F7944 802D2F94 4600B582 */  mul.s $f22, $f22, $f0
/* 0F7948 802D2F98 00000000 */  nop   
/* 0F794C 802D2F9C C6020004 */  lwc1  $f2, 4($s0)
/* 0F7950 802D2FA0 46141080 */  add.s $f2, $f2, $f20
/* 0F7954 802D2FA4 C600000C */  lwc1  $f0, 0xc($s0)
/* 0F7958 802D2FA8 46160000 */  add.s $f0, $f0, $f22
/* 0F795C 802D2FAC E6020004 */  swc1  $f2, 4($s0)
/* 0F7960 802D2FB0 E600000C */  swc1  $f0, 0xc($s0)
/* 0F7964 802D2FB4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F7968 802D2FB8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F796C 802D2FBC D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0F7970 802D2FC0 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0F7974 802D2FC4 03E00008 */  jr    $ra
/* 0F7978 802D2FC8 27BD0028 */   addiu $sp, $sp, 0x28

/* 0F797C 802D2FCC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F7980 802D2FD0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7984 802D2FD4 0000802D */  daddu $s0, $zero, $zero
/* 0F7988 802D2FD8 AFBF0014 */  sw    $ra, 0x14($sp)
.L802D2FDC:
/* 0F798C 802D2FDC 3C03802E */  lui   $v1, 0x802e
/* 0F7990 802D2FE0 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F7994 802D2FE4 00101080 */  sll   $v0, $s0, 2
/* 0F7998 802D2FE8 00431021 */  addu  $v0, $v0, $v1
/* 0F799C 802D2FEC 8C420000 */  lw    $v0, ($v0)
/* 0F79A0 802D2FF0 10400006 */  beqz  $v0, .L802D300C
/* 0F79A4 802D2FF4 26100001 */   addiu $s0, $s0, 1
/* 0F79A8 802D2FF8 8C440000 */  lw    $a0, ($v0)
/* 0F79AC 802D2FFC 04800003 */  bltz  $a0, .L802D300C
/* 0F79B0 802D3000 00000000 */   nop   
/* 0F79B4 802D3004 0C0483C1 */  jal   func_80120F04
/* 0F79B8 802D3008 00000000 */   nop   
.L802D300C:
/* 0F79BC 802D300C 2A020040 */  slti  $v0, $s0, 0x40
/* 0F79C0 802D3010 1440FFF2 */  bnez  $v0, .L802D2FDC
/* 0F79C4 802D3014 00000000 */   nop   
/* 0F79C8 802D3018 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F79CC 802D301C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F79D0 802D3020 03E00008 */  jr    $ra
/* 0F79D4 802D3024 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F79D8 802D3028 27BDFD68 */  addiu $sp, $sp, -0x298
/* 0F79DC 802D302C F7B60290 */  sdc1  $f22, 0x290($sp)
/* 0F79E0 802D3030 3C013F80 */  lui   $at, 0x3f80
/* 0F79E4 802D3034 4481B000 */  mtc1  $at, $f22
/* 0F79E8 802D3038 AFB20268 */  sw    $s2, 0x268($sp)
/* 0F79EC 802D303C 0000902D */  daddu $s2, $zero, $zero
/* 0F79F0 802D3040 F7B40288 */  sdc1  $f20, 0x288($sp)
/* 0F79F4 802D3044 4480A000 */  mtc1  $zero, $f20
/* 0F79F8 802D3048 27A80058 */  addiu $t0, $sp, 0x58
/* 0F79FC 802D304C AFBE0280 */  sw    $fp, 0x280($sp)
/* 0F7A00 802D3050 27BE0098 */  addiu $fp, $sp, 0x98
/* 0F7A04 802D3054 AFB7027C */  sw    $s7, 0x27c($sp)
/* 0F7A08 802D3058 27B700D8 */  addiu $s7, $sp, 0xd8
/* 0F7A0C 802D305C AFB60278 */  sw    $s6, 0x278($sp)
/* 0F7A10 802D3060 27B601D8 */  addiu $s6, $sp, 0x1d8
/* 0F7A14 802D3064 AFB10264 */  sw    $s1, 0x264($sp)
/* 0F7A18 802D3068 27B10158 */  addiu $s1, $sp, 0x158
/* 0F7A1C 802D306C AFB50274 */  sw    $s5, 0x274($sp)
/* 0F7A20 802D3070 27B50118 */  addiu $s5, $sp, 0x118
/* 0F7A24 802D3074 AFB40270 */  sw    $s4, 0x270($sp)
/* 0F7A28 802D3078 27B40198 */  addiu $s4, $sp, 0x198
/* 0F7A2C 802D307C AFB3026C */  sw    $s3, 0x26c($sp)
/* 0F7A30 802D3080 27B30218 */  addiu $s3, $sp, 0x218
/* 0F7A34 802D3084 AFBF0284 */  sw    $ra, 0x284($sp)
/* 0F7A38 802D3088 AFB00260 */  sw    $s0, 0x260($sp)
/* 0F7A3C 802D308C AFA80258 */  sw    $t0, 0x258($sp)
.L802D3090:
/* 0F7A40 802D3090 3C03802E */  lui   $v1, 0x802e
/* 0F7A44 802D3094 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F7A48 802D3098 00121080 */  sll   $v0, $s2, 2
/* 0F7A4C 802D309C 00431021 */  addu  $v0, $v0, $v1
/* 0F7A50 802D30A0 8C500000 */  lw    $s0, ($v0)
/* 0F7A54 802D30A4 5200003D */  beql  $s0, $zero, .L802D319C
/* 0F7A58 802D30A8 26520001 */   addiu $s2, $s2, 1
/* 0F7A5C 802D30AC 8E040000 */  lw    $a0, ($s0)
/* 0F7A60 802D30B0 0482003A */  bltzl $a0, .L802D319C
/* 0F7A64 802D30B4 26520001 */   addiu $s2, $s2, 1
/* 0F7A68 802D30B8 0C048B77 */  jal   func_80122DDC
/* 0F7A6C 802D30BC 00000000 */   nop   
/* 0F7A70 802D30C0 8C420000 */  lw    $v0, ($v0)
/* 0F7A74 802D30C4 30420008 */  andi  $v0, $v0, 8
/* 0F7A78 802D30C8 54400034 */  bnel  $v0, $zero, .L802D319C
/* 0F7A7C 802D30CC 26520001 */   addiu $s2, $s2, 1
/* 0F7A80 802D30D0 8E050004 */  lw    $a1, 4($s0)
/* 0F7A84 802D30D4 8E060008 */  lw    $a2, 8($s0)
/* 0F7A88 802D30D8 8E07000C */  lw    $a3, 0xc($s0)
/* 0F7A8C 802D30DC 0C019E40 */  jal   guTranslateF
/* 0F7A90 802D30E0 27A40018 */   addiu $a0, $sp, 0x18
/* 0F7A94 802D30E4 E7B40010 */  swc1  $f20, 0x10($sp)
/* 0F7A98 802D30E8 8E050010 */  lw    $a1, 0x10($s0)
/* 0F7A9C 802D30EC 4406B000 */  mfc1  $a2, $f22
/* 0F7AA0 802D30F0 4407A000 */  mfc1  $a3, $f20
/* 0F7AA4 802D30F4 8FA40258 */  lw    $a0, 0x258($sp)
/* 0F7AA8 802D30F8 0C019EC8 */  jal   guRotateF
/* 0F7AAC 802D30FC 26520001 */   addiu $s2, $s2, 1
/* 0F7AB0 802D3100 E7B40010 */  swc1  $f20, 0x10($sp)
/* 0F7AB4 802D3104 8E050014 */  lw    $a1, 0x14($s0)
/* 0F7AB8 802D3108 4406A000 */  mfc1  $a2, $f20
/* 0F7ABC 802D310C 4407B000 */  mfc1  $a3, $f22
/* 0F7AC0 802D3110 0C019EC8 */  jal   guRotateF
/* 0F7AC4 802D3114 03C0202D */   daddu $a0, $fp, $zero
/* 0F7AC8 802D3118 E7B60010 */  swc1  $f22, 0x10($sp)
/* 0F7ACC 802D311C 8E050018 */  lw    $a1, 0x18($s0)
/* 0F7AD0 802D3120 4406A000 */  mfc1  $a2, $f20
/* 0F7AD4 802D3124 4407A000 */  mfc1  $a3, $f20
/* 0F7AD8 802D3128 0C019EC8 */  jal   guRotateF
/* 0F7ADC 802D312C 02E0202D */   daddu $a0, $s7, $zero
/* 0F7AE0 802D3130 8E05001C */  lw    $a1, 0x1c($s0)
/* 0F7AE4 802D3134 8E060020 */  lw    $a2, 0x20($s0)
/* 0F7AE8 802D3138 8E070024 */  lw    $a3, 0x24($s0)
/* 0F7AEC 802D313C 0C019DF0 */  jal   guScaleF
/* 0F7AF0 802D3140 02C0202D */   daddu $a0, $s6, $zero
/* 0F7AF4 802D3144 02E0202D */  daddu $a0, $s7, $zero
/* 0F7AF8 802D3148 8FA50258 */  lw    $a1, 0x258($sp)
/* 0F7AFC 802D314C 0C019D80 */  jal   guMtxCatF
/* 0F7B00 802D3150 0220302D */   daddu $a2, $s1, $zero
/* 0F7B04 802D3154 0220202D */  daddu $a0, $s1, $zero
/* 0F7B08 802D3158 03C0282D */  daddu $a1, $fp, $zero
/* 0F7B0C 802D315C 0C019D80 */  jal   guMtxCatF
/* 0F7B10 802D3160 02A0302D */   daddu $a2, $s5, $zero
/* 0F7B14 802D3164 02C0202D */  daddu $a0, $s6, $zero
/* 0F7B18 802D3168 02A0282D */  daddu $a1, $s5, $zero
/* 0F7B1C 802D316C 0C019D80 */  jal   guMtxCatF
/* 0F7B20 802D3170 0220302D */   daddu $a2, $s1, $zero
/* 0F7B24 802D3174 0220202D */  daddu $a0, $s1, $zero
/* 0F7B28 802D3178 27A50018 */  addiu $a1, $sp, 0x18
/* 0F7B2C 802D317C 0C019D80 */  jal   guMtxCatF
/* 0F7B30 802D3180 0280302D */   daddu $a2, $s4, $zero
/* 0F7B34 802D3184 0280202D */  daddu $a0, $s4, $zero
/* 0F7B38 802D3188 0C019D40 */  jal   guMtxF2L
/* 0F7B3C 802D318C 0260282D */   daddu $a1, $s3, $zero
/* 0F7B40 802D3190 8E040000 */  lw    $a0, ($s0)
/* 0F7B44 802D3194 0C04873A */  jal   func_80121CE8
/* 0F7B48 802D3198 0260282D */   daddu $a1, $s3, $zero
.L802D319C:
/* 0F7B4C 802D319C 2A420040 */  slti  $v0, $s2, 0x40
/* 0F7B50 802D31A0 1440FFBB */  bnez  $v0, .L802D3090
/* 0F7B54 802D31A4 00000000 */   nop   
/* 0F7B58 802D31A8 8FBF0284 */  lw    $ra, 0x284($sp)
/* 0F7B5C 802D31AC 8FBE0280 */  lw    $fp, 0x280($sp)
/* 0F7B60 802D31B0 8FB7027C */  lw    $s7, 0x27c($sp)
/* 0F7B64 802D31B4 8FB60278 */  lw    $s6, 0x278($sp)
/* 0F7B68 802D31B8 8FB50274 */  lw    $s5, 0x274($sp)
/* 0F7B6C 802D31BC 8FB40270 */  lw    $s4, 0x270($sp)
/* 0F7B70 802D31C0 8FB3026C */  lw    $s3, 0x26c($sp)
/* 0F7B74 802D31C4 8FB20268 */  lw    $s2, 0x268($sp)
/* 0F7B78 802D31C8 8FB10264 */  lw    $s1, 0x264($sp)
/* 0F7B7C 802D31CC 8FB00260 */  lw    $s0, 0x260($sp)
/* 0F7B80 802D31D0 D7B60290 */  ldc1  $f22, 0x290($sp)
/* 0F7B84 802D31D4 D7B40288 */  ldc1  $f20, 0x288($sp)
/* 0F7B88 802D31D8 03E00008 */  jr    $ra
/* 0F7B8C 802D31DC 27BD0298 */   addiu $sp, $sp, 0x298

/* 0F7B90 802D31E0 27BDFD68 */  addiu $sp, $sp, -0x298
/* 0F7B94 802D31E4 F7B60290 */  sdc1  $f22, 0x290($sp)
/* 0F7B98 802D31E8 3C013F80 */  lui   $at, 0x3f80
/* 0F7B9C 802D31EC 4481B000 */  mtc1  $at, $f22
/* 0F7BA0 802D31F0 AFB20268 */  sw    $s2, 0x268($sp)
/* 0F7BA4 802D31F4 0000902D */  daddu $s2, $zero, $zero
/* 0F7BA8 802D31F8 F7B40288 */  sdc1  $f20, 0x288($sp)
/* 0F7BAC 802D31FC 4480A000 */  mtc1  $zero, $f20
/* 0F7BB0 802D3200 27A80058 */  addiu $t0, $sp, 0x58
/* 0F7BB4 802D3204 AFBE0280 */  sw    $fp, 0x280($sp)
/* 0F7BB8 802D3208 27BE0098 */  addiu $fp, $sp, 0x98
/* 0F7BBC 802D320C AFB7027C */  sw    $s7, 0x27c($sp)
/* 0F7BC0 802D3210 27B700D8 */  addiu $s7, $sp, 0xd8
/* 0F7BC4 802D3214 AFB60278 */  sw    $s6, 0x278($sp)
/* 0F7BC8 802D3218 27B601D8 */  addiu $s6, $sp, 0x1d8
/* 0F7BCC 802D321C AFB10264 */  sw    $s1, 0x264($sp)
/* 0F7BD0 802D3220 27B10158 */  addiu $s1, $sp, 0x158
/* 0F7BD4 802D3224 AFB50274 */  sw    $s5, 0x274($sp)
/* 0F7BD8 802D3228 27B50118 */  addiu $s5, $sp, 0x118
/* 0F7BDC 802D322C AFB40270 */  sw    $s4, 0x270($sp)
/* 0F7BE0 802D3230 27B40198 */  addiu $s4, $sp, 0x198
/* 0F7BE4 802D3234 AFB3026C */  sw    $s3, 0x26c($sp)
/* 0F7BE8 802D3238 27B30218 */  addiu $s3, $sp, 0x218
/* 0F7BEC 802D323C AFBF0284 */  sw    $ra, 0x284($sp)
/* 0F7BF0 802D3240 AFB00260 */  sw    $s0, 0x260($sp)
/* 0F7BF4 802D3244 AFA80258 */  sw    $t0, 0x258($sp)
.L802D3248:
/* 0F7BF8 802D3248 3C03802E */  lui   $v1, 0x802e
/* 0F7BFC 802D324C 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F7C00 802D3250 00121080 */  sll   $v0, $s2, 2
/* 0F7C04 802D3254 00431021 */  addu  $v0, $v0, $v1
/* 0F7C08 802D3258 8C500000 */  lw    $s0, ($v0)
/* 0F7C0C 802D325C 5200003D */  beql  $s0, $zero, .L802D3354
/* 0F7C10 802D3260 26520001 */   addiu $s2, $s2, 1
/* 0F7C14 802D3264 8E040000 */  lw    $a0, ($s0)
/* 0F7C18 802D3268 0482003A */  bltzl $a0, .L802D3354
/* 0F7C1C 802D326C 26520001 */   addiu $s2, $s2, 1
/* 0F7C20 802D3270 0C048B77 */  jal   func_80122DDC
/* 0F7C24 802D3274 00000000 */   nop   
/* 0F7C28 802D3278 8C420000 */  lw    $v0, ($v0)
/* 0F7C2C 802D327C 30420008 */  andi  $v0, $v0, 8
/* 0F7C30 802D3280 50400034 */  beql  $v0, $zero, .L802D3354
/* 0F7C34 802D3284 26520001 */   addiu $s2, $s2, 1
/* 0F7C38 802D3288 8E050004 */  lw    $a1, 4($s0)
/* 0F7C3C 802D328C 8E060008 */  lw    $a2, 8($s0)
/* 0F7C40 802D3290 8E07000C */  lw    $a3, 0xc($s0)
/* 0F7C44 802D3294 0C019E40 */  jal   guTranslateF
/* 0F7C48 802D3298 27A40018 */   addiu $a0, $sp, 0x18
/* 0F7C4C 802D329C E7B40010 */  swc1  $f20, 0x10($sp)
/* 0F7C50 802D32A0 8E050010 */  lw    $a1, 0x10($s0)
/* 0F7C54 802D32A4 4406B000 */  mfc1  $a2, $f22
/* 0F7C58 802D32A8 4407A000 */  mfc1  $a3, $f20
/* 0F7C5C 802D32AC 8FA40258 */  lw    $a0, 0x258($sp)
/* 0F7C60 802D32B0 0C019EC8 */  jal   guRotateF
/* 0F7C64 802D32B4 26520001 */   addiu $s2, $s2, 1
/* 0F7C68 802D32B8 E7B40010 */  swc1  $f20, 0x10($sp)
/* 0F7C6C 802D32BC 8E050014 */  lw    $a1, 0x14($s0)
/* 0F7C70 802D32C0 4406A000 */  mfc1  $a2, $f20
/* 0F7C74 802D32C4 4407B000 */  mfc1  $a3, $f22
/* 0F7C78 802D32C8 0C019EC8 */  jal   guRotateF
/* 0F7C7C 802D32CC 03C0202D */   daddu $a0, $fp, $zero
/* 0F7C80 802D32D0 E7B60010 */  swc1  $f22, 0x10($sp)
/* 0F7C84 802D32D4 8E050018 */  lw    $a1, 0x18($s0)
/* 0F7C88 802D32D8 4406A000 */  mfc1  $a2, $f20
/* 0F7C8C 802D32DC 4407A000 */  mfc1  $a3, $f20
/* 0F7C90 802D32E0 0C019EC8 */  jal   guRotateF
/* 0F7C94 802D32E4 02E0202D */   daddu $a0, $s7, $zero
/* 0F7C98 802D32E8 8E05001C */  lw    $a1, 0x1c($s0)
/* 0F7C9C 802D32EC 8E060020 */  lw    $a2, 0x20($s0)
/* 0F7CA0 802D32F0 8E070024 */  lw    $a3, 0x24($s0)
/* 0F7CA4 802D32F4 0C019DF0 */  jal   guScaleF
/* 0F7CA8 802D32F8 02C0202D */   daddu $a0, $s6, $zero
/* 0F7CAC 802D32FC 02E0202D */  daddu $a0, $s7, $zero
/* 0F7CB0 802D3300 8FA50258 */  lw    $a1, 0x258($sp)
/* 0F7CB4 802D3304 0C019D80 */  jal   guMtxCatF
/* 0F7CB8 802D3308 0220302D */   daddu $a2, $s1, $zero
/* 0F7CBC 802D330C 0220202D */  daddu $a0, $s1, $zero
/* 0F7CC0 802D3310 03C0282D */  daddu $a1, $fp, $zero
/* 0F7CC4 802D3314 0C019D80 */  jal   guMtxCatF
/* 0F7CC8 802D3318 02A0302D */   daddu $a2, $s5, $zero
/* 0F7CCC 802D331C 02C0202D */  daddu $a0, $s6, $zero
/* 0F7CD0 802D3320 02A0282D */  daddu $a1, $s5, $zero
/* 0F7CD4 802D3324 0C019D80 */  jal   guMtxCatF
/* 0F7CD8 802D3328 0220302D */   daddu $a2, $s1, $zero
/* 0F7CDC 802D332C 0220202D */  daddu $a0, $s1, $zero
/* 0F7CE0 802D3330 27A50018 */  addiu $a1, $sp, 0x18
/* 0F7CE4 802D3334 0C019D80 */  jal   guMtxCatF
/* 0F7CE8 802D3338 0280302D */   daddu $a2, $s4, $zero
/* 0F7CEC 802D333C 0280202D */  daddu $a0, $s4, $zero
/* 0F7CF0 802D3340 0C019D40 */  jal   guMtxF2L
/* 0F7CF4 802D3344 0260282D */   daddu $a1, $s3, $zero
/* 0F7CF8 802D3348 8E040000 */  lw    $a0, ($s0)
/* 0F7CFC 802D334C 0C0488A2 */  jal   func_80122288
/* 0F7D00 802D3350 0260282D */   daddu $a1, $s3, $zero
.L802D3354:
/* 0F7D04 802D3354 2A420040 */  slti  $v0, $s2, 0x40
/* 0F7D08 802D3358 1440FFBB */  bnez  $v0, .L802D3248
/* 0F7D0C 802D335C 00000000 */   nop   
/* 0F7D10 802D3360 8FBF0284 */  lw    $ra, 0x284($sp)
/* 0F7D14 802D3364 8FBE0280 */  lw    $fp, 0x280($sp)
/* 0F7D18 802D3368 8FB7027C */  lw    $s7, 0x27c($sp)
/* 0F7D1C 802D336C 8FB60278 */  lw    $s6, 0x278($sp)
/* 0F7D20 802D3370 8FB50274 */  lw    $s5, 0x274($sp)
/* 0F7D24 802D3374 8FB40270 */  lw    $s4, 0x270($sp)
/* 0F7D28 802D3378 8FB3026C */  lw    $s3, 0x26c($sp)
/* 0F7D2C 802D337C 8FB20268 */  lw    $s2, 0x268($sp)
/* 0F7D30 802D3380 8FB10264 */  lw    $s1, 0x264($sp)
/* 0F7D34 802D3384 8FB00260 */  lw    $s0, 0x260($sp)
/* 0F7D38 802D3388 D7B60290 */  ldc1  $f22, 0x290($sp)
/* 0F7D3C 802D338C D7B40288 */  ldc1  $f20, 0x288($sp)
/* 0F7D40 802D3390 03E00008 */  jr    $ra
/* 0F7D44 802D3394 27BD0298 */   addiu $sp, $sp, 0x298

/* 0F7D48 802D3398 3C028007 */  lui   $v0, 0x8007
/* 0F7D4C 802D339C 8C42419C */  lw    $v0, 0x419c($v0)
/* 0F7D50 802D33A0 80420070 */  lb    $v0, 0x70($v0)
/* 0F7D54 802D33A4 14400005 */  bnez  $v0, .L802D33BC
/* 0F7D58 802D33A8 00000000 */   nop   
/* 0F7D5C 802D33AC 3C02802E */  lui   $v0, 0x802e
/* 0F7D60 802D33B0 2442B6C0 */  addiu $v0, $v0, -0x4940
/* 0F7D64 802D33B4 080B4CF1 */  j     .L802D33C4
/* 0F7D68 802D33B8 00000000 */   nop   

.L802D33BC:
/* 0F7D6C 802D33BC 3C02802E */  lui   $v0, 0x802e
/* 0F7D70 802D33C0 2442B5C0 */  addiu $v0, $v0, -0x4a40
.L802D33C4:
/* 0F7D74 802D33C4 3C01802E */  lui   $at, 0x802e
/* 0F7D78 802D33C8 AC22B7C0 */  sw    $v0, -0x4840($at)
/* 0F7D7C 802D33CC 03E00008 */  jr    $ra
/* 0F7D80 802D33D0 24020002 */   addiu $v0, $zero, 2

/* 0F7D84 802D33D4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F7D88 802D33D8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F7D8C 802D33DC 0080882D */  daddu $s1, $a0, $zero
/* 0F7D90 802D33E0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F7D94 802D33E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7D98 802D33E8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F7D9C 802D33EC 8E050000 */  lw    $a1, ($s0)
/* 0F7DA0 802D33F0 0C0B1EAF */  jal   get_variable
/* 0F7DA4 802D33F4 26100004 */   addiu $s0, $s0, 4
/* 0F7DA8 802D33F8 0220202D */  daddu $a0, $s1, $zero
/* 0F7DAC 802D33FC 8E050000 */  lw    $a1, ($s0)
/* 0F7DB0 802D3400 0C0B1EAF */  jal   get_variable
/* 0F7DB4 802D3404 0040802D */   daddu $s0, $v0, $zero
/* 0F7DB8 802D3408 0040202D */  daddu $a0, $v0, $zero
/* 0F7DBC 802D340C 3C02802E */  lui   $v0, 0x802e
/* 0F7DC0 802D3410 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F7DC4 802D3414 00108080 */  sll   $s0, $s0, 2
/* 0F7DC8 802D3418 02028021 */  addu  $s0, $s0, $v0
/* 0F7DCC 802D341C 0C048338 */  jal   func_80120CE0
/* 0F7DD0 802D3420 8E100000 */   lw    $s0, ($s0)
/* 0F7DD4 802D3424 3C013F80 */  lui   $at, 0x3f80
/* 0F7DD8 802D3428 44810000 */  mtc1  $at, $f0
/* 0F7DDC 802D342C AE020000 */  sw    $v0, ($s0)
/* 0F7DE0 802D3430 0040202D */  daddu $a0, $v0, $zero
/* 0F7DE4 802D3434 AE000004 */  sw    $zero, 4($s0)
/* 0F7DE8 802D3438 AE000008 */  sw    $zero, 8($s0)
/* 0F7DEC 802D343C AE00000C */  sw    $zero, 0xc($s0)
/* 0F7DF0 802D3440 AE000010 */  sw    $zero, 0x10($s0)
/* 0F7DF4 802D3444 AE000014 */  sw    $zero, 0x14($s0)
/* 0F7DF8 802D3448 AE000018 */  sw    $zero, 0x18($s0)
/* 0F7DFC 802D344C E600001C */  swc1  $f0, 0x1c($s0)
/* 0F7E00 802D3450 E6000020 */  swc1  $f0, 0x20($s0)
/* 0F7E04 802D3454 0C0483C1 */  jal   func_80120F04
/* 0F7E08 802D3458 E6000024 */   swc1  $f0, 0x24($s0)
/* 0F7E0C 802D345C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F7E10 802D3460 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F7E14 802D3464 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F7E18 802D3468 24020002 */  addiu $v0, $zero, 2
/* 0F7E1C 802D346C 03E00008 */  jr    $ra
/* 0F7E20 802D3470 27BD0020 */   addiu $sp, $sp, 0x20


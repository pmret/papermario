.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3028
/* F79D8 802D3028 27BDFD68 */  addiu     $sp, $sp, -0x298
/* F79DC 802D302C F7B60290 */  sdc1      $f22, 0x290($sp)
/* F79E0 802D3030 3C013F80 */  lui       $at, 0x3f80
/* F79E4 802D3034 4481B000 */  mtc1      $at, $f22
/* F79E8 802D3038 AFB20268 */  sw        $s2, 0x268($sp)
/* F79EC 802D303C 0000902D */  daddu     $s2, $zero, $zero
/* F79F0 802D3040 F7B40288 */  sdc1      $f20, 0x288($sp)
/* F79F4 802D3044 4480A000 */  mtc1      $zero, $f20
/* F79F8 802D3048 27A80058 */  addiu     $t0, $sp, 0x58
/* F79FC 802D304C AFBE0280 */  sw        $fp, 0x280($sp)
/* F7A00 802D3050 27BE0098 */  addiu     $fp, $sp, 0x98
/* F7A04 802D3054 AFB7027C */  sw        $s7, 0x27c($sp)
/* F7A08 802D3058 27B700D8 */  addiu     $s7, $sp, 0xd8
/* F7A0C 802D305C AFB60278 */  sw        $s6, 0x278($sp)
/* F7A10 802D3060 27B601D8 */  addiu     $s6, $sp, 0x1d8
/* F7A14 802D3064 AFB10264 */  sw        $s1, 0x264($sp)
/* F7A18 802D3068 27B10158 */  addiu     $s1, $sp, 0x158
/* F7A1C 802D306C AFB50274 */  sw        $s5, 0x274($sp)
/* F7A20 802D3070 27B50118 */  addiu     $s5, $sp, 0x118
/* F7A24 802D3074 AFB40270 */  sw        $s4, 0x270($sp)
/* F7A28 802D3078 27B40198 */  addiu     $s4, $sp, 0x198
/* F7A2C 802D307C AFB3026C */  sw        $s3, 0x26c($sp)
/* F7A30 802D3080 27B30218 */  addiu     $s3, $sp, 0x218
/* F7A34 802D3084 AFBF0284 */  sw        $ra, 0x284($sp)
/* F7A38 802D3088 AFB00260 */  sw        $s0, 0x260($sp)
/* F7A3C 802D308C AFA80258 */  sw        $t0, 0x258($sp)
.L802D3090:
/* F7A40 802D3090 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F7A44 802D3094 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F7A48 802D3098 00121080 */  sll       $v0, $s2, 2
/* F7A4C 802D309C 00431021 */  addu      $v0, $v0, $v1
/* F7A50 802D30A0 8C500000 */  lw        $s0, ($v0)
/* F7A54 802D30A4 5200003D */  beql      $s0, $zero, .L802D319C
/* F7A58 802D30A8 26520001 */   addiu    $s2, $s2, 1
/* F7A5C 802D30AC 8E040000 */  lw        $a0, ($s0)
/* F7A60 802D30B0 0482003A */  bltzl     $a0, .L802D319C
/* F7A64 802D30B4 26520001 */   addiu    $s2, $s2, 1
/* F7A68 802D30B8 0C048B77 */  jal       func_80122DDC
/* F7A6C 802D30BC 00000000 */   nop
/* F7A70 802D30C0 8C420000 */  lw        $v0, ($v0)
/* F7A74 802D30C4 30420008 */  andi      $v0, $v0, 8
/* F7A78 802D30C8 54400034 */  bnel      $v0, $zero, .L802D319C
/* F7A7C 802D30CC 26520001 */   addiu    $s2, $s2, 1
/* F7A80 802D30D0 8E050004 */  lw        $a1, 4($s0)
/* F7A84 802D30D4 8E060008 */  lw        $a2, 8($s0)
/* F7A88 802D30D8 8E07000C */  lw        $a3, 0xc($s0)
/* F7A8C 802D30DC 0C019E40 */  jal       guTranslateF
/* F7A90 802D30E0 27A40018 */   addiu    $a0, $sp, 0x18
/* F7A94 802D30E4 E7B40010 */  swc1      $f20, 0x10($sp)
/* F7A98 802D30E8 8E050010 */  lw        $a1, 0x10($s0)
/* F7A9C 802D30EC 4406B000 */  mfc1      $a2, $f22
/* F7AA0 802D30F0 4407A000 */  mfc1      $a3, $f20
/* F7AA4 802D30F4 8FA40258 */  lw        $a0, 0x258($sp)
/* F7AA8 802D30F8 0C019EC8 */  jal       guRotateF
/* F7AAC 802D30FC 26520001 */   addiu    $s2, $s2, 1
/* F7AB0 802D3100 E7B40010 */  swc1      $f20, 0x10($sp)
/* F7AB4 802D3104 8E050014 */  lw        $a1, 0x14($s0)
/* F7AB8 802D3108 4406A000 */  mfc1      $a2, $f20
/* F7ABC 802D310C 4407B000 */  mfc1      $a3, $f22
/* F7AC0 802D3110 0C019EC8 */  jal       guRotateF
/* F7AC4 802D3114 03C0202D */   daddu    $a0, $fp, $zero
/* F7AC8 802D3118 E7B60010 */  swc1      $f22, 0x10($sp)
/* F7ACC 802D311C 8E050018 */  lw        $a1, 0x18($s0)
/* F7AD0 802D3120 4406A000 */  mfc1      $a2, $f20
/* F7AD4 802D3124 4407A000 */  mfc1      $a3, $f20
/* F7AD8 802D3128 0C019EC8 */  jal       guRotateF
/* F7ADC 802D312C 02E0202D */   daddu    $a0, $s7, $zero
/* F7AE0 802D3130 8E05001C */  lw        $a1, 0x1c($s0)
/* F7AE4 802D3134 8E060020 */  lw        $a2, 0x20($s0)
/* F7AE8 802D3138 8E070024 */  lw        $a3, 0x24($s0)
/* F7AEC 802D313C 0C019DF0 */  jal       guScaleF
/* F7AF0 802D3140 02C0202D */   daddu    $a0, $s6, $zero
/* F7AF4 802D3144 02E0202D */  daddu     $a0, $s7, $zero
/* F7AF8 802D3148 8FA50258 */  lw        $a1, 0x258($sp)
/* F7AFC 802D314C 0C019D80 */  jal       guMtxCatF
/* F7B00 802D3150 0220302D */   daddu    $a2, $s1, $zero
/* F7B04 802D3154 0220202D */  daddu     $a0, $s1, $zero
/* F7B08 802D3158 03C0282D */  daddu     $a1, $fp, $zero
/* F7B0C 802D315C 0C019D80 */  jal       guMtxCatF
/* F7B10 802D3160 02A0302D */   daddu    $a2, $s5, $zero
/* F7B14 802D3164 02C0202D */  daddu     $a0, $s6, $zero
/* F7B18 802D3168 02A0282D */  daddu     $a1, $s5, $zero
/* F7B1C 802D316C 0C019D80 */  jal       guMtxCatF
/* F7B20 802D3170 0220302D */   daddu    $a2, $s1, $zero
/* F7B24 802D3174 0220202D */  daddu     $a0, $s1, $zero
/* F7B28 802D3178 27A50018 */  addiu     $a1, $sp, 0x18
/* F7B2C 802D317C 0C019D80 */  jal       guMtxCatF
/* F7B30 802D3180 0280302D */   daddu    $a2, $s4, $zero
/* F7B34 802D3184 0280202D */  daddu     $a0, $s4, $zero
/* F7B38 802D3188 0C019D40 */  jal       guMtxF2L
/* F7B3C 802D318C 0260282D */   daddu    $a1, $s3, $zero
/* F7B40 802D3190 8E040000 */  lw        $a0, ($s0)
/* F7B44 802D3194 0C04873A */  jal       func_80121CE8
/* F7B48 802D3198 0260282D */   daddu    $a1, $s3, $zero
.L802D319C:
/* F7B4C 802D319C 2A420040 */  slti      $v0, $s2, 0x40
/* F7B50 802D31A0 1440FFBB */  bnez      $v0, .L802D3090
/* F7B54 802D31A4 00000000 */   nop
/* F7B58 802D31A8 8FBF0284 */  lw        $ra, 0x284($sp)
/* F7B5C 802D31AC 8FBE0280 */  lw        $fp, 0x280($sp)
/* F7B60 802D31B0 8FB7027C */  lw        $s7, 0x27c($sp)
/* F7B64 802D31B4 8FB60278 */  lw        $s6, 0x278($sp)
/* F7B68 802D31B8 8FB50274 */  lw        $s5, 0x274($sp)
/* F7B6C 802D31BC 8FB40270 */  lw        $s4, 0x270($sp)
/* F7B70 802D31C0 8FB3026C */  lw        $s3, 0x26c($sp)
/* F7B74 802D31C4 8FB20268 */  lw        $s2, 0x268($sp)
/* F7B78 802D31C8 8FB10264 */  lw        $s1, 0x264($sp)
/* F7B7C 802D31CC 8FB00260 */  lw        $s0, 0x260($sp)
/* F7B80 802D31D0 D7B60290 */  ldc1      $f22, 0x290($sp)
/* F7B84 802D31D4 D7B40288 */  ldc1      $f20, 0x288($sp)
/* F7B88 802D31D8 03E00008 */  jr        $ra
/* F7B8C 802D31DC 27BD0298 */   addiu    $sp, $sp, 0x298

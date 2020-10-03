.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D31E0
/* F7B90 802D31E0 27BDFD68 */  addiu     $sp, $sp, -0x298
/* F7B94 802D31E4 F7B60290 */  sdc1      $f22, 0x290($sp)
/* F7B98 802D31E8 3C013F80 */  lui       $at, 0x3f80
/* F7B9C 802D31EC 4481B000 */  mtc1      $at, $f22
/* F7BA0 802D31F0 AFB20268 */  sw        $s2, 0x268($sp)
/* F7BA4 802D31F4 0000902D */  daddu     $s2, $zero, $zero
/* F7BA8 802D31F8 F7B40288 */  sdc1      $f20, 0x288($sp)
/* F7BAC 802D31FC 4480A000 */  mtc1      $zero, $f20
/* F7BB0 802D3200 27A80058 */  addiu     $t0, $sp, 0x58
/* F7BB4 802D3204 AFBE0280 */  sw        $fp, 0x280($sp)
/* F7BB8 802D3208 27BE0098 */  addiu     $fp, $sp, 0x98
/* F7BBC 802D320C AFB7027C */  sw        $s7, 0x27c($sp)
/* F7BC0 802D3210 27B700D8 */  addiu     $s7, $sp, 0xd8
/* F7BC4 802D3214 AFB60278 */  sw        $s6, 0x278($sp)
/* F7BC8 802D3218 27B601D8 */  addiu     $s6, $sp, 0x1d8
/* F7BCC 802D321C AFB10264 */  sw        $s1, 0x264($sp)
/* F7BD0 802D3220 27B10158 */  addiu     $s1, $sp, 0x158
/* F7BD4 802D3224 AFB50274 */  sw        $s5, 0x274($sp)
/* F7BD8 802D3228 27B50118 */  addiu     $s5, $sp, 0x118
/* F7BDC 802D322C AFB40270 */  sw        $s4, 0x270($sp)
/* F7BE0 802D3230 27B40198 */  addiu     $s4, $sp, 0x198
/* F7BE4 802D3234 AFB3026C */  sw        $s3, 0x26c($sp)
/* F7BE8 802D3238 27B30218 */  addiu     $s3, $sp, 0x218
/* F7BEC 802D323C AFBF0284 */  sw        $ra, 0x284($sp)
/* F7BF0 802D3240 AFB00260 */  sw        $s0, 0x260($sp)
/* F7BF4 802D3244 AFA80258 */  sw        $t0, 0x258($sp)
.L802D3248:
/* F7BF8 802D3248 3C03802E */  lui       $v1, 0x802e
/* F7BFC 802D324C 8C63B7C0 */  lw        $v1, -0x4840($v1)
/* F7C00 802D3250 00121080 */  sll       $v0, $s2, 2
/* F7C04 802D3254 00431021 */  addu      $v0, $v0, $v1
/* F7C08 802D3258 8C500000 */  lw        $s0, ($v0)
/* F7C0C 802D325C 5200003D */  beql      $s0, $zero, .L802D3354
/* F7C10 802D3260 26520001 */   addiu    $s2, $s2, 1
/* F7C14 802D3264 8E040000 */  lw        $a0, ($s0)
/* F7C18 802D3268 0482003A */  bltzl     $a0, .L802D3354
/* F7C1C 802D326C 26520001 */   addiu    $s2, $s2, 1
/* F7C20 802D3270 0C048B77 */  jal       func_80122DDC
/* F7C24 802D3274 00000000 */   nop      
/* F7C28 802D3278 8C420000 */  lw        $v0, ($v0)
/* F7C2C 802D327C 30420008 */  andi      $v0, $v0, 8
/* F7C30 802D3280 50400034 */  beql      $v0, $zero, .L802D3354
/* F7C34 802D3284 26520001 */   addiu    $s2, $s2, 1
/* F7C38 802D3288 8E050004 */  lw        $a1, 4($s0)
/* F7C3C 802D328C 8E060008 */  lw        $a2, 8($s0)
/* F7C40 802D3290 8E07000C */  lw        $a3, 0xc($s0)
/* F7C44 802D3294 0C019E40 */  jal       guTranslateF
/* F7C48 802D3298 27A40018 */   addiu    $a0, $sp, 0x18
/* F7C4C 802D329C E7B40010 */  swc1      $f20, 0x10($sp)
/* F7C50 802D32A0 8E050010 */  lw        $a1, 0x10($s0)
/* F7C54 802D32A4 4406B000 */  mfc1      $a2, $f22
/* F7C58 802D32A8 4407A000 */  mfc1      $a3, $f20
/* F7C5C 802D32AC 8FA40258 */  lw        $a0, 0x258($sp)
/* F7C60 802D32B0 0C019EC8 */  jal       guRotateF
/* F7C64 802D32B4 26520001 */   addiu    $s2, $s2, 1
/* F7C68 802D32B8 E7B40010 */  swc1      $f20, 0x10($sp)
/* F7C6C 802D32BC 8E050014 */  lw        $a1, 0x14($s0)
/* F7C70 802D32C0 4406A000 */  mfc1      $a2, $f20
/* F7C74 802D32C4 4407B000 */  mfc1      $a3, $f22
/* F7C78 802D32C8 0C019EC8 */  jal       guRotateF
/* F7C7C 802D32CC 03C0202D */   daddu    $a0, $fp, $zero
/* F7C80 802D32D0 E7B60010 */  swc1      $f22, 0x10($sp)
/* F7C84 802D32D4 8E050018 */  lw        $a1, 0x18($s0)
/* F7C88 802D32D8 4406A000 */  mfc1      $a2, $f20
/* F7C8C 802D32DC 4407A000 */  mfc1      $a3, $f20
/* F7C90 802D32E0 0C019EC8 */  jal       guRotateF
/* F7C94 802D32E4 02E0202D */   daddu    $a0, $s7, $zero
/* F7C98 802D32E8 8E05001C */  lw        $a1, 0x1c($s0)
/* F7C9C 802D32EC 8E060020 */  lw        $a2, 0x20($s0)
/* F7CA0 802D32F0 8E070024 */  lw        $a3, 0x24($s0)
/* F7CA4 802D32F4 0C019DF0 */  jal       guScaleF
/* F7CA8 802D32F8 02C0202D */   daddu    $a0, $s6, $zero
/* F7CAC 802D32FC 02E0202D */  daddu     $a0, $s7, $zero
/* F7CB0 802D3300 8FA50258 */  lw        $a1, 0x258($sp)
/* F7CB4 802D3304 0C019D80 */  jal       guMtxCatF
/* F7CB8 802D3308 0220302D */   daddu    $a2, $s1, $zero
/* F7CBC 802D330C 0220202D */  daddu     $a0, $s1, $zero
/* F7CC0 802D3310 03C0282D */  daddu     $a1, $fp, $zero
/* F7CC4 802D3314 0C019D80 */  jal       guMtxCatF
/* F7CC8 802D3318 02A0302D */   daddu    $a2, $s5, $zero
/* F7CCC 802D331C 02C0202D */  daddu     $a0, $s6, $zero
/* F7CD0 802D3320 02A0282D */  daddu     $a1, $s5, $zero
/* F7CD4 802D3324 0C019D80 */  jal       guMtxCatF
/* F7CD8 802D3328 0220302D */   daddu    $a2, $s1, $zero
/* F7CDC 802D332C 0220202D */  daddu     $a0, $s1, $zero
/* F7CE0 802D3330 27A50018 */  addiu     $a1, $sp, 0x18
/* F7CE4 802D3334 0C019D80 */  jal       guMtxCatF
/* F7CE8 802D3338 0280302D */   daddu    $a2, $s4, $zero
/* F7CEC 802D333C 0280202D */  daddu     $a0, $s4, $zero
/* F7CF0 802D3340 0C019D40 */  jal       guMtxF2L
/* F7CF4 802D3344 0260282D */   daddu    $a1, $s3, $zero
/* F7CF8 802D3348 8E040000 */  lw        $a0, ($s0)
/* F7CFC 802D334C 0C0488A2 */  jal       func_80122288
/* F7D00 802D3350 0260282D */   daddu    $a1, $s3, $zero
.L802D3354:
/* F7D04 802D3354 2A420040 */  slti      $v0, $s2, 0x40
/* F7D08 802D3358 1440FFBB */  bnez      $v0, .L802D3248
/* F7D0C 802D335C 00000000 */   nop      
/* F7D10 802D3360 8FBF0284 */  lw        $ra, 0x284($sp)
/* F7D14 802D3364 8FBE0280 */  lw        $fp, 0x280($sp)
/* F7D18 802D3368 8FB7027C */  lw        $s7, 0x27c($sp)
/* F7D1C 802D336C 8FB60278 */  lw        $s6, 0x278($sp)
/* F7D20 802D3370 8FB50274 */  lw        $s5, 0x274($sp)
/* F7D24 802D3374 8FB40270 */  lw        $s4, 0x270($sp)
/* F7D28 802D3378 8FB3026C */  lw        $s3, 0x26c($sp)
/* F7D2C 802D337C 8FB20268 */  lw        $s2, 0x268($sp)
/* F7D30 802D3380 8FB10264 */  lw        $s1, 0x264($sp)
/* F7D34 802D3384 8FB00260 */  lw        $s0, 0x260($sp)
/* F7D38 802D3388 D7B60290 */  ldc1      $f22, 0x290($sp)
/* F7D3C 802D338C D7B40288 */  ldc1      $f20, 0x288($sp)
/* F7D40 802D3390 03E00008 */  jr        $ra
/* F7D44 802D3394 27BD0298 */   addiu    $sp, $sp, 0x298

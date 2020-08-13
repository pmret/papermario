.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel load_asset_by_name
/* 0360E8 8005ACE8 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0360EC 8005ACEC AFB00030 */  sw    $s0, 0x30($sp)
/* 0360F0 8005ACF0 0080802D */  daddu $s0, $a0, $zero
/* 0360F4 8005ACF4 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0360F8 8005ACF8 00A0982D */  daddu $s3, $a1, $zero
/* 0360FC 8005ACFC 3C0401E4 */  lui   $a0, 0x1e4
/* 036100 8005AD00 34840020 */  ori   $a0, $a0, 0x20
/* 036104 8005AD04 3C0501E4 */  lui   $a1, 0x1e4
/* 036108 8005AD08 34A5003C */  ori   $a1, $a1, 0x3c
/* 03610C 8005AD0C 27A60010 */  addiu $a2, $sp, 0x10
/* 036110 8005AD10 AFBF0040 */  sw    $ra, 0x40($sp)
/* 036114 8005AD14 AFB20038 */  sw    $s2, 0x38($sp)
/* 036118 8005AD18 0C00A5CF */  jal   dma_copy
/* 03611C 8005AD1C AFB10034 */   sw    $s1, 0x34($sp)
/* 036120 8005AD20 8FA40020 */  lw    $a0, 0x20($sp)
/* 036124 8005AD24 0C00AB39 */  jal   heap_malloc
/* 036128 8005AD28 00000000 */   nop   
/* 03612C 8005AD2C 0040902D */  daddu $s2, $v0, $zero
/* 036130 8005AD30 0240882D */  daddu $s1, $s2, $zero
/* 036134 8005AD34 3C0201E4 */  lui   $v0, 0x1e4
/* 036138 8005AD38 34420020 */  ori   $v0, $v0, 0x20
/* 03613C 8005AD3C 3C0401E4 */  lui   $a0, 0x1e4
/* 036140 8005AD40 34840020 */  ori   $a0, $a0, 0x20
/* 036144 8005AD44 8FA50020 */  lw    $a1, 0x20($sp)
/* 036148 8005AD48 0240302D */  daddu $a2, $s2, $zero
/* 03614C 8005AD4C 0C00A5CF */  jal   dma_copy
/* 036150 8005AD50 00A22821 */   addu  $a1, $a1, $v0
.L8005AD54:
/* 036154 8005AD54 0220202D */  daddu $a0, $s1, $zero
/* 036158 8005AD58 0C01BB5C */  jal   strcmp
/* 03615C 8005AD5C 0200282D */   daddu $a1, $s0, $zero
/* 036160 8005AD60 10400003 */  beqz  $v0, .L8005AD70
/* 036164 8005AD64 00000000 */   nop   
/* 036168 8005AD68 08016B55 */  j     .L8005AD54
/* 03616C 8005AD6C 2631001C */   addiu $s1, $s1, 0x1c

.L8005AD70:
/* 036170 8005AD70 8E220018 */  lw    $v0, 0x18($s1)
/* 036174 8005AD74 AE620000 */  sw    $v0, ($s3)
/* 036178 8005AD78 0C00AB0A */  jal   general_heap_malloc
/* 03617C 8005AD7C 8E240014 */   lw    $a0, 0x14($s1)
/* 036180 8005AD80 3C0301E4 */  lui   $v1, 0x1e4
/* 036184 8005AD84 34630020 */  ori   $v1, $v1, 0x20
/* 036188 8005AD88 0040802D */  daddu $s0, $v0, $zero
/* 03618C 8005AD8C 0040302D */  daddu $a2, $v0, $zero
/* 036190 8005AD90 8E220010 */  lw    $v0, 0x10($s1)
/* 036194 8005AD94 8E250014 */  lw    $a1, 0x14($s1)
/* 036198 8005AD98 00432021 */  addu  $a0, $v0, $v1
/* 03619C 8005AD9C 00A32821 */  addu  $a1, $a1, $v1
/* 0361A0 8005ADA0 0C00A5CF */  jal   dma_copy
/* 0361A4 8005ADA4 00452821 */   addu  $a1, $v0, $a1
/* 0361A8 8005ADA8 0C00AB4B */  jal   heap_free
/* 0361AC 8005ADAC 0240202D */   daddu $a0, $s2, $zero
/* 0361B0 8005ADB0 0200102D */  daddu $v0, $s0, $zero
/* 0361B4 8005ADB4 8FBF0040 */  lw    $ra, 0x40($sp)
/* 0361B8 8005ADB8 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0361BC 8005ADBC 8FB20038 */  lw    $s2, 0x38($sp)
/* 0361C0 8005ADC0 8FB10034 */  lw    $s1, 0x34($sp)
/* 0361C4 8005ADC4 8FB00030 */  lw    $s0, 0x30($sp)
/* 0361C8 8005ADC8 03E00008 */  jr    $ra
/* 0361CC 8005ADCC 27BD0048 */   addiu $sp, $sp, 0x48


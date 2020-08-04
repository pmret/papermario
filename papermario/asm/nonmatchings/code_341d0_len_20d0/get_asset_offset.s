.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_asset_offset
/* 0361D0 8005ADD0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0361D4 8005ADD4 AFB20038 */  sw    $s2, 0x38($sp)
/* 0361D8 8005ADD8 0080902D */  daddu $s2, $a0, $zero
/* 0361DC 8005ADDC AFB3003C */  sw    $s3, 0x3c($sp)
/* 0361E0 8005ADE0 00A0982D */  daddu $s3, $a1, $zero
/* 0361E4 8005ADE4 3C0401E4 */  lui   $a0, 0x1e4
/* 0361E8 8005ADE8 34840020 */  ori   $a0, $a0, 0x20
/* 0361EC 8005ADEC 3C0501E4 */  lui   $a1, 0x1e4
/* 0361F0 8005ADF0 34A5003C */  ori   $a1, $a1, 0x3c
/* 0361F4 8005ADF4 27A60010 */  addiu $a2, $sp, 0x10
/* 0361F8 8005ADF8 AFBF0040 */  sw    $ra, 0x40($sp)
/* 0361FC 8005ADFC AFB10034 */  sw    $s1, 0x34($sp)
/* 036200 8005AE00 0C00A5CF */  jal   dma_copy
/* 036204 8005AE04 AFB00030 */   sw    $s0, 0x30($sp)
/* 036208 8005AE08 8FA40020 */  lw    $a0, 0x20($sp)
/* 03620C 8005AE0C 0C00AB39 */  jal   heap_malloc
/* 036210 8005AE10 00000000 */   nop   
/* 036214 8005AE14 0040882D */  daddu $s1, $v0, $zero
/* 036218 8005AE18 0220802D */  daddu $s0, $s1, $zero
/* 03621C 8005AE1C 3C0201E4 */  lui   $v0, 0x1e4
/* 036220 8005AE20 34420020 */  ori   $v0, $v0, 0x20
/* 036224 8005AE24 3C0401E4 */  lui   $a0, 0x1e4
/* 036228 8005AE28 34840020 */  ori   $a0, $a0, 0x20
/* 03622C 8005AE2C 8FA50020 */  lw    $a1, 0x20($sp)
/* 036230 8005AE30 0220302D */  daddu $a2, $s1, $zero
/* 036234 8005AE34 0C00A5CF */  jal   dma_copy
/* 036238 8005AE38 00A22821 */   addu  $a1, $a1, $v0
.L8005AE3C:
/* 03623C 8005AE3C 0200202D */  daddu $a0, $s0, $zero
/* 036240 8005AE40 0C01BB5C */  jal   strcmp
/* 036244 8005AE44 0240282D */   daddu $a1, $s2, $zero
/* 036248 8005AE48 10400003 */  beqz  $v0, .L8005AE58
/* 03624C 8005AE4C 3C0301E4 */   lui   $v1, 0x1e4
/* 036250 8005AE50 08016B8F */  j     .L8005AE3C
/* 036254 8005AE54 2610001C */   addiu $s0, $s0, 0x1c

.L8005AE58:
/* 036258 8005AE58 8E020014 */  lw    $v0, 0x14($s0)
/* 03625C 8005AE5C 34630020 */  ori   $v1, $v1, 0x20
/* 036260 8005AE60 AE620000 */  sw    $v0, ($s3)
/* 036264 8005AE64 8E100010 */  lw    $s0, 0x10($s0)
/* 036268 8005AE68 0220202D */  daddu $a0, $s1, $zero
/* 03626C 8005AE6C 0C00AB4B */  jal   heap_free
/* 036270 8005AE70 02038021 */   addu  $s0, $s0, $v1
/* 036274 8005AE74 0200102D */  daddu $v0, $s0, $zero
/* 036278 8005AE78 8FBF0040 */  lw    $ra, 0x40($sp)
/* 03627C 8005AE7C 8FB3003C */  lw    $s3, 0x3c($sp)
/* 036280 8005AE80 8FB20038 */  lw    $s2, 0x38($sp)
/* 036284 8005AE84 8FB10034 */  lw    $s1, 0x34($sp)
/* 036288 8005AE88 8FB00030 */  lw    $s0, 0x30($sp)
/* 03628C 8005AE8C 03E00008 */  jr    $ra
/* 036290 8005AE90 27BD0048 */   addiu $sp, $sp, 0x48

/* 036294 8005AE94 00000000 */  nop   
/* 036298 8005AE98 00000000 */  nop   
/* 03629C 8005AE9C 00000000 */  nop   

.set reorder

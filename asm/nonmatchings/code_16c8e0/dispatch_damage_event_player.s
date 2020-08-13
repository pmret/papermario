.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel dispatch_damage_event_player
/* 1A1A9C 802731BC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1A1AA0 802731C0 00A0402D */  daddu $t0, $a1, $zero
/* 1A1AA4 802731C4 AFB30024 */  sw    $s3, 0x24($sp)
/* 1A1AA8 802731C8 3C13800E */  lui   $s3, 0x800e
/* 1A1AAC 802731CC 2673C070 */  addiu $s3, $s3, -0x3f90
/* 1A1AB0 802731D0 AFBF0028 */  sw    $ra, 0x28($sp)
/* 1A1AB4 802731D4 AFB20020 */  sw    $s2, 0x20($sp)
/* 1A1AB8 802731D8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1A1ABC 802731DC AFB00018 */  sw    $s0, 0x18($sp)
/* 1A1AC0 802731E0 A664017E */  sh    $a0, 0x17e($s3)
/* 1A1AC4 802731E4 00042400 */  sll   $a0, $a0, 0x10
/* 1A1AC8 802731E8 8E7000D8 */  lw    $s0, 0xd8($s3)
/* 1A1ACC 802731EC 00043C03 */  sra   $a3, $a0, 0x10
/* 1A1AD0 802731F0 960201FA */  lhu   $v0, 0x1fa($s0)
/* 1A1AD4 802731F4 3C058011 */  lui   $a1, 0x8011
/* 1A1AD8 802731F8 24A5F290 */  addiu $a1, $a1, -0xd70
/* 1A1ADC 802731FC 00471021 */  addu  $v0, $v0, $a3
/* 1A1AE0 80273200 00021C00 */  sll   $v1, $v0, 0x10
/* 1A1AE4 80273204 00033C03 */  sra   $a3, $v1, 0x10
/* 1A1AE8 80273208 A60201FA */  sh    $v0, 0x1fa($s0)
/* 1A1AEC 8027320C 90A40002 */  lbu   $a0, 2($a1)
/* 1A1AF0 80273210 960201FC */  lhu   $v0, 0x1fc($s0)
/* 1A1AF4 80273214 960301FA */  lhu   $v1, 0x1fa($s0)
/* 1A1AF8 80273218 00471021 */  addu  $v0, $v0, $a3
/* 1A1AFC 8027321C 00671823 */  subu  $v1, $v1, $a3
/* 1A1B00 80273220 A60201FC */  sh    $v0, 0x1fc($s0)
/* 1A1B04 80273224 A20401B8 */  sb    $a0, 0x1b8($s0)
/* 1A1B08 80273228 A60301FA */  sh    $v1, 0x1fa($s0)
/* 1A1B0C 8027322C A6600180 */  sh    $zero, 0x180($s3)
/* 1A1B10 80273230 920201B8 */  lbu   $v0, 0x1b8($s0)
/* 1A1B14 80273234 00471023 */  subu  $v0, $v0, $a3
/* 1A1B18 80273238 A20201B8 */  sb    $v0, 0x1b8($s0)
/* 1A1B1C 8027323C 9262007B */  lbu   $v0, 0x7b($s3)
/* 1A1B20 80273240 0100902D */  daddu $s2, $t0, $zero
/* 1A1B24 80273244 00471021 */  addu  $v0, $v0, $a3
/* 1A1B28 80273248 A262007B */  sb    $v0, 0x7b($s3)
/* 1A1B2C 8027324C 820301B8 */  lb    $v1, 0x1b8($s0)
/* 1A1B30 80273250 1C600006 */  bgtz  $v1, .L8027326C
/* 1A1B34 80273254 2611000C */   addiu $s1, $s0, 0xc
/* 1A1B38 80273258 96620180 */  lhu   $v0, 0x180($s3)
/* 1A1B3C 8027325C 24120020 */  addiu $s2, $zero, 0x20
/* 1A1B40 80273260 00431021 */  addu  $v0, $v0, $v1
/* 1A1B44 80273264 A6620180 */  sh    $v0, 0x180($s3)
/* 1A1B48 80273268 A20001B8 */  sb    $zero, 0x1b8($s0)
.L8027326C:
/* 1A1B4C 8027326C 96620180 */  lhu   $v0, 0x180($s3)
/* 1A1B50 80273270 00471021 */  addu  $v0, $v0, $a3
/* 1A1B54 80273274 A6620180 */  sh    $v0, 0x180($s3)
/* 1A1B58 80273278 920201B8 */  lbu   $v0, 0x1b8($s0)
/* 1A1B5C 8027327C A0A20002 */  sb    $v0, 2($a1)
/* 1A1B60 80273280 24020009 */  addiu $v0, $zero, 9
/* 1A1B64 80273284 52420001 */  beql  $s2, $v0, .L8027328C
/* 1A1B68 80273288 2412000A */   addiu $s2, $zero, 0xa
.L8027328C:
/* 1A1B6C 8027328C 24020017 */  addiu $v0, $zero, 0x17
/* 1A1B70 80273290 52420001 */  beql  $s2, $v0, .L80273298
/* 1A1B74 80273294 24120019 */   addiu $s2, $zero, 0x19
.L80273298:
/* 1A1B78 80273298 24020020 */  addiu $v0, $zero, 0x20
/* 1A1B7C 8027329C 16420009 */  bne   $s2, $v0, .L802732C4
/* 1A1B80 802732A0 2402002A */   addiu $v0, $zero, 0x2a
/* 1A1B84 802732A4 51020001 */  beql  $t0, $v0, .L802732AC
/* 1A1B88 802732A8 24120027 */   addiu $s2, $zero, 0x27
.L802732AC:
/* 1A1B8C 802732AC 2402002C */  addiu $v0, $zero, 0x2c
/* 1A1B90 802732B0 51020001 */  beql  $t0, $v0, .L802732B8
/* 1A1B94 802732B4 24120024 */   addiu $s2, $zero, 0x24
.L802732B8:
/* 1A1B98 802732B8 2402002F */  addiu $v0, $zero, 0x2f
/* 1A1B9C 802732BC 51020001 */  beql  $t0, $v0, .L802732C4
/* 1A1BA0 802732C0 24120026 */   addiu $s2, $zero, 0x26
.L802732C4:
/* 1A1BA4 802732C4 14C0000D */  bnez  $a2, .L802732FC
/* 1A1BA8 802732C8 24020001 */   addiu $v0, $zero, 1
/* 1A1BAC 802732CC 0220202D */  daddu $a0, $s1, $zero
/* 1A1BB0 802732D0 0000282D */  daddu $a1, $zero, $zero
/* 1A1BB4 802732D4 0C09A5D5 */  jal   set_goal_pos_to_part
/* 1A1BB8 802732D8 00A0302D */   daddu $a2, $a1, $zero
/* 1A1BBC 802732DC C6200014 */  lwc1  $f0, 0x14($s1)
/* 1A1BC0 802732E0 240400E9 */  addiu $a0, $zero, 0xe9
/* 1A1BC4 802732E4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 1A1BC8 802732E8 8E26000C */  lw    $a2, 0xc($s1)
/* 1A1BCC 802732EC 8E270010 */  lw    $a3, 0x10($s1)
/* 1A1BD0 802732F0 0C052757 */  jal   play_sound_at_position
/* 1A1BD4 802732F4 0000282D */   daddu $a1, $zero, $zero
/* 1A1BD8 802732F8 24020001 */  addiu $v0, $zero, 1
.L802732FC:
/* 1A1BDC 802732FC AFA20010 */  sw    $v0, 0x10($sp)
/* 1A1BE0 80273300 8E260014 */  lw    $a2, 0x14($s1)
/* 1A1BE4 80273304 86670180 */  lh    $a3, 0x180($s3)
/* 1A1BE8 80273308 C62C000C */  lwc1  $f12, 0xc($s1)
/* 1A1BEC 8027330C 0C09996B */  jal   show_damage_popup
/* 1A1BF0 80273310 C62E0010 */   lwc1  $f14, 0x10($s1)
/* 1A1BF4 80273314 86620180 */  lh    $v0, 0x180($s3)
/* 1A1BF8 80273318 AFA20010 */  sw    $v0, 0x10($sp)
/* 1A1BFC 8027331C 8E25000C */  lw    $a1, 0xc($s1)
/* 1A1C00 80273320 8E260010 */  lw    $a2, 0x10($s1)
/* 1A1C04 80273324 8E270014 */  lw    $a3, 0x14($s1)
/* 1A1C08 80273328 0C0999B9 */  jal   func_802666E4
/* 1A1C0C 8027332C 0200202D */   daddu $a0, $s0, $zero
/* 1A1C10 80273330 86620180 */  lh    $v0, 0x180($s3)
/* 1A1C14 80273334 18400003 */  blez  $v0, .L80273344
/* 1A1C18 80273338 0200202D */   daddu $a0, $s0, $zero
/* 1A1C1C 8027333C 0C099C06 */  jal   func_80267018
/* 1A1C20 80273340 24050001 */   addiu $a1, $zero, 1
.L80273344:
/* 1A1C24 80273344 3C10800E */  lui   $s0, 0x800e
/* 1A1C28 80273348 8E10C070 */  lw    $s0, -0x3f90($s0)
/* 1A1C2C 8027334C 0240202D */  daddu $a0, $s2, $zero
/* 1A1C30 80273350 32100240 */  andi  $s0, $s0, 0x240
/* 1A1C34 80273354 0C09C596 */  jal   dispatch_event_player
/* 1A1C38 80273358 0010802B */   sltu  $s0, $zero, $s0
/* 1A1C3C 8027335C 0200102D */  daddu $v0, $s0, $zero
/* 1A1C40 80273360 8FBF0028 */  lw    $ra, 0x28($sp)
/* 1A1C44 80273364 8FB30024 */  lw    $s3, 0x24($sp)
/* 1A1C48 80273368 8FB20020 */  lw    $s2, 0x20($sp)
/* 1A1C4C 8027336C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1A1C50 80273370 8FB00018 */  lw    $s0, 0x18($sp)
/* 1A1C54 80273374 03E00008 */  jr    $ra
/* 1A1C58 80273378 27BD0030 */   addiu $sp, $sp, 0x30


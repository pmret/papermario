.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E5088
/* 07E538 800E5088 3C028011 */  lui   $v0, 0x8011
/* 07E53C 800E508C 8042F2A2 */  lb    $v0, -0xd5e($v0)
/* 07E540 800E5090 03E00008 */  jr    $ra
/* 07E544 800E5094 00000000 */   nop   

/* 07E548 800E5098 3C028007 */  lui   $v0, 0x8007
/* 07E54C 800E509C 8C42419C */  lw    $v0, 0x419c($v0)
/* 07E550 800E50A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07E554 800E50A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 07E558 800E50A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 07E55C 800E50AC 94420134 */  lhu   $v0, 0x134($v0)
/* 07E560 800E50B0 14800002 */  bnez  $a0, .L800E50BC
/* 07E564 800E50B4 0044001A */   div   $zero, $v0, $a0
/* 07E568 800E50B8 0007000D */  break 7
.L800E50BC:
/* 07E56C 800E50BC 2401FFFF */  addiu $at, $zero, -1
/* 07E570 800E50C0 14810004 */  bne   $a0, $at, .L800E50D4
/* 07E574 800E50C4 3C018000 */   lui   $at, 0x8000
/* 07E578 800E50C8 14410002 */  bne   $v0, $at, .L800E50D4
/* 07E57C 800E50CC 00000000 */   nop   
/* 07E580 800E50D0 0006000D */  break 6
.L800E50D4:
/* 07E584 800E50D4 00001810 */  mfhi  $v1
/* 07E588 800E50D8 14600019 */  bnez  $v1, .L800E5140
/* 07E58C 800E50DC 00000000 */   nop   
/* 07E590 800E50E0 3C048016 */  lui   $a0, 0x8016
/* 07E594 800E50E4 8484A552 */  lh    $a0, -0x5aae($a0)
/* 07E598 800E50E8 0C016F6A */  jal   get_collider_type_by_id
/* 07E59C 800E50EC 00000000 */   nop   
/* 07E5A0 800E50F0 304300FF */  andi  $v1, $v0, 0xff
/* 07E5A4 800E50F4 24020006 */  addiu $v0, $zero, 6
/* 07E5A8 800E50F8 10620003 */  beq   $v1, $v0, .L800E5108
/* 07E5AC 800E50FC 24020009 */   addiu $v0, $zero, 9
/* 07E5B0 800E5100 14620004 */  bne   $v1, $v0, .L800E5114
/* 07E5B4 800E5104 24040141 */   addiu $a0, $zero, 0x141
.L800E5108:
/* 07E5B8 800E5108 24040143 */  addiu $a0, $zero, 0x143
/* 07E5BC 800E510C 08039446 */  j     .L800E5118
/* 07E5C0 800E5110 24030144 */   addiu $v1, $zero, 0x144

.L800E5114:
/* 07E5C4 800E5114 24030142 */  addiu $v1, $zero, 0x142
.L800E5118:
/* 07E5C8 800E5118 3C10800F */  lui   $s0, 0x800f
/* 07E5CC 800E511C 26107B80 */  addiu $s0, $s0, 0x7b80
/* 07E5D0 800E5120 86020000 */  lh    $v0, ($s0)
/* 07E5D4 800E5124 50400001 */  beql  $v0, $zero, .L800E512C
/* 07E5D8 800E5128 0060202D */   daddu $a0, $v1, $zero
.L800E512C:
/* 07E5DC 800E512C 0C052736 */  jal   play_sound_at_player
/* 07E5E0 800E5130 0000282D */   daddu $a1, $zero, $zero
/* 07E5E4 800E5134 96020000 */  lhu   $v0, ($s0)
/* 07E5E8 800E5138 38420001 */  xori  $v0, $v0, 1
/* 07E5EC 800E513C A6020000 */  sh    $v0, ($s0)
.L800E5140:
/* 07E5F0 800E5140 8FBF0014 */  lw    $ra, 0x14($sp)
/* 07E5F4 800E5144 8FB00010 */  lw    $s0, 0x10($sp)
/* 07E5F8 800E5148 03E00008 */  jr    $ra
/* 07E5FC 800E514C 27BD0018 */   addiu $sp, $sp, 0x18

/* 07E600 800E5150 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07E604 800E5154 AFBF0010 */  sw    $ra, 0x10($sp)
/* 07E608 800E5158 0C03945D */  jal   func_800E5174
/* 07E60C 800E515C 00000000 */   nop   
/* 07E610 800E5160 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07E614 800E5164 3C018016 */  lui   $at, 0x8016
/* 07E618 800E5168 A422A55A */  sh    $v0, -0x5aa6($at)
/* 07E61C 800E516C 03E00008 */  jr    $ra
/* 07E620 800E5170 27BD0018 */   addiu $sp, $sp, 0x18


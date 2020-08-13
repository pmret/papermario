.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E315C
/* 07C60C 800E315C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 07C610 800E3160 AFB00010 */  sw    $s0, 0x10($sp)
/* 07C614 800E3164 3C108011 */  lui   $s0, 0x8011
/* 07C618 800E3168 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 07C61C 800E316C AFB10014 */  sw    $s1, 0x14($sp)
/* 07C620 800E3170 3C118011 */  lui   $s1, 0x8011
/* 07C624 800E3174 2631EBB0 */  addiu $s1, $s1, -0x1450
/* 07C628 800E3178 0480003A */  bltz  $a0, .L800E3264
/* 07C62C 800E317C AFBF0018 */   sw    $ra, 0x18($sp)
/* 07C630 800E3180 0C016F6A */  jal   get_collider_type_by_id
/* 07C634 800E3184 00000000 */   nop   
/* 07C638 800E3188 304200FF */  andi  $v0, $v0, 0xff
/* 07C63C 800E318C 2443FFFF */  addiu $v1, $v0, -1
/* 07C640 800E3190 2C620005 */  sltiu $v0, $v1, 5
/* 07C644 800E3194 10400031 */  beqz  $v0, .L800E325C
/* 07C648 800E3198 00031080 */   sll   $v0, $v1, 2
/* 07C64C 800E319C 3C018011 */  lui   $at, 0x8011
/* 07C650 800E31A0 00220821 */  addu  $at, $at, $v0
/* 07C654 800E31A4 8C22BE40 */  lw    $v0, -0x41c0($at)
/* 07C658 800E31A8 00400008 */  jr    $v0
/* 07C65C 800E31AC 00000000 */   nop   
/* 07C660 800E31B0 0C039769 */  jal   set_action_state
/* 07C664 800E31B4 2404000A */   addiu $a0, $zero, 0xa
/* 07C668 800E31B8 08038C99 */  j     .L800E3264
/* 07C66C 800E31BC 00000000 */   nop   

/* 07C670 800E31C0 3C04FF00 */  lui   $a0, 0xff00
/* 07C674 800E31C4 348400FF */  ori   $a0, $a0, 0xff
/* 07C678 800E31C8 3C030100 */  lui   $v1, 0x100
/* 07C67C 800E31CC 8E220000 */  lw    $v0, ($s1)
/* 07C680 800E31D0 34630009 */  ori   $v1, $v1, 9
/* 07C684 800E31D4 00441024 */  and   $v0, $v0, $a0
/* 07C688 800E31D8 10430022 */  beq   $v0, $v1, .L800E3264
/* 07C68C 800E31DC 00000000 */   nop   
/* 07C690 800E31E0 86020010 */  lh    $v0, 0x10($s0)
/* 07C694 800E31E4 14400019 */  bnez  $v0, .L800E324C
/* 07C698 800E31E8 24020017 */   addiu $v0, $zero, 0x17
/* 07C69C 800E31EC 820300B4 */  lb    $v1, 0xb4($s0)
/* 07C6A0 800E31F0 1062001C */  beq   $v1, $v0, .L800E3264
/* 07C6A4 800E31F4 24020001 */   addiu $v0, $zero, 1
/* 07C6A8 800E31F8 08038C8F */  j     .L800E323C
/* 07C6AC 800E31FC A20200BF */   sb    $v0, 0xbf($s0)

/* 07C6B0 800E3200 3C04FF00 */  lui   $a0, 0xff00
/* 07C6B4 800E3204 348400FF */  ori   $a0, $a0, 0xff
/* 07C6B8 800E3208 3C030100 */  lui   $v1, 0x100
/* 07C6BC 800E320C 8E220000 */  lw    $v0, ($s1)
/* 07C6C0 800E3210 34630009 */  ori   $v1, $v1, 9
/* 07C6C4 800E3214 00441024 */  and   $v0, $v0, $a0
/* 07C6C8 800E3218 10430012 */  beq   $v0, $v1, .L800E3264
/* 07C6CC 800E321C 00000000 */   nop   
/* 07C6D0 800E3220 86020010 */  lh    $v0, 0x10($s0)
/* 07C6D4 800E3224 14400009 */  bnez  $v0, .L800E324C
/* 07C6D8 800E3228 24020015 */   addiu $v0, $zero, 0x15
/* 07C6DC 800E322C 820300B4 */  lb    $v1, 0xb4($s0)
/* 07C6E0 800E3230 1062000C */  beq   $v1, $v0, .L800E3264
/* 07C6E4 800E3234 24020002 */   addiu $v0, $zero, 2
/* 07C6E8 800E3238 A20200BF */  sb    $v0, 0xbf($s0)
.L800E323C:
/* 07C6EC 800E323C 0C039769 */  jal   set_action_state
/* 07C6F0 800E3240 24040017 */   addiu $a0, $zero, 0x17
/* 07C6F4 800E3244 08038C99 */  j     .L800E3264
/* 07C6F8 800E3248 00000000 */   nop   

.L800E324C:
/* 07C6FC 800E324C 0C039769 */  jal   set_action_state
/* 07C700 800E3250 24040016 */   addiu $a0, $zero, 0x16
/* 07C704 800E3254 08038C99 */  j     .L800E3264
/* 07C708 800E3258 00000000 */   nop   

.L800E325C:
/* 07C70C 800E325C 0C038C9E */  jal   func_800E3278
/* 07C710 800E3260 00000000 */   nop   
.L800E3264:
/* 07C714 800E3264 8FBF0018 */  lw    $ra, 0x18($sp)
/* 07C718 800E3268 8FB10014 */  lw    $s1, 0x14($sp)
/* 07C71C 800E326C 8FB00010 */  lw    $s0, 0x10($sp)
/* 07C720 800E3270 03E00008 */  jr    $ra
/* 07C724 800E3274 27BD0020 */   addiu $sp, $sp, 0x20


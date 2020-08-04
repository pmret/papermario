.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E3278
/* 07C728 800E3278 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 07C72C 800E327C 3C02FF7F */  lui   $v0, 0xff7f
/* 07C730 800E3280 3442FFFF */  ori   $v0, $v0, 0xffff
/* 07C734 800E3284 24040148 */  addiu $a0, $zero, 0x148
/* 07C738 800E3288 AFB00018 */  sw    $s0, 0x18($sp)
/* 07C73C 800E328C 3C108011 */  lui   $s0, 0x8011
/* 07C740 800E3290 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 07C744 800E3294 AFBF0020 */  sw    $ra, 0x20($sp)
/* 07C748 800E3298 AFB1001C */  sw    $s1, 0x1c($sp)
/* 07C74C 800E329C 8E030000 */  lw    $v1, ($s0)
/* 07C750 800E32A0 C6000028 */  lwc1  $f0, 0x28($s0)
/* 07C754 800E32A4 C6020030 */  lwc1  $f2, 0x30($s0)
/* 07C758 800E32A8 0000282D */  daddu $a1, $zero, $zero
/* 07C75C 800E32AC A60000C0 */  sh    $zero, 0xc0($s0)
/* 07C760 800E32B0 A60000C2 */  sh    $zero, 0xc2($s0)
/* 07C764 800E32B4 00621824 */  and   $v1, $v1, $v0
/* 07C768 800E32B8 2402FFF1 */  addiu $v0, $zero, -0xf
/* 07C76C 800E32BC AE030000 */  sw    $v1, ($s0)
/* 07C770 800E32C0 00621824 */  and   $v1, $v1, $v0
/* 07C774 800E32C4 E6000044 */  swc1  $f0, 0x44($s0)
/* 07C778 800E32C8 E6020048 */  swc1  $f2, 0x48($s0)
/* 07C77C 800E32CC 0C052736 */  jal   play_sound_at_player
/* 07C780 800E32D0 AE030000 */   sw    $v1, ($s0)
/* 07C784 800E32D4 3C038016 */  lui   $v1, 0x8016
/* 07C788 800E32D8 2463A550 */  addiu $v1, $v1, -0x5ab0
/* 07C78C 800E32DC 94620002 */  lhu   $v0, 2($v1)
/* 07C790 800E32E0 30424000 */  andi  $v0, $v0, 0x4000
/* 07C794 800E32E4 14400003 */  bnez  $v0, .L800E32F4
/* 07C798 800E32E8 0060882D */   daddu $s1, $v1, $zero
/* 07C79C 800E32EC 0C03954C */  jal   func_800E5530
/* 07C7A0 800E32F0 00000000 */   nop   
.L800E32F4:
/* 07C7A4 800E32F4 96240002 */  lhu   $a0, 2($s1)
/* 07C7A8 800E32F8 2402FFFF */  addiu $v0, $zero, -1
/* 07C7AC 800E32FC A6220004 */  sh    $v0, 4($s1)
/* 07C7B0 800E3300 30824000 */  andi  $v0, $a0, 0x4000
/* 07C7B4 800E3304 10400022 */  beqz  $v0, .L800E3390
/* 07C7B8 800E3308 00042400 */   sll   $a0, $a0, 0x10
/* 07C7BC 800E330C 0C0441A9 */  jal   func_801106A4
/* 07C7C0 800E3310 00042403 */   sra   $a0, $a0, 0x10
/* 07C7C4 800E3314 0040182D */  daddu $v1, $v0, $zero
/* 07C7C8 800E3318 28620009 */  slti  $v0, $v1, 9
/* 07C7CC 800E331C 1040001C */  beqz  $v0, .L800E3390
/* 07C7D0 800E3320 28620007 */   slti  $v0, $v1, 7
/* 07C7D4 800E3324 1440001A */  bnez  $v0, .L800E3390
/* 07C7D8 800E3328 00000000 */   nop   
/* 07C7DC 800E332C 0C04417A */  jal   get_entity_by_index
/* 07C7E0 800E3330 86240002 */   lh    $a0, 2($s1)
/* 07C7E4 800E3334 90430006 */  lbu   $v1, 6($v0)
/* 07C7E8 800E3338 34630001 */  ori   $v1, $v1, 1
/* 07C7EC 800E333C A0430006 */  sb    $v1, 6($v0)
/* 07C7F0 800E3340 920300B4 */  lbu   $v1, 0xb4($s0)
/* 07C7F4 800E3344 2462FFF1 */  addiu $v0, $v1, -0xf
/* 07C7F8 800E3348 2C420002 */  sltiu $v0, $v0, 2
/* 07C7FC 800E334C 1440000B */  bnez  $v0, .L800E337C
/* 07C800 800E3350 00031600 */   sll   $v0, $v1, 0x18
/* 07C804 800E3354 00021E03 */  sra   $v1, $v0, 0x18
/* 07C808 800E3358 2402000D */  addiu $v0, $zero, 0xd
/* 07C80C 800E335C 10620007 */  beq   $v1, $v0, .L800E337C
/* 07C810 800E3360 2402000E */   addiu $v0, $zero, 0xe
/* 07C814 800E3364 10620005 */  beq   $v1, $v0, .L800E337C
/* 07C818 800E3368 00000000 */   nop   
/* 07C81C 800E336C 0C039769 */  jal   set_action_state
/* 07C820 800E3370 24040007 */   addiu $a0, $zero, 7
/* 07C824 800E3374 08038D0D */  j     .L800E3434
/* 07C828 800E3378 00000000 */   nop   

.L800E337C:
/* 07C82C 800E337C 0C03805E */  jal   func_800E0178
/* 07C830 800E3380 00000000 */   nop   
/* 07C834 800E3384 2402000B */  addiu $v0, $zero, 0xb
/* 07C838 800E3388 08038D0D */  j     .L800E3434
/* 07C83C 800E338C A20200B6 */   sb    $v0, 0xb6($s0)

.L800E3390:
/* 07C840 800E3390 8E020000 */  lw    $v0, ($s0)
/* 07C844 800E3394 30424000 */  andi  $v0, $v0, 0x4000
/* 07C848 800E3398 10400005 */  beqz  $v0, .L800E33B0
/* 07C84C 800E339C 24020007 */   addiu $v0, $zero, 7
/* 07C850 800E33A0 0C039769 */  jal   set_action_state
/* 07C854 800E33A4 24040002 */   addiu $a0, $zero, 2
/* 07C858 800E33A8 08038D0D */  j     .L800E3434
/* 07C85C 800E33AC 00000000 */   nop   

.L800E33B0:
/* 07C860 800E33B0 820300B4 */  lb    $v1, 0xb4($s0)
/* 07C864 800E33B4 14620005 */  bne   $v1, $v0, .L800E33CC
/* 07C868 800E33B8 27A40010 */   addiu $a0, $sp, 0x10
/* 07C86C 800E33BC 0C039769 */  jal   set_action_state
/* 07C870 800E33C0 24040020 */   addiu $a0, $zero, 0x20
/* 07C874 800E33C4 08038D0D */  j     .L800E3434
/* 07C878 800E33C8 00000000 */   nop   

.L800E33CC:
/* 07C87C 800E33CC 0C0388C1 */  jal   func_800E2304
/* 07C880 800E33D0 27A50014 */   addiu $a1, $sp, 0x14
/* 07C884 800E33D4 C7A00014 */  lwc1  $f0, 0x14($sp)
/* 07C888 800E33D8 44801000 */  mtc1  $zero, $f2
/* 07C88C 800E33DC 00000000 */  nop   
/* 07C890 800E33E0 46020032 */  c.eq.s $f0, $f2
/* 07C894 800E33E4 00000000 */  nop   
/* 07C898 800E33E8 4500000C */  bc1f  .L800E341C
/* 07C89C 800E33EC 24020009 */   addiu $v0, $zero, 9
/* 07C8A0 800E33F0 820300B4 */  lb    $v1, 0xb4($s0)
/* 07C8A4 800E33F4 10620005 */  beq   $v1, $v0, .L800E340C
/* 07C8A8 800E33F8 00000000 */   nop   
/* 07C8AC 800E33FC 0C039769 */  jal   set_action_state
/* 07C8B0 800E3400 2404000A */   addiu $a0, $zero, 0xa
/* 07C8B4 800E3404 08038D0D */  j     .L800E3434
/* 07C8B8 800E3408 00000000 */   nop   

.L800E340C:
/* 07C8BC 800E340C 0C039769 */  jal   set_action_state
/* 07C8C0 800E3410 2404000B */   addiu $a0, $zero, 0xb
/* 07C8C4 800E3414 08038D0D */  j     .L800E3434
/* 07C8C8 800E3418 00000000 */   nop   

.L800E341C:
/* 07C8CC 800E341C 45010003 */  bc1t  .L800E342C
/* 07C8D0 800E3420 00000000 */   nop   
/* 07C8D4 800E3424 C7A00010 */  lwc1  $f0, 0x10($sp)
/* 07C8D8 800E3428 E6000080 */  swc1  $f0, 0x80($s0)
.L800E342C:
/* 07C8DC 800E342C 0C0397DA */  jal   update_locomotion_state
/* 07C8E0 800E3430 00000000 */   nop   
.L800E3434:
/* 07C8E4 800E3434 8FBF0020 */  lw    $ra, 0x20($sp)
/* 07C8E8 800E3438 8FB1001C */  lw    $s1, 0x1c($sp)
/* 07C8EC 800E343C 8FB00018 */  lw    $s0, 0x18($sp)
/* 07C8F0 800E3440 03E00008 */  jr    $ra
/* 07C8F4 800E3444 27BD0028 */   addiu $sp, $sp, 0x28


.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel phys_player_land
/* 7C728 800E3278 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7C72C 800E327C 3C02FF7F */  lui       $v0, 0xff7f
/* 7C730 800E3280 3442FFFF */  ori       $v0, $v0, 0xffff
/* 7C734 800E3284 24040148 */  addiu     $a0, $zero, 0x148
/* 7C738 800E3288 AFB00018 */  sw        $s0, 0x18($sp)
/* 7C73C 800E328C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7C740 800E3290 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7C744 800E3294 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7C748 800E3298 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7C74C 800E329C 8E030000 */  lw        $v1, ($s0)
/* 7C750 800E32A0 C6000028 */  lwc1      $f0, 0x28($s0)
/* 7C754 800E32A4 C6020030 */  lwc1      $f2, 0x30($s0)
/* 7C758 800E32A8 0000282D */  daddu     $a1, $zero, $zero
/* 7C75C 800E32AC A60000C0 */  sh        $zero, 0xc0($s0)
/* 7C760 800E32B0 A60000C2 */  sh        $zero, 0xc2($s0)
/* 7C764 800E32B4 00621824 */  and       $v1, $v1, $v0
/* 7C768 800E32B8 2402FFF1 */  addiu     $v0, $zero, -0xf
/* 7C76C 800E32BC AE030000 */  sw        $v1, ($s0)
/* 7C770 800E32C0 00621824 */  and       $v1, $v1, $v0
/* 7C774 800E32C4 E6000044 */  swc1      $f0, 0x44($s0)
/* 7C778 800E32C8 E6020048 */  swc1      $f2, 0x48($s0)
/* 7C77C 800E32CC 0C052736 */  jal       sfx_play_sound_at_player
/* 7C780 800E32D0 AE030000 */   sw       $v1, ($s0)
/* 7C784 800E32D4 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* 7C788 800E32D8 2463A550 */  addiu     $v1, $v1, %lo(gCollisionStatus)
/* 7C78C 800E32DC 94620002 */  lhu       $v0, 2($v1)
/* 7C790 800E32E0 30424000 */  andi      $v0, $v0, 0x4000
/* 7C794 800E32E4 14400003 */  bnez      $v0, .L800E32F4
/* 7C798 800E32E8 0060882D */   daddu    $s1, $v1, $zero
/* 7C79C 800E32EC 0C03954C */  jal       func_800E5530
/* 7C7A0 800E32F0 00000000 */   nop
.L800E32F4:
/* 7C7A4 800E32F4 96240002 */  lhu       $a0, 2($s1)
/* 7C7A8 800E32F8 2402FFFF */  addiu     $v0, $zero, -1
/* 7C7AC 800E32FC A6220004 */  sh        $v0, 4($s1)
/* 7C7B0 800E3300 30824000 */  andi      $v0, $a0, 0x4000
/* 7C7B4 800E3304 10400022 */  beqz      $v0, .L800E3390
/* 7C7B8 800E3308 00042400 */   sll      $a0, $a0, 0x10
/* 7C7BC 800E330C 0C0441A9 */  jal       get_entity_type
/* 7C7C0 800E3310 00042403 */   sra      $a0, $a0, 0x10
/* 7C7C4 800E3314 0040182D */  daddu     $v1, $v0, $zero
/* 7C7C8 800E3318 28620009 */  slti      $v0, $v1, 9
/* 7C7CC 800E331C 1040001C */  beqz      $v0, .L800E3390
/* 7C7D0 800E3320 28620007 */   slti     $v0, $v1, 7
/* 7C7D4 800E3324 1440001A */  bnez      $v0, .L800E3390
/* 7C7D8 800E3328 00000000 */   nop
/* 7C7DC 800E332C 0C04417A */  jal       get_entity_by_index
/* 7C7E0 800E3330 86240002 */   lh       $a0, 2($s1)
/* 7C7E4 800E3334 90430006 */  lbu       $v1, 6($v0)
/* 7C7E8 800E3338 34630001 */  ori       $v1, $v1, 1
/* 7C7EC 800E333C A0430006 */  sb        $v1, 6($v0)
/* 7C7F0 800E3340 920300B4 */  lbu       $v1, 0xb4($s0)
/* 7C7F4 800E3344 2462FFF1 */  addiu     $v0, $v1, -0xf
/* 7C7F8 800E3348 2C420002 */  sltiu     $v0, $v0, 2
/* 7C7FC 800E334C 1440000B */  bnez      $v0, .L800E337C
/* 7C800 800E3350 00031600 */   sll      $v0, $v1, 0x18
/* 7C804 800E3354 00021E03 */  sra       $v1, $v0, 0x18
/* 7C808 800E3358 2402000D */  addiu     $v0, $zero, 0xd
/* 7C80C 800E335C 10620007 */  beq       $v1, $v0, .L800E337C
/* 7C810 800E3360 2402000E */   addiu    $v0, $zero, 0xe
/* 7C814 800E3364 10620005 */  beq       $v1, $v0, .L800E337C
/* 7C818 800E3368 00000000 */   nop
/* 7C81C 800E336C 0C039769 */  jal       set_action_state
/* 7C820 800E3370 24040007 */   addiu    $a0, $zero, 7
/* 7C824 800E3374 08038D0D */  j         .L800E3434
/* 7C828 800E3378 00000000 */   nop
.L800E337C:
/* 7C82C 800E337C 0C03805E */  jal       disable_player_input
/* 7C830 800E3380 00000000 */   nop
/* 7C834 800E3384 2402000B */  addiu     $v0, $zero, 0xb
/* 7C838 800E3388 08038D0D */  j         .L800E3434
/* 7C83C 800E338C A20200B6 */   sb       $v0, 0xb6($s0)
.L800E3390:
/* 7C840 800E3390 8E020000 */  lw        $v0, ($s0)
/* 7C844 800E3394 30424000 */  andi      $v0, $v0, 0x4000
/* 7C848 800E3398 10400005 */  beqz      $v0, .L800E33B0
/* 7C84C 800E339C 24020007 */   addiu    $v0, $zero, 7
/* 7C850 800E33A0 0C039769 */  jal       set_action_state
/* 7C854 800E33A4 24040002 */   addiu    $a0, $zero, 2
/* 7C858 800E33A8 08038D0D */  j         .L800E3434
/* 7C85C 800E33AC 00000000 */   nop
.L800E33B0:
/* 7C860 800E33B0 820300B4 */  lb        $v1, 0xb4($s0)
/* 7C864 800E33B4 14620005 */  bne       $v1, $v0, .L800E33CC
/* 7C868 800E33B8 27A40010 */   addiu    $a0, $sp, 0x10
/* 7C86C 800E33BC 0C039769 */  jal       set_action_state
/* 7C870 800E33C0 24040020 */   addiu    $a0, $zero, 0x20
/* 7C874 800E33C4 08038D0D */  j         .L800E3434
/* 7C878 800E33C8 00000000 */   nop
.L800E33CC:
/* 7C87C 800E33CC 0C0388C1 */  jal       input_to_move_vector
/* 7C880 800E33D0 27A50014 */   addiu    $a1, $sp, 0x14
/* 7C884 800E33D4 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 7C888 800E33D8 44801000 */  mtc1      $zero, $f2
/* 7C88C 800E33DC 00000000 */  nop
/* 7C890 800E33E0 46020032 */  c.eq.s    $f0, $f2
/* 7C894 800E33E4 00000000 */  nop
/* 7C898 800E33E8 4500000C */  bc1f      .L800E341C
/* 7C89C 800E33EC 24020009 */   addiu    $v0, $zero, 9
/* 7C8A0 800E33F0 820300B4 */  lb        $v1, 0xb4($s0)
/* 7C8A4 800E33F4 10620005 */  beq       $v1, $v0, .L800E340C
/* 7C8A8 800E33F8 00000000 */   nop
/* 7C8AC 800E33FC 0C039769 */  jal       set_action_state
/* 7C8B0 800E3400 2404000A */   addiu    $a0, $zero, 0xa
/* 7C8B4 800E3404 08038D0D */  j         .L800E3434
/* 7C8B8 800E3408 00000000 */   nop
.L800E340C:
/* 7C8BC 800E340C 0C039769 */  jal       set_action_state
/* 7C8C0 800E3410 2404000B */   addiu    $a0, $zero, 0xb
/* 7C8C4 800E3414 08038D0D */  j         .L800E3434
/* 7C8C8 800E3418 00000000 */   nop
.L800E341C:
/* 7C8CC 800E341C 45010003 */  bc1t      .L800E342C
/* 7C8D0 800E3420 00000000 */   nop
/* 7C8D4 800E3424 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 7C8D8 800E3428 E6000080 */  swc1      $f0, 0x80($s0)
.L800E342C:
/* 7C8DC 800E342C 0C0397DA */  jal       update_locomotion_state
/* 7C8E0 800E3430 00000000 */   nop
.L800E3434:
/* 7C8E4 800E3434 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7C8E8 800E3438 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7C8EC 800E343C 8FB00018 */  lw        $s0, 0x18($sp)
/* 7C8F0 800E3440 03E00008 */  jr        $ra
/* 7C8F4 800E3444 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_74D570
/* 74D570 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 74D574 802A1004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 74D578 802A1008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 74D57C 802A100C AFBF0020 */  sw        $ra, 0x20($sp)
/* 74D580 802A1010 AFB1001C */  sw        $s1, 0x1c($sp)
/* 74D584 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 74D588 802A1018 8C6200D8 */  lw        $v0, 0xd8($v1)
/* 74D58C 802A101C 0080802D */  daddu     $s0, $a0, $zero
/* 74D590 802A1020 C442001C */  lwc1      $f2, 0x1c($v0)
/* 74D594 802A1024 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 74D598 802A1028 C44E0148 */  lwc1      $f14, 0x148($v0)
/* 74D59C 802A102C C444014C */  lwc1      $f4, 0x14c($v0)
/* 74D5A0 802A1030 C4460018 */  lwc1      $f6, 0x18($v0)
/* 74D5A4 802A1034 C4400020 */  lwc1      $f0, 0x20($v0)
/* 74D5A8 802A1038 44062000 */  mfc1      $a2, $f4
/* 74D5AC 802A103C 44073000 */  mfc1      $a3, $f6
/* 74D5B0 802A1040 0060882D */  daddu     $s1, $v1, $zero
/* 74D5B4 802A1044 E7A20010 */  swc1      $f2, 0x10($sp)
/* 74D5B8 802A1048 0C00A7CB */  jal       dist3D
/* 74D5BC 802A104C E7A00014 */   swc1     $f0, 0x14($sp)
/* 74D5C0 802A1050 3C014170 */  lui       $at, 0x4170
/* 74D5C4 802A1054 44811000 */  mtc1      $at, $f2
/* 74D5C8 802A1058 00000000 */  nop
/* 74D5CC 802A105C 46020002 */  mul.s     $f0, $f0, $f2
/* 74D5D0 802A1060 00000000 */  nop
/* 74D5D4 802A1064 3C0142C8 */  lui       $at, 0x42c8
/* 74D5D8 802A1068 44811000 */  mtc1      $at, $f2
/* 74D5DC 802A106C 00000000 */  nop
/* 74D5E0 802A1070 46020003 */  div.s     $f0, $f0, $f2
/* 74D5E4 802A1074 4600020D */  trunc.w.s $f8, $f0
/* 74D5E8 802A1078 44024000 */  mfc1      $v0, $f8
/* 74D5EC 802A107C 00000000 */  nop
/* 74D5F0 802A1080 AE020084 */  sw        $v0, 0x84($s0)
/* 74D5F4 802A1084 28420015 */  slti      $v0, $v0, 0x15
/* 74D5F8 802A1088 14400002 */  bnez      $v0, .L802A1094
/* 74D5FC 802A108C 24020014 */   addiu    $v0, $zero, 0x14
/* 74D600 802A1090 AE020084 */  sw        $v0, 0x84($s0)
.L802A1094:
/* 74D604 802A1094 82220083 */  lb        $v0, 0x83($s1)
/* 74D608 802A1098 10400007 */  beqz      $v0, .L802A10B8
/* 74D60C 802A109C 00000000 */   nop
/* 74D610 802A10A0 8E020084 */  lw        $v0, 0x84($s0)
/* 74D614 802A10A4 28420006 */  slti      $v0, $v0, 6
/* 74D618 802A10A8 10400008 */  beqz      $v0, .L802A10CC
/* 74D61C 802A10AC 24020006 */   addiu    $v0, $zero, 6
/* 74D620 802A10B0 080A8433 */  j         .L802A10CC
/* 74D624 802A10B4 AE020084 */   sw       $v0, 0x84($s0)
.L802A10B8:
/* 74D628 802A10B8 8E020084 */  lw        $v0, 0x84($s0)
/* 74D62C 802A10BC 2842000C */  slti      $v0, $v0, 0xc
/* 74D630 802A10C0 10400002 */  beqz      $v0, .L802A10CC
/* 74D634 802A10C4 2402000C */   addiu    $v0, $zero, 0xc
/* 74D638 802A10C8 AE020084 */  sw        $v0, 0x84($s0)
.L802A10CC:
/* 74D63C 802A10CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 74D640 802A10D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 74D644 802A10D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 74D648 802A10D8 24020002 */  addiu     $v0, $zero, 2
/* 74D64C 802A10DC 03E00008 */  jr        $ra
/* 74D650 802A10E0 27BD0028 */   addiu    $sp, $sp, 0x28

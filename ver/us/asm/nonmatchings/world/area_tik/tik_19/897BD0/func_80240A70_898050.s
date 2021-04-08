.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_19_UnkFunc20
/* 898050 80240A70 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 898054 80240A74 AFB1001C */  sw        $s1, 0x1c($sp)
/* 898058 80240A78 0080882D */  daddu     $s1, $a0, $zero
/* 89805C 80240A7C AFBF0020 */  sw        $ra, 0x20($sp)
/* 898060 80240A80 AFB00018 */  sw        $s0, 0x18($sp)
/* 898064 80240A84 8E30000C */  lw        $s0, 0xc($s1)
/* 898068 80240A88 8E050000 */  lw        $a1, ($s0)
/* 89806C 80240A8C 0C0B1EAF */  jal       get_variable
/* 898070 80240A90 26100004 */   addiu    $s0, $s0, 4
/* 898074 80240A94 0C04417A */  jal       get_entity_by_index
/* 898078 80240A98 0040202D */   daddu    $a0, $v0, $zero
/* 89807C 80240A9C 8E100000 */  lw        $s0, ($s0)
/* 898080 80240AA0 C444004C */  lwc1      $f4, 0x4c($v0)
/* 898084 80240AA4 3C014148 */  lui       $at, 0x4148
/* 898088 80240AA8 44810000 */  mtc1      $at, $f0
/* 89808C 80240AAC 3C013F33 */  lui       $at, 0x3f33
/* 898090 80240AB0 34213333 */  ori       $at, $at, 0x3333
/* 898094 80240AB4 44811000 */  mtc1      $at, $f2
/* 898098 80240AB8 AFA00014 */  sw        $zero, 0x14($sp)
/* 89809C 80240ABC 46002100 */  add.s     $f4, $f4, $f0
/* 8980A0 80240AC0 E7A20010 */  swc1      $f2, 0x10($sp)
/* 8980A4 80240AC4 8C450048 */  lw        $a1, 0x48($v0)
/* 8980A8 80240AC8 8C470050 */  lw        $a3, 0x50($v0)
/* 8980AC 80240ACC 44062000 */  mfc1      $a2, $f4
/* 8980B0 80240AD0 0C01C5D4 */  jal       func_80071750
/* 8980B4 80240AD4 0000202D */   daddu    $a0, $zero, $zero
/* 8980B8 80240AD8 0220202D */  daddu     $a0, $s1, $zero
/* 8980BC 80240ADC 0200282D */  daddu     $a1, $s0, $zero
/* 8980C0 80240AE0 0C0B2026 */  jal       set_variable
/* 8980C4 80240AE4 0040302D */   daddu    $a2, $v0, $zero
/* 8980C8 80240AE8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8980CC 80240AEC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8980D0 80240AF0 8FB00018 */  lw        $s0, 0x18($sp)
/* 8980D4 80240AF4 24020002 */  addiu     $v0, $zero, 2
/* 8980D8 80240AF8 03E00008 */  jr        $ra
/* 8980DC 80240AFC 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sfx_get_spatialized_sound_params
/* E0504 80149E04 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E0508 80149E08 44860000 */  mtc1      $a2, $f0
/* E050C 80149E0C 8FA3003C */  lw        $v1, 0x3c($sp)
/* E0510 80149E10 AFB1001C */  sw        $s1, 0x1c($sp)
/* E0514 80149E14 AFB20020 */  sw        $s2, 0x20($sp)
/* E0518 80149E18 8FB20038 */  lw        $s2, 0x38($sp)
/* E051C 80149E1C 3C02FFFF */  lui       $v0, 0xffff
/* E0520 80149E20 AFBF0024 */  sw        $ra, 0x24($sp)
/* E0524 80149E24 AFB00018 */  sw        $s0, 0x18($sp)
/* E0528 80149E28 00628024 */  and       $s0, $v1, $v0
/* E052C 80149E2C 3063FFFF */  andi      $v1, $v1, 0xffff
/* E0530 80149E30 24020001 */  addiu     $v0, $zero, 1
/* E0534 80149E34 1062000D */  beq       $v1, $v0, .L80149E6C
/* E0538 80149E38 00E0882D */   daddu    $s1, $a3, $zero
/* E053C 80149E3C 10600005 */  beqz      $v1, .L80149E54
/* E0540 80149E40 24020002 */   addiu    $v0, $zero, 2
/* E0544 80149E44 1062000F */  beq       $v1, $v0, .L80149E84
/* E0548 80149E48 3C020001 */   lui      $v0, 1
/* E054C 80149E4C 080527A8 */  j         .L80149EA0
/* E0550 80149E50 02021024 */   and      $v0, $s0, $v0
.L80149E54:
/* E0554 80149E54 44060000 */  mfc1      $a2, $f0
/* E0558 80149E58 0220382D */  daddu     $a3, $s1, $zero
/* E055C 80149E5C 0C0527D6 */  jal       sfx_compute_spatialized_sound_params_0
/* E0560 80149E60 AFB20010 */   sw       $s2, 0x10($sp)
/* E0564 80149E64 080527A7 */  j         .L80149E9C
/* E0568 80149E68 3C020001 */   lui      $v0, 1
.L80149E6C:
/* E056C 80149E6C 44060000 */  mfc1      $a2, $f0
/* E0570 80149E70 0220382D */  daddu     $a3, $s1, $zero
/* E0574 80149E74 0C05286D */  jal       sfx_compute_spatialized_sound_params_1
/* E0578 80149E78 AFB20010 */   sw       $s2, 0x10($sp)
/* E057C 80149E7C 080527A7 */  j         .L80149E9C
/* E0580 80149E80 3C020001 */   lui      $v0, 1
.L80149E84:
/* E0584 80149E84 44060000 */  mfc1      $a2, $f0
/* E0588 80149E88 0220382D */  daddu     $a3, $s1, $zero
/* E058C 80149E8C AFB20010 */  sw        $s2, 0x10($sp)
/* E0590 80149E90 0C052494 */  jal       sfx_compute_spatialized_sound_params_2
/* E0594 80149E94 AFB00014 */   sw       $s0, 0x14($sp)
/* E0598 80149E98 3C020001 */  lui       $v0, 1
.L80149E9C:
/* E059C 80149E9C 02021024 */  and       $v0, $s0, $v0
.L80149EA0:
/* E05A0 80149EA0 10400003 */  beqz      $v0, .L80149EB0
/* E05A4 80149EA4 3C020040 */   lui      $v0, 0x40
/* E05A8 80149EA8 080527C6 */  j         .L80149F18
/* E05AC 80149EAC A6200000 */   sh       $zero, ($s1)
.L80149EB0:
/* E05B0 80149EB0 02021024 */  and       $v0, $s0, $v0
/* E05B4 80149EB4 10400007 */  beqz      $v0, .L80149ED4
/* E05B8 80149EB8 3C020020 */   lui      $v0, 0x20
/* E05BC 80149EBC 86220000 */  lh        $v0, ($s1)
/* E05C0 80149EC0 28420050 */  slti      $v0, $v0, 0x50
/* E05C4 80149EC4 10400014 */  beqz      $v0, .L80149F18
/* E05C8 80149EC8 24020050 */   addiu    $v0, $zero, 0x50
/* E05CC 80149ECC 080527C6 */  j         .L80149F18
/* E05D0 80149ED0 A6220000 */   sh       $v0, ($s1)
.L80149ED4:
/* E05D4 80149ED4 02021024 */  and       $v0, $s0, $v0
/* E05D8 80149ED8 10400007 */  beqz      $v0, .L80149EF8
/* E05DC 80149EDC 3C020010 */   lui      $v0, 0x10
/* E05E0 80149EE0 86220000 */  lh        $v0, ($s1)
/* E05E4 80149EE4 2842003C */  slti      $v0, $v0, 0x3c
/* E05E8 80149EE8 1040000B */  beqz      $v0, .L80149F18
/* E05EC 80149EEC 2402003C */   addiu    $v0, $zero, 0x3c
/* E05F0 80149EF0 080527C6 */  j         .L80149F18
/* E05F4 80149EF4 A6220000 */   sh       $v0, ($s1)
.L80149EF8:
/* E05F8 80149EF8 02021024 */  and       $v0, $s0, $v0
/* E05FC 80149EFC 10400006 */  beqz      $v0, .L80149F18
/* E0600 80149F00 00000000 */   nop
/* E0604 80149F04 86220000 */  lh        $v0, ($s1)
/* E0608 80149F08 28420028 */  slti      $v0, $v0, 0x28
/* E060C 80149F0C 10400002 */  beqz      $v0, .L80149F18
/* E0610 80149F10 24020028 */   addiu    $v0, $zero, 0x28
/* E0614 80149F14 A6220000 */  sh        $v0, ($s1)
.L80149F18:
/* E0618 80149F18 86420000 */  lh        $v0, ($s2)
/* E061C 80149F1C 1C400005 */  bgtz      $v0, .L80149F34
/* E0620 80149F20 28420080 */   slti     $v0, $v0, 0x80
/* E0624 80149F24 24020001 */  addiu     $v0, $zero, 1
/* E0628 80149F28 A6420000 */  sh        $v0, ($s2)
/* E062C 80149F2C 86420000 */  lh        $v0, ($s2)
/* E0630 80149F30 28420080 */  slti      $v0, $v0, 0x80
.L80149F34:
/* E0634 80149F34 14400002 */  bnez      $v0, .L80149F40
/* E0638 80149F38 2402007F */   addiu    $v0, $zero, 0x7f
/* E063C 80149F3C A6420000 */  sh        $v0, ($s2)
.L80149F40:
/* E0640 80149F40 8FBF0024 */  lw        $ra, 0x24($sp)
/* E0644 80149F44 8FB20020 */  lw        $s2, 0x20($sp)
/* E0648 80149F48 8FB1001C */  lw        $s1, 0x1c($sp)
/* E064C 80149F4C 8FB00018 */  lw        $s0, 0x18($sp)
/* E0650 80149F50 03E00008 */  jr        $ra
/* E0654 80149F54 27BD0028 */   addiu    $sp, $sp, 0x28

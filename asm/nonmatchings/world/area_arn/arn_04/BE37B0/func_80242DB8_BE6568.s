.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DB8_BE6568
/* BE6568 80242DB8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BE656C 80242DBC AFB30024 */  sw        $s3, 0x24($sp)
/* BE6570 80242DC0 0080982D */  daddu     $s3, $a0, $zero
/* BE6574 80242DC4 AFBF0028 */  sw        $ra, 0x28($sp)
/* BE6578 80242DC8 AFB20020 */  sw        $s2, 0x20($sp)
/* BE657C 80242DCC AFB1001C */  sw        $s1, 0x1c($sp)
/* BE6580 80242DD0 AFB00018 */  sw        $s0, 0x18($sp)
/* BE6584 80242DD4 8E720148 */  lw        $s2, 0x148($s3)
/* BE6588 80242DD8 00A0882D */  daddu     $s1, $a1, $zero
/* BE658C 80242DDC 86440008 */  lh        $a0, 8($s2)
/* BE6590 80242DE0 0C00EABB */  jal       get_npc_unsafe
/* BE6594 80242DE4 00C0802D */   daddu    $s0, $a2, $zero
/* BE6598 80242DE8 0200202D */  daddu     $a0, $s0, $zero
/* BE659C 80242DEC 0240282D */  daddu     $a1, $s2, $zero
/* BE65A0 80242DF0 AFA00010 */  sw        $zero, 0x10($sp)
/* BE65A4 80242DF4 8E260024 */  lw        $a2, 0x24($s1)
/* BE65A8 80242DF8 8E270028 */  lw        $a3, 0x28($s1)
/* BE65AC 80242DFC 0C01242D */  jal       func_800490B4
/* BE65B0 80242E00 0040802D */   daddu    $s0, $v0, $zero
/* BE65B4 80242E04 1040000C */  beqz      $v0, .L80242E38
/* BE65B8 80242E08 00000000 */   nop
/* BE65BC 80242E0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE65C0 80242E10 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE65C4 80242E14 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE65C8 80242E18 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE65CC 80242E1C 8C460028 */  lw        $a2, 0x28($v0)
/* BE65D0 80242E20 0C00A720 */  jal       atan2
/* BE65D4 80242E24 8C470030 */   lw       $a3, 0x30($v0)
/* BE65D8 80242E28 2402000C */  addiu     $v0, $zero, 0xc
/* BE65DC 80242E2C E600000C */  swc1      $f0, 0xc($s0)
/* BE65E0 80242E30 08090BB5 */  j         .L80242ED4
/* BE65E4 80242E34 AE620070 */   sw       $v0, 0x70($s3)
.L80242E38:
/* BE65E8 80242E38 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE65EC 80242E3C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE65F0 80242E40 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE65F4 80242E44 C4440000 */  lwc1      $f4, ($v0)
/* BE65F8 80242E48 46802120 */  cvt.s.w   $f4, $f4
/* BE65FC 80242E4C 44062000 */  mfc1      $a2, $f4
/* BE6600 80242E50 C4440008 */  lwc1      $f4, 8($v0)
/* BE6604 80242E54 46802120 */  cvt.s.w   $f4, $f4
/* BE6608 80242E58 44072000 */  mfc1      $a3, $f4
/* BE660C 80242E5C 0C00A7B5 */  jal       dist2D
/* BE6610 80242E60 00000000 */   nop
/* BE6614 80242E64 C6020018 */  lwc1      $f2, 0x18($s0)
/* BE6618 80242E68 4602003E */  c.le.s    $f0, $f2
/* BE661C 80242E6C 00000000 */  nop
/* BE6620 80242E70 45000005 */  bc1f      .L80242E88
/* BE6624 80242E74 2402000A */   addiu    $v0, $zero, 0xa
/* BE6628 80242E78 A602008E */  sh        $v0, 0x8e($s0)
/* BE662C 80242E7C 24020032 */  addiu     $v0, $zero, 0x32
/* BE6630 80242E80 08090BB5 */  j         .L80242ED4
/* BE6634 80242E84 AE620070 */   sw       $v0, 0x70($s3)
.L80242E88:
/* BE6638 80242E88 8602008C */  lh        $v0, 0x8c($s0)
/* BE663C 80242E8C 14400011 */  bnez      $v0, .L80242ED4
/* BE6640 80242E90 00000000 */   nop
/* BE6644 80242E94 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE6648 80242E98 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE664C 80242E9C C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE6650 80242EA0 C4440000 */  lwc1      $f4, ($v0)
/* BE6654 80242EA4 46802120 */  cvt.s.w   $f4, $f4
/* BE6658 80242EA8 44062000 */  mfc1      $a2, $f4
/* BE665C 80242EAC C4440008 */  lwc1      $f4, 8($v0)
/* BE6660 80242EB0 46802120 */  cvt.s.w   $f4, $f4
/* BE6664 80242EB4 44072000 */  mfc1      $a3, $f4
/* BE6668 80242EB8 0C00A720 */  jal       atan2
/* BE666C 80242EBC 00000000 */   nop
/* BE6670 80242EC0 8E050018 */  lw        $a1, 0x18($s0)
/* BE6674 80242EC4 44060000 */  mfc1      $a2, $f0
/* BE6678 80242EC8 0200202D */  daddu     $a0, $s0, $zero
/* BE667C 80242ECC 0C00EA95 */  jal       npc_move_heading
/* BE6680 80242ED0 AC86000C */   sw       $a2, 0xc($a0)
.L80242ED4:
/* BE6684 80242ED4 8FBF0028 */  lw        $ra, 0x28($sp)
/* BE6688 80242ED8 8FB30024 */  lw        $s3, 0x24($sp)
/* BE668C 80242EDC 8FB20020 */  lw        $s2, 0x20($sp)
/* BE6690 80242EE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* BE6694 80242EE4 8FB00018 */  lw        $s0, 0x18($sp)
/* BE6698 80242EE8 03E00008 */  jr        $ra
/* BE669C 80242EEC 27BD0030 */   addiu    $sp, $sp, 0x30

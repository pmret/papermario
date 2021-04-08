.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F0D4
/* 1A4D4 8003F0D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A4D8 8003F0D8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A4DC 8003F0DC 0080882D */  daddu     $s1, $a0, $zero
/* 1A4E0 8003F0E0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A4E4 8003F0E4 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A4E8 8003F0E8 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A4EC 8003F0EC 8E30000C */  lw        $s0, 0xc($s1)
/* 1A4F0 8003F0F0 8E050000 */  lw        $a1, ($s0)
/* 1A4F4 8003F0F4 0C0B1EAF */  jal       func_802C7ABC
/* 1A4F8 8003F0F8 26100004 */   addiu    $s0, $s0, 4
/* 1A4FC 8003F0FC 8E050000 */  lw        $a1, ($s0)
/* 1A500 8003F100 26100004 */  addiu     $s0, $s0, 4
/* 1A504 8003F104 0220202D */  daddu     $a0, $s1, $zero
/* 1A508 8003F108 0C0B1EAF */  jal       func_802C7ABC
/* 1A50C 8003F10C 0040902D */   daddu    $s2, $v0, $zero
/* 1A510 8003F110 0220202D */  daddu     $a0, $s1, $zero
/* 1A514 8003F114 8E050000 */  lw        $a1, ($s0)
/* 1A518 8003F118 0C0B1EAF */  jal       func_802C7ABC
/* 1A51C 8003F11C 0040802D */   daddu    $s0, $v0, $zero
/* 1A520 8003F120 24040006 */  addiu     $a0, $zero, 6
/* 1A524 8003F124 44921000 */  mtc1      $s2, $f2
/* 1A528 8003F128 00000000 */  nop
/* 1A52C 8003F12C 468010A0 */  cvt.s.w   $f2, $f2
/* 1A530 8003F130 44051000 */  mfc1      $a1, $f2
/* 1A534 8003F134 44901000 */  mtc1      $s0, $f2
/* 1A538 8003F138 00000000 */  nop
/* 1A53C 8003F13C 468010A0 */  cvt.s.w   $f2, $f2
/* 1A540 8003F140 44061000 */  mfc1      $a2, $f2
/* 1A544 8003F144 44821000 */  mtc1      $v0, $f2
/* 1A548 8003F148 00000000 */  nop
/* 1A54C 8003F14C 468010A0 */  cvt.s.w   $f2, $f2
/* 1A550 8003F150 3C013F99 */  lui       $at, 0x3f99
/* 1A554 8003F154 3421999A */  ori       $at, $at, 0x999a
/* 1A558 8003F158 44810000 */  mtc1      $at, $f0
/* 1A55C 8003F15C 44071000 */  mfc1      $a3, $f2
/* 1A560 8003F160 2403001E */  addiu     $v1, $zero, 0x1e
/* 1A564 8003F164 AFA30014 */  sw        $v1, 0x14($sp)
/* 1A568 8003F168 0C01C824 */  jal       func_80072090
/* 1A56C 8003F16C E7A00010 */   swc1     $f0, 0x10($sp)
/* 1A570 8003F170 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A574 8003F174 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A578 8003F178 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A57C 8003F17C 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A580 8003F180 24020002 */  addiu     $v0, $zero, 2
/* 1A584 8003F184 03E00008 */  jr        $ra
/* 1A588 8003F188 27BD0028 */   addiu    $sp, $sp, 0x28

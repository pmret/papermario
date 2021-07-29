.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F18C
/* 1A58C 8003F18C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A590 8003F190 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A594 8003F194 0080882D */  daddu     $s1, $a0, $zero
/* 1A598 8003F198 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A59C 8003F19C AFB20020 */  sw        $s2, 0x20($sp)
/* 1A5A0 8003F1A0 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A5A4 8003F1A4 8E30000C */  lw        $s0, 0xc($s1)
/* 1A5A8 8003F1A8 8E050000 */  lw        $a1, ($s0)
/* 1A5AC 8003F1AC 0C0B1EAF */  jal       func_802C7ABC
/* 1A5B0 8003F1B0 26100004 */   addiu    $s0, $s0, 4
/* 1A5B4 8003F1B4 8E050000 */  lw        $a1, ($s0)
/* 1A5B8 8003F1B8 26100004 */  addiu     $s0, $s0, 4
/* 1A5BC 8003F1BC 0220202D */  daddu     $a0, $s1, $zero
/* 1A5C0 8003F1C0 0C0B1EAF */  jal       func_802C7ABC
/* 1A5C4 8003F1C4 0040902D */   daddu    $s2, $v0, $zero
/* 1A5C8 8003F1C8 0220202D */  daddu     $a0, $s1, $zero
/* 1A5CC 8003F1CC 8E050000 */  lw        $a1, ($s0)
/* 1A5D0 8003F1D0 0C0B1EAF */  jal       func_802C7ABC
/* 1A5D4 8003F1D4 0040802D */   daddu    $s0, $v0, $zero
/* 1A5D8 8003F1D8 24040009 */  addiu     $a0, $zero, 9
/* 1A5DC 8003F1DC 44921000 */  mtc1      $s2, $f2
/* 1A5E0 8003F1E0 00000000 */  nop
/* 1A5E4 8003F1E4 468010A0 */  cvt.s.w   $f2, $f2
/* 1A5E8 8003F1E8 44051000 */  mfc1      $a1, $f2
/* 1A5EC 8003F1EC 44901000 */  mtc1      $s0, $f2
/* 1A5F0 8003F1F0 00000000 */  nop
/* 1A5F4 8003F1F4 468010A0 */  cvt.s.w   $f2, $f2
/* 1A5F8 8003F1F8 44061000 */  mfc1      $a2, $f2
/* 1A5FC 8003F1FC 44821000 */  mtc1      $v0, $f2
/* 1A600 8003F200 00000000 */  nop
/* 1A604 8003F204 468010A0 */  cvt.s.w   $f2, $f2
/* 1A608 8003F208 3C0140A0 */  lui       $at, 0x40a0
/* 1A60C 8003F20C 44810000 */  mtc1      $at, $f0
/* 1A610 8003F210 44071000 */  mfc1      $a3, $f2
/* 1A614 8003F214 2403000F */  addiu     $v1, $zero, 0xf
/* 1A618 8003F218 AFA30014 */  sw        $v1, 0x14($sp)
/* 1A61C 8003F21C 0C01C5CC */  jal       func_80071730
/* 1A620 8003F220 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1A624 8003F224 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A628 8003F228 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A62C 8003F22C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A630 8003F230 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A634 8003F234 24020002 */  addiu     $v0, $zero, 2
/* 1A638 8003F238 03E00008 */  jr        $ra
/* 1A63C 8003F23C 27BD0028 */   addiu    $sp, $sp, 0x28

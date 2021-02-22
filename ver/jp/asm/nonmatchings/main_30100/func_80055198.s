.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055198
/* 30598 80055198 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3059C 8005519C AFB10014 */  sw        $s1, 0x14($sp)
/* 305A0 800551A0 0080882D */  daddu     $s1, $a0, $zero
/* 305A4 800551A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 305A8 800551A8 00A0902D */  daddu     $s2, $a1, $zero
/* 305AC 800551AC AFBF001C */  sw        $ra, 0x1c($sp)
/* 305B0 800551B0 0C014238 */  jal       func_800508E0
/* 305B4 800551B4 AFB00010 */   sw       $s0, 0x10($sp)
/* 305B8 800551B8 0040802D */  daddu     $s0, $v0, $zero
/* 305BC 800551BC 16000005 */  bnez      $s0, .L800551D4
/* 305C0 800551C0 0200102D */   daddu    $v0, $s0, $zero
/* 305C4 800551C4 0220202D */  daddu     $a0, $s1, $zero
/* 305C8 800551C8 0C014305 */  jal       func_80050C14
/* 305CC 800551CC 0240282D */   daddu    $a1, $s2, $zero
/* 305D0 800551D0 0200102D */  daddu     $v0, $s0, $zero
.L800551D4:
/* 305D4 800551D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 305D8 800551D8 8FB20018 */  lw        $s2, 0x18($sp)
/* 305DC 800551DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 305E0 800551E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 305E4 800551E4 03E00008 */  jr        $ra
/* 305E8 800551E8 27BD0020 */   addiu    $sp, $sp, 0x20

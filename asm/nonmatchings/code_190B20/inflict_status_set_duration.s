.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel inflict_status_set_duration
/* 1955D0 80266CF0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1955D4 80266CF4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1955D8 80266CF8 0080902D */  daddu     $s2, $a0, $zero
/* 1955DC 80266CFC AFB3001C */  sw        $s3, 0x1c($sp)
/* 1955E0 80266D00 00A0982D */  daddu     $s3, $a1, $zero
/* 1955E4 80266D04 AFB10014 */  sw        $s1, 0x14($sp)
/* 1955E8 80266D08 00E0882D */  daddu     $s1, $a3, $zero
/* 1955EC 80266D0C AFBF0020 */  sw        $ra, 0x20($sp)
/* 1955F0 80266D10 AFB00010 */  sw        $s0, 0x10($sp)
/* 1955F4 80266D14 8E44020C */  lw        $a0, 0x20c($s2)
/* 1955F8 80266D18 10800005 */  beqz      $a0, .L80266D30
/* 1955FC 80266D1C 0000802D */   daddu    $s0, $zero, $zero
/* 195600 80266D20 0C0997A6 */  jal       lookup_status_chance
/* 195604 80266D24 00000000 */   nop
/* 195608 80266D28 18400002 */  blez      $v0, .L80266D34
/* 19560C 80266D2C 00000000 */   nop
.L80266D30:
/* 195610 80266D30 0220802D */  daddu     $s0, $s1, $zero
.L80266D34:
/* 195614 80266D34 1E000003 */  bgtz      $s0, .L80266D44
/* 195618 80266D38 0240202D */   daddu    $a0, $s2, $zero
/* 19561C 80266D3C 08099B54 */  j         .L80266D50
/* 195620 80266D40 0000102D */   daddu    $v0, $zero, $zero
.L80266D44:
/* 195624 80266D44 0260282D */  daddu     $a1, $s3, $zero
/* 195628 80266D48 0C0997D0 */  jal       inflict_status
/* 19562C 80266D4C 0200302D */   daddu    $a2, $s0, $zero
.L80266D50:
/* 195630 80266D50 8FBF0020 */  lw        $ra, 0x20($sp)
/* 195634 80266D54 8FB3001C */  lw        $s3, 0x1c($sp)
/* 195638 80266D58 8FB20018 */  lw        $s2, 0x18($sp)
/* 19563C 80266D5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 195640 80266D60 8FB00010 */  lw        $s0, 0x10($sp)
/* 195644 80266D64 03E00008 */  jr        $ra
/* 195648 80266D68 27BD0028 */   addiu    $sp, $sp, 0x28

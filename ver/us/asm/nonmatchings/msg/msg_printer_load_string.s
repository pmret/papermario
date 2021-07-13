.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel msg_printer_load_string
/* BC168 80125A68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC16C 80125A6C 0080102D */  daddu     $v0, $a0, $zero
/* BC170 80125A70 AFB00010 */  sw        $s0, 0x10($sp)
/* BC174 80125A74 00A0802D */  daddu     $s0, $a1, $zero
/* BC178 80125A78 04400003 */  bltz      $v0, .L80125A88
/* BC17C 80125A7C AFBF0014 */   sw       $ra, 0x14($sp)
/* BC180 80125A80 0C049623 */  jal       load_message_to_buffer
/* BC184 80125A84 00000000 */   nop
.L80125A88:
/* BC188 80125A88 0040202D */  daddu     $a0, $v0, $zero
/* BC18C 80125A8C 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BC190 80125A90 AE040000 */  sw        $a0, ($s0)
/* BC194 80125A94 2404FFBF */  addiu     $a0, $zero, -0x41
/* BC198 80125A98 A600000C */  sh        $zero, 0xc($s0)
/* BC19C 80125A9C 00641824 */  and       $v1, $v1, $a0
/* BC1A0 80125AA0 AE0304FC */  sw        $v1, 0x4fc($s0)
/* BC1A4 80125AA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* BC1A8 80125AA8 8FB00010 */  lw        $s0, 0x10($sp)
/* BC1AC 80125AAC 24020001 */  addiu     $v0, $zero, 1
/* BC1B0 80125AB0 03E00008 */  jr        $ra
/* BC1B4 80125AB4 27BD0018 */   addiu    $sp, $sp, 0x18

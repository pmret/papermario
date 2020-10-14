.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_goto_end_loop
/* ED494 802C8AE4 0000282D */  daddu     $a1, $zero, $zero
/* ED498 802C8AE8 8C830008 */  lw        $v1, 8($a0)
/* ED49C 802C8AEC 24080005 */  addiu     $t0, $zero, 5
/* ED4A0 802C8AF0 24070001 */  addiu     $a3, $zero, 1
/* ED4A4 802C8AF4 24060006 */  addiu     $a2, $zero, 6
.L802C8AF8:
/* ED4A8 802C8AF8 8C640000 */  lw        $a0, ($v1)
/* ED4AC 802C8AFC 24630004 */  addiu     $v1, $v1, 4
/* ED4B0 802C8B00 8C620000 */  lw        $v0, ($v1)
/* ED4B4 802C8B04 24630004 */  addiu     $v1, $v1, 4
/* ED4B8 802C8B08 00021080 */  sll       $v0, $v0, 2
/* ED4BC 802C8B0C 10880012 */  beq       $a0, $t0, .L802C8B58
/* ED4C0 802C8B10 00621821 */   addu     $v1, $v1, $v0
/* ED4C4 802C8B14 28820006 */  slti      $v0, $a0, 6
/* ED4C8 802C8B18 10400005 */  beqz      $v0, .L802C8B30
/* ED4CC 802C8B1C 00000000 */   nop      
/* ED4D0 802C8B20 10870007 */  beq       $a0, $a3, .L802C8B40
/* ED4D4 802C8B24 00000000 */   nop      
/* ED4D8 802C8B28 080B22BE */  j         .L802C8AF8
/* ED4DC 802C8B2C 00000000 */   nop      
.L802C8B30:
/* ED4E0 802C8B30 50860005 */  beql      $a0, $a2, .L802C8B48
/* ED4E4 802C8B34 24A5FFFF */   addiu    $a1, $a1, -1
/* ED4E8 802C8B38 080B22BE */  j         .L802C8AF8
/* ED4EC 802C8B3C 00000000 */   nop      
.L802C8B40:
/* ED4F0 802C8B40 080B22D0 */  j         .L802C8B40
/* ED4F4 802C8B44 00000000 */   nop      
.L802C8B48:
/* ED4F8 802C8B48 04A1FFEB */  bgez      $a1, .L802C8AF8
/* ED4FC 802C8B4C 0060102D */   daddu    $v0, $v1, $zero
/* ED500 802C8B50 03E00008 */  jr        $ra
/* ED504 802C8B54 00000000 */   nop      
.L802C8B58:
/* ED508 802C8B58 080B22BE */  j         .L802C8AF8
/* ED50C 802C8B5C 24A50001 */   addiu    $a1, $a1, 1

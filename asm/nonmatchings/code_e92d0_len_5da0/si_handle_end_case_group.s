.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_end_case_group
/* EA00C 802C565C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA010 802C5660 AFB00010 */  sw        $s0, 0x10($sp)
/* EA014 802C5664 0080802D */  daddu     $s0, $a0, $zero
/* EA018 802C5668 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA01C 802C566C 82020007 */  lb        $v0, 7($s0)
/* EA020 802C5670 04410003 */  bgez      $v0, .L802C5680
/* EA024 802C5674 02021821 */   addu     $v1, $s0, $v0
.L802C5678:
/* EA028 802C5678 080B159E */  j         .L802C5678
/* EA02C 802C567C 00000000 */   nop      
.L802C5680:
/* EA030 802C5680 80640110 */  lb        $a0, 0x110($v1)
/* EA034 802C5684 14800003 */  bnez      $a0, .L802C5694
/* EA038 802C5688 2402FFFF */   addiu    $v0, $zero, -1
/* EA03C 802C568C 080B15AD */  j         .L802C56B4
/* EA040 802C5690 0200202D */   daddu    $a0, $s0, $zero
.L802C5694:
/* EA044 802C5694 10820006 */  beq       $a0, $v0, .L802C56B0
/* EA048 802C5698 0200202D */   daddu    $a0, $s0, $zero
/* EA04C 802C569C 24020001 */  addiu     $v0, $zero, 1
/* EA050 802C56A0 0C0B2298 */  jal       si_goto_next_case
/* EA054 802C56A4 A0620110 */   sb       $v0, 0x110($v1)
/* EA058 802C56A8 080B15B0 */  j         .L802C56C0
/* EA05C 802C56AC AE020008 */   sw       $v0, 8($s0)
.L802C56B0:
/* EA060 802C56B0 A0600110 */  sb        $zero, 0x110($v1)
.L802C56B4:
/* EA064 802C56B4 0C0B2279 */  jal       si_goto_end_case
/* EA068 802C56B8 00000000 */   nop      
/* EA06C 802C56BC AE020008 */  sw        $v0, 8($s0)
.L802C56C0:
/* EA070 802C56C0 24020002 */  addiu     $v0, $zero, 2
/* EA074 802C56C4 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA078 802C56C8 8FB00010 */  lw        $s0, 0x10($sp)
/* EA07C 802C56CC 03E00008 */  jr        $ra
/* EA080 802C56D0 27BD0018 */   addiu    $sp, $sp, 0x18

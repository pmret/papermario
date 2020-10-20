.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242528_C87FD8
/* C87FD8 80242528 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C87FDC 8024252C 0080102D */  daddu     $v0, $a0, $zero
/* C87FE0 80242530 AFB00010 */  sw        $s0, 0x10($sp)
/* C87FE4 80242534 AFBF0018 */  sw        $ra, 0x18($sp)
/* C87FE8 80242538 AFB10014 */  sw        $s1, 0x14($sp)
/* C87FEC 8024253C 8C44014C */  lw        $a0, 0x14c($v0)
/* C87FF0 80242540 8C510148 */  lw        $s1, 0x148($v0)
/* C87FF4 80242544 0C00EAD2 */  jal       get_npc_safe
/* C87FF8 80242548 00A0802D */   daddu    $s0, $a1, $zero
/* C87FFC 8024254C 56000001 */  bnel      $s0, $zero, .L80242554
/* C88000 80242550 A04000AB */   sb       $zero, 0xab($v0)
.L80242554:
/* C88004 80242554 8C420000 */  lw        $v0, ($v0)
/* C88008 80242558 30421000 */  andi      $v0, $v0, 0x1000
/* C8800C 8024255C 1040000A */  beqz      $v0, .L80242588
/* C88010 80242560 0000102D */   daddu    $v0, $zero, $zero
/* C88014 80242564 82220004 */  lb        $v0, 4($s1)
/* C88018 80242568 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* C8801C 8024256C 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* C88020 80242570 00021080 */  sll       $v0, $v0, 2
/* C88024 80242574 00431021 */  addu      $v0, $v0, $v1
/* C88028 80242578 8C440028 */  lw        $a0, 0x28($v0)
/* C8802C 8024257C 9623006E */  lhu       $v1, 0x6e($s1)
/* C88030 80242580 24020002 */  addiu     $v0, $zero, 2
/* C88034 80242584 A4830044 */  sh        $v1, 0x44($a0)
.L80242588:
/* C88038 80242588 8FBF0018 */  lw        $ra, 0x18($sp)
/* C8803C 8024258C 8FB10014 */  lw        $s1, 0x14($sp)
/* C88040 80242590 8FB00010 */  lw        $s0, 0x10($sp)
/* C88044 80242594 03E00008 */  jr        $ra
/* C88048 80242598 27BD0020 */   addiu    $sp, $sp, 0x20

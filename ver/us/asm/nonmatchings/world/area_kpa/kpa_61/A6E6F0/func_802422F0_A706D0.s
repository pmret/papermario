.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422F0_A706D0
/* A706D0 802422F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A706D4 802422F4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A706D8 802422F8 AFB00010 */  sw        $s0, 0x10($sp)
/* A706DC 802422FC 8C900148 */  lw        $s0, 0x148($a0)
/* A706E0 80242300 0C00EABB */  jal       get_npc_unsafe
/* A706E4 80242304 86040008 */   lh       $a0, 8($s0)
/* A706E8 80242308 0040202D */  daddu     $a0, $v0, $zero
/* A706EC 8024230C 8E03006C */  lw        $v1, 0x6c($s0)
/* A706F0 80242310 24020002 */  addiu     $v0, $zero, 2
/* A706F4 80242314 14620003 */  bne       $v1, $v0, .L80242324
/* A706F8 80242318 00000000 */   nop
/* A706FC 8024231C AC80001C */  sw        $zero, 0x1c($a0)
/* A70700 80242320 AC800018 */  sw        $zero, 0x18($a0)
.L80242324:
/* A70704 80242324 8FBF0014 */  lw        $ra, 0x14($sp)
/* A70708 80242328 8FB00010 */  lw        $s0, 0x10($sp)
/* A7070C 8024232C 24020002 */  addiu     $v0, $zero, 2
/* A70710 80242330 03E00008 */  jr        $ra
/* A70714 80242334 27BD0018 */   addiu    $sp, $sp, 0x18
/* A70718 80242338 00000000 */  nop
/* A7071C 8024233C 00000000 */  nop

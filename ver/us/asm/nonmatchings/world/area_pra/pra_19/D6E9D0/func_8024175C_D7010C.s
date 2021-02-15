.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024175C_D7010C
/* D7010C 8024175C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D70110 80241760 0000202D */  daddu     $a0, $zero, $zero
/* D70114 80241764 AFBF0020 */  sw        $ra, 0x20($sp)
/* D70118 80241768 AFB3001C */  sw        $s3, 0x1c($sp)
/* D7011C 8024176C AFB20018 */  sw        $s2, 0x18($sp)
/* D70120 80241770 AFB10014 */  sw        $s1, 0x14($sp)
/* D70124 80241774 0C00EABB */  jal       get_npc_unsafe
/* D70128 80241778 AFB00010 */   sw       $s0, 0x10($sp)
/* D7012C 8024177C 24040001 */  addiu     $a0, $zero, 1
/* D70130 80241780 0C00EABB */  jal       get_npc_unsafe
/* D70134 80241784 0040802D */   daddu    $s0, $v0, $zero
/* D70138 80241788 24040002 */  addiu     $a0, $zero, 2
/* D7013C 8024178C 0C00EABB */  jal       get_npc_unsafe
/* D70140 80241790 0040882D */   daddu    $s1, $v0, $zero
/* D70144 80241794 24040003 */  addiu     $a0, $zero, 3
/* D70148 80241798 0C00EABB */  jal       get_npc_unsafe
/* D7014C 8024179C 0040902D */   daddu    $s2, $v0, $zero
/* D70150 802417A0 24040004 */  addiu     $a0, $zero, 4
/* D70154 802417A4 0C00EABB */  jal       get_npc_unsafe
/* D70158 802417A8 0040982D */   daddu    $s3, $v0, $zero
/* D7015C 802417AC 3C018011 */  lui       $at, %hi(gPlayerStatus+0x28)
/* D70160 802417B0 C422EFF0 */  lwc1      $f2, %lo(gPlayerStatus+0x28)($at)
/* D70164 802417B4 C6000038 */  lwc1      $f0, 0x38($s0)
/* D70168 802417B8 4602003C */  c.lt.s    $f0, $f2
/* D7016C 802417BC 00000000 */  nop
/* D70170 802417C0 45030016 */  bc1tl     .L8024181C
/* D70174 802417C4 24020002 */   addiu    $v0, $zero, 2
/* D70178 802417C8 C6200038 */  lwc1      $f0, 0x38($s1)
/* D7017C 802417CC 4602003C */  c.lt.s    $f0, $f2
/* D70180 802417D0 00000000 */  nop
/* D70184 802417D4 45030011 */  bc1tl     .L8024181C
/* D70188 802417D8 24020002 */   addiu    $v0, $zero, 2
/* D7018C 802417DC C6400038 */  lwc1      $f0, 0x38($s2)
/* D70190 802417E0 4602003C */  c.lt.s    $f0, $f2
/* D70194 802417E4 00000000 */  nop
/* D70198 802417E8 4503000C */  bc1tl     .L8024181C
/* D7019C 802417EC 24020002 */   addiu    $v0, $zero, 2
/* D701A0 802417F0 C6600038 */  lwc1      $f0, 0x38($s3)
/* D701A4 802417F4 4602003C */  c.lt.s    $f0, $f2
/* D701A8 802417F8 00000000 */  nop
/* D701AC 802417FC 45030007 */  bc1tl     .L8024181C
/* D701B0 80241800 24020002 */   addiu    $v0, $zero, 2
/* D701B4 80241804 C4400038 */  lwc1      $f0, 0x38($v0)
/* D701B8 80241808 4602003C */  c.lt.s    $f0, $f2
/* D701BC 8024180C 00000000 */  nop
/* D701C0 80241810 45010002 */  bc1t      .L8024181C
/* D701C4 80241814 24020002 */   addiu    $v0, $zero, 2
/* D701C8 80241818 0000102D */  daddu     $v0, $zero, $zero
.L8024181C:
/* D701CC 8024181C 8FBF0020 */  lw        $ra, 0x20($sp)
/* D701D0 80241820 8FB3001C */  lw        $s3, 0x1c($sp)
/* D701D4 80241824 8FB20018 */  lw        $s2, 0x18($sp)
/* D701D8 80241828 8FB10014 */  lw        $s1, 0x14($sp)
/* D701DC 8024182C 8FB00010 */  lw        $s0, 0x10($sp)
/* D701E0 80241830 03E00008 */  jr        $ra
/* D701E4 80241834 27BD0028 */   addiu    $sp, $sp, 0x28

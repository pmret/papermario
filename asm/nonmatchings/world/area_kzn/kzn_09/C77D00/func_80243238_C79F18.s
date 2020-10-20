.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243238_C79F18
/* C79F18 80243238 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C79F1C 8024323C 0080102D */  daddu     $v0, $a0, $zero
/* C79F20 80243240 AFB00010 */  sw        $s0, 0x10($sp)
/* C79F24 80243244 AFBF0018 */  sw        $ra, 0x18($sp)
/* C79F28 80243248 AFB10014 */  sw        $s1, 0x14($sp)
/* C79F2C 8024324C 8C44014C */  lw        $a0, 0x14c($v0)
/* C79F30 80243250 8C510148 */  lw        $s1, 0x148($v0)
/* C79F34 80243254 0C00EAD2 */  jal       get_npc_safe
/* C79F38 80243258 00A0802D */   daddu    $s0, $a1, $zero
/* C79F3C 8024325C 56000001 */  bnel      $s0, $zero, .L80243264
/* C79F40 80243260 A04000AB */   sb       $zero, 0xab($v0)
.L80243264:
/* C79F44 80243264 8C420000 */  lw        $v0, ($v0)
/* C79F48 80243268 30421000 */  andi      $v0, $v0, 0x1000
/* C79F4C 8024326C 1040000A */  beqz      $v0, .L80243298
/* C79F50 80243270 0000102D */   daddu    $v0, $zero, $zero
/* C79F54 80243274 82220004 */  lb        $v0, 4($s1)
/* C79F58 80243278 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* C79F5C 8024327C 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* C79F60 80243280 00021080 */  sll       $v0, $v0, 2
/* C79F64 80243284 00431021 */  addu      $v0, $v0, $v1
/* C79F68 80243288 8C440028 */  lw        $a0, 0x28($v0)
/* C79F6C 8024328C 9623006E */  lhu       $v1, 0x6e($s1)
/* C79F70 80243290 24020002 */  addiu     $v0, $zero, 2
/* C79F74 80243294 A4830044 */  sh        $v1, 0x44($a0)
.L80243298:
/* C79F78 80243298 8FBF0018 */  lw        $ra, 0x18($sp)
/* C79F7C 8024329C 8FB10014 */  lw        $s1, 0x14($sp)
/* C79F80 802432A0 8FB00010 */  lw        $s0, 0x10($sp)
/* C79F84 802432A4 03E00008 */  jr        $ra
/* C79F88 802432A8 27BD0020 */   addiu    $sp, $sp, 0x20

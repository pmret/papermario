.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240428_EB1288
/* EB1288 80240428 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB128C 8024042C AFB10014 */  sw        $s1, 0x14($sp)
/* EB1290 80240430 0080882D */  daddu     $s1, $a0, $zero
/* EB1294 80240434 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB1298 80240438 AFB00010 */  sw        $s0, 0x10($sp)
/* EB129C 8024043C 8E30000C */  lw        $s0, 0xc($s1)
/* EB12A0 80240440 8E050000 */  lw        $a1, ($s0)
/* EB12A4 80240444 0C0B53A3 */  jal       func_802D4E8C
/* EB12A8 80240448 26100004 */   addiu    $s0, $s0, 4
/* EB12AC 8024044C 0C00F94D */  jal       func_8003E534
/* EB12B0 80240450 0040202D */   daddu    $a0, $v0, $zero
/* EB12B4 80240454 10400005 */  beqz      $v0, .L8024046C
/* EB12B8 80240458 00000000 */   nop      
/* EB12BC 8024045C 8E050000 */  lw        $a1, ($s0)
/* EB12C0 80240460 844600A8 */  lh        $a2, 0xa8($v0)
/* EB12C4 80240464 0C0B551A */  jal       func_802D5468
/* EB12C8 80240468 0220202D */   daddu    $a0, $s1, $zero
.L8024046C:
/* EB12CC 8024046C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB12D0 80240470 8FB10014 */  lw        $s1, 0x14($sp)
/* EB12D4 80240474 8FB00010 */  lw        $s0, 0x10($sp)
/* EB12D8 80240478 24020002 */  addiu     $v0, $zero, 2
/* EB12DC 8024047C 03E00008 */  jr        $ra
/* EB12E0 80240480 27BD0020 */   addiu    $sp, $sp, 0x20

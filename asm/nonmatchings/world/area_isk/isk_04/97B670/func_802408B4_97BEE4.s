.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408B4_97BEE4
/* 97BEE4 802408B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97BEE8 802408B8 0080102D */  daddu     $v0, $a0, $zero
/* 97BEEC 802408BC AFB00010 */  sw        $s0, 0x10($sp)
/* 97BEF0 802408C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 97BEF4 802408C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 97BEF8 802408C8 8C44014C */  lw        $a0, 0x14c($v0)
/* 97BEFC 802408CC 8C510148 */  lw        $s1, 0x148($v0)
/* 97BF00 802408D0 0C00EAD2 */  jal       get_npc_safe
/* 97BF04 802408D4 00A0802D */   daddu    $s0, $a1, $zero
/* 97BF08 802408D8 56000001 */  bnel      $s0, $zero, .L802408E0
/* 97BF0C 802408DC A04000AB */   sb       $zero, 0xab($v0)
.L802408E0:
/* 97BF10 802408E0 8C420000 */  lw        $v0, ($v0)
/* 97BF14 802408E4 30421000 */  andi      $v0, $v0, 0x1000
/* 97BF18 802408E8 1040000A */  beqz      $v0, .L80240914
/* 97BF1C 802408EC 0000102D */   daddu    $v0, $zero, $zero
/* 97BF20 802408F0 82220004 */  lb        $v0, 4($s1)
/* 97BF24 802408F4 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 97BF28 802408F8 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 97BF2C 802408FC 00021080 */  sll       $v0, $v0, 2
/* 97BF30 80240900 00431021 */  addu      $v0, $v0, $v1
/* 97BF34 80240904 8C440028 */  lw        $a0, 0x28($v0)
/* 97BF38 80240908 9623006E */  lhu       $v1, 0x6e($s1)
/* 97BF3C 8024090C 24020002 */  addiu     $v0, $zero, 2
/* 97BF40 80240910 A4830044 */  sh        $v1, 0x44($a0)
.L80240914:
/* 97BF44 80240914 8FBF0018 */  lw        $ra, 0x18($sp)
/* 97BF48 80240918 8FB10014 */  lw        $s1, 0x14($sp)
/* 97BF4C 8024091C 8FB00010 */  lw        $s0, 0x10($sp)
/* 97BF50 80240920 03E00008 */  jr        $ra
/* 97BF54 80240924 27BD0020 */   addiu    $sp, $sp, 0x20
/* 97BF58 80240928 00000000 */  nop       
/* 97BF5C 8024092C 00000000 */  nop       

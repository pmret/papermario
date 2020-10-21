.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240874_9856A4
/* 9856A4 80240874 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9856A8 80240878 0080102D */  daddu     $v0, $a0, $zero
/* 9856AC 8024087C AFB00010 */  sw        $s0, 0x10($sp)
/* 9856B0 80240880 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9856B4 80240884 AFB10014 */  sw        $s1, 0x14($sp)
/* 9856B8 80240888 8C44014C */  lw        $a0, 0x14c($v0)
/* 9856BC 8024088C 8C510148 */  lw        $s1, 0x148($v0)
/* 9856C0 80240890 0C00EAD2 */  jal       get_npc_safe
/* 9856C4 80240894 00A0802D */   daddu    $s0, $a1, $zero
/* 9856C8 80240898 56000001 */  bnel      $s0, $zero, .L802408A0
/* 9856CC 8024089C A04000AB */   sb       $zero, 0xab($v0)
.L802408A0:
/* 9856D0 802408A0 8C420000 */  lw        $v0, ($v0)
/* 9856D4 802408A4 30421000 */  andi      $v0, $v0, 0x1000
/* 9856D8 802408A8 1040000A */  beqz      $v0, .L802408D4
/* 9856DC 802408AC 0000102D */   daddu    $v0, $zero, $zero
/* 9856E0 802408B0 82220004 */  lb        $v0, 4($s1)
/* 9856E4 802408B4 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 9856E8 802408B8 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 9856EC 802408BC 00021080 */  sll       $v0, $v0, 2
/* 9856F0 802408C0 00431021 */  addu      $v0, $v0, $v1
/* 9856F4 802408C4 8C440028 */  lw        $a0, 0x28($v0)
/* 9856F8 802408C8 9623006E */  lhu       $v1, 0x6e($s1)
/* 9856FC 802408CC 24020002 */  addiu     $v0, $zero, 2
/* 985700 802408D0 A4830044 */  sh        $v1, 0x44($a0)
.L802408D4:
/* 985704 802408D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 985708 802408D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 98570C 802408DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 985710 802408E0 03E00008 */  jr        $ra
/* 985714 802408E4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 985718 802408E8 00000000 */  nop       
/* 98571C 802408EC 00000000 */  nop       

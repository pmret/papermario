.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BF568
/* 3202D8 802BF568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3202DC 802BF56C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3202E0 802BF570 AFB00010 */  sw        $s0, 0x10($sp)
/* 3202E4 802BF574 10A00003 */  beqz      $a1, .L802BF584
/* 3202E8 802BF578 8C90014C */   lw       $s0, 0x14c($a0)
/* 3202EC 802BF57C 0C03BB31 */  jal       func_800EECC4
/* 3202F0 802BF580 0200202D */   daddu    $a0, $s0, $zero
.L802BF584:
/* 3202F4 802BF584 0C03BB3A */  jal       func_800EECE8
/* 3202F8 802BF588 0200202D */   daddu    $a0, $s0, $zero
/* 3202FC 802BF58C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 320300 802BF590 8FB00010 */  lw        $s0, 0x10($sp)
/* 320304 802BF594 0002102B */  sltu      $v0, $zero, $v0
/* 320308 802BF598 03E00008 */  jr        $ra
/* 32030C 802BF59C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD188
/* 3170A8 802BD188 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3170AC 802BD18C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3170B0 802BD190 AFB00010 */  sw        $s0, 0x10($sp)
/* 3170B4 802BD194 8C90014C */  lw        $s0, 0x14c($a0)
/* 3170B8 802BD198 2402FFFF */  addiu     $v0, $zero, -1
/* 3170BC 802BD19C 3C01802C */  lui       $at, 0x802c
/* 3170C0 802BD1A0 AC22DF60 */  sw        $v0, -0x20a0($at)
/* 3170C4 802BD1A4 10A00003 */  beqz      $a1, .L802BD1B4
/* 3170C8 802BD1A8 00000000 */   nop      
/* 3170CC 802BD1AC 0C03BB31 */  jal       func_800EECC4
/* 3170D0 802BD1B0 0200202D */   daddu    $a0, $s0, $zero
.L802BD1B4:
/* 3170D4 802BD1B4 0C03BB3A */  jal       func_800EECE8
/* 3170D8 802BD1B8 0200202D */   daddu    $a0, $s0, $zero
/* 3170DC 802BD1BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3170E0 802BD1C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 3170E4 802BD1C4 0002102B */  sltu      $v0, $zero, $v0
/* 3170E8 802BD1C8 03E00008 */  jr        $ra
/* 3170EC 802BD1CC 27BD0018 */   addiu    $sp, $sp, 0x18

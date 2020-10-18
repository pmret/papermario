.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE4E8
/* 319238 802BE4E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31923C 802BE4EC AFBF0014 */  sw        $ra, 0x14($sp)
/* 319240 802BE4F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 319244 802BE4F4 10A00003 */  beqz      $a1, .L802BE504
/* 319248 802BE4F8 8C90014C */   lw       $s0, 0x14c($a0)
/* 31924C 802BE4FC 0C03BA65 */  jal       func_800EE994
/* 319250 802BE500 0200202D */   daddu    $a0, $s0, $zero
.L802BE504:
/* 319254 802BE504 0C03BA6E */  jal       func_800EE9B8
/* 319258 802BE508 0200202D */   daddu    $a0, $s0, $zero
/* 31925C 802BE50C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 319260 802BE510 8FB00010 */  lw        $s0, 0x10($sp)
/* 319264 802BE514 0002102B */  sltu      $v0, $zero, $v0
/* 319268 802BE518 03E00008 */  jr        $ra
/* 31926C 802BE51C 27BD0018 */   addiu    $sp, $sp, 0x18

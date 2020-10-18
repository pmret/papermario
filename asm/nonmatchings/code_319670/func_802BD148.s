.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD148
/* 3196B8 802BD148 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3196BC 802BD14C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3196C0 802BD150 AFB00010 */  sw        $s0, 0x10($sp)
/* 3196C4 802BD154 10A00003 */  beqz      $a1, .L802BD164
/* 3196C8 802BD158 8C90014C */   lw       $s0, 0x14c($a0)
/* 3196CC 802BD15C 0C03BB31 */  jal       func_800EECC4
/* 3196D0 802BD160 0200202D */   daddu    $a0, $s0, $zero
.L802BD164:
/* 3196D4 802BD164 0C03BB3A */  jal       func_800EECE8
/* 3196D8 802BD168 0200202D */   daddu    $a0, $s0, $zero
/* 3196DC 802BD16C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3196E0 802BD170 8FB00010 */  lw        $s0, 0x10($sp)
/* 3196E4 802BD174 0002102B */  sltu      $v0, $zero, $v0
/* 3196E8 802BD178 03E00008 */  jr        $ra
/* 3196EC 802BD17C 27BD0018 */   addiu    $sp, $sp, 0x18

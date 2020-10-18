.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD300
/* 318050 802BD300 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 318054 802BD304 AFBF0014 */  sw        $ra, 0x14($sp)
/* 318058 802BD308 AFB00010 */  sw        $s0, 0x10($sp)
/* 31805C 802BD30C 10A00003 */  beqz      $a1, .L802BD31C
/* 318060 802BD310 8C90014C */   lw       $s0, 0x14c($a0)
/* 318064 802BD314 0C03BB31 */  jal       func_800EECC4
/* 318068 802BD318 0200202D */   daddu    $a0, $s0, $zero
.L802BD31C:
/* 31806C 802BD31C 0C03BB3A */  jal       func_800EECE8
/* 318070 802BD320 0200202D */   daddu    $a0, $s0, $zero
/* 318074 802BD324 8FBF0014 */  lw        $ra, 0x14($sp)
/* 318078 802BD328 8FB00010 */  lw        $s0, 0x10($sp)
/* 31807C 802BD32C 0002102B */  sltu      $v0, $zero, $v0
/* 318080 802BD330 03E00008 */  jr        $ra
/* 318084 802BD334 27BD0018 */   addiu    $sp, $sp, 0x18

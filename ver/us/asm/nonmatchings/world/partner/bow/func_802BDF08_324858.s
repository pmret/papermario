.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDF08_324858
/* 324858 802BDF08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32485C 802BDF0C AFBF0014 */  sw        $ra, 0x14($sp)
/* 324860 802BDF10 AFB00010 */  sw        $s0, 0x10($sp)
/* 324864 802BDF14 10A0000C */  beqz      $a1, .L802BDF48
/* 324868 802BDF18 8C90014C */   lw       $s0, 0x14c($a0)
/* 32486C 802BDF1C 0C03BA65 */  jal       func_800EE994
/* 324870 802BDF20 0200202D */   daddu    $a0, $s0, $zero
/* 324874 802BDF24 3C02802C */  lui       $v0, %hi(D_802BE0C0)
/* 324878 802BDF28 8C42E0C0 */  lw        $v0, %lo(D_802BE0C0)($v0)
/* 32487C 802BDF2C 10400004 */  beqz      $v0, .L802BDF40
/* 324880 802BDF30 2404200F */   addiu    $a0, $zero, 0x200f
/* 324884 802BDF34 0000282D */  daddu     $a1, $zero, $zero
/* 324888 802BDF38 0C052742 */  jal       sfx_play_sound_at_npc
/* 32488C 802BDF3C 2406FFFC */   addiu    $a2, $zero, -4
.L802BDF40:
/* 324890 802BDF40 0C0AF77C */  jal       func_802BDDF0_324740
/* 324894 802BDF44 0200202D */   daddu    $a0, $s0, $zero
.L802BDF48:
/* 324898 802BDF48 0C03BA6E */  jal       func_800EE9B8
/* 32489C 802BDF4C 0200202D */   daddu    $a0, $s0, $zero
/* 3248A0 802BDF50 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3248A4 802BDF54 8FB00010 */  lw        $s0, 0x10($sp)
/* 3248A8 802BDF58 0002102B */  sltu      $v0, $zero, $v0
/* 3248AC 802BDF5C 03E00008 */  jr        $ra
/* 3248B0 802BDF60 27BD0018 */   addiu    $sp, $sp, 0x18

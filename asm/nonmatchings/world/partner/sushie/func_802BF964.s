.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BF964
/* 3206D4 802BF964 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3206D8 802BF968 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3206DC 802BF96C AFB00010 */  sw        $s0, 0x10($sp)
/* 3206E0 802BF970 10A0000A */  beqz      $a1, .L802BF99C
/* 3206E4 802BF974 8C90014C */   lw       $s0, 0x14c($a0)
/* 3206E8 802BF978 0C03BA65 */  jal       func_800EE994
/* 3206EC 802BF97C 0200202D */   daddu    $a0, $s0, $zero
/* 3206F0 802BF980 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* 3206F4 802BF984 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* 3206F8 802BF988 3C03FFBF */  lui       $v1, 0xffbf
/* 3206FC 802BF98C 8C820004 */  lw        $v0, 4($a0)
/* 320700 802BF990 3463FFFF */  ori       $v1, $v1, 0xffff
/* 320704 802BF994 00431024 */  and       $v0, $v0, $v1
/* 320708 802BF998 AC820004 */  sw        $v0, 4($a0)
.L802BF99C:
/* 32070C 802BF99C 0C03BA6E */  jal       func_800EE9B8
/* 320710 802BF9A0 0200202D */   daddu    $a0, $s0, $zero
/* 320714 802BF9A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 320718 802BF9A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 32071C 802BF9AC 0002102B */  sltu      $v0, $zero, $v0
/* 320720 802BF9B0 03E00008 */  jr        $ra
/* 320724 802BF9B4 27BD0018 */   addiu    $sp, $sp, 0x18

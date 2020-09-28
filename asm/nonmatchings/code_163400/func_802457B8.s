.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802457B8
/* 166018 802457B8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 16601C 802457BC 0080402D */  daddu     $t0, $a0, $zero
/* 166020 802457C0 00A0482D */  daddu     $t1, $a1, $zero
/* 166024 802457C4 00C0502D */  daddu     $t2, $a2, $zero
/* 166028 802457C8 0100282D */  daddu     $a1, $t0, $zero
/* 16602C 802457CC 8FA20038 */  lw        $v0, 0x38($sp)
/* 166030 802457D0 8FA3003C */  lw        $v1, 0x3c($sp)
/* 166034 802457D4 8FA40040 */  lw        $a0, 0x40($sp)
/* 166038 802457D8 0120302D */  daddu     $a2, $t1, $zero
/* 16603C 802457DC AFA70010 */  sw        $a3, 0x10($sp)
/* 166040 802457E0 0140382D */  daddu     $a3, $t2, $zero
/* 166044 802457E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 166048 802457E8 AFA4001C */  sw        $a0, 0x1c($sp)
/* 16604C 802457EC 24040003 */  addiu     $a0, $zero, 3
/* 166050 802457F0 AFA20014 */  sw        $v0, 0x14($sp)
/* 166054 802457F4 0C091513 */  jal       func_8024544C
/* 166058 802457F8 AFA30018 */   sw       $v1, 0x18($sp)
/* 16605C 802457FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 166060 80245800 03E00008 */  jr        $ra
/* 166064 80245804 27BD0028 */   addiu    $sp, $sp, 0x28

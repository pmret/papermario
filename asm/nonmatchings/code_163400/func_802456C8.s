.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802456C8
/* 165F28 802456C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165F2C 802456CC 0080402D */  daddu     $t0, $a0, $zero
/* 165F30 802456D0 00A0482D */  daddu     $t1, $a1, $zero
/* 165F34 802456D4 00C0502D */  daddu     $t2, $a2, $zero
/* 165F38 802456D8 0100282D */  daddu     $a1, $t0, $zero
/* 165F3C 802456DC 8FA20038 */  lw        $v0, 0x38($sp)
/* 165F40 802456E0 8FA3003C */  lw        $v1, 0x3c($sp)
/* 165F44 802456E4 8FA40040 */  lw        $a0, 0x40($sp)
/* 165F48 802456E8 0120302D */  daddu     $a2, $t1, $zero
/* 165F4C 802456EC AFA70010 */  sw        $a3, 0x10($sp)
/* 165F50 802456F0 0140382D */  daddu     $a3, $t2, $zero
/* 165F54 802456F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165F58 802456F8 AFA4001C */  sw        $a0, 0x1c($sp)
/* 165F5C 802456FC 0000202D */  daddu     $a0, $zero, $zero
/* 165F60 80245700 AFA20014 */  sw        $v0, 0x14($sp)
/* 165F64 80245704 0C091513 */  jal       func_8024544C
/* 165F68 80245708 AFA30018 */   sw       $v1, 0x18($sp)
/* 165F6C 8024570C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 165F70 80245710 03E00008 */  jr        $ra
/* 165F74 80245714 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DDFF8
/* 1010E8 802DDFF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1010EC 802DDFFC 00A0402D */  daddu     $t0, $a1, $zero
/* 1010F0 802DE000 00C0482D */  daddu     $t1, $a2, $zero
/* 1010F4 802DE004 2405FFFF */  addiu     $a1, $zero, -1
/* 1010F8 802DE008 8FA20038 */  lw        $v0, 0x38($sp)
/* 1010FC 802DE00C 8FA3003C */  lw        $v1, 0x3c($sp)
/* 101100 802DE010 8FA40040 */  lw        $a0, 0x40($sp)
/* 101104 802DE014 0100302D */  daddu     $a2, $t0, $zero
/* 101108 802DE018 AFA70010 */  sw        $a3, 0x10($sp)
/* 10110C 802DE01C 0120382D */  daddu     $a3, $t1, $zero
/* 101110 802DE020 AFBF0020 */  sw        $ra, 0x20($sp)
/* 101114 802DE024 AFA4001C */  sw        $a0, 0x1c($sp)
/* 101118 802DE028 0000202D */  daddu     $a0, $zero, $zero
/* 10111C 802DE02C AFA20014 */  sw        $v0, 0x14($sp)
/* 101120 802DE030 0C0B77B9 */  jal       func_802DDEE4
/* 101124 802DE034 AFA30018 */   sw       $v1, 0x18($sp)
/* 101128 802DE038 8FBF0020 */  lw        $ra, 0x20($sp)
/* 10112C 802DE03C 03E00008 */  jr        $ra
/* 101130 802DE040 27BD0028 */   addiu    $sp, $sp, 0x28

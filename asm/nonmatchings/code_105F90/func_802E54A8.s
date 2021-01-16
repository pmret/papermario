.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E54A8
/* 106D28 802E54A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106D2C 802E54AC 3C05802F */  lui       $a1, %hi(D_802EA760)
/* 106D30 802E54B0 24A5A760 */  addiu     $a1, $a1, %lo(D_802EA760)
/* 106D34 802E54B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 106D38 802E54B8 0C0442F3 */  jal       func_80110BCC
/* 106D3C 802E54BC 00000000 */   nop
/* 106D40 802E54C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106D44 802E54C4 03E00008 */  jr        $ra
/* 106D48 802E54C8 27BD0018 */   addiu    $sp, $sp, 0x18

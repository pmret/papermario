.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB778_E2E0A8
/* E2E0A8 802BB778 3C02802C */  lui       $v0, %hi(func_802BB374_E2DCA4)
/* E2E0AC 802BB77C 2442B374 */  addiu     $v0, $v0, %lo(func_802BB374_E2DCA4)
/* E2E0B0 802BB780 AC800054 */  sw        $zero, 0x54($a0)
/* E2E0B4 802BB784 03E00008 */  jr        $ra
/* E2E0B8 802BB788 AC82003C */   sw       $v0, 0x3c($a0)

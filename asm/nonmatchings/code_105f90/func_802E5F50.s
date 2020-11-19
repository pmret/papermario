.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5F50
/* 1077D0 802E5F50 8C830040 */  lw        $v1, 0x40($a0)
/* 1077D4 802E5F54 3C020A00 */  lui       $v0, 0xa00
/* 1077D8 802E5F58 24420328 */  addiu     $v0, $v0, 0x328
/* 1077DC 802E5F5C AC620128 */  sw        $v0, 0x128($v1)
/* 1077E0 802E5F60 3C020A00 */  lui       $v0, 0xa00
/* 1077E4 802E5F64 24420380 */  addiu     $v0, $v0, 0x380
/* 1077E8 802E5F68 AC62012C */  sw        $v0, 0x12c($v1)
/* 1077EC 802E5F6C 3C02802E */  lui       $v0, 0x802e
/* 1077F0 802E5F70 2442586C */  addiu     $v0, $v0, 0x586c
/* 1077F4 802E5F74 03E00008 */  jr        $ra
/* 1077F8 802E5F78 AC82003C */   sw       $v0, 0x3c($a0)

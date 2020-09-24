.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D4560
/* F8F10 802D4560 3C028007 */  lui       $v0, 0x8007
/* F8F14 802D4564 8C42419C */  lw        $v0, 0x419c($v0)
/* F8F18 802D4568 80420070 */  lb        $v0, 0x70($v0)
/* F8F1C 802D456C 14400007 */  bnez      $v0, .L802D458C
/* F8F20 802D4570 00000000 */   nop      
/* F8F24 802D4574 3C02802E */  lui       $v0, 0x802e
/* F8F28 802D4578 2442B6C0 */  addiu     $v0, $v0, -0x4940
/* F8F2C 802D457C 3C01802E */  lui       $at, 0x802e
/* F8F30 802D4580 AC22B7C0 */  sw        $v0, -0x4840($at)
/* F8F34 802D4584 03E00008 */  jr        $ra
/* F8F38 802D4588 00000000 */   nop      
.L802D458C:
/* F8F3C 802D458C 3C02802E */  lui       $v0, 0x802e
/* F8F40 802D4590 2442B5C0 */  addiu     $v0, $v0, -0x4a40
/* F8F44 802D4594 3C01802E */  lui       $at, 0x802e
/* F8F48 802D4598 AC22B7C0 */  sw        $v0, -0x4840($at)
/* F8F4C 802D459C 03E00008 */  jr        $ra
/* F8F50 802D45A0 00000000 */   nop      
/* F8F54 802D45A4 00000000 */  nop       
/* F8F58 802D45A8 00000000 */  nop       
/* F8F5C 802D45AC 00000000 */  nop       

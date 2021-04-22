.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3624
/* F7FD4 802D3624 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F7FD8 802D3628 AFBF0014 */  sw        $ra, 0x14($sp)
/* F7FDC 802D362C AFB00010 */  sw        $s0, 0x10($sp)
/* F7FE0 802D3630 8C82000C */  lw        $v0, 0xc($a0)
/* F7FE4 802D3634 0C0B1EAF */  jal       get_variable
/* F7FE8 802D3638 8C450000 */   lw       $a1, ($v0)
/* F7FEC 802D363C 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F7FF0 802D3640 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F7FF4 802D3644 00021080 */  sll       $v0, $v0, 2
/* F7FF8 802D3648 00431021 */  addu      $v0, $v0, $v1
/* F7FFC 802D364C 8C500000 */  lw        $s0, ($v0)
/* F8000 802D3650 0C048B7F */  jal       free_entity_model_by_index
/* F8004 802D3654 8E040000 */   lw       $a0, ($s0)
/* F8008 802D3658 2403FFFF */  addiu     $v1, $zero, -1
/* F800C 802D365C AE030000 */  sw        $v1, ($s0)
/* F8010 802D3660 8FBF0014 */  lw        $ra, 0x14($sp)
/* F8014 802D3664 8FB00010 */  lw        $s0, 0x10($sp)
/* F8018 802D3668 24020002 */  addiu     $v0, $zero, 2
/* F801C 802D366C 03E00008 */  jr        $ra
/* F8020 802D3670 27BD0018 */   addiu    $sp, $sp, 0x18

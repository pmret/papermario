.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC4B8_E30E08
/* E30E08 802BC4B8 8C840040 */  lw        $a0, 0x40($a0)
/* E30E0C 802BC4BC 90820004 */  lbu       $v0, 4($a0)
/* E30E10 802BC4C0 2442FFFF */  addiu     $v0, $v0, -1
/* E30E14 802BC4C4 A0820004 */  sb        $v0, 4($a0)
/* E30E18 802BC4C8 00021600 */  sll       $v0, $v0, 0x18
/* E30E1C 802BC4CC 1C40000F */  bgtz      $v0, .L802BC50C
/* E30E20 802BC4D0 240200FF */   addiu    $v0, $zero, 0xff
/* E30E24 802BC4D4 80830003 */  lb        $v1, 3($a0)
/* E30E28 802BC4D8 3C06802C */  lui       $a2, %hi(D_802BCAA0_E313F0)
/* E30E2C 802BC4DC 24C6CAA0 */  addiu     $a2, $a2, %lo(D_802BCAA0_E313F0)
/* E30E30 802BC4E0 3C05802C */  lui       $a1, %hi(D_802BCAA0_E313F0)
/* E30E34 802BC4E4 00A32821 */  addu      $a1, $a1, $v1
/* E30E38 802BC4E8 90A5CAA0 */  lbu       $a1, %lo(D_802BCAA0_E313F0)($a1)
/* E30E3C 802BC4EC 10A20007 */  beq       $a1, $v0, .L802BC50C
/* E30E40 802BC4F0 24630001 */   addiu    $v1, $v1, 1
/* E30E44 802BC4F4 00661021 */  addu      $v0, $v1, $a2
/* E30E48 802BC4F8 A0850005 */  sb        $a1, 5($a0)
/* E30E4C 802BC4FC 90420000 */  lbu       $v0, ($v0)
/* E30E50 802BC500 24630001 */  addiu     $v1, $v1, 1
/* E30E54 802BC504 A0830003 */  sb        $v1, 3($a0)
/* E30E58 802BC508 A0820004 */  sb        $v0, 4($a0)
.L802BC50C:
/* E30E5C 802BC50C 03E00008 */  jr        $ra
/* E30E60 802BC510 00000000 */   nop

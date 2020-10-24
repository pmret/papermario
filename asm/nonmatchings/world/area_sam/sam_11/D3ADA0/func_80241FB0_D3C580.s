.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FB0_D3C580
/* D3C580 80241FB0 3C058016 */  lui       $a1, 0x8016
/* D3C584 80241FB4 24A5A550 */  addiu     $a1, $a1, -0x5ab0
/* D3C588 80241FB8 AC8000AC */  sw        $zero, 0xac($a0)
/* D3C58C 80241FBC 84A20002 */  lh        $v0, 2($a1)
/* D3C590 80241FC0 24030040 */  addiu     $v1, $zero, 0x40
/* D3C594 80241FC4 14430002 */  bne       $v0, $v1, .L80241FD0
/* D3C598 80241FC8 24020001 */   addiu    $v0, $zero, 1
/* D3C59C 80241FCC AC8200AC */  sw        $v0, 0xac($a0)
.L80241FD0:
/* D3C5A0 80241FD0 84A20004 */  lh        $v0, 4($a1)
/* D3C5A4 80241FD4 14430002 */  bne       $v0, $v1, .L80241FE0
/* D3C5A8 80241FD8 24020001 */   addiu    $v0, $zero, 1
/* D3C5AC 80241FDC AC8200AC */  sw        $v0, 0xac($a0)
.L80241FE0:
/* D3C5B0 80241FE0 03E00008 */  jr        $ra
/* D3C5B4 80241FE4 24020002 */   addiu    $v0, $zero, 2
